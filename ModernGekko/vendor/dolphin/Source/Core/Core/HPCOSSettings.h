// SPDX-License-Identifier: GPL-2.0-or-later
// HPCOS PC runtime settings and keyboard/mouse bridge.
#pragma once

#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cstdlib>
#include <mutex>
#include <string>
#include <string_view>

#include "InputCommon/GCPadStatus.h"

namespace HPCOS
{
enum class Action : int
{
  MoveForward,
  MoveBackward,
  MoveLeft,
  MoveRight,
  ButtonA,
  ButtonB,
  ButtonX,
  ButtonY,
  TriggerL,
  TriggerR,
  TriggerZ,
  Start,
  DpadUp,
  DpadDown,
  DpadLeft,
  DpadRight,
  Count
};

inline constexpr std::array<const char*, static_cast<size_t>(Action::Count)> ACTION_NAMES = {
    "Move Forward", "Move Backward", "Move Left", "Move Right", "A / Primary action",
    "B / Secondary action", "X", "Y", "L", "R", "Z", "Start / Pause", "D-Pad Up",
    "D-Pad Down", "D-Pad Left", "D-Pad Right"};

inline constexpr std::array<const char*, static_cast<size_t>(Action::Count)> DEFAULT_BINDINGS = {
    "W", "S", "A", "D", "Mouse1", "Mouse2", "E", "Q", "Shift_L", "Control_L",
    "Mouse3", "Return", "Up", "Down", "Left", "Right"};

inline std::once_flag s_init_once;
inline std::atomic<bool> s_overlay_visible{false};
inline std::atomic<bool> s_dynamic_aspect{false};
inline std::atomic<float> s_aspect_override{0.0f};
inline std::atomic<float> s_fov{0.0f};
inline std::atomic<int> s_fps_cap{0};
inline std::atomic<int> s_game_fps_target{0};
inline std::atomic<bool> s_enhanced_graphics_enabled{false};
inline std::atomic<float> s_enhanced_saturation{1.08f};
inline std::atomic<float> s_enhanced_vibrance{0.12f};
inline std::atomic<float> s_enhanced_contrast{1.06f};
inline std::atomic<float> s_enhanced_exposure{0.03f};
inline std::atomic<float> s_enhanced_gamma{1.00f};
inline std::atomic<float> s_enhanced_temperature{0.02f};
inline std::atomic<float> s_enhanced_sharpen{0.28f};
inline std::atomic<float> s_enhanced_bloom{0.10f};
inline std::atomic<float> s_enhanced_vignette{0.06f};
inline std::atomic<float> s_enhanced_grain{0.00f};
inline std::atomic<bool> s_pc_input_enabled{true};
inline std::atomic<float> s_mouse_sensitivity{1.0f};
inline std::atomic<bool> s_mouse_invert_y{false};
inline std::atomic<int> s_mouse_dx{0};
inline std::atomic<int> s_mouse_dy{0};
inline std::array<std::atomic<bool>, static_cast<size_t>(Action::Count)> s_action_down{};
inline std::array<std::string, static_cast<size_t>(Action::Count)> s_bindings{};
inline std::mutex s_bindings_mutex;
inline std::atomic<int> s_capture_action{-1};
inline std::atomic<unsigned> s_binding_generation{0};

inline void EnsureInitialized()
{
  std::call_once(s_init_once, [] {
    for (size_t i = 0; i < s_bindings.size(); ++i)
      s_bindings[i] = DEFAULT_BINDINGS[i];

    if (const char* env = std::getenv("HPCOS_DYNAMIC_ASPECT"))
      s_dynamic_aspect.store(env[0] == '1', std::memory_order_relaxed);

    if (const char* env = std::getenv("HPCOS_FOV"))
    {
      char* end = nullptr;
      const float value = std::strtof(env, &end);
      if (end != env && *end == '\0' && value >= 30.0f && value <= 150.0f)
        s_fov.store(value, std::memory_order_relaxed);
    }

    if (const char* env = std::getenv("HPCOS_FPS_TARGET"))
    {
      char* end = nullptr;
      const long value = std::strtol(env, &end, 10);
      if (end != env && *end == '\0' && value >= 30 && value <= 1000)
        s_game_fps_target.store(static_cast<int>(value), std::memory_order_relaxed);
    }
  });
}

inline bool OverlayVisible()
{
  EnsureInitialized();
  return s_overlay_visible.load(std::memory_order_relaxed);
}
inline void ResetInput()
{
  for (auto& state : s_action_down)
    state.store(false, std::memory_order_relaxed);
  s_mouse_dx.store(0, std::memory_order_relaxed);
  s_mouse_dy.store(0, std::memory_order_relaxed);
}
inline void SetOverlayVisible(bool visible)
{
  EnsureInitialized();
  s_overlay_visible.store(visible, std::memory_order_relaxed);
  if (!visible)
    s_capture_action.store(-1, std::memory_order_relaxed);
  ResetInput();
}
inline void ToggleOverlay() { SetOverlayVisible(!OverlayVisible()); }
inline bool DynamicAspectEnabled()
{
  EnsureInitialized();
  return s_dynamic_aspect.load(std::memory_order_relaxed);
}
inline void SetDynamicAspectEnabled(bool enabled)
{
  EnsureInitialized();
  s_dynamic_aspect.store(enabled, std::memory_order_relaxed);
}
inline float AspectOverride()
{
  EnsureInitialized();
  return s_aspect_override.load(std::memory_order_relaxed);
}
inline void SetAspectOverride(float aspect)
{
  EnsureInitialized();
  s_aspect_override.store(aspect, std::memory_order_relaxed);
}
inline float Fov()
{
  EnsureInitialized();
  return s_fov.load(std::memory_order_relaxed);
}
inline void SetFov(float fov)
{
  EnsureInitialized();
  s_fov.store((fov >= 30.0f && fov <= 150.0f) ? fov : 0.0f, std::memory_order_relaxed);
}
inline int FpsCap() { return s_fps_cap.load(std::memory_order_relaxed); }
inline void SetFpsCap(int fps) { s_fps_cap.store(std::max(0, fps), std::memory_order_relaxed); }
inline int GameFpsTarget()
{
  EnsureInitialized();
  return s_game_fps_target.load(std::memory_order_relaxed);
}
inline void SetGameFpsTarget(int fps)
{
  EnsureInitialized();
  if (fps != 0)
    fps = std::clamp(fps, 30, 1000);
  s_game_fps_target.store(fps, std::memory_order_relaxed);
}
inline bool EnhancedGraphicsEnabled()
{
  return s_enhanced_graphics_enabled.load(std::memory_order_relaxed);
}
inline void SetEnhancedGraphicsEnabled(bool enabled)
{
  s_enhanced_graphics_enabled.store(enabled, std::memory_order_relaxed);
}
inline float EnhancedSaturation() { return s_enhanced_saturation.load(std::memory_order_relaxed); }
inline void SetEnhancedSaturation(float v) { s_enhanced_saturation.store(std::clamp(v, 0.0f, 2.0f), std::memory_order_relaxed); }
inline float EnhancedVibrance() { return s_enhanced_vibrance.load(std::memory_order_relaxed); }
inline void SetEnhancedVibrance(float v) { s_enhanced_vibrance.store(std::clamp(v, -1.0f, 1.0f), std::memory_order_relaxed); }
inline float EnhancedContrast() { return s_enhanced_contrast.load(std::memory_order_relaxed); }
inline void SetEnhancedContrast(float v) { s_enhanced_contrast.store(std::clamp(v, 0.5f, 1.8f), std::memory_order_relaxed); }
inline float EnhancedExposure() { return s_enhanced_exposure.load(std::memory_order_relaxed); }
inline void SetEnhancedExposure(float v) { s_enhanced_exposure.store(std::clamp(v, -1.0f, 1.0f), std::memory_order_relaxed); }
inline float EnhancedGamma() { return s_enhanced_gamma.load(std::memory_order_relaxed); }
inline void SetEnhancedGamma(float v) { s_enhanced_gamma.store(std::clamp(v, 0.5f, 2.0f), std::memory_order_relaxed); }
inline float EnhancedTemperature() { return s_enhanced_temperature.load(std::memory_order_relaxed); }
inline void SetEnhancedTemperature(float v) { s_enhanced_temperature.store(std::clamp(v, -1.0f, 1.0f), std::memory_order_relaxed); }
inline float EnhancedSharpen() { return s_enhanced_sharpen.load(std::memory_order_relaxed); }
inline void SetEnhancedSharpen(float v) { s_enhanced_sharpen.store(std::clamp(v, 0.0f, 1.5f), std::memory_order_relaxed); }
inline float EnhancedBloom() { return s_enhanced_bloom.load(std::memory_order_relaxed); }
inline void SetEnhancedBloom(float v) { s_enhanced_bloom.store(std::clamp(v, 0.0f, 1.0f), std::memory_order_relaxed); }
inline float EnhancedVignette() { return s_enhanced_vignette.load(std::memory_order_relaxed); }
inline void SetEnhancedVignette(float v) { s_enhanced_vignette.store(std::clamp(v, 0.0f, 1.0f), std::memory_order_relaxed); }
inline float EnhancedGrain() { return s_enhanced_grain.load(std::memory_order_relaxed); }
inline void SetEnhancedGrain(float v) { s_enhanced_grain.store(std::clamp(v, 0.0f, 0.25f), std::memory_order_relaxed); }

inline bool PcInputEnabled() { return s_pc_input_enabled.load(std::memory_order_relaxed); }
inline void SetPcInputEnabled(bool enabled)
{
  s_pc_input_enabled.store(enabled, std::memory_order_relaxed);
  ResetInput();
}
inline float MouseSensitivity() { return s_mouse_sensitivity.load(std::memory_order_relaxed); }
inline void SetMouseSensitivity(float value)
{
  s_mouse_sensitivity.store(std::clamp(value, 0.05f, 8.0f), std::memory_order_relaxed);
}
inline bool MouseInvertY() { return s_mouse_invert_y.load(std::memory_order_relaxed); }
inline void SetMouseInvertY(bool enabled) { s_mouse_invert_y.store(enabled, std::memory_order_relaxed); }

inline const char* ActionName(Action action) { return ACTION_NAMES[static_cast<size_t>(action)]; }
inline std::string Binding(Action action)
{
  std::lock_guard lock(s_bindings_mutex);
  return s_bindings[static_cast<size_t>(action)];
}
inline void SetBinding(Action action, std::string token)
{
  if (token.empty())
    return;
  std::lock_guard lock(s_bindings_mutex);
  s_bindings[static_cast<size_t>(action)] = std::move(token);
  s_binding_generation.fetch_add(1, std::memory_order_relaxed);
  ResetInput();
}
inline void ResetBindings()
{
  std::lock_guard lock(s_bindings_mutex);
  for (size_t i = 0; i < s_bindings.size(); ++i)
    s_bindings[i] = DEFAULT_BINDINGS[i];
  s_binding_generation.fetch_add(1, std::memory_order_relaxed);
  ResetInput();
}
inline unsigned BindingGeneration() { return s_binding_generation.load(std::memory_order_relaxed); }
inline void BeginBindingCapture(Action action)
{
  s_capture_action.store(static_cast<int>(action), std::memory_order_relaxed);
}
inline int CapturingAction() { return s_capture_action.load(std::memory_order_relaxed); }
inline void CancelBindingCapture() { s_capture_action.store(-1, std::memory_order_relaxed); }

inline void OnHostToken(std::string_view token, bool down)
{
  EnsureInitialized();
  if (token.empty())
    return;

  if (down)
  {
    const int capture = s_capture_action.exchange(-1, std::memory_order_relaxed);
    if (capture >= 0 && capture < static_cast<int>(Action::Count))
    {
      SetBinding(static_cast<Action>(capture), std::string(token));
      return;
    }
  }

  if (!PcInputEnabled() || OverlayVisible())
    return;

  std::lock_guard lock(s_bindings_mutex);
  for (size_t i = 0; i < s_bindings.size(); ++i)
  {
    if (s_bindings[i] == token)
      s_action_down[i].store(down, std::memory_order_relaxed);
  }
}

inline void OnMouseMotion(float dx, float dy)
{
  if (!PcInputEnabled() || OverlayVisible())
    return;
  const float sensitivity = MouseSensitivity();
  s_mouse_dx.fetch_add(static_cast<int>(std::lround(dx * sensitivity)), std::memory_order_relaxed);
  s_mouse_dy.fetch_add(static_cast<int>(std::lround(dy * sensitivity)), std::memory_order_relaxed);
}

inline bool Down(Action action)
{
  return s_action_down[static_cast<size_t>(action)].load(std::memory_order_relaxed);
}

inline GCPadStatus MergePadStatus(GCPadStatus pad)
{
  EnsureInitialized();
  if (!PcInputEnabled() || OverlayVisible())
    return pad;

  int x = 0;
  int y = 0;
  if (Down(Action::MoveLeft))
    --x;
  if (Down(Action::MoveRight))
    ++x;
  if (Down(Action::MoveBackward))
    --y;
  if (Down(Action::MoveForward))
    ++y;
  if (x != 0 || y != 0)
  {
    constexpr int cardinal = 112;
    constexpr int diagonal = 80;
    const int magnitude = (x != 0 && y != 0) ? diagonal : cardinal;
    pad.stickX = static_cast<u8>(std::clamp(128 + x * magnitude, 0, 255));
    pad.stickY = static_cast<u8>(std::clamp(128 + y * magnitude, 0, 255));
  }

  const auto press = [&](Action action, u16 mask) {
    if (Down(action))
      pad.button |= mask;
  };
  press(Action::ButtonA, PAD_BUTTON_A);
  press(Action::ButtonB, PAD_BUTTON_B);
  press(Action::ButtonX, PAD_BUTTON_X);
  press(Action::ButtonY, PAD_BUTTON_Y);
  press(Action::TriggerL, PAD_TRIGGER_L);
  press(Action::TriggerR, PAD_TRIGGER_R);
  press(Action::TriggerZ, PAD_TRIGGER_Z);
  press(Action::Start, PAD_BUTTON_START);
  press(Action::DpadUp, PAD_BUTTON_UP);
  press(Action::DpadDown, PAD_BUTTON_DOWN);
  press(Action::DpadLeft, PAD_BUTTON_LEFT);
  press(Action::DpadRight, PAD_BUTTON_RIGHT);
  if (Down(Action::TriggerL))
    pad.triggerLeft = 255;
  if (Down(Action::TriggerR))
    pad.triggerRight = 255;
  if (Down(Action::ButtonA))
    pad.analogA = 255;
  if (Down(Action::ButtonB))
    pad.analogB = 255;

  const int dx = std::clamp(s_mouse_dx.exchange(0, std::memory_order_relaxed), -127, 127);
  int dy = std::clamp(s_mouse_dy.exchange(0, std::memory_order_relaxed), -127, 127);
  if (!MouseInvertY())
    dy = -dy;
  if (dx != 0)
    pad.substickX = static_cast<u8>(std::clamp(128 + dx, 0, 255));
  if (dy != 0)
    pad.substickY = static_cast<u8>(std::clamp(128 + dy, 0, 255));

  return pad;
}
}  // namespace HPCOS
