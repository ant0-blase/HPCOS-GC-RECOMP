// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/aurora_recomp/dff2dolt.hpp"

#include "gxruntime/aurora_recomp/trace.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

namespace gxruntime::aurora_recomp::dff {
namespace {

// FifoDataFile on-disk layout (packed little-endian; sizes asserted upstream
// in dolphin FifoDataFile.cpp: header 128, frame info 64, memory update 24).
constexpr std::uint32_t kDffMagic = 0x0D01F1F0u;
constexpr std::uint32_t kMaxKnownVersion = 6u;
constexpr std::size_t kDffHeaderSize = 128u;
constexpr std::size_t kDffFrameInfoSize = 64u;
constexpr std::size_t kDffMemoryUpdateSize = 24u;
constexpr std::uint32_t kBpMemSize = 256u;
constexpr std::uint32_t kCpMemSize = 256u;
constexpr std::uint32_t kXfMemSize = 4096u;
constexpr std::uint32_t kXfRegsSize = 88u;
constexpr std::uint32_t kMem1SizeRetail = 0x01800000u;

std::uint16_t read_le16(const std::uint8_t* p) {
  return static_cast<std::uint16_t>(p[0] | (p[1] << 8u));
}

std::uint32_t read_le32(const std::uint8_t* p) {
  return static_cast<std::uint32_t>(p[0]) |
         (static_cast<std::uint32_t>(p[1]) << 8u) |
         (static_cast<std::uint32_t>(p[2]) << 16u) |
         (static_cast<std::uint32_t>(p[3]) << 24u);
}

std::uint64_t read_le64(const std::uint8_t* p) {
  return static_cast<std::uint64_t>(read_le32(p)) |
         (static_cast<std::uint64_t>(read_le32(p + 4u)) << 32u);
}

struct DffHeader {
  std::uint32_t version = 0;
  std::uint32_t min_loader_version = 0;
  std::uint64_t bp_mem_offset = 0;
  std::uint32_t bp_mem_size = 0;
  std::uint64_t cp_mem_offset = 0;
  std::uint32_t cp_mem_size = 0;
  std::uint64_t xf_mem_offset = 0;
  std::uint32_t xf_mem_size = 0;
  std::uint64_t xf_regs_offset = 0;
  std::uint32_t xf_regs_size = 0;
  std::uint64_t frame_list_offset = 0;
  std::uint32_t frame_count = 0;
  std::uint32_t flags = 0;
  std::uint64_t tex_mem_offset = 0;
  std::uint32_t tex_mem_size = 0;
  std::uint32_t mem1_size = 0;
  std::uint32_t mem2_size = 0;
  char game_id[8] = {};
};

struct DffMemoryUpdate {
  std::uint32_t fifo_position = 0;
  std::uint32_t address = 0;
  std::uint64_t data_offset = 0;
  std::uint32_t data_size = 0;
  std::uint8_t type = 0;
};

struct DffFrame {
  std::uint64_t fifo_data_offset = 0;
  std::uint32_t fifo_data_size = 0;
  std::vector<DffMemoryUpdate> memory_updates;
};

class DffFile {
public:
  bool parse(const std::uint8_t* bytes, std::size_t size, std::string* error) {
    bytes_ = bytes;
    size_ = size;
    if (size < kDffHeaderSize)
      return fail(error, "file smaller than the 128-byte DFF header");
    if (read_le32(bytes) != kDffMagic)
      return fail(error, "bad DFF magic (not a Dolphin FIFO log)");
    header_.version = read_le32(bytes + 4u);
    header_.min_loader_version = read_le32(bytes + 8u);
    if (header_.min_loader_version > kMaxKnownVersion)
      return fail(error, "DFF min_loader_version exceeds supported version 6");
    header_.bp_mem_offset = read_le64(bytes + 12u);
    header_.bp_mem_size = read_le32(bytes + 20u);
    header_.cp_mem_offset = read_le64(bytes + 24u);
    header_.cp_mem_size = read_le32(bytes + 32u);
    header_.xf_mem_offset = read_le64(bytes + 36u);
    header_.xf_mem_size = read_le32(bytes + 44u);
    header_.xf_regs_offset = read_le64(bytes + 48u);
    header_.xf_regs_size = read_le32(bytes + 56u);
    header_.frame_list_offset = read_le64(bytes + 60u);
    header_.frame_count = read_le32(bytes + 68u);
    header_.flags = read_le32(bytes + 72u);
    header_.tex_mem_offset = read_le64(bytes + 76u);
    header_.tex_mem_size = read_le32(bytes + 84u);
    header_.mem1_size = read_le32(bytes + 88u);
    header_.mem2_size = read_le32(bytes + 92u);
    std::memcpy(header_.game_id, bytes + 96u, sizeof header_.game_id);
    // RAM size fields were added in v5; game id in v6 (FifoDataFile::Load).
    if (header_.version < 5u) {
      header_.mem1_size = kMem1SizeRetail;
      header_.mem2_size = 0u;
    }
    if (header_.version < 6u)
      std::memset(header_.game_id, 0, sizeof header_.game_id);

    if (!read_u32_array(header_.bp_mem_offset,
                        std::min(header_.bp_mem_size, kBpMemSize), kBpMemSize,
                        bp_mem_, error, "BP snapshot") ||
        !read_u32_array(header_.cp_mem_offset,
                        std::min(header_.cp_mem_size, kCpMemSize), kCpMemSize,
                        cp_mem_, error, "CP snapshot") ||
        !read_u32_array(header_.xf_mem_offset,
                        std::min(header_.xf_mem_size, kXfMemSize), kXfMemSize,
                        xf_mem_, error, "XF memory snapshot") ||
        !read_u32_array(header_.xf_regs_offset,
                        std::min(header_.xf_regs_size, kXfRegsSize),
                        kXfRegsSize, xf_regs_, error, "XF register snapshot"))
      return false;

    // TMEM snapshot (v4+): only counted, never restored (see header comment).
    tmem_nonzero_ = 0;
    if (header_.version >= 4u && header_.tex_mem_size != 0u) {
      if (!range_ok(header_.tex_mem_offset, header_.tex_mem_size))
        return fail(error, "TMEM snapshot outside file");
      const std::uint8_t* tmem = bytes_ + header_.tex_mem_offset;
      for (std::uint32_t i = 0; i < header_.tex_mem_size; ++i)
        tmem_nonzero_ += tmem[i] != 0u ? 1u : 0u;
    }

    if (header_.frame_count == 0u)
      return fail(error, "DFF has zero frames");
    if (!range_ok(header_.frame_list_offset,
                  static_cast<std::uint64_t>(header_.frame_count) *
                      kDffFrameInfoSize))
      return fail(error, "frame list outside file");

    frames_.resize(header_.frame_count);
    for (std::uint32_t i = 0; i < header_.frame_count; ++i) {
      const std::uint8_t* info =
          bytes_ + header_.frame_list_offset + i * kDffFrameInfoSize;
      DffFrame& frame = frames_[i];
      frame.fifo_data_offset = read_le64(info);
      frame.fifo_data_size = read_le32(info + 8u);
      const std::uint64_t updates_offset = read_le64(info + 20u);
      const std::uint32_t update_count = read_le32(info + 28u);
      if (!range_ok(frame.fifo_data_offset, frame.fifo_data_size))
        return fail(error, "frame fifoData outside file");
      if (!range_ok(updates_offset, static_cast<std::uint64_t>(update_count) *
                                        kDffMemoryUpdateSize))
        return fail(error, "frame memory-update list outside file");
      frame.memory_updates.resize(update_count);
      for (std::uint32_t j = 0; j < update_count; ++j) {
        const std::uint8_t* u =
            bytes_ + updates_offset + j * kDffMemoryUpdateSize;
        DffMemoryUpdate& update = frame.memory_updates[j];
        update.fifo_position = read_le32(u);
        update.address = read_le32(u + 4u);
        update.data_offset = read_le64(u + 8u);
        update.data_size = read_le32(u + 16u);
        update.type = u[20];
        if (!range_ok(update.data_offset, update.data_size))
          return fail(error, "memory-update data outside file");
      }
      // FifoDataFile.h documents the list as sorted by fifoPosition; sort
      // defensively so interleaving never regresses on a violating recorder.
      std::stable_sort(frame.memory_updates.begin(),
                       frame.memory_updates.end(),
                       [](const DffMemoryUpdate& a, const DffMemoryUpdate& b) {
                         return a.fifo_position < b.fifo_position;
                       });
    }
    return true;
  }

