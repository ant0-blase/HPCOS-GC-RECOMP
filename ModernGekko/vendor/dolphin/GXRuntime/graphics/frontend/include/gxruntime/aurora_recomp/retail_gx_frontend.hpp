// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "gxruntime/aurora_recomp/render_sink.hpp"

#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

extern "C" {
#include "gxruntime/gx_recomp.h"
}

namespace gxruntime::aurora_recomp {

struct DrawTransformSnapshot {
  std::uint32_t transform_flags = 0;
  std::uint32_t current_pn_matrix = 0;
  std::uint32_t payload_pn_matrix_mask = 0;
  std::uint32_t position_matrix_valid_mask = 0;
  float viewport[6]{};
  float projection[6]{};
  std::uint32_t projection_type = 0;
  float position_matrices[DOL_GX_RECOMP_POSITION_MATRIX_COUNT]
                         [DOL_GX_RECOMP_POSITION_MATRIX_WORDS]{};
  float normal_matrices[DOL_GX_RECOMP_NORMAL_MATRIX_COUNT]
                       [DOL_GX_RECOMP_NORMAL_MATRIX_WORDS]{};
  std::uint16_t normal_matrix_word_mask[DOL_GX_RECOMP_NORMAL_MATRIX_COUNT]{};
  // XF lighting state at draw time (raw words; per-word validity in the
  // masks). Same layout as DolGxRecompState — see gx_recomp.h.
  std::uint32_t light_words[DOL_GX_RECOMP_LIGHT_COUNT]
                           [DOL_GX_RECOMP_LIGHT_WORDS]{};
  std::uint16_t light_word_mask[DOL_GX_RECOMP_LIGHT_COUNT]{};
  std::uint32_t chan_regs[DOL_GX_RECOMP_CHAN_REG_COUNT]{};
  std::uint32_t chan_reg_mask = 0;
  // Texture matrices + raw XF register window at draw time (gxcore
  // texgen inputs). Layouts match DolGxRecompState — see gx_recomp.h.
  float tex_matrices[DOL_GX_RECOMP_TEX_MATRIX_COUNT]
                    [DOL_GX_RECOMP_TEX_MATRIX_WORDS]{};
  std::uint16_t tex_matrix_word_mask[DOL_GX_RECOMP_TEX_MATRIX_COUNT]{};
  std::uint32_t xf_regs[DOL_GX_RECOMP_XF_REG_COUNT]{};
  std::uint64_t xf_reg_mask = 0;
};

class RetailGxFrontend {
public:
  RetailGxFrontend();
  explicit RetailGxFrontend(const DolGuestAddressResolver& resolver);

  void reset(const DolGuestAddressResolver* resolver = nullptr);

  bool set_vertex_layout(std::uint8_t vtx_fmt, std::uint32_t vertex_size);
  bool set_indexed_attr(std::uint8_t vtx_fmt, std::uint8_t attr,
                        std::uint32_t vertex_offset, std::uint8_t index_size,
                        std::uint32_t element_size,
                        std::uint32_t element_bias);
  bool derive_vertex_layout(std::uint8_t vtx_fmt);
  bool set_cp_array(std::uint8_t attr, std::uint32_t physical_base,
                    std::uint8_t stride);
  bool load_cp_reg(std::uint8_t reg, std::uint32_t value);
  void set_packet_drain_enabled(bool enabled);

  // Read-only tap on the decode event stream (histograms): invoked
  // for every trace event a successful flush/write_display_list/replay_fifo
  // produced, before drain reclaims the ring. Never affects decode.
  using TraceEventObserver = void (*)(const DolGxRecompTraceEvent& event,
                                      void* user);
  void set_event_observer(TraceEventObserver observer, void* user) {
    event_observer_ = observer;
    event_observer_user_ = user;
  }

