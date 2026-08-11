// SPDX-License-Identifier: GPL-2.0-or-later

#ifdef USE_RETRO_ACHIEVEMENTS

#include "Core/Achievements/AchievementManager.h"

#include <fmt/format.h>
#include <rcheevos/include/rc_api_user.h>

#include "Common/FileUtil.h"
#include "Common/HttpRequest.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/Crypto/SHA1.h"
#include "Common/ScopeGuard.h"
#include "Common/StringUtil.h"
#include "Common/Version.h"
#include "Core/System.h"

#ifdef ANDROID
static const Common::HttpRequest::Headers USER_AGENT_HEADER = {
    {"User-Agent", Common::GetUserAgentStr() + " (Android)"}};
#else   // ANDROID
static const Common::HttpRequest::Headers USER_AGENT_HEADER = {
    {"User-Agent", Common::GetUserAgentStr()}};
#endif  // ANDROID

void AchievementManager::FetchBadge(AchievementManager::Badge* badge, u32 badge_type,
                                    AchievementManager::BadgeNameFunction function,
                                    UpdatedItems callback_data)
{
  if (!m_client || !HasAPIToken())
  {
    update_event.Trigger(callback_data);
    if (m_display_welcome_message && badge_type == RC_IMAGE_TYPE_GAME)
      DisplayWelcomeMessage();
    return;
  }

  m_image_queue.Push([this, badge, badge_type, function = std::move(function),
                      callback_data = std::move(callback_data)] {
    Common::ScopeGuard on_end_scope([&] {
      if (m_display_welcome_message && badge_type == RC_IMAGE_TYPE_GAME)
        DisplayWelcomeMessage();
    });

    std::string name_to_fetch;
    {
      std::lock_guard lg{m_lock};
      name_to_fetch = function(*this);
      if (name_to_fetch.empty())
        return;
    }

    const std::string cache_path = fmt::format(
        "{}/badge-{}-{}.png", File::GetUserPath(D_RETROACHIEVEMENTSCACHE_IDX), badge_type,
        Common::SHA1::DigestToString(Common::SHA1::CalculateDigest(name_to_fetch)));

    AchievementManager::Badge tmp_badge;
    if (!LoadPNGTexture(&tmp_badge, cache_path))
    {
      rc_api_fetch_image_request_t icon_request = {.image_name = name_to_fetch.c_str(),
                                                   .image_type = badge_type};
      rc_api_request_t api_request;
      Common::HttpRequest http_request;
      if (rc_api_init_fetch_image_request(&api_request, &icon_request) != RC_OK)
      {
        ERROR_LOG_FMT(ACHIEVEMENTS, "Invalid request for image {}.", name_to_fetch);
        return;
      }
      auto http_response = http_request.Get(api_request.url, USER_AGENT_HEADER,
                                            Common::HttpRequest::AllowedReturnCodes::All);
      if (!http_response.has_value() || http_response->empty())
      {
        WARN_LOG_FMT(ACHIEVEMENTS,
                     "RetroAchievements connection failed on image request.\n URL: {}",
                     api_request.url);
        rc_api_destroy_request(&api_request);
        update_event.Trigger(callback_data);
        return;
      }

      rc_api_destroy_request(&api_request);

      INFO_LOG_FMT(ACHIEVEMENTS, "Successfully downloaded badge id {}.", name_to_fetch);

      if (!LoadPNGTexture(&tmp_badge, *http_response))
      {
        ERROR_LOG_FMT(ACHIEVEMENTS, "Badge '{}' failed to load", name_to_fetch);
        return;
      }

      std::string temp_path = fmt::format("{}.tmp", cache_path);
      File::IOFile temp_file(temp_path, "wb");
      if (!temp_file.IsOpen() ||
          !temp_file.WriteBytes(http_response->data(), http_response->size()) ||
          !temp_file.Close() || !File::Rename(temp_path, cache_path))
      {
        File::Delete(temp_path);
        WARN_LOG_FMT(ACHIEVEMENTS, "Failed to store badge '{}' to cache", name_to_fetch);
      }
    }

    std::lock_guard lg{m_lock};
    if (function(*this).empty() || name_to_fetch != function(*this))
    {
      INFO_LOG_FMT(ACHIEVEMENTS, "Requested outdated badge id {}.", name_to_fetch);
      return;
    }

    *badge = std::move(tmp_badge);
    update_event.Trigger(callback_data);
    if (badge_type == RC_IMAGE_TYPE_ACHIEVEMENT &&
        m_active_challenges.contains(*callback_data.achievements.begin()))
    {
      m_challenges_updated = true;
    }
  });
}

#endif  // USE_RETRO_ACHIEVEMENTS
