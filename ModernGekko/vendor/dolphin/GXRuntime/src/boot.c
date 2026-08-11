// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/boot.h"

#include <stdio.h>

// GameCube low-memory OS global addresses (see YAGCD "Low Memory globals").
#define LOMEM_BOOT_MAGIC   0x80000020u  // 0x0D15EA5E once the apploader has run
#define LOMEM_BOOT_VERSION 0x80000024u
#define LOMEM_PHYS_MEM     0x80000028u  // physical memory size
#define LOMEM_CONSOLE_TYPE 0x8000002Cu
#define LOMEM_ARENA_LO     0x80000030u
#define LOMEM_ARENA_HI     0x80000034u
#define LOMEM_FST_START    0x80000038u
#define LOMEM_FST_MAXLEN   0x8000003Cu
#define LOMEM_VIDEO_MODE   0x800000CCu  // 0=NTSC, 1=PAL, 2=MPAL
#define LOMEM_BUS_CLOCK    0x800000F8u
#define LOMEM_CPU_CLOCK    0x800000FCu

#define GC_PHYS_MEM_SIZE   0x01800000u  // 24 MB
#define GC_CONSOLE_RETAIL  0x00000001u
#define GC_BUS_CLOCK       0x09A7EC80u  // 162 MHz
#define GC_CPU_CLOCK       0x1CF7C580u  // 486 MHz

// ArenaHi: top of the OS arena the game's allocator (e.g. nlInitMemory) carves
// its MEM1 heap from. Must match real hardware or the heap is undersized and
// late allocations fail. Real HW / Dolphin BS2 boot sets low-mem 0x80000034 to
// 0x817FEC60 (dolphin Source/Core/Core/Boot/Boot_BS2Emu.cpp). The previous
// 0x81700000 reserved an extra ~1 MB at the top that nothing in this runtime
// uses (Aurora owns display, so no guest XFB lives there), shorting the heap by
// ~1.02 MB and freezing the in-game localization load in an OOM spin.
#define GC_ARENA_HI        0x817FEC60u
// Initial stack top. Real game startup loads its own SP almost immediately;
// this only needs to be valid before then. Kept ABOVE GC_ARENA_HI so the boot
// stack never sits inside the arena OSInit may clear (mirrors real HW, where
// the boot stack lives above ArenaHi near the top of MEM1).
#define GC_INIT_STACK      0x817FFF00u

static void poke32(CPUState* cpu, u32 address, u32 value) {
    if (address < GC_RAM_BASE)
        return;
    u32 offset = address - GC_RAM_BASE;
    if (offset + 4 <= cpu->ram_size)
        write_be32(cpu->ram + offset, value);
}

static u32 align_up(u32 value, u32 align) {
    return (value + (align - 1u)) & ~(align - 1u);
}

// Stack region reserved between the loaded image and ArenaLo. Game startup
// relocates its stack pointer into this gap. OSInit clears [ArenaLo,
// ArenaHi) arena in one memset, so ArenaLo MUST sit above the live stack or the
// clear wipes it (and the saved return addresses on it). Mirror what the real
// IPL/apploader does: leave a stack gap above bss before the arena starts.
#define GC_STACK_RESERVE 0x00020000u  // 128 KB

void boot_setup_os_globals(CPUState* cpu, const DolLayout* layout) {
    u32 arena_lo = align_up(layout->bss_address + layout->bss_size + GC_STACK_RESERVE, 32u);
    if (arena_lo < GC_RAM_BASE || arena_lo > GC_ARENA_HI)
        arena_lo = GC_RAM_BASE;

    poke32(cpu, LOMEM_BOOT_MAGIC,   0x0D15EA5Eu);
    poke32(cpu, LOMEM_BOOT_VERSION, 1u);
    poke32(cpu, LOMEM_PHYS_MEM,     GC_PHYS_MEM_SIZE);
    poke32(cpu, LOMEM_CONSOLE_TYPE, GC_CONSOLE_RETAIL);
    poke32(cpu, LOMEM_ARENA_LO,     arena_lo);
    poke32(cpu, LOMEM_ARENA_HI,     GC_ARENA_HI);
    poke32(cpu, LOMEM_FST_START,    0u);
    poke32(cpu, LOMEM_FST_MAXLEN,   0u);
    poke32(cpu, LOMEM_VIDEO_MODE,   0u);
    poke32(cpu, LOMEM_BUS_CLOCK,    GC_BUS_CLOCK);
    poke32(cpu, LOMEM_CPU_CLOCK,    GC_CPU_CLOCK);

    // Stack pointer (r1) and a small backchain/linkage area.
    cpu->gpr[1] = GC_INIT_STACK;
    poke32(cpu, GC_INIT_STACK, 0u);      // backchain terminator
    poke32(cpu, GC_INIT_STACK + 4u, 0u); // saved LR slot

    // MSR: enable FP (FP available) so floating-point code runs. Big-endian,
    // supervisor mode, matching the post-IPL state closely enough to boot.
    cpu->msr = 0x00002000u; // FP

    fprintf(stderr,
            "[boot] entry=0x%08X arena_lo=0x%08X arena_hi=0x%08X sp=0x%08X\n",
            layout->entry_point, arena_lo, GC_ARENA_HI, cpu->gpr[1]);
}
