# Current performance candidate

The retained current result is a **bootstrap candidate**, not yet a canonical
steady-state gameplay result.

## Provenance

| Field | Value |
| --- | --- |
| Date | 2026-08-20 (Europe/Paris) |
| Host / CPU | `archlinux`; Intel Core Ultra 7 258V |
| Source base | `db93436ae4e040a7a7d42d6ba9a01e6d0949f4b6`, dirty worktree |
| Candidate runtime | `/tmp/hpcos-moderngekko-after-hash` |
| Runtime SHA-256 | `858a678f71cd273728470aeb01c96c1f9a6c4e9ed7e650c2d1709876de164d02` |
| Comparison | Same source tree outside the tested runtime patch; same game/module/scenario |
| Retained evidence | `/tmp/hpcos-perf-startup-after.txt`, `/tmp/hpcos-strace-source-after.txt` |

The hash above identifies the measured candidate. It must not be substituted with the
currently published `runtime/moderngekko-run` unless its SHA-256 matches.

## Bootstrap candidate B

| Metric | Baseline A | Candidate B | Change |
| --- | ---: | ---: | ---: |
| Core-init wall-time median | 9.11 s | 0.21 s | 43.38x faster (-97.69%) |
| `perf stat` task-clock | 8,315.14 ms | 645.89 ms | 12.87x lower (-92.23%) |
| `readlink` calls | 1,010,447 | 447 | 2,260.51x lower (-99.956%) |
| Total syscalls | 1,275,435 | 64,080 | 19.90x lower (-94.98%) |

These measurements end at core initialization and say nothing about gameplay frame
pacing, renderer cost or steady-state native dispatch. The syscall result came from a
separate `strace -c` run and must not be mixed with the `perf stat` task-clock as if both
were collected simultaneously.

## Canonical steady-state result

Status: **pending**. Promote a result here only after a named, repeatable gameplay scene
has completed the scripted warmup, stat and sampling windows. Preserve the generated
`metadata.txt`, `perf-stat.txt`, `perf.data`, `perf-report.txt` and runtime log together.
