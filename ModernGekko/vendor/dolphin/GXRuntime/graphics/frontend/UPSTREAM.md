# Aurora upstream provenance

GXRuntime-owned Aurora recomp-mode work is rooted against the standalone
reference checkout:

- upstream: `https://github.com/encounter/aurora`
- observed commit: `05495810ba4bc906f4f9a131cb5792011b3f35c4`
- short name: `0549581 Migrate remaining GX functions to FIFO`

The workspace `aurora/` checkout is a PRISTINE read-only reference of that
commit. Do not patch or edit it; builds do not read it.

**The full vendored fork anticipated below was materialized 2026-07-03
: `GXRuntime/graphics/aurora/`** — baseline = upstream `0549581` +
the seven bootstrap patches folded in (see that directory's `UPSTREAM.md`).
The patch stack (`patches/*.patch` + `apply-patches.sh`) is retired/deleted;
Aurora changes are normal commits in the fork.

Current owned materialization:

- vendored hard fork: `GXRuntime/graphics/aurora/`;
- direct Aurora injected replay fixture: `tests/recomp_fifo_test.cpp`;
- separately buildable frontend/sink module:
  `GXRuntime::retail_gx_frontend` and `GXRuntime::aurora_render_sink`.
