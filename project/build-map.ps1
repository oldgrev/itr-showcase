<#
.SYNOPSIS
  Cooks a map from this project, packs only the /Game/Mods/<Map> packages into zzz_ITRMap_<Map>_P.pak and
  (optionally) installs it into the game.
.EXAMPLE
  .\build-map.ps1 -Engine "C:\ue427\Engine"                       # cook + pak /Game/Mods/ItrShowcase/L_ItrShowcase -> zzz_ITRMap_ItrShowcase_P.pak
  .\build-map.ps1 -Engine "C:\ue427\Engine" -Map Other -Install       # /Game/Mods/Other/L_Other, then copy into the game
#>
param(
    [Parameter(Mandatory)][string]$Engine,           # ...\Engine of the editor that built the map
    [string]$Map = "ItrShowcase",
    [string]$GameDir = "C:\Program Files (x86)\Steam\steamapps\common\IntoTheRadius",
    [switch]$Install
)
$ErrorActionPreference = "Stop"
$Project = Join-Path $PSScriptRoot "IntoTheRadius.uproject"
$OutDir  = Join-Path $PSScriptRoot "build"
$Cooked  = Join-Path $PSScriptRoot "Saved\Cooked\WindowsNoEditor\IntoTheRadius\Content\Mods\$Map"
$PakName = "zzz_ITRMap_$($Map)_P.pak"
$Pak     = Join-Path $OutDir $PakName
New-Item -ItemType Directory -Force $OutDir | Out-Null

# 1. Cook. -unversioned: the game's packages are unversioned. Old cooked files are removed first so assets the
#    map no longer uses aren't packed.
Remove-Item $Cooked -Recurse -Force -ErrorAction SilentlyContinue
$log = Join-Path $OutDir "cook_$Map.log"
Write-Host "Cooking /Game/Mods/$Map/L_$Map (log: $log)"
& (Join-Path $Engine "Binaries\Win64\UE4Editor-Cmd.exe") $Project -run=cook -targetplatform=WindowsNoEditor `
    "-map=/Game/Mods/$Map/L_$Map" -unversioned -unattended -NoLogTimes -abslog="$log" | Out-Null
if ($LASTEXITCODE -ne 0) { throw "Cook failed ($LASTEXITCODE); see $log" }

# 2. Response file: one line per file, "<file on disk>" "<path inside the game>". Only /Game/Mods/<Map>: anything
#    else in the cook output (engine content, game assets copied from the ITR-SDK) would override the game's files.
#    The stand-in host level (L_*Host) is editor-only and is left out.
$resp = Join-Path $OutDir "pak_$Map.txt"
$files = Get-ChildItem $Cooked -Recurse -File | Where-Object { $_.Name -notlike "L_*Host.*" }
$files | ForEach-Object {
    $rel = $_.FullName.Substring($Cooked.Length + 1) -replace '\\', '/'
    "`"$($_.FullName)`" `"../../../IntoTheRadius/Content/Mods/$Map/$rel`""
} | Set-Content -Encoding ASCII $resp
# e.g.  "C:\...\Saved\Cooked\...\Mods\Example\L_Example.umap" "../../../IntoTheRadius/Content/Mods/Example/L_Example.umap"

# 3. Pak (unsigned, uncompressed: the game loads unsigned paks)
& (Join-Path $Engine "Binaries\Win64\UnrealPak.exe") $Pak "-create=$resp" | Out-Null
if ($LASTEXITCODE -ne 0) { throw "UnrealPak failed ($LASTEXITCODE)" }
Write-Host "Packed $($files.Count) files -> $Pak"

# 4. The level tag pak: registers the map's level tag (NativeTag in the loader config) so a save made in the map keeps its level.
#    A separate pak, because a Config file would change this pak's mount point. Installed into ~mods (the map pak is not moved).
& (Join-Path $PSScriptRoot "build-tags.ps1") -Engine $Engine -Map $Map

if ($Install) {
    if (Get-Process "IntoTheRadius-Win64-Shipping" -ErrorAction SilentlyContinue) { throw "Close the game first (paks are mounted at startup)." }
    # T-165: install where the game loads it. When Paks\~mods\<pak> is a symlink (a mod manager's staging copy, e.g. Vortex), overwrite the link's TARGET and remove any loose
    # copy in Paks (two paks of one name = the loose one shadows or duplicates the staged one). Otherwise write the loose pak as before. No backup (the pak is ~500 MB).
    $Paks = Join-Path $GameDir "IntoTheRadius\Content\Paks"
    $Dest = Join-Path $Paks "~mods"
    function Get-InstallTarget([string]$Name) {
        $link = Get-Item -LiteralPath (Join-Path $Dest $Name) -Force -ErrorAction SilentlyContinue
        if ($link -and $link.LinkType -eq "SymbolicLink" -and $link.Target) {
            $t = [string](@($link.Target)[0])
            if (-not [IO.Path]::IsPathRooted($t)) { $t = [IO.Path]::GetFullPath((Join-Path $Dest $t)) }
            if (Test-Path -LiteralPath (Split-Path $t -Parent)) { return @{ Path = $t; Link = $link.FullName } }
            Write-Warning "$($link.FullName) is a symlink to $t but its folder is missing: writing a loose pak instead"
        }
        return @{ Path = (Join-Path $Paks $Name); Link = $null }
    }
    $tgt = Get-InstallTarget $PakName
    Copy-Item $Pak $tgt.Path -Force
    if ($tgt.Link) {
        Write-Host "Installed -> $($tgt.Path)  (target of the symlink $($tgt.Link))"
        $loose = Join-Path $Paks $PakName
        if (Test-Path -LiteralPath $loose) { Remove-Item -LiteralPath $loose -Force; Write-Host "Removed loose duplicate $loose" }
    } else { Write-Host "Installed -> $($tgt.Path)  (loose pak: no ~mods symlink)" }
    New-Item -ItemType Directory -Force $Dest | Out-Null
    $TagsName = "zzz_ITRMap_$($Map)_Tags_P.pak"
    $tt = Get-InstallTarget $TagsName
    Copy-Item (Join-Path $OutDir $TagsName) $(if ($tt.Link) { $tt.Path } else { $Dest }) -Force
    Write-Host "Installed -> $(if ($tt.Link) { $tt.Path } else { Join-Path $Dest $TagsName })"
}
