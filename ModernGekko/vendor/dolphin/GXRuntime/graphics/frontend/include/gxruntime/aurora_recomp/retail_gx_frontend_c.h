// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef GXRUNTIME_AURORA_RECOMP_RETAIL_GX_FRONTEND_C_H
#define GXRUNTIME_AURORA_RECOMP_RETAIL_GX_FRONTEND_C_H

#include "gxruntime/gx_recomp.h"

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DolAuroraRecompRetailGxFrontend
    DolAuroraRecompRetailGxFrontend;

typedef enum DolAuroraRecompRenderPacketKind {
    DOL_AURORA_RECOMP_PACKET_TRACE_EVENT = 1,
    DOL_AURORA_RECOMP_PACKET_STREAM = 2,
    DOL_AURORA_RECOMP_PACKET_STATE = 3,
    DOL_AURORA_RECOMP_PACKET_RESOURCE = 4,
    DOL_AURORA_RECOMP_PACKET_DRAW = 5,
} DolAuroraRecompRenderPacketKind;

typedef enum DolAuroraRecompRenderStreamKind {
    DOL_AURORA_RECOMP_STREAM_FIFO_BYTES = 1,
    DOL_AURORA_RECOMP_STREAM_DISPLAY_LIST = 2,
} DolAuroraRecompRenderStreamKind;

typedef enum DolAuroraRecompRenderStateKind {
    DOL_AURORA_RECOMP_STATE_CP_ARRAY_BASE = 1,
    DOL_AURORA_RECOMP_STATE_CP_ARRAY_STRIDE = 2,
    DOL_AURORA_RECOMP_STATE_CP_VCD = 3,
    DOL_AURORA_RECOMP_STATE_CP_VAT = 4,
    DOL_AURORA_RECOMP_STATE_VERTEX_LAYOUT = 5,
    DOL_AURORA_RECOMP_STATE_BP_REG = 6,
    DOL_AURORA_RECOMP_STATE_XF_LOAD = 7,
    DOL_AURORA_RECOMP_STATE_INDEXED_XF_LOAD = 8,
    DOL_AURORA_RECOMP_STATE_CULL_ALL = 9,
    DOL_AURORA_RECOMP_STATE_INVALIDATE_VTX_CACHE = 10,
} DolAuroraRecompRenderStateKind;

typedef enum DolAuroraRecompRenderResourceKind {
    DOL_AURORA_RECOMP_RESOURCE_INDEXED_ARRAY_SPAN = 1,
    DOL_AURORA_RECOMP_RESOURCE_TEXTURE = 2,
    DOL_AURORA_RECOMP_RESOURCE_TLUT = 3,
    DOL_AURORA_RECOMP_RESOURCE_COPY_DESTINATION = 4,
} DolAuroraRecompRenderResourceKind;

#define DOL_AURORA_RECOMP_DRAW_TRANSFORM_VIEWPORT_VALID 0x1u
#define DOL_AURORA_RECOMP_DRAW_TRANSFORM_PROJECTION_VALID 0x2u
#define DOL_AURORA_RECOMP_DRAW_TRANSFORM_PAYLOAD_PN_MATRIX_VALID 0x4u

typedef struct DolAuroraRecompRenderStreamPacket {
    u32 kind;
    u32 address;
    u32 size;
    u32 address_space;
    u32 total_size;
} DolAuroraRecompRenderStreamPacket;

typedef struct DolAuroraRecompRenderStatePacket {
    u32 kind;
    u32 index;
    u32 value;
    u32 aux0;
    u32 aux1;
} DolAuroraRecompRenderStatePacket;

typedef struct DolAuroraRecompRenderResourcePacket {
    u32 kind;
    u32 index;
    u32 address;
    u32 size;
    u32 format;
    u32 count;
    u32 vtx_fmt;
    /* IndexedArraySpan decode params (zero for other resources). */
    u32 vertex_offset;
    u32 index_size;
    u32 element_size;
} DolAuroraRecompRenderResourcePacket;

