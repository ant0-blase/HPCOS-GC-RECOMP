// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/gx_recomp.h"
#include "gx_recomp_internal.h"

#include <string.h>

void dol_gx_recomp_trace_event(DolGxRecompState* gx, DolGxRecompEventKind kind,
                        u32 a, u32 b, u32 c, u32 d) {

    if (gx == NULL || gx->trace_count >= DOL_GX_RECOMP_MAX_TRACE_EVENTS)
        return;
    DolGxRecompTraceEvent* event = &gx->trace[gx->trace_count++];
    event->kind = kind;
    event->a = a;
    event->b = b;
    event->c = c;
    event->d = d;
    /* Trace slots are reused across flushes; zero the extra fields so a slot
     * never carries stale decode params from a prior event. */
    event->e = 0u;
    event->f = 0u;
    event->g = 0u;
}

static u32 round_up(u32 value, u32 multiple) {
    if (multiple == 0u)
        return value;
    const u32 rem = value % multiple;
    return rem == 0u ? value : value + multiple - rem;
}

static u32 read_index(const u8* data, u8 size) {
    if (size == 1u)
        return data[0];
    return ((u32)data[0] << 8) | data[1];
}

static u32 bp_get(u32 value, u32 size, u32 shift) {
    return (value >> shift) & ((1u << size) - 1u);
}

static void note_matrix_index_a(DolGxRecompState* gx, u32 value) {
    if (gx == NULL)
        return;
    gx->matrix_index_a = value;
    gx->current_pn_matrix = bp_get(value, 6u, 0u) / 3u;
    if (gx->current_pn_matrix >= DOL_GX_RECOMP_POSITION_MATRIX_COUNT)
        gx->current_pn_matrix = 0u;
}

static u32 texture_physical_base(u32 image_or_tlut) {
    return (image_or_tlut & 0x00FFFFFFu) << 5;
}

static bool resolve_physical(DolGxRecompState* gx, u32 physical_base,
                             u32 byte_size, DolGuestResourceKind resource,
                             DolGuestResolvedRange* out) {
    return dol_guest_address_resolver_resolve(
        &gx->resolver, physical_base, byte_size, DOL_GUEST_ADDRESS_PHYSICAL,
        resource, out);
}

bool dol_gx_recomp_map_image0_reg(u8 reg, u8* slot) {
    if (slot == NULL)
        return false;
    if (reg >= DOL_GX_BP_REG_TX_SETIMAGE0 &&
        reg < DOL_GX_BP_REG_TX_SETIMAGE0 + 4u) {
        *slot = (u8)(reg - DOL_GX_BP_REG_TX_SETIMAGE0);
        return true;
    }
    if (reg >= DOL_GX_BP_REG_TX_SETIMAGE0_4 &&
        reg < DOL_GX_BP_REG_TX_SETIMAGE0_4 + 4u) {
        *slot = (u8)(4u + reg - DOL_GX_BP_REG_TX_SETIMAGE0_4);
        return true;
    }
    return false;
}

bool dol_gx_recomp_map_image3_reg(u8 reg, u8* slot) {
    if (slot == NULL)
        return false;
    if (reg >= DOL_GX_BP_REG_TX_SETIMAGE3 &&
        reg < DOL_GX_BP_REG_TX_SETIMAGE3 + 4u) {
        *slot = (u8)(reg - DOL_GX_BP_REG_TX_SETIMAGE3);
        return true;
    }
    if (reg >= DOL_GX_BP_REG_TX_SETIMAGE3_4 &&
        reg < DOL_GX_BP_REG_TX_SETIMAGE3_4 + 4u) {
        *slot = (u8)(4u + reg - DOL_GX_BP_REG_TX_SETIMAGE3_4);
        return true;
    }
    return false;
}

bool dol_gx_recomp_map_tlut_reg(u8 reg, u8* slot) {
    if (slot == NULL)
        return false;
    if (reg >= DOL_GX_BP_REG_TX_SETTLUT &&
        reg < DOL_GX_BP_REG_TX_SETTLUT + 4u) {
        *slot = (u8)(reg - DOL_GX_BP_REG_TX_SETTLUT);
        return true;
    }
    if (reg >= DOL_GX_BP_REG_TX_SETTLUT_4 &&
        reg < DOL_GX_BP_REG_TX_SETTLUT_4 + 4u) {
        *slot = (u8)(4u + reg - DOL_GX_BP_REG_TX_SETTLUT_4);
        return true;
    }
    return false;
}

u8 dol_gx_recomp_image0_reg_for_slot(u8 slot) {
    return slot < 4u ? (u8)(DOL_GX_BP_REG_TX_SETIMAGE0 + slot)
                     : (u8)(DOL_GX_BP_REG_TX_SETIMAGE0_4 + slot - 4u);
}

u8 dol_gx_recomp_image3_reg_for_slot(u8 slot) {
    return slot < 4u ? (u8)(DOL_GX_BP_REG_TX_SETIMAGE3 + slot)
                     : (u8)(DOL_GX_BP_REG_TX_SETIMAGE3_4 + slot - 4u);
}

