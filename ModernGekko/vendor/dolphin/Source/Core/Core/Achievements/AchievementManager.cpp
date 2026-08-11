// Copyright 2023 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#ifdef USE_RETRO_ACHIEVEMENTS

#include "Core/Achievements/AchievementManager.h"

#include <memory>
#include <fmt/format.h>

#include "Common/BitUtils.h"
#include "Common/CommonPaths.h"
#include "Common/Config/Config.h"
#include "Common/FileUtil.h"
#include "Common/HttpRequest.h"
#include "Common/IOFile.h"
#include "Common/JsonUtil.h"
#include "Common/Logging/Log.h"
#include "Common/ScopeGuard.h"
#include "Common/StringUtil.h"
#include "Common/Version.h"
#include "Common/WorkQueueThread.h"
#include "Core/Cheats/ActionReplay.h"
#include "Core/Config/AchievementSettings.h"
#include "Core/Config/FreeLookSettings.h"
#include "Core/Config/MainSettings.h"
#include "Core/ConfigLoaders/GameConfigLoader.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/Cheats/GeckoCode.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/VideoInterface.h"
#include "Core/Cheats/PatchEngine.h"
#include "Core/PowerPC/MMU.h"
#include "Core/System.h"
#include "DiscIO/Blob.h"
#include "UICommon/DiscordPresence.h"
#include "VideoCommon/Assets/CustomTextureData.h"
#include "VideoCommon/OnScreenDisplay.h"
#include "VideoCommon/VideoEvents.h"

#ifdef RC_CLIENT_SUPPORTS_RAINTEGRATION
#include <libloaderapi.h>
#include <rcheevos/include/rc_client_raintegration.h>
#include <shlwapi.h>
#endif  // RC_CLIENT_SUPPORTS_RAINTEGRATION

#ifdef ANDROID
static const Common::HttpRequest::Headers USER_AGENT_HEADER = {
    {"User-Agent", Common::GetUserAgentStr() + " (Android)"}};
#else   // ANDROID
static const Common::HttpRequest::Headers USER_AGENT_HEADER = {
    {"User-Agent", Common::GetUserAgentStr()}};
#endif  // ANDROID

AchievementManager& AchievementManager::GetInstance()
{
  static AchievementManager s_instance;
  return s_instance;
}

void AchievementManager::Init(void* hwnd)
{
  LoadDefaultBadges();
  if (!m_client && Config::Get(Config::RA_ENABLED))
  {
    {
      std::lock_guard lg{m_lock};
      m_client = rc_client_create(MemoryPeeker, Request);
    }
    std::string host_url = Config::Get(Config::RA_HOST_URL);
    if (!host_url.empty())
      rc_client_set_host(m_client, host_url.c_str());
    rc_client_set_event_handler(m_client, EventHandler);
    rc_client_enable_logging(m_client, RC_CLIENT_LOG_LEVEL_VERBOSE,
                             [](const char* message, const rc_client_t* client) {
                               INFO_LOG_FMT(ACHIEVEMENTS, "{}", message);
                             });
    m_config_changed_callback_id = Config::AddConfigChangedCallback([this] { SetHardcoreMode(); });
    SetHardcoreMode();
    m_queue.Reset("AchievementManagerQueue");
    m_image_queue.Reset("AchievementManagerImageQueue");

#ifdef RC_CLIENT_SUPPORTS_RAINTEGRATION
    // Attempt to load the integration DLL from the directory containing the main client executable.
    // In x64 build, will look for RA_Integration-x64.dll, then RA_Integration.dll.
    // In non-x64 build, will only look for RA_Integration.dll.
    rc_client_begin_load_raintegration(
        m_client, UTF8ToWString(File::GetExeDirectory()).c_str(), reinterpret_cast<HWND>(hwnd),
        "Dolphin", Common::GetScmDescStr().c_str(), LoadIntegrationCallback, NULL);
#else   // RC_CLIENT_SUPPORTS_RAINTEGRATION
    if (HasAPIToken())
      Login("");
    INFO_LOG_FMT(ACHIEVEMENTS, "Achievement Manager Initialized");
#endif  // RC_CLIENT_SUPPORTS_RAINTEGRATION
  }
}

