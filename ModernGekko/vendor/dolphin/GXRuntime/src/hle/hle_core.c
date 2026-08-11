// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/hle.h"
#include "gxruntime/hle_abi.h"
#include "gxruntime/guest_memory.h"
#include "gxruntime/aram.h"
#include "gxruntime/memory_card.h"
#include "gxruntime/platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Logging flags and memory card pointer
bool g_hle_log = false;
bool g_card_log = false;
bool g_audio_log = false;
bool g_graphics_log = false;
DolMemoryCard* g_memory_card = NULL;

static DolHleConfig g_hle_config;

// ---------------------------------------------------------------------------
// Callback Context structures and state
// ---------------------------------------------------------------------------
#define HLE_CALLBACK_QUEUE_CAPACITY 32u

typedef struct {
    u32 address;
    s32 channel;
    s32 result;
} HlePendingCallback;

typedef struct {
    u64 gpr[32];
    f64 fpr[32];
    f64 ps1[32];
    u32 pc;
    u32 lr;
    u32 ctr;
    u32 cr;
    u32 xer;
    u32 fpscr;
    u32 msr;
    u32 srr0;
    u32 srr1;
    u32 dar;
    u32 dsisr;
    u32 ear;
    u32 hid2;
    u32 sr[16];
    u32 gqr[8];
    u32 exception;
    u32 program_exception;
    u32 reserve_addr;
    bool reserve_valid;
} HleSavedContext;

static HlePendingCallback g_callback_queue[HLE_CALLBACK_QUEUE_CAPACITY];
static u32 g_callback_read;
static u32 g_callback_count;
static bool g_callback_active;
static HleSavedContext g_callback_context;

static void save_callback_context(HleSavedContext* saved, const CPUState* cpu) {
    memcpy(saved->gpr, cpu->gpr, sizeof saved->gpr);
    memcpy(saved->fpr, cpu->fpr, sizeof saved->fpr);
    memcpy(saved->ps1, cpu->ps1, sizeof saved->ps1);
    saved->pc = cpu->pc;
    saved->lr = cpu->lr;
    saved->ctr = cpu->ctr;
    saved->cr = cpu->cr;
    saved->xer = cpu->xer;
    saved->fpscr = cpu->fpscr;
    saved->msr = cpu->msr;
    saved->srr0 = cpu->srr0;
    saved->srr1 = cpu->srr1;
    saved->dar = cpu->dar;
    saved->dsisr = cpu->dsisr;
    saved->ear = cpu->ear;
    saved->hid2 = cpu->hid2;
    memcpy(saved->sr, cpu->sr, sizeof saved->sr);
    memcpy(saved->gqr, cpu->gqr, sizeof saved->gqr);
    saved->exception = cpu->exception;
    saved->program_exception = cpu->program_exception;
    saved->reserve_addr = cpu->reserve_addr;
    saved->reserve_valid = cpu->reserve_valid;
}

static void restore_callback_context(CPUState* cpu, const HleSavedContext* saved) {
    memcpy(cpu->gpr, saved->gpr, sizeof saved->gpr);
    memcpy(cpu->fpr, saved->fpr, sizeof saved->fpr);
    memcpy(cpu->ps1, saved->ps1, sizeof saved->ps1);
    cpu->pc = saved->pc;
    cpu->lr = saved->lr;
    cpu->ctr = saved->ctr;
    cpu->cr = saved->cr;
    cpu->xer = saved->xer;
    cpu->fpscr = saved->fpscr;
    cpu->msr = saved->msr;
    cpu->srr0 = saved->srr0;
    cpu->srr1 = saved->srr1;
    cpu->dar = saved->dar;
    cpu->dsisr = saved->dsisr;
    cpu->ear = saved->ear;
    cpu->hid2 = saved->hid2;
    memcpy(cpu->sr, saved->sr, sizeof saved->sr);
    memcpy(cpu->gqr, saved->gqr, sizeof saved->gqr);
    cpu->exception = saved->exception;
    cpu->program_exception = saved->program_exception;
    cpu->reserve_addr = saved->reserve_addr;
    cpu->reserve_valid = saved->reserve_valid;
}

