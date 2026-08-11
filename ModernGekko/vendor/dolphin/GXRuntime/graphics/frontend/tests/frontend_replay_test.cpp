// SPDX-License-Identifier: GPL-3.0-or-later
#ifdef NDEBUG
#undef NDEBUG
#endif
#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"
#include "gxruntime/aurora_recomp/retail_gx_frontend_c.h"

#include <cassert>
#include <cstdint>
#include <cstring>
#include <span>
#include <vector>

namespace {

using gxruntime::aurora_recomp::RecordingAuroraRenderSink;
using gxruntime::aurora_recomp::RenderPacketKind;
using gxruntime::aurora_recomp::RenderResourceKind;
using gxruntime::aurora_recomp::RenderStateKind;
using gxruntime::aurora_recomp::RenderStreamKind;
using gxruntime::aurora_recomp::RetailGxFrontend;

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

// Multi-word XF_LOAD: header encodes (count-1)<<16 | base, then `values` words.
void push_xf_block(std::vector<std::uint8_t>& fifo, std::uint16_t base,
                   const std::vector<std::uint32_t>& values) {
  push_u8(fifo, DOL_GX_CMD_LOAD_XF_REG);
  push_u32(fifo, (static_cast<std::uint32_t>(values.size() - 1u) << 16u) |
                     static_cast<std::uint32_t>(base));
  for (std::uint32_t v : values)
    push_u32(fifo, v);
}

std::uint32_t f32_bits(float f) {
  std::uint32_t bits;
  std::memcpy(&bits, &f, sizeof(bits));
  return bits;
}

std::uint32_t read_fixture_be32(const std::uint8_t* p) {
  return (static_cast<std::uint32_t>(p[0]) << 24u) |
         (static_cast<std::uint32_t>(p[1]) << 16u) |
         (static_cast<std::uint32_t>(p[2]) << 8u) |
         static_cast<std::uint32_t>(p[3]);
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

bool saw_packet(const RecordingAuroraRenderSink& sink,
                DolGxRecompEventKind kind) {
  for (const auto& packet : sink.packets()) {
    if (packet.event.kind == kind)
      return true;
  }
  return false;
}

bool saw_kind(const RecordingAuroraRenderSink& sink, RenderPacketKind kind) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == kind)
      return true;
  }
  return false;
}

bool saw_stream_packet(const RecordingAuroraRenderSink& sink,
                       RenderStreamKind kind) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::Stream && packet.stream.kind == kind)
      return true;
  }
  return false;
}

bool saw_state_packet(const RecordingAuroraRenderSink& sink,
                      RenderStateKind kind) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::State && packet.state.kind == kind)
      return true;
  }
  return false;
}

bool saw_resource_packet(const RecordingAuroraRenderSink& sink,
                         RenderResourceKind kind) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::Resource &&
        packet.resource.kind == kind)
      return true;
  }
  return false;
}

bool saw_texture_packet(const RecordingAuroraRenderSink& sink,
                        std::uint32_t slot, std::uint32_t address,
                        std::uint32_t size, std::uint32_t format) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::Resource &&
        packet.resource.kind == RenderResourceKind::Texture &&
        packet.resource.index == slot && packet.resource.address == address &&
        packet.resource.size == size && packet.resource.format == format)
      return true;
  }
  return false;
}

bool saw_draw_packet(const RecordingAuroraRenderSink& sink,
                     std::uint32_t primitive, std::uint32_t vtx_fmt,
                     std::uint32_t vertex_count,
                     std::uint32_t vertex_size) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::Draw &&
        packet.draw.primitive == primitive && packet.draw.vtx_fmt == vtx_fmt &&
        packet.draw.vertex_count == vertex_count &&
        packet.draw.vertex_size == vertex_size)
      return true;
  }
  return false;
}

bool saw_indexed_span_packet(const RecordingAuroraRenderSink& sink) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::Resource &&
        packet.resource.kind == RenderResourceKind::IndexedArraySpan &&
        packet.resource.index == 0u && packet.resource.size == 72u &&
        packet.resource.count == 3u && packet.resource.vtx_fmt == 0u)
      return true;
  }
  return false;
}

bool saw_indexed_xf_packet(const RecordingAuroraRenderSink& sink) {
  for (const auto& packet : sink.packets()) {
    if (packet.kind == RenderPacketKind::State &&
        packet.state.kind == RenderStateKind::IndexedXfLoad &&
        packet.state.index == 12u && packet.state.value == 1u &&
        packet.state.aux0 == 0u && packet.state.aux1 == 12u)
      return true;
  }
  return false;
}

struct CPacketRecorder {
  std::vector<DolAuroraRecompRenderPacket> packets;
};

bool record_c_packet(void* user, const DolAuroraRecompRenderPacket* packet) {
  assert(user != nullptr);
  assert(packet != nullptr);
  static_cast<CPacketRecorder*>(user)->packets.push_back(*packet);
  return true;
}

bool saw_c_packet(const CPacketRecorder& recorder, DolGxRecompEventKind kind) {
  for (const auto& packet : recorder.packets) {
    if (packet.event.kind == kind)
      return true;
  }
  return false;
}

bool saw_c_state_packet(const CPacketRecorder& recorder, std::uint32_t kind) {
  for (const auto& packet : recorder.packets) {
    if (packet.kind == DOL_AURORA_RECOMP_PACKET_STATE &&
        packet.state.kind == kind)
      return true;
  }
  return false;
}

