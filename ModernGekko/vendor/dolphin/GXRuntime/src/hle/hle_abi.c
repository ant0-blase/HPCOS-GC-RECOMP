// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/hle_abi.h"
#include "gxruntime/guest_memory.h"

char* hle_read_cstr(const CPUState* c, u32 gaddr, char* buf, size_t cap) {
    size_t i = 0;
    if (gaddr != 0) {
        for (; i + 1 < cap; i++) {
            u8 ch = mem_read8((CPUState*)c, gaddr + (u32)i);
            if (ch == 0)
                break;
            buf[i] = (char)ch;
        }
    }
    buf[i] = '\0';
    return buf;
}

bool copy_guest_to_host(const CPUState* cpu, u32 guest_address, void* output, u32 length) {
    if (length == 0)
        return true;
    u32 available = 0;
    const void* direct = dol_guest_memory_pointer(NULL, (CPUState*)cpu, guest_address, &available);
    if (direct != NULL && available >= length) {
        memcpy(output, direct, length);
        return true;
    }
    u8* bytes = (u8*)output;
    for (u32 i = 0; i < length; i++)
        bytes[i] = mem_read8((CPUState*)cpu, guest_address + i);
    return true;
}

bool copy_host_to_guest(CPUState* cpu, u32 guest_address, const void* input, u32 length) {
    if (length == 0)
        return true;
    u32 available = 0;
    void* direct = dol_guest_memory_pointer(NULL, cpu, guest_address, &available);
    if (direct != NULL && available >= length) {
        memcpy(direct, input, length);
        return true;
    }
    const u8* bytes = (const u8*)input;
    for (u32 i = 0; i < length; i++)
        mem_write8(cpu, guest_address + i, bytes[i]);
    return true;
}
