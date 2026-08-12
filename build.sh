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

# ---------------------------------------------------------------------------
# Build profiles
#
# One knob that sets runtime and module coherently. Every setting below changes
# emitted code and is folded into the module build identity, so each profile
# gets its own port-build/GHSE69/<hash>/ directory: profiles coexist, and
# switching back is a rebuild away rather than a lost artifact.
#
#   native    this machine only (-march=native), runtime LTO. Not portable.
#   modern    AVX2/BMI2/FMA, Haswell / Excavator and later.        [default]
#   compat    SSE4.2/POPCNT, Nehalem / Bulldozer and later.
#   baseline  plain x86-64. Runs on anything 64-bit, including weak CPUs.
#   lockstep  debug build: RAM write journal compiled in so
#             STATICRECOMP_LOCKSTEP works, stack protector kept, no LTO.
#
# Individual settings still win over the profile, e.g.
#   HPCOS_PROFILE=baseline HPCOS_RUNTIME_LTO=1 ./build.sh
#
# The structural optimizations (MEM1-only address decode, journal removal,
# gather-pipe shortcut) are ISA-independent and stay on in every profile except
# lockstep, so a weak CPU keeps them while dropping only the wide ISA.
# ---------------------------------------------------------------------------
HPCOS_PROFILE="${HPCOS_PROFILE:-modern}"

case "$HPCOS_PROFILE" in
  native)   p_march="native"     ; p_lto=1 ; p_journal=0 ; p_ssp=0 ; p_opt=3 ; p_fastmem=1 ;;
  modern)   p_march="x86-64-v3"  ; p_lto=0 ; p_journal=0 ; p_ssp=0 ; p_opt=3 ; p_fastmem=0 ;;
  compat)   p_march="x86-64-v2"  ; p_lto=0 ; p_journal=0 ; p_ssp=0 ; p_opt=3 ; p_fastmem=0 ;;
  baseline) p_march="x86-64"     ; p_lto=0 ; p_journal=0 ; p_ssp=0 ; p_opt=3 ; p_fastmem=0 ;;
  lockstep) p_march="x86-64-v3"  ; p_lto=0 ; p_journal=1 ; p_ssp=1 ; p_opt=2 ; p_fastmem=0 ;;
  *) printf 'build.sh: unknown HPCOS_PROFILE %s (native|modern|compat|baseline|lockstep)\n' \
       "$HPCOS_PROFILE" >&2; exit 1 ;;
esac

HPCOS_MARCH="${HPCOS_MARCH:-$p_march}"
HPCOS_RUNTIME_LTO="${HPCOS_RUNTIME_LTO:-$p_lto}"
HPCOS_MODULE_MEM_JOURNAL="${HPCOS_MODULE_MEM_JOURNAL:-$p_journal}"
HPCOS_MODULE_STACK_PROTECTOR="${HPCOS_MODULE_STACK_PROTECTOR:-$p_ssp}"
HPCOS_MODULE_OPT="${HPCOS_MODULE_OPT:-$p_opt}"
HPCOS_MODULE_MARCH="${HPCOS_MODULE_MARCH:-$HPCOS_MARCH}"
HPCOS_MODULE_MEM1_ONLY="${HPCOS_MODULE_MEM1_ONLY:-1}"
HPCOS_MODULE_FASTMEM="${HPCOS_MODULE_FASTMEM:-$p_fastmem}"

export HPCOS_MODULE_MARCH HPCOS_MODULE_OPT HPCOS_MODULE_MEM1_ONLY
export HPCOS_MODULE_MEM_JOURNAL HPCOS_MODULE_STACK_PROTECTOR HPCOS_MODULE_FASTMEM

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

# Runtime host flags.
#
# Upstream Dolphin only sets -march on Apple targets, so on Linux this build was
# emitting baseline x86-64. -ffp-contract=off is not optional once a wider ISA
# is selected: clang defaults to contracting a*b+c into an FMA as soon as the
# hardware allows it, which would silently change emulated float results (audio
# mixing, projection and matrix math). Off keeps the current semantics exactly.
if [[ "$HPCOS_MARCH" == "none" ]]; then
  RUNTIME_ARCH_FLAGS="${RUNTIME_ARCH_FLAGS:--ffp-contract=off}"
else
  RUNTIME_ARCH_FLAGS="${RUNTIME_ARCH_FLAGS:--march=$HPCOS_MARCH -ffp-contract=off}"
fi

# Runtime link-time optimization. Its win is inlining TranslateRelAddress and
# the MMU accessors into the StaticRecomp hooks, which no source change can
# reach across translation units. Off outside the native profile because it
# roughly doubles the runtime build time.
if [[ "$HPCOS_RUNTIME_LTO" == "1" ]]; then
  RUNTIME_ENABLE_LTO=ON
else
  RUNTIME_ENABLE_LTO=OFF
fi

printf 'build.sh: profile=%s march=%s runtime-lto=%s module(-O%s mem1=%s journal=%s ssp=%s fastmem=%s)\n' \
  "$HPCOS_PROFILE" "$HPCOS_MARCH" "$RUNTIME_ENABLE_LTO" "$HPCOS_MODULE_OPT" \
  "$HPCOS_MODULE_MEM1_ONLY" "$HPCOS_MODULE_MEM_JOURNAL" "$HPCOS_MODULE_STACK_PROTECTOR" \
  "$HPCOS_MODULE_FASTMEM"

cmake -S "$SOURCE" -B "$BUILD" -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="$RUNTIME_ARCH_FLAGS" \
  -DCMAKE_CXX_FLAGS="$RUNTIME_ARCH_FLAGS" \
  -DENABLE_LTO="$RUNTIME_ENABLE_LTO" \
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
