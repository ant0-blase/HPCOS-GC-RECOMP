# Performance baseline

This document records the retained **bootstrap** baseline. It is not a gameplay or
steady-state frame-time baseline.

## Measurement class

- **Bootstrap boundary:** process launch through the first
  `[staticrecomp] core init` log line, followed by an immediate stop.
- **Steady state:** intentionally not represented by the numbers below. Use
  `scripts/perf-benchmark.sh` after the game has reached a repeatable scene.
- Do not compare bootstrap medians with the script's post-warmup `perf stat` window.

## Provenance

| Field | Value |
| --- | --- |
| Date | 2026-08-20 (Europe/Paris) |
| Host | `archlinux` |
| CPU | Intel Core Ultra 7 258V, CPUs 0-3 are the P-core PMU domain |
| Kernel | Linux 7.2.0-rc7-1-cachyos-rc x86_64 |
| Source base | `db93436ae4e040a7a7d42d6ba9a01e6d0949f4b6` on `aurora-probe` |
| Worktree | Dirty; the commit alone does not reproduce the measured source tree |
| Baseline runtime | `/tmp/hpcos-moderngekko-before-hash` |
| Runtime SHA-256 | `3c0c22969fceb3f767b459a2c17a3897098d33b420f70575bb862a8312d537c3` |
| Scenario | Headless startup, temporary user directory, same game/module for A and B |
| Stop condition | First `[staticrecomp] core init` line |
| Retained evidence | `/tmp/hpcos-perf-startup-before.txt`, `/tmp/hpcos-strace-source-before.txt` |

The source tree was held constant apart from the tested runtime patch. The binary
hash, dirty-tree status and retained result files are therefore part of the build
identity; this must not be described as a clean-commit benchmark.

## Bootstrap baseline A

| Metric | Baseline A |
| --- | ---: |
| Core-init wall-time median | 9.11 s |
| `perf stat` task-clock | 8,315.14 ms |
| `readlink` calls in `strace -c` | 1,010,447 |
| Total syscalls in `strace -c` | 1,275,435 |

The wall-time sample count and cache preparation were not preserved with the supplied
summary. Treat 9.11 s as an exact observation from this session, not a portable machine
baseline.

## Establishing a steady-state baseline

Use the same explicit runtime, module, display mode, scene and timing windows for every
variant:

```bash
scripts/perf-benchmark.sh \
  --output /tmp/hpcos-perf \
  --runtime runtime/moderngekko-run \
  --module module/gGHSE69_recomp.so \
  --game extracted \
  --platform wayland \
  --warmup 45 \
  --stat-seconds 30 \
  --record-seconds 30
```

The timestamped result directory records host, date, Git dirtiness, artifact hashes,
resolved command line, affinity, PMU events and build-info files.
