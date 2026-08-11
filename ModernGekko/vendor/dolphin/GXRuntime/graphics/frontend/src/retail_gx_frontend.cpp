// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"
#include "gxruntime/aurora_recomp/retail_gx_frontend_c.h"

#include <cstring>
#include <new>

namespace gxruntime::aurora_recomp {

namespace {

class CallbackRenderSink final : public AuroraRenderSink {
public:
  CallbackRenderSink(DolAuroraRecompRenderPacketFn submit, void* user)
      : submit_(submit), user_(user) {}

  bool submit_packet(const RenderPacket& packet) override {
    if (submit_ == nullptr)
      return true;
    DolAuroraRecompRenderPacket c_packet{
        .kind = static_cast<std::uint32_t>(packet.kind),
        .sequence = packet.sequence,
        .event = packet.event,
        .stream = {
            .kind = static_cast<std::uint32_t>(packet.stream.kind),
            .address = packet.stream.address,
            .size = packet.stream.size,
            .address_space = packet.stream.address_space,
            .total_size = packet.stream.total_size,
        },
        .state = {
            .kind = static_cast<std::uint32_t>(packet.state.kind),
            .index = packet.state.index,
            .value = packet.state.value,
            .aux0 = packet.state.aux0,
            .aux1 = packet.state.aux1,
        },
        .resource = {
            .kind = static_cast<std::uint32_t>(packet.resource.kind),
            .index = packet.resource.index,
            .address = packet.resource.address,
            .size = packet.resource.size,
            .format = packet.resource.format,
            .count = packet.resource.count,
            .vtx_fmt = packet.resource.vtx_fmt,
            .vertex_offset = packet.resource.vertex_offset,
            .index_size = packet.resource.index_size,
            .element_size = packet.resource.element_size,
        },
        .draw = {
            .primitive = packet.draw.primitive,
            .vtx_fmt = packet.draw.vtx_fmt,
            .vertex_count = packet.draw.vertex_count,
            .vertex_size = packet.draw.vertex_size,
            .vertex_payload = packet.draw.vertex_payload,
            .vertex_payload_size = packet.draw.vertex_payload_size,
            .transform_flags = packet.draw.transform_flags,
            .current_pn_matrix = packet.draw.current_pn_matrix,
            .payload_pn_matrix_mask = packet.draw.payload_pn_matrix_mask,
            .position_matrix_valid_mask =
                packet.draw.position_matrix_valid_mask,
            .viewport = {},
            .projection = {},
            .projection_type = packet.draw.projection_type,
            .position_matrices = {},
        },
    };
    std::memcpy(c_packet.draw.viewport, packet.draw.viewport,
                sizeof(c_packet.draw.viewport));
    std::memcpy(c_packet.draw.projection, packet.draw.projection,
                sizeof(c_packet.draw.projection));
    std::memcpy(c_packet.draw.position_matrices, packet.draw.position_matrices,
                sizeof(c_packet.draw.position_matrices));
    return submit_(user_, &c_packet);
  }

private:
  DolAuroraRecompRenderPacketFn submit_;
  void* user_;
};

std::uint32_t read_be32(std::span<const std::uint8_t> bytes,
                        std::size_t offset) {
  return (static_cast<std::uint32_t>(bytes[offset]) << 24u) |
         (static_cast<std::uint32_t>(bytes[offset + 1u]) << 16u) |
         (static_cast<std::uint32_t>(bytes[offset + 2u]) << 8u) |
         static_cast<std::uint32_t>(bytes[offset + 3u]);
}

std::uint16_t read_be16(std::span<const std::uint8_t> bytes,
                        std::size_t offset) {
  return static_cast<std::uint16_t>(
      (static_cast<std::uint16_t>(bytes[offset]) << 8u) | bytes[offset + 1u]);
}

std::uint32_t bp_get(std::uint32_t value, std::uint32_t size,
                     std::uint32_t shift) {
  return (value >> shift) & ((1u << size) - 1u);
}

bool is_draw_opcode(std::uint8_t opcode) {
  switch (opcode & 0xF8u) {
  case 0x80u:
  case 0x90u:
  case 0x98u:
  case 0xA0u:
  case 0xA8u:
  case 0xB0u:
  case 0xB8u:
    return true;
  default:
    return false;
  }
}

std::uint8_t image0_reg_for_slot(std::uint8_t slot) {
  return slot < 4u ? static_cast<std::uint8_t>(DOL_GX_BP_REG_TX_SETIMAGE0 + slot)
                   : static_cast<std::uint8_t>(
                         DOL_GX_BP_REG_TX_SETIMAGE0_4 + slot - 4u);
}

std::uint8_t image3_reg_for_slot(std::uint8_t slot) {
  return slot < 4u ? static_cast<std::uint8_t>(DOL_GX_BP_REG_TX_SETIMAGE3 + slot)
                   : static_cast<std::uint8_t>(
                         DOL_GX_BP_REG_TX_SETIMAGE3_4 + slot - 4u);
}

bool map_image_reg(std::uint8_t reg, std::uint8_t first,
                   std::uint8_t second, std::uint8_t* slot) {
  if (slot == nullptr)
    return false;
  if (reg >= first && reg < first + 4u) {
    *slot = static_cast<std::uint8_t>(reg - first);
    return true;
  }
  if (reg >= second && reg < second + 4u) {
    *slot = static_cast<std::uint8_t>(4u + reg - second);
    return true;
  }
  return false;
}

bool map_image0_reg(std::uint8_t reg, std::uint8_t* slot) {
  return map_image_reg(reg, DOL_GX_BP_REG_TX_SETIMAGE0,
                       DOL_GX_BP_REG_TX_SETIMAGE0_4, slot);
}

bool map_image3_reg(std::uint8_t reg, std::uint8_t* slot) {
  return map_image_reg(reg, DOL_GX_BP_REG_TX_SETIMAGE3,
                       DOL_GX_BP_REG_TX_SETIMAGE3_4, slot);
}

bool map_tlut_reg(std::uint8_t reg, std::uint8_t* slot) {
  return map_image_reg(reg, DOL_GX_BP_REG_TX_SETTLUT,
                       DOL_GX_BP_REG_TX_SETTLUT_4, slot);
}

std::uint32_t texture_physical_base(std::uint32_t image_or_tlut) {
  return (image_or_tlut & 0x00FFFFFFu) << 5u;
}

// Reconstruct the true GX copy texture format from a BP 0x52 copy trigger.
// Dolphin BPMemory.h UPE_Copy: hardware target = bits 3-6, intensity = bit 15;
// tp_realFormat() maps target -> the GX format low nibble (EFBCopyFormat):
// real = target/2 + (target&1)*8. The copy reads DEPTH instead of color when
// the EFB pixel format (PE_CONTROL @ BP 0x43, bits 0-2) is Z24 at trigger time
// (Dolphin BPStructs.cpp: is_depth_copy) — the returned GXTexFmt then carries
// the Z bit (0x10) so the resolve samples the depth buffer. Channel-select
// copy formats carry the CTF bit (0x20); they were previously collapsed to
// I8/IA8, which turned e.g. Strikers' GX_CTF_A8 player-shadow grabs
// (smstrikers-decomp NL/glx/glxTarget.cpp glx_ShadowTextureGrab, target 14)
// into intensity-of-RGB instead of the EFB alpha channel.
std::uint32_t copy_trigger_texture_format(std::uint32_t value, bool is_depth) {
  const std::uint32_t target = bp_get(value, 4u, 3u);
  const std::uint32_t real = target / 2u + (target & 1u) * 8u;
  const bool intensity = bp_get(value, 1u, 15u) != 0u;

  if (is_depth) {
    switch (real) {
    case 0x0:
      return 0x30; // GX_CTF_Z4
    case 0x1: // R8_0x1 alias
    case 0x8:
      return 0x11; // GX_TF_Z8 (top 8 bits)
    case 0x3:
      return 0x13; // GX_TF_Z16
    case 0x9:
      return 0x39; // GX_CTF_Z8M (middle 8 bits)
    case 0xA:
      return 0x3A; // GX_CTF_Z8L (low 8 bits)
    case 0xC:
      return 0x3C; // GX_CTF_Z16L (low 16 bits)
    case 0x6:
    default:
      return 0x16; // GX_TF_Z24X8 (nearest representable for odd combos)
    }
  }
  if (intensity && real <= 0x3u)
    return real; // GX_TF_I4 / I8 / IA4 / IA8
  switch (real) {
  case 0x0:
    return 0x20; // GX_CTF_R4
  case 0x1: // R8_0x1 alias
  case 0x8:
    return 0x28; // GX_CTF_R8
  case 0x2:
    return 0x22; // GX_CTF_RA4
  case 0x3:
    return 0x23; // GX_CTF_RA8
  case 0x4:
    return 0x4; // GX_TF_RGB565
  case 0x5:
    return 0x5; // GX_TF_RGB5A3
  case 0x7:
    return 0x27; // GX_CTF_A8
  case 0x9:
    return 0x29; // GX_CTF_G8
  case 0xA:
    return 0x2A; // GX_CTF_B8
  case 0xB:
    return 0x2B; // GX_CTF_RG8
  case 0xC:
    return 0x2C; // GX_CTF_GB8
  case 0x6:
  default:
    return 0x6; // GX_TF_RGBA8 (nearest representable for odd combos)
  }
}

std::uint32_t payload_pn_matrix_mask(const DolGxRecompState& state,
                                     const DolGxRecompVertexLayout& layout,
                                     std::span<const std::uint8_t> vertex_data,
                                     std::uint16_t vertex_count) {
  if ((state.vcd_lo & 1u) == 0u || layout.vertex_size == 0u)
    return 0;
  std::uint32_t mask = 0;
  for (std::uint16_t v = 0; v < vertex_count; ++v) {
    const std::size_t offset =
        static_cast<std::size_t>(v) * layout.vertex_size;
    if (offset >= vertex_data.size())
      break;
    const std::uint32_t pn = vertex_data[offset] / 3u;
    if (pn < DOL_GX_RECOMP_POSITION_MATRIX_COUNT)
      mask |= (1u << pn);
  }
  return mask;
}

DrawTransformSnapshot snapshot_transform(const DolGxRecompState& state,
                                         const DolGxRecompVertexLayout& layout,
                                         std::span<const std::uint8_t> vertex_data,
                                         std::uint16_t vertex_count) {
  DrawTransformSnapshot out{};
  if (state.viewport_valid) {
    out.transform_flags |= kDrawTransformViewportValid;
    std::memcpy(out.viewport, state.viewport, sizeof(out.viewport));
  }
  if (state.projection_valid) {
    out.transform_flags |= kDrawTransformProjectionValid;
    std::memcpy(out.projection, state.projection, sizeof(out.projection));
    out.projection_type = state.projection_type;
  }
  out.current_pn_matrix = state.current_pn_matrix;
  out.payload_pn_matrix_mask =
      payload_pn_matrix_mask(state, layout, vertex_data, vertex_count);
  if (out.payload_pn_matrix_mask != 0u)
    out.transform_flags |= kDrawTransformPayloadPnMatrixValid;
  for (std::uint32_t i = 0; i < DOL_GX_RECOMP_POSITION_MATRIX_COUNT; ++i) {
    if (!state.position_matrix_valid[i])
      continue;
    out.position_matrix_valid_mask |= (1u << i);
    std::memcpy(out.position_matrices[i], state.position_matrices[i],
                sizeof(out.position_matrices[i]));
  }
  std::memcpy(out.normal_matrices, state.normal_matrices,
              sizeof(out.normal_matrices));
  std::memcpy(out.normal_matrix_word_mask, state.normal_matrix_word_mask,
              sizeof(out.normal_matrix_word_mask));
  std::memcpy(out.light_words, state.light_words, sizeof(out.light_words));
  std::memcpy(out.light_word_mask, state.light_word_mask,
              sizeof(out.light_word_mask));
  std::memcpy(out.chan_regs, state.chan_regs, sizeof(out.chan_regs));
  out.chan_reg_mask = state.chan_reg_mask;
  std::memcpy(out.tex_matrices, state.tex_matrices, sizeof(out.tex_matrices));
  std::memcpy(out.tex_matrix_word_mask, state.tex_matrix_word_mask,
              sizeof(out.tex_matrix_word_mask));
  std::memcpy(out.xf_regs, state.xf_regs, sizeof(out.xf_regs));
  out.xf_reg_mask = state.xf_reg_mask;
  return out;
}

} // namespace

RetailGxFrontend::RetailGxFrontend() { reset(); }

RetailGxFrontend::RetailGxFrontend(const DolGuestAddressResolver& resolver) {
  reset(&resolver);
}

void RetailGxFrontend::reset(const DolGuestAddressResolver* resolver) {
  dol_gx_recomp_init(&state_, resolver);
  fifo_buffer_.clear();
  draw_payload_queue_.clear();
  draw_transform_queue_.clear();
  draw_payload_head_ = 0u;
  draw_transform_head_ = 0u;
  zero_vertex_draws_ = 0u;
  emitted_trace_count_ = 0u;
  next_packet_sequence_ = 0u;
  last_error_ = nullptr;
  last_error_offset_ = 0u;
  last_error_opcode_ = 0u;
  last_error_a_ = 0u;
  last_error_b_ = 0u;
  last_error_c_ = 0u;
  last_error_d_ = 0u;
}

bool RetailGxFrontend::set_vertex_layout(std::uint8_t vtx_fmt,
                                         std::uint32_t vertex_size) {
  return dol_gx_recomp_set_vertex_layout(&state_, vtx_fmt, vertex_size);
}

bool RetailGxFrontend::set_indexed_attr(std::uint8_t vtx_fmt,
                                        std::uint8_t attr,
                                        std::uint32_t vertex_offset,
                                        std::uint8_t index_size,
                                        std::uint32_t element_size,
                                        std::uint32_t element_bias) {
  return dol_gx_recomp_set_indexed_attr(&state_, vtx_fmt, attr, vertex_offset,
                                        index_size, element_size,
                                        element_bias);
}

bool RetailGxFrontend::derive_vertex_layout(std::uint8_t vtx_fmt) {
  return dol_gx_recomp_derive_vertex_layout(&state_, vtx_fmt);
}

bool RetailGxFrontend::load_cp_reg(std::uint8_t reg, std::uint32_t value) {
  return dol_gx_recomp_load_cp_reg(&state_, reg, value);
}

bool RetailGxFrontend::set_cp_array(std::uint8_t attr,
                                    std::uint32_t physical_base,
                                    std::uint8_t stride) {
  if (attr >= DOL_GX_RECOMP_CP_ARRAY_COUNT)
    return false;
  return load_cp_reg(static_cast<std::uint8_t>(DOL_GX_CP_REG_ARRAYBASE + attr),
                     physical_base) &&
         load_cp_reg(
             static_cast<std::uint8_t>(DOL_GX_CP_REG_ARRAYSTRIDE + attr),
             stride);
}

void RetailGxFrontend::set_packet_drain_enabled(bool enabled) {
  packet_drain_enabled_ = enabled;
  emitted_trace_count_ = 0u;
  next_packet_sequence_ = 0u;
  if (enabled)
    state_.trace_count = 0u;
}

bool RetailGxFrontend::write_fifo(std::span<const std::uint8_t> bytes) {
  if (bytes.empty())
    return false;
  fifo_buffer_.insert(fifo_buffer_.end(), bytes.begin(), bytes.end());
  return true;
}

bool RetailGxFrontend::flush(AuroraRenderSink* sink) {
  last_error_ = nullptr;
  std::uint32_t first_event = 0;
  if (packet_drain_enabled_) {
    first_event = emitted_trace_count_;
  } else {
    (void)dol_gx_recomp_trace_events(&state_, &first_event);
  }

  std::size_t consumed = 0;
  if (!parse_stream(fifo_buffer_, true, true, 0u, &consumed))
    return false;

  if (consumed != 0u) {
    fifo_buffer_.erase(fifo_buffer_.begin(),
                       fifo_buffer_.begin() +
                           static_cast<std::ptrdiff_t>(consumed));
  }
  notify_events(first_event);

  if (sink == nullptr)
    return true;
  if (!emit_new_packets(*sink, first_event))
    return false;
  if (packet_drain_enabled_)
    drain_emitted_packets(state_.trace_count);
  return true;
}

bool RetailGxFrontend::write_display_list(std::span<const std::uint8_t> bytes,
                                          AuroraRenderSink* sink) {
  last_error_ = nullptr;
  std::uint32_t first_event = 0;
  if (packet_drain_enabled_) {
    first_event = emitted_trace_count_;
  } else {
    (void)dol_gx_recomp_trace_events(&state_, &first_event);
  }

  // Mirrors the 0x40 opcode branch of parse_stream: a zero-size list is a
  // no-op, the list bytes are recorded, then parsed at DL depth with partial
  // commands forbidden and full consumption required.
  if (!bytes.empty()) {
    if (!dol_gx_recomp_push_fifo(&state_, bytes.data(),
                                 static_cast<std::uint32_t>(bytes.size())))
      return false;
    std::size_t dl_consumed = 0;
    if (!parse_stream(bytes, false, false, 1u, &dl_consumed) ||
        dl_consumed != bytes.size()) {
      return false;
    }
  }
  notify_events(first_event);

  if (sink == nullptr)
    return true;
  if (!emit_new_packets(*sink, first_event))
    return false;
  if (packet_drain_enabled_)
    drain_emitted_packets(state_.trace_count);
  return true;
}

bool RetailGxFrontend::replay_fifo(std::span<const std::uint8_t> bytes,
                                   AuroraRenderSink* sink) {
  last_error_ = nullptr;
  std::uint32_t first_event = 0;
  if (packet_drain_enabled_) {
    first_event = emitted_trace_count_;
  } else {
    (void)dol_gx_recomp_trace_events(&state_, &first_event);
  }

  std::size_t consumed = 0;
  if (bytes.empty() ||
      !parse_stream(bytes, false, true, 0u, &consumed) ||
      consumed != bytes.size()) {
    return false;
  }
  notify_events(first_event);

  if (sink == nullptr)
    return true;
  if (!emit_new_packets(*sink, first_event))
    return false;
  if (packet_drain_enabled_)
    drain_emitted_packets(state_.trace_count);
  return true;
}

void RetailGxFrontend::notify_events(std::uint32_t first_event) {
  if (event_observer_ == nullptr)
    return;
  for (std::uint32_t i = first_event; i < state_.trace_count; ++i)
    event_observer_(state_.trace[i], event_observer_user_);
}

std::span<const DolGxRecompTraceEvent> RetailGxFrontend::trace_events() const {
  std::uint32_t count = 0;
  const DolGxRecompTraceEvent* events =
      dol_gx_recomp_trace_events(&state_, &count);
  return events == nullptr ? std::span<const DolGxRecompTraceEvent>{}
                           : std::span<const DolGxRecompTraceEvent>{events,
                                                                     count};
}

bool RetailGxFrontend::fail_parse(const char* reason, std::uint8_t opcode,
                                  std::size_t offset, std::uint32_t a,
                                  std::uint32_t b, std::uint32_t c,
                                  std::uint32_t d) {
  last_error_ = reason;
  last_error_opcode_ = opcode;
  last_error_offset_ = offset;
  last_error_a_ = a;
  last_error_b_ = b;
  last_error_c_ = c;
  last_error_d_ = d;
  return false;
}

bool RetailGxFrontend::parse_stream(std::span<const std::uint8_t> bytes,
                                    bool allow_partial,
                                    bool record_fifo_bytes,
                                    std::uint32_t depth,
                                    std::size_t* consumed) {
  if (consumed == nullptr || depth > 4u)
    return false;

  std::size_t pos = 0;
  while (pos < bytes.size()) {
    const std::uint8_t cmd = bytes[pos];
    if (cmd == 0x00u) {
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 1u))
        return false;
      ++pos;
      continue;
    }

