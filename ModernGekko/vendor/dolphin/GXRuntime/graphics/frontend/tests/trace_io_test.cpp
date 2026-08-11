// SPDX-License-Identifier: GPL-3.0-or-later
#ifdef NDEBUG
#undef NDEBUG
#endif
#include "gxruntime/aurora_recomp/trace.hpp"

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

namespace {

using gxruntime::aurora_recomp::trace::PresentStats;
using gxruntime::aurora_recomp::trace::RecordKind;
using gxruntime::aurora_recomp::trace::RecordView;
using gxruntime::aurora_recomp::trace::TraceHeader;
using gxruntime::aurora_recomp::trace::TraceReader;
using gxruntime::aurora_recomp::trace::TraceWriter;

constexpr const char* kPath = "trace_io_test.dolt";

std::vector<std::uint8_t> pattern_bytes(std::size_t size, std::uint8_t seed) {
  std::vector<std::uint8_t> bytes(size);
  for (std::size_t i = 0; i < size; ++i)
    bytes[i] = static_cast<std::uint8_t>(seed + i * 7u);
  return bytes;
}

TraceHeader test_header() {
  TraceHeader header{};
  std::memcpy(header.game_id, "G4QE01\0", 8);
  header.mem1_size = 0x01800000u;
  header.flags = 0;
  return header;
}

// Writes one of each record kind, including a 0-byte and a >64KB MemUpdate.
void write_reference_trace(const char* path, std::uint64_t* records_out) {
  TraceWriter writer;
  const bool opened = writer.open(path, test_header());
  assert(opened);
  writer.frame_begin(60);
  writer.gx_write(1, 0x61u);
  writer.gx_write(4, 0x41000234u);
  writer.gx_write(8, 0x1122334455667788u);
  const auto dl = pattern_bytes(35, 0x10);
  writer.call_display_list(0x80321000u, dl.data(), (std::uint32_t)dl.size());
  writer.set_array(9, 0x00321440u, 12);
  writer.mem_update(0x80440000u, nullptr, 0); // 0-byte update is legal
  const auto big = pattern_bytes(70001, 0x42); // > 64 KB payload
  writer.mem_update(0x80500000u, big.data(), (std::uint32_t)big.size());
  PresentStats stats{};
  stats.frame_index = 60;
  stats.queued_pipelines = 1;
  stats.created_pipelines = 2;
  stats.draw_call_count = 9;
  stats.merged_draw_call_count = 3;
  stats.last_vert_size = 1968;
  stats.last_uniform_size = 4096;
  stats.last_index_size = 984;
  stats.last_storage_size = 6560;
  stats.last_texture_upload_size = 0;
  writer.present_stats(stats);
  assert(writer.ok());
  *records_out = writer.records_written();
  const bool closed = writer.close();
  assert(closed);
}

void check_reference_records(TraceReader& reader) {
  RecordView r{};

  bool have = reader.next(r);
  assert(have);
  std::uint32_t frame = 0;
  assert(decode_frame_begin(r, frame) && frame == 60);

  const std::uint8_t expect_sizes[3] = {1, 4, 8};
  const std::uint64_t expect_values[3] = {0x61u, 0x41000234u,
                                          0x1122334455667788u};
  for (int i = 0; i < 3; ++i) {
    have = reader.next(r);
    assert(have);
    std::uint8_t size = 0;
    std::uint64_t value = 0;
    assert(decode_gx_write(r, size, value));
    assert(size == expect_sizes[i]);
    assert(value == expect_values[i]);
  }

  have = reader.next(r);
  assert(have);
  std::uint32_t addr = 0;
  std::span<const std::uint8_t> bytes;
  assert(decode_call_display_list(r, addr, bytes));
  assert(addr == 0x80321000u && bytes.size() == 35);
  const auto dl = pattern_bytes(35, 0x10);
  assert(std::memcmp(bytes.data(), dl.data(), dl.size()) == 0);

  have = reader.next(r);
  assert(have);
  std::uint8_t attr = 0;
  std::uint16_t stride = 0;
  assert(decode_set_array(r, attr, addr, stride));
  assert(attr == 9 && addr == 0x00321440u && stride == 12);

  have = reader.next(r);
  assert(have);
  assert(decode_mem_update(r, addr, bytes));
  assert(addr == 0x80440000u && bytes.empty());

  have = reader.next(r);
  assert(have);
  assert(decode_mem_update(r, addr, bytes));
  assert(addr == 0x80500000u && bytes.size() == 70001);
  const auto big = pattern_bytes(70001, 0x42);
  assert(std::memcmp(bytes.data(), big.data(), big.size()) == 0);

  have = reader.next(r);
  assert(have);
  PresentStats stats{};
  assert(decode_present_stats(r, stats));
  assert(stats.frame_index == 60 && stats.draw_call_count == 9 &&
         stats.last_vert_size == 1968 && stats.last_storage_size == 6560 &&
         stats.merged_draw_call_count == 3);
}

void test_round_trip() {
  std::uint64_t written = 0;
  write_reference_trace(kPath, &written);
  assert(written == 9);

  TraceReader reader;
  const bool opened = reader.open(kPath);
  assert(opened);
  assert(std::memcmp(reader.header().game_id, "G4QE01\0", 8) == 0);
  assert(reader.header().mem1_size == 0x01800000u);

  check_reference_records(reader);
  RecordView r{};
  assert(!reader.next(r));
  assert(!reader.truncated());
  assert(reader.records_read() == written);

  // rewind() re-reads the same stream.
  reader.rewind();
  check_reference_records(reader);
}

void test_truncated_tail() {
  TraceReader whole;
  const bool opened = whole.open(kPath);
  assert(opened);

  std::FILE* f = std::fopen(kPath, "rb");
  assert(f);
  std::vector<std::uint8_t> bytes;
  std::uint8_t buf[1 << 16];
  std::size_t n = 0;
  while ((n = std::fread(buf, 1, sizeof buf, f)) > 0)
    bytes.insert(bytes.end(), buf, buf + n);
  std::fclose(f);

  // Cut into the final record (PresentStats payload is 40 bytes).
  bytes.resize(bytes.size() - 5);
  TraceReader reader;
  const bool reopened = reader.open_bytes(std::move(bytes));
  assert(reopened);
  RecordView r{};
  std::uint64_t complete = 0;
  while (reader.next(r))
    ++complete;
  assert(reader.truncated());
  assert(complete == 8); // every record before the cut one
}

void test_bad_header() {
  TraceReader reader;
  assert(!reader.open_bytes({}));
  std::vector<std::uint8_t> junk(32, 0xAB);
  assert(!reader.open_bytes(std::move(junk)));
}

} // namespace

int main() {
  test_round_trip();
  test_truncated_tail();
  test_bad_header();
  std::remove(kPath);
  std::printf("trace_io_test: all assertions passed\n");
  return 0;
}
