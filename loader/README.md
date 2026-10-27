# Loader for the ITR Showcase

The game can't enter custom maps by itself. This is the UE4SS Lua mod that registers the showcase with the game as a level
and enters it through the game's level transfer, so you get the normal transition, loot, spawners and arrival. It is based on
[`itr-common/loader-ue4ss`](../../itr-common/loader-ue4ss/), configured for this map, and it is a **separate mod** from
itr-common's `ITRMapLoader` (which loads the example map): different folder (`ItrShowcaseLoader`), log tag, console command,
key and Hub item. The two are written to run side by side, but the showcase is tested with `ITRMapLoader` switched off and does not
need it: switch it off while you play the showcase (see "ITRMapLoader" in [`INSTALL.md`](../INSTALL.md)).

## Origin
- **Base: `itr-common/loader-ue4ss/ITRMapLoader`.** `Scripts/main.lua` and `enabled.txt` started as copies of it. Generic fixes
  belong there. At the moment `main.lua` here also has additions that itr-common does not have yet: adopting a save the
  game loads inside the map, the removal of the startup guard that moved such a save to the Hub, the level gates and the tablet
  picture, the missions glue and the cheap game-mode and game-data lookups. A plain re-copy from itr-common would drop them, so until
  they are merged upstream this file is maintained here.
- **Showcase-specific:**
  - `Scripts/config.lua`: the map entry (`ItrShowcase`, `/Game/Mods/ItrShowcase/L_ItrShowcase`, tag
    `Level.Zone.ItrShowcase`, map centre, start position, the tablet map settings and the return-pad markers), the triggers, the log
    tag, the console command and the missions switch.
  - `Scripts/ItrShowcase.loot.json`: the map's loot tags and budgets (68 tags). `main.lua` finds it as
    `<Map Name>.loot.json` next to itself. Without it the map still loads, but the loader skips the loot registration
    (the log says `no loot manifest`).
  - `Scripts/missions.lua` and `Scripts/ItrShowcase.missions.json`: the showcase missions (see "Missions" below).

## Install
The release archives (normal zip or FOMOD, see [`INSTALL.md`](../INSTALL.md)) contain this folder, the map pak and UE4SS, and put
this folder at `Content\Paks\LuaMods\ItrShowcaseLoader` (Nexus UE4SS layout). To install it by hand into an existing UE4SS, put
the `ItrShowcaseLoader` folder into UE4SS's mods folder; the settings and the UE4SS build that were tested are in `INSTALL.md`.
The loader needs `shared/UEHelpers/UEHelpers.lua` from UE4SS in the same mods folder: `main.lua` does `require("UEHelpers")`.
The empty `enabled.txt` turns the loader on; no `mods.txt` entry is needed.

## Getting in (defaults, all in `Scripts/config.lua`)
- **The tin of graphite grease.** In the Hub's workshop corner (by the tool wall and workbench), pick up the grey metal tin with
  the yellow lid and the "GRAPHITE GREASE 500g" label: the Hub prop whose static mesh is `Liquid08_1`, the only prop placed in the Hub with that
  mesh. A second tin and a loose lid beside it use other meshes and do nothing. Set `NativeTriggerMesh` to another Hub prop's mesh name
  to change it; the sugar cube (`SM_Tea01D`) is taken by the example map loader.
- **The key `F9`** (`Key`; `false` for none). It leaves again too.
- **The console command** `itrshowcase enter` (and `itrshowcase leave`); `ConsoleCommand` changes the name. Another mod can
  send it with `ExecuteConsoleCommand`.
- `TriggerFile = "<full path>"` enters the map when that file appears (it is deleted when seen). A test hook.
Entering only works from the Hub; nothing is ever loaded from the main menu.

## Leaving and coming back
- The map has exits at its return points R0 to R6: `TargetPoint`s tagged `itr:exit` and `itr:exit_id:R<n>`, on the return pads.
  Stand within `ExitRadius` (150 cm) of one and the loader asks the game to go back to the Hub. `F9` and `itrshowcase leave`
  leave too.
