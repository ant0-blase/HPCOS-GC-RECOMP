param(
    [switch]$Bootstrap,
    [ValidateSet("Release", "RelWithDebInfo")][string]$Configuration = "Release",
    [int]$Jobs = 8
)
$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $Root

function Need($name) { return -not (Get-Command $name -ErrorAction SilentlyContinue) }
if ($Bootstrap) {
    if (Need "winget") { throw "winget is required for -Bootstrap" }
    if (Need "cmake") { winget install -e --id Kitware.CMake --accept-source-agreements --accept-package-agreements }
    if (Need "ninja") { winget install -e --id Ninja-build.Ninja --accept-source-agreements --accept-package-agreements }
    if (Need "clang") { winget install -e --id LLVM.LLVM --accept-source-agreements --accept-package-agreements }
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (-not (Test-Path $vswhere)) {
        winget install Microsoft.VisualStudio.2022.Community --override "--quiet --wait --add Microsoft.VisualStudio.Workload.NativeDesktop --includeRecommended" --accept-source-agreements --accept-package-agreements
    }
}
foreach ($tool in @("cmake", "ninja", "clang", "clang++")) { if (Need $tool) { throw "Missing $tool. Run .\\build-windows.ps1 -Bootstrap first." } }

# Import the MSVC/Windows SDK environment while still compiling with Clang.
$vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path $vswhere)) { throw "Visual Studio C++ build tools are missing. Run .\\build-windows.ps1 -Bootstrap." }
$vs = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (-not $vs) { throw "Visual Studio Desktop C++ workload is missing. Run .\\build-windows.ps1 -Bootstrap." }
$vsDevCmd = Join-Path $vs "Common7\Tools\VsDevCmd.bat"
$envDump = & cmd.exe /s /c "`"$vsDevCmd`" -no_logo -arch=x64 -host_arch=x64 && set"
foreach ($line in $envDump) {
    $eq = $line.IndexOf('=')
    if ($eq -gt 0) { [Environment]::SetEnvironmentVariable($line.Substring(0,$eq), $line.Substring($eq+1), 'Process') }
}

$Dol = Join-Path $Root "extracted\sys\main.dol"
if (-not (Test-Path $Dol)) { throw "Missing extracted\\sys\\main.dol" }
$Expected = "45ee05b836e44ff8861ad12323185b1b96928488937ee131f061b8d753d0c452"
$Actual = (Get-FileHash -Algorithm SHA256 $Dol).Hash.ToLowerInvariant()
if ($Actual -ne $Expected) { throw "GHSE69 main.dol SHA-256 mismatch" }

$Build = Join-Path $Root "build\windows"
$Port = Join-Path $Root "port-build-windows"
New-Item -ItemType Directory -Force $Build,$Port | Out-Null

cmake -S ModernGekko -B $Build -G Ninja `
    -DCMAKE_BUILD_TYPE=$Configuration `
    -DCMAKE_C_COMPILER=clang `
    -DCMAKE_CXX_COMPILER=clang++ `
    -DCMAKE_C_FLAGS_RELEASE="-O3 -march=x86-64-v3 -ffp-contract=off -fno-fast-math" `
    -DCMAKE_CXX_FLAGS_RELEASE="-O3 -march=x86-64-v3 -ffp-contract=off -fno-fast-math" `
    -DMODERNGEKKO_ENABLE_DOLPHIN_RUNTIME=ON `
    -DMODERNGEKKO_ENABLE_DOLPHIN_TESTS=OFF `
    -DMODERNGEKKO_ENABLE_DYNAMIC_MODULES=ON `
    -DMODERNGEKKO_REQUIRED_DISC_ID=GHSE69 `
    -DMODERNGEKKO_REQUIRED_DOL_SHA256=$Expected `
    -DMODERNGEKKO_DEFAULT_WINDOW_TITLE="Harry Potter and the Chamber of Secrets" `
    -DMODERNGEKKO_PORTABLE_DEFAULT_GAME=ON `
    -DMODERNGEKKO_GAMECUBE_CONTROLLERS=ON `
    -DENABLE_LTO=ON
if ($LASTEXITCODE) { exit $LASTEXITCODE }
cmake --build $Build --target moderngekko-run moderngekko-port dolrecomp --parallel $Jobs
if ($LASTEXITCODE) { exit $LASTEXITCODE }

& "$Build\moderngekko-port.exe" build "$Root\extracted" --backend c --toolchain clang --output $Port
if ($LASTEXITCODE) { exit $LASTEXITCODE }

$Pointer = Join-Path $Port "GHSE69\active-module.txt"
if (-not (Test-Path $Pointer)) { throw "active-module.txt was not generated" }
$ModuleSource = (Get-Content $Pointer -Raw).Trim()
if (-not [IO.Path]::IsPathRooted($ModuleSource)) { $ModuleSource = Join-Path $Root $ModuleSource }
if (-not (Test-Path $ModuleSource)) { throw "Generated module missing: $ModuleSource" }

$Publish = Join-Path $Root "dist\windows"
if (Test-Path $Publish) { Remove-Item -Recurse -Force $Publish }
New-Item -ItemType Directory -Force $Publish | Out-Null
Copy-Item "$Build\moderngekko-run.exe" $Publish
Copy-Item $ModuleSource (Join-Path $Publish "gGHSE69_recomp.dll")
if (Test-Path "$Build\Sys") { Copy-Item -Recurse "$Build\Sys" $Publish }
Set-Content -NoNewline (Join-Path $Publish "default-game.txt") "..\..\extracted"

# Copy runtime DLL dependencies that live beside LLVM/MinGW binaries when present.
$llvmBin = Split-Path (Get-Command clang).Source -Parent
foreach ($dll in @("libc++.dll", "libunwind.dll", "libwinpthread-1.dll")) {
    $candidate = Join-Path $llvmBin $dll
    if (Test-Path $candidate) { Copy-Item $candidate $Publish }
}
Write-Host "Windows package: $Publish"
