// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/audio_dma.h"
#include "gxruntime/platform.h"

#include <string.h>

static u16 load_be16(const u8* data) {
    return (u16)(((u16)data[0] << 8) | data[1]);
}

static u32 load_be32(const u8* data) {
    return ((u32)data[0] << 24) | ((u32)data[1] << 16) |
           ((u32)data[2] << 8) | data[3];
}

static void store_be16(u8* data, u16 value) {
    data[0] = (u8)(value >> 8);
    data[1] = (u8)value;
}

static void store_be32(u8* data, u32 value) {
    data[0] = (u8)(value >> 24);
    data[1] = (u8)(value >> 16);
    data[2] = (u8)(value >> 8);
    data[3] = (u8)value;
}

static u64 register_read(const u8* regs, u32 offset, u8 size) {
    u64 value = 0;
    for (u8 i = 0; i < size; i++)
        value = (value << 8) | regs[offset + i];
    return value;
}

static void register_write(u8* regs, u32 offset, u8 size, u64 value) {
    for (u8 i = 0; i < size; i++)
        regs[offset + size - 1u - i] = (u8)(value >> (i * 8u));
}

static void recompute_work_units_per_chunk(DolAudioDma* dma) {
    if (dma->work_units_per_second == 0 || dma->chunks_per_second == 0) {
        dma->work_units_per_chunk = 1;
        return;
    }

    dma->work_units_per_chunk =
        dma->work_units_per_second / (u64)dma->chunks_per_second;
    if (dma->work_units_per_chunk == 0)
        dma->work_units_per_chunk = 1;
}

static void apply_ai_control(DolAudioDma* dma) {
    const u32 control = load_be32(dma->ai_regs + DOL_AUDIO_DMA_AI_CONTROL_OFF);
    // Dolphin: AIDFR set == 32 kHz AID, clear == 48 kHz AID (inverted w.r.t.
    // the rate name).
    const u32 rate = (control & DOL_AUDIO_DMA_AI_AIDFR_BIT) != 0u
                         ? DOL_AUDIO_DMA_32KHZ
                         : DOL_AUDIO_DMA_48KHZ;
    if (dma->sample_rate == rate)
        return;
    dol_audio_dma_set_sample_rate(dma, rate);
    dol_platform_audio_set_sample_rate(rate);
}

void dol_audio_dma_init(DolAudioDma* dma) {
    memset(dma, 0, sizeof(*dma));
    dma->sample_rate = DOL_AUDIO_DMA_32KHZ;
    dma->chunks_per_second =
        DOL_AUDIO_DMA_32KHZ / DOL_AUDIO_DMA_FRAMES_PER_CHUNK;
    dma->work_units_per_chunk = 1;
    store_be32(dma->ai_regs + DOL_AUDIO_DMA_AI_CONTROL_OFF,
               DOL_AUDIO_DMA_AI_CONTROL_INIT);
}

void dol_audio_dma_set_work_rate(DolAudioDma* dma, u64 work_units_per_second) {
    if (dma == NULL)
        return;
    dma->work_units_per_second = work_units_per_second;
    recompute_work_units_per_chunk(dma);
}

void dol_audio_dma_set_vi_clock(DolAudioDma* dma, u64 work_units_per_frame,
                                u32 refresh_hz) {
    if (dma == NULL)
        return;
    dma->work_units_per_frame = work_units_per_frame;
    dma->refresh_hz = refresh_hz;
    dma->work_units_per_second = work_units_per_frame * (u64)refresh_hz;
    recompute_work_units_per_chunk(dma);
}

void dol_audio_dma_set_sample_rate(DolAudioDma* dma, u32 sample_rate) {
    if (dma == NULL)
        return;
    if (sample_rate != DOL_AUDIO_DMA_48KHZ)
        sample_rate = DOL_AUDIO_DMA_32KHZ;
    dma->sample_rate = sample_rate;
    dma->chunks_per_second = sample_rate / DOL_AUDIO_DMA_FRAMES_PER_CHUNK;
    recompute_work_units_per_chunk(dma);
}

u32 dol_audio_dma_sample_rate(const DolAudioDma* dma) {
    return dma != NULL ? dma->sample_rate : DOL_AUDIO_DMA_32KHZ;
}

void dol_audio_dma_set_source(DolAudioDma* dma, u32 source_address) {
    if (dma != NULL)
        dma->source_address = source_address;
}

void dol_audio_dma_write_control(DolAudioDma* dma, u16 control) {
    if (dma == NULL)
        return;
    const bool was_enabled = (dma->control & DOL_AUDIO_DMA_ENABLE) != 0;
    dma->control = control;
    const bool enabled = (control & DOL_AUDIO_DMA_ENABLE) != 0;

    if (!enabled) {
        dma->remaining_blocks = 0;
        dma->work_counter = 0;
        return;
    }
    if (!was_enabled) {
        dma->remaining_blocks = control & DOL_AUDIO_DMA_BLOCK_MASK;
        dma->current_source_address = dma->source_address;
        dma->work_counter = 0;
        // Hardware raises AID shortly after the first transfer is latched.
        dma->interrupt_pending = true;
    }
}

u16 dol_audio_dma_read_control(const DolAudioDma* dma) {
    return dma != NULL ? dma->control : 0;
}

