# Changelog

Status of every release: early test with issues (see "Status" in the README).

## Unreleased

Not in an archive yet. Changes since the 2026-10-29 build.

### Loot
- **Items from using Common Mod Dependencies are automatically used by stashes and as individual loot spawns.** 47 of the map's loot tags (all tiers' ammo, equipment,
  food, valuables, stash and dead-man tables) are now composite tables: the map's tier rows plus the dependencies' 11 `ModdedData`
  user slot tables of the matching stock table. The loader picks the Vanilla, Scavenger or Stalker slot set from the game config and logs it
  (`loot: framework loot set ...`, then `loot: N framework rows in M of 47 tables`), and scales each tag's budget once by the live stock
  budget (clamped 0.25 to 4). `LootFrameworkSet`, `LootFrameworkMarkers` and `LootFollowBudgets` are in `config.lua`.
  The map pak has no files at the `ModdedData` paths. The Unreal project only has empty stand-ins of them, and those aren't in the repo.
- **Five or so large stashes for checking loot** on the road just south of the arrival checkpoint, one per loot tier T1 to T5, going south.

### Saving
- **Saves made in the map now load back into it,** and items you left on the ground are still there. It needs a new small pak,
  `zzz_ITRMap_ItrShowcase_Tags_P.pak`, next to the map pak in `~mods`. It's in both archives. Install and remove the two together.
- The loader logs at startup whether the tag is registered, switches to the map's loot tables when a save loads into the map, and
  moves you to the arrival marker if the save puts you outside the map.

### Exits
- **One return pad,** R0 at the Kordon entrance. R1 to R6 and their cyan "to entrance" pads are gone. The flattened ground they
  stood on is still there as bare dirt circles. `NativeGates` has one row, and the tablet map shows one Hub marker.

### Map
- **Stock tide.** A stock tide actor and the game's tide sequence, linked to the map's environment. The level reloads after a tide
  like a stock zone.
- **A shelter with a bed** next to the arrival pad, for testing sleeping and shelter logic.
- **Performance merge.** Repeated plain dressing pieces (same mesh, materials, collision, shadow setting and draw distance, inside one
  tile) are merged into instanced meshes, and every piece gets a draw distance that follows its size. The bunker pieces stay
  separate actors.
- **Day cycle flicker fixed.** The sun turned a tiny amount every frame, which shifted the shadow grid and made shadows crawl. It now
  moves in a small step once per game minute (every 2.5 real seconds).
- **The edge of the map uses trigger boxes.** `BP_ItrShowcase_PerimeterTide` no longer tests the player every 0.1 s. Four trigger strips
  along the square call the same transition when you walk into them.
- **The stock tide circle is wider,** 2300 m from the centre (it was 1800 m), so the bunker is inside it.

### Bunkers
- **Four ways into one bunker,** but it only looks like one... down the cellar stairs of ruined buildings in Kordon, on the track by Tikhoe lake, at the rail halt by the dachas, and at the end of Zarechye's upper street. Walk back to the landing to get back out.
- **Inside** there's a bed, a shop, a health booth, storage, a mission computer and a vise.
- **Tunnel door to the Hub.** Its handle can be grabbed to return to the Hub. When you want to return, you'll return back to wherever you left from.

## 2026-10-29 build

Changes since the 2026-10-24 build (this includes the 2026-10-27 archive).

### Map
- **Lighting redone.** The map has a day cycle, and the sun is much less harsh, especially from 17:00 to 20:00.
- **Pine needle colour** changed.
- **View distance 6 and foliage LOD 6** while you are in the map (they were 5). Tree cull distances are doubled, and sun shadows
  reach about 700 m.
- **Building interiors fixed.** Every building copies the furniture and fittings of the stock building it is modelled on, at the
  stock positions. Before, 157 of the 270 buildings were empty, and sinks and other fittings sat at the wrong height.
- **Buildings sit at the stock depth in the ground**, with the terrain fitted to them, so more buildings have door steps.
- **Dolina farm's big buildings** now copy the stock Pobeda buildings.
- **Lamps in interiors** are their meshes (their light is kept).
- **Trees were regenerated**, and many moved slightly.
- **Most stashes have new spots**, because stash placement follows the spots inside buildings. None were added or removed.
- **The tablet map picture** is updated to the current layout.

## 2026-10-24 build

Changes since the first archives (2026-10-18).

### Loader
- **Missions progress.** The showcase missions use mission ids the game registers at start. A finished mission is no longer offered
  again, and the next mission of the series appears at the mission computer.
- **The showcase missions are once-only.**
- **The freeze at the main menu is gone.** Keeping the mission assets alive scanned the whole game-instance array (4.3 s on the main
  menu); it now reads only what it appended (9 ms). The loader's game-mode and game-data lookups no longer scan objects either
  (11 to 14 ms of game thread each).
- **No per-frame Lua work.** The view-distance settings, the compass target and the progression unlock's player level and trigger
  flags moved from Lua into Blueprint actors in the map pak (`BP_ItrShowcase_MapSettings`, `_CompassSky`, `_Progression`).
- **A different Hub item enters the map.** It is now the tin of graphite grease in the workshop (static mesh `Liquid08_1`), not the
  pumice stone.
- Return pad R6 is on the tablet map.
- The loot manifest has 68 tags (T1 to T5, signature stashes, an example set) and budgets that follow the pockets' tiers.

### Map
- **Enemy pressure.** P2 is now tier T2 and P4 tier T3 (enemy rosters and loot follow the tier), and there are more armed Mimics.
- **Rifts are lifted** clear of the ground (they sat underground).
- **New return pad R6** at the lake (P4), with its to-entrance pad. The map now has seven return pads, R0 to R6.
- **Stashes are hidden** instead of standing in the open.
- **Darker grass and bushes.**
- **The map sign at the entrance is two-sided.**

### Also new since 2026-10-18
- The layout is twelve pockets (P1 to P12) in five tiers (T1 to T5), difficulty rising from the south checkpoint to the north.
- Showcase missions, with a progression unlock in the save (see "Showcase missions and uninstalling" in the README).
- A compass, a tablet map and a printed map board at the entrance.
- Ladders and other climbables work; the escarpment is a barrier; the canyon walls and the ground are darker.

## 2026-10-18 build

First archives: the map pak, the ItrShowcaseLoader UE4SS mod and a trimmed UE4SS in the Nexus layout, as a normal archive and a FOMOD
archive.
