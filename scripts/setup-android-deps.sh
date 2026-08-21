#!/usr/bin/env bash
set -Eeuo pipefail

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"
SDK_ROOT="${1:-${ANDROID_SDK_ROOT:-$ROOT/.deps/android-sdk}}"

TOOLS_VERSION="15859902"
TOOLS_SHA256="4e4c464f145a7512b57d088ac6c278c03c9eea610886b35a5e0804e74eedf583"
TOOLS_URL="https://dl.google.com/android/repository/commandlinetools-linux-${TOOLS_VERSION}_latest.zip"
NDK_VERSION="${HPCOS_ANDROID_NDK_VERSION:-29.0.14206865}"
CMAKE_VERSION="${HPCOS_ANDROID_CMAKE_VERSION:-3.22.1}"

need() {
  command -v "$1" >/dev/null 2>&1 || {
    echo "setup-android-deps.sh: missing '$1'" >&2
    exit 1
  }
}

need java
need curl
need unzip
need sha256sum

JAVA_MAJOR="$(java -version 2>&1 | awk -F'[".]' '/version/ {print ($2 == "1" ? $3 : $2); exit}')"
if [[ -z "$JAVA_MAJOR" || "$JAVA_MAJOR" -lt 17 ]]; then
  echo "Java 17+ is required (detected: ${JAVA_MAJOR:-unknown})." >&2
  echo "Arch: sudo pacman -S --needed jdk17-openjdk" >&2
  exit 1
fi

DEPS="$ROOT/.deps"
mkdir -p "$DEPS" "$SDK_ROOT/cmdline-tools"
SDKMANAGER="$SDK_ROOT/cmdline-tools/latest/bin/sdkmanager"

if [[ ! -x "$SDKMANAGER" ]]; then
  ZIP="$DEPS/commandlinetools-linux-${TOOLS_VERSION}_latest.zip"
  TMP="$DEPS/.android-commandlinetools.$$"

  echo "[HPCOS] Downloading Android command-line tools ${TOOLS_VERSION}..."
  curl -L --fail --retry 3 "$TOOLS_URL" -o "$ZIP"
  echo "$TOOLS_SHA256  $ZIP" | sha256sum -c -

  rm -rf "$TMP" "$SDK_ROOT/cmdline-tools/latest"
  mkdir -p "$TMP" "$SDK_ROOT/cmdline-tools/latest"
  unzip -q "$ZIP" -d "$TMP"
  cp -a "$TMP/cmdline-tools/." "$SDK_ROOT/cmdline-tools/latest/"
  rm -rf "$TMP"
fi

export ANDROID_HOME="$SDK_ROOT"
export ANDROID_SDK_ROOT="$SDK_ROOT"
export PATH="$SDK_ROOT/cmdline-tools/latest/bin:$SDK_ROOT/platform-tools:$PATH"

echo "[HPCOS] Accepting Android SDK licenses..."
yes | "$SDKMANAGER" --licenses >/dev/null || true

echo "[HPCOS] Installing project-local Android packages..."
"$SDKMANAGER" \
  "platform-tools" \
  "platforms;android-36" \
  "build-tools;36.0.0" \
  "ndk;$NDK_VERSION" \
  "cmake;$CMAKE_VERSION"

cat > "$DEPS/android-env.sh" <<EOF
export ANDROID_HOME="$SDK_ROOT"
export ANDROID_SDK_ROOT="$SDK_ROOT"
export ANDROID_NDK_HOME="$SDK_ROOT/ndk/$NDK_VERSION"
export PATH="$SDK_ROOT/cmdline-tools/latest/bin:$SDK_ROOT/platform-tools:\$PATH"
EOF

echo "[HPCOS] Android SDK ready: $SDK_ROOT"
echo "[HPCOS] NDK: $NDK_VERSION"
echo "[HPCOS] CMake: $CMAKE_VERSION"
