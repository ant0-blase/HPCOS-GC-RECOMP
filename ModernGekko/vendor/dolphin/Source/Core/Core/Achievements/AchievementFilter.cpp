// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Achievements/AchievementManager.h"
#include "Common/BitUtils.h"
#include "Common/CommonPaths.h"
#include "Common/FileUtil.h"
#include "Common/JsonUtil.h"
#include "Common/Logging/Log.h"
#include "Common/Crypto/SHA1.h"
#include "Core/Achievements/AchievementApprovedHash.h"
#include "Core/Cheats/ActionReplay.h"
#include "Core/Cheats/GeckoCode.h"
#include "Core/Cheats/PatchEngine.h"
#include "Core/ConfigLoaders/GameConfigLoader.h"
#include "VideoCommon/OnScreenDisplay.h"

#ifdef USE_RETRO_ACHIEVEMENTS

picojson::value AchievementManager::LoadApprovedList()
{
  picojson::value temp;
  std::string error;
  if (!JsonFromFile(fmt::format("{}{}{}", File::GetSysDirectory(), DIR_SEP,
                                ACHIEVEMENT_APPROVED_LIST_FILENAME),
                    &temp, &error))
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed to load approved game settings list {}",
                 ACHIEVEMENT_APPROVED_LIST_FILENAME);
    WARN_LOG_FMT(ACHIEVEMENTS, "Error: {}", error);
    return {};
  }
  auto context = Common::SHA1::CreateContext();
  context->Update(temp.serialize());
  auto digest = context->Finish();
  if (digest != ACHIEVEMENT_APPROVED_LIST_HASH)
  {
    WARN_LOG_FMT(ACHIEVEMENTS, "Failed to verify approved game settings list {}",
                 ACHIEVEMENT_APPROVED_LIST_FILENAME);
    WARN_LOG_FMT(ACHIEVEMENTS, "Expected hash {}, found hash {}",
                 Common::SHA1::DigestToString(ACHIEVEMENT_APPROVED_LIST_HASH),
                 Common::SHA1::DigestToString(digest));
    return {};
  }
  return temp;
}

template <typename T>
void AchievementManager::FilterApprovedIni(std::vector<T>& codes, std::string_view game_id,
                                           u16 revision) const
{
  if (codes.empty())
  {
    // There's nothing to verify, so let's save ourselves some work
    return;
  }

  std::lock_guard lg{m_lock};

  if (!IsHardcoreModeActive())
    return;

  // Approved codes list failed to hash
  if (!m_ini_root->is<picojson::value::object>())
  {
    codes.clear();
    return;
  }

  for (auto& code : codes)
  {
    if (code.enabled && !IsApprovedCode(code, game_id, revision))
      code.enabled = false;
  }
}

template <typename T>
bool AchievementManager::ShouldCodeBeActivated(const T& code, std::string_view game_id,
                                               u16 revision) const
{
  if (!code.enabled)
    return false;

  if (!IsHardcoreModeActive())
    return true;

  // Approved codes list failed to hash
  if (!m_ini_root->is<picojson::value::object>())
    return false;

  INFO_LOG_FMT(ACHIEVEMENTS, "Verifying code {}", code.name);

  if (IsApprovedCode(code, game_id, revision))
    return true;

  OSD::AddMessage(fmt::format("Failed to verify code {} for game ID {}.", code.name, game_id),
                  OSD::Duration::VERY_LONG, OSD::Color::RED);
  OSD::AddMessage("Disable hardcore mode to enable this code.", OSD::Duration::VERY_LONG,
                  OSD::Color::RED);

  return false;
}

template <typename T>
bool AchievementManager::IsApprovedCode(const T& code, std::string_view game_id, u16 revision) const
{
  // Approved codes list failed to hash
  if (!m_ini_root->is<picojson::value::object>())
    return false;

  const auto hash = Common::SHA1::DigestToString(GetCodeHash(code));

  for (const std::string& filename : ConfigLoaders::GetGameIniFilenames(game_id, revision))
  {
    const auto config = filename.substr(0, filename.length() - 4);
    if (m_ini_root->contains(config))
    {
      const auto ini_config = m_ini_root->get(config);
      if (ini_config.is<picojson::object>() && ini_config.contains(code.name))
      {
        const auto ini_code = ini_config.get(code.name);
        if (ini_code.template is<std::string>() && ini_code.template get<std::string>() == hash)
          return true;
      }
    }
  }
  return false;
}

