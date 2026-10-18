-- ItrShowcaseLoader settings for the ITR Showcase. Edit this file; main.lua reads it.
-- main.lua is a copy of itr-common's loader (tools/sync_loader.ps1 refreshes it); config.lua and ItrShowcase.loot.json belong
-- to the showcase and are not overwritten by the sync. Every field is explained in itr-common's loader config.lua.
--
-- This is a separate UE4SS mod from itr-common's ITRMapLoader (own folder, own log tag, own console command, own trigger), so
-- both can be installed at the same time: ITRMapLoader loads the example map, this one loads the showcase.
--
-- Entering the showcase (default triggers, change them below):
--   * in the Hub, pick up the pumice stone (static mesh SM_Pumice01, the only one in the Hub), or
--   * press F9, or
--   * type  itrshowcase enter  in the game console.
-- Leaving: walk onto one of the map's return pads (R0 to R4), press F9 again, or type  itrshowcase leave.
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
            NativeSaves = true,                    -- the level saves like a stock zone; a save made inside the map loads back into it
            -- Console variables set while you are in the map and put back to their earlier values when you leave it
            -- (r.ViewDistanceScale: draw distance of meshes; foliage.LODDistanceScale: tree / foliage LOD distances).
            CVars = { ["r.ViewDistanceScale"] = 5, ["foliage.LODDistanceScale"] = 5 },
            NativeReloadOnTide = false,            -- the map has no tide actor yet
            NativeRadius = 250000,
            NativeCenter = { X = -34500, Y = -364000, Z = 0 },              -- centre of the 2.5 km playable square
            NativeStart = { X = -143800, Y = -361200, Z = 2680, Yaw = 0 },  -- the itr:player_start marker (return pad R0 area)
            NativeFallback = false,

            -- Hub item that enters the map: the pumice stone. (The sugar cube, SM_Tea01D, belongs to the example map loader.)
            NativeTriggerMesh = "SM_Pumice01",

            -- The loot tables are kept alive while the map is loaded by this Blueprint actor placed in the map.
            LootHolderClass = "BP_ItrShowcase_LootTables_C",
        },
    },

    Key = "F9",                                -- enters / leaves the map; false = no key
    ConsoleCommand = "itrshowcase",            -- itrshowcase enter [ItrShowcase] / itrshowcase leave

    -- Standing within ExitRadius (cm) of a TargetPoint tagged ExitTag takes you back to the Hub. The map's return pads R0 to R4
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
    LootRetagShim = false,
}
