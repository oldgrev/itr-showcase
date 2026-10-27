-- ItrShowcaseLoader, based on itr-common's ITRMapLoader: gets you into a custom map in Into the Radius 1 (2.7.2) and back
-- out again. Every map-specific value (level name, level tag, donor zone, map centre, loot manifest, entry trigger,
-- exit) comes from config.lua. See README.md.
--
-- NATIVE mode (per map: Native = true; the recommended way). The map is registered with the game as a level at startup
-- (an unloaded streaming entry + a row in SystemConfig.LevelConfigurations + a map centre + the loot tags), and entering
-- calls the game mode's TransferToLevel, as a zone gate does. The game then runs the transition, level events, loot
-- and arrival as it does for a zone. Any number of maps can be registered at once; each has a trigger (a Hub item and/or a key).
-- See "Native level" below.
--
-- STREAMING mode (Native = false; the older fallback). Roughly:
--   1. once you're in the Hub, stream the map in at the origin (maps are built where they'll sit in the world).
--      Normally you'd use LevelStreamingDynamic::LoadLevelInstance, but UE4SS can't call it, see Load();
--   2. when the level's visible: (HubTeardown) teleport to a staging point on the map, unload every other streaming
--      level (the Hub), then teleport to the arrival marker. Without the teardown: just teleport to the arrival marker
--      and, for maps with baked lighting, hide the Hub's lighting-scenario level;
--   3. stepping near any ExitTag marker (or pressing the key again) takes you back to the Hub. With the teardown that
--      means asking the game to load the Hub (LevelManager::LoadLevel) while you still stand on the map;
--   4. leaving through an exit that has an id is remembered, and the next entry arrives at the matching arrive marker.
--   5. (ActivateGameplay) ~3 s after arrival the map's gameplay actors (loot, stashes, anomalies, spawners,
--      generators) get the level-start events they missed: OnLevelPrepare, GenerateLoot (the native distance check spawns the items), OnLevelStarted,
--      OnGameStarted, OnTransitionEnd, called on each actor in the map's level.
--   The streaming mode was tested in VR with UE4SS 3.0.1 (the Nexus Mods ITR repack) for entry, exit markers and the
--   basic load/unload; multiple exits, re-entry memory, Hub teardown and gameplay activation were not tested in game.
-- This file avoids Lua 5.4-only syntax so `luac5.1 -p` can check it.

local UEHelpers = require("UEHelpers")
local Config = require("config")
-- Test overrides: an optional Scripts/config_test.lua (a table) replaces keys of the config for an automated test run, for example
-- RequireLevelManagerReady = false for a -nohmd game, or MissionTest = true. A normal install has no such file.
do
    local OkT, Over = pcall(require, "config_test")
    if OkT and type(Over) == "table" then
        for K, V in pairs(Over) do Config[K] = V end
    end
end

-- LogTag names this loader in the log lines (config LogTag, default "ITRMapLoader"): give a second loader mod its own
local LogName = Config.LogTag or "ITRMapLoader"
local TAG = "[" .. LogName .. "] "
local Current = nil          -- { Map, Stream, Return, Phase, Exits, TornDown, HubLevels }
local HiddenScenarios = {}   -- ULevelStreaming objects we hid (no-teardown path only)
local NextIndex = 1
local InstanceCount = 0
local Memory = {}            -- map name -> last exit id

local function Log(fmt, ...) print(TAG .. string.format(fmt, ...) .. "\n") end

local function Valid(o) return o ~= nil and o:IsValid() end

-- Option lookup: per-map value, then global config value, then default
local function Opt(Map, Key, Default)
    if Map and Map[Key] ~= nil then return Map[Key] end
    if Config[Key] ~= nil then return Config[Key] end
    return Default
end

local ExitTag = Config.ExitTag or "itr:exit"
local ExitIdPrefix = Config.ExitIdTagPrefix or "itr:exit_id:"
local ArrivePrefix = Config.ArriveTagPrefix or "itr:arrive:"
local HubLevelTag = Config.HubLevelTag or "Level.Hub"
local StagingMaxWestX = Config.StagingMaxWestX or -20000

-- Wall-clock milliseconds. The loops below measure their waits with this, never by counting ticks: a tick count assumes
-- every LoopAsync tick runs its game-thread callback on time (it did not).
local function Now() return os.clock() * 1000 end

-- Runs fn on the game thread every ms until it returns true (or throws). LoopAsync runs on another thread, so the
-- stop flag is only seen one round after the game thread set it. The flag lives in a table (shared by reference).
-- IMPORTANT (UE4SS c62ada0): errors raised by UE4SS's functions (TMap:Find on a missing key, calling an invalid UFunction
-- object, ...) are C++ exceptions that pcall does NOT catch; they unwind to UE4SS, which logs "Error: ..." and drops the tick.
-- Such a tick never reaches the line after pcall, which is how it is noticed: Running is still set on the next tick.
-- MaxCrashes ticks lost that way end the loop (default 3), so one bad call can't repeat every tick for the whole session.
local function Every(ms, fn, MaxCrashes)
    local St = { Done = false, Running = false, Crashes = 0 }
    LoopAsync(ms, function()
        if St.Done then return true end
        ExecuteInGameThread(function()
            if St.Done then return end
            if St.Running then
                St.Crashes = St.Crashes + 1
                St.Running = false
                Log("loop tick %d aborted by a native error (see the Error line above)", St.Crashes)
                if St.Crashes >= (MaxCrashes or 3) then
                    Log("loop stopped after %d aborted ticks", St.Crashes)
                    St.Done = true
                    return
                end
            end
            St.Running = true
            local Ok, Res = pcall(fn)
            St.Running = false
            if not Ok then
                Log("error: %s", tostring(Res))
                St.Done = true
            elseif Res then
                St.Done = true
            end
        end)
        return false
    end)
end

-- Log each distinct message once (for failures that would otherwise repeat every tick)
local LoggedOnce = {}
local function LogOnce(Key, fmt, ...)
    if LoggedOnce[Key] then return end
    LoggedOnce[Key] = true
    Log(fmt, ...)
end

-- Calling a UFunction by name. UE4SS (c62ada0) answers obj[Name] with a UFunction userdata (callable), or with an invalid
-- UObject userdata when the class has no such function; older builds return a Lua function. Returns Found, Ok, Result.
local function FindUF(O, Name)
    local Ok, F = pcall(function() return O[Name] end)
    if not Ok or F == nil then return nil end
    if type(F) == "function" then return F end
    if type(F) == "userdata" then
        local Ok2, V = pcall(function() return F:IsValid() end)
        if Ok2 and V == true then return F end
    end
    return nil
end

local function CallUF(O, Name, ...)
    local F = FindUF(O, Name)
    if not F then return false, false, nil end
    local Args = { ... }
    local Ok, Res = pcall(function() return F(O, (table.unpack or unpack)(Args)) end)
    return true, Ok, Res
end

-- Same UObject? (UE4SS hands out a fresh Lua wrapper per access, so == on wrappers is not an identity test)
local function SameObj(A, B)
    if A == nil or B == nil then return false end
    local Ok, R = pcall(function() return A:IsValid() and B:IsValid() and A:GetAddress() == B:GetAddress() end)
    return Ok and R == true
end

local function Vec(v) return { X = v.X, Y = v.Y, Z = v.Z } end
local function Rot(r) return { Pitch = r.Pitch, Yaw = r.Yaw, Roll = r.Roll } end
local function FmtV(v) return string.format("(%.0f, %.0f, %.0f)", v.X, v.Y, v.Z) end
local function Dist2D(A, B) local DX, DY = A.X - B.X, A.Y - B.Y; return math.sqrt(DX * DX + DY * DY) end
local function Dist3D(A, B)
    local DX, DY, DZ = A.X - B.X, A.Y - B.Y, A.Z - B.Z
    return math.sqrt(DX * DX + DY * DY + DZ * DZ)
end

local function StreamingLevels(World)
    local out = {}
    World.StreamingLevels:ForEach(function(_, Elem)
        local S = Elem:get()
        if Valid(S) then table.insert(out, S) end
    end)
    return out
end

local function PkgName(S)
    local Ok, N = pcall(function() return S:GetWorldAssetPackageFName():ToString() end)
    return Ok and N or "?"
end

local function ShortName(P)
    local S = tostring(P):gsub("^.*/", "")
    S = S:gsub("%..*$", "")
    return S
end

local function CallBool(O, Fn)
    local Ok, R = pcall(function() return O[Fn](O) end)
    return Ok and R == true
end

local function PropBool(O, Prop)
    local Ok, R = pcall(function() return O[Prop] end)
    return Ok and R == true
end

-- A streaming entry is "in use" if it is requested, loaded or visible
local function StreamActive(S)
    return PropBool(S, "bShouldBeLoaded") or PropBool(S, "bShouldBeVisible")
        or CallBool(S, "IsLevelLoaded") or CallBool(S, "IsLevelVisible")
end

local function StreamBitsText(S)
    return string.format("shouldLoad %d shouldVisible %d loaded %d visible %d",
        PropBool(S, "bShouldBeLoaded") and 1 or 0, PropBool(S, "bShouldBeVisible") and 1 or 0,
        CallBool(S, "IsLevelLoaded") and 1 or 0, CallBool(S, "IsLevelVisible") and 1 or 0)
end

local function GetLevelManager()
    local Ok, LM = pcall(function()
        local LMClass = StaticFindObject("/Script/IntoTheRadius.Default__LevelManager")
        if Valid(LMClass) then return LMClass:GetLevelManager() end
        return nil
    end)
    if Ok and Valid(LM) then return LM end
    return nil
end

-- In the Hub = the Hub level visible and the game's level manager not mid-transition (the Hub level becomes visible
-- while the player is still in the menu room, during the transition; callers also wait for two checks in a row).
local function IsHubVisible(World)
    local Hub = false
    for _, S in ipairs(StreamingLevels(World)) do
        if S:IsLevelVisible() and PkgName(S):find("/Levels/Hub/L_Hub", 1, true) then
            Hub = true
        end
    end
    if not Hub then return false end
    local LM = GetLevelManager()
    if LM and Config.RequireLevelManagerReady ~= false and not LM:IsReady() then return false end
    return true
end

---------------------------------------------------------------------------------------------------------------------
-- Re-entry memory: { map name -> last exit id }, one "name<TAB>id" line each, in a small file next to this script.
---------------------------------------------------------------------------------------------------------------------
-- Where this script lives. debug.getinfo's source can be relative or empty under UE4SS, so also ask package.searchpath
-- where config.lua was found.
local ScriptDirCache = nil
local function ScriptDir()
    if ScriptDirCache then return ScriptDirCache end
    local Cands = {}
    local Ok, Info = pcall(debug.getinfo, 1, "S")
    if Ok and Info and type(Info.source) == "string" then
        local Src = (Info.source:gsub("^@", ""))
        local Dir = Src:match("^(.*[/\\])")
        if Dir then table.insert(Cands, Dir) end
    end
    local Ok2, Found = pcall(function() return package.searchpath("config", package.path) end)
    if Ok2 and type(Found) == "string" then
        local Dir = Found:match("^(.*[/\\])")
        if Dir then table.insert(Cands, Dir) end
    end
    table.insert(Cands, "ue4ss/Mods/" .. LogName .. "/Scripts/")
    table.insert(Cands, "Mods/" .. LogName .. "/Scripts/")
    for _, Dir in ipairs(Cands) do
        local OkF, F = pcall(io.open, Dir .. "config.lua", "r")
        if OkF and F then
            F:close()
            ScriptDirCache = Dir
            return Dir
        end
    end
    ScriptDirCache = Cands[1] or ""
    return ScriptDirCache
end

local MemoryPath = Config.ReEntryFile or (ScriptDir() .. "reentry.txt")
local MemoryWarned = false

local function LoadMemory()
    Memory = {}
    local Ok, F = pcall(io.open, MemoryPath, "r")
    if not Ok or not F then return end       -- no file yet: first run
    local Ok2, Text = pcall(F.read, F, "*a")
    pcall(F.close, F)
    if not Ok2 or type(Text) ~= "string" then
        Log("re-entry file %s unreadable; starting empty", MemoryPath)
        return
    end
    local N = 0
    for Line in Text:gmatch("[^\r\n]+") do
        local Name, Id = Line:match("^([^\t]+)\t(.+)$")
        if Name and Id then
            Memory[Name] = Id
            N = N + 1
        end                                  -- anything else (corrupt line) is ignored
    end
    Log("re-entry memory: %d entr%s from %s", N, N == 1 and "y" or "ies", MemoryPath)
end

local function SaveMemory()
    local Lines = {}
    for Name, Id in pairs(Memory) do table.insert(Lines, Name .. "\t" .. Id) end
    table.sort(Lines)
    local Ok, F = pcall(io.open, MemoryPath, "w")
    if Ok and F then
        pcall(F.write, F, table.concat(Lines, "\n") .. "\n")
        pcall(F.close, F)
        return
    end
    if not MemoryWarned then
        MemoryWarned = true
        Log("cannot write the re-entry file %s; the last exit will not be remembered across game restarts", MemoryPath)
    end
end

local function Remember(Map, ExitId)
    if not Opt(Map, "ReEntry", true) or not ExitId then return end
    local Id = tostring(ExitId):gsub("[\t\r\n]", " ")
    Memory[Map.Name] = Id
    SaveMemory()
    Log("remembered exit '%s' for %s", Id, Map.Name)
end

---------------------------------------------------------------------------------------------------------------------
-- Markers
---------------------------------------------------------------------------------------------------------------------
local function TagsOf(P)
    local Out = {}
    pcall(function()
        P.Tags:ForEach(function(_, T) table.insert(Out, T:get():ToString()) end)
    end)
    return Out
end

