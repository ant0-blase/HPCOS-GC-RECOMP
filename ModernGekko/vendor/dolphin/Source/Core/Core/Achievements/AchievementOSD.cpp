// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Achievements/AchievementManager.h"
#include "Common/Logging/Log.h"
#include "Core/Config/AchievementSettings.h"
#include "Core/Core.h"
#include "Core/System.h"
#include "VideoCommon/OnScreenDisplay.h"

#include <fmt/format.h>

#ifdef USE_RETRO_ACHIEVEMENTS

void AchievementManager::DisplayWelcomeMessage()
{
  std::lock_guard lg{m_lock};
  m_display_welcome_message = false;
  const u32 color =
      rc_client_get_hardcore_enabled(m_client) ? OSD::Color::YELLOW : OSD::Color::CYAN;

  OSD::AddMessage("", OSD::Duration::VERY_LONG, OSD::Color::GREEN, &GetGameBadge());
  auto info = rc_client_get_game_info(m_client);
  if (!info)
  {
    ERROR_LOG_FMT(ACHIEVEMENTS, "Attempting to welcome player to game not running.");
    return;
  }
  OSD::AddMessage(info->title, OSD::Duration::VERY_LONG, OSD::Color::GREEN);
  rc_client_user_game_summary_t summary;
  rc_client_get_user_game_summary(m_client, &summary);
  OSD::AddMessage(fmt::format("You have {}/{} achievements worth {}/{} points",
                              summary.num_unlocked_achievements, summary.num_core_achievements,
                              summary.points_unlocked, summary.points_core),
                  OSD::Duration::VERY_LONG, color);
  if (summary.num_unsupported_achievements > 0)
  {
    OSD::AddMessage(
        fmt::format("{} achievements unsupported", summary.num_unsupported_achievements),
        OSD::Duration::VERY_LONG, OSD::Color::RED);
  }
  OSD::AddMessage(
      fmt::format("Hardcore mode is {}", rc_client_get_hardcore_enabled(m_client) ? "ON" : "OFF"),
      OSD::Duration::VERY_LONG, color);
  OSD::AddMessage(fmt::format("Leaderboard submissions are {}",
                              rc_client_get_hardcore_enabled(m_client) ? "ON" : "OFF"),
                  OSD::Duration::VERY_LONG, color);
}

void AchievementManager::HandleAchievementTriggeredEvent(const rc_client_event_t* client_event)
{
  auto& instance = AchievementManager::GetInstance();

  OSD::AddMessage(fmt::format("Unlocked: {} ({})", client_event->achievement->title,
                              client_event->achievement->points),
                  OSD::Duration::VERY_LONG,
                  (rc_client_get_hardcore_enabled(instance.m_client)) ? OSD::Color::YELLOW :
                                                                        OSD::Color::CYAN,
                  &instance.GetAchievementBadge(client_event->achievement->id, false));
  instance.update_event.Trigger(UpdatedItems{.achievements = {client_event->achievement->id}});
#ifdef RC_CLIENT_SUPPORTS_RAINTEGRATION
  switch (rc_client_raintegration_get_achievement_state(instance.m_client,
                                                        client_event->achievement->id))
  {
  case RC_CLIENT_RAINTEGRATION_ACHIEVEMENT_STATE_LOCAL:
    // Achievement only exists locally and has not been uploaded.
    OSD::AddMessage("Local achievement; not submitted to site.", OSD::Duration::VERY_LONG,
                    OSD::Color::GREEN);
    break;
  case RC_CLIENT_RAINTEGRATION_ACHIEVEMENT_STATE_MODIFIED:
    // Achievement has been modified locally and differs from the one on the site.
    OSD::AddMessage("Modified achievement; not submitted to site.", OSD::Duration::VERY_LONG,
                    OSD::Color::GREEN);
    break;
  case RC_CLIENT_RAINTEGRATION_ACHIEVEMENT_STATE_INSECURE:
    // The player has done something that we consider cheating like modifying the RAM while playing.
    // Just indicate that the achievement was only unlocked locally, but don't clarify why.
    OSD::AddMessage("Achievement not submitted to site.", OSD::Duration::VERY_LONG,
                    OSD::Color::GREEN);
    break;
  default:
    break;
  }
#endif  // RC_CLIENT_SUPPORTS_RAINTEGRATION
}

