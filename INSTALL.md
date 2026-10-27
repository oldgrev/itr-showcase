# ITR Showcase: install (for modders)

A 2.5 km demo map for **Into the Radius 1, version 2.7.2** (PC VR). **Status: early test with issues.** The map loads, can be
walked, and its gameplay systems run, but a full pass in VR is still to come (see "Known issues" below). It is a reference
for people building their own maps, not a polished level.

The game cannot enter custom maps by itself. This release adds three things: the map pak, a small UE4SS Lua mod
(`ItrShowcaseLoader`) that registers the map with the game as a level and enters it through the game's normal level
transfer, and UE4SS itself (trimmed to the files the loader needs). Nothing else has to be downloaded.

## Pick one archive
Both hold the same files and install to the same paths.

| Archive | For | How |
|---|---|---|
| `ItrShowcase-<date>.zip` | manual install | Unzip into the game folder (the folder with `IntoTheRadius.exe`). |
| `ItrShowcase-<date>-FOMOD.zip` | Vortex with the "Into the Radius VR" extension | Install it like any mod; the installer has one UE4SS step (see below). |

## What is inside
Paths are relative to the game folder (Steam: `...\steamapps\common\IntoTheRadius`). The normal archive has them under its top
folder `IntoTheRadius`, so unzipping into the game folder puts every file in place.
```
IntoTheRadius\Binaries\Win64\dwmapi.dll                    UE4SS proxy: the game loads it, it loads UE4SS
IntoTheRadius\Binaries\Win64\override.txt                  contains "../../Content/Paks": where UE4SS lives
IntoTheRadius\Content\Paks\UE4SS.dll                       UE4SS v3.0.1-321-gc62ada0
IntoTheRadius\Content\Paks\UE4SS-settings.ini              settings (changed values listed below)
IntoTheRadius\Content\Paks\UE4SS-LICENSE.txt               UE4SS licence (MIT)
IntoTheRadius\Content\Paks\LuaMods\shared\UEHelpers\UEHelpers.lua    helper the loader requires
IntoTheRadius\Content\Paks\LuaMods\ItrShowcaseLoader\enabled.txt     turns the loader on
IntoTheRadius\Content\Paks\LuaMods\ItrShowcaseLoader\Scripts\main.lua, config.lua, missions.lua, ItrShowcase.loot.json, ItrShowcase.missions.json
IntoTheRadius\Content\Paks\~mods\zzz_ITRMap_ItrShowcase_P.pak        the map (about 480 MB)
```
The normal archive also has `ITR-Showcase-INSTALL.md` (this file) at its root; you can delete it after unzipping.

**UE4SS is the build from "UE4SS for ITR1" on Nexus Mods** (https://www.nexusmods.com/intotheradiusvr/mods/359, file
`UE4SS-ITR-359-v3-0-1-321-gc62ada0`, a repack of UE4SS 3.0.1 by MerithXYZ), with `override.txt` pointing it at `Content\Paks`.
Only the files the loader needs are included. Left out on purpose: UE4SS's sample and dev mods (CheatManagerEnabler,
ConsoleEnabler, ConsoleCommands, BPModLoader, BPML_GenericFunctions, LineTrace, Keybinds, ActorDumper, SplitScreen and the
profiler), its `shared` helpers other than `UEHelpers`, `mods.txt` (a mod with an `enabled.txt` starts without it), the
Changelog and README, and the debug symbols.

## Manual install (normal archive)
1. Close the game.
2. Unzip `ItrShowcase-<date>.zip` into the game folder. Let it merge with the existing `IntoTheRadius` folder.
3. Check that `IntoTheRadius\Content\Paks\UE4SS.dll` and `IntoTheRadius\Content\Paks\~mods\zzz_ITRMap_ItrShowcase_P.pak` exist.
4. Start the game, see "Play" below.

