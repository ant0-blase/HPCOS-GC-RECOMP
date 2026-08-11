#!/bin/sh
# Clones the sibling repositories StrikersRecomp builds against, at the
# pinned release tags. Idempotent: existing checkouts are left alone.
set -e
cd "$(dirname "$0")/.."

clone() {
  dir=$1; url=$2; ref=$3
  if [ -d "$dir" ]; then
    echo "$dir already exists, skipping"
  else
    git clone "$url" "$dir"
    [ -n "$ref" ] && git -C "$dir" checkout "$ref"
  fi
}

clone DolRecomp   https://github.com/aharonahdoot/DolRecomp.git   ""
clone GXRuntime  https://github.com/aharonahdoot/GXRuntime.git  v0.1.0
clone RecompCore  https://github.com/aharonahdoot/RecompCore.git  v0.1.0

cat <<'EOF'

Siblings ready. Next steps:
  1. Generate the recompiled code from your own ISO:
       python3 StrikersRecomp/tools/generate.py --iso /path/to/strikers.iso
     (or --dol /path/to/main.dol; extract it in Dolphin via
      right-click game -> Properties -> Filesystem)
  2. Build a RecompCore module:  StrikersRecomp/tools/package_module.sh
     or the standalone app:      cmake -S StrikersRecomp -B StrikersRecomp/build && cmake --build StrikersRecomp/build -j
EOF
