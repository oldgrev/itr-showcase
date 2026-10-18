# Loader for the ITR Showcase

The game can't enter custom maps by itself. This is the UE4SS Lua mod that registers the showcase with the game as a level
and enters it through the game's level transfer, so you get the normal transition, loot, spawners and arrival. It is based on
[`itr-common/loader-ue4ss`](../../itr-common/loader-ue4ss/), configured for this map, and it is a **separate mod** from
itr-common's `ITRMapLoader` (which loads the example map): different folder (`ItrShowcaseLoader`), log tag, console command,
key and Hub item. Both can be installed at the same time.

## Origin
- **Base: `itr-common/loader-ue4ss/ITRMapLoader`.** `Scripts/main.lua` and `enabled.txt` started as copies of it. Generic fixes
  belong there. At the moment `main.lua` here also has three additions that itr-common does not have yet: the per-map `CVars`
  block (see "View settings"), adopting a save the game loads inside the map, and the removal of the startup guard that moved
  such a save to the Hub. A plain re-copy from itr-common would drop them, so until they are merged upstream this file is
  maintained here.
- **Showcase-specific:**
  - `Scripts/config.lua`: the map entry (`ItrShowcase`, `/Game/Mods/ItrShowcase/L_ItrShowcase`, tag
    `Level.Zone.ItrShowcase`, map centre, start position), the triggers, the log tag, the console command and the view settings.
  - `Scripts/ItrShowcase.loot.json`: the map's loot tags and budgets (45 tags). `main.lua` finds it as
    `<Map Name>.loot.json` next to itself. Without it the map still loads, but the loader skips the loot registration
    (the log says `no loot manifest`).

## Install
The release archives (normal zip or FOMOD, see [`INSTALL.md`](../INSTALL.md)) contain this folder, the map pak and UE4SS, and put
this folder at `Content\Paks\LuaMods\ItrShowcaseLoader` (Nexus UE4SS layout). To install it by hand into an existing UE4SS, put
the `ItrShowcaseLoader` folder into UE4SS's mods folder; the settings and the UE4SS build that were tested are in `INSTALL.md`.
The loader needs `shared/UEHelpers/UEHelpers.lua` from UE4SS in the same mods folder: `main.lua` does `require("UEHelpers")`.
The empty `enabled.txt` turns the loader on; no `mods.txt` entry is needed.

## Getting in (defaults, all in `Scripts/config.lua`)
- **The pumice stone.** In the Hub, pick up the pumice stone (static mesh `SM_Pumice01`, the only one in the Hub). Set
  `NativeTriggerMesh` to another Hub item's mesh name to change it; the sugar cube (`SM_Tea01D`) is taken by the example
  map loader.
- **The key `F9`** (`Key`; `false` for none). It leaves again too.
- **The console command** `itrshowcase enter` (and `itrshowcase leave`); `ConsoleCommand` changes the name. Another mod can
  send it with `ExecuteConsoleCommand`.
- `TriggerFile = "<full path>"` enters the map when that file appears (it is deleted when seen). A test hook.
Entering only works from the Hub; nothing is ever loaded from the main menu.

## Leaving and coming back
- The map has exits at its return points R0 to R4: `TargetPoint`s tagged `itr:exit` and `itr:exit_id:R<n>`, on the return pads.
  Stand within `ExitRadius` (150 cm) of one and the loader asks the game to go back to the Hub. `F9` and `itrshowcase leave`
  leave too.
- **Re-entry.** Leaving through an exit with an id is remembered in `Scripts/reentry.txt`. The next entry puts you at
  the `itr:arrive:R<n>` marker in front of that exit instead of the start. Delete the file to forget, or set `ReEntry = false`.
- The map's teleport pads (`itr:tp:*` points, and the cyan to-entrance pads) only move you around inside the map. They do not
  leave it.

## Saving
`NativeSaves = true`: the level row copies the donor zone's (Buffer) autosave, save-on-load, save-on-exit and sleeping flags, so
the game saves while you are in the map as it does in a stock zone. The loader never edits a save and has no fallback that
moves one.

**Known issue:** a save made inside the map loads into the Hub, not into the map. The loader registers the level at startup,
before the main menu offers the save, and `IsLevelTagValid` answers true, yet the loaded save comes back in the Hub; the cause is
not found yet. Two untested ideas: the save stores the level as a gameplay tag that is not in the tag manager (only the name is
written), or the manual save path ignores the row's save flags. The code that handles a save the game loads inside the map (arm the
exits, point the loot at the map's tables, apply the view settings) is in `main.lua` for when that works.

If the mod is removed, or the registration fails, a save made inside the map names a level the game does not know, so leave the
map before you uninstall.

## View settings
While you are in the map the loader sets `r.ViewDistanceScale 5` and `foliage.LODDistanceScale 5` (`CVars` in
`config.lua`) and puts back the earlier values when you leave, however you leave. The lines `cvars: ...` in `UE4SS.log`
show both steps.

## Loot
The map includes its loot `DataTable`s and keeps them alive with a `BP_ItrShowcase_LootTables` actor that holds hard
references to all of them (`LootHolderClass` in the config). At startup the loader registers the tags from
`ItrShowcase.loot.json` in the game's loot config on the stock donor tables, points them at the map's tables while the
map is loaded, and points them back at the donor tables when it goes. See "Loot" in the itr-common loader README.

## What to look at in the log
`UE4SS.log` (next to `UE4SS.dll`) has everything under the prefix `[ItrShowcaseLoader]`: `ready: ...` at startup, then
`native: level row ... added`, `native: READY`, `native trigger: ...`, `native: arrived ...`, `loot: ...`, `cvars: ...` and
`native exit ...`. A native error from UE4SS shows as `Error:` lines without the prefix.
