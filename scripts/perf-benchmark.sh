#!/usr/bin/env bash
set -Eeuo pipefail

export LC_ALL=C

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd -P)"
PROJECT_SLUG="hpcos"
PROJECT_NAME="Harry Potter and the Chamber of Secrets (GHSE69)"
DEFAULT_RUNTIME="$ROOT/runtime/moderngekko-run"
DEFAULT_MODULE="$ROOT/module/gGHSE69_recomp.so"
DEFAULT_GAME="$ROOT/extracted"

RUNTIME="$DEFAULT_RUNTIME"
MODULE="$DEFAULT_MODULE"
GAME="$DEFAULT_GAME"
OUTPUT_ROOT=""
WARMUP_SECONDS=30
STAT_SECONDS=30
RECORD_SECONDS=30
FRAMETIME_SECONDS=0
PLATFORM="auto"
GRAPHICS="Vulkan"
AUDIO="No Audio Output"
DO_BUILD=0
CPUSET="0-3"
GAME_PID=""
GAME_LOG=""
CONTEXT_PID=""
PERF_PID=""
TEMP_ROOT=""
EXTRA_ARGS=()

usage() {
  cat <<'EOF'
Usage:
  scripts/perf-benchmark.sh --output DIR [options] [-- RUNTIME_ARGS...]

Required:
  --output DIR             Parent directory for the timestamped result directory.

Inputs:
  --runtime PATH           Runtime executable (default: runtime/moderngekko-run).
  --module PATH            Native module (default: module/gGHSE69_recomp.so).
  --game DIR               Extracted game root (default: extracted/).
  --build                  Run the repository Release build before benchmarking.

Protocol:
  --warmup SECONDS         Unmeasured warmup after launch (default: 30).
  --stat-seconds SECONDS   perf stat window (default: 30).
  --record-seconds SECONDS perf record window (default: 30).
  --frametime-seconds N    Separate MangoHud capture (default: 0, disabled).
                           It reuses --warmup before logging presented frames.
                           A zero warmup becomes one second for MangoHud.
  --platform MODE          auto, wayland, x11, or headless (default: auto).
  --graphics BACKEND       Graphics backend (default: Vulkan).
  --audio BACKEND          Audio backend (default: No Audio Output).
  -h, --help               Show this help.

The runtime is launched directly with explicit game/module/user paths, pinned to
CPUs 0-3, with RECOMP_SPAM_START=1, RECOMP_SPAM_A=1 and an empty temporary user
directory. Extra arguments after -- are appended to the ModernGekko command line.
Context-switch samples are written beside perf-stat.txt. When enabled, MangoHud
writes its raw frametime CSV and generated summary under frametime/.

Example:
  scripts/perf-benchmark.sh --output /tmp/hpcos-perf \
    --warmup 45 --stat-seconds 30 --record-seconds 30 \
    --frametime-seconds 30
EOF
}

die() {
  printf 'perf-benchmark: %s\n' "$*" >&2
  exit 1
}

need_value() {
  local option="$1"
  local value="${2:-}"
  [[ -n "$value" ]] || die "$option requires a value"
}

is_nonnegative_integer() {
  [[ "$1" =~ ^[0-9]+$ ]]
}

is_positive_integer() {
  [[ "$1" =~ ^[1-9][0-9]*$ ]]
}

