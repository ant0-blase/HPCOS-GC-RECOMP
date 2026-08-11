// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Boot/Boot.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <memory>
#include <numeric>
#include <optional>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include <fmt/ranges.h>

#include "Common/CommonPaths.h"
#include "Common/CommonTypes.h"
#include "Common/Config/Config.h"
#include "Common/FileUtil.h"
#include "Common/Hash.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/StringUtil.h"

#include "Core/Boot/DolReader.h"
#include "Core/Boot/ElfReader.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Config/MainSettings.h"
#include "Core/HW/EXI/EXI_DeviceIPL.h"
#include "Core/IOS/FS/FileSystem.h"
#include "Core/NetPlay/NetPlayProto.h"

#include "DiscIO/GameModDescriptor.h"
#include "DiscIO/RiivolutionParser.h"
#include "DiscIO/RiivolutionPatcher.h"
#include "DiscIO/VolumeDisc.h"
#include "DiscIO/VolumeWad.h"
static std::vector<std::string> ReadM3UFile(const std::string& m3u_path,
                                            const std::string& folder_path)
{
  std::vector<std::string> result;
  std::vector<std::string> nonexistent;

  std::ifstream s;
  File::OpenFStream(s, m3u_path, std::ios_base::in);

  std::string line;
  while (std::getline(s, line))
  {
    // This is the UTF-8 representation of U+FEFF.
    constexpr std::string_view utf8_bom = "\xEF\xBB\xBF";

    if (line.starts_with(utf8_bom))
    {
      WARN_LOG_FMT(BOOT, "UTF-8 BOM in file: {}", m3u_path);
      line.erase(0, utf8_bom.length());
    }

    if (!line.empty() && line.front() != '#')  // Comments start with #
    {
      const std::string path_to_add = PathToString(StringToPath(folder_path) / StringToPath(line));
      (File::Exists(path_to_add) ? result : nonexistent).push_back(path_to_add);
    }
  }

  if (!nonexistent.empty())
  {
    PanicAlertFmtT("Files specified in the M3U file \"{0}\" were not found:\n{1}", m3u_path,
                   fmt::join(nonexistent, "\n"));
    return {};
  }

  if (result.empty())
    PanicAlertFmtT("No paths found in the M3U file \"{0}\"", m3u_path);

  return result;
}

BootSessionData::BootSessionData()
{
}

BootSessionData::BootSessionData(std::optional<std::string> savestate_path,
                                 DeleteSavestateAfterBoot delete_savestate)
    : m_savestate_path(std::move(savestate_path)), m_delete_savestate(delete_savestate)
{
}

BootSessionData::BootSessionData(BootSessionData&& other) = default;

BootSessionData& BootSessionData::operator=(BootSessionData&& other) = default;

BootSessionData::~BootSessionData() = default;

const std::optional<std::string>& BootSessionData::GetSavestatePath() const
{
  return m_savestate_path;
}

DeleteSavestateAfterBoot BootSessionData::GetDeleteSavestate() const
{
  return m_delete_savestate;
}

void BootSessionData::SetSavestateData(std::optional<std::string> savestate_path,
                                       DeleteSavestateAfterBoot delete_savestate)
{
  m_savestate_path = std::move(savestate_path);
  m_delete_savestate = delete_savestate;
}

IOS::HLE::FS::FileSystem* BootSessionData::GetWiiSyncFS() const
{
  return m_wii_sync_fs.get();
}

const std::vector<u64>& BootSessionData::GetWiiSyncTitles() const
{
  return m_wii_sync_titles;
}

const std::string& BootSessionData::GetWiiSyncRedirectFolder() const
{
  return m_wii_sync_redirect_folder;
}

void BootSessionData::InvokeWiiSyncCleanup() const
{
  if (m_wii_sync_cleanup)
    m_wii_sync_cleanup();
}

void BootSessionData::SetWiiSyncData(std::unique_ptr<IOS::HLE::FS::FileSystem> fs,
                                     std::vector<u64> titles, std::string redirect_folder,
                                     WiiSyncCleanupFunction cleanup)
{
  m_wii_sync_fs = std::move(fs);
  m_wii_sync_titles = std::move(titles);
  m_wii_sync_redirect_folder = std::move(redirect_folder);
  m_wii_sync_cleanup = std::move(cleanup);
}

const NetPlay::NetSettings* BootSessionData::GetNetplaySettings() const
{
  return m_netplay_settings.get();
}

void BootSessionData::SetNetplaySettings(std::unique_ptr<NetPlay::NetSettings> netplay_settings)
{
  m_netplay_settings = std::move(netplay_settings);
}

BootParameters::BootParameters(Parameters&& parameters_, BootSessionData boot_session_data_)
    : parameters(std::move(parameters_)), boot_session_data(std::move(boot_session_data_))
{
}

