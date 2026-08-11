#!/bin/bash

WAD_PATH="wii_menu/Wii_Menu_v4.3K.wad"
MODULE_PATH="module-template/build/g000002_recomp.dylib"

echo "=== Booting Wii Menu WAD (using Static Recomp Module) ==="

# Ensure permissions on the compiled module are readable
chmod +x "$MODULE_PATH" 2>/dev/null || true

STATICRECOMP_MODULE="$MODULE_PATH" \
STATICRECOMP_VERBOSE=1 \
./build/Binaries/dolphin-emu-nogui -e "$WAD_PATH" -C Dolphin.Core.CPUCore=6