while (($#)); do
  case "$1" in
    --output)
      need_value "$1" "${2:-}"
      OUTPUT_ROOT="$2"
      shift 2
      ;;
    --runtime)
      need_value "$1" "${2:-}"
      RUNTIME="$2"
      shift 2
      ;;
    --module)
      need_value "$1" "${2:-}"
      MODULE="$2"
      shift 2
      ;;
    --game)
      need_value "$1" "${2:-}"
      GAME="$2"
      shift 2
      ;;
    --build)
      DO_BUILD=1
      shift
      ;;
    --warmup)
      need_value "$1" "${2:-}"
      WARMUP_SECONDS="$2"
      shift 2
      ;;
    --stat-seconds)
      need_value "$1" "${2:-}"
      STAT_SECONDS="$2"
      shift 2
      ;;
    --record-seconds)
      need_value "$1" "${2:-}"
      RECORD_SECONDS="$2"
      shift 2
      ;;
    --frametime-seconds)
      need_value "$1" "${2:-}"
      FRAMETIME_SECONDS="$2"
      shift 2
      ;;
    --platform)
      need_value "$1" "${2:-}"
      PLATFORM="${2,,}"
      shift 2
      ;;
    --graphics)
      need_value "$1" "${2:-}"
      GRAPHICS="$2"
      shift 2
      ;;
    --audio)
      need_value "$1" "${2:-}"
      AUDIO="$2"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    --)
      shift
      EXTRA_ARGS=("$@")
      break
      ;;
    *)
      die "unknown option: $1"
      ;;
  esac
done

[[ -n "$OUTPUT_ROOT" ]] || die "--output DIR is required"
is_nonnegative_integer "$WARMUP_SECONDS" || die "--warmup must be a non-negative integer"
is_positive_integer "$STAT_SECONDS" || die "--stat-seconds must be a positive integer"
is_positive_integer "$RECORD_SECONDS" || die "--record-seconds must be a positive integer"
is_nonnegative_integer "$FRAMETIME_SECONDS" ||
  die "--frametime-seconds must be a non-negative integer"
case "$PLATFORM" in
  auto|wayland|x11|headless) ;;
  *) die "--platform must be auto, wayland, x11, or headless" ;;
esac

for tool in awk date git hostname lscpu perf pidstat realpath sha256sum taskset; do
  command -v "$tool" >/dev/null 2>&1 || die "required command is missing: $tool"
done

if ((FRAMETIME_SECONDS > 0)); then
  for tool in find grep mangohud sort; do
    command -v "$tool" >/dev/null 2>&1 || die "--frametime-seconds requires: $tool"
  done
fi

mkdir -p -- "$OUTPUT_ROOT"
OUTPUT_ROOT="$(cd -- "$OUTPUT_ROOT" && pwd -P)"
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
RESULT_DIR="$OUTPUT_ROOT/$PROJECT_SLUG-$STAMP"
mkdir -- "$RESULT_DIR"

if ((DO_BUILD)); then
  printf 'Building the Release runtime and module...\n'
  (cd -- "$ROOT" && ./build.sh) 2>&1 | tee "$RESULT_DIR/build.log"
fi

RUNTIME="$(realpath -e -- "$RUNTIME")" || die "runtime does not exist: $RUNTIME"
MODULE="$(realpath -e -- "$MODULE")" || die "module does not exist: $MODULE"
GAME="$(realpath -e -- "$GAME")" || die "game root does not exist: $GAME"
[[ -x "$RUNTIME" ]] || die "runtime is not executable: $RUNTIME"
[[ -f "$MODULE" ]] || die "module is not a regular file: $MODULE"
[[ -f "$GAME/sys/main.dol" ]] || die "game root is missing sys/main.dol: $GAME"

if [[ "$PLATFORM" == "auto" ]]; then
  if [[ -n "${WAYLAND_DISPLAY:-}" ]]; then
    PLATFORM="wayland"
  elif [[ -n "${DISPLAY:-}" ]]; then
    PLATFORM="x11"
  else
    PLATFORM="headless"
  fi
fi

PLATFORM_ARGS=()
case "$PLATFORM" in
  wayland) PLATFORM_ARGS+=(--wayland) ;;
  x11) PLATFORM_ARGS+=(--x11) ;;
  headless) PLATFORM_ARGS+=(--headless) ;;
esac

if ((FRAMETIME_SECONDS > 0)) && [[ "$PLATFORM" == "headless" ]]; then
  die "--frametime-seconds requires wayland or x11 so MangoHud can observe presented frames"
fi

if [[ -d /sys/bus/event_source/devices/cpu_core ]]; then
  STAT_EVENTS="task-clock:u,cpu_core/cycles/u,cpu_core/instructions/u,cpu_core/branches/u,cpu_core/branch-misses/u"
  SAMPLE_EVENT="cpu_core/cycles/u"