bool queue_guest_callback(u32 address, s32 channel, s32 result) {
    if (address == 0)
        return true;
    if (g_callback_count == HLE_CALLBACK_QUEUE_CAPACITY) {
        fprintf(stderr, "[card] completion callback queue overflow\n");
        return false;
    }
    u32 index = (g_callback_read + g_callback_count) % HLE_CALLBACK_QUEUE_CAPACITY;
    g_callback_queue[index].address = address;
    g_callback_queue[index].channel = channel;
    g_callback_queue[index].result = result;
    g_callback_count++;
    if (g_card_log)
        fprintf(stderr, "[card] queued callback=0x%08X channel=%d result=%d depth=%u\n",
                address, channel, result, g_callback_count);
    return true;
}

bool dol_hle_queue_guest_callback(u32 address, s32 channel, s32 result) {
    return queue_guest_callback(address, channel, result);
}

bool dol_hle_poll_callback(CPUState* cpu) {
    if (cpu == NULL || g_callback_active || g_callback_count == 0)
        return false;

    HlePendingCallback pending = g_callback_queue[g_callback_read];
    g_callback_read = (g_callback_read + 1u) % HLE_CALLBACK_QUEUE_CAPACITY;
    g_callback_count--;

    save_callback_context(&g_callback_context, cpu);
    g_callback_active = true;
    cpu->gpr[3] = (u32)pending.channel;
    cpu->gpr[4] = (u32)pending.result;
    cpu->pc = pending.address;
    cpu->lr = HLE_CALLBACK_RETURN;
    cpu->exception = 0;
    cpu->program_exception = 0;
    if (g_card_log)
        fprintf(stderr, "[card] dispatch callback=0x%08X channel=%d result=%d\n",
                pending.address, pending.channel, pending.result);
    return true;
}