    if (cmd == DOL_GX_CMD_LOAD_CP_REG) {
      if (pos + 6u > bytes.size())
        break;
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 6u))
        return false;
      if (!dol_gx_recomp_load_cp_reg(&state_, bytes[pos + 1u],
                                     read_be32(bytes, pos + 2u)))
        return false;
      pos += 6u;
      continue;
    }

    if (cmd == DOL_GX_CMD_LOAD_XF_REG) {
      if (pos + 5u > bytes.size())
        break;
      const std::uint32_t header = read_be32(bytes, pos + 1u);
      const std::uint8_t count =
          static_cast<std::uint8_t>(((header >> 16u) & 0xFFFFu) + 1u);
      const std::uint16_t base = static_cast<std::uint16_t>(header);
      const std::size_t command_size = 5u + static_cast<std::size_t>(count) * 4u;
      if (pos + command_size > bytes.size())
        break;
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos,
                                   static_cast<std::uint32_t>(command_size)))
        return false;
      if (!dol_gx_recomp_note_xf_load(&state_, base, count))
        return false;
      // Data words follow the 1-byte command + 4-byte header. Decode the
      // viewport/projection registers if this load covers them (transform-diff).
      dol_gx_recomp_capture_xf_transform(&state_, base, count,
                                         bytes.data() + pos + 5u);
      pos += command_size;
      continue;
    }

    if (cmd == 0x20u || cmd == 0x28u || cmd == 0x30u || cmd == 0x38u) {
      if (pos + 5u > bytes.size())
        break;
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 5u))
        return false;
      const std::uint32_t value = read_be32(bytes, pos + 1u);
      const std::uint32_t index = value >> 16u;
      const std::uint16_t base = static_cast<std::uint16_t>(value & 0x0FFFu);
      const std::uint8_t count =
          static_cast<std::uint8_t>(((value >> 12u) & 0xFu) + 1u);
      const std::uint8_t attr =
          static_cast<std::uint8_t>(12u + ((cmd - 0x20u) / 8u));
      const std::uint32_t element_bytes = static_cast<std::uint32_t>(count) * 4u;
      const std::uint32_t span = state_.arrays[attr].stride_valid
                                     ? index * state_.arrays[attr].stride +
                                           element_bytes
                                     : 0u;
      DolGxRecompResolvedArray array;
      if (span == 0u ||
          !dol_gx_recomp_resolve_cp_array(&state_, attr, span, &array))
        return false;
      dol_gx_recomp_capture_xf_transform(
          &state_, base, count,
          static_cast<const std::uint8_t*>(array.range.data) +
              index * state_.arrays[attr].stride);
      if (!dol_gx_recomp_note_xf_load(&state_, base, count))
        return false;
      // `dol_gx_recomp_note_xf_load` records the generic XF event; retain the
      // indexed-XF-specific event shape expected by replay packets.
      if (state_.trace_count < DOL_GX_RECOMP_MAX_TRACE_EVENTS) {
        state_.trace[state_.trace_count++] = {
            .kind = DOL_GX_RECOMP_EVENT_INDEXED_XF_LOAD,
            .a = attr,
            .b = index,
            .c = base,
            .d = count,
        };
      }
      pos += 5u;
      continue;
    }

    if (cmd == DOL_GX_CMD_CALL_DL) {
      if (pos + 9u > bytes.size())
        break;
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 9u))
        return false;

      const std::uint32_t address = read_be32(bytes, pos + 1u);
      const std::uint32_t size = read_be32(bytes, pos + 5u);
      pos += 9u;
      if (size == 0u)
        continue;

      DolGuestResolvedRange range;
      if (!dol_gx_recomp_resolve_display_list(&state_, address, size, &range))
        return false;
      if (!dol_gx_recomp_push_fifo(&state_, range.data, range.size))
        return false;

      std::size_t dl_consumed = 0;
      if (!parse_stream(
              std::span<const std::uint8_t>{
                  static_cast<const std::uint8_t*>(range.data), range.size},
              false, false, depth + 1u, &dl_consumed) ||
          dl_consumed != range.size) {
        return false;
      }
      continue;
    }

    if (cmd == DOL_GX_CMD_INVL_VC) {
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 1u))
        return false;
      if (!dol_gx_recomp_note_invalidate_vtx_cache(&state_))
        return false;
      ++pos;
      continue;
    }

    if (cmd == DOL_GX_CMD_LOAD_BP_REG) {
      if (pos + 5u > bytes.size())
        break;
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 5u))
        return false;
      if (!handle_bp(read_be32(bytes, pos + 1u)))
        return fail_parse("BP register handler rejected", cmd, pos,
                          bytes[pos + 1u], read_be32(bytes, pos + 1u));
      pos += 5u;
      continue;
    }

    if (is_draw_opcode(cmd)) {
      if (pos + 3u > bytes.size())
        break;
      const std::uint16_t vertex_count = read_be16(bytes, pos + 1u);
      // Aurora's GX_AURORA_DRAW_SIZED command treats a zero-byte draw as a
      // no-op. Retail titles can emit the equivalent raw GXBegin header with a
      // zero vertex count, so consume it without requiring a vertex layout or
      // producing a Draw packet.
      if (vertex_count == 0u) {
        if (record_fifo_bytes &&
            !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos, 3u))
          return false;
        ++zero_vertex_draws_;
        pos += 3u;
        continue;
      }
      const std::uint8_t vtx_fmt = cmd & 0x7u;
      if (vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS)
        return fail_parse("draw vertex format out of range", cmd, pos);
      if (!state_.vertex_layouts[vtx_fmt].valid &&
          !dol_gx_recomp_derive_vertex_layout(&state_, vtx_fmt))
        return fail_parse("draw vertex layout unavailable", cmd, pos);
      const std::uint32_t vertex_size =
          state_.vertex_layouts[vtx_fmt].vertex_size;
      const std::size_t vertex_bytes =
          static_cast<std::size_t>(vertex_count) * vertex_size;
      const std::size_t command_size = 3u + vertex_bytes;
      if (pos + command_size > bytes.size())
        break;
      if (record_fifo_bytes &&
          !dol_gx_recomp_push_fifo(&state_, bytes.data() + pos,
                                   static_cast<std::uint32_t>(command_size)))
        return false;
      if (!handle_draw(cmd,
                       std::span<const std::uint8_t>{bytes.data() + pos + 3u,
                                                     vertex_bytes},
                       vertex_count, pos))
        return false;
      pos += command_size;
      continue;
    }

    return fail_parse("unsupported FIFO opcode", cmd, pos);
  }

  *consumed = pos;
  return true;
}

