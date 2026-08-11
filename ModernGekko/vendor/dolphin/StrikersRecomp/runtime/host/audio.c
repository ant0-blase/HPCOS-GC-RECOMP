#include "host/audio.h"
#include "host/hle_offsets.h"

#include "gxruntime/audio_dma.h"
#include "gxruntime/aram.h"
#include "gxruntime/platform.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DSP_BASE 0xCC005000u
#define DSP_SIZE 0x40u
#define AI_BASE  0xCC006C00u
#define AI_SIZE  0x20u

#define AI_CONTROL_OFF DOL_AUDIO_DMA_AI_CONTROL_OFF

#define AX_SAMPLES_PER_MS 32u
#define AX_FRAME_MS       5u
#define AX_FRAME_SAMPLES  (AX_SAMPLES_PER_MS * AX_FRAME_MS)
#define AX_CHANNELS       9u

enum {
    AX_MAIN_L,
    AX_MAIN_R,
    AX_MAIN_S,
    AX_AUXA_L,
    AX_AUXA_R,
    AX_AUXA_S,
    AX_AUXB_L,
    AX_AUXB_R,
    AX_AUXB_S,
};

static DolAudioDma g_audio_dma;
static bool g_waiting_for_command_list;
static bool g_log;
static u64 g_audio_frames;
static u64 g_aid_chunks;
static u32 g_active_voices;
static s32 g_mix[AX_CHANNELS][AX_FRAME_SAMPLES];

static u32 hilo(CPUState* cpu, u32 address) {
    return ((u32)mem_read16(cpu, address) << 16) | mem_read16(cpu, address + 2u);
}

static void write_s32(CPUState* cpu, u32 address, s32 value) {
    mem_write32(cpu, address, (u32)value);
}

static s32 read_s32(CPUState* cpu, u32 address) {
    return (s32)mem_read32(cpu, address);
}

static s16 clamp_s16(s64 value) {
    if (value > INT16_MAX)
        return INT16_MAX;
    if (value < INT16_MIN)
        return INT16_MIN;
    return (s16)value;
}

typedef struct {
    CPUState* cpu;
    u32 pb;
    u32 current;
    u32 end;
    u32 loop;
    u16 format;
    u16 loop_flag;
    u16 stream;
    u16 running;
    u16 pred_scale;
    s16 yn1;
    s16 yn2;
    s16 coef[16];
    u16 loop_pred_scale;
    s16 loop_yn1;
    s16 loop_yn2;
    u16 loop_counter;
} SampleReader;

static void sample_reader_load(SampleReader* reader, CPUState* cpu, u32 pb) {
    memset(reader, 0, sizeof *reader);
    reader->cpu = cpu;
    reader->pb = pb;
    reader->running = mem_read16(cpu, pb + 0x0Eu);
    reader->stream = mem_read16(cpu, pb + 0x10u);
    reader->loop_flag = mem_read16(cpu, pb + 0x6Eu);
    reader->format = mem_read16(cpu, pb + 0x70u);
    reader->loop = hilo(cpu, pb + 0x72u);
    reader->end = hilo(cpu, pb + 0x76u);
    reader->current = hilo(cpu, pb + 0x7Au);
    for (u32 i = 0; i < 16; i++)
        reader->coef[i] = (s16)mem_read16(cpu, pb + 0x7Eu + i * 2u);
    reader->pred_scale = mem_read16(cpu, pb + 0xA0u);
    reader->yn1 = (s16)mem_read16(cpu, pb + 0xA2u);
    reader->yn2 = (s16)mem_read16(cpu, pb + 0xA4u);
    reader->loop_pred_scale = mem_read16(cpu, pb + 0xB4u);
    reader->loop_yn1 = (s16)mem_read16(cpu, pb + 0xB6u);
    reader->loop_yn2 = (s16)mem_read16(cpu, pb + 0xB8u);
    reader->loop_counter = mem_read16(cpu, pb + 0xC2u);
}

