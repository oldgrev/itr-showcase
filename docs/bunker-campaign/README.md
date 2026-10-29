# Bunker campaign: player bunkers and zone clearance

Design corpus for two linked ideas for ITR1 2.7.2 and the ITR Showcase map: bunkers the player can fight out of, and
zone clearance that makes progress last. Nothing here is built.

## What's here

| File | What it is |
|---|---|
| [stories.md](stories.md) | 15 player-perspective stories (arrival, services, recall, the tide, clearing, downgrade, neighbours, campaign, failures, unlocking a bunker; S14 removed). Each has a "Should" list |
| [shoulds.md](shoulds.md) | 87 shoulds (85 live; J3 and J7 removed) in 11 groups (A bunker space to K service gating), each with game-today evidence, the cheapest layer and its cost class, practicality, and a blank **Want?** column. Ends with the corpus disagreements (D1-D10) |
| [corpus/game-systems.md](corpus/game-systems.md) | Stock mechanics, with evidence tags (T-155A). Section 8 now carries the user's basement correction |
| [corpus/implementation.md](corpus/implementation.md) | Implementation layers, costs and hook points (T-155B) |

## The idea

**Bunkers.** Selected buildings get a basement the player can retreat to. The basement holds a shop and repair bay
like the Hub's, a bed, and a recall door that looks like it leads into a tunnel. For now the door is a stand-on trigger
to the Hub. The building and a buffer around it have no navmesh, so enemies can't come in, and the basement can't be
seen from anywhere they can stand. When you come back after a tide into a crowded pocket, you arrive underground, with
cover and services, instead of on an open pad. Stock Bolotky already has two buildings with basements (the
construction site and a broken-down house), which are the template candidates. Bunkers are open from the start; each service stays off until the bunker is
fixed, powered or its pocket is cleared (group K).

**Clearance.** Clearing about 90 % of a pocket, by hunting or by its missions, downgrades it to T1 from its next fill.
Each cleared neighbour softens the next pocket: slower rifts, fewer armoured enemies. Clearance is saved and survives
tides, so working through a region finally changes the map. Long term, every recall point except the start could go,
and the bunkers carry a campaign across the map.

**Performance rule.** Each piece uses the cheapest layer, following `public/itr-common/bullet-penetration/README.md`: a
one-shot Lua write plus a cooked BP cost +0.05 ms, while Lua running on every hit cost +0.84 ms. In this design, the
safe zone, services, shelter and bunker geometry cost nothing at run time. The rest:
- Recall, counting, the downgrade cue and the board run per event, in cooked BPs.
- The downgrade and neighbour bonuses are applied at load.
- Lua is used only for one-shot data writes the BPs can't make: level rows, NPC type registration, the tablet map
  material.
- Nothing polls. The existing 2 Hz Lua exit poll would be replaced by an overlap BP.

## Decisions for the user

**Answered 2026-10-29** (the user's answers; the original questions are kept below for context):
1. **Area:** a P area (pocket).
2. **Progress:** a percentage of the pocket's population. A mission can take a fixed share off (e.g. 10%) to deal
   with a stubborn leftover group. The clear threshold is 90%.
3. **Re-contested:** no. Once cleared, a pocket stays T1.
4. **Placement:** bunker locations are picked by hand. The build carves them out of the terrain and installs the
   bunker template (to be designed).
5. **Downgrade:** literally T1, matching P1. A T1 pocket behaves like vanilla T1 and respawns normally. Read here as
   T1 rosters and T1 loot on later fills; confirm.
6. **Campaign:** respawn stays default for now. Bunkers get missions and storage. The campaign is the default, but
   players don't have to follow it.
7. **Access:** bunkers are open from the start, but the services (mission computer, repair etc.) stay off until the
   bunker is **fixed** (money), **powered** (bring a specific artifact), or its **pocket is cleared**, or a
   combination of these. This is a new group of shoulds, not yet written.
8. **Storage:** open. Recommendation: the game save (`CustomMarkers`), so clearance follows the save slot, a new game
   starts clean, and loading an older save gives the older clearance. Proof step 10 must show it survives a save and
   reload. Fallback: a SaveGame slot keyed by `GameUID`.

1. **What counts as "an area"?** (answered: a pocket) The generator's 12 pockets are ready-made: each has a tier, a nav bounds volume and a
   planned population. Smaller units (sites inside a pocket) give more frequent wins but more state and a busier board.
   Bigger units (a whole tier band) make one large goal but slow feedback.
2. **What progress counts, and how much?** (answered: percentage of population, 90 % threshold) Options: kills only, missions only, or a mix (for example a mission is worth a
   fixed share). Rifts could be a must-kill or a share. Kills could be the player's only, or any death (NPC-on-NPC,
   anomalies). Mission-spawned enemies could count as kills too, or only through their mission. Must-kill rifts make
   clearing deliberate. Counting any death is simpler but can be farmed.
