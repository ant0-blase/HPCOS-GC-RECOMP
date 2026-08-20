#include "mmio.h"

#include "gxruntime/aram.h"
#include "gxruntime/di.h"
#include "gxruntime/exi.h"
#include "gxruntime/guest_memory.h"
#include "gxruntime/interrupts.h"
#include "gxruntime/mmio_bus.h"
#include "gxruntime/platform.h"
#include "gxruntime/si.h"
#include "host/audio.h"
#include "host/interrupt.h"

#include <stdio.h>


static bool g_log = false;


/* Forward declarations for the PI FIFO wrapper. */
static bool interrupt_read_cb(
    void* user,
    CPUState* cpu,
    u32 ea,
    u8 size,
    u64* value
);

static bool interrupt_write_cb(
    void* user,
    CPUState* cpu,
    u32 ea,
    u8 size,
    u64 value
);


/*
 * HPCOS standalone PI CPU-FIFO shadow.
 *
 * The retail GX SDK reads these PI registers back when it snapshots
 * the current CPU FIFO (GXGet/Save CPU FIFO state):
 *
 *   PI + 0x0C : FIFO base
 *   PI + 0x10 : FIFO end (inclusive last 32-bit word)
 *   PI + 0x14 : FIFO write pointer
 *
 * The old standalone runtime routed the complete PI window only
 * through the interrupt model, so these registers always read zero.
 * That turned an otherwise valid display-list size into a wrapped
 * negative value such as FF9D99A0.
 */
#define HPCOS_PI_FIFO_BASE_REG (DOL_PI_BASE + 0x0Cu)
#define HPCOS_PI_FIFO_END_REG  (DOL_PI_BASE + 0x10u)
#define HPCOS_PI_FIFO_WPTR_REG (DOL_PI_BASE + 0x14u)

static u32 g_hpcos_pi_fifo_base = 0u;
static u32 g_hpcos_pi_fifo_end  = 0u;
static u32 g_hpcos_pi_fifo_wptr = 0u;

static bool g_hpcos_pi_fifo_have_base = false;
static bool g_hpcos_pi_fifo_have_end  = false;
static bool g_hpcos_pi_fifo_have_wptr = false;

static u64 g_hpcos_pi_fifo_bytes = 0u;
static u64 g_hpcos_pi_fifo_cfg_writes = 0u;

static bool hpcos_pi_fifo_reg_for_ea(
    u32 ea,
    u32** reg,
    bool** valid
) {
    const u32 aligned = ea & ~3u;

    switch (aligned) {
    case HPCOS_PI_FIFO_BASE_REG:
        *reg = &g_hpcos_pi_fifo_base;
        *valid = &g_hpcos_pi_fifo_have_base;
        return true;

    case HPCOS_PI_FIFO_END_REG:
        *reg = &g_hpcos_pi_fifo_end;
        *valid = &g_hpcos_pi_fifo_have_end;
        return true;

    case HPCOS_PI_FIFO_WPTR_REG:
        *reg = &g_hpcos_pi_fifo_wptr;
        *valid = &g_hpcos_pi_fifo_have_wptr;
        return true;

    default:
        return false;
    }
}

static bool hpcos_pi_fifo_extract_be(
    u32 reg,
    u32 ea,
    u8 size,
    u64* value
) {
    const u32 off = ea & 3u;

    if (value == NULL)
        return false;

    if (size == 4u && off == 0u) {
        *value = reg;
        return true;
    }

    if (size == 2u && off <= 2u) {
        const u32 shift = (2u - off) * 8u;
        *value = (reg >> shift) & 0xFFFFu;
        return true;
    }

    if (size == 1u) {
        const u32 shift = (3u - off) * 8u;
        *value = (reg >> shift) & 0xFFu;
        return true;
    }

    return false;
}

