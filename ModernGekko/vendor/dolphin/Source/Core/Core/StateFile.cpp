// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/StateFile.h"

#include <algorithm>
#include <filesystem>
#include <locale>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <utility>
#include <vector>

#include <fmt/chrono.h>
#include <fmt/format.h>
#include <fmt/std.h>

#include <lz4.h>
#include <lzo/lzo1x.h>

#include "Common/Buffer.h"
#include "Common/CommonTypes.h"
#include "Common/Contains.h"
#include "Common/FileUtil.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/Thread.h"
#include "Common/TimeUtil.h"
#include "Common/TransferableSharedMutex.h"
#include "Common/Version.h"

#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "VideoCommon/OnScreenDisplay.h"

namespace State
{

#if defined(__LZO_STRICT_16BIT)
static const u32 IN_LEN = 8 * 1024u;
#elif defined(LZO_ARCH_I086) && !defined(LZO_HAVE_MM_HUGE_ARRAY)
static const u32 IN_LEN = 60 * 1024u;
#else
static const u32 IN_LEN = 128 * 1024u;
#endif

static const u32 OUT_LEN = IN_LEN + (IN_LEN / 16) + 64 + 3;

static unsigned char __LZO_MMODEL out[OUT_LEN];

extern Common::TransferableSharedMutex s_state_saves_in_progress;

// Maps savestate versions to Dolphin versions.
static const std::map<u32, std::pair<std::string, std::string>> s_old_versions = {
    {17, {"3.5-1311", "3.5-1364"}}, {18, {"3.5-1366", "3.5-1371"}}, {19, {"3.5-1372", "3.5-1408"}},
    {20, {"3.5-1409", "4.0-704"}},  {21, {"4.0-705", "4.0-889"}},   {22, {"4.0-905", "4.0-1871"}},
    {23, {"4.0-1873", "4.0-1900"}}, {24, {"4.0-1902", "4.0-1919"}}, {25, {"4.0-1921", "4.0-1936"}},
    {26, {"4.0-1939", "4.0-1959"}}, {27, {"4.0-1961", "4.0-2018"}}, {28, {"4.0-2020", "4.0-2291"}},
    {29, {"4.0-2293", "4.0-2360"}}, {30, {"4.0-2362", "4.0-2628"}}, {31, {"4.0-2632", "4.0-3331"}},
    {32, {"4.0-3334", "4.0-3340"}}, {33, {"4.0-3342", "4.0-3373"}}, {34, {"4.0-3376", "4.0-3402"}},
    {35, {"4.0-3409", "4.0-3603"}}, {36, {"4.0-3610", "4.0-4480"}}, {37, {"4.0-4484", "4.0-4943"}},
    {38, {"4.0-4963", "4.0-5267"}}, {39, {"4.0-5279", "4.0-5525"}}, {40, {"4.0-5531", "4.0-5809"}},
    {41, {"4.0-5811", "4.0-5923"}}, {42, {"4.0-5925", "4.0-5946"}}};

double GetSystemTimeAsDouble()
{
  const auto since_epoch = std::chrono::system_clock::now().time_since_epoch();
  const auto since_double_time_epoch = since_epoch - std::chrono::seconds(DOUBLE_TIME_OFFSET);
  return std::chrono::duration_cast<std::chrono::duration<double>>(since_double_time_epoch).count();
}

std::string SystemTimeAsDoubleToString(double time)
{
  const time_t seconds = static_cast<time_t>(time) + DOUBLE_TIME_OFFSET;
  const auto local_time = Common::LocalTime(seconds);
  if (!local_time)
    return "";

  return fmt::format(std::locale{""}, "{:%x %X}", *local_time);
}

std::string MakeStateFilename(int number)
{
  return fmt::format("{}{}.s{:02d}", File::GetUserPath(D_STATESAVES_IDX),
                     SConfig::GetInstance().GetGameID(), number);
}

std::vector<SlotWithTimestamp> GetUsedSlotsWithTimestamp()
{
  std::vector<SlotWithTimestamp> result;
  StateHeader header;
  for (int i = 1; i <= int(NUM_STATES); ++i)
  {
    std::string filename = MakeStateFilename(i);
    if (!File::Exists(filename) || !ReadHeader(filename, header))
      continue;

    result.emplace_back(SlotWithTimestamp{.slot = i, .timestamp = header.legacy_header.time});
  }
  return result;
}

std::optional<int> GetEmptySlot(std::span<const SlotWithTimestamp> used_slots)
{
  for (int i = 1; i <= int(NUM_STATES); ++i)
  {
    if (!Common::Contains(used_slots, i, &SlotWithTimestamp::slot))
      return i;
  }
  return std::nullopt;
}

std::string GetInfoStringOfSlot(int slot, bool translate)
{
  std::lock_guard lk{s_state_saves_in_progress};

  std::string filename = MakeStateFilename(slot);
  if (!File::Exists(filename))
    return translate ? Common::GetStringT("Empty") : "Empty";

  State::StateHeader header;
  if (!ReadHeader(filename, header))
    return translate ? Common::GetStringT("Unknown") : "Unknown";

  return SystemTimeAsDoubleToString(header.legacy_header.time);
}

u64 GetUnixTimeOfSlot(int slot)
{
  std::lock_guard lk{s_state_saves_in_progress};

  State::StateHeader header;
  if (!ReadHeader(MakeStateFilename(slot), header))
    return 0;

  constexpr u64 MS_PER_SEC = 1000;
  return static_cast<u64>(header.legacy_header.time * MS_PER_SEC) +
         (DOUBLE_TIME_OFFSET * MS_PER_SEC);
}

static bool GetVersionFromLZO(StateHeader& header, File::IOFile& f)
{
  lzo_uint32 cur_len = 0;
  lzo_uint new_len = 0;
  Common::UniqueBuffer<u8> buffer(header.legacy_header.lzo_size);

  if (!f.ReadArray(&cur_len, 1) || !f.ReadBytes(out, cur_len))
    return false;

  const int res = lzo1x_decompress(out, cur_len, buffer.data(), &new_len, nullptr);
  if (res != LZO_E_OK)
  {
    PanicAlertFmtT("Internal LZO Error - decompression failed ({0}) ({1}) \n"
                   "Unable to retrieve outdated savestate version info.",
                   res, new_len);
    return false;
  }

  if (buffer.size() >= sizeof(StateHeaderVersion))
  {
    memcpy(&header.version_header, buffer.data(), sizeof(StateHeaderVersion));
  }
  else
  {
    PanicAlertFmtT("Internal LZO Error - failed to parse decompressed version cookie and version "
                   "string length ({0})",
                   buffer.size());
    return false;
  }

  if (buffer.size() >= sizeof(StateHeaderVersion) + header.version_header.version_string_length)
  {
    header.version_string.assign(
        reinterpret_cast<char*>(buffer.data() + sizeof(StateHeaderVersion)),
        header.version_header.version_string_length);
  }
  else
  {
    PanicAlertFmtT("Internal LZO Error - failed to parse decompressed version string ({0} / {1})",
                   header.version_header.version_string_length, buffer.size());
    return false;
  }

  return true;
}

bool ReadStateHeaderFromFile(StateHeader& header, File::IOFile& f, bool get_version_header)
{
  if (!f.ReadArray(&header.legacy_header, 1))
    return false;

  if (header.legacy_header.lzo_size > 0)
  {
    return GetVersionFromLZO(header, f);
  }

  if (get_version_header)
  {
    if (!f.ReadArray(&header.version_header, 1))
      return false;

    std::string version_buffer(header.version_header.version_string_length, '\0');
    if (!f.ReadBytes(version_buffer.data(), version_buffer.size()))
      return false;

    header.version_string = std::move(version_buffer);
  }

  return true;
}

bool ValidateHeaders(const StateHeader& header)
{
  bool success = false;
  u32 loaded_version = header.version_header.version_cookie - COOKIE_BASE;
  std::string loaded_str = header.version_string;

  if (loaded_version == STATE_VERSION)
  {
    success = true;
  }
  else if (loaded_version < STATE_VERSION)
  {
    std::string version_name;
    auto iter = s_old_versions.find(loaded_version);
    if (iter != s_old_versions.end())
    {
      const auto& p = iter->second;
      version_name =
          p.first == p.second ? "Dolphin " + p.first : "Dolphin " + p.first + " to " + p.second;
    }
    else if (loaded_version >= 43)
    {
      version_name = loaded_str;
    }

    if (version_name.empty())
    {
      Core::DisplayMessage("This savestate is too old and cannot be loaded", OSD::Duration::NORMAL);
    }
    else
    {
      Core::DisplayMessage("This savestate was created using the outdated version " + version_name,
                           OSD::Duration::NORMAL);
    }
  }
  else
  {
    const std::string message =
        loaded_str.empty() ?
            "This savestate was created using an incompatible version of Dolphin" :
            "This savestate was created using the incompatible version " + loaded_str;
    Core::DisplayMessage(message, OSD::Duration::NORMAL);
  }

  return success;
}

bool ReadHeader(const std::string& filename, StateHeader& header)
{
  File::IOFile f(filename, "rb");
  constexpr bool get_version_header = false;
  return ReadStateHeaderFromFile(header, f, get_version_header);
}

bool DecompressLZ4(Common::UniqueBuffer<u8>& raw_buffer, u64 size, File::IOFile& f)
{
  raw_buffer.reset(size);

  u64 total_bytes_read = 0;
  while (true)
  {
    s32 compressed_data_len = 0;
    if (!f.ReadArray(&compressed_data_len, 1))
    {
      PanicAlertFmt("Could not read state data length");
      return false;
    }

    Common::UniqueBuffer<char> compressed_buffer(compressed_data_len);
    if (!f.ReadBytes(compressed_buffer.get(), compressed_data_len))
    {
      PanicAlertFmt("Could not read state data");
      return false;
    }

    const u64 bytes_left = size - total_bytes_read;
    const int max_decompress =
        static_cast<int>(std::min(static_cast<u64>(LZ4_MAX_INPUT_SIZE), bytes_left));

    const int uncompressed_len = LZ4_decompress_safe(
        compressed_buffer.get(), reinterpret_cast<char*>(raw_buffer.data()) + total_bytes_read,
        compressed_data_len, max_decompress);

    if (uncompressed_len < 0)
    {
      PanicAlertFmt("LZ4 Decompression Failed");
      return false;
    }

    total_bytes_read += uncompressed_len;
    if (total_bytes_read == size)
      break;
  }
  return true;
}

void LoadFileStateData(const std::string& filename, Common::UniqueBuffer<u8>& ret_data)
{
  File::IOFile f;
  f.Open(filename, "rb");

  StateHeader header;
  if (!ReadStateHeaderFromFile(header, f) || !ValidateHeaders(header))
    return;

  StateExtendedHeader extended_header;
  if (!f.ReadArray(&extended_header.base_header, 1))
  {
    PanicAlertFmt("Unable to read state header");
    return;
  }

  if (extended_header.base_header.header_version != EXTENDED_HEADER_VERSION)
  {
    PanicAlertFmt("State header corrupted");
    return;
  }

  Common::UniqueBuffer<u8> buffer;

  switch (extended_header.base_header.compression_type)
  {
  case CompressionType::LZ4:
  {
    Core::DisplayMessage("Decompressing State...", OSD::Duration::SHORT);
    if (!DecompressLZ4(buffer, extended_header.base_header.uncompressed_size, f))
      return;

    break;
  }
  case CompressionType::Uncompressed:
  {
    u64 header_len = sizeof(StateHeaderLegacy) + sizeof(StateHeaderVersion) +
                     header.version_header.version_string_length + sizeof(StateExtendedBaseHeader) +
                     extended_header.base_header.payload_offset;

    u64 file_size = f.GetSize();
    if (file_size < header_len)
    {
      PanicAlertFmt("State header length corrupted");
      return;
    }

    const auto size = static_cast<size_t>(file_size - header_len);
    buffer.reset(size);

    if (!f.ReadBytes(buffer.data(), size))
    {
      PanicAlertFmt("Error reading bytes: {0}", size);
      return;
    }
    break;
  }
  default:
    PanicAlertFmt("Unknown compression type {0}", extended_header.base_header.compression_type);
    return;
  }

  ret_data.swap(buffer);
}

void CompressBufferToFile(std::span<const u8> raw_buffer, File::IOFile& f)
{
  u64 total_bytes_compressed = 0;

  while (true)
  {
    const u64 bytes_left_to_compress = raw_buffer.size() - total_bytes_compressed;

    const int bytes_to_compress =
        static_cast<int>(std::min(static_cast<u64>(LZ4_MAX_INPUT_SIZE), bytes_left_to_compress));
    Common::UniqueBuffer<char> compressed_buffer(LZ4_compressBound(bytes_to_compress));
    const int compressed_len = LZ4_compress_default(
        reinterpret_cast<const char*>(raw_buffer.data()) + total_bytes_compressed,
        compressed_buffer.get(), bytes_to_compress, int(compressed_buffer.size()));

    if (compressed_len == 0)
    {
      PanicAlertFmtT("Internal LZ4 Error - compression failed");
      break;
    }

    f.WriteArray(&compressed_len, 1);
    f.WriteBytes(compressed_buffer.get(), compressed_len);

    total_bytes_compressed += bytes_to_compress;
    if (total_bytes_compressed == raw_buffer.size())
      break;
  }
}

void CreateExtendedHeader(StateExtendedHeader& extended_header, size_t uncompressed_size)
{
  StateExtendedBaseHeader& base_header = extended_header.base_header;
  base_header.header_version = EXTENDED_HEADER_VERSION;
  base_header.compression_type =
      s_use_compression ? CompressionType::LZ4 : CompressionType::Uncompressed;
  base_header.payload_offset = COMPRESSED_DATA_OFFSET;
  base_header.uncompressed_size = uncompressed_size;
}

void WriteHeadersToFile(size_t uncompressed_size, File::IOFile& f)
{
  StateHeader header{};
  SConfig::GetInstance().GetGameID().copy(header.legacy_header.game_id,
                                          std::size(header.legacy_header.game_id));
  header.legacy_header.time = GetSystemTimeAsDouble();

  header.version_header.version_cookie = COOKIE_BASE + STATE_VERSION;
  header.version_string = Common::GetScmRevStr();
  header.version_header.version_string_length = static_cast<u32>(header.version_string.length());

  StateExtendedHeader extended_header{};
  CreateExtendedHeader(extended_header, uncompressed_size);

  f.WriteArray(&header.legacy_header, 1);
  f.WriteArray(&header.version_header, 1);
  f.WriteString(header.version_string);

  f.WriteArray(&extended_header.base_header, 1);
}

}  // namespace State
