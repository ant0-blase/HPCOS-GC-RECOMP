#!/usr/bin/env python3
"""
HPCOS-GC-RECOMP repository polish/cleanup helper.

What it does:
  - validates the current Git repository
  - removes stray backup/log/temp files outside generated/nested workspaces
  - normalizes screenshot names in docs/screenshots/
  - rewrites README.md
  - rewrites .gitignore
  - untracks files that are now ignored (without deleting local copies)
  - commits the cleanup
  - pushes the current branch to the selected remote

Run from anywhere inside the repository:
    python3 hpcos_repo_polish.py

Useful options:
    python3 hpcos_repo_polish_v3.py --dry-run
    python3 hpcos_repo_polish_v3.py --no-push
"""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path


TARGET_SCREENSHOTS = [
    ("01-title-screen", "Title screen"),
    ("02-continue-menu", "Continue menu"),
    ("03-loading-screen", "Loading screen"),
    ("04-entrance-hall", "Entrance hall"),
    ("05-castle-yard", "Castle yard"),
    ("06-harry-wand", "Harry with his wand"),
]

IMAGE_EXTENSIONS = {".png", ".jpg", ".jpeg", ".webp"}

# These directories are either generated, huge, user-specific, or independent
# repositories. We intentionally do not recurse through them during junk cleanup.
SKIP_CLEAN_DIRS = {
    ".git",
    "DolRecomp",
    "ModernGekko",
    "build",
    "runtime",
    "user",
    "extracted",
    "iso",
    "module",
    ".cache",
    ".releases",
}

JUNK_SUFFIXES = {
    ".bak",
    ".log",
    ".tmp",
    ".orig",
    ".rej",
    ".old",
}

GITIGNORE = r"""# HPCOS-GC-RECOMP
# Keep everything required to build/run the project.
# Ignore only reproducible build output, user/game data and temporary files.

# -----------------------------------------------------------------------------
# Reproducible build/intermediate output
# -----------------------------------------------------------------------------
/build/
/port-build/
/port-build-*/
/cmake-build-*/
/.cache/
/.releases/
/.publish.*/
/.build.lock

# Generic CMake/Ninja state when created outside the directories above
CMakeCache.txt
CMakeFiles/
cmake_install.cmake
CTestTestfile.cmake
compile_commands.json
.ninja_deps
.ninja_log

# -----------------------------------------------------------------------------
# User-owned original game data — never publish
# -----------------------------------------------------------------------------
/extracted/*
!/extracted/README.md
!/extracted/.gitkeep

/iso/*
!/iso/README.md
!/iso/.gitkeep

*.iso
*.gcm
*.rvz
*.wbfs
*.wad

# -----------------------------------------------------------------------------
# Per-user runtime state / saves / dumps
# -----------------------------------------------------------------------------
/user/

# -----------------------------------------------------------------------------
# Temporary/editor files
# -----------------------------------------------------------------------------
*.log
*.bak
*.tmp
*.orig
*.rej
*.old
*~
*.swp
*.swo
*.dmp
core
core.*
vgcore.*

__pycache__/
*.py[cod]
.venv/
venv/

.vscode/
.idea/
.DS_Store
Thumbs.db
desktop.ini

# Local repository-maintenance helpers
/hpcos_repo_polish.py
/hpcos_repo_polish_v2.py
/hpcos_repo_polish_v3.py

# IMPORTANT: intentionally NOT ignored:
#   /ModernGekko/  -> source used by build.sh
#   /DolRecomp/    -> development dependency/source when present
#   /recomp/       -> recompilation source/output that represents the port
#   /runtime/      -> published runnable ModernGekko runtime
#   /module/       -> published gGHSE69_recomp.so module
#   /build.sh      -> reproducible build entry point
#   /run.sh        -> launcher
"""


def run(
    cmd: list[str],
    cwd: Path,
    *,
    check: bool = True,
    capture: bool = False,
    dry_run: bool = False,
) -> subprocess.CompletedProcess[str]:
    printable = " ".join(shell_quote(x) for x in cmd)
    print(f"$ {printable}")
    if dry_run:
        return subprocess.CompletedProcess(cmd, 0, "", "")
    return subprocess.run(
        cmd,
        cwd=cwd,
        check=check,
        text=True,
        capture_output=capture,
    )


def shell_quote(value: str) -> str:
    if re.fullmatch(r"[A-Za-z0-9_./:@%+=,-]+", value):
        return value
    return "'" + value.replace("'", "'\"'\"'") + "'"