## Vortex install (FOMOD archive)
1. Install the "Into the Radius VR" Vortex extension (Nexus Mods) and add the game.
2. Drag `ItrShowcase-<date>-FOMOD.zip` into Vortex's Mods page (or "Install from file") and install it.
3. The installer shows one step, **Script loader (UE4SS)**, ticked by default. Keep it ticked unless UE4SS for Into the Radius is
   already installed on your game (`Content\Paks\UE4SS.dll` exists); then untick it, so your own UE4SS settings and Lua mods
   stay as they are. The map and the loader are always installed.
4. Deploy, then start the game.

## Already have UE4SS?
Two UE4SS copies must not be installed side by side. If one is installed:
- **Nexus layout** (`Content\Paks\UE4SS.dll`): skip the UE4SS files (untick the FOMOD step; with the normal archive, delete
  `Binaries`, `UE4SS*` and `LuaMods\shared` from the unzipped tree before copying, or restore your files afterwards). Keep
  `LuaMods\ItrShowcaseLoader` and the pak. Your `LuaMods\shared\UEHelpers\UEHelpers.lua` must exist.
- **Standard layout** (`Binaries\Win64\ue4ss`): copy only `LuaMods\ItrShowcaseLoader` into `ue4ss\Mods\` and the pak into
  `Content\Paks\~mods`. Add the line `ItrShowcaseLoader : 1` to `ue4ss\Mods\mods.txt`. `ue4ss\Mods\shared\UEHelpers\UEHelpers.lua`
  must exist, and `ModsFolderPath` in the ini must name your `Mods` folder.
- Either way the build matters: this loader is tested with v3.0.1-321-gc62ada0 only. Other builds are not known to work; a newer
  dev build (v3.0.1-1165-g12ec45a0) crashed the game a few seconds after start in our tests.
- Use the settings in the next section.

## ITRMapLoader (the example map loader from itr-common)
The showcase does not need it, and the showcase was tested with it switched off. The two mods are written to run side by side (each
has its own folder, log tag, key, console command and Hub item: F10, `itrmap` and the sugar cube for ITRMapLoader), but that
combination has not been tested with this release. Switch ITRMapLoader off while you play the showcase:
- **Standard layout:** set `ITRMapLoader : 0` in `ue4ss\Mods\mods.txt`, and rename `ue4ss\Mods\ITRMapLoader\enabled.txt` to
  `enabled.txt.off`.
- **Nexus layout:** rename `Content\Paks\LuaMods\ITRMapLoader\enabled.txt` to `enabled.txt.off` (and set `ITRMapLoader : 0` if you
  made a `mods.txt` there).

Remove the `enabled.txt` as well as the `mods.txt` line: a mod folder with an `enabled.txt` can start without a `mods.txt` line. The
release archives contain no `mods.txt` and no ITRMapLoader, so they never switch it on or off; only a copy you installed yourself
can be running.

## UE4SS settings
The included `UE4SS-settings.ini` is the Nexus file with these values. They are the ones the loader was tested with; if you keep
your own ini, set them too:

| Setting | Value | Why |
|---|---|---|
| `ConsoleEnabled`, `GuiConsoleEnabled`, `GuiConsoleVisible` | `0` | no console or GUI window |
| `GraphicsAPI` | `dx11` | the game is D3D11 (only matters if the GUI is on) |
| `bUseUObjectArrayCache` | `false` | UE4SS advises it against startup crashes; the tested value |
| `HookInitGameState` | `0` | not used by the loader |
| `HookLoadMap` | `1` | the tested value |
| `HookBeginPlay` | `0` | the loader registers no BeginPlay callback, so this hook is off. If the loader does not start, set it to `1` |
| `ModsFolderPath` | `./LuaMods` | where the Nexus layout keeps Lua mods (`./Mods` in the standard layout) |
| `SecondsToScanBeforeGivingUp` | `30` | |

The other hooks stay on, as in the setup the loader was tested with. The loader hooks a Hub item's grab event, registers a console
command and runs timers, which rely on them; `HookBeginPlay` is the only one it is known not to use.

## Play
Start the game, press Continue and wait in the Hub. Then:
- pick up the **tin of graphite grease** in the Hub's workshop corner, by the tool wall and workbench (a grey metal tin with a yellow
  lid and a "GRAPHITE GREASE 500g" label; the loader recognises it by its static mesh, `Liquid08_1`). It stands with a second tin and
  a loose lid, which do nothing; if the first tin you pick up does nothing, try its neighbour, or
- press **F9**, or
- run the console command `itrshowcase enter`. This release does not add a console; it works from one you already have, or from
  a mod that sends console commands.

The game runs its normal level transition and you arrive at the start in the south, with the map's spawners, loot and
anomalies running. The map is a registered level (`Level.Zone.ItrShowcase`) that copies the Buffer zone's settings, so game time
passes, and stamina and hunger run, as in a stock zone. While you are in the map the map sets `r.ViewDistanceScale 6` and
`foliage.LODDistanceScale 6` (a Blueprint in the map pak) and puts the earlier values back when you leave.

The mission computer in the Hub offers the showcase missions once the loader is running (see "Showcase missions and uninstalling" in
the README before you remove the mod). The map has a compass and a tablet map, and a printed map board at the entrance.

**Leaving:** walk onto one of the **return pads** (R0 to R6, a flat disc with a beam; the loader exit is on the pad), or press
`F9`, or type `itrshowcase leave`. You go back to the Hub through the same transition. The cyan "to entrance" pads beside
R1 to R6 only move you around inside the map.

**The edge of the map** is a square fog wall about 1.25 km from the centre, driven by a child of the game's `BP_TideBase`, so walking
into it should trigger the game's normal fog transition and put you back inside at one of the map's respawn splines. That
transition has not been through a full VR test since native loading came in.

`UE4SS.log` (next to `UE4SS.dll`, in `Content\Paks`) shows what the loader does; look for `[ItrShowcaseLoader]` lines.

## Known issues
- **A save made inside the map loads into the Hub**, not into the map: Continue puts you in the Hub and you enter the map again
  from there. The loader registers the level before the main menu and turns the level's save flags on, but the game still resolves
  the saved level to the Hub. The cause is not found yet.
- **Sun and sky light intensity are not applied yet.** The intended default for both is 1.0; the level in the pak still carries
  3.0, so the map looks brighter than planned. The first attempt at the fix did not reach the saved level; a new one is pending.
- Layout and dressing are still being tuned from walk tests: ground and foliage colour, enemy pressure, and where stashes and rifts
  sit. The gameplay setup, which is what this repo is for, is the part to look at.
- Loot balance is still being tuned.
- The game can crash while it shuts down. The same crash is in sessions without any mod installed, so it is not caused by this map
  or the loader.

## Troubleshooting
- **The game hangs at startup** (no window, about 12 MB of memory): `UE4SS.dll` is not where `override.txt` points. It has to sit
  directly in `IntoTheRadius\Content\Paks`, not in a subfolder.
- **Nothing happens at the grease tin:** open `Content\Paks\UE4SS.log`. No `[ItrShowcaseLoader]` lines means the loader did
  not start: check that `LuaMods\ItrShowcaseLoader\enabled.txt` exists and `ModsFolderPath` is `./LuaMods`. A line `ready: ...`
  and later `native: READY` means it is waiting for you in the Hub.
- **The loader is ready but the map does not load:** the pak has to be in `Content\Paks\~mods` and named
  `zzz_ITRMap_ItrShowcase_P.pak`.

## Uninstall
Leave the map first and let the Hub autosave run, because a save made inside the map names a level only the loader registers.
If the save holds a showcase mission, read "Showcase missions and uninstalling" in the README first. Then delete `Content\Paks\~mods\zzz_ITRMap_ItrShowcase_P.pak` and `Content\Paks\LuaMods\ItrShowcaseLoader`. To remove the
bundled UE4SS as well: `Binaries\Win64\dwmapi.dll` and `override.txt`, and from `Content\Paks` the files `UE4SS.dll`,
`UE4SS-settings.ini`, `UE4SS-LICENSE.txt`, `UE4SS.log` and `LuaMods\shared`. In Vortex, disable or remove the mod and purge.

The Unreal project (to inspect how the map is set up) is in the ITR Showcase repo this release was built from.