void AchievementManager::Login(const std::string& password)
{
  if (!m_client)
  {
    ERROR_LOG_FMT(
        ACHIEVEMENTS,
        "Attempted login to RetroAchievements server without achievement client initialized.");
    return;
  }
  if (password.empty())
  {
    rc_client_begin_login_with_token(m_client, Config::Get(Config::RA_USERNAME).c_str(),
                                     Config::Get(Config::RA_API_TOKEN).c_str(), LoginCallback,
                                     NULL);
  }
  else
  {
    rc_client_begin_login_with_password(m_client, Config::Get(Config::RA_USERNAME).c_str(),
                                        password.c_str(), LoginCallback, NULL);
  }
}

bool AchievementManager::HasAPIToken() const
{
  return !Config::Get(Config::RA_API_TOKEN).empty();
}

void AchievementManager::LoadGame(const DiscIO::Volume* volume)
{
  if (!m_client)
    return;
  if (volume == nullptr)
  {
    CloseGame();
    return;
  }
  {
    std::lock_guard lg{m_lock};
    if (rc_client_get_game_info(m_client) &&
        m_system.load(std::memory_order_acquire) != nullptr)
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Game already loaded in Achievement Manager.");
      return;
    }
  }
  std::lock_guard lg{m_filereader_lock};
  rc_hash_filereader volume_reader{
      .open = &AchievementManager::FilereaderOpen,
      .seek = &AchievementManager::FilereaderSeek,
      .tell = &AchievementManager::FilereaderTell,
      .read = &AchievementManager::FilereaderRead,
      .close = &AchievementManager::FilereaderClose,
  };
  rc_hash_init_custom_filereader(&volume_reader);
  if (rc_client_get_game_info(m_client))
  {
    rc_client_begin_identify_and_change_media(m_client, "", NULL, 0, ChangeMediaCallback, NULL);
  }
  else
  {
    u32 console_id = FindConsoleID(volume->GetVolumeType());
    rc_client_begin_identify_and_load_game(m_client, console_id, "", NULL, 0, LoadGameCallback,
                                           NULL);
  }
}

void AchievementManager::ChangeDisc(const DiscIO::Volume* volume)
{
  if (volume == nullptr)
  {
    INFO_LOG_FMT(ACHIEVEMENTS, "Ejecting disc.");
    LoadGame(nullptr);
  }
  else if (volume->GetGameID() != SConfig::GetInstance().GetGameID())
  {
    INFO_LOG_FMT(ACHIEVEMENTS, "Inserting disc that doesn't belong to the running game.");
    LoadGame(nullptr);
  }
  else
  {
    INFO_LOG_FMT(ACHIEVEMENTS, "Inserting disc.");
    LoadGame(volume);
  }
}

bool AchievementManager::IsGameLoaded() const
{
  auto* game_info = rc_client_get_game_info(m_client);
  return game_info && game_info->id != 0;
}

void AchievementManager::SetBackgroundExecutionAllowed(bool allowed)
{
  m_background_execution_allowed = allowed;

  Core::System* system = m_system.load(std::memory_order_acquire);
  if (!system)
    return;

  if (allowed && Core::GetState(*system) == Core::State::Paused)
    DoIdle();
}

void AchievementManager::FetchPlayerBadge()
{
  FetchBadge(&m_player_badge, RC_IMAGE_TYPE_USER,
             [](const auto& self) { return std::string(self.GetPlayerDisplayName()); },
             UpdatedItems{.player_icon = true});
}

void AchievementManager::FetchGameBadges()
{
  FetchBadge(&m_game_badge, RC_IMAGE_TYPE_GAME,
             [](const auto& self) {
               return std::string(rc_client_get_game_info(self.m_client)->badge_name);
             },
             UpdatedItems{.game_icon = true});
}

void AchievementManager::DoFrame()
{
  auto* system = m_system.load(std::memory_order_acquire);
  if (!system)
    return;

  Core::CPUThreadGuard thread_guard(*system);
  std::lock_guard lg{m_lock};

  auto current_time = std::chrono::steady_clock::now();
  if (m_display_welcome_message)
  {
    DisplayWelcomeMessage();
  }
  rc_client_do_frame(m_client);

  if (current_time - m_last_rp_time > std::chrono::seconds{10})
  {
    m_last_rp_time = current_time;
    rc_client_get_rich_presence_message(m_client, m_rich_presence.data(), RP_SIZE);
    update_event.Trigger(UpdatedItems{.rich_presence = true});
    if (Config::Get(Config::RA_DISCORD_PRESENCE_ENABLED))
      Discord::UpdateDiscordPresence();
  }
}

