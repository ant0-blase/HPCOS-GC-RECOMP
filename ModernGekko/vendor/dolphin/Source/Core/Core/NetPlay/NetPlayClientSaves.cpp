// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/NetPlay/NetPlayClient.h"
#include "Common/CommonPaths.h"
#include "Common/FileUtil.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/NandPaths.h"
#include "Common/SFMLHelper.h"
#include "Common/StringUtil.h"
#include "Core/HW/GCMemcard/GCMemcard.h"
#include "Core/HW/WiiSave.h"
#include "Core/HW/WiiSaveStructs.h"
#include "Core/IOS/FS/FileSystem.h"
#include "Core/IOS/FS/HostBackend/FS.h"
#include "Core/IOS/Uids.h"
#include "Core/NetPlay/NetPlayCommon.h"

namespace NetPlay
{

void NetPlayClient::OnSyncSaveData(sf::Packet& packet)
{
  SyncSaveDataID sub_id;
  packet >> sub_id;

  if (m_local_player->IsHost())
    return;

  INFO_LOG_FMT(NETPLAY, "Processing OnSyncSaveData sub id: {}", static_cast<u8>(sub_id));

  switch (sub_id)
  {
  case SyncSaveDataID::Notify:
    OnSyncSaveDataNotify(packet);
    break;

  case SyncSaveDataID::RawData:
    OnSyncSaveDataRaw(packet);
    break;

  case SyncSaveDataID::GCIData:
    OnSyncSaveDataGCI(packet);
    break;

  case SyncSaveDataID::WiiData:
    OnSyncSaveDataWii(packet);
    break;

  case SyncSaveDataID::GBAData:
    OnSyncSaveDataGBA(packet);
    break;

  default:
    PanicAlertFmtT("Unknown SYNC_SAVE_DATA message received with id: {0}", static_cast<u8>(sub_id));
    break;
  }
}

void NetPlayClient::OnSyncSaveDataNotify(sf::Packet& packet)
{
  packet >> m_sync_save_data_count;
  m_sync_save_data_success_count = 0;

  INFO_LOG_FMT(NETPLAY, "Initializing wait for {} savegame chunks.", m_sync_save_data_count);

  if (m_sync_save_data_count == 0)
    SyncSaveDataResponse(true);
  else
    m_dialog->AppendChat(Common::GetStringT("Synchronizing save data..."));
}

void NetPlayClient::OnSyncSaveDataRaw(sf::Packet& packet)
{
  bool is_slot_a;
  std::string region;
  int size_override;
  packet >> is_slot_a >> region >> size_override;

  INFO_LOG_FMT(NETPLAY, "Received raw memcard data for slot {}: region {}, size override {}.",
               is_slot_a ? 'A' : 'B', region, size_override);

  if (region != JAP_DIR && region != USA_DIR && region != EUR_DIR)
  {
    WARN_LOG_FMT(NETPLAY, "Received invalid raw memory card region.");
    SyncSaveDataResponse(false);
    return;
  }

  std::string size_suffix;
  if (size_override >= 0 && size_override <= 4)
  {
    size_suffix = fmt::format(
        ".{}", Memcard::MbitToFreeBlocks(Memcard::MBIT_SIZE_MEMORY_CARD_59 << size_override));
  }

  const std::string path = File::GetUserPath(D_GCUSER_IDX) + GC_MEMCARD_NETPLAY +
                           (is_slot_a ? "A." : "B.") + region + size_suffix + ".raw";
  if (File::Exists(path) && !File::Delete(path))
  {
    PanicAlertFmtT("Failed to delete NetPlay memory card. Verify your write permissions.");
    SyncSaveDataResponse(false);
    return;
  }

  const bool success = DecompressPacketIntoFile(packet, path);
  SyncSaveDataResponse(success);
}

void NetPlayClient::OnSyncSaveDataGCI(sf::Packet& packet)
{
  bool is_slot_a;
  u8 file_count;
  packet >> is_slot_a >> file_count;

  const std::string path = File::GetUserPath(D_GCUSER_IDX) + GC_MEMCARD_NETPLAY DIR_SEP +
                           fmt::format("Card {}", is_slot_a ? 'A' : 'B');

  INFO_LOG_FMT(NETPLAY, "Received GCI memcard data for slot {}: {}, {} files.",
               is_slot_a ? 'A' : 'B', path, file_count);

  if (File::Exists(path) && !File::DeleteDirRecursively(path))
  {
    PanicAlertFmtT("Failed to reset NetPlay GCI folder. Verify your write permissions.");
    SyncSaveDataResponse(false);
    return;
  }

  File::CreateFullPath(path + DIR_SEP);

  for (u8 i = 0; i < file_count; ++i)
  {
    std::string file_name;
    packet >> file_name;

    if (!DecompressPacketIntoFile(packet, path + DIR_SEP + file_name))
    {
      PanicAlertFmtT("Failed to write GCI save file.");
      SyncSaveDataResponse(false);
      return;
    }
  }

  SyncSaveDataResponse(true);
}

void NetPlayClient::OnSyncSaveDataWii(sf::Packet& packet)
{
  const std::string path = File::GetUserPath(D_USER_IDX) + "Wii" GC_MEMCARD_NETPLAY DIR_SEP;
  std::string redirect_path = File::GetUserPath(D_USER_IDX) + "Redirect" GC_MEMCARD_NETPLAY DIR_SEP;

  if (File::Exists(path) && !File::DeleteDirRecursively(path))
  {
    PanicAlertFmtT("Failed to reset NetPlay NAND folder. Verify your write permissions.");
    SyncSaveDataResponse(false);
    return;
  }
  if (File::Exists(redirect_path) && !File::DeleteDirRecursively(redirect_path))
  {
    PanicAlertFmtT("Failed to reset NetPlay redirect folder. Verify your write permissions.");
    SyncSaveDataResponse(false);
    return;
  }

  auto temp_fs = std::make_unique<IOS::HLE::FS::HostFileSystem>(path);
  std::vector<u64> titles;

  constexpr IOS::HLE::FS::Modes fs_modes{
      IOS::HLE::FS::Mode::ReadWrite,
      IOS::HLE::FS::Mode::ReadWrite,
      IOS::HLE::FS::Mode::ReadWrite,
  };

  bool mii_data;
  packet >> mii_data;
  if (mii_data)
  {
    INFO_LOG_FMT(NETPLAY, "Received Mii data.");

    auto buffer = DecompressPacketIntoBuffer(packet);

    temp_fs->CreateFullPath(IOS::PID_KERNEL, IOS::PID_KERNEL, "/shared2/menu/FaceLib/", 0,
                            fs_modes);
    auto file = temp_fs->CreateAndOpenFile(IOS::PID_KERNEL, IOS::PID_KERNEL,
                                           Common::GetMiiDatabasePath(), fs_modes);

    if (!buffer || !file || !file->Write(buffer->data(), buffer->size()))
    {
      PanicAlertFmtT("Failed to write Mii data.");
      SyncSaveDataResponse(false);
      return;
    }
  }

  u32 save_count;
  packet >> save_count;
  INFO_LOG_FMT(NETPLAY, "Received data for {} Wii saves.", save_count);
  for (u32 n = 0; n < save_count; n++)
  {
    u64 title_id = Common::PacketReadU64(packet);
    titles.push_back(title_id);
    temp_fs->CreateFullPath(IOS::PID_KERNEL, IOS::PID_KERNEL,
                            Common::GetTitleDataPath(title_id) + '/', 0, fs_modes);
    auto save = WiiSave::MakeNandStorage(temp_fs.get(), title_id);

    bool exists;
    packet >> exists;
    if (!exists)
    {
      INFO_LOG_FMT(NETPLAY, "No data for Wii save of title {:016x}.", title_id);
      continue;
    }

    INFO_LOG_FMT(NETPLAY, "Received Wii save of title {:016x}.", title_id);

    WiiSave::Header header;
    packet >> header.tid;
    packet >> header.banner_size;
    packet >> header.permissions;
    packet >> header.unk1;
    for (u8& byte : header.md5)
      packet >> byte;
    packet >> header.unk2;
    for (size_t i = 0; i < std::min<size_t>(header.banner_size, sizeof(header.banner)); i++)
      packet >> header.banner[i];

    WiiSave::BkHeader bk_header;
    packet >> bk_header.size;
    packet >> bk_header.magic;
    packet >> bk_header.ngid;
    packet >> bk_header.number_of_files;
    packet >> bk_header.size_of_files;
    packet >> bk_header.unk1;
    packet >> bk_header.unk2;
    packet >> bk_header.total_size;
    for (u8& byte : bk_header.unk3)
      packet >> byte;
    packet >> bk_header.tid;
    for (u8& byte : bk_header.mac_address)
      packet >> byte;

    std::vector<WiiSave::Storage::SaveFile> files;
    for (u32 i = 0; i < bk_header.number_of_files; i++)
    {
      WiiSave::Storage::SaveFile file;
      packet >> file.mode >> file.attributes;
      packet >> file.type;
      packet >> file.path;

      INFO_LOG_FMT(NETPLAY, "Received Wii save data of type {} at {}", static_cast<u8>(file.type),
                   file.path);

      if (file.type == WiiSave::Storage::SaveFile::Type::File)
      {
        auto buffer = DecompressPacketIntoBuffer(packet);
        if (!buffer)
        {
          SyncSaveDataResponse(false);
          return;
        }

        file.data = std::move(*buffer);
      }

      files.push_back(std::move(file));
    }

    if (!save->WriteHeader(header) || !save->WriteBkHeader(bk_header) || !save->WriteFiles(files))
    {
      PanicAlertFmtT("Failed to write Wii save.");
      SyncSaveDataResponse(false);
      return;
    }
  }

  bool has_redirected_save;
  packet >> has_redirected_save;
  if (has_redirected_save)
  {
    INFO_LOG_FMT(NETPLAY, "Received redirected save.");
    if (!DecompressPacketIntoFolder(packet, redirect_path))
    {
      PanicAlertFmtT("Failed to write redirected save.");
      SyncSaveDataResponse(false);
      return;
    }
  }

  SetWiiSyncData(std::move(temp_fs), std::move(titles), std::move(redirect_path));
  SyncSaveDataResponse(true);
}

void NetPlayClient::OnSyncSaveDataGBA(sf::Packet& packet)
{
  int device_number;
  packet >> device_number;

  const std::string path = File::GetUserPath(D_GBAUSER_IDX) + GC_MEMCARD_NETPLAY +
                           fmt::format("GBA_{}.sav", device_number);
  if (File::Exists(path) && !File::Delete(path))
  {
    PanicAlertFmtT("Failed to delete NetPlay GBA save. Verify your write permissions.");
    SyncSaveDataResponse(false);
    return;
  }

  const bool success = DecompressPacketIntoFile(packet, path);
  SyncSaveDataResponse(success);
}

void NetPlayClient::SyncSaveDataResponse(const bool success)
{
  if (!success)
  {
    m_dialog->AppendChat(Common::GetStringT("Error processing save data."));

    sf::Packet response_packet;
    response_packet << MessageID::SyncSaveData;
    response_packet << SyncSaveDataID::Failure;

    Send(response_packet);
    return;
  }

  if (++m_sync_save_data_success_count >= m_sync_save_data_count)
  {
    m_dialog->AppendChat(Common::GetStringT("Save data received!"));

    sf::Packet response_packet;
    response_packet << MessageID::SyncSaveData;
    response_packet << SyncSaveDataID::Success;

    Send(response_packet);
  }
}

}  // namespace NetPlay
