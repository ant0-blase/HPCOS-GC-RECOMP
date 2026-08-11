// SPDX-License-Identifier: GPL-3.0-or-later
#include "aurora_backend_private.h"
#include <aurora/aurora.h>
#include <aurora/gfx.h>
#include <dolphin/gx.h>
#include <dolphin/gx/GXAurora.h>
#include <dolphin/gx/GXCommandList.h>
#include <dolphin/vi.h>
#include <gx/fifo.hpp>
#include <gx/gx.hpp>
#include <gx/recomp.hpp>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <span>

#if GXRUNTIME_HAS_AURORA_RECOMP
// gxcore substrate submission lives in the Aurora fork (lib/gfx/gxcore_draw.cpp),
// linked into this binary via aurora::gx.
namespace aurora::gfx::gxcore {
bool submit_draw_plan(const gxruntime::gxcore::DrawPlan& plan);
void copy_efb_to_texture(const gxruntime::gxcore::EfbCopyCommand& cmd);
void reset_texture_cache();
} // namespace aurora::gfx::gxcore
#endif

namespace gx_aurora {

#if GXRUNTIME_HAS_AURORA_RECOMP
void core_plan_observer(const gxruntime::gxcore::DrawPlan& plan, void*) {
    if (!plan.ok)
        return; // skip reasons are tallied in the sink gap counters
    if (aurora::gfx::gxcore::submit_draw_plan(plan))
        ++g_core_submitted;
    else
        ++g_core_rejected;
}

void core_copy_observer(const gxruntime::gxcore::EfbCopyCommand& cmd, void*) {
    aurora::gfx::gxcore::copy_efb_to_texture(cmd);
}
#endif

void write_aurora_command(u16 command) {
    GXParam1u8(GX_AURORA);
    GXParam1u16(command);
}

void flush_pending_resource_metadata() {
    for (u8 slot = 0; slot < g_pending_tluts.size(); ++slot) {
        auto& pending = g_pending_tluts[slot];
        if (!pending.valid)
            continue;
        write_aurora_command(GX_AURORA_LOAD_TLUT);
        GXParam1u8(slot);
        GXCmd1u64(reinterpret_cast<u64>(pending.data));
        GXParam1u32(pending.format);
        GXParam1u16(pending.entries);
        GXParam1u32(pending.object_id);
        GXParam1u32(pending.data_version);
        pending.valid = false;
    }

    for (u8 slot = 0; slot < g_pending_textures.size(); ++slot) {
        auto& pending = g_pending_textures[slot];
        if (!pending.valid)
            continue;
        write_aurora_command(GX_AURORA_LOAD_TEXOBJ);
        GXParam1u8(slot);
        GXCmd1u64(reinterpret_cast<u64>(pending.data));
        GXParam1u32(pending.width);
        GXParam1u32(pending.height);
        GXParam1u32(pending.format);
        GXParam1u32(pending.tlut);
        GXParam1u8(pending.mipmap ? 1 : 0);
        GXParam1u32(pending.object_id);
        GXParam1u32(pending.data_version);
        pending.valid = false;
    }
}

bool gx_attr_to_cp_array(u32 attr, u8* out) {
    if (out == nullptr)
        return false;
    GXAttr cp_attr = static_cast<GXAttr>(attr);
    if (cp_attr == GX_VA_NBT)
        cp_attr = GX_VA_NRM;
    if (cp_attr < GX_VA_POS)
        return false;
    const u32 cp_index = static_cast<u32>(cp_attr) - static_cast<u32>(GX_VA_POS);
    if (cp_index >= DOL_GX_RECOMP_CP_ARRAY_COUNT)
        return false;
    *out = static_cast<u8>(cp_index);
    return true;
}

DolGuestAddressSpace map_address_space(
    aurora::gx::recomp::AddressSpace space) {
    switch (space) {
    case aurora::gx::recomp::AddressSpace::Virtual:
        return DOL_GUEST_ADDRESS_VIRTUAL;
    case aurora::gx::recomp::AddressSpace::Physical:
        return DOL_GUEST_ADDRESS_PHYSICAL;
    case aurora::gx::recomp::AddressSpace::Auto:
    default:
        return DOL_GUEST_ADDRESS_AUTO;
    }
}

DolGuestResourceKind map_resource_kind(aurora::gx::recomp::ResourceKind kind) {
    switch (kind) {
    case aurora::gx::recomp::ResourceKind::Fifo:
        return DOL_GUEST_RESOURCE_FIFO;
    case aurora::gx::recomp::ResourceKind::DisplayList:
        return DOL_GUEST_RESOURCE_DISPLAY_LIST;
    case aurora::gx::recomp::ResourceKind::VertexArray:
        return DOL_GUEST_RESOURCE_VERTEX_ARRAY;
    case aurora::gx::recomp::ResourceKind::Texture:
        return DOL_GUEST_RESOURCE_TEXTURE;
    case aurora::gx::recomp::ResourceKind::Tlut:
        return DOL_GUEST_RESOURCE_TLUT;
    case aurora::gx::recomp::ResourceKind::CopyDestination:
        return DOL_GUEST_RESOURCE_COPY_DESTINATION;
    case aurora::gx::recomp::ResourceKind::Generic:
    default:
        return DOL_GUEST_RESOURCE_GENERIC;
    }
}

bool aurora_guest_address_resolver_bridge(
    void*, std::uint32_t address, std::uint32_t size,
    aurora::gx::recomp::AddressSpace space,
    aurora::gx::recomp::ResourceKind resource, const void** data,
    std::uint32_t* available) {
    if (g_guest_address_resolver == nullptr)
        return false;
    return g_guest_address_resolver(
        g_guest_address_resolver_user, address, size, map_address_space(space),
        map_resource_kind(resource), data, available);
}

#if GXRUNTIME_HAS_AURORA_RECOMP
void shadow_frontend_fail_metadata(const char* reason, u32 attr,
                                   u32 guest_address, u32 value) {
    g_shadow_frontend_failed = true;
    std::fprintf(stderr,
                 "[aurora-recomp] shadow RetailGxFrontend rejected metadata; "
                 "reason=%s attr=%u guest=0x%08X value=%u; "
                 "live Aurora path remains active\n",
                 reason != nullptr ? reason : "unknown", attr, guest_address,
                 value);
}

unsigned long long trace_current_frame() {
    return g_trace_present_scope_frame != 0ull ? g_trace_present_scope_frame
                                               : g_present_count + 1ull;
}

bool trace_open_now() {
    if (g_trace_writer.is_open())
        return true;
    gxruntime::aurora_recomp::trace::TraceHeader header{};
    header.mem1_size = 0x01800000u;
    if (g_guest_address_resolver != nullptr) {
        const void* data = nullptr;
        u32 available = 0;
        if (g_guest_address_resolver(g_guest_address_resolver_user, 0x80000000u,
                                     sizeof header.game_id,
                                     DOL_GUEST_ADDRESS_VIRTUAL,
                                     DOL_GUEST_RESOURCE_GENERIC, &data,
                                     &available) &&
            data != nullptr && available >= sizeof header.game_id) {
            std::memcpy(header.game_id, data, sizeof header.game_id);
        }
    }
    if (!g_trace_writer.open(g_trace_path.c_str(), header)) {
        std::fprintf(stderr, "[trace] failed to open %s; recording disabled\n",
                     g_trace_path.c_str());
        g_trace_armed = false;
        return false;
    }
    return true;
}

bool trace_should_record() {
    if (!g_trace_armed)
        return false;
    const unsigned long long frame = trace_current_frame();
    if (frame < g_trace_first_frame || frame > g_trace_last_frame)
        return false;
    if (!trace_open_now())
        return false;
    if (!g_trace_frame_begun) {
        g_trace_writer.frame_begin(static_cast<u32>(frame));
        g_trace_frame_begun = true;
        ++g_trace_frames_recorded;
    }
    return true;
}

void trace_record_mem_update(u32 address, u32 size, const void* data) {
    if (size == 0 || data == nullptr || !trace_should_record())
        return;
    const u64 key = (static_cast<u64>(address) << 32) | size;
    u64 hash = 1469598103934665603ull;
    const auto* bytes = static_cast<const unsigned char*>(data);
    for (u32 i = 0; i < size; ++i) {
        hash ^= bytes[i];
        hash *= 1099511628211ull;
    }
    const auto it = g_trace_mem_dedup.find(key);
    if (it != g_trace_mem_dedup.end() && it->second == hash)
        return;
    g_trace_mem_dedup[key] = hash;
    g_trace_writer.mem_update(address, data, size);
}

void trace_close_and_log() {
    if (!g_trace_writer.is_open()) {
        g_trace_armed = false;
        return;
    }
    const unsigned long long records = g_trace_writer.records_written();
    const unsigned long long bytes = g_trace_writer.bytes_written();
    const bool ok = g_trace_writer.close();
    g_trace_armed = false;
    std::fprintf(stderr,
                 "[trace] wrote %s frames=%llu records=%llu bytes=%llu%s\n",
                 g_trace_path.c_str(), g_trace_frames_recorded, records, bytes,
                 ok ? "" : " (WRITE ERRORS)");
}

void trace_on_present() {
    if (g_trace_armed && trace_should_record()) {
        const AuroraStats* stats = aurora_get_stats();
        gxruntime::aurora_recomp::trace::PresentStats ps{};
        ps.frame_index = static_cast<u32>(trace_current_frame());
        ps.queued_pipelines = stats->queuedPipelines;
        ps.created_pipelines = stats->createdPipelines;
        ps.draw_call_count = stats->drawCallCount;
        ps.merged_draw_call_count = stats->mergedDrawCallCount;
        ps.last_vert_size = stats->lastVertSize;
        ps.last_uniform_size = stats->lastUniformSize;
        ps.last_index_size = stats->lastIndexSize;
        ps.last_storage_size = stats->lastStorageSize;
        ps.last_texture_upload_size = stats->lastTextureUploadSize;
        g_trace_writer.present_stats(ps);
    }
    if (g_trace_armed && g_present_count >= g_trace_last_frame)
        trace_close_and_log();
    g_trace_present_scope_frame = 0ull;
    g_trace_frame_begun = false;
}

void shadow_frontend_set_array(u32 attr, u32 guest_address, u8 stride) {
    if (!g_shadow_frontend_enabled || g_shadow_frontend_failed)
        return;
    u8 cp_attr = 0;
    if (!gx_attr_to_cp_array(attr, &cp_attr)) {
        shadow_frontend_fail_metadata("unsupported GX array attribute", attr,
                                      guest_address, stride);
        return;
    }
    const u32 physical = dol_gx_recomp_guest_to_physical(guest_address);
    if (trace_should_record())
        g_trace_writer.set_array(cp_attr, physical, stride);
    if (!g_shadow_frontend.set_cp_array(cp_attr, physical, stride)) {
        shadow_frontend_fail_metadata("failed to mirror CP array state", attr,
                                      guest_address, stride);
    }
}

bool frontend_guest_address_resolver_bridge(
    void*, u32 address, u32 size, DolGuestAddressSpace space,
    DolGuestResourceKind resource, DolGuestResolvedRange* out) {
    if (g_guest_address_resolver == nullptr || out == nullptr)
        return false;
    const void* data = nullptr;
    u32 available = 0;
    if (!g_guest_address_resolver(g_guest_address_resolver_user, address, size,
                                  space, resource, &data, &available) ||
        data == nullptr || available < size)
        return false;
    *out = {
        .data = const_cast<void*>(data),
        .address = address,
        .size = size,
        .available = available,
        .space = space,
        .resource = resource,
    };
    trace_record_mem_update(address, size, data);
    return true;
}

void shadow_frontend_call_display_list(const void* data, u32 size) {
    if (!g_shadow_frontend_enabled || g_shadow_frontend_failed)
        return;
    const std::span<const std::uint8_t> bytes(
        static_cast<const std::uint8_t*>(data), size);
    if (g_gx_core_enabled) {
        if (!g_shadow_frontend.write_display_list(bytes, &g_core_sink)) {
            g_shadow_frontend_failed = true;
            std::fprintf(stderr,
                         "[gx-core] frontend rejected HLE display list "
                         "(%u bytes): %s (opcode=0x%02X)\n",
                         size,
                         g_shadow_frontend.last_error() != nullptr
                             ? g_shadow_frontend.last_error()
                             : "none",
                         static_cast<unsigned>(
                             g_shadow_frontend.last_error_opcode()));
        }
        return;
    }
    if (!g_shadow_frontend.write_display_list(bytes, &g_shadow_packet_sink)) {
        g_shadow_frontend_failed = true;
        std::fprintf(stderr,
                     "[aurora-recomp] shadow RetailGxFrontend rejected HLE "
                     "display list (%u bytes): parse_error=%s opcode=0x%02X "
                     "offset=%llu a=%u b=%u c=%u d=%u; live Aurora path "
                     "remains active\n",
                     size,
                     g_shadow_frontend.last_error() != nullptr
                         ? g_shadow_frontend.last_error()
                         : "none",
                     static_cast<unsigned>(
                         g_shadow_frontend.last_error_opcode()),
                     static_cast<unsigned long long>(
                         g_shadow_frontend.last_error_offset()),
                     g_shadow_frontend.last_error_a(),
                     g_shadow_frontend.last_error_b(),
                     g_shadow_frontend.last_error_c(),
                     g_shadow_frontend.last_error_d());
    }
}

void shadow_frontend_write(u64 value, u8 size) {
    if (!g_shadow_frontend_enabled || g_shadow_frontend_failed)
        return;
    std::uint8_t bytes[8] = {};
    switch (size) {
    case 1:
        bytes[0] = static_cast<std::uint8_t>(value);
        break;
    case 2:
        bytes[0] = static_cast<std::uint8_t>(value >> 8u);
        bytes[1] = static_cast<std::uint8_t>(value);
        break;
    case 4:
        bytes[0] = static_cast<std::uint8_t>(value >> 24u);
        bytes[1] = static_cast<std::uint8_t>(value >> 16u);
        bytes[2] = static_cast<std::uint8_t>(value >> 8u);
        bytes[3] = static_cast<std::uint8_t>(value);
        break;
    case 8:
        for (unsigned i = 0; i < 8; ++i)
            bytes[i] =
                static_cast<std::uint8_t>(value >> ((7u - i) * 8u));
        break;
    default:
        return;
    }
    const std::span<const std::uint8_t> fragment(bytes, size);
    if (g_gx_core_enabled) {
        if (!g_shadow_frontend.write_fifo(fragment) ||
            !g_shadow_frontend.flush(&g_core_sink)) {
            g_shadow_frontend_failed = true;
            std::fprintf(stderr,
                         "[gx-core] frontend rejected FIFO after %llu byte(s): "
                         "%s (opcode=0x%02X offset=%llu); consumer=%s\n",
                         g_fifo_bytes,
                         g_shadow_frontend.last_error() != nullptr
                             ? g_shadow_frontend.last_error()
                             : "none",
                         static_cast<unsigned>(
                             g_shadow_frontend.last_error_opcode()),
                         static_cast<unsigned long long>(
                             g_shadow_frontend.last_error_offset()),
                         g_core_sink.failure_reason() != nullptr
                             ? g_core_sink.failure_reason()
                             : "none");
        }
        return;
    }
    if (!g_shadow_frontend.write_fifo(fragment) ||
        !g_shadow_frontend.flush(&g_shadow_packet_sink)) {
        g_shadow_frontend_failed = true;
        const auto& failed = g_shadow_packet_sink.failed_packet();
        std::fprintf(stderr,
                     "[aurora-recomp] shadow RetailGxFrontend rejected FIFO "
                     "after %llu byte(s), packets=%llu "
                     "(stream=%llu state=%llu resource=%llu draw=%llu); "
                     "write_size=%u write_value=0x%016llX; "
                     "parse_error=%s parse_opcode=0x%02X "
                     "parse_offset=%llu pending=%llu "
                     "detail=(%u,%u,%u,%u); "
                     "reason=%s seq=%u event=%s(%u) "
                     "a=%u b=%u c=%u d=%u; "
                     "live Aurora path remains active\n",
                     g_fifo_bytes, g_shadow_packet_sink.packets(),
                     g_shadow_packet_sink.stream_packets(),
                     g_shadow_packet_sink.state_packets(),
                     g_shadow_packet_sink.resource_packets(),
                     g_shadow_packet_sink.draw_packets(),
                     static_cast<unsigned>(size),
                     static_cast<unsigned long long>(value),
                     g_shadow_frontend.last_error() != nullptr
                         ? g_shadow_frontend.last_error()
                         : "none",
                     static_cast<unsigned>(
                         g_shadow_frontend.last_error_opcode()),
                     static_cast<unsigned long long>(
                         g_shadow_frontend.last_error_offset()),
                     static_cast<unsigned long long>(
                         g_shadow_frontend.pending_fifo_size()),
                     g_shadow_frontend.last_error_a(),
                     g_shadow_frontend.last_error_b(),
                     g_shadow_frontend.last_error_c(),
                     g_shadow_frontend.last_error_d(),
                     g_shadow_packet_sink.failure_reason() != nullptr
                         ? g_shadow_packet_sink.failure_reason()
                         : "frontend-parse",
                     failed.sequence,
                     gxruntime::aurora_recomp::trace_event_name(
                         failed.event.kind),
                     static_cast<unsigned>(failed.event.kind), failed.event.a,
                     failed.event.b, failed.event.c, failed.event.d);
    }
}

unsigned long long shadow_transform_frame_number() {
    return g_frame_open ? g_present_count + 1ull : g_present_count;
}

void log_transform_matrix(const char* label, unsigned index,
                           const float* values) {
    std::fprintf(stderr,
                 "[gfx] draw-transform %s[%u] "
                 "%.8g %.8g %.8g %.8g | %.8g %.8g %.8g %.8g | "
                 "%.8g %.8g %.8g %.8g\n",
                 label, index, values[0], values[1], values[2], values[3],
                 values[4], values[5], values[6], values[7], values[8],
                 values[9], values[10], values[11]);
}

void shadow_transform_observer(
    const gxruntime::aurora_recomp::ConsumedDraw& draw,
    unsigned long long cumulative_draw, void*) {
    const std::size_t frame_draw = g_shadow_transform_next_draw_index++;
    if (!g_shadow_transform_log_enabled ||
        g_shadow_transform_log_count >= g_shadow_transform_log_limit)
        return;
    const unsigned long long frame = shadow_transform_frame_number();
    if (g_shadow_transform_log_min_frame != 0ull &&
        frame < g_shadow_transform_log_min_frame)
        return;
    if (g_shadow_transform_log_frame != 0ull &&
        g_shadow_transform_log_frame != frame)
        return;
    if (g_shadow_transform_log_draw >= 0 &&
        static_cast<unsigned long>(g_shadow_transform_log_draw) != frame_draw)
        return;
    if (g_shadow_transform_log_sequence_enabled &&
        g_shadow_transform_log_sequence != draw.sequence)
        return;
    if (g_shadow_light_log_lit_only) {
        bool lit = false;
        for (unsigned c = 0; c < 4 && !lit; ++c) {
            if ((draw.chan_reg_mask & (1u << (5u + c))) == 0u)
                continue;
            const std::uint32_t ctrl = draw.chan_regs[5u + c];
            const std::uint32_t mask =
                ((ctrl >> 2u) & 0xFu) | (((ctrl >> 11u) & 0xFu) << 4u);
            lit = ((ctrl >> 1u) & 0x1u) != 0u && mask != 0u;
        }
        if (!lit)
            return;
    }

    ++g_shadow_transform_log_count;
    std::uint32_t pn_used_mask = 0u;
    if ((draw.transform_flags &
         gxruntime::aurora_recomp::kDrawTransformPayloadPnMatrixValid) != 0u &&
        draw.payload_pn_matrix_mask != 0u) {
        pn_used_mask = draw.payload_pn_matrix_mask;
    } else if (draw.current_pn_matrix < DOL_GX_RECOMP_POSITION_MATRIX_COUNT) {
        pn_used_mask = 1u << draw.current_pn_matrix;
    }
    const std::uint32_t pn_valid_used =
        pn_used_mask & draw.position_matrix_valid_mask;
    std::fprintf(stderr,
                 "[gfx] draw-transform frame=%llu draw=%zu seq=%u "
                 "total=%llu prim=0x%02X fmt=%u count=%u vsize=%u "
                 "payload=%zu cull=%d tex=%u:0x%08X flags=0x%X "
                 "current_pn=%u payload_pn_mask=0x%03X pn_used=0x%03X "
                 "pn_valid=0x%03X pos_valid=0x%03X arrays=%u active=0x%04X\n",
                 frame, frame_draw, draw.sequence, cumulative_draw,
                 draw.primitive, draw.vtx_fmt, draw.vertex_count,
                 draw.vertex_size, draw.vertex_payload.size(),
                 draw.cull_all ? 1 : 0, draw.texture.slot,
                 draw.texture.address, draw.transform_flags,
                 draw.current_pn_matrix, draw.payload_pn_matrix_mask,
                 pn_used_mask, pn_valid_used,
                 draw.position_matrix_valid_mask, draw.array_input_count,
                 draw.active_array_mask);
    if ((draw.transform_flags &
         gxruntime::aurora_recomp::kDrawTransformViewportValid) != 0u) {
        std::fprintf(stderr,
                     "[gfx] draw-transform viewport %.8g %.8g %.8g %.8g "
                     "%.8g %.8g\n",
                     draw.viewport[0], draw.viewport[1], draw.viewport[2],
                     draw.viewport[3], draw.viewport[4], draw.viewport[5]);
    } else {
        std::fprintf(stderr, "[gfx] draw-transform viewport invalid\n");
    }
    if ((draw.transform_flags &
         gxruntime::aurora_recomp::kDrawTransformProjectionValid) != 0u) {
        std::fprintf(stderr,
                     "[gfx] draw-transform projection type=%u %.8g %.8g "
                     "%.8g %.8g %.8g %.8g\n",
                     draw.projection_type, draw.projection[0],
                     draw.projection[1], draw.projection[2],
                     draw.projection[3], draw.projection[4],
                     draw.projection[5]);
    } else {
        std::fprintf(stderr, "[gfx] draw-transform projection invalid\n");
    }
    for (unsigned i = 0; i < DOL_GX_RECOMP_POSITION_MATRIX_COUNT; ++i) {
        const std::uint32_t bit = 1u << i;
        if ((pn_used_mask & bit) == 0u)
            continue;
        if ((draw.position_matrix_valid_mask & bit) == 0u) {
            std::fprintf(stderr,
                         "[gfx] draw-transform pnmtx[%u] invalid\n", i);
            continue;
        }
        log_transform_matrix("pnmtx", i, draw.position_matrices[i]);
    }
    if (!g_shadow_light_log_enabled)
        return;
    std::fprintf(stderr,
                 "[gfx] draw-light frame=%llu draw=%zu chan_mask=0x%03X "
                 "numchans=%u amb0=0x%08X amb1=0x%08X mat0=0x%08X "
                 "mat1=0x%08X\n",
                 frame, frame_draw, draw.chan_reg_mask,
                 (draw.chan_reg_mask & 0x1u) != 0u ? draw.chan_regs[0] : 0u,
                 draw.chan_regs[1], draw.chan_regs[2], draw.chan_regs[3],
                 draw.chan_regs[4]);
    static const char* const kChanNames[4] = {"cctrl0", "cctrl1", "actrl0",
                                               "actrl1"};
    for (unsigned c = 0; c < 4; ++c) {
        if ((draw.chan_reg_mask & (1u << (5u + c))) == 0u)
            continue;
        const std::uint32_t ctrl = draw.chan_regs[5u + c];
        const unsigned matsrc = ctrl & 0x1u;
        const unsigned lit = (ctrl >> 1u) & 0x1u;
        const unsigned ambsrc = (ctrl >> 6u) & 0x1u;
        const unsigned diffunc = (ctrl >> 7u) & 0x3u;
        const unsigned attnfunc = (ctrl >> 9u) & 0x3u;
        const unsigned light_mask =
            ((ctrl >> 2u) & 0xFu) | (((ctrl >> 11u) & 0xFu) << 4u);
        std::fprintf(stderr,
                     "[gfx] draw-light %s=0x%08X lit=%u matsrc=%u ambsrc=%u "
                     "diffunc=%u attnfunc=%u lights=0x%02X\n",
                     kChanNames[c], ctrl, lit, matsrc, ambsrc, diffunc,
                     attnfunc, light_mask);
    }
    for (unsigned i = 0; i < DOL_GX_RECOMP_LIGHT_COUNT; ++i) {
        if (draw.light_word_mask[i] == 0u)
            continue;
        float f[16];
        std::memcpy(f, draw.light_words[i], sizeof(f));
        std::fprintf(stderr,
                     "[gfx] draw-light light[%u] mask=0x%04X col=0x%08X "
                     "cos=%.8g,%.8g,%.8g dist=%.8g,%.8g,%.8g "
                     "pos=%.8g,%.8g,%.8g dir=%.8g,%.8g,%.8g\n",
                     i, draw.light_word_mask[i], draw.light_words[i][3],
                     f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11], f[12],
                     f[13], f[14], f[15]);
    }
}
#endif

} // namespace gx_aurora

