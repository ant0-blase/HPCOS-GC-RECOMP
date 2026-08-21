// Copyright 2023 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "VideoCommon/OnScreenUI.h"

#include "Common/CommonPaths.h"
#include "Common/EnumMap.h"
#include "Common/FileUtil.h"
#include "Common/Profiler.h"
#include "Common/Timer.h"

#include "Core/Achievements/AchievementManager.h"
#include "Core/HPCOSSettings.h"
#include "Core/Config/AchievementSettings.h"
#include "Core/Config/GraphicsSettings.h"
#include "Core/Config/MainSettings.h"
#include "Core/Config/NetplaySettings.h"
#include "Core/Movie.h"
#include "Core/System.h"

#include "VideoCommon/AbstractGfx.h"
#include "VideoCommon/AbstractPipeline.h"
#include "VideoCommon/AbstractShader.h"
#include "VideoCommon/AbstractStagingTexture.h"
#include "VideoCommon/FramebufferShaderGen.h"
#include "VideoCommon/HiresTextures.h"
#include "VideoCommon/NetPlayChatUI.h"
#include "VideoCommon/NetPlayGolfUI.h"
#include "VideoCommon/OnScreenDisplay.h"
#include "VideoCommon/PerformanceMetrics.h"
#include "VideoCommon/PostProcessing.h"
#include "VideoCommon/Present.h"
#include "VideoCommon/Statistics.h"
#include "VideoCommon/TextureCacheBase.h"
#include "VideoCommon/VertexManagerBase.h"
#include "VideoCommon/VideoConfig.h"

#include <fstream>
#include <sstream>

#include <inttypes.h>
#include <algorithm>
#include <cstdlib>
#include <mutex>

#include <imgui.h>
#include <implot.h>