u32 dol_gx_recomp_copy_trigger_texture_format(u32 value) {
    const u32 target = bp_get(value, 4u, 3u);
    const u32 real = target / 2u + (target & 1u) * 8u;
    const bool intensity = bp_get(value, 1u, 15u) != 0u;

    switch (real) {
    case 0x0:
        return 0x0; /* I4 or R4-sized */
    case 0x1:
        return 0x1; /* I8 */
    case 0x2:
        return 0x2; /* IA4 or RA4-sized */
    case 0x3:
        return 0x3; /* IA8 or RA8-sized */
    case 0x4:
        return 0x4; /* RGB565 */
    case 0x5:
        return 0x5; /* RGB5A3 */
    case 0x6:
        return 0x6; /* RGBA8 */
    case 0x7:
    case 0x8:
    case 0x9:
    case 0xA:
        return 0x1; /* A8/R8/G8/B8-sized */
    case 0xB:
    case 0xC:
        return intensity ? 0x1u : 0x3u; /* Z16/RG8/GB8-sized */
    default:
        return 0x6;
    }
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

static u32 cp_get(u32 value, u32 shift, u32 size) {
    return (value >> shift) & ((1u << size) - 1u);
}

static u32 popcount9(u32 value) {
    value &= 0x1FFu;
    u32 count = 0;
    while (value != 0u) {
        count += value & 1u;
        value >>= 1u;
    }
    return count;
}

static bool comp_scalar_size(u32 format, u32* out) {
    if (out == NULL)
        return false;
    switch (format & 0x7u) {
    case 0u:
    case 1u:
        *out = 1u;
        return true;
    case 2u:
    case 3u:
        *out = 2u;
        return true;
    case 4u:
    case 5u:
    case 6u:
    case 7u:
        *out = 4u;
        return true;
    default:
        return false;
    }
}

static bool cp_attr_index_size(u32 attr_type, u8* out) {
    if (out == NULL)
        return false;
    if (attr_type == 2u) {
        *out = 1u;
        return true;
    }
    if (attr_type == 3u) {
        *out = 2u;
        return true;
    }
    return false;
}

static bool add_indexed_attr_spec(DolGxRecompVertexLayout* layout, u8 attr,
                                  u32 vertex_offset, u8 index_size,
                                  u32 element_size, u32 element_bias) {
    if (layout == NULL || attr >= DOL_GX_RECOMP_CP_ARRAY_COUNT ||
        (index_size != 1u && index_size != 2u) || element_size == 0u ||
        vertex_offset + index_size > layout->vertex_size ||
        layout->indexed_attr_count >= DOL_GX_RECOMP_MAX_INDEXED_ATTR_SPECS)
        return false;

    const DolGxRecompIndexedAttr spec = {
        .valid = true,
        .attr = attr,
        .vertex_offset = vertex_offset,
        .index_size = index_size,
        .element_size = element_size,
        .element_bias = element_bias,
    };
    if (!layout->attrs[attr].valid)
        layout->attrs[attr] = spec;
    layout->indexed_attrs[layout->indexed_attr_count++] = spec;
    return true;
}

static bool derive_pos_attr(DolGxRecompVertexLayout* layout, u32 attr_type,
                            u32 vat0, u32* offset) {
    if (layout == NULL || offset == NULL || attr_type == 0u)
        return attr_type == 0u;
    const u32 elements = cp_get(vat0, 0u, 1u) != 0u ? 3u : 2u;
    const u32 format = cp_get(vat0, 1u, 3u);
    u32 scalar_size = 0;
    if (!comp_scalar_size(format, &scalar_size))
        return false;
    const u32 element_size = elements * scalar_size;
    if (attr_type == 1u) {
        *offset += element_size;
        return true;
    }
    u8 index_size = 0;
    if (!cp_attr_index_size(attr_type, &index_size))
        return false;
    if (!add_indexed_attr_spec(layout, 0u, *offset, index_size, element_size,
                               0u))
        return false;
    *offset += index_size;
    return true;
}

static bool derive_normal_attr(DolGxRecompVertexLayout* layout, u32 attr_type,
                               u32 vat0, u32* offset) {
    if (layout == NULL || offset == NULL || attr_type == 0u)
        return attr_type == 0u;
    const bool nbt = cp_get(vat0, 9u, 1u) != 0u;
    const bool index3 = cp_get(vat0, 31u, 1u) != 0u;
    const u32 format = cp_get(vat0, 10u, 3u);
    u32 scalar_size = 0;
    if (!comp_scalar_size(format, &scalar_size))
        return false;
    const u32 one_normal_size = 3u * scalar_size;
    const u32 element_size = nbt ? one_normal_size * 3u : one_normal_size;
    if (attr_type == 1u) {
        *offset += element_size;
        return true;
    }
    u8 index_size = 0;
    if (!cp_attr_index_size(attr_type, &index_size))
        return false;
    if (nbt && index3) {
        for (u32 i = 0; i < 3u; ++i) {
            if (!add_indexed_attr_spec(layout, 1u, *offset + i * index_size,
                                       index_size, one_normal_size, 0u))
                return false;
        }
        *offset += 3u * index_size;
        return true;
    }
    if (!add_indexed_attr_spec(layout, 1u, *offset, index_size, element_size,
                               0u))
        return false;
    *offset += index_size;
    return true;
}

static bool color_element_size(u32 format, u32* out) {
    if (out == NULL)
        return false;
    switch (format & 0x7u) {
    case 0u:
    case 3u:
        *out = 2u;
        return true;
    case 1u:
    case 4u:
        *out = 3u;
        return true;
    case 2u:
    case 5u:
        *out = 4u;
        return true;
    default:
        return false;
    }
}

static bool derive_color_attr(DolGxRecompVertexLayout* layout, u8 attr,
                              u32 attr_type, u32 format, u32* offset) {
    if (layout == NULL || offset == NULL || attr_type == 0u)
        return attr_type == 0u;
    u32 element_size = 0;
    if (!color_element_size(format, &element_size))
        return false;
    if (attr_type == 1u) {
        *offset += element_size;
        return true;
    }
    u8 index_size = 0;
    if (!cp_attr_index_size(attr_type, &index_size))
        return false;
    if (!add_indexed_attr_spec(layout, attr, *offset, index_size, element_size,
                               0u))
        return false;
    *offset += index_size;
    return true;
}

static bool tex_element_size(u32 elements_bit, u32 format, u32* out) {
    if (out == NULL)
        return false;
    u32 scalar_size = 0;
    if (!comp_scalar_size(format, &scalar_size))
        return false;
    *out = (elements_bit != 0u ? 2u : 1u) * scalar_size;
    return true;
}

static bool derive_tex_attr(DolGxRecompVertexLayout* layout, u8 attr,
                            u32 attr_type, u32 elements_bit, u32 format,
                            u32* offset) {
    if (layout == NULL || offset == NULL || attr_type == 0u)
        return attr_type == 0u;
    u32 element_size = 0;
    if (!tex_element_size(elements_bit, format, &element_size))
        return false;
    if (attr_type == 1u) {
        *offset += element_size;
        return true;
    }
    u8 index_size = 0;
    if (!cp_attr_index_size(attr_type, &index_size))
        return false;
    if (!add_indexed_attr_spec(layout, attr, *offset, index_size, element_size,
                               0u))
        return false;
    *offset += index_size;
    return true;
}

static bool derive_layout_from_cp(const DolGxRecompState* gx, u8 vtx_fmt,
                                  DolGxRecompVertexLayout* out) {
    if (gx == NULL || out == NULL || vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS ||
        (!gx->vcd_lo_valid && !gx->vcd_hi_valid))
        return false;

    DolGxRecompVertexLayout layout;
    memset(&layout, 0, sizeof(layout));
    layout.valid = true;
    layout.vertex_size = 0xFFFFFFFFu;

    u32 offset = popcount9(gx->vcd_lo);
    const u32 vat0 = gx->vat_group0[vtx_fmt];
    const u32 vat1 = gx->vat_group1[vtx_fmt];
    const u32 vat2 = gx->vat_group2[vtx_fmt];

    if (!derive_pos_attr(&layout, cp_get(gx->vcd_lo, 9u, 2u), vat0,
                         &offset))
        return false;
    if (!derive_normal_attr(&layout, cp_get(gx->vcd_lo, 11u, 2u), vat0,
                            &offset))
        return false;
    if (!derive_color_attr(&layout, 2u, cp_get(gx->vcd_lo, 13u, 2u),
                           cp_get(vat0, 14u, 3u), &offset))
        return false;
    if (!derive_color_attr(&layout, 3u, cp_get(gx->vcd_lo, 15u, 2u),
                           cp_get(vat0, 18u, 3u), &offset))
        return false;

    if (!derive_tex_attr(&layout, 4u, cp_get(gx->vcd_hi, 0u, 2u),
                         cp_get(vat0, 21u, 1u), cp_get(vat0, 22u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 5u, cp_get(gx->vcd_hi, 2u, 2u),
                         cp_get(vat1, 0u, 1u), cp_get(vat1, 1u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 6u, cp_get(gx->vcd_hi, 4u, 2u),
                         cp_get(vat1, 9u, 1u), cp_get(vat1, 10u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 7u, cp_get(gx->vcd_hi, 6u, 2u),
                         cp_get(vat1, 18u, 1u), cp_get(vat1, 19u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 8u, cp_get(gx->vcd_hi, 8u, 2u),
                         cp_get(vat1, 27u, 1u), cp_get(vat1, 28u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 9u, cp_get(gx->vcd_hi, 10u, 2u),
                         cp_get(vat2, 5u, 1u), cp_get(vat2, 6u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 10u, cp_get(gx->vcd_hi, 12u, 2u),
                         cp_get(vat2, 14u, 1u), cp_get(vat2, 15u, 3u),
                         &offset))
        return false;
    if (!derive_tex_attr(&layout, 11u, cp_get(gx->vcd_hi, 14u, 2u),
                         cp_get(vat2, 23u, 1u), cp_get(vat2, 24u, 3u),
                         &offset))
        return false;

    if (offset == 0u)
        return false;
    layout.vertex_size = offset;
    *out = layout;
    return true;
}

static void derive_all_vertex_layouts(DolGxRecompState* gx) {
    if (gx == NULL)
        return;
    for (u8 i = 0; i < DOL_GX_RECOMP_VERTEX_FORMATS; ++i)
        (void)dol_gx_recomp_derive_vertex_layout(gx, i);
}

void dol_gx_recomp_init(DolGxRecompState* gx,
                        const DolGuestAddressResolver* resolver) {
    if (gx == NULL)
        return;
    memset(gx, 0, sizeof(*gx));
    if (resolver != NULL)
        gx->resolver = *resolver;
}

bool dol_gx_recomp_push_fifo(DolGxRecompState* gx, const void* data, u32 size) {
    if (gx == NULL || data == NULL || size == 0u ||
        size > DOL_GX_RECOMP_MAX_FIFO_BYTES - gx->fifo.size)
        return false;
    memcpy(gx->fifo.bytes + gx->fifo.size, data, size);
    gx->fifo.size += size;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_FIFO_BYTES, size, gx->fifo.size, 0, 0);
    return true;
}

const u8* dol_gx_recomp_fifo_bytes(const DolGxRecompState* gx) {
    return gx != NULL ? gx->fifo.bytes : NULL;
}

u32 dol_gx_recomp_fifo_size(const DolGxRecompState* gx) {
    return gx != NULL ? gx->fifo.size : 0u;
}

u32 dol_gx_recomp_guest_to_physical(u32 address) {
    return address & DOL_GX_PHYSICAL_ADDRESS_MASK;
}

bool dol_gx_recomp_resolve_display_list(DolGxRecompState* gx, u32 address,
                                        u32 size,
                                        DolGuestResolvedRange* out) {
    if (gx == NULL || size == 0u || (address & 31u) != 0u ||
        (size & 31u) != 0u)
        return false;
    if (!dol_guest_address_resolver_resolve(
            &gx->resolver, address, size, DOL_GUEST_ADDRESS_AUTO,
            DOL_GUEST_RESOURCE_DISPLAY_LIST, out))
        return false;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_DISPLAY_LIST, address, size,
                out != NULL ? (u32)out->space : 0u, 0);
    return true;
}

bool dol_gx_recomp_call_display_list(DolGxRecompState* gx, u32 address,
                                     u32 size, bool append_fifo) {
    DolGuestResolvedRange range;
    if (!dol_gx_recomp_resolve_display_list(gx, address, size, &range))
        return false;
    if (append_fifo && !dol_gx_recomp_push_fifo(gx, range.data, range.size))
        return false;
    return true;
}

bool dol_gx_recomp_load_cp_reg(DolGxRecompState* gx, u8 reg, u32 value) {
    if (gx == NULL)
        return false;
    if (reg == DOL_GX_CP_REG_MATRIX_INDEX_A) {
        note_matrix_index_a(gx, value);
        return true;
    }
    if (reg == DOL_GX_CP_REG_VCD_LO) {
        gx->vcd_lo = value;
        gx->vcd_lo_valid = true;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_VCD, 0u, value, 0u, 0u);
        derive_all_vertex_layouts(gx);
        return true;
    }
    if (reg == DOL_GX_CP_REG_VCD_HI) {
        gx->vcd_hi = value;
        gx->vcd_hi_valid = true;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_VCD, 1u, value, 0u, 0u);
        derive_all_vertex_layouts(gx);
        return true;
    }
    if (reg >= DOL_GX_CP_REG_VAT_GRP0 &&
        reg < DOL_GX_CP_REG_VAT_GRP0 + DOL_GX_RECOMP_VERTEX_FORMATS) {
        const u8 fmt = (u8)(reg - DOL_GX_CP_REG_VAT_GRP0);
        gx->vat_group0[fmt] = value;
        gx->vat_group0_valid[fmt] = true;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_VAT, fmt, 0u, value, 0u);
        (void)dol_gx_recomp_derive_vertex_layout(gx, fmt);
        return true;
    }
    if (reg >= DOL_GX_CP_REG_VAT_GRP1 &&
        reg < DOL_GX_CP_REG_VAT_GRP1 + DOL_GX_RECOMP_VERTEX_FORMATS) {
        const u8 fmt = (u8)(reg - DOL_GX_CP_REG_VAT_GRP1);
        gx->vat_group1[fmt] = value;
        gx->vat_group1_valid[fmt] = true;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_VAT, fmt, 1u, value, 0u);
        (void)dol_gx_recomp_derive_vertex_layout(gx, fmt);
        return true;
    }
    if (reg >= DOL_GX_CP_REG_VAT_GRP2 &&
        reg < DOL_GX_CP_REG_VAT_GRP2 + DOL_GX_RECOMP_VERTEX_FORMATS) {
        const u8 fmt = (u8)(reg - DOL_GX_CP_REG_VAT_GRP2);
        gx->vat_group2[fmt] = value;
        gx->vat_group2_valid[fmt] = true;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_VAT, fmt, 2u, value, 0u);
        (void)dol_gx_recomp_derive_vertex_layout(gx, fmt);
        return true;
    }
    if (reg >= DOL_GX_CP_REG_ARRAYBASE &&
        reg < DOL_GX_CP_REG_ARRAYBASE + DOL_GX_RECOMP_CP_ARRAY_COUNT) {
        const u8 attr = (u8)(reg - DOL_GX_CP_REG_ARRAYBASE);
        gx->arrays[attr].base_valid = true;
        gx->arrays[attr].physical_base = value;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE, attr, value, 0, 0);
        return true;
    }
    if (reg >= DOL_GX_CP_REG_ARRAYSTRIDE &&
        reg < DOL_GX_CP_REG_ARRAYSTRIDE + DOL_GX_RECOMP_CP_ARRAY_COUNT) {
        const u8 attr = (u8)(reg - DOL_GX_CP_REG_ARRAYSTRIDE);
        gx->arrays[attr].stride_valid = true;
        gx->arrays[attr].stride = value;
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CP_ARRAY_STRIDE, attr, value, 0,
                    0);
        return true;
    }
    return true;
}

