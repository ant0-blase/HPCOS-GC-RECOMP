// SPDX-License-Identifier: GPL-3.0-or-later
#ifdef NDEBUG
#undef NDEBUG
#endif
#include "core/cpu.h"
#include "gxruntime/aram.h"
#include "gxruntime/audio_dma.h"
#include "gxruntime/boot.h"
#include "gxruntime/dvd.h"
#include "gxruntime/di.h"
#include "gxruntime/event_clock.h"
#include "gxruntime/exi.h"
#include "gxruntime/guest_memory.h"
#include "gxruntime/gx_recomp.h"
#include "gxruntime/headless_backend.h"
#include "gxruntime/interrupts.h"
#include "gxruntime/loader.h"
#include "gxruntime/memory_card.h"
#include "gxruntime/mmio_bus.h"
#include "gxruntime/platform.h"
#include "gxruntime/savestate.h"
#include "gxruntime/si.h"
#include "gxruntime/vi_clock.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

_Static_assert(GXRUNTIME_CPU_ABI_VERSION == 4u,
               "update runtime ABI tests when the CPU ABI changes");
_Static_assert(GXRUNTIME_CPU_ABI_DOLRECOMP_PREFIX == 1u,
               "GXRuntime generated-code prefix must stay explicit");
_Static_assert(offsetof(CPUState, gpr) == 0,
               "generated code expects CPUState.gpr at the ABI prefix start");
_Static_assert(offsetof(CPUState, fpr) > offsetof(CPUState, gpr),
               "CPUState register prefix order changed");
_Static_assert(offsetof(CPUState, ps1) > offsetof(CPUState, fpr),
               "CPUState paired-single lane order changed");
_Static_assert(offsetof(CPUState, pc) > offsetof(CPUState, ps1),
               "CPUState program-counter prefix order changed");
_Static_assert(offsetof(CPUState, external_read) > offsetof(CPUState, locked_cache_valid),
               "CPUState callback prefix order changed");
_Static_assert(offsetof(CPUState, ram) > offsetof(CPUState, external_user_data),
               "CPUState RAM fields must remain after callbacks");
_Static_assert(offsetof(CPUState, external_pointer) > offsetof(CPUState, ram_size),
               "GXRuntime external_pointer must remain a tail extension");
_Static_assert(offsetof(CPUState, downcount) > offsetof(CPUState, external_pointer),
               "ABI v2 downcount position changed");
_Static_assert(sizeof(((CPUState*)0)->downcount) == 8u,
               "downcount is s64 so unconsumed charges cannot wrap");
_Static_assert(offsetof(CPUState, native_cycle_budget) > offsetof(CPUState, exram_size),
               "ABI v4 scheduler budget must follow the generated-code prefix");
_Static_assert(offsetof(CPUState, native_guard_budget) >
                   offsetof(CPUState, native_cycle_budget),
               "ABI v4 guard budget order changed");
_Static_assert(offsetof(CPUState, spr_read) > offsetof(CPUState, native_guard_budget),
               "host SPR callbacks must follow the shared scheduler fields");
#if UINTPTR_MAX == UINT64_MAX
_Static_assert(offsetof(CPUState, native_cycle_budget) == 3504u,
               "64-bit generated-code cycle budget ABI offset changed");
_Static_assert(offsetof(CPUState, native_guard_budget) == 3512u,
               "64-bit generated-code guard budget ABI offset changed");
#endif
_Static_assert(offsetof(CPUState, cache_control) > offsetof(CPUState, spr_write),
               "ABI v3 callback order changed");
_Static_assert(sizeof(((CPUState*)0)->gpr) / sizeof(((CPUState*)0)->gpr[0]) == 32u,
               "generated code requires 32 GPRs");
_Static_assert(sizeof(((CPUState*)0)->fpr) / sizeof(((CPUState*)0)->fpr[0]) == 32u,
               "generated code requires 32 FPRs");
_Static_assert(sizeof(((CPUState*)0)->ps1) / sizeof(((CPUState*)0)->ps1[0]) == 32u,
               "generated code requires 32 paired-single high lanes");
_Static_assert(sizeof(((CPUState*)0)->sr) / sizeof(((CPUState*)0)->sr[0]) == 16u,
               "generated code requires 16 segment registers");
_Static_assert(sizeof(((CPUState*)0)->gqr) / sizeof(((CPUState*)0)->gqr[0]) == 8u,
               "generated code requires 8 GQRs");

static unsigned g_gx_writes;
static unsigned g_audio_frames;
static u32 g_platform_sample_rate;
static unsigned g_platform_rate_calls;
static unsigned g_guest_resolver_sets;
static DolPlatformGuestAddressResolverFn g_guest_resolver_fn;
static void* g_guest_resolver_user;
static u8 g_psq_external[16];
static unsigned g_psq_external_writes;
static unsigned g_mmio_read_hits;
static unsigned g_mmio_write_hits;
static CPUState* g_mmio_last_cpu;
static u64 g_mmio_last_write;
static unsigned g_exi_transfer_calls;
static DolExiTransfer g_exi_last_transfer;
static bool g_exi_complete_transfer;
static unsigned g_di_command_calls;
static DolDiCommand g_di_last_command;
static DolDiCommandResult g_di_command_result;
static unsigned g_platform_array_guest_calls;
static unsigned g_platform_texture_guest_calls;
static unsigned g_platform_tlut_guest_calls;
static unsigned g_platform_copy_guest_calls;
static unsigned g_spr_reads;
static unsigned g_spr_writes;
static unsigned g_cache_controls;
static u16 g_last_spr;
static u32 g_last_spr_value;
static u8 g_last_cache_operation;

static u32 test_spr_read(CPUState* cpu, u16 spr, u32 cia) {
    (void)cpu;
    (void)cia;
    g_spr_reads++;
    g_last_spr = spr;
    return 0xA5000000u | spr;
}

static void test_spr_write(CPUState* cpu, u16 spr, u32 value, u32 cia) {
    (void)cpu;
    (void)cia;
    g_spr_writes++;
    g_last_spr = spr;
    g_last_spr_value = value;
}

static void test_cache_control(CPUState* cpu, u8 operation, u32 ea, u32 cia) {
    (void)cpu;
    (void)cia;
    g_cache_controls++;
    g_last_cache_operation = operation;
    g_last_spr_value = ea;
}

static void put_be32(u8* p, u32 value) {
    p[0] = (u8)(value >> 24);
    p[1] = (u8)(value >> 16);
    p[2] = (u8)(value >> 8);
    p[3] = (u8)value;
}

static void put_be16(u8* p, u16 value) {
    p[0] = (u8)(value >> 8);
    p[1] = (u8)value;
}

static void test_gx_write(u64 value, u8 size) {
    assert(value == 0x12345678u);
    assert(size == 4);
    g_gx_writes++;
}

static void test_audio_push(const s16* samples, u32 frames) {
    assert(samples != NULL);
    g_audio_frames += frames;
}

static void test_audio_set_sample_rate(u32 sample_rate) {
    g_platform_sample_rate = sample_rate;
    g_platform_rate_calls++;
}

static void test_set_array_guest(u32 attr, u32 guest_address,
                                 const void* data, u32 size, u8 stride) {
    assert(attr == 3u);
    assert(guest_address == GC_RAM_BASE + 0x120u);
    assert(data != NULL);
    assert(size == 64u);
    assert(stride == 12u);
    g_platform_array_guest_calls++;
}

static void test_load_texture_guest(u8 slot, u32 guest_address,
                                    const void* data, u32 width, u32 height,
                                    u32 format, u32 tlut, bool mipmap,
                                    u32 object_id, u32 data_version) {
    assert(slot == 2u);
    assert(guest_address == GC_RAM_BASE + 0x200u);
    assert(data != NULL);
    assert(width == 32u);
    assert(height == 16u);
    assert(format == 6u);
    assert(tlut == 4u);
    assert(mipmap);
    assert(object_id == 0xAAu);
    assert(data_version == 0xBBu);
    g_platform_texture_guest_calls++;
}

static void test_load_tlut_guest(u8 slot, u32 guest_address, const void* data,
                                 u32 format, u16 entries, u32 object_id,
                                 u32 data_version) {
    assert(slot == 1u);
    assert(guest_address == GC_RAM_BASE + 0x300u);
    assert(data != NULL);
    assert(format == 2u);
    assert(entries == 16u);
    assert(object_id == 0xCCu);
    assert(data_version == 0xDDu);
    g_platform_tlut_guest_calls++;
}

static void test_set_copy_destination_guest(u32 guest_address,
                                            const void* data) {
    assert(guest_address == GC_RAM_BASE + 0x400u);
    assert(data != NULL);
    g_platform_copy_guest_calls++;
}

static bool test_guest_resolve(void* user, u32 address, u32 size,
                               DolGuestAddressSpace space,
                               DolGuestResourceKind resource,
                               const void** data, u32* available) {
    static const u8 bytes[4] = {1, 2, 3, 4};
    assert(user != NULL);
    assert(address == 0x40u);
    assert(size == 4u);
    assert(space == DOL_GUEST_ADDRESS_PHYSICAL);
    assert(resource == DOL_GUEST_RESOURCE_VERTEX_ARRAY);
    assert(data != NULL);
    assert(available != NULL);
    *data = bytes;
    *available = sizeof(bytes);
    return true;
}

static bool test_guest_range_resolve(void* user, u32 address, u32 size,
                                     DolGuestAddressSpace space,
                                     DolGuestResourceKind resource,
                                     DolGuestResolvedRange* out) {
    assert(user != NULL);
    assert(address == 0x80u);
    assert(size == 4u);
    assert(space == DOL_GUEST_ADDRESS_AUTO);
    assert(resource == DOL_GUEST_RESOURCE_TEXTURE);
    assert(out != NULL);
    out->data = user;
    out->available = 8u;
    return true;
}

static void test_set_guest_address_resolver(
    DolPlatformGuestAddressResolverFn resolve, void* user) {
    g_guest_resolver_sets++;
    g_guest_resolver_fn = resolve;
    g_guest_resolver_user = user;
}

static bool test_exi_transfer(void* user, DolExiTransfer* transfer) {
    assert(user == &g_exi_transfer_calls);
    g_exi_transfer_calls++;
    g_exi_last_transfer = *transfer;
    if (!transfer->dma && transfer->direction == DOL_EXI_TRANSFER_READ)
        *transfer->immediate_data = 0xA1B2C3D4u;
    return g_exi_complete_transfer;
}

static DolDiCommandResult test_di_command(void* user, DolDiCommand* command) {
    assert(user == &g_di_command_calls);
    g_di_command_calls++;
    g_di_last_command = *command;
    *command->immediate_data = 0x55667788u;
    return g_di_command_result;
}

/* External locked-cache-style memory backed big-endian by g_psq_external,
 * matching how the real runtime backs 0xE0000000 (the mmio bus routes psq
 * loads/stores through the external_read/write hooks, not a raw pointer). */
static u64 psq_external_read(CPUState* cpu, u32 ea, u8 size) {
    (void)cpu;
    const u32 base = 0xE0000000u;
    if (ea < base || (u64)(ea - base) + size > sizeof(g_psq_external))
        return 0;
    u64 value = 0;
    for (u8 i = 0; i < size; i++)
        value = (value << 8) | g_psq_external[(ea - base) + i];
    return value;
}

static void psq_external_write(CPUState* cpu, u32 ea, u64 value, u8 size) {
    (void)cpu;
    const u32 base = 0xE0000000u;
    g_psq_external_writes++;
    if (ea < base || (u64)(ea - base) + size > sizeof(g_psq_external))
        return;
    for (u8 i = 0; i < size; i++)
        g_psq_external[(ea - base) + (size - 1u - i)] = (u8)(value >> (i * 8u));
}

static bool mmio_read_false(void* user, CPUState* cpu, u32 ea, u8 size,
                            u64* value) {
    (void)user;
    (void)cpu;
    (void)ea;
    (void)size;
    (void)value;
    return false;
}

static bool mmio_read_test(void* user, CPUState* cpu, u32 ea, u8 size,
                           u64* value) {
    const u32 base = *(const u32*)user;
    assert(ea == base + 4u);
    assert(size == 4u);
    g_mmio_last_cpu = cpu;
    g_mmio_read_hits++;
    if (value != NULL)
        *value = 0xAABBCCDDu;
    return true;
}

static bool mmio_write_test(void* user, CPUState* cpu, u32 ea, u8 size,
                            u64 value) {
    const u32 base = *(const u32*)user;
    assert(ea == base + 8u);
    if (size != 2u)
        return false;
    g_mmio_last_cpu = cpu;
    g_mmio_write_hits++;
    g_mmio_last_write = value;
    return true;
}

