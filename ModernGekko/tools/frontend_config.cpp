#include "frontend_config.hpp"

#include <algorithm>
#include <atomic>
#include <cctype>
#include <charconv>
#include <chrono>
#include <cmath>
#include <fstream>
#include <initializer_list>
#include <iomanip>
#include <limits>
#include <string_view>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace fs = std::filesystem;

namespace moderngekko::frontend {
namespace {
std::string Trim(std::string value) {
  const auto not_space = [](unsigned char c) { return !std::isspace(c); };
  value.erase(value.begin(),
              std::find_if(value.begin(), value.end(), not_space));
  value.erase(std::find_if(value.rbegin(), value.rend(), not_space).base(),
              value.end());
  return value;
}

std::string Lower(std::string value) {
  std::ranges::transform(value, value.begin(), [](unsigned char c) {
    return static_cast<char>(std::tolower(c));
  });
  return value;
}

bool ValidNetplayAddress(std::string_view value) {
  if (value.empty() || value.size() > 253)
    return false;
  return std::ranges::all_of(value, [](unsigned char c) {
    return std::isalnum(c) || c == '.' || c == '-' || c == '_';
  });
}

std::string NormalizeGraphicsBackend(std::string value) {
  const std::string lower = Lower(Trim(std::move(value)));
  if (lower == "vulkan")
    return "Vulkan";
  if (lower == "opengl" || lower == "ogl")
    return "OGL";
  return {};
}

bool ParseBoolean(const std::string &value, bool *result) {
  if (value == "true" || value == "1" || value == "yes" || value == "on") {
    *result = true;
    return true;
  }
  if (value == "false" || value == "0" || value == "no" || value == "off") {
    *result = false;
    return true;
  }
  return false;
}

template <typename Integer>
bool ParseInteger(std::string_view value, Integer *result) {
  Integer parsed_value{};
  const auto parsed =
      std::from_chars(value.data(), value.data() + value.size(), parsed_value);
  if (parsed.ec != std::errc{} || parsed.ptr != value.data() + value.size())
    return false;
  *result = parsed_value;
  return true;
}

bool ParseDecimal(std::string_view value, double *result) {
  double parsed_value = 0.0;
  const auto parsed =
      std::from_chars(value.data(), value.data() + value.size(), parsed_value);
  if (parsed.ec != std::errc{} || parsed.ptr != value.data() + value.size() ||
      !std::isfinite(parsed_value))
    return false;
  *result = parsed_value;
  return true;
}

bool SingleLine(std::string_view value, std::size_t maximum_size,
                bool allow_empty = false) {
  return (allow_empty || !value.empty()) && value.size() <= maximum_size &&
         value.find_first_of("\r\n") == std::string_view::npos &&
         value.find('\0') == std::string_view::npos;
}

bool IsOneOf(std::string_view value,
             std::initializer_list<std::string_view> choices) {
  return std::ranges::find(choices, value) != choices.end();
}

bool IsOneOf(int value, std::initializer_list<int> choices) {
  return std::ranges::find(choices, value) != choices.end();
}

bool ValidDisplayResolution(std::string_view value) {
  if (value == "desktop" || value == "native")
    return true;
  const std::size_t separator = value.find('x');
  if (separator == std::string_view::npos ||
      value.find('x', separator + 1) != std::string_view::npos)
    return false;
  unsigned int width = 0;
  unsigned int height = 0;
  return ParseInteger(value.substr(0, separator), &width) &&
         ParseInteger(value.substr(separator + 1), &height) && width >= 320 &&
         width <= 16384 && height >= 200 && height <= 16384;
}

bool ValidMappingName(std::string_view value) {
  return !value.empty() && value.size() <= 64 &&
         std::ranges::all_of(value, [](unsigned char c) {
           return std::isalnum(c) || c == '_' || c == '-' || c == '.';
         });
}

bool NormalizeAndValidate(ConfigResult *config, std::string *error) {
  if (error)
    error->clear();
  const auto fail = [&](std::string message) {
    if (error)
      *error = std::move(message);
    return false;
  };

  config->display_mode = Lower(Trim(std::move(config->display_mode)));
  if (!IsOneOf(config->display_mode, {"windowed", "borderless", "fullscreen"}))
    return fail("display mode must be windowed, borderless, or fullscreen");
  // Keep the legacy flag useful to existing callers while treating an
  // explicitly selected borderless mode as distinct from fullscreen.
  if (config->fullscreen && config->display_mode == "windowed")
    config->display_mode = "fullscreen";
  config->fullscreen = config->display_mode == "fullscreen";

  config->display_resolution =
      Lower(Trim(std::move(config->display_resolution)));
  if (!ValidDisplayResolution(config->display_resolution))
    return fail("display resolution must be desktop, native, or WIDTHxHEIGHT "
                "between 320x200 and 16384x16384");

  config->aspect_ratio = Lower(Trim(std::move(config->aspect_ratio)));
  if (config->aspect_ratio == "4:3" || config->aspect_ratio == "original 4:3")
    config->aspect_ratio = "original";
  else if (config->aspect_ratio == "native" ||
           config->aspect_ratio == "auto/native")
    config->aspect_ratio = "auto";
  if (!IsOneOf(config->aspect_ratio,
               {"original", "16:9", "16:10", "21:9", "auto"}))
    return fail("aspect ratio must be original, 16:9, 16:10, 21:9, or auto");

  config->graphics_backend =
      NormalizeGraphicsBackend(std::move(config->graphics_backend));
  if (config->graphics_backend.empty())
    return fail("graphics backend must be Vulkan or OpenGL");

  config->resolution = Lower(Trim(std::move(config->resolution)));
  config->dolphin_scale = 0;
  for (const ResolutionOption &option : SupportedResolutions()) {
    if (config->resolution == option.text) {
      config->dolphin_scale = option.dolphin_scale;
      break;
    }
  }
  for (int scale = 1; !config->dolphin_scale && scale <= 12; ++scale) {
    const std::string raw =
        std::to_string(640 * scale) + "x" + std::to_string(528 * scale);
    if (config->resolution == raw)
      config->dolphin_scale = scale;
  }
  if (!config->dolphin_scale)
    return fail("unsupported Dolphin internal resolution '" +
                config->resolution +
                "'; use a listed display resolution or an exact 640x528 "
                "multiple up to 12x");

  if (!IsOneOf(config->anisotropic_filtering, {1, 2, 4, 8, 16}))
    return fail("anisotropic filtering must be 1, 2, 4, 8, or 16");
  config->texture_filtering = Lower(Trim(std::move(config->texture_filtering)));
  if (!IsOneOf(config->texture_filtering, {"default", "nearest", "linear"}))
    return fail("texture filtering must be default, nearest, or linear");
  if (!IsOneOf(config->anti_aliasing, {1, 2, 4, 8}))
    return fail("anti-aliasing must be 1, 2, 4, or 8");
  config->shader_compilation =
      Lower(Trim(std::move(config->shader_compilation)));
  if (!IsOneOf(config->shader_compilation,
               {"synchronous", "hybrid", "asynchronous"}))
    return fail("shader compilation must be synchronous, hybrid, or "
                "asynchronous");

  config->fps_target = Lower(Trim(std::move(config->fps_target)));
  if (!IsOneOf(config->fps_target, {"original", "30", "60", "90", "120", "144",
                                    "165", "240", "unlimited"}))
    return fail("FPS target must be original, 30, 60, 90, 120, 144, 165, "
                "240, or unlimited");

  config->controller_device_id = Trim(std::move(config->controller_device_id));
  config->controller_profile = Trim(std::move(config->controller_profile));
  if (!SingleLine(config->controller_device_id, 256) ||
      !SingleLine(config->controller_profile, 128))
    return fail("controller device ID and profile must be single-line values");
  if (config->controller_deadzone < 0.0 || config->controller_deadzone > 1.0)
    return fail("controller deadzone must be between 0.0 and 1.0");
  if (config->controller_sensitivity < 0.1 ||
      config->controller_sensitivity > 4.0)
    return fail("controller sensitivity must be between 0.1 and 4.0");
  std::erase(config->controllers, std::string{});
  if (config->controllers.empty() && !config->controller.empty())
    config->controllers.push_back(config->controller);
  if (config->controller.empty() && !config->controllers.empty())
    config->controller = config->controllers.front();
  if (config->controllers.size() > 4)
    return fail("at most four controllers can be configured");
  if (!config->controller.empty() && !SingleLine(config->controller, 512))
    return fail("controller device must be a single-line value");
  for (const std::string &controller : config->controllers) {
    if (!SingleLine(controller, 512))
      return fail("controller device must be a single-line value");
  }
  for (const auto &[action, binding] : config->controller_mappings) {
    if (!ValidMappingName(action) || !SingleLine(binding, 512))
      return fail("controller mappings require a simple action name and a "
                  "single-line binding");
  }

  config->audio_backend = Trim(std::move(config->audio_backend));
  if (!SingleLine(config->audio_backend, 64))
    return fail("audio backend must be a single-line value");
  if (config->audio_volume < 0 || config->audio_volume > 100)
    return fail("audio volume must be between 0 and 100");

  const std::string texture_pack_path = config->texture_pack_path.string();
  if (!SingleLine(texture_pack_path, 4096))
    return fail("texture-pack path must be a non-empty single-line path");

  if (config->netplay_nickname.empty())
    return fail("netplay nickname cannot be empty");
  if (config->netplay_nickname.size() > 30 ||
      config->netplay_nickname.find_first_of("\r\n") != std::string::npos)
    return fail("netplay nickname cannot exceed 30 single-line characters");
  if (!ValidNetplayAddress(config->netplay_address))
    return fail("netplay address must be an IPv4 address or hostname");
  if (config->netplay_port == 0)
    return fail("netplay port must be between 1 and 65535");
  config->netplay_buffer = Lower(Trim(std::move(config->netplay_buffer)));
  if (config->netplay_buffer != "auto") {
    unsigned int frames = 0;
    if (!ParseInteger(config->netplay_buffer, &frames) || frames < 1 ||
        frames > 20)
      return fail("netplay buffer must be auto or a value from 1 to 20");
  }
  return true;
}

std::uint64_t ProcessId() {
#if defined(_WIN32)
  return static_cast<std::uint64_t>(GetCurrentProcessId());
#else
  return static_cast<std::uint64_t>(getpid());
#endif
}

fs::path TemporaryConfigPath(const fs::path &destination) {
  static std::atomic_uint64_t sequence{0};
  fs::path temporary = destination;
  temporary +=
      ".tmp-" + std::to_string(ProcessId()) + "-" +
      std::to_string(
          std::chrono::steady_clock::now().time_since_epoch().count()) +
      "-" + std::to_string(sequence.fetch_add(1));
  return temporary;
}

bool ReplaceConfigFile(const fs::path &temporary, const fs::path &destination,
                       std::string *error) {
#if defined(_WIN32)
  if (MoveFileExW(temporary.c_str(), destination.c_str(),
                  MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
    return true;
  const std::error_code ec(static_cast<int>(GetLastError()),
                           std::system_category());
#else
  std::error_code ec;
  fs::rename(temporary, destination, ec);
  if (!ec)
    return true;
#endif
  if (error)
    *error = "can't replace " + destination.string() + ": " + ec.message();
  return false;
}

fs::path ControllerConfigPath(const fs::path &user_directory) {
#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
  return user_directory / "Config" / "GCPadNew.ini";
#else
  return user_directory / "Config" / "WiimoteNew.ini";
#endif
}

std::string_view ControllerSectionPrefix() {
#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
  return "[GCPad";
#else
  return "[Wiimote";
#endif
}

} // namespace

const std::vector<ResolutionOption> &SupportedResolutions() {
  // These are the output-resolution labels used by Dolphin's integer EFB
  // scales.
  static const std::vector<ResolutionOption> resolutions = {
      {"640x528", 1},   {"1280x720", 2},  {"1920x1080", 3},  {"2560x1440", 4},
      {"3840x2160", 6}, {"5120x2880", 8}, {"7680x4320", 12},
  };
  return resolutions;
}

const std::vector<GraphicsBackendOption> &SupportedGraphicsBackends() {
  static const std::vector<GraphicsBackendOption> backends = {
      {"Vulkan", "Vulkan"},
      {"OpenGL", "OGL"},
  };
  return backends;
}

ConfigResult DefaultConfig() {
  ConfigResult config;
  config.dolphin_scale = 3;
  return config;
}

bool ValidateConfig(const ConfigResult &config, std::string *error) {
  ConfigResult normalized = config;
  return NormalizeAndValidate(&normalized, error);
}

ConfigResult LoadConfig(const fs::path &user_directory,
                        bool create_if_missing) {
  const fs::path path = user_directory / "config.ini";
  if (!fs::exists(path) && create_if_missing) {
    std::string error;
    if (!SaveConfig(user_directory, DefaultConfig(), &error))
      return {.error = std::move(error)};
  }

  std::ifstream file(path);
  if (!file)
    return {.error = "can't open " + path.string()};

  ConfigResult config = DefaultConfig();
  std::string section;
  bool saw_settings_section = false;
  bool saw_schema_version = false;
  bool saw_display_mode = false;
  bool saw_legacy_fullscreen = false;
  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty() && line.back() == '\r')
      line.pop_back();
    const std::string trimmed = Trim(line);
    if (trimmed.empty() || trimmed[0] == '#' || trimmed[0] == ';')
      continue;
    if (trimmed[0] == '[') {
      if (!trimmed.ends_with(']'))
        return {.error = "invalid config.ini section: " + trimmed};
      section = Lower(Trim(trimmed.substr(1, trimmed.size() - 2)));
      if (section.empty())
        return {.error = "config.ini contains an empty section name"};
      if (section == "settings")
        saw_settings_section = true;
      continue;
    }
    const std::size_t separator = trimmed.find('=');
    if (separator == std::string::npos)
      return {.error = "invalid config.ini line: " + trimmed};
    const std::string raw_key = Trim(trimmed.substr(0, separator));
    const std::string key = Lower(raw_key);
    const std::string raw_value = Trim(trimmed.substr(separator + 1));
    const std::string value = Lower(raw_value);

    const auto parse_boolean = [&](bool *destination,
                                   std::string_view description) {
      if (ParseBoolean(value, destination))
        return ConfigResult{};
      return ConfigResult{.error = std::string(description) +
                                   " must be true or false"};
    };
    const auto parse_integer = [&](auto *destination,
                                   std::string_view description) {
      if (ParseInteger(raw_value, destination))
        return ConfigResult{};
      return ConfigResult{.error =
                              std::string(description) + " must be an integer"};
    };

    if (section == "settings" && key == "schema_version") {
      std::uint32_t version = 0;
      if (!ParseInteger(raw_value, &version) ||
          version != CONFIG_SCHEMA_VERSION)
        return {.error = "unsupported config.ini schema version '" + raw_value +
                         "'"};
      saw_schema_version = true;
    } else if (section == "display" && key == "mode") {
      config.display_mode = value;
      saw_display_mode = true;
    } else if (section == "display" && key == "resolution") {
      config.display_resolution = value;
    } else if (section == "display" && key == "aspect_ratio") {
      config.aspect_ratio = value;
    } else if (section == "display" && key == "vsync") {
      if (ConfigResult result = parse_boolean(&config.vsync, "vsync"); !result)
        return result;
    } else if (section == "graphics" && key == "backend") {
      config.graphics_backend = raw_value;
    } else if (section == "graphics" && key == "internal_resolution") {
      config.resolution = value;
    } else if (section == "graphics" && key == "anisotropic_filtering") {
      if (ConfigResult result = parse_integer(&config.anisotropic_filtering,
                                              "anisotropic_filtering");
          !result)
        return result;
    } else if (section == "graphics" && key == "texture_filtering") {
      config.texture_filtering = value;
    } else if (section == "graphics" && key == "anti_aliasing") {
      if (ConfigResult result =
              parse_integer(&config.anti_aliasing, "anti_aliasing");
          !result)
        return result;
    } else if (section == "graphics" && key == "shader_compilation") {
      config.shader_compilation = value;
    } else if (section == "fps" && key == "target") {
      config.fps_target = value;
    } else if (section == "fps" && key == "show_in_title") {
      if (ConfigResult result =
              parse_boolean(&config.show_fps_in_title, "show_in_title");
          !result)
        return result;
    } else if (section == "controller" && key == "device_id") {
      config.controller_device_id = raw_value;
    } else if (section == "controller" && key == "profile") {
      config.controller_profile = raw_value;
    } else if (section == "controller" && key == "deadzone") {
      if (!ParseDecimal(raw_value, &config.controller_deadzone))
        return {.error = "controller deadzone must be a decimal number"};
    } else if (section == "controller" && key == "sensitivity") {
      if (!ParseDecimal(raw_value, &config.controller_sensitivity))
        return {.error = "controller sensitivity must be a decimal number"};
    } else if (section == "controller" && key == "invert_x") {
      if (ConfigResult result =
              parse_boolean(&config.controller_invert_x, "invert_x");
          !result)
        return result;
    } else if (section == "controller" && key == "invert_y") {
      if (ConfigResult result =
              parse_boolean(&config.controller_invert_y, "invert_y");
          !result)
        return result;
    } else if (section == "controller" && key == "vibration") {
      if (ConfigResult result =
              parse_boolean(&config.controller_vibration, "vibration");
          !result)
        return result;
    } else if (section == "controllermappings") {
      config.controller_mappings[raw_key] = raw_value;
    } else if (section == "audio" && key == "backend") {
      config.audio_backend = raw_value;
    } else if (section == "audio" && key == "volume") {
      if (ConfigResult result =
              parse_integer(&config.audio_volume, "audio volume");
          !result)
        return result;
    } else if (section == "audio" && key == "muted") {
      if (ConfigResult result =
              parse_boolean(&config.audio_muted, "audio muted");
          !result)
        return result;
    } else if (section == "texturepacks" && key == "enabled") {
      if (ConfigResult result = parse_boolean(&config.texture_packs_enabled,
                                              "texture packs enabled");
          !result)
        return result;
    } else if (section == "texturepacks" && key == "path") {
      config.texture_pack_path = raw_value;
    } else if (section == "developer" && key == "debug_overlay") {
      if (ConfigResult result =
              parse_boolean(&config.developer_debug_overlay, "debug overlay");
          !result)
        return result;
    } else if (section == "developer" && key == "verbose_logging") {
      if (ConfigResult result = parse_boolean(&config.developer_verbose_logging,
                                              "verbose logging");
          !result)
        return result;
    } else if (section == "developer" && key == "dump_original_textures") {
      if (ConfigResult result =
              parse_boolean(&config.developer_dump_original_textures,
                            "dump original textures");
          !result)
        return result;
    } else if ((section == "video" || section.empty()) && key == "resolution") {
      config.resolution = value;
    } else if ((section == "video" || section.empty()) &&
               (key == "backend" || key == "graphics_backend")) {
      config.graphics_backend = raw_value;
    } else if ((section == "video" || section.empty()) &&
               key == "show_fps_in_title") {
      if (ConfigResult result =
              parse_boolean(&config.show_fps_in_title, "show_fps_in_title");
          !result)
        return result;
    } else if ((section == "video" || section.empty()) && key == "fullscreen") {
      if (ConfigResult result = parse_boolean(&config.fullscreen, "fullscreen");
          !result)
        return result;
      saw_legacy_fullscreen = true;
    } else if ((section == "input" || section == "controller" ||
                section.empty()) &&
               key == "controller") {
      config.controller = raw_value;
    } else if ((section == "input" || section == "controller" ||
                section.empty()) &&
               key.starts_with("controller") && key.size() == 11 &&
               key.back() >= '1' && key.back() <= '4') {
      const std::size_t index = static_cast<std::size_t>(key.back() - '1');
      if (config.controllers.size() <= index)
        config.controllers.resize(index + 1);
      config.controllers[index] = raw_value;
    } else if ((section == "netplay" || section.empty()) && key == "nickname") {
      config.netplay_nickname = raw_value;
    } else if ((section == "netplay" || section.empty()) && key == "address") {
      config.netplay_address = raw_value;
    } else if ((section == "netplay" || section.empty()) && key == "port") {
      unsigned int port = 0;
      if (!ParseInteger(raw_value, &port) || port == 0 || port > 65535)
        return {.error = "netplay port must be between 1 and 65535"};
      config.netplay_port = static_cast<std::uint16_t>(port);
    } else if ((section == "netplay" || section.empty()) && key == "buffer") {
      config.netplay_buffer = value;
    }
  }
  if (saw_settings_section && !saw_schema_version)
    return {.error = "config.ini [Settings] is missing schema_version=" +
                     std::to_string(CONFIG_SCHEMA_VERSION)};
  if (saw_display_mode)
    config.fullscreen = Lower(config.display_mode) == "fullscreen";
  else if (saw_legacy_fullscreen)
    config.display_mode = config.fullscreen ? "fullscreen" : "windowed";

