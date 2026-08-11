// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/di.h"

#include <string.h>

void dol_di_init(DolDi* di) {
    if (di == NULL)
        return;
    memset(di, 0, sizeof(*di));
    // No disc means the cover is open. CONFIG=1 disables the bootrom
    // descrambler, matching Dolphin's GameCube DI reset state.
    di->cover = DOL_DI_COVER_OPEN;
    di->config = 1u;
}

void dol_di_set_command_callback(DolDi* di, DolDiCommandFn execute,
                                 void* user) {
    if (di == NULL)
        return;
    di->execute = execute;
    di->execute_user = user;
}

bool dol_di_mmio_contains(u32 ea) {
    return ea >= DOL_DI_BASE &&
           ea < DOL_DI_BASE + DOL_DI_REGISTER_BYTES;
}

u64 dol_di_mmio_read(const DolDi* di, u32 ea, u8 size) {
    if (di == NULL || size != 4u || !dol_di_mmio_contains(ea))
        return 0;
    switch (ea - DOL_DI_BASE) {
    case DOL_DI_STATUS_OFF:
        return di->status;
    case DOL_DI_COVER_OFF:
        return di->cover;
    case DOL_DI_COMMAND_0_OFF:
        return di->command[0];
    case DOL_DI_COMMAND_1_OFF:
        return di->command[1];
    case DOL_DI_COMMAND_2_OFF:
        return di->command[2];
    case DOL_DI_DMA_ADDRESS_OFF:
        return di->dma_address;
    case DOL_DI_DMA_LENGTH_OFF:
        return di->dma_length;
    case DOL_DI_CONTROL_OFF:
        return di->control;
    case DOL_DI_IMMEDIATE_DATA_OFF:
        return di->immediate_data;
    case DOL_DI_CONFIG_OFF:
        return di->config;
    default:
        return 0;
    }
}

static void write_status(DolDi* di, u32 value) {
    const u32 masks = DOL_DI_STATUS_DEINTMASK |
                      DOL_DI_STATUS_TCINTMASK |
                      DOL_DI_STATUS_BRKINTMASK;
    di->status = (di->status & ~masks) | (value & masks);
    if ((value & DOL_DI_STATUS_DEINT) != 0u)
        di->status &= ~DOL_DI_STATUS_DEINT;
    if ((value & DOL_DI_STATUS_TCINT) != 0u)
        di->status &= ~DOL_DI_STATUS_TCINT;
    if ((value & DOL_DI_STATUS_BRKINT) != 0u)
        di->status &= ~DOL_DI_STATUS_BRKINT;

    if ((value & DOL_DI_STATUS_BREAK) != 0u) {
        di->status |= DOL_DI_STATUS_BREAK;
        if ((di->control & DOL_DI_CONTROL_TSTART) != 0u) {
            di->control &= ~DOL_DI_CONTROL_TSTART;
            di->status |= DOL_DI_STATUS_BRKINT;
        }
    } else {
        di->status &= ~DOL_DI_STATUS_BREAK;
    }
}

void dol_di_complete_command(DolDi* di, DolDiCommandResult result) {
    if (di == NULL || result == DOL_DI_COMMAND_DEFERRED)
        return;
    if ((di->control & DOL_DI_CONTROL_TSTART) == 0u)
        return;

    if (result == DOL_DI_COMMAND_COMPLETE) {
        if ((di->control & DOL_DI_CONTROL_DMA) != 0u) {
            di->dma_address += di->dma_length;
            di->dma_length = 0u;
        }
        di->status |= DOL_DI_STATUS_TCINT;
    } else {
        di->status |= DOL_DI_STATUS_DEINT;
    }
    di->control &= ~DOL_DI_CONTROL_TSTART;
}

static void start_command(DolDi* di, CPUState* cpu) {
    DolDiCommand command = {
        .cpu = cpu,
        .command = {di->command[0], di->command[1], di->command[2]},
        .dma_address = di->dma_address,
        .dma_length = di->dma_length,
        .dma = (di->control & DOL_DI_CONTROL_DMA) != 0u,
        .write = (di->control & DOL_DI_CONTROL_WRITE) != 0u,
        .immediate_data = &di->immediate_data,
    };
    const DolDiCommandResult result =
        di->execute != NULL
            ? di->execute(di->execute_user, &command)
            : DOL_DI_COMMAND_ERROR;
    dol_di_complete_command(di, result);
}

void dol_di_mmio_write(DolDi* di, CPUState* cpu, u32 ea, u8 size, u64 value) {
    if (di == NULL || size != 4u || !dol_di_mmio_contains(ea))
        return;
    switch (ea - DOL_DI_BASE) {
    case DOL_DI_STATUS_OFF:
        write_status(di, (u32)value);
        break;
    case DOL_DI_COVER_OFF:
        di->cover =
            (di->cover & ~DOL_DI_COVER_INT_MASK) |
            ((u32)value & DOL_DI_COVER_INT_MASK);
        if (((u32)value & DOL_DI_COVER_INT) != 0u)
            di->cover &= ~DOL_DI_COVER_INT;
        break;
    case DOL_DI_COMMAND_0_OFF:
        di->command[0] = (u32)value;
        break;
    case DOL_DI_COMMAND_1_OFF:
        di->command[1] = (u32)value;
        break;
    case DOL_DI_COMMAND_2_OFF:
        di->command[2] = (u32)value;
        break;
    case DOL_DI_DMA_ADDRESS_OFF:
        di->dma_address = (u32)value & 0x03FFFFE0u;
        break;
    case DOL_DI_DMA_LENGTH_OFF:
        di->dma_length = (u32)value & ~0x1Fu;
        break;
    case DOL_DI_CONTROL_OFF:
        di->control = (u32)value & 0x7u;
        if ((di->control & DOL_DI_CONTROL_TSTART) != 0u)
            start_command(di, cpu);
        break;
    case DOL_DI_IMMEDIATE_DATA_OFF:
        di->immediate_data = (u32)value;
        break;
    case DOL_DI_CONFIG_OFF:
        // Read-only on GameCube.
        break;
    default:
        break;
    }
}

void dol_di_set_disc_present(DolDi* di, bool present) {
    if (di == NULL)
        return;
    const bool was_open = (di->cover & DOL_DI_COVER_OPEN) != 0u;
    const bool is_open = !present;
    if (is_open)
        di->cover |= DOL_DI_COVER_OPEN;
    else
        di->cover &= ~DOL_DI_COVER_OPEN;
    if (was_open != is_open)
        di->cover |= DOL_DI_COVER_INT;
}

bool dol_di_interrupt_pending(const DolDi* di) {
    if (di == NULL)
        return false;
    return ((di->status & DOL_DI_STATUS_DEINT) != 0u &&
            (di->status & DOL_DI_STATUS_DEINTMASK) != 0u) ||
           ((di->status & DOL_DI_STATUS_TCINT) != 0u &&
            (di->status & DOL_DI_STATUS_TCINTMASK) != 0u) ||
           ((di->status & DOL_DI_STATUS_BRKINT) != 0u &&
            (di->status & DOL_DI_STATUS_BRKINTMASK) != 0u) ||
           ((di->cover & DOL_DI_COVER_INT) != 0u &&
            (di->cover & DOL_DI_COVER_INT_MASK) != 0u);
}