else
  STAT_EVENTS="task-clock:u,cycles:u,instructions:u,branches:u,branch-misses:u"
  SAMPLE_EVENT="cycles:u"
fi

taskset -c "$CPUSET" true || die "CPU affinity $CPUSET is not available"
perf stat -e "$SAMPLE_EVENT" -- taskset -c 0 true >/dev/null 2>&1 ||
  die "perf cannot count $SAMPLE_EVENT as the current user"

TEMP_ROOT="$(mktemp -d "${TMPDIR:-/tmp}/$PROJECT_SLUG-perf.XXXXXXXX")"
USER_DIR="$TEMP_ROOT/user"
mkdir -- "$USER_DIR"

stop_game() {
  [[ -n "$GAME_PID" ]] || return 0
  if kill -0 "$GAME_PID" 2>/dev/null; then
    kill -INT "$GAME_PID" 2>/dev/null || true
    for _ in {1..50}; do
      if ! kill -0 "$GAME_PID" 2>/dev/null; then
        wait "$GAME_PID" 2>/dev/null || true
        GAME_PID=""
        return 0
      fi
      sleep 0.1
    done
    kill -TERM "$GAME_PID" 2>/dev/null || true
    for _ in {1..20}; do
      if ! kill -0 "$GAME_PID" 2>/dev/null; then
        wait "$GAME_PID" 2>/dev/null || true
        GAME_PID=""
        return 0
      fi
      sleep 0.1
    done
    kill -KILL "$GAME_PID" 2>/dev/null || true
  fi
  wait "$GAME_PID" 2>/dev/null || true
  GAME_PID=""
}

stop_context_monitor() {
  [[ -n "$CONTEXT_PID" ]] || return 0
  if kill -0 "$CONTEXT_PID" 2>/dev/null; then
    kill -TERM "$CONTEXT_PID" 2>/dev/null || true
  fi
  wait "$CONTEXT_PID" 2>/dev/null || true
  CONTEXT_PID=""
}

stop_perf_monitor() {
  [[ -n "$PERF_PID" ]] || return 0
  if kill -0 "$PERF_PID" 2>/dev/null; then
    kill -TERM "$PERF_PID" 2>/dev/null || true
    for _ in {1..20}; do
      kill -0 "$PERF_PID" 2>/dev/null || break
      sleep 0.1
    done
    if kill -0 "$PERF_PID" 2>/dev/null; then
      kill -KILL "$PERF_PID" 2>/dev/null || true
    fi
  fi
  wait "$PERF_PID" 2>/dev/null || true
  PERF_PID=""
}

cleanup() {
  local status
  status=$?
  trap - EXIT INT TERM HUP
  stop_perf_monitor
  stop_context_monitor
  stop_game
  if [[ -n "$TEMP_ROOT" && -d "$TEMP_ROOT" ]]; then
    case "$TEMP_ROOT" in
      "${TMPDIR:-/tmp}/$PROJECT_SLUG-perf."*) rm -rf -- "$TEMP_ROOT" ;;
      *) printf 'perf-benchmark: refusing to remove unexpected temp path: %s\n' "$TEMP_ROOT" >&2 ;;
    esac
  fi
  exit "$status"
}
trap cleanup EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
trap 'exit 129' HUP

RUNTIME_ARGS=(
  --game "$GAME"
  --module "$MODULE"
  --user-dir "$USER_DIR"
  --graphics "$GRAPHICS"
  --audio "$AUDIO"
  --no-mods
  "${PLATFORM_ARGS[@]}"
  "${EXTRA_ARGS[@]}"
)

