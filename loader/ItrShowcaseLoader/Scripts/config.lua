-- ItrShowcaseLoader settings for the ITR Showcase. Edit this file; main.lua reads it.
-- main.lua started as a copy of itr-common's loader and has additions (see loader/README.md); config.lua,
-- ItrShowcase.loot.json, ItrShowcase.missions.json and missions.lua belong to the showcase. Every field of the generic part is explained
-- in itr-common's loader config.lua.
--
-- This is a separate UE4SS mod from itr-common's ITRMapLoader (own folder, log tag, console command and trigger). The two are
-- written to run side by side, but the showcase is tested with ITRMapLoader switched off and does not need it: switch it off
-- while you play the showcase (INSTALL.md says how).
--
-- Entering the showcase (default triggers, change them below):
--   * in the Hub, pick up the tin of graphite grease in the workshop (static mesh Liquid08_1, NativeTriggerMesh below), or
--   * press F9, or
--   * type  itrshowcase enter  in the game console.
-- Leaving: walk onto one of the map's return pads (R0 to R6), press F9 again, or type  itrshowcase leave.
return {
    LogTag = "ItrShowcaseLoader",              -- the prefix of this loader's lines in UE4SS.log

    Maps = {
        {
            Name = "ItrShowcase",              -- also picks the loot manifest: Scripts/ItrShowcase.loot.json
            Level = "/Game/Mods/ItrShowcase/L_ItrShowcase",
            StartTag = "itr:player_start",

            -- Registered with the game as the level Level.Zone.ItrShowcase and entered through its level transfer.
            Native = true,
            NativeTag = "Level.Zone.ItrShowcase",
            DisplayName = "ITR Showcase",
            NativeDonorTag = "Level.Zone.Buffer",  -- stock zone whose time, inventory and map-scale settings are copied
            NativeSaves = true,                    -- the level saves like a stock zone; a save made inside the map loads back into it (needs zzz_ITRMap_ItrShowcase_Tags_P.pak, which registers the level tag)
            -- The map's console variables (r.ViewDistanceScale 6 and foliage.LODDistanceScale 6, set while you are in the map and put back when you
            -- leave it), the compass target and the progression unlock's player level and trigger flags are Blueprint actors in the map pak
            -- (BP_ItrShowcase_MapSettings, _CompassSky, _Progression), not settings of this file.
            NativeReloadOnTide = true,             -- stock tide: reload after the tide (shelters, respawn), as every stock zone
            NativeGenerators = 33,                 -- rifts the game keeps in the level (AllowedGenerators; the donor zone allows 3). Written by gen/tools/loader_sync.py: do not edit
            NativeRadius = 250000,
            NativeCenter = { X = -34500, Y = -364000, Z = 0 },              -- centre of the 2.5 km playable square
            NativeStart = { X = -143800, Y = -385500, Z = 3184, Yaw = 0 },  -- the itr:player_start marker (return pad R0, Kordon entrance; layout v4: map-local -1093, -215)
            NativeFallback = false,

            -- Hip-tablet map. The picture is the cooked MI_ItrShowcase_Map, taken from the map board actor tagged itr:mapboard while the
            -- level is loaded (the level's reference keeps it alive); the level row shows stock blank paper outside the map.
            -- 2048 map units = half the picture: 100 * MapScale = 1.58 picture pixels per metre, so a 4096 px picture covers 2592 m.
            -- MapRotation 180 turns the markers so that north (+X) is up and east (+Y) is right in the picture.
            NativeMapPicture = true,
            NativeMapBoardTag = "itr:mapboard",
            NativeMapScale = 0.0158,
            NativeMapRotation = 180,
            -- Return markers on the tablet map (stock LevelGates rows, one per return pad R0 to R6). X, Y, Z in cm from NativeCenter,
            -- read from the level's R<n>_Exit TargetPoints.
            NativeGates = {
                { To = "Level.Hub", X = -109500.0, Y = -21500.0, Z = 3184.3 },   -- R0 Kordon (entrance)
                { To = "Level.Hub", X = -100480.0, Y = 64610.0, Z = 3025.8 },    -- R1 Novostroy
                { To = "Level.Hub", X = 64820.0, Y = -65080.0, Z = 4115.8 },     -- R2 Zarechye
                { To = "Level.Hub", X = 74000.0, Y = 106000.0, Z = 4670.0 },     -- R3 quarry office
                { To = "Level.Hub", X = 116500.0, Y = 12000.0, Z = 11010.8 },    -- R4 ridge camp
                { To = "Level.Hub", X = 18300.0, Y = 7000.0, Z = 240.0 },        -- R5 valley fork
                { To = "Level.Hub", X = -6000.0, Y = -67000.0, Z = 98.8 },       -- R6 Tikhoe lake
            },

            -- Hub item that enters the map: the Hub prop whose static mesh is named Liquid08_1, the tin of graphite grease in the workshop.
            NativeTriggerMesh = "Liquid08_1",

            -- The loot tables are kept alive while the map is loaded by this Blueprint actor placed in the map.
            LootHolderClass = "BP_ItrShowcase_LootTables_C",
        },
    },

    -- Showcase missions (Scripts/missions.lua + ItrShowcase.missions.json): a "showcase" mission series at the mission computer (each mission is
    -- offered once), the same missions in the random pool, and (when the map loads) the stock zones added to the visited levels (the player level 5
    -- and the stock shortcut and transition flags of the unlock are set by BP_ItrShowcase_Progression in the map pak). Enabled = false turns the Lua
    -- part off. See the README before removing the mod with showcase missions in a save.
    Missions = { Enabled = true },

    Key = "F9",                                -- enters / leaves the map; false = no key
    ConsoleCommand = "itrshowcase",            -- itrshowcase enter [ItrShowcase] / itrshowcase leave

    -- Standing within ExitRadius (cm) of a TargetPoint tagged ExitTag takes you back to the Hub. The map's return pads R0 to R6
    -- carry itr:exit and itr:exit_id:R<n>.
    ExitTag = "itr:exit",
    ExitIdTagPrefix = "itr:exit_id:",
    ExitRadius = 150,

    NativeExitLocation = nil,                  -- a Hub gate's location tag to arrive at in the Hub, or nil for the Hub's PlayerStart
    TriggerFile = nil,                         -- test hook: creating this file enters the map

    -- Re-entry memory: leaving through an exit with an id remembers it; the next entry arrives at the matching itr:arrive:<ID>.
    ReEntry = true,
    ArriveTagPrefix = "itr:arrive:",
    ReEntryFile = nil,

    HubLevelTag = "Level.Hub",
    RequireLevelManagerReady = true,

    -- Streaming-mode settings (Native = false only; the native entry does not use them)
    AutoLoadInHub = nil,
    HubTeardown = true,
    StagingMaxWestX = -20000,
    ActivateGameplay = true,
}
