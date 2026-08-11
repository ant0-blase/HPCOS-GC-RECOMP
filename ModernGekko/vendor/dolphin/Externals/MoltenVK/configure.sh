#!/bin/bash

# To lower build times, we avoid running the fetchDependencies script if the MoltenVK
# version didn't change. The last-built MoltenVK version is stored inside a file in
# the timestamp directory. If the file doesn't exist or the file contains a different
# MoltenVK version, fetchDependencies is ran.
#
# Usage: configure.sh <timestamp directory> <source directory> <MoltenVK version>
#

set -e

VERSION_PATH="$1/MoltenVK-last-version.txt"
CURRENT_VERSION="$3"
LAST_VERSION=$(cat "$VERSION_PATH" || true)

if ! [ "$LAST_VERSION" = "$3" ]; then
  export GIT_CONFIG_GLOBAL=/dev/null
  export GIT_CONFIG_SYSTEM=/dev/null
  export GIT_CONFIG_NOSYSTEM=1
  python3 -c "import pathlib; p = pathlib.Path('$2/fetchDependencies'); p.write_bytes(p.read_bytes().replace(b'\r\n', b'\n'))"
  python3 -c "import pathlib; [p.write_bytes(p.read_bytes().replace(b'\r\n', b'\n')) for p in (pathlib.Path('$2') / 'ExternalRevisions').glob('*') if p.is_file()]"
  $2/fetchDependencies --macos
  echo $CURRENT_VERSION > $VERSION_PATH
fi