GIT_DIRTY_COUNT="$(git -C "$ROOT" status --porcelain=v1 | wc -l)"
GIT_DIRTY_COUNT="${GIT_DIRTY_COUNT//[[:space:]]/}"
{
  printf 'project=%s\n' "$PROJECT_NAME"
  printf 'date_utc=%s\n' "$(date -u --iso-8601=seconds)"
  printf 'host=%s\n' "$(hostname)"
  printf 'kernel=%s\n' "$(uname -srmo)"
  printf 'cpu=%s\n' "$(lscpu | sed -n 's/^Model name:[[:space:]]*//p' | head -n 1)"
  printf 'git_head=%s\n' "$(git -C "$ROOT" rev-parse HEAD)"
  printf 'git_dirty_files=%s\n' "$GIT_DIRTY_COUNT"
  printf 'runtime=%s\n' "$RUNTIME"
  printf 'runtime_sha256=%s\n' "$(sha256sum "$RUNTIME" | awk '{print $1}')"
  printf 'module=%s\n' "$MODULE"
  printf 'module_sha256=%s\n' "$(sha256sum "$MODULE" | awk '{print $1}')"
  printf 'game=%s\n' "$GAME"
  printf 'cpuset=%s\n' "$CPUSET"
  printf 'platform=%s\n' "$PLATFORM"
  printf 'graphics=%s\n' "$GRAPHICS"
  printf 'audio=%s\n' "$AUDIO"
  printf 'recomp_spam_start=1\n'
  printf 'recomp_spam_a=1\n'
  printf 'warmup_seconds=%s\n' "$WARMUP_SECONDS"
  printf 'stat_seconds=%s\n' "$STAT_SECONDS"
  printf 'record_seconds=%s\n' "$RECORD_SECONDS"
  printf 'frametime_seconds=%s\n' "$FRAMETIME_SECONDS"
  printf 'stat_events=%s\n' "$STAT_EVENTS"
  printf 'sample_event=%s\n' "$SAMPLE_EVENT"
  printf 'perf_software_event_note=kernel-side_software_counters_omitted_under_perf_event_paranoid\n'
  printf 'context_switch_source=pidstat_-wt_1s_process_threads\n'
  printf 'perf_attach_scope=process_wide_including_existing_threads\n'
  printf 'perf_event_paranoid=%s\n' "$(cat /proc/sys/kernel/perf_event_paranoid 2>/dev/null || printf unknown)"
  printf 'power_profile=%s\n' "$(powerprofilesctl get 2>/dev/null || printf unknown)"
  printf 'command='
  printf ' %q' taskset -c "$CPUSET" env -u MANGOHUD -u MANGOHUD_CONFIG \
    -u MANGOHUD_CONFIGFILE RECOMP_SPAM_START=1 RECOMP_SPAM_A=1 \
    "$RUNTIME" "${RUNTIME_ARGS[@]}"
  printf '\n'
} >"$RESULT_DIR/metadata.txt"
git -C "$ROOT" status --short --branch >"$RESULT_DIR/git-status.txt"

for info in "$(dirname -- "$RUNTIME")/build-info.txt" "$(dirname -- "$MODULE")/build-info.txt"; do
  if [[ -f "$info" ]]; then
    destination="$(basename -- "$(dirname -- "$info")")-build-info.txt"
    cp -- "$info" "$RESULT_DIR/$destination"
  fi
done

printf 'Results: %s\n' "$RESULT_DIR"
printf 'Launching %s on CPUs %s (platform=%s)...\n' "$PROJECT_NAME" "$CPUSET" "$PLATFORM"
GAME_LOG="$RESULT_DIR/runtime.log"
taskset -c "$CPUSET" env -u MANGOHUD -u MANGOHUD_CONFIG -u MANGOHUD_CONFIGFILE \
  RECOMP_SPAM_START=1 RECOMP_SPAM_A=1 \
  "$RUNTIME" "${RUNTIME_ARGS[@]}" >"$GAME_LOG" 2>&1 &
GAME_PID=$!
printf 'pid=%s\n' "$GAME_PID" >>"$RESULT_DIR/metadata.txt"

ensure_game_running() {
  if kill -0 "$GAME_PID" 2>/dev/null; then
    return 0
  fi
  local game_status=0
  wait "$GAME_PID" || game_status=$?
  GAME_PID=""
  die "runtime exited early with status $game_status; inspect $GAME_LOG"
}

