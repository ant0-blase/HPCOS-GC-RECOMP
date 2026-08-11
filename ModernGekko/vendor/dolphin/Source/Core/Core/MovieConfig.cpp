// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Movie.h"

#include <algorithm>
#include <array>
#include <string>
#include <vector>

#include "Common/CommonPaths.h"
#include "Common/Config/Config.h"
#include "Common/FileUtil.h"
#include "Common/Hash.h"
#include "Common/IOFile.h"
#include "Common/StringUtil.h"
#include "Common/Version.h"
#include "Core/Config/MainSettings.h"
#include "Core/Config/ConfigManager.h"
#include "Core/DSP/DSPCore.h"
#include "Core/HW/EXI/EXI.h"
#include "Core/HW/EXI/EXI_DeviceMemoryCard.h"
#include "Core/NetPlay/NetPlayProto.h"
#include "Core/System.h"

namespace Movie
{

static std::array<u8, 20> ConvertGitRevisionToBytes(const std::string& revision)
{
  std::array<u8, 20> revision_bytes{};

  if (revision.size() % 2 == 0 && std::ranges::all_of(revision, Common::IsXDigit))
  {
    size_t bytes_to_write = std::min(revision.size() / 2, revision_bytes.size());
    unsigned int temp;
    for (size_t i = 0; i < bytes_to_write; ++i)
    {
      sscanf(&revision[2 * i], "%02x", &temp);
      revision_bytes[i] = temp;
    }
  }
  else
  {
    size_t bytes_to_write = std::min(revision.size(), revision_bytes.size());
    std::copy_n(std::begin(revision), bytes_to_write, std::begin(revision_bytes));
  }

  return revision_bytes;
}

void MovieManager::GetSettings()
{
  using ExpansionInterface::EXIDeviceType;
  const EXIDeviceType slot_a_type = Config::Get(Config::MAIN_SLOT_A);
  const EXIDeviceType slot_b_type = Config::Get(Config::MAIN_SLOT_B);
  const bool slot_a_has_raw_memcard = slot_a_type == EXIDeviceType::MemoryCard;
  const bool slot_a_has_gci_folder = slot_a_type == EXIDeviceType::MemoryCardFolder;
  const bool slot_b_has_raw_memcard = slot_b_type == EXIDeviceType::MemoryCard;
  const bool slot_b_has_gci_folder = slot_b_type == EXIDeviceType::MemoryCardFolder;

  m_save_config = true;
  m_net_play = NetPlay::IsNetPlayRunning();
  if (m_system.IsWii())
  {
    u64 title_id = SConfig::GetInstance().GetTitleID();
    m_clear_save = !File::Exists(
        Common::GetTitleDataPath(title_id, Common::FromWhichRoot::Session) + "/banner.bin");
  }
  else
  {
    const auto raw_memcard_exists = [](ExpansionInterface::Slot card_slot) {
      return File::Exists(Config::GetMemcardPath(card_slot, SConfig::GetInstance().m_region));
    };
    const auto gci_folder_has_saves = [this](ExpansionInterface::Slot card_slot) {
      const auto [path, migrate] = ExpansionInterface::CEXIMemoryCard::GetGCIFolderPath(
          card_slot, ExpansionInterface::AllowMovieFolder::No, *this);
      const u64 number_of_saves = File::ScanDirectoryTree(path, false).size;
      return number_of_saves > 0;
    };

    m_clear_save = !(slot_a_has_raw_memcard && raw_memcard_exists(ExpansionInterface::Slot::A)) &&
                   !(slot_b_has_raw_memcard && raw_memcard_exists(ExpansionInterface::Slot::B)) &&
                   !(slot_a_has_gci_folder && gci_folder_has_saves(ExpansionInterface::Slot::A)) &&
                   !(slot_b_has_gci_folder && gci_folder_has_saves(ExpansionInterface::Slot::B));
  }
  m_memcards |= (slot_a_has_raw_memcard || slot_a_has_gci_folder) << 0;
  m_memcards |= (slot_b_has_raw_memcard || slot_b_has_gci_folder) << 1;

  m_revision = ConvertGitRevisionToBytes(Common::GetScmRevGitStr());

  if (!Config::Get(Config::MAIN_DSP_HLE))
  {
    std::string irom_file = File::GetUserPath(D_GCUSER_IDX) + DSP_IROM;
    std::string coef_file = File::GetUserPath(D_GCUSER_IDX) + DSP_COEF;

    if (!File::Exists(irom_file))
      irom_file = File::GetSysDirectory() + GC_SYS_DIR DIR_SEP DSP_IROM;
    if (!File::Exists(coef_file))
      coef_file = File::GetSysDirectory() + GC_SYS_DIR DIR_SEP DSP_COEF;
    std::vector<u16> irom(DSP::DSP_IROM_SIZE);
    File::IOFile file_irom(irom_file, "rb");

    file_irom.ReadArray(irom.data(), irom.size());
    file_irom.Close();
    for (u16& entry : irom)
      entry = Common::swap16(entry);

    std::vector<u16> coef(DSP::DSP_COEF_SIZE);
    File::IOFile file_coef(coef_file, "rb");

    file_coef.ReadArray(coef.data(), coef.size());
    file_coef.Close();
    for (u16& entry : coef)
      entry = Common::swap16(entry);
    m_dsp_irom_hash =
        Common::HashAdler32(reinterpret_cast<u8*>(irom.data()), DSP::DSP_IROM_BYTE_SIZE);
    m_dsp_coef_hash =
        Common::HashAdler32(reinterpret_cast<u8*>(coef.data()), DSP::DSP_COEF_BYTE_SIZE);
  }
  else
  {
    m_dsp_irom_hash = 0;
    m_dsp_coef_hash = 0;
  }
}

}  // namespace Movie