3. **Can a cleared pocket be re-contested?** (answered: no) Never: simplest, and the map steadily "dies". At a tide after N tides
   untouched: keeps pressure, but can feel like lost work. From pressure by an uncleared neighbour: more systemic, more
   to show on the board.
4. **How are bunkers placed?** (answered: by hand) One per pocket by a generator rule, or a few hand-picked sites. They could sit at pocket
   borders, as a base for the next pocket, or inside pockets. Which template(s): the construction site, the broken
   house, or both. A generator rule is reusable for anyone's map. Hand-placing reads better and costs less to build
   and cook.
5. **What does "downgraded" mean?** (answered: literally T1; loot reading to confirm) Literally T1, or one tier down. What clearing P1 does, since it is already T1.
   Whether loot and missions drop with the tier: keeping high-tier loot in a softened pocket is a reward, dropping it is
   consistent. The loot swap is also the hardest part (F5).
6. **Campaign scope.** (answered) Is the campaign a per-save option or a separate map variant? Where does the player respawn after
   death (Hub, or the last bunker slept in; this is unread, J5)? Do bunkers need missions (C5) and persistent storage
   (C10), the two hardest services?
7. **Bunker access and services.** (answered; written up as shoulds group K) Are all bunkers open from the start, or do they unlock when their pocket or a
   neighbour is cleared (as State of Decay 2 outposts do)? Does every bunker get shop, repair and bed, or do some get a
   bed only?
8. **Where clearance is stored.** (recommendation given; gated on proof step 10) In the game save (`CustomMarkers`, per slot; a new game starts clean; persistence is
   inferred, not yet proven) or in a separate SaveGame slot (proven pattern, but per install, so a new game would
   inherit old clearance unless keyed by `GameUID`).

**Still open** (new, 2026-10-29):
9. **Neighbour bonus.** How much does a permanently cleared neighbour soften the adjacent pocket (rift timing,
   armour)? Per neighbour, a cap, or all-or-nothing (G2, G3)?
10. **Which services are gated, and each bunker's rule.** Recommended: mission computer, shop, repair and storage
    gated, the bed open; which of fixed, powered and cleared opens each, any-of or all-of (K2, K3); which artifact and
    what repair price per bunker (K5, K6).
11. **Counting details.** Player kills only or any death; how much a mission takes off (10 % is the example) (E3, E7).
12. **Loot on a T1 pocket.** Does literally T1 include T1 loot (F5)? To confirm.
13. **Storage.** Does `CustomMarkers` survive save and reload (proof step 10, H1, K9)?

## Proof steps, cheapest first

Merged and deduplicated from both corpus look-lists and the corrections. **[agent]** = offline or editor work an
agent can do; **[user editor]** / **[user VR]** = a user check. The VR steps can run as one grouped session.

1. **[agent, offline]** Does the showcase project hold stand-ins for `BP_FreeShop`, `BP_ShopComputer`,
   `BP_ShopShowcase`, `BP_ShopBin`, `BP_ShopSlot`, `BP_TrainStorage`, `BP_Bed`, `BP_ShelterVolume`, `BP_HealthBooth`,
   `BP_MissionComputer`, and the enemy parent classes the child BPs would extend? (`itr where`; T-152 forbids
   `/Game/ITR` closure copies.)
