param([Parameter(ValueFromRemainingArguments=$true)][string[]]$Args)
$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$Dist = Join-Path $Root "dist\windows"
$Exe = Join-Path $Dist "moderngekko-run.exe"
if (-not (Test-Path $Exe)) { throw "Build first with .\\build-windows.ps1" }
$env:STATICRECOMP_MODULE = Join-Path $Dist "gGHSE69_recomp.dll"
$env:HPCOS_PC_EDITION = "1"
& $Exe --game (Join-Path $Root "extracted") --module $env:STATICRECOMP_MODULE @Args
exit $LASTEXITCODE