static bool hpcos_pi_fifo_merge_be(
    u32* reg,
    u32 ea,
    u8 size,
    u64 value
) {
    const u32 off = ea & 3u;

    if (reg == NULL)
        return false;

    if (size == 4u && off == 0u) {
        *reg = (u32)value;
        return true;
    }

    if (size == 2u && off <= 2u) {
        const u32 shift = (2u - off) * 8u;
        const u32 mask = 0xFFFFu << shift;

        *reg =
            (*reg & ~mask) |
            (((u32)value & 0xFFFFu) << shift);

        return true;
    }

    if (size == 1u) {
        const u32 shift = (3u - off) * 8u;
        const u32 mask = 0xFFu << shift;

        *reg =
            (*reg & ~mask) |
            (((u32)value & 0xFFu) << shift);

        return true;
    }

    return false;
}

static bool hpcos_pi_fifo_read_cb(
    void* user,
    CPUState* cpu,
    u32 ea,
    u8 size,
    u64* value
) {
    u32* reg = NULL;
    bool* valid = NULL;

    if (hpcos_pi_fifo_reg_for_ea(ea, &reg, &valid)) {
        if (!*valid)
            *reg = 0u;

        return hpcos_pi_fifo_extract_be(
            *reg,
            ea,
            size,
            value
        );
    }

    /*
     * Cause/mask/reset/etc. remain owned by the existing PI
     * interrupt model.
     */
    return interrupt_read_cb(
        user,
        cpu,
        ea,
        size,
        value
    );
}

static bool hpcos_pi_fifo_write_cb(
    void* user,
    CPUState* cpu,
    u32 ea,
    u8 size,
    u64 value
) {
    u32* reg = NULL;
    bool* valid = NULL;

    if (hpcos_pi_fifo_reg_for_ea(ea, &reg, &valid)) {
        if (!hpcos_pi_fifo_merge_be(
                reg,
                ea,
                size,
                value)) {
            return false;
        }

        *valid = true;
        ++g_hpcos_pi_fifo_cfg_writes;

        if (g_hpcos_pi_fifo_cfg_writes <= 100u) {
            fprintf(stderr,
                    "[HPCOS-PI-FIFO] cfg #%llu "
                    "ea=%08X size=%u value=%08llX "
                    "base=%08X end=%08X wptr=%08X\n",
                    (unsigned long long)
                        g_hpcos_pi_fifo_cfg_writes,
                    ea,
                    (unsigned)size,
                    (unsigned long long)value,
                    g_hpcos_pi_fifo_base,
                    g_hpcos_pi_fifo_end,
                    g_hpcos_pi_fifo_wptr);
        }

        return true;
    }

    return interrupt_write_cb(
        user,
        cpu,
        ea,
        size,
        value
    );
}

static void hpcos_pi_fifo_advance(u32 bytes)
{
    if (bytes == 0u)
        return;

    if (!g_hpcos_pi_fifo_have_base ||
        !g_hpcos_pi_fifo_have_end ||
        !g_hpcos_pi_fifo_have_wptr) {
        return;
    }

    /*
     * PI stores physical MEM1 addresses. Keep the complete shadow
     * values for readback, but use the 26-bit physical address for
     * the circular FIFO arithmetic.
     */
    const u32 base =
        g_hpcos_pi_fifo_base & 0x03FFFFFFu;

    const u32 end =
        g_hpcos_pi_fifo_end & 0x03FFFFFFu;

    u32 wptr =
        g_hpcos_pi_fifo_wptr & 0x03FFFFFFu;

    if (end < base)
        return;

    /*
     * GX FIFO 'end' denotes the inclusive address of the final
     * 32-bit word, hence +4 for the byte span.
     */
    const u64 span =
        (u64)end - (u64)base + 4u;

    if (span == 0u)
        return;

    const u64 end_exclusive =
        (u64)base + span;

    if ((u64)wptr < (u64)base ||
        (u64)wptr >= end_exclusive) {
        wptr = base;
    }

    u64 rel =
        (u64)wptr - (u64)base;

    rel += bytes;
    rel %= span;

    g_hpcos_pi_fifo_wptr =
        base + (u32)rel;

    g_hpcos_pi_fifo_bytes += bytes;
}

