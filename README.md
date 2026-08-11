# Harry Potter and the Chamber of Secrets — GameCube Static Recompilation

<p align="center">
  <img src="docs/screenshots/01-title-screen.png" alt="Harry Potter and the Chamber of Secrets running through the HPCOS recompilation project" width="900">
</p>

> [!IMPORTANT]
> This project is an **experimental work in progress**. It does not distribute the original game, disc image, extracted assets, or other copyrighted game data. You must provide your own legally obtained copy of the GameCube game.

## About

**HPCOS GC** is an experimental static recompilation project for the GameCube version of **Harry Potter and the Chamber of Secrets** (`GHSE69`).

The project uses **DolRecomp** for static recompilation together with **ModernGekko** as the runtime environment. The goal is to progressively run the original GameCube program through a native recompilation workflow rather than shipping or emulating the original disc image as part of this repository.

## Current status

The project is actively under development. The current build is far enough along to reach the title/menu flow, loading screens, and in-game scenes represented in the screenshots below.

This repository intentionally keeps generated builds, local tool repositories, emulator/runtime state, and user-supplied game files out of Git.

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

## Repository layout

```text
.
├── README.md
├── LICENSE
├── docs/
│   ├── current-state.md
│   └── screenshots/
├── DolRecomp/          # local dependency repository — ignored
├── ModernGekko/        # local runtime repository — ignored
├── extracted/          # user-supplied extracted game data — ignored
├── iso/                # local disc images — ignored
├── port-build-*/       # generated recompilation/build output — ignored
├── runtime/            # generated runtime output — ignored
└── user/               # local emulator/runtime state — ignored
```

Not every local directory shown above is required to exist at all times.

## Development notes

- **Target game:** Harry Potter and the Chamber of Secrets
- **Platform:** Nintendo GameCube
- **Game ID:** `GHSE69`
- **Recompiler:** DolRecomp
- **Runtime:** ModernGekko
- **Status:** Work in progress

Detailed implementation notes and known issues can live in [`docs/current-state.md`](docs/current-state.md).

## Building

The recompilation toolchain and runtime are maintained locally as separate repositories and are intentionally excluded from this repository. Build instructions will be documented here once the workflow is stable enough to be reproducible for other developers.

## Legal

This is an unofficial fan/research project and is not affiliated with or endorsed by Electronic Arts, Warner Bros., Nintendo, or the original developers/publishers.

No copyrighted game files are included. Users are responsible for supplying their own legally obtained game data.

## License

See [`LICENSE`](LICENSE) for the source-code license that applies to this repository.