def git_output(root: Path, *args: str) -> str:
    result = subprocess.run(
        ["git", *args],
        cwd=root,
        check=True,
        text=True,
        capture_output=True,
    )
    return result.stdout.strip()


def find_repo_root() -> Path:
    try:
        out = subprocess.run(
            ["git", "rev-parse", "--show-toplevel"],
            check=True,
            text=True,
            capture_output=True,
        ).stdout.strip()
    except (subprocess.CalledProcessError, FileNotFoundError):
        raise SystemExit("ERROR: run this script from inside the HPCOS Git repository.")
    return Path(out).resolve()


def natural_key(path: Path) -> list[object]:
    return [
        int(part) if part.isdigit() else part.lower()
        for part in re.split(r"(\d+)", path.name)
    ]


def is_junk_file(path: Path) -> bool:
    name = path.name.lower()
    if name.endswith("~"):
        return True
    return any(name.endswith(suffix) for suffix in JUNK_SUFFIXES)


def cleanup_junk(root: Path, dry_run: bool) -> list[Path]:
    removed: list[Path] = []

    # Root-level port-build-* directories are intentionally skipped.
    dynamic_skip = {
        p.name
        for p in root.iterdir()
        if p.is_dir() and p.name.startswith("port-build")
    }
    skip_dirs = SKIP_CLEAN_DIRS | dynamic_skip

    for current, dirs, files in __import__("os").walk(root):
        current_path = Path(current)
        if current_path == root:
            dirs[:] = [d for d in dirs if d not in skip_dirs]
        else:
            dirs[:] = [d for d in dirs if d not in {".git", "__pycache__", ".pytest_cache"}]

        for filename in files:
            path = current_path / filename
            if not is_junk_file(path):
                continue

            rel = path.relative_to(root)
            print(f"REMOVE junk: {rel}")
            removed.append(rel)
            if not dry_run:
                try:
                    path.unlink()
                except FileNotFoundError:
                    pass

    return removed


def screenshot_keywords(stem: str) -> set[str]:
    s = re.sub(r"[^a-z0-9]+", " ", stem.lower())
    words = set(s.split())
    if "title" in words:
        words.add("title-screen")
    if "continue" in words:
        words.add("continue-menu")
    if "loading" in words or "load" in words:
        words.add("loading-screen")
    if "entrance" in words or ("hall" in words and "castle" not in words):
        words.add("entrance-hall")
    if "yard" in words or "courtyard" in words:
        words.add("castle-yard")
    if "wand" in words:
        words.add("harry-wand")
    return words


def score_for_target(path: Path, target_stem: str) -> int:
    words = screenshot_keywords(path.stem)
    semantic_stem = re.sub(r"^\\d+-", "", target_stem)
    tokens = set(semantic_stem.split("-"))
    score = len(words & tokens)
    if semantic_stem in words:
        score += 10
    if target_stem == "05-castle-yard" and ("yard" in words or "courtyard" in words):
        score += 8
    if target_stem == "04-entrance-hall" and ("entrance" in words or "hall" in words):
        score += 8
    if target_stem == "06-harry-wand" and "wand" in words:
        score += 8
    return score


