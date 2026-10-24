-- ITR Showcase missions: registers the "showcase" mission category and its missions with the game, the objective points of the
-- map, and (when the showcase loads) sets the visited levels of the progression unlock. Required from main.lua; switched by config.lua  Missions = { Enabled = true }.
-- (The player level and trigger flags of the unlock are BP_ItrShowcase_Progression and the compass target is BP_ItrShowcase_CompassSky, both in the map pak.)
--
-- What it does, all in pcall, each step logged with a read-back, nothing registered unless the step before it was confirmed:
--   1. load the cooked mission data assets (UMissionNormalConfig, /Game/Mods/ItrShowcase/Missions/DA_*) from the map pak;
--   2. keep them alive: UE4SS Lua cannot root an object, and SystemConfig / MissionsConfig are not walked by the GC, so the assets are
--      appended to GameInstance.ReferencedObjects (a reflected TArray<UObject*> the GC does walk, as long as the game instance lives).
--      If that cannot be read back, NOTHING is registered (a config that points at a collectable asset would crash later);
--   3. objective points: MapPointsConfig.LevelPoints[Level.Zone.ItrShowcase][point tag] = transform relative to the level centre
--      (the executors resolve a point tag through this config, not through the placed PRMapPoint actors);
--   4. a new category in MissionsConfig.Missions (the "showcase" series: no story conditions) holding the series assets, and the pool
--      entries appended to the stock categories' CategoryMissions;
--   5. offered at once: PRCheatManager.GetMission(id) + AddMission for the first mission of the series that is not offered or finished;
--   6. progression: when the showcase loads, the stock zones are added to the visited levels (PRGameData.VisitedLevels is BlueprintReadOnly, so a Blueprint cannot do it).
-- Tags stay unregistered at run time (a tag ini in a mod pak does not load): only exact matches are used.
local M = {}

local Ctx = nil              -- supplied by main.lua: Log, Valid, TagStruct, TMapFind, TagsOf, LoadAsset, GetGameData, GetGameMode, LevelTagNow, InTransition, Now, Hub
local Man = nil              -- the manifest (ItrShowcase.missions.json)
local St = { Loaded = nil, Kept = false, Points = false, Category = false, Pool = false, PointsAdded = 0, PoolAdded = 0, Failed = nil, PushDone = false,
             PushTries = 0, ProgDone = {}, PointsStarted = false, CategoryStarted = false, GenTried = false, CheatTried = false }

local function Log(Fmt, ...) Ctx.Log("missions: " .. Fmt, ...) end
local function Valid(O) return Ctx.Valid(O) end

function M.Init(C) Ctx = C end
function M.Manifest() return Man end
function M.State() return St end

