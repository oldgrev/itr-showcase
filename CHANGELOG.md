# Changelog

Status of every release: early test with issues (see "Status" in the README).

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
- The comments in the Lua files describe what the code does.

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
