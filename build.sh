#!/usr/bin/env bash
set -Eeuo pipefail

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"
SOURCE="$ROOT/ModernGekko"
BUILD="$ROOT/build/runtime"
PORT_BUILD="$ROOT/port-build"
EXTRACTED="$ROOT/extracted"
CACHE_ROOT="$ROOT/.cache"
GAME_ID="GHSE69"
MODULE_NAME="gGHSE69_recomp.so"
EXPECTED_DOL_SHA256="45ee05b836e44ff8861ad12323185b1b96928488937ee131f061b8d753d0c452"

BACKEND="${BACKEND:-c}"
TOOLCHAIN="${TOOLCHAIN:-clang}"
JOBS="${JOBS:-4}"
LLVM_DIR="${LLVM_DIR:-/usr/lib/llvm20/lib/cmake/llvm}"

die() {
  printf 'build.sh: %s\n' "$*" >&2
  exit 1
}

[[ -d "$SOURCE" ]] || die "missing local source tree: $SOURCE"
[[ -f "$EXTRACTED/sys/main.dol" ]] || die "missing extracted DOL: $EXTRACTED/sys/main.dol"
[[ "$(sha256sum "$EXTRACTED/sys/main.dol" | awk '{print $1}')" == \
   "$EXPECTED_DOL_SHA256" ]] || die "GHSE69 main.dol hash mismatch"
[[ "$BACKEND" == "c" || "$BACKEND" == "llvm" ]] ||
  die "BACKEND must be c or llvm"
[[ "$TOOLCHAIN" == "clang" || "$TOOLCHAIN" == "gcc" ||
   "$TOOLCHAIN" == "auto" ]] || die "TOOLCHAIN must be clang, gcc, or auto"
[[ "$JOBS" =~ ^[1-4]$ ]] || die "JOBS must be an integer from 1 through 4"

command -v flock >/dev/null 2>&1 || die "flock is required"
exec 9>"$ROOT/.build.lock"
flock -n 9 || die "another build.sh is already running for this project"

mkdir -p -- "$BUILD" "$PORT_BUILD" "$CACHE_ROOT/dolrecomp/llvm" \
  "$ROOT/.releases" "$ROOT/user"
export XDG_CACHE_HOME="$CACHE_ROOT"
export DOLRECOMP_LLVM_CACHE="$CACHE_ROOT/dolrecomp/llvm"
export MODERNGEKKO_BUILD_JOBS="$JOBS"
export CCACHE_DISABLE=1
export SCCACHE_DISABLE=1

if [[ "$BACKEND" == "llvm" ]]; then
  DOLRECOMP_LLVM=ON
else
  DOLRECOMP_LLVM=OFF
fi

cmake -S "$SOURCE" -B "$BUILD" -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_TESTING=OFF \
  -DMODERNGEKKO_ENABLE_DOLPHIN_RUNTIME=ON \
  -DMODERNGEKKO_ENABLE_DOLPHIN_TESTS=OFF \
  -DMODERNGEKKO_ENABLE_DYNAMIC_MODULES=ON \
  -DCMAKE_C_COMPILER_LAUNCHER= \
  -DCMAKE_CXX_COMPILER_LAUNCHER= \
  -DDOLRECOMP_ENABLE_LLVM="$DOLRECOMP_LLVM" \
  -DMODERNGEKKO_REQUIRED_DISC_ID="$GAME_ID" \
  -DMODERNGEKKO_REQUIRED_DOL_SHA256="$EXPECTED_DOL_SHA256" \
  -DMODERNGEKKO_DEFAULT_WINDOW_TITLE="Harry Potter and the Chamber of Secrets" \
  -DLLVM_DIR="$LLVM_DIR"

cmake --build "$BUILD" --target moderngekko-run moderngekko-port dolrecomp \
  --parallel "$JOBS"

if [[ "$BACKEND" == "llvm" ]]; then
  export DOLRECOMP_LLVM_BUILD_MODE="${DOLRECOMP_LLVM_BUILD_MODE:-balanced}"
  export DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS="${DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS:-512}"
fi

"$BUILD/moderngekko-port" build "$EXTRACTED" \
  --backend "$BACKEND" \
  --toolchain "$TOOLCHAIN" \
  --output "$PORT_BUILD"

