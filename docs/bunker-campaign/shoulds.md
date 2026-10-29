# Bunker and clearance "shoulds"

The "should" lines from [stories.md](stories.md), collected into tables. Next step: go through them together and fill
in **Want?**. Updated 2026-10-29 for the user's answers (README "Answered" block): the unit is a pocket; no re-contest; bunker sites are hand-picked; new group K (service gating). The IDs are stable, so they can be used in discussion.

Columns:
- **Game today**: what stock 2.7.2 and the showcase do now. ✓ = present, ~ = partial, ✗ = absent, ? = unknown or
  untested. Evidence: **GS §n** = [corpus/game-systems.md](corpus/game-systems.md) section n, **IM §n** =
  [corpus/implementation.md](corpus/implementation.md) section n.
- **Approach**: the cheapest layer that would work, from IM §3, with its cost class:
  - **zero**: nothing runs at play time (geometry, volumes, nav cuts, placed stock actors);
  - **load-only**: runs once per level load or session;
  - **per-event**: runs only when something happens (overlap, death, mission end), with nothing between events;
  - **per-tick**: a timer or poll.

  Layers: *cooked* (level content), *BP* (cooked Blueprint via BPGen), *data* (one-shot Lua write or cooked data),
  *Lua* (UE4SS hook or poll), *native* (aiMod, private, not usable for a public map). The performance model is
  `public/itr-common/bullet-penetration/README.md`: a one-shot Lua write plus a cooked BP cost +0.05 ms, while the same
  logic in Lua on every hit cost +0.84 ms. "The showcase already does it in Lua" is not a reason to use Lua.
- **Practicality**: **E** easy (placement or data), **M** medium (new logic on known layers), **H** hard (an unproven
  layer, a big kit or an open unknown on the critical path), **VH** very hard, or not realistic from a public mod.