/*
 * Minimal DSP bootstrap state for standalone static-recomp bring-up.
 *
 * DSPCR  = 0xCC00500A
 * AR DMA length = 0xCC005028
 *
 * Real hardware clears DSPCR.RES after reset and raises ARINT when an
 * ARAM DMA completes. The current lightweight audio backend does not yet
 * model those asynchronous transitions.
 */
static bool g_dsp_reset_pending = false;
static bool g_dsp_aram_dma_complete = false;

/*
 * Minimal bootstrap mailbox model.
 *
 * After the DSP bootstrap code is uploaded and HALT is released,
 * the DSP sends one word to the CPU mailbox. The bootstrap only
 * waits for the FULL bit and consumes the word.
 */
static unsigned g_dsp_aram_dma_count = 0;
static bool g_dsp_boot_mailbox_ready = false;
static u16 g_cpu_dsp_mail_hi = 0;
static u16 g_cpu_dsp_mail_lo = 0;
static bool g_cpu_dsp_mail_full = false;


#define HPCOS_DSPCR        0xCC00500Au
#define HPCOS_ARAM_DMA_LEN 0xCC005028u
#define HPCOS_DSPCR_RES    0x0001u
#define HPCOS_DSPCR_ARINT  0x0020u
#define HPCOS_DSPCR_HALT   0x0004u

#define HPCOS_DSP_AR_MODE 0xCC005016u
#define HPCOS_CPU_DSP_MAILBOX_HI 0xCC005000u
#define HPCOS_CPU_DSP_MAILBOX_LO 0xCC005002u

#define HPCOS_DSP_MAILBOX_HI 0xCC005004u
#define HPCOS_DSP_MAILBOX_LO 0xCC005006u
#define HPCOS_DSP_MAILBOX_FULL 0x8000u
static DolGuestMemory g_guest_memory;
static DolMmioBus g_mmio_bus;
static DolExi g_exi;
static DolDi g_di;

#define DSP_BASE 0xCC005000u
#define DSP_SIZE 0x40u
#define AI_BASE  0xCC006C00u
#define AI_SIZE  0x20u
#define WGPIPE_BASE 0xCC008000u
#define WGPIPE_SIZE 0x20u

void mmio_set_logging(bool enabled) {
    g_log = enabled;
}

static const char* region_name(u32 ea) {
    if (ea >= 0xCC006800u && ea < 0xCC006C00u)
        return "EXI";
    if (ea >= 0xCC006400u && ea < 0xCC006800u)
        return "SI";
    if (ea >= 0xCC006000u && ea < 0xCC006400u)
        return "DI";
    u32 base = ea & 0xFFFFF000u;
    switch (base) {
    case 0xCC002000u: return "VI";   // video interface
    case 0xCC003000u: return "PI";   // processor interface
    case 0xCC004000u: return "MI";   // memory interface
    case 0xCC005000u: return "DSP/AI";
    case 0xCC006C00u: return "AI";   // audio interface
    case 0xCC000000u: return "CP";   // command processor (GX)
    case 0xCC008000u: return "PE/GX FIFO";
    default:          return "MMIO";
    }
}

static bool guest_memory_read_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                                 u64* value) {
    (void)cpu;
    return dol_guest_memory_read((const DolGuestMemory*)user, ea, size, value);
}

static bool guest_memory_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                                  u64 value) {
    (void)cpu;
    return dol_guest_memory_write((DolGuestMemory*)user, ea, size, value);
}

static bool aram_read_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                         u64* value) {
    (void)user;
    (void)cpu;
    if (!aram_contains(ea))
        return false;
    if (value != NULL)
        *value = aram_read(ea, size);
    return true;
}

static bool aram_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                          u64 value) {
    (void)user;
    (void)cpu;
    if (!aram_contains(ea))
        return false;
    aram_write(ea, value, size);
    return true;
}