printf 'Warmup: %s seconds (not measured).\n' "$WARMUP_SECONDS"
for ((second = 0; second < WARMUP_SECONDS; ++second)); do
  sleep 1
  ensure_game_running
done

printf 'perf stat: %s seconds.\n' "$STAT_SECONDS"
pidstat -wt -p "$GAME_PID" 1 "$STAT_SECONDS" >"$RESULT_DIR/context-switches-pidstat.txt" &
CONTEXT_PID=$!
perf stat \
  -o "$RESULT_DIR/perf-stat.txt" \
  -e "$STAT_EVENTS" \
  -p "$GAME_PID" \
  --timeout "$((STAT_SECONDS * 1000))" &
PERF_PID=$!
perf_status=0
wait "$PERF_PID" || perf_status=$?
PERF_PID=""
((perf_status == 0)) || die "perf stat failed with status $perf_status"
ensure_game_running

context_status=0
wait "$CONTEXT_PID" || context_status=$?
CONTEXT_PID=""
((context_status == 0)) || die "pidstat failed with status $context_status"

awk -v requested_window="$STAT_SECONDS" '
  $1 != "Average:" &&
  $1 ~ /^[0-9][0-9]:[0-9][0-9]:[0-9][0-9]$/ &&
  $3 == "-" && $4 ~ /^[0-9]+$/ &&
  $5 ~ /^[0-9]+([.][0-9]+)?$/ && $6 ~ /^[0-9]+([.][0-9]+)?$/ {
    if (!($1 in sample_seen)) {
      sample_seen[$1] = 1
      samples++
    }
    thread_seen[$4] = 1
    thread_samples++
    voluntary_rate_sum += $5
    involuntary_rate_sum += $6
  }
  END {
    if (samples == 0)
      exit 2
    for (tid in thread_seen)
      unique_threads++
    printf "source=pidstat -wt (one-second samples)\n"
    printf "requested_window_seconds=%d\n", requested_window
    printf "observed_samples=%d\n", samples
    printf "unique_threads=%d\n", unique_threads
    printf "average_threads_per_sample=%.2f\n", thread_samples / samples
    printf "voluntary_context_switches_per_second=%.2f\n", voluntary_rate_sum / samples
    printf "involuntary_context_switches_per_second=%.2f\n", involuntary_rate_sum / samples
    printf "total_context_switches_per_second=%.2f\n", (voluntary_rate_sum + involuntary_rate_sum) / samples
    printf "estimated_voluntary_context_switches=%.2f\n", voluntary_rate_sum
    printf "estimated_involuntary_context_switches=%.2f\n", involuntary_rate_sum
    printf "note=Totals sum rounded per-thread rates over observed one-second samples; raw per-thread data is in context-switches-pidstat.txt.\n"
  }
' "$RESULT_DIR/context-switches-pidstat.txt" >"$RESULT_DIR/context-switches-summary.txt" ||
  die "could not summarize pidstat output"
ensure_game_running

printf 'perf record: %s seconds.\n' "$RECORD_SECONDS"
perf record \
  -o "$RESULT_DIR/perf.data" \
  -F 499 \
  -e "$SAMPLE_EVENT" \
  -g \
  --call-graph dwarf,8192 \
  -p "$GAME_PID" \
  -- sleep "$RECORD_SECONDS" \
  >"$RESULT_DIR/perf-record.log" 2>&1 &
PERF_PID=$!
perf_status=0
wait "$PERF_PID" || perf_status=$?
PERF_PID=""
((perf_status == 0)) || die "perf record failed with status $perf_status"
ensure_game_running

perf report \
  --stdio \
  --sort comm,dso,symbol \
  --percent-limit 0.5 \
  -i "$RESULT_DIR/perf.data" >"$RESULT_DIR/perf-report.txt"
perf buildid-list -i "$RESULT_DIR/perf.data" >"$RESULT_DIR/perf-buildids.txt"

