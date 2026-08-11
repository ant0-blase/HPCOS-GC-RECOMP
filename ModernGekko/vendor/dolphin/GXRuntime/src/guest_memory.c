// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/guest_memory.h"

#include <stdlib.h>
#include <string.h>

#define DOL_DEFAULT_VM_BASE 0x7E000000u
#define DOL_DEFAULT_VM_SIZE 0x02000000u
#define DOL_DEFAULT_LC_BASE 0xE0000000u
#define DOL_DEFAULT_LC_SIZE 0x00004000u

static bool contains(u32 base, u32 bytes, u32 address, u8 size) {
    return size != 0 && size <= bytes && address >= base &&
           (address - base) <= bytes - size;
}

static u64 read_be(const u8* data, u32 offset, u8 size) {
    u64 value = 0;
    for (u8 i = 0; i < size; i++)
        value = (value << 8) | data[offset + i];
    return value;
}

static void write_be(u8* data, u32 offset, u8 size, u64 value) {
    for (u8 i = 0; i < size; i++)
        data[offset + size - 1u - i] = (u8)(value >> (8u * i));
}

DolGuestMemoryConfig dol_guest_memory_default_config(void) {
    DolGuestMemoryConfig config = {
        .vm_base = DOL_DEFAULT_VM_BASE,
        .vm_size = DOL_DEFAULT_VM_SIZE,
        .locked_cache_base = DOL_DEFAULT_LC_BASE,
        .locked_cache_size = DOL_DEFAULT_LC_SIZE,
    };
    return config;
}

bool dol_guest_memory_init(DolGuestMemory* memory,
                           const DolGuestMemoryConfig* config) {
    if (memory == NULL)
        return false;
    memset(memory, 0, sizeof(*memory));
    memory->config = config != NULL ? *config : dol_guest_memory_default_config();
    if (memory->config.vm_size != 0) {
        memory->vm = (u8*)calloc(1, memory->config.vm_size);
        if (memory->vm == NULL)
            goto fail;
    }
    if (memory->config.locked_cache_size != 0) {
        memory->locked_cache =
            (u8*)calloc(1, memory->config.locked_cache_size);
        if (memory->locked_cache == NULL)
            goto fail;
    }
    return true;

fail:
    dol_guest_memory_shutdown(memory);
    return false;
}

void dol_guest_memory_shutdown(DolGuestMemory* memory) {
    if (memory == NULL)
        return;
    free(memory->vm);
    free(memory->locked_cache);
    memset(memory, 0, sizeof(*memory));
}

bool dol_guest_memory_read(const DolGuestMemory* memory, u32 address, u8 size,
                           u64* value) {
    if (memory == NULL || value == NULL)
        return false;
    if (memory->vm != NULL &&
        contains(memory->config.vm_base, memory->config.vm_size, address, size)) {
        *value = read_be(memory->vm, address - memory->config.vm_base, size);
        return true;
    }
    if (memory->locked_cache != NULL &&
        contains(memory->config.locked_cache_base,
                 memory->config.locked_cache_size, address, size)) {
        *value = read_be(memory->locked_cache,
                         address - memory->config.locked_cache_base, size);
        return true;
    }
    return false;
}

bool dol_guest_memory_write(DolGuestMemory* memory, u32 address, u8 size,
                            u64 value) {
    if (memory == NULL)
        return false;
    if (memory->vm != NULL &&
        contains(memory->config.vm_base, memory->config.vm_size, address, size)) {
        write_be(memory->vm, address - memory->config.vm_base, size, value);
        return true;
    }
    if (memory->locked_cache != NULL &&
        contains(memory->config.locked_cache_base,
                 memory->config.locked_cache_size, address, size)) {
        write_be(memory->locked_cache,
                 address - memory->config.locked_cache_base, size, value);
        return true;
    }
    return false;
}

#define Wii_EXRAM_BASE     0x90000000u
#define Wii_EXRAM_UNCACHED 0xD0000000u

