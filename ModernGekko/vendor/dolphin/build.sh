#!/bin/bash
set -e

# Bypassing global/system git configs (autocrlf) during dependency checkouts
export GIT_CONFIG_GLOBAL=/dev/null
export GIT_CONFIG_SYSTEM=/dev/null
export GIT_CONFIG_NOSYSTEM=1


# Core count detection
if [ "$1" = "--force" ] || [ "$1" = "-f" ]; then
  echo "=== Force rebuild requested. Cleaning build directories... ==="
  rm -rf build
  rm -rf module-template/build
fi

NCPU=$(sysctl -n hw.ncpu 2>/dev/null || sysctl -n hw.logicalcpu 2>/dev/null || echo 4)

# Detect Ninja generator for faster builds
GENERATOR=""
if command -v ninja >/dev/null 2>&1; then
  GENERATOR="-G Ninja"
fi

# Detect ccache to cache compilation artifacts
LAUNCHER_FLAGS=""
if command -v ccache >/dev/null 2>&1; then
  LAUNCHER_FLAGS="-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache"
fi

echo "=== Building RecompCore (Dolphin Emulator chassis) ==="
# Clean build folder if switching generators (e.g. from Makefiles to Ninja)
if [ -d "build" ] && [ ! -f "build/build.ninja" ] && [ -n "$GENERATOR" ]; then
  echo "Switching generator to Ninja. Cleaning build directory..."
  rm -rf build
fi
cmake $GENERATOR $LAUNCHER_FLAGS -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$NCPU"

echo "=== Building Static Recomp Module ==="
cd module-template
if [ -d "build" ] && [ ! -f "build/build.ninja" ] && [ -n "$GENERATOR" ]; then
  echo "Switching generator to Ninja. Cleaning build directory..."
  rm -rf build
fi
cmake $GENERATOR $LAUNCHER_FLAGS -S . -B build -DCMAKE_BUILD_TYPE=Release -DGAME_ID=000002
cmake --build build -j"$NCPU"
cd ..

# Copy compiled module to default Dolphin User path search directory
DEST_DIR="$HOME/Library/Application Support/Dolphin/StaticRecompModules"
mkdir -p "$DEST_DIR"
cp module-template/build/g000002_recomp.dylib "$DEST_DIR/g000002_recomp.dylib"
echo "=== Copied module to default user directory: $DEST_DIR ==="

echo "=== Build Complete! ==="