-- The manifest: "<Map>.missions.json" next to main.lua, decoded with main.lua's JSON reader. Returns true when it is there and usable.
function M.LoadManifest(Dir, MapName, JsonDecode)
    local Path = Dir .. MapName .. ".missions.json"
    local Ok, F = pcall(io.open, Path, "r")
    if not Ok or not F then
        Ctx.Log("missions: no manifest %s; showcase missions are off", Path)
        return false
    end
    local Text = F:read("*a")
    F:close()
    local Ok2, Res = pcall(JsonDecode, Text or "")
    if not Ok2 or type(Res) ~= "table" or type(Res.missions) ~= "table" or type(Res.category) ~= "table" then
        Ctx.Log("missions: manifest %s is not usable: %s", Path, tostring(Res))
        return false
    end
    Man = Res
    Ctx.Log("missions: manifest %s: category %s, %d mission(s), %d point(s), %d pool entr%s", Path, tostring(Res.category.tag), #Res.missions,
        #(Res.points or {}), #(Res.pool or {}), #(Res.pool or {}) == 1 and "y" or "ies")
    return true
end

local function Grow(Arr)
    -- index past the end grows a TArray by one zeroed element in UE4SS c62ada0 (the level-table route); returns the new element count
    local N = Arr:GetArrayNum()
    local _ = Arr[N + 1]
    return N + 1
end

local function ObjName(O)
    local Ok, N = pcall(function() return O:GetFName():ToString() end)
    return Ok and N or "?"
end

local function TagName(T)
    local Ok, N = pcall(function() return T.TagName:ToString() end)
    return Ok and N or "?"
end

-- ---- 1b: the assets carry the manifest's ids ---------------------------------------------------------------------------------
-- The ids (and the predecessor condition of each series mission) must be tags the game registers at start: its bookkeeping goes through hierarchical tag logic, which never
-- matches an unregistered tag (a series mission offered again right after it succeeded, its successor never eligible). The cooked assets carry the registered ids. This only
-- checks: an asset with other ids (from an older map pak) switches the missions off with a log line instead of misbehaving.
local function IdsMatch(Loaded)
    local Bad = {}
    for _, E in ipairs(Loaded) do
        if TagName(E.Obj.ID) ~= E.Id then table.insert(Bad, E.Id) end
    end
    return #Bad == 0, Bad
end

-- ---- 1 + 2: load and keep alive ---------------------------------------------------------------------------------------------
local function GameInstance()
    local GI = nil
    pcall(function()
        local H = require("UEHelpers")
        if H.GetGameInstance then GI = H.GetGameInstance() end
    end)
    if Valid(GI) then return GI end
    local Ok, Found = pcall(FindFirstOf, "GameInstance")
    if Ok and Valid(Found) then return Found end
    return nil
end

local function LoadAssets()
    local All = {}
    for _, E in ipairs(Man.missions) do table.insert(All, { Id = E.id, Path = E.asset, After = E.after }) end
    for _, E in ipairs(Man.pool or {}) do table.insert(All, { Id = E.id, Path = E.asset, Pool = E.category }) end
    local Loaded, Missing = {}, 0
    for _, E in ipairs(All) do
        local Obj = Ctx.LoadAsset(E.Path)
        if Obj then
            E.Obj = Obj
            table.insert(Loaded, E)
        else
            Missing = Missing + 1
            Log("asset %s did not load", E.Path)
        end
    end
    return Loaded, Missing
end

local function KeepAlive(Loaded)
    local GI = GameInstance()
    if not GI then return false, "no GameInstance yet" end
    local Ok, Arr = pcall(function() return GI.ReferencedObjects end)
    if not Ok or Arr == nil then return false, "GameInstance.ReferencedObjects is not readable" end
    -- Append, then read back only the tail that was written, by address: scanning the whole array (about 18,000 entries after a game start) once per asset
    -- and comparing full names takes seconds on the main menu. The array belongs to the game instance and lives as long as it does; this runs once.
    local Before = Arr:GetArrayNum()
    for _, E in ipairs(Loaded) do
        local Ok2, Err = pcall(function()
            local N = Grow(Arr)
            Arr[N] = E.Obj
        end)
        if not Ok2 then return false, "could not append to ReferencedObjects: " .. tostring(Err) end
    end
    local Want = {}
    for _, E in ipairs(Loaded) do Want[E.Obj:GetAddress()] = true end
    local After, Found = Arr:GetArrayNum(), 0
    if After - Before ~= #Loaded then return false, string.format("ReferencedObjects grew by %d, expected %d", After - Before, #Loaded) end
    for I = Before + 1, After do
        local Ok3, O = pcall(function() return Arr[I] end)
        if Ok3 and Valid(O) and Want[O:GetAddress()] then Found = Found + 1 end
    end
    if Found ~= #Loaded then return false, string.format("only %d of %d assets read back from ReferencedObjects", Found, #Loaded) end
    return true, nil, After
end

-- ---- 3: points --------------------------------------------------------------------------------------------------------------
local function MapPointsConfig()
    local MPC = nil
    pcall(function()
        local C = StaticFindObject("/Script/IntoTheRadius.Default__MapPointsConfig")
        if Valid(C) then MPC = C:GetMapPointsConfig() end
    end)
    return Valid(MPC) and MPC or nil
end

local function RegisterPoints()
    local Pts = Man.points or {}
    if #Pts == 0 then return true, 0 end
    local MPC = MapPointsConfig()
    if not MPC then return false, "MapPointsConfig not found" end
    local LP = MPC.LevelPoints
    local LevelKey = Ctx.TagStruct(Man.level_tag)
    if Ctx.TMapFind(LP, LevelKey) == nil then
        -- an empty table: UE4SS cannot build the nested TMap (List) from a Lua table (it raises "Parameter must be of type 'StructProperty' or table",
        -- a native error that aborts the tick). The value struct is stored zeroed (a zeroed TMap is an empty one) and the map is filled in place below.
        local Ok, Err = pcall(function() LP:Add(LevelKey, {}) end)
        if not Ok then return false, "LevelPoints:Add failed: " .. tostring(Err) end
    end
    local Entry = Ctx.TMapFind(LP, LevelKey)
    if Entry == nil then return false, "LevelPoints has no entry for " .. Man.level_tag .. " after Add" end
    local List = nil
    pcall(function() List = Entry.List end)
    if List == nil then return false, "the level entry has no readable point list" end
    local Added = 0
    for _, P in ipairs(Pts) do
        local Key = Ctx.TagStruct(P.tag)
        local Want = { Rotation = { X = 0, Y = 0, Z = 0, W = 1 }, Translation = { X = P.x, Y = P.y, Z = P.z }, Scale3D = { X = 1, Y = 1, Z = 1 } }
        if Ctx.TMapFind(List, Key) == nil then
            local Ok, Err = pcall(function() List:Add(Key, Want) end)
            if not Ok then return false, string.format("point %s: Add failed: %s", P.tag, tostring(Err)), Added end
        end
        local Back = Ctx.TMapFind(List, Key)
        if Back == nil then return false, "point " .. P.tag .. " not found after Add", Added end
        -- TMap:Add stored zeroed values in c62ada0 (the loot tables): write the fields into the stored struct in place
        pcall(function()
            Back.Rotation = Want.Rotation
            Back.Translation = Want.Translation
            Back.Scale3D = Want.Scale3D
        end)
        local X, Y, Z = nil, nil, nil
        pcall(function() X, Y, Z = Back.Translation.X, Back.Translation.Y, Back.Translation.Z end)
        if X == nil or math.abs(X - P.x) > 1 or math.abs(Y - P.y) > 1 or math.abs(Z - P.z) > 1 then
            return false, string.format("point %s reads back (%s, %s, %s), wanted (%.0f, %.0f, %.0f)", P.tag, tostring(X), tostring(Y), tostring(Z), P.x, P.y, P.z), Added
        end
        Added = Added + 1
    end
    -- the config itself resolves the first point (the call the objective executors make)
    local Resolved = "not checked"
    pcall(function()
        local Yes = MPC:IsPointInLevel(Ctx.TagStruct(Pts[1].tag), LevelKey)
        Resolved = tostring(Yes)
    end)
    Log("points: %d registered under %s; MapPointsConfig:IsPointInLevel(%s) = %s", Added, Man.level_tag, Pts[1].tag, Resolved)
    return true, Added
end

-- ---- 4: category and pool -------------------------------------------------------------------------------------------------
local function MissionsConfig()
    local MC = nil
    pcall(function()
        local C = StaticFindObject("/Script/IntoTheRadius.Default__MissionsConfig")
        if Valid(C) then MC = C:GetMissionsConfig() end
    end)
    return Valid(MC) and MC or nil
end

local function CategoryIndex(Arr, Tag)
    local Idx = nil
    pcall(function() Arr:ForEach(function(I, E) if TagName(E:get().CategoryID) == Tag then Idx = I end end) end)
    return Idx
end

local function AppendAsset(Row, Obj)
    local CM = Row.CategoryMissions
    local N = Grow(CM)
    CM[N] = Obj
    return N
end

local function RegisterCategory(Loaded)
    local MC = MissionsConfig()
    if not MC then return false, "MissionsConfig not found" end
    local Arr = MC.Missions
    local Tag = Man.category.tag
    local Before = Arr:GetArrayNum()
    local Idx = CategoryIndex(Arr, Tag)
    if Idx then
        Log("category %s is already registered (row %d)", Tag, Idx)
        return true, Idx
    end
    local Stock = {}
    pcall(function() Arr:ForEach(function(_, E) table.insert(Stock, TagName(E:get().CategoryID)) end) end)
    local Ok, Err = pcall(function()
        local N = Grow(Arr)
        local Row = Arr[N]
        Row.MaxSimultaneously = math.floor(tonumber(Man.category.max_simultaneously) or 1)
        Row.RestrictMaxSuccessfulPerTide = false
        Row.OnceInALife = Man.category.once_in_a_life == true
        for _, E in ipairs(Loaded) do
            if not E.Pool then AppendAsset(Row, E.Obj) end
        end
        Row.CategoryID = Ctx.TagStruct(Tag)                 -- last: until here the row answers to no category
    end)
    if not Ok then return false, "category row failed: " .. tostring(Err) end
    -- read back; the stock categories must be untouched
    local After = Arr:GetArrayNum()
    local NewIdx = CategoryIndex(Arr, Tag)
    local Names, Count = {}, 0
    pcall(function()
        local R = Arr[NewIdx]
        R.CategoryMissions:ForEach(function(_, E)
            Count = Count + 1
            local D = E:get()
            if Valid(D) then table.insert(Names, TagName(D.ID)) end
        end)
    end)
    local Damaged = 0
    local Now = {}
    pcall(function() Arr:ForEach(function(_, E) table.insert(Now, TagName(E:get().CategoryID)) end) end)
    for I = 1, #Stock do
        if Now[I] ~= Stock[I] then Damaged = Damaged + 1 end
    end
    Log("category %s added: MissionsConfig.Missions %d -> %d rows, %d mission(s) read back (%s); %d stock row(s) changed", Tag, Before, After, Count,
        table.concat(Names, ", "), Damaged)
    if Damaged > 0 then return false, "stock category rows changed while adding ours: quit without saving" end
    if NewIdx == nil then return false, "the new category is not readable" end
    return true, NewIdx
end

local function RegisterPool(Loaded)
    local MC = MissionsConfig()
    if not MC then return false, "MissionsConfig not found" end
    local Arr = MC.Missions
    local Added = 0
    for _, E in ipairs(Loaded) do
        if E.Pool then
            local Idx = CategoryIndex(Arr, E.Pool)
            if not Idx then
                Log("pool entry %s: stock category %s not found; skipped", tostring(E.Id), tostring(E.Pool))
            else
                local Ok, Err = pcall(function() AppendAsset(Arr[Idx], E.Obj) end)
                if Ok then Added = Added + 1 else Log("pool entry %s: %s", tostring(E.Id), tostring(Err)) end
            end
        end
    end
    return true, Added
end

-- ---- registration (one attempt per stage; a native error aborts the tick and the next tick resumes after the finished stages) -------
-- Returns true when finished (or hopeless: St.Failed says why), false to retry next tick.
function M.Register()
    if not Man or St.Failed then return true end
    if not St.Loaded then
        local Loaded, Missing = LoadAssets()
        if #Loaded == 0 or Missing > 0 then
            St.Failed = string.format("%d mission asset(s) did not load (the map pak is not installed?)", Missing > 0 and Missing or #Man.missions)
            Log("%s; showcase missions are off", St.Failed)
            return true
        end
        St.Loaded = Loaded
        Log("%d mission asset(s) loaded", #Loaded)
        local IdsOk, Bad = IdsMatch(Loaded)
        if not IdsOk then
            St.Failed = string.format("%d mission asset(s) carry other ids than the manifest (an older map pak?): %s", #Bad, table.concat(Bad, ", "))
            Log("%s; showcase missions are off", St.Failed)
            return true
        end
    end
    if not St.Kept then
        local Ok, Why, N = KeepAlive(St.Loaded)
        if not Ok then
            if Why == "no GameInstance yet" then return false end
            St.Failed = "keep-alive failed (" .. tostring(Why) .. ")"
            Log("%s; nothing registered, showcase missions are off", St.Failed)
            return true
        end
        St.Kept = true
        Log("kept alive: %d asset(s) in GameInstance.ReferencedObjects (%d entries)", #St.Loaded, N or -1)
    end
    if not St.Points then
        if St.PointsStarted then
            -- the last tick died inside the points step (a native error aborts the tick; pcall does not catch it). The category must NOT be registered
            -- without its points, and the step is not tried again.
            St.Failed = "objective points: the attempt was aborted by a native error (see the Error line above)"
            Log("%s; the category is not registered, showcase missions are off", St.Failed)
            return true
        end
        St.PointsStarted = true
        local Ok, Why = RegisterPoints()
        if not Ok then
            St.Failed = "objective points failed (" .. tostring(Why) .. ")"
            Log("%s; the category is not registered, showcase missions are off", St.Failed)
            return true
        end
        St.PointsAdded = tonumber(Why) or 0
        St.Points = true
    end
    if not St.Category then
        if St.CategoryStarted then
            St.Failed = "category: the attempt was aborted by a native error (see the Error line above)"
            Log("%s", St.Failed)
            return true
        end
        St.CategoryStarted = true
        local Ok, Why = RegisterCategory(St.Loaded)
        if not Ok then
            St.Failed = "category failed (" .. tostring(Why) .. ")"
            Log("%s", St.Failed)
            return true
        end
        St.Category = true
    end
    if not St.Pool then
        St.Pool = true
        local Ok, Why = RegisterPool(St.Loaded)
        if Ok then
            St.PoolAdded = Why or 0
            if (Man.pool and #Man.pool > 0) then Log("pool: %d entr%s appended to the stock categories", St.PoolAdded, St.PoolAdded == 1 and "y" or "ies") end
        else
            Log("pool failed (%s); the series itself stays registered", tostring(Why))
        end
    end
    Log("READY: category %s with %d point(s)", Man.category.tag, St.PointsAdded)
    return true
end

-- ---- 5: keep the series going ----------------------------------------------------------------------------------------------
-- The series must always show its next mission at the mission computer: the first one at the start, the next one after a hand-in. The game's offer pass does this for
-- a registered category when its conditions allow it; this keeper only makes sure, and logs which route worked. It is cheap: one slow tick (every 5 s) that reads the
-- game's lists and does nothing unless the next mission is missing.
--
-- What "already there" means: a mission is LIVE when it is in ActiveMissionsMap (keyed by mission id; every offered / executing mission is there), in ActiveMissions, or its
-- instance id is in SelectedMissions; it is FINISHED when it is in GameMissions.FinishedMissions or in PRCommonGameData.FinishedMissions (the container the story chain's
-- MissionSuccessfullyFinished conditions read). Reading only ActiveMissions and FinishedMissions would miss offered missions and add the first one again and again.
--
-- UE4SS reports a call with the wrong number of arguments as a native error that drops the whole tick (pcall does not catch it; for example "UFunction expected
-- 2 parameters, received 1"), so every call here uses the exact arity of the C++ signature and is made at most once per mission:
--   1. UMissionsManager::GenerateNewMissions(bool bTide) -> bool (no out parameter);
--   2. if the mission is still not live 6 s later: PRCheatManager::GetMission(FGameplayTag, UMissionData*& out) with a table for the out parameter, then AddMission(data).
local function TagIdOf(D)
    local Ok, N = pcall(function() return D.ConfigID.TagName:ToString() end)
    return Ok and N or nil
end

local CommonCache = nil
local function CommonFinished()
    local Set = {}
    if not (CommonCache and Valid(CommonCache)) then
        CommonCache = nil
        local Ok, All = pcall(FindAllOf, "PRCommonGameData")
        if Ok and All then
            for _, C in ipairs(All) do
                if Valid(C) then
                    local Ok2, N = pcall(function() return C.FinishedMissions.GameplayTags:GetArrayNum() end)
                    if Ok2 and N and N > 0 then CommonCache = C; break end
                end
            end
        end
    end
    if CommonCache then
        pcall(function()
            local A = CommonCache.FinishedMissions.GameplayTags
            for I = 1, A:GetArrayNum() do Set[TagName(A[I])] = true end
        end)
    end
    return Set
end

-- { Live = { [id] = { Inst, State } }, Finished = { [id] = true } }, or nil when the mission data is not readable yet
local function ReadLists(GD, WithCommon)
    local MD = nil
    pcall(function() MD = GD.MissionsData end)
    if not Valid(MD) then return nil end
    local L = { Live = {}, Finished = {}, Selected = {} }
    local function Take(D, Into)
        if not Valid(D) then return end
        local Id = TagIdOf(D)
        if not Id then return end
        if Into == "live" then
            local Inst, St = "?", -1
            pcall(function() Inst = D.InstanceId:ToString() end)
            pcall(function() St = tonumber(D.State) or -1 end)
            L.Live[Id] = L.Live[Id] or { Inst = Inst, State = St }
        else
            L.Finished[Id] = true
        end
    end
    pcall(function() local A = MD.ActiveMissions; for I = 1, A:GetArrayNum() do Take(A[I], "live") end end)
    pcall(function() MD.ActiveMissionsMap:ForEach(function(_, V) Take(V:get(), "live") end) end)
    pcall(function() local A = MD.FinishedMissions; for I = 1, A:GetArrayNum() do Take(A[I], "finished") end end)
    pcall(function() local A = MD.SelectedMissions; for I = 1, A:GetArrayNum() do L.Selected[A[I]:ToString()] = true end end)
    if WithCommon then
        for Id in pairs(CommonFinished()) do L.Finished[Id] = true end
    end
    return L
end

local function PickNext(L)
    for _, E in ipairs(Man.missions) do
        if not L.Live[E.id] and not L.Finished[E.id] then
            if E.after == nil or L.Finished[E.after] then return E end
            return nil                                                          -- the predecessor is not finished: wait for it
        end
    end
    return nil
end

local function MissionsManager()
    local Mgr = nil
    pcall(function()
        local C = StaticFindObject("/Script/IntoTheRadius.Default__MissionsManager")
        if Valid(C) then Mgr = C:GetMissionsManager() end
    end)
    return Valid(Mgr) and Mgr or nil
end

local KeepLastMs = -1e9
local Tried = {}            -- [mission id] = { Gen = ms, Cheat = bool, Logged = bool }

-- One keeper tick; call it every second or so. Returns nothing.
function M.Keep()
    if not Man or St.Failed or not St.Category then return end
    if Man.push == false or (Ctx.Config and Ctx.Config.Push == false) then return end
    local T = Ctx.Now()
    if T - KeepLastMs < 5000 then return end
    KeepLastMs = T
    local GD, GM = Ctx.GetGameData(), Ctx.GetGameMode()
    if not (GD and GM) or Ctx.InTransition() then return end
    local Lvl = Ctx.LevelTagNow()
    if Lvl == nil or (Lvl ~= Ctx.Hub and Lvl ~= Man.level_tag) then return end
    local L = ReadLists(GD, false)
    if not L then return end
    for _, E in ipairs(Man.missions) do
        if L.Live[E.id] and not Tried["described:" .. E.id] then
            Tried["described:" .. E.id] = true
            Log("%s is in the computer's list (state %s, instance %s)", E.id, tostring(L.Live[E.id].State), tostring(L.Live[E.id].Inst))
        end
    end
    local Pick = PickNext(L)
    if Pick then
        -- before adding anything, count the common container too (finished missions are recorded there as well); only when something is about to be offered
        L = ReadLists(GD, true) or L
        Pick = PickNext(L)
    end
    if not Pick then return end
    local Tr = Tried[Pick.id]
    if not Tr then
        Tr = { Gen = nil, Cheat = false }
        Tried[Pick.id] = Tr
        -- the game runs an offer pass at start; give it a moment before adding anything
        Tr.Wait = T
        Log("next to offer: %s", Pick.id)
        return
    end
    if Tr.Wait and T - Tr.Wait < 6000 then return end
    if not Tr.Gen then
        Tr.Gen = T
        local Mgr = MissionsManager()
        if not Mgr then Tr.Gen = nil; return end
        local Res = nil
        local Ok, Err = pcall(function() Res = Mgr:GenerateNewMissions(false) end)
        Log("GenerateNewMissions(false) -> %s for %s", Ok and tostring(Res) or ("error " .. tostring(Err)), Pick.id)
        return
    end
    if T - Tr.Gen < 6000 then return end
    if Tr.Cheat then return end                     -- once per mission: whatever happened is in the log
    Tr.Cheat = true
    local CM = nil
    pcall(function() CM = FindFirstOf("PRCheatManager") end)
    if not Valid(CM) then
        Log("%s was not offered by GenerateNewMissions and there is no PRCheatManager; it appears with the game's next offer pass", Pick.id)
        return
    end
    local Out = {}
    local Ok, Err = pcall(function() CM:GetMission(Ctx.TagStruct(Pick.id), Out) end)
    local Data = nil
    for _, V in pairs(Out) do
        if (type(V) == "userdata" or (type(V) == "table" and type(V.IsValid) == "function")) and Valid(V) then Data = V; break end
    end
    if not Ok or not Data then
        Log("PRCheatManager:GetMission(%s) gave no mission data (%s); it appears with the game's next offer pass", Pick.id, Ok and "no object in the out table" or tostring(Err))
        return
    end
    local Ok2, Err2 = pcall(function() CM:AddMission(Data) end)
    local After = ReadLists(GD, false)
    Log("offered %s through PRCheatManager.AddMission: %s; live now: %s", Pick.id, Ok2 and "called" or ("error " .. tostring(Err2)), tostring(After and After.Live[Pick.id] ~= nil))
end

-- ---- 6: progression ---------------------------------------------------------------------------------------------------------
-- Idempotent: adds the stock zones to the visited levels. (The player level and the shortcut / transition trigger flags are BP_ItrShowcase_Progression.)
-- Returns a one-line summary (also logged).
function M.ApplyVisitedLevels(Why)
    if not Man or not Man.progression then return nil end
    local P = Man.progression
    local GD = Ctx.GetGameData()
    if not GD then
        Log("progression (%s): no game data yet", tostring(Why))
        return nil
    end
    local Out = {}
    -- visited levels
    local VL = nil
    pcall(function() VL = GD.VisitedLevels end)
    if VL ~= nil then
        local Have = {}
        pcall(function() VL:ForEach(function(_, E) Have[TagName(E:get())] = true end) end)
        local Added = 0
        for _, T in ipairs(P.visited_levels or {}) do
            if not Have[T] then
                local Ok = pcall(function()
                    local N = Grow(VL)
                    VL[N].TagName = FName(T)
                end)
                if Ok then Added = Added + 1 end
            end
        end
        local Now = {}
        pcall(function() VL:ForEach(function(_, E) Now[TagName(E:get())] = true end) end)
        local Missing = 0
        for _, T in ipairs(P.visited_levels or {}) do if not Now[T] then Missing = Missing + 1 end end
        table.insert(Out, string.format("visited levels +%d (%d still missing)", Added, Missing))
    else
        table.insert(Out, "visited levels unreadable")
    end
    local Line = table.concat(Out, "; ")
    Log("progression, visited levels (%s): %s", tostring(Why), Line)
    return Line
end

return M
