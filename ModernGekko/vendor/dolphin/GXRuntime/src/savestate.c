// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/savestate.h"

#include <stdio.h>
#include <string.h>

// The resumable register state is the POD prefix of CPUState, ending right
// before the first host function pointer (external_read). Everything from there
// on (function pointers, ram pointer, ram_size, external_pointer) is host-side
// and rebound by cpu_init on restore, so it must not be serialized.
size_t dol_savestate_cpu_pod_size(void) {
    return offsetof(CPUState, external_read);
}

typedef struct {
    uint32_t magic;
    uint32_t version;
    uint32_t cpu_pod_size;
    uint32_t region_count;
} DolSaveHeader;

typedef struct {
    char name[DOL_SAVESTATE_NAME_LEN];
    uint32_t size;
} DolSaveRegionHeader;

bool dol_savestate_write(const char* path, const CPUState* cpu,
                         const DolSaveRegion* regions, uint32_t region_count) {
    if (path == NULL || cpu == NULL)
        return false;
    if (region_count > DOL_SAVESTATE_MAX_REGIONS)
        return false;

    FILE* f = fopen(path, "wb");
    if (f == NULL)
        return false;

    bool ok = true;
    const DolSaveHeader header = {
        .magic = DOL_SAVESTATE_MAGIC,
        .version = DOL_SAVESTATE_VERSION,
        .cpu_pod_size = (uint32_t)dol_savestate_cpu_pod_size(),
        .region_count = region_count,
    };
    ok = ok && fwrite(&header, sizeof(header), 1, f) == 1;

    for (uint32_t i = 0; i < region_count && ok; ++i) {
        DolSaveRegionHeader rh;
        memset(&rh, 0, sizeof(rh));
        if (regions[i].name != NULL)
            strncpy(rh.name, regions[i].name, DOL_SAVESTATE_NAME_LEN - 1u);
        rh.size = regions[i].size;
        ok = ok && fwrite(&rh, sizeof(rh), 1, f) == 1;
    }

    ok = ok && fwrite(cpu, header.cpu_pod_size, 1, f) == 1;

    for (uint32_t i = 0; i < region_count && ok; ++i) {
        if (regions[i].size == 0u)
            continue;
        if (regions[i].data == NULL) {
            ok = false;
            break;
        }
        ok = ok && fwrite(regions[i].data, 1u, regions[i].size, f) ==
                       regions[i].size;
    }

    if (fclose(f) != 0)
        ok = false;
    return ok;
}

bool dol_savestate_read(const char* path, CPUState* cpu,
                        const DolSaveRegion* regions, uint32_t region_count,
                        bool* mismatch) {
    if (mismatch != NULL)
        *mismatch = false;
    if (path == NULL || cpu == NULL)
        return false;

    FILE* f = fopen(path, "rb");
    if (f == NULL)
        return false;

    bool ok = true;
    DolSaveHeader header;
    ok = ok && fread(&header, sizeof(header), 1, f) == 1;
    if (ok && (header.magic != DOL_SAVESTATE_MAGIC ||
               header.version != DOL_SAVESTATE_VERSION ||
               header.cpu_pod_size != (uint32_t)dol_savestate_cpu_pod_size() ||
               header.region_count > DOL_SAVESTATE_MAX_REGIONS)) {
        ok = false;
    }

    DolSaveRegionHeader rh[DOL_SAVESTATE_MAX_REGIONS];
    for (uint32_t i = 0; i < header.region_count && ok; ++i)
        ok = ok && fread(&rh[i], sizeof(rh[i]), 1, f) == 1;

    // Overwrite only the register POD prefix; host pointers stay intact.
    ok = ok && fread(cpu, header.cpu_pod_size, 1, f) == 1;

    for (uint32_t i = 0; i < header.region_count && ok; ++i) {
        // Find the matching destination region by name.
        const DolSaveRegion* dest = NULL;
        for (uint32_t j = 0; j < region_count; ++j) {
            if (regions[j].name != NULL &&
                strncmp(regions[j].name, rh[i].name, DOL_SAVESTATE_NAME_LEN) ==
                    0) {
                dest = &regions[j];
                break;
            }
        }
        if (dest == NULL || dest->data == NULL || dest->size == 0u) {
            // No destination: skip the bytes in the file.
            if (fseek(f, (long)rh[i].size, SEEK_CUR) != 0)
                ok = false;
            continue;
        }
        uint32_t copy = rh[i].size < dest->size ? rh[i].size : dest->size;
        if (copy != rh[i].size || copy != dest->size) {
            if (mismatch != NULL)
                *mismatch = true;
        }
        ok = ok && fread(dest->data, 1u, copy, f) == copy;
        if (ok && rh[i].size > copy) {
            if (fseek(f, (long)(rh[i].size - copy), SEEK_CUR) != 0)
                ok = false;
        }
    }

    if (fclose(f) != 0)
        ok = false;
    return ok;
}