bool dol_gx_recomp_resolve_cp_array(DolGxRecompState* gx, u8 attr,
                                    u32 byte_span,
                                    DolGxRecompResolvedArray* out) {
    if (gx == NULL || out == NULL || attr >= DOL_GX_RECOMP_CP_ARRAY_COUNT ||
        byte_span == 0u || !gx->arrays[attr].base_valid)
        return false;
    DolGuestResolvedRange range;
    if (!resolve_physical(gx, gx->arrays[attr].physical_base, byte_span,
                          DOL_GUEST_RESOURCE_VERTEX_ARRAY, &range))
        return false;
    out->range = range;
    out->attr = attr;
    out->stride = gx->arrays[attr].stride_valid ? gx->arrays[attr].stride : 0u;
    out->byte_span = byte_span;
    return true;
}

bool dol_gx_recomp_indexed_span(const void* vertices, u32 vertex_size,
                                u16 vertex_count, u32 index_offset,
                                u8 index_size, u32 array_stride,
                                u32 element_size, u32 element_bias,
                                u32* out_span) {
    if (vertices == NULL || out_span == NULL || vertex_count == 0u ||
        vertex_size == 0u || (index_size != 1u && index_size != 2u) ||
        array_stride == 0u || element_size == 0u ||
        index_offset + index_size > vertex_size)
        return false;
    const u8* bytes = (const u8*)vertices;
    u32 span = 0;
    for (u16 i = 0; i < vertex_count; ++i) {
        const u8* index_ptr = bytes + (u32)i * vertex_size + index_offset;
        const u32 index = read_index(index_ptr, index_size);
        const u32 required = index * array_stride + element_bias + element_size;
        if (required > span)
            span = required;
    }
    *out_span = span;
    return true;
}

