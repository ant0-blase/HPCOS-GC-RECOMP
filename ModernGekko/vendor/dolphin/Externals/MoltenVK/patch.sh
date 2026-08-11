#!/bin/bash

# Applies all patches in the "patches" folder to the cloned MoltenVK git repository.
#
# Usage: patch.sh <patches folder> <MoltenVK version>
#

set -e

export GIT_CONFIG_GLOBAL=/dev/null
export GIT_CONFIG_SYSTEM=/dev/null
export GIT_CONFIG_NOSYSTEM=1

# Reset the git repository first to ensure that it's in the base state.
git -c core.autocrlf=false reset --hard $2

python3 -c "import pathlib; [p.write_bytes(p.read_bytes().replace(b'\r\n', b'\n')) for p in pathlib.Path('$1').glob('*.patch') if p.is_file()]"
git apply $1/*.patch