static void test_guest_memory(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));

    DolGuestMemory memory;
    assert(dol_guest_memory_init(&memory, NULL));

    const u32 vm = memory.config.vm_base + 0x40u;
    const u32 lc = memory.config.locked_cache_base + 0x80u;
    u64 value = 0;

    assert(dol_guest_memory_write(&memory, vm, 4, 0x11223344u));
    assert(dol_guest_memory_read(&memory, vm, 4, &value));
    assert(value == 0x11223344u);

    assert(dol_guest_memory_write(&memory, lc, 4, 0xAABBCCDDu));
    assert(dol_guest_memory_read(&memory, lc, 4, &value));
    assert(value == 0xAABBCCDDu);

    mem_write32(&cpu, GC_RAM_BASE + 0x100u, 0xCAFEBABEu);
    dol_guest_memory_copy(&memory, &cpu, lc, GC_RAM_BASE + 0x100u, 4);
    dol_guest_memory_copy(&memory, &cpu, GC_RAM_BASE + 0x200u, lc, 4);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x200u) == 0xCAFEBABEu);

    u32 available = 0;
    assert(dol_guest_memory_pointer(&memory, &cpu, lc, &available) != NULL);
    assert(available == memory.config.locked_cache_size - 0x80u);
    assert(dol_guest_memory_pointer(&memory, &cpu, 0x100u, &available) ==
           cpu.ram + 0x100u);
    assert(available == cpu.ram_size - 0x100u);

    DolGuestAddressResolver resolver;
    DolGuestResolvedRange range;
    dol_guest_address_resolver_init(&resolver, &memory, &cpu);
    assert(dol_guest_address_resolver_resolve(
        &resolver, GC_RAM_BASE + 0x100u, 4u, DOL_GUEST_ADDRESS_VIRTUAL,
        DOL_GUEST_RESOURCE_DISPLAY_LIST, &range));
    assert(range.data == cpu.ram + 0x100u);
    assert(range.available == cpu.ram_size - 0x100u);
    assert(range.space == DOL_GUEST_ADDRESS_VIRTUAL);
    assert(range.resource == DOL_GUEST_RESOURCE_DISPLAY_LIST);

    assert(dol_guest_address_resolver_resolve(
        &resolver, 0x100u, 4u, DOL_GUEST_ADDRESS_PHYSICAL,
        DOL_GUEST_RESOURCE_VERTEX_ARRAY, &range));
    assert(range.data == cpu.ram + 0x100u);
    assert(range.available == cpu.ram_size - 0x100u);
    assert(range.space == DOL_GUEST_ADDRESS_PHYSICAL);
    assert(range.resource == DOL_GUEST_RESOURCE_VERTEX_ARRAY);

    assert(dol_guest_address_resolver_resolve(
        &resolver, lc, 4u, DOL_GUEST_ADDRESS_AUTO,
        DOL_GUEST_RESOURCE_TEXTURE, &range));
    assert(range.data == memory.locked_cache + 0x80u);
    assert(range.space == DOL_GUEST_ADDRESS_VIRTUAL);
    assert(range.resource == DOL_GUEST_RESOURCE_TEXTURE);

    assert(!dol_guest_address_resolver_resolve(
        &resolver, 0x100u, 4u, DOL_GUEST_ADDRESS_VIRTUAL,
        DOL_GUEST_RESOURCE_GENERIC, &range));
    assert(!dol_guest_address_resolver_resolve(
        &resolver, GC_RAM_BASE + 0x100u, 4u, DOL_GUEST_ADDRESS_PHYSICAL,
        DOL_GUEST_RESOURCE_GENERIC, &range));
    assert(!dol_guest_address_resolver_resolve(
        &resolver, 0x100u, 0u, DOL_GUEST_ADDRESS_PHYSICAL,
        DOL_GUEST_RESOURCE_GENERIC, &range));
    assert(!dol_guest_address_resolver_resolve(
        &resolver, cpu.ram_size - 2u, 4u, DOL_GUEST_ADDRESS_PHYSICAL,
        DOL_GUEST_RESOURCE_VERTEX_ARRAY, &range));

    u8 callback_bytes[8] = {0};
    dol_guest_address_resolver_init_callback(&resolver, test_guest_range_resolve,
                                             callback_bytes);
    assert(dol_guest_address_resolver_resolve(
        &resolver, 0x80u, 4u, DOL_GUEST_ADDRESS_AUTO,
        DOL_GUEST_RESOURCE_TEXTURE, &range));
    assert(range.data == callback_bytes);
    assert(range.address == 0x80u);
    assert(range.size == 4u);
    assert(range.available == 8u);
    assert(range.space == DOL_GUEST_ADDRESS_AUTO);
    assert(range.resource == DOL_GUEST_RESOURCE_TEXTURE);

    dol_guest_memory_shutdown(&memory);
    cpu_free(&cpu);
}

static void test_store_reservation(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));

    cpu.reserve_addr = GC_RAM_BASE + 0x100u;
    cpu.reserve_valid = true;
    mem_write32(&cpu, GC_RAM_UNCACHED + 0x11Cu, 0x12345678u);
    assert(!cpu.reserve_valid);

    cpu.reserve_addr = GC_RAM_BASE + 0x100u;
    cpu.reserve_valid = true;
    mem_write8(&cpu, GC_RAM_BASE + 0x120u, 0xABu);
    assert(cpu.reserve_valid);

    cpu_free(&cpu);
}

static u32 tex_image0(u16 width, u16 height, u32 format) {
    return ((u32)(width - 1u)) | ((u32)(height - 1u) << 10) |
           ((format & 0xFu) << 20);
}

static void fifo_u8(u8* fifo, u32* pos, u8 value) {
    fifo[(*pos)++] = value;
}

static void fifo_u16(u8* fifo, u32* pos, u16 value) {
    put_be16(fifo + *pos, value);
    *pos += 2u;
}

static void fifo_u32(u8* fifo, u32* pos, u32 value) {
    put_be32(fifo + *pos, value);
    *pos += 4u;
}

static void fifo_cp(u8* fifo, u32* pos, u8 reg, u32 value) {
    fifo_u8(fifo, pos, DOL_GX_CMD_LOAD_CP_REG);
    fifo_u8(fifo, pos, reg);
    fifo_u32(fifo, pos, value);
}

static void fifo_bp(u8* fifo, u32* pos, u8 reg, u32 value) {
    fifo_u8(fifo, pos, DOL_GX_CMD_LOAD_BP_REG);
    fifo_u32(fifo, pos, ((u32)reg << 24) | (value & 0x00FFFFFFu));
}

static void fifo_xf(u8* fifo, u32* pos, u16 base, const u32* values,
                    u8 count) {
    fifo_u8(fifo, pos, DOL_GX_CMD_LOAD_XF_REG);
    fifo_u32(fifo, pos, ((u32)(count - 1u) << 16) | base);
    for (u8 i = 0; i < count; ++i)
        fifo_u32(fifo, pos, values[i]);
}

static void fifo_indexed_xf(u8* fifo, u32* pos, u8 command, u16 index,
                            u16 base, u8 count) {
    fifo_u8(fifo, pos, command);
    fifo_u32(fifo, pos,
             ((u32)index << 16) | ((u32)(count - 1u) << 12) |
                 (base & 0x0FFFu));
}

static void fifo_call_dl(u8* fifo, u32* pos, u32 address, u32 size) {
    fifo_u8(fifo, pos, DOL_GX_CMD_CALL_DL);
    fifo_u32(fifo, pos, address);
    fifo_u32(fifo, pos, size);
}

static void fifo_draw_indexed_fixture(u8* fifo, u32* pos, u8 cmd) {
    fifo_u8(fifo, pos, cmd);
    fifo_u16(fifo, pos, 3u);
    const u8 verts[] = {
        0xAA, 0x02,
        0xBB, 0x05,
        0xCC, 0x01,
    };
    memcpy(fifo + *pos, verts, sizeof(verts));
    *pos += (u32)sizeof(verts);
}

static void test_gx_recomp_modules(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));

    DolGuestMemory memory;
    assert(dol_guest_memory_init(&memory, NULL));

    DolGuestAddressResolver resolver;
    dol_guest_address_resolver_init(&resolver, &memory, &cpu);

    DolGxRecompState gx;
    dol_gx_recomp_init(&gx, &resolver);

    const u32 dl_offset = 0x200u;
    for (u32 i = 0; i < 32u; ++i)
        cpu.ram[dl_offset + i] = (u8)(0x80u + i);

    DolGuestResolvedRange display_list;
    assert(dol_gx_recomp_resolve_display_list(
        &gx, GC_RAM_BASE + dl_offset, 32u, &display_list));
    assert(display_list.data == cpu.ram + dl_offset);
    assert(display_list.space == DOL_GUEST_ADDRESS_VIRTUAL);
    assert(display_list.resource == DOL_GUEST_RESOURCE_DISPLAY_LIST);

    assert(dol_gx_recomp_call_display_list(&gx, dl_offset, 32u, true));
    assert(dol_gx_recomp_fifo_size(&gx) == 32u);
    assert(memcmp(dol_gx_recomp_fifo_bytes(&gx), cpu.ram + dl_offset, 32u) ==
           0);
    assert(!dol_gx_recomp_resolve_display_list(
        &gx, GC_RAM_BASE + dl_offset + 1u, 32u, &display_list));
    assert(!dol_gx_recomp_resolve_display_list(
        &gx, GC_RAM_BASE + dl_offset, 31u, &display_list));

    const u32 array_base = 0x400u;
    assert(dol_gx_recomp_load_cp_reg(&gx, DOL_GX_CP_REG_ARRAYBASE, array_base));
    assert(dol_gx_recomp_load_cp_reg(&gx, DOL_GX_CP_REG_ARRAYSTRIDE, 12u));
    DolGxRecompResolvedArray array;
    assert(dol_gx_recomp_resolve_cp_array(&gx, 0u, 72u, &array));
    assert(array.range.data == cpu.ram + array_base);
    assert(array.range.space == DOL_GUEST_ADDRESS_PHYSICAL);
    assert(array.range.resource == DOL_GUEST_RESOURCE_VERTEX_ARRAY);
    assert(array.stride == 12u);
    assert(array.byte_span == 72u);
    assert(!dol_gx_recomp_resolve_cp_array(&gx, 2u, 72u, &array));

    const u8 verts8[] = {
        0xAA, 0x02, 0x00, 0x00,
        0xBB, 0x05, 0x00, 0x00,
        0xCC, 0x01, 0x00, 0x00,
    };
    u32 span = 0;
    assert(dol_gx_recomp_indexed_span(verts8, 4u, 3u, 1u, 1u, 12u, 12u,
                                      0u, &span));
    assert(span == 72u);

    const u8 verts16[] = {
        0x00, 0x00, 0x00, 0x03,
        0x00, 0x00, 0x00, 0x07,
    };
    assert(dol_gx_recomp_indexed_span(verts16, 4u, 2u, 2u, 2u, 16u, 8u,
                                      4u, &span));
    assert(span == 124u);
    assert(!dol_gx_recomp_indexed_span(verts8, 4u, 3u, 4u, 1u, 12u, 12u,
                                       0u, &span));

    assert(dol_gx_recomp_load_cp_reg(&gx, DOL_GX_CP_REG_VCD_LO,
                                     (1u << 0) | (2u << 9)));
    assert(dol_gx_recomp_load_cp_reg(&gx, DOL_GX_CP_REG_VCD_HI, 0u));
    assert(dol_gx_recomp_load_cp_reg(&gx, DOL_GX_CP_REG_VAT_GRP0,
                                     (1u << 0) | (4u << 1)));
    assert(dol_gx_recomp_derive_vertex_layout(&gx, 0u));
    assert(gx.vcd_lo_valid);
    assert(gx.vcd_hi_valid);
    assert(gx.vertex_layouts[0].valid);
    assert(gx.vertex_layouts[0].vertex_size == 2u);
    assert(gx.vertex_layouts[0].indexed_attr_count == 1u);
    assert(gx.vertex_layouts[0].indexed_attrs[0].attr == 0u);
    assert(gx.vertex_layouts[0].indexed_attrs[0].vertex_offset == 1u);
    assert(gx.vertex_layouts[0].indexed_attrs[0].index_size == 1u);
    assert(gx.vertex_layouts[0].indexed_attrs[0].element_size == 12u);

    u32 tex_size = 0;
    assert(dol_gx_recomp_texture_size(16u, 8u, 1u, &tex_size));
    assert(tex_size == 128u);
    assert(dol_gx_recomp_texture_size(8u, 8u, 0xEu, &tex_size));
    assert(tex_size == 32u);
    assert(!dol_gx_recomp_texture_size(16u, 8u, 7u, &tex_size));

    const u32 texture_base = 0x800u;
    const u32 image0 = tex_image0(16u, 8u, 1u);
    const u32 image3 = texture_base >> 5;
    DolGxRecompTexture texture;
    assert(dol_gx_recomp_resolve_texture_image(&gx, 1u, image0, image3,
                                               &texture));
    assert(texture.valid);
    assert(texture.slot == 1u);
    assert(texture.width == 16u);
    assert(texture.height == 8u);
    assert(texture.format == 1u);
    assert(texture.byte_size == 128u);
    assert(texture.range.data == cpu.ram + texture_base);
    assert(texture.range.resource == DOL_GUEST_RESOURCE_TEXTURE);

    const u32 tlut_base = 0x1000u;
    DolGxRecompTlut tlut;
    assert(dol_gx_recomp_resolve_tlut(&gx, 2u, tlut_base >> 5, 1u, 16u,
                                      &tlut));
    assert(tlut.valid);
    assert(tlut.slot == 2u);
    assert(tlut.byte_size == 32u);
    assert(tlut.range.data == cpu.ram + tlut_base);
    assert(tlut.range.resource == DOL_GUEST_RESOURCE_TLUT);

    DolGuestResolvedRange copy_dst;
    assert(dol_gx_recomp_resolve_copy_destination(&gx, 0x1200u, 64u,
                                                  &copy_dst));
    assert(copy_dst.data == cpu.ram + 0x1200u);
    assert(copy_dst.resource == DOL_GUEST_RESOURCE_COPY_DESTINATION);
    assert(!dol_gx_recomp_resolve_copy_destination(&gx, cpu.ram_size - 8u,
                                                   64u, &copy_dst));

    assert(dol_gx_recomp_note_bp_reg(&gx, DOL_GX_BP_REG_GENMODE,
                                     3u << 14));
    assert(gx.cull_all);
    assert(dol_gx_recomp_note_bp_reg(&gx, DOL_GX_BP_REG_GENMODE, 0u));
    assert(!gx.cull_all);
    assert(dol_gx_recomp_note_xf_load(&gx, 0x0040u, 4u));
    assert(gx.last_xf_base == 0x0040u);
    assert(gx.last_xf_count == 4u);

    u32 trace_count = 0;
    const DolGxRecompTraceEvent* trace =
        dol_gx_recomp_trace_events(&gx, &trace_count);
    assert(trace != NULL);
    assert(trace_count >= 12u);
    bool saw_fifo = false;
    bool saw_array = false;
    bool saw_texture = false;
    bool saw_tlut = false;
    bool saw_copy = false;
    bool saw_cull = false;
    bool saw_xf = false;
    for (u32 i = 0; i < trace_count; ++i) {
        saw_fifo |= trace[i].kind == DOL_GX_RECOMP_EVENT_FIFO_BYTES;
        saw_array |= trace[i].kind == DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE;
        saw_texture |= trace[i].kind == DOL_GX_RECOMP_EVENT_TEXTURE;
        saw_tlut |= trace[i].kind == DOL_GX_RECOMP_EVENT_TLUT;
        saw_copy |= trace[i].kind == DOL_GX_RECOMP_EVENT_COPY_DESTINATION;
        saw_cull |= trace[i].kind == DOL_GX_RECOMP_EVENT_CULL_ALL;
        saw_xf |= trace[i].kind == DOL_GX_RECOMP_EVENT_XF_LOAD;
    }
    assert(saw_fifo);
    assert(saw_array);
    assert(saw_texture);
    assert(saw_tlut);
    assert(saw_copy);
    assert(saw_cull);
    assert(saw_xf);

    dol_guest_memory_shutdown(&memory);
    cpu_free(&cpu);
}

