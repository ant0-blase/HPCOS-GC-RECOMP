// SPDX-License-Identifier: GPL-3.0-or-later
// Replay-digest fixture: writes a tiny two-frame .dolt covering every
// record kind, replays it in-process, and asserts hand-checked digest values,
// digest stability across replays, and the against-stats gate (positive +
// negative). Frame 1 drives the display list through the in-FIFO 0x40 opcode
// (guest-resolved from shadow MEM1); frame 2 drives the SAME bytes through
// write_display_list (the CALL_DL record path) — the two frames must digest
// identically, proving the two DL entry paths are byte-path-identical.

#ifdef NDEBUG
#undef NDEBUG
#endif
#include "gxruntime/aurora_recomp/replay.hpp"
#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

namespace {

namespace replay = gxruntime::aurora_recomp::replay;
namespace trace = gxruntime::aurora_recomp::trace;

std::uint32_t tex_image0(std::uint16_t width, std::uint16_t height,
                         std::uint32_t format) {
  return static_cast<std::uint32_t>(width - 1u) |
         (static_cast<std::uint32_t>(height - 1u) << 10u) |
         ((format & 0xFu) << 20u);
}

void push_u8(std::vector<std::uint8_t>& fifo, std::uint8_t value) {
  fifo.push_back(value);
}

void push_u16(std::vector<std::uint8_t>& fifo, std::uint16_t value) {
  fifo.push_back(static_cast<std::uint8_t>(value >> 8u));
  fifo.push_back(static_cast<std::uint8_t>(value));
}

void push_u32(std::vector<std::uint8_t>& fifo, std::uint32_t value) {
  fifo.push_back(static_cast<std::uint8_t>(value >> 24u));
  fifo.push_back(static_cast<std::uint8_t>(value >> 16u));
  fifo.push_back(static_cast<std::uint8_t>(value >> 8u));
  fifo.push_back(static_cast<std::uint8_t>(value));
}

void push_cp(std::vector<std::uint8_t>& fifo, std::uint8_t reg,
             std::uint32_t value) {
  push_u8(fifo, DOL_GX_CMD_LOAD_CP_REG);
  push_u8(fifo, reg);
  push_u32(fifo, value);
}

void push_bp(std::vector<std::uint8_t>& fifo, std::uint8_t reg,
             std::uint32_t value) {
  push_u8(fifo, DOL_GX_CMD_LOAD_BP_REG);
  push_u32(fifo, (static_cast<std::uint32_t>(reg) << 24u) |
                     (value & 0x00FFFFFFu));
}

void push_xf(std::vector<std::uint8_t>& fifo, std::uint16_t base,
             std::uint32_t value) {
  push_u8(fifo, DOL_GX_CMD_LOAD_XF_REG);
  push_u32(fifo, base);
  push_u32(fifo, value);
}

void push_indexed_xf(std::vector<std::uint8_t>& fifo, std::uint8_t command,
                     std::uint16_t index, std::uint16_t base,
                     std::uint8_t count) {
  push_u8(fifo, command);
  push_u32(fifo, (static_cast<std::uint32_t>(index) << 16u) |
                     (static_cast<std::uint32_t>(count - 1u) << 12u) |
                     (base & 0x0FFFu));
}

void push_call_dl(std::vector<std::uint8_t>& fifo, std::uint32_t address,
                  std::uint32_t size) {
  push_u8(fifo, DOL_GX_CMD_CALL_DL);
  push_u32(fifo, address);
  push_u32(fifo, size);
}

void push_draw_indexed_fixture(std::vector<std::uint8_t>& fifo,
                               std::uint8_t cmd) {
  push_u8(fifo, cmd);
  push_u16(fifo, 3u);
  const std::uint8_t verts[] = {
      0x00, 0x02,
      0x03, 0x05,
      0x06, 0x01,
  };
  fifo.insert(fifo.end(), std::begin(verts), std::end(verts));
}

constexpr std::uint32_t kDlOffset = 0x200u;
constexpr std::uint32_t kArrayBase = 0x400u;
constexpr std::uint32_t kXfArrayBase = 0x600u;
constexpr std::uint32_t kTextureBase = 0x800u;
constexpr std::uint32_t kTlutBase = 0x1000u;
constexpr std::uint32_t kCopyBase = 0x1200u;
constexpr std::uint32_t kMem1Size = 0x2000u;

std::vector<std::uint8_t> build_display_list() {
  std::vector<std::uint8_t> dl;
  push_bp(dl, DOL_GX_BP_REG_GENMODE, 3u << 14u);
  push_bp(dl, DOL_GX_BP_REG_LOAD_TLUT0, kTlutBase >> 5u);
  push_bp(dl, DOL_GX_BP_REG_LOAD_TLUT1, 0x20u | (1u << 10u));
  push_bp(dl, DOL_GX_BP_REG_TX_SETTLUT + 1u, 0x20u | (1u << 10u));
  push_bp(dl, DOL_GX_BP_REG_TX_SETIMAGE0 + 1u, tex_image0(16u, 8u, 1u));
  push_bp(dl, DOL_GX_BP_REG_TX_SETIMAGE3 + 1u, kTextureBase >> 5u);
  push_bp(dl, DOL_GX_BP_REG_EFB_TL, 0u);
  push_bp(dl, DOL_GX_BP_REG_EFB_WH, (7u << 10u) | 7u);
  push_bp(dl, DOL_GX_BP_REG_EFB_ADDR, kCopyBase >> 5u);
  push_bp(dl, DOL_GX_BP_REG_TRIGGER_EFB_COPY, 2u << 3u);
  push_u8(dl, DOL_GX_CMD_INVL_VC);
  push_xf(dl, 0x1008u, 0x12345678u);
  push_indexed_xf(dl, 0x20u, 1u, 0x0000u, 12u);
  push_draw_indexed_fixture(dl, 0x80u);
  // Zero-vertex draw header (s56 no-op; the exact retail pattern `98 00 00`):
  // no Draw packet, but counted as zdraws for the against-stats gate.
  push_u8(dl, 0x98u);
  push_u16(dl, 0u);
  while ((dl.size() & 31u) != 0u)
    push_u8(dl, 0u);
  return dl;
}

std::vector<std::uint8_t> build_fifo(std::uint32_t dl_size) {
  std::vector<std::uint8_t> fifo;
  push_cp(fifo, DOL_GX_CP_REG_VCD_LO, (1u << 0u) | (2u << 9u));
  push_cp(fifo, DOL_GX_CP_REG_VCD_HI, 0u);
  push_cp(fifo, DOL_GX_CP_REG_VAT_GRP0, (1u << 0u) | (4u << 1u));
  push_cp(fifo, DOL_GX_CP_REG_ARRAYBASE, kArrayBase);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYSTRIDE, 12u);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYBASE + 12u, kXfArrayBase);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYSTRIDE + 12u, 48u);
  push_call_dl(fifo, kDlOffset, dl_size);
  return fifo;
}

