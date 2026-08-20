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
- high-rate game VI/render target (60/90/120/144/165/240 FPS) with native-rate fixed simulation
- optional host presentation FPS cap
- runtime audio volume and mute
- keyboard/mouse enable, sensitivity and Y inversion
- direct keyboard/mouse rebinding

HPCOS-specific FOV and aspect values are no longer process-only environment
constants. The renderer, guest FOV synchronization and presentation path read
live atomic runtime values, while the old `HPCOS_FOV` and
`HPCOS_DYNAMIC_ASPECT` environment variables remain valid startup defaults.

There are now two deliberately separate FPS controls:

- **Game FPS** changes GHSE69's VI/render cadence through Dolphin's VI overclock
  path. It does **not** change global emulation speed, so CPU/CoreTiming and
  DSP/audio keep their normal clocks. Reverse engineering of the retail main loop
  (`0x8000BF70`) identifies `0x80038DAC` as the phase-1 gameplay/physics update and
  `0x80038E4C` as the later render phase. At targets above 60 FPS the chassis gates
  the phase-1 update back to the native ~59.94 Hz with a fractional scheduler and
  prevents catch-up paths from executing a second physics step in the same render
  frame. High-rate frames therefore reuse the most recent fixed simulation state;
  visual interpolation is not implemented yet.
- **Presentation FPS cap** only throttles host presentation and never changes the
  guest simulation cadence.

The widescreen path also synchronizes all three GHSE69 aspect globals used by
the original 16:9 patch (`0x8042788C`, `0x80427A74`, `0x8049EC8C`). This keeps
the guest camera/frustum in agreement with the expanded host view instead of
letting 4:3 culling remove objects near the new left/right edges.

Custom FOV is now applied only through GHSE69's game-side camera value. The
generic Dolphin perspective-matrix override was removed because it also altered
auxiliary perspective passes such as shadow/light cameras, which could make
shadows disappear at non-native FOV values.

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
