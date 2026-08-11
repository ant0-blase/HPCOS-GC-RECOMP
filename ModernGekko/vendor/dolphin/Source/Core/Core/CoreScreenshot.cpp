// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Core.h"
#include "Core/Config/ConfigManager.h"
#include "Core/System.h"
#include "Common/CommonPaths.h"
#include "Common/FileUtil.h"
#include "Common/TimeUtil.h"
#include "VideoCommon/FrameDumper.h"

#include <fmt/chrono.h>
#include <fmt/format.h>
#include <ctime>
#include <optional>
#include <string>
#include <string_view>

namespace Core
{
static std::string GenerateScreenshotFolderPath()
{
  const std::string& gameId = SConfig::GetInstance().GetGameID();
  std::string path = File::GetUserPath(D_SCREENSHOTS_IDX) + gameId + DIR_SEP_CHR;

  if (!File::CreateFullPath(path))
  {
    // fallback to old-style screenshots, without folder.
    path = File::GetUserPath(D_SCREENSHOTS_IDX);
  }

  return path;
}

static std::optional<std::string> GenerateScreenshotName()
{
  // append gameId, path only contains the folder here.
  const std::string path_prefix =
      GenerateScreenshotFolderPath() + SConfig::GetInstance().GetGameID();

  const std::time_t cur_time = std::time(nullptr);
  const auto local_time = Common::LocalTime(cur_time);
  if (!local_time)
    return std::nullopt;
  const std::string base_name = fmt::format("{}_{:%Y-%m-%d_%H-%M-%S}", path_prefix, *local_time);

  // First try a filename without any suffixes, if already exists then append increasing numbers
  std::string name = fmt::format("{}.png", base_name);
  if (File::Exists(name))
  {
    for (u32 i = 1; File::Exists(name = fmt::format("{}_{}.png", base_name, i)); ++i)
      ;
  }

  return name;
}

void SaveScreenShot()
{
  const Core::CPUThreadGuard guard(Core::System::GetInstance());
  std::optional<std::string> name = GenerateScreenshotName();
  if (name)
    g_frame_dumper->SaveScreenshot(*name);
}

void SaveScreenShot(std::string_view name)
{
  const Core::CPUThreadGuard guard(Core::System::GetInstance());
  g_frame_dumper->SaveScreenshot(fmt::format("{}{}.png", GenerateScreenshotFolderPath(), name));
}

}  // namespace Core