namespace
{

constexpr const char* HPCOS_REMASTER_SHADER = "HPCOS_Remaster";

std::string HpcosHdTexturePath()
{
  return File::GetUserPath(D_HIRESTEXTURES_IDX) + "GHSE69" + DIR_SEP;
}

bool HpcosNearlyEqual(float a, float b)
{
  return std::fabs(a - b) < 0.0005f;
}

void ApplyHpcosEnhancedPreset(int preset)
{
  switch (preset)
  {
  case 0:  // Original / neutral
    HPCOS::SetEnhancedSaturation(1.00f);
    HPCOS::SetEnhancedVibrance(0.00f);
    HPCOS::SetEnhancedContrast(1.00f);
    HPCOS::SetEnhancedExposure(0.00f);
    HPCOS::SetEnhancedGamma(1.00f);
    HPCOS::SetEnhancedTemperature(0.00f);
    HPCOS::SetEnhancedSharpen(0.00f);
    HPCOS::SetEnhancedBloom(0.00f);
    HPCOS::SetEnhancedVignette(0.00f);
    HPCOS::SetEnhancedGrain(0.00f);
    break;
  case 1:  // Remaster balanced
    HPCOS::SetEnhancedSaturation(1.08f);
    HPCOS::SetEnhancedVibrance(0.12f);
    HPCOS::SetEnhancedContrast(1.06f);
    HPCOS::SetEnhancedExposure(0.03f);
    HPCOS::SetEnhancedGamma(1.00f);
    HPCOS::SetEnhancedTemperature(0.02f);
    HPCOS::SetEnhancedSharpen(0.28f);
    HPCOS::SetEnhancedBloom(0.10f);
    HPCOS::SetEnhancedVignette(0.06f);
    HPCOS::SetEnhancedGrain(0.00f);
    break;
  case 2:  // Vibrant
    HPCOS::SetEnhancedSaturation(1.18f);
    HPCOS::SetEnhancedVibrance(0.25f);
    HPCOS::SetEnhancedContrast(1.08f);
    HPCOS::SetEnhancedExposure(0.04f);
    HPCOS::SetEnhancedGamma(1.00f);
    HPCOS::SetEnhancedTemperature(0.04f);
    HPCOS::SetEnhancedSharpen(0.35f);
    HPCOS::SetEnhancedBloom(0.14f);
    HPCOS::SetEnhancedVignette(0.05f);
    HPCOS::SetEnhancedGrain(0.00f);
    break;
  case 3:  // Cinematic
    HPCOS::SetEnhancedSaturation(0.95f);
    HPCOS::SetEnhancedVibrance(0.08f);
    HPCOS::SetEnhancedContrast(1.12f);
    HPCOS::SetEnhancedExposure(-0.02f);
    HPCOS::SetEnhancedGamma(0.96f);
    HPCOS::SetEnhancedTemperature(0.06f);
    HPCOS::SetEnhancedSharpen(0.22f);
    HPCOS::SetEnhancedBloom(0.18f);
    HPCOS::SetEnhancedVignette(0.15f);
    HPCOS::SetEnhancedGrain(0.015f);
    break;
  default:
    break;
  }
}

int DetectHpcosEnhancedPreset()
{
  struct Preset
  {
    float saturation, vibrance, contrast, exposure, gamma, temperature, sharpen, bloom, vignette,
        grain;
  };
  constexpr Preset presets[] = {
      {1.00f, 0.00f, 1.00f, 0.00f, 1.00f, 0.00f, 0.00f, 0.00f, 0.00f, 0.000f},
      {1.08f, 0.12f, 1.06f, 0.03f, 1.00f, 0.02f, 0.28f, 0.10f, 0.06f, 0.000f},
      {1.18f, 0.25f, 1.08f, 0.04f, 1.00f, 0.04f, 0.35f, 0.14f, 0.05f, 0.000f},
      {0.95f, 0.08f, 1.12f, -0.02f, 0.96f, 0.06f, 0.22f, 0.18f, 0.15f, 0.015f},
  };

  const float current[] = {HPCOS::EnhancedSaturation(), HPCOS::EnhancedVibrance(),
                           HPCOS::EnhancedContrast(), HPCOS::EnhancedExposure(),
                           HPCOS::EnhancedGamma(), HPCOS::EnhancedTemperature(),
                           HPCOS::EnhancedSharpen(), HPCOS::EnhancedBloom(),
                           HPCOS::EnhancedVignette(), HPCOS::EnhancedGrain()};
  for (int p = 0; p < 4; ++p)
  {
    const float values[] = {presets[p].saturation, presets[p].vibrance, presets[p].contrast,
                            presets[p].exposure, presets[p].gamma, presets[p].temperature,
                            presets[p].sharpen, presets[p].bloom, presets[p].vignette,
                            presets[p].grain};
    bool match = true;
    for (size_t i = 0; i < std::size(current); ++i)
      match &= HpcosNearlyEqual(current[i], values[i]);
    if (match)
      return p;
  }
  return 4;  // Custom
}

void SetHpcosPostFloat(VideoCommon::PostProcessingConfiguration* config, const char* option,
                       float value)
{
  if (!config)
    return;
  const auto it = config->GetOptions().find(option);
  if (it == config->GetOptions().end() || it->second.m_float_values.empty())
    return;
  if (!HpcosNearlyEqual(it->second.m_float_values[0], value))
    config->SetOptionf(option, 0, value);
}

void ApplyHpcosEnhancedGraphics()
{
  const bool enabled = HPCOS::EnhancedGraphicsEnabled();
  const std::string current_shader = Config::Get(Config::GFX_ENHANCE_POST_SHADER);
  if (enabled && current_shader != HPCOS_REMASTER_SHADER)
    Config::SetCurrent(Config::GFX_ENHANCE_POST_SHADER, std::string(HPCOS_REMASTER_SHADER));
  else if (!enabled && current_shader == HPCOS_REMASTER_SHADER)
    Config::SetCurrent(Config::GFX_ENHANCE_POST_SHADER, std::string{});

  if (!enabled || !g_presenter || !g_presenter->GetPostProcessor())
    return;

  auto* config = g_presenter->GetPostProcessor()->GetConfig();
  if (!config || config->GetShader() != HPCOS_REMASTER_SHADER)
    return;  // The VideoConfig change will load it on the next frame.

  SetHpcosPostFloat(config, "HPCOS_SATURATION", HPCOS::EnhancedSaturation());
  SetHpcosPostFloat(config, "HPCOS_VIBRANCE", HPCOS::EnhancedVibrance());
  SetHpcosPostFloat(config, "HPCOS_CONTRAST", HPCOS::EnhancedContrast());
  SetHpcosPostFloat(config, "HPCOS_EXPOSURE", HPCOS::EnhancedExposure());
  SetHpcosPostFloat(config, "HPCOS_GAMMA", HPCOS::EnhancedGamma());
  SetHpcosPostFloat(config, "HPCOS_TEMPERATURE", HPCOS::EnhancedTemperature());
  SetHpcosPostFloat(config, "HPCOS_SHARPEN", HPCOS::EnhancedSharpen());
  SetHpcosPostFloat(config, "HPCOS_BLOOM", HPCOS::EnhancedBloom());
  SetHpcosPostFloat(config, "HPCOS_VIGNETTE", HPCOS::EnhancedVignette());
  SetHpcosPostFloat(config, "HPCOS_GRAIN", HPCOS::EnhancedGrain());
}

std::string HpcosPcSettingsPath()
{
  return File::GetUserPath(D_CONFIG_IDX) + "HPCOS_PC.ini";
}

void SaveHpcosPcSettings()
{
  std::ofstream out(HpcosPcSettingsPath(), std::ios::trunc);
  if (!out)
    return;

  out << "# HPCOS PC Edition runtime settings - edited with Ctrl+F10\n";
  out << "dynamic_aspect=" << (HPCOS::DynamicAspectEnabled() ? 1 : 0) << '\n';
  out << "aspect_override=" << HPCOS::AspectOverride() << '\n';
  out << "fov=" << HPCOS::Fov() << '\n';
  out << "fps_cap=" << HPCOS::FpsCap() << '\n';
  out << "game_fps=" << HPCOS::GameFpsTarget() << '\n';
  out << "enhanced_graphics=" << (HPCOS::EnhancedGraphicsEnabled() ? 1 : 0) << '\n';
  out << "enhanced_saturation=" << HPCOS::EnhancedSaturation() << '\n';
  out << "enhanced_vibrance=" << HPCOS::EnhancedVibrance() << '\n';
  out << "enhanced_contrast=" << HPCOS::EnhancedContrast() << '\n';
  out << "enhanced_exposure=" << HPCOS::EnhancedExposure() << '\n';
  out << "enhanced_gamma=" << HPCOS::EnhancedGamma() << '\n';
  out << "enhanced_temperature=" << HPCOS::EnhancedTemperature() << '\n';
  out << "enhanced_sharpen=" << HPCOS::EnhancedSharpen() << '\n';
  out << "enhanced_bloom=" << HPCOS::EnhancedBloom() << '\n';
  out << "enhanced_vignette=" << HPCOS::EnhancedVignette() << '\n';
  out << "enhanced_grain=" << HPCOS::EnhancedGrain() << '\n';
  out << "hd_textures=" << (Config::Get(Config::GFX_HIRES_TEXTURES) ? 1 : 0) << '\n';
  out << "cache_hd_textures=" << (Config::Get(Config::GFX_CACHE_HIRES_TEXTURES) ? 1 : 0) << '\n';
  out << "enhanced_anisotropy=" << static_cast<int>(Config::Get(Config::GFX_ENHANCE_MAX_ANISOTROPY)) << '\n';
  out << "enhanced_texture_filter=" << static_cast<int>(Config::Get(Config::GFX_ENHANCE_FORCE_TEXTURE_FILTERING)) << '\n';
  out << "enhanced_true_color=" << (Config::Get(Config::GFX_ENHANCE_FORCE_TRUE_COLOR) ? 1 : 0) << '\n';
  out << "enhanced_disable_copy_filter=" << (Config::Get(Config::GFX_ENHANCE_DISABLE_COPY_FILTER) ? 1 : 0) << '\n';
  out << "pc_input=" << (HPCOS::PcInputEnabled() ? 1 : 0) << '\n';
  out << "mouse_sensitivity=" << HPCOS::MouseSensitivity() << '\n';
  out << "mouse_invert_y=" << (HPCOS::MouseInvertY() ? 1 : 0) << '\n';
  out << "internal_resolution=" << Config::Get(Config::GFX_EFB_SCALE) << '\n';
  out << "vsync=" << (Config::Get(Config::GFX_VSYNC) ? 1 : 0) << '\n';
  out << "show_fps=" << (Config::Get(Config::GFX_SHOW_FPS) ? 1 : 0) << '\n';
  out << "audio_volume=" << Config::Get(Config::MAIN_AUDIO_VOLUME) << '\n';
  out << "audio_muted=" << (Config::Get(Config::MAIN_AUDIO_MUTED) ? 1 : 0) << '\n';
  for (int i = 0; i < static_cast<int>(HPCOS::Action::Count); ++i)
    out << "bind." << i << '=' << HPCOS::Binding(static_cast<HPCOS::Action>(i)) << '\n';
}

void LoadHpcosPcSettingsOnce()
{
  static bool loaded = false;
  if (loaded)
    return;
  loaded = true;

  std::ifstream in(HpcosPcSettingsPath());
  if (!in)
    return;

  std::string line;
  while (std::getline(in, line))
  {
    if (line.empty() || line[0] == '#')
      continue;
    const size_t eq = line.find('=');
    if (eq == std::string::npos)
      continue;
    const std::string key = line.substr(0, eq);
    const std::string value = line.substr(eq + 1);
    if (key == "dynamic_aspect")
      HPCOS::SetDynamicAspectEnabled(std::atoi(value.c_str()) != 0);
    else if (key == "aspect_override")
      HPCOS::SetAspectOverride(std::strtof(value.c_str(), nullptr));
    else if (key == "fov")
      HPCOS::SetFov(std::strtof(value.c_str(), nullptr));
    else if (key == "fps_cap")
      HPCOS::SetFpsCap(std::atoi(value.c_str()));
    else if (key == "game_fps")
      HPCOS::SetGameFpsTarget(std::atoi(value.c_str()));
    else if (key == "enhanced_graphics")
      HPCOS::SetEnhancedGraphicsEnabled(std::atoi(value.c_str()) != 0);
    else if (key == "enhanced_saturation")
      HPCOS::SetEnhancedSaturation(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_vibrance")
      HPCOS::SetEnhancedVibrance(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_contrast")
      HPCOS::SetEnhancedContrast(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_exposure")
      HPCOS::SetEnhancedExposure(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_gamma")
      HPCOS::SetEnhancedGamma(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_temperature")
      HPCOS::SetEnhancedTemperature(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_sharpen")
      HPCOS::SetEnhancedSharpen(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_bloom")
      HPCOS::SetEnhancedBloom(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_vignette")
      HPCOS::SetEnhancedVignette(std::strtof(value.c_str(), nullptr));
    else if (key == "enhanced_grain")
      HPCOS::SetEnhancedGrain(std::strtof(value.c_str(), nullptr));
    else if (key == "hd_textures")
      Config::SetCurrent(Config::GFX_HIRES_TEXTURES, std::atoi(value.c_str()) != 0);
    else if (key == "cache_hd_textures")
      Config::SetCurrent(Config::GFX_CACHE_HIRES_TEXTURES, std::atoi(value.c_str()) != 0);
    else if (key == "enhanced_anisotropy")
      Config::SetCurrent(Config::GFX_ENHANCE_MAX_ANISOTROPY,
                         static_cast<AnisotropicFilteringMode>(std::clamp(std::atoi(value.c_str()), -1, 4)));
    else if (key == "enhanced_texture_filter")
      Config::SetCurrent(Config::GFX_ENHANCE_FORCE_TEXTURE_FILTERING,
                         static_cast<TextureFilteringMode>(std::clamp(std::atoi(value.c_str()), 0, 2)));
    else if (key == "enhanced_true_color")
      Config::SetCurrent(Config::GFX_ENHANCE_FORCE_TRUE_COLOR, std::atoi(value.c_str()) != 0);
    else if (key == "enhanced_disable_copy_filter")
      Config::SetCurrent(Config::GFX_ENHANCE_DISABLE_COPY_FILTER, std::atoi(value.c_str()) != 0);
    else if (key == "pc_input")
      HPCOS::SetPcInputEnabled(std::atoi(value.c_str()) != 0);
    else if (key == "mouse_sensitivity")
      HPCOS::SetMouseSensitivity(std::strtof(value.c_str(), nullptr));
    else if (key == "mouse_invert_y")
      HPCOS::SetMouseInvertY(std::atoi(value.c_str()) != 0);
    else if (key == "internal_resolution")
      Config::SetCurrent(Config::GFX_EFB_SCALE, std::clamp(std::atoi(value.c_str()), 1, 12));
    else if (key == "vsync")
      Config::SetCurrent(Config::GFX_VSYNC, std::atoi(value.c_str()) != 0);
    else if (key == "show_fps")
      Config::SetCurrent(Config::GFX_SHOW_FPS, std::atoi(value.c_str()) != 0);
    else if (key == "audio_volume")
      Config::SetCurrent(Config::MAIN_AUDIO_VOLUME, std::clamp(std::atoi(value.c_str()), 0, 100));
    else if (key == "audio_muted")
      Config::SetCurrent(Config::MAIN_AUDIO_MUTED, std::atoi(value.c_str()) != 0);
    else if (key.rfind("bind.", 0) == 0)
    {
      const int index = std::atoi(key.c_str() + 5);
      if (index >= 0 && index < static_cast<int>(HPCOS::Action::Count))
        HPCOS::SetBinding(static_cast<HPCOS::Action>(index), value);
    }
  }
}

void DrawHpcosPcSettings()
{
  LoadHpcosPcSettingsOnce();
  ApplyHpcosEnhancedGraphics();
  if (!HPCOS::OverlayVisible())
    return;

  ImGuiIO& io = ImGui::GetIO();
  ImGui::SetNextWindowSize(ImVec2(std::min(760.0f, io.DisplaySize.x * 0.86f),
                                 std::min(620.0f, io.DisplaySize.y * 0.88f)),
                           ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f),
                          ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

  if (!ImGui::Begin("HPCOS PC Settings  |  Ctrl+F10", nullptr,
                    ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
  {
    ImGui::End();
    return;
  }

  ImGui::TextUnformatted("Harry Potter and the Chamber of Secrets - PC runtime controls");
  ImGui::Separator();

  bool changed = false;
  if (ImGui::BeginTabBar("##hpcos-tabs"))
  {
    if (ImGui::BeginTabItem("Graphics"))
    {
      int scale = Config::Get(Config::GFX_EFB_SCALE);
      const char* resolutions[] = {"1x Native (640x528)", "2x (~720p)", "3x (~1080p)",
                                   "4x (~1440p)", "5x", "6x (~4K)", "7x", "8x (~5K)",
                                   "9x", "10x", "11x", "12x (~8K)"};
      int index = std::clamp(scale, 1, 12) - 1;
      if (ImGui::Combo("Internal resolution", &index, resolutions, 12))
      {
        Config::SetCurrent(Config::GFX_EFB_SCALE, index + 1);
        changed = true;
      }

      bool vsync = Config::Get(Config::GFX_VSYNC);
      if (ImGui::Checkbox("V-Sync", &vsync))
      {
        Config::SetCurrent(Config::GFX_VSYNC, vsync);
        changed = true;
      }
      bool show_fps = Config::Get(Config::GFX_SHOW_FPS);
      if (ImGui::Checkbox("Show FPS overlay", &show_fps))
      {
        Config::SetCurrent(Config::GFX_SHOW_FPS, show_fps);
        changed = true;
      }

      int aspect_index = 0;
      const float override_aspect = HPCOS::AspectOverride();
      if (HPCOS::DynamicAspectEnabled())
      {
        if (std::fabs(override_aspect - 16.0f / 9.0f) < 0.01f) aspect_index = 2;
        else if (std::fabs(override_aspect - 16.0f / 10.0f) < 0.01f) aspect_index = 3;
        else if (std::fabs(override_aspect - 21.0f / 9.0f) < 0.02f) aspect_index = 4;
        else if (std::fabs(override_aspect - 32.0f / 9.0f) < 0.02f) aspect_index = 5;
        else aspect_index = 1;
      }
      const char* aspects[] = {"Original 4:3", "Auto / window", "16:9", "16:10", "21:9", "32:9"};
      if (ImGui::Combo("Aspect ratio", &aspect_index, aspects, 6))
      {
        if (aspect_index == 0)
        {
          HPCOS::SetDynamicAspectEnabled(false);
          HPCOS::SetAspectOverride(0.0f);
          Config::SetCurrent(Config::GFX_ASPECT_RATIO, AspectMode::ForceStandard);
        }
        else
        {
          HPCOS::SetDynamicAspectEnabled(true);
          const float values[] = {0.0f, 0.0f, 16.0f / 9.0f, 16.0f / 10.0f, 21.0f / 9.0f, 32.0f / 9.0f};
          HPCOS::SetAspectOverride(values[aspect_index]);
          Config::SetCurrent(Config::GFX_ASPECT_RATIO, AspectMode::Stretch);
        }
        changed = true;
      }

      bool fov_override = HPCOS::Fov() > 0.0f;
      if (ImGui::Checkbox("Custom FOV", &fov_override))
      {
        HPCOS::SetFov(fov_override ? 90.0f : 0.0f);
        changed = true;
      }
      if (fov_override)
      {
        float fov = HPCOS::Fov();
        if (ImGui::SliderFloat("Horizontal FOV", &fov, 50.0f, 130.0f, "%.0f deg"))
        {
          HPCOS::SetFov(fov);
          changed = true;
        }
      }

      int game_fps = HPCOS::GameFpsTarget();
      const int game_fps_values[] = {0, 60, 90, 120, 144, 165, 240};
      const char* game_fps_labels[] = {"Original timing", "60", "90", "120", "144", "165", "240"};
      int game_fps_index = 0;
      for (int i = 0; i < 7; ++i)
        if (game_fps == game_fps_values[i]) game_fps_index = i;
      if (ImGui::Combo("Game FPS", &game_fps_index, game_fps_labels, 7))
      {
        HPCOS::SetGameFpsTarget(game_fps_values[game_fps_index]);
        changed = true;
      }
      ImGui::TextDisabled("High-rate VI/render; gameplay + physics stays at native 59.94 Hz. Audio/DSP remains real-time.");

      int fps = HPCOS::FpsCap();
      const int fps_values[] = {0, 30, 60, 90, 120, 144, 165, 240};
      const char* fps_labels[] = {"Uncapped presentation", "30", "60", "90", "120", "144", "165", "240"};
      int fps_index = 0;
      for (int i = 0; i < 8; ++i)
        if (fps == fps_values[i]) fps_index = i;
      if (ImGui::Combo("Presentation FPS cap", &fps_index, fps_labels, 8))
      {
        HPCOS::SetFpsCap(fps_values[fps_index]);
        changed = true;
      }
      ImGui::TextDisabled("Presentation cap only; it does not alter the guest simulation clock.");
      ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Enhanced Graphics"))
    {
      bool enhanced = HPCOS::EnhancedGraphicsEnabled();
      if (ImGui::Checkbox("Enable HPCOS Remaster post-processing", &enhanced))
      {
        HPCOS::SetEnhancedGraphicsEnabled(enhanced);
        changed = true;
      }
      ImGui::TextDisabled("Runs after the original GameCube image. Changes are live and do not alter game logic.");

      ImGui::SeparatorText("Rendering quality");
      int anisotropy_index = static_cast<int>(Config::Get(Config::GFX_ENHANCE_MAX_ANISOTROPY)) + 1;
      const char* anisotropy_labels[] = {"Default / game", "1x", "2x", "4x", "8x", "16x"};
      anisotropy_index = std::clamp(anisotropy_index, 0, 5);
      if (ImGui::Combo("Anisotropic filtering", &anisotropy_index, anisotropy_labels, 6))
      {
        Config::SetCurrent(Config::GFX_ENHANCE_MAX_ANISOTROPY,
                           static_cast<AnisotropicFilteringMode>(anisotropy_index - 1));
        changed = true;
      }

      int filtering = static_cast<int>(Config::Get(Config::GFX_ENHANCE_FORCE_TEXTURE_FILTERING));
      filtering = std::clamp(filtering, 0, 2);
      const char* filtering_labels[] = {"Original texture filtering", "Force nearest", "Force linear"};
      if (ImGui::Combo("Texture filtering", &filtering, filtering_labels, 3))
      {
        Config::SetCurrent(Config::GFX_ENHANCE_FORCE_TEXTURE_FILTERING,
                           static_cast<TextureFilteringMode>(filtering));
        changed = true;
      }
      bool true_color = Config::Get(Config::GFX_ENHANCE_FORCE_TRUE_COLOR);
      if (ImGui::Checkbox("Force 24-bit color", &true_color))
      {
        Config::SetCurrent(Config::GFX_ENHANCE_FORCE_TRUE_COLOR, true_color);
        changed = true;
      }
      bool disable_copy_filter = Config::Get(Config::GFX_ENHANCE_DISABLE_COPY_FILTER);
      if (ImGui::Checkbox("Disable original copy filter (cleaner image)", &disable_copy_filter))
      {
        Config::SetCurrent(Config::GFX_ENHANCE_DISABLE_COPY_FILTER, disable_copy_filter);
        changed = true;
      }

      ImGui::SeparatorText("Remaster look");
      int preset = DetectHpcosEnhancedPreset();
      const char* presets[] = {"Original / neutral", "Remaster balanced", "Vibrant",
                               "Cinematic", "Custom"};
      if (ImGui::Combo("Preset", &preset, presets, 5) && preset < 4)
      {
        ApplyHpcosEnhancedPreset(preset);
        HPCOS::SetEnhancedGraphicsEnabled(true);
        changed = true;
      }

      float saturation = HPCOS::EnhancedSaturation();
      if (ImGui::SliderFloat("Saturation", &saturation, 0.0f, 2.0f, "%.2fx"))
      {
        HPCOS::SetEnhancedSaturation(saturation);
        changed = true;
      }
      float vibrance = HPCOS::EnhancedVibrance();
      if (ImGui::SliderFloat("Vibrance", &vibrance, -1.0f, 1.0f, "%+.2f"))
      {
        HPCOS::SetEnhancedVibrance(vibrance);
        changed = true;
      }
      float contrast = HPCOS::EnhancedContrast();
      if (ImGui::SliderFloat("Contrast", &contrast, 0.5f, 1.8f, "%.2fx"))
      {
        HPCOS::SetEnhancedContrast(contrast);
        changed = true;
      }
      float exposure = HPCOS::EnhancedExposure();
      if (ImGui::SliderFloat("Exposure / brightness", &exposure, -1.0f, 1.0f, "%+.2f EV"))
      {
        HPCOS::SetEnhancedExposure(exposure);
        changed = true;
      }
      float gamma = HPCOS::EnhancedGamma();
      if (ImGui::SliderFloat("Gamma", &gamma, 0.5f, 2.0f, "%.2f"))
      {
        HPCOS::SetEnhancedGamma(gamma);
        changed = true;
      }
      float temperature = HPCOS::EnhancedTemperature();
      if (ImGui::SliderFloat("Color temperature", &temperature, -1.0f, 1.0f, "%+.2f"))
      {
        HPCOS::SetEnhancedTemperature(temperature);
        changed = true;
      }

      ImGui::SeparatorText("Detail / lens");
      float sharpen = HPCOS::EnhancedSharpen();
      if (ImGui::SliderFloat("Sharpen", &sharpen, 0.0f, 1.5f, "%.2f"))
      {
        HPCOS::SetEnhancedSharpen(sharpen);
        changed = true;
      }
      float bloom = HPCOS::EnhancedBloom();
      if (ImGui::SliderFloat("Bloom", &bloom, 0.0f, 1.0f, "%.2f"))
      {
        HPCOS::SetEnhancedBloom(bloom);
        changed = true;
      }
      float vignette = HPCOS::EnhancedVignette();
      if (ImGui::SliderFloat("Vignette", &vignette, 0.0f, 1.0f, "%.2f"))
      {
        HPCOS::SetEnhancedVignette(vignette);
        changed = true;
      }
      float grain = HPCOS::EnhancedGrain();
      if (ImGui::SliderFloat("Film grain", &grain, 0.0f, 0.25f, "%.3f"))
      {
        HPCOS::SetEnhancedGrain(grain);
        changed = true;
      }

      if (ImGui::Button("Reset graphics to neutral"))
      {
        ApplyHpcosEnhancedPreset(0);
        changed = true;
      }
      ImGui::SameLine();
      if (ImGui::Button("Apply remaster preset"))
      {
        ApplyHpcosEnhancedPreset(1);
        HPCOS::SetEnhancedGraphicsEnabled(true);
        changed = true;
      }

      ImGui::SeparatorText("HD Texture Pack");
      bool hd_textures = Config::Get(Config::GFX_HIRES_TEXTURES);
      if (ImGui::Checkbox("Load custom / HD textures", &hd_textures))
      {
        Config::SetCurrent(Config::GFX_HIRES_TEXTURES, hd_textures);
        changed = true;
      }
      bool cache_hd = Config::Get(Config::GFX_CACHE_HIRES_TEXTURES);
      if (ImGui::Checkbox("Preload HD textures in RAM", &cache_hd))
      {
        Config::SetCurrent(Config::GFX_CACHE_HIRES_TEXTURES, cache_hd);
        changed = true;
      }

      const std::string hd_path = HpcosHdTexturePath();
      ImGui::TextWrapped("Texture pack folder: %s", hd_path.c_str());
      ImGui::TextDisabled("Drop Dolphin-format PNG/DDS replacements here (tex1_*.png / tex1_*.dds). Game ID: GHSE69.");

      if (ImGui::Button("Enable & load HD textures"))
      {
        File::CreateFullPath(hd_path);
        Config::SetCurrent(Config::GFX_HIRES_TEXTURES, true);
        changed = true;
        OSD::AddMessage("HPCOS: HD textures enabled. Loading GHSE69 texture pack.",
                        OSD::Duration::NORMAL);
      }
      ImGui::SameLine();
      if (ImGui::Button("Reload HD textures now"))
      {
        File::CreateFullPath(hd_path);
        if (g_ActiveConfig.bHiresTextures)
        {
          HiresTexture::Clear();
          HiresTexture::Update();
          if (g_texture_cache)
            g_texture_cache->Invalidate();
          OSD::AddMessage("HPCOS: HD texture pack reloaded.", OSD::Duration::NORMAL);
        }
        else
        {
          Config::SetCurrent(Config::GFX_HIRES_TEXTURES, true);
          OSD::AddMessage("HPCOS: HD textures enabled; reload starts on the next video frame.",
                          OSD::Duration::NORMAL);
        }
        changed = true;
      }
      ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Keyboard + Mouse"))
    {
      bool enabled = HPCOS::PcInputEnabled();
      if (ImGui::Checkbox("Enable keyboard + mouse (Port 1, merged with gamepad)", &enabled))
      {
        HPCOS::SetPcInputEnabled(enabled);
        changed = true;
      }
      float sensitivity = HPCOS::MouseSensitivity();
      if (ImGui::SliderFloat("Mouse sensitivity", &sensitivity, 0.10f, 5.0f, "%.2fx"))
      {
        HPCOS::SetMouseSensitivity(sensitivity);
        changed = true;
      }
      bool invert_y = HPCOS::MouseInvertY();
      if (ImGui::Checkbox("Invert mouse Y", &invert_y))
      {
        HPCOS::SetMouseInvertY(invert_y);
        changed = true;
      }
      ImGui::SeparatorText("Bindings");
      ImGui::TextDisabled("Click a binding, then press a keyboard key or mouse button.");
      for (int i = 0; i < static_cast<int>(HPCOS::Action::Count); ++i)
      {
        const auto action = static_cast<HPCOS::Action>(i);
        ImGui::PushID(i);
        ImGui::AlignTextToFramePadding();
        ImGui::TextUnformatted(HPCOS::ActionName(action));
        ImGui::SameLine(260.0f);
        std::string label = HPCOS::CapturingAction() == i ? "Press a key..." : HPCOS::Binding(action);
        if (ImGui::Button(label.c_str(), ImVec2(180.0f, 0.0f)))
          HPCOS::BeginBindingCapture(action);
        ImGui::PopID();
      }
      if (ImGui::Button("Reset default bindings"))
      {
        HPCOS::ResetBindings();
        changed = true;
      }
      ImGui::SameLine();
      if (HPCOS::CapturingAction() >= 0 && ImGui::Button("Cancel rebind"))
        HPCOS::CancelBindingCapture();
      ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Audio / QoL"))
    {
      int volume = Config::Get(Config::MAIN_AUDIO_VOLUME);
      if (ImGui::SliderInt("Volume", &volume, 0, 100, "%d%%"))
      {
        Config::SetCurrent(Config::MAIN_AUDIO_VOLUME, volume);
        changed = true;
      }
      bool muted = Config::Get(Config::MAIN_AUDIO_MUTED);
      if (ImGui::Checkbox("Mute", &muted))
      {
        Config::SetCurrent(Config::MAIN_AUDIO_MUTED, muted);
        changed = true;
      }
      ImGui::Spacing();
      ImGui::TextWrapped("Ctrl+F10 opens/closes this menu. F10 keeps Dolphin's normal pause hotkey. "
                         "Gamepad input stays available alongside keyboard and mouse.");
      ImGui::EndTabItem();
    }
    ImGui::EndTabBar();
  }

  static unsigned last_generation = HPCOS::BindingGeneration();
  const unsigned generation = HPCOS::BindingGeneration();
  if (generation != last_generation)
  {
    last_generation = generation;
    changed = true;
  }
  if (changed)
    SaveHpcosPcSettings();

  ImGui::Separator();
  ImGui::TextDisabled("Press Ctrl+F10 to close this menu.");
  ImGui::End();
}
}  // namespace

namespace VideoCommon
{
bool OnScreenUI::Initialize(u32 width, u32 height, float scale)
{
  std::unique_lock<std::mutex> imgui_lock(m_imgui_mutex);

  if (!IMGUI_CHECKVERSION())
  {
    PanicAlertFmt("ImGui version check failed");
    return false;
  }
  if (!ImGui::CreateContext())
  {
    PanicAlertFmt("Creating ImGui context failed");
    return false;
  }
  if (!ImPlot::CreateContext())
  {
    PanicAlertFmt("Creating ImPlot context failed");
    return false;
  }

  // Don't create an ini file. TODO: Do we want this in the future?
  ImGui::GetIO().IniFilename = nullptr;
  SetScale(scale);

  PortableVertexDeclaration vdecl = {};
  vdecl.position = {ComponentFormat::Float, 2, offsetof(ImDrawVert, pos), true, false};
  vdecl.texcoords[0] = {ComponentFormat::Float, 2, offsetof(ImDrawVert, uv), true, false};
  vdecl.colors[0] = {ComponentFormat::UByte, 4, offsetof(ImDrawVert, col), true, false};
  vdecl.stride = sizeof(ImDrawVert);
  m_imgui_vertex_format = g_gfx->CreateNativeVertexFormat(vdecl);
  if (!m_imgui_vertex_format)
  {
    PanicAlertFmt("Failed to create ImGui vertex format");
    return false;
  }

  // Font defaults
  ImGuiIO& io = ImGui::GetIO();
  m_imgui_textures.clear();

  // User supplied font
  std::string file = File::GetUserPath(D_LOAD_IDX) + "OSD_Font.ttf";

  bool font_exists = File::Exists(file);
  if (!font_exists)
  {
    // Default supplied font
    file = File::GetSysDirectory() + DIR_SEP + RESOURCES_DIR + DIR_SEP + "OSD_Font.ttf";
    font_exists = File::Exists(file);
  }

  if (font_exists)
  {
    io.Fonts->Clear();
    io.Fonts->AddFontFromFileTTF(file.c_str());
  }

  // Setup new font management behavior
  io.BackendFlags |= ImGuiBackendFlags_RendererHasTextures | ImGuiBackendFlags_RendererHasVtxOffset;

  if (!RecompileImGuiPipeline())
    return false;

  m_imgui_last_frame_time = Common::Timer::NowUs();
  m_ready = true;
  BeginImGuiFrameUnlocked(width, height);  // lock is already held

  return true;
}

OnScreenUI::~OnScreenUI()
{
  std::unique_lock<std::mutex> imgui_lock(m_imgui_mutex);

  ImGui::EndFrame();
  ImPlot::DestroyContext();
  ImGui::DestroyContext();
  m_imgui_textures.clear();
}

bool OnScreenUI::RecompileImGuiPipeline()
{
  if (g_presenter->GetBackbufferFormat() == AbstractTextureFormat::Undefined)
  {
    // No backbuffer (nogui) means no imgui rendering will happen
    // Some backends don't like making pipelines with no render targets
    return true;
  }

  const bool linear_space_output =
      g_presenter->GetBackbufferFormat() == AbstractTextureFormat::RGBA16F;

  std::unique_ptr<AbstractShader> vertex_shader = g_gfx->CreateShaderFromSource(
      ShaderStage::Vertex, FramebufferShaderGen::GenerateImGuiVertexShader(), nullptr,
      "ImGui vertex shader");
  std::unique_ptr<AbstractShader> pixel_shader = g_gfx->CreateShaderFromSource(
      ShaderStage::Pixel, FramebufferShaderGen::GenerateImGuiPixelShader(linear_space_output),
      nullptr, "ImGui pixel shader");
  if (!vertex_shader || !pixel_shader)
  {
    PanicAlertFmt("Failed to compile ImGui shaders");
    return false;
  }

  // GS is used to render the UI to both eyes in stereo modes.
  std::unique_ptr<AbstractShader> geometry_shader;
  if (g_gfx->UseGeometryShaderForUI())
  {
    geometry_shader = g_gfx->CreateShaderFromSource(
        ShaderStage::Geometry, FramebufferShaderGen::GeneratePassthroughGeometryShader(1, 1),
        nullptr, "ImGui passthrough geometry shader");
    if (!geometry_shader)
    {
      PanicAlertFmt("Failed to compile ImGui geometry shader");
      return false;
    }
  }

  AbstractPipelineConfig pconfig = {};
  pconfig.vertex_format = m_imgui_vertex_format.get();
  pconfig.vertex_shader = vertex_shader.get();
  pconfig.geometry_shader = geometry_shader.get();
  pconfig.pixel_shader = pixel_shader.get();
  pconfig.rasterization_state = RenderState::GetNoCullRasterizationState(PrimitiveType::Triangles);
  pconfig.depth_state = RenderState::GetNoDepthTestingDepthState();
  pconfig.blending_state = RenderState::GetNoBlendingBlendState();
  pconfig.blending_state.blend_enable = true;
  pconfig.blending_state.src_factor = SrcBlendFactor::SrcAlpha;
  pconfig.blending_state.dst_factor = DstBlendFactor::InvSrcAlpha;
  pconfig.blending_state.src_factor_alpha = SrcBlendFactor::Zero;
  pconfig.blending_state.dst_factor_alpha = DstBlendFactor::One;
  pconfig.framebuffer_state.color_texture_format = g_presenter->GetBackbufferFormat();
  pconfig.framebuffer_state.depth_texture_format = AbstractTextureFormat::Undefined;
  pconfig.framebuffer_state.samples = 1;
  pconfig.framebuffer_state.per_sample_shading = false;
  pconfig.usage = AbstractPipelineUsage::Utility;
  m_imgui_pipeline = g_gfx->CreatePipeline(pconfig);
  if (!m_imgui_pipeline)
  {
    PanicAlertFmt("Failed to create imgui pipeline");
    return false;
  }

  return true;
}

void OnScreenUI::BeginImGuiFrame(u32 width, u32 height)
{
  std::unique_lock<std::mutex> imgui_lock(m_imgui_mutex);
  BeginImGuiFrameUnlocked(width, height);
}

void OnScreenUI::BeginImGuiFrameUnlocked(u32 width, u32 height)
{
  m_backbuffer_width = width;
  m_backbuffer_height = height;

  const u64 current_time_us = Common::Timer::NowUs();
  const u64 time_diff_us = current_time_us - m_imgui_last_frame_time;
  const float time_diff_secs = static_cast<float>(time_diff_us / 1000000.0);
  m_imgui_last_frame_time = current_time_us;

  // Update I/O with window dimensions.
  ImGuiIO& io = ImGui::GetIO();
  io.DisplaySize =
      ImVec2(static_cast<float>(m_backbuffer_width), static_cast<float>(m_backbuffer_height));
  io.DeltaTime = time_diff_secs;

  ImGui::NewFrame();
}

void OnScreenUI::DrawImGui()
{
  ImDrawData* draw_data = ImGui::GetDrawData();
  if (!draw_data)
    return;

  g_gfx->SetViewport(0.0f, 0.0f, static_cast<float>(m_backbuffer_width),
                     static_cast<float>(m_backbuffer_height), 0.0f, 1.0f);

  // Uniform buffer for draws.
  struct ImGuiUbo
  {
    float u_rcp_viewport_size_mul2[2];
    float padding[2];
  };
  ImGuiUbo ubo = {{1.0f / m_backbuffer_width * 2.0f, 1.0f / m_backbuffer_height * 2.0f}};

  // Set up common state for drawing.
  g_gfx->SetPipeline(m_imgui_pipeline.get());
  g_gfx->SetSamplerState(0, RenderState::GetPointSamplerState());
  g_vertex_manager->UploadUtilityUniforms(&ubo, sizeof(ubo));

  for (int i = 0; i < draw_data->CmdListsCount; i++)
  {
    const ImDrawList* cmdlist = draw_data->CmdLists[i];
    if (cmdlist->VtxBuffer.empty() || cmdlist->IdxBuffer.empty())
      return;

    u32 base_vertex, base_index;
    g_vertex_manager->UploadUtilityVertices(cmdlist->VtxBuffer.Data, sizeof(ImDrawVert),
                                            cmdlist->VtxBuffer.Size, cmdlist->IdxBuffer.Data,
                                            cmdlist->IdxBuffer.Size, &base_vertex, &base_index);

    for (const ImDrawCmd& cmd : cmdlist->CmdBuffer)
    {
      if (cmd.UserCallback)
      {
        cmd.UserCallback(cmdlist, &cmd);
        continue;
      }

      g_gfx->SetScissorRect(g_gfx->ConvertFramebufferRectangle(
          MathUtil::Rectangle<int>(
              static_cast<int>(cmd.ClipRect.x), static_cast<int>(cmd.ClipRect.y),
              static_cast<int>(cmd.ClipRect.z), static_cast<int>(cmd.ClipRect.w)),
          g_gfx->GetCurrentFramebuffer()));
      g_gfx->SetTexture(0, reinterpret_cast<const AbstractTexture*>(cmd.GetTexID()));
      g_gfx->DrawIndexed(base_index, cmd.ElemCount, base_vertex);
      base_index += cmd.ElemCount;
    }
  }

  // Some capture software (such as OBS) hooks SwapBuffers and uses glBlitFramebuffer to copy our
  // back buffer just before swap. Because glBlitFramebuffer honors the scissor test, the capture
  // itself will be clipped to whatever bounds were last set by ImGui, resulting in a rather useless
  // capture whenever any ImGui windows are open. We'll reset the scissor rectangle to the entire
  // viewport here to avoid this problem.
  g_gfx->SetScissorRect(g_gfx->ConvertFramebufferRectangle(
      MathUtil::Rectangle<int>(0, 0, m_backbuffer_width, m_backbuffer_height),
      g_gfx->GetCurrentFramebuffer()));
}

// Create On-Screen-Messages
void OnScreenUI::DrawDebugText()
{
  if (Config::Get(Config::MAIN_MOVIE_SHOW_OSD))
  {
    // Position under the FPS display.
    ImGui::SetNextWindowPos(
        ImVec2(ImGui::GetIO().DisplaySize.x - ImGui::GetFontSize() * m_backbuffer_scale,
               80.f * m_backbuffer_scale),
        ImGuiCond_FirstUseEver, ImVec2(1.0f, 0.0f));
    ImGui::SetNextWindowSizeConstraints(ImVec2(5.0f * ImGui::GetFontSize() * m_backbuffer_scale,
                                               2.1f * ImGui::GetFontSize() * m_backbuffer_scale),
                                        ImGui::GetIO().DisplaySize);
    if (ImGui::Begin("Movie", nullptr, ImGuiWindowFlags_NoFocusOnAppearing))
    {
      auto& movie = Core::System::GetInstance().GetMovie();
      if (movie.IsPlayingInput())
      {
        ImGui::Text("Frame: %" PRIu64 " / %" PRIu64, movie.GetCurrentFrame(),
                    movie.GetTotalFrames());
        ImGui::Text("Input: %" PRIu64 " / %" PRIu64, movie.GetCurrentInputCount(),
                    movie.GetTotalInputCount());
      }
      else if (Config::Get(Config::MAIN_SHOW_FRAME_COUNT))
      {
        ImGui::Text("Frame: %" PRIu64, movie.GetCurrentFrame());
        if (movie.IsRecordingInput())
          ImGui::Text("Input: %" PRIu64, movie.GetCurrentInputCount());
      }
      if (Config::Get(Config::MAIN_SHOW_LAG))
        ImGui::Text("Lag: %" PRIu64 "\n", movie.GetCurrentLagCount());
      if (Config::Get(Config::MAIN_MOVIE_SHOW_INPUT_DISPLAY))
        ImGui::TextUnformatted(movie.GetInputDisplay().c_str());
      if (Config::Get(Config::MAIN_MOVIE_SHOW_RTC))
        ImGui::TextUnformatted(movie.GetRTCDisplay().c_str());
      if (Config::Get(Config::MAIN_MOVIE_SHOW_RERECORD))
        ImGui::TextUnformatted(movie.GetRerecords().c_str());
    }
    ImGui::End();
  }

  if (g_ActiveConfig.bOverlayStats)
    g_stats.Display();

  if (Config::Get(Config::GFX_SHOW_NETPLAY_MESSAGES) && g_netplay_chat_ui)
    g_netplay_chat_ui->Display();

  if (Config::Get(Config::NETPLAY_GOLF_MODE_OVERLAY) && g_netplay_golf_ui)
    g_netplay_golf_ui->Display();

  if (g_ActiveConfig.bOverlayProjStats)
    g_stats.DisplayProj();

  if (g_ActiveConfig.bOverlayScissorStats)
    g_stats.DisplayScissor();

  const std::string profile_output = Common::Profiler::ToString();
  if (!profile_output.empty())
    ImGui::TextUnformatted(profile_output.c_str());
}

void OnScreenUI::DrawChallengesAndLeaderboards()
{
  if (!Config::Get(Config::MAIN_OSD_MESSAGES))
    return;
#ifdef USE_RETRO_ACHIEVEMENTS
  auto& instance = AchievementManager::GetInstance();
  std::lock_guard lg{instance.GetLock()};
  const bool challenge_indicators_enabled = Config::Get(Config::RA_CHALLENGE_INDICATORS_ENABLED);
  const bool challenges_updated = instance.AreChallengesUpdated();
  const auto& challenges = instance.GetActiveChallenges();

  if (!challenge_indicators_enabled)
  {
    if (challenges_updated)
      instance.ResetChallengesUpdated();
    if (!m_challenge_texture_map.empty())
      m_challenge_texture_map.clear();
  }
  else if (challenges_updated || m_challenge_texture_map.size() != challenges.size())
  {
    if (challenges_updated)
      instance.ResetChallengesUpdated();
    m_challenge_texture_map.clear();
    for (const auto& name : challenges)
    {
      const auto& icon = instance.GetAchievementBadge(name, false);
      const u32 width = icon.width;
      const u32 height = icon.height;
      TextureConfig tex_config(width, height, 1, 1, 1, AbstractTextureFormat::RGBA8, 0,
                               AbstractTextureType::Texture_2DArray);
      auto res = m_challenge_texture_map.insert_or_assign(name, g_gfx->CreateTexture(tex_config));
      res.first->second->Load(0, width, height, width, icon.data.data(),
                              sizeof(u32) * width * height);
    }
  }

  float leaderboard_y = ImGui::GetIO().DisplaySize.y;
  if (challenge_indicators_enabled && !m_challenge_texture_map.empty())
  {
    float scale = ImGui::GetIO().DisplaySize.y / 1024.0;
    ImGui::SetNextWindowSize(ImVec2(0, 0));
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), 0,
                            ImVec2(1, 1));
    if (ImGui::Begin("Challenges", nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs |
                         ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings |
                         ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoNav |
                         ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing))
    {
      for (auto& [name, texture] : m_challenge_texture_map)
      {
        ImGui::Image(*texture.get(), ImVec2(static_cast<float>(texture->GetWidth()) * scale,
                                            static_cast<float>(texture->GetHeight()) * scale));
        ImGui::SameLine();
      }
    }
    leaderboard_y -= ImGui::GetWindowHeight();
    ImGui::End();
  }

  const auto& leaderboard_progress = instance.GetActiveLeaderboards();
  if (Config::Get(Config::RA_LEADERBOARD_TRACKER_ENABLED) && !leaderboard_progress.empty())
  {
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x, leaderboard_y), 0,
                            ImVec2(1.0, 1.0));
    ImGui::SetNextWindowSize(ImVec2(0.0f, 0.0f));
    if (ImGui::Begin("Leaderboards", nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs |
                         ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings |
                         ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoNav |
                         ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing))
    {
      for (const auto& value : leaderboard_progress)
        ImGui::TextUnformatted(value.c_str());
    }
    ImGui::End();
  }
#endif  // USE_RETRO_ACHIEVEMENTS
}

void OnScreenUI::Finalize()
{
  auto lock = GetImGuiLock();

  auto& perf_metrics = Core::System::GetInstance().GetPerfMetrics();
  perf_metrics.DrawImGuiStats(m_backbuffer_scale);
  DrawDebugText();
  OSD::DrawMessages();
  DrawChallengesAndLeaderboards();
  DrawHpcosPcSettings();
  ImGui::Render();

  // Check for font changes
  ImGuiStyle& style = ImGui::GetStyle();
  const int size = Config::Get(Config::MAIN_OSD_FONT_SIZE);
  if (size != style.FontSizeBase)
    style.FontSizeBase = static_cast<float>(size);

  // Create or update fonts.
  ImDrawData* draw_data = ImGui::GetDrawData();
  if (draw_data->Textures != nullptr)
    for (ImTextureData* tex : *draw_data->Textures)
      if (tex->Status != ImTextureStatus_OK)
        UpdateImguiTexture(tex);
}

void OnScreenUI::UpdateImguiTexture(ImTextureData* tex)
{
  if (tex->Status == ImTextureStatus_WantCreate)
  {
    // Create new font texture.
    IM_ASSERT(tex->TexID == ImTextureID_Invalid);
    IM_ASSERT(tex->Format == ImTextureFormat_RGBA32);

    TextureConfig font_tex_config(tex->Width, tex->Height, 1, 1, 1, AbstractTextureFormat::RGBA8, 0,
                                  AbstractTextureType::Texture_2DArray);
    std::unique_ptr<AbstractTexture> font_tex =
        g_gfx->CreateTexture(font_tex_config, "ImGui font texture");

    if (!font_tex)
    {
      PanicAlertFmt("Failed to create ImGui texture");
      return;
    }

    font_tex->Load(0, tex->Width, tex->Height, tex->Width, tex->Pixels,
                   sizeof(u32) * tex->Width * tex->Height);

    tex->SetTexID(static_cast<ImTextureID>(*font_tex.get()));
    // Keeps the texture alive.
    m_imgui_textures.push_back(std::move(font_tex));
    tex->SetStatus(ImTextureStatus_OK);
  }
  else if (tex->Status == ImTextureStatus_WantUpdates)
  {
    AbstractTexture* font_tex = reinterpret_cast<AbstractTexture*>(tex->GetTexID());

    if (!font_tex || tex->TexID == ImTextureID_Invalid)
    {
      PanicAlertFmt("ImGui texture not created before update");
      return;
    }

    for (const ImTextureRect& r : tex->Updates)
    {
      // Rect of texture that will be updated.
      const int x_offset = static_cast<int>(r.x);
      const int y_offset = static_cast<int>(r.y);
      const int width = static_cast<int>(r.w);
      const int height = static_cast<int>(r.h);

      // Create a staging texture to update the font texture with.
      TextureConfig font_tex_config(width, height, 1, 1, 1, AbstractTextureFormat::RGBA8, 0,
                                    AbstractTextureType::Texture_2DArray);
      std::unique_ptr<AbstractStagingTexture> stage =
          g_gfx->CreateStagingTexture(StagingTextureType::Upload, font_tex_config);

      const int src_pitch = width * tex->BytesPerPixel;

      // Write to staging texture.
      for (int y = 0; y < height; y++)
      {
        const MathUtil::Rectangle<int> rect_line = {0, y, width, y + 1};
        stage->WriteTexels(rect_line, tex->GetPixelsAt(x_offset, y_offset + y), src_pitch);
      }

      // Copy to font texture.
      const MathUtil::Rectangle<int> rect_staging = {0, 0, width, height};
      const MathUtil::Rectangle<int> rect_target = {x_offset, y_offset, width + x_offset,
                                                    height + y_offset};

      stage->CopyToTexture(rect_staging, font_tex, rect_target, 0, 0);
    }

    tex->SetStatus(ImTextureStatus_OK);
  }
  else if (tex->Status == ImTextureStatus_WantDestroy && tex->UnusedFrames > 0)
  {
    AbstractTexture* font_tex = reinterpret_cast<AbstractTexture*>(tex->GetTexID());

    tex->SetTexID(ImTextureID_Invalid);

    m_imgui_textures.erase(
        std::find_if(m_imgui_textures.begin(), m_imgui_textures.end(),
                     [font_tex](auto& element) { return element.get() == font_tex; }));

    tex->Status = ImTextureStatus_Destroyed;
  }
}

std::unique_lock<std::mutex> OnScreenUI::GetImGuiLock()
{
  return std::unique_lock<std::mutex>(m_imgui_mutex);
}

void OnScreenUI::SetScale(float backbuffer_scale)
{
  ImGui::GetIO().DisplayFramebufferScale.x = backbuffer_scale;
  ImGui::GetIO().DisplayFramebufferScale.y = backbuffer_scale;

  // ScaleAllSizes scales in-place, so calling it twice will double-apply the scale
  // Reset the style first so that the scale is applied to the base style, not an already-scaled one
  ImGuiStyle& style = ImGui::GetStyle();
  style = {};
  style.FontScaleMain = backbuffer_scale;
  style.WindowRounding = 7.0f;
  style.ScaleAllSizes(backbuffer_scale);

  m_backbuffer_scale = backbuffer_scale;
}
void OnScreenUI::SetKeyMap(const DolphinKeyMap& key_map)
{
  static constexpr DolphinKeyMap dolphin_to_imgui_map = {
      ImGuiKey_Tab,       ImGuiKey_LeftArrow, ImGuiKey_RightArrow, ImGuiKey_UpArrow,
      ImGuiKey_DownArrow, ImGuiKey_PageUp,    ImGuiKey_PageDown,   ImGuiKey_Home,
      ImGuiKey_End,       ImGuiKey_Insert,    ImGuiKey_Delete,     ImGuiKey_Backspace,
      ImGuiKey_Space,     ImGuiKey_Enter,     ImGuiKey_Escape,     ImGuiKey_KeypadEnter,
      ImGuiKey_A,         ImGuiKey_C,         ImGuiKey_V,          ImGuiKey_X,
      ImGuiKey_Y,         ImGuiKey_Z,
  };

  auto lock = GetImGuiLock();

  if (!ImGui::GetCurrentContext())
    return;

  m_dolphin_to_imgui_map.clear();
  for (int dolphin_key = 0; dolphin_key <= static_cast<int>(DolphinKey::Z); dolphin_key++)
  {
    const int imgui_key = dolphin_to_imgui_map[DolphinKey(dolphin_key)];
    if (imgui_key >= 0)
    {
      const int mapped_key = key_map[DolphinKey(dolphin_key)];
      m_dolphin_to_imgui_map[mapped_key & 0x1FF] = imgui_key;
    }
  }
}

void OnScreenUI::SetKey(u32 key, bool is_down, const char* chars)
{
  auto lock = GetImGuiLock();
  if (auto iter = m_dolphin_to_imgui_map.find(key); iter != m_dolphin_to_imgui_map.end())
    ImGui::GetIO().AddKeyEvent((ImGuiKey)iter->second, is_down);

  if (chars)
    ImGui::GetIO().AddInputCharactersUTF8(chars);
}

void OnScreenUI::SetMousePos(float x, float y)
{
  auto lock = GetImGuiLock();

  ImGui::GetIO().AddMousePosEvent(x, y);
}

void OnScreenUI::SetMousePress(u32 button_mask)
{
  auto lock = GetImGuiLock();

  for (size_t i = 0; i < std::size(ImGui::GetIO().MouseDown); i++)
  {
    ImGui::GetIO().AddMouseButtonEvent(static_cast<int>(i), (button_mask & (1u << i)) != 0);
  }
}

}  // namespace VideoCommon
