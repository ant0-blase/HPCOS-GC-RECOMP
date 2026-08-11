// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/gx_recomp.h"
#include "gx_recomp_internal.h"
#include "core/types.h"

#include <string.h>

static u32 bp_get(u32 value, u32 size, u32 shift) {
    return (value >> shift) & ((1u << size) - 1u);
}

static bool is_draw_opcode(u8 opcode) {
    switch (opcode & 0xF8u) {
    case 0x80u: /* quads */
    case 0x90u: /* triangles */
    case 0x98u: /* triangle strip */
    case 0xA0u: /* triangle fan */
    case 0xA8u: /* lines */
    case 0xB0u: /* line strip */
    case 0xB8u: /* points */
        return true;
    default:
        return false;
    }
}

static bool replay_maybe_resolve_texture(DolGxRecompState* gx, u8 slot) {
    if (gx == NULL || slot >= DOL_GX_RECOMP_TEXTURE_SLOTS)
        return false;
    const u8 image0_reg = dol_gx_recomp_image0_reg_for_slot(slot);
    const u8 image3_reg = dol_gx_recomp_image3_reg_for_slot(slot);
    if (!gx->bp_valid[image0_reg] || !gx->bp_valid[image3_reg])
        return true;
    DolGxRecompTexture texture;
    return dol_gx_recomp_resolve_texture_image(
        gx, slot, gx->bp_regs[image0_reg], gx->bp_regs[image3_reg],
        &texture);
}

static bool replay_handle_copy_trigger(DolGxRecompState* gx, u32 value) {
    if (gx == NULL)
        return false;
    if (bp_get(value, 1u, 14u) != 0u)
        return true;
    if (!gx->copy.physical_base_valid)
        return false;

    u32 width = gx->copy.width != 0u ? gx->copy.width : 1u;
    u32 height = gx->copy.height != 0u ? gx->copy.height : 1u;
    if (bp_get(value, 1u, 9u) != 0u) {
        width = (width + 1u) / 2u;
        height = (height + 1u) / 2u;
        if (width == 0u)
            width = 1u;
        if (height == 0u)
            height = 1u;
    }

    gx->copy.format = dol_gx_recomp_copy_trigger_texture_format(value);
    if (!dol_gx_recomp_texture_size((u16)width, (u16)height,
                                    gx->copy.format, &gx->copy.byte_size))
        return false;
    gx->copy.width = width;
    gx->copy.height = height;
    if (!dol_gx_recomp_resolve_copy_destination(
            gx, gx->copy.physical_base, gx->copy.byte_size, &gx->copy.range))
        return false;
    gx->copy.range_valid = true;
    return true;
}

static bool replay_handle_bp(DolGxRecompState* gx, u32 raw) {
    if (gx == NULL)
        return false;
    const u8 reg = (u8)(raw >> 24);
    const u32 value = raw & 0x00FFFFFFu;
    if (!dol_gx_recomp_note_bp_reg(gx, reg, value))
        return false;

    u8 slot = 0;
    if (dol_gx_recomp_map_image0_reg(reg, &slot) || dol_gx_recomp_map_image3_reg(reg, &slot))
        return replay_maybe_resolve_texture(gx, slot);
    if (dol_gx_recomp_map_tlut_reg(reg, &slot)) {
        gx->texture_tlut_valid[slot] = true;
        gx->texture_tlut_tmem_offset[slot] = (u16)bp_get(value, 10u, 0u);
        gx->texture_tlut_format[slot] = bp_get(value, 2u, 10u);
        return true;
    }

    switch (reg) {
    case DOL_GX_BP_REG_EFB_TL:
        gx->copy.src_x = bp_get(value, 10u, 0u);
        gx->copy.src_y = bp_get(value, 10u, 10u);
        return true;
    case DOL_GX_BP_REG_EFB_WH:
        gx->copy.width = bp_get(value, 10u, 0u) + 1u;
        gx->copy.height = bp_get(value, 10u, 10u) + 1u;
        return true;
    case DOL_GX_BP_REG_EFB_ADDR:
        gx->copy.physical_base = (value & 0x00FFFFFFu) << 5;
        gx->copy.physical_base_valid = true;
        return true;
    case DOL_GX_BP_REG_TRIGGER_EFB_COPY:
        return replay_handle_copy_trigger(gx, value);
    case DOL_GX_BP_REG_LOAD_TLUT1: {
        const u16 tmem_offset = (u16)bp_get(value, 10u, 0u);
        const u32 line_count = bp_get(value, 11u, 10u);
        if (line_count == 0u)
            return true;
        if (!gx->bp_valid[DOL_GX_BP_REG_LOAD_TLUT0])
            return true;
        DolGxRecompTlut tlut;
        (void)dol_gx_recomp_resolve_tmem_tlut(
            gx, tmem_offset, gx->bp_regs[DOL_GX_BP_REG_LOAD_TLUT0], 0u,
            (u16)(line_count * 16u), &tlut);
        return true;
    }
    default:
        return true;
    }
}