  bool write_fifo(std::span<const std::uint8_t> bytes);
  bool flush(AuroraRenderSink* sink = nullptr);
  // Parse a display list from caller-provided bytes through the SAME internal
  // path as the in-stream 0x40 CALL_DL opcode, minus the guest resolution
  // (the bytes are already host-visible). Entry point for trace replay
  // (CALL_DL records) and the backend's DL mirror; keep it
  // byte-path-identical to the opcode branch.
  bool write_display_list(std::span<const std::uint8_t> bytes,
                          AuroraRenderSink* sink = nullptr);
  std::size_t pending_fifo_size() const { return fifo_buffer_.size(); }

  bool replay_fifo(std::span<const std::uint8_t> bytes,
                   AuroraRenderSink* sink = nullptr);

  const DolGxRecompState& state() const { return state_; }
  DolGxRecompState& state() { return state_; }

  std::span<const DolGxRecompTraceEvent> trace_events() const;
  // Cumulative zero-vertex draw headers consumed as no-ops (s56 conformance:
  // the frontend emits no Draw packet for them, but Aurora's live decoder
  // counts each unmerged one in drawCallCount). Replay adds this to its draw
  // count when gating against recorded PRESENT_STATS.
  std::uint64_t zero_vertex_draws() const { return zero_vertex_draws_; }
  const char* last_error() const { return last_error_; }
  std::size_t last_error_offset() const { return last_error_offset_; }
  std::uint8_t last_error_opcode() const { return last_error_opcode_; }
  std::uint32_t last_error_a() const { return last_error_a_; }
  std::uint32_t last_error_b() const { return last_error_b_; }
  std::uint32_t last_error_c() const { return last_error_c_; }
  std::uint32_t last_error_d() const { return last_error_d_; }

private:
  bool fail_parse(const char* reason, std::uint8_t opcode,
                  std::size_t offset, std::uint32_t a = 0,
                  std::uint32_t b = 0, std::uint32_t c = 0,
                  std::uint32_t d = 0);
  bool parse_stream(std::span<const std::uint8_t> bytes, bool allow_partial,
                    bool record_fifo_bytes, std::uint32_t depth,
                    std::size_t* consumed);
  bool handle_bp(std::uint32_t raw);
  bool maybe_resolve_texture(std::uint8_t slot);
  bool handle_copy_trigger(std::uint32_t value);
  bool handle_draw(std::uint8_t command,
                   std::span<const std::uint8_t> vertex_data,
                   std::uint16_t vertex_count,
                   std::size_t command_offset);
  bool emit_new_packets(AuroraRenderSink& sink, std::uint32_t first_event);
  void drain_emitted_packets(std::uint32_t emitted_count);

  DolGxRecompState state_{};
  std::vector<std::uint8_t> fifo_buffer_;
  // Raw per-vertex payload bytes for each parsed draw, in trace order. Popped in
  // lockstep as Draw events are emitted (emit_new_packets) so each Draw packet
  // references its own bytes; cleared on full drain/reset. Each element is its
  // own buffer, so the outer vector reallocating during parse does not move the
  // inner heap storage the emitted packets point at.
  std::vector<std::vector<std::uint8_t>> draw_payload_queue_;
  std::vector<DrawTransformSnapshot> draw_transform_queue_;
  std::size_t draw_payload_head_ = 0;
  std::size_t draw_transform_head_ = 0;
  void notify_events(std::uint32_t first_event);

  bool packet_drain_enabled_ = false;
  std::uint64_t zero_vertex_draws_ = 0;
  TraceEventObserver event_observer_ = nullptr;
  void* event_observer_user_ = nullptr;
  std::uint32_t emitted_trace_count_ = 0;
  std::uint32_t next_packet_sequence_ = 0;
  const char* last_error_ = nullptr;
  std::size_t last_error_offset_ = 0;
  std::uint8_t last_error_opcode_ = 0;
  std::uint32_t last_error_a_ = 0;
  std::uint32_t last_error_b_ = 0;
  std::uint32_t last_error_c_ = 0;
  std::uint32_t last_error_d_ = 0;
};

} // namespace gxruntime::aurora_recomp