bool RetailGxFrontend::handle_bp(std::uint32_t raw) {
  const std::uint8_t reg = static_cast<std::uint8_t>(raw >> 24u);
  const std::uint32_t value = raw & 0x00FFFFFFu;
  if (!dol_gx_recomp_note_bp_reg(&state_, reg, value))
    return false;

  std::uint8_t slot = 0;
  if (map_image0_reg(reg, &slot) || map_image3_reg(reg, &slot))
    return maybe_resolve_texture(slot);
  if (map_tlut_reg(reg, &slot)) {
    state_.texture_tlut_valid[slot] = true;
    state_.texture_tlut_tmem_offset[slot] =
        static_cast<std::uint16_t>(bp_get(value, 10u, 0u));
    state_.texture_tlut_format[slot] = bp_get(value, 2u, 10u);
    return true;
  }

  switch (reg) {
  case DOL_GX_BP_REG_EFB_TL:
    state_.copy.src_x = bp_get(value, 10u, 0u);
    state_.copy.src_y = bp_get(value, 10u, 10u);
    return true;
  case DOL_GX_BP_REG_EFB_WH:
    state_.copy.width = bp_get(value, 10u, 0u) + 1u;
    state_.copy.height = bp_get(value, 10u, 10u) + 1u;
    return true;
  case DOL_GX_BP_REG_EFB_ADDR:
    state_.copy.physical_base = texture_physical_base(value);
    state_.copy.physical_base_valid = true;
    return true;
  case DOL_GX_BP_REG_TRIGGER_EFB_COPY:
    return handle_copy_trigger(value);
  case DOL_GX_BP_REG_LOAD_TLUT1: {
    const std::uint16_t tmem_offset =
        static_cast<std::uint16_t>(bp_get(value, 10u, 0u));
    const std::uint32_t line_count = bp_get(value, 11u, 10u);
    if (line_count == 0u)
      return true;
    if (!state_.bp_valid[DOL_GX_BP_REG_LOAD_TLUT0])
      return true;
    DolGxRecompTlut tlut;
    (void)dol_gx_recomp_resolve_tmem_tlut(
        &state_, tmem_offset, state_.bp_regs[DOL_GX_BP_REG_LOAD_TLUT0], 0u,
        static_cast<std::uint16_t>(line_count * 16u), &tlut);
    return true;
  }
  default:
    return true;
  }
}

