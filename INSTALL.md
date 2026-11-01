# ITR Showcase: install (for modders)

A 2.5 km demo map for **Into the Radius 1, version 2.7.2** (PC VR). **Status: early test with issues** (see "Known issues" below).
It's a reference for people building maps, and it isn't polished.

The game can't enter custom maps by itself, so this release has the map paks, a small UE4SS Lua mod (`ItrShowcaseLoader`) that
registers the map with the game as a level and enters it through the game's normal level transfer, and UE4SS trimmed to the files
the loader needs. You don't need to download anything else.

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
IntoTheRadius\Content\Paks\~mods\zzz_ITRMap_ItrShowcase_Tags_P.pak   the level tag pak (under 1 KB): registers the map's level tag so saves keep it
```
The normal archive also has `ITR-Showcase-INSTALL.md` (this file) at its root; you can delete it after unzipping.

**UE4SS is the build from "UE4SS for ITR1" on Nexus Mods** (https://www.nexusmods.com/intotheradiusvr/mods/359, file
`UE4SS-ITR-359-v3-0-1-321-gc62ada0`, a repack of UE4SS 3.0.1 by MerithXYZ), with `override.txt` pointing it at `Content\Paks`.
Only the files the loader needs are included. Left out: UE4SS's sample and dev mods (CheatManagerEnabler,
ConsoleEnabler, ConsoleCommands, BPModLoader, BPML_GenericFunctions, LineTrace, Keybinds, ActorDumper, SplitScreen and the
profiler), its `shared` helpers other than `UEHelpers`, `mods.txt` (a mod with an `enabled.txt` starts without it), the
Changelog and README, and the debug symbols.

## Manual install (normal archive)
1. Close the game.
2. Unzip `ItrShowcase-<date>.zip` into the game folder. Let it merge with the existing `IntoTheRadius` folder.
3. Check that `IntoTheRadius\Content\Paks\UE4SS.dll`, `IntoTheRadius\Content\Paks\~mods\zzz_ITRMap_ItrShowcase_P.pak` and `IntoTheRadius\Content\Paks\~mods\zzz_ITRMap_ItrShowcase_Tags_P.pak` exist.
4. Start the game, see "Play" below.

## Vortex install (FOMOD archive)
1. Install the "Into the Radius VR" Vortex extension (Nexus Mods) and add the game.
2. Drag `ItrShowcase-<date>-FOMOD.zip` into Vortex's Mods page (or "Install from file") and install it.
3. The installer shows one step, **Script loader (UE4SS)**, ticked by default. If you already have UE4SS for Into the Radius
   (`Content\Paks\UE4SS.dll` exists), untick it so your UE4SS settings and Lua mods stay as they are.
4. Deploy, then start the game.

## Already have UE4SS?
Two UE4SS copies must not be installed side by side. If one is installed:
- **Nexus layout** (`Content\Paks\UE4SS.dll`): skip the UE4SS files (untick the FOMOD step; with the normal archive, delete
  `Binaries`, `UE4SS*` and `LuaMods\shared` from the unzipped tree before copying, or restore your files afterwards). Keep
  `LuaMods\ItrShowcaseLoader` and the pak. Your `LuaMods\shared\UEHelpers\UEHelpers.lua` must exist.
- **Standard layout** (`Binaries\Win64\ue4ss`): copy only `LuaMods\ItrShowcaseLoader` into `ue4ss\Mods\` and the pak into
  `Content\Paks\~mods`. Add the line `ItrShowcaseLoader : 1` to `ue4ss\Mods\mods.txt`. `ue4ss\Mods\shared\UEHelpers\UEHelpers.lua`
  must exist, and `ModsFolderPath` in the ini must name your `Mods` folder.
- Either way, this loader is tested with v3.0.1-321-gc62ada0 only. Other builds are not known to work; a newer dev build
  (v3.0.1-1165-g12ec45a0) crashed the game a few seconds after start for me.
- Use the settings in the next section.

## ITRMapLoader (the example map loader from itr-common)
The showcase doesn't need it and was tested with it switched off. The two mods are written to run side by side (separate folder,
log tag, key, console command and Hub item: F10, `itrmap` and the sugar cube for ITRMapLoader), but that hasn't been tested with this
release. Switch ITRMapLoader off while you play the showcase:
- **Standard layout:** set `ITRMapLoader : 0` in `ue4ss\Mods\mods.txt`, and rename `ue4ss\Mods\ITRMapLoader\enabled.txt` to
  `enabled.txt.off`.
- **Nexus layout:** rename `Content\Paks\LuaMods\ITRMapLoader\enabled.txt` to `enabled.txt.off` (and set `ITRMapLoader : 0` if you
  made a `mods.txt` there).

Remove the `enabled.txt` as well as the `mods.txt` line: a mod folder with an `enabled.txt` can start without a `mods.txt` line. The
release archives have no `mods.txt` and no ITRMapLoader, so this only matters if you installed it yourself.

## UE4SS settings
The included `UE4SS-settings.ini` is the Nexus file with these values, which are what the loader was tested with. If you keep your
ini, set them too:

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
  lid and a "GRAPHITE GREASE 500g" label; the loader looks for its static mesh, `Liquid08_1`). There's a second tin and a loose lid
  next to it that do nothing, so if the first tin does nothing, try the other one, or
- press **F9**, or
- run the console command `itrshowcase enter`. This release doesn't add a console; use one you have, or a mod that sends console
  commands.

You arrive at the start in the south. The map is a registered level (`Level.Zone.ItrShowcase`) that copies the Buffer zone's
settings, so game time, stamina and hunger work like a stock zone. While you're in the map, a Blueprint in the map pak sets
`r.ViewDistanceScale 6` and `foliage.LODDistanceScale 6` and puts the earlier values back when you leave.

The mission computer in the Hub offers the showcase missions once the loader is running (see "Showcase missions and uninstalling" in
the README before you remove the mod). The map has a compass and a tablet map, and a printed map board at the entrance.

**Leaving:** to get back to the Hub, walk onto the **return pad** (R0 at the Kordon entrance, a flat disc with a beam), or
press `F9`, or type `itrshowcase leave`. The bunkers (below) can also be used.

**Bunkers.**
There are ruined buildings in Kordon, on the track by Tikhoe lake, at the rail halt by the dachas, and at the end of Zarechye's upper street, and their cellar stairs all lead to the same bunker. Walk back to the landing to get back out. The tunnel door's handle can be grabbed to return to the Hub. When you want to return, you'll return back to wherever you left from.
See "Bunkers" in the README.


**The edge of the map** is a square fog wall about 1.25 km from the centre, driven by a child of the game's `BP_TideBase`, so walking
into it should trigger the game's normal fog transition and put you back inside at one of the map's respawn splines. That
transition has not been through a full VR test since native loading came in.

`UE4SS.log` (next to `UE4SS.dll`, in `Content\Paks`) shows what the loader does; look for `[ItrShowcaseLoader]` lines.

## Known issues
- **Saving in the map needs `zzz_ITRMap_ItrShowcase_Tags_P.pak`** next to the map pak. Without it Continue opens the Hub and what you
  left in the map is lost. It needs the loader too: with the loader gone and the pak still there, a save made in the map won't
  continue. `UE4SS.log` has a line `tags: Level.Zone.ItrShowcase is REGISTERED` when the tag pak works.
- Everything placed is still being tuned.
- My game sometimes crashes when I exit it, but it's done that before I even installed anything so I doubt it's this.

## Troubleshooting
- **The game hangs at startup** (no window, about 12 MB of memory): `UE4SS.dll` is not where `override.txt` points. It has to sit
  directly in `IntoTheRadius\Content\Paks`, not in a subfolder.
- **Nothing happens at the grease tin:** open `Content\Paks\UE4SS.log`. No `[ItrShowcaseLoader]` lines means the loader did
  not start: check that `LuaMods\ItrShowcaseLoader\enabled.txt` exists and `ModsFolderPath` is `./LuaMods`. A line `ready: ...`
  and later `native: READY` means it is waiting for you in the Hub.
- **The loader is ready but the map does not load:** the pak has to be in `Content\Paks\~mods` and named
  `zzz_ITRMap_ItrShowcase_P.pak`.
- **Continue opens the Hub although you saved in the map:** a `UE4SS.log` line `tags: ... NOT registered` means
  `zzz_ITRMap_ItrShowcase_Tags_P.pak` is missing or not in `Content\Paks\~mods`.

## Uninstall
Leave the map first and let the Hub autosave run, because a save made inside the map names a level only the loader registers.
If the save holds a showcase mission, read "Showcase missions and uninstalling" in the README first. Then delete `Content\Paks\~mods\zzz_ITRMap_ItrShowcase_P.pak`, `Content\Paks\~mods\zzz_ITRMap_ItrShowcase_Tags_P.pak` and `Content\Paks\LuaMods\ItrShowcaseLoader`. To remove the
bundled UE4SS as well: `Binaries\Win64\dwmapi.dll` and `override.txt`, and from `Content\Paks` the files `UE4SS.dll`,
`UE4SS-settings.ini`, `UE4SS-LICENSE.txt`, `UE4SS.log` and `LuaMods\shared`. In Vortex, disable or remove the mod and purge.

The Unreal project (to inspect how the map is set up) is in the ITR Showcase repo this release was built from.
