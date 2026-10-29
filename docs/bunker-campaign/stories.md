# Bunker and clearance stories: how play would run

Player-perspective walkthroughs of the bunker and zone-clearance idea in ITR1 2.7.2 on the ITR Showcase map. Each story
is a short scene, followed by a **Should** list: what the systems do at each beat. The IDs (A1, E3, ...) point to the
tables in [shoulds.md](shoulds.md), which hold the "game today" evidence, the approach, the cost and the practicality.

Sources: [corpus/game-systems.md](corpus/game-systems.md) (stock mechanics) and
[corpus/implementation.md](corpus/implementation.md) (layers and costs). Where a stock mechanic already does the job, the
story uses it and names it. Nothing here has been built.

Names used:
- **Pocket**: one of the showcase's 12 generator areas P1-P12, each with one tier. P1 is T1, P2-P3 T2, P4-P7 T3,
  P8-P10 T4, P11-P12 T5. A pocket is the unit of clearance (user, 2026-10-29; README decision 1).
- **Bunker**: a 1-2 storey building over a basement. The basement holds the services (mission computer, shop, repair bay, storage, bed) and the recall
  door. Bunkers are open from the start; the services stay off until unlocked (S15).
- **Recall door**: a door in the basement that looks like it opens onto a tunnel out. It is a stand-on trigger to the
  Hub.
- **Director**: the per-level logic that reads clearance state when the level loads and applies it to spawners and rifts
  (see F1, G2).

---

## S1. First arrival, finding a bunker

*You enter the showcase from the Hub tin for the first time and arrive at the start pad by the Kordon entrance in P1.
Nothing is cleared.*

You walk into P1. It is quiet T1 country: spiders, a fragment or two. On the tablet the map shows the start pad and
one more gate icon a few hundred metres in (stock gate rows can only draw a gate icon, labelled with the level it leads
to). You reach a building you may know from Bolotky: the stock construction-site block, or the broken-down house
with the cellar, standing in a patch of open ground that nothing walks across. The ground floor is an ordinary ruin with
debris and a stair going down. At the bottom, a steel door
opens on a lit room with a different hum, a reverb that sounds underground, a shop terminal and display, a repair
hatch, a cot, and at the far end a heavy door with a hatch-lid frame and a dark culvert behind it.

**Should**
- The bunker is a stock building that already has a basement (the Bolotky templates), readable from outside, with one
  obvious way down (A1, A5).
- The building and a buffer of ground around it have no navmesh, so enemies never walk into it (B1).
- The tablet map already shows the bunker as a gate marker before you reach it (I3, D5).
- The stair leads to a basement roomy enough for the shop, the repair bay, a bed and space to move (A2, A5).
- The basement sounds and looks underground: bunker ambience, underground reverb, shelter lamps (A3).
- The recall door at the back looks like a tunnel exit, not a teleport pad (D1).
- Nothing spawns in or right next to the bunker, so you can't walk in on an enemy that appeared there (B2).
- The bunker is open, but its services start locked: dark, with a placard that says what opens them (K1, K4; S15).

---

## S2. Settling in: shop, repair, bed, save

*The bunker's services are already unlocked (S15). You came in with a damaged rifle, little ammo and low rest.*

You put the rifle on the repair hatch, pay, and take it back fixed. At the terminal you buy ammo and a medkit; they
drop into the bin beside it like in the Hub. You sell two scavenged pistols the same way. You lie on the cot and pick
"sleep until morning". You wake healed, the tablet shows a campfire marker on the bunker, and the game has saved.

**Should**
- The shop works like the Hub shop: same prices, same level gates, buying into a bin, selling from it (C1, C2, C3). This
  is stock `BP_FreeShop`, already placed in a non-Hub level (the shooting range).
- The repair hatch repairs only; no delivery or mission pages (C4). This is the stock `BP_TrainStorage` in
  `EnableRepiarModeOnly` mode, which `BP_FreeShop` already sets.
- The bed is the stock `BP_Bed`: sleep until rested or until morning, heal by percent (C6). The level row allows sleep
  (C6 notes the corpus disagreement on this).
- Sleeping puts the camp marker on the tablet (`SaveSleepLocation`) (C7).
- After sleeping, or on arrival, the game is saved so the bunker is a real checkpoint (C8).
- A healing booth like the Hub's (C9, optional) and a storage box that keeps what you leave (C10; bunkers get storage, user 2026-10-29). Each service works only once unlocked (K3).