bool dol_gx_recomp_texture_size(u16 width, u16 height, u32 format,
                                u32* out_size) {
    if (out_size == NULL || width == 0u || height == 0u)
        return false;

    u32 block_w = 0;
    u32 block_h = 0;
    u32 bytes_per_block = 0;
    /* Full GXTexFmt codes: plain formats < 0x10, Z formats carry 0x10, EFB
     * channel-select copy formats carry 0x20 (both per GXEnum.h). Block
     * geometry follows bits-per-texel (Dolphin TextureDecoder). */
    switch (format) {
    case 0x00: /* I4 */
    case 0x08: /* CI4 */
    case 0x0E: /* CMPR */
    case 0x20: /* CTF_R4 */
    case 0x30: /* CTF_Z4 */
        block_w = 8;
        block_h = 8;
        bytes_per_block = 32;
        break;
    case 0x01: /* I8 */
    case 0x02: /* IA4 */
    case 0x09: /* CI8 */
    case 0x11: /* Z8 */
    case 0x22: /* CTF_RA4 */
    case 0x27: /* CTF_A8 */
    case 0x28: /* CTF_R8 */
    case 0x29: /* CTF_G8 */
    case 0x2A: /* CTF_B8 */
    case 0x39: /* CTF_Z8M */
    case 0x3A: /* CTF_Z8L */
        block_w = 8;
        block_h = 4;
        bytes_per_block = 32;
        break;
    case 0x03: /* IA8 */
    case 0x04: /* RGB565 */
    case 0x05: /* RGB5A3 */
    case 0x0A: /* CI14X2 */
    case 0x13: /* Z16 */
    case 0x23: /* CTF_RA8 */
    case 0x2B: /* CTF_RG8 */
    case 0x2C: /* CTF_GB8 */
    case 0x3C: /* CTF_Z16L */
        block_w = 4;
        block_h = 4;
        bytes_per_block = 32;
        break;
    case 0x06: /* RGBA8 */
    case 0x16: /* Z24X8 */
        block_w = 4;
        block_h = 4;
        bytes_per_block = 64;
        break;
    default:
        return false;
    }
    const u32 blocks_w = round_up(width, block_w) / block_w;
    const u32 blocks_h = round_up(height, block_h) / block_h;
    *out_size = blocks_w * blocks_h * bytes_per_block;
    return true;
}