static void sample_reader_store(const SampleReader* reader) {
    CPUState* cpu = reader->cpu;
    u32 pb = reader->pb;
    mem_write16(cpu, pb + 0x0Eu, reader->running);
    mem_write16(cpu, pb + 0x7Au, (u16)(reader->current >> 16));
    mem_write16(cpu, pb + 0x7Cu, (u16)reader->current);
    mem_write16(cpu, pb + 0xA0u, reader->pred_scale);
    mem_write16(cpu, pb + 0xA2u, (u16)reader->yn1);
    mem_write16(cpu, pb + 0xA4u, (u16)reader->yn2);
    mem_write16(cpu, pb + 0xC2u, reader->loop_counter);
}

static void sample_reader_finish_or_loop(SampleReader* reader) {
    if (reader->current <= reader->end)
        return;
    if (!reader->loop_flag) {
        reader->running = 0;
        return;
    }
    reader->current = reader->loop;
    reader->pred_scale = reader->loop_pred_scale;
    if (reader->stream == 1) {
        reader->loop_counter++;
    } else {
        reader->yn1 = reader->loop_yn1;
        reader->yn2 = reader->loop_yn2;
    }
}

static s16 sample_reader_next(SampleReader* reader) {
    if (reader->running != 1)
        return 0;

    sample_reader_finish_or_loop(reader);
    if (reader->running != 1)
        return 0;

    s16 sample = 0;
    switch (reader->format) {
    case 0: { // Nintendo DSP ADPCM; current/end/loop are nibble addresses.
        if ((reader->current & 0xFu) < 2u) {
            reader->pred_scale = (u16)aram_read(reader->current >> 1, 1);
            reader->current = (reader->current & ~0xFu) + 2u;
        }
        u8 packed = (u8)aram_read(reader->current >> 1, 1);
        s32 nibble = (reader->current & 1u) ? (packed & 0xFu) : (packed >> 4);
        if (nibble >= 8)
            nibble -= 16;
        u32 predictor = (reader->pred_scale >> 4) & 7u;
        u32 shift = reader->pred_scale & 0xFu;
        s64 value = (s64)nibble * ((s64)1 << shift) * 2048 +
                    (s64)reader->coef[predictor * 2u] * reader->yn1 +
                    (s64)reader->coef[predictor * 2u + 1u] * reader->yn2 +
                    1024;
        sample = clamp_s16(value >> 11);
        reader->yn2 = reader->yn1;
        reader->yn1 = sample;
        reader->current++;
        break;
    }
    case 0x0A: // Signed 16-bit PCM; addresses are sample indices.
        sample = (s16)aram_read(reader->current * 2u, 2);
        reader->current++;
        break;
    case 0x19: // Signed 8-bit PCM; addresses are byte offsets.
        sample = (s16)((s8)aram_read(reader->current, 1) << 8);
        reader->current++;
        break;
    default:
        reader->running = 0;
        break;
    }

    sample_reader_finish_or_loop(reader);
    return sample;
}

