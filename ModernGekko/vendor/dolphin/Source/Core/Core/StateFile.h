// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <string>
#include <vector>
#include <span>
#include <optional>
#include "Common/CommonTypes.h"
#include "Common/IOFile.h"
#include "Common/Buffer.h"
#include "Common/TransferableSharedMutex.h"
#include "Core/State.h"

namespace State
{
extern Common::TransferableSharedMutex s_state_saves_in_progress;
// Don't forget to increase this after doing changes on the savestate system
constexpr u32 STATE_VERSION = 191;  // Last changed in PR 14668

// Increase this if the StateExtendedHeader definition changes
constexpr u32 EXTENDED_HEADER_VERSION = 1;  // Last changed in PR 12217

// Change this if we ever need to store more data in the extended header
constexpr u32 COMPRESSED_DATA_OFFSET = 0;

constexpr u32 COOKIE_BASE = 0xBAADBABE;

// Arbitrarily chosen value (38 years) that is subtracted in GetSystemTimeAsDouble()
// to increase sub-second precision of the resulting double timestamp
constexpr int DOUBLE_TIME_OFFSET = (38 * 365 * 24 * 60 * 60);

constexpr bool s_use_compression = true;

struct SlotWithTimestamp
{
  // 1-based indexing.
  int slot;
  double timestamp;
};

std::string MakeStateFilename(int number);
std::vector<SlotWithTimestamp> GetUsedSlotsWithTimestamp();
std::optional<int> GetEmptySlot(std::span<const SlotWithTimestamp> used_slots);

bool ReadStateHeaderFromFile(StateHeader& header, File::IOFile& f, bool get_version_header = true);
bool ValidateHeaders(const StateHeader& header);
bool ReadHeader(const std::string& filename, StateHeader& header);
bool DecompressLZ4(Common::UniqueBuffer<u8>& raw_buffer, u64 size, File::IOFile& f);
void LoadFileStateData(const std::string& filename, Common::UniqueBuffer<u8>& ret_data);
void CompressBufferToFile(std::span<const u8> raw_buffer, File::IOFile& f);
void CreateExtendedHeader(StateExtendedHeader& extended_header, size_t uncompressed_size);
void WriteHeadersToFile(size_t uncompressed_size, File::IOFile& f);

double GetSystemTimeAsDouble();
std::string SystemTimeAsDoubleToString(double time);

}  // namespace State