bool dol_gx_recomp_resolve_texture_image(DolGxRecompState* gx, u8 slot,
                                         u32 image0, u32 image3,
                                         DolGxRecompTexture* out) {
    if (gx == NULL || out == NULL || slot >= DOL_GX_RECOMP_TEXTURE_SLOTS)
        return false;
    const u16 width = (u16)((image0 & 0x3FFu) + 1u);
    const u16 height = (u16)(((image0 >> 10) & 0x3FFu) + 1u);
    const u32 format = (image0 >> 20) & 0xFu;
    u32 byte_size = 0;
    if (!dol_gx_recomp_texture_size(width, height, format, &byte_size))
        return false;
    const u32 physical_base = texture_physical_base(image3);
    DolGuestResolvedRange range;
    if (!resolve_physical(gx, physical_base, byte_size,
                          DOL_GUEST_RESOURCE_TEXTURE, &range))
        return false;
    DolGxRecompTexture texture = {
        .valid = true,
        .slot = slot,
        .width = width,
        .height = height,
        .format = format,
        .physical_base = physical_base,
        .byte_size = byte_size,
        .range = range,
    };
    gx->textures[slot] = texture;
    *out = texture;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_TEXTURE, slot, physical_base,
                byte_size, format);
    /* Carry the decoded dimensions on the event just emitted so an issuing
     * consumer can upload without re-decoding image0. */
    if (gx->trace_count > 0u) {
        DolGxRecompTraceEvent* ev = &gx->trace[gx->trace_count - 1u];
        if (ev->kind == DOL_GX_RECOMP_EVENT_TEXTURE && ev->a == slot) {
            ev->e = width;
            ev->f = height;
            /* CI formats (C4=0x8, C8=0x9, C14X2=0xA) index a TLUT; carry the
             * resolved palette (physical base + entry count from the TMEM tlut,
             * format from the SetTlut register bits) so an issuing consumer can
             * decode without re-walking BP state. */
            if ((format == 0x8u || format == 0x9u || format == 0xAu) &&
                gx->texture_tlut_valid[slot]) {
                const u16 tmem_offset = gx->texture_tlut_tmem_offset[slot];
                if (tmem_offset < DOL_GX_RECOMP_TMEM_TLUT_SLOTS &&
                    gx->tmem_tluts[tmem_offset].valid) {
                    const DolGxRecompTlut* t = &gx->tmem_tluts[tmem_offset];
                    ev->tlut_address = t->physical_base;
                    ev->tlut_format = gx->texture_tlut_format[slot];
                    ev->tlut_entries = t->entries;
                }
            }
        }
    }
    return true;
}