static void test_gx_recomp_all_module_replay(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));

    DolGuestMemory memory;
    assert(dol_guest_memory_init(&memory, NULL));

    DolGuestAddressResolver resolver;
    dol_guest_address_resolver_init(&resolver, &memory, &cpu);

    DolGxRecompState gx;
    dol_gx_recomp_init(&gx, &resolver);

    const u32 dl_offset = 0x200u;
    const u32 array_base = 0x400u;
    const u32 xf_array_base = 0x600u;
    const u32 texture_base = 0x800u;
    const u32 tlut_base = 0x1000u;
    const u32 copy_base = 0x1200u;
    for (u32 i = 0; i < 256u; ++i) {
        cpu.ram[array_base + i] = (u8)(0x10u + i);
        cpu.ram[xf_array_base + i] = (u8)(0x80u + i);
        cpu.ram[texture_base + i] = (u8)(0x40u + i);
        cpu.ram[tlut_base + i] = (u8)(0x20u + i);
        cpu.ram[copy_base + i] = (u8)(0x60u + i);
    }

    u8 dl[96] = {0};
    u32 dl_pos = 0;
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_GENMODE, 3u << 14);
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_LOAD_TLUT0, tlut_base >> 5);
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_LOAD_TLUT1,
            0x20u | (1u << 10));
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_TX_SETTLUT + 1u,
            0x20u | (1u << 10));
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_TX_SETIMAGE0 + 1u,
            tex_image0(16u, 8u, 1u));
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_TX_SETIMAGE3 + 1u,
            texture_base >> 5);
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_EFB_TL, 0u);
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_EFB_WH,
            (7u << 10) | 7u);
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_EFB_ADDR, copy_base >> 5);
    fifo_bp(dl, &dl_pos, DOL_GX_BP_REG_TRIGGER_EFB_COPY, 2u << 3);
    const u32 xf_value = 0x12345678u;
    fifo_xf(dl, &dl_pos, 0x1008u, &xf_value, 1u);
    fifo_indexed_xf(dl, &dl_pos, 0x20u, 1u, 0x0000u, 12u);
    fifo_draw_indexed_fixture(dl, &dl_pos, 0x80u);
    assert(dl_pos <= sizeof(dl));
    while (dl_pos < sizeof(dl))
        fifo_u8(dl, &dl_pos, 0u);
    memcpy(cpu.ram + dl_offset, dl, sizeof(dl));

    u8 stream[64] = {0};
    u32 pos = 0;
    fifo_cp(stream, &pos, DOL_GX_CP_REG_VCD_LO, (1u << 0) | (2u << 9));
    fifo_cp(stream, &pos, DOL_GX_CP_REG_VCD_HI, 0u);
    fifo_cp(stream, &pos, DOL_GX_CP_REG_VAT_GRP0, (1u << 0) | (4u << 1));
    fifo_cp(stream, &pos, DOL_GX_CP_REG_ARRAYBASE, array_base);
    fifo_cp(stream, &pos, DOL_GX_CP_REG_ARRAYSTRIDE, 12u);
    fifo_cp(stream, &pos, DOL_GX_CP_REG_ARRAYBASE + 12u, xf_array_base);
    fifo_cp(stream, &pos, DOL_GX_CP_REG_ARRAYSTRIDE + 12u, 48u);
    fifo_call_dl(stream, &pos, dl_offset, sizeof(dl));

    assert(dol_gx_recomp_replay_fifo(&gx, stream, pos));
    assert(dol_gx_recomp_fifo_size(&gx) == pos + sizeof(dl));
    assert(gx.cull_all);
    assert(gx.textures[1].valid);
    assert(gx.textures[1].physical_base == texture_base);
    assert(gx.textures[1].byte_size == 128u);
    assert(gx.textures[1].range.data == cpu.ram + texture_base);
    assert(gx.texture_tlut_valid[1]);
    assert(gx.texture_tlut_tmem_offset[1] == 0x20u);
    assert(gx.texture_tlut_format[1] == 1u);
    assert(gx.tmem_tluts[0x20u].valid);
    assert(gx.tmem_tluts[0x20u].physical_base == tlut_base);
    assert(gx.tmem_tluts[0x20u].byte_size == 32u);
    assert(gx.tmem_tluts[0x20u].range.data == cpu.ram + tlut_base);
    assert(gx.copy.range_valid);
    assert(gx.copy.physical_base == copy_base);
    assert(gx.copy.byte_size == 64u);
    assert(gx.copy.range.data == cpu.ram + copy_base);
    assert(gx.last_xf_base == 0x0000u);
    assert(gx.last_xf_count == 12u);

    u32 trace_count = 0;
    const DolGxRecompTraceEvent* trace =
        dol_gx_recomp_trace_events(&gx, &trace_count);
    bool saw_display_list = false;
    bool saw_fifo = false;
    bool saw_array = false;
    bool saw_texture = false;
    bool saw_tlut = false;
    bool saw_copy = false;
    bool saw_cull = false;
    bool saw_xf = false;
    bool saw_draw = false;
    bool saw_indexed_span = false;
    bool saw_indexed_xf = false;
    for (u32 i = 0; i < trace_count; ++i) {
        saw_display_list |=
            trace[i].kind == DOL_GX_RECOMP_EVENT_DISPLAY_LIST;
        saw_fifo |= trace[i].kind == DOL_GX_RECOMP_EVENT_FIFO_BYTES;
        saw_array |= trace[i].kind == DOL_GX_RECOMP_EVENT_CP_ARRAY_BASE;
        saw_texture |= trace[i].kind == DOL_GX_RECOMP_EVENT_TEXTURE;
        saw_tlut |= trace[i].kind == DOL_GX_RECOMP_EVENT_TLUT;
        saw_copy |= trace[i].kind == DOL_GX_RECOMP_EVENT_COPY_DESTINATION;
        saw_cull |= trace[i].kind == DOL_GX_RECOMP_EVENT_CULL_ALL;
        saw_xf |= trace[i].kind == DOL_GX_RECOMP_EVENT_XF_LOAD;
        saw_draw |= trace[i].kind == DOL_GX_RECOMP_EVENT_DRAW;
        saw_indexed_span |=
            trace[i].kind == DOL_GX_RECOMP_EVENT_INDEXED_SPAN &&
            trace[i].a == 0u && trace[i].b == 72u;
        saw_indexed_xf |=
            trace[i].kind == DOL_GX_RECOMP_EVENT_INDEXED_XF_LOAD &&
            trace[i].a == 12u && trace[i].b == 1u &&
            trace[i].c == 0u && trace[i].d == 12u;
    }
    assert(saw_display_list);
    assert(saw_fifo);
    assert(saw_array);
    assert(saw_texture);
    assert(saw_tlut);
    assert(saw_copy);
    assert(saw_cull);
    assert(saw_xf);
    assert(saw_draw);
    assert(saw_indexed_span);
    assert(saw_indexed_xf);

    dol_guest_memory_shutdown(&memory);
    cpu_free(&cpu);
}

static void test_mmio_bus(void) {
    DolMmioBus bus;
    CPUState cpu;
    const u32 base = 0xCC010000u;
    const u32 fallback_base = base + 4u;
    u64 value = 0;

    assert(cpu_init(&cpu));
    dol_mmio_bus_init(&bus);

    assert(!dol_mmio_bus_register(NULL, base, 0x10u, mmio_read_test,
                                  mmio_write_test, (void*)&base));
    assert(!dol_mmio_bus_register(&bus, base, 0u, mmio_read_test,
                                  mmio_write_test, (void*)&base));
    assert(!dol_mmio_bus_register(&bus, 0xFFFFFFF0u, 0x20u, mmio_read_test,
                                  mmio_write_test, (void*)&base));
    assert(!dol_mmio_bus_register(&bus, base, 0x10u, NULL, NULL,
                                  (void*)&base));

    assert(dol_mmio_bus_register(&bus, base, 0x10u, mmio_read_false,
                                 NULL, (void*)&base));
    assert(dol_mmio_bus_register(&bus, base, 0x10u, mmio_read_test,
                                 mmio_write_test, (void*)&base));
    assert(dol_mmio_bus_register(&bus, fallback_base, 0x08u,
                                 mmio_read_test, NULL,
                                 (void*)&fallback_base));

    assert(dol_mmio_bus_contains(&bus, base));
    assert(dol_mmio_bus_contains(&bus, base + 0x0Fu));
    assert(!dol_mmio_bus_contains(&bus, base + 0x10u));

    g_mmio_read_hits = 0;
    g_mmio_last_cpu = NULL;
    assert(dol_mmio_bus_read(&bus, &cpu, base + 4u, 4u, &value));
    assert(value == 0xAABBCCDDu);
    assert(g_mmio_read_hits == 1u);
    assert(g_mmio_last_cpu == &cpu);

    assert(!dol_mmio_bus_read(&bus, &cpu, base + 0x0Fu, 2u, &value));

    g_mmio_write_hits = 0;
    g_mmio_last_cpu = NULL;
    g_mmio_last_write = 0;
    assert(dol_mmio_bus_write(&bus, &cpu, base + 8u, 2u, 0x1122u));
    assert(g_mmio_write_hits == 1u);
    assert(g_mmio_last_cpu == &cpu);
    assert(g_mmio_last_write == 0x1122u);
    assert(!dol_mmio_bus_write(&bus, &cpu, base + 8u, 4u, 0x11223344u));

    DolMmioBus full;
    dol_mmio_bus_init(&full);
    for (u32 i = 0; i < DOL_MMIO_BUS_MAX_REGIONS; i++)
        assert(dol_mmio_bus_register(&full, 0xCC020000u + i * 0x10u,
                                     0x10u, mmio_read_false, NULL, NULL));
    assert(!dol_mmio_bus_register(&full, 0xCC030000u, 0x10u,
                                  mmio_read_false, NULL, NULL));

    cpu_free(&cpu);
}

static void test_loader(void) {
    const char* path = "gxruntime-loader-test.dol";
    remove(path);

    u8 dol[DOL_HEADER_SIZE + 8];
    memset(dol, 0, sizeof(dol));
    put_be32(dol + 0x00, DOL_HEADER_SIZE);
    put_be32(dol + 0x48, GC_RAM_BASE + 0x3100u);
    put_be32(dol + 0x90, 4u);
    put_be32(dol + 0x1C, DOL_HEADER_SIZE + 4u);
    put_be32(dol + 0x64, GC_RAM_BASE + 0x3104u);
    put_be32(dol + 0xAC, 4u);
    put_be32(dol + 0xD8, GC_RAM_BASE + 0x3100u);
    put_be32(dol + 0xDC, 0x20u);
    put_be32(dol + 0xE0, GC_RAM_BASE + 0x3100u);
    put_be32(dol + DOL_HEADER_SIZE, 0x11223344u);
    put_be32(dol + DOL_HEADER_SIZE + 4u, 0x55667788u);

    FILE* file = fopen(path, "wb");
    assert(file != NULL);
    assert(fwrite(dol, 1, sizeof(dol), file) == sizeof(dol));
    assert(fclose(file) == 0);

    CPUState cpu;
    assert(cpu_init(&cpu));
    memset(cpu.ram + 0x3100u, 0xA5, 0x40u);

    DolLayout layout;
    assert(dol_load_into_ram(&cpu, path, &layout));
    assert(layout.entry_point == GC_RAM_BASE + 0x3100u);
    assert(layout.text_address[0] == GC_RAM_BASE + 0x3100u);
    assert(layout.data_address[0] == GC_RAM_BASE + 0x3104u);
    assert(layout.bss_address == GC_RAM_BASE + 0x3100u);
    assert(layout.bss_size == 0x20u);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x3100u) == 0x11223344u);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x3104u) == 0x55667788u);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x3108u) == 0u);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x311Cu) == 0u);

    cpu_free(&cpu);
    remove(path);
}

