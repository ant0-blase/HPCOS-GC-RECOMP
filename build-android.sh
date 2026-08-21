#!/usr/bin/env bash
set -Eeuo pipefail
ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"
cd "$ROOT"

# Project-local Android toolchain. If the caller already supplies an SDK, keep it;
# otherwise bootstrap a reproducible SDK/NDK/CMake under .deps/android-sdk.
SDK_ROOT="${ANDROID_SDK_ROOT:-${ANDROID_HOME:-$ROOT/.deps/android-sdk}}"
NDK_VERSION="${HPCOS_ANDROID_NDK_VERSION:-29.0.14206865}"
SDK_CMAKE_VERSION="${HPCOS_ANDROID_CMAKE_VERSION:-3.22.1}"

if [[ ! -x "$SDK_ROOT/cmdline-tools/latest/bin/sdkmanager" ||
      ! -f "$SDK_ROOT/ndk/$NDK_VERSION/build/cmake/android.toolchain.cmake" ||
      ! -x "$SDK_ROOT/cmake/$SDK_CMAKE_VERSION/bin/cmake" ]]; then
  echo "[HPCOS] Android SDK/NDK missing; bootstrapping project-local dependencies..."
  "$ROOT/scripts/setup-android-deps.sh" "$SDK_ROOT"
fi

export ANDROID_HOME="$SDK_ROOT"
export ANDROID_SDK_ROOT="$SDK_ROOT"
ANDROID_NDK_HOME="${ANDROID_NDK_HOME:-${ANDROID_NDK_ROOT:-$SDK_ROOT/ndk/$NDK_VERSION}}"
export ANDROID_NDK_HOME
SDK_CMAKE="$SDK_ROOT/cmake/$SDK_CMAKE_VERSION/bin/cmake"
SDK_NINJA="$SDK_ROOT/cmake/$SDK_CMAKE_VERSION/bin/ninja"

[[ -f "$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" ]] || {
  echo "Android NDK toolchain missing: $ANDROID_NDK_HOME" >&2; exit 2;
}
[[ -x "$SDK_CMAKE" ]] || { echo "Android SDK CMake missing: $SDK_CMAKE" >&2; exit 2; }
[[ -x "$SDK_NINJA" ]] || { echo "Android SDK Ninja missing: $SDK_NINJA" >&2; exit 2; }
command -v cmake >/dev/null || { echo "Host cmake is required to build DolRecomp" >&2; exit 2; }
command -v ninja >/dev/null || { echo "Host ninja is required to build DolRecomp" >&2; exit 2; }
command -v python3 >/dev/null || { echo "python3 is required" >&2; exit 2; }
command -v java >/dev/null || { echo "Java 17+ is required" >&2; exit 2; }

GAME_ID=GHSE69
EXPECTED=45ee05b836e44ff8861ad12323185b1b96928488937ee131f061b8d753d0c452
DOL="$ROOT/extracted/sys/main.dol"
[[ -f "$DOL" ]] || { echo "Missing extracted/sys/main.dol" >&2; exit 2; }
[[ "$(sha256sum "$DOL" | awk '{print $1}')" == "$EXPECTED" ]] || { echo "GHSE69 DOL hash mismatch" >&2; exit 2; }

HOST_BUILD="$ROOT/build/android-host-tools"
OUT="$ROOT/build/android-dolrecomp-output"
GEN="$OUT/generated"
MOD_BUILD="$ROOT/build/android-module"
ANDROID_SRC="$ROOT/ModernGekko/vendor/dolphin/Source/Android"
JNI_LIBS="$ANDROID_SRC/app/src/main/jniLibs/arm64-v8a"

cmake -S "$ROOT/ModernGekko/vendor/dolphin/DolRecomp" -B "$HOST_BUILD" -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build "$HOST_BUILD" --target dolrecomp --parallel "${JOBS:-$(nproc)}"
rm -rf "$OUT"
mkdir -p "$OUT"
"$HOST_BUILD/dolrecomp" -j"${JOBS:-4}" --backend=c --cpu gekko --gamecube "$DOL" "$OUT"

# module-template validates the generated source tree against the original
# executable and requires main.dol beside generated.c/generated.h.
cp -f "$DOL" "$GEN/main.dol"

rm -rf "$MOD_BUILD"
"$SDK_CMAKE" -S "$ROOT/ModernGekko/vendor/dolphin/module-template" -B "$MOD_BUILD" -G Ninja \
  -DCMAKE_MAKE_PROGRAM="$SDK_NINJA" \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-26 \
  -DGAME_ID="$GAME_ID" -DGENERATED_DIR="$GEN" \
  -DGXRUNTIME_DIR="$ROOT/ModernGekko/vendor/dolphin/GXRuntime" \
  -DCHASSIS_ABI_DIR="$ROOT/ModernGekko/vendor/dolphin/Source/Core/Core/PowerPC/StaticRecomp" \
  -DRECOMPCORE_MODULE_OPT_LEVEL=3 -DRECOMPCORE_MODULE_ENABLE_IPO=ON \
  -DRECOMPCORE_MODULE_GAMECUBE_MEM1_ONLY=ON -DRECOMPCORE_MODULE_ENABLE_MEM_JOURNAL=OFF \
  -DRECOMPCORE_MODULE_FASTMEM=ON
"$SDK_CMAKE" --build "$MOD_BUILD" --parallel "${JOBS:-$(nproc)}"
MODULE="$(find "$MOD_BUILD" -maxdepth 2 -type f -name 'gGHSE69_recomp.so' | head -1)"
[[ -n "$MODULE" ]] || { echo "Android recomp module was not produced" >&2; exit 1; }
mkdir -p "$JNI_LIBS"
cp -f "$MODULE" "$JNI_LIBS/libgGHSE69_recomp.so"

pushd "$ANDROID_SRC" >/dev/null
ANDROID_HOME="$SDK_ROOT" ANDROID_SDK_ROOT="$SDK_ROOT" ./gradlew :app:assembleRelease
popd >/dev/null
APK="$(find "$ANDROID_SRC/app/build/outputs/apk" -type f -name '*release*.apk' | head -1)"
[[ -n "$APK" ]] || { echo "Release APK not found" >&2; exit 1; }
mkdir -p "$ROOT/dist/android"
cp -f "$APK" "$ROOT/dist/android/HPCOS-GC-RECOMP-arm64.apk"
echo "APK: $ROOT/dist/android/HPCOS-GC-RECOMP-arm64.apk"