def rename_screenshots(root: Path, dry_run: bool) -> tuple[list[Path], dict[str, str]]:
    shots_dir = root / "docs" / "screenshots"
    if not dry_run:
        shots_dir.mkdir(parents=True, exist_ok=True)

    if not shots_dir.exists():
        print("No docs/screenshots directory found; screenshot rename skipped.")
        return [], {}

    images = sorted(
        [p for p in shots_dir.iterdir() if p.is_file() and p.suffix.lower() in IMAGE_EXTENSIONS],
        key=natural_key,
    )

    if not images:
        print("No screenshots found in docs/screenshots; screenshot rename skipped.")
        return [], {}

    print(f"Found {len(images)} screenshot(s) in {shots_dir.relative_to(root)}")

    # Preserve already-professional target names first.
    target_by_stem = {stem: label for stem, label in TARGET_SCREENSHOTS}
    assigned: dict[str, Path] = {}
    remaining = []

    for image in images:
        if image.stem in target_by_stem:
            assigned[image.stem] = image
        else:
            remaining.append(image)

    # Try semantic filename matching for unassigned targets.
    for target_stem, _ in TARGET_SCREENSHOTS:
        if target_stem in assigned or not remaining:
            continue
        ranked = sorted(
            ((score_for_target(p, target_stem), p) for p in remaining),
            key=lambda item: (-item[0], natural_key(item[1])),
        )
        if ranked and ranked[0][0] >= 2:
            chosen = ranked[0][1]
            assigned[target_stem] = chosen
            remaining.remove(chosen)

    # The supplied project README documents six screenshots in this exact scene order.
    # If names are opaque, map the remaining images deterministically by natural order.
    missing_targets = [stem for stem, _ in TARGET_SCREENSHOTS if stem not in assigned]
    if missing_targets and remaining:
        for target_stem, source in zip(missing_targets, sorted(remaining, key=natural_key)):
            assigned[target_stem] = source
        remaining = sorted(remaining, key=natural_key)[len(missing_targets):]

    planned: list[tuple[Path, Path]] = []
    final_images: list[Path] = []
    replacements: dict[str, str] = {}

    for target_stem, _ in TARGET_SCREENSHOTS:
        source = assigned.get(target_stem)
        if source is None:
            continue
        ext = source.suffix.lower()
        target = shots_dir / f"{target_stem}{ext}"
        final_images.append(target)
        if source != target:
            planned.append((source, target))
            replacements[source.name] = target.name

    # Any additional screenshots get stable, readable names without pretending
    # to know their content.
    extra_index = len(TARGET_SCREENSHOTS) + 1
    for source in remaining:
        slug = re.sub(r"[^a-z0-9]+", "-", source.stem.lower()).strip("-")
        if not slug or slug.startswith("screenshot"):
            slug = "gameplay"
        target = shots_dir / f"{extra_index:02d}-{slug}{source.suffix.lower()}"
        extra_index += 1
        final_images.append(target)
        if source != target:
            planned.append((source, target))
            replacements[source.name] = target.name

    if not planned:
        print("Screenshots already have clean names.")
        return [p for p in final_images if p.exists() or dry_run], replacements

    # Two-phase rename avoids collisions such as 1.png -> 2.png -> 3.png.
    temp_moves: list[tuple[Path, Path, Path]] = []
    for idx, (source, target) in enumerate(planned, 1):
        print(f"RENAME screenshot: {source.name} -> {target.name}")
        if dry_run:
            continue
        temp = shots_dir / f".hpcos-rename-{idx:02d}{source.suffix.lower()}"
        counter = 0
        while temp.exists():
            counter += 1
            temp = shots_dir / f".hpcos-rename-{idx:02d}-{counter}{source.suffix.lower()}"
        source.rename(temp)
        temp_moves.append((temp, target, source))

    if not dry_run:
        for temp, target, original_source in temp_moves:
            if target.exists() and target != original_source:
                # This should only happen if a target was not detected above.
                # Preserve data rather than overwriting.
                raise RuntimeError(f"Refusing to overwrite existing screenshot: {target}")
            temp.rename(target)

    return [p for p in final_images if p.exists() or dry_run], replacements


def update_markdown_references(root: Path, replacements: dict[str, str], dry_run: bool) -> None:
    if not replacements:
        return

    docs = root / "docs"
    candidates = [root / "README.md"]
    if docs.exists():
        candidates.extend(docs.rglob("*.md"))

    for path in candidates:
        if not path.exists():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        new_text = text
        for old, new in replacements.items():
            new_text = new_text.replace(old, new)
        if new_text != text:
            print(f"UPDATE references: {path.relative_to(root)}")
            if not dry_run:
                path.write_text(new_text, encoding="utf-8")


def image_label(path: Path) -> str:
    labels = {stem: label for stem, label in TARGET_SCREENSHOTS}
    if path.stem in labels:
        return labels[path.stem]
    words = path.stem.split("-", 1)
    name = words[1] if len(words) == 2 and words[0].isdigit() else path.stem
    return name.replace("-", " ").strip().title()