static void read_resampled_samples(CPUState* cpu, u32 pb, s16 output[AX_SAMPLES_PER_MS]) {
    SampleReader reader;
    sample_reader_load(&reader, cpu, pb);

    u16 src_type = mem_read16(cpu, pb + 0x08u);
    u32 ratio = hilo(cpu, pb + 0xA6u);
    u32 position = mem_read16(cpu, pb + 0xAAu);
    s16 history[4];
    for (u32 i = 0; i < 4; i++)
        history[i] = (s16)mem_read16(cpu, pb + 0xACu + i * 2u);

    if (src_type == 2) {
        for (u32 i = 0; i < AX_SAMPLES_PER_MS; i++)
            output[i] = sample_reader_next(&reader);
        for (u32 i = 0; i < 4; i++)
            history[i] = output[AX_SAMPLES_PER_MS - 4u + i];
    } else {
        // MusyX source type 0 requests the DSP's polyphase filter. The
        // coefficients live in DSP ROM, so the portable backend uses the
        // hardware's linear mode as a deterministic fallback.
        s16 ring[4];
        memcpy(ring, history, sizeof ring);
        u32 index = 4;
        for (u32 i = 0; i < AX_SAMPLES_PER_MS; i++) {
            position += ratio;
            while (position >= 0x10000u) {
                ring[index++ & 3u] = sample_reader_next(&reader);
                position -= 0x10000u;
            }

            u16 fraction = (u16)position;
            if (fraction) {
                s32 first = ring[index++ & 3u];
                s32 second = ring[index++ & 3u];
                output[i] = (s16)((first * (u16)-fraction +
                                   second * fraction) >> 16);
                index += 2;
            } else {
                output[i] = ring[index++ & 3u];
                index += 3;
            }
        }
        history[3] = ring[--index & 3u];
        history[2] = ring[--index & 3u];
        history[1] = ring[--index & 3u];
        history[0] = ring[--index & 3u];
    }

    mem_write16(cpu, pb + 0xAAu, (u16)position);
    for (u32 i = 0; i < 4; i++)
        mem_write16(cpu, pb + 0xACu + i * 2u, (u16)history[i]);
    sample_reader_store(&reader);
}

static void apply_updates(CPUState* cpu, u32 pb, u32 millisecond, u32* update_index) {
    u16 count = mem_read16(cpu, pb + 0x44u + millisecond * 2u);
    u32 updates = hilo(cpu, pb + 0x4Eu);
    for (u16 i = 0; i < count; i++, (*update_index)++) {
        u32 entry = updates + *update_index * 4u;
        u16 word_offset = mem_read16(cpu, entry);
        u16 value = mem_read16(cpu, entry + 2u);
        mem_write16(cpu, pb + (u32)word_offset * 2u, value);
    }
}

static void mix_channel(CPUState* cpu, u32 pb, const s16* input, u32 buffer,
                        u32 mix_offset, u32 dpop_offset, bool enabled, bool ramp,
                        u32 frame_offset) {
    u16 volume = mem_read16(cpu, pb + mix_offset);
    u16 delta = ramp ? mem_read16(cpu, pb + mix_offset + 2u) : 0;
    s16 last = 0;
    if (enabled) {
        for (u32 i = 0; i < AX_SAMPLES_PER_MS; i++) {
            s16 mixed = clamp_s16(((s64)input[i] * volume) >> 15);
            g_mix[buffer][frame_offset + i] += mixed;
            volume = (u16)(volume + delta);
            last = mixed;
        }
    }
    mem_write16(cpu, pb + mix_offset, volume);
    mem_write16(cpu, pb + dpop_offset, (u16)last);
}

