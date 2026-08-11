// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Achievements/AchievementManager.h"
#include "Common/Logging/Log.h"
#include "Core/Config/MainSettings.h"
#include "DiscIO/Volume.h"

#ifdef USE_RETRO_ACHIEVEMENTS

std::string AchievementManager::CalculateHash(const std::string& file_path)
{
  char hash_result[33] = "0";
  GetInstance().m_loading_volume = DiscIO::CreateVolume(file_path);
  rc_hash_filereader volume_reader{
      .open = &AchievementManager::FilereaderOpen,
      .seek = &AchievementManager::FilereaderSeek,
      .tell = &AchievementManager::FilereaderTell,
      .read = &AchievementManager::FilereaderRead,
      .close = &AchievementManager::FilereaderClose,
  };
  rc_hash_init_custom_filereader(&volume_reader);
  u32 console_id = FindConsoleID(GetInstance().m_loading_volume->GetVolumeType());
  rc_hash_generate_from_file(hash_result, console_id, file_path.c_str());

  return std::string(hash_result);
}

void* AchievementManager::FilereaderOpen(const char* path_utf8)
{
  auto state = std::make_unique<FilereaderState>();
  {
    auto& instance = GetInstance();
    std::lock_guard lg{instance.GetLock()};
    state->volume = std::move(instance.GetLoadingVolume());
  }
  if (!state->volume)
    return nullptr;
  return state.release();
}

void AchievementManager::FilereaderSeek(void* file_handle, int64_t offset, int origin)
{
  switch (origin)
  {
  case SEEK_SET:
    static_cast<FilereaderState*>(file_handle)->position = offset;
    break;
  case SEEK_CUR:
    static_cast<FilereaderState*>(file_handle)->position += offset;
    break;
  case SEEK_END:
    // Unused
    break;
  }
}

int64_t AchievementManager::FilereaderTell(void* file_handle)
{
  return static_cast<FilereaderState*>(file_handle)->position;
}

size_t AchievementManager::FilereaderRead(void* file_handle, void* buffer, size_t requested_bytes)
{
  FilereaderState* filereader_state = static_cast<FilereaderState*>(file_handle);
  bool success = (filereader_state->volume->Read(filereader_state->position, requested_bytes,
                                                 static_cast<u8*>(buffer), DiscIO::PARTITION_NONE));
  if (success)
  {
    filereader_state->position += requested_bytes;
    return requested_bytes;
  }
  else
  {
    return 0;
  }
}

void AchievementManager::FilereaderClose(void* file_handle)
{
  delete static_cast<FilereaderState*>(file_handle);
}

#endif // USE_RETRO_ACHIEVEMENTS
