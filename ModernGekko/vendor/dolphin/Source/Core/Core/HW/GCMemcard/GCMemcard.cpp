// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/GCMemcard/GCMemcard.h"

#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

#include "Common/Assert.h"
#include "Common/BitUtils.h"
#include "Common/ColorUtil.h"
#include "Common/CommonTypes.h"
#include "Common/IOFile.h"
#include "Common/MsgHandler.h"
#include "Common/StringUtil.h"
#include "Common/Swap.h"

#include "Core/HW/GCMemcard/GCMemcardUtils.h"

static constexpr std::optional<u64> BytesToMegabits(u64 bytes)
{
  const u64 factor = ((1024 * 1024) / 8);
  const u64 megabits = bytes / factor;
  const u64 remainder = bytes % factor;
  if (remainder != 0)
    return std::nullopt;
  return megabits;
}

namespace Memcard
{
bool GCMemcardErrorCode::HasCriticalErrors() const
{
  return Test(GCMemcardValidityIssues::FAILED_TO_OPEN) || Test(GCMemcardValidityIssues::IO_ERROR) ||
         Test(GCMemcardValidityIssues::INVALID_CARD_SIZE) ||
         Test(GCMemcardValidityIssues::INVALID_CHECKSUM) ||
         Test(GCMemcardValidityIssues::MISMATCHED_CARD_SIZE) ||
         Test(GCMemcardValidityIssues::FREE_BLOCK_MISMATCH) ||
         Test(GCMemcardValidityIssues::DIR_BAT_INCONSISTENT);
}

bool GCMemcardErrorCode::Test(GCMemcardValidityIssues code) const
{
  return m_errors.test(static_cast<size_t>(code));
}

void GCMemcardErrorCode::Set(GCMemcardValidityIssues code)
{
  m_errors.set(static_cast<size_t>(code));
}

GCMemcardErrorCode& GCMemcardErrorCode::operator|=(const GCMemcardErrorCode& other)
{
  this->m_errors |= other.m_errors;
  return *this;
}

GCMemcard::GCMemcard()
    : m_valid(false), m_size_blocks(0), m_size_mb(0), m_active_directory(0), m_active_bat(0)
{
}

std::optional<GCMemcard> GCMemcard::Create(std::string filename, const CardFlashId& flash_id,
                                           u16 size_mbits, bool shift_jis, u32 rtc_bias,
                                           u32 sram_language, u64 format_time)
{
  GCMemcard card;
  card.m_filename = std::move(filename);

  // TODO: Format() not only formats the card but also writes it to disk at m_filename.
  // Those tasks should probably be separated.
  if (!card.Format(flash_id, size_mbits, shift_jis, rtc_bias, sram_language, format_time))
    return std::nullopt;

  return std::move(card);
}

std::pair<GCMemcardErrorCode, std::optional<GCMemcard>> GCMemcard::Open(std::string filename)
{
  GCMemcardErrorCode error_code;
  File::IOFile file(filename, "rb");
  if (!file.IsOpen())
  {
    error_code.Set(GCMemcardValidityIssues::FAILED_TO_OPEN);
    return std::make_pair(error_code, std::nullopt);
  }

  // check if the filesize is a valid memory card size
  const u64 filesize = file.GetSize();
  const u64 filesize_megabits = BytesToMegabits(filesize).value_or(0);
  const std::array<u16, 6> valid_megabits = {{
      MBIT_SIZE_MEMORY_CARD_59,
      MBIT_SIZE_MEMORY_CARD_123,
      MBIT_SIZE_MEMORY_CARD_251,
      MBIT_SIZE_MEMORY_CARD_507,
      MBIT_SIZE_MEMORY_CARD_1019,
      MBIT_SIZE_MEMORY_CARD_2043,
  }};

  if (!std::ranges::any_of(valid_megabits,
                           [filesize_megabits](u64 mbits) { return mbits == filesize_megabits; }))
  {
    error_code.Set(GCMemcardValidityIssues::INVALID_CARD_SIZE);
    return std::make_pair(error_code, std::nullopt);
  }

  const u16 card_size_mbits = static_cast<u16>(filesize_megabits);

  // read the entire card into memory
  GCMemcard card;
  file.Seek(0, File::SeekOrigin::Begin);
  if (!file.ReadBytes(&card.m_header_block, BLOCK_SIZE) ||
      !file.ReadBytes(&card.m_directory_blocks[0], BLOCK_SIZE) ||
      !file.ReadBytes(&card.m_directory_blocks[1], BLOCK_SIZE) ||
      !file.ReadBytes(&card.m_bat_blocks[0], BLOCK_SIZE) ||
      !file.ReadBytes(&card.m_bat_blocks[1], BLOCK_SIZE))
  {
    error_code.Set(GCMemcardValidityIssues::IO_ERROR);
    return std::make_pair(error_code, std::nullopt);
  }

  const u16 card_size_blocks = card_size_mbits * MBIT_TO_BLOCKS;
  const u16 user_data_blocks = card_size_blocks - MC_FST_BLOCKS;
  card.m_data_blocks.reserve(user_data_blocks);
  for (u16 i = 0; i < user_data_blocks; ++i)
  {
    GCMBlock& block = card.m_data_blocks.emplace_back();
    if (!file.ReadArray(block.m_block.data(), BLOCK_SIZE))
    {
      error_code.Set(GCMemcardValidityIssues::IO_ERROR);
      return std::make_pair(error_code, std::nullopt);
    }
  }

  file.Close();

  card.m_filename = std::move(filename);
  card.m_size_blocks = card_size_blocks;
  card.m_size_mb = card_size_mbits;

  // can return invalid card size, invalid checksum, data in unused area
  // data in unused area is okay, otherwise fail
  const GCMemcardErrorCode header_error_code = card.m_header_block.CheckForErrors(card_size_mbits);
  error_code |= header_error_code;
  if (header_error_code.HasCriticalErrors())
    return std::make_pair(error_code, std::nullopt);

  // The GC BIOS counts any card as corrupted as long as at least any two of [dir0, dir1, bat0,
  // bat1] are corrupted. Yes, even if we have one valid dir and one valid bat, and even if those
  // are both supposedly the newer ones.
  //
  // If both blocks of a single category are non-corrupted the used block depends on the update
  // counter. If both blocks have the same update counter, it prefers block 0. Otherwise it prefers
  // whichever block has the higher value. Essentially, if (0.update_ctr >= 1.update_ctr) { use 0 }
  // else { use 1 }.
  //
  // If a single block of the four is corrupted, the non-corrupted one of the same category is
  // immediately copied over the corrupted block with an incremented update counter. At this point
  // both blocks contain the same data, so it's hard to tell which one is used, but presumably it
  // uses the one with the now-higher update counter, same as it would have otherwise.
  //
  // This rule only applies for errors within a single block! That is, invalid checksums for both
  // types, and free block mismatch for the BATs. Once two valid blocks have been selected but it
  // later turns out they do not match each other (eg. claimed block count of a file in the
  // directory does not match the actual block count arrived at by following BAT), the card will be
  // treated as corrupted, even if perhaps a different combination of the two blocks would result in
  // a valid memory card.

  // can return invalid checksum, data in unused area
  GCMemcardErrorCode dir_block_0_error_code = card.m_directory_blocks[0].CheckForErrors();
  GCMemcardErrorCode dir_block_1_error_code = card.m_directory_blocks[1].CheckForErrors();

  // can return invalid card size, invalid checksum, data in unused area, free block mismatch
  GCMemcardErrorCode bat_block_0_error_code = card.m_bat_blocks[0].CheckForErrors(card_size_mbits);
  GCMemcardErrorCode bat_block_1_error_code = card.m_bat_blocks[1].CheckForErrors(card_size_mbits);

  const bool dir_block_0_valid = !dir_block_0_error_code.HasCriticalErrors();
  const bool dir_block_1_valid = !dir_block_1_error_code.HasCriticalErrors();
  const bool bat_block_0_valid = !bat_block_0_error_code.HasCriticalErrors();
  const bool bat_block_1_valid = !bat_block_1_error_code.HasCriticalErrors();

  // if any two (at least) blocks are corrupted return failure
  // TODO: Consider allowing a recovery option when there's still a valid one of each type.
  int number_of_corrupted_dir_bat_blocks = 0;
  if (!dir_block_0_valid)
    ++number_of_corrupted_dir_bat_blocks;
  if (!dir_block_1_valid)
    ++number_of_corrupted_dir_bat_blocks;
  if (!bat_block_0_valid)
    ++number_of_corrupted_dir_bat_blocks;
  if (!bat_block_1_valid)
    ++number_of_corrupted_dir_bat_blocks;

  if (number_of_corrupted_dir_bat_blocks > 1)
  {
    error_code |= dir_block_0_error_code;
    error_code |= dir_block_1_error_code;
    error_code |= bat_block_0_error_code;
    error_code |= bat_block_1_error_code;
    return std::make_pair(error_code, std::nullopt);
  }

  // if exactly one block is corrupted copy and update it over the non-corrupted block
  if (number_of_corrupted_dir_bat_blocks == 1)
  {
    if (!dir_block_0_valid)
    {
      card.m_directory_blocks[0] = card.m_directory_blocks[1];
      card.m_directory_blocks[0].m_update_counter = card.m_directory_blocks[0].m_update_counter + 1;
      card.m_directory_blocks[0].FixChecksums();
      dir_block_0_error_code = card.m_directory_blocks[0].CheckForErrors();
    }
    else if (!dir_block_1_valid)
    {
      card.m_directory_blocks[1] = card.m_directory_blocks[0];
      card.m_directory_blocks[1].m_update_counter = card.m_directory_blocks[1].m_update_counter + 1;
      card.m_directory_blocks[1].FixChecksums();
      dir_block_1_error_code = card.m_directory_blocks[1].CheckForErrors();
    }
    else if (!bat_block_0_valid)
    {
      card.m_bat_blocks[0] = card.m_bat_blocks[1];
      card.m_bat_blocks[0].m_update_counter = card.m_bat_blocks[0].m_update_counter + 1;
      card.m_bat_blocks[0].FixChecksums();
      bat_block_0_error_code = card.m_bat_blocks[0].CheckForErrors(card_size_mbits);
    }
    else if (!bat_block_1_valid)
    {
      card.m_bat_blocks[1] = card.m_bat_blocks[0];
      card.m_bat_blocks[1].m_update_counter = card.m_bat_blocks[1].m_update_counter + 1;
      card.m_bat_blocks[1].FixChecksums();
      bat_block_1_error_code = card.m_bat_blocks[1].CheckForErrors(card_size_mbits);
    }
    else
    {
      // should never reach here
      ASSERT(false);
    }
  }

  error_code |= dir_block_0_error_code;
  error_code |= dir_block_1_error_code;
  error_code |= bat_block_0_error_code;
  error_code |= bat_block_1_error_code;

  // select the in-use Dir and BAT blocks based on update counter

  // These are compared as signed values by the GC BIOS. There is no protection against overflow, so
  // if one block is MAX_VAL and the other is MIN_VAL it still picks the MAX_VAL one as the active
  // one, even if that results in a corrupted memory card.
  // TODO: We could try to be smarter about this to rescue seemingly-corrupted cards.

  if (card.m_directory_blocks[0].m_update_counter >= card.m_directory_blocks[1].m_update_counter)
    card.m_active_directory = 0;
  else
    card.m_active_directory = 1;

  if (card.m_bat_blocks[0].m_update_counter >= card.m_bat_blocks[1].m_update_counter)
    card.m_active_bat = 0;
  else
    card.m_active_bat = 1;

  // check for consistency between the active Dir and BAT
  const GCMemcardErrorCode dir_bat_consistency_error_code =
      card.GetActiveDirectory().CheckForErrorsWithBat(card.GetActiveBat());
  error_code |= dir_bat_consistency_error_code;
  if (error_code.HasCriticalErrors())
    return std::make_pair(error_code, std::nullopt);

  card.m_valid = true;

  return std::make_pair(error_code, std::move(card));
}

const Directory& GCMemcard::GetActiveDirectory() const
{
  return m_directory_blocks[m_active_directory];
}

const BlockAlloc& GCMemcard::GetActiveBat() const
{
  return m_bat_blocks[m_active_bat];
}

void GCMemcard::UpdateDirectory(const Directory& directory)
{
  // overwrite inactive dir with given data, then set active dir to written block
  const int new_directory_index = m_active_directory == 0 ? 1 : 0;
  m_directory_blocks[new_directory_index] = directory;
  m_active_directory = new_directory_index;
}

void GCMemcard::UpdateBat(const BlockAlloc& bat)
{
  // overwrite inactive BAT with given data, then set active BAT to written block
  const int new_bat_index = m_active_bat == 0 ? 1 : 0;
  m_bat_blocks[new_bat_index] = bat;
  m_active_bat = new_bat_index;
}

bool GCMemcard::IsShiftJIS() const
{
  return m_header_block.IsShiftJIS();
}

bool GCMemcard::Save()
{
  File::IOFile mcdFile(m_filename, "wb");
  mcdFile.Seek(0, File::SeekOrigin::Begin);

  mcdFile.WriteBytes(&m_header_block, BLOCK_SIZE);
  mcdFile.WriteBytes(&m_directory_blocks[0], BLOCK_SIZE);
  mcdFile.WriteBytes(&m_directory_blocks[1], BLOCK_SIZE);
  mcdFile.WriteBytes(&m_bat_blocks[0], BLOCK_SIZE);
  mcdFile.WriteBytes(&m_bat_blocks[1], BLOCK_SIZE);
  for (unsigned int i = 0; i < m_size_blocks - MC_FST_BLOCKS; ++i)
  {
    mcdFile.WriteBytes(m_data_blocks[i].m_block.data(), m_data_blocks[i].m_block.size());
  }

  return mcdFile.Close();
}

static std::pair<u16, u16> CalculateMemcardChecksums(const u8* data, size_t size)
{
  ASSERT(size % 2 == 0);
  u16 csum = 0;
  u16 inv_csum = 0;

  for (size_t i = 0; i < size; i += 2)
  {
    const u16 d = Common::swap16(&data[i]);
    csum += d;
    inv_csum += static_cast<u16>(d ^ 0xffff);
  }

  csum = Common::swap16(csum);
  inv_csum = Common::swap16(inv_csum);

  if (csum == 0xffff)
    csum = 0;
  if (inv_csum == 0xffff)
    inv_csum = 0;

  return std::make_pair(csum, inv_csum);
}

bool GCMemcard::FixChecksums()
{
  if (!m_valid)
    return false;

  m_header_block.FixChecksums();
  m_directory_blocks[0].FixChecksums();
  m_directory_blocks[1].FixChecksums();
  m_bat_blocks[0].FixChecksums();
  m_bat_blocks[1].FixChecksums();

  return true;
}

u8 GCMemcard::GetNumFiles() const
{
  if (!m_valid)
    return 0;

  u8 j = 0;
  for (int i = 0; i < DIRLEN; i++)
  {
    if (GetActiveDirectory().m_dir_entries[i].m_gamecode != DEntry::UNINITIALIZED_GAMECODE)
      j++;
  }
  return j;
}

u8 GCMemcard::GetFileIndex(u8 fileNumber) const
{
  if (m_valid)
  {
    u8 j = 0;
    for (u8 i = 0; i < DIRLEN; i++)
    {
      if (GetActiveDirectory().m_dir_entries[i].m_gamecode != DEntry::UNINITIALIZED_GAMECODE)
      {
        if (j == fileNumber)
        {
          return i;
        }
        j++;
      }
    }
  }
  return 0xFF;
}

u16 GCMemcard::GetFreeBlocks() const
{
  if (!m_valid)
    return 0;

  return GetActiveBat().m_free_blocks;
}

std::optional<u8> GCMemcard::TitlePresent(const DEntry& d) const
{
  if (!m_valid)
    return std::nullopt;

  const Directory& dir = GetActiveDirectory();
  for (u8 i = 0; i < DIRLEN; ++i)
  {
    if (HasSameIdentity(dir.m_dir_entries[i], d))
      return i;
  }

  return std::nullopt;
}

bool GCMemcard::DEntry_IsPingPong(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return false;

  const int flags = GetActiveDirectory().m_dir_entries[index].m_banner_and_icon_flags;
  return (flags & 0b0000'0100) != 0;
}

u16 GCMemcard::DEntry_FirstBlock(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return 0xFFFF;

  const u16 block = GetActiveDirectory().m_dir_entries[index].m_first_block;
  if (block > (u16)m_size_blocks)
    return 0xFFFF;
  return block;
}

u16 GCMemcard::DEntry_BlockCount(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return 0xFFFF;

  const u16 blocks = GetActiveDirectory().m_dir_entries[index].m_block_count;
  if (blocks > (u16)m_size_blocks)
    return 0xFFFF;
  return blocks;
}

BlockAlloc::BlockAlloc(u16 size_mbits)
{
  memset(this, 0, BLOCK_SIZE);
  m_free_blocks = MbitToFreeBlocks(size_mbits);
  m_last_allocated_block = 4;
  FixChecksums();
}

u16 BlockAlloc::GetNextBlock(u16 block) const
{
  // FIXME: This is fishy, shouldn't that be in range [5, 4096[?
  if ((block < MC_FST_BLOCKS) || (block > 4091))
    return 0;

  return m_map[block - MC_FST_BLOCKS];
}

// Parameters and return value are expected as memory card block index,
// not BAT index; that is, block 5 is the first file data block.
u16 BlockAlloc::NextFreeBlock(u16 max_block, u16 starting_block) const
{
  if (m_free_blocks > 0)
  {
    starting_block = std::clamp<u16>(starting_block, MC_FST_BLOCKS, BAT_SIZE + MC_FST_BLOCKS);
    max_block = std::clamp<u16>(max_block, MC_FST_BLOCKS, BAT_SIZE + MC_FST_BLOCKS);
    for (u16 i = starting_block; i < max_block; ++i)
      if (m_map[i - MC_FST_BLOCKS] == 0)
        return i;

    for (u16 i = MC_FST_BLOCKS; i < starting_block; ++i)
      if (m_map[i - MC_FST_BLOCKS] == 0)
        return i;
  }
  return 0xFFFF;
}

bool BlockAlloc::ClearBlocks(u16 starting_block, u16 block_count)
{
  std::vector<u16> blocks;
  while (starting_block != 0xFFFF && starting_block != 0)
  {
    blocks.push_back(starting_block);
    starting_block = GetNextBlock(starting_block);
  }
  if (starting_block > 0)
  {
    const size_t length = blocks.size();
    if (length != block_count)
    {
      return false;
    }
    for (unsigned int i = 0; i < length; ++i)
      m_map[blocks.at(i) - MC_FST_BLOCKS] = 0;
    m_free_blocks = m_free_blocks + block_count;

    return true;
  }
  return false;
}

void BlockAlloc::FixChecksums()
{
  std::tie(m_checksum, m_checksum_inv) = CalculateChecksums();
}

u16 BlockAlloc::AssignBlocksContiguous(u16 length)
{
  const u16 starting = m_last_allocated_block + 1;
  if (length > m_free_blocks)
    return 0xFFFF;
  u16 current = starting;
  while ((current - starting + 1) < length)
  {
    m_map[current - 5] = current + 1;
    current++;
  }
  m_map[current - 5] = 0xFFFF;
  m_last_allocated_block = current;
  m_free_blocks = m_free_blocks - length;
  FixChecksums();
  return starting;
}

std::pair<u16, u16> BlockAlloc::CalculateChecksums() const
{
  static_assert(std::is_trivially_copyable<BlockAlloc>());

  std::array<u8, sizeof(BlockAlloc)> raw;
  memcpy(raw.data(), this, raw.size());

  constexpr size_t checksum_area_start = offsetof(BlockAlloc, m_update_counter);
  constexpr size_t checksum_area_end = sizeof(BlockAlloc);
  constexpr size_t checksum_area_size = checksum_area_end - checksum_area_start;
  return CalculateMemcardChecksums(&raw[checksum_area_start], checksum_area_size);
}

GCMemcardErrorCode BlockAlloc::CheckForErrors(u16 size_mbits) const
{
  GCMemcardErrorCode error_code;

  // verify checksums
  const auto [checksum_sum, checksum_inv] = CalculateChecksums();
  if (checksum_sum != m_checksum || checksum_inv != m_checksum_inv)
    error_code.Set(GCMemcardValidityIssues::INVALID_CHECKSUM);

  if (size_mbits > 0 && size_mbits <= 256)
  {
    // check if free block count matches the actual amount of free blocks in m_map
    const u16 total_available_blocks = (size_mbits * MBIT_TO_BLOCKS) - MC_FST_BLOCKS;
    ASSERT(total_available_blocks <= m_map.size());
    u16 blocks_in_use = 0;
    for (size_t i = 0; i < total_available_blocks; ++i)
    {
      if (m_map[i] != 0)
        ++blocks_in_use;
    }
    const u16 free_blocks = total_available_blocks - blocks_in_use;

    if (free_blocks != m_free_blocks)
      error_code.Set(GCMemcardValidityIssues::FREE_BLOCK_MISMATCH);

    // remaining blocks map to nothing on hardware and must be empty
    for (size_t i = total_available_blocks; i < m_map.size(); ++i)
    {
      if (m_map[i] != 0)
      {
        error_code.Set(GCMemcardValidityIssues::DATA_IN_UNUSED_AREA);
        break;
      }
    }
  }
  else
  {
    // card size is outside the range of blocks that can be addressed
    error_code.Set(GCMemcardValidityIssues::INVALID_CARD_SIZE);
  }

  return error_code;
}

bool GCMemcard::Format(u8* card_data, const CardFlashId& flash_id, u16 size_mbits, bool shift_jis,
                       u32 rtc_bias, u32 sram_language, u64 format_time)
{
  if (!card_data)
    return false;

  const Header header(flash_id, size_mbits, shift_jis, rtc_bias, sram_language, format_time);
  const Directory dir;
  const BlockAlloc bat(size_mbits);

  std::memcpy(&card_data[BLOCK_SIZE * 0], &header, BLOCK_SIZE);
  std::memcpy(&card_data[BLOCK_SIZE * 1], &dir, BLOCK_SIZE);
  std::memcpy(&card_data[BLOCK_SIZE * 2], &dir, BLOCK_SIZE);
  std::memcpy(&card_data[BLOCK_SIZE * 3], &bat, BLOCK_SIZE);
  std::memcpy(&card_data[BLOCK_SIZE * 4], &bat, BLOCK_SIZE);

  return true;
}

bool GCMemcard::Format(const CardFlashId& flash_id, u16 size_mbits, bool shift_jis, u32 rtc_bias,
                       u32 sram_language, u64 format_time)
{
  m_header_block = Header(flash_id, size_mbits, shift_jis, rtc_bias, sram_language, format_time);
  m_directory_blocks[0] = m_directory_blocks[1] = Directory();
  m_bat_blocks[0] = m_bat_blocks[1] = BlockAlloc(size_mbits);

  m_size_mb = size_mbits;
  m_size_blocks = (u32)m_size_mb * MBIT_TO_BLOCKS;
  m_data_blocks.clear();
  m_data_blocks.resize(m_size_blocks - MC_FST_BLOCKS);

  m_active_directory = 0;
  m_active_bat = 0;
  m_valid = true;

  return Save();
}

GCMBlock::GCMBlock()
{
  Erase();
}

void GCMBlock::Erase()
{
  memset(m_block.data(), 0xFF, m_block.size());
}

Header::Header()
{
  static_assert(std::is_trivially_copyable_v<Header>);
  std::memset(this, 0xFF, BLOCK_SIZE);
}

void InitializeHeaderData(HeaderData* data, const CardFlashId& flash_id, u16 size_mbits,
                          bool shift_jis, u32 rtc_bias, u32 sram_language, u64 format_time)
{
  // Nintendo format algorithm.
  // Constants are fixed by the GC SDK
  // Changing the constants will break memory card support
  data->m_size_mb = size_mbits;
  data->m_encoding = shift_jis ? 1 : 0;
  data->m_format_time = format_time;
  u64 rand = format_time;
  for (int i = 0; i < 12; i++)
  {
    rand = (((rand * (u64)0x0000000041c64e6dULL) + (u64)0x0000000000003039ULL) >> 16);
    data->m_serial[i] = (u8)(flash_id[i] + (u32)rand);
    rand = (((rand * (u64)0x0000000041c64e6dULL) + (u64)0x0000000000003039ULL) >> 16);
    rand &= (u64)0x0000000000007fffULL;
  }
  data->m_sram_bias = rtc_bias;
  data->m_sram_language = sram_language;
  // TODO: determine the purpose of m_dtv_status
  // 1 works for slot A, 0 works for both slot A and slot B
  data->m_dtv_status = 0;
  data->m_device_id = 0;
}

bool operator==(const HeaderData& lhs, const HeaderData& rhs)
{
  static_assert(std::is_trivially_copyable_v<HeaderData>);
  return std::memcmp(&lhs, &rhs, sizeof(HeaderData)) == 0;
}

Header::Header(const CardFlashId& flash_id, u16 size_mbits, bool shift_jis, u32 rtc_bias,
               u32 sram_language, u64 format_time)
{
  static_assert(std::is_trivially_copyable_v<Header>);
  std::memset(this, 0xFF, BLOCK_SIZE);
  InitializeHeaderData(&m_data, flash_id, size_mbits, shift_jis, rtc_bias, sram_language,
                       format_time);
  FixChecksums();
}

Header::Header(const HeaderData& data)
{
  static_assert(std::is_trivially_copyable_v<Header>);
  std::memset(this, 0xFF, BLOCK_SIZE);
  m_data = data;
  FixChecksums();
}

std::pair<u32, u32> Header::CalculateSerial() const
{
  static_assert(std::is_trivially_copyable<Header>());

  std::array<u8, 32> raw;
  memcpy(raw.data(), this, raw.size());

  u32 serial1 = 0;
  u32 serial2 = 0;
  for (size_t i = 0; i < raw.size(); i += 8)
  {
    serial1 ^= Common::BitCastPtr<u32>(&raw[i + 0]);
    serial2 ^= Common::BitCastPtr<u32>(&raw[i + 4]);
  }

  return std::make_pair(serial1, serial2);
}

DEntry::DEntry()
{
  memset(reinterpret_cast<u8*>(this), 0xFF, DENTRY_SIZE);
}

void Header::FixChecksums()
{
  std::tie(m_checksum, m_checksum_inv) = CalculateChecksums();
}

std::pair<u16, u16> Header::CalculateChecksums() const
{
  static_assert(std::is_trivially_copyable<Header>());

  std::array<u8, sizeof(Header)> raw;
  memcpy(raw.data(), this, raw.size());

  constexpr size_t checksum_area_start = offsetof(Header, m_data);
  constexpr size_t checksum_area_end = offsetof(Header, m_checksum);
  constexpr size_t checksum_area_size = checksum_area_end - checksum_area_start;
  return CalculateMemcardChecksums(&raw[checksum_area_start], checksum_area_size);
}

GCMemcardErrorCode Header::CheckForErrors(u16 card_size_mbits) const
{
  GCMemcardErrorCode error_code;

  // total card size should match card size in header
  if (m_data.m_size_mb != card_size_mbits)
    error_code.Set(GCMemcardValidityIssues::MISMATCHED_CARD_SIZE);

  // unused areas, should always be filled with 0xFF
  if (std::ranges::any_of(m_unused_1, [](u8 val) { return val != 0xFF; }) ||
      std::ranges::any_of(m_unused_2, [](u8 val) { return val != 0xFF; }))
  {
    error_code.Set(GCMemcardValidityIssues::DATA_IN_UNUSED_AREA);
  }

  // verify checksums
  const auto [checksum_sum, checksum_inv] = CalculateChecksums();
  if (checksum_sum != m_checksum || checksum_inv != m_checksum_inv)
    error_code.Set(GCMemcardValidityIssues::INVALID_CHECKSUM);

  return error_code;
}

bool Header::IsShiftJIS() const
{
  return m_data.m_encoding != 0;
}

Directory::Directory()
{
  memset(reinterpret_cast<u8*>(this), 0xFF, BLOCK_SIZE);
  m_update_counter = 0;
  m_checksum = Common::swap16(0xF003);
  m_checksum_inv = 0;
}

bool Directory::Replace(const DEntry& entry, size_t index)
{
  if (index >= m_dir_entries.size())
    return false;

  m_dir_entries[index] = entry;
  FixChecksums();
  return true;
}

void Directory::FixChecksums()
{
  std::tie(m_checksum, m_checksum_inv) = CalculateChecksums();
}

std::pair<u16, u16> Directory::CalculateChecksums() const
{
  static_assert(std::is_trivially_copyable<Directory>());

  std::array<u8, sizeof(Directory)> raw;
  memcpy(raw.data(), this, raw.size());

  constexpr size_t checksum_area_start = offsetof(Directory, m_dir_entries);
  constexpr size_t checksum_area_end = offsetof(Directory, m_checksum);
  constexpr size_t checksum_area_size = checksum_area_end - checksum_area_start;
  return CalculateMemcardChecksums(&raw[checksum_area_start], checksum_area_size);
}

GCMemcardErrorCode Directory::CheckForErrors() const
{
  GCMemcardErrorCode error_code;

  // verify checksums
  const auto [checksum_sum, checksum_inv] = CalculateChecksums();
  if (checksum_sum != m_checksum || checksum_inv != m_checksum_inv)
    error_code.Set(GCMemcardValidityIssues::INVALID_CHECKSUM);

  // unused area, should always be filled with 0xFF
  if (std::ranges::any_of(m_padding, [](u8 val) { return val != 0xFF; }))
    error_code.Set(GCMemcardValidityIssues::DATA_IN_UNUSED_AREA);

  return error_code;
}

GCMemcardErrorCode Directory::CheckForErrorsWithBat(const BlockAlloc& bat) const
{
  GCMemcardErrorCode error_code;

  for (u8 i = 0; i < DIRLEN; ++i)
  {
    const DEntry& entry = m_dir_entries[i];
    if (entry.m_gamecode == DEntry::UNINITIALIZED_GAMECODE)
      continue;

    // check if we end up with the same number of blocks when traversing through the BAT using the
    // given first block
    const u16 dir_number_of_blocks = entry.m_block_count;
    const u16 dir_first_block = entry.m_first_block;
    bool bat_block_count_matches = false;
    {
      u16 remaining_blocks = dir_number_of_blocks;
      u16 current_block = dir_first_block;
      while (true)
      {
        if (remaining_blocks == 0)
        {
          // we should be at the last block but haven't seen the last-block BAT indicator yet, file
          // is larger according to BAT, so we're inconsistent
          break;
        }
        --remaining_blocks;
        const u16 next_block = bat.GetNextBlock(current_block);
        if (next_block == 0)
        {
          // current block is out-of-range or next block is unallocated, this is definitely wrong
          break;
        }
        if (next_block == 0xFFFF)
        {
          // we're at the final block according to the BAT
          // if there are zero remaining blocks according to the directory we're consistent,
          // otherwise the file is smaller according to the BAT and we're inconsistent
          bat_block_count_matches = remaining_blocks == 0;
          break;
        }
        current_block = next_block;
      }
    }

    if (!bat_block_count_matches)
    {
      error_code.Set(GCMemcardValidityIssues::DIR_BAT_INCONSISTENT);
      break;
    }
  }

  // TODO: We could also check if every allocated BAT block is actually reachable with the files.

  return error_code;
}
}  // namespace Memcard