static bool replay_handle_draw(DolGxRecompState* gx, u8 cmd,
                               const u8* vertex_data, u16 vertex_count) {
    if (gx == NULL || vertex_data == NULL || vertex_count == 0u)
        return false;
    const u8 vtx_fmt = cmd & 0x7u;
    if (vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS ||
        !gx->vertex_layouts[vtx_fmt].valid)
        return false;
    const DolGxRecompVertexLayout* layout = &gx->vertex_layouts[vtx_fmt];
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_DRAW, cmd & 0xF8u, vtx_fmt,
                              vertex_count, layout->vertex_size);

    for (u32 i = 0; i < layout->indexed_attr_count; ++i) {
        const DolGxRecompIndexedAttr* spec = &layout->indexed_attrs[i];
        const u8 attr = spec->attr;
        if (!spec->valid || attr >= DOL_GX_RECOMP_CP_ARRAY_COUNT)
            return false;
        u32 span = 0;
        if (!dol_gx_recomp_indexed_span(
                vertex_data, layout->vertex_size, vertex_count,
                spec->vertex_offset, spec->index_size,
                gx->arrays[attr].stride_valid ? gx->arrays[attr].stride : 0u,
                spec->element_size, spec->element_bias, &span))
            return false;
        DolGxRecompResolvedArray array;
        if (!dol_gx_recomp_resolve_cp_array(gx, attr, span, &array))
            return false;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_INDEXED_SPAN, attr, span,
                                  vertex_count, vtx_fmt);
        /* Carry the per-attr decode params on the event just emitted (if it
         * was recorded) so a consumer can assemble vertices from this span. */
        if (gx->trace_count > 0u) {
            DolGxRecompTraceEvent* ev = &gx->trace[gx->trace_count - 1u];
            if (ev->kind == DOL_GX_RECOMP_EVENT_INDEXED_SPAN && ev->a == attr) {
                ev->e = spec->vertex_offset;
                ev->f = spec->index_size;
                ev->g = spec->element_size;
            }
        }
    }
    return true;
}

