#!/usr/bin/env bash
# Scaffold a per-game static-recompilation project from this one.
#
# The heavy part -- ModernGekko with its vendored Dolphin, DolRecomp and every
# CPU optimization -- is shared by symlink rather than copied. One source tree,
# so a fix or an optimization lands in every game at once instead of forking
# into divergent copies. What is per-game is small: the two scripts, and the
# generated build/, port-build/, module/, runtime/ and user/ directories.
#
# Usage:
#   tools/new-game-project.sh <project-dir> <GAME_ID> <window title>
#
# <project-dir> must already contain extracted/sys/{main.dol,boot.bin}; the
# disc id and DOL hash are read from them and pinned into the generated build.

set -uo pipefail

SOURCE_PROJECT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd -P)"

fail() {
  printf 'new-game-project: %s\n' "$*" >&2
  return 1
}

main() {
  if [[ $# -lt 3 ]]; then
    printf 'usage: %s <project-dir> <GAME_ID> <window title>\n' "$0" >&2
    return 2
  fi

  local target game_id title
  target="$1"; game_id="$2"; shift 2; title="$*"

  [[ -d "$target" ]] || { fail "no such directory: $target"; return 1; }
  target="$(cd -- "$target" && pwd -P)"
  [[ "$target" != "$SOURCE_PROJECT" ]] || { fail "refusing to scaffold over the source project"; return 1; }

  local dol="$target/extracted/sys/main.dol"
  [[ -f "$dol" ]] || { fail "missing $dol -- extract the disc there first"; return 1; }

  local dol_sha
  dol_sha="$(sha256sum "$dol" | awk '{print $1}')"

  # Cross-check the requested id against the disc header so a typo cannot pin
  # a build to the wrong game.
  local boot="$target/extracted/sys/boot.bin"
  if [[ -f "$boot" ]]; then
    local disc_id
    disc_id="$(head -c6 "$boot" | tr -d '\0')"
    if [[ "$disc_id" != "$game_id" ]]; then
      fail "disc header says '$disc_id' but '$game_id' was requested"
      return 1
    fi
  fi

  printf 'scaffolding %s\n  game id : %s\n  title   : %s\n  dol     : %s\n' \
    "$target" "$game_id" "$title" "$dol_sha"

  # Shared source tree. A relative symlink keeps both projects movable as long
  # as they stay siblings.
  local link="$target/ModernGekko"
  if [[ -e "$link" && ! -L "$link" ]]; then
    fail "$link exists and is not a symlink; refusing to replace it"
    return 1
  fi
  ln -sfn "$SOURCE_PROJECT/ModernGekko" "$link"

  # build.sh: same script, with the three per-game constants and the window
  # title substituted.
  sed -e "s|^GAME_ID=.*|GAME_ID=\"$game_id\"|" \
      -e "s|^MODULE_NAME=.*|MODULE_NAME=\"g${game_id}_recomp.so\"|" \
      -e "s|^EXPECTED_DOL_SHA256=.*|EXPECTED_DOL_SHA256=\"$dol_sha\"|" \
      -e "s|-DMODERNGEKKO_DEFAULT_WINDOW_TITLE=.*|-DMODERNGEKKO_DEFAULT_WINDOW_TITLE=\"$title\" \\\\|" \
      "$SOURCE_PROJECT/build.sh" > "$target/build.sh" || { fail "cannot write build.sh"; return 1; }
  chmod +x "$target/build.sh"

  # run.sh: only the module name is game-specific. The dynamic widescreen is
  # generic (it derives from the host drawable), but --fov also patches guest
  # camera globals, and those were only ever identified for GHSE69 -- the
  # runtime gates that on the game id, so --fov is a no-op elsewhere until the
  # equivalent globals are found.
  # HPCOS_XFB_OVERSCAN is dropped, not copied: the crop it enables is measured
  # from GHSE69's XFB and would shift the image on any other game.
  sed -e "s|/module/gGHSE69_recomp.so|/module/g${game_id}_recomp.so|" \
      -e "/HPCOS_XFB_OVERSCAN/d" \
      -e "/Overscan border measured on GHSE69/,+2d" \
      "$SOURCE_PROJECT/run.sh" > "$target/run.sh" || { fail "cannot write run.sh"; return 1; }
  chmod +x "$target/run.sh"

  mkdir -p "$target/user/Config"

  # Seed the controller configuration.
  #
  # Two settings that a fresh config does not have, and without which a game can
  # sit on its loading screen forever:
  #
  #   Always Connected -- GCPadEmu reports the emulated pad as *disconnected*
  #   unless this is set or a real bound device is present, and the serial
  #   interface then raises NO RESPONSE on that port.
  #
  #   four ports -- Super Monkey Ball spins in SI initialisation until every
  #   port answers; one configured port is not enough. Disney's Magical Mirror
  #   also gets further with all four.
  for pad in 1 2 3 4; do
    printf '[GCPad%s]\nDevice = SDL/0/Xbox Series X Controller\nOptions/Always Connected = True\n' \
      "$pad" >> "$target/user/Config/GCPadNew.ini"
  done
  printf '[Core]\nSIDevice0 = 6\nSIDevice1 = 6\nSIDevice2 = 6\nSIDevice3 = 6\n' \
    > "$target/user/Config/Dolphin.ini"

  cat > "$target/.gitignore" <<'EOF'
build/
port-build/
recomp/
extracted/
user/
module/
runtime/
.cache/
.releases/
.build.lock
ModernGekko
*.pre-*
*.before-*
perf.data*
EOF

  printf '\n[OK] %s is ready.\n' "$target"
  printf '     build : cd %s && HPCOS_PROFILE=native ./build.sh\n' "$target"
  printf '     run   : cd %s && ./run.sh --widescreen\n' "$target"
  printf '     note  : first build recompiles the whole DOL, expect it to be long.\n'
}

main "$@"