static void test_loader_failures(void) {
    const char* path = "gxruntime-loader-fail.dol";

    CPUState cpu;
    assert(cpu_init(&cpu));

    DolLayout layout;
    memset(&layout, 0, sizeof(layout));

    /* 1) Missing file: fopen returns NULL; load fails cleanly. */
    remove("gxruntime-loader-missing.dol");
    assert(!dol_load_into_ram(&cpu, "gxruntime-loader-missing.dol", &layout));

    /* 2) Truncated DOL: smaller than DOL_HEADER_SIZE. */
    {
        u8 tiny[DOL_HEADER_SIZE - 1u];
        memset(tiny, 0, sizeof(tiny));
        remove(path);
        FILE* file = fopen(path, "wb");
        assert(file != NULL);
        assert(fwrite(tiny, 1, sizeof(tiny), file) == sizeof(tiny));
        assert(fclose(file) == 0);
        assert(!dol_load_into_ram(&cpu, path, &layout));
        remove(path);
    }

    /* 3) Section file range out of bounds: text[0] offset exceeds file size. */
    {
        u8 dol[DOL_HEADER_SIZE + 8u];
        memset(dol, 0, sizeof(dol));
        /* text[0] offset points past end of file, but address+size fit RAM. */
        put_be32(dol + 0x00u, DOL_HEADER_SIZE + 0x200u);
        put_be32(dol + 0x48u, GC_RAM_BASE + 0x1000u);
        put_be32(dol + 0x90u, 4u);
        put_be32(dol + DOL_HEADER_SIZE, 0x11223344u);
        remove(path);
        FILE* file = fopen(path, "wb");
        assert(file != NULL);
        assert(fwrite(dol, 1, sizeof(dol), file) == sizeof(dol));
        assert(fclose(file) == 0);
        assert(!dol_load_into_ram(&cpu, path, &layout));
        remove(path);
    }

    /* 4) Section address does not fit in RAM (offset+size overflows). */
    {
        u8 dol[DOL_HEADER_SIZE + 4u];
        memset(dol, 0, sizeof(dol));
        /* text[0] address = top of RAM; size=4 does not fit. */
        put_be32(dol + 0x00u, DOL_HEADER_SIZE);
        put_be32(dol + 0x48u, GC_RAM_BASE + cpu.ram_size);
        put_be32(dol + 0x90u, 4u);
        put_be32(dol + DOL_HEADER_SIZE, 0x11223344u);
        remove(path);
        FILE* file = fopen(path, "wb");
        assert(file != NULL);
        assert(fwrite(dol, 1, sizeof(dol), file) == sizeof(dol));
        assert(fclose(file) == 0);
        assert(!dol_load_into_ram(&cpu, path, &layout));
        remove(path);
    }

    /* 5) Section address below GC_RAM_BASE (uncached/base address forms). */
    {
        u8 dol[DOL_HEADER_SIZE + 4u];
        memset(dol, 0, sizeof(dol));
        /* text[0] address below 0x80000000; rejected by ram_offset. */
        put_be32(dol + 0x00u, DOL_HEADER_SIZE);
        put_be32(dol + 0x48u, 0x00001000u);
        put_be32(dol + 0x90u, 4u);
        put_be32(dol + DOL_HEADER_SIZE, 0x11223344u);
        remove(path);
        FILE* file = fopen(path, "wb");
        assert(file != NULL);
        assert(fwrite(dol, 1, sizeof(dol), file) == sizeof(dol));
        assert(fclose(file) == 0);
        assert(!dol_load_into_ram(&cpu, path, &layout));
        remove(path);
    }

    /* 6) BSS does not fit in RAM. */
    {
        u8 dol[DOL_HEADER_SIZE];
        memset(dol, 0, sizeof(dol));
        put_be32(dol + 0xD8u, GC_RAM_BASE + cpu.ram_size);
        put_be32(dol + 0xDCu, 0x1000u);
        put_be32(dol + 0xE0u, GC_RAM_BASE);
        remove(path);
        FILE* file = fopen(path, "wb");
        assert(file != NULL);
        assert(fwrite(dol, 1, sizeof(dol), file) == sizeof(dol));
        assert(fclose(file) == 0);
        assert(!dol_load_into_ram(&cpu, path, &layout));
        remove(path);
    }

    /* 7) Valid DOL with no sections: all zero sections, only BSS. */
    {
        u8 dol[DOL_HEADER_SIZE];
        memset(dol, 0, sizeof(dol));
        put_be32(dol + 0xD8u, GC_RAM_BASE + 0x1000u);
        put_be32(dol + 0xDCu, 0x100u);
        put_be32(dol + 0xE0u, GC_RAM_BASE + 0x1000u);
        remove(path);
        FILE* file = fopen(path, "wb");
        assert(file != NULL);
        assert(fwrite(dol, 1, sizeof(dol), file) == sizeof(dol));
        assert(fclose(file) == 0);
        memset(&layout, 0, sizeof(layout));
        assert(dol_load_into_ram(&cpu, path, &layout));
        assert(layout.bss_size == 0x100u);
        assert(layout.entry_point == GC_RAM_BASE + 0x1000u);
        assert(mem_read32(&cpu, GC_RAM_BASE + 0x1000u) == 0u);
        assert(mem_read32(&cpu, GC_RAM_BASE + 0x10FCu) == 0u);
        remove(path);
    }

    remove(path);
    cpu_free(&cpu);
}

static void test_boot_globals(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));

    DolLayout layout;
    memset(&layout, 0, sizeof(layout));
    layout.bss_address = GC_RAM_BASE + 0x4000u;
    layout.bss_size = 0x2000u;
    layout.entry_point = GC_RAM_BASE + 0x3100u;

    boot_setup_os_globals(&cpu, &layout);

    assert(mem_read32(&cpu, 0x80000020u) == 0x0D15EA5Eu);
    assert(mem_read32(&cpu, 0x80000024u) == 1u);
    assert(mem_read32(&cpu, 0x80000028u) == 0x01800000u);
    assert(mem_read32(&cpu, 0x8000002Cu) == 1u);
    assert(mem_read32(&cpu, 0x80000030u) == GC_RAM_BASE + 0x26000u);
    assert(mem_read32(&cpu, 0x80000034u) == 0x817FEC60u);
    assert(mem_read32(&cpu, 0x80000038u) == 0u);
    assert(mem_read32(&cpu, 0x8000003Cu) == 0u);
    assert(mem_read32(&cpu, 0x800000CCu) == 0u);
    assert(mem_read32(&cpu, 0x800000F8u) == 0x09A7EC80u);
    assert(mem_read32(&cpu, 0x800000FCu) == 0x1CF7C580u);
    assert(cpu.gpr[1] == 0x817FFF00u);
    assert(mem_read32(&cpu, cpu.gpr[1]) == 0u);
    assert(mem_read32(&cpu, cpu.gpr[1] + 4u) == 0u);
    assert(cpu.msr == 0x00002000u);

    cpu_free(&cpu);
}

static void test_aram(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));
    aram_free();
    aram_init();

    assert(aram_contains(ARAM_BASE));
    assert(aram_contains(ARAM_BASE + ARAM_SIZE - 1u));
    assert(!aram_contains(ARAM_BASE + ARAM_SIZE));

    aram_write(ARAM_BASE + 0x20u, 0x11223344u, 4);
    assert(aram_read(ARAM_BASE + 0x20u, 4) == 0x11223344u);
    assert(aram_read(0x20u, 4) == 0x11223344u);
    aram_write(0x24u, 0xABCDu, 2);
    assert(aram_read(ARAM_BASE + 0x24u, 2) == 0xABCDu);

    mem_write32(&cpu, GC_RAM_BASE + 0x180u, 0xDEADBEEFu);
    aram_dma_to_aram(cpu.ram, GC_RAM_BASE + 0x180u, 0x40u, 4);
    assert(aram_read(0x40u, 4) == 0xDEADBEEFu);
    memset(cpu.ram + 0x190u, 0, 4);
    aram_dma_to_ram(cpu.ram, GC_RAM_BASE + 0x190u, 0x40u, 4);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x190u) == 0xDEADBEEFu);

    aram_free();
    cpu_free(&cpu);
}

static void test_aram_boundaries(void) {
    aram_free();
    aram_init();

    /* 1) Wrap-around: 4-byte value straddling the top of ARAM. */
    u32 wrap_addr = ARAM_BASE + ARAM_SIZE - 2u;
    aram_write(ARAM_BASE + ARAM_SIZE - 2u, 0x11223344u, 4);
    /* read back across the wrap boundary; bytes 2,3 land at offset 0,1 */
    assert(aram_read(wrap_addr, 4) == 0x11223344u);

    /* 2) The wrapped bytes are readable via raw offsets 0 and 1. */
    assert(aram_read(0u, 1) == 0x33u);
    assert(aram_read(1u, 1) == 0x44u);

    /* 3) Uninitialized ARAM reads as zero (calloc backing). */
    aram_free();
    aram_init();
    assert(aram_read(ARAM_BASE + 0x100u, 8) == 0u);
    assert(aram_read(0u, 4) == 0u);

    /* 4) DMA straddling the wrap boundary. */
    CPUState cpu;
    assert(cpu_init(&cpu));
    mem_write32(&cpu, GC_RAM_BASE + 0x100u, 0xDEADBEEFu);
    aram_dma_to_aram(cpu.ram, GC_RAM_BASE + 0x100u, ARAM_SIZE - 2u, 4);
    assert(aram_read(ARAM_SIZE - 2u, 4) == 0xDEADBEEFu);
    /* The wrapped low bytes land at ARAM offsets 0 and 1. */
    assert(aram_read(0u, 1) == 0xBEu);
    assert(aram_read(1u, 1) == 0xEFu);

    /* 5) DMA reverse direction wraps bytes into RAM correctly. */
    aram_write(ARAM_SIZE - 1u, 0xCAFEBABEu, 4);
    memset(cpu.ram + 0x200u, 0, 4);
    aram_dma_to_ram(cpu.ram, GC_RAM_BASE + 0x200u, ARAM_SIZE - 1u, 4);
    assert(mem_read32(&cpu, GC_RAM_BASE + 0x200u) == 0xCAFEBABEu);

    cpu_free(&cpu);
    aram_free();
    aram_init();
    aram_free();
}

static void write_sparse_block(FILE* file, u32 offset, const u8* bytes, size_t size) {
    assert(fseek(file, (long)offset, SEEK_SET) == 0);
    assert(fwrite(bytes, 1, size, file) == size);
}

static void test_dvd_fst(void) {
    const char* path = "gxruntime-dvd-test.iso";
    remove(path);

    enum {
        fst_offset = 0x500,
        file_offset = 0x800,
        entry_count = 3,
    };
    const u8 payload[] = {0x10, 0x32, 0x54, 0x76, 0x98, 0xBA};
    const char strings[] = "\0assets\0runtime.bin";
    u8 header[0x440];
    u8 fst[entry_count * 12u + sizeof(strings)];
    memset(header, 0, sizeof(header));
    memset(fst, 0, sizeof(fst));

    put_be32(header + 0x1Cu, 0xC2339F3Du);
    put_be32(header + 0x424u, fst_offset);
    put_be32(header + 0x428u, sizeof(fst));

    put_be32(fst + 0, 0x01000000u);
    put_be32(fst + 4, 0u);
    put_be32(fst + 8, entry_count);
    put_be32(fst + 12, 0x01000001u);
    put_be32(fst + 16, 0u);
    put_be32(fst + 20, entry_count);
    put_be32(fst + 24, 8u);
    put_be32(fst + 28, file_offset);
    put_be32(fst + 32, sizeof(payload));
    memcpy(fst + entry_count * 12u, strings, sizeof(strings));

    FILE* file = fopen(path, "wb");
    assert(file != NULL);
    write_sparse_block(file, 0, header, sizeof(header));
    write_sparse_block(file, fst_offset, fst, sizeof(fst));
    write_sparse_block(file, file_offset, payload, sizeof(payload));
    assert(fclose(file) == 0);

    dvd_close_image();
    assert(dvd_open_image(path));
    assert(dvd_image_ready());
    assert(dvd_path_to_entrynum("/") == 0);
    assert(dvd_path_to_entrynum("assets/RUNTIME.BIN") == 2);
    assert(dvd_path_to_entrynum("./assets/runtime.bin") == 2);
    assert(dvd_path_to_entrynum("missing.bin") == -1);

    u32 start = 0;
    u32 length = 0;
    assert(dvd_entry_info(2, &start, &length));
    assert(start == file_offset);
    assert(length == sizeof(payload));
    assert(!dvd_entry_info(1, &start, &length));

    CPUState cpu;
    assert(cpu_init(&cpu));
    dvd_read_to_guest(&cpu, GC_RAM_BASE + 0x500u, start, length);
    assert(memcmp(cpu.ram + 0x500u, payload, sizeof(payload)) == 0);
    dvd_read_to_guest(&cpu, GC_RAM_UNCACHED + 0x520u, start, length);
    assert(memcmp(cpu.ram + 0x520u, payload, sizeof(payload)) == 0);

    cpu_free(&cpu);
    dvd_close_image();
    remove(path);
}

