<#
.SYNOPSIS
  Packs the map's level gameplay tag into a small pak (no cook): zzz_ITRMap_<Map>_Tags_P.pak.
.DESCRIPTION
  A save stores every gameplay tag as its name and turns the name back into a tag on load. A tag the game has not registered
  comes back empty, so a save made in the map would lose its level and Continue would open the Hub. The game reads every tag
  ini under IntoTheRadius/Config/Tags/ at startup, so one line in a tag ini (packed into a pak that mounts there) registers
  the tag.

  The tag is read from NativeTag in the loader's config.lua (default Level.Zone.<Map>, as the loader does), or pass -Tag.
  The ini is generated into build\tags\. Its file name is unique on purpose: a pak file at the same path as a game file
  replaces it, and LevelGameplayTags.ini is the stock list of level tags.
.EXAMPLE
  .\build-tags.ps1 -Engine "C:\ue427\Engine"             # -> build\zzz_ITRMap_ItrShowcase_Tags_P.pak
  .\build-tags.ps1 -Engine "C:\ue427\Engine" -Install    # also copy it to <game>\IntoTheRadius\Content\Paks\~mods
#>
param(
    [Parameter(Mandatory)][string]$Engine,
    [string]$Map = "ItrShowcase",
    [string]$Tag = "",
    [string]$Config = "",
    [string]$GameDir = "C:\Program Files (x86)\Steam\steamapps\common\IntoTheRadius",
    [switch]$Install
)
$ErrorActionPreference = "Stop"
$OutDir  = Join-Path $PSScriptRoot "build"
$TagDir  = Join-Path $OutDir "tags"
$PakName = "zzz_ITRMap_$($Map)_Tags_P.pak"
$Pak     = Join-Path $OutDir $PakName
$IniName = "$($Map)LevelTags.ini"
$Ini     = Join-Path $TagDir $IniName
$resp    = Join-Path $OutDir "pak_tags.txt"
New-Item -ItemType Directory -Force $OutDir, $TagDir | Out-Null

if (-not $Tag) {
    if (-not $Config) { $Config = Join-Path $PSScriptRoot "..\loader\ItrShowcaseLoader\Scripts\config.lua" }
    if (-not (Test-Path $Config)) { throw "Loader config not found: $Config (pass -Tag)" }
    $m = [regex]::Match((Get-Content $Config -Raw), '(?m)^\s*NativeTag\s*=\s*"([^"]+)"')
    $Tag = if ($m.Success) { $m.Groups[1].Value } else { "Level.Zone.$Map" }
}
if ($Tag -notmatch '^[A-Za-z0-9_]+(\.[A-Za-z0-9_]+)+$') { throw "Not a gameplay tag name: '$Tag'" }

# the tag ini: ASCII, LF, no BOM
$text = "[/Script/GameplayTags.GameplayTagsList]`nGameplayTagList=(Tag=`"$Tag`",DevComment=`"$Map level; registered so a save made in the map keeps its level`")`n"
[IO.File]::WriteAllBytes($Ini, [Text.Encoding]::ASCII.GetBytes($text))
Write-Host "Tag $Tag -> $Ini"

"`"$Ini`" `"../../../IntoTheRadius/Config/Tags/$IniName`"" | Set-Content -Encoding ASCII $resp
& (Join-Path $Engine "Binaries\Win64\UnrealPak.exe") $Pak "-create=$resp" | Out-Null
if ($LASTEXITCODE -ne 0) { throw "UnrealPak failed ($LASTEXITCODE)" }
Write-Host "Packed -> $Pak"

if ($Install) {
    if (Get-Process "IntoTheRadius-Win64-Shipping" -ErrorAction SilentlyContinue) { throw "Close the game first (paks are mounted at startup)." }
    $Dest = Join-Path $GameDir "IntoTheRadius\Content\Paks\~mods"
    New-Item -ItemType Directory -Force $Dest | Out-Null
    Copy-Item $Pak $Dest -Force
    Write-Host "Installed -> $Dest\$PakName"
}