std::unique_ptr<BootParameters> BootParameters::GenerateFromFile(std::string boot_path,
                                                                 BootSessionData boot_session_data_)
{
  return GenerateFromFile(std::vector<std::string>{std::move(boot_path)},
                          std::move(boot_session_data_));
}

std::unique_ptr<BootParameters> BootParameters::GenerateFromFile(std::vector<std::string> paths,
                                                                 BootSessionData boot_session_data_)
{
  ASSERT(!paths.empty());

  for (std::string& path : paths)
    UnifyPathSeparators(path);

  // Check if the file exist, we may have gotten it from a --elf command line
  // that gave an incorrect file name
  if (!File::Exists(paths.front()))
  {
    PanicAlertFmtT("The specified file \"{0}\" does not exist", paths.front());
    return {};
  }

  std::string folder_path;
  std::string extension;
  SplitPath(paths.front(), &folder_path, nullptr, &extension);
  Common::ToLower(&extension);

  if (extension == ".m3u" || extension == ".m3u8")
  {
    paths = ReadM3UFile(paths.front(), folder_path);
    if (paths.empty())
      return {};

    for (std::string& path : paths)
      UnifyPathSeparators(path);

    SplitPath(paths.front(), nullptr, nullptr, &extension);
    Common::ToLower(&extension);
  }

  std::string path = paths.front();
  if (paths.size() == 1)
    paths.clear();

#ifdef ANDROID
  if (extension.empty() && IsPathAndroidContent(path))
  {
    const std::string display_name = GetAndroidContentDisplayName(path);
    SplitPath(display_name, nullptr, nullptr, &extension);
    Common::ToLower(&extension);
  }
#endif

  static const std::unordered_set<std::string> disc_image_extensions = {
      {".gcm", ".bin", ".iso", ".tgc", ".wbfs", ".ciso", ".gcz", ".wia", ".rvz", ".nfs", ".dol",
       ".elf"}};
  if (disc_image_extensions.contains(extension))
  {
    std::unique_ptr<DiscIO::VolumeDisc> disc = DiscIO::CreateDiscForCore(path);
    if (disc)
    {
      return std::make_unique<BootParameters>(Disc{std::move(path), std::move(disc), paths},
                                              std::move(boot_session_data_));
    }

    if (extension == ".elf")
    {
      auto elf_reader = std::make_unique<ElfReader>(path);
      return std::make_unique<BootParameters>(Executable{std::move(path), std::move(elf_reader)},
                                              std::move(boot_session_data_));
    }

    if (extension == ".dol")
    {
      auto dol_reader = std::make_unique<DolReader>(path);
      return std::make_unique<BootParameters>(Executable{std::move(path), std::move(dol_reader)},
                                              std::move(boot_session_data_));
    }

    PanicAlertFmtT("\"{0}\" is an invalid GCM/ISO file, or is not a GC/Wii ISO.", path);
    return {};
  }

  if (extension == ".dff")
    return std::make_unique<BootParameters>(DFF{std::move(path)}, std::move(boot_session_data_));

  if (extension == ".wad")
  {
    std::unique_ptr<DiscIO::VolumeWAD> wad = DiscIO::CreateWAD(path);
    if (wad)
      return std::make_unique<BootParameters>(std::move(*wad), std::move(boot_session_data_));
  }

  if (extension == ".json")
  {
    auto descriptor = DiscIO::ParseGameModDescriptorFile(path);
    if (descriptor)
    {
      auto boot_params = GenerateFromFile(descriptor->base_file, std::move(boot_session_data_));
      if (!boot_params)
      {
        PanicAlertFmtT("Could not recognize file {0}", descriptor->base_file);
        return nullptr;
      }

      if (descriptor->riivolution && std::holds_alternative<Disc>(boot_params->parameters))
      {
        const auto& volume = *std::get<Disc>(boot_params->parameters).volume;
        AddRiivolutionPatches(boot_params.get(),
                              DiscIO::Riivolution::GenerateRiivolutionPatchesFromGameModDescriptor(
                                  *descriptor->riivolution, volume.GetGameID(),
                                  volume.GetRevision(), volume.GetDiscNumber()));
      }

      return boot_params;
    }
  }

  PanicAlertFmtT("Could not recognize file {0}", path);
  return {};
}

BootParameters::IPL::IPL(DiscIO::Region region_) : region(region_)
{
  const std::string directory = Config::GetDirectoryForRegion(region);
  path = Config::GetBootROMPath(directory);
}

BootParameters::IPL::IPL(DiscIO::Region region_, Disc&& disc_) : IPL(region_)
{
  disc = std::move(disc_);
}