bool RetailGxFrontend::maybe_resolve_texture(std::uint8_t slot) {
  if (slot >= DOL_GX_RECOMP_TEXTURE_SLOTS)
    return false;
  const std::uint8_t image0_reg = image0_reg_for_slot(slot);
  const std::uint8_t image3_reg = image3_reg_for_slot(slot);
  if (!state_.bp_valid[image0_reg] || !state_.bp_valid[image3_reg])
    return true;
  DolGxRecompTexture texture;
  return dol_gx_recomp_resolve_texture_image(
      &state_, slot, state_.bp_regs[image0_reg], state_.bp_regs[image3_reg],
      &texture);
}

bool RetailGxFrontend::handle_copy_trigger(std::uint32_t value) {
  if (bp_get(value, 1u, 14u) != 0u)
    return dol_gx_recomp_note_display_copy(&state_, bp_get(value, 1u, 11u));
  if (!state_.copy.physical_base_valid)
    return false;

  std::uint32_t width = state_.copy.width != 0u ? state_.copy.width : 1u;
  std::uint32_t height = state_.copy.height != 0u ? state_.copy.height : 1u;
  if (bp_get(value, 1u, 9u) != 0u) {
    width = (width + 1u) / 2u;
    height = (height + 1u) / 2u;
    if (width == 0u)
      width = 1u;
    if (height == 0u)
      height = 1u;
  }

  state_.copy.is_depth =
      state_.bp_valid[DOL_GX_BP_REG_PE_CONTROL] &&
      (state_.bp_regs[DOL_GX_BP_REG_PE_CONTROL] & 0x7u) ==
          DOL_GX_PE_PIXEL_FORMAT_Z24;
  state_.copy.format = copy_trigger_texture_format(value, state_.copy.is_depth);
  state_.copy.clear = bp_get(value, 1u, 11u); // EFB cleared after copy
  if (!dol_gx_recomp_texture_size(static_cast<std::uint16_t>(width),
                                  static_cast<std::uint16_t>(height),
                                  state_.copy.format,
                                  &state_.copy.byte_size))
    return false;
  state_.copy.width = width;
  state_.copy.height = height;
  if (!dol_gx_recomp_resolve_copy_destination(
          &state_, state_.copy.physical_base, state_.copy.byte_size,
          &state_.copy.range))
    return false;
  state_.copy.range_valid = true;
  return true;
}