// Chop a byte stream into GX_WRITE records (4-byte words, 1-byte remainder),
// crossing command boundaries so partial-command buffering is exercised.
void record_gx_writes(trace::TraceWriter& writer,
                      const std::vector<std::uint8_t>& bytes) {
  std::size_t pos = 0;
  while (pos + 4u <= bytes.size()) {
    const std::uint64_t value = (static_cast<std::uint64_t>(bytes[pos]) << 24u) |
                                (static_cast<std::uint64_t>(bytes[pos + 1u]) << 16u) |
                                (static_cast<std::uint64_t>(bytes[pos + 2u]) << 8u) |
                                static_cast<std::uint64_t>(bytes[pos + 3u]);
    writer.gx_write(4u, value);
    pos += 4u;
  }
  while (pos < bytes.size())
    writer.gx_write(1u, bytes[pos++]);
}

void write_region(trace::TraceWriter& writer, std::uint32_t base,
                  std::uint8_t seed) {
  std::uint8_t bytes[256];
  for (std::uint32_t i = 0; i < 256u; ++i)
    bytes[i] = static_cast<std::uint8_t>(seed + i);
  writer.mem_update(base, bytes, sizeof bytes);
}

trace::PresentStats fixture_stats(std::uint32_t frame) {
  trace::PresentStats stats{};
  stats.frame_index = frame;
  // One real draw + one zero-vertex draw: live Aurora counts both.
  stats.draw_call_count = 2u;
  // Replay produces 6 raw vertex bytes; Aurora pads unmerged draws to 4 bytes,
  // so a native 8 must sit inside the 4*draws+4 band.
  stats.last_vert_size = 8u;
  return stats;
}

void write_fixture_trace(const char* path) {
  const std::vector<std::uint8_t> dl = build_display_list();
  const std::vector<std::uint8_t> fifo =
      build_fifo(static_cast<std::uint32_t>(dl.size()));

  trace::TraceWriter writer;
  trace::TraceHeader header{};
  std::memcpy(header.game_id, "TEST0063", 8u);
  header.mem1_size = kMem1Size;
  assert(writer.open(path, header));

  writer.frame_begin(1u);
  write_region(writer, kArrayBase, 0x10u);
  write_region(writer, kXfArrayBase, 0x80u);
  write_region(writer, kTextureBase, 0x40u);
  write_region(writer, kTlutBase, 0x20u);
  write_region(writer, kCopyBase, 0x60u);
  writer.mem_update(kDlOffset, dl.data(), static_cast<std::uint32_t>(dl.size()));
  // Redundant with the CP writes below; exercises the SET_ARRAY record kind.
  writer.set_array(0u, kArrayBase, 12u);
  record_gx_writes(writer, fifo);
  writer.present_stats(fixture_stats(1u));

  writer.frame_begin(2u);
  writer.call_display_list(0u, dl.data(), static_cast<std::uint32_t>(dl.size()));
  writer.present_stats(fixture_stats(2u));

  assert(writer.close());
  assert(writer.ok());
}

