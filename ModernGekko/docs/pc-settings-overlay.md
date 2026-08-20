# HPCOS in-game PC settings overlay

Status: implemented for the HPCOS / GHSE69 runtime on Linux X11 and Wayland.

## Hotkey and rendering

- **Ctrl+F10** toggles the HPCOS PC settings overlay.
- Dolphin's normal **F10** pause hotkey is preserved.
- The overlay is rendered directly inside Dolphin's existing `OnScreenUI` ImGui
  frame, before `ImGui::Render()`.
- Emulation keeps running while the overlay is visible so the menu remains
  responsive.
- `Host_UIBlocksControllerState()` gates normal guest controller input while the
  menu is open.

## Live settings

The current overlay exposes:

- internal EFB resolution scale (1x through 12x)
- V-Sync
- FPS OSD
- original 4:3, automatic host aspect, 16:9, 16:10, 21:9 and 32:9 presets
- live horizontal FOV override
- optional host presentation FPS cap
- runtime audio volume and mute
- keyboard/mouse enable, sensitivity and Y inversion
- direct keyboard/mouse rebinding

HPCOS-specific FOV and aspect values are no longer process-only environment
constants. The renderer, guest FOV synchronization and presentation path read
live atomic runtime values, while the old `HPCOS_FOV` and
`HPCOS_DYNAMIC_ASPECT` environment variables remain valid startup defaults.

The host FPS setting is intentionally a presentation cap only. It does not
alter emulation speed and is not presented as a game-side framerate unlock.

## Keyboard and mouse

Keyboard/mouse input is merged into GameCube controller Port 1, so a normal
controller remains usable at the same time.

Default bindings:

| GameCube input | PC binding |
| --- | --- |
| Main stick | WASD |
| C-stick / camera | Mouse movement |
| A | Mouse 1 |
| B | Mouse 2 |
| X | E |
| Y | Q |
| Z | Mouse 3 |
| L | Left Shift |
| R | Left Ctrl |
| Start | Enter |
| D-pad | Arrow keys |

Selecting a binding in the overlay starts capture; the next keyboard key or
mouse button becomes the new binding. Bindings and menu settings are written to
`HPCOS_PC.ini` in Dolphin/ModernGekko's runtime config directory.

## Platform notes

The source includes both X11 and native Wayland input paths. X11 can be built
and syntax-checked with the dependencies in the normal ModernGekko toolchain.
Native Wayland currently uses surface pointer motion because the runtime does
not yet ship the relative-pointer / pointer-constraints protocol plumbing; a
future pass can add true locked relative mouse input for unlimited camera
rotation on Wayland.

Win32 and macOS input parity are not part of this HPCOS implementation yet.