void AchievementManager::HandleLeaderboardStartedEvent(const rc_client_event_t* client_event)
{
  if (Config::Get(Config::RA_LEADERBOARD_TRACKER_ENABLED))
  {
    OSD::AddMessage(fmt::format("Attempting leaderboard: {} - {}", client_event->leaderboard->title,
                                client_event->leaderboard->description),
                    OSD::Duration::VERY_LONG, OSD::Color::GREEN);
  }
  AchievementManager::GetInstance().FetchBoardInfo(client_event->leaderboard->id);
}

void AchievementManager::HandleLeaderboardFailedEvent(const rc_client_event_t* client_event)
{
  if (Config::Get(Config::RA_LEADERBOARD_TRACKER_ENABLED))
  {
    OSD::AddMessage(fmt::format("Failed leaderboard: {}", client_event->leaderboard->title),
                    OSD::Duration::VERY_LONG, OSD::Color::RED);
  }
  AchievementManager::GetInstance().FetchBoardInfo(client_event->leaderboard->id);
}

void AchievementManager::HandleLeaderboardSubmittedEvent(const rc_client_event_t* client_event)
{
  auto& instance = AchievementManager::GetInstance();
  if (Config::Get(Config::RA_LEADERBOARD_TRACKER_ENABLED))
  {
    OSD::AddMessage(fmt::format("Scored {} on leaderboard: {}",
                                client_event->leaderboard->tracker_value,
                                client_event->leaderboard->title),
                    OSD::Duration::VERY_LONG, OSD::Color::YELLOW);
  }
  instance.FetchBoardInfo(client_event->leaderboard->id);
  instance.update_event.Trigger(UpdatedItems{.leaderboards = {client_event->leaderboard->id}});
}

void AchievementManager::HandleLeaderboardTrackerUpdateEvent(const rc_client_event_t* client_event)
{
  auto& active_leaderboards = AchievementManager::GetInstance().m_active_leaderboards;
  for (auto& leaderboard : active_leaderboards)
  {
    if (leaderboard.id == client_event->leaderboard_tracker->id)
    {
      strncpy(leaderboard.display, client_event->leaderboard_tracker->display,
              RC_CLIENT_LEADERBOARD_DISPLAY_SIZE);
    }
  }
}

void AchievementManager::HandleLeaderboardTrackerShowEvent(const rc_client_event_t* client_event)
{
  AchievementManager::GetInstance().m_active_leaderboards.push_back(
      *client_event->leaderboard_tracker);
}

void AchievementManager::HandleLeaderboardTrackerHideEvent(const rc_client_event_t* client_event)
{
  auto& active_leaderboards = AchievementManager::GetInstance().m_active_leaderboards;
  std::erase_if(active_leaderboards, [client_event](const auto& leaderboard) {
    return leaderboard.id == client_event->leaderboard_tracker->id;
  });
}

void AchievementManager::HandleAchievementChallengeIndicatorShowEvent(
    const rc_client_event_t* client_event)
{
  auto& instance = AchievementManager::GetInstance();
  const auto [iter, inserted] = instance.m_active_challenges.insert(client_event->achievement->id);
  if (inserted)
    instance.m_challenges_updated = true;
  instance.update_event.Trigger(UpdatedItems{.rich_presence = true});
}

void AchievementManager::HandleAchievementChallengeIndicatorHideEvent(
    const rc_client_event_t* client_event)
{
  auto& instance = AchievementManager::GetInstance();
  const auto removed = instance.m_active_challenges.erase(client_event->achievement->id);
  if (removed > 0)
    instance.m_challenges_updated = true;
  instance.update_event.Trigger(UpdatedItems{.rich_presence = true});
}

void AchievementManager::HandleAchievementProgressIndicatorShowEvent(
    const rc_client_event_t* client_event)
{
  auto& instance = AchievementManager::GetInstance();
  auto current_time = std::chrono::steady_clock::now();
  const auto message_wait_time = std::chrono::milliseconds{OSD::Duration::SHORT};
  if (current_time - instance.m_last_progress_message < message_wait_time)
    return;
  OSD::AddMessage(fmt::format("{} {}", client_event->achievement->title,
                              client_event->achievement->measured_progress),
                  OSD::Duration::SHORT, OSD::Color::GREEN,
                  &instance.GetAchievementBadge(client_event->achievement->id, false));
  instance.m_last_progress_message = current_time;
  instance.update_event.Trigger(UpdatedItems{.achievements = {client_event->achievement->id}});
}

