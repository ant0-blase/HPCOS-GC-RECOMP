param(
    [switch]$Bootstrap,
    [switch]$Clean,
    [switch]$KeepScratch,
    [ValidateSet("Release", "RelWithDebInfo")]
    [string]$Configuration = "Release",
    [ValidateRange(1, 64)]
    [int]$Jobs = 12
)

$ErrorActionPreference = "Stop"
$BuildId = "HPCOS-WINDOWS-MSVC-FINAL-20260822"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $Root

Write-Host ""
Write-Host "================================================================"
Write-Host (" {0}" -f $BuildId)
Write-Host " COMPLETE WINDOWS BUILD: HOST + GHSE69 MODULE + PACKAGE"
Write-Host "================================================================"
Write-Host ""

function Need([string]$Name) {
    return -not (Get-Command $Name -ErrorAction SilentlyContinue)
}

function Run([string]$Exe, [string[]]$CommandArgs) {
    Write-Host ("[HPCOS/FINAL] {0} {1}" -f $Exe, ($CommandArgs -join " "))
    & $Exe @CommandArgs
    if ($LASTEXITCODE -ne 0) {
        throw ("{0} failed with exit code {1}" -f $Exe, $LASTEXITCODE)
    }
}

function Refresh-ProcessPath {
    $machine = [Environment]::GetEnvironmentVariable("Path", "Machine")
    $user = [Environment]::GetEnvironmentVariable("Path", "User")
    $env:Path = (($machine, $user) -join ";")
}

function Import-VsDevEnvironment {
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (-not (Test-Path -LiteralPath $vswhere)) {
        throw "Visual Studio Installer/vswhere.exe not found. Run this script with -Bootstrap."
    }

    $vs = & $vswhere -latest -products * `
        -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
        -property installationPath

    if (-not $vs) {
        throw "Visual Studio 2022 Desktop C++ workload not found. Run this script with -Bootstrap."
    }

    $vsDevCmd = Join-Path $vs "Common7\Tools\VsDevCmd.bat"
    if (-not (Test-Path -LiteralPath $vsDevCmd)) {
        throw ("VsDevCmd.bat not found: {0}" -f $vsDevCmd)
    }

    $envDump = & cmd.exe /d /s /c "`"$vsDevCmd`" -no_logo -arch=x64 -host_arch=x64 && set"
    foreach ($line in $envDump) {
        $eq = $line.IndexOf("=")
        if ($eq -gt 0) {
            [Environment]::SetEnvironmentVariable(
                $line.Substring(0, $eq),
                $line.Substring($eq + 1),
                "Process"
            )
        }
    }
}

function Resolve-RealPython {
    $commands = @(
        'python -c "import sys;print(sys.executable)"',
        'py -3 -c "import sys;print(sys.executable)"'
    )

    foreach ($command in $commands) {
        $result = & cmd.exe /d /s /c $command 2>$null
        if ($LASTEXITCODE -eq 0 -and $result) {
            $candidate = ($result | Select-Object -Last 1).Trim()
            if ($candidate -and (Test-Path -LiteralPath $candidate)) {
                return $candidate
            }
        }
    }

    $roots = @(
        (Join-Path $env:LocalAppData "Programs\Python"),
        $env:ProgramFiles,
        ${env:ProgramFiles(x86)}
    )

    foreach ($scanRoot in $roots) {
        if (-not $scanRoot -or -not (Test-Path -LiteralPath $scanRoot)) {
            continue
        }

        $candidate = Get-ChildItem -Path $scanRoot -Filter "python.exe" -File -Recurse -ErrorAction SilentlyContinue |
            Where-Object { $_.FullName -notmatch "\\WindowsApps\\" } |
            Sort-Object LastWriteTime -Descending |
            Select-Object -First 1 -ExpandProperty FullName

        if ($candidate) {
            return $candidate
        }
    }

    throw "No working Python interpreter found. Run this script with -Bootstrap."
}

function Find-BuiltExe([string]$BuildRoot, [string]$Name) {
    $direct = Join-Path $BuildRoot $Name
    if (Test-Path -LiteralPath $direct) {
        return $direct
    }

    return Get-ChildItem -Path $BuildRoot -Filter $Name -File -Recurse -ErrorAction SilentlyContinue |
        Select-Object -First 1 -ExpandProperty FullName
}

