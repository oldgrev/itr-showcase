# ITR Showcase: install (for modders)

A 2.5 km demo map for **Into the Radius 1, version 2.7.2** (PC VR). **Early test with issues**: it loads and has been
walked in test runs, but a full pass in VR is still to come. This is a reference for people building their own maps,
not a polished level for playing.

The game can't enter custom maps by itself, so the map needs two things besides its pak: UE4SS, and a small Lua script
that streams the map in when you reach the Hub. This zip has the pak and that script. UE4SS you get yourself (step 1).

What's in this zip:
```
zzz_ITRMap_ItrShowcase_P.pak                 the map (~400 MB)
ue4ss/Mods/ITRMapLoader/                      the Lua loader, set up for this map
    enabled.txt
    Scripts/main.lua, config.lua, ItrShowcase.loot.json
INSTALL.md                                    this file
```

## 1. Install UE4SS (not included)
Use **UE4SS v3.0.1-321-gc62ada0**, the build from "UE4SS for ITR1" on Nexus Mods:
https://www.nexusmods.com/intotheradiusvr/mods/359 (file `UE4SS-ITR-359-v3-0-1-321-gc62ada0`, a repack of UE4SS 3.0.1 by
MerithXYZ). Install it with Vortex and the Into the Radius extension, or by hand as the mod page says:

- `dwmapi.dll` and `override.txt` go into `<game>\IntoTheRadius\Binaries\Win64\`. `override.txt` contains just
  `../../Content/Paks`.
- The **contents** of the zip's `ue4ss\` folder go into `<game>\IntoTheRadius\Content\Paks\`, so `UE4SS.dll`,
  `UE4SS-settings.ini` and the `Mods` folder sit directly in `Paks`.
- In `Paks`, rename `Mods` to `LuaMods`, because this build's `UE4SS-settings.ini` reads Lua mods from `./LuaMods`.

If the game hangs at startup (no window, about 12 MB of memory), `UE4SS.dll` isn't where `override.txt` points. You
probably copied the `ue4ss` folder itself into `Paks` instead of what's inside it.

The **standard UE4SS layout** also works (we started the game with it, not in VR): `dwmapi.dll` and the whole `ue4ss\`
folder next to `IntoTheRadius-Win64-Shipping.exe` in `Binaries\Win64`, no `override.txt`, nothing in `Paks`, and `Mods`
keeps its name. Use only one of the two layouts.

Other UE4SS builds are not known to work. A newer dev build (v3.0.1-1165-g12ec45a0) crashed the game a few seconds after
start in our tests.

## 2. UE4SS settings
Open `UE4SS-settings.ini` (in `Content\Paks`, or in `Binaries\Win64\ue4ss` in the standard layout) and check these. They
are the values that started the game without crashing in our tests:

| Setting | Value |
|---|---|
| `GuiConsoleEnabled`, `GuiConsoleVisible`, `ConsoleEnabled` | `0` |
| `bUseUObjectArrayCache` | `false` |
| `HookInitGameState` | `0` |
| `HookLoadMap` | `1` |
| `GraphicsAPI` | `dx11` (the game is D3D11; `opengl` only matters if the GUI is on, so keep the GUI off) |
| `ModsFolderPath` | the folder your mods are in: `./LuaMods` (Nexus layout) or `./Mods` (standard layout) |
| `SecondsToScanBeforeGivingUp` | `30` |

## 3. Install the loader
1. Copy `ue4ss\Mods\ITRMapLoader` from this zip into UE4SS's mods folder: `Content\Paks\LuaMods\` in the Nexus layout,
   `Binaries\Win64\ue4ss\Mods\` in the standard layout. Result: `...\ITRMapLoader\Scripts\main.lua` and
   `...\ITRMapLoader\enabled.txt`.
2. Make sure the mods folder also has `shared\UEHelpers.lua` (it comes with UE4SS; `main.lua` calls
   `require("UEHelpers")`). This zip doesn't include it.
3. Mod list. The empty `enabled.txt` turns the loader on, so the Nexus layout needs nothing more. In the standard
   layout, `Mods\mods.txt` also needs the line `ITRMapLoader : 1`. UE4SS's default dev mods (CheatManagerEnabler,
   ConsoleEnabler, ConsoleCommands, BPModLoader, BPML_GenericFunctions, LineTrace) aren't needed; we ran with only
   ITRMapLoader enabled.

`config.lua` is already set for the showcase (`AutoLoadInHub = "ItrShowcase"`). Details: the README in the repo's
`loader/` folder.

## 4. Install the map
Copy `zzz_ITRMap_ItrShowcase_P.pak` into `<game>\IntoTheRadius\Content\Paks\`. The `zzz_` makes it load last.

## 5. Play
Start the game and Continue into the Hub. Some seconds after the Hub has loaded, the loader streams the map in, moves
you to the start at the southern entrance, unloads the Hub's levels and starts the map's spawners and loot.
To leave, walk onto one of the return pads (the exit markers); you're taken back to the Hub. On a keyboard, `F7` also
loads and leaves. The map's teleport pads only move you around inside the map.

`UE4SS.log` (next to `UE4SS.dll`) shows what the loader is doing; look for `[ITRMapLoader]`.

## Known issues
- The loader's Lua path (Hub teardown, exit, gameplay activation) was ported from our C++ mod and hasn't had a complete
  pass through UE4SS Lua yet.
- Loot from the map's loot tables, through the map-held table actor, is untested in this path.
- Teleport points drop you about 128 cm onto the ground after landing.

## Uninstall
Delete the pak, `dwmapi.dll` and `override.txt` from `Binaries\Win64`, and the UE4SS files you copied (`UE4SS.dll`,
`UE4SS-settings.ini`, `LuaMods`, `UE4SS.log`). In the standard layout, delete `dwmapi.dll` and the `ue4ss` folder.

The Unreal project (to inspect how the map is set up) is in the ITR Showcase repo this zip was built from.