static void process_voice_ms(CPUState* cpu, u32 pb, u32 frame_offset) {
    if (mem_read16(cpu, pb + 0x0Eu) != 1)
        return;

    s16 samples[AX_SAMPLES_PER_MS];
    read_resampled_samples(cpu, pb, samples);

    s16 envelope = (s16)mem_read16(cpu, pb + 0x64u);
    s16 envelope_delta = (s16)mem_read16(cpu, pb + 0x66u);
    for (u32 i = 0; i < AX_SAMPLES_PER_MS; i++) {
        samples[i] = clamp_s16(((s64)samples[i] * envelope) >> 15);
        envelope = (s16)(envelope + envelope_delta);
    }
    mem_write16(cpu, pb + 0x64u, (u16)envelope);

    if (mem_read16(cpu, pb + 0xBAu)) {
        s16 history = (s16)mem_read16(cpu, pb + 0xBCu);
        u16 a0 = mem_read16(cpu, pb + 0xBEu);
        s16 b0 = (s16)mem_read16(cpu, pb + 0xC0u);
        for (u32 i = 0; i < AX_SAMPLES_PER_MS; i++) {
            history = samples[i] =
                clamp_s16(((s64)a0 * samples[i] + (s64)b0 * history) >> 15);
        }
        mem_write16(cpu, pb + 0xBCu, (u16)history);
    }

    u16 control = mem_read16(cpu, pb + 0x0Cu);
    mix_channel(cpu, pb, samples, AX_MAIN_L, 0x12u, 0x52u,
                (control & 0x0001u) != 0, (control & 0x0008u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_MAIN_R, 0x16u, 0x58u,
                (control & 0x0002u) != 0, (control & 0x0008u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_MAIN_S, 0x2Eu, 0x5Eu,
                (control & 0x0004u) != 0, (control & 0x0008u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_AUXA_L, 0x1Au, 0x54u,
                (control & 0x0010u) != 0, (control & 0x0040u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_AUXA_R, 0x1Eu, 0x5Au,
                (control & 0x0020u) != 0, (control & 0x0040u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_AUXA_S, 0x32u, 0x60u,
                (control & 0x0080u) != 0, (control & 0x0100u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_AUXB_L, 0x22u, 0x56u,
                (control & 0x0200u) != 0, (control & 0x0800u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_AUXB_R, 0x26u, 0x5Cu,
                (control & 0x0400u) != 0, (control & 0x0800u) != 0, frame_offset);
    mix_channel(cpu, pb, samples, AX_AUXB_S, 0x2Au, 0x62u,
                (control & 0x1000u) != 0, (control & 0x2000u) != 0, frame_offset);
}

static void process_pb_list(CPUState* cpu, u32 first_pb) {
    u32 pb = first_pb;
    for (u32 voice = 0; pb && voice < 64; voice++) {
        if (mem_read16(cpu, pb + 0x0Eu) == 1)
            g_active_voices++;
        u32 update_index = 0;
        for (u32 ms = 0; ms < AX_FRAME_MS; ms++) {
            apply_updates(cpu, pb, ms, &update_index);
            process_voice_ms(cpu, pb, ms * AX_SAMPLES_PER_MS);
        }
        pb = hilo(cpu, pb);
    }
}

static void setup_processing(CPUState* cpu, u32 address) {
    memset(g_mix, 0, sizeof g_mix);
    for (u32 channel = 0; channel < AX_CHANNELS; channel++) {
        s32 value = (s32)mem_read32(cpu, address + channel * 6u);
        s16 delta = (s16)mem_read16(cpu, address + channel * 6u + 4u);
        if (!value)
            continue;
        for (u32 sample = 0; sample < AX_FRAME_SAMPLES; sample++) {
            g_mix[channel][sample] = value;
            value += delta;
        }
    }
}

static void download_and_mix(CPUState* cpu, u32 address,
                             u16 main_volume, u16 auxa_volume, u16 auxb_volume) {
    const u16 volumes[3] = {main_volume, auxa_volume, auxb_volume};
    const u32 channels[3][3] = {
        {AX_MAIN_L, AX_MAIN_R, AX_MAIN_S},
        {AX_AUXA_L, AX_AUXA_R, AX_AUXA_S},
        {AX_AUXB_L, AX_AUXB_R, AX_AUXB_S},
    };
    u32 cursor = address;
    for (u32 group = 0; group < 3; group++) {
        for (u32 component = 0; component < 3; component++) {
            s32* destination = g_mix[channels[group][component]];
            for (u32 i = 0; i < AX_FRAME_SAMPLES; i++, cursor += 4u)
                destination[i] += (s32)(((s64)read_s32(cpu, cursor) *
                                         volumes[group]) >> 15);
        }
    }
}

static void upload_three(CPUState* cpu, u32 address, u32 first_channel) {
    for (u32 channel = 0; channel < 3; channel++)
        for (u32 i = 0; i < AX_FRAME_SAMPLES; i++)
            write_s32(cpu, address + (channel * AX_FRAME_SAMPLES + i) * 4u,
                      g_mix[first_channel + channel][i]);
}

static void mix_aux(CPUState* cpu, u32 aux_channel, u32 write_address, u32 read_address) {
    if (write_address)
        upload_three(cpu, write_address, aux_channel);
    for (u32 channel = 0; channel < 3; channel++)
        for (u32 i = 0; i < AX_FRAME_SAMPLES; i++)
            g_mix[AX_MAIN_L + channel][i] +=
                read_s32(cpu, read_address + (channel * AX_FRAME_SAMPLES + i) * 4u);
}

static void output_samples(CPUState* cpu, u32 stereo_address, u32 surround_address) {
    u32 peak = 0;
    for (u32 i = 0; i < AX_FRAME_SAMPLES; i++) {
        write_s32(cpu, surround_address + i * 4u, g_mix[AX_MAIN_S][i]);
        s16 left = clamp_s16(g_mix[AX_MAIN_L][i]);
        s16 right = clamp_s16(g_mix[AX_MAIN_R][i]);
        // GameCube AI DMA is interleaved right/left. SDL receives conventional
        // left/right ordering.
        mem_write16(cpu, stereo_address + i * 4u, (u16)right);
        mem_write16(cpu, stereo_address + i * 4u + 2u, (u16)left);
        u32 left_magnitude = left == INT16_MIN ? 32768u : (u32)abs(left);
        u32 right_magnitude = right == INT16_MIN ? 32768u : (u32)abs(right);
        if (left_magnitude > peak)
            peak = left_magnitude;
        if (right_magnitude > peak)
            peak = right_magnitude;
    }
    g_audio_frames++;
    if (g_log && (g_audio_frames <= 10u || g_audio_frames % 100u == 0u))
        fprintf(stderr, "[audio] frame %llu: voices=%u peak=%u\n",
                (unsigned long long)g_audio_frames, g_active_voices, peak);
}

static void mix_auxb_lr(CPUState* cpu, u32 upload_address, u32 download_address) {
    for (u32 channel = 0; channel < 2; channel++)
        for (u32 i = 0; i < AX_FRAME_SAMPLES; i++)
            write_s32(cpu, upload_address + (channel * AX_FRAME_SAMPLES + i) * 4u,
                      g_mix[AX_AUXB_L + channel][i]);
    for (u32 channel = 0; channel < 2; channel++) {
        for (u32 i = 0; i < AX_FRAME_SAMPLES; i++) {
            s32 value = read_s32(
                cpu, download_address + (channel * AX_FRAME_SAMPLES + i) * 4u);
            g_mix[AX_AUXB_L + channel][i] = value;
            g_mix[AX_MAIN_L + channel][i] += value;
        }
    }
}

static void set_opposite_lr(CPUState* cpu, u32 address) {
    for (u32 i = 0; i < AX_FRAME_SAMPLES; i++) {
        s32 value = read_s32(cpu, address + i * 4u);
        g_mix[AX_MAIN_L][i] = -value;
        g_mix[AX_MAIN_R][i] = value;
        g_mix[AX_MAIN_S][i] = 0;
    }
}

static void run_compressor(CPUState* cpu, u16 threshold, u16 frames, u32 table) {
    (void)frames;
    bool triggered = false;
    for (u32 i = 0; i < AX_FRAME_SAMPLES; i++) {
        s32 left = g_mix[AX_MAIN_L][i];
        s32 right = g_mix[AX_MAIN_R][i];
        if (labs(left) > threshold || labs(right) > threshold) {
            triggered = true;
            break;
        }
    }
    if (!triggered)
        return;
    for (u32 i = 0; i < AX_FRAME_SAMPLES; i++) {
        u16 coefficient = mem_read16(cpu, table + i * 2u);
        g_mix[AX_MAIN_L][i] =
            (s32)(((s64)g_mix[AX_MAIN_L][i] * coefficient) >> 15);
        g_mix[AX_MAIN_R][i] =
            (s32)(((s64)g_mix[AX_MAIN_R][i] * coefficient) >> 15);
    }
}

static void process_command_list(CPUState* cpu, u32 address) {
    u32 cursor = address;
    u32 pb = 0;
    g_active_voices = 0;
    for (u32 command_count = 0; command_count < 4096; command_count++) {
        u16 command = mem_read16(cpu, cursor);
        cursor += 2u;
        switch (command) {
        case 0:
            setup_processing(cpu, hilo(cpu, cursor));
            cursor += 4u;
            break;
        case 1: {
            u32 source = hilo(cpu, cursor);
            u16 main_volume = mem_read16(cpu, cursor + 4u);
            u16 auxa_volume = mem_read16(cpu, cursor + 6u);
            u16 auxb_volume = mem_read16(cpu, cursor + 8u);
            cursor += 10u;
            download_and_mix(cpu, source, main_volume, auxa_volume, auxb_volume);
            break;
        }
        case 2:
            pb = hilo(cpu, cursor);
            cursor += 4u;
            break;
        case 3:
            process_pb_list(cpu, pb);
            break;
        case 4:
        case 5: {
            u32 upload = hilo(cpu, cursor);
            u32 download = hilo(cpu, cursor + 4u);
            cursor += 8u;
            mix_aux(cpu, command == 4 ? AX_AUXA_L : AX_AUXB_L, upload, download);
            break;
        }
        case 6:
            upload_three(cpu, hilo(cpu, cursor), AX_MAIN_L);
            cursor += 4u;
            break;
        case 7: {
            u32 source = hilo(cpu, cursor);
            cursor += 4u;
            for (u32 i = 0; i < AX_FRAME_SAMPLES; i++) {
                s32 value = read_s32(cpu, source + i * 4u);
                g_mix[AX_MAIN_L][i] = value;
                g_mix[AX_MAIN_R][i] = value;
                g_mix[AX_MAIN_S][i] = 0;
            }
            break;
        }
        case 8:
            cursor += 20u;
            break;
        case 9:
            mix_aux(cpu, AX_AUXB_L, 0, hilo(cpu, cursor));
            cursor += 4u;
            break;
        case 10:
        case 11:
        case 12:
            break;
        case 13:
            cursor = hilo(cpu, cursor);
            // The following size word describes this new chunk for hardware
            // DMA. Host memory is directly accessible, so no copy is needed.
            break;
        case 14: {
            u32 surround = hilo(cpu, cursor);
            u32 stereo = hilo(cpu, cursor + 4u);
            cursor += 8u;
            output_samples(cpu, stereo, surround);
            break;
        }
        case 15:
            return;
        case 16: {
            u32 upload = hilo(cpu, cursor);
            u32 download = hilo(cpu, cursor + 4u);
            cursor += 8u;
            mix_auxb_lr(cpu, upload, download);
            break;
        }
        case 17:
            set_opposite_lr(cpu, hilo(cpu, cursor));
            cursor += 4u;
            break;
        case 18: {
            u16 threshold = mem_read16(cpu, cursor);
            u16 frames = mem_read16(cpu, cursor + 2u);
            u32 table = hilo(cpu, cursor + 4u);
            cursor += 8u;
            run_compressor(cpu, threshold, frames, table);
            break;
        }
        default:
            fprintf(stderr, "[audio] unknown AX command 0x%04X at 0x%08X\n",
                    command, cursor - 2u);
            return;
        }
    }
    fprintf(stderr, "[audio] AX command list exceeded safety limit\n");
}

void audio_init(void) {
    memset(g_mix, 0, sizeof g_mix);
    dol_audio_dma_init(&g_audio_dma);
    // The device debounces AI control writes; mirror the apploader AID rate
    // explicitly once at boot so the platform HAL starts at 32 kHz.
    dol_platform_audio_set_sample_rate(DOL_AUDIO_DMA_32KHZ);
    g_waiting_for_command_list = false;
    g_audio_frames = 0;
    g_aid_chunks = 0;
    g_active_voices = 0;
    g_log = getenv("STRIKERS_AUDIO_LOG") != NULL;
}

void audio_shutdown(void) {
    dol_audio_dma_write_control(&g_audio_dma, 0);
    dol_audio_dma_ack_interrupt(&g_audio_dma);
}

void audio_set_vi_clock(u64 work_units_per_frame, u32 refresh_hz) {
    dol_audio_dma_set_vi_clock(&g_audio_dma, work_units_per_frame, refresh_hz);
}

bool audio_mmio_contains(u32 address) {
    return (address >= DSP_BASE && address < DSP_BASE + DSP_SIZE) ||
           (address >= AI_BASE && address < AI_BASE + AI_SIZE);
}

u64 audio_mmio_read(u32 address, u8 size) {
    u64 value = 0;
    if (address >= DSP_BASE && address < DSP_BASE + DSP_SIZE)
        dol_audio_dma_dsp_mmio_read(&g_audio_dma, address - DSP_BASE, size,
                                    &value);
    else
        dol_audio_dma_ai_mmio_read(&g_audio_dma, address - AI_BASE, size,
                                   &value);
    return value;
}

void audio_mmio_write(u32 address, u8 size, u64 value) {
    if (address >= DSP_BASE && address < DSP_BASE + DSP_SIZE) {
        dol_audio_dma_dsp_mmio_write(&g_audio_dma, address - DSP_BASE, size,
                                     value);
        return;
    }
    const u32 offset = address - AI_BASE;
    dol_audio_dma_ai_mmio_write(&g_audio_dma, offset, size, value);
    if (g_log && offset < AI_CONTROL_OFF + 4u &&
        offset + size > AI_CONTROL_OFF) {
        u64 control = 0;
        dol_audio_dma_ai_mmio_read(&g_audio_dma, AI_CONTROL_OFF, 4, &control);
        fprintf(stderr, "[audio] AI control=0x%08llX ais=%u aid=%u\n",
                (unsigned long long)control,
                (control & 0x00000002u) != 0u ? 48000u : 32000u,
                (control & 0x00000040u) != 0u ? 32000u : 48000u);
    }
}

void audio_poll(CPUState* cpu) {
    u32 physical = 0;
    if (!dol_audio_dma_poll(&g_audio_dma, &physical))
        return;

    s16 output[8u * 2u];
    u32 peak = 0;
    const u32 source = GC_RAM_BASE | physical;
    for (u32 i = 0; i < 8u; i++) {
        const s16 right = (s16)mem_read16(cpu, source + i * 4u);
        const s16 left = (s16)mem_read16(cpu, source + i * 4u + 2u);
        output[i * 2u] = left;
        output[i * 2u + 1u] = right;
        const u32 left_magnitude =
            left == INT16_MIN ? 32768u : (u32)abs(left);
        const u32 right_magnitude =
            right == INT16_MIN ? 32768u : (u32)abs(right);
        if (left_magnitude > peak)
            peak = left_magnitude;
        if (right_magnitude > peak)
            peak = right_magnitude;
    }
    g_aid_chunks++;
    if (g_log && (g_aid_chunks <= 10u || g_aid_chunks % 400u == 0u))
        fprintf(stderr, "[audio] AID chunk %llu: source=%08x peak=%u\n",
                (unsigned long long)g_aid_chunks, physical, peak);
    dol_platform_audio_push(output, 8u);
}

bool audio_interrupt_pending(void) {
    return dol_audio_dma_dsp_interrupt_pending(&g_audio_dma);
}

void audio_dsp_mail(CPUState* cpu, u32 mail) {
    if ((mail & 0xFFFF0000u) == 0xBABE0000u) {
        g_waiting_for_command_list = true;
        return;
    }
    if (!g_waiting_for_command_list)
        return;

    g_waiting_for_command_list = false;
    process_command_list(cpu, mail);
    mem_write32(cpu, STRIKERS_MUSYX_DSP_DONE_ADDR, 1);
}

void audio_skip_dsp_init(CPUState* cpu) {
    mem_write32(cpu, STRIKERS_MUSYX_DSP_DONE_ADDR, 1);
}