ACTIVE_POINTER="$PORT_BUILD/$GAME_ID/active-module.txt"
[[ -f "$ACTIVE_POINTER" ]] || die "module build did not publish $ACTIVE_POINTER"
mapfile -t active_lines < "$ACTIVE_POINTER"
[[ ${#active_lines[@]} -eq 1 && -n "${active_lines[0]}" ]] ||
  die "active module pointer must contain exactly one non-empty path"

MODULE_SOURCE="${active_lines[0]}"
if [[ "$MODULE_SOURCE" != /* ]]; then
  MODULE_SOURCE="$ROOT/$MODULE_SOURCE"
fi
MODULE_SOURCE="$(realpath -e -- "$MODULE_SOURCE")"
LOCAL_PORT_BUILD="$(realpath -e -- "$PORT_BUILD")"
case "$MODULE_SOURCE" in
  "$LOCAL_PORT_BUILD/$GAME_ID/"*) ;;
  *) die "refusing module outside this project's port-build: $MODULE_SOURCE" ;;
esac
[[ "$(basename -- "$MODULE_SOURCE")" == "$MODULE_NAME" ]] ||
  die "unexpected module name: $MODULE_SOURCE"
[[ -s "$MODULE_SOURCE" ]] || die "built module is empty: $MODULE_SOURCE"
[[ -x "$BUILD/moderngekko-run" ]] || die "runtime build did not produce moderngekko-run"
[[ -d "$BUILD/Sys" ]] || die "runtime build did not produce its Sys data directory"

STAGE="$(mktemp -d "$ROOT/.publish.XXXXXX")"
PUBLISHING=0
OLD_RUNTIME_MOVED=0
OLD_MODULE_MOVED=0
NEW_RUNTIME_MOVED=0
NEW_MODULE_MOVED=0
cleanup_stage() {
  if [[ -n "${STAGE:-}" && "$STAGE" == "$ROOT"/.publish.* && -d "$STAGE" ]]; then
    rm -rf -- "$STAGE"
  fi
}

restore_previous() {
  set +e
  if (( NEW_RUNTIME_MOVED )) && [[ -d "$ROOT/runtime" ]]; then
    mv -- "$ROOT/runtime" "$STAGE/runtime.failed"
  fi
  if (( NEW_MODULE_MOVED )) && [[ -d "$ROOT/module" ]]; then
    mv -- "$ROOT/module" "$STAGE/module.failed"
  fi
  if (( OLD_RUNTIME_MOVED )) && [[ -d "$PREVIOUS/runtime" ]]; then
    mv -- "$PREVIOUS/runtime" "$ROOT/runtime"
  fi
  if (( OLD_MODULE_MOVED )) && [[ -d "$PREVIOUS/module" ]]; then
    mv -- "$PREVIOUS/module" "$ROOT/module"
  fi
  [[ -d "$PREVIOUS" ]] && rmdir -- "$PREVIOUS" 2>/dev/null
  set -e
}

finish() {
  local status="$1"
  trap - EXIT INT TERM HUP
  if (( PUBLISHING )); then
    restore_previous
  fi
  cleanup_stage
  exit "$status"
}
trap 'finish $?' EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
trap 'exit 129' HUP

mkdir -p -- "$STAGE/runtime" "$STAGE/module"
install -m 0755 -- "$BUILD/moderngekko-run" "$STAGE/runtime/moderngekko-run"
cp -a -- "$BUILD/Sys" "$STAGE/runtime/Sys"
install -m 0644 -- "$MODULE_SOURCE" "$STAGE/module/$MODULE_NAME"

RUNTIME_SHA="$(sha256sum "$STAGE/runtime/moderngekko-run" | awk '{print $1}')"
MODULE_SHA="$(sha256sum "$STAGE/module/$MODULE_NAME" | awk '{print $1}')"
printf 'game_id=%s\nbackend=%s\nruntime_sha256=%s\nmodule_sha256=%s\n' \
  "$GAME_ID" "$BACKEND" "$RUNTIME_SHA" "$MODULE_SHA" > "$STAGE/build-info.txt"
install -m 0644 -- "$STAGE/build-info.txt" "$STAGE/runtime/build-info.txt"
install -m 0644 -- "$STAGE/build-info.txt" "$STAGE/module/build-info.txt"

STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
PREVIOUS="$(mktemp -d "$ROOT/.releases/$STAMP.XXXXXX")"
PUBLISHING=1
if [[ -e "$ROOT/runtime" ]]; then
  OLD_RUNTIME_MOVED=1
  mv -- "$ROOT/runtime" "$PREVIOUS/runtime"
fi
if [[ -e "$ROOT/module" ]]; then
  OLD_MODULE_MOVED=1
  mv -- "$ROOT/module" "$PREVIOUS/module"
fi

NEW_RUNTIME_MOVED=1
mv -- "$STAGE/runtime" "$ROOT/runtime" || die "failed to publish runtime"
if [[ "${MODERNGEKKO_TEST_FAIL_PUBLISH_AFTER_RUNTIME:-0}" == "1" ]]; then
  die "test injection: failing publication after runtime rename"
fi
NEW_MODULE_MOVED=1
mv -- "$STAGE/module" "$ROOT/module" || die "failed to publish module"
PUBLISHING=0

if (( ! OLD_RUNTIME_MOVED && ! OLD_MODULE_MOVED )); then
  rmdir -- "$PREVIOUS"
fi

printf 'Published %s runtime %s\n' "$GAME_ID" "$RUNTIME_SHA"
printf 'Published %s module  %s\n' "$GAME_ID" "$MODULE_SHA"