u16 dol_audio_dma_blocks_left(const DolAudioDma* dma) {
    if (dma == NULL || dma->remaining_blocks == 0)
        return 0;
    return dma->remaining_blocks - 1u;
}

void dol_audio_dma_ack_interrupt(DolAudioDma* dma) {
    if (dma != NULL)
        dma->interrupt_pending = false;
}

bool dol_audio_dma_interrupt_pending(const DolAudioDma* dma) {
    return dma != NULL && dma->interrupt_pending;
}

bool dol_audio_dma_poll(DolAudioDma* dma, u32* source_address) {
    if (dma == NULL || (dma->control & DOL_AUDIO_DMA_ENABLE) == 0)
        return false;
    if (++dma->work_counter < dma->work_units_per_chunk)
        return false;
    dma->work_counter = 0;

    if (source_address != NULL)
        *source_address = dma->current_source_address;
    if (dma->remaining_blocks != 0) {
        dma->remaining_blocks--;
        dma->current_source_address += 32u;
    }
    if (dma->remaining_blocks == 0) {
        dma->remaining_blocks = dma->control & DOL_AUDIO_DMA_BLOCK_MASK;
        dma->current_source_address = dma->source_address;
        dma->interrupt_pending = true;
    }
    return true;
}

static u32 latched_dma_source(const DolAudioDma* dma) {
    // Dolphin AUDIO_DMA_START_HI/LO form a 32-bit source address; the top 10
    // bits of the high half and the low 11 bits (aligned to 32 bytes) are
    // significant.
    const u32 hi = (u32)load_be16(dma->dsp_regs +
                                 DOL_AUDIO_DMA_DSP_DMA_START_HI_OFF)
                   << 16;
    const u32 lo = (u32)load_be16(dma->dsp_regs +
                                 DOL_AUDIO_DMA_DSP_DMA_START_LO_OFF);
    return (hi & 0x03FF0000u) | (lo & 0xFFE0u);
}

void dol_audio_dma_ai_mmio_read(DolAudioDma* dma, u32 offset, u8 size,
                                u64* value) {
    if (dma == NULL || value == NULL)
        return;
    *value = register_read(dma->ai_regs, offset, size);
}

void dol_audio_dma_ai_mmio_write(DolAudioDma* dma, u32 offset, u8 size,
                                 u64 value) {
    if (dma == NULL)
        return;
    register_write(dma->ai_regs, offset, size, value);
    if (offset < DOL_AUDIO_DMA_AI_CONTROL_OFF + 4u &&
        offset + size > DOL_AUDIO_DMA_AI_CONTROL_OFF)
        apply_ai_control(dma);
}

void dol_audio_dma_dsp_mmio_read(DolAudioDma* dma, u32 offset, u8 size,
                                 u64* value) {
    if (dma == NULL || value == NULL)
        return;
    if (offset == DOL_AUDIO_DMA_DSP_CONTROL_OFF && size == 2u) {
        u16 control = load_be16(dma->dsp_regs + offset);
        // The AID interrupt status is authoritative in the DMA engine; merge it
        // into the register image for guest-readable state.
        if (dma->interrupt_pending)
            control |= DOL_AUDIO_DMA_DSP_AID_INT_BIT;
        else
            control &= (u16)~DOL_AUDIO_DMA_DSP_AID_INT_BIT;
        *value = control;
        return;
    }
    if (offset == DOL_AUDIO_DMA_DSP_DMA_BLOCKS_LEFT_OFF && size == 2u) {
        *value = dol_audio_dma_blocks_left(dma);
        return;
    }
    *value = register_read(dma->dsp_regs, offset, size);
}

void dol_audio_dma_dsp_mmio_write(DolAudioDma* dma, u32 offset, u8 size,
                                  u64 value) {
    if (dma == NULL)
        return;
    if (offset == DOL_AUDIO_DMA_DSP_CONTROL_OFF && size == 2u) {
        u16 control = (u16)value;
        // Writing the AID status bit acknowledges the interrupt (write-1-clear).
        if (control & DOL_AUDIO_DMA_DSP_AID_INT_BIT)
            dol_audio_dma_ack_interrupt(dma);
        control &= (u16)~DOL_AUDIO_DMA_DSP_AID_INT_BIT;
        store_be16(dma->dsp_regs + offset, control);
        return;
    }
    register_write(dma->dsp_regs, offset, size, value);
    if ((offset == DOL_AUDIO_DMA_DSP_DMA_START_HI_OFF ||
         offset == DOL_AUDIO_DMA_DSP_DMA_START_LO_OFF) &&
        size == 2u)
        dol_audio_dma_set_source(dma, latched_dma_source(dma));
    if (offset == DOL_AUDIO_DMA_DSP_DMA_CONTROL_OFF && size == 2u)
        dol_audio_dma_write_control(dma, (u16)value);
}

bool dol_audio_dma_dsp_interrupt_pending(const DolAudioDma* dma) {
    if (dma == NULL || !dma->interrupt_pending)
        return false;
    const u16 control = load_be16(dma->dsp_regs +
                                  DOL_AUDIO_DMA_DSP_CONTROL_OFF);
    return (control & DOL_AUDIO_DMA_DSP_AID_MSK_BIT) != 0;
}
