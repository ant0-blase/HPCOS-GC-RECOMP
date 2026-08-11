# patches

DolRecomp is used as-is and must not be modified in place. If a fix to DolRecomp
itself ever becomes necessary (for example to handle a self-modifying-code range
that breaks Strikers — see `docs/architecture.md` §5), add it here as a `.patch`
file generated with `git diff`/`diff -u` against the DolRecomp checkout, and
document what it does and why.

No in-place source patches are currently required. The known DolRecomp
single-precision arithmetic emission issue is corrected after generation by
`tools/fix_generated.py`, keeping the reference checkout untouched.