bool dol_gx_recomp_resolve_tlut(DolGxRecompState* gx, u8 slot,
                                u32 load_tlut0, u32 format, u16 entries,
                                DolGxRecompTlut* out) {
    if (gx == NULL || out == NULL || slot >= DOL_GX_RECOMP_TLUT_SLOTS ||
        entries == 0u)
        return false;
    DolGxRecompTlut tlut;
    if (!dol_gx_recomp_resolve_tmem_tlut(gx, slot, load_tlut0, format,
                                         entries, &tlut))
        return false;
    gx->tluts[slot] = tlut;
    *out = tlut;
    return true;
}

bool dol_gx_recomp_resolve_tmem_tlut(DolGxRecompState* gx, u16 tmem_offset,
                                     u32 load_tlut0, u32 format, u16 entries,
                                     DolGxRecompTlut* out) {
    if (gx == NULL || out == NULL ||
        tmem_offset >= DOL_GX_RECOMP_TMEM_TLUT_SLOTS || entries == 0u)
        return false;
    const u32 byte_size = (u32)entries * 2u;
    const u32 physical_base = texture_physical_base(load_tlut0);
    DolGuestResolvedRange range;
    if (!resolve_physical(gx, physical_base, byte_size,
                          DOL_GUEST_RESOURCE_TLUT, &range))
        return false;
    DolGxRecompTlut tlut = {
        .valid = true,
        .slot = tmem_offset < DOL_GX_RECOMP_TLUT_SLOTS ? (u8)tmem_offset
                                                       : 0xFFu,
        .tmem_offset = tmem_offset,
        .format = format,
        .entries = entries,
        .physical_base = physical_base,
        .byte_size = byte_size,
        .range = range,
    };
    gx->tmem_tluts[tmem_offset] = tlut;
    *out = tlut;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_TLUT, tmem_offset, physical_base,
                byte_size, format);
    return true;
}

bool dol_gx_recomp_resolve_copy_destination(DolGxRecompState* gx,
                                            u32 physical_base, u32 byte_size,
                                            DolGuestResolvedRange* out) {
    if (gx == NULL || out == NULL || byte_size == 0u)
        return false;
    if (!resolve_physical(gx, physical_base, byte_size,
                          DOL_GUEST_RESOURCE_COPY_DESTINATION, out))
        return false;
    /* Carry the full copy params for the gxcore EFB-copy consumer:
     * c=texCopyFmt — the TRUE GXTexFmt the frontend reconstructed from the
     * trigger, incl. the Z bit (0x10) when PE_CONTROL was Z24 at trigger time
     * (depth-source copy, Dolphin BPStructs.cpp is_depth_copy) and the CTF bit
     * (0x20) for channel-select formats — d=clear flag, e=EFB source x,
     * f=source y, g=packed dims (width<<16 | height). In-memory only (never
     * in .dolt). */
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_COPY_DESTINATION, physical_base,
                byte_size, gx->copy.format, gx->copy.clear);
    if (gx->trace_count > 0u) {
        DolGxRecompTraceEvent* ev = &gx->trace[gx->trace_count - 1u];
        ev->e = gx->copy.src_x;
        ev->f = gx->copy.src_y;
        ev->g = (gx->copy.width << 16u) | (gx->copy.height & 0xFFFFu);
    }
    return true;
}

bool dol_gx_recomp_note_display_copy(DolGxRecompState* gx, u32 clear) {
    if (gx == NULL)
        return false;
    /* c=0xF marks the display copy (no dest texture); d=clear. The consumer
     * applies the copy-clear (BP 0x4F-0x51 at this stream position) as the
     * next frame's EFB clear. In-memory only (never in .dolt). */
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_COPY_DESTINATION, 0u, 0u, 0xFu, clear);
    if (gx->trace_count > 0u) {
        DolGxRecompTraceEvent* ev = &gx->trace[gx->trace_count - 1u];
        ev->e = gx->copy.src_x;
        ev->f = gx->copy.src_y;
        ev->g = (gx->copy.width << 16u) | (gx->copy.height & 0xFFFFu);
    }
    return true;
}

