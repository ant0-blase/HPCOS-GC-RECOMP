// SPDX-License-Identifier: GPL-3.0-or-later
// ARAM model: a flat 16 MB buffer mapped into a synthetic CPU-addressable
// window [ARAM_BASE, ARAM_BASE + ARAM_SIZE). See aram.h.
#include "gxruntime/aram.h"

#include <stdlib.h>
#include <string.h>

static u8* g_aram = NULL;

void aram_init(void) {
    if (!g_aram)
        g_aram = (u8*)calloc(1, ARAM_SIZE);
}

void aram_free(void) {
    free(g_aram);
    g_aram = NULL;
}

bool aram_contains(u32 ea) {
    return ea >= ARAM_BASE && ea < ARAM_BASE + ARAM_SIZE;
}

// Offset of a guest ARAM address into the buffer. Accepts both CPU-window
// addresses (>= ARAM_BASE) and raw ARAM-space offsets (< ARAM_SIZE), since the
// SDK uses both forms.
static u32 aram_offset(u32 ea) {
    u32 off = (ea >= ARAM_BASE) ? (ea - ARAM_BASE) : ea;
    return off & (ARAM_SIZE - 1u);
}

u64 aram_read(u32 ea, u8 size) {
    if (!g_aram)
        return 0;
    u32 off = aram_offset(ea);
    u64 v = 0;
    for (u8 i = 0; i < size; i++)  // big-endian, matching guest memory
        v = (v << 8) | g_aram[(off + i) & (ARAM_SIZE - 1u)];
    return v;
}

void aram_write(u32 ea, u64 value, u8 size) {
    if (!g_aram)
        return;
    u32 off = aram_offset(ea);
    for (u8 i = 0; i < size; i++)
        g_aram[(off + (size - 1u - i)) & (ARAM_SIZE - 1u)] = (u8)(value >> (8 * i));
}

void aram_dma_to_aram(const u8* ram, u32 ram_addr, u32 aram_addr, u32 length) {
    if (!g_aram)
        return;
    u32 off = aram_offset(aram_addr);
    u32 r = ram_addr - 0x80000000u;
    for (u32 i = 0; i < length; i++)
        g_aram[(off + i) & (ARAM_SIZE - 1u)] = ram[r + i];
}

void aram_dma_to_ram(u8* ram, u32 ram_addr, u32 aram_addr, u32 length) {
    if (!g_aram)
        return;
    u32 off = aram_offset(aram_addr);
    u32 r = ram_addr - 0x80000000u;
    for (u32 i = 0; i < length; i++)
        ram[r + i] = g_aram[(off + i) & (ARAM_SIZE - 1u)];
}