  const DffHeader& header() const { return header_; }
  const std::vector<DffFrame>& frames() const { return frames_; }
  const std::uint32_t* bp_mem() const { return bp_mem_; }
  const std::uint32_t* cp_mem() const { return cp_mem_; }
  const std::uint32_t* xf_mem() const { return xf_mem_; }
  const std::uint32_t* xf_regs() const { return xf_regs_; }
  std::uint32_t tmem_nonzero() const { return tmem_nonzero_; }
  const std::uint8_t* file_bytes() const { return bytes_; }

private:
  static bool fail(std::string* error, const char* message) {
    if (error != nullptr)
      *error = message;
    return false;
  }

  bool range_ok(std::uint64_t offset, std::uint64_t size) const {
    return offset <= size_ && size <= size_ - offset;
  }

  bool read_u32_array(std::uint64_t offset, std::uint32_t count,
                      std::uint32_t capacity, std::uint32_t* out,
                      std::string* error, const char* what) {
    std::memset(out, 0, capacity * sizeof(std::uint32_t));
    if (!range_ok(offset, static_cast<std::uint64_t>(count) * 4u)) {
      if (error != nullptr)
        *error = std::string(what) + " outside file";
      return false;
    }
    for (std::uint32_t i = 0; i < count; ++i)
      out[i] = read_le32(bytes_ + offset + i * 4u);
    return true;
  }