bool RetailGxFrontend::handle_draw(std::uint8_t command,
                                   std::span<const std::uint8_t> vertex_data,
                                   std::uint16_t vertex_count,
                                   std::size_t command_offset) {
  if (vertex_data.empty() || vertex_count == 0u)
    return fail_parse("empty draw command", command, command_offset);
  const std::uint8_t vtx_fmt = command & 0x7u;
  if (vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS ||
      !state_.vertex_layouts[vtx_fmt].valid)
    return fail_parse("draw vertex layout missing", command, command_offset);

  const DolGxRecompVertexLayout* layout = &state_.vertex_layouts[vtx_fmt];
  if (state_.trace_count < DOL_GX_RECOMP_MAX_TRACE_EVENTS) {
    state_.trace[state_.trace_count++] = {
        .kind = DOL_GX_RECOMP_EVENT_DRAW,
        .a = command & 0xF8u,
        .b = vtx_fmt,
        .c = vertex_count,
        .d = layout->vertex_size,
    };
    // Retain this draw's raw per-vertex bytes in trace order; emit_new_packets
    // pops them in lockstep so each Draw packet references its own payload.
    draw_payload_queue_.emplace_back(vertex_data.begin(), vertex_data.end());
    draw_transform_queue_.push_back(
        snapshot_transform(state_, *layout, vertex_data, vertex_count));
  }

  for (std::uint32_t i = 0u; i < layout->indexed_attr_count; ++i) {
    const DolGxRecompIndexedAttr* spec = &layout->indexed_attrs[i];
    const std::uint8_t attr = spec->attr;
    if (!spec->valid || attr >= DOL_GX_RECOMP_CP_ARRAY_COUNT)
      return fail_parse("draw indexed attribute invalid", command,
                        command_offset);
    std::uint32_t span = 0;
    if (!dol_gx_recomp_indexed_span(
            vertex_data.data(), layout->vertex_size, vertex_count,
            spec->vertex_offset, spec->index_size,
            state_.arrays[attr].stride_valid ? state_.arrays[attr].stride : 0u,
            spec->element_size, spec->element_bias, &span))
      return fail_parse(
          "draw indexed span failed", command, command_offset, attr,
          state_.arrays[attr].stride_valid ? state_.arrays[attr].stride : 0u,
          spec->vertex_offset, spec->index_size);
    DolGxRecompResolvedArray array;
    if (!dol_gx_recomp_resolve_cp_array(&state_, attr, span, &array))
      return fail_parse("draw CP array resolve failed", command,
                        command_offset);
    if (state_.trace_count < DOL_GX_RECOMP_MAX_TRACE_EVENTS) {
      state_.trace[state_.trace_count++] = {
          .kind = DOL_GX_RECOMP_EVENT_INDEXED_SPAN,
          .a = attr,
          .b = span,
          .c = vertex_count,
          .d = vtx_fmt,
          // Per-attr decode params so an issuing sink can read each vertex's
          // index from the draw payload and fetch element_size bytes from the
          // resolved array at base + index * stride.
          .e = spec->vertex_offset,
          .f = spec->index_size,
          .g = spec->element_size,
      };
    }
  }
  return true;
}

