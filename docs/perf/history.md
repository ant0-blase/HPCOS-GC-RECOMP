# Performance history

## 2026-08-20 — core-initialization candidate

- Scope: bootstrap only, from launch to `[staticrecomp] core init`.
- Source base: `db93436ae4e040a7a7d42d6ba9a01e6d0949f4b6`, dirty worktree.
- Runtime A: `3c0c22969fceb3f767b459a2c17a3897098d33b420f70575bb862a8312d537c3`.
- Runtime B: `858a678f71cd273728470aeb01c96c1f9a6c4e9ed7e650c2d1709876de164d02`.
- Core-init median: 9.11 s to 0.21 s.
- Task-clock: 8,315.14 ms to 645.89 ms.
- `readlink`: 1,010,447 to 447 calls.
- Total syscalls: 1,275,435 to 64,080 calls.
- Interpretation: strong bootstrap win; no steady-state claim.

Future entries should link a complete timestamped directory produced by
`scripts/perf-benchmark.sh`, name the gameplay scene, and state whether the run is
bootstrap or steady state.