bool AchievementManager::CanPause()
{
  if (!IsGameLoaded())
    return true;
  u32 frames_to_next_pause = 0;
  bool can_pause = rc_client_can_pause(m_client, &frames_to_next_pause);
  if (!can_pause)
  {
    OSD::AddMessage(
        fmt::format("RetroAchievements Hardcore Mode:\n"
                    "Cannot pause until another {:.2f} seconds have passed.",
                    static_cast<float>(frames_to_next_pause) /
                        Core::System::GetInstance().GetVideoInterface().GetTargetRefreshRate()),
        OSD::Duration::VERY_LONG, OSD::Color::RED);
  }
  return can_pause;
}

void AchievementManager::DoIdle()
{
  auto* system = m_system.load(std::memory_order_acquire);
  if (!system)
    return;

  Core::CPUThreadGuard thread_guard(*system);
  std::lock_guard lg{m_lock};

  rc_client_idle(m_client);
  if (m_challenges_updated)
  {
    update_event.Trigger(UpdatedItems{.rich_presence = true});
    m_challenges_updated = false;
  }
}

std::recursive_mutex& AchievementManager::GetLock()
{
  return m_lock;
}

bool AchievementManager::IsHardcoreModeActive() const
{
  return m_client && rc_client_get_hardcore_enabled(m_client);
}

void AchievementManager::SetSpectatorMode()
{
  rc_client_set_spectator_mode_enabled(m_client, Config::Get(Config::RA_SPECTATOR_ENABLED));
}

std::string_view AchievementManager::GetPlayerDisplayName() const
{
  if (!HasAPIToken())
    return "";
  auto* user = rc_client_get_user_info(m_client);
  if (!user)
    return "";
  return std::string_view(user->display_name);
}

u32 AchievementManager::GetPlayerScore() const
{
  if (!HasAPIToken())
    return 0;
  auto* user = rc_client_get_user_info(m_client);
  if (!user)
    return 0;
  return user->score;
}

const AchievementManager::Badge& AchievementManager::GetPlayerBadge() const
{
  return m_player_badge.data.empty() ? m_default_player_badge : m_player_badge;
}

std::string_view AchievementManager::GetGameDisplayName() const
{
  return IsGameLoaded() ? std::string_view(rc_client_get_game_info(m_client)->title) : "";
}

rc_client_t* AchievementManager::GetClient()
{
  return m_client;
}

const AchievementManager::Badge& AchievementManager::GetGameBadge() const
{
  return m_game_badge.data.empty() ? m_default_game_badge : m_game_badge;
}

const AchievementManager::Badge& AchievementManager::GetAchievementBadge(AchievementId id,
                                                                         bool locked) const
{
  auto& badge_list = locked ? m_locked_badges : m_unlocked_badges;
  auto itr = badge_list.find(id);
  return (itr != badge_list.end() && itr->second.data.size() > 0) ?
             itr->second :
             (locked ? m_default_locked_badge : m_default_unlocked_badge);
}

const AchievementManager::LeaderboardStatus*
AchievementManager::GetLeaderboardInfo(AchievementManager::AchievementId leaderboard_id)
{
  if (const auto leaderboard_iter = m_leaderboard_map.find(leaderboard_id);
      leaderboard_iter != m_leaderboard_map.end())
  {
    return &leaderboard_iter->second;
  }

  return nullptr;
}

AchievementManager::RichPresence AchievementManager::GetRichPresence() const
{
  return m_rich_presence;
}

bool AchievementManager::AreChallengesUpdated() const
{
  return m_challenges_updated;
}

void AchievementManager::ResetChallengesUpdated()
{
  m_challenges_updated = false;
}

const std::unordered_set<AchievementManager::AchievementId>&
AchievementManager::GetActiveChallenges() const
{
  return m_active_challenges;
}

std::vector<std::string> AchievementManager::GetActiveLeaderboards() const
{
  if (!Config::Get(Config::RA_LEADERBOARD_TRACKER_ENABLED))
    return {};

  std::vector<std::string> display_values;
  for (u32 ix = 0; ix < MAX_DISPLAYED_LBOARDS && ix < m_active_leaderboards.size(); ix++)
  {
    display_values.push_back(std::string(m_active_leaderboards[ix].display));
  }
  return display_values;
}