bool RetailGxFrontend::emit_new_packets(AuroraRenderSink& sink,
                                        std::uint32_t first_event) {
  const auto events = trace_events();
  if (first_event > events.size())
    return false;

  for (std::uint32_t i = first_event; i < events.size(); ++i) {
    const std::uint32_t sequence =
        packet_drain_enabled_ ? next_packet_sequence_++ : i;
    RenderPacket packet = make_render_packet(sequence, events[i]);
    // Draw events are emitted exactly once, in order, so the retained payloads
    // pop FIFO in lockstep. Attach this draw's raw bytes for the issuing sink.
    if (packet.kind == RenderPacketKind::Draw &&
        draw_payload_head_ < draw_payload_queue_.size()) {
      const std::vector<std::uint8_t>& payload =
          draw_payload_queue_[draw_payload_head_++];
      packet.draw.vertex_payload = payload.data();
      packet.draw.vertex_payload_size =
          static_cast<std::uint32_t>(payload.size());
    }
    if (packet.kind == RenderPacketKind::Draw &&
        draw_transform_head_ < draw_transform_queue_.size()) {
      const DrawTransformSnapshot& transform =
          draw_transform_queue_[draw_transform_head_++];
      packet.draw.transform_flags = transform.transform_flags;
      packet.draw.current_pn_matrix = transform.current_pn_matrix;
      packet.draw.payload_pn_matrix_mask =
          transform.payload_pn_matrix_mask;
      packet.draw.position_matrix_valid_mask =
          transform.position_matrix_valid_mask;
      std::memcpy(packet.draw.viewport, transform.viewport,
                  sizeof(packet.draw.viewport));
      std::memcpy(packet.draw.projection, transform.projection,
                  sizeof(packet.draw.projection));
      packet.draw.projection_type = transform.projection_type;
      std::memcpy(packet.draw.position_matrices, transform.position_matrices,
                  sizeof(packet.draw.position_matrices));
      std::memcpy(packet.draw.normal_matrices, transform.normal_matrices,
                  sizeof(packet.draw.normal_matrices));
      std::memcpy(packet.draw.normal_matrix_word_mask,
                  transform.normal_matrix_word_mask,
                  sizeof(packet.draw.normal_matrix_word_mask));
      std::memcpy(packet.draw.light_words, transform.light_words,
                  sizeof(packet.draw.light_words));
      std::memcpy(packet.draw.light_word_mask, transform.light_word_mask,
                  sizeof(packet.draw.light_word_mask));
      std::memcpy(packet.draw.chan_regs, transform.chan_regs,
                  sizeof(packet.draw.chan_regs));
      packet.draw.chan_reg_mask = transform.chan_reg_mask;
      std::memcpy(packet.draw.tex_matrices, transform.tex_matrices,
                  sizeof(packet.draw.tex_matrices));
      std::memcpy(packet.draw.tex_matrix_word_mask,
                  transform.tex_matrix_word_mask,
                  sizeof(packet.draw.tex_matrix_word_mask));
      std::memcpy(packet.draw.xf_regs, transform.xf_regs,
                  sizeof(packet.draw.xf_regs));
      packet.draw.xf_reg_mask = transform.xf_reg_mask;
    }
    if (!sink.submit_packet(packet))
      return false;
  }
  if (!packet_drain_enabled_)
    emitted_trace_count_ = static_cast<std::uint32_t>(events.size());
  return true;
}