#ifdef STRIKERSRECOMP_AURORA
static bool gx_fifo_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                             u64 value) {
    (void)user;

    /*
     * HPCOS temporary Aurora WGPIPE origin probe.
     *
     * Bound it past the current ~2479-byte frontend failure so the
     * complete first failing command stream can be reconstructed.
     */
    static unsigned long long hpcos_wgpipe_bytes = 0;

    if (hpcos_wgpipe_bytes < 3072ull) {
        fprintf(stderr,
                "[HPCOS-AURORA-WGPIPE] off=%llu pc=%08X lr=%08X "
                "ea=%08X size=%u value=%016llX\\n",
                hpcos_wgpipe_bytes,
                cpu != NULL ? cpu->pc : 0u,
                cpu != NULL ? cpu->lr : 0u,
                ea,
                (unsigned)size,
                (unsigned long long)value);
        fflush(stderr);
    }

    hpcos_wgpipe_bytes += size;

    /*
     * Feed Aurora exactly as before, but also model the PI CPU-FIFO
     * write pointer which real hardware advances as bytes leave the
     * write-gather pipe.
     */
    dol_platform_gx_write(value, size);
    hpcos_pi_fifo_advance((u32)size);

    return true;
}

static bool graphics_guest_address_resolver_cb(
    void* user, u32 address, u32 size, DolGuestAddressSpace space,
    DolGuestResourceKind resource, const void** data, u32* available) {
    CPUState* cpu = (CPUState*)user;
    if (cpu == NULL || data == NULL || available == NULL)
        return false;
    DolGuestAddressResolver resolver;
    DolGuestResolvedRange range;
    dol_guest_address_resolver_init(&resolver, &g_guest_memory, cpu);
    if (!dol_guest_address_resolver_resolve(&resolver, address, size, space,
                                            resource, &range)) {
        *data = NULL;
        *available = 0;
        return false;
    }
    *data = range.data;
    *available = range.available;
    return true;
}
#endif

static bool audio_read_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                          u64* value) {
    (void)user;
    (void)cpu;

    if (!audio_mmio_contains(ea))
        return false;

    u64 result = audio_mmio_read(ea, size);

    if (ea == HPCOS_DSPCR && size == 2u) {
        /*
         * DSP reset is self-clearing in hardware.
         */
        if (g_dsp_reset_pending) {
            result &= ~(u64)HPCOS_DSPCR_RES;
            g_dsp_reset_pending = false;

            fprintf(stderr,
                    "[dsp] reset completed DSPCR=%04llX\n",
                    (unsigned long long)result);
        }

        /*
         * ARAM DMA completion raises ARINT.
         */
        if (g_dsp_aram_dma_complete)
            result |= HPCOS_DSPCR_ARINT;
    }

    /*
     * DSP -> CPU mailbox.
     *
     * Once the bootstrap has released DSP HALT, expose one completed
     * mailbox message. Reading the low half consumes the message.
     */
    
    /*
     * GameCube AR_MODE (CC005016) is read-only.
     * Bit 0 indicates that the ARAM controller has initialized.
     *
     * Dolphin initializes this register to 1 on GameCube.
     * GHSE69 waits synchronously for this bit during ARInit().
     */
    /*
     * HPCOS CPU->DSP mailbox read overlay.
     *
     * CC005000 bit 15 is CPU-mailbox FULL.
     * Our fake DSP consumes a completed mail synchronously when
     * CC005002 is written, so subsequent polling must observe FULL=0.
     */
    if (ea == HPCOS_CPU_DSP_MAILBOX_HI && size == 2u) {
        result = (u64)g_cpu_dsp_mail_hi;

        if (g_cpu_dsp_mail_full)
            result |= 0x8000u;
        else
            result &= ~0x8000u;
    }

    if (ea == HPCOS_CPU_DSP_MAILBOX_LO && size == 2u) {
        result = (u64)g_cpu_dsp_mail_lo;
    }

    if (ea == HPCOS_DSP_AR_MODE && size == 2u) {
        result = 1u;

        static bool logged_aram_mode = false;
        if (!logged_aram_mode) {
            fprintf(stderr,
                    "[HPCOS-AURORA:ARAM] AR_MODE initialized -> 0001\n");
            logged_aram_mode = true;
        }
    }

if (ea == HPCOS_DSP_MAILBOX_HI &&
        size == 2u &&
        g_dsp_boot_mailbox_ready) {

        result |= HPCOS_DSP_MAILBOX_FULL;
    }

    if (ea == HPCOS_DSP_MAILBOX_LO &&
        size == 2u &&
        g_dsp_boot_mailbox_ready) {

        /*
         * The bootstrap does not use the actual message contents here;
         * it merely waits for DSP startup confirmation.
         */
        result = 0u;
        g_dsp_boot_mailbox_ready = false;

        fprintf(stderr,
                "[dsp] bootstrap mailbox consumed\n");
    }

    if (value != NULL)
        *value = result;

    return true;
}