void* dol_guest_memory_pointer(DolGuestMemory* memory, CPUState* cpu,
                               u32 address, u32* available) {
    u32 offset = 0;
    if (cpu != NULL && address < cpu->ram_size) {
        offset = address;
        if (available != NULL)
            *available = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (cpu != NULL && cpu->exram) {
        u32 ex_offset = address - 0x10000000u;
        if (ex_offset < cpu->exram_size) {
            if (available != NULL)
                *available = cpu->exram_size - ex_offset;
            return cpu->exram + ex_offset;
        }
    }
    if (cpu != NULL &&
        address >= GC_RAM_BASE && address < GC_RAM_BASE + cpu->ram_size) {
        offset = address - GC_RAM_BASE;
        if (available != NULL)
            *available = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (cpu != NULL &&
        address >= GC_RAM_UNCACHED &&
        address < GC_RAM_UNCACHED + cpu->ram_size) {
        offset = address - GC_RAM_UNCACHED;
        if (available != NULL)
            *available = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (cpu != NULL && cpu->exram) {
        if (address >= Wii_EXRAM_BASE && address < Wii_EXRAM_BASE + cpu->exram_size) {
            offset = address - Wii_EXRAM_BASE;
            if (available != NULL)
                *available = cpu->exram_size - offset;
            return cpu->exram + offset;
        }
        if (address >= Wii_EXRAM_UNCACHED && address < Wii_EXRAM_UNCACHED + cpu->exram_size) {
            offset = address - Wii_EXRAM_UNCACHED;
            if (available != NULL)
                *available = cpu->exram_size - offset;
            return cpu->exram + offset;
        }
    }
    if (memory != NULL && memory->vm != NULL &&
        address >= memory->config.vm_base &&
        address < memory->config.vm_base + memory->config.vm_size) {
        offset = address - memory->config.vm_base;
        if (available != NULL)
            *available = memory->config.vm_size - offset;
        return memory->vm + offset;
    }
    if (memory != NULL && memory->locked_cache != NULL &&
        address >= memory->config.locked_cache_base &&
        address < memory->config.locked_cache_base +
                      memory->config.locked_cache_size) {
        offset = address - memory->config.locked_cache_base;
        if (available != NULL)
            *available = memory->config.locked_cache_size - offset;
        return memory->locked_cache + offset;
    }
    if (available != NULL)
        *available = 0;
    return NULL;
}

void dol_guest_address_resolver_init(DolGuestAddressResolver* resolver,
                                     DolGuestMemory* memory, CPUState* cpu) {
    if (resolver == NULL)
        return;
    memset(resolver, 0, sizeof(*resolver));
    resolver->memory = memory;
    resolver->cpu = cpu;
}

void dol_guest_address_resolver_init_callback(
    DolGuestAddressResolver* resolver, DolGuestAddressResolveFn resolve,
    void* user) {
    if (resolver == NULL)
        return;
    memset(resolver, 0, sizeof(*resolver));
    resolver->resolve = resolve;
    resolver->user = user;
}

static void* resolve_mem1_physical(CPUState* cpu, u32 address,
                                   u32* available) {
    if (cpu == NULL)
        return NULL;
    if (address < cpu->ram_size) {
        if (available != NULL)
            *available = cpu->ram_size - address;
        return cpu->ram + address;
    }
    if (cpu->exram) {
        u32 offset = address - 0x10000000u;
        if (offset < cpu->exram_size) {
            if (available != NULL)
                *available = cpu->exram_size - offset;
            return cpu->exram + offset;
        }
    }
    return NULL;
}

static void* resolve_mem1_virtual(CPUState* cpu, u32 address,
                                  u32* available) {
    if (cpu == NULL)
        return NULL;
    u32 offset = 0;
    if (address >= GC_RAM_BASE && address < GC_RAM_BASE + cpu->ram_size) {
        offset = address - GC_RAM_BASE;
        if (available != NULL)
            *available = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (address >= GC_RAM_UNCACHED && address < GC_RAM_UNCACHED + cpu->ram_size) {
        offset = address - GC_RAM_UNCACHED;
        if (available != NULL)
            *available = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (cpu->exram) {
        if (address >= Wii_EXRAM_BASE && address < Wii_EXRAM_BASE + cpu->exram_size) {
            offset = address - Wii_EXRAM_BASE;
            if (available != NULL)
                *available = cpu->exram_size - offset;
            return cpu->exram + offset;
        }
        if (address >= Wii_EXRAM_UNCACHED && address < Wii_EXRAM_UNCACHED + cpu->exram_size) {
            offset = address - Wii_EXRAM_UNCACHED;
            if (available != NULL)
                *available = cpu->exram_size - offset;
            return cpu->exram + offset;
        }
    }
    return NULL;
}

static void* resolve_aux_virtual(DolGuestMemory* memory, u32 address,
                                 u32* available) {
    u32 offset = 0;
    if (memory != NULL && memory->vm != NULL &&
        address >= memory->config.vm_base &&
        address < memory->config.vm_base + memory->config.vm_size) {
        offset = address - memory->config.vm_base;
        if (available != NULL)
            *available = memory->config.vm_size - offset;
        return memory->vm + offset;
    }
    if (memory != NULL && memory->locked_cache != NULL &&
        address >= memory->config.locked_cache_base &&
        address < memory->config.locked_cache_base +
                      memory->config.locked_cache_size) {
        offset = address - memory->config.locked_cache_base;
        if (available != NULL)
            *available = memory->config.locked_cache_size - offset;
        return memory->locked_cache + offset;
    }
    return NULL;
}

static bool finish_resolve(void* data, u32 address, u32 size, u32 available,
                           DolGuestAddressSpace space,
                           DolGuestResourceKind resource,
                           DolGuestResolvedRange* out) {
    if (data == NULL || size == 0u || available < size || out == NULL)
        return false;
    out->data = data;
    out->address = address;
    out->size = size;
    out->available = available;
    out->space = space;
    out->resource = resource;
    return true;
}

bool dol_guest_address_resolver_resolve(
    const DolGuestAddressResolver* resolver, u32 address, u32 size,
    DolGuestAddressSpace space, DolGuestResourceKind resource,
    DolGuestResolvedRange* out) {
    if (resolver == NULL || out == NULL)
        return false;

    if (resolver->resolve != NULL) {
        DolGuestResolvedRange range;
        memset(&range, 0, sizeof(range));
        if (!resolver->resolve(resolver->user, address, size, space, resource,
                               &range))
            return false;
        if (range.data == NULL || size == 0u || range.available < size)
            return false;
        range.address = address;
        range.size = size;
        range.space = space;
        range.resource = resource;
        *out = range;
        return true;
    }

    u32 available = 0;
    void* data = NULL;
    if (space == DOL_GUEST_ADDRESS_PHYSICAL) {
        data = resolve_mem1_physical(resolver->cpu, address, &available);
        return finish_resolve(data, address, size, available, space, resource,
                              out);
    }
    if (space == DOL_GUEST_ADDRESS_VIRTUAL) {
        data = resolve_mem1_virtual(resolver->cpu, address, &available);
        if (data == NULL)
            data = resolve_aux_virtual(resolver->memory, address, &available);
        return finish_resolve(data, address, size, available, space, resource,
                              out);
    }
    if (space != DOL_GUEST_ADDRESS_AUTO)
        return false;

    data = resolve_mem1_physical(resolver->cpu, address, &available);
    if (data != NULL) {
        return finish_resolve(data, address, size, available,
                              DOL_GUEST_ADDRESS_PHYSICAL, resource, out);
    }
    data = resolve_mem1_virtual(resolver->cpu, address, &available);
    if (data == NULL)
        data = resolve_aux_virtual(resolver->memory, address, &available);
    return finish_resolve(data, address, size, available,
                          DOL_GUEST_ADDRESS_VIRTUAL, resource, out);
}

void dol_guest_memory_copy(DolGuestMemory* memory, CPUState* cpu, u32 dest,
                           u32 src, u32 bytes) {
    if (bytes == 0)
        return;

    u32 dest_available = 0;
    u32 src_available = 0;
    void* dest_ptr =
        dol_guest_memory_pointer(memory, cpu, dest, &dest_available);
    void* src_ptr =
        dol_guest_memory_pointer(memory, cpu, src, &src_available);
    if (dest_ptr != NULL && src_ptr != NULL &&
        dest_available >= bytes && src_available >= bytes) {
        memmove(dest_ptr, src_ptr, bytes);
        return;
    }

    for (u32 i = 0; i < bytes; i++)
        mem_write8(cpu, dest + i, mem_read8(cpu, src + i));
}