  const std::uint8_t* bytes_ = nullptr;
  std::size_t size_ = 0;
  DffHeader header_{};
  std::vector<DffFrame> frames_;
  std::uint32_t bp_mem_[kBpMemSize] = {};
  std::uint32_t cp_mem_[kCpMemSize] = {};
  std::uint32_t xf_mem_[kXfMemSize] = {};
  std::uint32_t xf_regs_[kXfRegsSize] = {};
  std::uint32_t tmem_nonzero_ = 0;
};

// FifoPlayer::ShouldLoadBP — registers whose replay would trigger side
// effects rather than restore state (draw-done/token interrupts, EFB copy,
// TLUT DMA, TMEM preload, perf counters).
bool should_load_bp(std::uint8_t reg) {
  switch (reg) {
  case 0x45: // BPMEM_SETDRAWDONE
  case 0x47: // BPMEM_PE_TOKEN_ID
  case 0x48: // BPMEM_PE_TOKEN_INT_ID
  case 0x52: // BPMEM_TRIGGER_EFB_COPY
  case 0x63: // BPMEM_PRELOAD_MODE
  case 0x65: // BPMEM_LOADTLUT1
  case 0x67: // BPMEM_PERF1
    return false;
  default:
    return true;
  }
}

// FifoPlayer::ShouldLoadXF — skip the unknown/perf register ranges
// (addresses relative to 0x1000).
bool should_load_xf(std::uint8_t reg) {
  return !(reg == 0x07u || (reg >= 0x13u && reg <= 0x17u) ||
           (reg >= 0x27u && reg <= 0x3Eu) || (reg >= 0x48u && reg <= 0x4Fu));
}

void push_be32(std::vector<std::uint8_t>& out, std::uint32_t value) {
  out.push_back(static_cast<std::uint8_t>(value >> 24u));
  out.push_back(static_cast<std::uint8_t>(value >> 16u));
  out.push_back(static_cast<std::uint8_t>(value >> 8u));
  out.push_back(static_cast<std::uint8_t>(value));
}

// The state-restore preamble as raw FIFO bytes — the same command sequence
// FifoPlayer::LoadRegisters feeds Dolphin's GPU (BP 0x61 / CP 0x08 / XF 0x10
// loads, XF memory in 16-word bursts), so both replayers start from the
// recorded snapshot.
std::vector<std::uint8_t> build_state_preamble(const DffFile& dff,
                                               ConvertStats* stats) {
  std::vector<std::uint8_t> fifo;
  fifo.reserve(32u * 1024u);

  for (std::uint32_t reg = 0; reg < kBpMemSize; ++reg) {
    if (!should_load_bp(static_cast<std::uint8_t>(reg)))
      continue;
    fifo.push_back(0x61u);
    push_be32(fifo, (reg << 24u) | (dff.bp_mem()[reg] & 0x00FFFFFFu));
    if (stats != nullptr)
      ++stats->preamble_bp_regs;
  }

  auto load_cp = [&](std::uint8_t reg) {
    fifo.push_back(0x08u);
    fifo.push_back(reg);
    push_be32(fifo, dff.cp_mem()[reg]);
    if (stats != nullptr)
      ++stats->preamble_cp_regs;
  };
  load_cp(0x30u); // MATINDEX_A
  load_cp(0x40u); // MATINDEX_B
  load_cp(0x50u); // VCD_LO
  load_cp(0x60u); // VCD_HI
  for (std::uint8_t i = 0; i < 8u; ++i) {
    load_cp(0x70u + i); // VAT group A
    load_cp(0x80u + i); // VAT group B
    load_cp(0x90u + i); // VAT group C
  }
  for (std::uint8_t i = 0; i < 16u; ++i) {
    load_cp(0xA0u + i); // ARRAY_BASE
    load_cp(0xB0u + i); // ARRAY_STRIDE
  }

  for (std::uint32_t addr = 0; addr < kXfMemSize; addr += 16u) {
    fifo.push_back(0x10u);
    push_be32(fifo, 0x000F0000u | addr); // (count-1)=15 << 16 | address
    for (std::uint32_t i = 0; i < 16u; ++i)
      push_be32(fifo, dff.xf_mem()[addr + i]);
    if (stats != nullptr)
      stats->preamble_xf_words += 16u;
  }

  for (std::uint32_t reg = 0; reg < kXfRegsSize; ++reg) {
    if (!should_load_xf(static_cast<std::uint8_t>(reg)))
      continue;
    fifo.push_back(0x10u);
    push_be32(fifo, 0x1000u | reg); // count 1
    push_be32(fifo, dff.xf_regs()[reg]);
    if (stats != nullptr)
      ++stats->preamble_xf_regs;
  }
  return fifo;
}

// Emits a raw byte run as GX_WRITE records, preserving stream order. 8-byte
// records with 4/2/1 tails: the frontend re-buffers, so fragmentation only
// affects record count, never decode.
void write_gx_run(trace::TraceWriter& writer, const std::uint8_t* bytes,
                  std::size_t size, ConvertStats* stats) {
  std::size_t pos = 0;
  auto emit = [&](std::uint8_t width) {
    std::uint64_t value = 0;
    for (std::uint8_t i = 0; i < width; ++i)
      value = (value << 8u) | bytes[pos + i];
    writer.gx_write(width, value);
    pos += width;
    if (stats != nullptr)
      ++stats->gx_records;
  };
  while (size - pos >= 8u)
    emit(8u);
  if (size - pos >= 4u)
    emit(4u);
  if (size - pos >= 2u)
    emit(2u);
  if (size - pos >= 1u)
    emit(1u);
}

} // namespace

bool convert(const std::uint8_t* dff_bytes, std::size_t dff_size,
             const char* out_path, const ConvertOptions& options,
             ConvertStats* stats, std::string* error) {
  DffFile dff;
  if (!dff.parse(dff_bytes, dff_size, error))
    return false;

  if (stats != nullptr) {
    *stats = ConvertStats{};
    stats->dff_version = dff.header().version;
    stats->frames = dff.header().frame_count;
    stats->tmem_nonzero_bytes = dff.tmem_nonzero();
    std::memcpy(stats->game_id, dff.header().game_id, 8u);
  }

  trace::TraceWriter writer;
  trace::TraceHeader header{};
  std::memcpy(header.game_id, dff.header().game_id, sizeof header.game_id);
  header.mem1_size = dff.header().mem1_size != 0u ? dff.header().mem1_size
                                                  : kMem1SizeRetail;
  if (!writer.open(out_path, header)) {
    if (error != nullptr)
      *error = std::string("cannot open output ") + out_path;
    return false;
  }

  const std::vector<std::uint8_t> preamble = build_state_preamble(dff, stats);
  write_gx_run(writer, preamble.data(), preamble.size(), stats);

  for (std::uint32_t f = 0; f < dff.header().frame_count; ++f) {
    const DffFrame& frame = dff.frames()[f];
    writer.frame_begin(options.frame_base + f);
    const std::uint8_t* fifo = dff.file_bytes() + frame.fifo_data_offset;
    std::uint32_t pos = 0;
    for (const DffMemoryUpdate& update : frame.memory_updates) {
      const std::uint32_t split =
          std::min(update.fifo_position, frame.fifo_data_size);
      if (split > pos) {
        write_gx_run(writer, fifo + pos, split - pos, stats);
        pos = split;
      }
      if ((update.address & 0x10000000u) != 0u) {
        // EXRAM (Wii); unreachable for GC titles but never silently misfile
        // it into MEM1.
        if (stats != nullptr)
          ++stats->skipped_exram_updates;
        continue;
      }
      writer.mem_update(update.address,
                        dff.file_bytes() + update.data_offset,
                        update.data_size);
      if (stats != nullptr) {
        ++stats->mem_updates;
        stats->mem_update_bytes += update.data_size;
      }
    }
    if (pos < frame.fifo_data_size)
      write_gx_run(writer, fifo + pos, frame.fifo_data_size - pos, stats);
    if (stats != nullptr)
      stats->fifo_bytes += frame.fifo_data_size;
  }

  if (!writer.close() || !writer.ok()) {
    if (error != nullptr)
      *error = std::string("write failed for ") + out_path;
    return false;
  }
  return true;
}

bool convert_file(const char* dff_path, const char* out_path,
                  const ConvertOptions& options, ConvertStats* stats,
                  std::string* error) {
  std::FILE* file = std::fopen(dff_path, "rb");
  if (file == nullptr) {
    if (error != nullptr)
      *error = std::string("cannot open ") + dff_path;
    return false;
  }
  std::fseek(file, 0, SEEK_END);
  const long size = std::ftell(file);
  std::fseek(file, 0, SEEK_SET);
  std::vector<std::uint8_t> bytes(size > 0 ? static_cast<std::size_t>(size)
                                           : 0u);
  const std::size_t read =
      bytes.empty() ? 0u : std::fread(bytes.data(), 1u, bytes.size(), file);
  std::fclose(file);
  if (read != bytes.size()) {
    if (error != nullptr)
      *error = std::string("cannot read ") + dff_path;
    return false;
  }
  return convert(bytes.data(), bytes.size(), out_path, options, stats, error);
}

} // namespace gxruntime::aurora_recomp::dff
