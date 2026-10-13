# Loader for the ITR Showcase

The game can't enter custom maps by itself. This is the UE4SS Lua script that streams the showcase in from the Hub and
takes you back out. It is a copy of [`itr-common/loader-ue4ss`](../../itr-common/loader-ue4ss/), configured for this map.

**Status: early test with issues.** The parts of this loader that run the Hub teardown, the exit, the re-entry memory,
gameplay activation and loot registration were ported from our C++ mod and have not had a clean end-to-end pass through
UE4SS Lua yet. See "Known issues" in the [main README](../README.md#status). The itr-common README says in detail what
has been tested.

## Origin
- **Source of truth: `itr-common/loader-ue4ss/ITRMapLoader`.** `Scripts/main.lua` and `enabled.txt` here are unmodified
  copies. Fixes go there first and are then copied here by a maintainer script (it lives in our private workspace).
- **Showcase-specific, not overwritten by the sync:**
  - `Scripts/config.lua`: one map entry (`ItrShowcase`, `/Game/Mods/ItrShowcase/L_ItrShowcase`, start tag
    `itr:player_start`) and `AutoLoadInHub = "ItrShowcase"`.
  - `Scripts/ItrShowcase.loot.json`: the map's loot tags and budgets (36 tags). `main.lua` finds it as
    `<Map Name>.loot.json` next to itself. Without it the map
    still loads, but the loader skips the loot registration (the log says `no loot manifest`).

## Install
Put the `ITRMapLoader` folder (this folder's `ITRMapLoader/`) into UE4SS's mods folder. The steps for UE4SS itself, its
settings and where the mods folder is are in [`INSTALL.md`](../INSTALL.md) (the same text is in the
release zip). The loader needs `shared/UEHelpers.lua` from UE4SS in the same mods folder: `main.lua` does
`require("UEHelpers")`.

## Starting the map
- **Automatic (default here, `AutoLoadInHub = "ItrShowcase"`).** Continue into the Hub as usual. Once the Hub has been
  loaded for two checks in a row (2 s apart), the loader streams the map in, moves you to the start, unloads the Hub's
  levels and starts the map's gameplay. This happens once per visit to the Hub. The teardown and the gameplay start add
  a few seconds on top of the streaming, so give it time. Nothing is ever loaded from the main menu.
- **Keyboard.** `F7` (`Key` in `config.lua`) loads the next map in the `Maps` list. Pressing it again leaves.
  Set `AutoLoadInHub = nil` if you only want the key.
- **Desktop `-nohmd`.** The game never reports the Hub as ready there, so set `RequireLevelManagerReady = false`
  or the auto-load never fires.
- `TriggerFile = "<full path>"` loads the first map when that file appears (it is deleted when seen). A test hook.

## Leaving and coming back
- The map has exits at its return points R0 to R4: `TargetPoint`s tagged `itr:exit` and `itr:exit_id:R<n>`. Stand within
  `ExitRadius` (150 cm) of one and the loader asks the game to load the Hub, then unloads the map. `F7` leaves too.
- **Re-entry.** Leaving through an exit with an id is remembered in `Scripts/reentry.txt`. The next load puts you at
  the `itr:arrive:R<n>` marker in front of that exit instead of the start. Delete the file to forget, or set
  `ReEntry = false`.
- The map's teleport pads (`itr:tp:*` points) only move you around inside the map. They do not leave it.

## Settings worth knowing
All keys are documented in `Scripts/config.lua`. For this map:
- `HubTeardown = true` must stay on. The map reaches west of world X -30000, where the game would send you back to the
  Hub while the Hub's levels are loaded.
- `ActivateGameplay = true` sends the map's spawners, loot points, stashes, anomalies and generators the level-start
  events they would otherwise miss. Without it nothing in the map does anything.
- `LootRetagShim` is a dev-only helper from an earlier map version. Leave it `false`.
- Loot tables: the map includes its `DataTable`s and keeps them alive with a `BP_ItrShowcase_LootTables` actor that
  holds hard references to all of them. The loader reads the tables from that actor and registers the tags from
  `ItrShowcase.loot.json` into the game's loot config. See "Gameplay activation" in the itr-common loader README.

## What to look at in the log
`UE4SS.log` (next to `UE4SS.dll`) has everything under the prefix `[ITRMapLoader]`:
`ready: 1 map(s) ...` at startup, then `streaming ...`, `Hub teardown: ...`, `teleport to ...`, `activate: ...`,
`loot: ...`, `exit marker reached`, `exit: ...` and `unloaded ItrShowcase`. A native error from UE4SS shows as `Error:`
lines without the prefix.