bool dol_hle_handle_callback_return(CPUState* cpu, u32 address) {
    if (address == HLE_CALLBACK_RETURN && g_callback_active) {
        restore_callback_context(cpu, &g_callback_context);
        g_callback_active = false;
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------
// Initialization and teardown
// ---------------------------------------------------------------------------

void dol_hle_init(const DolHleConfig* config) {
    if (config != NULL) {
        g_hle_config = *config;
    }
    g_hle_log = getenv("STRIKERS_HLE_LOG") != NULL;
    g_card_log = getenv("STRIKERS_CARD_LOG") != NULL;
    g_audio_log = getenv("STRIKERS_AUDIO_LOG") != NULL;
    g_graphics_log = getenv("STRIKERS_GRAPHICS_LOG") != NULL;

    g_callback_read = 0;
    g_callback_count = 0;
    g_callback_active = false;
    memset(&g_callback_context, 0, sizeof g_callback_context);
}

bool dol_hle_card_open(const char* path) {
    dol_hle_card_close();
    DolMemoryCardConfig config;
    memset(&config, 0, sizeof config);
    config.path = path;
    config.size_mbits = 4;
    config.encoding = 0;
    memcpy(config.game_code, g_hle_config.game_code, 4);
    memcpy(config.company, g_hle_config.company, 2);
    g_memory_card = dol_card_open(&config);
    if (g_memory_card == NULL)
        return false;

    u16 size_mbits = 0;
    u32 sector_size = 0;
    if (dol_card_probe(g_memory_card, &size_mbits, &sector_size) != DOL_CARD_RESULT_READY) {
        dol_hle_card_close();
        return false;
    }
    fprintf(stderr, "[card] slot A: %s (%u Mbit, %u-byte sectors, serial %016llX)\n",
            path != NULL && path[0] != '\0' ? path : "(memory)",
            size_mbits, sector_size,
            (unsigned long long)dol_card_serial(g_memory_card));
    return true;
}

void dol_hle_card_close(void) {
    if (g_memory_card != NULL) {
        dol_card_close(g_memory_card);
        g_memory_card = NULL;
    }
}

// ---------------------------------------------------------------------------
// Standard wrappers implementations
// ---------------------------------------------------------------------------

void dol_hle_noop(CPUState* cpu) {
    (void)cpu;
}

void dol_hle_return_zero(CPUState* cpu) {
    hle_set_u32(cpu, 0);
}

void dol_hle_return_true(CPUState* cpu) {
    hle_set_u32(cpu, 1);
}

static u32 lc_transaction_count(u32 bytes) {
    const u32 blocks = (bytes + 31u) / 32u;
    return (blocks + 127u) / 128u;
}

void dol_hle_LCStoreBlocks(CPUState* cpu) {
    const u32 dest = hle_arg_u32(cpu, 0);
    const u32 src = hle_arg_u32(cpu, 1);
    const u32 blocks = hle_arg_u32(cpu, 2) ? hle_arg_u32(cpu, 2) : 128u;
    dol_guest_memory_copy(NULL, cpu, dest, src, blocks * 32u);
}

void dol_hle_LCStoreData(CPUState* cpu) {
    const u32 dest = hle_arg_u32(cpu, 0);
    const u32 src = hle_arg_u32(cpu, 1);
    const u32 bytes = hle_arg_u32(cpu, 2);
    dol_guest_memory_copy(NULL, cpu, dest, src, bytes);
    hle_set_u32(cpu, lc_transaction_count(bytes));
}

void dol_hle_LCQueueWait(CPUState* cpu) {
    (void)cpu;
}

void dol_hle_OSGetResetButtonState(CPUState* cpu) {
    hle_set_u32(cpu, 0u);
}

void dol_hle_salInitDsp(CPUState* cpu) {
    if (g_hle_config.musyx_dsp_done_addr != 0) {
        mem_write32(cpu, g_hle_config.musyx_dsp_done_addr, 1);
    }
    hle_set_u32(cpu, 1);
}

void dol_hle_DSPCheckMailToDSP(CPUState* cpu) {
    hle_set_u32(cpu, 0);
}

void dol_hle_ARInit(CPUState* cpu) {
    (void)cpu;
}

void dol_hle_ARGetBaseAddress(CPUState* cpu) {
    hle_set_u32(cpu, ARAM_BASE);
}

void dol_hle_ARGetSize(CPUState* cpu) {
    hle_set_u32(cpu, ARAM_SIZE);
}

void dol_hle_ARGetDMAStatus(CPUState* cpu) {
    hle_set_u32(cpu, 0);
}

void dol_hle_ARStartDMA(CPUState* cpu) {
    u32 type = hle_arg_u32(cpu, 0);
    u32 mainmem = hle_arg_u32(cpu, 1);
    u32 aram = hle_arg_u32(cpu, 2);
    u32 length = hle_arg_u32(cpu, 3);
    if (type == 0)
        aram_dma_to_aram(cpu->ram, mainmem, aram, length);
    else
        aram_dma_to_ram(cpu->ram, mainmem, aram, length);
}

void dol_hle_aramUploadData(CPUState* cpu) {
    u32 mainmem = hle_arg_u32(cpu, 0);
    u32 aram = hle_arg_u32(cpu, 1);
    u32 length = hle_arg_u32(cpu, 2);
    u32 callback = hle_arg_u32(cpu, 4);
    u32 user = hle_arg_u32(cpu, 5);
    aram_dma_to_aram(cpu->ram, mainmem, aram, length);
    if (callback) {
        cpu->gpr[3] = user;
        cpu->pc = callback;
        // The game-specific host dispatch loop checks cpu->pc to support tail calls.
    }
}

void dol_hle_ARQPostRequest(CPUState* cpu) {
    u32 request = hle_arg_u32(cpu, 0);
    u32 type = hle_arg_u32(cpu, 2);
    u32 source = hle_arg_u32(cpu, 4);
    u32 destination = hle_arg_u32(cpu, 5);
    u32 length = hle_arg_u32(cpu, 6);
    u32 callback = hle_arg_u32(cpu, 7);
    if (type == 0)
        aram_dma_to_aram(cpu->ram, source, destination, length);
    else
        aram_dma_to_ram(cpu->ram, destination, source, length);
    if (callback) {
        cpu->gpr[3] = request;
        cpu->pc = callback;
    }
}

void dol_hle_OSReport(CPUState* cpu) {
    char fmt[1024];
    hle_read_cstr(cpu, cpu->gpr[3], fmt, sizeof fmt);

    char out[2048];
    size_t oi = 0;
    unsigned iarg = 1;  // next integer vararg -> r4
    unsigned farg = 1;  // next float vararg   -> f2 (f1 unused for varargs)

    for (size_t i = 0; fmt[i] && oi + 1 < sizeof out;) {
        if (fmt[i] != '%') {
            out[oi++] = fmt[i++];
            continue;
        }
        char spec[32];
        size_t si = 0;
        spec[si++] = fmt[i++];
        while (fmt[i] && si + 2 < sizeof spec && strchr("-+ #0123456789.", fmt[i]))
            spec[si++] = fmt[i++];
        while (fmt[i] && strchr("lhLzjt", fmt[i]))
            i++;  // skip length modifier
        char conv = fmt[i] ? fmt[i++] : '\0';
        spec[si++] = conv;
        spec[si] = '\0';

        char tmp[576];
        tmp[0] = '\0';
        switch (conv) {
        case '%':
            tmp[0] = '%';
            tmp[1] = '\0';
            break;
        case 'd': case 'i':
            snprintf(tmp, sizeof tmp, spec, (int)hle_arg_u32(cpu, iarg++));
            break;
        case 'u': case 'x': case 'X': case 'o': case 'c':
            snprintf(tmp, sizeof tmp, spec, (unsigned)hle_arg_u32(cpu, iarg++));
            break;
        case 'p':
            snprintf(tmp, sizeof tmp, "0x%08X", hle_arg_u32(cpu, iarg++));
            break;
        case 's': {
            char s[512];
            hle_read_cstr(cpu, hle_arg_u32(cpu, iarg++), s, sizeof s);
            snprintf(tmp, sizeof tmp, spec, s);
            break;
        }
        case 'f': case 'F': case 'e': case 'E': case 'g': case 'G':
            snprintf(tmp, sizeof tmp, spec, hle_arg_f64(cpu, farg++));
            break;
        default:
            snprintf(tmp, sizeof tmp, "%s", spec);
            break;
        }
        size_t tl = strlen(tmp);
        if (oi + tl < sizeof out) {
            memcpy(out + oi, tmp, tl);
            oi += tl;
        } else {
            break;
        }
    }
    out[oi] = '\0';
    fprintf(stderr, "%s", out);
}

void dol_hle_PSMTXConcat(CPUState* cpu) {
    const u32 a_address = hle_arg_u32(cpu, 0);
    const u32 b_address = hle_arg_u32(cpu, 1);
    const u32 out_address = hle_arg_u32(cpu, 2);
    f32 a[12], b[12], out[12];

    for (u32 i = 0; i < 12; i++) {
        a[i] = guest_read_f32(cpu, a_address + i * 4u);
        b[i] = guest_read_f32(cpu, b_address + i * 4u);
    }
    for (u32 row = 0; row < 3; row++) {
        for (u32 col = 0; col < 3; col++) {
            out[row * 4u + col] =
                (f32)((f32)(a[row * 4u] * b[col]) +
                      (f32)(a[row * 4u + 1u] * b[4u + col]) +
                      (f32)(a[row * 4u + 2u] * b[8u + col]));
        }
        out[row * 4u + 3u] =
            (f32)(a[row * 4u + 3u] +
                  (f32)(a[row * 4u] * b[3u]) +
                  (f32)(a[row * 4u + 1u] * b[7u]) +
                  (f32)(a[row * 4u + 2u] * b[11u]));
    }
    for (u32 i = 0; i < 12; i++)
        guest_write_f32(cpu, out_address + i * 4u, out[i]);
}

// ---------------------------------------------------------------------------
// GX Graphics HLE Emulation
// ---------------------------------------------------------------------------

#define HLE_DISPLAY_LIST_RETURN 0x7FFF0010u
#define HLE_GX_BEGIN_RETURN     0x7FFF0020u
#define GX_DATA_SDA_OFFSET      (-20664)
#define GX_DIRTY_STATE_OFFSET   1452u
#define GX_MAX_TEXTURES 8u
#define GX_MAX_TLUTS    20u

typedef struct {
    bool active;
    u8 stage;
    u32 caller;
    u32 address;
    u32 size;
} HleDisplayListCall;

static HleDisplayListCall g_display_list_call;

typedef struct {
    bool active;
    u8 stage;
    u8 primitive;
    u8 vtxfmt;
    u16 vertex_count;
    u32 caller;
} HleGxBegin;

static HleGxBegin g_gx_begin;

typedef struct {
    bool valid;
    u32 object;
    u32 guest_data;
    u32 width;
    u32 height;
    u32 format;
    u32 tlut;
    u32 version;
    u32 emitted_version;
    u32 data_bytes;
    u32 data_hash;
    u8 flags;
} GxTextureBinding;

typedef struct {
    bool valid;
    u32 object;
    u32 guest_data;
    u32 format;
    u32 version;
    u32 emitted_version;
    u32 data_bytes;
    u32 data_hash;
    u16 entries;
} GxTlutBinding;

static GxTextureBinding g_textures[GX_MAX_TEXTURES];
static GxTlutBinding g_tluts[GX_MAX_TLUTS];
static u32 g_array_stride[32];
static u32 g_max_array_verts = 0u;
static unsigned g_gx_begin_count;
static unsigned g_gx_array_count;
static u64 g_frame_array_bytes;
static unsigned g_frame_array_calls;
static u64 g_frame_array_bytes_peak;
static bool g_array_budget_warned;
static unsigned g_movie_texture_load_count;
static unsigned g_movie_texobj_log_count;
static bool g_hle_tail_call = false;

enum { AURORA_STORAGE_BUDGET = 8u * 1024u * 1024u };
enum { ARRAY_UPLOAD_WARN_BYTES = (AURORA_STORAGE_BUDGET * 3u) / 4u };

static void* graphics_guest_pointer(CPUState* cpu, u32 address, u32* available) {
    return dol_guest_memory_pointer(NULL, cpu, address, available);
}

static u32 gx_texture_base_bytes(u32 width, u32 height, u32 format) {
    u32 shift_x = 2;
    u32 shift_y = 2;
    switch (format) {
    case 0x00u: // GX_TF_I4
    case 0x08u: // GX_TF_C4
    case 0x0Eu: // GX_TF_CMPR
    case 0x20u: // GX_CTF_R4
    case 0x30u: // GX_CTF_Z4
        shift_x = 3;
        shift_y = 3;
        break;
    case 0x01u: // GX_TF_I8
    case 0x02u: // GX_TF_IA4
    case 0x09u: // GX_TF_C8
    case 0x11u: // GX_TF_Z8
    case 0x22u: // GX_CTF_RA4
    case 0x27u: // GX_CTF_A8
    case 0x28u: // GX_CTF_R8
    case 0x29u: // GX_CTF_G8
    case 0x2Au: // GX_CTF_B8
    case 0x39u: // GX_CTF_Z8M
    case 0x3Au: // GX_CTF_Z8L
        shift_x = 3;
        shift_y = 2;
        break;
    default:
        shift_x = 2;
        shift_y = 2;
        break;
    }

    const u32 tile_x = (width + (1u << shift_x) - 1u) >> shift_x;
    const u32 tile_y = (height + (1u << shift_y) - 1u) >> shift_y;
    const u32 block_bits = (format == 0x06u || format == 0x16u) ? 64u : 32u;
    return block_bits * tile_x * tile_y;
}

static u32 guest_hash_bytes(const void* data, u32 bytes) {
    const u8* p = (const u8*)data;
    u32 hash = 2166136261u;
    for (u32 i = 0; i < bytes; i++)
        hash = (hash ^ p[i]) * 16777619u;
    return hash ? hash : 1u;
}

static u32 guest_hash(CPUState* cpu, u32 address, u32 bytes, u32* hashed_bytes) {
    u32 available = 0;
    const void* data = graphics_guest_pointer(cpu, address, &available);
    if (data == NULL || bytes == 0 || available == 0) {
        if (hashed_bytes != NULL)
            *hashed_bytes = 0;
        return 0;
    }
    if (bytes > available)
        bytes = available;
    if (hashed_bytes != NULL)
        *hashed_bytes = bytes;
    return guest_hash_bytes(data, bytes);
}

static u32 gx_hash_token_mix(u32 hash, u32 value) {
    for (u32 i = 0; i < 4u; i++) {
        hash = (hash ^ (u8)(value >> (i * 8u))) * 16777619u;
    }
    return hash ? hash : 1u;
}

static u32 gx_texture_resource_version(u32 width, u32 height, u32 format,
                                       u32 tlut, u8 flags,
                                       u32 data_bytes, u32 data_hash) {
    u32 hash = 2166136261u;
    hash = gx_hash_token_mix(hash, 0x54455831u);
    hash = gx_hash_token_mix(hash, width);
    hash = gx_hash_token_mix(hash, height);
    hash = gx_hash_token_mix(hash, format);
    hash = gx_hash_token_mix(hash, tlut);
    hash = gx_hash_token_mix(hash, flags);
    hash = gx_hash_token_mix(hash, data_bytes);
    return gx_hash_token_mix(hash, data_hash);
}

static u32 gx_tlut_resource_version(u32 format, u16 entries, u32 data_bytes,
                                    u32 data_hash) {
    u32 hash = 2166136261u;
    hash = gx_hash_token_mix(hash, 0x544C5431u);
    hash = gx_hash_token_mix(hash, format);
    hash = gx_hash_token_mix(hash, entries);
    hash = gx_hash_token_mix(hash, data_bytes);
    return gx_hash_token_mix(hash, data_hash);
}

static bool thp_movie_plane_generation(CPUState* cpu, u32 guest_data,
                                       u32 width, u32 height, u32 format,
                                       u32* data_bytes, u32* data_hash,
                                       u32* cache_object) {
    if (format != 1u || g_hle_config.thp_simple_control_addr == 0)
        return false;

    const u32 base = g_hle_config.thp_simple_control_addr;
    const u32 y = mem_read32(cpu, base + 0x15Cu);
    const u32 u = mem_read32(cpu, base + 0x160u);
    const u32 v = mem_read32(cpu, base + 0x164u);
    bool matches_plane = false;
    if (guest_data == y && width == 512u && height == 416u)
        matches_plane = true;
    else if ((guest_data == u || guest_data == v) &&
             width == 256u && height == 208u)
        matches_plane = true;
    if (!matches_plane)
        return false;

    const s32 tex_frame = (s32)mem_read32(cpu, base + 0x168u);
    if (tex_frame < 0)
        return false;

    const u32 bytes = gx_texture_base_bytes(width, height, format);
    u32 hash = 2166136261u;
    hash = gx_hash_token_mix(hash, 0x54485031u);
    hash = gx_hash_token_mix(hash, guest_data);
    hash = gx_hash_token_mix(hash, (u32)tex_frame);
    hash = gx_hash_token_mix(hash, width);
    hash = gx_hash_token_mix(hash, height);
    hash = gx_hash_token_mix(hash, format);
    if (data_bytes != NULL)
        *data_bytes = bytes;
    if (data_hash != NULL)
        *data_hash = hash;
    if (cache_object != NULL)
        *cache_object = guest_data;
    return true;
}

static void emit_gx_resource_metadata(CPUState* cpu) {
    for (u32 slot = 0; slot < GX_MAX_TLUTS; slot++) {
        GxTlutBinding* binding = &g_tluts[slot];
        if (!binding->valid)
            continue;
        if (binding->emitted_version == binding->version)
            continue;
        void* data = graphics_guest_pointer(cpu, binding->guest_data, NULL);
        dol_platform_load_tlut_guest((u8)slot, binding->guest_data, data,
                                     binding->format, binding->entries,
                                     binding->object, binding->version);
        binding->emitted_version = binding->version;
    }

    for (u32 slot = 0; slot < GX_MAX_TEXTURES; slot++) {
        GxTextureBinding* binding = &g_textures[slot];
        if (!binding->valid)
            continue;
        if (binding->emitted_version == binding->version)
            continue;
        void* data = graphics_guest_pointer(cpu, binding->guest_data, NULL);
        dol_platform_load_texture_guest(
            (u8)slot, binding->guest_data, data, binding->width,
            binding->height, binding->format, binding->tlut,
            (binding->flags & 1u) != 0, binding->object, binding->version);
        binding->emitted_version = binding->version;
    }
}

void dol_hle_GXLoadTexObj(CPUState* cpu) {
    u32 obj = hle_arg_u32(cpu, 0);
    u32 slot = hle_arg_u32(cpu, 1);
    if (slot >= GX_MAX_TEXTURES)
        return;
    u32 image0 = mem_read32(cpu, obj + 8u);
    u32 image3 = mem_read32(cpu, obj + 12u);
    u32 guest_data = GC_RAM_BASE | ((image3 & 0x001FFFFFu) << 5);
    u32 width = (image0 & 0x3FFu) + 1u;
    u32 height = ((image0 >> 10) & 0x3FFu) + 1u;
    u32 format = mem_read32(cpu, obj + 20u);
    u32 tlut = mem_read32(cpu, obj + 24u);
    u8 flags = mem_read8(cpu, obj + 31u);
    u32 data_bytes = gx_texture_base_bytes(width, height, format);
    u32 data_hash = 0;
    u32 cache_object = obj;
    const bool movie_generation =
        thp_movie_plane_generation(cpu, guest_data, width, height, format,
                                   &data_bytes, &data_hash, &cache_object);
    if (!movie_generation)
        data_hash = guest_hash(cpu, guest_data, data_bytes, &data_bytes);
    const u32 version =
        gx_texture_resource_version(width, height, format, tlut, flags,
                                    data_bytes, data_hash);
    if (!movie_generation)
        cache_object = version;

    GxTextureBinding* binding = &g_textures[slot];
    binding->valid = true;
    binding->object = cache_object;
    binding->guest_data = guest_data;
    binding->width = width;
    binding->height = height;
    binding->format = format;
    binding->tlut = tlut;
    binding->flags = flags;
    binding->data_bytes = data_bytes;
    binding->data_hash = data_hash;
    binding->version = version;
    binding->emitted_version = 0;
}

void dol_hle_GXLoadTlut(CPUState* cpu) {
    u32 obj = hle_arg_u32(cpu, 0);
    u32 slot = hle_arg_u32(cpu, 1);
    if (slot >= GX_MAX_TLUTS)
        return;
    u32 load_tlut0 = mem_read32(cpu, obj + 4u);
    u32 guest_data = GC_RAM_BASE | ((load_tlut0 & 0x001FFFFFu) << 5);
    u32 format = (mem_read32(cpu, obj) >> 10) & 3u;
    u16 entries = mem_read16(cpu, obj + 8u);
    u32 data_bytes = (u32)entries * 2u;
    u32 data_hash = guest_hash(cpu, guest_data, data_bytes, &data_bytes);
    const u32 version =
        gx_tlut_resource_version(format, entries, data_bytes, data_hash);
    GxTlutBinding* binding = &g_tluts[slot];
    binding->valid = true;
    binding->object = version;
    binding->guest_data = guest_data;
    binding->format = format;
    binding->entries = entries;
    binding->data_bytes = data_bytes;
    binding->data_hash = data_hash;
    binding->version = version;
    binding->emitted_version = 0;
}

void dol_hle_GXSetArray(CPUState* cpu) {
    u32 attr = hle_arg_u32(cpu, 0);
    u32 address = hle_arg_u32(cpu, 1);
    u8 stride = (u8)hle_arg_u32(cpu, 2);
    u32 available = 0;
    void* data = graphics_guest_pointer(cpu, address, &available);
    u32 size = available;
    if (g_max_array_verts != 0u) {
        u64 indexed_span = (u64)(stride ? stride : 1u) * g_max_array_verts;
        if (indexed_span < (u64)size)
            size = (u32)indexed_span;
    }
    g_frame_array_bytes += size;
    g_frame_array_calls++;
    if (g_max_array_verts != 0u &&
        g_frame_array_bytes > ARRAY_UPLOAD_WARN_BYTES && !g_array_budget_warned) {
        g_array_budget_warned = true;
        fprintf(stderr,
                "[gfx] WARNING: indexed-array uploads this frame reached %llu bytes, "
                "nearing Aurora's %u-byte per-frame storage limit.\n",
                (unsigned long long)g_frame_array_bytes,
                (unsigned)AURORA_STORAGE_BUDGET);
    }
    dol_platform_set_array_guest(attr, address, data, size, stride);
}

static void finish_GXCallDisplayList(CPUState* cpu) {
    u32 available = 0;
    void* data = graphics_guest_pointer(cpu, g_display_list_call.address, &available);
    if (data == NULL || g_display_list_call.size > available) {
        fprintf(stderr,
                "[gx] GXCallDisplayList unresolved address=0x%08X size=%u "
                "available=%u\n",
                g_display_list_call.address, g_display_list_call.size,
                available);
    } else {
        emit_gx_resource_metadata(cpu);
        dol_platform_call_display_list(data, g_display_list_call.size);
    }
    cpu->lr = g_display_list_call.caller;
    cpu->pc = g_display_list_call.caller;
    g_display_list_call.active = false;
}

static void continue_GXCallDisplayList(CPUState* cpu) {
    const u32 gx_data = mem_read32(cpu, cpu->gpr[2] + (u32)(s32)GX_DATA_SDA_OFFSET);
    if (g_display_list_call.stage == 0u &&
        mem_read32(cpu, gx_data + GX_DIRTY_STATE_OFFSET) != 0u) {
        g_display_list_call.stage = 1u;
        cpu->lr = HLE_DISPLAY_LIST_RETURN;
        cpu->pc = g_hle_config.gx_dirty_state_helper_addr;
        return;
    }
    if (g_display_list_call.stage <= 1u && mem_read32(cpu, gx_data) != 0u) {
        g_display_list_call.stage = 2u;
        cpu->lr = HLE_DISPLAY_LIST_RETURN;
        cpu->pc = g_hle_config.gx_flush_prim_helper_addr;
        return;
    }
    finish_GXCallDisplayList(cpu);
}

void dol_hle_GXCallDisplayList(CPUState* cpu) {
    if (g_display_list_call.active) {
        fprintf(stderr, "[gx] nested GXCallDisplayList host continuation\n");
        return;
    }
    g_display_list_call.active = true;
    g_display_list_call.stage = 0u;
    g_display_list_call.caller = cpu->lr;
    g_display_list_call.address = hle_arg_u32(cpu, 0);
    g_display_list_call.size = hle_arg_u32(cpu, 1);
    g_hle_tail_call = true;
    continue_GXCallDisplayList(cpu);
}

static void finish_GXBegin(CPUState* cpu) {
    emit_gx_resource_metadata(cpu);
    dol_platform_mark_gx_begin();
    mem_write8(cpu, 0xCC008000u, (u8)(g_gx_begin.primitive | g_gx_begin.vtxfmt));
    mem_write16(cpu, 0xCC008000u, g_gx_begin.vertex_count);
    cpu->lr = g_gx_begin.caller;
    cpu->pc = g_gx_begin.caller;
    g_gx_begin.active = false;
}

static void continue_GXBegin(CPUState* cpu) {
    const u32 gx_data = mem_read32(cpu, cpu->gpr[2] + (u32)(s32)GX_DATA_SDA_OFFSET);
    if (g_gx_begin.stage == 0u &&
        mem_read32(cpu, gx_data + GX_DIRTY_STATE_OFFSET) != 0u) {
        g_gx_begin.stage = 1u;
        cpu->lr = HLE_GX_BEGIN_RETURN;
        cpu->pc = g_hle_config.gx_dirty_state_helper_addr;
        return;
    }
    if (g_gx_begin.stage <= 1u && mem_read32(cpu, gx_data) != 0u) {
        g_gx_begin.stage = 2u;
        cpu->lr = HLE_GX_BEGIN_RETURN;
        cpu->pc = g_hle_config.gx_flush_prim_helper_addr;
        return;
    }
    finish_GXBegin(cpu);
}

void dol_hle_GXBegin(CPUState* cpu) {
    if (g_gx_begin.active) {
        fprintf(stderr, "[gx] nested GXBegin host continuation\n");
        cpu->pc = cpu->lr;
        return;
    }
    g_gx_begin.active = true;
    g_gx_begin.stage = 0u;
    g_gx_begin.primitive = (u8)hle_arg_u32(cpu, 0);
    g_gx_begin.vtxfmt = (u8)hle_arg_u32(cpu, 1);
    g_gx_begin.vertex_count = (u16)hle_arg_u32(cpu, 2);
    g_gx_begin.caller = cpu->lr;
    g_hle_tail_call = true;
    continue_GXBegin(cpu);
}

bool dol_hle_handle_gx_return(CPUState* cpu, u32 address) {
    if (address == HLE_DISPLAY_LIST_RETURN && g_display_list_call.active) {
        continue_GXCallDisplayList(cpu);
        return true;
    }
    if (address == HLE_GX_BEGIN_RETURN && g_gx_begin.active) {
        continue_GXBegin(cpu);
        return true;
    }
    return false;
}

void dol_hle_GXCopyTex(CPUState* cpu) {
    u32 address = hle_arg_u32(cpu, 0);
    void* data = graphics_guest_pointer(cpu, address, NULL);
    dol_platform_set_copy_destination_guest(address, data);
}

void dol_hle_GXCopyDisp(CPUState* cpu) {
    (void)cpu;
    dol_platform_present();
}

void dol_hle_VIConfigure(CPUState* cpu) {
    u32 mode = hle_arg_u32(cpu, 0);
    if (!mode)
        return;
    dol_platform_configure_vi(
        mem_read32(cpu, mode),
        mem_read16(cpu, mode + 4u),
        mem_read16(cpu, mode + 6u),
        mem_read16(cpu, mode + 8u),
        mem_read16(cpu, mode + 0x0Eu),
        mem_read16(cpu, mode + 0x10u));
}

