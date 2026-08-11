// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/aurora_recomp/render_sink.hpp"

#include <cstring>

namespace gxruntime::aurora_recomp {

bool RecordingAuroraRenderSink::submit_packet(const RenderPacket& packet) {
  packets_.push_back(packet);
  return true;
}

bool ConsumingAuroraRenderSink::fail(const char* reason,
                                     const RenderPacket& packet) {
  if (failure_reason_ == nullptr) {
    failure_reason_ = reason;
    failed_packet_ = packet;
  }
  return false;
}

const ConsumedArrayBinding&
ConsumingAuroraRenderSink::array(std::uint32_t index) const {
  static const ConsumedArrayBinding empty{};
  if (index >= kArrayCount)
    return empty;
  return arrays_[index];
}

void ConsumingAuroraRenderSink::reset() {
  for (auto& binding : arrays_)
    binding = ConsumedArrayBinding{};
  bound_texture_ = ConsumedTexture{};
  for (auto& t : bound_textures_)
    t = ConsumedTexture{};
  cull_all_ = false;
  draws_.clear();
  total_draws_ = 0;
  total_vertices_ = 0;
  payload_bytes_ = 0;
  packets_ = 0;
  stream_packets_ = 0;
  state_packets_ = 0;
  resource_packets_ = 0;
  texture_count_ = 0;
  tlut_count_ = 0;
  copy_count_ = 0;
  indexed_span_count_ = 0;
  resolved_array_inputs_ = 0;
  unresolved_array_inputs_ = 0;
  assembled_draws_ = 0;
  assembled_elements_ = 0;
  assemble_failed_draws_ = 0;
  assembled_index_bytes_ = 0;
  assembled_element_bytes_ = 0;
  topology_index_bytes_ = 0;
  storage_bytes_ = 0;
  back_assembled_ = false;
  last_sequence_ = 0;
  has_last_sequence_ = false;
  failure_reason_ = nullptr;
  failed_packet_ = {};
}

bool ConsumingAuroraRenderSink::submit_packet(const RenderPacket& packet) {
  if (has_last_sequence_ && packet.sequence <= last_sequence_)
    return fail("non-monotonic packet sequence", packet);
  has_last_sequence_ = true;
  last_sequence_ = packet.sequence;
  ++packets_;

  switch (packet.kind) {
  case RenderPacketKind::Stream:
    ++stream_packets_;
    if (packet.stream.size == 0u)
      return fail("empty stream packet", packet);
    return true;
  case RenderPacketKind::State:
    ++state_packets_;
    switch (packet.state.kind) {
    case RenderStateKind::CpArrayBase:
      if (packet.state.index < kArrayCount) {
        arrays_[packet.state.index].base_valid = true;
        arrays_[packet.state.index].base = packet.state.value;
      }
      break;
    case RenderStateKind::CpArrayStride:
      if (packet.state.index < kArrayCount) {
        arrays_[packet.state.index].stride_valid = true;
        arrays_[packet.state.index].stride = packet.state.value;
      }
      break;
    case RenderStateKind::CullAll:
      cull_all_ = packet.state.value != 0u;
      break;
    default:
      break;
    }
    return true;
  case RenderPacketKind::Resource:
    ++resource_packets_;
    switch (packet.resource.kind) {
    case RenderResourceKind::IndexedArraySpan:
      ++indexed_span_count_;
      if (packet.resource.size == 0u || packet.resource.count == 0u)
        return fail("empty indexed-array span packet", packet);
      // A CP array is only READ when its attr is indexed in the VCD; the
      // frontend emits exactly one INDEXED_SPAN per read array, immediately
      // AFTER the draw it belongs to. So a draw's real array inputs are its
      // spans, not every bound array. Append the read array to the most recent
      // draw and resolve its exact byte span.
      if (!draws_.empty() && packet.resource.index < kArrayCount) {
        ConsumedDraw& draw = draws_.back();
        const ConsumedArrayBinding& binding = arrays_[packet.resource.index];
        if (draw.array_input_count < ConsumedDraw::kMaxArrays) {
          ConsumedArrayInput& input = draw.arrays[draw.array_input_count++];
          input.attr = packet.resource.index;
          input.base = binding.base;
          input.stride = binding.stride;
          input.indexed = true;
          input.span_size = packet.resource.size;
          input.vertex_offset = packet.resource.vertex_offset;
          input.index_size = packet.resource.index_size;
          input.element_size = packet.resource.element_size;
          tally_array_input(resolve_array_input(input));
        }
      }
      break;
    case RenderResourceKind::Texture:
      ++texture_count_;
      if (packet.resource.size == 0u)
        return fail("empty texture packet", packet);
      bound_texture_ = ConsumedTexture{
          .valid = true,
          .slot = packet.resource.index,
          .address = packet.resource.address,
          .size = packet.resource.size,
          .format = packet.resource.format,
          .width = packet.resource.width,
          .height = packet.resource.height,
      };
      if (resolver_ != nullptr) {
        DolGuestResolvedRange range{};
        if (dol_guest_address_resolver_resolve(
                resolver_, packet.resource.address, packet.resource.size,
                DOL_GUEST_ADDRESS_AUTO, DOL_GUEST_RESOURCE_TEXTURE, &range)) {
          bound_texture_.resolved = true;
          bound_texture_.host_data = range.data;
          bound_texture_.host_available = range.available;
        } else {
          return fail("texture guest address did not resolve", packet);
        }
        // CI textures carry a TLUT: resolve the palette bytes too. Best-effort —
        // an unresolved palette leaves has_tlut false so the CI decode falls
        // back, rather than failing the whole draw.
        if (packet.resource.tlut_address != 0u &&
            packet.resource.tlut_entries != 0u) {
          DolGuestResolvedRange tlut_range{};
          if (dol_guest_address_resolver_resolve(
                  resolver_, packet.resource.tlut_address,
                  packet.resource.tlut_entries * 2u, DOL_GUEST_ADDRESS_AUTO,
                  DOL_GUEST_RESOURCE_TLUT, &tlut_range)) {
            bound_texture_.has_tlut = true;
            bound_texture_.tlut_address = packet.resource.tlut_address;
            bound_texture_.tlut_format = packet.resource.tlut_format;
            bound_texture_.tlut_entries = packet.resource.tlut_entries;
            bound_texture_.tlut_host_data = tlut_range.data;
            bound_texture_.tlut_host_available = tlut_range.available;
          }
        }
      }
      // Record into the per-texmap slot too, so a draw sampling >1 texmap
      // (THP YUV Y/U/V) sees every bound texture, not just the last (63/Mfin).
      if (bound_texture_.slot < ConsumedDraw::kMaxTexmaps)
        bound_textures_[bound_texture_.slot] = bound_texture_;
      break;
    case RenderResourceKind::Tlut:
      ++tlut_count_;
      if (packet.resource.size == 0u)
        return fail("empty tlut packet", packet);
      break;
    case RenderResourceKind::CopyDestination:
      ++copy_count_;
      // Display copies (GXCopyDisp, format 0xF) carry no texture destination
      // — only the copy-clear params — so zero size is their normal shape.
      if (packet.resource.size == 0u && packet.resource.format != 0xFu)
        return fail("empty copy-destination packet", packet);
      break;
    }
    return true;
  case RenderPacketKind::Draw: {
    if (packet.draw.vertex_count == 0u || packet.draw.vertex_size == 0u)
      return fail("empty draw packet", packet);
    std::uint32_t active_mask = 0;
    for (std::uint32_t i = 0; i < kArrayCount; ++i) {
      if (arrays_[i].base_valid && arrays_[i].stride_valid)
        active_mask |= (1u << i);
    }
    ConsumedDraw draw{
        .sequence = packet.sequence,
        .primitive = packet.draw.primitive,
        .vtx_fmt = packet.draw.vtx_fmt,
        .vertex_count = packet.draw.vertex_count,
        .vertex_size = packet.draw.vertex_size,
        .cull_all = cull_all_,
        .active_array_mask = active_mask,
        .texture = bound_texture_,
    };
    for (std::uint32_t t = 0; t < ConsumedDraw::kMaxTexmaps; ++t)
      draw.textures[t] = bound_textures_[t];
    draw.transform_flags = packet.draw.transform_flags;
    draw.current_pn_matrix = packet.draw.current_pn_matrix;
    draw.payload_pn_matrix_mask = packet.draw.payload_pn_matrix_mask;
    draw.position_matrix_valid_mask = packet.draw.position_matrix_valid_mask;
    std::memcpy(draw.viewport, packet.draw.viewport, sizeof(draw.viewport));
    std::memcpy(draw.projection, packet.draw.projection,
                sizeof(draw.projection));
    draw.projection_type = packet.draw.projection_type;
    std::memcpy(draw.position_matrices, packet.draw.position_matrices,
                sizeof(draw.position_matrices));
    std::memcpy(draw.normal_matrices, packet.draw.normal_matrices,
                sizeof(draw.normal_matrices));
    std::memcpy(draw.normal_matrix_word_mask,
                packet.draw.normal_matrix_word_mask,
                sizeof(draw.normal_matrix_word_mask));
    std::memcpy(draw.light_words, packet.draw.light_words,
                sizeof(draw.light_words));
    std::memcpy(draw.light_word_mask, packet.draw.light_word_mask,
                sizeof(draw.light_word_mask));
    std::memcpy(draw.chan_regs, packet.draw.chan_regs,
                sizeof(draw.chan_regs));
    draw.chan_reg_mask = packet.draw.chan_reg_mask;
    std::memcpy(draw.tex_matrices, packet.draw.tex_matrices,
                sizeof(draw.tex_matrices));
    std::memcpy(draw.tex_matrix_word_mask, packet.draw.tex_matrix_word_mask,
                sizeof(draw.tex_matrix_word_mask));
    std::memcpy(draw.xf_regs, packet.draw.xf_regs, sizeof(draw.xf_regs));
    draw.xf_reg_mask = packet.draw.xf_reg_mask;
    // The previous draw's trailing INDEXED_SPAN packets are now all in, so it is
    // span-complete: assemble it before it is dropped (streaming clears draws_).
    if (!draws_.empty())
      accumulate_assembly(draws_.back());
    // Array inputs are appended by the draw's trailing INDEXED_SPAN packets
    // (only indexed attrs read CP arrays). In streaming mode keep only the
    // latest draw so the vector stays bounded; back() is still the target of
    // those spans.
    if (streaming_)
      draws_.clear();
    draws_.push_back(draw);
    back_assembled_ = false; // the just-pushed draw is not yet assembled
    // Retain the draw's raw per-vertex bytes (valid only during this call) so an
    // issuing sink can assemble vertices after submit. Append after push_back so
    // the copy lands on the just-added draw.
    if (packet.draw.vertex_payload != nullptr &&
        packet.draw.vertex_payload_size != 0u) {
      draws_.back().vertex_payload.assign(
          packet.draw.vertex_payload,
          packet.draw.vertex_payload + packet.draw.vertex_payload_size);
      payload_bytes_ += packet.draw.vertex_payload_size;
    }
    ++total_draws_;
    total_vertices_ += packet.draw.vertex_count;
    return true;
  }
  case RenderPacketKind::TraceEvent:
  default:
    return fail("unmapped trace event packet", packet);
  }
}

bool ConsumingAuroraRenderSink::resolve_array_input(
    ConsumedArrayInput& input) {
  input.resolved = false;
  input.host_data = nullptr;
  input.host_available = 0;
  if (resolver_ == nullptr || input.span_size == 0u)
    return false;

  DolGuestResolvedRange range{};
  if (dol_guest_address_resolver_resolve(
          resolver_, input.base, input.span_size, DOL_GUEST_ADDRESS_AUTO,
          DOL_GUEST_RESOURCE_VERTEX_ARRAY, &range)) {
    input.resolved = true;
    input.host_data = range.data;
    input.host_available = range.available;
  }
  return input.resolved;
}

void ConsumingAuroraRenderSink::accumulate_assembly(const ConsumedDraw& draw) {
  if (back_assembled_)
    return;
  // Count-only (nullptr): the live path does not retain per-vertex elements.
  const AssembledDrawStats stats = assemble_consumed_draw(draw, nullptr);
  ++assembled_draws_;
  assembled_elements_ += stats.element_reads;
  assembled_index_bytes_ += stats.index_bytes;
  assembled_element_bytes_ += stats.element_bytes;
  // Compute the DRAW-INPUT extents an issued draw would submit to Aurora, using
  // the same pure builders the cutover will call. Proves the builders run on
  // every live ConsumedDraw and lets the backend diff totals against Aurora's
  // native frame.verts/indices/storage sizes before exclusive cutover.
  const std::uint32_t topo = build_topology_indices(
      static_cast<GxPrimitive>(draw.primitive), 0,
      static_cast<std::uint16_t>(draw.vertex_count), nullptr);
  topology_index_bytes_ += static_cast<unsigned long long>(topo) * 2ull;
  std::uint32_t sizes[ConsumedDraw::kMaxArrays] = {0};
  build_array_sizes(draw, sizes, ConsumedDraw::kMaxArrays);
  for (std::uint32_t i = 0; i < ConsumedDraw::kMaxArrays; ++i)
    storage_bytes_ += sizes[i];
  if (!stats.ok)
    ++assemble_failed_draws_;
  if (draw_observer_ != nullptr)
    draw_observer_(draw, total_draws_, draw_observer_user_);
  back_assembled_ = true;
}

void ConsumingAuroraRenderSink::flush_assembly() {
  if (!draws_.empty())
    accumulate_assembly(draws_.back());
}

void ConsumingAuroraRenderSink::tally_array_input(bool resolved) {
  if (resolved)
    ++resolved_array_inputs_;
  else
    ++unresolved_array_inputs_;
}

void ConsumingAuroraRenderSink::untally_array_input(bool resolved) {
  if (resolved) {
    if (resolved_array_inputs_ > 0)
      --resolved_array_inputs_;
  } else if (unresolved_array_inputs_ > 0) {
    --unresolved_array_inputs_;
  }
}


namespace {
std::uint32_t read_index_be(const std::uint8_t* p, std::uint32_t index_size) {
  if (index_size == 1u)
    return p[0];
  if (index_size == 2u)
    return (static_cast<std::uint32_t>(p[0]) << 8) | p[1];
  return 0u;
}
} // namespace

AssembledDrawStats assemble_consumed_draw(const ConsumedDraw& draw,
                                          std::vector<AssembledElement>* out) {
  AssembledDrawStats stats{};
  stats.vertex_count = draw.vertex_count;
  if (out != nullptr)
    out->clear();

  if (draw.vertex_count == 0u || draw.vertex_size == 0u) {
    stats.ok = false;
    stats.failure_reason = "empty draw";
    return stats;
  }
  // The retained payload must hold vertex_count whole strides.
  if (draw.vertex_payload.size() <
      static_cast<std::size_t>(draw.vertex_count) * draw.vertex_size) {
    stats.ok = false;
    stats.failure_reason = "payload smaller than vertex_count*vertex_size";
    return stats;
  }
  const std::uint8_t* payload = draw.vertex_payload.data();

  for (std::uint32_t a = 0; a < draw.array_input_count; ++a) {
    const ConsumedArrayInput& in = draw.arrays[a];
    if (!in.indexed)
      continue; // direct attrs are inline in the payload; nothing to fetch.
    ++stats.indexed_attr_count;
    if (in.index_size != 1u && in.index_size != 2u) {
      stats.ok = false;
      stats.failure_attr = in.attr;
      stats.failure_reason = "unsupported index size";
      return stats;
    }
    if (!in.resolved || in.host_data == nullptr) {
      stats.ok = false;
      stats.failure_attr = in.attr;
      stats.failure_reason = "array input unresolved";
      return stats;
    }
    const std::uint8_t* host =
        static_cast<const std::uint8_t*>(in.host_data);
    for (std::uint32_t v = 0; v < draw.vertex_count; ++v) {
      const std::size_t idx_pos =
          static_cast<std::size_t>(v) * draw.vertex_size + in.vertex_offset;
      if (idx_pos + in.index_size > draw.vertex_payload.size()) {
        ++stats.failed_reads;
        stats.ok = false;
        stats.failure_attr = in.attr;
        stats.failure_reason = "index offset past payload";
        return stats;
      }
      const std::uint32_t index = read_index_be(payload + idx_pos, in.index_size);
      const std::size_t elem_off =
          static_cast<std::size_t>(index) * in.stride;
      if (in.stride == 0u ||
          elem_off + in.element_size > in.host_available) {
        ++stats.failed_reads;
        stats.ok = false;
        stats.failure_attr = in.attr;
        stats.failure_reason = "element fetch out of resolved span";
        return stats;
      }
      ++stats.element_reads;
      stats.index_bytes += in.index_size;
      stats.element_bytes += in.element_size;
      if (out != nullptr) {
        out->push_back(AssembledElement{
            .attr = in.attr,
            .vertex = v,
            .index = index,
            .host_element = host + elem_off,
            .element_size = in.element_size,
        });
      }
    }
  }
  return stats;
}

std::uint32_t build_topology_indices(GxPrimitive primitive,
                                     std::uint16_t vtx_start,
                                     std::uint16_t vtx_count,
                                     std::vector<std::uint16_t>* out) {
  std::uint32_t num = 0;
  const auto push = [&](std::uint16_t v) {
    if (out != nullptr)
      out->push_back(v);
    ++num;
  };
  switch (primitive) {
  case GxPrimitive::Quads:
    // Each quad -> two triangles {0,1,2} {2,3,0}. Trailing verts (< 4) ignored,
    // matching Aurora's v += 4 loop.
    for (std::uint16_t v = 0; v + 4u <= vtx_count; v += 4u) {
      const std::uint16_t i0 = static_cast<std::uint16_t>(vtx_start + v);
      const std::uint16_t i1 = static_cast<std::uint16_t>(vtx_start + v + 1);
      const std::uint16_t i2 = static_cast<std::uint16_t>(vtx_start + v + 2);
      const std::uint16_t i3 = static_cast<std::uint16_t>(vtx_start + v + 3);
      push(i0);
      push(i1);
      push(i2);
      push(i2);
      push(i3);
      push(i0);
    }
    break;
  case GxPrimitive::Triangles:
    for (std::uint16_t v = 0; v < vtx_count; ++v)
      push(static_cast<std::uint16_t>(vtx_start + v));
    break;
  case GxPrimitive::TriangleFan:
    for (std::uint16_t v = 0; v < vtx_count; ++v) {
      const std::uint16_t idx = static_cast<std::uint16_t>(vtx_start + v);
      if (v < 3u) {
        push(idx);
        continue;
      }
      push(vtx_start);
      push(static_cast<std::uint16_t>(idx - 1));
      push(idx);
    }
    break;
  case GxPrimitive::TriangleStrip:
    for (std::uint16_t v = 0; v < vtx_count; ++v) {
      const std::uint16_t idx = static_cast<std::uint16_t>(vtx_start + v);
      if (v < 3u) {
        push(idx);
        continue;
      }
      if ((v & 1u) == 0u) {
        push(static_cast<std::uint16_t>(idx - 2));
        push(static_cast<std::uint16_t>(idx - 1));
        push(idx);
      } else {
        push(static_cast<std::uint16_t>(idx - 1));
        push(static_cast<std::uint16_t>(idx - 2));
        push(idx);
      }
    }
    break;
  default:
    // Lines/points/unknown: Aurora handles separately; no triangle topology.
    break;
  }
  return num;
}

std::uint32_t build_array_sizes(const ConsumedDraw& draw, std::uint32_t* out,
                                std::size_t count) {
  if (out == nullptr || count == 0u)
    return 0u;
  for (std::size_t i = 0; i < count; ++i)
    out[i] = 0u;
  std::uint32_t non_zero = 0;
  for (std::uint32_t a = 0; a < draw.array_input_count; ++a) {
    const ConsumedArrayInput& in = draw.arrays[a];
    if (!in.indexed || in.attr >= count)
      continue;
    // span_size is already max((index+1)*stride) over the draw's vertices.
    if (in.span_size > out[in.attr]) {
      if (out[in.attr] == 0u)
        ++non_zero;
      out[in.attr] = in.span_size;
    }
  }
  return non_zero;
}

RenderPacket make_render_packet(std::uint32_t sequence,
                                const DolGxRecompTraceEvent& event) {
  RenderPacket packet{
      .kind = RenderPacketKind::TraceEvent,
      .sequence = sequence,
      .event = event,
  };

  switch (event.kind) {
  case DOL_GX_RECOMP_EVENT_FIFO_BYTES:
    packet.kind = RenderPacketKind::Stream;
    packet.stream = {
        .kind = RenderStreamKind::FifoBytes,
        .size = event.a,
        .total_size = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_DISPLAY_LIST:
    packet.kind = RenderPacketKind::Stream;
    packet.stream = {
        .kind = RenderStreamKind::DisplayList,
        .address = event.a,
        .size = event.b,
        .address_space = event.c,
    };
    break;
  case DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::CpArrayBase,
        .index = event.a,
        .value = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_CP_ARRAY_STRIDE:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::CpArrayStride,
        .index = event.a,
        .value = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_CP_VCD:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::CpVcd,
        .index = event.a,
        .value = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_CP_VAT:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::CpVat,
        .index = event.a,
        .value = event.c,
        .aux0 = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::VertexLayout,
        .index = event.a,
        .value = event.b,
        .aux0 = event.c,
    };
    break;
  case DOL_GX_RECOMP_EVENT_BP_REG:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::BpReg,
        .index = event.a,
        .value = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_XF_LOAD:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::XfLoad,
        .index = event.a,
        .value = event.b,
    };
    break;
  case DOL_GX_RECOMP_EVENT_INDEXED_XF_LOAD:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::IndexedXfLoad,
        .index = event.a,
        .value = event.b,
        .aux0 = event.c,
        .aux1 = event.d,
    };
    break;
  case DOL_GX_RECOMP_EVENT_CULL_ALL:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::CullAll,
        .value = event.a,
    };
    break;
  case DOL_GX_RECOMP_EVENT_INVALIDATE_VTX_CACHE:
    packet.kind = RenderPacketKind::State;
    packet.state = {
        .kind = RenderStateKind::InvalidateVtxCache,
    };
    break;
  case DOL_GX_RECOMP_EVENT_INDEXED_SPAN:
    packet.kind = RenderPacketKind::Resource;
    packet.resource = {
        .kind = RenderResourceKind::IndexedArraySpan,
        .index = event.a,
        .size = event.b,
        .count = event.c,
        .vtx_fmt = event.d,
        .vertex_offset = event.e,
        .index_size = event.f,
        .element_size = event.g,
    };
    break;
  case DOL_GX_RECOMP_EVENT_TEXTURE:
    packet.kind = RenderPacketKind::Resource;
    packet.resource = {
        .kind = RenderResourceKind::Texture,
        .index = event.a,
        .address = event.b,
        .size = event.c,
        .format = event.d,
        .width = event.e,
        .height = event.f,
        .tlut_address = event.tlut_address,
        .tlut_format = event.tlut_format,
        .tlut_entries = event.tlut_entries,
    };
    break;
  case DOL_GX_RECOMP_EVENT_TLUT:
    packet.kind = RenderPacketKind::Resource;
    packet.resource = {
        .kind = RenderResourceKind::Tlut,
        .index = event.a,
        .address = event.b,
        .size = event.c,
        .format = event.d,
    };
    break;
  case DOL_GX_RECOMP_EVENT_COPY_DESTINATION:
    packet.kind = RenderPacketKind::Resource;
    packet.resource = {
        .kind = RenderResourceKind::CopyDestination,
        .address = event.a,
        .size = event.b,
        .format = event.c,       // GX copy texture format (incl. Z target)
        .width = event.g >> 16,  // packed dims: width<<16 | height
        .height = event.g & 0xFFFFu,
        .copy_src_x = event.e,
        .copy_src_y = event.f,
        .copy_clear = event.d,
    };
    break;
  case DOL_GX_RECOMP_EVENT_DRAW:
    packet.kind = RenderPacketKind::Draw;
    packet.draw = {
        .primitive = event.a,
        .vtx_fmt = event.b,
        .vertex_count = event.c,
        .vertex_size = event.d,
    };
    break;
  default:
    break;
  }

  return packet;
}

