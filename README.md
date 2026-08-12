# Harry Potter and the Chamber of Secrets — GameCube Static Recompilation

<p align="center">
  <img src="docs/screenshots/01-title-screen.png" alt="Harry Potter and the Chamber of Secrets running through HPCOS GC" width="900">
</p>

<p align="center">
  <strong>HPCOS GC</strong> — an experimental native static-recompilation project for
  <em>Harry Potter and the Chamber of Secrets</em> on Nintendo GameCube.
</p>

> [!IMPORTANT]
> **Work in progress.** No original disc image or extracted copyrighted game data is
> distributed by this repository. You must supply your own legally obtained copy of
> the game.

## Overview

**HPCOS GC** targets the North American GameCube release of
**Harry Potter and the Chamber of Secrets** (`GHSE69`).

The project uses the ExpansionPak GameCube/Wii recompilation stack, with
**DolRecomp** for ahead-of-time PowerPC recompilation and **ModernGekko** for the
native runtime.

The goal is to run the original GameCube executable as statically recompiled native
code while preserving the behaviour of the original game and progressively adding
PC-oriented improvements in the runtime.

## Current status

The game currently reaches and runs:

- title and menu flow
- loading screens
- in-game scenes and normal gameplay
- audio
- controller input
- save/runtime state
- Vulkan rendering through ModernGekko/Dolphin

The current native build targets the original NTSC game timing.

## PC enhancements

### Dynamic widescreen

HPCOS includes a runtime widescreen implementation rather than relying on a fixed
16:9 game patch.

The projection is adjusted dynamically from the actual host aspect ratio, allowing
the 3D view to adapt to displays such as:

- 16:9
- 16:10
- ultrawide aspect ratios
- other window aspect ratios

For wider displays the 3D projection uses a Hor+ style adjustment instead of simply
stretching the original 4:3 image.

Enable it with:

```bash
./run.sh --widescreen
```

### Configurable FOV

A horizontal FOV can be selected at launch:

```bash
./run.sh --widescreen --fov 110
```

`--fov` represents the requested **horizontal** field of view.

The renderer adjusts the host-side projection while the runtime also synchronizes
the corresponding game-side camera/frustum FOV used by `GHSE69`.

This is important because changing only the projection matrix causes objects near the
expanded edges of the screen to be incorrectly culled by the original game.

The game-side FOV synchronization greatly reduces this widescreen/FOV pop-in while
leaving the original game logic intact.

### XFB / presentation correction

The presentation path includes an XFB crop used to remove the original overscan-style
bordering and make better use of the host window while preserving the dynamically
corrected aspect ratio.

### HUD behaviour

The 3D projection and orthographic paths are handled separately so increasing the
world aspect ratio does not simply stretch the HUD together with the scene.

## Static recompilation and runtime work

HPCOS is not just a wrapper around an emulator.

The original GameCube PowerPC code is processed by DolRecomp and translated ahead of
time into native code that executes through the ModernGekko runtime.

Project-specific work currently includes:

- PowerPC static recompilation fixes and runtime integration
- optimized generated-code dispatch paths
- SMC / recompilation runtime optimizations
- optimized PowerPC emitter paths
- direct handling of common guest execution cases
- GameCube memory/MMIO/runtime integration
- guest-side camera/FOV synchronization
- host-side projection and presentation changes

The focus is to keep the recompiled execution path as native and lightweight as
possible while retaining compatibility with the original GameCube software.

## Screenshots

<table>
<tr>
<td align="center" width="50%"><img src="docs/screenshots/01-title-screen.png" alt="Title screen" width="100%"><br><sub>Title screen</sub></td>
<td align="center" width="50%"><img src="docs/screenshots/02-continue-menu.png" alt="Continue menu" width="100%"><br><sub>Continue menu</sub></td>
</tr>
<tr>
<td align="center" width="50%"><img src="docs/screenshots/03-loading-screen.png" alt="Loading screen" width="100%"><br><sub>Loading screen</sub></td>
<td align="center" width="50%"><img src="docs/screenshots/04-entrance-hall.png" alt="Entrance hall" width="100%"><br><sub>Entrance hall</sub></td>
</tr>
<tr>
<td align="center" width="50%"><img src="docs/screenshots/05-castle-yard.png" alt="Castle yard" width="100%"><br><sub>Castle yard</sub></td>
<td align="center" width="50%"><img src="docs/screenshots/06-harry-wand.png" alt="Harry with his wand" width="100%"><br><sub>Harry with his wand</sub></td>
</tr>
</table>

