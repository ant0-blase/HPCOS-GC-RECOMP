// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/GCMemcard/GCMemcard.h"
#include "Common/MsgHandler.h"
#include "Common/StringUtil.h"
#include <algorithm>
#include <cstring>

namespace Memcard
{

std::optional<std::vector<u8>> GCMemcard::GetSaveDataBytes(u8 save_index, size_t offset,
                                                           size_t length) const
{
  if (!m_valid || save_index >= DIRLEN)
    return std::nullopt;

  const DEntry& entry = GetActiveDirectory().m_dir_entries[save_index];
  const BlockAlloc& bat = GetActiveBat();
  const u16 block_count = entry.m_block_count;
  const u16 first_block = entry.m_first_block;
  const size_t block_max = MC_FST_BLOCKS + m_data_blocks.size();
  if (block_count == 0xFFFF || first_block < MC_FST_BLOCKS || first_block >= block_max)
    return std::nullopt;

  const u32 file_size = block_count * BLOCK_SIZE;
  if (offset >= file_size)
    return std::nullopt;

  const size_t bytes_to_copy = std::min(length, file_size - offset);
  std::vector<u8> result;
  result.reserve(bytes_to_copy);

  u16 current_block = first_block;
  size_t offset_in_current_block = offset;
  size_t bytes_remaining = bytes_to_copy;

  // skip unnecessary blocks at start
  while (offset_in_current_block >= BLOCK_SIZE)
  {
    offset_in_current_block -= BLOCK_SIZE;
    current_block = bat.GetNextBlock(current_block);
    if (current_block < MC_FST_BLOCKS || current_block >= block_max)
      return std::nullopt;
  }

  // then copy one block at a time into the result vector
  while (true)
  {
    const GCMBlock& block = m_data_blocks[current_block - MC_FST_BLOCKS];
    const size_t bytes_in_current_block_left = BLOCK_SIZE - offset_in_current_block;
    const size_t bytes_in_current_block_left_to_copy =
        std::min(bytes_remaining, bytes_in_current_block_left);

    const auto data_to_copy_begin = block.m_block.begin() + offset_in_current_block;
    const auto data_to_copy_end = data_to_copy_begin + bytes_in_current_block_left_to_copy;
    result.insert(result.end(), data_to_copy_begin, data_to_copy_end);

    bytes_remaining -= bytes_in_current_block_left_to_copy;
    if (bytes_remaining == 0)
      break;

    offset_in_current_block = 0;
    current_block = bat.GetNextBlock(current_block);
    if (current_block < MC_FST_BLOCKS || current_block >= block_max)
      return std::nullopt;
  }

  return std::make_optional(std::move(result));
}

std::optional<std::pair<std::string, std::string>> GCMemcard::GetSaveComments(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return std::nullopt;

  const u32 address = GetActiveDirectory().m_dir_entries[index].m_comments_address;
  if (address == 0xFFFFFFFF)
    return std::nullopt;

  const auto data = GetSaveDataBytes(index, address, DENTRY_STRLEN * 2);
  if (!data || data->size() != DENTRY_STRLEN * 2)
    return std::nullopt;

  const auto string_decoder = IsShiftJIS() ? SHIFTJISToUTF8 : CP1252ToUTF8;
  const auto strip_null = [](const std::string& s) {
    auto offset = s.find('\0');
    if (offset == std::string::npos)
      offset = s.length();
    return s.substr(0, offset);
  };

  const u8* address_1 = data->data();
  const u8* address_2 = address_1 + DENTRY_STRLEN;
  const std::string encoded_1(reinterpret_cast<const char*>(address_1), DENTRY_STRLEN);
  const std::string encoded_2(reinterpret_cast<const char*>(address_2), DENTRY_STRLEN);
  return std::make_pair(strip_null(string_decoder(encoded_1)),
                        strip_null(string_decoder(encoded_2)));
}

std::optional<DEntry> GCMemcard::GetDEntry(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return std::nullopt;

  return GetActiveDirectory().m_dir_entries[index];
}

GCMemcardGetSaveDataRetVal GCMemcard::GetSaveData(u8 index, std::vector<GCMBlock>& Blocks) const
{
  if (!m_valid)
    return GCMemcardGetSaveDataRetVal::NOMEMCARD;

  const u16 block = DEntry_FirstBlock(index);
  const u16 BlockCount = DEntry_BlockCount(index);

  if ((block == 0xFFFF) || (BlockCount == 0xFFFF))
  {
    return GCMemcardGetSaveDataRetVal::FAIL;
  }

  u16 nextBlock = block;
  for (int i = 0; i < BlockCount; ++i)
  {
    if ((!nextBlock) || (nextBlock == 0xFFFF))
      return GCMemcardGetSaveDataRetVal::FAIL;
    Blocks.push_back(m_data_blocks[nextBlock - MC_FST_BLOCKS]);
    nextBlock = GetActiveBat().GetNextBlock(nextBlock);
  }
  return GCMemcardGetSaveDataRetVal::SUCCESS;
}

GCMemcardImportFileRetVal GCMemcard::ImportFile(const Savefile& savefile)
{
  if (!m_valid)
    return GCMemcardImportFileRetVal::NOMEMCARD;

  const DEntry& direntry = savefile.dir_entry;

  if (GetNumFiles() >= DIRLEN)
  {
    return GCMemcardImportFileRetVal::OUTOFDIRENTRIES;
  }
  if (GetActiveBat().m_free_blocks < direntry.m_block_count)
  {
    return GCMemcardImportFileRetVal::OUTOFBLOCKS;
  }
  if (TitlePresent(direntry))
  {
    return GCMemcardImportFileRetVal::TITLEPRESENT;
  }

  // find first free data block
  u16 firstBlock =
      GetActiveBat().NextFreeBlock(m_size_blocks, GetActiveBat().m_last_allocated_block);
  if (firstBlock == 0xFFFF)
    return GCMemcardImportFileRetVal::OUTOFBLOCKS;
  Directory UpdatedDir = GetActiveDirectory();

  // find first free dir entry
  for (int i = 0; i < DIRLEN; i++)
  {
    if (UpdatedDir.m_dir_entries[i].m_gamecode == DEntry::UNINITIALIZED_GAMECODE)
    {
      UpdatedDir.m_dir_entries[i] = direntry;
      UpdatedDir.m_dir_entries[i].m_first_block = firstBlock;
      UpdatedDir.m_dir_entries[i].m_copy_counter = UpdatedDir.m_dir_entries[i].m_copy_counter + 1;
      break;
    }
  }
  UpdatedDir.m_update_counter = UpdatedDir.m_update_counter + 1;
  UpdateDirectory(UpdatedDir);

  const int fileBlocks = direntry.m_block_count;

  std::vector<GCMBlock> blocks = savefile.blocks;
  FZEROGX_MakeSaveGameValid(m_header_block, direntry, blocks);
  PSO_MakeSaveGameValid(m_header_block, direntry, blocks);

  BlockAlloc UpdatedBat = GetActiveBat();
  u16 nextBlock;
  // keep assuming no freespace fragmentation, and copy over all the data
  for (int i = 0; i < fileBlocks; ++i)
  {
    if (firstBlock == 0xFFFF)
      PanicAlertFmt("Fatal Error");
    m_data_blocks[firstBlock - MC_FST_BLOCKS] = blocks[i];
    if (i == fileBlocks - 1)
      nextBlock = 0xFFFF;
    else
      nextBlock = UpdatedBat.NextFreeBlock(m_size_blocks, firstBlock + 1);
    UpdatedBat.m_map[firstBlock - MC_FST_BLOCKS] = nextBlock;
    UpdatedBat.m_last_allocated_block = firstBlock;
    firstBlock = nextBlock;
  }

  UpdatedBat.m_free_blocks = UpdatedBat.m_free_blocks - fileBlocks;
  UpdatedBat.m_update_counter = UpdatedBat.m_update_counter + 1;
  UpdateBat(UpdatedBat);

  FixChecksums();

  return GCMemcardImportFileRetVal::SUCCESS;
}

std::optional<Savefile> GCMemcard::ExportFile(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return std::nullopt;

  Savefile savefile;
  savefile.dir_entry = GetActiveDirectory().m_dir_entries[index];
  if (savefile.dir_entry.m_gamecode == DEntry::UNINITIALIZED_GAMECODE)
    return std::nullopt;

  if (GetSaveData(index, savefile.blocks) != GCMemcardGetSaveDataRetVal::SUCCESS)
    return std::nullopt;

  return savefile;
}

GCMemcardRemoveFileRetVal GCMemcard::RemoveFile(u8 index)  // index in the directory array
{
  if (!m_valid)
    return GCMemcardRemoveFileRetVal::NOMEMCARD;
  if (index >= DIRLEN)
    return GCMemcardRemoveFileRetVal::DELETE_FAIL;

  const u16 startingblock = GetActiveDirectory().m_dir_entries[index].m_first_block;
  const u16 numberofblocks = GetActiveDirectory().m_dir_entries[index].m_block_count;

  BlockAlloc UpdatedBat = GetActiveBat();
  if (!UpdatedBat.ClearBlocks(startingblock, numberofblocks))
    return GCMemcardRemoveFileRetVal::DELETE_FAIL;
  UpdatedBat.m_update_counter = UpdatedBat.m_update_counter + 1;
  UpdateBat(UpdatedBat);

  Directory UpdatedDir = GetActiveDirectory();

  memset(reinterpret_cast<u8*>(&UpdatedDir.m_dir_entries[index]), 0xFF, DENTRY_SIZE);
  UpdatedDir.m_update_counter = UpdatedDir.m_update_counter + 1;
  UpdateDirectory(UpdatedDir);

  FixChecksums();

  return GCMemcardRemoveFileRetVal::SUCCESS;
}

}  // namespace Memcard