def build_readme(screenshots: list[Path], root: Path) -> str:
    existing = [p for p in screenshots if p.exists()]
    hero = (
        f'<p align="center">\n'
        f'  <img src="{existing[0].relative_to(root).as_posix()}" '
        f'alt="Harry Potter and the Chamber of Secrets running through HPCOS GC" width="900">\n'
        f'</p>\n\n'
        if existing
        else ""
    )

    screenshot_section = ""
    if existing:
        cards = []
        for shot in existing:
            rel = shot.relative_to(root).as_posix()
            label = image_label(shot)
            cards.append(
                f'<td align="center" width="50%">'
                f'<img src="{rel}" alt="{label}" width="100%"><br>'
                f'<sub>{label}</sub></td>'
            )
        rows = []
        for i in range(0, len(cards), 2):
            row = cards[i:i + 2]
            if len(row) == 1:
                row.append('<td width="50%"></td>')
            rows.append("<tr>\n" + "\n".join(row) + "\n</tr>")
        screenshot_section = "## Screenshots\n\n<table>\n" + "\n".join(rows) + "\n</table>\n\n"

    return f"""# Harry Potter and the Chamber of Secrets — GameCube Static Recompilation

{hero}<p align="center">
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
**DolRecomp** for static PowerPC recompilation and **ModernGekko** for the runtime.
The repository is intended to contain the actual HPCOS project state needed for
building and running the port — not only screenshots or documentation.

## Current status

HPCOS is actively under development. The current project reaches the title/menu
flow, loading and in-game scenes shown below.

{screenshot_section}## Build layout

The checked-in project deliberately keeps the files that are required to reproduce
or run the current port:

```text
.
├── build.sh                  # configures/builds ModernGekko + DolRecomp + the GHSE69 module
├── run.sh                    # launches the published runtime/module
├── ModernGekko/              # source tree consumed by build.sh
├── DolRecomp/                # recompilation dependency/source when present locally
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
module, then atomically publishes the runnable outputs into `runtime/` and `module/`.

`run.sh` launches:

- `runtime/moderngekko-run`
- `module/gGHSE69_recomp.so`
- the user's local `extracted/` game directory
- a local `user/` runtime directory

## Building

Requirements include CMake, Ninja, a supported C/C++ toolchain and the dependencies
required by ModernGekko/DolRecomp. The current build script supports the `c` and
`llvm` recompilation backends and `clang`, `gcc` or automatic toolchain selection.

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

The expected target is `GHSE69`; `build.sh` verifies the DOL SHA-256 before building.

## Running

After a successful build:

```bash
./run.sh
```

The current launcher uses Vulkan and Wayland.

## What is intentionally ignored

The `.gitignore` is intentionally conservative. It ignores only things that should
not be part of the repository: reproducible build directories, caches, release
staging, user-specific Dolphin/ModernGekko state, logs/backups, and original game
files supplied by the user.

Notably, **`runtime/`, `module/`, `recomp/`, `ModernGekko/`, `DolRecomp/`, `build.sh`
and `run.sh` are not ignored.**

## Credits and acknowledgements

HPCOS GC depends on open-source work from the GameCube/Wii recompilation and emulation
communities.

### ExpansionPak

- **DolRecomp** — static PowerPC recompiler used by GameCube/Wii recompilation projects.
  https://github.com/ExpansionPak/DolRecomp
- **ModernGekko** — runtime and tooling used to execute recompiled GameCube/Wii code.
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

No original disc image or extracted copyrighted game assets should be committed to
this repository. Users must provide their own legally obtained game data.

## License

See [`LICENSE`](LICENSE) for HPCOS-specific repository content. Third-party components,
including DolRecomp, ModernGekko and their dependencies, remain subject to their own
licenses.
"""

def write_text(path: Path, content: str, root: Path, dry_run: bool) -> None:
    print(f"WRITE {path.relative_to(root)}")
    if not dry_run:
        path.write_text(content.rstrip() + "\n", encoding="utf-8")


def untrack_ignored(root: Path, dry_run: bool) -> list[str]:
    if dry_run:
        print("DRY-RUN: skipped index scan for newly ignored tracked files.")
        return []

    result = subprocess.run(
        ["git", "ls-files", "-ci", "--exclude-standard"],
        cwd=root,
        text=True,
        capture_output=True,
        check=True,
    )
    paths = [line for line in result.stdout.splitlines() if line.strip()]
    if not paths:
        return []

    print(f"Untracking {len(paths)} file(s) now covered by .gitignore (local files are kept).")
    batch_size = 200
    for i in range(0, len(paths), batch_size):
        batch = paths[i:i + batch_size]
        run(["git", "rm", "-r", "--cached", "--ignore-unmatch", "--", *batch], root)
    return paths


def ensure_remote(root: Path, remote: str) -> str:
    try:
        return git_output(root, "remote", "get-url", remote)
    except subprocess.CalledProcessError:
        raise SystemExit(
            f"ERROR: Git remote '{remote}' does not exist. "
            f"Add it first, then rerun the script."
        )


def staged_changes(root: Path) -> bool:
    result = subprocess.run(
        ["git", "diff", "--cached", "--quiet"],
        cwd=root,
    )
    return result.returncode != 0