extern "C" {

void aurora_backend_present(void) {
    if (!gx_aurora::g_initialized)
        return;
#if GXRUNTIME_HAS_AURORA_RECOMP
    if (gx_aurora::g_gx_core_enabled && !gx_aurora::g_shadow_frontend_failed)
        gx_aurora::g_core_sink.flush_frame();
    if (gx_aurora::g_gx_core_enabled) {
        static int s_cutscene_diag = -1;
        if (s_cutscene_diag < 0)
            s_cutscene_diag = std::getenv("STRIKERS_CUTSCENE_DIAG") != nullptr ? 1 : 0;
        if (s_cutscene_diag) {
            static gxruntime::gxcore::GapCounters s_prev{};
            const gxruntime::gxcore::GapCounters& c = gx_aurora::g_core_sink.counters();
            std::fprintf(stderr,
                "[cutscene] present=%llu planned=%llu skipped=%llu cull=%llu "
                "missing_vcd=%llu vtx_fail=%llu\n",
                gx_aurora::g_present_count + 1,
                c.draws_planned - s_prev.draws_planned,
                c.draws_skipped - s_prev.draws_skipped,
                c.cull_all_draws - s_prev.cull_all_draws,
                c.missing_vcd - s_prev.missing_vcd,
                c.vertex_decode_failures - s_prev.vertex_decode_failures);
            s_prev = c;
        }
    }
#endif
    if (gx_aurora::g_frame_open) {
        aurora_end_frame();
        gx_aurora::g_frame_open = false;
    }
    ++gx_aurora::g_present_count;
    if (gx_aurora::g_frame_pacing_log &&
        (gx_aurora::g_present_count <= 10 || (gx_aurora::g_present_count % 60) == 0)) {
        const AuroraStats* stats = aurora_get_stats();
        std::fprintf(stderr,
                     "[frame-pacing] frame=%llu fps=%.1f draws=%u "
                     "texture-upload=%u fifo=%llu\n",
                     gx_aurora::g_present_count, aurora_get_fps(), stats->drawCallCount,
                     stats->lastTextureUploadSize, gx_aurora::g_fifo_bytes);
    }
    if (gx_aurora::g_graphics_log) {
        const AuroraStats* s = aurora_get_stats();
        std::fprintf(stderr,
                     "[gfxN] present=%llu draws=%u merged=%u verts=%u indices=%u "
                     "fifo=%llu\n",
                     gx_aurora::g_present_count, s->drawCallCount, s->mergedDrawCallCount,
                     s->lastVertSize, s->lastIndexSize, gx_aurora::g_fifo_bytes);
    }
#if GXRUNTIME_HAS_AURORA_RECOMP
    gx_aurora::g_trace_present_scope_frame = gx_aurora::g_present_count;
    if (gx_aurora::g_shadow_frontend_enabled && !gx_aurora::g_gx_core_enabled) {
        gx_aurora::g_shadow_packet_sink.flush_assembly();
        const AuroraStats* astats = aurora_get_stats();
        const unsigned long long fe_draw_total = gx_aurora::g_shadow_packet_sink.draw_packets();
        const unsigned long long fe_vtx_total = gx_aurora::g_shadow_packet_sink.vertex_inputs();
        const unsigned long long fe_zero_draw_total =
            gx_aurora::g_shadow_frontend.zero_vertex_draws();
        const unsigned long long fe_frame_draws =
            fe_draw_total - gx_aurora::g_shadow_last_draw_total;
        const unsigned long long fe_frame_verts =
            fe_vtx_total - gx_aurora::g_shadow_last_vertex_total;
        const unsigned long long fe_frame_zero_draws =
            fe_zero_draw_total - gx_aurora::g_shadow_last_zero_draw_total;
        gx_aurora::g_shadow_last_draw_total = fe_draw_total;
        gx_aurora::g_shadow_last_vertex_total = fe_vtx_total;
        gx_aurora::g_shadow_last_zero_draw_total = fe_zero_draw_total;
        const unsigned long long fe_rawvert_total =
            gx_aurora::g_shadow_packet_sink.raw_vertex_bytes();
        const unsigned long long fe_topoidx_total =
            gx_aurora::g_shadow_packet_sink.topology_index_bytes();
        const unsigned long long fe_storage_total =
            gx_aurora::g_shadow_packet_sink.storage_bytes();
        const unsigned long long fe_frame_rawvert =
            fe_rawvert_total - gx_aurora::g_shadow_last_rawvert_total;
        const unsigned long long fe_frame_topoidx =
            fe_topoidx_total - gx_aurora::g_shadow_last_topoidx_total;
        const unsigned long long fe_frame_storage =
            fe_storage_total - gx_aurora::g_shadow_last_storage_total;
        gx_aurora::g_shadow_last_rawvert_total = fe_rawvert_total;
        gx_aurora::g_shadow_last_topoidx_total = fe_topoidx_total;
        gx_aurora::g_shadow_last_storage_total = fe_storage_total;
        const bool have_prev = gx_aurora::g_shadow_prev_frame_valid;
        const bool draw_match =
            !have_prev ||
            (!gx_aurora::g_shadow_frontend_failed &&
             gx_aurora::g_shadow_prev_draws + gx_aurora::g_shadow_prev_zero_draws ==
                 astats->drawCallCount);
        if (!draw_match)
            ++gx_aurora::g_shadow_draw_mismatch_frames;
        const unsigned long long vert_align_slack =
            4ull * gx_aurora::g_shadow_prev_draws + 4ull;
        const bool vert_extent_match =
            !have_prev ||
            (!gx_aurora::g_shadow_frontend_failed &&
             astats->lastVertSize >= gx_aurora::g_shadow_prev_rawvert &&
             (astats->lastVertSize - gx_aurora::g_shadow_prev_rawvert) <=
                 vert_align_slack);
        if (!vert_extent_match)
            ++gx_aurora::g_shadow_vert_extent_mismatch_frames;
        if (gx_aurora::g_graphics_log && have_prev &&
            (gx_aurora::g_present_count <= 10 || gx_aurora::g_present_count % 60 == 0 ||
             !draw_match || !vert_extent_match)) {
            std::fprintf(stderr,
                         "[gfx] shadow-consume failed=%d packets=%llu "
                         "draws=%llu textures=%llu copies=%llu spans=%llu "
                         "array-inputs=%llu/%llu (resolved/unresolved) "
                         "assembled=%llu/%llu elems=%llu (ok/fail)\n",
                         gx_aurora::g_shadow_frontend_failed ? 1 : 0,
                         gx_aurora::g_shadow_packet_sink.packets(),
                         fe_draw_total,
                         gx_aurora::g_shadow_packet_sink.texture_count(),
                         gx_aurora::g_shadow_packet_sink.copy_count(),
                         gx_aurora::g_shadow_packet_sink.indexed_span_count(),
                         gx_aurora::g_shadow_packet_sink.resolved_array_inputs(),
                         gx_aurora::g_shadow_packet_sink.unresolved_array_inputs(),
                         gx_aurora::g_shadow_packet_sink.assembled_draws() -
                             gx_aurora::g_shadow_packet_sink.assemble_failed_draws(),
                         gx_aurora::g_shadow_packet_sink.assemble_failed_draws(),
                         gx_aurora::g_shadow_packet_sink.assembled_elements());
            std::fprintf(stderr,
                         "[gfx] shadow-diff frame=%llu fe_draws=%llu "
                         "fe_zdraws=%llu aurora_draws=%u match=%d "
                         "fe_verts=%llu mismatch_frames=%llu\n",
                         gx_aurora::g_shadow_prev_frame_index, gx_aurora::g_shadow_prev_draws,
                         gx_aurora::g_shadow_prev_zero_draws, astats->drawCallCount,
                         draw_match ? 1 : 0, gx_aurora::g_shadow_prev_verts,
                         gx_aurora::g_shadow_draw_mismatch_frames);
            std::fprintf(stderr,
                         "[gfx] shadow-extent frame=%llu fe_vertB=%llu "
                         "aurora_vertB=%u vmatch=%d vmiss=%llu | fe_idxB=%llu "
                         "aurora_idxB=%u | fe_storeB=%llu aurora_storeB=%u\n",
                         gx_aurora::g_shadow_prev_frame_index, gx_aurora::g_shadow_prev_rawvert,
                         astats->lastVertSize, vert_extent_match ? 1 : 0,
                         gx_aurora::g_shadow_vert_extent_mismatch_frames,
                         gx_aurora::g_shadow_prev_topoidx, astats->lastIndexSize,
                         gx_aurora::g_shadow_prev_storage, astats->lastStorageSize);
        }
        gx_aurora::g_shadow_prev_frame_valid = true;
        gx_aurora::g_shadow_prev_frame_index = gx_aurora::g_present_count;
        gx_aurora::g_shadow_prev_draws = fe_frame_draws;
        gx_aurora::g_shadow_prev_zero_draws = fe_frame_zero_draws;
        gx_aurora::g_shadow_prev_verts = fe_frame_verts;
        gx_aurora::g_shadow_prev_rawvert = fe_frame_rawvert;
        gx_aurora::g_shadow_prev_topoidx = fe_frame_topoidx;
        gx_aurora::g_shadow_prev_storage = fe_frame_storage;
    }
    gx_aurora::trace_on_present();
#endif
    if (gx_aurora::g_graphics_log && (gx_aurora::g_present_count <= 10 || gx_aurora::g_present_count % 60 == 0)) {
        const AuroraStats* stats = aurora_get_stats();
        const auto& gx = aurora::gx::g_gxState;
        std::fprintf(stderr,
                     "[gfx] frame=%llu fifo=%llu draws=%u merged=%u verts=%u "
                     "uniforms=%u indices=%u textures=%u fps=%.1f\n",
                     gx_aurora::g_present_count, gx_aurora::g_fifo_bytes, stats->drawCallCount,
                     stats->mergedDrawCallCount, stats->lastVertSize,
                     stats->lastUniformSize, stats->lastIndexSize,
                     stats->lastTextureUploadSize, aurora_get_fps());
        std::fprintf(
            stderr,
            "[gfx] parsed-state tev=%u texgen=%u chans=%u ind=%u cull=%u "
            "blend=%u/%u/%u depth=%u/%u/%u write=%u/%u "
            "viewport=(%.1f,%.1f %.1fx%.1f %.3f..%.3f) "
            "scissor=(%d,%d %dx%d) pnmtx=%u\n",
            gx.numTevStages, gx.numTexGens, gx.numChans, gx.numIndStages,
            static_cast<unsigned>(gx.cullMode),
            static_cast<unsigned>(gx.blendMode),
            static_cast<unsigned>(gx.blendFacSrc),
            static_cast<unsigned>(gx.blendFacDst), gx.depthCompare,
            static_cast<unsigned>(gx.depthFunc), gx.depthUpdate, gx.colorUpdate,
            gx.alphaUpdate, gx.logicalViewport.left, gx.logicalViewport.top,
            gx.logicalViewport.width, gx.logicalViewport.height,
            gx.logicalViewport.znear, gx.logicalViewport.zfar,
            gx.logicalScissor.x, gx.logicalScissor.y,
            gx.logicalScissor.width, gx.logicalScissor.height, gx.currentPnMtx);
        std::fprintf(stderr, "[gfx] projection");
        for (unsigned row = 0; row < 4; row++)
            for (unsigned col = 0; col < 4; col++)
                std::fprintf(stderr, " %.5g", gx.proj[row][col]);
        fputc('\n', stderr);
        std::fprintf(stderr, "[gfx] pnmtx[%u]", gx.currentPnMtx);
        const auto& pos = gx.pnMtx[gx.currentPnMtx].pos;
        const float* pos_values = reinterpret_cast<const float*>(&pos);
        for (unsigned i = 0; i < 12; i++)
            std::fprintf(stderr, " %.5g", pos_values[i]);
        fputc('\n', stderr);
        for (unsigned attr : {9u, 11u, 13u}) {
            const auto& fmt = gx.vtxFmts[0].attrs[attr];
            const auto& array = gx.arrays[attr];
            std::fprintf(stderr,
                         "[gfx] attr=%u desc=%u cnt=%u type=%u frac=%u "
                         "array=%p size=%u stride=%u le=%u\n",
                         attr, static_cast<unsigned>(gx.vtxDesc[attr]),
                         static_cast<unsigned>(fmt.cnt),
                         static_cast<unsigned>(fmt.type), fmt.frac, array.data,
                         array.size, array.stride, array.le);
        }
        if (gx.numTexGens != 0) {
            const auto& tcg = gx.tcgs[0];
            std::fprintf(stderr,
                         "[gfx] tcg0 type=%u src=%u mtx=%u post=%u norm=%u\n",
                         static_cast<unsigned>(tcg.type),
                         static_cast<unsigned>(tcg.src),
                         static_cast<unsigned>(tcg.mtx),
                         static_cast<unsigned>(tcg.postMtx), tcg.normalize);
        }
        if (gx.numTevStages != 0) {
            const auto& tev = gx.tevStages[0];
            std::fprintf(
                stderr,
                "[gfx] tev0 texcoord=%u texmap=%u chan=%u "
                "color=%u,%u,%u,%u alpha=%u,%u,%u,%u\n",
                static_cast<unsigned>(tev.texCoordId),
                static_cast<unsigned>(tev.texMapId),
                static_cast<unsigned>(tev.channelId),
                static_cast<unsigned>(tev.colorPass.a),
                static_cast<unsigned>(tev.colorPass.b),
                static_cast<unsigned>(tev.colorPass.c),
                static_cast<unsigned>(tev.colorPass.d),
                static_cast<unsigned>(tev.alphaPass.a),
                static_cast<unsigned>(tev.alphaPass.b),
                static_cast<unsigned>(tev.alphaPass.c),
                static_cast<unsigned>(tev.alphaPass.d));
        }
    }
    const unsigned long long present_fifo = gx_aurora::g_fifo_bytes;
    gx_aurora::g_fifo_bytes = 0;
    gx_aurora::poll_events();
    if (!gx_aurora::g_should_quit) {
        gx_aurora::g_frame_open = aurora_begin_frame();
#if GXRUNTIME_HAS_AURORA_RECOMP
        gx_aurora::g_shadow_transform_next_draw_index = 0;
#endif
        if (gx_aurora::g_graphics_log && !gx_aurora::g_frame_open)
            std::fprintf(stderr,
                         "[gfx] WARN aurora_begin_frame()=false present=%llu "
                         "fifo_this_interval=%llu (FIFO will accumulate "
                         "undrained)\n",
                         gx_aurora::g_present_count, present_fifo);
    }
    if (gx_aurora::g_graphics_log && present_fifo > 50000ull)
        std::fprintf(stderr, "[gfx] LARGE present=%llu fifo_this_interval=%llu\n",
                     gx_aurora::g_present_count, present_fifo);
}

void aurora_backend_mark_gx_begin(void) {
    gx_aurora::g_draw_opcode_pending = true;
}

void aurora_backend_call_display_list(const void* data, u32 size) {
    if (!gx_aurora::g_initialized || data == nullptr || size == 0)
        return;
#if GXRUNTIME_HAS_AURORA_RECOMP
    gx_aurora::shadow_frontend_call_display_list(data, size);
    if (gx_aurora::trace_should_record())
        gx_aurora::g_trace_writer.call_display_list(0u, data, size);
    if (gx_aurora::g_gx_core_enabled) {
        gx_aurora::g_fifo_bytes += size;
        return;
    }
#endif
    gx_aurora::flush_pending_resource_metadata();
    aurora::gx::fifo::write_data(data, size);
    gx_aurora::g_fifo_bytes += size;
}

void aurora_backend_gx_write(u64 value, u8 size) {
    if (!gx_aurora::g_initialized)
        return;
    gx_aurora::g_fifo_bytes += size;
#if GXRUNTIME_HAS_AURORA_RECOMP
    gx_aurora::shadow_frontend_write(value, size);
    if (gx_aurora::trace_should_record())
        gx_aurora::g_trace_writer.gx_write(size, value);
    if (gx_aurora::g_gx_core_enabled)
        return;
#endif

    static u32 s_last_zmode = 0x40000017;
    static u32 s_last_cmode0 = 0x410004BC;
    static bool s_cull_all_active = false;
    static u8 s_last_opcode = 0;

    switch (size) {
    case 1: {
        const u8 command = static_cast<u8>(value);
        s_last_opcode = command;
        if (gx_aurora::g_draw_opcode_pending && command >= 0x80u) {
            gx_aurora::g_draw_opcode_pending = false;
            gx_aurora::flush_pending_resource_metadata();
            if (gx_aurora::g_force_untextured) {
                GXSetCullMode(GX_CULL_NONE);
                GXSetZMode(GX_FALSE, GX_ALWAYS, GX_FALSE);
                GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR);
                GXSetColorUpdate(GX_TRUE);
                GXSetAlphaUpdate(GX_TRUE);
                GXSetNumTexGens(0);
                GXSetNumChans(1);
                GXSetNumTevStages(1);
                GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL,
                              GX_COLOR0A0);
                GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
            }
        }
        GXParam1u8(command);
        break;
    }
    case 2: GXParam1u16(static_cast<u16>(value)); break;
    case 4: {
        u32 val32 = static_cast<u32>(value);

        if (s_last_opcode == 0x61) {
            u8 regId = (val32 >> 24) & 0xFF;

            if (regId == 0x40) {
                s_last_zmode = val32;
                if (s_cull_all_active) {
                    val32 &= ~0x11;
                }
                GXParam1u32(val32);
            } else if (regId == 0x41) {
                s_last_cmode0 = val32;
                if (s_cull_all_active) {
                    val32 &= ~0x18;
                }
                GXParam1u32(val32);
            } else if (regId == 0x00) {
                u32 hwCull = (val32 >> 14) & 3;
                if (hwCull == 3) {
                    val32 &= ~(3u << 14);
                    GXParam1u32(val32);

                    if (!s_cull_all_active) {
                        s_cull_all_active = true;
                        GXParam1u8(0x61);
                        GXParam1u32(s_last_zmode & ~0x11);
                        GXParam1u8(0x61);
                        GXParam1u32(s_last_cmode0 & ~0x18);
                    }
                } else {
                    GXParam1u32(val32);

                    if (s_cull_all_active) {
                        s_cull_all_active = false;
                        GXParam1u8(0x61);
                        GXParam1u32(s_last_zmode);
                        GXParam1u8(0x61);
                        GXParam1u32(s_last_cmode0);
                    }
                }
            } else {
                GXParam1u32(val32);
            }
        } else {
            GXParam1u32(val32);
        }
        break;
    }
    case 8: GXCmd1u64(value); break;
    default: break;
    }
}