replay::ReplayResult replay_file(const char* path) {
  trace::TraceReader reader;
  assert(reader.open(path));
  return replay::replay_trace(reader);
}

void test_fixture_digest(const char* path) {
  const replay::ReplayResult result = replay_file(path);
  assert(result.parse_ok);
  assert(!result.truncated);
  assert(result.frames.size() == 2u);

  // Hand-checked frame 1: one 3-vertex quad draw, 3*2 payload bytes, no
  // complete quad -> no topology indices, indexed span 72 -> storage, 3
  // assembled elements (one indexed attr x 3 vertices).
  const replay::FrameDigest& f1 = result.frames[0];
  assert(f1.frame_index == 1u);
  assert(f1.draws == 1u);
  assert(f1.zero_draws == 1u);
  assert(f1.vert_bytes == 6u);
  assert(f1.topo_bytes == 0u);
  assert(f1.store_bytes == 72u);
  assert(f1.elements == 3u);
  assert(f1.has_stats);
  assert(f1.stats.draw_call_count == 2u);

  const std::string line1 = replay::format_digest_line(f1);
  const char* expected_prefix =
      "frame 1 draws 1 zdraws 1 verts 6 topo 0 store 72 elems 3 fnv ";
  assert(line1.compare(0u, std::strlen(expected_prefix), expected_prefix) ==
         0);

  // Frame 2 replays the SAME display list through write_display_list; every
  // digest field except the frame index must match frame 1 exactly.
  const replay::FrameDigest& f2 = result.frames[1];
  assert(f2.frame_index == 2u);
  assert(f2.draws == f1.draws);
  assert(f2.zero_draws == f1.zero_draws);
  assert(f2.vert_bytes == f1.vert_bytes);
  assert(f2.topo_bytes == f1.topo_bytes);
  assert(f2.store_bytes == f1.store_bytes);
  assert(f2.elements == f1.elements);
  assert(f2.content_fnv == f1.content_fnv);
  assert(f2.state_fnv == f1.state_fnv);
  assert(f1.content_fnv != 0u);
  assert(f1.state_fnv != 0u);

  // Digest stability: an independent replay of the same file produces
  // byte-identical digest lines.
  const replay::ReplayResult again = replay_file(path);
  assert(again.parse_ok);
  assert(again.frames.size() == result.frames.size());
  for (std::size_t i = 0; i < result.frames.size(); ++i) {
    assert(replay::format_digest_line(result.frames[i]) ==
           replay::format_digest_line(again.frames[i]));
  }

  // Positive against-stats gate: draws exact, vert extent inside the band.
  // Stats gate one present behind (frame N pairs with stats@N+1), so two
  // frames yield one gated pair; both frames carry identical stats here,
  // making the fixture shift-invariant.
  const replay::StatsCompareResult cmp =
      replay::compare_against_stats(result);
  assert(cmp.ok);
  assert(cmp.frames_compared == 1u);
  assert(cmp.mismatch_frames == 0u);
}

void test_against_stats_gate_fails_on_sustained_mismatch(const char* path) {
  // Four empty frames each claiming one draw: replay produces zero draws.
  // With the one-behind pairing that yields three gated pairs, and three
  // consecutive mismatches must trip the >2-consecutive rule.
  trace::TraceWriter writer;
  trace::TraceHeader header{};
  header.mem1_size = kMem1Size;
  assert(writer.open(path, header));
  for (std::uint32_t frame = 1u; frame <= 4u; ++frame) {
    writer.frame_begin(frame);
    trace::PresentStats stats{};
    stats.frame_index = frame;
    stats.draw_call_count = 1u;
    writer.present_stats(stats);
  }
  assert(writer.close());

  const replay::ReplayResult result = replay_file(path);
  assert(result.parse_ok);
  assert(result.frames.size() == 4u);
  const replay::StatsCompareResult cmp =
      replay::compare_against_stats(result);
  assert(!cmp.ok);
  assert(cmp.mismatch_frames == 3u);
  assert(cmp.worst_consecutive == 3u);
  assert(!cmp.detail.empty());
}

} // namespace

int main() {
  const char* fixture_path = "replay_digest_fixture.dolt";
  const char* negative_path = "replay_digest_negative.dolt";
  write_fixture_trace(fixture_path);
  test_fixture_digest(fixture_path);
  test_against_stats_gate_fails_on_sustained_mismatch(negative_path);
  std::remove(fixture_path);
  std::remove(negative_path);
  std::printf("replay_digest_tests passed\n");
  return 0;
}