2. **[agent, offline]** Ghidra on `PRGameData::ApplyTideReset`: which maps it clears, and that it leaves
   `CustomMarkers` / `PassedTriggers` alone. In the same pass, what `SpawnSavedNPC` does with an unknown saved `TypeID`
   (H8).
3. **[user editor, or agent]** In the Construct (Bolotky) level: name the two basement buildings (which
   `Village_House_Destroyed_01_*` variant), measure the basement floors against the `BP_FreeShop` + bed footprint, and
   see how the landscape is kept out of them. Then, on `L_ItrShowcase`, a test `NavModifierVolume` over one building +
   buffer, with the navmesh view showing the cut (the lake already works).
4. **[agent, editor run + cook]** The child-class pattern on one enemy class: a BPGen child that binds its own death
   and spawn events and logs; its own NPC type tag + `FPRNPCInfo`, registered once; one spawner using that tag.
5. **[user VR]** Shooting range `BP_FreeShop`: buy, sell, repair.
6. **[user VR]** A zone bed (Buffer SupplyDepo): sleep until rested or until morning. Does the game save? Does the camp
   marker appear?
7. **[user VR]** Showcase return pads R1-R6: does each one return to the Hub? (V4-078 was last seen as "nothing".)
8. **[user VR]** Force a tide in the showcase (cheats tide button): do killed enemies and loot come back with
   `NativeReloadOnTide = false`? (V4-087.) In a stock zone, standing in a `BP_ShelterVolume`: does the tide leave you in
   place?
9. **[user VR]** Stand inside an existing nav-cut area (lake shore) with enemies alerted. Do they stop at the edge and
   hold or lose interest (B4)? Do they fire only with line of sight?
10. **[user VR + log probe]** One `UpdateMarker` write, then save, quit and reload: does `CheckMarker` still return true?
11. **[user VR]** The step 4 child: does it fight and loot like its parent, and is its death logged? After save and
    reload, does it come back as the child?

Only if the child route fails: a Lua `RegisterHook` probe on `UEventsManager.OnNPCDied` / `FireOnNPCDied`, and the BPGen
`node` op with `K2Node_AddDelegate` (shoulds.md D4, D5).

## Corrections to the corpus

The corpus files are left as written except for the dated note in game-systems.md section 8. Corrections:
- **game-systems.md §8:** stock basements exist (user, 2026-10-29), in Bolotky's construction site
  (`Prefab_Zone_Construct_Building_01_a`, down to z -3.7 m) and a broken-down house (`..._Village_House_Destroyed_01_b/_c/_d`,
  down to -3.3 / -2.8 m). A dated note has been added to the file.
- **implementation.md §3 (sleep):** "`SleepAllowed` set false by the showcase row" is stale. With `NativeSaves = true`
  the row copies the donor's flag (`main.lua:1653`, `config.lua:29`). See shoulds.md D1.
- **implementation.md §3 (repair host):** the repair pages live on `BP_TrainStorage`, which `BP_FreeShop` puts in
  repair-only mode (game-systems.md §1). See D2.
- **implementation.md §3 and §5 (safe zone):** targeting into the safe zone is not the big unknown it is listed as. The
  user's model is no-nav building + buffer, AI that fire only with line of sight, and no line of sight into the
  basement. Remaining checks: B4, B8.
- **implementation.md §3 and §5 (counting):** "BPGen can't bind `OnNPCDied`" is no longer on the critical path. The user's
  route is child enemy BPs that bind their own events (the bullet-penetration pattern). One SDK detail for that route:
  `Monsters` maps NPC type **tags** to counts, so each child needs its own registered type tag (shoulds.md E12, D10).
- **implementation.md §2 vs game-systems.md §2 (entry key):** both are right. F10 / `itrmap` are the loader defaults;
  the showcase config overrides them with F9 / `itrshowcase` (D9).
- **game-systems.md §3:** the `NativeReloadOnTide = false` comment "the map has no tide actor yet" in `config.lua:33`
  is stale (already noted there). Set it deliberately for this design (H7).
