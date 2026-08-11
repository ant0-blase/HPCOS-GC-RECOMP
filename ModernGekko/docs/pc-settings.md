# PC settings foundation

ModernGekko keeps its user-editable PC settings in `config.ini` at the root of
the selected user directory. The launcher and `moderngekko-run` already share
this file, so the versioned PC schema extends that facility instead of adding a
second configuration source.

`[Settings] schema_version=1` identifies the current schema. Files produced by
the older frontend (the unversioned `[Video]`, `[Input]`, and `[Netplay]`
sections and no `[Settings]` section) remain readable. Saving a loaded legacy
configuration migrates it to the versioned layout. Once `[Settings]` is present,
`schema_version` is mandatory. Unknown keys are ignored for forward-compatible
additions within schema version 1; a missing or unknown schema version is
rejected rather than silently misinterpreted.

## Schema and defaults

| Section | Keys and defaults | Validation |
| --- | --- | --- |
| `Display` | `mode=windowed`, `resolution=desktop`, `aspect_ratio=auto`, `vsync=true` | Mode is `windowed`, `borderless`, or `fullscreen`; resolution is `desktop`, `native`, or `WIDTHxHEIGHT`; aspect ratio is `original`, `16:9`, `16:10`, `21:9`, or `auto`. |
| `Graphics` | `backend=Vulkan`, `internal_resolution=1920x1080`, `anisotropic_filtering=1`, `texture_filtering=default`, `anti_aliasing=1`, `shader_compilation=hybrid` | Backend is Vulkan or OpenGL; filtering, sample count, and shader modes use bounded enumerations; the existing Dolphin EFB-scale validation is retained. |
| `FPS` | `target=original`, `show_in_title=true` | Target is `original`, `30`, `60`, `90`, `120`, `144`, `165`, `240`, or `unlimited`. Persisting a target does not assert that a title has a safe timing patch for it. |
| `Controller` | `device_id=auto`, `profile=default`, `deadzone=0.15`, `sensitivity=1.0`, inversion off, vibration on | Deadzone is 0–1, sensitivity is 0.1–4, and text values must be single-line. `device_id` is intended for a stable SDL GUID or `auto`, not an enumeration index. Legacy Dolphin `controller1` through `controller4` values remain supported during the controller-abstraction transition. |
| `ControllerMappings` | empty | Arbitrary action-to-binding entries with simple action names and single-line values. |
| `Audio` | `backend=auto`, `volume=100`, `muted=false` | Volume is 0–100 and the backend is a bounded single-line identifier. |
| `TexturePacks` | `enabled=false`, `path=texturepacks` | The path must be non-empty and single-line. Relative paths are interpreted from the user directory by future consumers. This reserves configuration for the replacement-texture subsystem without claiming that loading is implemented. |
| `Developer` | debug overlay, verbose logging, and original-texture dumping all disabled | Strict booleans. Original-texture dumping is only a reserved setting until the texture subsystem consumes it. |
| `Netplay` | existing nickname/address/port/buffer defaults | Existing nickname, host, port, and buffer validation is retained. |

`DefaultConfig()`, `ValidateConfig()`, `LoadConfig()`, and `SaveConfig()` are the
shared programmatic entry points. Save validates the complete object, writes and
closes a uniquely named sibling temporary file, and atomically replaces
`config.ini` only after the write succeeds. Rejected settings, write failures,
and replacement failures therefore leave the previous file intact.

## Current integration boundary

The existing runner still consumes the graphics backend, internal resolution,
fullscreen state, FPS title display, controller compatibility values, and
netplay fields. The remaining version-1 fields are a persistent, validated
foundation for later UI, per-game FPS/aspect patches, audio controls, controller
abstraction, and texture replacement. They are deliberately not presented as
live features yet.

## Tests

The two frontend-config variants cover default-file creation, a complete
load/save round trip, category validation, preservation after a rejected save,
failed-publish cleanup, legacy migration, missing/unknown-schema rejection,
malformed developer booleans, and the existing Wii/GameCube controller-profile
generators:

```sh
cmake --build build-llvm20 --target \
  moderngekko_frontend_config_test \
  moderngekko_frontend_config_gamecube_test
ctest --test-dir build-llvm20 --output-on-failure \
  -R '^moderngekko\.frontend_config(_gamecube)?$'
```
