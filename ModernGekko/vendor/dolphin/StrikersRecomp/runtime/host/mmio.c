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
    (void)cpu;
    (void)ea;
    // The write-gather pipe occupies one 32-byte cache line. Paired-single
    // stores write their second element at base+4, and every write in the line
    // is appended to the same FIFO stream.
    dol_platform_gx_write(value, size);
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
    if (value != NULL)
        *value = audio_mmio_read(ea, size);
    return true;
}

static bool audio_write_cb(void* user, CPUState* cpu, u32 ea, u8 size,
                           u64 value) {
    (void)user;
    (void)cpu;
    if (!audio_mmio_contains(ea))
        return false;
    audio_mmio_write(ea, size, value);
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
                                     interrupt_read_cb, interrupt_write_cb,
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