---

## S3. Taking the recall door to the Hub and coming back

*Your pack is full of artefacts that sell better in the Hub, or you want the Hub's stash.*

You stand on the mat in front of the recall door. A lamp above it turns from amber to green, a low clunk sounds, and
after a couple of seconds the screen fades and you are in the Hub. Later you use the Hub tin to go back. You don't
arrive at the start pad. You arrive in the same basement, facing the stairs, where you left.

**Should**
- Standing on the mat for a short dwell sends you to the Hub; walking past it on the way to the shop does not (D2).
- The door shows it is armed (light and sound), and it does nothing during a level transition (D4).
- Coming back from the Hub puts you in the bunker you left from, in the basement (D3). The loader already remembers the
  exit id and arrives at the matching `itr:arrive:<id>` point.
- The bunker's recall door has its own gate marker on the tablet (D5).

---

## S4. Back after the tide, into a hot zone, fighting out from the basement

*You recalled from the P5 bunker (a T3 pocket) and spent a long time in the Hub. A tide has passed. You come back.*

You arrive in the P5 basement. Upstairs you hear movement: the tide has refilled P5, and a squad of armoured mimics now
holds the courtyard outside the bunker. In the old pad design you would have appeared on an open pad in their sight
line. Here you restock at the terminal, check your mags at the repair hatch, then go up the stairs and take the
ground-floor windows. No mimic can come into the building or across the buffer of open ground around it, but they can
shoot at the windows from beyond it, so the upper floors are a firing position, not a refuge. The basement behind you
is the refuge.

**Should**
- Arrival after a tide is in the basement, never outside in the open (D3, H4).
- The tide refills the pocket as normal; the bunker itself is untouched: shop, bed and door are level content, not
  spawned actors, so `KillActorsOnReload` does not remove them (H3, H5).
- No enemy spawns inside the bunker or in the stairwell, even right after a tide refill (B2).
- Enemies can't enter the building, but the ground and upper floors are exposed to fire through the windows from
  outside the buffer. They are a firing position (A4, B1).
- You can restock before the fight because the services are in reach (C1, C4).

---

## S5. An enemy chases you to the stairs

*You are pushing out of the P5 bunker. It goes badly. A Hunter flanks you and you sprint back into the building and
down the stairs with it following.*

The Hunter reaches the edge of the open ground around the bunker and stops: its path ends there. It takes cover behind a
wall at the edge and fires at the ground-floor windows while it can see you. Once you are on the stairs it has no line
of sight, and in the basement there is none from anywhere it can stand. After a minute it gives up and wanders back
to its spawner. The fragment that was also chasing you runs to the same edge, finds no way on, and mills about until it
loses interest.

**Should**
- No enemy can path into the buffer, the building or down the stair: there is no navmesh there (B1).
- Enemies fire only with direct line of sight, and no spot an enemy can reach sees into the basement (B3).
- The buffer is wide enough that nobody standing at its edge can see down the stairwell (B8).
- An enemy whose path stops at the buffer edge holds cover or loses interest (the stock 60 s lost timer); it doesn't
  jitter on the edge or slide inside (B4).
- If anything does end up inside (a ragdoll, a physics push), the safe zone removes it (B7, only if needed).
- Shooting in the basement doesn't call the whole pocket to the door, or at least no more than shooting in any closed
  room does (B5).

---

## S6. Clearing a pocket by hunting

*You decide to clear P2 (T2) so the route to the T3 pockets is easier.*

You work P2 sector by sector. Each kill counts silently. Back at the P2 bunker, the clearance board on the basement wall
shows P2 at 46 %. There are still two rifts. While they live, they keep calling their spawners every few minutes, and
the count stalls because new spawns don't count as progress. You go out, find the rifts by their light and noise, and
shoot them down. Each drops a shard. The next sweep takes P2 to 82 %, then 91 %.