static bool audio_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                           u64 value) {
    (void)user;
    (void)cpu;

    if (!audio_mmio_contains(ea))
        return false;

    audio_mmio_write(ea, size, value);

    if (ea == HPCOS_DSPCR && size == 2u) {
        if (value & HPCOS_DSPCR_RES) {
            g_dsp_reset_pending = true;

            fprintf(stderr,
                    "[dsp] reset requested DSPCR=%04llX\n",
                    (unsigned long long)value);
        }

        /*
         * Writing ARINT back acknowledges the interrupt.
         */
        if (value & HPCOS_DSPCR_ARINT)
            g_dsp_aram_dma_complete = false;

        /*
         * After the two bootstrap ARAM uploads, releasing DSP HALT
         * starts the bootstrap microcode. Model its first mailbox
         * response immediately.
         */
        if (!(value & HPCOS_DSPCR_HALT) &&
            g_dsp_aram_dma_count >= 2u &&
            !g_dsp_boot_mailbox_ready) {

            g_dsp_boot_mailbox_ready = true;

            fprintf(stderr,
                    "[dsp] HALT released -> bootstrap mailbox ready\n");
        }
    }

    if (ea == HPCOS_CPU_DSP_MAILBOX_HI && size == 2u) {
        g_cpu_dsp_mail_hi = (u16)value;
        g_cpu_dsp_mail_full =
            (g_cpu_dsp_mail_hi & 0x8000u) != 0u;
    }

    if (ea == HPCOS_CPU_DSP_MAILBOX_LO && size == 2u) {
        g_cpu_dsp_mail_lo = (u16)value;

        const u32 mail =
            ((u32)g_cpu_dsp_mail_hi << 16) |
            (u32)g_cpu_dsp_mail_lo;

        fprintf(stderr,
                "[dsp] CPU->DSP mail consumed %08X\n",
                mail);

        /*
         * No DSP microcode executes in the standalone bring-up yet,
         * so consume the mailbox synchronously.
         */
        g_cpu_dsp_mail_full = false;
        g_cpu_dsp_mail_hi &= 0x7FFFu;
    }

    if (ea == HPCOS_ARAM_DMA_LEN && size == 4u && value != 0u) {
        /*
         * Bootstrap uses tiny synchronous ARAM uploads. Complete them
         * immediately for now.
         */
        g_dsp_aram_dma_complete = true;
        g_dsp_aram_dma_count++;

        fprintf(stderr,
                "[dsp] ARAM DMA #%u complete bytes=%llu\n",
                g_dsp_aram_dma_count,
                (unsigned long long)value);
    }

    return true;
}

static bool interrupt_read_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                              u64* value) {
    (void)user;
    (void)cpu;
    if (!interrupt_mmio_contains(ea))
        return false;
    if (value != NULL)
        *value = interrupt_mmio_read(ea, size);
    return true;
}

static bool interrupt_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                               u64 value) {
    (void)user;
    (void)cpu;
    if (!interrupt_mmio_contains(ea))
        return false;
    interrupt_mmio_write(ea, size, value);
    return true;
}

static bool exi_read_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                        u64* value) {
    (void)cpu;
    DolExi* exi = (DolExi*)user;
    if (!dol_exi_mmio_contains(ea))
        return false;
    if (value != NULL)
        *value = dol_exi_mmio_read(exi, ea, size);
    interrupt_set_exi_pending(dol_exi_interrupt_pending(exi));
    return true;
}