-- Every TargetPoint in the streamed level, with its tags; picks out start / arrive:<id> / exit markers.
local function ScanMarkers(Map, Stream)
    local M = { All = {}, Start = nil, Arrive = {}, Exits = {} }
    local Level = Stream:GetLoadedLevel()
    local Points = FindAllOf("TargetPoint")
    if not Points or not Valid(Level) then return M end
    for _, P in ipairs(Points) do
        if Valid(P) and P:GetOuter():GetAddress() == Level:GetAddress() then
            local Rec = { P = P, Loc = Vec(P:K2_GetActorLocation()), Rot = Rot(P:K2_GetActorRotation()), Tags = TagsOf(P) }
            local IsExit, ExitId = false, nil
            for _, T in ipairs(Rec.Tags) do
                if T == Map.StartTag and not M.Start then M.Start = Rec end
                if T == Opt(Map, "ExitTag", ExitTag) then IsExit = true end
                if T:sub(1, #ExitIdPrefix) == ExitIdPrefix and #T > #ExitIdPrefix then
                    IsExit = true            -- an exit id alone also makes an exit
                    ExitId = ExitId or T:sub(#ExitIdPrefix + 1)
                end
                if T:sub(1, #ArrivePrefix) == ArrivePrefix and #T > #ArrivePrefix then
                    local Id = T:sub(#ArrivePrefix + 1)
                    if not M.Arrive[Id] then M.Arrive[Id] = Rec end
                end
            end
            Rec.IsExit, Rec.ExitId = IsExit, ExitId
            if IsExit then table.insert(M.Exits, { X = Rec.Loc.X, Y = Rec.Loc.Y, Z = Rec.Loc.Z, Id = ExitId }) end
            table.insert(M.All, Rec)
        end
    end
    return M
end

-- Where to arrive: the remembered exit's arrive marker if there is one, else the start marker
local function ChooseArrival(Map, M)
    if Opt(Map, "ReEntry", true) then
        local Id = Memory[Map.Name]
        if Id then
            if M.Arrive[Id] then
                Log("re-entry: last exit was '%s'; arriving at %s%s", Id, ArrivePrefix, Id)
                return M.Arrive[Id]
            end
            Log("re-entry: last exit was '%s' but the map has no '%s%s' marker; using '%s'", Id, ArrivePrefix, Id, Map.StartTag)
        end
    end
    return M.Start
end

local function ArmExits(M)
    Current.Exits = M.Exits
    if #M.Exits > 0 then
        local Ids = {}
        for _, E in ipairs(M.Exits) do table.insert(Ids, E.Id or "-") end
        Log("%d exit marker(s) (ids: %s)", #M.Exits, table.concat(Ids, ", "))
        for _, E in ipairs(M.Exits) do Log("exit point %s at (%.0f, %.0f, %.0f)", E.Id or "-", E.X, E.Y, E.Z) end
    end
end

---------------------------------------------------------------------------------------------------------------------
-- Player helpers
---------------------------------------------------------------------------------------------------------------------
local function TeleportPlayer(Loc, Rt, What)
    local Pawn = UEHelpers.GetPlayer()
    if not Valid(Pawn) then
        Log("teleport %s: no player pawn", What)
        return false
    end
    local Ok, R = pcall(function() return Pawn:K2_TeleportTo(Loc, Rt) end)
    Log("teleport to %s %s: %s", What, FmtV(Loc), Ok and tostring(R) or ("error " .. tostring(R)))
    return Ok and R ~= false
end

local function PawnLoc()
    local Pawn = UEHelpers.GetPlayer()
    if not Valid(Pawn) then return nil end
    local Ok, L = pcall(function() return Vec(Pawn:K2_GetActorLocation()) end)
    if not Ok then
        LogOnce("pawnloc", "cannot read the pawn location: %s", tostring(L))
        return nil
    end
    return L
end

-- Is the player standing on this streamed level? true / false, or nil when the pawn can't tell.
-- Information only: Pawn:GetMovementBase() is not a UFunction (UE4SS c62ada0 returns an invalid object for it and every call
-- raises "Tried calling a member function but the UObject instance is nullptr"), so the base is read as the
-- Character's BasedMovement.MovementBase property. It can be stale or empty for a VR pawn, so no decision depends on it;
-- the staging/exit decisions use the pawn's position (StablePosition below). One log line on the first failure.
local function OnMapGround(Stream)
    local Pawn = UEHelpers.GetPlayer()
    if not Valid(Pawn) or not Valid(Stream) then return nil end
    local Ok, Res = pcall(function()
        local Base = Pawn.BasedMovement.MovementBase
        if not Valid(Base) then return nil end
        local Owner = Base:GetOwner()
        local Level = Stream:GetLoadedLevel()
        if not Valid(Owner) or not Valid(Level) then return nil end
        return Owner:GetOuter():GetAddress() == Level:GetAddress()
    end)
    if not Ok then
        LogOnce("ground", "movement base unreadable (BasedMovement.MovementBase): %s; positions are used instead", tostring(Res))
        return nil
    end
    return Res
end

-- The pawn has stayed within HRadius (horizontal) and VRadius (vertical) cm of Target for HoldMs of wall-clock time.
-- State = a table the caller keeps between ticks. Returns true once stable, plus the current pawn location (may be nil).
local function StablePosition(State, Target, HRadius, VRadius, HoldMs)
    local L = PawnLoc()
    if L and Dist2D(L, Target) <= HRadius and math.abs(L.Z - Target.Z) <= VRadius then
        State.Since = State.Since or Now()
        if Now() - State.Since >= HoldMs then return true, L end
    else
        State.Since = nil
    end
    return false, L
end

---------------------------------------------------------------------------------------------------------------------
-- Hub teardown helpers
---------------------------------------------------------------------------------------------------------------------
-- Short names of the sublevels any level configuration lists (the game reloads these itself). nil: couldn't read it.
local function ManagedSublevels()
    local Ok, Set = pcall(function()
        local SCClass = StaticFindObject("/Script/IntoTheRadius.Default__SystemConfig")
        if not Valid(SCClass) then return nil end
        local SC = SCClass:GetSystemConfig()
        if not Valid(SC) then return nil end
        local Out, N = {}, 0
        SC.LevelConfigurations:ForEach(function(_, E)
            local C = E:get()
            Out[ShortName(C.MainSublevel:ToString())] = true
            C.StaticSublevels:ForEach(function(_, S) Out[ShortName(S:get():ToString())] = true end)
            N = N + 1
        end)
        if N == 0 then return nil end
        return Out
    end)
    if Ok then return Set end
    return nil
end

-- Request a Hub load from the game, like its gates do. LevelManager::LoadLevel takes a FGameplayTag by value (a plain
-- struct, no out-parameter), so UE4SS 3.0.1 can call it.
local function CallLoadLevelHub()
    local LM = GetLevelManager()
    if not LM then
        Log("exit: no LevelManager")
        return false
    end
    local Ok, Err = pcall(function() LM:LoadLevel({ TagName = FName(HubLevelTag) }) end)
    if not Ok then
        Log("exit: LevelManager LoadLevel(%s) failed: %s", HubLevelTag, tostring(Err))
        return false
    end
    Log("exit: LevelManager LoadLevel(%s) called; ready now %s", HubLevelTag, tostring(LM:IsReady()))
    return true
end

-- Fallback when LoadLevel does nothing (the game thinks it's still in the Hub): the game mode's
-- TransferToLevel(LevelTag, LocationTag), as the zone gates call it.
local function CallTransferHub()
    local Ok, Res = pcall(function()
        local GM = FindFirstOf("PRGameMode")
        if not Valid(GM) then error("no PRGameMode") end
        -- an interface function (IPRGameMode), not one of the game mode's class: call it with the game mode as context
        local Fn = StaticFindObject("/Script/IntoTheRadius.IPRGameMode:TransferToLevel")
        if not Valid(Fn) then error("IPRGameMode:TransferToLevel not found") end
        return Fn(GM, { TagName = FName(HubLevelTag) }, { TagName = FName("None") })
    end)
    Log("exit: game mode TransferToLevel(%s) -> %s", HubLevelTag, Ok and tostring(Res) or ("failed: " .. tostring(Res)))
    return Ok
end

---------------------------------------------------------------------------------------------------------------------
-- Lighting scenarios (no-teardown path)
---------------------------------------------------------------------------------------------------------------------
local function SetLightingScenariosHidden(World, Hide)
    if Hide then
        for _, S in ipairs(StreamingLevels(World)) do
            local L = S:GetLoadedLevel()
            if not SameObj(S, Current and Current.Stream) and Valid(L) and L.bIsLightingScenario and S:IsLevelVisible() then
                S:SetShouldBeVisible(false)
                table.insert(HiddenScenarios, S)
                Log("hid lighting scenario %s", PkgName(S))
            end
        end
    else
        for _, S in ipairs(HiddenScenarios) do
            if Valid(S) then S:SetShouldBeVisible(true) end
        end
        HiddenScenarios = {}
    end
end

---------------------------------------------------------------------------------------------------------------------
-- Gameplay activation (streaming mode; untested in game)
---------------------------------------------------------------------------------------------------------------------
-- The map streams in after the Hub already fired its level-start events, so the map's gameplay actors (loot points,
-- stashes, anomalies, spawners, generators; all APRBasicActor) never get them. The loader calls the same UFUNCTIONs on each
-- actor that lives in the map's level, in the game's order, through the actor so Blueprint overrides run. The global
-- UEventsManager delegates are NOT fired (the game mode, the player and the UI listen to those too).
local ActivateDelayMs = 3000                 -- after arrival: the actors' BeginPlay must have run
local LootBaseClass = "BP_LootSpawnPoint_C"  -- GenerateLoot is called on this class and its children

local function ClassNameOf(A)
    local Ok, N = pcall(function() return A:GetClass():GetFName():ToString() end)
    return Ok and N or "?"
end

-- Is the actor's class (or one of its parents) called Name?
local function IsClassNamed(A, Name)
    local Ok, Res = pcall(function()
        local C = A:GetClass()
        local Guard = 0
        while Valid(C) and Guard < 32 do
            if C:GetFName():ToString() == Name then return true end
            C = C:GetSuperStruct()
            Guard = Guard + 1
        end
        return false
    end)
    return Ok and Res or false
end

-- The level tag the game is in (Level.Hub with the Hub torn down); HubLevelTag when it can't be read.
local function CurrentLevelTagName()
    local Ok, N = pcall(function()
        local GD = FindFirstOf("PRGameData")
        if not Valid(GD) then return nil end
        return GD.CurrentLevelTag.TagName:ToString()
    end)
    if Ok and type(N) == "string" and N ~= "" and N ~= "None" then return N end
    return HubLevelTag
end

-- ---- loot manifest -----------------------------------------------------------------------------------------------------
-- The map's loot tags go into the game config's LootArray (TMap<FGameplayTag, FPRLootTableConfig>) before its loot is
-- generated, so its nodes never draw on the save-wide budgets of the real zone tags. The entries are added with TMap:Add through UE4SS.
-- Manifest = "<Map.Name>.loot.json" next to this script; a "<Map.Name>.loot.lua" returning the same table also works, or
-- set Map.LootManifest = path.

-- Minimal JSON decoder (objects, arrays, strings, numbers, true/false/null); errors on malformed input.
local function JsonDecode(Text)
    local Pos = 1
    local function Ws() Pos = Text:find("%S", Pos) or (#Text + 1) end
    local ParseValue
    local Esc = { n = "\n", t = "\t", r = "\r", b = "\b", f = "\f" }
    local function ParseString()
        local Out = {}
        Pos = Pos + 1
        while true do
            local C = Text:sub(Pos, Pos)
            if C == "" then error("unterminated string") end
            if C == '"' then Pos = Pos + 1; break end
            if C == "\\" then
                local N = Text:sub(Pos + 1, Pos + 1)
                if N == "u" then table.insert(Out, "?"); Pos = Pos + 6
                else table.insert(Out, Esc[N] or N); Pos = Pos + 2 end
            else
                table.insert(Out, C); Pos = Pos + 1
            end
        end
        return table.concat(Out)
    end
    ParseValue = function()
        Ws()
        local C = Text:sub(Pos, Pos)
        if C == "{" then
            local O = {}
            Pos = Pos + 1
            Ws()
            if Text:sub(Pos, Pos) == "}" then Pos = Pos + 1; return O end
            while true do
                Ws()
                if Text:sub(Pos, Pos) ~= '"' then error("object key expected at " .. Pos) end
                local K = ParseString()
                Ws()
                if Text:sub(Pos, Pos) ~= ":" then error("':' expected at " .. Pos) end
                Pos = Pos + 1
                O[K] = ParseValue()
                Ws()
                local D = Text:sub(Pos, Pos)
                Pos = Pos + 1
                if D == "}" then return O end
                if D ~= "," then error("',' or '}' expected at " .. (Pos - 1)) end
            end
        elseif C == "[" then
            local A = {}
            Pos = Pos + 1
            Ws()
            if Text:sub(Pos, Pos) == "]" then Pos = Pos + 1; return A end
            while true do
                table.insert(A, ParseValue())
                Ws()
                local D = Text:sub(Pos, Pos)
                Pos = Pos + 1
                if D == "]" then return A end
                if D ~= "," then error("',' or ']' expected at " .. (Pos - 1)) end
            end
        elseif C == '"' then
            return ParseString()
        elseif Text:sub(Pos, Pos + 3) == "true" then Pos = Pos + 4; return true
        elseif Text:sub(Pos, Pos + 4) == "false" then Pos = Pos + 5; return false
        elseif Text:sub(Pos, Pos + 3) == "null" then Pos = Pos + 4; return nil
        else
            local Num = Text:match("^-?%d+%.?%d*[eE]?[+-]?%d*", Pos)
            if not Num or Num == "" then error("unexpected character at " .. Pos) end
            Pos = Pos + #Num
            return tonumber(Num)
        end
    end
    local V = ParseValue()
    return V
end

-- Returns the manifest table (or nil) and the path that was used / tried last.
local function LoadLootManifest(Map)
    local Dir = ScriptDir()
    local Candidates = {}
    if Map.LootManifest then table.insert(Candidates, Map.LootManifest) end
    table.insert(Candidates, Dir .. Map.Name .. ".loot.json")
    table.insert(Candidates, Dir .. Map.Name .. ".loot.lua")
    local Tried = {}
    for _, Path in ipairs(Candidates) do
        table.insert(Tried, Path)
        if Path:sub(-5) == ".json" then
            local Ok, F = pcall(io.open, Path, "r")
            if Ok and F then
                local Text = F:read("*a")
                F:close()
                local Ok2, Res = pcall(JsonDecode, Text or "")
                if Ok2 and type(Res) == "table" then return Res, Path end
                Log("loot manifest %s is not usable: %s", Path, tostring(Res))
                return nil, Path
            end
        else
            local Chunk = loadfile(Path)
            if Chunk then
                local Ok, Res = pcall(Chunk)
                if Ok and type(Res) == "table" then return Res, Path end
                Log("loot manifest %s is not usable: %s", Path, tostring(Res))
                return nil, Path
            end
        end
    end
    return nil, table.concat(Tried, " | ")
end

local function TMapCount(M)
    local N = 0
    local Ok = pcall(function() M:ForEach(function() N = N + 1 end) end)
    return Ok and N or -1
end

-- The value struct of Key in the TMap, or nil. TMap:Find THROWS (natively, not catchable) on a missing key, so Contains first.
local function TMapFind(M, Key)
    local Okc, Has = pcall(function() return M:Contains(Key) end)
    if not Okc or Has ~= true then return nil end
    local Ok, V = pcall(function() return M:Find(Key) end)
    if not Ok or V == nil then return nil end
    if type(V) == "userdata" then
        local Ok2, Isv = pcall(function() return V:IsValid() end)
        if Ok2 and Isv == false then return nil end
        local Ok3, Got = pcall(function() return V:get() end)
        if Ok3 and Got ~= nil then return Got end
    end
    return V
end

local function LootArrayOf()
    local Ok, GC = pcall(function() return FindFirstOf("GameConfig") end)
    if not Ok or not Valid(GC) then return nil end
    local Ok2, M = pcall(function() return GC.LootArray end)
    if Ok2 then return M end
    return nil
end

local function LootHasTag(Tag)
    local M = LootArrayOf()
    return M ~= nil and TMapFind(M, { TagName = FName(Tag) }) ~= nil
end

-- Loading an asset (a DataTable) from the map pak. The global LoadAsset of c62ada0 goes through the asset registry and does not
-- find pak-only assets, so the routes are tried in this order: AssetRegistryHelpers.GetAsset, StaticFindObject (already loaded),
-- LoadAsset, and KismetSystemLibrary.LoadAsset_Blocking with a soft-object struct, the route the game's blueprints use. The route
-- that worked is logged once.
local function LoadOwnTable(Path)
    local function Try(Name, Fn)
        local Ok, O = pcall(Fn)
        if Ok and O ~= nil and type(O) == "userdata" then
            local Ok2, V = pcall(function() return O:IsValid() end)
            if Ok2 and V == true then
                LogOnce("loadroute", "loot: custom tables load via %s", Name)
                return O
            end
        end
        return nil
    end
    -- AssetRegistryHelpers::GetAsset(FAssetData) = FindObject, else LoadObject on ObjectPath: works for pak assets the game's asset
    -- registry does not list.
    local Obj = Path:find(".", 1, true) and Path or (Path .. "." .. ShortName(Path))
    return Try("AssetRegistryHelpers.GetAsset", function()
            local ARH = StaticFindObject("/Script/AssetRegistry.Default__AssetRegistryHelpers")
            return ARH:GetAsset({ ObjectPath = FName(Obj) })
        end)
        or Try("StaticFindObject", function() return StaticFindObject(Path) end)
        or Try("LoadAsset", function() local O = LoadAsset(Path); return O end)
        or Try("KismetSystemLibrary.LoadAsset_Blocking", function()
            local KSL = StaticFindObject("/Script/Engine.Default__KismetSystemLibrary")
            return KSL:LoadAsset_Blocking({ AssetPathName = FName(Path), SubPathString = "" })
        end)
end

-- The map's table holder: one Blueprint actor in the map (config LootHolderClass, default "BP_<Map.Name>_LootTables_C") with
-- a "Tables" array that hard-references every loot DataTable, so the tables load with the level and the GC keeps them while
-- it is loaded (UE4SS Lua cannot AddToRoot). Returns { [DataTable name] = DataTable } and the count; empty for a map without
-- a holder.
local function HolderClassOf(Map) return Opt(Map, "LootHolderClass", "BP_" .. Map.Name .. "_LootTables_C") end

-- Loot state per map (maps register and switch their tables independently)
local LootCtxs = {}
local function LootCtxOf(Map)
    local C = LootCtxs[Map.Name]
    if not C then
        C = { Reg = { I = 0, Added = 0, Skipped = 0, NoDonor = 0, Failed = 0, Own = 0, Before = nil },
              Once = false,       -- the tags are registered (once per session)
              KeepAlive = {},     -- Lua-side references to the map's DataTables (not GC roots; see RegisterLootTags)
              Manifest = nil,     -- the manifest of the registration (re-pointing / clearing the map's entries on later loads / unload)
              Native = false }    -- native mode registered the tags at startup with donor tables: never load the map's tables then
        LootCtxs[Map.Name] = C
    end
    return C
end

local function HeldTables(Map)
    local Out, N = {}, 0
    local Ok, All = pcall(FindAllOf, HolderClassOf(Map))
    if not Ok or not All then return Out, 0 end
    for _, H in ipairs(All) do
        if Valid(H) then
            pcall(function()
                H.Tables:ForEach(function(_, Elem)
                    local T = Elem:get()
                    if Valid(T) then
                        Out[T:GetFName():ToString()] = T
                        N = N + 1
                    end
                end)
            end)
        end
    end
    return Out, N
end

-- Called before the activation pass, once per session. For each manifest tag not already in LootArray: copy the donor
-- (source_tag) entry's table, set LootPoints, TMap:Add. The map's DataTable (table_asset) if the map pak includes it, else the donor's
-- (used points are then SHARED with the donor zone).
-- Progress survives a native error (not catchable by pcall) in the middle of the tag list: the step is re-run and resumes after the
-- tag that was being processed, so one bad tag is skipped instead of repeating forever or losing the rest.
-- The map's entries point at tables that live only while the map is loaded. Each later load re-points them at the tables the new
-- level's holder brought in (ToDonor = false), each unload points them back at the donor's vanilla table (ToDonor = true), so LootArray
-- never keeps a pointer to a collected table.
local function RepointLootTables(Map, ToDonor)
    local Manifest = LootCtxOf(Map).Manifest
    local M = LootArrayOf()
    if not Manifest or type(Manifest.tags) ~= "table" or not M then return 0 end
    local Held, HeldN = {}, 0
    if not ToDonor then Held, HeldN = HeldTables(Map) end
    if not ToDonor and HeldN == 0 then
        Log("loot: %s: no table holder loaded; entries stay on the donor tables", Map.Name)
        return 0
    end
    local N, Missing = 0, 0
    for _, T in ipairs(Manifest.tags) do
        if type(T.tag) == "string" and type(T.table_name) == "string" and T.table_asset and T.table_asset ~= "" then
            local Back = TMapFind(M, { TagName = FName(T.tag) })
            local New = nil
            if ToDonor then
                local Donor = type(T.source_tag) == "string" and TMapFind(M, { TagName = FName(T.source_tag) }) or nil
                if Donor then pcall(function() New = Donor.LootTable end) end
            else
                New = Held[T.table_name]
            end
            if Back ~= nil and New ~= nil then
                if pcall(function() Back.LootTable = New end) then N = N + 1 end
            else
                Missing = Missing + 1
            end
        end
    end
    Log("loot: %s: own entries %s: %d re-pointed, %d without a table%s", Map.Name, ToDonor and "back to the donor tables (map unloaded)" or "to the map's held tables",
        N, Missing, ToDonor and "" or string.format(" (holder: %d table(s))", HeldN))
    return N
end

local function RegisterLootTags(Map, Manifest)
    if not Manifest then return 0 end
    local C = LootCtxOf(Map)
    if C.Once then return RepointLootTables(Map, false) end
    local Tags = Manifest.tags
    if type(Tags) ~= "table" then
        Log("loot manifest: no tags array")
        return 0
    end
    local M = LootArrayOf()
    if not M then
        Log("loot manifest: GameConfig / LootArray not available yet; nothing registered")
        return 0
    end
    local R = C.Reg
    R.Held, R.HeldN = HeldTables(Map)
    if not R.Before then
        R.Before = TMapCount(M)
        Log("loot manifest: %d tag(s); LootArray has %d entries before", #Tags, R.Before)
    else
        Log("loot manifest: resuming after tag #%d (the previous attempt was aborted by a native error)", R.I)
    end
    for I = R.I + 1, #Tags do
        R.I = I
        local T = Tags[I]
        local Tag, Src, Points = T.tag, T.source_tag, math.floor(tonumber(T.loot_points) or 0)
        if type(Tag) == "string" and Tag ~= "" then
            local Key = { TagName = FName(Tag) }
            if TMapFind(M, Key) ~= nil then
                R.Skipped = R.Skipped + 1
                Log("loot: tag %s already in LootArray: skipped", Tag)
            else
                local Donor = type(Src) == "string" and TMapFind(M, { TagName = FName(Src) }) or nil
                if Donor == nil then
                    R.NoDonor = R.NoDonor + 1
                    Log("loot: tag %s: source tag %s not in LootArray (no donor DataTable): skipped", Tag, tostring(Src))
                else
                    local Table = Donor.LootTable
                    local OwnTable = nil
                    if type(T.table_asset) == "string" and T.table_asset ~= "" and not C.Native then
                        OwnTable = R.Held[T.table_name or ""]
                        if OwnTable then
                            LogOnce("held", "loot: custom tables come from the map's table holder (%d table(s))", R.HeldN)
                        else
                            OwnTable = LoadOwnTable(T.table_asset)
                            if OwnTable then
                                Log("loot: tag %s: table %s is NOT held by the map (no %s actor): nothing keeps it alive in Lua", Tag,
                                    tostring(T.table_asset), HolderClassOf(Map))
                            end
                        end
                    end
                    if OwnTable then
                        Table = OwnTable
                        R.Own = R.Own + 1
                        Log("loot: tag %s: own DataTable %s (isolated used points)", Tag, T.table_asset)
                    else
                        Log("loot: tag %s: no own DataTable asset (%s); using the donor's: its used points are SHARED with the zone tag %s",
                            Tag, tostring(T.table_asset), tostring(Src))
                    end
                    Log("loot: tag %s: adding (budget %d)", Tag, Points)
                    local Ok, Err = pcall(function()
                        M:Add(Key, { Conditions = {}, LootPoints = Points, LootTable = Table, ExcludeGeneration = false })
                    end)
                    if not Ok then
                        R.Failed = R.Failed + 1
                        Log("loot: tag %s: TMap:Add failed: %s", Tag, tostring(Err))
                    else
                        local Back = TMapFind(M, Key)
                        if Back ~= nil then
                            -- c62ada0's TMap:Add stored a zeroed value (read back: budget 0), so write the fields into the stored
                            -- struct in place (Find hands out a reference to the map's storage)
                            local PtsNow = -1
                            pcall(function() PtsNow = Back.LootPoints end)
                            if PtsNow ~= Points then
                                local OkW, ErrW = pcall(function()
                                    Back.LootPoints = Points
                                    Back.LootTable = Table
                                    Back.ExcludeGeneration = false
                                end)
                                pcall(function() PtsNow = Back.LootPoints end)
                                LogOnce("inplace", "loot: Add stored the struct without its fields; wrote LootPoints/LootTable in place: %s (LootPoints now %s)",
                                    OkW and "ok" or tostring(ErrW), tostring(PtsNow))
                            end
                            R.Added = R.Added + 1
                            local Pts = -1
                            pcall(function() Pts = Back.LootPoints end)
                            Log("loot: tag %s added: budget %s (wanted %d), donor %s", Tag, tostring(Pts), Points, tostring(Src))
                            if OwnTable then
                                -- UE4SS Lua has no AddToRoot / SetFlags (only HasAnyFlags / HasAnyInternalFlags), so the map's
                                -- DataTable is kept alive the only way Lua can: by the UPROPERTY reference in GameConfig.LootArray
                                -- (a TMap<FGameplayTag, FPRLootTableConfig> on a live data asset is traversed by the GC). Pin the
                                -- Lua wrapper too, and log the root-set bit (EInternalObjectFlags::RootSet = 1<<30) once per table.
                                C.KeepAlive[Tag] = OwnTable
                                local Ok3, Root = pcall(function() return OwnTable:HasAnyInternalFlags(0x40000000) end)
                                local Ok4, TblBack = pcall(function() return Back.LootTable end)
                                Log("loot: tag %s: custom table %s RootSet flag %s; referenced from LootArray: %s", Tag,
                                    ClassNameOf(OwnTable) .. " " .. tostring(T.table_asset), Ok3 and tostring(Root) or "unreadable",
                                    (Ok4 and Valid(TblBack)) and "yes (GC-reachable)" or "no")
                            end
                        else
                            R.Failed = R.Failed + 1
                            Log("loot: tag %s: TMap:Add returned but Find does not see it", Tag)
                        end
                    end
                end
            end
        end
    end
    C.Once = true
    C.Manifest = Manifest
    Log("loot manifest registered: LootArray %d -> %d entries (%d added, %d already present, %d without donor, %d failed, %d custom tables)",
        R.Before, TMapCount(M), R.Added, R.Skipped, R.NoDonor, R.Failed, R.Own)
    return R.Added
end

-- Every APRBasicActor whose outer is the streamed level
local function BasicActorsIn(Stream)
    local Out = {}
    local Level = Stream:GetLoadedLevel()
    if not Valid(Level) then return Out end
    local LA = Level:GetAddress()
    local All = FindAllOf("PRBasicActor")
    if not All then return Out end
    for _, A in ipairs(All) do
        if Valid(A) and A:GetOuter():GetAddress() == LA then table.insert(Out, A) end
    end
    return Out
end

local function CountByClass(Acts)
    local C = {}
    for _, A in ipairs(Acts) do
        if Valid(A) then
            local N = ClassNameOf(A)
            C[N] = (C[N] or 0) + 1
        end
    end
    return C
end

local function SortedKeys(T)
    local K = {}
    for k in pairs(T) do table.insert(K, k) end
    table.sort(K)
    return K
end

-- One pass: call Fn(Args) on every actor in Acts that passes Filter and is still valid. St = {I, C} lives in the caller's context:
-- a native error in a call (not catchable by pcall) aborts the step, the step is re-run and resumes after that actor.
local function ActivationPass(Acts, Fn, Args, Filter, St)
    St.I = St.I or 0
    St.C = St.C or { Ok = 0, NoFunc = 0, Failed = 0, Dead = 0 }
    local C = St.C
    if St.I > 0 then Log("activate: %s: resuming after actor #%d (aborted by a native error)", Fn, St.I) end
    while St.I < #Acts do
        St.I = St.I + 1
        local A = Acts[St.I]
        if not Filter or Filter(A) then
            if not Valid(A) then
                C.Dead = C.Dead + 1
            else
                local Name = A:GetFName():ToString()
                local Cls = ClassNameOf(A)
                C.Failed = C.Failed + 1                -- counted as failed until the call returns (undone below)
                local Found, Ok, Res = CallUF(A, Fn, (table.unpack or unpack)(Args or {}))
                C.Failed = C.Failed - 1
                if not Found then
                    C.NoFunc = C.NoFunc + 1
                    if C.NoFunc <= 10 then Log("activate: %s -> %s (%s): NO SUCH FUNCTION", Fn, Name, Cls) end
                elseif Ok then
                    C.Ok = C.Ok + 1
                    if C.Ok <= 25 or not Valid(A) or Name:sub(1, 3) == "G2_" then
                        Log("activate: %s -> %s (%s): called%s%s", Fn, Name, Cls, Res ~= nil and (" = " .. tostring(Res)) or "",
                            Valid(A) and "" or "; actor DESTROYED itself")
                    end
                else
                    C.Failed = C.Failed + 1
                    if C.Failed <= 10 then Log("activate: %s -> %s (%s): ERROR %s", Fn, Name, Cls, tostring(Res)) end
                end
            end
        end
    end
    Log("activate: %s: %d called, %d without the function, %d errors, %d already gone", Fn, C.Ok, C.NoFunc, C.Failed, C.Dead)
    return C
end

local function ActivationSteps(Map, Stream, Ctx)
    local function Alive()
        if Valid(Stream) and CallBool(Stream, "IsLevelVisible") then return true end
        Log("activate: step skipped (map gone)")
        return false
    end
    local function IsLoot(A) return IsClassNamed(A, LootBaseClass) end
    -- The native APRLootSpawner::OnLevelPrepare arms a distance timer that calls SpawnLoot once the player is within
    -- GameConfig.LootSpawnDistance, so SpawnLoot is not called here (a second call would spawn every item twice). The passes are
    -- OnLevelPrepare + GenerateLoot only, and OnLevelPrepare is skipped for a node that already spawned (saved items from an
    -- earlier visit), which it would re-arm.
    local function NotPreSpawned(A)
        local Ok, Addr = pcall(function() return A:GetAddress() end)
        return not (Ok and Ctx.PreSpawned and Ctx.PreSpawned[Addr])
    end
    local function PassStep(Key, Fn, Args, Filter)
        return { Pass = true, Run = function()
            if not Alive() then Ctx[Key] = Ctx[Key] or { Ok = 0, Failed = 0 }; return end
            local St = Ctx[Key .. "St"]
            if not St then St = {}; Ctx[Key .. "St"] = St end
            St.C = St.C or { Ok = 0, NoFunc = 0, Failed = 0, Dead = 0 }
            Ctx[Key] = St.C
            ActivationPass(Ctx.Acts, Fn, Args and Args(Ctx) or nil, Filter, St)
        end }
    end
    local function TagArgs(C) return { C.Tag } end
    return {
        { Run = function()
            Ctx.T0 = os.clock()
            if not Alive() then return end
            Ctx.TagName = CurrentLevelTagName()
            Ctx.Tag = { TagName = FName(Ctx.TagName) }
            Ctx.Acts = BasicActorsIn(Stream)
            local Before = CountByClass(Ctx.Acts)
            Ctx.Before = Before
            Log("activate: %d APRBasicActor(s) in %s; level tag %s", #Ctx.Acts, Map.Level, Ctx.TagName)
            for _, N in ipairs(SortedKeys(Before)) do Log("activate:   %s x %d", N, Before[N]) end
            Ctx.PreSpawned, Ctx.PreSpawnedN = {}, 0
            for _, A in ipairs(Ctx.Acts) do
                if Valid(A) and IsLoot(A) then
                    local Ok, N = pcall(function() return A.SpawnedItems:GetArrayNum() end)
                    if Ok and (N or 0) > 0 then
                        Ctx.PreSpawned[A:GetAddress()] = true
                        Ctx.PreSpawnedN = Ctx.PreSpawnedN + 1
                    end
                end
            end
            Log("activate: %d loot node(s) already spawned their items (no OnLevelPrepare for them)", Ctx.PreSpawnedN)
            local Manifest, ManifestPath = LoadLootManifest(Map)
            if Manifest then Log("activate: loot manifest %s", ManifestPath)
            else Log("activate: no loot manifest (tried %s)", ManifestPath) end
            Ctx.Step1Done = true
        end },
        { Pass = true, Run = function()
            -- loot tags: TMap:Add into GameConfig.LootArray (a native error here only loses this step)
            if not Alive() then return end
            local Manifest = LoadLootManifest(Map)
            local Ok, Err = pcall(RegisterLootTags, Map, Manifest)
            if not Ok then Log("activate: RegisterLootTags failed: %s", tostring(Err)) end
        end },
        -- Order of the game's level-start chain. An actor that destroys itself in OnLevelPrepare
        -- (generator excluded in the save) is skipped by the later passes through the Valid check.
        PassStep("Prep", "OnLevelPrepare", TagArgs, NotPreSpawned),
        PassStep("Gen", "GenerateLoot", nil, IsLoot),
        -- (no SpawnLoot pass: the native distance check spawns each node's items once)
        PassStep("Start", "OnLevelStarted", TagArgs),
        PassStep("Game", "OnGameStarted"),
        PassStep("Trans", "OnTransitionEnd"),
        { Run = function()
            local Acts = Ctx.Acts or {}
            local After = CountByClass(Acts)
            Log("activate: summary per class (before -> alive after):")
            for _, N in ipairs(SortedKeys(Ctx.Before or {})) do
                Log("activate:   %s: %d -> %d%s", N, Ctx.Before[N], After[N] or 0, (After[N] or 0) < Ctx.Before[N] and "  (destroyed itself)" or "")
            end
            local Z = { Ok = 0, Failed = 0 }
            local P, G, S, St, Gm, T = Ctx.Prep or Z, Ctx.Gen or Z, Ctx.Spawn or Z, Ctx.Start or Z, Ctx.Game or Z, Ctx.Trans or Z
            Log("activate: done in %.0f ms; level tag %s; basic actors %d; OnLevelPrepare %d, GenerateLoot %d, SpawnLoot %d (native), "
                .. "OnLevelStarted %d, OnGameStarted %d, OnTransitionEnd %d; errors %d", (os.clock() - (Ctx.T0 or os.clock())) * 1000,
                Ctx.TagName or "?", #Acts, P.Ok, G.Ok, S.Ok, St.Ok, Gm.Ok, T.Ok,
                P.Failed + G.Failed + S.Failed + St.Failed + Gm.Failed + T.Failed)
        end },
    }
end

-- Once per load: ActivateDelayMs after the player is settled, if this load is still the current one and still visible
local function ScheduleActivation(Map)
    if not Opt(Map, "ActivateGameplay", true) then
        Log("activate: off (ActivateGameplay = false)")
        return
    end
    if not Current or Current.Activated then return end
    Current.Activated = true
    local Stream = Current.Stream
    local T0w = Now()
    local Ctx, Steps = { Next = 0, Tries = {} }, nil
    Every(250, function()
        if not Current or not SameObj(Current.Stream, Stream) or not Valid(Stream) then
            Log("activate: skipped (map unloaded or another load started)")
            return true
        end
        if Now() - T0w < ActivateDelayMs then return false end
        Steps = Steps or ActivationSteps(Map, Stream, Ctx)
        local I = Ctx.Next + 1
        if I > #Steps then return true end
        -- a step that was aborted by a native error is re-run (passes resume where they stopped); the others get 2 attempts
        Ctx.Tries[I] = (Ctx.Tries[I] or 0) + 1
        if Ctx.Tries[I] > (Steps[I].Pass and 300 or 2) then
            Log("activate: step %d given up after %d attempts", I, Ctx.Tries[I] - 1)
            Ctx.Next = I
            return Ctx.Next >= #Steps
        end
        Steps[I].Run()
        Ctx.Next = I
        return I >= #Steps
    end, 400)
end

---------------------------------------------------------------------------------------------------------------------
-- Arrival
---------------------------------------------------------------------------------------------------------------------
-- Watches whether the player stays at the arrival point after the teardown (the Hub's snap-back shows up here)
local function StayCheck(Arrive)
    local At = { 1, 3, 6, 10, 20 }
    local T0w = Now()
    local Step, Elapsed = 1, 0
    Every(500, function()
        if not Current or Current.Phase ~= "active" then return true end
        Elapsed = math.floor(Now() - T0w)
        if Elapsed < At[Step] * 1000 then return false end
        local L = PawnLoc()
        if L then
            local D = Dist3D(L, Arrive)
            Log("stay check +%ds: player at %s, %.0f m from the arrival point: %s", At[Step], FmtV(L), D / 100,
                D < 30000 and "stayed" or "MOVED AWAY (snap-back?)")
            if D >= 30000 then return true end
        end
        Step = Step + 1
        return Step > #At
    end)
end

local function Arrive(Map, M, Rec)
    if Rec then
        TeleportPlayer(Rec.Loc, Rec.Rot, "arrival marker")
    else
        Log("no start marker tagged '%s' in %s (or no player pawn); you stay where you are", Map.StartTag, Map.Level)
    end
    ArmExits(M)
    Current.Phase = "active"
    if Rec and Current.TornDown then StayCheck(Rec.Loc) end
    ScheduleActivation(Map)
end

---------------------------------------------------------------------------------------------------------------------
-- Hub teardown (streaming mode; untested in game)
---------------------------------------------------------------------------------------------------------------------
-- Staging point: a TargetPoint east of StagingMaxWestX (positions west of about X -30000 snap back to the Hub while it
-- is loaded), preferring itr:tp:* / itr:arrive* / itr:exit_id* markers, nearest to itr:player_start.
local function FindStaging(M)
    local Ref = M.Start and M.Start.Loc or nil
    local Best, BestD, BestTier = nil, 1e30, 3
    for _, Rec in ipairs(M.All) do
        if Rec ~= M.Start and Rec.Loc.X > StagingMaxWestX then
            local Tier = 2
            for _, T in ipairs(Rec.Tags) do
                if T:sub(1, 7) == "itr:tp:" or T:sub(1, 10) == "itr:arrive" or T:sub(1, 11) == "itr:exit_id" then Tier = 1 end
            end
            local D = Ref and Dist3D(Rec.Loc, Ref) or 0
            if Tier < BestTier or (Tier == BestTier and D < BestD) then
                Best, BestD, BestTier = Rec, D, Tier
            end
        end
    end
    if not Best and M.Start and M.Start.Loc.X > StagingMaxWestX then
        Best, BestD = M.Start, 0                 -- the start itself is east of the limit: stand there
    end
    return Best, BestD
end

-- Unload every streaming level except the map's (and any that holds the player), wait until they are gone, then arrive.
local function UnloadHub(Map, M, Arrival, Staging)
    local T0 = os.clock()
    local World = UEHelpers.GetWorld()
    local Pawn, PC = UEHelpers.GetPlayer(), UEHelpers.GetPlayerController()
    local Levels = {}
    local Idle = 0
    for _, S in ipairs(StreamingLevels(World)) do
        if not SameObj(S, Current.Stream) then
            if not StreamActive(S) then
                Idle = Idle + 1
            else
                local L = S:GetLoadedLevel()
                local H = {
                    S = S, Package = PkgName(S), Name = ShortName(PkgName(S)),
                    WasLoaded = CallBool(S, "IsLevelLoaded"), WasVisible = CallBool(S, "IsLevelVisible"),
                    WasShouldLoad = PropBool(S, "bShouldBeLoaded"), WasShouldVisible = PropBool(S, "bShouldBeVisible"),
                    Scenario = Valid(L) and PropBool(L, "bIsLightingScenario") or false,
                }
                if Valid(L) then
                    -- a level holding the player's pawn / controller stays
                    local LA = L:GetAddress()
                    for _, O in ipairs({ Pawn, PC }) do
                        if Valid(O) and O:GetOuter():GetAddress() == LA then
                            H.Kept = true
                            Log("Hub teardown: player's %s lives in %s: that level is KEPT", O:GetFullName(), H.Name)
                        end
                    end
                end
                table.insert(Levels, H)
            end
        end
    end
    local Count = 0
    for _, H in ipairs(Levels) do
        Log("Hub teardown: %s %s (%s): %s%s", H.Kept and "KEEP" or "unload", H.Name, H.Package, StreamBitsText(H.S),
            H.Scenario and ", lighting scenario" or "")
        if not H.Kept then
            H.S:SetShouldBeVisible(false)
            H.S:SetShouldBeLoaded(false)
            Count = Count + 1
        end
    end
    Current.HubLevels = Levels
    Current.TornDown = true
    Log("Hub teardown: %d level(s) unloading, %d kept, %d streaming level(s) already idle", Count, #Levels - Count, Idle)
    Current.Phase = "tearing"
    local T0w = Now()
    local Waited = 0
    Every(250, function()
        if not Current or not Valid(Current.Stream) then return true end
        Waited = math.floor(Now() - T0w)
        local Left = 0
        for _, H in ipairs(Levels) do
            if not H.Kept and not H.Gone then
                if not Valid(H.S) or not (CallBool(H.S, "IsLevelLoaded") or CallBool(H.S, "IsLevelVisible")) then
                    H.Gone = true
                    Log("Hub teardown: %s unloaded after %d ms", H.Name, Waited)
                else
                    Left = Left + 1
                end
            end
        end
        -- loaded but hidden and not requested for 5 s (L_Transition after a -nohmd start): an unload that never completes. A level
        -- that is not visible has no collision and runs nothing, so it cannot hold or move the player: counted as gone.
        if Left > 0 and Waited > 5000 then
            for _, H in ipairs(Levels) do
                if not H.Kept and not H.Gone and Valid(H.S) and not CallBool(H.S, "IsLevelVisible")
                    and not PropBool(H.S, "bShouldBeLoaded") and not PropBool(H.S, "bShouldBeVisible") then
                    H.Gone = true
                    Left = Left - 1
                    Log("Hub teardown: %s is loaded but hidden and not requested after %d ms (%s); counted as gone", H.Name, Waited,
                        StreamBitsText(H.S))
                end
            end
        end
        if Left > 0 and Waited < 30000 then return false end
        for _, H in ipairs(Levels) do
            if not H.Kept and not H.Gone then
                Log("Hub teardown: %s still there after %d ms (%s)  <-- did not unload", H.Name, Waited, StreamBitsText(H.S))
            end
        end
        local L = PawnLoc()
        local Ground = OnMapGround(Current.Stream)
        Log("Hub teardown done after %d ms: %d unloaded, %d left; player at %s, on map ground: %s", Waited,
            Count - Left, Left, L and FmtV(L) or "?", tostring(Ground))
        if Left > 0 then
            Log("Hub teardown: NOT moving to the arrival marker (%d Hub level(s) did not unload, on map ground: %s); "
                .. "the player stays at the staging point", Left, tostring(Ground))
            ArmExits(M)
            Current.Phase = "active"
            ScheduleActivation(Map)              -- activate whatever the teardown did
            return true
        end
        Log("Hub teardown: %.1f s since the map became visible; moving to the arrival marker", os.clock() - T0)
        Arrive(Map, M, Arrival)
        return true
    end)
end

-- (a) to the staging point, (b) confirm the player stands on the map, (c) unload the Hub, (d) arrive
local function Teardown(Map, M)
    local Arrival = ChooseArrival(Map, M)
    local Staging, StageD = FindStaging(M)
    if not Staging then
        Log("Hub teardown skipped: %s has no TargetPoint east of X %.0f to stand on while the Hub unloads; plain arrival",
            Map.Level, StagingMaxWestX)
        if Map.HideLightingScenario then SetLightingScenariosHidden(UEHelpers.GetWorld(), true) end
        Arrive(Map, M, Arrival)
        return
    end
    Log("Hub teardown: staging point %s (%.0f m from the start marker)", FmtV(Staging.Loc), StageD / 100)
    Current.Phase = "staging"
    TeleportPlayer(Staging.Loc, Staging.Rot, "staging point")
    local T0w = Now()
    local Waited, Stable, Logged = 0, {}, 0
    Every(250, function()
        if not Current or not Valid(Current.Stream) then return true end
        Waited = math.floor(Now() - T0w)
        -- Standing on the map = the pawn has held still at the staging point for 1.5 s (the Hub is far away from it, so the
        -- only ground there is the map's; a snap-back to the Hub would move the pawn). The movement base is logged for info.
        local Confirmed, L = StablePosition(Stable, Staging.Loc, 400, 1000, 1500)
        if Confirmed then
            local Ground = OnMapGround(Current.Stream)
            Log("Hub teardown +%d ms: player at %s held the staging point 1.5 s (movement base on map: %s); unloading the Hub",
                Waited, L and FmtV(L) or "?", tostring(Ground))
            UnloadHub(Map, M, Arrival, Staging)
            return true
        end
        if Waited >= 2000 * (Logged + 1) and Logged < 7 then
            Logged = Logged + 1
            Log("Hub teardown: waiting %d ms; player at %s, %s from the staging point", Waited, L and FmtV(L) or "?",
                L and string.format("%.0f cm", Dist3D(L, Staging.Loc)) or "?")
        end
        if Waited >= 15000 then
            Log("Hub teardown skipped: the player did not hold the staging point within 15 s (player at %s)", L and FmtV(L) or "?")
            if Map.HideLightingScenario then SetLightingScenariosHidden(UEHelpers.GetWorld(), true) end
            Arrive(Map, M, Arrival)
            return true
        end
        return false
    end)
end

---------------------------------------------------------------------------------------------------------------------
-- Native level (config Native = true; one native map per loader mod, see README.md)
---------------------------------------------------------------------------------------------------------------------
-- How the game finds a level, read from the 2.7.2 exe (static disassembly, not a guess):
--   * USystemConfig::IsLevelTagValid / GetLevelConfig walk SystemConfig.LevelConfigurations (TArray<FLevelConfig>, 0x70 bytes
--     a row) on every call and compare the tag's FName. Nothing is cached, so a row appended at runtime is seen.
--   * ULevelManager::LoadSublevel(Name) calls UGameplayStatics::GetStreamingLevel(Name): every call walks World.StreamingLevels
--     and takes the first entry whose world-asset package name ends with "/<Name>" (case-insensitive). No cache either.
--   * FLGeneral::GetActorLevelTag (used by IsActorInLevel, PlayerStart search, zone gates) maps an actor to a level by the NAME
--     OF ITS UWORLD object (not the package) against MainSublevel / StaticSublevels.
-- So: MainSublevel = the map's world name (short name of Map.Level, e.g. L_Example), and the streaming entry made with
-- LevelStreaming::CreateInstance(<that name>) gets the package "<source dir>/L_Example" (suffix match) while the loaded
-- world keeps its own object name L_Example (actor -> level tag match). PackageNameToLoad points it at the real package.
--
-- Registration (once per session for the row and map centre, once per world for the streaming entry), all fail-safe:
--   (1) streaming entry, unloaded and hidden; (2) row: TArray grows by one zeroed element (UE4SS c62ada0 TArray:__index past the
--   end = FScriptArray::AddZeroed through the game's GMalloc), fields copied from a donor zone row and overridden, the tag written
--   LAST, then checked: earlier rows unchanged and the game's IsLevelTagValid says yes; (3) MapPointsConfig.levelCenters entry;
--   (4) the loot manifest (tables loaded through AssetRegistryHelpers.GetAsset and held by GameConfig.LootArray).
-- If any of (1)/(2) fails, native entry stays off for the session (logged), nothing else changes.
--
-- Saves: NativeSaves = true (the showcase config) copies the donor zone's autosave, save-on-load, save-on-exit and sleeping flags,
-- so the level saves like a stock zone and a save made in it loads back into it (the registration at startup runs before the
-- main menu offers the save). Apart from the progression unlock (MissionsProgression), the loader does not touch saves.
-- NativeSaves = false turns those four flags off (no save file is written while the game is in the level).
local NativeState = { Ready = false, Failed = nil, RowDone = false, CenterDone = false, GatesDone = false, LootDone = false, WorldAddr = nil,
                      Entry = nil, Map = nil, Tag = nil, Sub = nil, RowFill = nil, Checks = 0, Logged = {} }
local NativeTrip = nil       -- the current native transfer in progress { Map, T0, Phase }
-- Loot tables: the map's DataTables must never sit in GameConfig.LootArray while nothing keeps them
-- alive. GameConfig is loaded at engine start (GC does not walk its references), so a table referenced only from LootArray is
-- collected and ItemsManager::GetLootForTable later reads the dead pointer (access violation). The tags are
-- registered on the donor (stock) tables; while the map's level is loaded, its table holder keeps the map's
-- tables alive and the entries point at them; before the level goes they point back at the donor tables.
local NativeLootOwn = false

local function NativeMap()
    for _, M in ipairs(Config.Maps) do
        if Opt(M, "Native", true) then return M end
    end
    return nil
end

local function NativeTagOf(Map) return Map.NativeTag or ("Level.Zone." .. Map.Name) end
local function NativeSubOf(Map) return Map.NativeSublevel or ShortName(Map.Level) end
local function TagStruct(Name) return { TagName = FName(Name) } end

local function GetSystemConfig()
    local Ok, SC = pcall(function()
        local C = StaticFindObject("/Script/IntoTheRadius.Default__SystemConfig")
        if not Valid(C) then return nil end
        return C:GetSystemConfig()
    end)
    if Ok and Valid(SC) then return SC end
    return nil
end

-- Live (non-default) instances of a class, by short class name
local function LiveOf(ClassName)
    local Out = {}
    local Ok, All = pcall(FindAllOf, ClassName)
    if not Ok or not All then return Out end
    for _, O in ipairs(All) do
        if Valid(O) then
            local Okn, N = pcall(function() return O:GetFName():ToString() end)
            if Okn and type(N) == "string" and N:sub(1, 9) ~= "Default__" then table.insert(Out, O) end
        end
    end
    return Out
end

-- FindAllOf walks every object; the game mode / game data lookups are cached for 2 s (and re-checked with IsValid) so the
-- 100 ms transfer loop does not scan the object array while the level streams
local LookCache = {}
local function Cached(Key, Fn)
    local C = LookCache[Key]
    if C and Valid(C.O) and Now() - C.T < 2000 then return C.O end
    local O = Fn()
    LookCache[Key] = O and { O = O, T = Now() } or nil
    return O
end

-- Cheap lookups first (no object scan, about 0.1 ms; a FindAllOf costs 11-14 ms of game thread, a visible hitch in VR): the world's authority game mode is a
-- property read, the live game data is the static UPRGameData::GetGameData (out parameter, filled by name). Each falls back to the scan when it gives nothing usable.
local PRGameModeClass = nil
local function CheapGameMode()
    local Ok, GM = pcall(function() return UEHelpers.GetGameModeBase() end)
    if not Ok or GM == nil or not Valid(GM) then return nil end
    if not Valid(PRGameModeClass) then
        local OkC, C = pcall(StaticFindObject, "/Script/IntoTheRadius.PRGameMode")
        if not OkC or not Valid(C) then return nil end
        PRGameModeClass = C
    end
    local OkI, Is = pcall(function() return GM:IsA(PRGameModeClass) end)
    if OkI and Is == true then return GM end
    return nil
end

local GameDataStatic = nil
local function CheapGameData()
    if not Valid(GameDataStatic) then
        local Ok, C = pcall(StaticFindObject, "/Script/IntoTheRadius.Default__PRGameData")
        if not Ok or not Valid(C) then return nil end
        GameDataStatic = C
    end
    local Out = {}
    local Ok = pcall(function() GameDataStatic:GetGameData(Out) end)
    local GD = Ok and Out.GameData or nil
    if GD ~= nil and Valid(GD) then return GD end
    return nil
end

local function GetGameMode()
    return Cached("gm", function()
        local GM = CheapGameMode()
        if GM then LogOnce("gmcheap", "lookup: game mode from the world's authority game mode (no object scan)"); return GM end
        LogOnce("gmscan", "lookup: game mode by object scan (no authority game mode of the PRGameMode class yet)")
        return LiveOf("PRGameMode")[1]
    end)
end

-- The game data that holds the current level: the live PRGameData whose CurrentLevelTag is set (others: none, or a save preview)
local GameDataLogged = false
local function GetGameDataUncached()
    local Cheap = CheapGameData()
    if Cheap then
        local Ok, N = pcall(function() return Cheap.CurrentLevelTag.TagName:ToString() end)
        if Ok and type(N) == "string" and N ~= "None" and N ~= "" then
            LogOnce("gdcheap", "lookup: game data from the static GetGameData (no object scan)")
            return Cheap
        end
    end
    LogOnce("gdscan", "lookup: game data by object scan (the static GetGameData gave none with a level tag yet)")
    local All = LiveOf("PRGameData")
    local Best = nil
    local Seen = {}
    for _, GD in ipairs(All) do
        local Ok, N = pcall(function() return GD.CurrentLevelTag.TagName:ToString() end)
        table.insert(Seen, string.format("%s=%s", GD:GetFName():ToString(), Ok and tostring(N) or "?"))
        if not Best and Ok and type(N) == "string" and N ~= "None" and N ~= "" then Best = GD end
    end
    if not GameDataLogged and #All > 0 then
        GameDataLogged = true
        Log("native: PRGameData instance(s): %s", table.concat(Seen, ", "))
    end
    return Best or All[1]
end

local function GetGameData()
    return Cached("gd", GetGameDataUncached)
end

-- The game's current level tag as a string, or nil when it can't be read
local function LevelTagNow()
    local GD = GetGameData()
    if not GD then return nil end
    local Ok, N = pcall(function() return GD.CurrentLevelTag.TagName:ToString() end)
    if Ok and type(N) == "string" and N ~= "" then return N end
    return nil
end

-- TransferToLevel and GetIsInTransition are functions of the game mode's INTERFACES (IPRGameMode, IPRGameModeNative,
-- implemented in C++), not of its class, so GM:TransferToLevel finds nothing ("UObject instance is nullptr"). The interface
-- UFunction is called with the game mode as context: ProcessEvent -> UFunction::Invoke moves the context to the interface
-- address for functions whose outer is an interface.
local IfaceFns = {}
local function IfaceFn(Path)
    local F = IfaceFns[Path]
    if F and Valid(F) then return F end
    local Ok, O = pcall(StaticFindObject, Path)
    if Ok and Valid(O) then
        IfaceFns[Path] = O
        return O
    end
    return nil
end
local TransferFnPath = "/Script/IntoTheRadius.IPRGameMode:TransferToLevel"
local InTransitionFnPath = "/Script/IntoTheRadius.IPRGameModeNative:GetIsInTransition"

-- GM:TransferToLevel(LevelTag, LocationTag) through the interface function. Returns the game's bool, or nil + reason.
-- (A native error inside the call is not catchable by pcall; callers run it from a loop tick or the key handler.)
local function CallTransfer(GM, LevelTag, LocationTag)
    if not Valid(GM) then return nil, "no PRGameMode" end
    local Fn = IfaceFn(TransferFnPath)
    if not Fn then return nil, "interface function " .. TransferFnPath .. " not found" end
    local Ok, Res = pcall(function() return Fn(GM, TagStruct(LevelTag), TagStruct(LocationTag or "None")) end)
    if not Ok then return nil, "error " .. tostring(Res) end
    return Res == true, nil
end

local function InTransition(GM)
    GM = GM or GetGameMode()
    if not Valid(GM) then return false end
    local Fn = IfaceFn(InTransitionFnPath)
    if not Fn then return false end
    local Ok, Res = pcall(function() return Fn(GM) end)
    return Ok and Res == true
end

local function EndsWithI(S, Suffix)
    S, Suffix = S:lower(), Suffix:lower()
    return #S >= #Suffix and S:sub(-#Suffix) == Suffix
end

-- The streaming entry GetStreamingLevel would return for Sub (first package name ending in "/Sub"), or nil
local function FindNativeEntry(World, Sub)
    for _, S in ipairs(StreamingLevels(World)) do
        if EndsWithI(PkgName(S), "/" .. Sub) then return S end
    end
    return nil
end

local function NativeLogOnce(Key, fmt, ...)
    if NativeState.Logged[Key] then return end
    NativeState.Logged[Key] = true
    Log(fmt, ...)
end

local function TagsOfRows(Arr)
    local Out = {}
    pcall(function()
        Arr:ForEach(function(_, E) table.insert(Out, E:get().LevelTag.TagName:ToString()) end)
    end)
    return Out
end

-- (1) streaming entry for the current world
local function NativeEnsureEntry(World)
    local Sub, Map = NativeState.Sub, NativeState.Map
    local Have = FindNativeEntry(World, Sub)
    if Have then
        local Want = Map.Level:lower()
        local Pkg = PkgName(Have)
        local ToLoad = "?"
        pcall(function() ToLoad = Have.PackageNameToLoad:ToString() end)
        if ToLoad:lower() ~= Want and Pkg:lower() ~= Want then
            NativeLogOnce("foreign", "native: another streaming entry already answers to '%s' (%s, loads %s); native entry disabled", Sub, Pkg, ToLoad)
            NativeState.Failed = "foreign streaming entry " .. Pkg
            return false
        end
        NativeState.Entry = Have
        return true
    end
    local Source = nil
    for _, S in ipairs(StreamingLevels(World)) do
        if S:GetClass():GetFName():ToString() == "LevelStreamingDynamic" then Source = S; break end
    end
    if not Source then
        NativeLogOnce("nosource", "native: no LevelStreamingDynamic in this world yet; waiting")
        return false
    end
    local Ok, E = pcall(function() return Source:CreateInstance(Sub) end)
    if not Ok or not Valid(E) then
        Log("native: CreateInstance(%s) failed (%s); native entry disabled", Sub, tostring(E))
        NativeState.Failed = "CreateInstance failed"
        return false
    end
    E.PackageNameToLoad = FName(Map.Level)
    E.LevelTransform = { Rotation = { X = 0, Y = 0, Z = 0, W = 1 }, Translation = { X = 0, Y = 0, Z = 0 },
                         Scale3D = { X = 1, Y = 1, Z = 1 } }
    local Pkg = PkgName(E)
    if not EndsWithI(Pkg, "/" .. Sub) or not SameObj(FindNativeEntry(World, Sub), E) then
        Log("native: the new streaming entry is '%s', which the game's lookup of '%s' would not find first; native entry disabled", Pkg, Sub)
        NativeState.Failed = "streaming entry name mismatch"
        return false
    end
    NativeState.Entry = E
    Log("native: streaming entry %s -> %s created (unloaded; the game's LevelManager loads it by the name %s)", Pkg, Map.Level, Sub)
    return true
end

-- (2) the level row. Returns true when the row is in place and the game accepts the tag.
local function NativeEnsureRow(SC)
    local Map, Tag, Sub = NativeState.Map, NativeState.Tag, NativeState.Sub
    local Arr = SC.LevelConfigurations
    local Ok0, Valid0 = pcall(function() return SC:IsLevelTagValid(TagStruct(Tag)) end)
    if Ok0 and Valid0 == true and not NativeState.RowFill then
        Log("native: %s is already a valid level tag (registered earlier this session)", Tag)
        return true
    end
    local Fill = NativeState.RowFill
    if not Fill then
        -- Values to copy, read BEFORE the array grows (growing can move the rows)
        local DonorTag = Opt(Map, "NativeDonorTag", "Level.Zone.Buffer")
        local D = nil
        local Before = TagsOfRows(Arr)
        local N = #Before
        if N == 0 then
            Log("native: SystemConfig.LevelConfigurations is empty or unreadable; waiting")
            return false
        end
        for I = 1, N do
            if Before[I] == DonorTag then
                pcall(function()
                    local R = Arr[I]
                    D = { StopGameTimeTick = R.StopGameTimeTick, InventoryAllowed = R.InventoryAllowed, SleepAllowed = R.SleepAllowed,
                          GenMin = R.AllowedGenerators.Min, GenMax = R.AllowedGenerators.Max, SaveOnExit = R.SaveOnExit,
                          Autosave = R.Autosave, SaveOnLoad = R.SaveOnLoad, MapScale = R.MapScale, FullPlayerStats = R.FullPlayerStats }
                end)
            end
        end
        if not D then
            Log("native: donor row %s not found; using built-in zone defaults", DonorTag)
            D = { StopGameTimeTick = false, InventoryAllowed = true, SleepAllowed = true, GenMin = 0, GenMax = 0, SaveOnExit = true,
                  Autosave = true, SaveOnLoad = true, MapScale = 1.0, FullPlayerStats = false }
        end
        local Empty = nil
        pcall(function() Empty = SC.EmptyMapMaterial end)
        local Saves = Opt(Map, "NativeSaves", false)
        Fill = { N = N, Before = Before, D = D, Empty = Empty, Saves = Saves, Grown = false }
        NativeState.RowFill = Fill
        Log("native: level table has %d rows; adding %s (main sublevel %s, flags from %s, saves %s)", N, Tag, Sub, DonorTag,
            Saves and "ON" or "off")
    else
        Log("native: resuming the row fill (the previous attempt was aborted by a native error)")
    end
    local Now1 = Arr:GetArrayNum()
    local Row
    if Now1 == Fill.N then
        Row = Arr[Fill.N + 1]                    -- grows the array by one zeroed row
        Fill.Grown = true
    elseif Now1 == Fill.N + 1 and Fill.Grown then
        Row = Arr[Fill.N + 1]                    -- resume: the zeroed / half-written row of the aborted attempt
    else
        Log("native: level table changed size unexpectedly (%d -> %d); not touching it; native entry disabled", Fill.N, Now1)
        NativeState.Failed = "level table size changed"
        return false
    end
    if Arr:GetArrayNum() ~= Fill.N + 1 then
        Log("native: could not grow the level table (%d rows); native entry disabled", Arr:GetArrayNum())
        NativeState.Failed = "TArray growth failed"
        return false
    end
    local D, Saves = Fill.D, Fill.Saves
    -- a zeroed FText has no text data; FText:SetString (UE4SS) builds a new one through the game's FText(FString&&) and
    -- overwrites the slot without reading the old one, so this is safe on the zeroed row
    Row.LevelName = FText(Map.DisplayName or Map.Name)
    Row.MainSublevel = FName(Sub)
    Row.StopGameTimeTick = D.StopGameTimeTick == true
    Row.ReloadOnTideHappening = Opt(Map, "NativeReloadOnTide", false) == true
    Row.InventoryAllowed = D.InventoryAllowed ~= false
    Row.SleepAllowed = Saves and (D.SleepAllowed == true) or false
    Row.AllowedGenerators = { Min = math.floor(tonumber(D.GenMin) or 0), Max = math.floor(tonumber(D.GenMax) or 0) }
    -- The game keeps only AllowedGenerators of the level's rifts and removes the rest in OnLevelPrepare ("Excluded from this cruel world"); the donor zone allows 3,
    -- so a map with 12 rifts would run 3. NativeGenerators = the number of rifts the map places (written by the generator, loader_sync.py).
    local WantGen = tonumber(Opt(Map, "NativeGenerators", nil))
    if WantGen and WantGen >= 0 then
        Row.AllowedGenerators = { Min = math.floor(WantGen), Max = math.floor(WantGen) }
    end
    Row.SaveOnExit = Saves and (D.SaveOnExit == true) or false
    Row.Autosave = Saves and (D.Autosave == true) or false
    Row.SaveOnLoad = Saves and (D.SaveOnLoad == true) or false
    if Valid(Fill.Empty) then
        Row.MapMaterial = Fill.Empty
        Row.MapLegendMaterial = Fill.Empty
    end
    Row.MapScale = tonumber(Opt(Map, "NativeMapScale", D.MapScale)) or 1.0
    Row.MapRotation = tonumber(Opt(Map, "NativeMapRotation", 0.0)) or 0.0
    Row.MaxLevelRadius = tonumber(Opt(Map, "NativeRadius", 250000)) or 250000
    Row.FullPlayerStats = D.FullPlayerStats == true
    Row.LevelTag = TagStruct(Tag)                -- last: until here the row answers to no tag
    NativeState.RowFill = nil
    -- checks: the earlier rows are untouched, the new row reads back, and the game accepts the tag
    local After = TagsOfRows(SC.LevelConfigurations)
    local Damaged = 0
    for I = 1, Fill.N do
        if After[I] ~= Fill.Before[I] then Damaged = Damaged + 1 end
    end
    if Damaged > 0 then
        Log("native: !! %d earlier level row(s) changed while adding ours. The level table in memory is damaged: quit the game "
            .. "without saving and report this. Native entry disabled.", Damaged)
        NativeState.Failed = "level table damaged"
        return false
    end
    local Ok2, V2 = pcall(function() return SC:IsLevelTagValid(TagStruct(Tag)) end)
    if not (Ok2 and V2 == true) then
        Log("native: row added (%d rows) but SystemConfig:IsLevelTagValid(%s) = %s; native entry disabled", #After, Tag, tostring(V2))
        NativeState.Failed = "IsLevelTagValid false"
        return false
    end
    local Back = {}
    pcall(function()
        local R = SC.LevelConfigurations[Fill.N + 1]
        Back = { Main = R.MainSublevel:ToString(), Name = R.LevelName:ToString(), Radius = R.MaxLevelRadius, Auto = R.Autosave,
                 Time = R.StopGameTimeTick, Inv = R.InventoryAllowed }
    end)
    Log("native: level row %d added: %s, main sublevel %s, name '%s', radius %s cm, time stopped %s, inventory %s, autosave %s; "
        .. "IsLevelTagValid = true", Fill.N + 1, Tag, tostring(Back.Main), tostring(Back.Name), tostring(Back.Radius), tostring(Back.Time),
        tostring(Back.Inv), tostring(Back.Auto))
    return true
end

-- (3) map centre: MapPointsConfig.levelCenters[tag] (level <-> world transforms for the handheld map and map points)
local function NativeEnsureCenter()
    local Map, Tag = NativeState.Map, NativeState.Tag
    local MPC = nil
    pcall(function()
        local C = StaticFindObject("/Script/IntoTheRadius.Default__MapPointsConfig")
        if Valid(C) then MPC = C:GetMapPointsConfig() end
    end)
    if not Valid(MPC) then
        Log("native: MapPointsConfig not found; no map centre registered")
        return true
    end
    local M = MPC.levelCenters
    local Key = TagStruct(Tag)
    local C = Opt(Map, "NativeCenter", { X = 0, Y = 0, Z = 0 })
    local Want = { Rotation = { X = 0, Y = 0, Z = 0, W = 1 }, Translation = { X = C.X or 0, Y = C.Y or 0, Z = C.Z or 0 },
                   Scale3D = { X = 1, Y = 1, Z = 1 } }
    if TMapFind(M, Key) == nil then
        local Ok, Err = pcall(function() M:Add(Key, Want) end)
        if not Ok then Log("native: levelCenters:Add failed: %s", tostring(Err)) end
    end
    local Back = TMapFind(M, Key)
    if Back == nil then
        Log("native: map centre for %s not registered (levelCenters has no entry)", Tag)
        return true
    end
    -- c62ada0's TMap:Add stored zeroed values for the loot tags: write the fields into the stored struct in place
    pcall(function()
        Back.Rotation = Want.Rotation
        Back.Translation = Want.Translation
        Back.Scale3D = Want.Scale3D
    end)
    local T = { X = 0, Y = 0, Z = 0 }
    local W = -1
    pcall(function() T = Vec(Back.Translation); W = Back.Rotation.W end)
    Log("native: map centre for %s = %s (rotation W %s, %d level centres)", Tag, FmtV(T), tostring(W), TMapCount(M))
    return true
end

-- (3b) level gates: one stock LevelGates row per return pad, so the tablet map draws the transition markers.
-- MapPointsConfig.LevelGates is a TArray<FGateInfo> (LeadsFrom, LeadsTo, UnlockTrigger, LocationInLevel = cm from the level centre);
-- it grows the way the level table does (index past the end = one zeroed element), the tag written last.
local function NativeEnsureGates()
    local Map, Tag = NativeState.Map, NativeState.Tag
    local Gates = Opt(Map, "NativeGates", nil)
    if type(Gates) ~= "table" or #Gates == 0 then return true end
    local MPC = nil
    pcall(function()
        local C = StaticFindObject("/Script/IntoTheRadius.Default__MapPointsConfig")
        if Valid(C) then MPC = C:GetMapPointsConfig() end
    end)
    if not Valid(MPC) then
        Log("native: MapPointsConfig not found; no gate markers registered")
        return true
    end
    local Arr = MPC.LevelGates
    local Own, Before = 0, Arr:GetArrayNum()
    pcall(function() Arr:ForEach(function(_, E) if E:get().LeadsFrom.TagName:ToString() == Tag then Own = Own + 1 end end) end)
    if Own > 0 then
        Log("native: %d gate row(s) for %s already registered (%d rows)", Own, Tag, Before)
        return true
    end
    local Added = 0
    for I, G in ipairs(Gates) do
        local Ok, Err = pcall(function()
            local Row = Arr[Before + I]                       -- grows the array by one zeroed row
            Row.LeadsTo = TagStruct(G.To or HubLevelTag)
            Row.LocationInLevel = { X = tonumber(G.X) or 0, Y = tonumber(G.Y) or 0, Z = tonumber(G.Z) or 0 }
            Row.LeadsFrom = TagStruct(Tag)                    -- last: until here the row leads from no level (UnlockTrigger stays None = open)
        end)
        if Ok then Added = Added + 1 else Log("native: gate row %d failed: %s", I, tostring(Err)); break end
    end
    local After, Mine, Last = Arr:GetArrayNum(), 0, "?"
    pcall(function()
        Arr:ForEach(function(_, E)
            local R = E:get()
            if R.LeadsFrom.TagName:ToString() == Tag then
                Mine = Mine + 1
                Last = string.format("%s at (%.0f, %.0f, %.0f)", R.LeadsTo.TagName:ToString(), R.LocationInLevel.X, R.LocationInLevel.Y, R.LocationInLevel.Z)
            end
        end)
    end)
    Log("native: gates for %s: %d of %d added (%d -> %d rows), %d read back, last %s", Tag, Added, #Gates, Before, After, Mine, Last)
    return true
end

-- (3c) the tablet picture. The level row shows blank paper (EmptyMapMaterial) while the map's level is not loaded; while it is, the row points
-- at the MaterialInstance on the map board (a StaticMeshActor tagged NativeMapBoardTag): the level's reference keeps it alive, nothing in
-- SystemConfig does. Back to blank paper before the level goes.
local function MapBoardMaterial(Map)
    local BoardTag = Opt(Map, "NativeMapBoardTag", "itr:mapboard")
    local Ok, All = pcall(FindAllOf, "StaticMeshActor")
    if not Ok or not All then return nil end
    for _, A in ipairs(All) do
        if Valid(A) then
            for _, T in ipairs(TagsOf(A)) do
                if T == BoardTag then
                    local Mic = nil
                    pcall(function() Mic = A.StaticMeshComponent:GetMaterial(0) end)
                    if Valid(Mic) then return Mic end
                end
            end
        end
    end
    return nil
end

local function RepointMapPicture(Map, ToEmpty)
    if not Opt(Map, "NativeMapPicture", false) then return false end
    local SC = GetSystemConfig()
    if not SC then return false end
    local Arr = SC.LevelConfigurations
    local Idx = nil
    for I, T in ipairs(TagsOfRows(Arr)) do
        if T == NativeState.Tag then Idx = I end
    end
    if not Idx then
        Log("map picture: no level row for %s", tostring(NativeState.Tag))
        return false
    end
    local New = nil
    if ToEmpty then
        pcall(function() New = SC.EmptyMapMaterial end)
    else
        New = MapBoardMaterial(Map)
        if not Valid(New) then
            Log("map picture: no map board (actor tagged %s) found in the loaded level; the tablet keeps the blank paper",
                Opt(Map, "NativeMapBoardTag", "itr:mapboard"))
            return false
        end
    end
    if not Valid(New) then return false end
    local Row = Arr[Idx]
    Row.MapMaterial = New
    Row.MapLegendMaterial = New
    local Name = "?"
    pcall(function() Name = Row.MapMaterial:GetFName():ToString() end)
    Log("map picture: level row %d %s -> %s (scale %s, rotation %s)", Idx, ToEmpty and "back to blank paper" or "shows the map board's picture", Name,
        tostring(Row.MapScale), tostring(Row.MapRotation))
    return true
end

-- Loot tables and the tablet picture follow the level: both are re-pointed when it loads and put back before it goes
local function RepointOwnTables(Map, ToDonor)
    local N = RepointLootTables(Map, ToDonor)
    local Ok, Err = pcall(RepointMapPicture, Map, ToDonor)
    if not Ok then Log("map picture: error %s", tostring(Err)) end
    return N
end

-- (3d) showcase missions (Scripts/missions.lua, config Missions = { Enabled = true }): category, missions, objective points, the first mission
-- offered at once, and the progression unlock on arrival. Every step is logged; a failure turns only the missions off.
local MissionsMod = nil
local MissionsState = { Inited = false, Registered = false, Pushed = false, Off = false }
local function MissionsCfg() return Config.Missions end
local function MissionsEnabled()
    local C = MissionsCfg()
    return type(C) == "table" and C.Enabled == true and not MissionsState.Off
end

local function MissionsInit()
    if MissionsState.Inited then return MissionsState.Inited == true end
    MissionsState.Inited = "failed"
    local Ok, Mod = pcall(require, "missions")
    if not Ok or type(Mod) ~= "table" then
        Log("missions: module missing or broken (%s); showcase missions are off", tostring(Mod))
        MissionsState.Off = true
        return false
    end
    Mod.Init({ Log = Log, Valid = Valid, TagStruct = TagStruct, TMapFind = TMapFind, LoadAsset = LoadOwnTable, GetGameData = GetGameData,
               GetGameMode = GetGameMode, LevelTagNow = LevelTagNow, InTransition = InTransition, Hub = HubLevelTag, Config = MissionsCfg(), Now = Now })
    if not Mod.LoadManifest(ScriptDir(), NativeState.Map.Name, JsonDecode) then
        MissionsState.Off = true
        return false
    end
    MissionsMod = Mod
    MissionsState.Inited = true
    if Config.MissionTest == true then                          -- autotest only (config_test.lua)
        local OkT, T = pcall(require, "missiontest")
        if OkT and type(T) == "table" then
            local OkS, ErrS = pcall(T.Start, { Log = Log, Valid = Valid, Every = Every, Mod = Mod, GetGameData = GetGameData, GetGameMode = GetGameMode, LevelTagNow = LevelTagNow,
                                               InTransition = InTransition, Hub = HubLevelTag, Now = Now, Config = Config })
            if not OkS then Log("mission test driver failed to start: %s", tostring(ErrS)) end
        else
            Log("mission test driver missing: %s", tostring(T))
        end
    end
    return true
end

-- one tick (1 s loop, game thread): register once, then keep the series going (the keeper throttles itself to one look every 5 s)
local function MissionsTick()
    if not MissionsEnabled() then return end
    if not MissionsInit() then return end
    local LM = GetLevelManager()
    if not LM or (Config.RequireLevelManagerReady ~= false and not LM:IsReady()) or InTransition() then return end
    if not MissionsState.Registered then
        local Ok, Done = pcall(MissionsMod.Register)
        if not Ok then
            Log("missions: registration error %s; showcase missions are off", tostring(Done))
            MissionsState.Off = true
            return
        end
        MissionsState.Registered = Done == true
        return
    end
    if MissionsMod.State().Failed then return end
    local Ok, Err = pcall(MissionsMod.Keep)
    if not Ok then LogOnce("keeperr", "missions: keeper error %s", tostring(Err)) end
end

-- the showcase loaded: set the visited levels of the progression unlock (the player level and the trigger flags are BP_ItrShowcase_Progression; idempotent)
local function MissionsProgression(Why)
    if not MissionsEnabled() or not MissionsMod or MissionsMod.State().Failed then return end
    local Ok, Err = pcall(MissionsMod.ApplyVisitedLevels, Why)
    if not Ok then Log("missions: progression error %s", tostring(Err)) end
end

-- One registration tick (game thread). Returns nothing; NativeState tells the story.
local function NativeRegisterTick()
    local Map = NativeState.Map
    if not Map or NativeState.Failed then return end
    local World = UEHelpers.GetWorld()
    if not Valid(World) then return end
    local WA = World:GetAddress()
    if NativeState.WorldAddr ~= WA then          -- new world (first time, or after a full map change): entry again
        NativeState.WorldAddr = WA
        NativeState.Entry = nil
        NativeState.Ready = false
    end
    if NativeState.Ready then
        if not Valid(NativeState.Entry) then NativeState.Ready = false end
        return
    end
    -- the level manager must be idle (no level load holding a pointer into the level table while it grows)
    local LM = GetLevelManager()
    if not LM then return end
    if Config.RequireLevelManagerReady ~= false and not LM:IsReady() then
        NativeState.Checks = 0
        return
    end
    NativeState.Checks = NativeState.Checks + 1
    if NativeState.Checks < 2 then return end
    local SC = GetSystemConfig()
    if not SC then return end
    if not Valid(NativeState.Entry) and not NativeEnsureEntry(World) then return end
    if not NativeState.RowDone then
        if not NativeEnsureRow(SC) then return end
        NativeState.RowDone = true
    end
    if not NativeState.CenterDone then
        NativeState.CenterDone = true            -- one attempt; a failure is logged and does not block entry
        NativeEnsureCenter()
    end
    if not NativeState.GatesDone then
        NativeState.GatesDone = true             -- one attempt; a failure is logged and does not block entry
        local Ok, Err = pcall(NativeEnsureGates)
        if not Ok then Log("native: gates: error %s", tostring(Err)) end
    end
    if not NativeState.LootDone then
        NativeState.LootDone = true
        local Manifest, Path = LoadLootManifest(Map)
        if Manifest then
            LootCtxOf(Map).Native = true
            local Ok, Err = pcall(RegisterLootTags, Map, Manifest)
            Log("native: loot manifest %s registered at startup: %s", Path, Ok and "ok" or ("error " .. tostring(Err)))
        else
            Log("native: no loot manifest (tried %s); the map's loot tags are not registered", Path)
        end
    end
    NativeState.Ready = true
    Log("native: READY: %s is a game level (%s). Entering uses the game's TransferToLevel; the streaming loader is not used.",
        Map.Name, NativeState.Tag)
end

-- Arrival transform for the save slot the game reads first (PlayerGameData position for the level)
local function NativeStartTransform(Map)
    local S = Opt(Map, "NativeStart", nil)
    if type(S) ~= "table" then return nil end
    local Yaw = math.rad(tonumber(S.Yaw) or 0) / 2
    return { Rotation = { X = 0, Y = 0, Z = math.sin(Yaw), W = math.cos(Yaw) },
             Translation = { X = S.X or 0, Y = S.Y or 0, Z = S.Z or 0 }, Scale3D = { X = 1, Y = 1, Z = 1 } }
end

local function NativeSavePosition(Map)
    local T = NativeStartTransform(Map)
    if not T then return false end
    local GD = GetGameData()
    if not GD then return false end
    local Ok = pcall(function() GD.PlayerData:SavePosition(TagStruct(NativeState.Tag), T, { X = 0, Y = 0, Z = 0 }) end)
    return Ok
end

-- Enter the map through the game's level transfer. Returns true when the game accepted the transfer.
local function NativeEnter(Map, Why)
    if NativeTrip then
        Log("native: %s ignored: a transfer is already running", Why)
        return false
    end
    if not NativeState.Ready then
        Log("native: %s: not registered (%s)", Why, NativeState.Failed or "registration not finished")
        return false
    end
    local GM = GetGameMode()
    if not GM then
        Log("native: %s: no PRGameMode yet", Why)
        return false
    end
    if not Valid(UEHelpers.GetPlayer()) then
        Log("native: %s: no player pawn yet", Why)
        return false
    end
    if not IfaceFn(TransferFnPath) then
        Log("native: %s: %s not found", Why, TransferFnPath)
        return false
    end
    local Tag = NativeState.Tag
    local Saved = NativeSavePosition(Map)
    Log("native: %s: calling TransferToLevel(%s) on %s (arrival position %s)", Why, Tag, GM:GetFName():ToString(),
        Saved and "saved for the level" or "from the game")
    local Res, Err = CallTransfer(GM, Tag, "None")
    Log("native: %s: TransferToLevel(%s) -> %s", Why, Tag, Err or tostring(Res))
    if Res ~= true then return false end
    NativeTrip = { Map = Map, T0 = Now(), Phase = "transfer", SeenTransition = false }
    local Trip = NativeTrip
    Every(100, function()
        if NativeTrip ~= Trip then return true end
        local Ms = Now() - Trip.T0
        local GMn = GetGameMode()
        local InTr = InTransition(GMn)
        if InTr then Trip.SeenTransition = true end
        local LevelNow = LevelTagNow()
        local LM = GetLevelManager()
        local LMReady = LM and (Config.RequireLevelManagerReady == false or LM:IsReady()) or false     -- a -nohmd game never reports the level manager ready (config_test.lua)
        -- the game's DoSavePlayerPosition overwrites the single saved position while not in transition; keep the start position in place
        -- until the level start has read it
        if LevelNow ~= Tag or InTr or not LMReady then NativeSavePosition(Map) end
        -- the map's level is in memory: its table holder keeps the map's loot tables alive, so point the entries at them now
        -- (before the level's loot nodes roll; until then the entries hold the stock donor tables, which never go away)
        if not Trip.LootDone then
            local W = UEHelpers.GetWorld()
            local S = Valid(W) and FindNativeEntry(W, NativeState.Sub) or nil
            if S and CallBool(S, "IsLevelLoaded") then
                Trip.LootDone = true
                local OkR, NR = pcall(RepointOwnTables, Map, false)
                NativeLootOwn = OkR and (NR or 0) > 0
                Log("native: level loaded after %.1f s; own loot tables %s", Ms / 1000,
                    NativeLootOwn and ("in use (" .. tostring(NR) .. " entries)") or "not available, donor tables kept")
            end
        end
        if (LevelNow == Tag or (LevelNow == nil and Trip.SeenTransition)) and not InTr and LMReady then
            local World = UEHelpers.GetWorld()
            local Stream = Valid(World) and FindNativeEntry(World, NativeState.Sub) or nil
            if not (Stream and CallBool(Stream, "IsLevelVisible")) then
                if Ms > 180000 then
                    Log("native: level tag is %s but the map's level is not visible after %.0f s", Tag, Ms / 1000)
                    NativeTrip = nil
                    return true
                end
                return false
            end
            local L = PawnLoc()
            local M = ScanMarkers(Map, Stream)
            local Want = ChooseArrival(Map, M)
            Log("native: arrived after %.1f s (transition seen %s): level %s, player at %s, %d TargetPoint(s), start marker %s",
                Ms / 1000, tostring(Trip.SeenTransition), LevelNow, L and FmtV(L) or "?", #M.All, M.Start and "found" or "MISSING")
            if Want and L and Dist3D(L, Want.Loc) > Opt(Map, "NativeArriveTolerance", 3000) then
                Log("native: the game placed the player %.0f m from the arrival marker; moving them there", Dist3D(L, Want.Loc) / 100)
                TeleportPlayer(Want.Loc, Want.Rot, "arrival marker")
            end
            Current = { Map = Map, Stream = Stream, Return = nil, Phase = "active", Exits = {}, Native = true }
            ArmExits(M)
            MissionsProgression("arrival")
            NativeTrip = nil
            return true
        end
        if Ms > 180000 then
            Log("native: transfer did not finish within 180 s (level %s, in transition %s, level manager ready %s)",
                tostring(LevelNow), tostring(InTr), tostring(LMReady))
            NativeTrip = nil
            return true
        end
        return false
    end)
    return true
end

-- Leave the map through the game's level transfer (to HubLevelTag)
local function NativeExit(Why)
    if NativeLootOwn then
        pcall(RepointOwnTables, Current.Map, true)
        NativeLootOwn = false
    end
    local GM = GetGameMode()
    local Res, Err = CallTransfer(GM, HubLevelTag, Config.NativeExitLocation or "None")
    Log("native exit (%s): TransferToLevel(%s) -> %s", Why, HubLevelTag, Err or tostring(Res))
    if Res ~= true then
        Current.Phase = "active"
        return
    end
    local T0w = Now()
    Every(500, function()
        if not Current or not Current.Native then return true end
        local LevelNow = LevelTagNow()
        local LM = GetLevelManager()
        local World = UEHelpers.GetWorld()
        local Back = LevelNow == HubLevelTag or (LevelNow == nil and Valid(World) and IsHubVisible(World))
        if Back and LM and (Config.RequireLevelManagerReady == false or LM:IsReady()) and not InTransition() then
            Log("native exit: back in %s after %.1f s", HubLevelTag, (Now() - T0w) / 1000)
            Current = nil
            return true
        end
        if Now() - T0w > 180000 then
            Log("native exit: not back in %s after 180 s (level %s)", HubLevelTag, tostring(LevelNow))
            Current = nil
            return true
        end
        return false
    end)
end

-- Pickup trigger (config NativeTriggerMesh = the name of a Hub item's static mesh): grabbing a Hub prop with that mesh starts the
-- transfer. Hub props such as cups, books and tins are BP_PhysicsActor_C actors whose Mesh property names the static mesh.
-- The hook only reacts to the mesh named in this loader's config, so several loader mods can share the grab event.
-- BP_PhysicsActor_C implements the VRExpansion grip event OnGrip(GrippingController, GripInformation) as a Blueprint
-- function, which the grip controller calls when a hand takes the item, so UE4SS can hook it like any script function.
local TriggerHooked = false
local TriggerLastMs = -1e9
local function NativeTriggerGrab(Context)
    local Map = NativeState.Map
    if not Map then return end
    local Want = Opt(Map, "NativeTriggerMesh", nil)
    if not Want then return end
    local Ok, MeshName = pcall(function()
        local A = Context:get()
        if not Valid(A) then return nil end
        local M = A.Mesh
        if not Valid(M) then return nil end
        return M:GetFName():ToString()
    end)
    if not Ok or MeshName ~= Want then return end
    local T = Now()
    if T - TriggerLastMs < 10000 then return end            -- debounce: one transfer per grab, 10 s apart
    TriggerLastMs = T
    -- start the transfer on the next game-thread tick, outside the grip call
    ExecuteInGameThread(function()
        if not NativeState.Ready then Log("native trigger: %s grabbed, but the level is not registered (%s)", Want, NativeState.Failed or "not finished"); return end
        if Current or NativeTrip then Log("native trigger: %s grabbed, but a map is already active / a transfer is running", Want); return end
        local World = UEHelpers.GetWorld()
        local Lvl = LevelTagNow()
        if not (Valid(World) and IsHubVisible(World)) or (Lvl ~= nil and Lvl ~= HubLevelTag) then
            Log("native trigger: %s grabbed outside the Hub (level %s); ignored", Want, tostring(Lvl))
            return
        end
        if InTransition() then Log("native trigger: %s grabbed during a transition; ignored", Want); return end
        Log("native trigger: %s grabbed in the Hub", Want)
        NativeEnter(Map, "pickup of " .. Want)
    end)
end

local function NativeHookTrigger()
    if TriggerHooked then return end
    local Map = NativeState.Map
    if not Map or not Opt(Map, "NativeTriggerMesh", nil) then TriggerHooked = true; return end
    local Path = Opt(Map, "NativeTriggerFunction", "/Game/ITR/BPs/Items/BP_PhysicsActor.BP_PhysicsActor_C:OnGrip")
    local Ok, F = pcall(StaticFindObject, Path)
    if not Ok or not Valid(F) then
        NativeLogOnce("trigwait", "native trigger: waiting for %s to load", Path)
        return
    end
    TriggerHooked = true
    local OkH, Err = pcall(RegisterHook, Path, function(Context)
        local OkT, E = pcall(NativeTriggerGrab, Context)
        if not OkT then LogOnce("trigerr", "native trigger: error %s", tostring(E)) end
    end)
    Log("native trigger: hook on %s (grab an item with mesh %s in the Hub to enter %s): %s", Path,
        tostring(Opt(Map, "NativeTriggerMesh", nil)), Map.Name, OkH and "registered" or ("FAILED " .. tostring(Err)))
end

-- Re-entry of the map by the game itself (fog wall / tide / death reload = IPRGameMode::ReEnterCurrentLevel, no NativeEnter):
-- the level is unloaded and loaded again behind the transition screen. Its table holder goes with the old level, so the map's
-- loot entries move back to the donor tables as soon as the transition starts (before the old tables can be collected) and
-- to the new level's holder as soon as the level is loaded again (before its loot nodes roll), as NativeEnter does.
local NativeReturn = nil     -- { T0 } while waiting for the map's level to come back
local function NativeReentryWatch(Map)
    Every(250, function()
        if NativeTrip then return false end
        if NativeLootOwn and Current and Current.Native and InTransition() then
            pcall(RepointOwnTables, Map, true)
            NativeLootOwn = false
            NativeReturn = { T0 = Now() }
            Log("native: a transition started while the map is loaded (fog / tide / death / gate); loot entries back on the donor tables")
            return false
        end
        if NativeReturn then
            local LevelNow = LevelTagNow()
            if LevelNow and LevelNow ~= NativeState.Tag and not InTransition() then
                Log("native: the transition left the map (level now %s)", LevelNow)
                NativeReturn = nil
                return false
            end
            local W = UEHelpers.GetWorld()
            local S = Valid(W) and FindNativeEntry(W, NativeState.Sub) or nil
            if LevelNow == NativeState.Tag and S and CallBool(S, "IsLevelLoaded") then
                local OkR, NR = pcall(RepointOwnTables, Map, false)
                NativeLootOwn = OkR and (NR or 0) > 0
                Log("native: the map's level is back after %.1f s (re-entered by the game); own loot tables %s", (Now() - NativeReturn.T0) / 1000,
                    NativeLootOwn and ("in use (" .. tostring(NR) .. " entries)") or "not available, donor tables kept")
                NativeReturn = nil
                if Current then Current.Stream = S end
            elseif Now() - NativeReturn.T0 > 180000 then
                Log("native: the map's level did not come back within 180 s (level %s)", tostring(LevelNow))
                NativeReturn = nil
            end
        end
        return false
    end, 30)
end

-- Background: registration, then a light watch (left the map another way: death, fog, gate)
local function NativeStartup()
    local Map = NativeMap()
    if not Map then return end
    NativeState.Map, NativeState.Tag, NativeState.Sub = Map, NativeTagOf(Map), NativeSubOf(Map)
    Log("native: registering %s as %s (main sublevel %s) once the game is idle", Map.Name, NativeState.Tag, NativeState.Sub)
    NativeReentryWatch(Map)
    Every(1000, function()
        NativeRegisterTick()
        if NativeState.Ready then
            local OkM, ErrM = pcall(MissionsTick)
            if not OkM then LogOnce("missionstick", "missions: tick error %s", tostring(ErrM)) end
        end
        if NativeState.Ready and not TriggerHooked then NativeHookTrigger() end
        if NativeState.Failed then
            NativeLogOnce("failed", "native: registration FAILED (%s); %s", NativeState.Failed,
                Opt(Map, "NativeFallback", false) and "entry falls back to the streaming loader" or "map entry is off this session")
        end
        if NativeLootOwn and not NativeTrip then
            local W = UEHelpers.GetWorld()
            local S = Valid(W) and FindNativeEntry(W, NativeState.Sub) or nil
            if not (S and CallBool(S, "IsLevelLoaded")) then
                pcall(RepointOwnTables, Map, true)
                NativeLootOwn = false
                Log("native: the map's level is gone; loot entries back on the donor tables")
                if Current and Current.Native and not NativeReturn then NativeReturn = { T0 = Now() } end   -- a game re-entry may follow
            end
        end
        if Current and Current.Native and Current.Phase == "active" and not NativeTrip then
            local LevelNow = LevelTagNow()
            if LevelNow and LevelNow ~= NativeState.Tag and not InTransition() then
                Log("native: the game left the map another way (level now %s); exits disarmed", LevelNow)
                Current = nil
            end
        end
        -- the game loaded the map's level itself (a save made in the map): exits, loot tables and map settings as after an entry
        -- (cheap test first: in the Hub the map's streaming entry is not visible, and LevelTagNow() would scan every PRGameData object every 2 s)
        local SaveW = (NativeState.Ready and not Current and not NativeTrip and not NativeReturn) and UEHelpers.GetWorld() or nil
        local SaveS = Valid(SaveW) and FindNativeEntry(SaveW, NativeState.Sub) or nil
        if SaveS and CallBool(SaveS, "IsLevelVisible") and LevelTagNow() == NativeState.Tag and not InTransition() then
            local W = SaveW
            local S = SaveS
            if S and CallBool(S, "IsLevelVisible") then
                local M = ScanMarkers(Map, S)
                local L = PawnLoc()
                Log("native: the game loaded %s itself (a save made in the map); player at %s, %d TargetPoint(s); exits armed",
                    NativeState.Tag, L and FmtV(L) or "?", #M.All)
                Current = { Map = Map, Stream = S, Return = nil, Phase = "active", Exits = {}, Native = true }
                ArmExits(M)
                MissionsProgression("save loaded in the map")
                if not NativeLootOwn then
                    local OkR, NR = pcall(RepointOwnTables, Map, false)
                    NativeLootOwn = OkR and (NR or 0) > 0
                    Log("native: own loot tables %s", NativeLootOwn and ("in use (" .. tostring(NR) .. " entries)") or "not available, donor tables kept")
                end
            end
        end
        return false
    end, 30)
end

---------------------------------------------------------------------------------------------------------------------
-- The map's console variables, the compass target and the player level / trigger-flag part of the progression unlock are Blueprint
-- actors in the map pak (BP_ItrShowcase_MapSettings, _CompassSky, _Progression); nothing in this file ticks for them.
---------------------------------------------------------------------------------------------------------------------

---------------------------------------------------------------------------------------------------------------------
-- Leaving
---------------------------------------------------------------------------------------------------------------------
local function FinishUnload()
    if Current then pcall(RepointOwnTables, Current.Map, true) end   -- the map's tables go with the level
    local World = UEHelpers.GetWorld()
    if Current and Valid(Current.Stream) then
        Current.Stream:SetShouldBeVisible(false)
        Current.Stream:SetShouldBeLoaded(false)
        Log("unloaded %s", Current.Map.Name)
    end
    if Valid(World) then SetLightingScenariosHidden(World, false) end
    Current = nil
end

-- Player must stand off the map before it goes away. Return = where they stood in the Hub (may be nil).
-- With a Return position: off the map = within 6 m of it for 2 ticks (the Hub is far from the map). Without one: the
-- movement base decides when it can tell, else there is nothing to wait for.
local function ConfirmOffMapThenUnload(Return)
    local T0w = Now()
    local Waited, Near = 0, 0
    local Stream = Current.Stream
    Every(250, function()
        if not Current then return true end
        Waited = math.floor(Now() - T0w)
        local Off, How
        if Return then
            local L = PawnLoc()
            if L and Dist2D(L, Return) < 600 then Near = Near + 1 else Near = 0 end
            Off, How = Near >= 2, "position"
        else
            local Ground = OnMapGround(Stream)
            Off, How = (Ground ~= true), (Ground ~= nil and "movement base" or "nothing to compare with")
        end
        if Off then
            Log("exit: player is off the map (%s); unloading it", How)
            FinishUnload()
            return true
        end
        if Waited >= 10000 then
            Log("exit: the player is still on %s after the Hub load and the teleport back; map kept (never unloaded from under "
                .. "the player). Use the exit again.", Current.Map.Name)
            Current.Phase = "active"
            return true
        end
        return false
    end)
end

-- Hub levels the game did not bring back: restore the ones no level configuration lists (nobody else will)
local function RestoreHubLevels()
    local Levels = Current and Current.HubLevels or {}
    if #Levels == 0 then return end
    local Managed = ManagedSublevels()
    local Back, NotBack, Restored = 0, 0, 0
    for _, H in ipairs(Levels) do
        if not H.Kept and Valid(H.S) then
            local Back1 = CallBool(H.S, "IsLevelLoaded") or PropBool(H.S, "bShouldBeLoaded")
                or not (H.WasLoaded or H.WasShouldLoad)
            if Back1 then
                Back = Back + 1
            else
                NotBack = NotBack + 1
                -- Managed unknown: restore only a lighting-scenario level, the one level the configs are least likely to list
                local Restore
                if Managed then Restore = not Managed[H.Name] else Restore = H.Scenario end
                Log("exit: %s NOT brought back by the game (%s)%s", H.Name, StreamBitsText(H.S),
                    Restore and "  -> restored by the loader" or "  -> left to the game")
                if Restore then
                    H.S:SetShouldBeLoaded(true)
                    H.S:SetShouldBeVisible(H.WasVisible or H.WasShouldVisible)
                    Restored = Restored + 1
                end
            end
        end
    end
    Log("exit: %d Hub level(s) back via the game, %d not (%d restored by the loader)", Back, NotBack, Restored)
end

local function HubExitFinish(Start, Return)
    local L = PawnLoc()
    local Moved = (L and Start) and Dist3D(L, Start) or 0
    local MapLoaded = Valid(Current.Stream) and StreamActive(Current.Stream)
    Log("exit: Hub ready; the native Hub load left the map loaded: %s; player at %s, moved %.0f m since the exit began (%s)",
        tostring(MapLoaded), L and FmtV(L) or "?", Moved / 100, Moved > 5000 and "the game placed them" or "the game did not move them")
    -- The game brings the Hub's sublevels back one after the other after the main Hub level turned visible; judged at that
    -- moment, levels that return a few seconds later would count as "not brought back". So wait up to 20 s for the ones it had
    -- loaded before, then judge.
    local T0w = Now()
    local Ctx = { Judged = false }
    local function Finish()
        if Ctx.Judged then return end
        Ctx.Judged = true
        RestoreHubLevels()
        if Moved <= 5000 and Return then
            Log("exit: teleporting the player back to their Hub position %s", FmtV(Return.Loc))
            TeleportPlayer(Return.Loc, Return.Rot, "saved Hub position")
            ConfirmOffMapThenUnload(Return.Loc)
        else
            ConfirmOffMapThenUnload(nil)
        end
    end
    Every(500, function()
        if not Current then return true end
        local Missing = 0
        for _, H in ipairs(Current.HubLevels or {}) do
            if not H.Kept and Valid(H.S) and (H.WasLoaded or H.WasShouldLoad)
                and not (CallBool(H.S, "IsLevelLoaded") or PropBool(H.S, "bShouldBeLoaded")) then
                Missing = Missing + 1
            end
        end
        if Missing > 0 and Now() - T0w < 20000 then return false end
        Finish()
        return true
    end)
end

-- Exit with the Hub torn down: the game's Hub load while the player still stands on the map, then unload the map
-- only if it is still loaded and the player isn't on it.
local function HubExit()
    local Start = PawnLoc()
    local Return = Current.Return
    for _, H in ipairs(Current.HubLevels or {}) do H.Gone = nil end
    Log("exit: Hub teardown is active; asking the game to load %s while the player stands on the map", HubLevelTag)
    local St = { LoadTried = false, Called = false, Transferred = false }
    local T0w = Now()
    local Elapsed, Activity = 0, false
    local Transferred = false
    Every(250, function()
        if not Current or Current.Phase ~= "exiting" then return true end
        Elapsed = math.floor(Now() - T0w)
        -- The calls are made from inside the loop, one per tick, so a native error in LoadLevel (not catchable by pcall)
        -- leaves the loop alive and the next tick falls back to TransferToLevel.
        if not St.LoadTried then
            St.LoadTried = true
            St.Called = CallLoadLevelHub()
            if not St.Called then
                St.Transferred = true
                if not CallTransferHub() then
                    Log("exit FAILED: neither LoadLevel nor TransferToLevel could be called; the map stays loaded")
                    Current.Phase = "active"
                    return true
                end
            end
            return false
        end
        if not St.Called and not St.Transferred then
            Log("exit: LoadLevel did not return (native error); falling back to TransferToLevel")
            St.Transferred = true
            CallTransferHub()
            return false
        end
        Transferred = St.Transferred
        local World = UEHelpers.GetWorld()
        if not Valid(World) then return false end
        local LM = GetLevelManager()
        if LM and not LM:IsReady() then Activity = true end
        for _, H in ipairs(Current.HubLevels or {}) do
            if not H.Kept and Valid(H.S) and StreamActive(H.S) then Activity = true end
        end
        if Activity and IsHubVisible(World) then
            Log("exit +%d ms: Hub visible and the level manager ready", Elapsed)
            HubExitFinish(Start, Return)
            return true
        end
        if not Activity and not Transferred and Elapsed > 4000 then
            Log("exit +%d ms: LoadLevel(%s) did nothing (the game probably believes it is still in the Hub); "
                .. "falling back to TransferToLevel", Elapsed, HubLevelTag)
            Transferred = true
            St.Transferred = true
            CallTransferHub()
        end
        if Elapsed > 120000 then
            Log("exit FAILED: the Hub was not ready after %d ms (activity %s); map kept", Elapsed, tostring(Activity))
            Current.Phase = "active"
            return true
        end
        return false
    end)
end

-- Exit with the Hub still loaded: back to where the player stood, then unload
local function SimpleExit()
    local Return = Current.Return
    if Return then
        TeleportPlayer(Return.Loc, Return.Rot, "saved Hub position")
        Log("returned to the Hub")
        ConfirmOffMapThenUnload(Return.Loc)
    else
        FinishUnload()
    end
end

local function StartExit(Why)
    if not Current or Current.Phase ~= "active" then
        Log("%s ignored: the map is %s", Why, Current and Current.Phase or "not loaded")
        return
    end
    Log("leaving %s (%s)", Current.Map.Name, Why)
    Current.Phase = "exiting"
    if Current.Native then NativeExit(Why)
    elseif Current.TornDown then HubExit() else SimpleExit() end
end

---------------------------------------------------------------------------------------------------------------------
-- Loading
---------------------------------------------------------------------------------------------------------------------
local function OnVisible(Map)
    local Stream = Current.Stream
    local M = ScanMarkers(Map, Stream)
    Log("%s visible: %d TargetPoint(s), start marker %s, %d arrive marker(s)", Map.Level, #M.All,
        M.Start and "found" or "MISSING", (function() local N = 0; for _ in pairs(M.Arrive) do N = N + 1 end; return N end)())
    if Opt(Map, "HubTeardown", true) then
        Teardown(Map, M)
    else
        if Map.HideLightingScenario then SetLightingScenariosHidden(UEHelpers.GetWorld(), true) end
        Arrive(Map, M, ChooseArrival(Map, M))
    end
end

local function Load(Map)
    if Current then return end
    local World = UEHelpers.GetWorld()
    if not Valid(World) then Log("no world yet"); return end
    if not IsHubVisible(World) then
        -- From the main menu the teleport reports success but the VR player doesn't move.
        Log("load maps from the Hub")
        return
    end
    -- LevelStreamingDynamic::LoadLevelInstance can't be called from UE4SS 3.0.1 Lua: after its bool out-parameter the
    -- next argument is read from the wrong stack slot. So do what LoadLevelInstance does inside: make a new streaming
    -- entry with LevelStreaming::CreateInstance (copies an existing dynamic entry under a unique name and adds it to the
    -- world), point it at the map's package with PackageNameToLoad, place it at the origin, and load it.
    local Source = nil
    for _, S in ipairs(StreamingLevels(World)) do
        if S:GetClass():GetFName():ToString() == "LevelStreamingDynamic" then Source = S; break end
    end
    if not Source then Log("no dynamic streaming level to copy"); return end
    InstanceCount = InstanceCount + 1
    local Stream = Source:CreateInstance(string.format("ITRMap_%s_%d", Map.Name, InstanceCount))
    if not Valid(Stream) then
        Log("CreateInstance failed")
        return
    end
    Stream.PackageNameToLoad = FName(Map.Level)
    Stream.LevelTransform = { Rotation = { X = 0, Y = 0, Z = 0, W = 1 }, Translation = { X = 0, Y = 0, Z = 0 },
                              Scale3D = { X = 1, Y = 1, Z = 1 } }
    Stream:SetShouldBeLoaded(true)
    Stream:SetShouldBeVisible(true)
    local Pawn = UEHelpers.GetPlayer()
    local Return = nil
    if Valid(Pawn) then
        Return = { Loc = Vec(Pawn:K2_GetActorLocation()), Rot = Rot(Pawn:K2_GetActorRotation()) }
    end
    Current = { Map = Map, Stream = Stream, Return = Return, Phase = "loading", Exits = {} }
    Log("streaming %s ...", Map.Level)
    local T0w = Now()
    local Waited = 0
    Every(250, function()
        if not Current or not SameObj(Current.Stream, Stream) or not Valid(Stream) then return true end
        Waited = math.floor(Now() - T0w)
        if Stream:IsLevelVisible() then
            OnVisible(Map)
            return true
        elseif Waited > 60000 then
            Log("%s did not become visible within 60 s", Map.Level)
            Current.Phase = "active"             -- lets the key unload it
            return true
        end
        return false
    end)
end

local function MapByName(Name)
    for _, M in ipairs(Config.Maps) do
        if M.Name == Name then return M end
    end
    return nil
end

-- Enter Map: through the game's level transfer when the map is Native, else stream it in (Load). Native maps fall back to
-- Load only with NativeFallback = true. Returns true when something was started.
local function Enter(Map, Why)
    if Opt(Map, "Native", true) then
        if NativeState.Map == Map and NativeState.Ready then
            local World = UEHelpers.GetWorld()
            if not (Valid(World) and IsHubVisible(World)) then
                Log("native: %s: enter the map from the Hub", Why)
                return false
            end
            return NativeEnter(Map, Why)
        end
        if not Opt(Map, "NativeFallback", false) then
            Log("native: %s: %s is not registered (%s); NativeFallback is off, nothing loaded", Why, Map.Name,
                NativeState.Failed or "registration not finished")
            return false
        end
        Log("native: %s: %s is not registered (%s); falling back to the streaming loader", Why, Map.Name,
            NativeState.Failed or "registration not finished")
    end
    Load(Map)
    return Current ~= nil
end

LoadMemory()

-- Key: enters the map (the next one, with several maps), or leaves the current one. Config Key = a UE4SS key name; false = no key.
-- The default is F10, which none of the common ITR mods use.
local DefaultKey = "F10"
local KeyName = Config.Key
if KeyName == nil then KeyName = DefaultKey end
if KeyName ~= false then
    local Code = Key[KeyName]
    if not Code then
        Log("config Key '%s' is not a UE4SS key name; no key is bound", tostring(KeyName))
    else
        RegisterKeyBind(Code, function()
            ExecuteInGameThread(function()
                if Current then
                    StartExit("key")
                else
                    local Map = Config.Maps[NextIndex]
                    NextIndex = NextIndex % #Config.Maps + 1
                    if Map then Enter(Map, "key") end
                end
            end)
        end)
    end
end

-- Console command (config ConsoleCommand, default "itrmap"; false = none), typed in the game console or sent by another mod
-- (ExecuteConsoleCommand):
--   <command> enter [MapName]    enter the map (the first map when no name is given)
--   <command> leave              leave the current map (back to the Hub)
-- A command naming a map this loader does not have is left for other handlers, so two loader mods can each use their own
-- command name (set ConsoleCommand per loader) without taking each other's commands.
local CommandName = Config.ConsoleCommand
if CommandName == nil then CommandName = "itrmap" end
if CommandName and type(RegisterConsoleCommandHandler) == "function" then
    local OkC, ErrC = pcall(RegisterConsoleCommandHandler, CommandName, function(FullCommand, Parameters)
        local Verb = Parameters and Parameters[1] and tostring(Parameters[1]):lower() or "enter"
        local Name = Parameters and Parameters[2] and tostring(Parameters[2]) or nil
        local Map = Config.Maps[1]
        if Name then Map = MapByName(Name) end
        if not Map then return false end
        ExecuteInGameThread(function()
            if Verb == "leave" then
                if Current then StartExit("console command") else Log("console command: leave ignored: no map is loaded") end
            elseif Verb == "enter" then
                if Current then Log("console command: enter ignored: %s is already loaded", Current.Map.Name)
                else Enter(Map, "console command") end
            else
                Log("console command: unknown verb '%s' (use enter or leave)", Verb)
            end
        end)
        return true
    end)
    Log("console command '%s enter|leave [MapName]': %s", CommandName, OkC and "registered" or ("FAILED " .. tostring(ErrC)))
end

-- Test hook (config TriggerFile): creating that file loads the first map once, like its key; the file is deleted when seen.
-- Lets an unattended run start the load at a moment of its choosing instead of when the Hub is first seen.
if Config.TriggerFile then
    LoopAsync(1000, function()
        ExecuteInGameThread(function()
            local Ok, F = pcall(io.open, Config.TriggerFile, "r")
            if not Ok or not F then return end
            F:close()
            pcall(os.remove, Config.TriggerFile)
            if Current then
                Log("trigger file: a map is already loaded; ignored")
                return
            end
            local Map = Config.Maps[1]
            if Map then
                Log("trigger file: loading %s", Map.Name)
                Enter(Map, "trigger file")
            end
        end)
        return false
    end)
end

-- Exit markers: checked twice a second while a map is loaded and settled
LoopAsync(500, function()
    local Cur = Current
    if not Cur or Cur.Phase ~= "active" then return false end                  -- nothing to watch: no game-thread work at all
    ExecuteInGameThread(function()
        if not Current or Current.Phase ~= "active" or not Current.Exits or #Current.Exits == 0 then return end
        local Pawn = UEHelpers.GetPlayer()
        if not Valid(Pawn) then return end
        local L = Pawn:K2_GetActorLocation()
        local R = Opt(Current.Map, "ExitRadius", 150)
        Current.WatchTicks = (Current.WatchTicks or 0) + 1
        if Current.WatchTicks % 60 == 1 and Current.WatchTicks < 400 then          -- every 30 s, a handful of lines
            local Best, BestD = nil, 1e30
            for _, E in ipairs(Current.Exits) do
                local D = Dist2D(L, E)
                if D < BestD then Best, BestD = E, D end
            end
            Log("exit watch: player at %s, nearest exit %s %.1f m away (radius %.1f m)", FmtV(L), Best and Best.Id or "-", BestD / 100, R / 100)
        end
        for _, E in ipairs(Current.Exits) do
            local DX, DY, DZ = L.X - E.X, L.Y - E.Y, L.Z - E.Z
            if DX * DX + DY * DY < R * R and math.abs(DZ) < 250 then
                Log("exit marker reached%s", E.Id and (" (id " .. E.Id .. ")") or "")
                Remember(Current.Map, E.Id)
                StartExit("exit marker")
                return
            end
        end
    end)
    return false
end)

if Config.AutoLoadInHub then
    local Map = MapByName(Config.AutoLoadInHub)
    if not Map then
        Log("AutoLoadInHub: no map named %s in config.lua", Config.AutoLoadInHub)
    else
        -- Load once per Hub visit, after two consecutive checks (2 s apart) found the player in the Hub.
        -- While a map is loaded the Hub may be gone (teardown); that is not a new visit, so nothing resets then.
        local HubChecks, LoadedThisVisit = 0, false
        LoopAsync(2000, function()
            ExecuteInGameThread(function()
                -- Native map: no timed entry. The transfer starts when the trigger item is picked up (NativeTriggerMesh),
                -- or with the key. Only a failed registration with NativeFallback = true streams the map in as before.
                if Opt(Map, "Native", true) and not (NativeState.Failed and Opt(Map, "NativeFallback", false)) then
                    return
                end
                if Current then
                    LoadedThisVisit = true
                    HubChecks = 0
                    if Current.Phase == "active" and not Valid(Current.Stream) then Current = nil end
                    return
                end
                local World = UEHelpers.GetWorld()
                local InHub = Valid(World) and IsHubVisible(World)
                HubChecks = InHub and HubChecks + 1 or 0
                if not InHub then LoadedThisVisit = false end
                if HubChecks >= 2 and not LoadedThisVisit then
                    LoadedThisVisit = true
                    Load(Map)
                end
            end)
            return false
        end)
    end
end

NativeStartup()

Log("ready: %d map(s); key %s%s; native %s; Hub teardown %s; re-entry %s; gameplay activation %s; scripts dir %s", #Config.Maps, tostring(KeyName),
    Config.AutoLoadInHub and (", auto-load " .. Config.AutoLoadInHub .. " in the Hub") or "",
    NativeState.Map and (NativeState.Map.Name .. " as " .. NativeState.Tag) or "off",
    Opt(nil, "HubTeardown", true) and "on" or "off", Opt(nil, "ReEntry", true) and "on" or "off",
    Opt(nil, "ActivateGameplay", true) and "on" or "off", ScriptDir())
