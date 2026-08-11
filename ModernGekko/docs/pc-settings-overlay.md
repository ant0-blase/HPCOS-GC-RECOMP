# In-game PC settings overlay architecture

Status: design audit, not yet implemented. This document records the smallest
reusable integration path through the existing ModernGekko/Dolphin frontend.
It deliberately contains no game addresses or title-specific behavior.

## Ownership and rendering

`moderngekko-run` should own a game-independent settings-overlay controller and
the validated frontend configuration. Dolphin's `Presenter` already owns the
only in-game ImGui context through `OnScreenUI`; the launcher SDL/ImGui backend
cannot be reused because the emulation window is created by Dolphin's native
platform layer.

Add a draw event inside `OnScreenUI::Finalize()`, after built-in OSD drawing and
before `ImGui::Render()`. Register the overlay with the existing RAII event-hook
facility. This point renders once per presented frame under the ImGui lock;
`before_present_event` is outside that lock and can run for skipped duplicate
presents.

The video-thread draw callback must not perform filesystem I/O, controller
reloads, or other blocking runtime changes. Widget edits enqueue a small host-
side apply command. The host path validates and atomically saves the frontend
configuration, then applies only settings whose Dolphin APIs are safe live.

## Input and visibility

- Default to a configurable F10 edge-triggered toggle; move the existing pause
  binding to Shift+F10. F1 through F8 already select savestate slots.
- Keep emulation running while the overlay is open. Pausing can freeze the
  presentation path that draws the overlay.
- Store visibility atomically. Make `Host_UIBlocksControllerState()` reflect
  it and ensure the input gate remains effective even when background input is
  enabled. Closing clears UI key/button state before guest input resumes.
- Forward keyboard press/release, mouse movement and buttons from each native
  platform to `Presenter` only while the overlay is visible. X11, Wayland,
  Win32 and macOS currently have different incomplete event paths, so platform
  parity is an explicit milestone.
- Enable ImGui keyboard navigation first. Controller navigation should later
  consume a separate raw UI stream, never the gated emulated GameCube pad.

## Initial application policy

Safe candidates for live application through existing Dolphin configuration
and refresh paths are VSync, internal EFB scale, renderer aspect presentation,
anisotropic/texture filtering, supported MSAA modes, shader compilation mode,
volume/mute, high-resolution texture enablement, statistics, and texture dump.

Graphics backend, audio backend, output window mode/resolution, controller
topology/profile and texture-pack search path should initially be marked
restart-required. Backend capabilities must constrain values such as MSAA.
Netplay must lock settings that affect emulation or controller topology.

FPS targets remain unsupported until game timing is proved and patched under
the P6 work. Renderer aspect selection alone is not proper widescreen; Hor+
camera/FOV, HUD and FMV behavior belong to the per-game patch layer.

## Implementation stages

1. Finish and test the versioned settings schema, atomic save and legacy
   migration.
2. Add the `OnScreenUI::Finalize()` draw hook and an initially read-only shell
   with Display, Graphics, Performance, Controller, Audio, Texture Packs,
   Advanced and About categories.
3. Implement F10, keyboard/mouse forwarding, cursor restoration and
   unconditional guest-input gating on X11 and Wayland.
4. Add a host-side apply queue and unit-test exact frontend-to-Dolphin setting
   mappings with a mock adapter.
5. Add Win32/macOS parity, stable SDL device identities, safe controller
   profile reload, then separate controller navigation for ImGui.
6. Manually verify that guest input is neutral while open, recovers on close,
   live changes take effect, restart labels are truthful, and saved settings
   survive relaunch.