void aurora_backend_set_array(u32 attr, const void* data, u32 size, u8 stride) {
    aurora_backend_set_array_guest(attr, 0u, data, size, stride);
}

void aurora_backend_set_array_guest(u32 attr, u32 guest_address,
                                    const void* data, u32 size, u8 stride) {
    if (!gx_aurora::g_initialized || data == nullptr)
        return;
#if GXRUNTIME_HAS_AURORA_RECOMP
    if (guest_address != 0u)
        gx_aurora::shadow_frontend_set_array(attr, guest_address, stride);
#endif
    GXSetArray(static_cast<GXAttr>(attr), data, size, stride, false);
}

void aurora_backend_load_texture(u8 slot, const void* data, u32 width, u32 height,
                                 u32 format, u32 tlut, bool mipmap, u32 object_id,
                                 u32 data_version) {
    aurora_backend_load_texture_guest(slot, 0u, data, width, height, format,
                                      tlut, mipmap, object_id, data_version);
}

void aurora_backend_load_texture_guest(u8 slot, u32 guest_address,
                                       const void* data, u32 width, u32 height,
                                       u32 format, u32 tlut, bool mipmap,
                                       u32 object_id, u32 data_version) {
    (void)guest_address;
    if (!gx_aurora::g_initialized || data == nullptr || slot >= 8)
        return;
    gx_aurora::g_pending_textures[slot] = {
        .valid = true,
        .data = data,
        .width = width,
        .height = height,
        .format = format,
        .tlut = tlut,
        .mipmap = mipmap,
        .object_id = object_id,
        .data_version = data_version,
    };
}