void test_c_frontend_abi_byte_fragmentation() {
  CPUState cpu;
  assert(cpu_init(&cpu));

  DolGuestMemory memory;
  assert(dol_guest_memory_init(&memory, nullptr));

  DolGuestAddressResolver resolver;
  dol_guest_address_resolver_init(&resolver, &memory, &cpu);

  std::vector<std::uint8_t> fifo;
  push_cp(fifo, DOL_GX_CP_REG_VCD_LO, (1u << 0u) | (2u << 9u));
  push_cp(fifo, DOL_GX_CP_REG_VCD_HI, 0u);
  push_cp(fifo, DOL_GX_CP_REG_VAT_GRP0, (1u << 0u) | (4u << 1u));
  push_cp(fifo, DOL_GX_CP_REG_ARRAYBASE, 0x480u);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYSTRIDE, 12u);
  push_u8(fifo, DOL_GX_CMD_INVL_VC);
  push_bp(fifo, DOL_GX_BP_REG_GENMODE, 3u << 14u);
  push_xf(fifo, 0x1008u, 0xABCDEF01u);

  DolAuroraRecompRetailGxFrontend* frontend =
      dol_aurora_recomp_frontend_create(&resolver);
  assert(frontend != nullptr);

  CPacketRecorder recorder;
  for (std::uint8_t byte : fifo) {
    assert(dol_aurora_recomp_frontend_write_fifo(frontend, &byte, 1u));
    assert(dol_aurora_recomp_frontend_flush(frontend, record_c_packet,
                                            &recorder));
  }

  assert(dol_aurora_recomp_frontend_pending_fifo_size(frontend) == 0u);
  const DolGxRecompState* state =
      dol_aurora_recomp_frontend_state(frontend);
  assert(state != nullptr);
  assert(state->vcd_lo_valid);
  assert(state->vcd_hi_valid);
  assert(state->vertex_layouts[0].valid);
  assert(state->vertex_layouts[0].vertex_size == 2u);
  assert(state->vertex_layouts[0].indexed_attr_count == 1u);
  assert(state->vertex_layouts[0].indexed_attrs[0].attr == 0u);
  assert(state->vertex_layouts[0].indexed_attrs[0].vertex_offset == 1u);
  assert(state->vertex_layouts[0].indexed_attrs[0].index_size == 1u);
  assert(state->vertex_layouts[0].indexed_attrs[0].element_size == 12u);
  assert(state->arrays[0].base_valid);
  assert(state->arrays[0].physical_base == 0x480u);
  assert(state->arrays[0].stride_valid);
  assert(state->arrays[0].stride == 12u);
  assert(state->cull_all);
  assert(state->last_xf_base == 0x1008u);
  assert(state->last_xf_count == 1u);
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_CP_VCD));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_CP_VAT));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_CP_ARRAY_STRIDE));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_INVALIDATE_VTX_CACHE));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_CULL_ALL));
  assert(saw_c_packet(recorder, DOL_GX_RECOMP_EVENT_XF_LOAD));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_CP_VCD));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_CP_VAT));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_VERTEX_LAYOUT));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_CP_ARRAY_BASE));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_CP_ARRAY_STRIDE));
  assert(saw_c_state_packet(
      recorder, DOL_AURORA_RECOMP_STATE_INVALIDATE_VTX_CACHE));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_CULL_ALL));
  assert(saw_c_state_packet(recorder, DOL_AURORA_RECOMP_STATE_XF_LOAD));
  assert(std::strcmp(dol_aurora_recomp_trace_event_name(
                         DOL_GX_RECOMP_EVENT_CULL_ALL),
                     "cull-all") == 0);
  assert(std::strcmp(dol_aurora_recomp_trace_event_name(
                         DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT),
                     "vertex-layout") == 0);
  assert(std::strcmp(dol_aurora_recomp_trace_event_name(
                         DOL_GX_RECOMP_EVENT_INVALIDATE_VTX_CACHE),
                     "invalidate-vtx-cache") == 0);

  u32 trace_count = 0;
  const DolGxRecompTraceEvent* trace =
      dol_aurora_recomp_frontend_trace_events(frontend, &trace_count);
  assert(trace != nullptr);
  assert(trace_count == recorder.packets.size());
  for (std::size_t i = 0; i < recorder.packets.size(); ++i) {
    assert(recorder.packets[i].kind != DOL_AURORA_RECOMP_PACKET_TRACE_EVENT);
    assert(recorder.packets[i].sequence == i);
    assert(recorder.packets[i].event.kind == trace[i].kind);
  }
  assert(dol_aurora_recomp_frontend_derive_vertex_layout(frontend, 0u));

  dol_aurora_recomp_frontend_destroy(frontend);
  dol_guest_memory_shutdown(&memory);
  cpu_free(&cpu);
}