bool dol_gx_recomp_note_bp_reg(DolGxRecompState* gx, u8 reg, u32 value) {
    if (gx == NULL)
        return false;
    gx->bp_regs[reg] = value;
    gx->bp_valid[reg] = true;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_BP_REG, reg, value, 0, 0);
    if (reg == DOL_GX_BP_REG_GENMODE) {
        gx->cull_all = ((value >> 14) & 0x3u) == 3u;
        /* Emit the cull-all state on EVERY genMode write, not just the ->ALL
         * transition: the consumer latches this flag, so without the ALL->normal
         * edge it stays culled forever. (Strikers sets GX_CULL_ALL on a batch of
         * draws late in a frame, then never re-clears it via a path we emit —
         * frames after the first would cull all geometry.) Carry the boolean in
         * event.a so the consumer tracks true on cull==ALL, false otherwise. */
        dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_CULL_ALL, gx->cull_all ? 1u : 0u, 0,
                    0, 0);
    }
    return true;
}

bool dol_gx_recomp_note_xf_load(DolGxRecompState* gx, u16 base, u8 count) {
    if (gx == NULL || count == 0u)
        return false;
    gx->last_xf_base = base;
    gx->last_xf_count = count;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_XF_LOAD, base, count, 0, 0);
    return true;
}

bool dol_gx_recomp_capture_xf_transform(DolGxRecompState* gx, u16 base, u8 count,
                                        const u8* data_be) {
    if (gx == NULL || data_be == NULL || count == 0u)
        return false;
    /* Position matrices occupy XF memory 0x0000..0x0077, texture matrices
     * 0x78..0xFB. Matrix index A is register 0x1018. Viewport occupies
     * 0x101A..0x101F, projection 0x1020..0x1026, and the raw register window
     * 0x1018..0x1057 spans matrix indices through the dual-tex matrix info
     * regs. Lights occupy 0x600..0x67F and the channel registers
     * 0x1009..0x1011. Skip loads that touch none of these inputs. */
    const u32 first = base;
    const u32 last = (u32)base + (u32)count - 1u; /* inclusive */
    const u32 pn_last = DOL_GX_RECOMP_POSITION_MATRIX_COUNT *
                            DOL_GX_RECOMP_POSITION_MATRIX_WORDS -
                        1u;
    const u32 tex_last = DOL_GX_XF_TEX_MATRIX_BASE +
                         DOL_GX_RECOMP_TEX_MATRIX_COUNT *
                             DOL_GX_RECOMP_TEX_MATRIX_WORDS -
                         1u;
    const bool touches_pn = first <= pn_last;
    const bool touches_tex =
        last >= DOL_GX_XF_TEX_MATRIX_BASE && first <= tex_last;
    const bool touches_scalar =
        last >= DOL_GX_XF_CHAN_REG_BASE && first <= DOL_GX_XF_PROJECTION_TYPE;
    const bool touches_window =
        last >= DOL_GX_XF_REG_WINDOW_BASE &&
        first < DOL_GX_XF_REG_WINDOW_BASE + DOL_GX_RECOMP_XF_REG_COUNT;
    const bool touches_light =
        last >= DOL_GX_XF_LIGHT_BASE && first < DOL_GX_XF_LIGHT_END;
    const bool touches_normal =
        last >= DOL_GX_XF_NORMAL_MATRIX_BASE &&
        first < DOL_GX_XF_NORMAL_MATRIX_END;
    if (!touches_pn && !touches_tex && !touches_scalar && !touches_window &&
        !touches_light && !touches_normal)
        return false;
    bool captured = false;
    for (u32 w = 0u; w < count; ++w) {
        const u32 xf_addr = (u32)base + w;
        const u32 bits = read_be32(data_be + w * 4u);
        f32 value;
        memcpy(&value, &bits, sizeof(value));
        /* Raw register window first: it overlaps the decoded fields below
         * (viewport/projection live inside it), so it must not join the
         * else-if chain. */
        if (xf_addr >= DOL_GX_XF_REG_WINDOW_BASE &&
            xf_addr < DOL_GX_XF_REG_WINDOW_BASE + DOL_GX_RECOMP_XF_REG_COUNT) {
            const u32 rel = xf_addr - DOL_GX_XF_REG_WINDOW_BASE;
            gx->xf_regs[rel] = bits;
            gx->xf_reg_mask |= 1ull << rel;
            captured = true;
        }
        if (xf_addr <= pn_last) {
            const u32 matrix = xf_addr / DOL_GX_RECOMP_POSITION_MATRIX_WORDS;
            const u32 word = xf_addr % DOL_GX_RECOMP_POSITION_MATRIX_WORDS;
            gx->position_matrices[matrix][word] = value;
            gx->position_matrix_word_mask[matrix] |= (u16)(1u << word);
            gx->position_matrix_valid[matrix] =
                gx->position_matrix_word_mask[matrix] ==
                ((1u << DOL_GX_RECOMP_POSITION_MATRIX_WORDS) - 1u);
            captured = true;
        } else if (xf_addr >= DOL_GX_XF_TEX_MATRIX_BASE &&
                   xf_addr <= tex_last) {
            const u32 rel = xf_addr - DOL_GX_XF_TEX_MATRIX_BASE;
            const u32 matrix = rel / DOL_GX_RECOMP_TEX_MATRIX_WORDS;
            const u32 word = rel % DOL_GX_RECOMP_TEX_MATRIX_WORDS;
            gx->tex_matrices[matrix][word] = value;
            gx->tex_matrix_word_mask[matrix] |= (u16)(1u << word);
            captured = true;
        } else if (xf_addr == DOL_GX_XF_MATRIX_INDEX_A) {
            note_matrix_index_a(gx, bits);
            captured = true;
        } else if (xf_addr >= DOL_GX_XF_VIEWPORT_BASE &&
            xf_addr <= DOL_GX_XF_VIEWPORT_BASE + 5u) {
            gx->viewport[xf_addr - DOL_GX_XF_VIEWPORT_BASE] = value;
            gx->viewport_valid = true;
            captured = true;
        } else if (xf_addr >= DOL_GX_XF_PROJECTION_BASE &&
                   xf_addr <= DOL_GX_XF_PROJECTION_BASE + 5u) {
            gx->projection[xf_addr - DOL_GX_XF_PROJECTION_BASE] = value;
            gx->projection_valid = true;
            captured = true;
        } else if (xf_addr == DOL_GX_XF_PROJECTION_TYPE) {
            gx->projection_type = bits;
        } else if (xf_addr >= DOL_GX_XF_LIGHT_BASE &&
                   xf_addr < DOL_GX_XF_LIGHT_END) {
            const u32 rel = xf_addr - DOL_GX_XF_LIGHT_BASE;
            const u32 light = rel / DOL_GX_RECOMP_LIGHT_WORDS;
            const u32 word = rel % DOL_GX_RECOMP_LIGHT_WORDS;
            gx->light_words[light][word] = bits;
            gx->light_word_mask[light] |= (u16)(1u << word);
            captured = true;
        } else if (xf_addr >= DOL_GX_XF_CHAN_REG_BASE &&
                   xf_addr <
                       DOL_GX_XF_CHAN_REG_BASE + DOL_GX_RECOMP_CHAN_REG_COUNT) {
            const u32 rel = xf_addr - DOL_GX_XF_CHAN_REG_BASE;
            gx->chan_regs[rel] = bits;
            gx->chan_reg_mask |= (u16)(1u << rel);
            captured = true;
        } else if (xf_addr >= DOL_GX_XF_NORMAL_MATRIX_BASE &&
                   xf_addr < DOL_GX_XF_NORMAL_MATRIX_END) {
            const u32 rel = xf_addr - DOL_GX_XF_NORMAL_MATRIX_BASE;
            const u32 matrix = rel / DOL_GX_RECOMP_NORMAL_MATRIX_WORDS;
            const u32 word = rel % DOL_GX_RECOMP_NORMAL_MATRIX_WORDS;
            if (matrix < DOL_GX_RECOMP_NORMAL_MATRIX_COUNT) {
                gx->normal_matrices[matrix][word] = value;
                gx->normal_matrix_word_mask[matrix] |= (u16)(1u << word);
                captured = true;
            }
        }
    }
    return captured;
}

