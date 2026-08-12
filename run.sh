#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"

RUNTIME="$ROOT/runtime/moderngekko-run"
MODULE="$ROOT/module/gGHSE69_recomp.so"
GAME="$ROOT/extracted"
USERDIR="$ROOT/user"

DYNAMIC_WIDESCREEN=0

usage() {
  cat <<'EOF'
HPCOS GC

Usage:
  ./run.sh [options]

Display:
  --widescreen       Dynamic aspect from the real drawable/window.
                     16:10, 16:9, 21:9, 32:9, resize, etc.

Camera:
  --fov <degrees>    Optional horizontal FOV override.

Examples:
  ./run.sh
  ./run.sh --widescreen
  ./run.sh --widescreen --fov 90
EOF
}

while (($#)); do
  case "$1" in

    --widescreen)
      DYNAMIC_WIDESCREEN=1
      shift
      ;;

    --fov)
      [[ $# -ge 2 ]] || {
        echo "run.sh: --fov requires degrees" >&2
        exit 2
      }

      export HPCOS_FOV="$2"
      shift 2
      ;;

    -h|--help)
      usage
      exit 0
      ;;

    *)
      echo "run.sh: unknown option: $1" >&2
      exit 2
      ;;
  esac
done


[[ -x "$RUNTIME" ]] || {
  echo "missing runtime: $RUNTIME" >&2
  exit 1
}

[[ -f "$MODULE" ]] || {
  echo "missing module: $MODULE" >&2
  exit 1
}

[[ -f "$GAME/sys/main.dol" ]] || {
  echo "missing extracted game: $GAME" >&2
  exit 1
}

mkdir -p "$USERDIR/Config"


python3 - \
  "$USERDIR/Config/GFX.ini" \
  "$DYNAMIC_WIDESCREEN" <<'PYCFG'
from pathlib import Path
import re
import sys

path = Path(sys.argv[1])
wide = sys.argv[2] == "1"

text = path.read_text() if path.exists() else ""


def set_ini(text, section, key, value):
    lines = text.splitlines()

    section_rx = re.compile(
        rf"^\s*\[{re.escape(section)}\]\s*$",
        re.I
    )
    key_rx = re.compile(
        rf"^\s*{re.escape(key)}\s*=.*$",
        re.I
    )

    start = None

    for i, line in enumerate(lines):
        if section_rx.match(line):
            start = i
            break

    if start is None:
        if lines and lines[-1].strip():
            lines.append("")

        lines += [
            f"[{section}]",
            f"{key} = {value}",
        ]

        return "\n".join(lines) + "\n"

    end = len(lines)

    for i in range(start + 1, len(lines)):
        if re.match(r"^\s*\[.*\]\s*$", lines[i]):
            end = i
            break

    for i in range(start + 1, end):
        if key_rx.match(lines[i]):
            lines[i] = f"{key} = {value}"
            return "\n".join(lines) + "\n"

    lines.insert(end, f"{key} = {value}")
    return "\n".join(lines) + "\n"


if wide:
    # Full drawable: no Presenter pillarboxing.
    text = set_ini(text, "Settings", "AspectRatio", "3")

    # CRITICAL:
    # game-side aspect patch replaces Dolphin's generic hack.
    text = set_ini(text, "Settings", "wideScreenHack", "False")
    text = set_ini(text, "Settings", "CPUCull", "False")

    # Make sure old experiments aren't introducing crop/borders.
    text = set_ini(text, "Settings", "Crop", "False")
    text = set_ini(text, "Settings", "CropCustom", "False")
    text = set_ini(text, "Settings", "CropCustomLeft", "0")
    text = set_ini(text, "Settings", "CropCustomRight", "0")
    text = set_ini(text, "Settings", "CropCustomTop", "0")
    text = set_ini(text, "Settings", "CropCustomBottom", "0")

else:
    text = set_ini(text, "Settings", "AspectRatio", "0")
    text = set_ini(text, "Settings", "wideScreenHack", "False")


path.write_text(text)
PYCFG


if (( DYNAMIC_WIDESCREEN )); then
  export HPCOS_DYNAMIC_ASPECT=1
  echo "[HPCOS] dynamic widescreen enabled"
else
  unset HPCOS_DYNAMIC_ASPECT || true
fi

exec "$RUNTIME" \
  --game "$GAME" \
  --module "$MODULE" \
  --user-dir "$USERDIR" \
  --graphics Vulkan \
  --wayland