#ifdef RC_CLIENT_SUPPORTS_RAINTEGRATION
const rc_client_raintegration_menu_t* AchievementManager::GetDevelopmentMenu()
{
  if (!m_dll_found)
    return nullptr;
  return rc_client_raintegration_get_menu(m_client);
}

u32 AchievementManager::ActivateDevMenuItem(u32 menu_item_id)
{
  if (!m_dll_found)
    return 0;
  return rc_client_raintegration_activate_menu_item(m_client, menu_item_id);
}
#endif  // RC_CLIENT_SUPPORTS_RAINTEGRATION

void AchievementManager::DoState(PointerWrap& p)
{
  if (!m_client || !Config::Get(Config::RA_ENABLED))
    return;
  size_t size = 0;
  if (!p.IsReadMode())
    size = rc_client_progress_size(m_client);
  p.Do(size);
  auto buffer = std::make_unique<u8[]>(size);
  if (!p.IsReadMode())
  {
    int result = rc_client_serialize_progress_sized(m_client, buffer.get(), size);
    if (result != RC_OK)
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Failed serializing achievement client with error code {}",
                    result);
      return;
    }
  }
  p.DoArray(buffer.get(), (u32)size);
  if (p.IsReadMode())
  {
    int result = rc_client_deserialize_progress_sized(m_client, buffer.get(), size);
    if (result != RC_OK)
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Failed deserializing achievement client with error code {}",
                    result);
      return;
    }
    size_t new_size = rc_client_progress_size(m_client);
    if (size != new_size)
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Loaded client size {} does not match size in state {}", new_size,
                    size);
      return;
    }
  }
  p.DoMarker("AchievementManager");
}

void AchievementManager::CloseGame()
{
  m_queue.Cancel();
  m_image_queue.Cancel();
  {
    std::lock_guard lg{m_lock};
    m_active_challenges.clear();
    m_active_leaderboards.clear();
    m_game_badge.width = 0;
    m_game_badge.height = 0;
    m_game_badge.data.clear();
    m_unlocked_badges.clear();
    m_locked_badges.clear();
    m_leaderboard_map.clear();
    m_rich_presence.fill('\0');
    m_system.store(nullptr, std::memory_order_release);
    if (Config::Get(Config::RA_DISCORD_PRESENCE_ENABLED))
      Discord::UpdateDiscordPresence();
    if (rc_client_get_game_info(m_client))
      rc_client_unload_game(m_client);
    INFO_LOG_FMT(ACHIEVEMENTS, "Game closed.");
  }

  update_event.Trigger(UpdatedItems{.all = true});
}

void AchievementManager::Logout()
{
  {
    CloseGame();
    std::lock_guard lg{m_lock};
    m_player_badge.width = 0;
    m_player_badge.height = 0;
    m_player_badge.data.clear();
    Config::SetBaseOrCurrent(Config::RA_API_TOKEN, "");
  }

  update_event.Trigger(UpdatedItems{.all = true});
  INFO_LOG_FMT(ACHIEVEMENTS, "Logged out from server.");
}

void AchievementManager::Shutdown()
{
  if (m_client)
  {
    CloseGame();
    m_queue.Shutdown();
    Config::RemoveConfigChangedCallback(m_config_changed_callback_id);
    std::lock_guard lg{m_lock};
    // DON'T log out - keep those credentials for next run.
    rc_client_destroy(m_client);
    m_client = nullptr;
    m_dll_found = false;
    INFO_LOG_FMT(ACHIEVEMENTS, "Achievement Manager shut down.");
  }
}

u32 AchievementManager::FindConsoleID(const DiscIO::Platform& platform)
{
  switch (platform)
  {
  case DiscIO::Platform::GameCubeDisc:
    return RC_CONSOLE_GAMECUBE;
  case DiscIO::Platform::WiiDisc:
  case DiscIO::Platform::WiiWAD:
    return RC_CONSOLE_WII;
  default:
    return RC_CONSOLE_UNKNOWN;
  }
}