Where the two corpora disagree or overlap, the row says so and the disagreement is listed in
[Corpus disagreements](#corpus-disagreements) at the end, with what would settle it.

## A. Bunker space

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| A1 | A bunker is a solid 1-2 storey building over a basement, readable from outside as a bunker site | ~ stock basements exist in Bolotky (Construct): the construction-site building and a broken-down house (user, 2026-10-29; GS §8 correction). Template candidates: `Prefab_Zone_Construct_Building_01_a` (48 x 30 m, reaches z -3.7 m, has water meshes) and `Prefab_Zone_Construct_Village_House_Destroyed_01_b/_c/_d` (reach z -3.3 / -3.3 / -2.8 m). Which destroyed variant is the user's: to confirm | cooked: the build carves the terrain and installs the stock prefab as the bunker template at a hand-picked site (zero). Open point: how the stock level keeps the landscape out of those basements (a landscape hole, or a raised site); the showcase landscape-hole proof failed and cut-and-cover worked (GS §8) | M | |
| A2 | The basement is big enough for shop + repair + bed + room to move | ? the basement floor areas of the templates are not measured; the prefab footprints are 48 x 30 m and 10-20 m per side (asset-kits.md); `BP_FreeShop` footprint known from the range level (GS §1) | cooked: measure the template basements in the editor; pick the template whose basement fits (zero) | M | |
| A3 | The basement sounds and looks underground | ~ assets exist as sound and texture only: `A_BGBunkerAmb_Cue`, `Rvrb_Underground_B`, `t_Bunker_floor_c_*`, `T_ShelterLamps2k_E` (GS §8) | cooked: ambient sound + reverb volume + materials (zero) | E | |
| A4 | Ground and upper floors are firing positions: enemies can't enter them (no-nav, B1) but can shoot in through windows wherever they have line of sight from outside the buffer | ~ the templates have upper floors and window openings (asset-kits.md); stock AI fire only with direct line of sight (user, 2026-10-29) | cooked (zero) | E | |
| A5 | The way down is a stair, with an optional door at the bottom | ~ the template basements have their own stairs (to confirm in the editor); `BP_Door` is a VR physics door (GS §5) | cooked; a door is optional, since the no-nav area (B1) does the fencing (zero) | E | |
| A6 | Bunker sites are picked by hand, as many as needed so that every pocket a run must cross has one within reach; the build carves the terrain and installs the bunker template there (user, 2026-10-29). No generator placement rule | ✗ none placed; T-148 "return points inside protected buildings" is the open seed task (GS §2) | cooked: a hand-made list of bunker sites read by the build (carve + template install; the template itself is still to be designed) (zero) | M | |

## B. Safe zone

The safe zone, as the user defines it (2026-10-29): the bunker building plus a buffer area around it has no navmesh.
With no nav, AI can't path into the buffer, into the building or down the stairs. AI fire only with direct line of
sight, and the basement has none from outside the no-nav area. So the safe zone is nav exclusion plus geometry, with no
run-time cost. The remaining risks are shoulds below (B4, B8), not blockers.

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| B1 | The bunker building plus a buffer area around it has no navmesh, so no enemy can path into the buffer, the building or down the stairs | ~ no safe-zone class in the SDK; the Hub is safe because it has no spawner (GS §5) and, per IM §3, no navmesh. The showcase already cuts the lake out of the navmesh with `NavModifierVolume` / `NavArea_Null` (`v4/lakenav.py`), checked on the saved navmesh by `check_nav_strips` | cooked: `NavModifierVolume` (`NavArea_Null`) over building + buffer, or leave the area out of the bake; navmesh re-bake (zero) | E | |
| B2 | Nothing spawns in or near the bunker | ✓ mechanism: `NPCSpawnMinDistanceFromPlayer` 20 m, `NPCSpawnerRestoreRadius` 15 m; the Hub has no spawner (GS §3, §5). With no navmesh in the buffer, there is no spawn point there either | cooked: a build check at each hand-picked site, no spawner whose `Radius` or restore radius reaches the buffer (zero) | E | |
| B3 | Enemies can't shoot into the basement: no walkable point outside the buffer has line of sight to it | ✓ AI fire only with direct line of sight (user, 2026-10-29); the sight trace channel itself is not named in the corpora (IM §3) | cooked geometry: closed basement walls; the only opening is the stairwell (zero) | E | |
| B4 | Enemies whose path ends at the buffer edge hold cover or lose interest there (partial paths stop at the edge), with no jitter or clipping | ~ the stock 60 s lost timer and idle return exist (GS §5); behaviour at a nav-cut edge is untested; IM §3 also flags NPCs already mid-path or ragdolls at the cut edge | stock behaviour; check only (zero) | M (until seen in VR) | |
| B8 | The buffer is big enough that no walkable point sees down the stairwell into the basement | ? depends on the template's stair and door layout and the buffer radius | cooked: size the buffer per template from sight lines into the stairwell; checkable in the editor (zero) | M | |
| B5 | Shooting in the basement doesn't pull the whole pocket to the door | ✗ vanilla hearing goes through walls (enemy-design-shoulds B2); aiMod's wall occlusion exists but is private (IM §1.5) | accept stock, or native (per-event) | E to accept; VH as a public fix | |
| B6 | No anomalies spawn in the basement | ✓ class exists: `BP_SpawnBlockingVolume` blocks anomaly spawns (effect inferred, GS §5) | cooked: place one over the basement (zero) | E | |
| B7 | Anything that ends up inside anyway (ragdoll, physics push) is removed | ✓ precedent: `BP_ItrShowcase_KillVolume` (IM §3) | BP: overlap box, filter NPC pawns (per-event; optional, only if B4 shows a need) | E | |

## C. Services

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| C1 | A shop like the Hub's: terminal, display, bin | ✓ stock `BP_FreeShop` (computer + showcase + repair + bin) is placed in the non-Hub `L_Shooting_Range_2` (GS §1). IM §3 calls a zone-level context untested. Whether the showcase project has stand-ins: ? (GS look-list 1) | cooked: place `BP_FreeShop` (zero) | M (stand-in question; T-152: no `/Game/ITR` closure copies) | |
| C2 | Same prices and level gates as the Hub | ✓ prices and gates are game data, not level data (`GetTypeBuyPrice`, `GetTypeLevelRequirement`) (GS §1) | none needed (zero) | E | |
| C3 | Selling works from the bin | ? untested outside the Hub (GS look-list 2) | none needed (zero) | E (if C1 works) | |
| C4 | A repair bay, repair only | ✓ `BP_TrainStorage` in `EnableRepiarModeOnly()` mode; `BP_FreeShop.Init` already calls it on its child `Repair` (GS §1). IM §3 says the repair host is "not identified", which GS settles | cooked: comes with `BP_FreeShop` (zero) | E (if C1 works) | |
| C5 | Missions can be taken at a bunker (bunkers get missions; user, 2026-10-29) | ~ `BP_MissionComputer` is Hub-only in stock; full `BP_TrainStorage` mission and delivery pages outside the Hub: untested (GS §1) | cooked: place `BP_MissionComputer`; plus the Lua mission registration for that computer (load-only) | H | yes (user 2026-10-29) |
| C6 | A bed: sleep until rested or until morning, heal | ✓ `BP_Bed` is placed in many stock zone sublevels (GS §1). Level row `SleepAllowed`: **the corpora disagree** (D1 below); the loader code shows the row copies the donor's flag | cooked: place `BP_Bed` (zero) | E | |
| C7 | Sleeping marks the bunker as camp on the tablet | ✓ `SaveSleepLocation` / `GetSleepLocation`, camp marker (GS §1, §7) | none needed (zero) | E | |
| C8 | Sleeping or arriving at a bunker saves the game | ? whether a sleep saves is unread; the showcase row has zone autosave (60 s) since `NativeSaves = true` (GS §1, §7) | stock flags (zero); if sleep doesn't save, a BP on the bed's sleep event could (per-event) | E | |
| C9 | A healing booth like the Hub's | ~ `BP_HealthBooth` is Hub-only in stock (also `L_VRTest`); its dependencies are not Hub-specific (inferred, GS §1) | cooked: place it (zero) | M | |
| C10 | Storage (bunkers get storage; user, 2026-10-29) that keeps what you leave, across visits and tides | ? no personal stash actor found; `LevelDecorItems` is keyed by level (inferred carrier); the tide's `KillActorsOnReload` removes stashes (GS §1, §3, §7) | cooked: a plain container (`BP_Safe`) or loose items; persistence untested (zero) | H | yes (user 2026-10-29) |

## D. Recall

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| D1 | The recall point is a basement door that looks like a tunnel exit | ✗ today's pads R0-R6 are a cylinder + beam (GS §2); parts exist: `SM_Props_Hatch_01_*`, `SM_Building_Fort_Arch_Ceiling_01_*`, `ConcreteConstruction_Tube_Large` (GS §8) | cooked (zero) | E | |
| D2 | Stand-on: a short dwell on the mat sends you to the Hub; walking past does not | ~ a Lua poll at 2 Hz tests the distance to every `itr:exit_id` point and transfers immediately (GS §2; IM §2 rates it "convenient, not cheapest") | BP: overlap box + dwell timer calling `TransferToLevel(Level.Hub)` (a copy of `BP_ItrShowcase_TeleportPad`), or a placed stock `BP_ZoneGate` (per-event) | M (a generated BP calling the interface is untested; `BP_ZoneGate.DoTransfer` does it in stock) | |
| D3 | Coming back from the Hub arrives in the basement you left from | ✓ the loader remembers the exit id and arrives at `itr:arrive:<id>` (`ReEntry`) (GS §2) | keep the existing loader logic (load-only) | E | |
| D4 | The door shows when it is armed and does nothing during a transition | ~ `GetIsInTransition` is callable from a BP (`PerimeterTide` uses it) (IM §4) | BP: part of D2 (per-event) | E | |
| D5 | Each recall door is a gate marker on the tablet | ✓ `NativeGates` → `LevelGates` rows draw gate icons (GS §2, §7) | data: existing loader rows (load-only) | E | |

## E. Clearance counting

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| E1 | A kill counts for the pocket its spawner belongs to | ✗ no per-zone count; `PlayerStats.Kills` is global by NPC type (GS §6). Pockets exist only in the generator (GS §4) | a spawner → pocket table (or the 12 pocket rectangles) baked by the generator into the counting BP (the `runtime.json` pattern) (load-only); the E3 child looks its pocket up on death | M | |
| E2 | The target is the generator's planned population per pocket, not a live count | ✗ (IM §3: live counts drift because spawners fill on approach and rifts respawn) | baked from `population_out.json` into the director (load-only) | E | |
| E3 | Each counted death is counted once, and only for the pocket's own enemies (still open: player kills only, or any death) | ~ no per-pocket count today. Stock death events exist: `UEventsManager.OnNPCDied` (BlueprintAssignable), `OnPlayerKilledNPC(Actor, weaponTag)`, `AMonsterSpawner.OnNPCDied` (GS §6, IM §4) | **BP, bullet-penetration pattern** (user, 2026-10-29): a child BP of each enemy class binds its own death event on itself, the way `BP_PenBulletProjectile` binds `OnComponentHit` on its own sphere (BPGen `component_event` or an inherited-event override, so no bind on another object is needed). The generator writes the child types into each spawner's `Monsters` at build time: no Lua swap, no per-event Lua; saved NPCs keep their type (per-event). Alternative: a director bound to `UEventsManager.OnNPCDied` (needs a BPGen bind op, see D4) | M | |
| E4 | Rifts count toward clearance (as a share or as a must-kill), and their respawns can't inflate or drain progress | ✓ rifts are real objects with HP, cooldown and a shard drop; HP and cooldown persist (GS §3) | BP: count generator destruction (per-event; the same child-class pattern on `BP_MonsterSpawnGenerator`, or the director); cap progress at the planned total | M | |
| E5 | Cheaper unit: count emptied spawners rather than single kills | ✓ `OnWildSpawnerCleared` (BlueprintAssignable on `AMonsterSpawner` and `UEventsManager`), Wild spawners only (GS §3, §6) | alternative to E3; needs a bind on the spawner, so it has the D4 question (per-event) | M | |
| E6 | No-bind alternative: derive the cleared fraction from the save's survivor map at load | ~ `USpawnerGameData.npcSpawners` holds live NPCs per spawner; `RemoveNpcData` suggests kills drop out (inferred, GS §3) | BP or Lua read at level load and save (load-only) | M (semantics inferred; the tide clears it) | |
| E7 | Finishing a mission in a pocket takes a fixed share off (e.g. 10 %), for a stubborn leftover group | ~ `OnMissionFinished` / `OnMissionStateChanged` exist; the showcase's mission keeper polls in Lua at 1 Hz (IM §2) | same director, bound to `OnMissionFinished` (per-event); or the existing keeper (per-tick) | M | |
| E8 | Clearance is a percentage of the pocket's population; kills and missions combine toward one 90 % clear threshold (user, 2026-10-29) | ✗ | director data (load-only) | E | |
| E9 | Counting costs nothing between events: no timer, no poll | n/a | rule for E1-E7 | E | |
| E10 | A child enemy class behaves exactly like its parent | n/a | BP child per enemy class. **Cost:** one child BP per enemy class used by the generator (all mimic weapon variants, Spider, Fragment, Phantom, Seeker, Hunter, Commando, SWAT, Marksman, Slider and the armoured variants), each authored, cooked and listed. **Must not break:** the parent's events (any overridden event calls the parent); the AI controller, behaviour tree and perception the parent sets; loot (`SpawnLoot`) and corpse saving (`SavedCorpseTypes`); the save restore (`SpawnSavedNPC` by `TypeID`); mission kill objectives; `StatAddKill` stats; aiMod hooks keyed on parent UFunctions (`CPP_Char_Mimic_C::Alert`), which inherited functions keep. The parents must exist as stand-ins in the showcase project, and rebuilding a BP with SCS components asserts the editor (BPGen gotcha) | M per class, H in total | |
| E11 | A child also reports its own spawn, so live population is known without a poll (for a live denominator; the re-contest use, J7, is out) | ✗ | BP: the child's `BeginPlay` (per-event) | E (with E10) | |
| E12 | Each child is reached through an NPC type tag that the game resolves to the child class | ~ `Monsters` is `TMap<FGameplayTag, int32>` (SDK `IntoTheRadius_classes.hpp:1266`), so a spawner names NPC types by tag, and the class comes from the infos config (`GetNPCClass(npcTypeID)`, `GetNPCInfos()`, `:4122-4124`). A child class needs its own type tag with an `FPRNPCInfo` entry | data: register the child tags and infos once per session (one-shot Lua write, like `RegisterLootTags`) or a cooked override of the infos asset (load-only). Unregistered tags work for exact matches only (IM §1.3) | M | |

## F. Downgrade

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| F1 | A cleared pocket is literally T1: from its next fill (load or tide) it fills with T1 rosters, behaves like vanilla T1 and respawns normally (user, 2026-10-29) | ✗ no tier field in stock; showcase tiers are baked per spawner (`Monsters` TMap, `AlternativeMonstersMax`) (GS §4). `Monsters` is `Edit, BlueprintVisible` (IM §4) | BP director at `BeginPlay` (or an `OnLevelStarted` override) writes the T1 lists (the T1 child tags, E12) into the pocket's spawners (load-only). Alternative: two cooked `_Monsters` sublevels per pocket, streamed by state (load-only, bigger cook) | H (BeginPlay vs `OnLevelPrepare` order inferred) | |
| F2 | Crossing the threshold is a clear moment: a sound, the board flips | ✗ | BP director (per-event) | M | |
| F3 | Survivors keep their type until killed or reset; nothing swaps mid-fight | ✓ (inferred): saved NPCs come back with their saved `TypeID` (GS §4, IM §3) | none needed (zero) | E | |
| F4 | A cleared pocket's rifts are fewer or slower, only if plain T1 values are not enough (it is literally T1) | ~ `CooldownSeconds`, `HitPoints` per rift; saved `GeneratorsCooldown` may override a load-time write (inferred, IM §3) | BP director writes `CooldownSeconds`, or removes generators (load-only) | M | |
| F5 | Loot in a cleared pocket follows the new tier (reading of "T1" for loot: to confirm) | ✗ `LootArray` entries are global by tag; tier tags are baked per stash (GS §4) | the sublevel variant of F1 (load-only); no run-time tag swap is known | H | |
| F6 | Missions in a cleared pocket follow the new tier | ~ missions follow the pocket tier at build time (`missions_gen.py`) (GS §4) | data: register the T1 mission variants for the pocket (load-only) | H | |
| F7 | Clearing a pocket that is already T1 (P1) changes no roster: it is T1 already and behaves like vanilla T1; it only gets the cleared state (board, tint) | ✗ | director data: the cleared flag only (load-only) | E | |
| F8 | A cleared pocket can also have fewer active spawners | ~ "cheaper lever" in GS §4: zero a spawner's `Monsters` | director (load-only) | E | |

## G. Neighbour bonus

How much a permanently cleared neighbour softens the adjacent pocket (rift timing, armour). The amounts stay an open question (README decision 9).

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| G1 | Neighbours come from the generator layout (pocket adjacency) | ✗ (pockets are generator data, GS §4) | baked into the director (load-only) | E | |
| G2 | Each cleared neighbour lengthens the pocket's rift cooldowns, up to a cap | ✓ the lever is real: per-rift `CooldownSeconds` (showcase T1 150 s to T5 240 s) (GS §3) | director writes `CooldownSeconds` at load (load-only) | M (saved cooldown may override, see F4) | |
| G3 | Each cleared neighbour swaps armoured variants for plain ones | ✓ armoured variants are separate NPC tags (Castle, Factory, Kolhoz only) (GS §4) | director rewrites `Monsters` entries (load-only) | M | |
| G4 | The bonus is local to the next pocket; global difficulty is untouched | ✓ global multipliers exist but are per save (`GameDifficultyConfig`) (GS §4) | none needed | E | |
| G5 | The bonus applies from the pocket's next fill, not mid-visit | ✓ by design of F1/G2 (load-only) | none needed | E | |

## H. Persistence and tide

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| H1 | Clearance is saved with the game save, per slot (a new game starts clean) | ~ candidates: `PRGameData.CustomMarkers` (`TArray<FString>`, `CheckMarker` / `UpdateMarker` BlueprintCallable; serialisation inferred); `PassedTriggers` needs registered tags and the pool is too small (GS §7, IM §3) | BP writes a marker string on change (per-event), reads at load (load-only). **Recommended (user, 2026-10-29): the game save (`CustomMarkers`), gated on proof step 10** (one `UpdateMarker`, save, quit, reload, `CheckMarker`). Fallback: a SaveGame slot (precedent `EggSave`) keyed by `GameUID`, so a new game starts clean (per install otherwise) | M | |
| H2 | Clearance and bonuses survive tides | ~ (inferred) markers and triggers sit outside `SpawnSaveData`; the native `ApplyTideReset` body is unread (GS §3, IM §4) | follows from H1 | E (once H1 and the tide probe pass) | |
| H3 | A tide refills a cleared pocket at its current tier (T1), not empty | ? tide refill in the showcase is untested (V4-087); `NativeReloadOnTide = false` (GS §3) | follows from F1 at the next load (load-only) | M | |
| H4 | Being in the basement when the tide hits leaves you there | ✓ stock: `OnTideFinished` saves the current transform when the player overlaps `BP_ShelterVolume`; every zone has some (GS §3) | cooked: place `BP_ShelterVolume` over the basement (zero) | E | |
| H5 | The bunker's services survive the tide | ✓ (inferred) `KillActorsOnReload` removes spawned NPCs, generators, spawners, anomalies, stashes and corpses; placed shop and bed are not in that list (GS §3) | none needed (zero) | E | |
| H6 | Items left in bunker storage survive the tide | ? (see C10) | same as C10 | H | yes (user 2026-10-29) |
| H7 | The showcase's reload-on-tide setting suits this design | ~ `NativeReloadOnTide = false` with a stale comment ("no tide actor yet"; a perimeter tide exists) (GS §3) | data: loader config (load-only) | E | |
| H8 | With the mod removed, a save that holds clearance state still loads | ~ marker strings are inert without the mod; the loader guard rewrites the unknown level tag (GS §7). New risk from E12: saved NPCs hold child type tags (`npcSpawners` `TypeID`), which mean nothing without the mod; how the game treats an unknown saved `TypeID` is unread | follows from H1; for the child tags, check what `SpawnSavedNPC` does with an unknown `TypeID` | M | |

## I. UI

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| I1 | A clearance board in each bunker basement: per pocket tier, % (kills / missions), cleared state | ✗ no stock surface for it (GS §7) | BP: world-space mesh with a `MaterialInstanceDynamic` scalar per pocket, or `TextRenderComponent`s, written only on change (per-event) | M | |
| I2 | The tablet map shows cleared pockets | ~ the showcase map picture on the tablet works (T-145); swapping the material per state is untested, and a BP can't write `FLevelConfig` (GS §7, IM §3) | data: Lua level-row material swap on change (per-event, rare) | M | |
| I3 | Bunkers appear on the tablet map | ✓ as gate icons via `LevelGates` rows (gate icon only) (GS §7) | data (load-only) | E | |
| I4 | The board shows active neighbour bonuses (the re-contest warning is removed, user 2026-10-29) | ✗ | part of I1 (per-event) | M | |
| I5 | Optional: a field readout of the current pocket's progress | ✗ needs a widget; BPGen has no widget path (IM §3) | widget BP (route unknown), or an item like `BP_TideClock` | H | |

## J. Campaign

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| J1 | Campaign mode keeps only the starting recall point R0 (a later step: the campaign is the default but optional, respawn stays default for now) | ~ pads R0-R6 exist as loader config rows and generator placements (GS §2); R1-R6 proof state: ? (V4-078) | data/cooked: drop the rows and pads for the campaign variant (load-only) | E | |
| J2 | Everything a run needs is in reach of a bunker | ~ depends on C1-C10; missions (C5) and storage (C10) are the gaps | follows from C | H | |
| J3 | removed (user 2026-10-29): bunkers are open from the start; gating is by service, group K | n/a | n/a | n/a | superseded by K |
| J4 | Pocket order gives a route: tier rises away from R0, and clearing softens the next | ✓ tiers already rise P1 → P12 (GS §4) | follows from G | E | |
| J5 | Respawn after death stays default for now; respawning at the last slept bunker is deferred (user, 2026-10-29) | ✓ default flow; `LastDeathLocation`, `LastSleepLocation` exist (GS §7) | none for now | E | |
| J6 | Dropped gear and the death marker work as in stock | ✓ `DeathDropItems`, `LastDeathLocation`, tablet death marker (GS §7) | none needed (zero) | E | |
| J7 | removed (user 2026-10-29): a cleared pocket is never re-contested | n/a | n/a | n/a | no (user 2026-10-29) |
| J8 | The Hub stays reachable from R0 | ✓ (GS §2) | none needed | E | |
| J9 | Every piece is reusable by another map: bunker kit, director, counter, board | n/a (the showcase's purpose) | director data baked per map (the `runtime.json` pattern); pak-only where possible | M | |
| J10 | The campaign is the default route but nothing forces it: players can ignore the bunker chain and play free | n/a | no gating of the map by campaign state; only bunker services are gated (K) | E | |

## K. Service gating

Added 2026-10-29. Bunkers are open from the start (entry, basement, safe zone, shelter, recall door). Each service stays
off until the bunker is **fixed** (money), **powered** (a specific artifact brought) or its **pocket is cleared**, or a
combination. Layer costs follow [corpus/implementation.md](corpus/implementation.md) section 3.

| ID | Should | Game today | Approach (cost) | Practicality | Want? |
|---|---|---|---|---|---|
| K1 | Every bunker is open from the start; only its services are gated. The safe zone (B), shelter (H4) and recall door (D2) never depend on the unlock state | ✗ nothing gated today | cooked: those parts carry no gating logic (zero) | E | |
| K2 | Per-bunker state: three flags, fixed, powered, cleared (cleared is read from the pocket's clearance, not stored twice), plus a per-bunker rule saying which combination opens each service (any of, or all of) | ✗ | data: the rule is baked per bunker from the hand-picked site list at build (the `runtime.json` pattern, IM §1.6); the flags are marker strings (load-only read, per-event write) | M | |
| K3 | Per-service state: mission computer, shop, repair, storage and bed each have their own requirement and locked/unlocked state. Decision to take: which are gated. Recommended: mission computer, shop, repair and storage gated; the bed open, so a bunker is a refuge and a checkpoint from the first visit (to confirm) | ✗ | data: one row per service in the same baked rule table (load-only) | E | |
| K4 | A locked service looks locked and says what opens it: dark screen, red lamp, a placard with the requirements and their state (for example "Needs: repair, power cell, or P2 cleared"); using it does nothing | ✗ no stock locked state is documented for `BP_ShopComputer`, `BP_TrainStorage`, `BP_MissionComputer`, `BP_Bed` | cooked BP: a gate actor in front of each service, a collision shutter that blocks the interaction, a `TextRenderComponent` placard and a lamp; unlocking hides the shutter. No stock BP is edited (per-event; zero between events). Fallback: spawn the service actor on unlock (needs stand-ins, proof step 1) | M | |
| K5 | Unlock by fixing: a repair panel in the bunker; pay money once and the fixed flag is set | ? the shop spends money, but the BP-callable spend and balance functions are not named in the corpora | BP: overlap or grip interaction on a placed prop that calls the money spend and writes the marker (per-event). Needs the spend call identified first | H (until the money call is found) | |
| K6 | Unlock by power: a socket takes one specific artifact per bunker; the item is consumed and the powered flag is set | ? reading an item's type from a BP is unread; the loader's Lua `BP_PhysicsActor_C:OnGrip` hook is the only item precedent (IM §2) | BP: an overlap box on the socket, cast the item, compare its type tag with the bunker's baked tag, destroy it, write the marker (per-event). Fallback: a Lua hook (per-event, needs UE4SS) | M to H | |
| K7 | Unlock by clearing: when the pocket crosses 90 % (F2), the bunker's cleared state turns on and its services open by their rule, with no visit needed | ✗ | the F2 director event writes the marker and calls the gates (per-event, no poll) | M | |
| K8 | The state is applied at load and live: on level start each gate reads its markers and opens or stays shut; a flag changing while the player is there opens it at once with a cue | ✗ | BP: inherited `OnLevelStarted` override on the gate (no bind needed, IM §4) plus a call from the unlock event (load-only, per-event) | M | |
| K9 | Persistence: the per-bunker flags live in the same store as clearance (H1): `CustomMarkers` (marker strings such as `bnk:B3:fixed`), gated on proof step 10, fallback a SaveGame slot keyed by `GameUID`. They survive tides and an unlock never relocks | ~ as H1 and H2 (inferred, unproven) | follows from H1: write on change (per-event), read at load (load-only) | M (gated on proof step 10) | |
| K10 | The bunker's clearance board (I1) also shows each bunker's service state and what is missing; the tablet gate marker (I3) stays a plain icon | ✗ | part of I1 (per-event); the tablet icon is a fixed `LevelGates` row, so it cannot show state | M | |

## Counts

| Group | Shoulds |
|---|---|
| A. Bunker space | 6 |
| B. Safe zone | 8 |
| C. Services | 10 |
| D. Recall | 5 |
| E. Clearance counting | 12 |
| F. Downgrade | 8 |
| G. Neighbour bonus | 5 |
| H. Persistence and tide | 8 |
| I. UI | 5 |
| J. Campaign | 10 (J3 and J7 removed; J10 added) |
| K. Service gating | 10 (new) |
| **Total** | **87 rows, 85 live** (was 76 in 10 groups) |

---

## Corpus disagreements

Where [game-systems.md](corpus/game-systems.md) (GS) and [implementation.md](corpus/implementation.md) (IM) disagree or
overlap. Each entry gives both sides, what a targeted read (made for this file) showed, and what would settle the rest.

**D1. Sleep in the showcase level row (C6).**
- IM §3: "`SleepAllowed` was set false by the showcase row (`NativeSaves=false`, NLT 1.2a): needs flipping."
- GS §1: the row copies the donor `Level.Zone.Buffer` flags, so `SleepAllowed` follows the donor; it is forced false
  only when `NativeSaves=false`, and the config now has `NativeSaves = true`.
- Read: `config.lua:29` has `NativeSaves = true`; `main.lua:1653` is `Row.SleepAllowed = Saves and (D.SleepAllowed ==
  true) or false`, with `D` copied from the donor row (`main.lua:1607`) or defaulting to true (`main.lua:1615`).
  `native-loading-tides.md:231` still describes the old `NativeSaves = false` state, which is where IM's statement comes
  from.
- Verdict: GS is right about the code; IM is stale. **Still open:** the donor Buffer row's own `SleepAllowed` value
  (not read). Settled by sleeping on a placed `BP_Bed` in the showcase, or by one log line of the row after
  registration.

**D2. Who hosts the repair pages (C4).**
- IM §3: "the actor hosting the repair pages (`WBP_Page_RepairList`) is not identified in the dump."
- GS §1: `BP_TrainStorage` (parent `PRBasicActor`) has the Repair page; `BP_FreeShop.Init` calls
  `EnableRepiarModeOnly()` on its child `Repair` actor (read from the BP summaries).
- Verdict: GS identifies it from the bytecode summary. It is still to be seen working (VR look at the shooting range).

**D3. Shop outside the Hub (C1).**
- GS §1: "Yes, stock proof": `BP_FreeShop` is placed in `L_Shooting_Range_2`.
- IM §3: "shop and repair in a zone-level context are untested (they may read Hub-only state)."
- Both hold: the stock placement shows the BP graph needs no Hub-only subsystem, but the shooting range is not a zone
  row (its flags differ), and the showcase would use stand-ins. Settled by: the range VR check (buy, sell, repair),
  then the same check in the showcase.

**D4. Binding `OnNPCDied` from a Blueprint (E3, E5, E7).** *Superseded for deaths and spawns by the user's child-class
route (D10); kept because it is the alternative for E3 and still applies to E5 and E7.*
- IM §1.2, §5: BPGen has no op to bind a delegate on another object (`UK2Node_AddDelegate`); `create_delegate` is
  timer-style and untested; the generic `node` op might build an AddDelegate node (untested).
- GS §6 only says Lua delegate binding on native multicast events is unverified.
- Read: `SPEC.md:59` and `ItrShowcaseBPGen.cpp:521, 1088` confirm `create_delegate` is the only delegate op. The SDK
  marks `UEventsManager.OnNPCDied` (+0x2E8), `OnWildSpawnerCleared` and `AMonsterSpawner.OnWildSpawnerCleared` as
  `BlueprintAssignable`, so a hand-made BP can bind them; the gap is BPGen, not the game.
- Options: (a) add an `add_delegate` op to BPGen (one C++ op and a plugin build), (b) try the `node` escape hatch with
  `K2Node_AddDelegate`, (c) a Lua hook (D5). A BP override of an inherited event (`OnLevelStarted` on a `PRBasicActor`
  child) needs no binding and covers the director's load step (IM §4), but not deaths. Settled by one test spec built
  with (b), then (a) if it fails.

**D5. Can a Lua hook see the native death broadcast (E3)?** *Superseded by D10 for counting; kept as background.*
- IM §1.4, §4: `FireOnNPCDied` is native; a `RegisterHook` on it fires only if it is reached through `ProcessEvent`
  (unverified). Hooks on `ProcessEvent`-dispatched delegate broadcasts do fire.
- GS §6: unverified.
- Read: `enemy-ai-notes.md:98-114` (VR session 1): aiMod's `ProcessEvent` detour caught the `Alert` calls that the
  native death broadcast (`ACharBroadcast`) makes on nearby NPCs, and `OnDamage` arrives through a native delegate for
  lethal hits with the pawn already unpossessed. So native-to-Blueprint calls on death do pass through `ProcessEvent`.
  That supports "a BP handler bound to `OnNPCDied` will run" (that is how a multicast broadcast reaches BP handlers).
  It says nothing about hooking `FireOnNPCDied` itself, which may be called C++-to-C++.
- Settled by: one logged probe on a kill, only if the alternative route is ever needed. If nothing binds `OnNPCDied`,
  there is no handler for a Lua hook to catch, so a BP binding is the more certain route either way.

**D6. Why the Hub is safe (B1).**
- GS §5: "it simply contains no monster spawner"; the navmesh is in `L_Common`.
- IM §3: "no spawners and no navmesh (NLT 5)."
- It doesn't change the design (the bunker uses both levers). Settled by the navmesh view in the Hub, if ever needed.

**D7. `BP_SpawnBlockingVolume` (B1, B6).**
- IM §3 lists it as an optional NPC fence, with its NPC effect unread.
- GS §5: its stock use is the anomaly cluster system; it blocks anomaly spawns, not NPCs (effect inferred).
- Both are inferences. This file uses it only for anomalies (B6). NPC fencing relies on B1 and B2.

**D8. What `ApplyTideReset` clears (H2, H3, E6).**
- IM §4 states that it clears `SpawnSaveData`, and lists it as an inference only in §5.
- GS §3 says the native body is unread and which maps it clears is unknown.
- Settled by Ghidra on `PRGameData::ApplyTideReset` (offline), or by the forced-tide VR test.

**D9. Entry key and command (context only).**
- IM §2: F10 / `itrmap`. GS §2: F9 / `itrshowcase enter`.
- Read: the loader defaults are F10 / `itrmap` (`main.lua:2619-2626`); the showcase `config.lua:74-75` overrides them
  with F9 / `itrshowcase`. Both are right at their own layer.

**D10. User corrections of 2026-10-29 that override the corpora.**
- *Basements (A1, A2).* GS §8 said no stock building has a basement. The user says two exist in Bolotky (Construct):
  the construction-site building and a broken-down house. Prefab bounds agree (`Prefab_Zone_Construct_Building_01_a`
  reaches z -3.7 m; `Prefab_Zone_Construct_Village_House_Destroyed_01_b/_c/_d` reach z -3.3 / -3.3 / -2.8 m;
  `asset-kits.md:139-158`). GS §8 now carries a dated correction note. Still open: which destroyed variant, the
  basement floor areas, and how the stock level keeps the landscape out.
- *Safe zone (B1-B4, B8).* IM §3 treated "stop targeting into it" as the biggest unknown, with a native veto as the
  fallback. The user's model: building + buffer has no navmesh, AI fire only with direct line of sight, and the
  basement has no line of sight from outside the buffer. Nav exclusion plus geometry, zero run-time cost. Remaining
  risks are B4 (partial paths stopping at the buffer edge) and B8 (buffer size vs line of sight down the stairwell).
- *Counting (E3, E10-E12).* IM §3 and §5 made "BPGen can't bind `UEventsManager.OnNPCDied`" the biggest authoring
  risk, with a Lua hook as the fallback. The user's route: a child BP per enemy class binds its own death and spawn
  events (the `BP_PenBulletProjectile` pattern: own `OnComponentHit` on own sphere), and the generator writes the
  child types into each spawner's `Monsters` at build time. No bind on another object, no Lua per event, and saved NPCs
  keep their type. One detail from the SDK that the route has to absorb: `AMonsterSpawner.Monsters` is
  `TMap<FGameplayTag, int32>` (`IntoTheRadius_classes.hpp:1266`), so the generator writes **type tags**, and the class
  comes from the infos config (`GetNPCClass(npcTypeID)`, `:4122`). Each child therefore needs its own NPC type tag with
  an `FPRNPCInfo` entry pointing at the child class (E12): a one-shot data write per session or a cooked override of
  the infos asset. Which event the child binds for "death" (an own component delegate such as the alive-stats
  component's, or an inherited event such as `OnDeath`) is a check in the editor.