static void test_dvd_fst_edges(void) {
    const char* path = "gxruntime-dvd-edges.iso";
    remove(path);

    enum {
        fst_off = 0x500,
        sub_files_off = 0x800,
        top_off = 0x900,
        entry_count = 4,
    };
    const u8 payload_a[] = {0xAA, 0xBB, 0xCC};
    const u8 payload_top[] = {0x77};
    const char strings[] =
        "\0"        /* 0: root */
        "sub\0"     /* 1 */
        "file_a\0"  /* 5 */
        "top\0"     /* 12 */
        ;
    u8 header[0x440];
    u8 fst[entry_count * 12u + sizeof(strings)];
    memset(header, 0, sizeof(header));
    memset(fst, 0, sizeof(fst));

    put_be32(header + 0x1Cu, 0xC2339F3Du);
    put_be32(header + 0x424u, fst_off);
    put_be32(header + 0x428u, sizeof(fst));

    /* entry 0: root dir; parent=0, next=entry_count */
    put_be32(fst + 0,  0x01000000u);
    put_be32(fst + 4,  0u);
    put_be32(fst + 8,  entry_count);
    /* entry 1: dir "sub"; parent=0, next=3 (only entry 2 is its child) */
    put_be32(fst + 12, 0x01000001u);
    put_be32(fst + 16, 0u);
    put_be32(fst + 20, 3u);
    /* entry 2: file "file_a" inside sub, stroff=5 */
    put_be32(fst + 24, 5u);
    put_be32(fst + 28, sub_files_off);
    put_be32(fst + 32, sizeof(payload_a));
    /* entry 3: file "top" at root level, stroff=12 */
    put_be32(fst + 36, 12u);
    put_be32(fst + 40, top_off);
    put_be32(fst + 44, sizeof(payload_top));
    memcpy(fst + entry_count * 12u, strings, sizeof(strings));

    FILE* file = fopen(path, "wb");
    assert(file != NULL);
    write_sparse_block(file, 0, header, sizeof(header));
    write_sparse_block(file, fst_off, fst, sizeof(fst));
    write_sparse_block(file, sub_files_off, payload_a, sizeof(payload_a));
    write_sparse_block(file, top_off, payload_top, sizeof(payload_top));
    assert(fclose(file) == 0);

    dvd_close_image();
    assert(dvd_open_image(path));
    assert(dvd_image_ready());

    /* 1) '..' navigation: sub/../top == top, sub/.. == root. */
    assert(dvd_path_to_entrynum("sub/file_a") == 2);
    assert(dvd_path_to_entrynum("sub/../top") == 3);
    assert(dvd_path_to_entrynum("sub/..") == 0);
    assert(dvd_path_to_entrynum("sub/../sub/../sub/..") == 0);

    /* 2) Case-insensitive matching. */
    assert(dvd_path_to_entrynum("SUB/FILE_A") == 2);
    assert(dvd_path_to_entrynum("Top") == 3);

    /* 3) Out-of-range entries and directory entrynum rejected. */
    u32 start = 0, length = 0;
    assert(!dvd_entry_info(entry_count, &start, &length));
    assert(!dvd_entry_info(-1, &start, &length));
    assert(!dvd_entry_info(1, &start, &length));  /* directory */

    /* 4) Read straddling image EOF: payload bytes + zero-fill tail. */
    CPUState cpu;
    assert(cpu_init(&cpu));
    dvd_read_to_guest(&cpu, GC_RAM_BASE + 0x500u, sub_files_off, 8u);
    assert(cpu.ram[0x500] == payload_a[0]);
    assert(cpu.ram[0x502] == payload_a[2]);
    assert(cpu.ram[0x503] == 0u);
    assert(cpu.ram[0x507] == 0u);

    /* 5) Read far past image end: fully zero-filled (short read). */
    memset(cpu.ram + 0x600u, 0xA5, 8);
    dvd_read_to_guest(&cpu, GC_RAM_BASE + 0x600u, 0x100000u, 4u);
    assert(cpu.ram[0x600] == 0u);
    assert(cpu.ram[0x603] == 0u);

    /* 6) Zero-length read is a no-op (leaves destination untouched). */
    memset(cpu.ram + 0x700u, 0x5A, 8);
    dvd_read_to_guest(&cpu, GC_RAM_BASE + 0x700u, sub_files_off, 0u);
    assert(cpu.ram[0x700] == 0x5Au);
    assert(cpu.ram[0x707] == 0x5Au);

    /* 7) Read to uncached RAM mirror path also lands bytes correctly. */
    dvd_read_to_guest(&cpu, GC_RAM_UNCACHED + 0x500u, top_off,
                      sizeof(payload_top));
    assert(cpu.ram[0x500] == payload_top[0]);

    cpu_free(&cpu);
    dvd_close_image();
    remove(path);

    /* 8) Wrong magic: open_image rejects. */
    {
        const char* bad = "gxruntime-dvd-badmagic.iso";
        remove(bad);
        u8 hdr[0x440];
        memset(hdr, 0xCC, sizeof(hdr));
        FILE* f = fopen(bad, "wb");
        assert(f != NULL);
        assert(fwrite(hdr, 1, sizeof(hdr), f) == sizeof(hdr));
        assert(fclose(f) == 0);
        assert(!dvd_open_image(bad));
        assert(!dvd_image_ready());
        remove(bad);
    }

    /* 9) Truncated header: file smaller than 0x440 bytes. */
    {
        const char* bad = "gxruntime-dvd-truncated.iso";
        remove(bad);
        u8 hdr[0x100];
        memset(hdr, 0, sizeof(hdr));
        put_be32(hdr + 0x1Cu, 0xC2339F3Du);
        FILE* f = fopen(bad, "wb");
        assert(f != NULL);
        assert(fwrite(hdr, 1, sizeof(hdr), f) == sizeof(hdr));
        assert(fclose(f) == 0);
        assert(!dvd_open_image(bad));
        remove(bad);
    }

    /* 10) NULL or empty path: open_image rejects. */
    assert(!dvd_open_image(NULL));
    assert(!dvd_open_image(""));
    assert(!dvd_image_ready());
}

static void test_psq_quantized_paths(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));
    cpu.hid2 = PPC_HID2_PSE | PPC_HID2_LSQE;

    cpu.gqr[5] = 0x00070007u;
    mem_write16(&cpu, GC_RAM_BASE + 0x100u, 0xFFFEu);
    mem_write16(&cpu, GC_RAM_BASE + 0x102u, 0x0003u);
    ppc_psq_load(&cpu, 1, GC_RAM_BASE + 0x100u, false, 5, false, 0);
    assert(cpu.exception == 0);
    assert(cpu.fpr[1] == -2.0);
    assert(cpu.ps1[1] == 3.0);

    memset(g_psq_external, 0, sizeof(g_psq_external));
    g_psq_external[0] = 0xFFu;
    g_psq_external[1] = 0xFEu;
    g_psq_external[2] = 0x00u;
    g_psq_external[3] = 0x03u;
    cpu.external_read = psq_external_read;
    cpu.external_write = psq_external_write;
    ppc_psq_load(&cpu, 4, 0xE0000000u, false, 5, false, 0);
    assert(cpu.exception == 0);
    assert(cpu.fpr[4] == -2.0);
    assert(cpu.ps1[4] == 3.0);

    memset(g_psq_external, 0, sizeof(g_psq_external));
    g_psq_external[0] = 0x3Fu;
    g_psq_external[1] = 0xC0u;
    g_psq_external[2] = 0x00u;
    g_psq_external[3] = 0x00u;
    g_psq_external[4] = 0xC0u;
    g_psq_external[5] = 0x10u;
    g_psq_external[6] = 0x00u;
    g_psq_external[7] = 0x00u;
    ppc_psq_load(&cpu, 5, 0xE0000000u, false, 0, false, 0);
    assert(cpu.exception == 0);
    assert(cpu.fpr[5] == 1.5);
    assert(cpu.ps1[5] == -2.25);

    memset(g_psq_external, 0, sizeof(g_psq_external));
    g_psq_external_writes = 0;
    cpu.external_write = psq_external_write;
    cpu.fpr[6] = 1.5;
    cpu.ps1[6] = -2.25;
    ppc_psq_store(&cpu, 6, 0xE0000000u, false, 0, false, 0);
    assert(g_psq_external[0] == 0x3Fu);
    assert(g_psq_external[1] == 0xC0u);
    assert(g_psq_external[2] == 0x00u);
    assert(g_psq_external[3] == 0x00u);
    assert(g_psq_external[4] == 0xC0u);
    assert(g_psq_external[5] == 0x10u);
    assert(g_psq_external[6] == 0x00u);
    assert(g_psq_external[7] == 0x00u);
    /* Both PS lanes store through the external_write hook (2 word writes) -
     * psq now uses the normal mem access path, matching how the runtime
     * backs 0xE0000000 on the mmio bus (the old raw-pointer fast path that
     * bypassed the hook is retired for Dolphin-exact lockstep). */
    assert(g_psq_external_writes == 2);

    cpu.gqr[6] = 0x3D043D04u;
    cpu.fpr[2] = 2040.0;
    cpu.ps1[2] = -8.0;
    ppc_psq_store(&cpu, 2, GC_RAM_BASE + 0x110u, false, 6, false, 0);
    assert(cpu.exception == 0);
    assert(mem_read16(&cpu, GC_RAM_BASE + 0x110u) == 0xFF00u);

    memset(g_psq_external, 0, sizeof(g_psq_external));
    g_psq_external_writes = 0;
    cpu.external_write = psq_external_write;
    cpu.fpr[3] = 16.0;
    cpu.ps1[3] = 24.0;
    ppc_psq_store(&cpu, 3, 0xE0000000u, false, 6, false, 0);
    assert(g_psq_external[0] == 2u);
    assert(g_psq_external[1] == 3u);
    assert(g_psq_external_writes == 2);

    cpu_free(&cpu);
}

static void test_platform_dispatch(void) {
    dol_platform_reset();
    g_guest_resolver_sets = 0;
    g_guest_resolver_fn = NULL;
    g_guest_resolver_user = NULL;
    g_platform_array_guest_calls = 0;
    g_platform_texture_guest_calls = 0;
    g_platform_tlut_guest_calls = 0;
    g_platform_copy_guest_calls = 0;

    const DolPlatformOps ops = {
        .gx_write = test_gx_write,
        .set_array_guest = test_set_array_guest,
        .load_texture_guest = test_load_texture_guest,
        .load_tlut_guest = test_load_tlut_guest,
        .set_copy_destination_guest = test_set_copy_destination_guest,
        .set_guest_address_resolver = test_set_guest_address_resolver,
        .audio_push = test_audio_push,
    };
    const s16 samples[4] = {0};
    const u8 gfx_data[64] = {0};
    int resolver_token = 7;

    dol_platform_install(&ops);
    assert(dol_platform_available());
    dol_platform_set_guest_address_resolver(test_guest_resolve,
                                            &resolver_token);
    assert(g_guest_resolver_sets == 1u);
    assert(g_guest_resolver_fn == test_guest_resolve);
    assert(g_guest_resolver_user == &resolver_token);
    const void* resolved = NULL;
    u32 available = 0;
    assert(g_guest_resolver_fn(g_guest_resolver_user, 0x40u, 4u,
                               DOL_GUEST_ADDRESS_PHYSICAL,
                               DOL_GUEST_RESOURCE_VERTEX_ARRAY, &resolved,
                               &available));
    assert(resolved != NULL);
    assert(available == 4u);
    dol_platform_gx_write(0x12345678u, 4);
    dol_platform_set_array_guest(3u, GC_RAM_BASE + 0x120u, gfx_data,
                                 sizeof(gfx_data), 12u);
    dol_platform_load_texture_guest(2u, GC_RAM_BASE + 0x200u, gfx_data, 32u,
                                    16u, 6u, 4u, true, 0xAAu, 0xBBu);
    dol_platform_load_tlut_guest(1u, GC_RAM_BASE + 0x300u, gfx_data, 2u, 16u,
                                 0xCCu, 0xDDu);
    dol_platform_set_copy_destination_guest(GC_RAM_BASE + 0x400u, gfx_data);
    dol_platform_audio_push(samples, 2);
    assert(g_gx_writes == 1);
    assert(g_platform_array_guest_calls == 1u);
    assert(g_platform_texture_guest_calls == 1u);
    assert(g_platform_tlut_guest_calls == 1u);
    assert(g_platform_copy_guest_calls == 1u);
    assert(g_audio_frames == 2);

    dol_platform_reset();
    assert(!dol_platform_available());
    assert(g_guest_resolver_sets == 2u);
    assert(g_guest_resolver_fn == NULL);
    assert(g_guest_resolver_user == NULL);
    dol_platform_gx_write(0x12345678u, 4);
    assert(g_gx_writes == 1);
}

static void test_event_clock(void) {
    enum {
        EVENT_AI = 1,
        EVENT_VI = 2,
        EVENT_DVD = 3,
    };

    DolEventClock clock;
    dol_event_clock_init(&clock);
    assert(dol_event_clock_now(&clock) == 0);
    assert(!dol_event_clock_pop_due(&clock, NULL, NULL));
    assert(dol_event_clock_schedule(&clock, EVENT_AI, 25, 25));
    assert(dol_event_clock_schedule(&clock, EVENT_VI, 100, 100));
    assert(dol_event_clock_schedule(&clock, EVENT_DVD, 60, 0));
    assert(dol_event_clock_is_scheduled(&clock, EVENT_AI));

    u64 next = 0;
    assert(dol_event_clock_next_deadline(&clock, &next));
    assert(next == 25);
    dol_event_clock_advance(&clock, 59);

    u32 id = 0;
    u64 deadline = 0;
    assert(dol_event_clock_pop_due(&clock, &id, &deadline));
    assert(id == EVENT_AI);
    assert(deadline == 25);
    assert(dol_event_clock_pop_due(&clock, &id, &deadline));
    assert(id == EVENT_AI);
    assert(deadline == 50);
    assert(!dol_event_clock_pop_due(&clock, NULL, NULL));

    dol_event_clock_advance(&clock, 41);
    const u32 expected_ids[] = {EVENT_DVD, EVENT_AI, EVENT_AI, EVENT_VI};
    const u64 expected_deadlines[] = {60, 75, 100, 100};
    for (u32 i = 0; i < 4; i++) {
        assert(dol_event_clock_pop_due(&clock, &id, &deadline));
        assert(id == expected_ids[i]);
        assert(deadline == expected_deadlines[i]);
    }
    assert(!dol_event_clock_is_scheduled(&clock, EVENT_DVD));
    assert(dol_event_clock_is_scheduled(&clock, EVENT_AI));
    assert(dol_event_clock_is_scheduled(&clock, EVENT_VI));

    assert(dol_event_clock_cancel(&clock, EVENT_AI));
    assert(!dol_event_clock_is_scheduled(&clock, EVENT_AI));
    assert(!dol_event_clock_cancel(&clock, EVENT_AI));
    assert(dol_event_clock_next_deadline(&clock, &next));
    assert(next == 200);
}

static void test_vi_clock(void) {
    DolViClock vi;
    dol_vi_clock_init(&vi);
    dol_vi_clock_configure(&vi, 350000u, 60u, 40500000ull);
    assert(dol_vi_clock_now(&vi) == 0);
    assert(dol_vi_clock_work_units_per_retrace(&vi) == 350000u);
    assert(dol_vi_clock_refresh_hz(&vi) == 60u);
    assert(dol_vi_clock_timebase_ticks_per_retrace(&vi) == 675000u);

    dol_vi_clock_advance(&vi, 349999u);
    assert(!dol_vi_clock_pop_retrace(&vi, NULL));
    dol_vi_clock_advance(&vi, 1u);
    u64 ticks = 0;
    assert(dol_vi_clock_pop_retrace(&vi, &ticks));
    assert(ticks == 675000u);
    assert(!dol_vi_clock_pop_retrace(&vi, NULL));

    dol_vi_clock_advance(&vi, 700000u);
    assert(dol_vi_clock_pop_retrace(&vi, &ticks));
    assert(ticks == 675000u);
    assert(dol_vi_clock_pop_retrace(&vi, &ticks));
    assert(ticks == 675000u);
    assert(!dol_vi_clock_pop_retrace(&vi, NULL));

    dol_vi_clock_configure(&vi, 0, 0, 0);
    assert(dol_vi_clock_work_units_per_retrace(&vi) == 1u);
    assert(dol_vi_clock_refresh_hz(&vi) == DOL_VI_DEFAULT_REFRESH_HZ);
    assert(dol_vi_clock_timebase_ticks_per_retrace(&vi) ==
           DOL_VI_DEFAULT_TIMEBASE_HZ / DOL_VI_DEFAULT_REFRESH_HZ);
}