  std::string validation_error;
  if (!NormalizeAndValidate(&config, &validation_error))
    return {.error = std::move(validation_error)};
  return config;
}

bool SaveConfig(const fs::path &user_directory, const ConfigResult &config,
                std::string *error) {
  ConfigResult normalized = config;
  if (!NormalizeAndValidate(&normalized, error))
    return false;
  std::error_code ec;
  fs::create_directories(user_directory, ec);
  if (ec) {
    if (error)
      *error = "can't create user directory: " + ec.message();
    return false;
  }
  const fs::path destination = user_directory / "config.ini";
  const fs::path temporary = TemporaryConfigPath(destination);
  {
    std::ofstream file(temporary, std::ios::trunc);
    if (!file) {
      if (error)
        *error = "can't write temporary config for " + destination.string();
      fs::remove(temporary, ec);
      return false;
    }
    file << std::setprecision(std::numeric_limits<double>::max_digits10)
         << "# ModernGekko PC settings. Unsupported future keys are ignored.\n"
            "[Settings]\n"
            "schema_version="
         << CONFIG_SCHEMA_VERSION
         << "\n\n[Display]\n"
            "mode="
         << normalized.display_mode << '\n'
         << "resolution=" << normalized.display_resolution << '\n'
         << "aspect_ratio=" << normalized.aspect_ratio << '\n'
         << "vsync=" << (normalized.vsync ? "true" : "false")
         << "\n\n[Graphics]\n"
         << "backend=" << normalized.graphics_backend << '\n'
         << "internal_resolution=" << normalized.resolution << '\n'
         << "anisotropic_filtering=" << normalized.anisotropic_filtering << '\n'
         << "texture_filtering=" << normalized.texture_filtering << '\n'
         << "anti_aliasing=" << normalized.anti_aliasing << '\n'
         << "shader_compilation=" << normalized.shader_compilation
         << "\n\n[FPS]\n"
         << "target=" << normalized.fps_target << '\n'
         << "show_in_title="
         << (normalized.show_fps_in_title ? "true" : "false")
         << "\n\n[Controller]\n"
         << "device_id=" << normalized.controller_device_id << '\n'
         << "profile=" << normalized.controller_profile << '\n'
         << "deadzone=" << normalized.controller_deadzone << '\n'
         << "sensitivity=" << normalized.controller_sensitivity << '\n'
         << "invert_x=" << (normalized.controller_invert_x ? "true" : "false")
         << '\n'
         << "invert_y=" << (normalized.controller_invert_y ? "true" : "false")
         << '\n'
         << "vibration=" << (normalized.controller_vibration ? "true" : "false")
         << '\n';
    for (std::size_t i = 0; i < normalized.controllers.size(); ++i)
      file << "controller" << i + 1 << '=' << normalized.controllers[i] << '\n';
    file << "\n[ControllerMappings]\n";
    for (const auto &[action, binding] : normalized.controller_mappings)
      file << action << '=' << binding << '\n';
    file << "\n[Audio]\n"
         << "backend=" << normalized.audio_backend << '\n'
         << "volume=" << normalized.audio_volume << '\n'
         << "muted=" << (normalized.audio_muted ? "true" : "false")
         << "\n\n[TexturePacks]\n"
         << "enabled=" << (normalized.texture_packs_enabled ? "true" : "false")
         << '\n'
         << "path=" << normalized.texture_pack_path.string()
         << "\n\n[Developer]\n"
         << "debug_overlay="
         << (normalized.developer_debug_overlay ? "true" : "false") << '\n'
         << "verbose_logging="
         << (normalized.developer_verbose_logging ? "true" : "false") << '\n'
         << "dump_original_textures="
         << (normalized.developer_dump_original_textures ? "true" : "false")
         << "\n\n[Netplay]\n"
         << "nickname=" << normalized.netplay_nickname << '\n'
         << "address=" << normalized.netplay_address << '\n'
         << "port=" << normalized.netplay_port << '\n'
         << "buffer=" << normalized.netplay_buffer << '\n';
    file.flush();
    if (!file) {
      if (error)
        *error =
            "can't finish writing temporary config for " + destination.string();
      file.close();
      fs::remove(temporary, ec);
      return false;
    }
    file.close();
    if (!file) {
      if (error)
        *error = "can't close temporary config for " + destination.string();
      fs::remove(temporary, ec);
      return false;
    }
  }
  if (!ReplaceConfigFile(temporary, destination, error)) {
    fs::remove(temporary, ec);
    return false;
  }
  return true;
}

bool SaveConfig(const fs::path &user_directory, std::string_view resolution,
                bool show_fps_in_title, std::string_view controller,
                std::string *error) {
  ConfigResult config = LoadConfig(user_directory, false);
  if (!config)
    config = {};
  config.resolution = resolution;
  config.show_fps_in_title = show_fps_in_title;
  config.controller = controller;
  config.controllers.clear();
  if (!controller.empty())
    config.controllers.emplace_back(controller);
  return SaveConfig(user_directory, config, error);
}

std::string ReadConfiguredController(const fs::path &user_directory) {
  const std::vector<std::string> controllers =
      ReadConfiguredControllers(user_directory);
  return controllers.empty() ? std::string{} : controllers.front();
}

std::vector<std::string>
ReadConfiguredControllers(const fs::path &user_directory) {
  std::ifstream input(ControllerConfigPath(user_directory));
  std::vector<std::string> controllers;
  std::string line;
  std::size_t controller_index = 4;
  const std::string_view section_prefix = ControllerSectionPrefix();
  while (std::getline(input, line)) {
    const std::string trimmed = Trim(line);
    if (trimmed.starts_with('[') && trimmed.ends_with(']')) {
      controller_index = 4;
      if (trimmed.size() == section_prefix.size() + 2 &&
          trimmed.starts_with(section_prefix) &&
          trimmed[section_prefix.size()] >= '1' &&
          trimmed[section_prefix.size()] <= '4')
        controller_index =
            static_cast<std::size_t>(trimmed[section_prefix.size()] - '1');
      continue;
    }
    if (controller_index >= 4)
      continue;
    const std::size_t separator = trimmed.find('=');
    if (separator != std::string::npos &&
        Trim(trimmed.substr(0, separator)) == "Device") {
      const std::string device = Trim(trimmed.substr(separator + 1));
      if (!device.empty()) {
        if (controllers.size() <= controller_index)
          controllers.resize(controller_index + 1);
        controllers[controller_index] = device;
      }
    }
  }
  std::erase(controllers, std::string{});
  return controllers;
}

bool ControllerConfigExists(const fs::path &user_directory) {
  std::error_code ec;
  return fs::is_regular_file(ControllerConfigPath(user_directory), ec);
}

bool GenerateControllerConfig(const fs::path &user_directory,
                              std::span<const std::string> controllers,
                              std::string *message) {
  if (controllers.empty() || controllers.size() > 4) {
    if (message)
      *message = "select between one and four connected SDL gamepads";
    return false;
  }
  for (const std::string &controller : controllers) {
    if (controller.empty() ||
        controller.find_first_of("\r\n") != std::string_view::npos) {
      if (message)
        *message = "select connected SDL gamepads";
      return false;
    }
  }

  const fs::path destination = ControllerConfigPath(user_directory);
  std::error_code ec;
  fs::create_directories(destination.parent_path(), ec);
  if (ec) {
    if (message)
      *message = "can't create controller config directory: " + ec.message();
    return false;
  }
  std::ofstream output(destination, std::ios::trunc);
  if (!output) {
    if (message)
      *message = "can't write " + destination.string();
    return false;
  }
  for (std::size_t i = 0; i < 4; ++i) {
#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
    output << "[GCPad" << i + 1 << "]\n";
    if (i >= controllers.size())
      continue;
    output << "Device = " << controllers[i] << '\n'
           << "Buttons/A = `Button A`\n"
              "Buttons/B = `Button B`\n"
              "Buttons/X = `Button X`\n"
              "Buttons/Y = `Button Y`\n"
              "Buttons/Z = `Shoulder R`\n"
              "Buttons/Start = Start\n"
              "Main Stick/Up = `Left Y+`\n"
              "Main Stick/Down = `Left Y-`\n"
              "Main Stick/Left = `Left X-`\n"
              "Main Stick/Right = `Left X+`\n"
              "Main Stick/Calibration = 100.00\n"
              "C-Stick/Up = `Right Y+`\n"
              "C-Stick/Down = `Right Y-`\n"
              "C-Stick/Left = `Right X-`\n"
              "C-Stick/Right = `Right X+`\n"
              "C-Stick/Calibration = 100.00\n"
              "Triggers/L = `Trigger L`\n"
              "Triggers/R = `Trigger R`\n"
              "Triggers/L-Analog = `Trigger L`\n"
              "Triggers/R-Analog = `Trigger R`\n"
              "D-Pad/Up = `Pad N`\n"
              "D-Pad/Down = `Pad S`\n"
              "D-Pad/Left = `Pad W`\n"
              "D-Pad/Right = `Pad E`\n"
              "Rumble/Motor = `Motor L` | `Motor R`\n";
#else
    output << "[Wiimote" << i + 1 << "]\n";
    if (i >= controllers.size())
      continue;
    output << "Device = " << controllers[i] << '\n'
           << "Buttons/A = `Shoulder L`\n"
              "Buttons/B = `Shoulder R`\n"
              "Buttons/1 = `Button W`\n"
              "Buttons/2 = `Button S`\n"
              "Buttons/- = Back\n"
              "Buttons/+ = Start\n"
              "Buttons/Home = Guide\n"
              "D-Pad/Up = `Pad N` | `Left Y+`\n"
              "D-Pad/Down = `Pad S` | `Left Y-`\n"
              "D-Pad/Left = `Pad W` | `Left X-`\n"
              "D-Pad/Right = `Pad E` | `Left X+`\n"
              "IR/Up = `Cursor Y-`\n"
              "IR/Down = `Cursor Y+`\n"
              "IR/Left = `Cursor X-`\n"
              "IR/Right = `Cursor X+`\n"
              "Shake/X = `Trigger L`\n"
              "Shake/Y = `Trigger R`\n"
              "Shake/Z = `Trigger L`\n"
              "IRPassthrough/Object 1 X = `IR Object 1 X`\n"
              "IRPassthrough/Object 1 Y = `IR Object 1 Y`\n"
              "IRPassthrough/Object 1 Size = `IR Object 1 Size`\n"
              "IRPassthrough/Object 2 X = `IR Object 2 X`\n"
              "IRPassthrough/Object 2 Y = `IR Object 2 Y`\n"
              "IRPassthrough/Object 2 Size = `IR Object 2 Size`\n"
              "IRPassthrough/Object 3 X = `IR Object 3 X`\n"
              "IRPassthrough/Object 3 Y = `IR Object 3 Y`\n"
              "IRPassthrough/Object 3 Size = `IR Object 3 Size`\n"
              "IRPassthrough/Object 4 X = `IR Object 4 X`\n"
              "IRPassthrough/Object 4 Y = `IR Object 4 Y`\n"
              "IRPassthrough/Object 4 Size = `IR Object 4 Size`\n"
              "IMUAccelerometer/Up = `Accel Up`\n"
              "IMUAccelerometer/Down = `Accel Down`\n"
              "IMUAccelerometer/Left = `Accel Left`\n"
              "IMUAccelerometer/Right = `Accel Right`\n"
              "IMUAccelerometer/Forward = `Accel Forward`\n"
              "IMUAccelerometer/Backward = `Accel Backward`\n"
              "IMUGyroscope/Pitch Up = `Gyro Pitch Up`\n"
              "IMUGyroscope/Pitch Down = `Gyro Pitch Down`\n"
              "IMUGyroscope/Roll Left = `Gyro Roll Left`\n"
              "IMUGyroscope/Roll Right = `Gyro Roll Right`\n"
              "IMUGyroscope/Yaw Left = `Gyro Yaw Left`\n"
              "IMUGyroscope/Yaw Right = `Gyro Yaw Right`\n"
              "Rumble/Motor = Motor\n"
              "Extension = None\n"
              "Options/Sideways Wiimote = True\n";
#endif
  }
#ifndef MODERNGEKKO_GAMECUBE_CONTROLLERS
  output << "[BalanceBoard]\n";
#endif
  if (!output) {
    if (message)
      *message = "can't write " + destination.string();
    return false;
  }
  if (message)
    *message = std::to_string(controllers.size()) +
#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
               " GameCube controller" +
#else
               " sideways Wii Remote" +
#endif
               (controllers.size() == 1 ? " mapped" : "s mapped");
  return true;
}

bool GenerateControllerConfig(const fs::path &user_directory,
                              std::string_view controller,
                              std::string *message) {
  const std::string value(controller);
  return GenerateControllerConfig(
      user_directory, std::span<const std::string>(&value, 1), message);
}

bool EnsureControllerConfig(const fs::path &user_directory,
                            std::span<const std::string> controllers,
                            std::string *message) {
  if (ControllerConfigExists(user_directory)) {
    if (message)
      *message = "using existing controller profile";
    return true;
  }
  return GenerateControllerConfig(user_directory, controllers, message);
}

bool EnsureControllerConfig(const fs::path &user_directory,
                            std::string_view controller, std::string *message) {
  const std::string value(controller);
  return EnsureControllerConfig(
      user_directory, std::span<const std::string>(&value, 1), message);
}
} // namespace moderngekko::frontend
