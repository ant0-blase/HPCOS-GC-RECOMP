#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"
RUNTIME="$ROOT/runtime/moderngekko-run"
MODULE="$ROOT/module/gGHSE69_recomp.so"
GAME="$ROOT/extracted"
USERDIR="$ROOT/user"

[[ -x "$RUNTIME" ]] || {
  printf 'run.sh: missing runtime: %s\n' "$RUNTIME" >&2
  exit 1
}
[[ -f "$MODULE" ]] || {
  printf 'run.sh: missing module: %s\n' "$MODULE" >&2
  exit 1
}
[[ -f "$GAME/sys/main.dol" ]] || {
  printf 'run.sh: missing extracted game: %s\n' "$GAME" >&2
  exit 1
}
mkdir -p -- "$USERDIR"

exec "$RUNTIME" \
  --game "$GAME" \
  --module "$MODULE" \
  --user-dir "$USERDIR" \
  --graphics Vulkan \
  --wayland