void AchievementManager::LoadDefaultBadges()
{
  std::lock_guard lg{m_lock};

  std::string directory = File::GetSysDirectory() + DIR_SEP + RESOURCES_DIR + DIR_SEP;

  if (m_default_player_badge.data.empty())
  {
    if (!LoadPNGTexture(&m_default_player_badge,
                        fmt::format("{}{}", directory, DEFAULT_PLAYER_BADGE_FILENAME)))
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Default player badge '{}' failed to load",
                    DEFAULT_PLAYER_BADGE_FILENAME);
    }
  }

  if (m_default_game_badge.data.empty())
  {
    if (!LoadPNGTexture(&m_default_game_badge,
                        fmt::format("{}{}", directory, DEFAULT_GAME_BADGE_FILENAME)))
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Default game badge '{}' failed to load",
                    DEFAULT_GAME_BADGE_FILENAME);
    }
  }

  if (m_default_unlocked_badge.data.empty())
  {
    if (!LoadPNGTexture(&m_default_unlocked_badge,
                        fmt::format("{}{}", directory, DEFAULT_UNLOCKED_BADGE_FILENAME)))
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Default unlocked achievement badge '{}' failed to load",
                    DEFAULT_UNLOCKED_BADGE_FILENAME);
    }
  }

  if (m_default_locked_badge.data.empty())
  {
    if (!LoadPNGTexture(&m_default_locked_badge,
                        fmt::format("{}{}", directory, DEFAULT_LOCKED_BADGE_FILENAME)))
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Default locked achievement badge '{}' failed to load",
                    DEFAULT_LOCKED_BADGE_FILENAME);
    }
  }
}

void AchievementManager::LoadGameCallback(int result, const char* error_message,
                                          rc_client_t* client, void* userdata)
{
  auto& instance = AchievementManager::GetInstance();
  instance.m_loading_volume.reset(nullptr);
  if (result == RC_API_FAILURE)
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Load data request rejected for old Dolphin version.");
    OSD::AddMessage("RetroAchievements no longer supports this version of Dolphin.",
                    OSD::Duration::VERY_LONG, OSD::Color::RED);
    OSD::AddMessage("Please update Dolphin to a newer version.", OSD::Duration::VERY_LONG,
                    OSD::Color::RED);
    return;
  }
  if (result == RC_LOGIN_REQUIRED || result == RC_INVALID_CREDENTIALS || result == RC_EXPIRED_TOKEN)
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Invalid/expired RetroAchievements API token.");
    OSD::AddMessage(
        "You have been logged out from RetroAchievements due to invalid/expired credentials.",
        OSD::Duration::VERY_LONG, OSD::Color::RED);
    OSD::AddMessage("Please close the game to log back in before continuing.",
                    OSD::Duration::VERY_LONG, OSD::Color::RED);
    Config::SetBaseOrCurrent(Config::RA_API_TOKEN, "");
    instance.update_event.Trigger(UpdatedItems{.failed_login_code = result});
    return;
  }

  auto* game = rc_client_get_game_info(client);
  if (result == RC_OK)
  {
    if (!game)
    {
      ERROR_LOG_FMT(ACHIEVEMENTS, "Failed to retrieve game information from client.");
      OSD::AddMessage("Failed to load achievements for this title.", OSD::Duration::VERY_LONG,
                      OSD::Color::RED);
    }
    else
    {
      INFO_LOG_FMT(ACHIEVEMENTS, "Loaded data for game ID {}.", game->id);
      instance.m_display_welcome_message = true;
    }
  }
  else
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed to load data for current game.");
    OSD::AddMessage("Achievements are not supported for this title.", OSD::Duration::VERY_LONG,
                    OSD::Color::RED);
  }

  if (game == nullptr)
    return;

  instance.FetchGameBadges();
  instance.m_system.store(&Core::System::GetInstance(), std::memory_order_release);
  instance.update_event.Trigger({.all = true});
  // Set this to a value that will immediately trigger RP
  instance.m_last_rp_time = std::chrono::steady_clock::now() - std::chrono::minutes{2};

  std::lock_guard lg{instance.GetLock()};
  auto* leaderboard_list =
      rc_client_create_leaderboard_list(client, RC_CLIENT_LEADERBOARD_LIST_GROUPING_NONE);
  for (u32 bucket = 0; bucket < leaderboard_list->num_buckets; bucket++)
  {
    const auto& leaderboard_bucket = leaderboard_list->buckets[bucket];
    for (u32 board = 0; board < leaderboard_bucket.num_leaderboards; board++)
    {
      const auto& leaderboard = leaderboard_bucket.leaderboards[board];
      instance.m_leaderboard_map.insert(
          std::pair(leaderboard->id, LeaderboardStatus{.name = leaderboard->title,
                                                       .description = leaderboard->description}));
    }
  }
  rc_client_destroy_leaderboard_list(leaderboard_list);
}