- **Re-entry.** Leaving through an exit with an id is remembered in `Scripts/reentry.txt`. The next entry puts you at
  the `itr:arrive:R<n>` marker in front of that exit instead of the start. Delete the file to forget, or set `ReEntry = false`.
- The map's teleport pads (`itr:tp:*` points, and the cyan to-entrance pads) only move you around inside the map. They do not
  leave it.

## Saving
`NativeSaves = true`: the level row copies the donor zone's (Buffer) autosave, save-on-load, save-on-exit and sleeping flags, so
the game saves while you are in the map as it does in a stock zone. The loader has no fallback that moves a save. The one thing it
writes into save data is the progression unlock of the missions (see "Missions").

**Known issue:** a save made inside the map loads into the Hub, not into the map. The loader registers the level at startup,
before the main menu offers the save, and `IsLevelTagValid` answers true, yet the loaded save comes back in the Hub; the cause is
not found yet. Two untested ideas: the save stores the level as a gameplay tag that is not in the tag manager (only the name is
written), or the manual save path ignores the row's save flags. The code that handles a save the game loads inside the map (arm the
exits, point the loot at the map's tables, apply the view settings) is in `main.lua` for when that works.

If the mod is removed, or the registration fails, a save made inside the map names a level the game does not know, so leave the
map before you uninstall.

## View settings
While you are in the map `r.ViewDistanceScale 6` and `foliage.LODDistanceScale 6` are set, and the earlier values are put
back when the map goes, however you leave. This is done by the Blueprint actor `BP_ItrShowcase_MapSettings` in the map
(BeginPlay remembers and sets, EndPlay restores); it is not a loader setting. The compass target (`BP_ItrShowcase_CompassSky`) and
the player level and trigger flags of the progression unlock (`BP_ItrShowcase_Progression`) are Blueprint actors in the map too, so the
loader does no per-frame or per-second work for them.

## Loot
The map includes its loot `DataTable`s and keeps them alive with a `BP_ItrShowcase_LootTables` actor that holds hard
references to all of them (`LootHolderClass` in the config). At startup the loader registers the tags from
`ItrShowcase.loot.json` in the game's loot config on the stock donor tables, points them at the map's tables while the
map is loaded, and points them back at the donor tables when it goes. See "Loot" in the itr-common loader README.

## Tablet map
The hip tablet shows blank paper outside the map. `NativeMapPicture = true` makes the loader point the map's level row at the
material instance on the map board (the `StaticMeshActor` tagged `NativeMapBoardTag`, `itr:mapboard`) while the map's level is
loaded, and back at the blank paper before it goes. `NativeMapScale` and `NativeMapRotation` set the picture's scale and turn.
`NativeGates` lists one stock `LevelGates` row per return pad (position in cm from `NativeCenter`), so the tablet draws the pads as
transition markers.

## Missions
`Missions = { Enabled = true }` in `config.lua` switches `Scripts/missions.lua` on. It reads `ItrShowcase.missions.json` and, once the
game is idle, registers a "showcase" mission category and its twelve missions (cooked data assets in the map pak), adds the objective
points to the map-point configuration, appends eight more missions to the stock random pools, and keeps the next mission of the series
on offer at the mission computer. The category is once-only (`once_in_a_life` in the manifest): a finished mission is not offered
again. The mission ids are unused leaf tags the game registers at start (`Mission.ID.Generic.*`); a tag the game does not register
is never matched by its finished / eligible bookkeeping, so the series would repeat. When the map loads, the loader adds the stock
zones to the visited levels; the player level and the trigger flags of the unlock are set by `BP_ItrShowcase_Progression`. A failed
step is logged and turns only the missions off. See the README before you remove the mod from a save that holds showcase missions.

## What to look at in the log
`UE4SS.log` (next to `UE4SS.dll`) has everything under the prefix `[ItrShowcaseLoader]`: `ready: ...` at startup, then
`native: level row ... added`, `native: gates ...`, `native: READY`, `native trigger: ...`, `native: arrived ...`, `loot: ...`,
`map picture: ...`, `missions: ...` and `native exit ...`. A native error from UE4SS shows as `Error:` lines without the prefix.