bool dol_gx_recomp_note_invalidate_vtx_cache(DolGxRecompState* gx) {
    if (gx == NULL)
        return false;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_INVALIDATE_VTX_CACHE, 0u, 0u, 0u,
                0u);
    return true;
}

bool dol_gx_recomp_set_vertex_layout(DolGxRecompState* gx, u8 vtx_fmt,
                                     u32 vertex_size) {
    if (gx == NULL || vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS ||
        vertex_size == 0u)
        return false;
    DolGxRecompVertexLayout* layout = &gx->vertex_layouts[vtx_fmt];
    memset(layout, 0, sizeof(*layout));
    layout->valid = true;
    layout->vertex_size = vertex_size;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT, vtx_fmt, vertex_size,
                0u, 0u);
    return true;
}

bool dol_gx_recomp_set_indexed_attr(DolGxRecompState* gx, u8 vtx_fmt,
                                    u8 attr, u32 vertex_offset,
                                    u8 index_size, u32 element_size,
                                    u32 element_bias) {
    if (gx == NULL || vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS ||
        attr >= DOL_GX_RECOMP_CP_ARRAY_COUNT ||
        (index_size != 1u && index_size != 2u) || element_size == 0u)
        return false;
    DolGxRecompVertexLayout* layout = &gx->vertex_layouts[vtx_fmt];
    if (!layout->valid || vertex_offset + index_size > layout->vertex_size)
        return false;
    return add_indexed_attr_spec(layout, attr, vertex_offset, index_size,
                                 element_size, element_bias);
}

bool dol_gx_recomp_derive_vertex_layout(DolGxRecompState* gx, u8 vtx_fmt) {
    if (gx == NULL || vtx_fmt >= DOL_GX_RECOMP_VERTEX_FORMATS)
        return false;
    DolGxRecompVertexLayout layout;
    if (!derive_layout_from_cp(gx, vtx_fmt, &layout))
        return false;
    gx->vertex_layouts[vtx_fmt] = layout;
    dol_gx_recomp_trace_event(gx, DOL_GX_RECOMP_EVENT_VERTEX_LAYOUT, vtx_fmt,
                layout.vertex_size, layout.indexed_attr_count, 0u);
    return true;
}

