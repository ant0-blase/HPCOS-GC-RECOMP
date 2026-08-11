// SPDX-License-Identifier: GPL-3.0-or-later
// dff2dolt fixture: builds a synthetic Dolphin FIFO log (v6) in
// memory, converts it, and replays the result in-process. The draw-critical
// CP state (VCD/VAT/array base+stride) lives ONLY in the .dff header
// snapshot — never in the frame's fifoData — so a passing draw proves the
// synthesized state-restore preamble reaches the frontend. Frame 2 repeats
// the draw with no state commands at all, proving restored state persists
// across converted frame boundaries.

#ifdef NDEBUG
#undef NDEBUG
#endif
#include "gxruntime/aurora_recomp/dff2dolt.hpp"
#include "gxruntime/aurora_recomp/replay.hpp"
#include "gxruntime/aurora_recomp/trace.hpp"

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

namespace {

namespace dff = gxruntime::aurora_recomp::dff;
namespace replay = gxruntime::aurora_recomp::replay;
namespace trace = gxruntime::aurora_recomp::trace;

constexpr std::uint32_t kArrayBase = 0x400u;
constexpr std::uint32_t kMem1Retail = 0x01800000u;

void put_le16(std::vector<std::uint8_t>& out, std::uint16_t value) {
  out.push_back(static_cast<std::uint8_t>(value));
  out.push_back(static_cast<std::uint8_t>(value >> 8u));
}

void put_le32(std::vector<std::uint8_t>& out, std::uint32_t value) {
  put_le16(out, static_cast<std::uint16_t>(value));
  put_le16(out, static_cast<std::uint16_t>(value >> 16u));
}

void put_le64(std::vector<std::uint8_t>& out, std::uint64_t value) {
  put_le32(out, static_cast<std::uint32_t>(value));
  put_le32(out, static_cast<std::uint32_t>(value >> 32u));
}

void patch_le32(std::vector<std::uint8_t>& out, std::size_t offset,
                std::uint32_t value) {
  out[offset] = static_cast<std::uint8_t>(value);
  out[offset + 1u] = static_cast<std::uint8_t>(value >> 8u);
  out[offset + 2u] = static_cast<std::uint8_t>(value >> 16u);
  out[offset + 3u] = static_cast<std::uint8_t>(value >> 24u);
}

void patch_le64(std::vector<std::uint8_t>& out, std::size_t offset,
                std::uint64_t value) {
  patch_le32(out, offset, static_cast<std::uint32_t>(value));
  patch_le32(out, offset + 4u, static_cast<std::uint32_t>(value >> 32u));
}

// One 3-vertex indexed draw (quads, vtxfmt 0): [pn-matrix u8, pos index u8]
// per vertex — decodes only if VCD_LO/VAT0/ARRAYBASE/STRIDE restored.
std::vector<std::uint8_t> build_draw_fifo() {
  std::vector<std::uint8_t> fifo;
  fifo.push_back(0x80u); // draw quads, vtxfmt 0
  fifo.push_back(0x00u); // count 3 (big-endian u16)
  fifo.push_back(0x03u);
  const std::uint8_t verts[] = {0x00u, 0x02u, 0x03u, 0x05u, 0x06u, 0x01u};
  fifo.insert(fifo.end(), std::begin(verts), std::end(verts));
  return fifo;
}

struct DffMemUpdateSpec {
  std::uint32_t fifo_position = 0;
  std::uint32_t address = 0;
  std::vector<std::uint8_t> data;
};

struct DffFrameSpec {
  std::vector<std::uint8_t> fifo;
  std::vector<DffMemUpdateSpec> updates;
};

// Serializes a v6 FifoDataFile: 128-byte header, frame list, BP/CP/XF/XFRegs
// snapshots, then per-frame fifoData + memory-update lists (the same shapes
// FifoDataFile::Save writes; TMEM omitted via texMemSize=0).
std::vector<std::uint8_t> build_dff(const std::vector<DffFrameSpec>& frames,
                                    const std::uint32_t* cp_snapshot,
                                    const std::uint32_t* xf_regs_snapshot) {
  std::vector<std::uint8_t> out;
  out.resize(128u, 0u); // header patched at the end
  const std::size_t frame_list_offset = out.size();
  out.resize(out.size() + frames.size() * 64u, 0u);

  const std::size_t bp_offset = out.size();
  for (std::uint32_t i = 0; i < 256u; ++i)
    put_le32(out, 0u);
  const std::size_t cp_offset = out.size();
  for (std::uint32_t i = 0; i < 256u; ++i)
    put_le32(out, cp_snapshot[i]);
  const std::size_t xf_offset = out.size();
  for (std::uint32_t i = 0; i < 4096u; ++i)
    put_le32(out, i < 12u ? 0x3F800000u : 0u); // matrix 0 words = 1.0f
  const std::size_t xf_regs_offset = out.size();
  for (std::uint32_t i = 0; i < 88u; ++i)
    put_le32(out, xf_regs_snapshot[i]);

  for (std::size_t f = 0; f < frames.size(); ++f) {
    const DffFrameSpec& frame = frames[f];
    const std::size_t fifo_offset = out.size();
    out.insert(out.end(), frame.fifo.begin(), frame.fifo.end());

    const std::size_t update_list_offset = out.size();
    out.resize(out.size() + frame.updates.size() * 24u, 0u);
    std::vector<std::uint64_t> data_offsets;
    for (const DffMemUpdateSpec& update : frame.updates) {
      data_offsets.push_back(out.size());
      out.insert(out.end(), update.data.begin(), update.data.end());
    }
    for (std::size_t u = 0; u < frame.updates.size(); ++u) {
      const std::size_t entry = update_list_offset + u * 24u;
      patch_le32(out, entry, frames[f].updates[u].fifo_position);
      patch_le32(out, entry + 4u, frames[f].updates[u].address);
      patch_le64(out, entry + 8u, data_offsets[u]);
      patch_le32(out, entry + 16u,
                 static_cast<std::uint32_t>(frames[f].updates[u].data.size()));
      out[entry + 20u] = 0x04u; // MemoryUpdate::Type::VertexStream
    }

    const std::size_t frame_entry = frame_list_offset + f * 64u;
    patch_le64(out, frame_entry, fifo_offset);
    patch_le32(out, frame_entry + 8u,
               static_cast<std::uint32_t>(frame.fifo.size()));
    patch_le32(out, frame_entry + 12u, 0x01000000u); // fifoStart (unused)
    patch_le32(out, frame_entry + 16u, 0x01010000u); // fifoEnd (unused)
    patch_le64(out, frame_entry + 20u, update_list_offset);
    patch_le32(out, frame_entry + 28u,
               static_cast<std::uint32_t>(frame.updates.size()));
  }

  patch_le32(out, 0u, 0x0D01F1F0u); // magic
  patch_le32(out, 4u, 6u);          // file_version
  patch_le32(out, 8u, 1u);          // min_loader_version
  patch_le64(out, 12u, bp_offset);
  patch_le32(out, 20u, 256u);
  patch_le64(out, 24u, cp_offset);
  patch_le32(out, 32u, 256u);
  patch_le64(out, 36u, xf_offset);
  patch_le32(out, 44u, 4096u);
  patch_le64(out, 48u, xf_regs_offset);
  patch_le32(out, 56u, 88u);
  patch_le64(out, 60u, frame_list_offset);
  patch_le32(out, 68u, static_cast<std::uint32_t>(frames.size()));
  patch_le32(out, 72u, 0u);          // flags (GC)
  patch_le64(out, 76u, 0u);          // texMemOffset
  patch_le32(out, 84u, 0u);          // texMemSize (no TMEM snapshot)
  patch_le32(out, 88u, kMem1Retail); // mem1_size
  patch_le32(out, 92u, 0x04000000u); // mem2_size
  std::memcpy(out.data() + 96u, "TESTDFF0", 8u);
  return out;
}

std::vector<std::uint8_t> vertex_array_bytes() {
  std::vector<std::uint8_t> data(256u);
  for (std::size_t i = 0; i < data.size(); ++i)
    data[i] = static_cast<std::uint8_t>(0x10u + i);
  return data;
}

void snapshot_regs(std::uint32_t* cp, std::uint32_t* xf_regs) {
  std::memset(cp, 0, 256u * sizeof(std::uint32_t));
  std::memset(xf_regs, 0, 88u * sizeof(std::uint32_t));
  cp[0x50] = (1u << 0u) | (2u << 9u); // VCD_LO: PNMatIdx + pos INDEX8
  cp[0x70] = (1u << 0u) | (4u << 1u); // VAT0: pos 3-comp F32
  cp[0xA0] = kArrayBase;              // ARRAY_BASE[pos]
  cp[0xB0] = 12u;                     // ARRAY_STRIDE[pos]
  for (std::uint32_t i = 0; i < 6u; ++i) {
    xf_regs[0x1Au + i] = 0x42C80000u; // viewport = 100.0f
    xf_regs[0x20u + i] = 0x3F800000u; // projection = 1.0f
  }
  xf_regs[0x26u] = 0u; // projection type: perspective
}

void test_two_frame_conversion(const char* dolt_path) {
  std::uint32_t cp[256];
  std::uint32_t xf_regs[88];
  snapshot_regs(cp, xf_regs);

  std::vector<DffFrameSpec> frames(2u);
  frames[0].fifo = build_draw_fifo();
  frames[0].updates.push_back({0u, kArrayBase, vertex_array_bytes()});
  frames[1].fifo = build_draw_fifo(); // no state commands: preamble persists

  const std::vector<std::uint8_t> dff_bytes = build_dff(frames, cp, xf_regs);

  dff::ConvertStats stats;
  std::string error;
  assert(dff::convert(dff_bytes.data(), dff_bytes.size(), dolt_path,
                      dff::ConvertOptions{}, &stats, &error));
  assert(stats.dff_version == 6u);
  assert(stats.frames == 2u);
  assert(std::strcmp(stats.game_id, "TESTDFF0") == 0);
  assert(stats.preamble_bp_regs == 256u - 7u);
  assert(stats.preamble_cp_regs == 4u + 3u * 8u + 2u * 16u);
  assert(stats.preamble_xf_words == 4096u);
  assert(stats.preamble_xf_regs == 88u - 38u);
  assert(stats.mem_updates == 1u);
  assert(stats.mem_update_bytes == 256u);
  assert(stats.skipped_exram_updates == 0u);
  assert(stats.fifo_bytes == frames[0].fifo.size() + frames[1].fifo.size());

  trace::TraceReader reader;
  assert(reader.open(dolt_path));
  assert(reader.header().mem1_size == kMem1Retail);
  assert(std::memcmp(reader.header().game_id, "TESTDFF0", 8u) == 0);

  const replay::ReplayResult result = replay::replay_trace(reader);
  if (!result.parse_ok)
    std::fprintf(stderr, "replay error: %s\n", result.error.c_str());
  assert(result.parse_ok);
  assert(!result.truncated);
  assert(result.frames.size() == 2u);

  // Hand-checked (same geometry as replay_digest_test): one 3-vertex quad
  // draw, 2 bytes/vertex payload, index span 5*12+12 = 72 storage bytes.
  const replay::FrameDigest& f1 = result.frames[0];
  assert(f1.frame_index == 1u);
  assert(f1.draws == 1u);
  assert(f1.zero_draws == 0u);
  assert(f1.vert_bytes == 6u);
  assert(f1.store_bytes == 72u);
  assert(f1.elements == 3u);
  assert(!f1.has_stats); // converted traces carry no Aurora stats

  const replay::FrameDigest& f2 = result.frames[1];
  assert(f2.frame_index == 2u);
  assert(f2.draws == f1.draws);
  assert(f2.vert_bytes == f1.vert_bytes);
  assert(f2.store_bytes == f1.store_bytes);
  assert(f2.elements == f1.elements);
  assert(f2.content_fnv == f1.content_fnv);
  assert(f1.content_fnv != 0u);

  // No PRESENT_STATS records -> against-stats must report zero gateable
  // pairs (the pixel oracle is the .dff gate, never the stats gate).
  const replay::StatsCompareResult cmp = replay::compare_against_stats(result);
  assert(!cmp.ok);
  assert(cmp.frames_compared == 0u);
}

void test_exram_update_skipped(const char* dolt_path) {
  std::uint32_t cp[256];
  std::uint32_t xf_regs[88];
  snapshot_regs(cp, xf_regs);

  std::vector<DffFrameSpec> frames(1u);
  frames[0].fifo = build_draw_fifo();
  frames[0].updates.push_back({0u, kArrayBase, vertex_array_bytes()});
  frames[0].updates.push_back({0u, 0x10000040u, {0xAAu, 0xBBu}}); // EXRAM

  const std::vector<std::uint8_t> dff_bytes = build_dff(frames, cp, xf_regs);
  dff::ConvertStats stats;
  std::string error;
  assert(dff::convert(dff_bytes.data(), dff_bytes.size(), dolt_path,
                      dff::ConvertOptions{}, &stats, &error));
  assert(stats.skipped_exram_updates == 1u);
  assert(stats.mem_updates == 1u);

  trace::TraceReader reader;
  assert(reader.open(dolt_path));
  const replay::ReplayResult result = replay::replay_trace(reader);
  assert(result.parse_ok);
  assert(result.frames.size() == 1u);
  assert(result.frames[0].draws == 1u);
}

void test_malformed_inputs() {
  dff::ConvertStats stats;
  std::string error;
  const std::uint8_t junk[64] = {};
  assert(!dff::convert(junk, sizeof junk, "dff2dolt_unwritten.dolt",
                       dff::ConvertOptions{}, &stats, &error));
  assert(!error.empty());

  std::uint32_t cp[256];
  std::uint32_t xf_regs[88];
  snapshot_regs(cp, xf_regs);
  std::vector<DffFrameSpec> frames(1u);
  frames[0].fifo = build_draw_fifo();
  std::vector<std::uint8_t> dff_bytes = build_dff(frames, cp, xf_regs);
  dff_bytes.resize(dff_bytes.size() - 4u); // truncate the frame payload
  error.clear();
  assert(!dff::convert(dff_bytes.data(), dff_bytes.size(),
                       "dff2dolt_unwritten.dolt", dff::ConvertOptions{},
                       &stats, &error));
  assert(!error.empty());
}

} // namespace

int main() {
  const char* fixture_path = "dff2dolt_fixture.dolt";
  const char* exram_path = "dff2dolt_exram.dolt";
  test_two_frame_conversion(fixture_path);
  test_exram_update_skipped(exram_path);
  test_malformed_inputs();
  std::remove(fixture_path);
  std::remove(exram_path);
  std::printf("dff2dolt_tests passed\n");
  return 0;
}