void AchievementManager::ChangeMediaCallback(int result, const char* error_message,
                                             rc_client_t* client, void* userdata)
{
  AchievementManager::GetInstance().m_loading_volume.reset(nullptr);
  if (result == RC_OK)
  {
    return;
  }

  if (result == RC_HARDCORE_DISABLED)
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Hardcore disabled. Unrecognized media inserted.");
  }
  else
  {
    if (!error_message)
      error_message = rc_error_str(result);

    ERROR_LOG_FMT(ACHIEVEMENTS, "RetroAchievements media change failed: {}", error_message);
  }
}

void AchievementManager::LoginCallback(int result, const char* error_message, rc_client_t* client,
                                       void* userdata)
{
  auto& instance = GetInstance();
  if (result == RC_OK)
  {
    auto* user = rc_client_get_user_info(client);
    if (user != nullptr)
    {
      INFO_LOG_FMT(ACHIEVEMENTS, "Successfully logged in as {}.", user->username);
      OSD::AddMessage(fmt::format("Logged in to RetroAchievements as {}", user->display_name),
                      OSD::Duration::NORMAL, OSD::Color::GREEN);
      Config::SetBaseOrCurrent(Config::RA_API_TOKEN, user->token);
      instance.FetchPlayerBadge();
    }
  }
  else
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed to login to RetroAchievements server with error: {}",
                 error_message);
    OSD::AddMessage(fmt::format("Failed to log in to RetroAchievements: {}", error_message),
                    OSD::Duration::NORMAL, OSD::Color::RED);
  }
  instance.login_event.Trigger(result);
}

void AchievementManager::FetchBoardInfo(AchievementId leaderboard_id)
{
  auto leaderboard = m_leaderboard_map.find(leaderboard_id);
  if (leaderboard != m_leaderboard_map.end() && leaderboard->second.entries.size() > 0)
    return;

  auto callback_data = std::make_unique<AchievementId>(leaderboard_id);
  rc_client_begin_fetch_leaderboard_entries(m_client, leaderboard_id, 1, 10,
                                            LeaderboardEntriesCallback, callback_data.release());
}

void AchievementManager::SetHardcoreMode()
{
  if (rc_client_get_hardcore_enabled(m_client) != Config::Get(Config::RA_HARDCORE_ENABLED))
  {
    rc_client_set_hardcore_enabled(m_client, Config::Get(Config::RA_HARDCORE_ENABLED));
    update_event.Trigger(UpdatedItems{.all = true});
  }
}

void AchievementManager::LeaderboardEntriesCallback(int result, const char* error_message,
                                                    rc_client_leaderboard_entry_list_t* list,
                                                    rc_client_t* client, void* userdata)
{
  auto leaderboard_id = std::unique_ptr<AchievementId>(static_cast<AchievementId*>(userdata));
  if (result != RC_OK)
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed to fetch leaderboard entries for ID {}.", *leaderboard_id);
    return;
  }

  auto& instance = GetInstance();
  std::lock_guard lg{instance.m_lock};
  auto& leaderboard = instance.m_leaderboard_map[*leaderboard_id];
  leaderboard.entries.clear();
  for (u32 ix = 0; ix < list->num_entries; ix++)
  {
    auto& response_entry = list->entries[ix];
    auto& map_entry = leaderboard.entries[ix + 1];
    map_entry.username.assign(response_entry.user);
    memcpy(map_entry.score.data(), response_entry.display, FORMAT_SIZE);
    map_entry.rank = response_entry.rank;
    if (static_cast<int32_t>(ix) == list->user_index)
      leaderboard.player_index = response_entry.rank;
  }
  instance.update_event.Trigger({.leaderboards = {*leaderboard_id}});
}