const char* trace_event_name(DolGxRecompEventKind kind) {
  switch (kind) {
  case DOL_GX_RECOMP_EVENT_FIFO_BYTES:
    return "fifo-bytes";
  case DOL_GX_RECOMP_EVENT_DISPLAY_LIST:
    return "display-list";
  case DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE:
    return "cp-array-base";
  case DOL_GX_RECOMP_EVENT_CP_ARRAY_STRIDE:
    return "cp-array-stride";
  case DOL_GX_RECOMP_EVENT_INDEXED_SPAN:
    return "indexed-span";
  case DOL_GX_RECOMP_EVENT_TEXTURE:
    return "texture";
  case DOL_GX_RECOMP_EVENT_TLUT:
    return "tlut";
  case DOL_GX_RECOMP_EVENT_COPY_DESTINATION:
    return "copy-destination";
  case DOL_GX_RECOMP_EVENT_BP_REG:
    return "bp-reg";
  case DOL_GX_RECOMP_EVENT_XF_LOAD:
    return "xf-load";
  case DOL_GX_RECOMP_EVENT_CULL_ALL:
    return "cull-all";
  case DOL_GX_RECOMP_EVENT_DRAW:
    return "draw";
  case DOL_GX_RECOMP_EVENT_INDEXED_XF_LOAD:
    return "indexed-xf-load";
  case DOL_GX_RECOMP_EVENT_CP_VCD:
    return "cp-vcd";
  case DOL_GX_RECOMP_EVENT_CP_VAT:
    return "cp-vat";
  case DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT:
    return "vertex-layout";
  case DOL_GX_RECOMP_EVENT_INVALIDATE_VTX_CACHE:
    return "invalidate-vtx-cache";
  default:
    return "unknown";
  }
}

} // namespace gxruntime::aurora_recomp
