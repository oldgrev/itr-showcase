# ITR Showcase

A large custom map for **Into the Radius 1 (version 2.7.2)**, with its Unreal project. It is a reference for people
building their own maps: how big a 2.7.2 map can be, how the zone look is matched(but not particularly well yet), and how the game's gameplay systems
(loot, spawners, rifts, stashes, anomalies, cover, navmesh, teleports and exits) are set up in a level that the game
streams in from the Hub. Open the project to inspect the placements and copy what you need.

About 2.5 x 2.5 km playable, with a low-detail backdrop beyond it, built from 2.7.2 assets only.

![Layout overview of the ITR Showcase map](docs/images/layout-overview.jpg)

*Layout overview, north up, 250 m grid. The playable area is about 2.5 x 2.5 km.*

## Status
**Early test with issues.** The map loads, can be walked, and has been through automated in-game runs. A full pass in VR
is still to come. Known issues:
- The UE4SS Lua loader that gets you into the map has not had a clean end-to-end pass yet. Its Hub teardown, exit and
  gameplay-activation code was ported from our C++ mod.
- Loot through the map-held loot tables (the map's `DataTable`s, kept alive by an actor in the level) is untested on
  the Lua path.
- Landing on a teleport point drops you about 128 cm.
- Grass, water and long-view-distance performance are still being checked in VR.

The sister repo [`itr-common`](../itr-common/) has the map-making how-to, the editor patch and the loader this relies on,
and says for each thing how far it has been tested.

## What's in the repo
| Folder / file | What |
|---|---|
| `project/` | The Unreal 4.27 project. It has to be called `IntoTheRadius.uproject`. The map is in `Content/Mods/ItrShowcase/`: `L_ItrShowcase.umap` (the level, stored with Git LFS), the landscape layers and material, sky and marker materials, the 36 loot `DataTable`s and the generated Blueprints. |
| `project/Plugins/ItrShowcaseEditor` | An optional editor plugin that builds the map's Blueprints (teleport pad, light event, light follower, loot-table holder, an event director) from JSON specs. You don't need it to open the map or to make your own. |
| `project/build-map.ps1`, `extract-game-config.ps1` | Cook and pack the map into a pak; extract the game's `DefaultEngine.ini`. |
| `loader/` | The UE4SS Lua loader that streams the map in, configured for it. See [`loader/README.md`](loader/README.md). |
| `docs/images/` | Pictures used in this README. |
| `INSTALL.md` | How to install the release (also included in the release zip). |

Not in the repo:
- **The pak.** It is a **GitHub release** asset.
- **UE4SS.** It is linked in `INSTALL.md`.
- **The game's assets.** The map references meshes, materials and textures by their `/Game/...` path and the pak
  contains none of them. The project's copies of those (under `project/Content` outside `Mods/ItrShowcase`) are
  git-ignored. See "Opening the project".

## Cloning (Git LFS)
`project/Content/Mods/ItrShowcase/L_ItrShowcase.umap` is about 156 MB, over GitHub's file limit, so it is stored with
**Git LFS**. Install [Git LFS](https://git-lfs.com/) before cloning:
```
git lfs install
git clone <this repo>
```
If you cloned without it, the `.umap` is a small text pointer file; run `git lfs pull` inside the repo.

## Install and play (from the release)
Download `ItrShowcase-<date>.zip` from the **Releases** page. It holds the pak, the loader and `INSTALL.md`. In short:
1. Install **UE4SS v3.0.1-321-gc62ada0** ("UE4SS for ITR1", https://www.nexusmods.com/intotheradiusvr/mods/359, file
   `UE4SS-ITR-359-v3-0-1-321-gc62ada0`). It is not bundled. Other builds are not known to work; a newer dev build
   crashed the game at startup in our tests.
2. Check its settings: GUI and console off (`GuiConsoleEnabled`, `GuiConsoleVisible`, `ConsoleEnabled` = 0),
   `bUseUObjectArrayCache = false`, `HookInitGameState = 0`, `HookLoadMap = 1`, `ModsFolderPath` matching your mods folder.
3. Copy the zip's `ue4ss/Mods/ITRMapLoader` into UE4SS's mods folder (`LuaMods` in the Nexus layout, `Mods` in the
   standard layout, where `mods.txt` also needs `ITRMapLoader : 1`). `shared/UEHelpers.lua` has to be in that folder
   too; it comes with UE4SS.
4. Copy `zzz_ITRMap_ItrShowcase_P.pak` into `<game>\IntoTheRadius\Content\Paks\`.
5. Continue into the Hub; the loader moves you onto the map a few seconds later. Walk onto a return pad, or press `F7`,
   to leave.

Both UE4SS layouts, the full settings table, and what to do if the game hangs are in [`INSTALL.md`](INSTALL.md).

## What the map demonstrates
Everything below is placed in `L_ItrShowcase` (the persistent level of the map) and grouped in the World Outliner by
area: `A0_Checkpoint/...` to `A9_Quarry/...`. The numbers are approximate, from the last full build; the outliner has the
real ones.

### Scale and layout
- Landscape of 2521 x 2521 vertices (about 2.5 km) plus a 757 x 757 backdrop landscape, with a separate material
  (`M_ItrShowcase_Landscape`: eight weight-blended layers using 2.7.2 ground textures, `LI_ItrShowcase_*`).
- Roads, rail, a river and a lake, a canyon with a rail bridge, a ridge with a relay mast, a quarry, a town, a farm, a
  construction district, a lake village and a forest district, in ten areas (A0 to A9), difficulty rising from south to
  north. The start is a checkpoint in the south.
- About 12,600 placed items, plus about 58,000 trees and undergrowth instances in HISM groups.
- Placed at world (-34500, -364000, 0) cm so the whole map is inside the Hub's level radius (the game sends you back to the
  Hub beyond it).

### Zone look
Sun, sky light (the game's cubemap `04-03_Sun_A_1024`), height fog and an unbound post-process volume, following the
2.7.2 Buffer zone's setup; the sky sphere is the game's mesh and master material with our instances
(`MI_ItrShowcase_Sky_*`). Landscape grass uses copies of the game's grass types with longer cull distances
(`Content/Mods/ItrShowcase/Grass`).

### Gameplay systems
All of these are the game's Blueprints (`/Game/ITR/BPs/...`) with per-instance property overrides. Open the level and
select one to see how it is configured.

| System | Class | Where | How it's set up |
|---|---|---|---|
| Enemy squads | `BP_MonsterSpawner` (about 100 free and generator-owned) | `<Area>/Gameplay/Spawners` | `Monsters` is a map of NPC tag to count (for example `NPC.Monster.Mimic.PM`: 1, `NPC.Monster.Fragment`: 2), `Radius` is the spawn scatter (roughly 10 to 65 m for roaming squads), `AlternativeMonstersMax` 1 to 3, `CanWalkAway`, `SnipingMode` for marksmen. Each has a stable `SpawnerInstanceID` of the form `L_ItrShowcase>A7_Spawner_003`, which is the key the game's save uses. The roster gets harder from tier 1 (Spider, Fragment, Phantom, Mimic PM) to tier 3 (armoured Mimics, Seekers, Marksmen). |
| Static NPCs | the same `BP_MonsterSpawner` (about 20) | `<Area>/Gameplay/Static` | One monster, `CanWalkAway` off, a `Radius` of a few metres at most, so the NPC stands where you placed it: guards, a man in an attic. Snipers also set `SnipingMode`. |
| Rifts | `BP_MonsterSpawnGenerator` (18) | `<Area>/Gameplay/Rifts` | The visible, shootable source of enemies. `generatorID` is a custom tag (`NPC.Generator.ItrShowcase.A0_1`), `Spawners` lists the spawners it drives, `CooldownSeconds` 150. The tags are registered in the project's gameplay tags. |
| Loot | `BP_RandomLoot` (about 1,050) | `<Area>/Gameplay/Loot` | `LootTable` is a custom tag (`Loot.ItrShowcase.T1.Ammo`), `LootPoints` is the node's share of the tag's budget, `InstanceID`/`InstanceIDPrefix` are set so the save can key them. Tags are per tier and category: Ammo, Equipment, FoodBaseItem, plus stashes. |
| Stashes and corpses | `BP_Stash_Small`, `BP_Stash_Large` (about 70), `BP_Corpse` (about 55) | `<Area>/Gameplay/Stashes` | Same `LootTable` mechanism with the `Stash.Red`, `Stash.Grey`, `Stash.Valuables` and `Stash.Deadmans` tags. |
| Anomalies | `BP_Anomaly_Gas`, `_Grass`, `_Web`, `_Reflector`, `_Distortion`, `_Lightning`, `_Stomper`, `_Scythe` (about 190) | `<Area>/Gameplay/Anomalies` | One actor each, no property overrides. The game's anomaly clusters are driven by map-point data registered per level, so as far as we know they don't work in a custom map; this map uses single anomalies. |
| AI cover | `ItrShowcase_CoverLoader`, a child of the game's `ACoverLoader` (`Content/Mods/ItrShowcase/Blueprints/BP_ItrShowcase_CoverLoader`) | persistent level | One actor holding the cover and shooting-position arrays (plain world-space `FVector`s, the same data the zone levels carry) with the zone's `CoverSettings`. |
| Navmesh | `NavMeshBoundsVolume` (31) | `<Area>/Gameplay/Nav` | Per-area volumes around the gameplay footprints (about 165 ha in total), not the whole map, baked for the game's two agents (Default and Big). |
| Teleports | `TargetPoint`s tagged `itr:tp:<group>/<name>` | `Teleports/<group>` | Standing-height points on walkable ground (dry, not on a steep slope). The game ignores the tag; it is a label for dev tools, and the loader prefers these points as the staging point during the Hub teardown. |
| Exits and arrivals | `TargetPoint`s tagged `itr:player_start`, `itr:exit` + `itr:exit_id:R<n>`, `itr:arrive:R<n>` | `Returns/R0` to `Returns/R4` | Read by the loader. Walking onto an exit marker takes you back to the Hub; the next entry puts you at the matching arrive marker. |
| Return pads | `BP_ItrShowcase_TeleportPad` | `Returns/R<n>` | An engine-only Blueprint (no game classes) that teleports you back to the start area. |

### Loot setup
This is the part most map makers will want to copy.
- The game's loot budgets are global and save-wide per tag, so a 2.5 km map reusing the vanilla zone tags would be sparse.
  The map therefore has **36 custom loot tags** (`Loot.ItrShowcase.<tier>.<category>`) in four tiers (T1, T2, T25, T3, getting
  better to the north), each with a budget scaled from the vanilla zone it is modelled on by area. The manifest is
  `loader/ITRMapLoader/Scripts/ItrShowcase.loot.json`; it records the tag, the donor tag, the table and the budget.
- Each tag has a `DataTable` (`Content/Mods/ItrShowcase/Loot/DT_Loot_ItrShowcase_*`), with rows cloned from the donor
  zone's table, so used loot points are not shared with the vanilla zones.
- Nothing in the map registers these tags with the game, so the loader does it at load time: it adds each tag to the game
  config's `LootArray` (`TMap` of tag to `FPRLootTableConfig`). See "Gameplay activation" in
  [`itr-common`'s loader README](../itr-common/loader-ue4ss/README.md).
- The tables must stay loaded. `BP_ItrShowcase_LootTables` is a placed actor whose `Tables` array holds a hard reference to
  every ItrShowcase table, so they load and unload with the level. **This path is untested in Lua** (see Status).
- Generator ids follow the same idea: `NPC.Generator.ItrShowcase.<area>_<n>`.

### Streamed-level gameplay
A map streamed in from the Hub misses the level-start events the game fires for its levels, so spawners, loot and
anomalies would sit idle. The loader sends them `OnLevelPrepare`, `GenerateLoot`, `OnLevelStarted`, `OnGameStarted` and
`OnTransitionEnd` about 3 s after you arrive. It also unloads the Hub's streaming levels while you are on the map, because
the map reaches west of world X -30000, where the game sends you back to the Hub. Details: [`loader/README.md`](loader/README.md)
and the loader README in `itr-common`.

## Opening the project
You can open `project/IntoTheRadius.uproject` to inspect the level, the Blueprints and the placements. What that needs:
- **Engine.** Unreal 4.27. We only opened it with the **patched Oculus 4.27 editor** from `itr-common` (route B in its
  [guide](../itr-common/map-making/guide.md)), which the landscape material needs. A stock editor is untested.
- **It is a code project, and the SDK code is not in this repo.** Copy the community SDK's recreation of the game's C++
  module into `project/Source/IntoTheRadius`, and its `VRExpansionPlugin` and `ModFramework` plugins into
  `project/Plugins/`. The module has class and property declarations with empty bodies, so the editor can load Blueprints
  parented on the game's classes. Compile it the first time you open the project (Visual Studio with the C++ game workload).
  The game's real module is in the game; none of this goes into the pak. Our editor plugin,
  `Plugins/ItrShowcaseEditor` (builds the map's Blueprints from JSON specs), is included and optional.
- **Game config.** `Config/DefaultEngine.ini` is the game's file and is not in the repo. Extract it once:
  `project\extract-game-config.ps1 -Engine "<your editor>\Engine"`.
- **Gameplay tags.** The placed Blueprints store tags (`Loot.*`, `NPC.Monster.*`, `NPC.Generator.*`). The editor clears a
  tag value it doesn't know, so the game's tag lists need to be in `Config/DefaultGameplayTags.ini` and `Config/Tags/`
  (they come from the SDK's `Config`). The map's tags are in `Config/Tags/ItrShowcaseGameplayTags.ini`.
- **The game's assets.** The level references the game's meshes, materials, textures and Blueprints by path. Without the
  community **ITR-SDK** (ChuckSharts, see the itr-common guide §1) copied into `project/Content` at the same `/Game` paths,
  those references are missing and the level opens with empty slots. Take the gameplay Blueprints from ChuckSharts's SDK,
  not R3mains's. The SDK's master materials are reconstructions: reference them, don't cook your own copies of them.
  A handful of the meshes (the tower-crane kit and some others) are in no SDK at all.
- **Cook and pack** (only if you want to make your own pak from a modified level):
  `project\build-map.ps1 -Engine "<your editor>\Engine"` cooks `/Game/Mods/ItrShowcase/L_ItrShowcase` and packs only
  `/Game/Mods/ItrShowcase` into `zzz_ITRMap_ItrShowcase_P.pak`, so none of the copied game assets end up in it. Landscape
  grass data is baked in the editor and has to be baked before cooking, or the grass is missing from the pak.

The levels were generated by scripts and then baked (navmesh, grass), not authored by hand in the editor. The result is a
normal level you can edit.

## Attribution
Five of the map's sites (the checkpoint, construction yard, farm, station and quarry) are laid out 1:1 from OpenStreetMap
data, and the village street patterns are measured from other villages. Contains data (c) OpenStreetMap contributors,
available under the Open Database Licence (ODbL) 1.0: https://www.openstreetmap.org/copyright.

## Licence and credits
The licence of this repo is not settled yet. Expect the same as `itr-common`: AGPL-3.0 for the scripts, with the Unreal
Engine EULA applying to any cooked pak. The map is made of the game's assets, referenced by path; we don't
redistribute them.

Credits:
- **Into the Radius** is by CM Games; all game assets belong to them.
- **ITR-SDK** by ChuckSharts, and the other community SDK copies: the gameplay Blueprints and module declarations this
  project builds on.
- **UE4SS**, and the "UE4SS for ITR1" repack on Nexus Mods by MerithXYZ.
- **OpenStreetMap contributors** because I used some stats from regional building layouts to drive my layouts.