static bool replay_stream(DolGxRecompState* gx, const u8* data, u32 size,
                          u32 depth, bool append_bytes) {
    if (gx == NULL || data == NULL || size == 0u || depth > 4u)
        return false;
    if (append_bytes && !dol_gx_recomp_push_fifo(gx, data, size))
        return false;

    u32 pos = 0;
    while (pos < size) {
        const u8 cmd = data[pos++];
        switch (cmd & 0xF8u) {
        case 0x00u:
            if (cmd == 0x00u)
                break;
            return false;
        case DOL_GX_CMD_LOAD_CP_REG:
            if (pos + 5u > size)
                return false;
            if (!dol_gx_recomp_load_cp_reg(gx, data[pos], read_be32(data + pos + 1u)))
                return false;
            pos += 5u;
            break;
        case DOL_GX_CMD_LOAD_XF_REG: {
            if (pos + 4u > size)
                return false;
            const u32 header = read_be32(data + pos);
            const u8 count = (u8)(((header >> 16) & 0xFFFFu) + 1u);
            const u16 base = (u16)(header & 0xFFFFu);
            const u32 byte_count = (u32)count * 4u;
            if (pos + 4u + byte_count > size)
                return false;
            if (!dol_gx_recomp_note_xf_load(gx, base, count))
                return false;
            dol_gx_recomp_capture_xf_transform(gx, base, count,
                                               data + pos + 4u);
            pos += 4u + byte_count;
            break;
        }
        case 0x20u:
        case 0x28u:
        case 0x30u:
        case 0x38u: {
            if (pos + 4u > size)
                return false;
            const u32 value = read_be32(data + pos);
            const u32 index = value >> 16;
            const u16 base = (u16)(value & 0x0FFFu);
            const u8 count = (u8)(((value >> 12) & 0xFu) + 1u);
            const u8 attr = (u8)(12u + ((cmd - 0x20u) / 8u));
            const u32 element_bytes = (u32)count * 4u;
            const u32 span = gx->arrays[attr].stride_valid
                                 ? index * gx->arrays[attr].stride +
                                       element_bytes
                                 : 0u;
            DolGxRecompResolvedArray array;
            if (span == 0u ||
                !dol_gx_recomp_resolve_cp_array(gx, attr, span, &array))
                return false;
            dol_gx_recomp_capture_xf_transform(
                gx, base, count,
                (const u8*)array.range.data + index * gx->arrays[attr].stride);
            dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_INDEXED_XF_LOAD, attr, index,
                                      base, count);
            if (!dol_gx_recomp_note_xf_load(gx, base, count))
                return false;
            pos += 4u;
            break;
        }
        case DOL_GX_CMD_CALL_DL: {
            if (pos + 8u > size)
                return false;
            const u32 address = read_be32(data + pos);
            const u32 dl_size = read_be32(data + pos + 4u);
            pos += 8u;
            if (dl_size == 0u)
                break;
            DolGuestResolvedRange range;
            if (!dol_gx_recomp_resolve_display_list(gx, address, dl_size,
                                                    &range))
                return false;
            if (!dol_gx_recomp_push_fifo(gx, range.data, range.size))
                return false;
            if (!replay_stream(gx, (const u8*)range.data, range.size,
                               depth + 1u, false))
                return false;
            break;
        }
        case DOL_GX_CMD_INVL_VC:
            if (!dol_gx_recomp_note_invalidate_vtx_cache(gx))
                return false;
            break;
        case 0x60u: {
            if (cmd != DOL_GX_CMD_LOAD_BP_REG || pos + 4u > size)
                return false;
            if (!replay_handle_bp(gx, read_be32(data + pos)))
                return false;
            pos += 4u;
            break;
        }
        default:
            if (!is_draw_opcode(cmd))
                return false;
            if (pos + 2u > size)
                return false;
            const u16 vertex_count = read_be16(data + pos);
            pos += 2u;
            const u8 vtx_fmt = cmd & 0x7u;
            if (vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS ||
                (!gx->vertex_layouts[vtx_fmt].valid &&
                 !dol_gx_recomp_derive_vertex_layout(gx, vtx_fmt)))
                return false;
            const u32 vertex_size = gx->vertex_layouts[vtx_fmt].vertex_size;
            const u32 byte_count = (u32)vertex_count * vertex_size;
            if (pos + byte_count > size)
                return false;
            if (!replay_handle_draw(gx, cmd, data + pos, vertex_count))
                return false;
            pos += byte_count;
            break;
        }
    }
    return true;
}

bool dol_gx_recomp_replay_fifo(DolGxRecompState* gx, const void* data,
                               u32 size) {
    if (gx == NULL || data == NULL || size == 0u)
        return false;
    return replay_stream(gx, (const u8*)data, size, 0u, true);
}

const DolGxRecompTraceEvent*
dol_gx_recomp_trace_events(const DolGxRecompState* gx, u32* count) {
    if (count != NULL)
        *count = gx != NULL ? gx->trace_count : 0u;
    return gx != NULL ? gx->trace : NULL;
}
