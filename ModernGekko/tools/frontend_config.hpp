#pragma once

#include <cstdint>
#include <filesystem>
#include <map>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace moderngekko::frontend {
struct ResolutionOption {
  const char *text;
  int dolphin_scale;
};

struct GraphicsBackendOption {
  const char *text;
  const char *value;
};

inline constexpr std::uint32_t CONFIG_SCHEMA_VERSION = 1;

struct ConfigResult {
  // Display. `resolution` remains the internal EFB resolution used by the
  // current launcher; `display_resolution` describes the future PC window or
  // monitor mode and is intentionally not applied by the runtime yet.
  std::string display_mode = "windowed";
  std::string display_resolution = "desktop";
  std::string aspect_ratio = "auto";
  bool vsync = true;

  // Graphics and frame pacing. These settings are persisted now so future
  // frontends and per-game patches can share one validated schema.
  int dolphin_scale = 0;
  std::string resolution = "1920x1080";
  std::string graphics_backend = "Vulkan";
  int anisotropic_filtering = 1;
  std::string texture_filtering = "default";
  int anti_aliasing = 1;
  std::string shader_compilation = "hybrid";
  std::string fps_target = "original";
  bool show_fps_in_title = true;

  // Controller selection/mapping metadata is separate from Dolphin's
  // generated controllerN device strings below. `controller_device_id` is the
  // stable PC-facing selector (for example, an SDL GUID); "auto" is portable.
  std::string controller_device_id = "auto";
  std::string controller_profile = "default";
  std::map<std::string, std::string> controller_mappings;
  double controller_deadzone = 0.15;
  double controller_sensitivity = 1.0;
  bool controller_invert_x = false;
  bool controller_invert_y = false;
  bool controller_vibration = true;
  std::string controller;
  std::vector<std::string> controllers;

  // Audio, replacement textures, and developer facilities.
  std::string audio_backend = "auto";
  int audio_volume = 100;
  bool audio_muted = false;
  bool texture_packs_enabled = false;
  std::filesystem::path texture_pack_path = "texturepacks";
  bool developer_debug_overlay = false;
  bool developer_verbose_logging = false;
  bool developer_dump_original_textures = false;

  // Compatibility field consumed by the current runner/launcher. It mirrors
  // display_mode == "fullscreen"; borderless remains distinct.
  bool fullscreen = false;

  // Netplay.
  std::string netplay_nickname = "Player";
  std::string netplay_address = "127.0.0.1";
  std::uint16_t netplay_port = 2626;
  std::string netplay_buffer = "auto";
  std::string error;

  explicit operator bool() const { return error.empty(); }
};

const std::vector<ResolutionOption> &SupportedResolutions();
const std::vector<GraphicsBackendOption> &SupportedGraphicsBackends();
ConfigResult DefaultConfig();
bool ValidateConfig(const ConfigResult &config, std::string *error);
ConfigResult LoadConfig(const std::filesystem::path &user_directory,
                        bool create_if_missing);
bool SaveConfig(const std::filesystem::path &user_directory,
                const ConfigResult &config, std::string *error);
bool SaveConfig(const std::filesystem::path &user_directory,
                std::string_view resolution, bool show_fps_in_title,
                std::string_view controller, std::string *error);
std::string
ReadConfiguredController(const std::filesystem::path &user_directory);
std::vector<std::string>
ReadConfiguredControllers(const std::filesystem::path &user_directory);
bool ControllerConfigExists(const std::filesystem::path &user_directory);
bool GenerateControllerConfig(const std::filesystem::path &user_directory,
                              std::span<const std::string> controllers,
                              std::string *message);
bool GenerateControllerConfig(const std::filesystem::path &user_directory,
                              std::string_view controller,
                              std::string *message);
bool EnsureControllerConfig(const std::filesystem::path &user_directory,
                            std::span<const std::string> controllers,
                            std::string *message);
bool EnsureControllerConfig(const std::filesystem::path &user_directory,
                            std::string_view controller, std::string *message);
} // namespace moderngekko::frontend