void test_c_frontend_guest_array_bridge() {
  CPUState cpu;
  assert(cpu_init(&cpu));

  DolGuestMemory memory;
  assert(dol_guest_memory_init(&memory, nullptr));

  DolGuestAddressResolver resolver;
  dol_guest_address_resolver_init(&resolver, &memory, &cpu);

  DolAuroraRecompRetailGxFrontend* frontend =
      dol_aurora_recomp_frontend_create(&resolver);
  assert(frontend != nullptr);
  assert(dol_aurora_recomp_frontend_set_cp_array(frontend, 2u, 0x180u, 24u));

  const DolGxRecompState* state =
      dol_aurora_recomp_frontend_state(frontend);
  assert(state != nullptr);
  assert(state->arrays[2].base_valid);
  assert(state->arrays[2].physical_base == 0x180u);
  assert(state->arrays[2].stride_valid);
  assert(state->arrays[2].stride == 24u);

  u32 trace_count = 0;
  const DolGxRecompTraceEvent* trace =
      dol_aurora_recomp_frontend_trace_events(frontend, &trace_count);
  assert(trace != nullptr);
  assert(trace_count == 2u);
  assert(trace[0].kind == DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE);
  assert(trace[0].a == 2u);
  assert(trace[0].b == 0x180u);
  assert(trace[1].kind == DOL_GX_RECOMP_EVENT_CP_ARRAY_STRIDE);
  assert(trace[1].a == 2u);
  assert(trace[1].b == 24u);

  dol_aurora_recomp_frontend_destroy(frontend);
  dol_guest_memory_shutdown(&memory);
  cpu_free(&cpu);
}

void test_fragmented_fifo_display_list_frontend() {
  CPUState cpu;
  assert(cpu_init(&cpu));

  DolGuestMemory memory;
  assert(dol_guest_memory_init(&memory, nullptr));

  DolGuestAddressResolver resolver;
  dol_guest_address_resolver_init(&resolver, &memory, &cpu);

  constexpr std::uint32_t dl_offset = 0x200u;
  constexpr std::uint32_t array_base = 0x480u;

  std::vector<std::uint8_t> display_list;
  push_cp(display_list, DOL_GX_CP_REG_ARRAYSTRIDE, 16u);
  while ((display_list.size() & 31u) != 0u)
    push_u8(display_list, 0u);
  std::memcpy(cpu.ram + dl_offset, display_list.data(), display_list.size());

  std::vector<std::uint8_t> cp_command;
  push_cp(cp_command, DOL_GX_CP_REG_ARRAYBASE, array_base);

  std::vector<std::uint8_t> call_command;
  push_call_dl(call_command, dl_offset,
               static_cast<std::uint32_t>(display_list.size()));

  RetailGxFrontend frontend(resolver);
  RecordingAuroraRenderSink sink;

  assert(frontend.write_fifo(
      std::span<const std::uint8_t>{cp_command.data(), 2u}));
  assert(frontend.flush(&sink));
  assert(frontend.pending_fifo_size() == 2u);
  assert(sink.packets().empty());

  assert(frontend.write_fifo(std::span<const std::uint8_t>{
      cp_command.data() + 2u, cp_command.size() - 2u}));
  assert(frontend.flush(&sink));
  assert(frontend.pending_fifo_size() == 0u);
  assert(frontend.state().arrays[0].base_valid);
  assert(frontend.state().arrays[0].physical_base == array_base);
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE));
  const auto packets_after_cp = sink.packets().size();

  assert(frontend.write_fifo(
      std::span<const std::uint8_t>{call_command.data(), 5u}));
  assert(frontend.flush(&sink));
  assert(frontend.pending_fifo_size() == 5u);
  assert(sink.packets().size() == packets_after_cp);

  assert(frontend.write_fifo(std::span<const std::uint8_t>{
      call_command.data() + 5u, call_command.size() - 5u}));
  assert(frontend.flush(&sink));
  assert(frontend.pending_fifo_size() == 0u);
  assert(frontend.state().arrays[0].stride_valid);
  assert(frontend.state().arrays[0].stride == 16u);
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_DISPLAY_LIST));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_CP_ARRAY_STRIDE));
  assert(dol_gx_recomp_fifo_size(&frontend.state()) ==
         cp_command.size() + call_command.size() + display_list.size());

  dol_guest_memory_shutdown(&memory);
  cpu_free(&cpu);
}

void test_fragmented_zero_vertex_draw_is_noop() {
  // Strikers writes the primitive opcode and the zero count separately. Match
  // that boundary exactly: the incomplete opcode remains pending, then the
  // complete header is consumed without needing a configured vertex layout.
  const std::uint8_t draw[] = {0x98u, 0x00u, 0x00u};
  RetailGxFrontend frontend;
  RecordingAuroraRenderSink sink;
  frontend.set_packet_drain_enabled(true);

  assert(frontend.write_fifo(
      std::span<const std::uint8_t>{draw, 1u}));
  assert(frontend.flush(&sink));
  assert(frontend.pending_fifo_size() == 1u);
  assert(!saw_packet(sink, DOL_GX_RECOMP_EVENT_DRAW));

  assert(frontend.write_fifo(
      std::span<const std::uint8_t>{draw + 1u, 2u}));
  assert(frontend.flush(&sink));
  assert(frontend.pending_fifo_size() == 0u);
  assert(frontend.last_error() == nullptr);
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_FIFO_BYTES));
  assert(!saw_packet(sink, DOL_GX_RECOMP_EVENT_DRAW));

  RetailGxFrontend replay_frontend;
  RecordingAuroraRenderSink replay_sink;
  assert(replay_frontend.replay_fifo(draw, &replay_sink));
  assert(replay_frontend.last_error() == nullptr);
  assert(!saw_packet(replay_sink, DOL_GX_RECOMP_EVENT_DRAW));
}