## Build layout

The checked-in project deliberately keeps the files required to reproduce or run the
current port:

```text
.
├── build.sh                  # configures/builds ModernGekko + DolRecomp + the GHSE69 module
├── run.sh                    # launches the published runtime/module
├── ModernGekko/              # source tree consumed by build.sh
├── DolRecomp/                # recompilation source/tooling
├── recomp/                   # HPCOS recompilation source/output
├── runtime/                  # published moderngekko-run + Sys runtime data
├── module/                   # published gGHSE69_recomp.so + build info
├── docs/screenshots/         # project screenshots
├── build/                    # local CMake/Ninja build directory — ignored
├── port-build/               # intermediate port build — ignored
├── extracted/                # user-supplied original game files — ignored
└── user/                     # local runtime profile/saves/configuration — ignored
```

`build.sh` validates the `GHSE69` `main.dol`, configures ModernGekko with CMake/Ninja,
builds `moderngekko-run`, `moderngekko-port` and `dolrecomp`, builds the recompilation
module, then publishes the runnable outputs into `runtime/` and `module/`.

`run.sh` launches:

- `runtime/moderngekko-run`
- `module/gGHSE69_recomp.so`
- the user's local `extracted/` game directory
- a local `user/` runtime directory

## Building

Requirements include CMake, Ninja, a supported C/C++ toolchain and the dependencies
required by ModernGekko/DolRecomp.

The current build script supports the `c` and `llvm` recompilation backends and
`clang`, `gcc` or automatic toolchain selection.

```bash
./build.sh
```

Examples:

```bash
BACKEND=c TOOLCHAIN=clang ./build.sh
BACKEND=llvm TOOLCHAIN=clang ./build.sh
```

The build expects your legally obtained game extraction at:

```text
extracted/sys/main.dol
```

The expected target is `GHSE69`; `build.sh` verifies the DOL before building.

## Running

Basic launch:

```bash
./run.sh
```

Dynamic widescreen:

```bash
./run.sh --widescreen
```

Dynamic widescreen with a custom horizontal FOV:

```bash
./run.sh --widescreen --fov 110
```

The current launcher uses Vulkan and Wayland.

## Experimental project

HPCOS GC is still under active development.

Rendering, recompilation accuracy, performance and game compatibility may change as
the static recompilation runtime continues to be investigated and optimized.

The project does **not** currently provide an unlocked-framerate implementation; the
original NTSC game timing is intentionally preserved.

## What is intentionally ignored

The `.gitignore` is intentionally conservative. It ignores things that should not be
part of the repository, including reproducible build directories, caches, release
staging, user-specific Dolphin/ModernGekko state, logs and original game files
supplied by the user.

Original game data must never be committed.

## Credits and acknowledgements

HPCOS GC depends on open-source work from the GameCube/Wii recompilation and emulation
communities.

### ExpansionPak

- **DolRecomp** — static PowerPC recompiler used by GameCube/Wii recompilation projects  
  https://github.com/ExpansionPak/DolRecomp
- **ModernGekko** — runtime and tooling used to execute recompiled GameCube/Wii code  
  https://github.com/ExpansionPak/ModernGekko

### Upstream acknowledgements

ModernGekko credits and builds on work including:

- **SpecialK / aharonahdoot** — RecompCore
- **The Dolphin Team** — Dolphin and the GameCube/Wii hardware/runtime knowledge base
- **Literally God / MrPoloGit** — recompilation template/macOS work credited upstream

Please consult the upstream repositories, contributor histories and license files for
complete and authoritative attribution.

## Legal

This is an unofficial research/fan project and is not affiliated with or endorsed by
Electronic Arts, Warner Bros., Nintendo, ExpansionPak, or the original developers.

No original disc image or extracted copyrighted game assets are distributed by this
repository. Users must provide their own legally obtained game data.

## License

See [`LICENSE`](LICENSE) for HPCOS-specific repository content.

Third-party components, including DolRecomp, ModernGekko and their dependencies,
remain subject to their respective licenses.