def warn_nested_repositories(root: Path) -> None:
    """Warn when dependency trees are independent Git repositories.

    A parent repository cannot transparently vendor the full contents of an embedded
    Git repository. If these paths contain their own .git metadata, users should
    either register proper submodules or vendor the dependency source intentionally.
    """
    found = []
    for name in ("ModernGekko", "DolRecomp"):
        path = root / name
        if path.exists() and (path / ".git").exists():
            found.append(name)
    if found:
        print("\nWARNING: embedded Git repositories detected: " + ", ".join(found))
        print("Git may record these as gitlinks instead of storing every file in the parent repo.")
        print("Before publishing, verify with: git ls-files --stage ModernGekko DolRecomp")
        print("Mode 160000 means submodule/gitlink; make sure .gitmodules + reachable commits exist,")
        print("or vendor the dependency source if you want a self-contained repository.\n")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Polish and push the HPCOS GC repository.")
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="show the cleanup/rename plan without modifying files or Git",
    )
    parser.add_argument(
        "--no-push",
        action="store_true",
        help="make/commit the cleanup but do not push",
    )
    parser.add_argument(
        "--remote",
        default="origin",
        help="Git remote to push to (default: origin)",
    )
    parser.add_argument(
        "--commit-message",
        default="chore: polish HPCOS repository and preserve build/runtime files",
        help="commit message",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    root = find_repo_root()
    print(f"Repository: {root}")

    # Warn, but do not block, if the directory has a different name.
    if "HPCOS" not in root.name.upper():
        print("WARNING: repository directory name does not contain 'HPCOS'.")

    branch = git_output(root, "branch", "--show-current")
    if not branch:
        raise SystemExit("ERROR: detached HEAD. Check out a branch before running this script.")
    print(f"Branch: {branch}")
    warn_nested_repositories(root)

    if not args.dry_run and staged_changes(root):
        raise SystemExit(
            "ERROR: the repository already has staged changes. "
            "Commit or unstage them first so this cleanup cannot accidentally "
            "include unrelated work in its commit."
        )

    print("\n== 1. Clean stray backup/log/temp files ==")
    cleanup_junk(root, args.dry_run)

    print("\n== 2. Normalize screenshots ==")
    screenshots, replacements = rename_screenshots(root, args.dry_run)
    update_markdown_references(root, replacements, args.dry_run)

    print("\n== 3. Write .gitignore ==")
    write_text(root / ".gitignore", GITIGNORE, root, args.dry_run)

    print("\n== 4. Write README.md ==")
    if args.dry_run:
        # During dry-run, target screenshots may not exist yet. Use current files so
        # the generated README plan remains meaningful.
        current_shots_dir = root / "docs" / "screenshots"
        current_shots = (
            sorted(
                [p for p in current_shots_dir.iterdir() if p.suffix.lower() in IMAGE_EXTENSIONS],
                key=natural_key,
            )
            if current_shots_dir.exists()
            else []
        )
        readme = build_readme(current_shots, root)
    else:
        readme = build_readme(screenshots, root)
    write_text(root / "README.md", readme, root, args.dry_run)

    if args.dry_run:
        print("\nDRY-RUN complete. No files, commits, or remotes were changed.")
        return 0

    print("\n== 5. Remove newly ignored files from the Git index ==")
    untrack_ignored(root, False)

    print("\n== 6. Stage and commit ==")
    # Stage the actual repository, not only the presentation files.
    # .gitignore protects only build/cache/user/game data; project sources and published runtime/module remain trackable.
    run(["git", "add", "-A"], root)
    run(["git", "status", "--short"], root)

    if not staged_changes(root):
        print("Nothing to commit.")
    else:
        run(["git", "commit", "-m", args.commit_message], root)

    if args.no_push:
        print("\nDone. Push skipped because --no-push was requested.")
        return 0

    print("\n== 7. Push ==")
    remote_url = ensure_remote(root, args.remote)
    print(f"Remote: {args.remote} -> {remote_url}")
    # Deliberately never force-push. If the remote moved, Git will stop safely.
    run(["git", "push", "-u", args.remote, branch], root)

    print("\nRepository cleanup complete and pushed successfully.")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except KeyboardInterrupt:
        print("\nInterrupted.", file=sys.stderr)
        raise SystemExit(130)
    except subprocess.CalledProcessError as exc:
        print(f"\nERROR: command failed with exit code {exc.returncode}.", file=sys.stderr)
        raise SystemExit(exc.returncode)
    except Exception as exc:
        print(f"\nERROR: {exc}", file=sys.stderr)
        raise SystemExit(1)
