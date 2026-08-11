// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/mmio_bus.h"

#include <string.h>

static bool range_valid(u32 base, u32 size) {
    return size != 0u && base <= UINT32_MAX - (size - 1u);
}

static bool range_contains(u32 base, u32 size, u32 ea, u8 access_size) {
    if (!range_valid(base, size) || access_size == 0u)
        return false;
    if (ea < base)
        return false;
    const u32 off = ea - base;
    return off < size && (u32)access_size <= size - off;
}

void dol_mmio_bus_init(DolMmioBus* bus) {
    if (bus != NULL)
        memset(bus, 0, sizeof(*bus));
}

bool dol_mmio_bus_register(DolMmioBus* bus, u32 base, u32 size,
                           DolMmioReadFn read, DolMmioWriteFn write,
                           void* user) {
    if (bus == NULL || !range_valid(base, size) ||
        (read == NULL && write == NULL))
        return false;

    for (u32 i = 0; i < DOL_MMIO_BUS_MAX_REGIONS; i++) {
        DolMmioRegion* region = &bus->regions[i];
        if (!region->active) {
            region->base = base;
            region->size = size;
            region->read = read;
            region->write = write;
            region->user = user;
            region->active = true;
            return true;
        }
    }
    return false;
}

bool dol_mmio_bus_contains(const DolMmioBus* bus, u32 ea) {
    if (bus == NULL)
        return false;
    for (u32 i = 0; i < DOL_MMIO_BUS_MAX_REGIONS; i++) {
        const DolMmioRegion* region = &bus->regions[i];
        if (region->active && range_contains(region->base, region->size, ea, 1))
            return true;
    }
    return false;
}

bool dol_mmio_bus_read(const DolMmioBus* bus, CPUState* cpu, u32 ea, u8 size,
                       u64* value) {
    if (bus == NULL || size == 0u)
        return false;
    for (u32 i = 0; i < DOL_MMIO_BUS_MAX_REGIONS; i++) {
        const DolMmioRegion* region = &bus->regions[i];
        if (!region->active || region->read == NULL ||
            !range_contains(region->base, region->size, ea, size))
            continue;
        if (region->read(region->user, cpu, ea, size, value))
            return true;
    }
    return false;
}

bool dol_mmio_bus_write(const DolMmioBus* bus, CPUState* cpu, u32 ea, u8 size,
                        u64 value) {
    if (bus == NULL || size == 0u)
        return false;
    for (u32 i = 0; i < DOL_MMIO_BUS_MAX_REGIONS; i++) {
        const DolMmioRegion* region = &bus->regions[i];
        if (!region->active || region->write == NULL ||
            !range_contains(region->base, region->size, ea, size))
            continue;
        if (region->write(region->user, cpu, ea, size, value))
            return true;
    }
    return false;
}