static bool exi_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                         u64 value) {
    DolExi* exi = (DolExi*)user;
    if (!dol_exi_mmio_contains(ea))
        return false;
    dol_exi_mmio_write(exi, cpu, ea, size, value);
    interrupt_set_exi_pending(dol_exi_interrupt_pending(exi));
    return true;
}


/*
 * HPCOS standalone GameCube DVD backend.
 *
 * GXRuntime's DolDi emulates the DI registers, command completion and
 * interrupt flags, but requires a command callback to provide actual
 * disc data.
 */
static FILE* g_hpcos_disc = NULL;

static DolDiCommandResult hpcos_di_execute_command(
    void* user,
    DolDiCommand* command)
{
    if (command == NULL || command->cpu == NULL)
        return DOL_DI_COMMAND_ERROR;

    const char* disc_path =
        user != NULL
            ? (const char*)user
            : "iso/HPCOS.iso";

    const u8 opcode =
        (u8)(command->command[0] >> 24);

    fprintf(stderr,
            "[HPCOS-DI:CMD] "
            "op=%02X "
            "cmd0=%08X cmd1=%08X cmd2=%08X "
            "dma=%08X len=%08X "
            "DMA=%u WRITE=%u\n",
            opcode,
            command->command[0],
            command->command[1],
            command->command[2],
            command->dma_address,
            command->dma_length,
            command->dma ? 1u : 0u,
            command->write ? 1u : 0u);

    switch (opcode) {
    /*
     * DVD Low Read.
     *
     * command[1] contains the disc offset divided by four.
     */
    case 0xA8u: {
        if (!command->dma ||
            command->write ||
            command->dma_length == 0u) {

            fprintf(stderr,
                    "[HPCOS-DI:A8] invalid transfer flags\n");

            return DOL_DI_COMMAND_ERROR;
        }

        if (g_hpcos_disc == NULL) {
            g_hpcos_disc =
                fopen(disc_path, "rb");

            if (g_hpcos_disc == NULL) {
                fprintf(stderr,
                        "[HPCOS-DI:A8] "
                        "cannot open %s\n",
                        disc_path);

                return DOL_DI_COMMAND_ERROR;
            }

            fprintf(stderr,
                    "[HPCOS-DI] opened %s\n",
                    disc_path);
        }

        const u64 disc_offset =
            ((u64)command->command[1]) << 2;

        u32 available = 0u;

        void* dest =
            dol_guest_memory_pointer(
                &g_guest_memory,
                command->cpu,
                command->dma_address,
                &available);

        if (dest == NULL ||
            available < command->dma_length) {

            fprintf(stderr,
                    "[HPCOS-DI:A8] "
                    "bad guest DMA destination "
                    "addr=%08X len=%08X "
                    "available=%08X\n",
                    command->dma_address,
                    command->dma_length,
                    available);

            return DOL_DI_COMMAND_ERROR;
        }

        if (fseek(
                g_hpcos_disc,
                (long)disc_offset,
                SEEK_SET) != 0) {

            fprintf(stderr,
                    "[HPCOS-DI:A8] "
                    "seek failed offset=%08llX\n",
                    (unsigned long long)disc_offset);

            return DOL_DI_COMMAND_ERROR;
        }

        const size_t got =
            fread(
                dest,
                1u,
                command->dma_length,
                g_hpcos_disc);

        fprintf(stderr,
                "[HPCOS-DI:A8] "
                "offset=%08llX "
                "dest=%08X "
                "len=%08X "
                "got=%08zX\n",
                (unsigned long long)disc_offset,
                command->dma_address,
                command->dma_length,
                got);

        if (got != command->dma_length)
            return DOL_DI_COMMAND_ERROR;

        const u8* bytes =
            (const u8*)dest;

        fprintf(stderr,
                "[HPCOS-DI:A8] first32=");

        const u32 dump_len =
            command->dma_length < 32u
                ? command->dma_length
                : 32u;

        for (u32 i = 0u; i < dump_len; ++i)
            fprintf(stderr, "%02X", bytes[i]);

        fputc('\n', stderr);

        return DOL_DI_COMMAND_COMPLETE;
    }

    /*
     * Request Error.
     *
     * For the initial bring-up backend, no pending drive error is reported.
     */
    case 0xE0u:
        if (command->immediate_data != NULL)
            *command->immediate_data = 0u;

        fprintf(stderr,
                "[HPCOS-DI:E0] request-error -> no error\n");

        return DOL_DI_COMMAND_COMPLETE;

    /*
     * Stop Motor.
     */
    case 0xE3u:
        fprintf(stderr,
                "[HPCOS-DI:E3] stop motor\n");

        return DOL_DI_COMMAND_COMPLETE;

    default:
        fprintf(stderr,
                "[HPCOS-DI] unsupported command %02X\n",
                opcode);

        return DOL_DI_COMMAND_ERROR;
    }
}