typedef struct DolAuroraRecompRenderDrawPacket {
    u32 primitive;
    u32 vtx_fmt;
    u32 vertex_count;
    u32 vertex_size;
    /* Raw per-vertex FIFO payload (inline direct attrs + per-vertex indices).
     * Valid only for the duration of the submit callback; copy to retain. */
    const u8* vertex_payload;
    u32 vertex_payload_size;
    u32 transform_flags;
    u32 current_pn_matrix;
    u32 payload_pn_matrix_mask;
    u32 position_matrix_valid_mask;
    f32 viewport[6];
    f32 projection[6];
    u32 projection_type;
    f32 position_matrices[DOL_GX_RECOMP_POSITION_MATRIX_COUNT]
                         [DOL_GX_RECOMP_POSITION_MATRIX_WORDS];
} DolAuroraRecompRenderDrawPacket;

typedef struct DolAuroraRecompRenderPacket {
    u32 kind;
    u32 sequence;
    DolGxRecompTraceEvent event;
    DolAuroraRecompRenderStreamPacket stream;
    DolAuroraRecompRenderStatePacket state;
    DolAuroraRecompRenderResourcePacket resource;
    DolAuroraRecompRenderDrawPacket draw;
} DolAuroraRecompRenderPacket;

typedef bool (*DolAuroraRecompRenderPacketFn)(
    void* user, const DolAuroraRecompRenderPacket* packet);

DolAuroraRecompRetailGxFrontend*
dol_aurora_recomp_frontend_create(const DolGuestAddressResolver* resolver);

void dol_aurora_recomp_frontend_destroy(
    DolAuroraRecompRetailGxFrontend* frontend);

void dol_aurora_recomp_frontend_reset(
    DolAuroraRecompRetailGxFrontend* frontend,
    const DolGuestAddressResolver* resolver);

bool dol_aurora_recomp_frontend_set_vertex_layout(
    DolAuroraRecompRetailGxFrontend* frontend, u8 vtx_fmt, u32 vertex_size);

bool dol_aurora_recomp_frontend_set_indexed_attr(
    DolAuroraRecompRetailGxFrontend* frontend, u8 vtx_fmt, u8 attr,
    u32 vertex_offset, u8 index_size, u32 element_size, u32 element_bias);

bool dol_aurora_recomp_frontend_derive_vertex_layout(
    DolAuroraRecompRetailGxFrontend* frontend, u8 vtx_fmt);

bool dol_aurora_recomp_frontend_set_cp_array(
    DolAuroraRecompRetailGxFrontend* frontend, u8 attr, u32 physical_base,
    u8 stride);

bool dol_aurora_recomp_frontend_load_cp_reg(
    DolAuroraRecompRetailGxFrontend* frontend, u8 reg, u32 value);

bool dol_aurora_recomp_frontend_write_fifo(
    DolAuroraRecompRetailGxFrontend* frontend, const void* bytes, size_t size);

bool dol_aurora_recomp_frontend_flush(
    DolAuroraRecompRetailGxFrontend* frontend,
    DolAuroraRecompRenderPacketFn submit, void* user);

bool dol_aurora_recomp_frontend_replay_fifo(
    DolAuroraRecompRetailGxFrontend* frontend, const void* bytes, size_t size,
    DolAuroraRecompRenderPacketFn submit, void* user);

size_t dol_aurora_recomp_frontend_pending_fifo_size(
    const DolAuroraRecompRetailGxFrontend* frontend);

const DolGxRecompState* dol_aurora_recomp_frontend_state(
    const DolAuroraRecompRetailGxFrontend* frontend);

const DolGxRecompTraceEvent* dol_aurora_recomp_frontend_trace_events(
    const DolAuroraRecompRetailGxFrontend* frontend, u32* count);

const char* dol_aurora_recomp_trace_event_name(DolGxRecompEventKind kind);

#ifdef __cplusplus
}
#endif

#endif
