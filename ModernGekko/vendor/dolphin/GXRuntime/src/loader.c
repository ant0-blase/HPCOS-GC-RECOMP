// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/loader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Map a cached guest address (0x8000_0000 based) to a byte offset in RAM.
// Returns (u32)-1 if the range does not fit entirely inside RAM.
static u32 ram_offset(const CPUState* cpu, u32 address, u32 size) {
    if (address < GC_RAM_BASE)
        return (u32)-1;
    u32 offset = address - GC_RAM_BASE;
    if (offset > cpu->ram_size || size > cpu->ram_size - offset)
        return (u32)-1;
    return offset;
}

static bool copy_section(CPUState* cpu, const u8* file, u32 file_size,
                         u32 file_offset, u32 address, u32 size,
                         const char* label, int index) {
    if (size == 0)
        return true;

    if (file_offset > file_size || size > file_size - file_offset) {
        fprintf(stderr, "error: DOL %s[%d] file range out of bounds\n", label, index);
        return false;
    }

    u32 offset = ram_offset(cpu, address, size);
    if (offset == (u32)-1) {
        fprintf(stderr, "error: DOL %s[%d] address 0x%08X+0x%X does not fit in RAM\n",
                label, index, address, size);
        return false;
    }

    memcpy(cpu->ram + offset, file + file_offset, size);
    return true;
}

bool dol_load_into_ram(CPUState* cpu, const char* path, DolLayout* layout) {
    memset(layout, 0, sizeof(*layout));

    FILE* f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "error: cannot open DOL '%s'\n", path);
        return false;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size < DOL_HEADER_SIZE) {
        fprintf(stderr, "error: '%s' is too small to be a DOL (%ld bytes)\n", path, size);
        fclose(f);
        return false;
    }

    u8* file = (u8*)malloc((size_t)size);
    if (!file) {
        fprintf(stderr, "error: out of memory reading DOL\n");
        fclose(f);
        return false;
    }
    if (fread(file, 1, (size_t)size, f) != (size_t)size) {
        fprintf(stderr, "error: failed to read '%s'\n", path);
        free(file);
        fclose(f);
        return false;
    }
    fclose(f);

    const u8* h = file;
    for (int i = 0; i < DOL_NUM_TEXT; i++) {
        layout->text_offset[i]  = read_be32(h + 0x00 + i * 4);
        layout->text_address[i] = read_be32(h + 0x48 + i * 4);
        layout->text_size[i]    = read_be32(h + 0x90 + i * 4);
    }
    for (int i = 0; i < DOL_NUM_DATA; i++) {
        layout->data_offset[i]  = read_be32(h + 0x1C + i * 4);
        layout->data_address[i] = read_be32(h + 0x64 + i * 4);
        layout->data_size[i]    = read_be32(h + 0xAC + i * 4);
    }
    layout->bss_address = read_be32(h + 0xD8);
    layout->bss_size    = read_be32(h + 0xDC);
    layout->entry_point = read_be32(h + 0xE0);

    bool ok = true;

    // Zero BSS *before* loading sections. The DOL's single BSS descriptor is a
    // coarse span that, with the Metrowerks layout, encloses the small data
    // sections (.sdata/.sdata2) as well as the true zero-init regions
    // (.bss/.sbss/.sbss2). Those small-data sections are loaded as ordinary DOL
    // data that overlaps the BSS span, so the data copies must come *after* the
    // clear or they would be wiped -- which is exactly what blanks out small
    // initialized constants like the "art/" path prefix. (Real hardware never
    // zeroes the DOL BSS in the apploader; the game's own __init_data clears
    // only the true sub-ranges via _bss_init_info, leaving .sdata intact. We
    // approximate that faithfully here: clear the span, then overlay the data.)
    if (layout->bss_size != 0) {
        u32 offset = ram_offset(cpu, layout->bss_address, layout->bss_size);
        if (offset == (u32)-1) {
            fprintf(stderr, "error: BSS 0x%08X+0x%X does not fit in RAM\n",
                    layout->bss_address, layout->bss_size);
            ok = false;
        } else {
            memset(cpu->ram + offset, 0, layout->bss_size);
        }
    }

    for (int i = 0; ok && i < DOL_NUM_TEXT; i++)
        ok = copy_section(cpu, file, (u32)size, layout->text_offset[i],
                          layout->text_address[i], layout->text_size[i], "text", i);
    for (int i = 0; ok && i < DOL_NUM_DATA; i++)
        ok = copy_section(cpu, file, (u32)size, layout->data_offset[i],
                          layout->data_address[i], layout->data_size[i], "data", i);

    free(file);
    return ok;
}