static bool di_read_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                       u64* value) {
    (void)cpu;
    DolDi* di = (DolDi*)user;
    if (!dol_di_mmio_contains(ea))
        return false;
    if (value != NULL)
        *value = dol_di_mmio_read(di, ea, size);
    interrupt_set_di_pending(dol_di_interrupt_pending(di));
    return true;
}

static bool di_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                        u64 value) {
    DolDi* di = (DolDi*)user;
    if (!dol_di_mmio_contains(ea))
        return false;
    dol_di_mmio_write(di, cpu, ea, size, value);
    interrupt_set_di_pending(dol_di_interrupt_pending(di));
    return true;
}

static u64 mmio_read(CPUState* cpu, u32 ea, u8 size) {
    u64 value = 0;
    if (dol_mmio_bus_read(&g_mmio_bus, cpu, ea, size, &value))
        return value;
    if (g_log)
        fprintf(stderr, "[mmio] read%u  %-10s 0x%08X -> 0\n",
                (unsigned)(size * 8u), region_name(ea), ea);
    return 0;
}

static void mmio_write(CPUState* cpu, u32 ea, u64 value, u8 size) {
    if (dol_mmio_bus_write(&g_mmio_bus, cpu, ea, size, value))
        return;
    if (g_log)
        fprintf(stderr, "[mmio] write%u %-10s 0x%08X <- 0x%llX\n",
                (unsigned)(size * 8u), region_name(ea), ea,
                (unsigned long long)value);
}

static u32 mmio_read32(CPUState* cpu, u32 ea, u8 rid) {
    (void)cpu; (void)rid;
    if (g_log)
        fprintf(stderr, "[mmio] eciwx %-10s 0x%08X -> 0\n", region_name(ea), ea);
    return 0;
}

static void mmio_write32(CPUState* cpu, u32 ea, u32 value, u8 rid) {
    (void)cpu; (void)rid;
    if (g_log)
        fprintf(stderr, "[mmio] ecowx %-10s 0x%08X <- 0x%08X\n",
                region_name(ea), ea, value);
}

static void* guest_region_pointer(u8* data, u32 base, u32 bytes,
                                  u32 ea, u32 size) {
    if (data == NULL || size == 0u || size > bytes || ea < base ||
        ea - base > bytes - size)
        return NULL;
    return data + (ea - base);
}

static void* mmio_pointer(CPUState* cpu, u32 ea, u32 size) {
    (void)cpu;
    void* ptr = guest_region_pointer(g_guest_memory.vm,
                                     g_guest_memory.config.vm_base,
                                     g_guest_memory.config.vm_size, ea, size);
    if (ptr != NULL)
        return ptr;
    return guest_region_pointer(g_guest_memory.locked_cache,
                                g_guest_memory.config.locked_cache_base,
                                g_guest_memory.config.locked_cache_size, ea,
                                size);
}