void RetailGxFrontend::drain_emitted_packets(std::uint32_t emitted_count) {
  if (emitted_count == 0u)
    return;
  state_.fifo.size = 0u;
  // Drain mode emits every pending event each flush, so all retained draw
  // payloads were just consumed; release them and reset the FIFO cursor so the
  // queue cannot grow unbounded across a long run.
  draw_payload_queue_.clear();
  draw_transform_queue_.clear();
  draw_payload_head_ = 0u;
  draw_transform_head_ = 0u;
  if (emitted_count >= state_.trace_count) {
    state_.trace_count = 0u;
    emitted_trace_count_ = 0u;
    return;
  }
  const std::uint32_t remaining = state_.trace_count - emitted_count;
  std::memmove(state_.trace, state_.trace + emitted_count,
               static_cast<std::size_t>(remaining) * sizeof(state_.trace[0]));
  state_.trace_count = remaining;
  emitted_trace_count_ = 0u;
}

} // namespace gxruntime::aurora_recomp

extern "C" {

struct DolAuroraRecompRetailGxFrontend {
  gxruntime::aurora_recomp::RetailGxFrontend impl;
};

DolAuroraRecompRetailGxFrontend*
dol_aurora_recomp_frontend_create(const DolGuestAddressResolver* resolver) {
  auto* frontend = new (std::nothrow) DolAuroraRecompRetailGxFrontend;
  if (frontend == nullptr)
    return nullptr;
  frontend->impl.reset(resolver);
  return frontend;
}

void dol_aurora_recomp_frontend_destroy(
    DolAuroraRecompRetailGxFrontend* frontend) {
  delete frontend;
}

void dol_aurora_recomp_frontend_reset(
    DolAuroraRecompRetailGxFrontend* frontend,
    const DolGuestAddressResolver* resolver) {
  if (frontend != nullptr)
    frontend->impl.reset(resolver);
}

bool dol_aurora_recomp_frontend_set_vertex_layout(
    DolAuroraRecompRetailGxFrontend* frontend, u8 vtx_fmt, u32 vertex_size) {
  return frontend != nullptr &&
         frontend->impl.set_vertex_layout(vtx_fmt, vertex_size);
}

bool dol_aurora_recomp_frontend_set_indexed_attr(
    DolAuroraRecompRetailGxFrontend* frontend, u8 vtx_fmt, u8 attr,
    u32 vertex_offset, u8 index_size, u32 element_size, u32 element_bias) {
  return frontend != nullptr &&
         frontend->impl.set_indexed_attr(vtx_fmt, attr, vertex_offset,
                                         index_size, element_size,
                                         element_bias);
}

bool dol_aurora_recomp_frontend_derive_vertex_layout(
    DolAuroraRecompRetailGxFrontend* frontend, u8 vtx_fmt) {
  return frontend != nullptr && frontend->impl.derive_vertex_layout(vtx_fmt);
}

bool dol_aurora_recomp_frontend_set_cp_array(
    DolAuroraRecompRetailGxFrontend* frontend, u8 attr, u32 physical_base,
    u8 stride) {
  return frontend != nullptr &&
         frontend->impl.set_cp_array(attr, physical_base, stride);
}

bool dol_aurora_recomp_frontend_load_cp_reg(
    DolAuroraRecompRetailGxFrontend* frontend, u8 reg, u32 value) {
  return frontend != nullptr && frontend->impl.load_cp_reg(reg, value);
}

bool dol_aurora_recomp_frontend_write_fifo(
    DolAuroraRecompRetailGxFrontend* frontend, const void* bytes, size_t size) {
  if (frontend == nullptr || bytes == nullptr || size == 0u)
    return false;
  return frontend->impl.write_fifo(std::span<const std::uint8_t>{
      static_cast<const std::uint8_t*>(bytes), size});
}

bool dol_aurora_recomp_frontend_flush(
    DolAuroraRecompRetailGxFrontend* frontend,
    DolAuroraRecompRenderPacketFn submit, void* user) {
  if (frontend == nullptr)
    return false;
  gxruntime::aurora_recomp::CallbackRenderSink sink(submit, user);
  return frontend->impl.flush(&sink);
}

bool dol_aurora_recomp_frontend_replay_fifo(
    DolAuroraRecompRetailGxFrontend* frontend, const void* bytes, size_t size,
    DolAuroraRecompRenderPacketFn submit, void* user) {
  if (frontend == nullptr || bytes == nullptr || size == 0u)
    return false;
  gxruntime::aurora_recomp::CallbackRenderSink sink(submit, user);
  return frontend->impl.replay_fifo(
      std::span<const std::uint8_t>{static_cast<const std::uint8_t*>(bytes),
                                    size},
      &sink);
}

size_t dol_aurora_recomp_frontend_pending_fifo_size(
    const DolAuroraRecompRetailGxFrontend* frontend) {
  return frontend != nullptr ? frontend->impl.pending_fifo_size() : 0u;
}

const DolGxRecompState* dol_aurora_recomp_frontend_state(
    const DolAuroraRecompRetailGxFrontend* frontend) {
  return frontend != nullptr ? &frontend->impl.state() : nullptr;
}

const DolGxRecompTraceEvent* dol_aurora_recomp_frontend_trace_events(
    const DolAuroraRecompRetailGxFrontend* frontend, u32* count) {
  if (frontend == nullptr) {
    if (count != nullptr)
      *count = 0u;
    return nullptr;
  }
  const auto events = frontend->impl.trace_events();
  if (count != nullptr)
    *count = static_cast<u32>(events.size());
  return events.data();
}

const char* dol_aurora_recomp_trace_event_name(DolGxRecompEventKind kind) {
  return gxruntime::aurora_recomp::trace_event_name(kind);
}

} // extern "C"