void aurora_backend_load_tlut(u8 slot, const void* data, u32 format, u16 entries,
                              u32 object_id, u32 data_version) {
    aurora_backend_load_tlut_guest(slot, 0u, data, format, entries, object_id,
                                   data_version);
}

void aurora_backend_load_tlut_guest(u8 slot, u32 guest_address,
                                    const void* data, u32 format, u16 entries,
                                    u32 object_id, u32 data_version) {
    (void)guest_address;
    if (!gx_aurora::g_initialized || data == nullptr || slot >= gx_aurora::g_pending_tluts.size())
        return;
    gx_aurora::g_pending_tluts[slot] = {
        .valid = true,
        .data = data,
        .format = format,
        .entries = entries,
        .object_id = object_id,
        .data_version = data_version,
    };
}

void aurora_backend_set_copy_destination(const void* data) {
    aurora_backend_set_copy_destination_guest(0u, data);
}

void aurora_backend_set_copy_destination_guest(u32 guest_address,
                                               const void* data) {
    (void)guest_address;
    if (!gx_aurora::g_initialized || data == nullptr)
        return;
    gx_aurora::write_aurora_command(GX_AURORA_LOAD_COPY_DEST);
    GXCmd1u64(reinterpret_cast<u64>(data));
}

void aurora_backend_set_guest_address_resolver(
    DolPlatformGuestAddressResolverFn resolve, void* user) {
    gx_aurora::g_guest_address_resolver = resolve;
    gx_aurora::g_guest_address_resolver_user = user;
#if GXRUNTIME_HAS_AURORA_RECOMP
    if (resolve != nullptr) {
        DolGuestAddressResolver frontend_resolver;
        dol_guest_address_resolver_init_callback(
            &frontend_resolver, gx_aurora::frontend_guest_address_resolver_bridge,
            nullptr);
        gx_aurora::g_shadow_frontend.reset(&frontend_resolver);
        gx_aurora::g_shadow_frontend.set_packet_drain_enabled(gx_aurora::g_shadow_frontend_enabled);
        gx_aurora::g_shadow_packet_sink.reset();
        gx_aurora::g_shadow_packet_sink.set_guest_resolver(
            &gx_aurora::g_shadow_frontend.state().resolver);
        if (gx_aurora::g_gx_core_enabled)
            gx_aurora::g_core_sink.set_guest_resolver(&gx_aurora::g_shadow_frontend.state().resolver);
        gx_aurora::g_shadow_frontend_failed = false;
    } else {
        gx_aurora::g_shadow_frontend.reset(nullptr);
        gx_aurora::g_shadow_frontend.set_packet_drain_enabled(gx_aurora::g_shadow_frontend_enabled);
        gx_aurora::g_shadow_packet_sink.reset();
        gx_aurora::g_shadow_packet_sink.set_guest_resolver(nullptr);
    }
    gx_aurora::g_shadow_last_draw_total = 0;
    gx_aurora::g_shadow_last_vertex_total = 0;
    gx_aurora::g_shadow_last_rawvert_total = 0;
    gx_aurora::g_shadow_last_topoidx_total = 0;
    gx_aurora::g_shadow_last_storage_total = 0;
#endif
    if (resolve != nullptr) {
        aurora::gx::recomp::set_guest_address_resolver(
            gx_aurora::aurora_guest_address_resolver_bridge, nullptr);
    } else {
        aurora::gx::recomp::clear_guest_address_resolver();
    }
}

void aurora_backend_configure_vi(u32 tv_mode, u16 fb_width, u16 efb_height,
                                 u16 xfb_height, u16 vi_width, u16 vi_height) {
    if (!gx_aurora::g_initialized)
        return;
    GXRenderModeObj mode{};
    mode.viTVmode = static_cast<VITVMode>(tv_mode);
    mode.fbWidth = fb_width;
    mode.efbHeight = efb_height;
    mode.xfbHeight = xfb_height;
    mode.viWidth = vi_width;
    mode.viHeight = vi_height;
    VIConfigure(&mode);
}

} // extern "C"