bool mmio_install(CPUState* cpu) {
    aram_init();
    audio_init();
    interrupt_init();
    dol_exi_init(&g_exi);
    dol_di_init(&g_di);

    /*
     * A GameCube disc is already inserted when the standalone
     * executable starts. Install the actual command executor before
     * the guest begins touching the DI registers.
     */
    dol_di_set_command_callback(
        &g_di,
        hpcos_di_execute_command,
        (void*)"iso/HPCOS.iso");

    dol_di_set_disc_present(&g_di, true);

    /*
     * This is the initial inserted state, not a runtime lid-close
     * transition, so don't expose a synthetic cover interrupt.
     */
    g_di.cover &= ~DOL_DI_COVER_INT;
    if (!dol_guest_memory_init(&g_guest_memory, NULL)) {
        fprintf(stderr, "[mmio] failed to allocate guest memory regions\n");
        return false;
    }
    dol_mmio_bus_init(&g_mmio_bus);
    bool ok = true;
    ok = ok && dol_mmio_bus_register(
                   &g_mmio_bus, g_guest_memory.config.vm_base,
                   g_guest_memory.config.vm_size, guest_memory_read_cb,
                   guest_memory_write_cb, &g_guest_memory);
    ok = ok && dol_mmio_bus_register(
                   &g_mmio_bus, g_guest_memory.config.locked_cache_base,
                   g_guest_memory.config.locked_cache_size,
                   guest_memory_read_cb, guest_memory_write_cb,
                   &g_guest_memory);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, ARAM_BASE, ARAM_SIZE,
                                     aram_read_cb, aram_write_cb, NULL);
#ifdef STRIKERSRECOMP_AURORA
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, WGPIPE_BASE, WGPIPE_SIZE,
                                     NULL, gx_fifo_write_cb, NULL);
#endif
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DSP_BASE, DSP_SIZE,
                                     audio_read_cb, audio_write_cb, NULL);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, AI_BASE, AI_SIZE,
                                     audio_read_cb, audio_write_cb, NULL);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DOL_PE_INTERRUPT_STATUS, 2u,
                                     interrupt_read_cb, interrupt_write_cb,
                                     NULL);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DOL_VI_BASE,
                                     DOL_VI_REGISTER_BYTES,
                                     interrupt_read_cb, interrupt_write_cb,
                                     NULL);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DOL_PI_BASE, 0x40u,
                                     hpcos_pi_fifo_read_cb,
                                     hpcos_pi_fifo_write_cb,
                                     NULL);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DOL_SI_BASE,
                                     DOL_SI_REGISTER_BYTES,
                                     interrupt_read_cb, interrupt_write_cb,
                                     NULL);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DOL_EXI_BASE,
                                     DOL_EXI_REGISTER_BYTES,
                                     exi_read_cb, exi_write_cb, &g_exi);
    ok = ok && dol_mmio_bus_register(&g_mmio_bus, DOL_DI_BASE,
                                     DOL_DI_REGISTER_BYTES,
                                     di_read_cb, di_write_cb, &g_di);
    if (!ok) {
        fprintf(stderr, "[mmio] failed to register runtime MMIO regions\n");
        dol_guest_memory_shutdown(&g_guest_memory);
        return false;
    }
    cpu->external_read   = mmio_read;
    cpu->external_write  = mmio_write;
    cpu->external_read32 = mmio_read32;
    cpu->external_write32 = mmio_write32;
    cpu->external_pointer = mmio_pointer;
#ifdef STRIKERSRECOMP_AURORA
    dol_platform_set_guest_address_resolver(
        graphics_guest_address_resolver_cb, cpu);
#endif
    return true;
}

void mmio_set_disc_present(bool present) {
    dol_di_set_disc_present(&g_di, present);
    interrupt_set_di_pending(dol_di_interrupt_pending(&g_di));
}

void mmio_shutdown(void) {
    if (g_hpcos_disc != NULL) {
        fclose(g_hpcos_disc);
        g_hpcos_disc = NULL;
    }

#ifdef STRIKERSRECOMP_AURORA
    dol_platform_set_guest_address_resolver(NULL, NULL);
#endif
    dol_guest_memory_shutdown(&g_guest_memory);
    aram_free();
}

void* mmio_guest_pointer(CPUState* cpu, u32 address, u32* available) {
    return dol_guest_memory_pointer(&g_guest_memory, cpu, address, available);
}

void mmio_guest_copy(CPUState* cpu, u32 dest, u32 src, u32 bytes) {
    dol_guest_memory_copy(&g_guest_memory, cpu, dest, src, bytes);
}
