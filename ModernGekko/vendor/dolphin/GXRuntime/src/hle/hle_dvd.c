// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/hle.h"
#include "gxruntime/hle_abi.h"
#include "gxruntime/dvd.h"
#include <stdio.h>

#define DVD_CB_STATE      0x0Cu
#define DVD_CB_CURRXFER   0x1Cu
#define DVD_CB_XFERRED    0x20u
#define DVD_FI_STARTADDR  0x30u
#define DVD_FI_LENGTH     0x34u
#define DVD_FI_CALLBACK   0x38u
#define DVD_STATE_END     0u

void dol_hle_DVDInit(CPUState* cpu) {
    (void)cpu;
}

void dol_hle_DVDClose(CPUState* cpu) {
    hle_set_u32(cpu, 1);
}

void dol_hle_DVDGetCommandBlockStatus(CPUState* cpu) {
    u32 block = hle_arg_u32(cpu, 0);
    s32 state = block ? (s32)mem_read32(cpu, block + DVD_CB_STATE) : DVD_STATE_END;
    hle_set_u32(cpu, state == 3 ? 1u : (u32)state);
}

void dol_hle_DVDGetDriveStatus(CPUState* cpu) {
    hle_set_u32(cpu, DVD_STATE_END);
}

void dol_hle_DVDConvertPathToEntrynum(CPUState* cpu) {
    char path[256];
    hle_read_cstr(cpu, hle_arg_u32(cpu, 0), path, sizeof path);
    s32 entry = dvd_path_to_entrynum(path);
    if (g_hle_log)
        fprintf(stderr, "[dvd] open '%s' -> entry %d\n", path, entry);
    hle_set_u32(cpu, (u32)entry);
}

void dol_hle_DVDFastOpen(CPUState* cpu) {
    s32 entry = (s32)hle_arg_u32(cpu, 0);
    u32 fi = hle_arg_u32(cpu, 1);
    u32 start = 0, length = 0;
    if (fi && dvd_entry_info(entry, &start, &length)) {
        mem_write32(cpu, fi + DVD_FI_STARTADDR, start);
        mem_write32(cpu, fi + DVD_FI_LENGTH, length);
        mem_write32(cpu, fi + DVD_FI_CALLBACK, 0);
        mem_write32(cpu, fi + DVD_CB_STATE, DVD_STATE_END);
        hle_set_u32(cpu, 1);  // TRUE
    } else {
        hle_set_u32(cpu, 0);  // FALSE
    }
}

void dol_hle_DVDReadAsyncPrio(CPUState* cpu) {
    u32 fi = hle_arg_u32(cpu, 0);
    u32 addr = hle_arg_u32(cpu, 1);
    u32 length = hle_arg_u32(cpu, 2);
    u32 offset = hle_arg_u32(cpu, 3);
    u32 callback = hle_arg_u32(cpu, 4);

    u32 start = mem_read32(cpu, fi + DVD_FI_STARTADDR);
    if (g_hle_log)
        fprintf(stderr, "[dvd] read addr=0x%08X len=%u disc=0x%08X\n",
                addr, length, start + offset);
    dvd_read_to_guest(cpu, addr, start + offset, length);

    mem_write32(cpu, fi + DVD_CB_STATE, DVD_STATE_END);
    mem_write32(cpu, fi + DVD_CB_CURRXFER, length);
    mem_write32(cpu, fi + DVD_CB_XFERRED, length);
    if (callback)
        fprintf(stderr, "[dvd] note: read completion callback 0x%08X not invoked\n",
                callback);
    hle_set_u32(cpu, 1);  // TRUE (queued)
}
