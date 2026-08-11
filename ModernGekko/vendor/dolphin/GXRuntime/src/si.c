// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/si.h"

#include <string.h>

static u32 load_be32(const u8* bytes, u32 off) {
    return ((u32)bytes[off] << 24) | ((u32)bytes[off + 1u] << 16) |
           ((u32)bytes[off + 2u] << 8) | bytes[off + 3u];
}

static void store_be32(u8* bytes, u32 off, u32 value) {
    bytes[off] = (u8)(value >> 24);
    bytes[off + 1u] = (u8)(value >> 16);
    bytes[off + 2u] = (u8)(value >> 8);
    bytes[off + 3u] = (u8)value;
}

static u64 read_be(const u8* bytes, u32 off, u8 size) {
    u64 value = 0;
    for (u8 i = 0; i < size; i++)
        value = (value << 8) | bytes[off + i];
    return value;
}

static void write_be(u8* bytes, u32 off, u8 size, u64 value) {
    for (u8 i = 0; i < size; i++)
        bytes[off + size - 1u - i] = (u8)(value >> (8u * i));
}

static u32 channel_rdst_bit(u32 channel) {
    return 0x20000000u >> (channel * 8u);
}

static bool channel_input_offset(u32 off, u32* channel) {
    for (u32 i = 0; i < 4u; i++) {
        const u32 in_hi = 0x04u + i * 0x0Cu;
        const u32 in_lo = in_hi + 4u;
        if (off == in_hi || off == in_lo) {
            if (channel != NULL)
                *channel = i;
            return true;
        }
    }
    return false;
}

static void sync_rdst(DolSiDevice* si) {
    u32 comcsr = load_be32(si->regs, DOL_SI_COMCSR_OFF);
    const u32 status = load_be32(si->regs, DOL_SI_STATUS_OFF);
    if ((status & DOL_SI_STATUS_RDST_ALL) != 0u)
        comcsr |= DOL_SI_RDSTINT;
    else
        comcsr &= ~DOL_SI_RDSTINT;
    store_be32(si->regs, DOL_SI_COMCSR_OFF, comcsr);
}

void dol_si_init(DolSiDevice* si) {
    if (si != NULL)
        memset(si, 0, sizeof(*si));
}

bool dol_si_mmio_contains(u32 ea) {
    return ea >= DOL_SI_BASE && ea < DOL_SI_BASE + DOL_SI_REGISTER_BYTES;
}

u64 dol_si_mmio_read(DolSiDevice* si, u32 ea, u8 size) {
    if (si == NULL || size == 0u || !dol_si_mmio_contains(ea))
        return 0;
    const u32 off = ea - DOL_SI_BASE;
    if (off + size > DOL_SI_REGISTER_BYTES)
        return 0;

    u32 channel = 0;
    if (size == 4u && channel_input_offset(off, &channel)) {
        const u64 value = read_be(si->regs, off, size);
        u32 status = load_be32(si->regs, DOL_SI_STATUS_OFF);
        status &= ~channel_rdst_bit(channel);
        store_be32(si->regs, DOL_SI_STATUS_OFF, status);
        sync_rdst(si);
        return value;
    }
    return read_be(si->regs, off, size);
}

void dol_si_mmio_write(DolSiDevice* si, u32 ea, u8 size, u64 value) {
    if (si == NULL || size == 0u || !dol_si_mmio_contains(ea))
        return;
    const u32 off = ea - DOL_SI_BASE;
    if (off + size > DOL_SI_REGISTER_BYTES)
        return;

    if (off == DOL_SI_COMCSR_OFF && size == 4u) {
        const u32 written = (u32)value;
        u32 comcsr = load_be32(si->regs, off);
        // Dolphin preserves the transfer channel/length fields and both masks.
        const u32 control_mask =
            0x00000006u | 0x00007F00u | 0x007F0000u |
            DOL_SI_RDSTINTMSK | DOL_SI_TCINTMSK;
        comcsr = (comcsr & ~control_mask) | (written & control_mask);
        if ((written & DOL_SI_RDSTINT) != 0u)
            comcsr &= ~DOL_SI_RDSTINT;
        if ((written & DOL_SI_TCINT) != 0u)
            comcsr &= ~DOL_SI_TCINT;
        if ((written & DOL_SI_TSTART) != 0u) {
            // The reusable runtime currently completes host SI transfers
            // synchronously. TSTART clears and TCINT latches independently.
            comcsr &= ~DOL_SI_TSTART;
            comcsr |= DOL_SI_TCINT;
        }
        store_be32(si->regs, off, comcsr);
        sync_rdst(si);
        return;
    }

    if (off == DOL_SI_STATUS_OFF && size == 4u) {
        u32 status = load_be32(si->regs, off);
        status &= ~((u32)value & DOL_SI_STATUS_ERROR_ALL);
        if (((u32)value & DOL_SI_STATUS_WR) != 0u)
            status &= ~DOL_SI_STATUS_WR;
        store_be32(si->regs, off, status);
        sync_rdst(si);
        return;
    }

    write_be(si->regs, off, size, value);
    sync_rdst(si);
}

void dol_si_latch_poll(DolSiDevice* si, u32 channel_mask) {
    if (si == NULL)
        return;
    u32 status = load_be32(si->regs, DOL_SI_STATUS_OFF);
    for (u32 channel = 0; channel < 4u; channel++) {
        if ((channel_mask & (1u << channel)) != 0u)
            status |= channel_rdst_bit(channel);
    }
    store_be32(si->regs, DOL_SI_STATUS_OFF, status);
    sync_rdst(si);
}

bool dol_si_interrupt_pending(const DolSiDevice* si) {
    if (si == NULL)
        return false;
    const u32 comcsr = load_be32(si->regs, DOL_SI_COMCSR_OFF);
    return ((comcsr & DOL_SI_RDSTINT) != 0u &&
            (comcsr & DOL_SI_RDSTINTMSK) != 0u) ||
           ((comcsr & DOL_SI_TCINT) != 0u &&
            (comcsr & DOL_SI_TCINTMSK) != 0u);
}