stop_game

if ((FRAMETIME_SECONDS > 0)); then
  FRAMETIME_DIR="$RESULT_DIR/frametime"
  MANGOHUD_CONFIG_PATH="$RESULT_DIR/MangoHud.conf"
  FRAMETIME_DELAY_SECONDS="$WARMUP_SECONDS"
  if ((FRAMETIME_DELAY_SECONDS == 0)); then
    # MangoHud treats autostart_log=0 as disabled rather than immediate.
    FRAMETIME_DELAY_SECONDS=1
  fi
  mkdir -- "$FRAMETIME_DIR"
  {
    # no_display/preset=0 disables logging in MangoHud 0.8.4. Transparent
    # rendering keeps the capture active without obscuring the game.
    printf 'alpha=0\n'
    printf 'background_alpha=0\n'
    printf 'autostart_log=%s\n' "$FRAMETIME_DELAY_SECONDS"
    printf 'log_duration=%s\n' "$FRAMETIME_SECONDS"
    printf 'log_interval=0\n'
    printf 'output_folder=%s\n' "$FRAMETIME_DIR"
    printf 'permit_upload=0\n'
    printf 'upload_logs=0\n'
  } >"$MANGOHUD_CONFIG_PATH"

  {
    printf 'frametime_warmup_seconds=%s\n' "$FRAMETIME_DELAY_SECONDS"
    printf 'mangohud_version=%s\n' "$(mangohud --version 2>&1)"
    printf 'frametime_command='
    printf ' %q' taskset -c "$CPUSET" env -u MANGOHUD_CONFIG \
      RECOMP_SPAM_START=1 RECOMP_SPAM_A=1 \
      "MANGOHUD_CONFIGFILE=$MANGOHUD_CONFIG_PATH" mangohud "$RUNTIME" "${RUNTIME_ARGS[@]}"
    printf '\n'
  } >>"$RESULT_DIR/metadata.txt"

  printf 'MangoHud frametime run: %s second warmup, %s second capture.\n' \
    "$FRAMETIME_DELAY_SECONDS" "$FRAMETIME_SECONDS"
  GAME_LOG="$RESULT_DIR/frametime-runtime.log"
  taskset -c "$CPUSET" env -u MANGOHUD_CONFIG RECOMP_SPAM_START=1 RECOMP_SPAM_A=1 \
    "MANGOHUD_CONFIGFILE=$MANGOHUD_CONFIG_PATH" \
    mangohud "$RUNTIME" "${RUNTIME_ARGS[@]}" >"$GAME_LOG" 2>&1 &
  GAME_PID=$!
  printf 'frametime_pid=%s\n' "$GAME_PID" >>"$RESULT_DIR/metadata.txt"

  frametime_complete=0
  frametime_deadline=$((FRAMETIME_DELAY_SECONDS + FRAMETIME_SECONDS + 10))
  for ((second = 0; second < frametime_deadline; ++second)); do
    sleep 1
    ensure_game_running
    if ((second + 1 >= FRAMETIME_DELAY_SECONDS + FRAMETIME_SECONDS)) &&
      find "$FRAMETIME_DIR" -maxdepth 1 -type f -name '*_summary.csv' -size +0c \
        -print -quit | grep -q .; then
      frametime_complete=1
      break
    fi
  done

  ((frametime_complete == 1)) ||
    die "MangoHud did not produce a summary; inspect $RESULT_DIR/frametime-runtime.log"
  find "$FRAMETIME_DIR" -maxdepth 1 -type f -name '*.csv' -size +0c \
    -printf '%f\n' | sort >"$RESULT_DIR/frametime-files.txt"
  if ! find "$FRAMETIME_DIR" -maxdepth 1 -type f -name '*.csv' \
    ! -name '*_summary.csv' -size +0c -print -quit | grep -q .; then
    die "MangoHud produced a summary without a raw frametime CSV"
  fi
  stop_game
fi

printf 'Completed. Steady-state results are in %s\n' "$RESULT_DIR"