void AchievementManager::Request(const rc_api_request_t* request,
                                 rc_client_server_callback_t callback, void* callback_data,
                                 rc_client_t* client)
{
  std::string url = request->url;
  std::string post_data = request->post_data;
  AchievementManager::GetInstance().m_queue.Push(
      [url = std::move(url), post_data = std::move(post_data), callback, callback_data] {
        Common::HttpRequest http_request;
        Common::HttpRequest::Response http_response;
        if (!post_data.empty())
        {
          http_response = http_request.Post(url, post_data, USER_AGENT_HEADER,
                                            Common::HttpRequest::AllowedReturnCodes::All);
        }
        else
        {
          http_response = http_request.Get(url, USER_AGENT_HEADER,
                                           Common::HttpRequest::AllowedReturnCodes::All);
        }

        rc_api_server_response_t server_response;
        if (http_response.has_value() && http_response->size() > 0)
        {
          server_response.body = reinterpret_cast<const char*>(http_response->data());
          server_response.body_length = http_response->size();
          server_response.http_status_code = http_request.GetLastResponseCode();
        }
        else
        {
          static constexpr char error_message[] = "Failed HTTP request.";
          server_response.body = error_message;
          server_response.body_length = sizeof(error_message);
          server_response.http_status_code = RC_API_SERVER_RESPONSE_RETRYABLE_CLIENT_ERROR;
        }

        callback(&server_response, callback_data);
      });
}

u32 AchievementManager::MemoryPeeker(u32 address, u8* buffer, u32 num_bytes, rc_client_t* client)
{
  if (buffer == nullptr)
    return 0u;
  auto& system = Core::System::GetInstance();
  Core::CPUThreadGuard thread_guard(system);
  for (u32 num_read = 0; num_read < num_bytes; num_read++)
  {
    auto value = system.GetMMU().HostTryRead<u8>(thread_guard, address + num_read,
                                                 PowerPC::RequestedAddressSpace::Physical);
    if (!value.has_value())
      return num_read;
    buffer[num_read] = value.value().value;
  }
  return num_bytes;
}

#ifdef RC_CLIENT_SUPPORTS_RAINTEGRATION
void AchievementManager::LoadIntegrationCallback(int result, const char* error_message,
                                                 rc_client_t* client, void* userdata)
{
  auto& instance = GetInstance();
  if (result == RC_OK)
  {
    instance.m_dll_found = true;
    rc_client_raintegration_set_event_handler(client, RAIntegrationEventHandler);
    rc_client_raintegration_set_write_memory_function(client, MemoryPoker);
    rc_client_raintegration_set_get_game_title_estimate_function(client, GameTitleEstimateHandler);
  }
  else
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed loading RA Integration DLL with error: {}",
                 error_message);
  }
  if (instance.HasAPIToken())
    instance.Login("");
}

void AchievementManager::RAIntegrationEventHandler(const rc_client_raintegration_event_t* event,
                                                   rc_client_t* client)
{
  auto& instance = AchievementManager::GetInstance();
  switch (event->type)
  {
  case RC_CLIENT_RAINTEGRATION_EVENT_MENU_CHANGED:
    instance.dev_menu_update_event.Trigger();
    break;
  case RC_CLIENT_RAINTEGRATION_EVENT_PAUSE_CHANGED:
    if (rc_client_raintegration_is_paused(client))
      Core::Pause(*instance.m_system.load(std::memory_order_acquire));
    else
      Core::Resume(*instance.m_system.load(std::memory_order_acquire));
    break;
  default:
    break;
  }
}

void AchievementManager::MemoryPoker(u32 address, u8* buffer, u32 num_bytes, rc_client_t* client)
{
  auto& system = Core::System::GetInstance();
  Core::CPUThreadGuard thread_guard(system);
  for (u32 num_written = 0; num_written < num_bytes; num_written++)
  {
    system.GetMMU().HostWrite<u8>(thread_guard, buffer[num_written], address + num_written,
                                  PowerPC::RequestedAddressSpace::Physical);
  }
}

void AchievementManager::GameTitleEstimateHandler(char* buffer, u32 buffer_size,
                                                  rc_client_t* client)
{
  auto& instance = AchievementManager::GetInstance();
  strncpy(buffer, instance.m_title_estimate.c_str(), buffer_size);
}
#endif  // RC_CLIENT_SUPPORTS_RAINTEGRATION

#endif  // USE_RETRO_ACHIEVEMENTS
