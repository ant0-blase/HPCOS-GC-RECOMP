#include "frontend_config.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>

#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
constexpr const char *CONTROLLER_CONFIG_NAME = "GCPadNew.ini";
#else
constexpr const char *CONTROLLER_CONFIG_NAME = "WiimoteNew.ini";
#endif

int main() {
  namespace fs = std::filesystem;
  const fs::path directory =
      fs::temp_directory_path() /
      ("moderngekko-frontend-config-" +
       std::to_string(
           std::chrono::steady_clock::now().time_since_epoch().count()));

  std::string error;
  const std::string controller = "SDL/0/Test Controller";

  const auto defaults = moderngekko::frontend::LoadConfig(directory, true);
  if (!defaults || defaults.display_mode != "windowed" ||
      defaults.display_resolution != "desktop" ||
      defaults.aspect_ratio != "auto" || !defaults.vsync ||
      defaults.resolution != "1920x1080" || defaults.dolphin_scale != 3 ||
      defaults.fps_target != "original" ||
      defaults.controller_device_id != "auto" || defaults.audio_volume != 100 ||
      defaults.texture_packs_enabled ||
      defaults.texture_pack_path != "texturepacks" ||
      defaults.developer_dump_original_textures) {
    return 14;
  }
  {
    std::ifstream input(directory / "config.ini");
    const std::string generated{std::istreambuf_iterator<char>(input),
                                std::istreambuf_iterator<char>()};
    if (!generated.contains("[Settings]\nschema_version=1\n") ||
        !generated.contains("[Display]\nmode=windowed\n") ||
        !generated.contains("[TexturePacks]\nenabled=false\n"))
      return 15;
  }

  if (!moderngekko::frontend::SaveConfig(directory, "1920x1080", false,
                                         controller, &error))
    return 1;

  const auto loaded = moderngekko::frontend::LoadConfig(directory, false);
  if (!loaded || loaded.dolphin_scale != 3 || loaded.show_fps_in_title ||
      loaded.controller != controller || loaded.graphics_backend != "Vulkan") {
    return 2;
  }

  moderngekko::frontend::ConfigResult netplay_config = loaded;
  netplay_config.graphics_backend = "OpenGL";
  netplay_config.fullscreen = true;
  netplay_config.controllers = {controller, "SDL/1/Second Controller"};
  netplay_config.controller = controller;
  netplay_config.netplay_nickname = "Kirby";
  netplay_config.netplay_address = "192.168.1.50";
  netplay_config.netplay_port = 34567;
  netplay_config.netplay_buffer = "auto";
  if (!moderngekko::frontend::SaveConfig(directory, netplay_config, &error))
    return 6;
  const auto netplay_loaded =
      moderngekko::frontend::LoadConfig(directory, false);
  if (!netplay_loaded ||
      netplay_loaded.controllers != netplay_config.controllers ||
      netplay_loaded.netplay_nickname != "Kirby" ||
      netplay_loaded.netplay_address != "192.168.1.50" ||
      netplay_loaded.netplay_port != 34567 ||
      netplay_loaded.netplay_buffer != "auto" ||
      netplay_loaded.graphics_backend != "OGL" || !netplay_loaded.fullscreen) {
    return 7;
  }

  moderngekko::frontend::ConfigResult pc_config =
      moderngekko::frontend::DefaultConfig();
  pc_config.display_mode = "borderless";
  pc_config.display_resolution = "3440x1440";
  pc_config.aspect_ratio = "21:9";
  pc_config.vsync = false;
  pc_config.resolution = "3840x2160";
  pc_config.graphics_backend = "OpenGL";
  pc_config.anisotropic_filtering = 16;
  pc_config.texture_filtering = "linear";
  pc_config.anti_aliasing = 8;
  pc_config.shader_compilation = "asynchronous";
  pc_config.fps_target = "144";
  pc_config.show_fps_in_title = false;
  pc_config.controller_device_id = "sdl-guid:030000005e0400008e02000000000000";
  pc_config.controller_profile = "xbox-gamecube";
  pc_config.controller_mappings = {{"button_a", "south"},
                                   {"main_stick_x", "left_x"}};
  pc_config.controller_deadzone = 0.2;
  pc_config.controller_sensitivity = 1.25;
  pc_config.controller_invert_x = true;
  pc_config.controller_invert_y = true;
  pc_config.controller_vibration = false;
  pc_config.controllers = {controller};
  pc_config.audio_backend = "cubeb";
  pc_config.audio_volume = 65;
  pc_config.audio_muted = true;
  pc_config.texture_packs_enabled = true;
  pc_config.texture_pack_path = "texturepacks/HD";
  pc_config.developer_debug_overlay = true;
  pc_config.developer_verbose_logging = true;
  pc_config.developer_dump_original_textures = true;
  if (!moderngekko::frontend::ValidateConfig(pc_config, &error) ||
      !moderngekko::frontend::SaveConfig(directory, pc_config, &error))
    return 16;
  const auto pc_loaded = moderngekko::frontend::LoadConfig(directory, false);
  if (!pc_loaded || pc_loaded.display_mode != "borderless" ||
      pc_loaded.fullscreen || pc_loaded.display_resolution != "3440x1440" ||
      pc_loaded.aspect_ratio != "21:9" || pc_loaded.vsync ||
      pc_loaded.dolphin_scale != 6 || pc_loaded.graphics_backend != "OGL" ||
      pc_loaded.anisotropic_filtering != 16 ||
      pc_loaded.texture_filtering != "linear" || pc_loaded.anti_aliasing != 8 ||
      pc_loaded.shader_compilation != "asynchronous" ||
      pc_loaded.fps_target != "144" || pc_loaded.show_fps_in_title ||
      pc_loaded.controller_device_id != pc_config.controller_device_id ||
      pc_loaded.controller_profile != "xbox-gamecube" ||
      pc_loaded.controller_mappings != pc_config.controller_mappings ||
      pc_loaded.controller_deadzone != pc_config.controller_deadzone ||
      pc_loaded.controller_sensitivity != pc_config.controller_sensitivity ||
      !pc_loaded.controller_invert_x || !pc_loaded.controller_invert_y ||
      pc_loaded.controller_vibration || pc_loaded.audio_backend != "cubeb" ||
      pc_loaded.audio_volume != 65 || !pc_loaded.audio_muted ||
      !pc_loaded.texture_packs_enabled ||
      pc_loaded.texture_pack_path != "texturepacks/HD" ||
      !pc_loaded.developer_debug_overlay ||
      !pc_loaded.developer_verbose_logging ||
      !pc_loaded.developer_dump_original_textures) {
    return 17;
  }
  for (const fs::directory_entry &entry : fs::directory_iterator(directory)) {
    if (entry.path().filename().string().starts_with("config.ini.tmp-"))
      return 27;
  }

  const auto invalid_setting = [&](auto change) {
    auto invalid = pc_config;
    change(invalid);
    return !moderngekko::frontend::ValidateConfig(invalid, &error) &&
           !moderngekko::frontend::SaveConfig(directory, invalid, &error);
  };
  if (!invalid_setting([](auto &value) { value.display_mode = "exclusive"; }) ||
      !invalid_setting(
          [](auto &value) { value.display_resolution = "100x100"; }) ||
      !invalid_setting([](auto &value) { value.anisotropic_filtering = 32; }) ||
      !invalid_setting([](auto &value) { value.fps_target = "59"; }) ||
      !invalid_setting([](auto &value) { value.controller_deadzone = 1.5; }) ||
      !invalid_setting([](auto &value) { value.audio_volume = 101; }) ||
      !invalid_setting([](auto &value) { value.texture_pack_path.clear(); })) {
    return 18;
  }

  // Validation happens before opening config.ini, so a rejected save cannot
  // truncate the last known-good settings.
  std::ifstream before_input(directory / "config.ini");
  const std::string before_invalid_save{
      std::istreambuf_iterator<char>(before_input),
      std::istreambuf_iterator<char>()};
  auto invalid_developer_file = pc_config;
  invalid_developer_file.controller_mappings["button_b"] = "line1\nline2";
  if (moderngekko::frontend::SaveConfig(directory, invalid_developer_file,
                                        &error))
    return 19;
  std::ifstream after_input(directory / "config.ini");
  const std::string after_invalid_save{
      std::istreambuf_iterator<char>(after_input),
      std::istreambuf_iterator<char>()};
  if (after_invalid_save != before_invalid_save)
    return 20;

  // A failed publish must leave the destination untouched and clean up its
  // sibling temporary file. A non-empty destination directory is a portable
  // way to make the final file replacement fail after the temporary write.
  const fs::path blocked_directory = directory / "blocked-publish";
  const fs::path blocked_destination = blocked_directory / "config.ini";
  fs::create_directories(blocked_destination);
  {
    std::ofstream sentinel(blocked_destination / "last-good-config");
    sentinel << "preserve me\n";
  }
  if (moderngekko::frontend::SaveConfig(blocked_directory, pc_config, &error) ||
      !error.contains("can't replace") ||
      !fs::is_regular_file(blocked_destination / "last-good-config"))
    return 24;
  for (const fs::directory_entry &entry :
       fs::directory_iterator(blocked_directory)) {
    if (entry.path().filename().string().starts_with("config.ini.tmp-"))
      return 25;
  }

  auto invalid_netplay = netplay_config;
  invalid_netplay.netplay_address = "not a host";
  if (moderngekko::frontend::SaveConfig(directory, invalid_netplay, &error))
    return 8;
  invalid_netplay = netplay_config;
  invalid_netplay.netplay_nickname = std::string(31, 'K');
  if (moderngekko::frontend::SaveConfig(directory, invalid_netplay, &error))
    return 9;
  invalid_netplay = netplay_config;
  invalid_netplay.graphics_backend = "Direct3D 9";
  if (moderngekko::frontend::SaveConfig(directory, invalid_netplay, &error))
    return 13;
  if (!moderngekko::frontend::GenerateControllerConfig(
          directory, netplay_config.controllers, &error))
    return 3;
  if (moderngekko::frontend::ReadConfiguredController(directory) != controller)
    return 4;
  if (moderngekko::frontend::ReadConfiguredControllers(directory) !=
      netplay_config.controllers)
    return 10;

  std::ifstream input(directory / "Config" / CONTROLLER_CONFIG_NAME);
  const std::string generated{std::istreambuf_iterator<char>(input),
                              std::istreambuf_iterator<char>()};
#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
  if (!generated.contains("Buttons/A = `Button A`\n") ||
      !generated.contains("Buttons/Z = `Shoulder R`\n") ||
      !generated.contains("Main Stick/Up = `Left Y+`\n") ||
      !generated.contains("C-Stick/Up = `Right Y+`\n") ||
      !generated.contains("Triggers/L-Analog = `Trigger L`\n") ||
      !generated.contains("Rumble/Motor = `Motor L` | `Motor R`\n") ||
      !generated.contains("[GCPad2]\nDevice = SDL/1/Second Controller\n") ||
      generated.contains("[Wiimote") || generated.contains("[BalanceBoard]")) {
    return 5;
  }
#else
  if (!generated.contains("Buttons/A = `Shoulder L`\n") ||
      !generated.contains("Buttons/1 = `Button W`\n") ||
      !generated.contains("Buttons/2 = `Button S`\n") ||
      !generated.contains("Shake/X = `Trigger L`\n") ||
      !generated.contains("D-Pad/Up = `Pad N` | `Left Y+`\n") ||
      !generated.contains("D-Pad/Right = `Pad E` | `Left X+`\n") ||
      !generated.contains("Extension = None\n") ||
      !generated.contains("Options/Sideways Wiimote = True\n") ||
      !generated.contains("[Wiimote2]\nDevice = SDL/1/Second Controller\n") ||
      generated.contains("Nunchuk/")) {
    return 5;
  }
#endif

#ifdef MODERNGEKKO_GAMECUBE_CONTROLLERS
  const std::string custom =
      "[GCPad1]\nDevice = SDL/9/Custom Controller\nButtons/A = Custom\n";
#else
  const std::string custom =
      "[Wiimote1]\nDevice = SDL/9/Custom Controller\nButtons/1 = Custom\n";
#endif
  {
    std::ofstream output(directory / "Config" / CONTROLLER_CONFIG_NAME,
                         std::ios::trunc);
    output << custom;
  }
  if (!moderngekko::frontend::EnsureControllerConfig(
          directory, netplay_config.controllers, &error))
    return 11;
  std::ifstream custom_input(directory / "Config" / CONTROLLER_CONFIG_NAME);
  const std::string preserved{std::istreambuf_iterator<char>(custom_input),
                              std::istreambuf_iterator<char>()};
  if (preserved != custom || moderngekko::frontend::ReadConfiguredController(
                                 directory) != "SDL/9/Custom Controller")
    return 12;

  // Pre-schema files remain loadable and receive defaults for settings that
  // did not exist in the original frontend.
  {
    std::ofstream output(directory / "config.ini", std::ios::trunc);
    output << "[Video]\n"
              "resolution=1280x720\n"
              "backend=Vulkan\n"
              "fullscreen=true\n"
              "show_fps_in_title=false\n"
              "[Input]\n"
              "controller1=SDL/0/Legacy Pad\n"
              "[Netplay]\n"
              "nickname=Legacy\n"
              "address=localhost\n"
              "port=2626\n"
              "buffer=auto\n";
  }
  const auto legacy = moderngekko::frontend::LoadConfig(directory, false);
  if (!legacy || legacy.display_mode != "fullscreen" || !legacy.fullscreen ||
      legacy.dolphin_scale != 2 || legacy.fps_target != "original" ||
      legacy.audio_volume != 100 || legacy.controller != "SDL/0/Legacy Pad")
    return 21;

  {
    std::ofstream output(directory / "config.ini", std::ios::trunc);
    output << "[Settings]\nschema_version=2\n";
  }
  if (moderngekko::frontend::LoadConfig(directory, false))
    return 22;

  {
    std::ofstream output(directory / "config.ini", std::ios::trunc);
    output << "[Settings]\n"
              "[Display]\nmode=windowed\n";
  }
  const auto missing_schema =
      moderngekko::frontend::LoadConfig(directory, false);
  if (missing_schema ||
      !missing_schema.error.contains("[Settings] is missing schema_version"))
    return 26;

  {
    std::ofstream output(directory / "config.ini", std::ios::trunc);
    output << "[Settings]\nschema_version=1\n"
              "[Developer]\ndump_original_textures=sometimes\n";
  }
  if (moderngekko::frontend::LoadConfig(directory, false))
    return 23;

  fs::remove_all(directory);
  return 0;
}
