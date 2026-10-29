### Scale and layout
- One landscape of 2521 x 2521 vertices (about 2.5 km) with a separate material (`M_ItrShowcase_Landscape`: eight
  weight-blended layers using 2.7.2 ground textures, `LI_ItrShowcase_*`). There is no backdrop landscape: a fog wall
  closes the map (see "The edge of the map").
- Twelve pockets (P1 to P12), each with a tier from T1 to T5 that sets its enemy roster and loot, difficulty rising from south to
  north: P1 Kordon, the entrance checkpoint on the south rim (T1); P2 Berezhok forest (T2); P3 Novostroy construction site and rail
  yard (T2); P4 Tikhoe lake with a boathouse and a lamp isle (T3); P5 Dolina farm (T2); P6 dachas and a rail halt (T3); P7 bridges and
  a fork on the valley floor (T3); P8 canyon and rail bridge (T4); P9 Zarechye town (T4); P10 haul road and a rift compound (T4); P11
  Khrebet ridge with a relay mast, an expedition camp and a cave network (T5); P12 Kariera quarry (T5). Roads, rail, a river and the
  lake link them.
- About 22,000 static-mesh actors, about 1,700 gameplay actors, and about 140,000 foliage and merged-mesh instances in HISM
  groups.
- Placed at world (-34500, -364000, 0) cm. The map is registered as its own level, so the Hub's level radius does not apply;
  the loader gives it a radius of 2.5 km around that point.

