// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/aurora_recomp/trace.hpp"

#include <cstring>

namespace gxruntime::aurora_recomp::trace {

namespace {

void store_u16le(std::uint8_t* dst, std::uint16_t v) {
  dst[0] = static_cast<std::uint8_t>(v);
  dst[1] = static_cast<std::uint8_t>(v >> 8u);
}

void store_u32le(std::uint8_t* dst, std::uint32_t v) {
  dst[0] = static_cast<std::uint8_t>(v);
  dst[1] = static_cast<std::uint8_t>(v >> 8u);
  dst[2] = static_cast<std::uint8_t>(v >> 16u);
  dst[3] = static_cast<std::uint8_t>(v >> 24u);
}

void store_u64le(std::uint8_t* dst, std::uint64_t v) {
  store_u32le(dst, static_cast<std::uint32_t>(v));
  store_u32le(dst + 4, static_cast<std::uint32_t>(v >> 32u));
}

std::uint16_t load_u16le(const std::uint8_t* src) {
  return static_cast<std::uint16_t>(src[0] | (src[1] << 8u));
}

std::uint32_t load_u32le(const std::uint8_t* src) {
  return static_cast<std::uint32_t>(src[0]) |
         (static_cast<std::uint32_t>(src[1]) << 8u) |
         (static_cast<std::uint32_t>(src[2]) << 16u) |
         (static_cast<std::uint32_t>(src[3]) << 24u);
}

std::uint64_t load_u64le(const std::uint8_t* src) {
  return static_cast<std::uint64_t>(load_u32le(src)) |
         (static_cast<std::uint64_t>(load_u32le(src + 4)) << 32u);
}

} // namespace

TraceWriter::~TraceWriter() { close(); }

bool TraceWriter::open(const char* path, const TraceHeader& header) {
  close();
  file_ = std::fopen(path, "wb");
  if (!file_)
    return false;
  ok_ = true;
  records_ = 0;
  bytes_ = 0;
  std::uint8_t buf[kHeaderSize];
  store_u32le(buf, kMagic);
  store_u32le(buf + 4, kVersion);
  std::memcpy(buf + 8, header.game_id, 8);
  store_u32le(buf + 16, header.mem1_size);
  store_u32le(buf + 20, header.flags);
  if (std::fwrite(buf, 1, sizeof buf, file_) != sizeof buf)
    ok_ = false;
  bytes_ += sizeof buf;
  return ok_;
}

void TraceWriter::write_record(RecordKind kind, const void* fixed,
                               std::uint32_t fixed_size, const void* tail,
                               std::uint32_t tail_size) {
  if (!file_)
    return;
  std::uint8_t head[kRecordHeaderSize];
  head[0] = static_cast<std::uint8_t>(kind);
  store_u32le(head + 1, fixed_size + tail_size);
  if (std::fwrite(head, 1, sizeof head, file_) != sizeof head)
    ok_ = false;
  if (fixed_size &&
      std::fwrite(fixed, 1, fixed_size, file_) != fixed_size)
    ok_ = false;
  if (tail_size && std::fwrite(tail, 1, tail_size, file_) != tail_size)
    ok_ = false;
  ++records_;
  bytes_ += sizeof head + fixed_size + tail_size;
}

void TraceWriter::frame_begin(std::uint32_t frame_index) {
  std::uint8_t p[4];
  store_u32le(p, frame_index);
  write_record(RecordKind::FrameBegin, p, sizeof p);
}

void TraceWriter::gx_write(std::uint8_t size, std::uint64_t value) {
  std::uint8_t p[9];
  p[0] = size;
  store_u64le(p + 1, value);
  write_record(RecordKind::GxWrite, p, sizeof p);
}

void TraceWriter::call_display_list(std::uint32_t guest_addr, const void* bytes,
                                    std::uint32_t byte_size) {
  std::uint8_t p[8];
  store_u32le(p, guest_addr);
  store_u32le(p + 4, byte_size);
  write_record(RecordKind::CallDisplayList, p, sizeof p, bytes, byte_size);
}

void TraceWriter::set_array(std::uint8_t attr, std::uint32_t guest_addr,
                            std::uint16_t stride) {
  std::uint8_t p[7];
  p[0] = attr;
  store_u32le(p + 1, guest_addr);
  store_u16le(p + 5, stride);
  write_record(RecordKind::SetArray, p, sizeof p);
}

void TraceWriter::mem_update(std::uint32_t guest_addr, const void* bytes,
                             std::uint32_t byte_size) {
  std::uint8_t p[8];
  store_u32le(p, guest_addr);
  store_u32le(p + 4, byte_size);
  write_record(RecordKind::MemUpdate, p, sizeof p, bytes, byte_size);
}

void TraceWriter::present_stats(const PresentStats& stats) {
  std::uint8_t p[40];
  const std::uint32_t fields[10] = {
      stats.frame_index,        stats.queued_pipelines,
      stats.created_pipelines,  stats.draw_call_count,
      stats.merged_draw_call_count, stats.last_vert_size,
      stats.last_uniform_size,  stats.last_index_size,
      stats.last_storage_size,  stats.last_texture_upload_size,
  };
  for (std::size_t i = 0; i < 10; ++i)
    store_u32le(p + i * 4, fields[i]);
  write_record(RecordKind::PresentStats, p, sizeof p);
}

bool TraceWriter::close() {
  if (!file_)
    return ok_;
  if (std::fflush(file_) != 0)
    ok_ = false;
  if (std::fclose(file_) != 0)
    ok_ = false;
  file_ = nullptr;
  return ok_;
}

bool TraceReader::open(const char* path) {
  std::FILE* f = std::fopen(path, "rb");
  if (!f)
    return false;
  std::vector<std::uint8_t> bytes;
  std::uint8_t buf[1 << 16];
  std::size_t n = 0;
  while ((n = std::fread(buf, 1, sizeof buf, f)) > 0)
    bytes.insert(bytes.end(), buf, buf + n);
  std::fclose(f);
  return open_bytes(std::move(bytes));
}

bool TraceReader::open_bytes(std::vector<std::uint8_t> bytes) {
  data_ = std::move(bytes);
  return parse_header();
}

bool TraceReader::parse_header() {
  pos_ = 0;
  truncated_ = false;
  records_ = 0;
  if (data_.size() < kHeaderSize)
    return false;
  if (load_u32le(data_.data()) != kMagic)
    return false;
  version_ = load_u32le(data_.data() + 4);
  if (version_ != kVersion)
    return false;
  std::memcpy(header_.game_id, data_.data() + 8, 8);
  header_.mem1_size = load_u32le(data_.data() + 16);
  header_.flags = load_u32le(data_.data() + 20);
  pos_ = kHeaderSize;
  return true;
}

bool TraceReader::next(RecordView& out) {
  if (pos_ >= data_.size())
    return false;
  if (data_.size() - pos_ < kRecordHeaderSize) {
    truncated_ = true;
    return false;
  }
  const std::uint8_t kind = data_[pos_];
  const std::uint32_t payload_size = load_u32le(data_.data() + pos_ + 1);
  if (data_.size() - pos_ - kRecordHeaderSize < payload_size) {
    truncated_ = true;
    return false;
  }
  out.kind = static_cast<RecordKind>(kind);
  out.payload = std::span<const std::uint8_t>(
      data_.data() + pos_ + kRecordHeaderSize, payload_size);
  pos_ += kRecordHeaderSize + payload_size;
  ++records_;
  return true;
}

void TraceReader::rewind() {
  pos_ = data_.empty() ? 0 : kHeaderSize;
  truncated_ = false;
  records_ = 0;
}

bool decode_frame_begin(const RecordView& r, std::uint32_t& frame_index) {
  if (r.kind != RecordKind::FrameBegin || r.payload.size() != 4)
    return false;
  frame_index = load_u32le(r.payload.data());
  return true;
}

bool decode_gx_write(const RecordView& r, std::uint8_t& size,
                     std::uint64_t& value) {
  if (r.kind != RecordKind::GxWrite || r.payload.size() != 9)
    return false;
  size = r.payload[0];
  value = load_u64le(r.payload.data() + 1);
  return true;
}

bool decode_call_display_list(const RecordView& r, std::uint32_t& guest_addr,
                              std::span<const std::uint8_t>& bytes) {
  if (r.kind != RecordKind::CallDisplayList || r.payload.size() < 8)
    return false;
  guest_addr = load_u32le(r.payload.data());
  const std::uint32_t byte_size = load_u32le(r.payload.data() + 4);
  if (r.payload.size() - 8 != byte_size)
    return false;
  bytes = r.payload.subspan(8);
  return true;
}

bool decode_set_array(const RecordView& r, std::uint8_t& attr,
                      std::uint32_t& guest_addr, std::uint16_t& stride) {
  if (r.kind != RecordKind::SetArray || r.payload.size() != 7)
    return false;
  attr = r.payload[0];
  guest_addr = load_u32le(r.payload.data() + 1);
  stride = load_u16le(r.payload.data() + 5);
  return true;
}

bool decode_mem_update(const RecordView& r, std::uint32_t& guest_addr,
                       std::span<const std::uint8_t>& bytes) {
  if (r.kind != RecordKind::MemUpdate || r.payload.size() < 8)
    return false;
  guest_addr = load_u32le(r.payload.data());
  const std::uint32_t byte_size = load_u32le(r.payload.data() + 4);
  if (r.payload.size() - 8 != byte_size)
    return false;
  bytes = r.payload.subspan(8);
  return true;
}

bool decode_present_stats(const RecordView& r, PresentStats& out) {
  if (r.kind != RecordKind::PresentStats || r.payload.size() != 40)
    return false;
  std::uint32_t fields[10];
  for (std::size_t i = 0; i < 10; ++i)
    fields[i] = load_u32le(r.payload.data() + i * 4);
  out.frame_index = fields[0];
  out.queued_pipelines = fields[1];
  out.created_pipelines = fields[2];
  out.draw_call_count = fields[3];
  out.merged_draw_call_count = fields[4];
  out.last_vert_size = fields[5];
  out.last_uniform_size = fields[6];
  out.last_index_size = fields[7];
  out.last_storage_size = fields[8];
  out.last_texture_upload_size = fields[9];
  return true;
}

} // namespace gxruntime::aurora_recomp::trace