void test_unresolved_tlut_load_is_noop() {
  // Melee emits a LOAD_TLUT1 trigger with a zero line count in FIFO captures.
  // The BP write is real state, but it does not transfer TLUT bytes.
  std::vector<std::uint8_t> fifo;
  push_bp(fifo, DOL_GX_BP_REG_LOAD_TLUT1, 0u);

  RetailGxFrontend frontend;
  RecordingAuroraRenderSink sink;
  assert(frontend.replay_fifo(fifo, &sink));
  assert(frontend.last_error() == nullptr);
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_BP_REG));
  assert(!saw_packet(sink, DOL_GX_RECOMP_EVENT_TLUT));

  // Converted .dff captures can also start from a TMEM snapshot without the
  // paired LOAD_TLUT0 base register in the FIFO preamble. Keep decoding and
  // leave the TLUT resource absent until snapshot restore exists.
  fifo.clear();
  push_bp(fifo, DOL_GX_BP_REG_LOAD_TLUT1, 0x00010300u);
  RetailGxFrontend missing_base_frontend;
  RecordingAuroraRenderSink missing_base_sink;
  assert(missing_base_frontend.replay_fifo(fifo, &missing_base_sink));
  assert(missing_base_frontend.last_error() == nullptr);
  assert(saw_packet(missing_base_sink, DOL_GX_RECOMP_EVENT_BP_REG));
  assert(!saw_packet(missing_base_sink, DOL_GX_RECOMP_EVENT_TLUT));

  fifo.clear();
  push_bp(fifo, DOL_GX_BP_REG_LOAD_TLUT0, 0x00020000u);
  push_bp(fifo, DOL_GX_BP_REG_LOAD_TLUT1, 0x00010300u);
  RetailGxFrontend unresolved_source_frontend;
  RecordingAuroraRenderSink unresolved_source_sink;
  assert(unresolved_source_frontend.replay_fifo(fifo, &unresolved_source_sink));
  assert(unresolved_source_frontend.last_error() == nullptr);
  assert(saw_packet(unresolved_source_sink, DOL_GX_RECOMP_EVENT_BP_REG));
  assert(!saw_packet(unresolved_source_sink, DOL_GX_RECOMP_EVENT_TLUT));
}

// The XF projection register (XF 0x1020) is decoded from a direct XF_LOAD that
// covers it, so the recomp's projection transform is inspectable for the
// Dolphin-vs-recomp transform diff. A wrong/degenerate projection puts geometry
// off-screen — the cheapest discriminator for the missing-geometry scene.
void test_xf_projection_capture() {
  DolGxRecompState gx;
  dol_gx_recomp_init(&gx, nullptr);
  assert(!gx.projection_valid);

  // A non-covering XF load (matrix-memory region) must not touch projection.
  std::vector<std::uint8_t> other;
  push_xf(other, 0x0008u, 0x11223344u);
  assert(dol_gx_recomp_replay_fifo(&gx, other.data(),
                                   static_cast<std::uint32_t>(other.size())));
  assert(!gx.projection_valid);

  // A full position-matrix XF memory load captures PN matrix slot 0.
  const float pos_mtx[12] = {1.0f, 0.0f, 0.0f, 10.0f, 0.0f, 1.0f,
                             0.0f, 20.0f, 0.0f, 0.0f, 1.0f, 30.0f};
  std::vector<std::uint32_t> pos_words;
  for (float f : pos_mtx)
    pos_words.push_back(f32_bits(f));
  std::vector<std::uint8_t> pos_fifo;
  push_xf_block(pos_fifo, 0x0000u, pos_words);
  assert(dol_gx_recomp_replay_fifo(&gx, pos_fifo.data(),
                                   static_cast<std::uint32_t>(pos_fifo.size())));
  assert(gx.position_matrix_valid[0]);
  assert(gx.position_matrix_word_mask[0] == 0x0FFFu);
  for (int i = 0; i < 12; ++i)
    assert(gx.position_matrices[0][i] == pos_mtx[i]);

  // Matrix-index A stores GX_PNMTX ids in units of 3; Aurora uses id/3.
  std::vector<std::uint8_t> index_fifo;
  push_xf(index_fifo, DOL_GX_XF_MATRIX_INDEX_A, 6u);
  assert(dol_gx_recomp_replay_fifo(
      &gx, index_fifo.data(), static_cast<std::uint32_t>(index_fifo.size())));
  assert(gx.current_pn_matrix == 2u);

  // A 7-word load at 0x1020 covers the 6 projection params + the type word.
  const float params[6] = {1.5f, -2.25f, 0.0f, 480.0f, -1.0f, 0.03125f};
  std::vector<std::uint32_t> words;
  for (float p : params)
    words.push_back(f32_bits(p));
  words.push_back(1u); // projection type (perspective=0/orthographic=1 region)
  std::vector<std::uint8_t> fifo;
  push_xf_block(fifo, DOL_GX_XF_PROJECTION_BASE, words);
  assert(dol_gx_recomp_replay_fifo(&gx, fifo.data(),
                                   static_cast<std::uint32_t>(fifo.size())));
  assert(gx.projection_valid);
  for (int i = 0; i < 6; ++i)
    assert(gx.projection[i] == params[i]);
  assert(gx.projection_type == 1u);
  assert(!gx.viewport_valid); // a projection-only load must not set viewport

  // A 6-word load at 0x101A captures the viewport (wd/ht/zrange/xorig/yorig/farz).
  const float vp[6] = {320.0f, -240.0f, 16777215.0f, 342.0f, 342.0f, 16777215.0f};
  std::vector<std::uint32_t> vp_words;
  for (float v : vp)
    vp_words.push_back(f32_bits(v));
  std::vector<std::uint8_t> vp_fifo;
  push_xf_block(vp_fifo, DOL_GX_XF_VIEWPORT_BASE, vp_words);
  assert(dol_gx_recomp_replay_fifo(&gx, vp_fifo.data(),
                                   static_cast<std::uint32_t>(vp_fifo.size())));
  assert(gx.viewport_valid);
  for (int i = 0; i < 6; ++i)
    assert(gx.viewport[i] == vp[i]);

  // A single combined load spanning 0x101A..0x1026 captures both at once.
  DolGxRecompState both;
  dol_gx_recomp_init(&both, nullptr);
  std::vector<std::uint32_t> all;
  for (float v : vp)
    all.push_back(f32_bits(v));
  for (float p : params)
    all.push_back(f32_bits(p));
  all.push_back(1u);
  std::vector<std::uint8_t> all_fifo;
  push_xf_block(all_fifo, DOL_GX_XF_VIEWPORT_BASE, all);
  assert(dol_gx_recomp_replay_fifo(&both, all_fifo.data(),
                                   static_cast<std::uint32_t>(all_fifo.size())));
  assert(both.viewport_valid && both.projection_valid);
  assert(both.viewport[0] == vp[0] && both.projection[3] == params[3]);
  assert(both.projection_type == 1u);
}

} // namespace

