#!/usr/bin/env bash
# One-command packaging for the Super Mario Strikers (G4QE01) RecompCore module.
#
# Builds gG4QE01_recomp.<dylib|so> with ThinLTO (Release) and installs it into a
# Dolphin UserDir's StaticRecompModules/ directory, where the dolphin-chassis
# StaticRecomp core autoloads it by disc ID (no STATICRECOMP_MODULE env needed).
#
# Usage:
#   tools/package_module.sh [USER_DIR]
#     USER_DIR  Dolphin user directory to install into.
#               Default: <repo>/.tools/dolphin/user
#
# After packaging, run any G4QE01 ISO on the chassis with:
#   dolphin-emu-nogui -e <iso> -u <USER_DIR> -v Metal -C Dolphin.Core.CPUCore=6
# The module loads automatically; -C Dolphin.Core.StaticRecompModule=False forces
# interpreter-only (the prime-invariant path) without removing the file.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
STRIKERS_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
REPO_ROOT="$(cd "${STRIKERS_DIR}/.." && pwd)"

MODULE_SRC="${REPO_ROOT}/module-template"
BUILD_DIR="${STRIKERS_DIR}/build-chassis-module"
USER_DIR="${1:-${REPO_ROOT}/.tools/dolphin/user}"

case "$(uname -s)" in
  Darwin) SUFFIX=".dylib" ;;
  *)      SUFFIX=".so" ;;
esac
MODULE_NAME="gG4QE01_recomp${SUFFIX}"
DEST_DIR="${USER_DIR}/StaticRecompModules"

echo "[package] repo root : ${REPO_ROOT}"
echo "[package] module src: ${MODULE_SRC}"
echo "[package] user dir  : ${USER_DIR}"

# Configure once (ThinLTO Release), then build.
if [ ! -f "${BUILD_DIR}/build.ninja" ]; then
  cmake -S "${MODULE_SRC}" -B "${BUILD_DIR}" -GNinja -DCMAKE_BUILD_TYPE=Release -DGAME_ID=G4QE01 -DGENERATED_DIR="${STRIKERS_DIR}/generated"
fi
ninja -C "${BUILD_DIR}"

BUILT="${BUILD_DIR}/${MODULE_NAME}"
if [ ! -f "${BUILT}" ]; then
  echo "[package] ERROR: expected ${BUILT} not found" >&2
  exit 1
fi

mkdir -p "${DEST_DIR}"
cp -f "${BUILT}" "${DEST_DIR}/${MODULE_NAME}"

echo "[package] installed : ${DEST_DIR}/${MODULE_NAME}"
echo "[package] done. Run: dolphin-emu-nogui -e <iso> -u \"${USER_DIR}\" -v Metal -C Dolphin.Core.CPUCore=6"