function Find-FreeSubstDrive {
    foreach ($letter in @("R","Q","P","O","N","M","L","K","J","I")) {
        if (-not (Test-Path ("{0}:\" -f $letter))) {
            return $letter
        }
    }
    throw "No free drive letter is available for the short-path module build."
}

function Ensure-DolphinPchDisabled {
    param([string]$PchCmake)

    if (-not (Test-Path -LiteralPath $PchCmake)) {
        throw ("Dolphin PCH CMake file not found: {0}" -f $PchCmake)
    }

    $text = [System.IO.File]::ReadAllText($PchCmake)

    # Dolphin explicitly documents return() at this location as the switch to
    # disable its non-standard shared MSVC PCH. This avoids C1853 when a C
    # translation unit is injected into Dolphin's core target.
    if ($text -match '(?m)^\s*return\s*\(\s*\)\s*$') {
        Write-Host "[HPCOS/FINAL] Dolphin shared PCH already disabled."
        return
    }

    if ($text.Contains("#return()")) {
        $text = $text.Replace("#return()", "return()")
    }
    else {
        $needle = "add_library(use_pch INTERFACE)"
        $pos = $text.IndexOf($needle, [System.StringComparison]::Ordinal)
        if ($pos -lt 0) {
            throw "Could not find Dolphin use_pch target. PCH fix was not applied."
        }
        $insertAt = $pos + $needle.Length
        $text = $text.Insert(
            $insertAt,
            [Environment]::NewLine + [Environment]::NewLine + "return()"
        )
    }

    [System.IO.File]::WriteAllText(
        $PchCmake,
        $text,
        [System.Text.UTF8Encoding]::new($false)
    )

    Write-Host "[HPCOS/FINAL] Dolphin shared PCH disabled."
}

function Ensure-ModernGekkoWindowsLinkFix {
    param([string]$CMakeFile)

    if (-not (Test-Path -LiteralPath $CMakeFile)) {
        throw ("ModernGekko CMakeLists.txt not found: {0}" -f $CMakeFile)
    }

    $text = [System.IO.File]::ReadAllText($CMakeFile)
    $tag = "# HPCOS_MSVC_LINK_FIX_FINAL"

    if ($text.Contains($tag)) {
        Write-Host "[HPCOS/FINAL] DX11/DX12 + LTCG source fix already present."
        return
    }

    # Accept the previous R2 fix as equivalent and do not duplicate it.
    if ($text.Contains("# HPCOS_MSVC_LINK_FIX_R2")) {
        Write-Host "[HPCOS/FINAL] Existing R2 DX11/DX12 + LTCG source fix detected."
        return
    }

    $pattern = '(?ms)([ \t]*target_link_libraries\s*\(\s*moderngekko-run\s+PRIVATE\s*\r?\n[ \t]*ModernGekko::Runtime\s+core\s+uicommon\s+imgui\s+\$\{_moderngekko_sdl_target\}\s*\))'
    $match = [regex]::Match($text, $pattern)

    if (-not $match.Success) {
        throw "Could not locate moderngekko-run target_link_libraries block. No CMake source was changed."
    }

    $fix = @'

    # HPCOS_MSVC_LINK_FIX_FINAL
    # Dolphin creates Core before VideoBackends. The Core-side TARGET checks for
    # videod3d/videod3d12 therefore happen too early. ModernGekko is configured
    # after Dolphin, so attach the actual Windows backends here.
    if(WIN32 AND MSVC)
        if(NOT TARGET videod3d OR NOT TARGET videod3d12)
            message(FATAL_ERROR "HPCOS: Dolphin DX11/DX12 targets are missing")
        endif()

        target_link_libraries(moderngekko-run PRIVATE
            videod3d
            videod3d12)

        # Dolphin static objects use /GL with ENABLE_LTO. Consume them with a
        # real LTCG final link instead of relying on link.exe to restart itself.
        target_link_options(moderngekko-run PRIVATE
            /LTCG
            /OPT:REF
            /OPT:ICF)

        message(STATUS "HPCOS: moderngekko-run -> DX11 + DX12 + /LTCG")
    endif()
'@

    $replacement = $match.Value + $fix
    $text = $text.Remove($match.Index, $match.Length).Insert($match.Index, $replacement)

    [System.IO.File]::WriteAllText(
        $CMakeFile,
        $text,
        [System.Text.UTF8Encoding]::new($false)
    )

    Write-Host "[HPCOS/FINAL] Applied DX11/DX12 + LTCG source fix."
}

# ---------------------------------------------------------------------------
# 1. Bootstrap / toolchain
# ---------------------------------------------------------------------------
if ($Bootstrap) {
    if (Need "winget") {
        throw "winget is required for -Bootstrap."
    }

    if (Need "cmake") {
        winget install -e --id Kitware.CMake `
            --accept-source-agreements --accept-package-agreements
    }

    if (Need "ninja") {
        winget install -e --id Ninja-build.Ninja `
            --accept-source-agreements --accept-package-agreements
    }

    $pythonWorks = $false
    try {
        & cmd.exe /d /s /c 'python -c "import sys;print(sys.version)"' *> $null
        $pythonWorks = ($LASTEXITCODE -eq 0)
    }
    catch {
        $pythonWorks = $false
    }

    if (-not $pythonWorks) {
        winget install -e --id Python.Python.3.14 `
            --accept-source-agreements --accept-package-agreements
    }

    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    $needVs = -not (Test-Path -LiteralPath $vswhere)

    if (-not $needVs) {
        $vs = & $vswhere -latest -products * `
            -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
            -property installationPath
        $needVs = -not $vs
    }

    if ($needVs) {
        winget install Microsoft.VisualStudio.2022.Community `
            --override "--quiet --wait --add Microsoft.VisualStudio.Workload.NativeDesktop --includeRecommended" `
            --accept-source-agreements --accept-package-agreements
    }

    Refresh-ProcessPath
}

Import-VsDevEnvironment
Refresh-ProcessPath
# Re-import VS after PATH refresh so VS tools stay first and SDK variables stay set.
Import-VsDevEnvironment

foreach ($tool in @("cmake", "ninja", "cl", "link")) {
    if (Need $tool) {
        throw ("Required tool missing: {0}. Run with -Bootstrap." -f $tool)
    }
}

$Python = Resolve-RealPython
$PythonDir = Split-Path -Parent $Python
$env:PATH = "$PythonDir;$env:PATH"

$ClPath = (Get-Command cl).Source
$LinkPath = (Get-Command link).Source
$NinjaPath = (Get-Command ninja).Source
$ClVersion = (Get-Item -LiteralPath $ClPath).VersionInfo.ProductVersion

Write-Host "[HPCOS/FINAL] Toolchain"
Write-Host ("[HPCOS/FINAL] MSVC     = {0}" -f $ClVersion)
Write-Host ("[HPCOS/FINAL] cl.exe   = {0}" -f $ClPath)
Write-Host ("[HPCOS/FINAL] link.exe = {0}" -f $LinkPath)
Write-Host ("[HPCOS/FINAL] ninja    = {0}" -f $NinjaPath)
Write-Host ("[HPCOS/FINAL] python   = {0}" -f $Python)
Write-Host ""

# ---------------------------------------------------------------------------
# 2. Validate game / paths
# ---------------------------------------------------------------------------
$ModernGekko = Join-Path $Root "ModernGekko"
$ModernGekkoCMake = Join-Path $ModernGekko "CMakeLists.txt"
$DolphinPchCMake = Join-Path $ModernGekko "vendor\dolphin\Source\PCH\CMakeLists.txt"
$Dol = Join-Path $Root "extracted\sys\main.dol"

if (-not (Test-Path -LiteralPath $ModernGekkoCMake)) {
    throw "ModernGekko\CMakeLists.txt is missing."
}

if (-not (Test-Path -LiteralPath $Dol)) {
    throw "extracted\sys\main.dol is missing."
}

$ExpectedDolHash = "45ee05b836e44ff8861ad12323185b1b96928488937ee131f061b8d753d0c452"
$ActualDolHash = (Get-FileHash -Algorithm SHA256 $Dol).Hash.ToLowerInvariant()

if ($ActualDolHash -ne $ExpectedDolHash) {
    throw ("GHSE69 main.dol SHA-256 mismatch: {0}" -f $ActualDolHash)
}

Write-Host "[HPCOS/FINAL] GHSE69 main.dol verified."

# ---------------------------------------------------------------------------
# 3. Permanent Windows source fixes, idempotent
# ---------------------------------------------------------------------------
Ensure-DolphinPchDisabled -PchCmake $DolphinPchCMake
Ensure-ModernGekkoWindowsLinkFix -CMakeFile $ModernGekkoCMake

# ---------------------------------------------------------------------------
# 4. Host MSVC configure + build
# ---------------------------------------------------------------------------
$Build = Join-Path $Root "build\windows-msvc"
$Publish = Join-Path $Root "dist\windows"
$Zip = Join-Path $Root "dist\HPCOS-GC-RECOMP-Windows-MSVC.zip"

if ($Clean -and (Test-Path -LiteralPath $Build)) {
    Write-Host ("[HPCOS/FINAL] Removing host build cache: {0}" -f $Build)
    Remove-Item -Recurse -Force $Build
}

New-Item -ItemType Directory -Force $Build | Out-Null

# _CL_ is appended after ordinary cl.exe command-line options, so /WX- wins
# over upstream /WX. Suppress only known noisy informational warnings.
$OldCLTail = $env:_CL_
$env:_CL_ = "/WX- /wd4711 /wd5045 /wd5049"

try {
    $CFlagsRelease = "/O2 /arch:AVX2 /DNDEBUG /wd4711 /wd5045 /wd5049"
    $CxxFlagsRelease = "/O2 /arch:AVX2 /DNDEBUG /wd4711 /wd5045 /wd5049"
    $CFlagsRelDbg = "/O2 /arch:AVX2 /DNDEBUG /Zi /wd4711 /wd5045 /wd5049"
    $CxxFlagsRelDbg = "/O2 /arch:AVX2 /DNDEBUG /Zi /wd4711 /wd5045 /wd5049"

    $CMakeArgs = @(
        "-S", $ModernGekko,
        "-B", $Build,
        "-G", "Ninja",
        "-Wno-dev",
        "-DCMAKE_BUILD_TYPE:STRING=$Configuration",
        "-DCMAKE_C_COMPILER:FILEPATH=$ClPath",
        "-DCMAKE_CXX_COMPILER:FILEPATH=$ClPath",
        "-DCMAKE_MAKE_PROGRAM:FILEPATH=$NinjaPath",
        "-DPython3_EXECUTABLE:FILEPATH=$Python",
        "-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES:STRING=",
        "-DCMAKE_MSVC_RUNTIME_LIBRARY:STRING=MultiThreadedDLL",
        "-DCMAKE_C_FLAGS_RELEASE:STRING=$CFlagsRelease",
        "-DCMAKE_CXX_FLAGS_RELEASE:STRING=$CxxFlagsRelease",
        "-DCMAKE_C_FLAGS_RELWITHDEBINFO:STRING=$CFlagsRelDbg",
        "-DCMAKE_CXX_FLAGS_RELWITHDEBINFO:STRING=$CxxFlagsRelDbg",
        "-DMODERNGEKKO_ENABLE_DOLPHIN_RUNTIME:BOOL=ON",
        "-DMODERNGEKKO_ENABLE_DOLPHIN_TESTS:BOOL=OFF",
        "-DMODERNGEKKO_ENABLE_DYNAMIC_MODULES:BOOL=ON",
        "-DMODERNGEKKO_REQUIRED_DISC_ID:STRING=GHSE69",
        "-DMODERNGEKKO_REQUIRED_DOL_SHA256:STRING=$ExpectedDolHash",
        "-DMODERNGEKKO_DEFAULT_WINDOW_TITLE:STRING=Harry Potter and the Chamber of Secrets",
        "-DMODERNGEKKO_PORTABLE_DEFAULT_GAME:BOOL=ON",
        "-DMODERNGEKKO_GAMECUBE_CONTROLLERS:BOOL=ON",
        "-DUSE_SYSTEM_LIBS:STRING=OFF",
        "-DENABLE_LTO:BOOL=ON"
    )

    Run "cmake" $CMakeArgs

    # Verify the final link graph before spending time in Ninja.
    $BuildNinja = Join-Path $Build "build.ninja"
    if (-not (Test-Path -LiteralPath $BuildNinja)) {
        throw "CMake did not generate build.ninja."
    }

    $NinjaGraph = [System.IO.File]::ReadAllText($BuildNinja)

    foreach ($needle in @("videod3d.lib", "videod3d12.lib")) {
        if ($NinjaGraph -notmatch [regex]::Escape($needle)) {
            throw ("CMake graph verification failed: {0} is missing." -f $needle)
        }
    }

    if ($NinjaGraph -notmatch "/LTCG") {
        throw "CMake graph verification failed: /LTCG is missing."
    }

    Write-Host "[HPCOS/FINAL] VERIFIED host graph: DX11 + DX12 + /LTCG."

    # Build the graphics libraries explicitly first so a Windows backend error
    # fails early, then build the three required host binaries.
    Run "cmake" @(
        "--build", $Build,
        "--target", "videod3d", "videod3d12",
        "--parallel", "$Jobs"
    )

    Run "cmake" @(
        "--build", $Build,
        "--target", "moderngekko-run", "moderngekko-port", "dolrecomp",
        "--parallel", "$Jobs"
    )

    $RunExe = Find-BuiltExe $Build "moderngekko-run.exe"
    $PortExe = Find-BuiltExe $Build "moderngekko-port.exe"
    $DolRecompExe = Find-BuiltExe $Build "dolrecomp.exe"

    if (-not $RunExe) { throw "moderngekko-run.exe was not produced." }
    if (-not $PortExe) { throw "moderngekko-port.exe was not produced." }
    if (-not $DolRecompExe) { throw "dolrecomp.exe was not produced." }

    Write-Host "[HPCOS/FINAL] HOST BUILD OK."
    Write-Host ("[HPCOS/FINAL] runner    = {0}" -f $RunExe)
    Write-Host ("[HPCOS/FINAL] port      = {0}" -f $PortExe)
    Write-Host ("[HPCOS/FINAL] dolrecomp = {0}" -f $DolRecompExe)

    # -----------------------------------------------------------------------
    # 5. GHSE69 MSVC module using a short subst path
    # -----------------------------------------------------------------------
    # moderngekko-port creates:
    #   output\GHSE69\<DOL-hash>-<identity-hash>\dolrecomp-output\generated\...
    # The normal repository path exceeded Windows MAX_PATH during chunks/
    # creation. A subst drive keeps the same build logic while making every
    # generated path short.
    $PhysicalScratch = Join-Path $env:TEMP "HPCOSMG-FINAL"
    if (Test-Path -LiteralPath $PhysicalScratch) {
        Remove-Item -Recurse -Force $PhysicalScratch
    }
    New-Item -ItemType Directory -Force $PhysicalScratch | Out-Null

    $DriveLetter = Find-FreeSubstDrive
    $Drive = "${DriveLetter}:"
    $ShortOutput = "${Drive}\M"

    Write-Host ("[HPCOS/FINAL] Short module path: {0} -> {1}" -f $Drive, $PhysicalScratch)

    & subst $Drive $PhysicalScratch
    if ($LASTEXITCODE -ne 0) {
        throw "subst failed while creating the short module-build drive."
    }

    try {
        New-Item -ItemType Directory -Force $ShortOutput | Out-Null

        $env:CC = $ClPath
        $env:CXX = $ClPath
        $env:MODERNGEKKO_BUILD_JOBS = [string]([Math]::Min([Math]::Max($Jobs, 1), 4))

        # Stable Windows module profile. Fastmem remains OFF because the current
        # recovery table is ELF-oriented and does not yet have a Windows/COFF
        # implementation. Everything else stays on: optimization level 3,
        # MEM1-only decoder, no write journal, no stack-protector request.
        $env:HPCOS_MODULE_OPT = "3"
        $env:HPCOS_MODULE_MEM1_ONLY = "1"
        $env:HPCOS_MODULE_MEM_JOURNAL = "0"
        $env:HPCOS_MODULE_STACK_PROTECTOR = "0"
        $env:HPCOS_MODULE_FASTMEM = "0"

        # moderngekko-port records environment in its build identity and then
        # deliberately cleans compiler flags before module CMake. Keep that
        # identity deterministic and avoid leaking host /WX flags.
        Remove-Item Env:_CL_ -ErrorAction SilentlyContinue
        Remove-Item Env:CL -ErrorAction SilentlyContinue
        Remove-Item Env:LINK -ErrorAction SilentlyContinue

        Run $PortExe @(
            "build",
            (Join-Path $Root "extracted"),
            "--backend", "c",
            "--toolchain", "msvc",
            "--output", $ShortOutput
        )

        $ModuleDll = Get-ChildItem -Path $ShortOutput -Filter "gGHSE69_recomp.dll" -File -Recurse -ErrorAction SilentlyContinue |
            Sort-Object LastWriteTime -Descending |
            Select-Object -First 1 -ExpandProperty FullName

        if (-not $ModuleDll -or -not (Test-Path -LiteralPath $ModuleDll)) {
            throw "GHSE69 MSVC module build finished without producing gGHSE69_recomp.dll."
        }

        Write-Host ("[HPCOS/FINAL] MODULE BUILD OK: {0}" -f $ModuleDll)

        # -------------------------------------------------------------------
        # 6. Package
        # -------------------------------------------------------------------
        if (Test-Path -LiteralPath $Publish) {
            Remove-Item -Recurse -Force $Publish
        }
        New-Item -ItemType Directory -Force $Publish | Out-Null

        Copy-Item -LiteralPath $RunExe -Destination (Join-Path $Publish "moderngekko-run.exe")
        Copy-Item -LiteralPath $ModuleDll -Destination (Join-Path $Publish "gGHSE69_recomp.dll")

        $Sys = Join-Path $Build "Sys"
        if (-not (Test-Path -LiteralPath $Sys)) {
            throw "The host build did not produce its Sys directory."
        }
        Copy-Item -LiteralPath $Sys -Destination $Publish -Recurse

        Set-Content -LiteralPath (Join-Path $Publish "default-game.txt") `
            -NoNewline "..\..\extracted"

        $RunBat = @'
@echo off
setlocal
cd /d "%~dp0"
moderngekko-run.exe --game "..\..\extracted" --module "gGHSE69_recomp.dll" %*
endlocal
'@
        [System.IO.File]::WriteAllText(
            (Join-Path $Publish "run-windows.bat"),
            $RunBat,
            [System.Text.ASCIIEncoding]::new()
        )

        $RunnerHash = (Get-FileHash -Algorithm SHA256 (Join-Path $Publish "moderngekko-run.exe")).Hash.ToLowerInvariant()
        $ModuleHash = (Get-FileHash -Algorithm SHA256 (Join-Path $Publish "gGHSE69_recomp.dll")).Hash.ToLowerInvariant()

        $BuildInfo = @"
HPCOS-GC-RECOMP Windows build
Build ID: $BuildId
Configuration: $Configuration
Compiler: MSVC $ClVersion
Architecture: x64 / AVX2
Host LTO: /GL + /LTCG
Video backends: DX11 + DX12
Game: GHSE69
DOL SHA256: $ActualDolHash
Module backend: C static recompilation
Module toolchain: MSVC
Module fastmem: OFF (Windows/COFF recovery support pending)
moderngekko-run.exe SHA256: $RunnerHash
gGHSE69_recomp.dll SHA256: $ModuleHash
"@

        [System.IO.File]::WriteAllText(
            (Join-Path $Publish "BUILD-INFO.txt"),
            $BuildInfo,
            [System.Text.UTF8Encoding]::new($false)
        )

        if (Test-Path -LiteralPath $Zip) {
            Remove-Item -Force $Zip
        }
        New-Item -ItemType Directory -Force (Split-Path -Parent $Zip) | Out-Null
        Compress-Archive -Path (Join-Path $Publish "*") -DestinationPath $Zip -CompressionLevel Optimal

        if (-not (Test-Path -LiteralPath $Zip)) {
            throw "Final ZIP package was not produced."
        }

        $ZipHash = (Get-FileHash -Algorithm SHA256 $Zip).Hash.ToLowerInvariant()

        Write-Host ""
        Write-Host "================================================================"
        Write-Host " HPCOS WINDOWS MSVC FINAL BUILD COMPLETE"
        Write-Host "================================================================"
        Write-Host " Host:"
        Write-Host "   moderngekko-run.exe : OK"
        Write-Host "   moderngekko-port.exe: OK"
        Write-Host "   dolrecomp.exe        : OK"
        Write-Host " Module:"
        Write-Host "   gGHSE69_recomp.dll   : OK"
        Write-Host " Package:"
        Write-Host ("   directory            : {0}" -f $Publish)
        Write-Host ("   zip                  : {0}" -f $Zip)
        Write-Host ("   runner SHA256        : {0}" -f $RunnerHash)
        Write-Host ("   module SHA256        : {0}" -f $ModuleHash)
        Write-Host ("   zip SHA256           : {0}" -f $ZipHash)
        Write-Host "================================================================"
    }
    finally {
        if ($Drive) {
            Write-Host ("[HPCOS/FINAL] Removing temporary drive {0}" -f $Drive)
            & subst $Drive /D *> $null
        }

        if (-not $KeepScratch -and (Test-Path -LiteralPath $PhysicalScratch)) {
            Remove-Item -Recurse -Force $PhysicalScratch -ErrorAction SilentlyContinue
        }
    }
}
finally {
    if ($null -eq $OldCLTail) {
        Remove-Item Env:_CL_ -ErrorAction SilentlyContinue
    }
    else {
        $env:_CL_ = $OldCLTail
    }
}
