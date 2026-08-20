// Copyright 2010 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/GCPad.h"

#include <chrono>
#include <cstdlib>
#include <optional>
#include <string_view>

#include "Common/Common.h"
#include "Core/HW/GCPadEmu.h"
#include "InputCommon/ControllerEmu/ControlGroup/ControlGroup.h"
#include "InputCommon/GCPadStatus.h"
#include "InputCommon/InputConfig.h"

namespace Pad
{
namespace
{
using namespace std::chrono_literals;

// GHSE69's unskippable legal/logo sequence reaches the interactive title
// after roughly 17 seconds, so the shorter shared-runtime window expires
// before START can be observed. Keep this bounded, but long enough to cover
// that title transition.
constexpr auto START_SPAM_DURATION = 30s;
constexpr auto START_SPAM_PERIOD = 250ms;
constexpr auto START_SPAM_PRESS = 100ms;
constexpr auto A_SPAM_DURATION = 30s;
constexpr auto A_SPAM_PHASE = 125ms;
constexpr auto A_SPAM_PRESS = 100ms;

constexpr bool IsStartSpamPress(std::chrono::milliseconds elapsed)
{
  return elapsed >= 0ms && elapsed < START_SPAM_DURATION &&
         elapsed % START_SPAM_PERIOD < START_SPAM_PRESS;
}

constexpr bool IsASpamPress(std::chrono::milliseconds elapsed)
{
  if (elapsed < 0ms || elapsed >= A_SPAM_DURATION)
    return false;

  const auto phase = elapsed % START_SPAM_PERIOD;
  return phase >= A_SPAM_PHASE && phase < A_SPAM_PHASE + A_SPAM_PRESS;
}

constexpr bool SpamPressesOverlap()
{
  for (auto elapsed = 0ms; elapsed < START_SPAM_PERIOD; elapsed += 1ms)
  {
    if (IsStartSpamPress(elapsed) && IsASpamPress(elapsed))
      return true;
  }
  return false;
}

static_assert(IsStartSpamPress(0ms));
static_assert(!IsStartSpamPress(100ms));
static_assert(IsStartSpamPress(250ms));
static_assert(!IsStartSpamPress(START_SPAM_DURATION));
static_assert(!IsASpamPress(100ms));
static_assert(IsASpamPress(125ms));
static_assert(!IsASpamPress(225ms));
static_assert(!IsASpamPress(A_SPAM_DURATION));
static_assert(!SpamPressesOverlap());

struct InputSpamState
{
  bool start_enabled = false;
  bool a_enabled = false;
  std::optional<std::chrono::steady_clock::time_point> started;
};

u16 GetInjectedButtons()
{
  static const InputSpamState state = [] {
    const auto enabled = [](const char* name) {
      const char* value = std::getenv(name);
      return value != nullptr && std::string_view(value) == "1";
    };

    InputSpamState result;
    result.start_enabled = enabled("RECOMP_SPAM_START");
    result.a_enabled = enabled("RECOMP_SPAM_A");
    if (result.start_enabled || result.a_enabled)
      result.started = std::chrono::steady_clock::now();
    return result;
  }();
  if (!state.started)
    return 0;

  const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now() - *state.started);

  u16 buttons = 0;
  if (state.start_enabled && IsStartSpamPress(elapsed))
    buttons |= PAD_BUTTON_START;
  if (state.a_enabled && IsASpamPress(elapsed))
    buttons |= PAD_BUTTON_A;
  return buttons;
}
}  // namespace

static InputConfig s_config("GCPadNew", _trans("Pad"), "GCPad", "Pad");
InputConfig* GetConfig()
{
  return &s_config;
}

void Shutdown()
{
  s_config.UnregisterHotplugCallback();

  s_config.ClearControllers();
}

void Initialize()
{
  if (s_config.ControllersNeedToBeCreated())
  {
    for (unsigned int i = 0; i < 4; ++i)
      s_config.CreateController<GCPad>(i);
  }

  s_config.RegisterHotplugCallback();

  // Load the saved controller config
  s_config.LoadConfig();
}

void LoadConfig()
{
  s_config.LoadConfig();
}

void GenerateDynamicInputTextures()
{
  s_config.GenerateControllerTextures();
}

bool IsInitialized()
{
  return !s_config.ControllersNeedToBeCreated();
}

GCPadStatus GetStatus(int pad_num)
{
  GCPadStatus status = static_cast<GCPad*>(s_config.GetController(pad_num))->GetInput();
  const u16 injected_buttons = pad_num == 0 ? GetInjectedButtons() : 0;
  if (injected_buttons != 0)
  {
    status.button |= injected_buttons;
    status.isConnected = true;
  }
  return status;
}

ControllerEmu::ControlGroup* GetGroup(int pad_num, PadGroup group)
{
  return static_cast<GCPad*>(s_config.GetController(pad_num))->GetGroup(group);
}

void Rumble(const int pad_num, const ControlState strength)
{
  static_cast<GCPad*>(s_config.GetController(pad_num))->SetOutput(strength);
}

void ResetRumble(const int pad_num)
{
  static_cast<GCPad*>(s_config.GetController(pad_num))->SetOutput(0.0);
}

bool GetMicButton(const int pad_num)
{
  return static_cast<GCPad*>(s_config.GetController(pad_num))->GetMicButton();
}
}  // namespace Pad