### Zone look
Sun, sky light (the game's cubemap `04-03_Sun_A_1024`), height fog and an unbound post-process volume, following the
2.7.2 Buffer zone's setup; the sky sphere is the game's mesh and master material with material instances made for the map
(`MI_ItrShowcase_Sky_*`), and the Radius ball sits in the north. Sun and sky light intensity are still 3.0 in the pak
(intended 1.0, see Status). Landscape grass uses copies of the game's grass types with longer cull distances
(`Content/Mods/ItrShowcase/Grass`).

### The edge of the map
The map ends in a square fog wall about 1.25 km from the centre, so there is no backdrop to build or load. The pieces:
- `BP_ItrShowcase_PerimeterTide` (`Content/Mods/ItrShowcase/Blueprints`): a child of the game's `BP_TideBase`. It tests the player
  against a square (about 1247 m from the centre) every 0.1 s instead of the stock circle and then calls the stock `DoTransition`:
  the player is moved to one of the respawn points and the level is re-entered through the game's transition.
- Seven `BP_SpawnSpline` actors inside the nav volumes are the respawn points (`PlayerSpawn`).
- Twelve `FogWall_*` plane actors (four sides, three layers: fog, masked fog and an opaque backstop) with the game's fog materials
  (`FogMaterial_Inst`, `MI_FogMaterial_Masked`), up to 180 m high.
- The backdrop landscape and the trees and foliage past the edge of the main landscape were removed, so nothing outside the wall
  is built or loaded.

### Gameplay systems
All of these are the game's Blueprints (`/Game/ITR/BPs/...`) with per-instance property overrides. Open the level and
select one to see how it is configured.

| System | Class | Where | How it's set up |
|---|---|---|---|
| Enemy squads | `BP_MonsterSpawner` (about 600, roaming and static together) | `<Pocket>/Gameplay/Spawners` | `Monsters` is a map of NPC tag to count (for example `NPC.Monster.Mimic.PM`: 1, `NPC.Monster.Fragment`: 2), `Radius` is the spawn scatter (roughly 10 to 55 m for roaming squads), `AlternativeMonstersMax` 1 to 4, `CanWalkAway`, `SnipingMode` for marksmen. Each has a stable `SpawnerInstanceID` of the form `L_ItrShowcase>P1_P1_KPP_E1_b0`, which is the key the game's save uses. The roster gets harder from tier 1 (Spider, Fragment, Mimic PM) through Seekers and armed Mimics (sawn-off shotgun, MP5, SVD) to armoured Seekers, Fragments and Mimics (AKSu, AKM, Val) and a few Sliders in tiers 4 and 5. |
| Static NPCs | the same `BP_MonsterSpawner` | `<Pocket>/Gameplay/Static` | One monster, `CanWalkAway` off, a `Radius` of a few metres at most, so the NPC stands where you placed it: guards, a man in an attic. Snipers also set `SnipingMode`. |
| Rifts | `BP_MonsterSpawnGenerator` (12) | `<Pocket>/Gameplay/Rifts` | The visible, shootable source of enemies. `generatorID` is a custom tag (`NPC.Generator.ItrShowcase.A0_1`), `Spawners` lists the spawners it drives, `CooldownSeconds` 150. The tags are registered in the project's gameplay tags. |
| Loot | `BP_RandomLoot` (about 500) | `<Pocket>/Gameplay/Loot` | `LootTable` is a custom tag (`Loot.ItrShowcase.T1.Ammo`), `LootPoints` is the node's share of the tag's budget, `InstanceID`/`InstanceIDPrefix` are set so the save can key them. Tags are per tier and category: Ammo, Equipment, FoodBaseItem, plus stashes. |
| Artifacts | `BP_RandomLoot` (about 190 of the 500, one point each) | `<Pocket>/Gameplay/Artifacts` | Loot nodes next to the anomalies, on the per-tier `Loot.ItrShowcase.<tier>.Artifact` tags. |
| Stashes and corpses | `BP_Stash_Small`, `BP_Stash_Large` (about 330 together), `BP_Corpse` (2) | `<Pocket>/Gameplay/Stashes` | Same `LootTable` mechanism with the `Stash.Red`, `Stash.Grey`, `Stash.Valuables` and `Stash.Deadmans` tags, plus ten signature stashes. Stashes are placed out of sight rather than in the open. |
| Anomalies | `BP_Anomaly_Gas`, `_Grass`, `_Web`, `_Distortion`, `_Lightning` (about 270) | `<Pocket>/Gameplay/Anomalies` | One actor each, no property overrides. The game's anomaly clusters are driven by map-point data registered per level, so as far as we know they don't work in a custom map; this map uses single anomalies. |
| Mission points | `BP_ItrShowcase_MissionPoint` (20) | the pockets | Objective points of the showcase missions. The loader registers each point's tag and position with the game's map-point configuration. |
| AI cover | `ItrShowcase_CoverLoader`, a child of the game's `ACoverLoader` (`Content/Mods/ItrShowcase/Blueprints/BP_ItrShowcase_CoverLoader`) | persistent level | One actor holding the cover and shooting-position arrays (plain world-space `FVector`s, the same data the zone levels carry) with the zone's `CoverSettings`. |
| Navmesh | `NavMeshBoundsVolume` (12) | `Nav` | Volumes around the gameplay footprints, not the whole map, baked for the game's two agents (Default and Big). |
| Teleports | `TargetPoint`s tagged `itr:tp:<group>/<name>` | `Teleports/<group>` | Standing-height points on walkable ground (dry, not on a steep slope). The game ignores the tag; it is a label that tools such as a teleport menu can list. |
| Exits and arrivals | `TargetPoint`s tagged `itr:player_start`, `itr:exit` + `itr:exit_id:R<n>`, `itr:arrive:R<n>` | `Returns/R0` to `Returns/R6` | Read by the loader. Walking onto an exit marker takes you back to the Hub; the next entry puts you at the matching arrive marker. R0 is the entrance at P1; R6 is at the lake (P4). |
| Return pads | a flat disc and a light beam (static meshes) | `Returns/R<n>` | The visible part of each exit: stand on the pad and the loader's exit marker on it sends you to the Hub. |
| To-entrance pads | `BP_ItrShowcase_TeleportPad` | `Returns/R<n>` | An engine-only Blueprint (no game classes) beside R1 to R6 that teleports you inside the map, back to the R0 start area. |
| Fog perimeter | `BP_ItrShowcase_PerimeterTide`, `BP_SpawnSpline`, `FogWall_*` | `Global/Perimeter` | See "The edge of the map". |
| Map board and tablet map | a two-sided map sign (a `StaticMeshActor` tagged `itr:mapboard`) carrying the material instance `MI_ItrShowcase_Map` | at the entrance | The picture on the sign is also what the hip tablet shows while you are in the map: the loader points the map's level row at the sign's material, and adds one `LevelGates` row per return pad so the pads show as markers. |
| Runtime settings | `BP_ItrShowcase_MapSettings`, `BP_ItrShowcase_CompassSky`, `BP_ItrShowcase_Progression` | persistent level | Blueprint actors that do what a loader would otherwise do every tick: `MapSettings` sets `r.ViewDistanceScale 6` and `foliage.LODDistanceScale 6` in BeginPlay and restores the earlier values in EndPlay, `CompassSky` sets the compass target, `Progression` sets the player level and the trigger flags of the progression unlock. |

### Loot setup
This is the part most map makers will want to copy.
```
Quick interjection since most of this document was with ai and it's made a heck of a claim right there!
It's a bit strong to say 'map makers will want to copy', since the loot on this is map a little different and it's not just "here is loot table". So
a) folks might find this a little overcomplicated for what *they* want, although it does simplify down
b) once some maps are made, circulated and played, a better approach may be adopted.
So it's a tad overconfident to say 'map makers will want to copy' and then not call out clearly why the loot in the map is pretty cool imho.
- you get to define your loot table(s)
- you can also have different loot tables(tiers) assigned to different spawners and each tier has their own budget.
It's not mind blowing, but it's something I haven't seen done in ITR yet.
```
- The game's loot budgets are global and save-wide per tag, so a 2.5 km map reusing the vanilla zone tags would be sparse.
  The map therefore has **68 custom loot tags** (`Loot.ItrShowcase.<tier>.<category>`): five tiers T1 to T5 (getting better to
  the north, one per pocket tier), each with a budget scaled from the vanilla zone it is modelled on by area, plus ten signature
  stash tags and a small example set (`G2`). The manifest also lists an intermediate tier `T25` that the current layout does not
  use. The manifest is `loader/ItrShowcaseLoader/Scripts/ItrShowcase.loot.json`; it records the tag, the donor tag, the table and
  the budget.
- Each tag has a `DataTable` (`Content/Mods/ItrShowcase/Loot/DT_Loot_ItrShowcase_*`), with rows cloned from the donor
  zone's table, so used loot points are not shared with the vanilla zones.
- Nothing in the map registers these tags with the game, so the loader does it at startup: it adds each tag to the game
  config's `LootArray` (`TMap` of tag to `FPRLootTableConfig`) on the stock donor tables, which never unload. See "Loot" in
  [`itr-common`'s loader README](../itr-common/loader-ue4ss/README.md).
- The map's tables must stay loaded while you are in it, or the game reads a freed table. `BP_ItrShowcase_LootTables` is a
  placed actor whose `Tables` array holds a hard reference to every ItrShowcase table, so they load and unload with the level. Once
  the level is loaded the loader points the entries at those tables, and back at the donor tables when the level goes.
- Generator ids follow the same idea: `NPC.Generator.ItrShowcase.<area>_<n>` (the area part is `A0` to `A9`, a numbering the
  generator still uses for the rifts).

### Native level loading
The loader registers the map with the game as a level, `Level.Zone.ItrShowcase`, and enters it with the game's level
transfer (`TransferToLevel`), so the transition, the unload of the Hub, the prepare and start events, the loot pass and the arrival
run as they do for a stock zone. What it does, at startup, before the main menu:
- adds a streaming entry for `L_ItrShowcase` (`LevelStreaming::CreateInstance`) and a level row to the system config's
  `LevelConfigurations`, copied from the Buffer zone (time, inventory, sleep, saves, map scale; radius 2.5 km);
- adds the map centre and one level-gate row per return pad to the map-point config, and registers the loot tags (above);
- once the game is idle, registers the showcase missions (see "Showcase missions and uninstalling").

Entering and leaving are triggers on top of that (`loader/ItrShowcaseLoader/Scripts/config.lua`): the tin of graphite grease, `F9`, the
console command, the exit markers. Details: [`loader/README.md`](loader/README.md) and the loader README in `itr-common`.

## Opening the project
You can open `project/IntoTheRadius.uproject` to inspect the level, the Blueprints and the placements. What that needs:
- **Engine.** Unreal 4.27. We only opened it with the **patched Oculus 4.27 editor** from `itr-common` (route B in its
  [guide](../itr-common/map-making/guide.md)), which the landscape material needs. A stock editor is untested.
- **It is a code project.** `project/Source/IntoTheRadius` is a recreation of the game's C++ module, generated from
  the game's reflection data by a script in the maintainer's workspace (not in this repo) and verified against the game (classes,
  properties, functions, flags, native defaults; function bodies are empty). Copy the community SDK's `VRExpansionPlugin`
  and `ModFramework` plugins into `project/Plugins/`. Compile it the first time you open the project (Visual Studio with
  the C++ game workload).
  The game's real module is in the game; none of this goes into the pak. The editor plugin,
  `Plugins/ItrShowcaseEditor` (builds the map's Blueprints from JSON specs), is included and optional.
- **Game config.** `Config/DefaultEngine.ini` is the game's file and is not in the repo. Extract it once:
  `project\extract-game-config.ps1 -Engine "<your editor>\Engine"`.
- **Gameplay tags.** The placed Blueprints store tags (`Loot.*`, `NPC.Monster.*`, `NPC.Generator.*`). The editor clears a
  tag value it doesn't know, so the game's tag lists need to be in `Config/DefaultGameplayTags.ini` and `Config/Tags/`
  (they come from the SDK's `Config`). The map's tags are in `Config/Tags/ItrShowcaseGameplayTags.ini`.
- **The game's assets.** The level references the game's meshes, materials, textures and Blueprints by path. Without the
  community **ITR-SDK** (ChuckSharts, see the itr-common guide §1) copied into `project/Content` at the same `/Game` paths,
  those references are missing and the level opens with empty slots. Take the gameplay Blueprints from ChuckSharts's SDK,
  not R3mains's. The SDK's master materials are reconstructions: reference them, don't cook copies of them.
  A handful of the meshes (the tower-crane kit and some others) are in no SDK at all.
- **Cook and pack** (only if you want to make a pak from a modified level):
  `project\build-map.ps1 -Engine "<your editor>\Engine"` cooks `/Game/Mods/ItrShowcase/L_ItrShowcase` and packs only
  `/Game/Mods/ItrShowcase` into `zzz_ITRMap_ItrShowcase_P.pak`, so none of the copied game assets end up in it. Landscape
  grass data is baked in the editor and has to be baked before cooking, or the grass is missing from the pak.


## Licence
The licence of this repo is I don't fully know. Expect the same as `itr-common`: AGPL-3.0 for the scripts, with the Unreal
Engine EULA applying to any cooked pak. The map is made of the game's assets, referenced by path; they are not
redistributed. The release archives include UE4SS, which is MIT-licensed; its licence text is in the archives
(`UE4SS-LICENSE.txt`).