void AchievementManager::HandleGameCompletedEvent(const rc_client_event_t* client_event,
                                                   rc_client_t* client)
{
  auto* user_info = rc_client_get_user_info(client);
  auto* game_info = rc_client_get_game_info(client);
  if (!user_info || !game_info)
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Received Game Completed event when game not running.");
    return;
  }
  bool hardcore = rc_client_get_hardcore_enabled(client);
  OSD::AddMessage(fmt::format("Congratulations, {}! You have {} {}", user_info->display_name,
                              hardcore ? "mastered" : "completed", game_info->title),
                  OSD::Duration::VERY_LONG, hardcore ? OSD::Color::YELLOW : OSD::Color::CYAN,
                  &AchievementManager::GetInstance().GetGameBadge());
}

void AchievementManager::HandleResetEvent(const rc_client_event_t* client_event)
{
  INFO_LOG_FMT(ACHIEVEMENTS, "Reset requested by Achievement Manager");
  Core::Stop(Core::System::GetInstance());
}

void AchievementManager::HandleServerErrorEvent(const rc_client_event_t* client_event)
{
  ERROR_LOG_FMT(ACHIEVEMENTS, "RetroAchievements server error: {} {}",
                client_event->server_error->api, client_event->server_error->error_message);
}

void AchievementManager::EventHandler(const rc_client_event_t* event, rc_client_t* client)
{
  switch (event->type)
  {
  case RC_CLIENT_EVENT_ACHIEVEMENT_TRIGGERED:
    HandleAchievementTriggeredEvent(event);
    break;
  case RC_CLIENT_EVENT_LEADERBOARD_STARTED:
    HandleLeaderboardStartedEvent(event);
    break;
  case RC_CLIENT_EVENT_LEADERBOARD_FAILED:
    HandleLeaderboardFailedEvent(event);
    break;
  case RC_CLIENT_EVENT_LEADERBOARD_SUBMITTED:
    HandleLeaderboardSubmittedEvent(event);
    break;
  case RC_CLIENT_EVENT_LEADERBOARD_TRACKER_UPDATE:
    HandleLeaderboardTrackerUpdateEvent(event);
    break;
  case RC_CLIENT_EVENT_LEADERBOARD_TRACKER_SHOW:
    HandleLeaderboardTrackerShowEvent(event);
    break;
  case RC_CLIENT_EVENT_LEADERBOARD_TRACKER_HIDE:
    HandleLeaderboardTrackerHideEvent(event);
    break;
  case RC_CLIENT_EVENT_ACHIEVEMENT_CHALLENGE_INDICATOR_SHOW:
    HandleAchievementChallengeIndicatorShowEvent(event);
    break;
  case RC_CLIENT_EVENT_ACHIEVEMENT_CHALLENGE_INDICATOR_HIDE:
    HandleAchievementChallengeIndicatorHideEvent(event);
    break;
  case RC_CLIENT_EVENT_ACHIEVEMENT_PROGRESS_INDICATOR_SHOW:
  case RC_CLIENT_EVENT_ACHIEVEMENT_PROGRESS_INDICATOR_UPDATE:
    HandleAchievementProgressIndicatorShowEvent(event);
    break;
  case RC_CLIENT_EVENT_ACHIEVEMENT_PROGRESS_INDICATOR_HIDE:
    break;
  case RC_CLIENT_EVENT_GAME_COMPLETED:
    HandleGameCompletedEvent(event, client);
    break;
  case RC_CLIENT_EVENT_RESET:
    HandleResetEvent(event);
    break;
  case RC_CLIENT_EVENT_SERVER_ERROR:
    HandleServerErrorEvent(event);
    break;
  default:
    INFO_LOG_FMT(ACHIEVEMENTS, "Event triggered of unhandled type {}", event->type);
    break;
  }
}

#endif // USE_RETRO_ACHIEVEMENTS
