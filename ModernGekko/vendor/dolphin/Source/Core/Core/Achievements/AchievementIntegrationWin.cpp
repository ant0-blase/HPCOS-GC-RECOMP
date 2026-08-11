// SPDX-License-Identifier: GPL-2.0-or-later

#ifdef USE_RETRO_ACHIEVEMENTS
#ifdef RC_CLIENT_SUPPORTS_RAINTEGRATION

#include "Core/Achievements/AchievementManager.h"

#include <cstring>
#include <fmt/format.h>

#include "Common/Logging/Log.h"
#include "Core/Core.h"
#include "Core/System.h"

void AchievementManager::LoadIntegrationCallback(int result, const char* error_message,
                                                 rc_client_t* client, void* userdata)
{
  auto& instance = AchievementManager::GetInstance();
  switch (result)
  {
  case RC_OK:
    INFO_LOG_FMT(ACHIEVEMENTS, "RAIntegration.dll found.");
    instance.m_dll_found = true;
    rc_client_set_allow_background_memory_reads(instance.m_client, 0);
    rc_client_raintegration_set_event_handler(instance.m_client, RAIntegrationEventHandler);
    rc_client_raintegration_set_write_memory_function(instance.m_client, MemoryPoker);
    rc_client_raintegration_set_get_game_name_function(instance.m_client, GameTitleEstimateHandler);
    instance.dev_menu_update_event.Trigger();
    break;

  case RC_MISSING_VALUE:
    INFO_LOG_FMT(ACHIEVEMENTS, "RAIntegration.dll not found.");
    break;

  default:
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed to load RAIntegration.dll. {}", error_message);
    break;
  }

  if (instance.HasAPIToken())
    instance.Login("");
  INFO_LOG_FMT(ACHIEVEMENTS, "Achievement Manager Initialized");
}

void AchievementManager::RAIntegrationEventHandler(const rc_client_raintegration_event_t* event,
                                                   rc_client_t* client)
{
  auto& instance = AchievementManager::GetInstance();
  switch (event->type)
  {
  case RC_CLIENT_RAINTEGRATION_EVENT_MENU_CHANGED:
  case RC_CLIENT_RAINTEGRATION_EVENT_MENUITEM_CHECKED_CHANGED:
    instance.dev_menu_update_event.Trigger();
    break;
  case RC_CLIENT_RAINTEGRATION_EVENT_PAUSE:
  {
    Core::QueueHostJob([](Core::System& system) { Core::SetState(system, Core::State::Paused); });
    break;
  }
  case RC_CLIENT_RAINTEGRATION_EVENT_HARDCORE_CHANGED:
    Config::SetBaseOrCurrent(Config::RA_HARDCORE_ENABLED,
                             !Config::Get(Config::RA_HARDCORE_ENABLED));
    break;
  default:
    WARN_LOG_FMT(ACHIEVEMENTS, "Unsupported raintegration event. {}", event->type);
    break;
  }
}

void AchievementManager::MemoryPoker(u32 address, u8* buffer, u32 num_bytes, rc_client_t* client)
{
  if (buffer == nullptr)
    return;
  auto& instance = AchievementManager::GetInstance();
  Core::System* system = instance.m_system.load(std::memory_order_acquire);
  if (!system)
    return;
  Core::CPUThreadGuard thread_guard(*system);
  system->GetMemory().CopyToEmu(address, buffer, num_bytes);
}

void AchievementManager::GameTitleEstimateHandler(char* buffer, u32 buffer_size,
                                                  rc_client_t* client)
{
  auto& instance = AchievementManager::GetInstance();
  std::lock_guard lg{instance.m_lock};
  strncpy(buffer, instance.m_title_estimate.c_str(), static_cast<size_t>(buffer_size));
}

#endif  // RC_CLIENT_SUPPORTS_RAINTEGRATION
#endif  // USE_RETRO_ACHIEVEMENTS