Common::SHA1::Digest AchievementManager::GetCodeHash(const PatchEngine::Patch& patch) const
{
  auto context = Common::SHA1::CreateContext();
  context->Update(Common::BitCastToArray<u8>(static_cast<u64>(patch.entries.size())));
  for (const auto& entry : patch.entries)
  {
    context->Update(Common::BitCastToArray<u8>(entry.type));
    context->Update(Common::BitCastToArray<u8>(entry.address));
    context->Update(Common::BitCastToArray<u8>(entry.value));
    context->Update(Common::BitCastToArray<u8>(entry.comparand));
    context->Update(Common::BitCastToArray<u8>(entry.conditional));
  }
  return context->Finish();
}

Common::SHA1::Digest AchievementManager::GetCodeHash(const Gecko::GeckoCode& code) const
{
  auto context = Common::SHA1::CreateContext();
  context->Update(Common::BitCastToArray<u8>(static_cast<u64>(code.codes.size())));
  for (const auto& entry : code.codes)
  {
    context->Update(Common::BitCastToArray<u8>(entry.address));
    context->Update(Common::BitCastToArray<u8>(entry.data));
  }
  return context->Finish();
}

Common::SHA1::Digest AchievementManager::GetCodeHash(const ActionReplay::ARCode& code) const
{
  auto context = Common::SHA1::CreateContext();
  context->Update(Common::BitCastToArray<u8>(static_cast<u64>(code.ops.size())));
  for (const auto& entry : code.ops)
  {
    context->Update(Common::BitCastToArray<u8>(entry.cmd_addr));
    context->Update(Common::BitCastToArray<u8>(entry.value));
  }
  return context->Finish();
}

void AchievementManager::FilterApprovedPatches(std::vector<PatchEngine::Patch>& patches,
                                               std::string_view game_id, u16 revision) const
{
  FilterApprovedIni(patches, game_id, revision);
}

void AchievementManager::FilterApprovedGeckoCodes(std::vector<Gecko::GeckoCode>& codes,
                                                   std::string_view game_id, u16 revision) const
{
  FilterApprovedIni(codes, game_id, revision);
}

void AchievementManager::FilterApprovedARCodes(std::vector<ActionReplay::ARCode>& codes,
                                               std::string_view game_id, u16 revision) const
{
  FilterApprovedIni(codes, game_id, revision);
}

bool AchievementManager::ShouldGeckoCodeBeActivated(const Gecko::GeckoCode& code,
                                                    std::string_view game_id, u16 revision) const
{
  return ShouldCodeBeActivated(code, game_id, revision);
}

bool AchievementManager::ShouldARCodeBeActivated(const ActionReplay::ARCode& code,
                                                 std::string_view game_id, u16 revision) const
{
  return ShouldCodeBeActivated(code, game_id, revision);
}

bool AchievementManager::IsApprovedGeckoCode(const Gecko::GeckoCode& code, std::string_view game_id,
                                             u16 revision) const
{
  return IsApprovedCode(code, game_id, revision);
}

bool AchievementManager::IsApprovedARCode(const ActionReplay::ARCode& code,
                                          std::string_view game_id, u16 revision) const
{
  return IsApprovedCode(code, game_id, revision);
}

// Explicit template instantiations for internal use
template void AchievementManager::FilterApprovedIni<PatchEngine::Patch>(
    std::vector<PatchEngine::Patch>&, std::string_view, u16) const;
template void AchievementManager::FilterApprovedIni<Gecko::GeckoCode>(
    std::vector<Gecko::GeckoCode>&, std::string_view, u16) const;
template void AchievementManager::FilterApprovedIni<ActionReplay::ARCode>(
    std::vector<ActionReplay::ARCode>&, std::string_view, u16) const;

template bool AchievementManager::ShouldCodeBeActivated<Gecko::GeckoCode>(
    const Gecko::GeckoCode&, std::string_view, u16) const;
template bool AchievementManager::ShouldCodeBeActivated<ActionReplay::ARCode>(
    const ActionReplay::ARCode&, std::string_view, u16) const;

template bool AchievementManager::IsApprovedCode<PatchEngine::Patch>(
    const PatchEngine::Patch&, std::string_view, u16) const;
template bool AchievementManager::IsApprovedCode<Gecko::GeckoCode>(
    const Gecko::GeckoCode&, std::string_view, u16) const;
template bool AchievementManager::IsApprovedCode<ActionReplay::ARCode>(
    const ActionReplay::ARCode&, std::string_view, u16) const;

#endif // USE_RETRO_ACHIEVEMENTS