**Should**
- A kill counts for the pocket the enemy belongs to (its spawner's pocket), not for wherever the body falls (E1).
- The enemy reports its own death: each enemy in the map is a child of the stock class that does exactly what the
  stock one does, plus reporting its death and spawn (E3, E10, E11, E12).
- The target is the generator's planned population for the pocket, not a live count, so rift respawns can't inflate or
  drain progress (E2, E4).
- Clearance is a percentage of the pocket's population; 90 % is the clear threshold (E2, E8).
- Rifts matter: they keep respawning while alive and they count toward clearance (as a share or as a must-kill), so
  clearing a pocket means dealing with its rifts (E4).
- Counting costs nothing between kills: it reacts to a death event, with no poll (E9).
- Progress shows at the bunker board, and only updates when it changes (I1).
- The count is saved with the game (H1).

---

## S7. Clearing a pocket by missions

*You don't want to hunt every spider in P3. You take P3 missions instead.*

At the Hub mission computer (or at an unlocked bunker's mission computer) you take a "clear the depot" kill mission and
a fetch mission in P3. Finishing the kill mission takes a fixed share off (say 10 %), which suits a stubborn leftover
group, so P3 goes from 30 % to 40 %. The board in the P3 bunker shows both sources: kills and missions.

**Should**
- Finishing a mission whose objective point lies in a pocket takes a fixed share (e.g. 10 %) off that pocket's remaining clearance, for a stubborn leftover group (E7).
- Mission kills also count as kills only if the decided weighting says so; they are not counted twice (E3, E7; the weighting is still open).
- Kills and missions combine toward the same threshold (E8).
- Mission completion is caught from the mission-finished event, not by polling the mission list (E7, E9).

---

## S8. The downgrade moment

*P2 crosses 90 % while you are out in it.*

You kill the last fragment of a squad and hear a distant siren wail, then quiet. Nothing changes around you; the
enemies still alive stay as they are. Back at the bunker the board shows P2 at "CLEARED: T1" in a new colour, and the
tablet map tints P2 green. The next time P2 fills, after you leave and come back or after the next tide, the rosters
are spiders and fragments, P2 behaves like vanilla T1 and respawns normally, and (if loot follows the tier; to confirm) the stashes roll T1 loot.

**Should**
- Crossing the threshold is a clear moment: a sound cue and the bunker board flipping (F2, I1).
- Nothing swaps mid-fight: enemies still alive keep their type until killed or until the next reset (F3).
- From the next fill (load or tide), the pocket is literally T1 (F1): T1 rosters, vanilla T1 behaviour, normal respawn.
  Slower or fewer rifts (F4) and fewer active spawners (F8) only if plain T1 is not enough.
- Loot and missions in the pocket follow the new tier, if wanted (F5, F6); the loot reading of "T1" is to confirm.
- The tablet map shows the pocket as cleared (I2).
- Clearing P1, which is already T1, changes no roster: it only gets the cleared state (F7).

---

## S9. A permanently cleared neighbour softens the adjacent pocket

*P2 and P3 (both T2) are cleared. You head into P4 (T3), which borders both.*

The P4 bunker board says "Neighbours cleared: 2. Rifts slower, fewer armoured." Out in P4, the rifts still spawn, but
the gap between waves is longer than it was. The Factory-style squads have plain mimics and commandos where there used
to be armoured ones. P4 is still T3, so the fights are real, but you can make progress.

**Should**
- Neighbours come from the generator layout (pocket adjacency), not from distance at run time (G1).
- How much a cleared neighbour softens the pocket (rift timing, armour) is an open question (README decision 9).
- Each cleared neighbour lengthens rift cooldowns in the pocket, up to a cap (G2).
- Each cleared neighbour removes armoured variants from the pocket's rosters, replaced with the plain variant (G3).
- The bonus is local to that pocket and never touches the global difficulty (G4).
- It takes effect at the pocket's next fill, not mid-visit (G6).
- The board tells you which bonuses are active (I4).

---

## S10. Checking clearance

*You want to plan the next push.*

In any bunker basement, the wall board shows all 12 pockets: tier, clearance % (kills / missions), CLEARED or not, and
active neighbour bonuses. On the hip tablet, the map tab shows the showcase map with cleared pockets tinted and the
bunkers as gate markers. Out in the field you have no live counter; to check, you go back to a bunker.

**Should**
- The board lists every pocket with tier, progress and bonuses, in world space, written only when values change (I1,
  I4).
- The tablet map shows which pockets are cleared (I2) and where the bunkers are (I3).
- An optional field readout (I5) is a separate want: it needs a widget, which BPGen can't author today.

---

## S11. The tide hits a cleared pocket

*You are in the P2 bunker (cleared, T1) when the tide warning sounds. You stay in the basement.*

The fog rolls through. You stay where you are; the bunker counts as shelter. When it passes, P2 has repopulated, but
with T1 rosters: the spiders and fragments are back, the rifts are back at their normal T1 cooldown, and stashes have rolled
fresh T1 loot. The board still says CLEARED. The clearance is permanent: a cleared pocket is never re-contested (user, 2026-10-29).

**Should**
- Being in the basement when the tide hits leaves you there: stock `BP_ShelterVolume` saves your current transform
  instead of a random respawn (H4).
- The tide resets the pocket's spawners and loot as in any zone, at the pocket's current tier (T1 if cleared) (H3).
- Clearance and neighbour bonuses survive the tide; they are stored outside `SpawnSaveData`, which the tide clears
  (H2).
- The bunker's services, and anything you left in its storage, survive the tide (H5, H6).
- The showcase's reload-on-tide setting is set for this design, not left at the stale default (H7).

---

## S12. The long campaign, with only the starting recall point

*Campaign mode, the default route but not a forced one. The only recall pad left is R0 at the Kordon entrance. Every other route home is gone. You start a new game. Respawn after death stays default for now.*

You arrive at R0 with starter kit. P1's bunker is the first base. You clear P1, then push to P2 and use its bunker as
the next base: sleep, buy, repair, all there. You never go back to the Hub unless you walk to R0. Clearing P2 and P3
softens P4; P4's bunker becomes the base for the T3 belt. Twenty hours in, you are working on P11 from the P10 bunker,
with a map of green pockets behind you.

**Should**
- The recall pads R1-R6 are gone (or switched off) in campaign mode; R0 stays (J1, a later step).
- The campaign is the default, but players don't have to follow it (J10).
- Everything a run needs is in reach of a bunker: shop, repair, bed, healing, storage, and missions (J2, C5, C9, C10).
- Bunkers are open from the start; their services open by fixing, powering or clearing the pocket (K1-K9, S15), so bases move forward with you. (J3, the old "bunker opens when cleared" idea, is removed.)
- The pocket order gives a route: tier rises with distance from R0, and clearing softens the next (J4, G2, G3).
- The Hub is still reachable from R0 for anything bunkers don't have (J8).
- Every piece (bunker kit, director, counter, board) is something another map could reuse (J9).

---

## S13. Failure: dying far from a bunker

*Deep in P7 (T3), far from any bunker, a Marksman drops you.*

You respawn the stock way. Your gear lies where you died, and the tablet shows a death marker there. The clearance you
earned in P7 is kept: those kills counted. Respawn stays default for now (user, 2026-10-29); respawning at the last bunker you slept in is deferred.

**Should**
- Kills and mission progress made before the death are kept; death doesn't roll back clearance (H1).
- Your dropped gear and its death marker work as in stock (`DeathDropItems`, `LastDeathLocation`) (J6).
- Respawn stays default for now; last-slept-bunker respawn is deferred (J5).

---

## S14. removed (user 2026-10-29)

A cleared pocket is never re-contested, so this story is gone. Its shoulds (J7, and the re-contest warning in I4) are
removed too. The ID stays so S15 doesn't renumber anything.

---

## S15. Unlocking a bunker

*You reach the P3 bunker for the first time. The door is open and you walk in, but the terminals are dark.*

The shop and the mission computer show a red lamp and a placard: "Needs: repair, or power cell, or P3 cleared". The
repair bay and storage are shuttered the same way. The bed is open, so you can at least rest and save. You have money,
so you walk to the repair panel on the wall, pay once and hear the lights come on, but only the services whose rule
includes "fixed" open: the shop and the repair bay. The mission computer's rule asks for power or for P3 cleared. Later
you bring the artifact the placard names, set it in the socket and the mission computer comes up. Or you clear P3, and
all of its services open without another visit. Quit and reload, and nothing relocks.

**Should**
- The bunker itself is open from the start; only the services are gated (K1).
- Each bunker has fixed, powered and cleared state and a rule per service; each service has its own state (K2, K3).
- A locked service shows it is locked and what opens it (K4).
- Fixing is a one-time money payment at a panel (K5); powering is a specific artifact put in a socket (K6); clearing
  is the pocket crossing 90 % (K7).
- The state applies at load and changes live with a cue (K8).
- It is saved with the clearance and never relocks, and survives tides (K9, H1, H2).
- The board shows each bunker's state (K10, I1).

---

## Story count

15 stories (S1-S15); S14 is removed, so 14 are live.
