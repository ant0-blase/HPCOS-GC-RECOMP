// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// .dolt trace format v1 — raw-hardware-shaped record stream for deterministic
// record/replay of the retail GX path.
//
// Constraint (KNOWLEDGE/aurora-runtime.md "FIFO trace regression path"): records
// carry only FIFO bytes, guest addresses, and raw memory bytes — never sink
// packets or backend-derived metadata. Backend-specific meaning is re-derived at
// replay time by RetailGxFrontend/ConsumingAuroraRenderSink.
//
// File layout (all integers little-endian):
//   header: u32 magic "DOLT" | u32 version | char game_id[8] | u32 mem1_size | u32 flags
//   records: { u8 kind | u32 payload_size | payload bytes } ...
// A file may end mid-record (interrupted recording); TraceReader reports that
// via truncated() and yields every complete record before it.

#include <cstdint>
#include <cstdio>
#include <span>
#include <vector>

namespace gxruntime::aurora_recomp::trace {

constexpr std::uint32_t kMagic = 0x544C4F44u; // "DOLT"
constexpr std::uint32_t kVersion = 1u;
constexpr std::size_t kHeaderSize = 24u;
constexpr std::size_t kRecordHeaderSize = 5u;

enum class RecordKind : std::uint8_t {
  FrameBegin = 1,      // u32 frame_index
  GxWrite = 2,         // u8 size | u64 value — one per WGPIPE write, fragmentation preserved
  CallDisplayList = 3, // u32 guest_addr (0 if unknown) | u32 byte_size | bytes
  SetArray = 4,        // u8 attr | u32 guest_addr | u16 stride — HLE bridge record
  MemUpdate = 5,       // u32 guest_addr | u32 byte_size | bytes (resolved guest memory)
  PresentStats = 6,    // u32 frame_index | 9 x u32 AuroraStats fields
};

struct TraceHeader {
  char game_id[8] = {};
  std::uint32_t mem1_size = 0;
  std::uint32_t flags = 0;
};

// Field order mirrors AuroraStats exactly (aurora/include/aurora/gfx.h:19-29).
struct PresentStats {
  std::uint32_t frame_index = 0;
  std::uint32_t queued_pipelines = 0;
  std::uint32_t created_pipelines = 0;
  std::uint32_t draw_call_count = 0;
  std::uint32_t merged_draw_call_count = 0;
  std::uint32_t last_vert_size = 0;
  std::uint32_t last_uniform_size = 0;
  std::uint32_t last_index_size = 0;
  std::uint32_t last_storage_size = 0;
  std::uint32_t last_texture_upload_size = 0;
};

class TraceWriter {
public:
  TraceWriter() = default;
  ~TraceWriter();
  TraceWriter(const TraceWriter&) = delete;
  TraceWriter& operator=(const TraceWriter&) = delete;

  bool open(const char* path, const TraceHeader& header);
  bool is_open() const { return file_ != nullptr; }

  void frame_begin(std::uint32_t frame_index);
  void gx_write(std::uint8_t size, std::uint64_t value);
  void call_display_list(std::uint32_t guest_addr, const void* bytes,
                         std::uint32_t byte_size);
  void set_array(std::uint8_t attr, std::uint32_t guest_addr,
                 std::uint16_t stride);
  void mem_update(std::uint32_t guest_addr, const void* bytes,
                  std::uint32_t byte_size);
  void present_stats(const PresentStats& stats);

  // Flushes and closes; returns false if any write failed at any point.
  bool close();
  bool ok() const { return ok_; }
  std::uint64_t records_written() const { return records_; }
  std::uint64_t bytes_written() const { return bytes_; }

private:
  void write_record(RecordKind kind, const void* fixed, std::uint32_t fixed_size,
                    const void* tail = nullptr, std::uint32_t tail_size = 0);

  std::FILE* file_ = nullptr;
  bool ok_ = true;
  std::uint64_t records_ = 0;
  std::uint64_t bytes_ = 0;
};

struct RecordView {
  RecordKind kind{};
  std::span<const std::uint8_t> payload;
};

class TraceReader {
public:
  // Loads the whole file (traces are MB-scale). Returns false on missing file,
  // bad magic, or unsupported version.
  bool open(const char* path);
  bool open_bytes(std::vector<std::uint8_t> bytes);

  const TraceHeader& header() const { return header_; }
  std::uint32_t version() const { return version_; }

  // Yields the next complete record. Returns false at clean end AND at a
  // truncated tail; distinguish via truncated().
  bool next(RecordView& out);
  bool truncated() const { return truncated_; }
  std::uint64_t records_read() const { return records_; }
  void rewind();

private:
  bool parse_header();

  std::vector<std::uint8_t> data_;
  std::size_t pos_ = 0;
  TraceHeader header_{};
  std::uint32_t version_ = 0;
  bool truncated_ = false;
  std::uint64_t records_ = 0;
};

// Typed payload decoders; return false on size mismatch.
bool decode_frame_begin(const RecordView& r, std::uint32_t& frame_index);
bool decode_gx_write(const RecordView& r, std::uint8_t& size,
                     std::uint64_t& value);
bool decode_call_display_list(const RecordView& r, std::uint32_t& guest_addr,
                              std::span<const std::uint8_t>& bytes);
bool decode_set_array(const RecordView& r, std::uint8_t& attr,
                      std::uint32_t& guest_addr, std::uint16_t& stride);
bool decode_mem_update(const RecordView& r, std::uint32_t& guest_addr,
                       std::span<const std::uint8_t>& bytes);
bool decode_present_stats(const RecordView& r, PresentStats& out);

} // namespace gxruntime::aurora_recomp::trace