static void test_interrupts(void) {
    DolInterrupts interrupts;
    dol_interrupts_init(&interrupts);

    assert(dol_interrupts_mmio_contains(DOL_PI_INTERRUPT_CAUSE));
    assert(dol_interrupts_mmio_contains(DOL_VI_BASE + DOL_VI_DI0_OFF));
    assert(dol_interrupts_mmio_contains(DOL_PE_INTERRUPT_STATUS));
    assert(!dol_interrupts_mmio_contains(0xCC004000u));

    assert(dol_interrupts_pi_cause(&interrupts) ==
           DOL_PI_CAUSE_RST_BUTTON);
    assert(!dol_interrupts_external_pending(&interrupts));

    dol_interrupts_mmio_write(&interrupts, DOL_PI_INTERRUPT_MASK, 4,
                              DOL_PI_CAUSE_VI | DOL_PI_CAUSE_SI |
                                  DOL_PI_CAUSE_PE_FINISH |
                                  DOL_PI_CAUSE_DSP);
    assert(dol_interrupts_pi_mask(&interrupts) ==
           (DOL_PI_CAUSE_VI | DOL_PI_CAUSE_SI |
            DOL_PI_CAUSE_PE_FINISH | DOL_PI_CAUSE_DSP));

    dol_interrupts_assert_vi_retrace(&interrupts);
    assert((dol_interrupts_pi_cause(&interrupts) & DOL_PI_CAUSE_VI) == 0);
    dol_interrupts_mmio_write(&interrupts, DOL_VI_BASE + DOL_VI_DI0_OFF, 2,
                              0x1000u);
    assert((dol_interrupts_pi_cause(&interrupts) & DOL_PI_CAUSE_VI) == 0);
    dol_interrupts_assert_vi_retrace(&interrupts);
    assert(dol_interrupts_mmio_read(&interrupts, DOL_VI_BASE + DOL_VI_DI0_OFF,
                                    2) == 0x9000u);
    assert((dol_interrupts_pi_cause(&interrupts) & DOL_PI_CAUSE_VI) != 0);
    assert(dol_interrupts_external_pending(&interrupts));

    dol_interrupts_mmio_write(&interrupts, DOL_VI_BASE + DOL_VI_DI0_OFF, 2,
                              0x1000u);
    assert((dol_interrupts_pi_cause(&interrupts) & DOL_PI_CAUSE_VI) == 0);

    dol_interrupts_commit_pe_finish(&interrupts);
    assert((dol_interrupts_pi_cause(&interrupts) &
            DOL_PI_CAUSE_PE_FINISH) != 0);
    assert(dol_interrupts_mmio_read(&interrupts, DOL_PE_INTERRUPT_STATUS, 2) ==
           DOL_PE_FINISH_ACK_BIT);
    dol_interrupts_mmio_write(&interrupts, DOL_PE_INTERRUPT_STATUS, 2,
                              DOL_PE_FINISH_ACK_BIT);
    assert((dol_interrupts_pi_cause(&interrupts) &
            DOL_PI_CAUSE_PE_FINISH) == 0);

    dol_interrupts_set_source(&interrupts, DOL_PI_CAUSE_DSP, true);
    assert((dol_interrupts_pi_cause(&interrupts) & DOL_PI_CAUSE_DSP) != 0);
    assert(dol_interrupts_external_pending(&interrupts));
    dol_interrupts_mmio_write(&interrupts, DOL_PI_INTERRUPT_CAUSE, 4,
                              DOL_PI_CAUSE_DSP);
    assert((dol_interrupts_pi_cause(&interrupts) & DOL_PI_CAUSE_DSP) == 0);
    assert(!dol_interrupts_external_pending(&interrupts));
}

static void test_si_device(void) {
    DolSiDevice si;
    dol_si_init(&si);

    assert(dol_si_mmio_contains(DOL_SI_BASE));
    assert(dol_si_mmio_contains(DOL_SI_BASE + DOL_SI_REGISTER_BYTES - 1u));
    assert(!dol_si_mmio_contains(DOL_SI_BASE + DOL_SI_REGISTER_BYTES));
    assert(!dol_si_interrupt_pending(&si));

    dol_si_mmio_write(&si, DOL_SI_BASE + DOL_SI_POLL_OFF, 4,
                      0x00F00001u);
    assert(dol_si_mmio_read(&si, DOL_SI_BASE + DOL_SI_POLL_OFF, 4) ==
           0x00F00001u);

    dol_si_mmio_write(&si, DOL_SI_BASE + DOL_SI_COMCSR_OFF, 4,
                      DOL_SI_RDSTINTMSK);
    dol_si_latch_poll(&si, 0x5u);
    u32 comcsr = (u32)dol_si_mmio_read(
        &si, DOL_SI_BASE + DOL_SI_COMCSR_OFF, 4);
    assert((comcsr & (DOL_SI_RDSTINT | DOL_SI_RDSTINTMSK)) ==
           (DOL_SI_RDSTINT | DOL_SI_RDSTINTMSK));
    assert(dol_si_interrupt_pending(&si));
    assert(dol_si_mmio_read(&si, DOL_SI_BASE + DOL_SI_STATUS_OFF, 4) ==
           0x20002000u);

    // COMCSR reads do not consume RDST. Each channel's input read does.
    (void)dol_si_mmio_read(&si, DOL_SI_BASE + 0x04u, 4);
    assert(dol_si_interrupt_pending(&si));
    (void)dol_si_mmio_read(&si, DOL_SI_BASE + 0x1Cu, 4);
    assert(!dol_si_interrupt_pending(&si));
    assert(((u32)dol_si_mmio_read(
                &si, DOL_SI_BASE + DOL_SI_COMCSR_OFF, 4) &
            DOL_SI_RDSTINT) == 0u);

    // TSTART completes synchronously, clears busy, and latches TCINT.
    dol_si_mmio_write(&si, DOL_SI_BASE + DOL_SI_COMCSR_OFF, 4,
                      DOL_SI_TCINTMSK | DOL_SI_TSTART | 0x00020502u);
    comcsr = (u32)dol_si_mmio_read(
        &si, DOL_SI_BASE + DOL_SI_COMCSR_OFF, 4);
    assert((comcsr & DOL_SI_TSTART) == 0u);
    assert((comcsr & (DOL_SI_TCINT | DOL_SI_TCINTMSK)) ==
           (DOL_SI_TCINT | DOL_SI_TCINTMSK));
    assert((comcsr & 0x00007F06u) == 0x00000502u);
    assert(dol_si_interrupt_pending(&si));
    dol_si_mmio_write(&si, DOL_SI_BASE + DOL_SI_COMCSR_OFF, 4,
                      DOL_SI_TCINT | DOL_SI_TCINTMSK);
    assert(!dol_si_interrupt_pending(&si));

    // IO buffer and non-special channel registers remain big-endian MMIO.
    dol_si_mmio_write(&si, DOL_SI_BASE + DOL_SI_IO_BUFFER_OFF, 4,
                      0x12345678u);
    assert(dol_si_mmio_read(&si, DOL_SI_BASE + DOL_SI_IO_BUFFER_OFF, 2) ==
           0x1234u);
}

static void test_exi_device(void) {
    DolExi exi;
    CPUState cpu;
    cpu_init(&cpu);
    dol_exi_init(&exi);
    dol_exi_set_transfer_callback(&exi, test_exi_transfer,
                                  &g_exi_transfer_calls);
    g_exi_transfer_calls = 0;
    g_exi_complete_transfer = true;

    assert(dol_exi_mmio_contains(DOL_EXI_BASE));
    assert(dol_exi_mmio_contains(DOL_EXI_BASE +
                                 DOL_EXI_REGISTER_BYTES - 1u));
    assert(!dol_exi_mmio_contains(DOL_EXI_BASE +
                                  DOL_EXI_REGISTER_BYTES));
    assert(dol_exi_mmio_read(&exi, DOL_EXI_BASE, 4) ==
           DOL_EXI_STATUS_EXTINT);
    assert(dol_exi_mmio_read(
               &exi, DOL_EXI_BASE + DOL_EXI_CHANNEL_STRIDE, 4) ==
           (DOL_EXI_STATUS_EXTINT | (1u << 7u)));

    // Channel 0 immediate read, four bytes, chip select 2.
    dol_exi_mmio_write(
        &exi, &cpu, DOL_EXI_BASE + DOL_EXI_STATUS_OFF, 4,
        DOL_EXI_STATUS_TCINTMASK | (2u << 7u) |
            DOL_EXI_STATUS_ROMDIS | DOL_EXI_STATUS_EXTINT);
    assert((dol_exi_mmio_read(&exi, DOL_EXI_BASE, 4) &
            (DOL_EXI_STATUS_CHIP_SELECT_MASK |
             DOL_EXI_STATUS_ROMDIS | DOL_EXI_STATUS_EXTINT)) ==
           ((2u << 7u) | DOL_EXI_STATUS_ROMDIS));
    dol_exi_mmio_write(
        &exi, &cpu, DOL_EXI_BASE + DOL_EXI_CONTROL_OFF, 4,
        DOL_EXI_CONTROL_TSTART | (3u << 4u));
    assert(g_exi_transfer_calls == 1u);
    assert(g_exi_last_transfer.cpu == &cpu);
    assert(g_exi_last_transfer.channel == 0u);
    assert(g_exi_last_transfer.chip_select == 2u);
    assert(g_exi_last_transfer.direction == DOL_EXI_TRANSFER_READ);
    assert(!g_exi_last_transfer.dma);
    assert(g_exi_last_transfer.length == 4u);
    assert(dol_exi_mmio_read(
               &exi, DOL_EXI_BASE + DOL_EXI_IMMEDIATE_DATA_OFF, 4) ==
           0xA1B2C3D4u);
    assert((dol_exi_mmio_read(
                &exi, DOL_EXI_BASE + DOL_EXI_CONTROL_OFF, 4) &
            DOL_EXI_CONTROL_TSTART) == 0u);
    assert(dol_exi_interrupt_pending(&exi));
    dol_exi_mmio_write(
        &exi, &cpu, DOL_EXI_BASE + DOL_EXI_STATUS_OFF, 4,
        DOL_EXI_STATUS_TCINTMASK | DOL_EXI_STATUS_TCINT);
    assert(!dol_exi_interrupt_pending(&exi));

    // Channel 2 delayed DMA write retains TSTART until explicit completion.
    const u32 ch2 = DOL_EXI_BASE + 2u * DOL_EXI_CHANNEL_STRIDE;
    dol_exi_mmio_write(&exi, &cpu, ch2 + DOL_EXI_DMA_ADDRESS_OFF, 4,
                       0x00123440u);
    dol_exi_mmio_write(&exi, &cpu, ch2 + DOL_EXI_DMA_LENGTH_OFF, 4, 0x80u);
    g_exi_complete_transfer = false;
    dol_exi_mmio_write(
        &exi, &cpu, ch2 + DOL_EXI_CONTROL_OFF, 4,
        DOL_EXI_CONTROL_TSTART | DOL_EXI_CONTROL_DMA |
            (DOL_EXI_TRANSFER_WRITE << 2u));
    assert(g_exi_transfer_calls == 2u);
    assert(g_exi_last_transfer.channel == 2u);
    assert(g_exi_last_transfer.dma);
    assert(g_exi_last_transfer.direction == DOL_EXI_TRANSFER_WRITE);
    assert(g_exi_last_transfer.dma_address == 0x00123440u);
    assert(g_exi_last_transfer.length == 0x80u);
    assert((dol_exi_mmio_read(&exi, ch2 + DOL_EXI_CONTROL_OFF, 4) &
            DOL_EXI_CONTROL_TSTART) != 0u);
    dol_exi_complete_transfer(&exi, 2u);
    assert((dol_exi_mmio_read(&exi, ch2 + DOL_EXI_CONTROL_OFF, 4) &
            DOL_EXI_CONTROL_TSTART) == 0u);

    // Device and insertion sources obey their masks and W1C status writes.
    dol_exi_mmio_write(
        &exi, &cpu, DOL_EXI_BASE + DOL_EXI_STATUS_OFF, 4,
        DOL_EXI_STATUS_EXIINTMASK | DOL_EXI_STATUS_EXTINTMASK);
    dol_exi_set_device_interrupt(&exi, 0u, true);
    dol_exi_set_device_present(&exi, 0u, true, true);
    assert(dol_exi_interrupt_pending(&exi));
    assert((dol_exi_mmio_read(&exi, DOL_EXI_BASE, 4) &
            DOL_EXI_STATUS_EXT) != 0u);
    dol_exi_mmio_write(
        &exi, &cpu, DOL_EXI_BASE + DOL_EXI_STATUS_OFF, 4,
        DOL_EXI_STATUS_EXIINTMASK | DOL_EXI_STATUS_EXTINTMASK |
            DOL_EXI_STATUS_EXIINT | DOL_EXI_STATUS_EXTINT);
    assert(!dol_exi_interrupt_pending(&exi));
    cpu_free(&cpu);
}

