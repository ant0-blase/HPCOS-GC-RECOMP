// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/exi.h"

#include <string.h>

static bool decode_address(u32 ea, u32* channel, u32* offset) {
    if (!dol_exi_mmio_contains(ea))
        return false;
    const u32 relative = ea - DOL_EXI_BASE;
    if (channel != NULL)
        *channel = relative / DOL_EXI_CHANNEL_STRIDE;
    if (offset != NULL)
        *offset = relative % DOL_EXI_CHANNEL_STRIDE;
    return true;
}

static u32 chip_select(const DolExiChannel* channel) {
    return (channel->status & DOL_EXI_STATUS_CHIP_SELECT_MASK) >> 7u;
}

void dol_exi_init(DolExi* exi) {
    if (exi == NULL)
        return;
    memset(exi, 0, sizeof(*exi));
    // Dolphin initializes channels 0/1 with an external-change latch, and
    // channel 1 starts with chip select 1.
    exi->channels[0].status = DOL_EXI_STATUS_EXTINT;
    exi->channels[1].status =
        DOL_EXI_STATUS_EXTINT | (1u << 7u);
}

void dol_exi_set_transfer_callback(DolExi* exi, DolExiTransferFn transfer,
                                   void* user) {
    if (exi == NULL)
        return;
    exi->transfer = transfer;
    exi->transfer_user = user;
}

bool dol_exi_mmio_contains(u32 ea) {
    return ea >= DOL_EXI_BASE &&
           ea < DOL_EXI_BASE + DOL_EXI_REGISTER_BYTES;
}

u64 dol_exi_mmio_read(const DolExi* exi, u32 ea, u8 size) {
    u32 channel = 0;
    u32 offset = 0;
    if (exi == NULL || size != 4u ||
        !decode_address(ea, &channel, &offset))
        return 0;
    const DolExiChannel* ch = &exi->channels[channel];
    switch (offset) {
    case DOL_EXI_STATUS_OFF:
        return ch->status;
    case DOL_EXI_DMA_ADDRESS_OFF:
        return ch->dma_address;
    case DOL_EXI_DMA_LENGTH_OFF:
        return ch->dma_length;
    case DOL_EXI_CONTROL_OFF:
        return ch->control;
    case DOL_EXI_IMMEDIATE_DATA_OFF:
        return ch->immediate_data;
    default:
        return 0;
    }
}

static void write_status(DolExi* exi, u32 channel, u32 value) {
    DolExiChannel* ch = &exi->channels[channel];
    u32 writable =
        DOL_EXI_STATUS_EXIINTMASK | DOL_EXI_STATUS_TCINTMASK |
        DOL_EXI_STATUS_CLK_MASK | DOL_EXI_STATUS_CHIP_SELECT_MASK;
    if (channel < 2u)
        writable |= DOL_EXI_STATUS_EXTINTMASK;
    ch->status = (ch->status & ~writable) | (value & writable);
    if ((value & DOL_EXI_STATUS_EXIINT) != 0u)
        ch->status &= ~DOL_EXI_STATUS_EXIINT;
    if ((value & DOL_EXI_STATUS_TCINT) != 0u)
        ch->status &= ~DOL_EXI_STATUS_TCINT;
    if (channel < 2u && (value & DOL_EXI_STATUS_EXTINT) != 0u)
        ch->status &= ~DOL_EXI_STATUS_EXTINT;
    if (channel == 0u) {
        ch->status = (ch->status & ~DOL_EXI_STATUS_ROMDIS) |
                     (value & DOL_EXI_STATUS_ROMDIS);
    }
}

void dol_exi_complete_transfer(DolExi* exi, u32 channel) {
    if (exi == NULL || channel >= DOL_EXI_CHANNELS)
        return;
    exi->channels[channel].control &= ~DOL_EXI_CONTROL_TSTART;
    exi->channels[channel].status |= DOL_EXI_STATUS_TCINT;
}

static void start_transfer(DolExi* exi, CPUState* cpu, u32 channel) {
    DolExiChannel* ch = &exi->channels[channel];
    const bool dma = (ch->control & DOL_EXI_CONTROL_DMA) != 0u;
    DolExiTransfer transfer = {
        .cpu = cpu,
        .channel = channel,
        .chip_select = chip_select(ch),
        .direction =
            (ch->control & DOL_EXI_CONTROL_RW_MASK) >> 2u,
        .length = dma ? ch->dma_length
                      : ((ch->control & DOL_EXI_CONTROL_TLEN_MASK) >> 4u) + 1u,
        .dma = dma,
        .dma_address = ch->dma_address,
        .immediate_data = &ch->immediate_data,
    };
    const bool completed =
        exi->transfer == NULL ||
        exi->transfer(exi->transfer_user, &transfer);
    if (completed)
        dol_exi_complete_transfer(exi, channel);
}

void dol_exi_mmio_write(DolExi* exi, CPUState* cpu, u32 ea, u8 size,
                        u64 value) {
    u32 channel = 0;
    u32 offset = 0;
    if (exi == NULL || size != 4u ||
        !decode_address(ea, &channel, &offset))
        return;
    DolExiChannel* ch = &exi->channels[channel];
    switch (offset) {
    case DOL_EXI_STATUS_OFF:
        write_status(exi, channel, (u32)value);
        break;
    case DOL_EXI_DMA_ADDRESS_OFF:
        ch->dma_address = (u32)value;
        break;
    case DOL_EXI_DMA_LENGTH_OFF:
        ch->dma_length = (u32)value;
        break;
    case DOL_EXI_CONTROL_OFF:
        ch->control = (u32)value;
        if ((ch->control & DOL_EXI_CONTROL_TSTART) != 0u)
            start_transfer(exi, cpu, channel);
        break;
    case DOL_EXI_IMMEDIATE_DATA_OFF:
        ch->immediate_data = (u32)value;
        break;
    default:
        break;
    }
}

void dol_exi_set_device_interrupt(DolExi* exi, u32 channel, bool asserted) {
    if (exi == NULL || channel >= DOL_EXI_CHANNELS)
        return;
    if (asserted)
        exi->channels[channel].status |= DOL_EXI_STATUS_EXIINT;
    else
        exi->channels[channel].status &= ~DOL_EXI_STATUS_EXIINT;
}

void dol_exi_set_device_present(DolExi* exi, u32 channel, bool present,
                                bool signal_change) {
    if (exi == NULL || channel >= 2u)
        return;
    DolExiChannel* ch = &exi->channels[channel];
    if (present)
        ch->status |= DOL_EXI_STATUS_EXT;
    else
        ch->status &= ~DOL_EXI_STATUS_EXT;
    if (signal_change)
        ch->status |= DOL_EXI_STATUS_EXTINT;
}

bool dol_exi_interrupt_pending(const DolExi* exi) {
    if (exi == NULL)
        return false;
    for (u32 i = 0; i < DOL_EXI_CHANNELS; i++) {
        const u32 status = exi->channels[i].status;
        if (((status & DOL_EXI_STATUS_EXIINT) != 0u &&
             (status & DOL_EXI_STATUS_EXIINTMASK) != 0u) ||
            ((status & DOL_EXI_STATUS_TCINT) != 0u &&
             (status & DOL_EXI_STATUS_TCINTMASK) != 0u) ||
            ((status & DOL_EXI_STATUS_EXTINT) != 0u &&
             (status & DOL_EXI_STATUS_EXTINTMASK) != 0u))
            return true;
    }
    return false;
}
