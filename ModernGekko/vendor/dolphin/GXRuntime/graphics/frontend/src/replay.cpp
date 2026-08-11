// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/aurora_recomp/replay.hpp"

#include "gxruntime/aurora_recomp/render_sink.hpp"
#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"

#include <cstdio>
#include <cstring>
#include <memory>

namespace gxruntime::aurora_recomp::replay {
namespace {

constexpr std::uint64_t kFnvBasis = 1469598103934665603ull;
constexpr std::uint64_t kFnvPrime = 1099511628211ull;

void fnv_bytes(std::uint64_t& hash, const void* data, std::size_t size) {
  const auto* bytes = static_cast<const std::uint8_t*>(data);
  for (std::size_t i = 0; i < size; ++i) {
    hash ^= bytes[i];
    hash *= kFnvPrime;
  }
}

void fnv_u32(std::uint64_t& hash, std::uint32_t value) {
  for (unsigned i = 0; i < 4u; ++i) {
    hash ^= static_cast<std::uint8_t>(value >> (i * 8u));
    hash *= kFnvPrime;
  }
}

struct ReplayContext {
  std::vector<std::uint8_t> mem1;
  RetailGxFrontend frontend;
  ConsumingAuroraRenderSink sink;
  std::uint64_t content_fnv = kFnvBasis;
  std::uint64_t state_fnv = kFnvBasis;
};

bool mem1_resolver(void* user, u32 address, u32 size,
                   DolGuestAddressSpace space, DolGuestResourceKind resource,
                   DolGuestResolvedRange* out) {
  auto* ctx = static_cast<ReplayContext*>(user);
  if (out == nullptr || size == 0u)
    return false;
  const u32 physical = dol_gx_recomp_guest_to_physical(address);
  if (physical >= ctx->mem1.size() || size > ctx->mem1.size() - physical)
    return false;
  *out = {
      .data = ctx->mem1.data() + physical,
      .address = address,
      .size = size,
      .available = static_cast<u32>(ctx->mem1.size() - physical),
      .space = space,
      .resource = resource,
  };
  return true;
}

// Fold each span-complete draw into the frame's content/state digests. Runs
// once per draw (on the next draw's arrival or at flush_assembly).
void digest_draw_observer(const ConsumedDraw& draw, unsigned long long,
                          void* user) {
  auto* ctx = static_cast<ReplayContext*>(user);
  fnv_bytes(ctx->content_fnv, draw.vertex_payload.data(),
            draw.vertex_payload.size());
  std::vector<AssembledElement> elements;
  const AssembledDrawStats stats = assemble_consumed_draw(draw, &elements);
  fnv_u32(ctx->content_fnv, stats.ok ? 1u : 0u);
  for (const AssembledElement& element : elements) {
    fnv_u32(ctx->content_fnv, element.attr);
    fnv_u32(ctx->content_fnv, element.vertex);
    fnv_u32(ctx->content_fnv, element.index);
    if (element.host_element != nullptr)
      fnv_bytes(ctx->content_fnv, element.host_element, element.element_size);
  }

  fnv_u32(ctx->state_fnv, draw.transform_flags);
  fnv_u32(ctx->state_fnv, draw.current_pn_matrix);
  fnv_u32(ctx->state_fnv, draw.payload_pn_matrix_mask);
  fnv_u32(ctx->state_fnv, draw.position_matrix_valid_mask);
  fnv_u32(ctx->state_fnv, draw.projection_type);
  fnv_bytes(ctx->state_fnv, draw.viewport, sizeof draw.viewport);
  fnv_bytes(ctx->state_fnv, draw.projection, sizeof draw.projection);
  fnv_bytes(ctx->state_fnv, draw.position_matrices,
            sizeof draw.position_matrices);
}

std::string frontend_error_detail(const RetailGxFrontend& frontend) {
  char buf[160];
  std::snprintf(buf, sizeof buf,
                "%s (opcode=0x%02X offset=%zu detail=%u,%u,%u,%u)",
                frontend.last_error() != nullptr ? frontend.last_error()
                                                 : "unknown",
                static_cast<unsigned>(frontend.last_error_opcode()),
                frontend.last_error_offset(), frontend.last_error_a(),
                frontend.last_error_b(), frontend.last_error_c(),
                frontend.last_error_d());
  return buf;
}

} // namespace

ReplayResult replay_trace(trace::TraceReader& reader,
                          RetailGxFrontend::TraceEventObserver event_observer,
                          void* event_observer_user) {
  ReplayResult result;
  auto ctx = std::make_unique<ReplayContext>();
  const std::uint32_t mem1_size =
      reader.header().mem1_size != 0u ? reader.header().mem1_size : 0x01800000u;
  ctx->mem1.assign(mem1_size, 0u);

  DolGuestAddressResolver resolver;
  dol_guest_address_resolver_init_callback(&resolver, mem1_resolver,
                                           ctx.get());
  ctx->frontend.reset(&resolver);
  ctx->frontend.set_event_observer(event_observer, event_observer_user);
  ctx->frontend.set_packet_drain_enabled(true);
  ctx->sink.reset();
  ctx->sink.set_streaming(true);
  // Resolve through the frontend's persistent resolver copy (the local above
  // is stack-scoped) — same wiring as the backend shadow path.
  ctx->sink.set_guest_resolver(&ctx->frontend.state().resolver);
  ctx->sink.set_draw_observer(digest_draw_observer, ctx.get());

  std::uint32_t current_frame = 0;
  bool frame_open = false;
  unsigned long long record_index = 0;
  unsigned long long last_draws = 0;
  unsigned long long last_zero_draws = 0;
  unsigned long long last_verts = 0;
  unsigned long long last_topo = 0;
  unsigned long long last_store = 0;
  unsigned long long last_elems = 0;

  auto fail = [&](const std::string& message) {
    result.parse_ok = false;
    char prefix[64];
    std::snprintf(prefix, sizeof prefix, "record %llu frame %u: ",
                  record_index, current_frame);
    result.error = prefix + message;
  };

  // Frame boundary: assemble the frame's final draw so its extents and
  // digests are folded in (same as the backend at present). Traces recorded
  // by the backend close every frame with PRESENT_STATS; converted traces
  // (dff2dolt) carry no Aurora stats, so their frames close at the next
  // FRAME_BEGIN or at end-of-trace instead.
  auto close_frame = [&](const trace::PresentStats* stats) {
    ctx->sink.flush_assembly();
    FrameDigest digest;
    digest.frame_index = current_frame != 0u
                             ? current_frame
                             : (stats != nullptr ? stats->frame_index : 0u);
    digest.draws = ctx->sink.draw_packets() - last_draws;
    digest.zero_draws = ctx->frontend.zero_vertex_draws() - last_zero_draws;
    last_zero_draws = ctx->frontend.zero_vertex_draws();
    digest.vert_bytes = ctx->sink.raw_vertex_bytes() - last_verts;
    digest.topo_bytes = ctx->sink.topology_index_bytes() - last_topo;
    digest.store_bytes = ctx->sink.storage_bytes() - last_store;
    digest.elements = ctx->sink.assembled_elements() - last_elems;
    last_draws = ctx->sink.draw_packets();
    last_verts = ctx->sink.raw_vertex_bytes();
    last_topo = ctx->sink.topology_index_bytes();
    last_store = ctx->sink.storage_bytes();
    last_elems = ctx->sink.assembled_elements();
    digest.content_fnv = ctx->content_fnv;
    digest.state_fnv = ctx->state_fnv;
    ctx->content_fnv = kFnvBasis;
    ctx->state_fnv = kFnvBasis;
    if (stats != nullptr) {
      digest.has_stats = true;
      digest.stats = *stats;
    }
    result.frames.push_back(digest);
    frame_open = false;
  };

  trace::RecordView record;
  while (result.parse_ok && reader.next(record)) {
    ++record_index;
    switch (record.kind) {
    case trace::RecordKind::FrameBegin: {
      std::uint32_t frame_index = 0;
      if (!trace::decode_frame_begin(record, frame_index)) {
        fail("malformed FRAME_BEGIN");
        break;
      }
      if (frame_open)
        close_frame(nullptr);
      current_frame = frame_index;
      frame_open = true;
      break;
    }
    case trace::RecordKind::GxWrite: {
      std::uint8_t size = 0;
      std::uint64_t value = 0;
      if (!trace::decode_gx_write(record, size, value)) {
        fail("malformed GX_WRITE");
        break;
      }
      // Reconstruct the big-endian WGPIPE bytes exactly as the backend's
      // shadow write does, preserving the recorded fragmentation.
      std::uint8_t bytes[8] = {};
      if (size != 1u && size != 2u && size != 4u && size != 8u) {
        fail("GX_WRITE with unsupported size");
        break;
      }
      for (unsigned i = 0; i < size; ++i)
        bytes[i] =
            static_cast<std::uint8_t>(value >> ((size - 1u - i) * 8u));
      if (!ctx->frontend.write_fifo({bytes, size}) ||
          !ctx->frontend.flush(&ctx->sink)) {
        fail("frontend rejected FIFO: " + frontend_error_detail(ctx->frontend));
        break;
      }
      break;
    }
    case trace::RecordKind::CallDisplayList: {
      std::uint32_t guest_addr = 0;
      std::span<const std::uint8_t> bytes;
      if (!trace::decode_call_display_list(record, guest_addr, bytes)) {
        fail("malformed CALL_DL");
        break;
      }
      if (!ctx->frontend.write_display_list(bytes, &ctx->sink)) {
        fail("frontend rejected display list: " +
             frontend_error_detail(ctx->frontend));
        break;
      }
      break;
    }
    case trace::RecordKind::SetArray: {
      std::uint8_t attr = 0;
      std::uint32_t guest_addr = 0;
      std::uint16_t stride = 0;
      if (!trace::decode_set_array(record, attr, guest_addr, stride) ||
          stride > 0xFFu) {
        fail("malformed SET_ARRAY");
        break;
      }
      if (!ctx->frontend.set_cp_array(attr, guest_addr,
                                      static_cast<std::uint8_t>(stride))) {
        fail("set_cp_array rejected");
        break;
      }
      break;
    }
    case trace::RecordKind::MemUpdate: {
      std::uint32_t guest_addr = 0;
      std::span<const std::uint8_t> bytes;
      if (!trace::decode_mem_update(record, guest_addr, bytes)) {
        fail("malformed MEM_UPDATE");
        break;
      }
      const u32 physical = dol_gx_recomp_guest_to_physical(guest_addr);
      if (physical >= ctx->mem1.size() ||
          bytes.size() > ctx->mem1.size() - physical) {
        fail("MEM_UPDATE outside shadow MEM1");
        break;
      }
      std::memcpy(ctx->mem1.data() + physical, bytes.data(), bytes.size());
      break;
    }
    case trace::RecordKind::PresentStats: {
      trace::PresentStats stats{};
      if (!trace::decode_present_stats(record, stats)) {
        fail("malformed PRESENT_STATS");
        break;
      }
      close_frame(&stats);
      break;
    }
    default:
      // Unknown kinds are forward-compatible: skip.
      break;
    }
  }
  if (result.parse_ok && frame_open)
    close_frame(nullptr);

  if (result.parse_ok && ctx->sink.failure_reason() != nullptr)
    fail(std::string("sink invariant failure: ") + ctx->sink.failure_reason());
  result.truncated = reader.truncated();
  return result;
}

std::string format_digest_line(const FrameDigest& f) {
  char buf[208];
  std::snprintf(buf, sizeof buf,
                "frame %u draws %llu zdraws %llu verts %llu topo %llu "
                "store %llu elems %llu fnv %016llx state %016llx",
                f.frame_index, f.draws, f.zero_draws, f.vert_bytes,
                f.topo_bytes, f.store_bytes, f.elements,
                static_cast<unsigned long long>(f.content_fnv),
                static_cast<unsigned long long>(f.state_fnv));
  return buf;
}

StatsCompareResult compare_against_stats(const ReplayResult& result) {
  StatsCompareResult r;
  unsigned long long consecutive = 0;
  // AuroraStats are published by the render worker one present late
  // (aurora/lib/gfx/common.cpp end_frame -> render_worker::enqueue_end_frame
  // copies the counters into g_stats on the worker), so the stats the
  // recorder sampled at present N describe frame N-1. Gate each frame's
  // replay counters against the NEXT frame's recorded stats; the window's
  // last frame has no partner and is ungated. Steady-state scenes are
  // shift-invariant; gameplay is not.
  for (std::size_t i = 0; i + 1 < result.frames.size(); ++i) {
    const FrameDigest& f = result.frames[i];
    const FrameDigest& next = result.frames[i + 1];
    if (!next.has_stats)
      continue;
    if (next.frame_index != f.frame_index + 1u)
      continue; // never gate across a frame-window gap
    ++r.frames_compared;
    const bool draw_match =
        f.draws + f.zero_draws == next.stats.draw_call_count;
    const unsigned long long slack = 4ull * f.draws + 4ull;
    const bool vert_match =
        next.stats.last_vert_size >= f.vert_bytes &&
        (next.stats.last_vert_size - f.vert_bytes) <= slack;
    if (draw_match && vert_match) {
      consecutive = 0;
      continue;
    }
    ++r.mismatch_frames;
    ++consecutive;
    if (consecutive > r.worst_consecutive)
      r.worst_consecutive = consecutive;
    if (r.detail.empty()) {
      char buf[176];
      std::snprintf(buf, sizeof buf,
                    "frame %u (stats@%u): draws replay=%llu+%lluz stats=%u, "
                    "vertB replay=%llu stats=%u slack=%llu",
                    f.frame_index, next.frame_index, f.draws, f.zero_draws,
                    next.stats.draw_call_count, f.vert_bytes,
                    next.stats.last_vert_size, slack);
      r.detail = buf;
    }
  }
  if (r.frames_compared == 0u) {
    r.ok = false;
    r.detail = "no gateable frame pairs (stats gate one present behind)";
    return r;
  }
  r.ok = r.worst_consecutive <= 2u;
  return r;
}

} // namespace gxruntime::aurora_recomp::replay
