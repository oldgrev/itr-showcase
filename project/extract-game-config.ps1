<#
.SYNOPSIS
  Copies the game's DefaultEngine.ini (render settings, navmesh agents, collision channels) into this project's Config\.
  It is inside the game's pakchunk0; UnrealPak (comes with every editor) extracts it in about a second.
.EXAMPLE
  .\extract-game-config.ps1 -Engine "C:\ue427\Engine"
  .\extract-game-config.ps1 -Engine "C:\Program Files\Epic Games\UE_4.27\Engine"
#>
param(
    [Parameter(Mandatory)][string]$Engine,
    [string]$GameDir = "C:\Program Files (x86)\Steam\steamapps\common\IntoTheRadius"
)
$ErrorActionPreference = "Stop"
$Pak = Join-Path $GameDir "IntoTheRadius\Content\Paks\pakchunk0-WindowsNoEditor.pak"
$Tmp = Join-Path $env:TEMP "itr-config"
Remove-Item $Tmp -Recurse -Force -ErrorAction SilentlyContinue
& (Join-Path $Engine "Binaries\Win64\UnrealPak.exe") $Pak -Extract $Tmp "-Filter=*Config/Default*.ini" | Out-Null
if ($LASTEXITCODE -ne 0) { throw "UnrealPak failed ($LASTEXITCODE)" }
$Src = Join-Path $Tmp "IntoTheRadius\Config"
Copy-Item (Join-Path $Src "DefaultEngine.ini") (Join-Path $PSScriptRoot "Config\DefaultEngine.ini") -Force
Write-Host "Config\DefaultEngine.ini copied from the game."
$v = Select-String -Path (Join-Path $Src "DefaultGame.ini") -Pattern "^ProjectVersion=" | Select-Object -First 1
Write-Host "Game $($v.Line)  (this guide targets 2.7.2)"