static void test_di_device(void) {
    DolDi di;
    CPUState cpu;
    cpu_init(&cpu);
    dol_di_init(&di);
    dol_di_set_command_callback(&di, test_di_command,
                                &g_di_command_calls);
    g_di_command_calls = 0;

    assert(dol_di_mmio_contains(DOL_DI_BASE));
    assert(dol_di_mmio_contains(DOL_DI_BASE + DOL_DI_REGISTER_BYTES - 1u));
    assert(!dol_di_mmio_contains(DOL_DI_BASE + DOL_DI_REGISTER_BYTES));
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_CONFIG_OFF, 4) == 1u);
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_COVER_OFF, 4) ==
           DOL_DI_COVER_OPEN);
    dol_di_mmio_write(&di, &cpu, DOL_DI_BASE + DOL_DI_CONFIG_OFF, 4, 9u);
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_CONFIG_OFF, 4) == 1u);

    dol_di_set_disc_present(&di, true);
    assert((dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_COVER_OFF, 4) &
            (DOL_DI_COVER_OPEN | DOL_DI_COVER_INT)) ==
           DOL_DI_COVER_INT);
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_COVER_OFF, 4,
        DOL_DI_COVER_INT_MASK | DOL_DI_COVER_INT);
    assert(!dol_di_interrupt_pending(&di));
    dol_di_set_disc_present(&di, false);
    assert(dol_di_interrupt_pending(&di));
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_COVER_OFF, 4,
        DOL_DI_COVER_INT_MASK | DOL_DI_COVER_INT);
    assert(!dol_di_interrupt_pending(&di));

    const u32 commands[3] = {0xA8000000u, 0x00001234u, 0x00000080u};
    for (u32 i = 0; i < 3u; i++)
        dol_di_mmio_write(&di, &cpu,
                          DOL_DI_BASE + DOL_DI_COMMAND_0_OFF + i * 4u,
                          4, commands[i]);
    dol_di_mmio_write(&di, &cpu, DOL_DI_BASE + DOL_DI_DMA_ADDRESS_OFF, 4,
                      0xFC12345Fu);
    dol_di_mmio_write(&di, &cpu, DOL_DI_BASE + DOL_DI_DMA_LENGTH_OFF, 4,
                      0x123u);
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_DMA_ADDRESS_OFF, 4) ==
           0x00123440u);
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_DMA_LENGTH_OFF, 4) ==
           0x120u);

    g_di_command_result = DOL_DI_COMMAND_COMPLETE;
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_STATUS_OFF, 4,
        DOL_DI_STATUS_TCINTMASK);
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_CONTROL_OFF, 4,
        DOL_DI_CONTROL_TSTART | DOL_DI_CONTROL_DMA);
    assert(g_di_command_calls == 1u);
    assert(g_di_last_command.cpu == &cpu);
    assert(memcmp(g_di_last_command.command, commands, sizeof(commands)) == 0);
    assert(g_di_last_command.dma);
    assert(!g_di_last_command.write);
    assert(g_di_last_command.dma_address == 0x00123440u);
    assert(g_di_last_command.dma_length == 0x120u);
    assert(dol_di_mmio_read(
               &di, DOL_DI_BASE + DOL_DI_IMMEDIATE_DATA_OFF, 4) ==
           0x55667788u);
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_DMA_ADDRESS_OFF, 4) ==
           0x00123560u);
    assert(dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_DMA_LENGTH_OFF, 4) ==
           0u);
    assert(dol_di_interrupt_pending(&di));
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_STATUS_OFF, 4,
        DOL_DI_STATUS_TCINTMASK | DOL_DI_STATUS_TCINT);
    assert(!dol_di_interrupt_pending(&di));

    // Deferred command can be aborted, producing a mask-gated BRK interrupt.
    g_di_command_result = DOL_DI_COMMAND_DEFERRED;
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_CONTROL_OFF, 4,
        DOL_DI_CONTROL_TSTART);
    assert((dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_CONTROL_OFF, 4) &
            DOL_DI_CONTROL_TSTART) != 0u);
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_STATUS_OFF, 4,
        DOL_DI_STATUS_BREAK | DOL_DI_STATUS_BRKINTMASK);
    assert(dol_di_interrupt_pending(&di));
    assert((dol_di_mmio_read(&di, DOL_DI_BASE + DOL_DI_CONTROL_OFF, 4) &
            DOL_DI_CONTROL_TSTART) == 0u);
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_STATUS_OFF, 4,
        DOL_DI_STATUS_BRKINTMASK | DOL_DI_STATUS_BRKINT);
    assert(!dol_di_interrupt_pending(&di));

    // Unsupported commands fail explicitly instead of silently succeeding.
    dol_di_set_command_callback(&di, NULL, NULL);
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_STATUS_OFF, 4,
        DOL_DI_STATUS_DEINTMASK);
    dol_di_mmio_write(
        &di, &cpu, DOL_DI_BASE + DOL_DI_CONTROL_OFF, 4,
        DOL_DI_CONTROL_TSTART);
    assert(dol_di_interrupt_pending(&di));
    cpu_free(&cpu);
}

static void test_audio_dma(void) {
    DolAudioDma dma;
    dol_audio_dma_init(&dma);
    dol_audio_dma_set_work_rate(&dma, 4000000u);
    assert(dma.work_units_per_chunk == 1000u);
    dol_audio_dma_set_vi_clock(&dma, 350000u, 60u);
    assert(dol_audio_dma_sample_rate(&dma) == DOL_AUDIO_DMA_32KHZ);
    assert(dma.work_units_per_chunk == 5250u);
    dol_audio_dma_set_sample_rate(&dma, DOL_AUDIO_DMA_48KHZ);
    assert(dol_audio_dma_sample_rate(&dma) == DOL_AUDIO_DMA_48KHZ);
    assert(dma.work_units_per_chunk == 3500u);
    dol_audio_dma_set_sample_rate(&dma, DOL_AUDIO_DMA_32KHZ);
    assert(dma.work_units_per_chunk == 5250u);

    dol_audio_dma_set_source(&dma, 0x00100000u);
    dol_audio_dma_write_control(&dma, DOL_AUDIO_DMA_ENABLE | 20u);
    assert(dol_audio_dma_interrupt_pending(&dma));
    dol_audio_dma_ack_interrupt(&dma);
    assert(dol_audio_dma_blocks_left(&dma) == 19u);

    for (u32 block = 0; block < 20u; block++) {
        for (u32 work = 1; work < 5250u; work++)
            assert(!dol_audio_dma_poll(&dma, NULL));
        u32 source = 0;
        assert(dol_audio_dma_poll(&dma, &source));
        assert(source == 0x00100000u + block * 32u);
    }
    assert(dol_audio_dma_interrupt_pending(&dma));
    assert(dol_audio_dma_blocks_left(&dma) == 19u);

    dol_audio_dma_write_control(&dma, 0);
    assert(!dol_audio_dma_poll(&dma, NULL));
}

static void test_audio_device(void) {
    const DolPlatformOps ops = {
        .audio_set_sample_rate = test_audio_set_sample_rate,
    };
    dol_platform_install(&ops);

    DolAudioDma dma;
    dol_audio_dma_init(&dma);

    u64 value = 0;

    // AI control register initializes to AISFR|AIDFR (AID 32 kHz), matching the
    // apploader value Strikers read (0x42) and Dolphin's AIDFR-set == 32 kHz.
    dol_audio_dma_ai_mmio_read(&dma, DOL_AUDIO_DMA_AI_CONTROL_OFF, 4, &value);
    assert(value == DOL_AUDIO_DMA_AI_CONTROL_INIT);
    assert(dol_audio_dma_sample_rate(&dma) == DOL_AUDIO_DMA_32KHZ);

    // AIDFR cleared -> AID 48 kHz; platform HAL is notified exactly once.
    g_platform_rate_calls = 0;
    dol_audio_dma_ai_mmio_write(&dma, DOL_AUDIO_DMA_AI_CONTROL_OFF, 4,
                                DOL_AUDIO_DMA_AI_AISFR_BIT);
    assert(dol_audio_dma_sample_rate(&dma) == DOL_AUDIO_DMA_48KHZ);
    assert(g_platform_sample_rate == DOL_AUDIO_DMA_48KHZ);
    assert(g_platform_rate_calls == 1u);

    // Same control re-written -> debounced, no platform notification.
    dol_audio_dma_ai_mmio_write(&dma, DOL_AUDIO_DMA_AI_CONTROL_OFF, 4,
                                DOL_AUDIO_DMA_AI_AISFR_BIT);
    assert(g_platform_rate_calls == 1u);

    // AIDFR set again -> back to 32 kHz, platform notified once.
    dol_audio_dma_ai_mmio_write(&dma, DOL_AUDIO_DMA_AI_CONTROL_OFF, 4,
                                DOL_AUDIO_DMA_AI_CONTROL_INIT);
    assert(dol_audio_dma_sample_rate(&dma) == DOL_AUDIO_DMA_32KHZ);
    assert(g_platform_rate_calls == 2u);

    // AI volume register (offset 4) is a plain passthrough; never decoded.
    dol_audio_dma_ai_mmio_write(&dma, 0x04u, 4, 0x12345678u);
    dol_audio_dma_ai_mmio_read(&dma, 0x04u, 4, &value);
    assert(value == 0x12345678u);

    // DSP DMA source latches from AUDIO_DMA_START_HI/LO. The high half keeps
    // the low 10 bits; the low half keeps bits [11:5].
    dol_audio_dma_dsp_mmio_write(&dma, DOL_AUDIO_DMA_DSP_DMA_START_HI_OFF,
                                 2, 0xFFFFu);
    dol_audio_dma_dsp_mmio_write(&dma, DOL_AUDIO_DMA_DSP_DMA_START_LO_OFF,
                                 2, 0xFFFFu);
    assert(dma.source_address == (0x03FF0000u | 0xFFE0u));

    // AUDIO_DMA_CONTROL_LEN arms 20 blocks; blocks_left reads back (count-1).
    dol_audio_dma_dsp_mmio_write(&dma, DOL_AUDIO_DMA_DSP_DMA_CONTROL_OFF,
                                 2, DOL_AUDIO_DMA_ENABLE | 20u);
    assert(dol_audio_dma_interrupt_pending(&dma));
    assert(dol_audio_dma_blocks_left(&dma) == 19u);
    dol_audio_dma_dsp_mmio_read(&dma, DOL_AUDIO_DMA_DSP_DMA_BLOCKS_LEFT_OFF,
                                2, &value);
    assert(value == 19u);

    // DSP control read merges the AID interrupt status bit into the image.
    dol_audio_dma_dsp_mmio_read(&dma, DOL_AUDIO_DMA_DSP_CONTROL_OFF, 2,
                                &value);
    assert((value & DOL_AUDIO_DMA_DSP_AID_INT_BIT) != 0);

    // PI source is pending only while the AID mask is enabled.
    assert(!dol_audio_dma_dsp_interrupt_pending(&dma));
    dol_audio_dma_dsp_mmio_write(&dma, DOL_AUDIO_DMA_DSP_CONTROL_OFF, 2,
                                 DOL_AUDIO_DMA_DSP_AID_MSK_BIT);
    assert(dol_audio_dma_dsp_interrupt_pending(&dma));

    // Writing the AID status bit acknowledges the interrupt.
    dol_audio_dma_dsp_mmio_write(&dma, DOL_AUDIO_DMA_DSP_CONTROL_OFF, 2,
                                 DOL_AUDIO_DMA_DSP_AID_INT_BIT |
                                     DOL_AUDIO_DMA_DSP_AID_MSK_BIT);
    assert(!dol_audio_dma_interrupt_pending(&dma));
    dol_audio_dma_dsp_mmio_read(&dma, DOL_AUDIO_DMA_DSP_CONTROL_OFF, 2,
                                &value);
    assert((value & DOL_AUDIO_DMA_DSP_AID_INT_BIT) == 0);
    assert((value & DOL_AUDIO_DMA_DSP_AID_MSK_BIT) != 0);
    assert(!dol_audio_dma_dsp_interrupt_pending(&dma));

    // Non-special DSP offsets are plain passthrough.
    dol_audio_dma_dsp_mmio_write(&dma, 0x10u, 4, 0xDEADBEEFu);
    dol_audio_dma_dsp_mmio_read(&dma, 0x10u, 4, &value);
    assert(value == 0xDEADBEEFu);

    dol_audio_dma_write_control(&dma, 0);
    dol_audio_dma_ack_interrupt(&dma);
    dol_platform_reset();
}