int main() {
  test_c_frontend_abi_byte_fragmentation();
  test_c_frontend_guest_array_bridge();
  test_fragmented_fifo_display_list_frontend();
  test_fragmented_zero_vertex_draw_is_noop();
  test_unresolved_tlut_load_is_noop();
  test_xf_projection_capture();

  CPUState cpu;
  assert(cpu_init(&cpu));

  DolGuestMemory memory;
  assert(dol_guest_memory_init(&memory, nullptr));

  DolGuestAddressResolver resolver;
  dol_guest_address_resolver_init(&resolver, &memory, &cpu);

  constexpr std::uint32_t dl_offset = 0x200u;
  constexpr std::uint32_t array_base = 0x400u;
  constexpr std::uint32_t xf_array_base = 0x600u;
  constexpr std::uint32_t texture_base = 0x800u;
  constexpr std::uint32_t tlut_base = 0x1000u;
  constexpr std::uint32_t copy_base = 0x1200u;
  for (std::uint32_t i = 0; i < 256u; ++i) {
    cpu.ram[array_base + i] = static_cast<std::uint8_t>(0x10u + i);
    cpu.ram[xf_array_base + i] = static_cast<std::uint8_t>(0x80u + i);
    cpu.ram[texture_base + i] = static_cast<std::uint8_t>(0x40u + i);
    cpu.ram[tlut_base + i] = static_cast<std::uint8_t>(0x20u + i);
    cpu.ram[copy_base + i] = static_cast<std::uint8_t>(0x60u + i);
  }

  std::vector<std::uint8_t> display_list;
  push_bp(display_list, DOL_GX_BP_REG_GENMODE, 3u << 14u);
  push_bp(display_list, DOL_GX_BP_REG_LOAD_TLUT0, tlut_base >> 5u);
  push_bp(display_list, DOL_GX_BP_REG_LOAD_TLUT1, 0x20u | (1u << 10u));
  push_bp(display_list, DOL_GX_BP_REG_TX_SETTLUT + 1u,
          0x20u | (1u << 10u));
  push_bp(display_list, DOL_GX_BP_REG_TX_SETIMAGE0 + 1u,
          tex_image0(16u, 8u, 1u));
  push_bp(display_list, DOL_GX_BP_REG_TX_SETIMAGE3 + 1u,
          texture_base >> 5u);
  push_bp(display_list, DOL_GX_BP_REG_EFB_TL, 0u);
  push_bp(display_list, DOL_GX_BP_REG_EFB_WH, (7u << 10u) | 7u);
  push_bp(display_list, DOL_GX_BP_REG_EFB_ADDR, copy_base >> 5u);
  push_bp(display_list, DOL_GX_BP_REG_TRIGGER_EFB_COPY, 2u << 3u);
  // Faithful copy-format reconstruction (PROGRAM 64/A): target 14 is the
  // GX_CTF_A8 channel-select grab (Strikers glx_ShadowTextureGrab), and the
  // same trigger with PE_CONTROL pixel format Z24 becomes a depth-source copy.
  push_bp(display_list, DOL_GX_BP_REG_TRIGGER_EFB_COPY, 14u << 3u);
  push_bp(display_list, DOL_GX_BP_REG_PE_CONTROL, 0x3u);
  push_bp(display_list, DOL_GX_BP_REG_TRIGGER_EFB_COPY, 12u << 3u);
  push_u8(display_list, DOL_GX_CMD_INVL_VC);
  push_xf(display_list, 0x1008u, 0x12345678u);
  push_indexed_xf(display_list, 0x20u, 1u, 0x0000u, 12u);
  push_draw_indexed_fixture(display_list, 0x80u);
  while ((display_list.size() & 31u) != 0u)
    push_u8(display_list, 0u);

  std::memcpy(cpu.ram + dl_offset, display_list.data(), display_list.size());

  std::vector<std::uint8_t> fifo;
  push_cp(fifo, DOL_GX_CP_REG_VCD_LO, (1u << 0u) | (2u << 9u));
  push_cp(fifo, DOL_GX_CP_REG_VCD_HI, 0u);
  push_cp(fifo, DOL_GX_CP_REG_VAT_GRP0, (1u << 0u) | (4u << 1u));
  push_cp(fifo, DOL_GX_CP_REG_ARRAYBASE, array_base);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYSTRIDE, 12u);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYBASE + 12u, xf_array_base);
  push_cp(fifo, DOL_GX_CP_REG_ARRAYSTRIDE + 12u, 48u);
  push_call_dl(fifo, dl_offset,
               static_cast<std::uint32_t>(display_list.size()));

  RetailGxFrontend frontend(resolver);

  RecordingAuroraRenderSink sink;
  assert(frontend.replay_fifo(fifo, &sink));

  const auto& state = frontend.state();
  assert(state.vertex_layouts[0].valid);
  assert(state.vertex_layouts[0].vertex_size == 2u);
  assert(state.vertex_layouts[0].indexed_attr_count == 1u);
  assert(state.vertex_layouts[0].indexed_attrs[0].attr == 0u);
  assert(state.vertex_layouts[0].indexed_attrs[0].vertex_offset == 1u);
  assert(state.vertex_layouts[0].indexed_attrs[0].index_size == 1u);
  assert(state.vertex_layouts[0].indexed_attrs[0].element_size == 12u);
  assert(state.cull_all);
  assert(state.textures[1].valid);
  assert(state.textures[1].physical_base == texture_base);
  assert(state.textures[1].byte_size == 128u);
  assert(state.textures[1].range.data == cpu.ram + texture_base);
  assert(state.tmem_tluts[0x20u].valid);
  assert(state.tmem_tluts[0x20u].range.data == cpu.ram + tlut_base);
  assert(state.copy.range_valid);
  assert(state.copy.range.data == cpu.ram + copy_base);
  assert(state.last_xf_base == 0x0000u);
  assert(state.last_xf_count == 12u);
  assert(state.position_matrix_valid[0]);
  assert((state.position_matrix_word_mask[0] & 0x0FFFu) == 0x0FFFu);
  for (std::size_t i = 0; i < DOL_GX_RECOMP_POSITION_MATRIX_WORDS; ++i) {
    assert(f32_bits(state.position_matrices[0][i]) ==
           read_fixture_be32(cpu.ram + xf_array_base + 48u + i * 4u));
  }

  const auto trace = frontend.trace_events();
  assert(!trace.empty());
  {
    // Copy formats reconstructed from the three triggers: target 2 ->
    // GX_CTF_R8 (0x28), target 14 -> GX_CTF_A8 (0x27, EFB alpha channel),
    // target 12 under PE_CONTROL Z24 -> GX_TF_Z24X8 (0x16, depth source).
    std::vector<std::uint32_t> copy_formats;
    for (const auto& ev : trace)
      if (ev.kind == DOL_GX_RECOMP_EVENT_COPY_DESTINATION)
        copy_formats.push_back(ev.c);
    assert(copy_formats.size() == 3u);
    assert(copy_formats[0] == 0x28u);
    assert(copy_formats[1] == 0x27u);
    assert(copy_formats[2] == 0x16u);
    assert(state.copy.is_depth);
  }
  assert(sink.packets().size() == trace.size());
  assert(saw_kind(sink, RenderPacketKind::Stream));
  assert(saw_kind(sink, RenderPacketKind::State));
  assert(saw_kind(sink, RenderPacketKind::Resource));
  assert(saw_kind(sink, RenderPacketKind::Draw));
  assert(saw_stream_packet(sink, RenderStreamKind::FifoBytes));
  assert(saw_stream_packet(sink, RenderStreamKind::DisplayList));
  assert(saw_state_packet(sink, RenderStateKind::CpVcd));
  assert(saw_state_packet(sink, RenderStateKind::CpVat));
  assert(saw_state_packet(sink, RenderStateKind::VertexLayout));
  assert(saw_state_packet(sink, RenderStateKind::CpArrayBase));
  assert(saw_state_packet(sink, RenderStateKind::CpArrayStride));
  assert(saw_state_packet(sink, RenderStateKind::BpReg));
  assert(saw_state_packet(sink, RenderStateKind::XfLoad));
  assert(saw_state_packet(sink, RenderStateKind::CullAll));
  assert(saw_state_packet(sink, RenderStateKind::InvalidateVtxCache));
  assert(saw_resource_packet(sink, RenderResourceKind::Tlut));
  assert(saw_resource_packet(sink, RenderResourceKind::CopyDestination));
  assert(saw_texture_packet(sink, 1u, texture_base, 128u, 1u));
  assert(saw_draw_packet(sink, 0x80u, 0u, 3u, 2u));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_DISPLAY_LIST));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_FIFO_BYTES));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_CP_VCD));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_CP_VAT));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_TEXTURE));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_TLUT));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_COPY_DESTINATION));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_CULL_ALL));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_INVALIDATE_VTX_CACHE));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_XF_LOAD));
  assert(saw_packet(sink, DOL_GX_RECOMP_EVENT_DRAW));
  assert(saw_indexed_span_packet(sink));
  assert(saw_indexed_xf_packet(sink));

  // Replay the same FIFO through a consuming sink and assert it reconstructs
  // the renderer-facing draw model a live Aurora sink would translate.
  {
    using gxruntime::aurora_recomp::ConsumedArrayInput;
    using gxruntime::aurora_recomp::ConsumedDraw;
    using gxruntime::aurora_recomp::ConsumingAuroraRenderSink;

    RetailGxFrontend consume_frontend(resolver);
    ConsumingAuroraRenderSink consume_sink;
    consume_sink.set_guest_resolver(&resolver);
    assert(consume_frontend.replay_fifo(fifo, &consume_sink));
    assert(consume_sink.failure_reason() == nullptr);

    // CP arrays 0 (FIFO) and 12 (FIFO +12 reg) were both given base+stride.
    assert(consume_sink.array(0u).base_valid);
    assert(consume_sink.array(0u).base == array_base);
    assert(consume_sink.array(0u).stride_valid);
    assert(consume_sink.array(0u).stride == 12u);
    assert(consume_sink.array(12u).base_valid);
    assert(consume_sink.array(12u).base == xf_array_base);
    assert(consume_sink.array(12u).stride == 48u);

    // genMode cull==3 inside the display list set cull-all before the draw.
    assert(consume_sink.cull_all());
    assert(consume_sink.bound_texture().valid);
    assert(consume_sink.bound_texture().slot == 1u);
    assert(consume_sink.bound_texture().address == texture_base);
    assert(consume_sink.bound_texture().size == 128u);

    assert(consume_sink.texture_count() == 1u);
    assert(consume_sink.copy_count() == 3u); // R8 + A8 + Z24X8 triggers
    assert(consume_sink.indexed_span_count() == 1u);
    assert(consume_sink.tlut_count() >= 1u);

    assert(consume_sink.draws().size() == 1u);
    const ConsumedDraw& d = consume_sink.draws().front();
    assert(d.primitive == 0x80u);
    assert(d.vtx_fmt == 0u);
    assert(d.vertex_count == 3u);
    assert(d.vertex_size == 2u);
    assert(d.cull_all);
    assert((d.active_array_mask & (1u << 0u)) != 0u);
    assert((d.active_array_mask & (1u << 12u)) != 0u);
    assert(d.texture.valid);
    assert(d.texture.slot == 1u);
    assert(d.texture.address == texture_base);

    // Texture bytes resolved to host memory through the guest resolver.
    assert(d.texture.resolved);
    assert(d.texture.host_data ==
           static_cast<const void*>(cpu.ram + texture_base));

    // Only the INDEXED attr (0) is actually read from a CP array, so it is the
    // draw's lone resolved array input (frontend span = 72 bytes). Array 12 is
    // bound (see active_array_mask above) but the VCD does not index it, so it
    // is not a draw input.
    assert(d.array_input_count == 1u);
    assert(consume_sink.resolved_array_inputs() == 1u);
    assert(consume_sink.unresolved_array_inputs() == 0u);

    const ConsumedArrayInput& a0 = d.arrays[0];
    assert(a0.attr == 0u);
    assert(a0.indexed);
    assert(a0.span_size == 72u);
    assert(a0.resolved);
    assert(a0.host_data == static_cast<const void*>(cpu.ram + array_base));

    // draw_packets() is the cumulative DRAW count, not draws_.size().
    assert(consume_sink.draw_packets() == 1u);
    // vertex_inputs() is the cumulative sum of vertex_count across draws; the
    // backend pairs it with draw_packets() to diff per-frame draw/vertex
    // deltas against Aurora's live drawCallCount before renderer cutover.
    assert(consume_sink.vertex_inputs() == 3u);

    // The draw's raw per-vertex payload (vertex_count * vertex_size = 3*2) is
    // carried through the packet and retained on the ConsumedDraw, so an issuing
    // sink can assemble vertices. It must byte-match push_draw_indexed_fixture's
    // inline vertex bytes.
    assert(d.vertex_payload.size() == 6u);
    assert(consume_sink.payload_bytes() == 6u);
    {
      const std::uint8_t expected_payload[] = {0x00, 0x02, 0x03,
                                               0x05, 0x06, 0x01};
      assert(std::memcmp(d.vertex_payload.data(), expected_payload, 6u) == 0);
    }

    // The draw snapshots transform state at draw time. The indexed-XF load in
    // the display list populated PN matrix 0 from CP array 12, index 1.
    assert(d.current_pn_matrix == 0u);
    assert((d.transform_flags &
            gxruntime::aurora_recomp::kDrawTransformPayloadPnMatrixValid) !=
           0u);
    assert(d.payload_pn_matrix_mask == 0x7u);
    assert((d.position_matrix_valid_mask & 1u) != 0u);
    for (std::size_t i = 0; i < DOL_GX_RECOMP_POSITION_MATRIX_WORDS; ++i) {
      assert(f32_bits(d.position_matrices[0][i]) ==
             read_fixture_be32(cpu.ram + xf_array_base + 48u + i * 4u));
    }

    // Assemble the draw: decode each vertex's index from the payload (offset 1
    // within the 2-byte stride -> {0x02, 0x05, 0x01}) and resolve element_size
    // (12) bytes at array_base + index*stride(12). This is the per-vertex data a
    // live Aurora draw consumes for the indexed attribute.
    {
      using gxruntime::aurora_recomp::AssembledDrawStats;
      using gxruntime::aurora_recomp::AssembledElement;
      std::vector<AssembledElement> elements;
      const AssembledDrawStats stats =
          gxruntime::aurora_recomp::assemble_consumed_draw(d, &elements);
      assert(stats.ok);
      assert(stats.indexed_attr_count == 1u);
      assert(stats.element_reads == 3u);
      assert(stats.failed_reads == 0u);
      // Geometry byte extents: 3 indices × 1 byte, 3 elements × 12 bytes.
      assert(stats.index_bytes == 3u);
      assert(stats.element_bytes == 36u);
      assert(elements.size() == 3u);
      assert(elements[0].attr == 0u && elements[1].attr == 0u &&
             elements[2].attr == 0u);
      assert(elements[0].index == 2u);
      assert(elements[1].index == 5u);
      assert(elements[2].index == 1u);
      assert(elements[0].element_size == 12u);
      // Element host pointers land at array_base + index*stride in guest RAM.
      assert(elements[0].host_element ==
             cpu.ram + array_base + 2u * 12u);
      assert(elements[1].host_element ==
             cpu.ram + array_base + 5u * 12u);
      assert(elements[2].host_element ==
             cpu.ram + array_base + 1u * 12u);
    }

    // Topology index buffer mirrors Aurora's prepare_idx_buffer: a quad becomes
    // two triangles {0,1,2}{2,3,0}; a triangle list is identity.
    {
      using gxruntime::aurora_recomp::build_topology_indices;
      using gxruntime::aurora_recomp::GxPrimitive;
      std::vector<std::uint16_t> idx;
      const std::uint32_t n =
          build_topology_indices(GxPrimitive::Quads, 0u, 4u, &idx);
      assert(n == 6u && idx.size() == 6u);
      const std::uint16_t expect_quad[] = {0, 1, 2, 2, 3, 0};
      for (std::size_t i = 0; i < 6u; ++i)
        assert(idx[i] == expect_quad[i]);

      idx.clear();
      const std::uint32_t n3 =
          build_topology_indices(GxPrimitive::Triangles, 0u, 3u, &idx);
      assert(n3 == 3u && idx.size() == 3u);
      assert(idx[0] == 0u && idx[1] == 1u && idx[2] == 2u);

      // Count-only (out == nullptr) must agree.
      assert(build_topology_indices(GxPrimitive::Quads, 0u, 8u, nullptr) == 12u);
      // Lines/points have no triangle topology.
      assert(build_topology_indices(GxPrimitive::Lines, 0u, 4u, nullptr) == 0u);
    }

    // arraySizes for the cutover draw map directly from the resolved spans: the
    // single indexed attr (0) has span 72, all others zero.
    {
      using gxruntime::aurora_recomp::build_array_sizes;
      std::uint32_t array_sizes[16] = {0};
      const std::uint32_t nz = build_array_sizes(d, array_sizes, 16u);
      assert(nz == 1u);
      assert(array_sizes[0] == 72u);
      for (std::size_t i = 1; i < 16u; ++i)
        assert(array_sizes[i] == 0u);
    }

    // The live consumer accumulates the same draw-input byte extents an issued
    // draw would submit, via the cutover builders, when a draw is assembled.
    // flush_assembly() folds the frame's final draw. For this Quads/3-vertex
    // fixture: raw verts = 6 (3×2), topology indices = 0 (a quad needs 4 verts
    // so no complete primitive), storage = the single indexed span (72). These
    // are what the backend diffs against Aurora lastVertSize/Index/Storage.
    consume_sink.flush_assembly();
    assert(consume_sink.raw_vertex_bytes() == 6u);
    assert(consume_sink.topology_index_bytes() == 0u);
    assert(consume_sink.storage_bytes() == 72u);

    // Streaming mode keeps only the latest draw, but the cumulative count must
    // still reflect every DRAW packet (the bug: draw_packets()==draws_.size()).
    RetailGxFrontend stream_frontend(resolver);
    ConsumingAuroraRenderSink stream_sink;
    stream_sink.set_guest_resolver(&resolver);
    stream_sink.set_streaming(true);
    assert(stream_frontend.replay_fifo(fifo, &stream_sink));
    assert(stream_sink.failure_reason() == nullptr);
    assert(stream_sink.draws().size() <= 1u);
    assert(stream_sink.draw_packets() == 1u);
    // Cumulative vertex count survives the streaming draw-window clamp.
    assert(stream_sink.vertex_inputs() == 3u);
    assert(stream_sink.resolved_array_inputs() == 1u);
    // The single draw is the frame's last, so flush_assembly() folds it in:
    // 1 draw assembled, 0 failures, 3 indexed elements resolved.
    stream_sink.flush_assembly();
    assert(stream_sink.assembled_draws() == 1u);
    assert(stream_sink.assemble_failed_draws() == 0u);
    assert(stream_sink.assembled_elements() == 3u);
  }

  dol_guest_memory_shutdown(&memory);
  cpu_free(&cpu);
  return 0;
}