static void test_headless_backend(void) {
    DolHeadlessBackend backend;
    dol_headless_backend_init(&backend);
    assert(!dol_platform_available());

    dol_headless_backend_install(&backend);
    assert(dol_platform_available());
    assert(!dol_platform_should_quit());

    // Presentation contract: present/mark_gx_begin/configure_vi are recorded.
    dol_platform_present();
    dol_platform_present();
    dol_platform_mark_gx_begin();
    dol_platform_configure_vi(1u, 640u, 480u, 480u, 720u, 480u);
    assert(backend.present_count == 2u);
    assert(backend.begin_count == 1u);
    assert(backend.configure_vi_count == 1u);
    assert(backend.vi.tv_mode == 1u);
    assert(backend.vi.fb_width == 640u);
    assert(backend.vi.vi_width == 720u);

    // should_quit flag is honored.
    backend.should_quit = true;
    assert(dol_platform_should_quit());

    // Graphics ops are pure no-ops: they must not raise the recording or crash,
    // and they cannot affect the settled contracts captured here.
    dol_platform_gx_write(0xDEADBEEFu, 4);
    dol_platform_set_array(0, NULL, 0, 0);
    dol_platform_set_array_guest(0, GC_RAM_BASE, NULL, 0, 0);
    dol_platform_load_texture(0, NULL, 0, 0, 0, 0, false, 0, 0);
    dol_platform_load_texture_guest(0, GC_RAM_BASE, NULL, 0, 0, 0, 0, false, 0,
                                    0);
    dol_platform_load_tlut(0, NULL, 0, 0, 0, 0);
    dol_platform_load_tlut_guest(0, GC_RAM_BASE, NULL, 0, 0, 0, 0);
    dol_platform_set_copy_destination(NULL);
    dol_platform_set_copy_destination_guest(GC_RAM_BASE, NULL);
    assert(backend.present_count == 2u);
    assert(backend.begin_count == 1u);

    // Input contract: scripted pad state is returned verbatim.
    backend.pad_mask = 0x1u;
    backend.pad[0].button = 0x0100u;
    backend.pad[0].stick_x = -5;
    backend.pad[0].stick_y = 7;
    DolPadState pads[4];
    memset(pads, 0xFF, sizeof pads);
    u32 connected = dol_platform_pad_read(pads);
    assert(connected == 0x1u);
    assert(pads[0].button == 0x0100u);
    assert(pads[0].stick_x == -5);
    assert(pads[0].stick_y == 7);
    assert(pads[1].button == 0u);  // unplugged slots read as zero, not 0xFFFF
    assert(backend.pad_read_count == 1u);

    // pad_init/reset/recalibrate succeed in the deterministic host.
    assert(dol_platform_pad_init());
    assert(dol_platform_pad_reset(0x1u));
    assert(dol_platform_pad_recalibrate(0x1u));

    // Audio contract: sample rate and pushed frames are captured.
    dol_platform_audio_set_sample_rate(DOL_AUDIO_DMA_48KHZ);
    const s16 samples[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    dol_platform_audio_push(samples, 4);
    dol_platform_audio_push(samples, 2);
    assert(backend.audio_sample_rate == DOL_AUDIO_DMA_48KHZ);
    assert(backend.audio_frames == 6u);
    assert(backend.audio_push_count == 2u);

    dol_platform_reset();
    assert(!dol_platform_available());
    // After reset the headless backend is detached; pad_read returns zeros.
    memset(pads, 0xFF, sizeof pads);
    connected = dol_platform_pad_read(pads);
    assert(connected == 0u);
    assert(pads[0].button == 0u);
}

static DolMemoryCardConfig test_card_config(const char* path, u64 serial) {
    DolMemoryCardConfig config;
    memset(&config, 0, sizeof(config));
    config.path = path;
    config.size_mbits = 4;
    config.serial = serial;
    memcpy(config.game_code, "TEST", 4);
    memcpy(config.company, "99", 2);
    return config;
}

static void test_memory_card(void) {
    DolMemoryCardConfig config =
        test_card_config(NULL, 0x1122334455667788ull);
    DolMemoryCard* card = dol_card_open(&config);
    assert(card != NULL);

    u16 size_mbits = 0;
    u32 sector_size = 0;
    assert(dol_card_probe(card, &size_mbits, &sector_size) ==
           DOL_CARD_RESULT_READY);
    assert(size_mbits == 4);
    assert(sector_size == DOL_CARD_SECTOR_SIZE);
    assert(dol_card_free_space(card, NULL, NULL) ==
           DOL_CARD_RESULT_NO_CARD);
    assert(dol_card_mount(card) == DOL_CARD_RESULT_READY);

    u32 bytes_free = 0;
    u32 files_free = 0;
    assert(dol_card_free_space(card, &bytes_free, &files_free) ==
           DOL_CARD_RESULT_READY);
    assert(bytes_free == 59u * DOL_CARD_SECTOR_SIZE);
    assert(files_free == DOL_CARD_MAX_FILES);

    s32 file_no = -1;
    const u32 file_length = 3u * DOL_CARD_SECTOR_SIZE;
    assert(dol_card_create_file(card, "runtime_save", file_length,
                                &file_no) == DOL_CARD_RESULT_READY);
    assert(file_no == 0);
    assert(dol_card_create_file(card, "runtime_save", file_length,
                                NULL) == DOL_CARD_RESULT_EXISTS);

    u8 written[DOL_CARD_SECTOR_SIZE];
    u8 readback[DOL_CARD_SECTOR_SIZE];
    for (u32 i = 0; i < DOL_CARD_SECTOR_SIZE; i++)
        written[i] = (u8)(i * 17u + 3u);
    memset(readback, 0, sizeof(readback));
    assert(dol_card_write_file(card, file_no, DOL_CARD_SECTOR_SIZE,
                               written, sizeof(written)) ==
           DOL_CARD_RESULT_READY);
    assert(dol_card_transferred_bytes(card) == sizeof(written));
    assert(dol_card_read_file(card, file_no, DOL_CARD_SECTOR_SIZE,
                              readback, sizeof(readback)) ==
           DOL_CARD_RESULT_READY);
    assert(memcmp(written, readback, sizeof(written)) == 0);

    DolMemoryCardStat stat;
    assert(dol_card_get_status(card, file_no, &stat) ==
           DOL_CARD_RESULT_READY);
    assert(stat.length == file_length);
    assert(strcmp(stat.file_name, "runtime_save") == 0);
    stat.banner_format = 2;
    stat.icon_address = 0x40;
    stat.icon_format = 2;
    stat.icon_speed = 3;
    stat.comment_address = 0;
    assert(dol_card_set_status(card, file_no, &stat) ==
           DOL_CARD_RESULT_READY);
    assert(dol_card_format(card) == DOL_CARD_RESULT_READY);
    assert(dol_card_open_file(card, "runtime_save", NULL, NULL) ==
           DOL_CARD_RESULT_NO_FILE);
    assert(dol_card_free_space(card, &bytes_free, &files_free) ==
           DOL_CARD_RESULT_READY);
    assert(bytes_free == 59u * DOL_CARD_SECTOR_SIZE);
    assert(files_free == DOL_CARD_MAX_FILES);
    assert(dol_card_unmount(card) == DOL_CARD_RESULT_READY);
    dol_card_close(card);
}

static void test_memory_card_persistence(void) {
    const char* path = "gxruntime-memory-card-test.dolcard";
    remove(path);

    DolMemoryCardConfig config =
        test_card_config(path, 0x8877665544332211ull);
    DolMemoryCard* card = dol_card_open(&config);
    assert(card != NULL);
    assert(dol_card_mount(card) == DOL_CARD_RESULT_READY);

    s32 file_no = -1;
    assert(dol_card_create_file(card, "persistent",
                                DOL_CARD_SECTOR_SIZE, &file_no) ==
           DOL_CARD_RESULT_READY);
    const u8 bytes[4] = {0x12, 0x34, 0x56, 0x78};
    assert(dol_card_write_file(card, file_no, 16, bytes, sizeof(bytes)) ==
           DOL_CARD_RESULT_READY);
    dol_card_close(card);

    config.serial = 1;
    card = dol_card_open(&config);
    assert(card != NULL);
    assert(dol_card_serial(card) == 0x8877665544332211ull);
    assert(dol_card_mount(card) == DOL_CARD_RESULT_READY);
    u32 length = 0;
    assert(dol_card_open_file(card, "persistent", &file_no, &length) ==
           DOL_CARD_RESULT_READY);
    assert(length == DOL_CARD_SECTOR_SIZE);
    u8 readback[4] = {0};
    assert(dol_card_read_file(card, file_no, 16, readback,
                              sizeof(readback)) ==
           DOL_CARD_RESULT_READY);
    assert(memcmp(bytes, readback, sizeof(bytes)) == 0);
    assert(dol_card_delete_file(card, "persistent") ==
           DOL_CARD_RESULT_READY);
    assert(dol_card_open_file(card, "persistent", NULL, NULL) ==
           DOL_CARD_RESULT_NO_FILE);
    dol_card_close(card);
    remove(path);
}

static void test_memory_card_rejects_corruption(void) {
    const char* path = "gxruntime-memory-card-corrupt.dolcard";
    remove(path);
    FILE* file = fopen(path, "wb");
    assert(file != NULL);
    const u8 invalid[] = {0x44, 0x4F, 0x4C, 0x00};
    assert(fwrite(invalid, 1, sizeof(invalid), file) == sizeof(invalid));
    assert(fclose(file) == 0);

    DolMemoryCardConfig config = test_card_config(path, 1);
    assert(dol_card_open(&config) == NULL);

    file = fopen(path, "rb");
    assert(file != NULL);
    u8 unchanged[sizeof(invalid)] = {0};
    assert(fread(unchanged, 1, sizeof(unchanged), file) == sizeof(unchanged));
    assert(fclose(file) == 0);
    assert(memcmp(invalid, unchanged, sizeof(invalid)) == 0);
    remove(path);
}

// Snapshot round-trip: registers + a memory region survive write/read, host
// function pointers are preserved, and bad magic is rejected. This is the
// foundation of the deterministic restore-and-replay differential harness.
static void test_savestate_roundtrip(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));

    // Seed register + memory state.
    cpu.gpr[3] = 0xDEADBEEFu;
    cpu.gpr[31] = 0x12345678u;
    cpu.fpr[1] = 3.5;
    cpu.ps1[1] = -2.25;
    cpu.pc = 0x80123456u;
    cpu.lr = 0x80004812u;
    cpu.gqr[5] = 0x00070007u;
    cpu.timebase = 0x0011223344556677ull;
    cpu.ram[0x100] = 0xAB;
    cpu.ram[0x101] = 0xCD;
    cpu.ram[cpu.ram_size - 1u] = 0x5Au;

    // Capture the host pointer to verify it is NOT clobbered by restore.
    PPCHostCall saved_host_call = cpu.host_call;
    u8* saved_ram = cpu.ram;

    const char* path = "/tmp/gxruntime_savestate_test.dols";
    DolSaveRegion regions[1] = {{"MEM1", cpu.ram, cpu.ram_size}};
    assert(dol_savestate_write(path, &cpu, regions, 1));

    // Clobber everything, then restore.
    cpu.gpr[3] = 0;
    cpu.gpr[31] = 0;
    cpu.fpr[1] = 0;
    cpu.ps1[1] = 0;
    cpu.pc = 0;
    cpu.lr = 0;
    cpu.gqr[5] = 0;
    cpu.timebase = 0;
    cpu.ram[0x100] = 0;
    cpu.ram[0x101] = 0;
    cpu.ram[cpu.ram_size - 1u] = 0;

    bool mismatch = true;
    assert(dol_savestate_read(path, &cpu, regions, 1, &mismatch));
    assert(!mismatch);

    // Registers restored.
    assert(cpu.gpr[3] == 0xDEADBEEFu);
    assert(cpu.gpr[31] == 0x12345678u);
    assert(cpu.fpr[1] == 3.5);
    assert(cpu.ps1[1] == -2.25);
    assert(cpu.pc == 0x80123456u);
    assert(cpu.lr == 0x80004812u);
    assert(cpu.gqr[5] == 0x00070007u);
    assert(cpu.timebase == 0x0011223344556677ull);
    // Memory restored.
    assert(cpu.ram[0x100] == 0xAB);
    assert(cpu.ram[0x101] == 0xCD);
    assert(cpu.ram[cpu.ram_size - 1u] == 0x5Au);
    // Host pointer + ram pointer preserved (not part of the serialized prefix).
    assert(cpu.host_call == saved_host_call);
    assert(cpu.ram == saved_ram);

    // Bad magic rejected.
    FILE* corrupt = fopen(path, "wb");
    assert(corrupt != NULL);
    const u32 garbage = 0xFFFFFFFFu;
    fwrite(&garbage, sizeof(garbage), 1, corrupt);
    fclose(corrupt);
    assert(!dol_savestate_read(path, &cpu, regions, 1, NULL));

    remove(path);
    cpu_free(&cpu);
}

static void test_native_system_helpers(void) {
    CPUState cpu;
    assert(cpu_init(&cpu));
    cpu.spr_read = test_spr_read;
    cpu.spr_write = test_spr_write;
    cpu.cache_control = test_cache_control;
    cpu_reset(&cpu);
    assert(cpu.spr_read == test_spr_read);
    assert(cpu.spr_write == test_spr_write);
    assert(cpu.cache_control == test_cache_control);

    cpu.lr = 0x12345678u;
    assert(ppc_mfspr(&cpu, 8, 0x80001000u) == cpu.lr);
    g_spr_reads = 0;
    assert(ppc_mfspr(&cpu, 1008, 0x80001004u) == 0xA50003F0u);
    assert(g_spr_reads == 1 && g_last_spr == 1008);

    g_spr_writes = 0;
    ppc_mtspr(&cpu, 1008, 0xCAFEBABEu, 0x80001008u);
    assert(g_spr_writes == 1 && g_last_spr == 1008);
    assert(g_last_spr_value == 0xCAFEBABEu);

    cpu.xer = 5;
    cpu.gpr[10] = 0x80000100u;
    cpu.gpr[11] = 0;
    cpu.ram[0x100] = 0x12;
    cpu.ram[0x101] = 0x34;
    cpu.ram[0x102] = 0x56;
    cpu.ram[0x103] = 0x78;
    cpu.ram[0x104] = 0x9A;
    ppc_lswx(&cpu, 3, 10, 11, 0x8000100Cu);
    assert(cpu.gpr[3] == 0x12345678u);
    assert(cpu.gpr[4] == 0x9A000000u);

    g_cache_controls = 0;
    ppc_cache_control(&cpu, PPC_CACHE_DCBF, 0x80000100u, 0x80001010u);
    assert(g_cache_controls == 1);
    assert(g_last_cache_operation == PPC_CACHE_DCBF);
    assert(g_last_spr_value == 0x80000100u);

    cpu.msr = PPC_MSR_PR;
    cpu.exception = 0;
    ppc_cache_control(&cpu, PPC_CACHE_DCBI, 0x80000100u, 0x80001014u);
    assert(g_cache_controls == 1);
    assert((cpu.program_exception & PPC_PROGRAM_PRIV) != 0);
    cpu_free(&cpu);
}

int main(void) {
    test_guest_memory();
    test_store_reservation();
    test_native_system_helpers();
    test_savestate_roundtrip();
    test_gx_recomp_modules();
    test_gx_recomp_all_module_replay();
    test_mmio_bus();
    test_loader();
    test_loader_failures();
    test_boot_globals();
    test_aram();
    test_aram_boundaries();
    test_dvd_fst();
    test_dvd_fst_edges();
    test_psq_quantized_paths();
    test_platform_dispatch();
    test_event_clock();
    test_vi_clock();
    test_interrupts();
    test_si_device();
    test_exi_device();
    test_di_device();
    test_audio_dma();
    test_audio_device();
    test_headless_backend();
    test_memory_card();
    test_memory_card_persistence();
    test_memory_card_rejects_corruption();
    puts("GXRuntime tests passed");
    return 0;
}
