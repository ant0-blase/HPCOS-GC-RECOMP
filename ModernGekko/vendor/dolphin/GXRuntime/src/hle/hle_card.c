// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/hle.h"
#include "gxruntime/hle_abi.h"
#include "gxruntime/memory_card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARD_FILE_INFO_CHAN 0x00u
#define CARD_FILE_INFO_FILENO 0x04u
#define CARD_FILE_INFO_OFFSET 0x08u
#define CARD_FILE_INFO_LENGTH 0x0Cu
#define CARD_FILE_INFO_IBLOCK 0x10u

#define CARD_STAT_FILENAME 0x00u
#define CARD_STAT_LENGTH 0x20u
#define CARD_STAT_TIME 0x24u
#define CARD_STAT_GAME 0x28u
#define CARD_STAT_COMPANY 0x2Cu
#define CARD_STAT_BANNER_FORMAT 0x2Eu
#define CARD_STAT_ICON_ADDRESS 0x30u
#define CARD_STAT_ICON_FORMAT 0x34u
#define CARD_STAT_ICON_SPEED 0x36u
#define CARD_STAT_COMMENT_ADDRESS 0x38u
#define CARD_STAT_OFFSET_BANNER 0x3Cu
#define CARD_STAT_OFFSET_BANNER_TLUT 0x40u
#define CARD_STAT_OFFSET_ICON 0x44u
#define CARD_STAT_OFFSET_ICON_TLUT 0x64u
#define CARD_STAT_OFFSET_DATA 0x68u

static DolMemoryCard* card_for_channel(s32 channel) {
    return channel == 0 ? g_memory_card : NULL;
}

static s32 card_invalid_channel_result(s32 channel) {
    return (channel < 0 || channel >= 2) ? DOL_CARD_RESULT_FATAL
                                         : DOL_CARD_RESULT_NO_CARD;
}

static void card_set_async_result(CPUState* cpu, s32 channel, s32 result, u32 callback) {
    if (result >= 0 && callback != 0 && !queue_guest_callback(callback, channel, result))
        result = DOL_CARD_RESULT_IO_ERROR;
    hle_set_u32(cpu, (u32)result);
}

static void card_write_file_info(CPUState* cpu, u32 address, s32 channel, s32 file_no) {
    mem_write32(cpu, address + CARD_FILE_INFO_CHAN, (u32)channel);
    mem_write32(cpu, address + CARD_FILE_INFO_FILENO, (u32)file_no);
    mem_write32(cpu, address + CARD_FILE_INFO_OFFSET, 0);
    mem_write32(cpu, address + CARD_FILE_INFO_LENGTH, 0);
    mem_write16(cpu, address + CARD_FILE_INFO_IBLOCK, (u16)(DOL_CARD_SYSTEM_BLOCKS + (u32)file_no));
}

static void card_update_icon_offsets(CPUState* cpu, u32 address, const DolMemoryCardStat* stat) {
    u32 offset = stat->icon_address;
    bool icon_tlut = false;
    u8 banner_format = stat->banner_format & 3u;
    if (stat->icon_address == 0xFFFFFFFFu) {
        banner_format = 0;
        offset = 0;
    }

    if (banner_format == 1u) {
        mem_write32(cpu, address + CARD_STAT_OFFSET_BANNER, offset);
        offset += 96u * 32u;
        mem_write32(cpu, address + CARD_STAT_OFFSET_BANNER_TLUT, offset);
        offset += 2u * 256u;
    } else if (banner_format == 2u) {
        mem_write32(cpu, address + CARD_STAT_OFFSET_BANNER, offset);
        offset += 2u * 96u * 32u;
        mem_write32(cpu, address + CARD_STAT_OFFSET_BANNER_TLUT, 0xFFFFFFFFu);
    } else {
        mem_write32(cpu, address + CARD_STAT_OFFSET_BANNER, 0xFFFFFFFFu);
        mem_write32(cpu, address + CARD_STAT_OFFSET_BANNER_TLUT, 0xFFFFFFFFu);
    }

    for (u32 i = 0; i < 8u; i++) {
        u32 format = (stat->icon_format >> (2u * i)) & 3u;
        if (format == 1u) {
            mem_write32(cpu, address + CARD_STAT_OFFSET_ICON + i * 4u, offset);
            offset += 32u * 32u;
            icon_tlut = true;
        } else if (format == 2u) {
            mem_write32(cpu, address + CARD_STAT_OFFSET_ICON + i * 4u, offset);
            offset += 2u * 32u * 32u;
        } else {
            mem_write32(cpu, address + CARD_STAT_OFFSET_ICON + i * 4u, 0xFFFFFFFFu);
        }
    }
    if (icon_tlut) {
        mem_write32(cpu, address + CARD_STAT_OFFSET_ICON_TLUT, offset);
        offset += 2u * 256u;
    } else {
        mem_write32(cpu, address + CARD_STAT_OFFSET_ICON_TLUT, 0xFFFFFFFFu);
    }
    mem_write32(cpu, address + CARD_STAT_OFFSET_DATA, offset);
}

static void card_write_status(CPUState* cpu, u32 address, const DolMemoryCardStat* stat) {
    const bool has_icon_data = stat->icon_address != 0xFFFFFFFFu;
    for (u32 i = 0; i < DOL_CARD_FILENAME_MAX; i++)
        mem_write8(cpu, address + CARD_STAT_FILENAME + i, (u8)stat->file_name[i]);
    mem_write32(cpu, address + CARD_STAT_LENGTH, stat->length);
    mem_write32(cpu, address + CARD_STAT_TIME, stat->time);
    for (u32 i = 0; i < 4u; i++)
        mem_write8(cpu, address + CARD_STAT_GAME + i, stat->game_code[i]);
    for (u32 i = 0; i < 2u; i++)
        mem_write8(cpu, address + CARD_STAT_COMPANY + i, stat->company[i]);
    mem_write8(cpu, address + CARD_STAT_BANNER_FORMAT, has_icon_data ? stat->banner_format : 0);
    mem_write32(cpu, address + CARD_STAT_ICON_ADDRESS, stat->icon_address);
    mem_write16(cpu, address + CARD_STAT_ICON_FORMAT, has_icon_data ? stat->icon_format : 0);
    mem_write16(cpu, address + CARD_STAT_ICON_SPEED, has_icon_data ? stat->icon_speed : 0);
    mem_write32(cpu, address + CARD_STAT_COMMENT_ADDRESS, stat->comment_address);
    card_update_icon_offsets(cpu, address, stat);
}

static void card_read_status(CPUState* cpu, u32 address, DolMemoryCardStat* stat) {
    memset(stat, 0, sizeof(*stat));
    stat->banner_format = mem_read8(cpu, address + CARD_STAT_BANNER_FORMAT);
    stat->icon_address = mem_read32(cpu, address + CARD_STAT_ICON_ADDRESS);
    stat->icon_format = mem_read16(cpu, address + CARD_STAT_ICON_FORMAT);
    stat->icon_speed = mem_read16(cpu, address + CARD_STAT_ICON_SPEED);
    stat->comment_address = mem_read32(cpu, address + CARD_STAT_COMMENT_ADDRESS);
}

void dol_hle_CARDInit(CPUState* cpu) {
    (void)cpu;
}

void dol_hle_CARDProbe(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u16 size_mbits = 0;
    u32 sector_size = 0;
    hle_set_u32(cpu, dol_card_probe(card_for_channel(channel), &size_mbits, &sector_size) == DOL_CARD_RESULT_READY ? 1u : 0u);
}

void dol_hle_CARDProbeEx(CPUState* cpu) {
    static unsigned probe_log_count;
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 memory_size_address = hle_arg_u32(cpu, 1);
    u32 sector_size_address = hle_arg_u32(cpu, 2);
    DolMemoryCard* card = card_for_channel(channel);
    u16 size_mbits = 0;
    u32 sector_size = 0;
    s32 result = card != NULL ? dol_card_probe(card, &size_mbits, &sector_size)
                             : card_invalid_channel_result(channel);
    if (result == DOL_CARD_RESULT_READY) {
        if (memory_size_address != 0)
            mem_write32(cpu, memory_size_address, size_mbits);
        if (sector_size_address != 0)
            mem_write32(cpu, sector_size_address, sector_size);
    }
    if (g_card_log && (probe_log_count < 32u || (probe_log_count % 600u) == 0u))
        fprintf(stderr, "[card] CARDProbeEx channel=%d result=%d size=%u sector=%u\n",
                channel, result, size_mbits, sector_size);
    probe_log_count++;
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDGetResultCode(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    DolMemoryCard* card = card_for_channel(channel);
    hle_set_u32(cpu, (u32)(card != NULL ? dol_card_last_result(card)
                                        : card_invalid_channel_result(channel)));
}

void dol_hle_CARDGetFastMode(CPUState* cpu) {
    hle_set_u32(cpu, 0u);
}

void dol_hle_CARDGetXferredBytes(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    hle_set_u32(cpu, dol_card_transferred_bytes(card_for_channel(channel)));
}

void dol_hle_CARDUnmount(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_unmount(card) : card_invalid_channel_result(channel);
    if (g_card_log)
        fprintf(stderr, "[card] CARDUnmount channel=%d result=%d\n", channel, result);
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDClose(CPUState* cpu) {
    u32 file_info = hle_arg_u32(cpu, 0);
    s32 channel = file_info != 0 ? (s32)mem_read32(cpu, file_info + CARD_FILE_INFO_CHAN) : -1;
    s32 file_no = file_info != 0 ? (s32)mem_read32(cpu, file_info + CARD_FILE_INFO_FILENO) : -1;
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_close_file(card, file_no) : card_invalid_channel_result(channel);
    if (result == DOL_CARD_RESULT_READY)
        mem_write32(cpu, file_info + CARD_FILE_INFO_CHAN, 0xFFFFFFFFu);
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDMountAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 callback = hle_arg_u32(cpu, 3);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_mount(card) : card_invalid_channel_result(channel);
    if (g_card_log)
        fprintf(stderr, "[card] CARDMountAsync channel=%d result=%d callback=0x%08X\n",
                channel, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDCheckAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 callback = hle_arg_u32(cpu, 1);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_check(card) : card_invalid_channel_result(channel);
    if (g_card_log)
        fprintf(stderr, "[card] CARDCheckAsync channel=%d result=%d callback=0x%08X\n",
                channel, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDCheckExAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 transferred_address = hle_arg_u32(cpu, 1);
    u32 callback = hle_arg_u32(cpu, 2);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_check(card) : card_invalid_channel_result(channel);
    if (transferred_address != 0)
        mem_write32(cpu, transferred_address, 0);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDFreeBlocks(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 bytes_address = hle_arg_u32(cpu, 1);
    u32 files_address = hle_arg_u32(cpu, 2);
    DolMemoryCard* card = card_for_channel(channel);
    u32 bytes_free = 0;
    u32 files_free = 0;
    s32 result = card != NULL ? dol_card_free_space(card, &bytes_free, &files_free)
                             : card_invalid_channel_result(channel);
    if (result == DOL_CARD_RESULT_READY) {
        if (bytes_address != 0)
            mem_write32(cpu, bytes_address, bytes_free);
        if (files_address != 0)
            mem_write32(cpu, files_address, files_free);
    }
    if (g_card_log)
        fprintf(stderr, "[card] CARDFreeBlocks channel=%d result=%d bytes=%u files=%u\n",
                channel, result, bytes_free, files_free);
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDOpen(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 name_address = hle_arg_u32(cpu, 1);
    u32 file_info = hle_arg_u32(cpu, 2);
    char name[DOL_CARD_FILENAME_MAX + 2u];
    hle_read_cstr(cpu, name_address, name, sizeof name);
    DolMemoryCard* card = card_for_channel(channel);
    s32 file_no = -1;
    u32 length = 0;
    s32 result = card != NULL ? dol_card_open_file(card, name, &file_no, &length)
                             : card_invalid_channel_result(channel);
    (void)length;
    if (result == DOL_CARD_RESULT_READY && file_info != 0)
        card_write_file_info(cpu, file_info, channel, file_no);
    else if (file_info != 0)
        mem_write32(cpu, file_info + CARD_FILE_INFO_CHAN, 0xFFFFFFFFu);
    if (g_card_log)
        fprintf(stderr, "[card] CARDOpen channel=%d name='%s' result=%d file=%d length=%u\n",
                channel, name, result, file_no, length);
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDCreateAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 name_address = hle_arg_u32(cpu, 1);
    u32 length = hle_arg_u32(cpu, 2);
    u32 file_info = hle_arg_u32(cpu, 3);
    u32 callback = hle_arg_u32(cpu, 4);
    char name[DOL_CARD_FILENAME_MAX + 2u];
    hle_read_cstr(cpu, name_address, name, sizeof name);
    DolMemoryCard* card = card_for_channel(channel);
    s32 file_no = -1;
    s32 result = card != NULL ? dol_card_create_file(card, name, length, &file_no)
                             : card_invalid_channel_result(channel);
    if (result == DOL_CARD_RESULT_READY && file_info != 0)
        card_write_file_info(cpu, file_info, channel, file_no);
    if (g_card_log)
        fprintf(stderr, "[card] CARDCreateAsync channel=%d name='%s' length=%u result=%d file=%d callback=0x%08X\n",
                channel, name, length, result, file_no, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDDeleteAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 name_address = hle_arg_u32(cpu, 1);
    u32 callback = hle_arg_u32(cpu, 2);
    char name[DOL_CARD_FILENAME_MAX + 2u];
    hle_read_cstr(cpu, name_address, name, sizeof name);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_delete_file(card, name) : card_invalid_channel_result(channel);
    if (g_card_log)
        fprintf(stderr, "[card] CARDDeleteAsync channel=%d name='%s' result=%d callback=0x%08X\n",
                channel, name, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDReadAsync(CPUState* cpu) {
    u32 file_info = hle_arg_u32(cpu, 0);
    u32 buffer = hle_arg_u32(cpu, 1);
    u32 length = hle_arg_u32(cpu, 2);
    u32 offset = hle_arg_u32(cpu, 3);
    u32 callback = hle_arg_u32(cpu, 4);
    s32 channel = file_info != 0 ? (s32)mem_read32(cpu, file_info + CARD_FILE_INFO_CHAN) : -1;
    s32 file_no = file_info != 0 ? (s32)mem_read32(cpu, file_info + CARD_FILE_INFO_FILENO) : -1;
    DolMemoryCard* card = card_for_channel(channel);
    u8* bytes = length != 0 ? (u8*)malloc(length) : NULL;
    s32 result = length != 0 && bytes == NULL
                     ? DOL_CARD_RESULT_IO_ERROR
                     : (card != NULL ? dol_card_read_file(card, file_no, offset, bytes, length)
                                     : card_invalid_channel_result(channel));
    if (result == DOL_CARD_RESULT_READY)
        copy_host_to_guest(cpu, buffer, bytes, length);
    free(bytes);
    if (g_card_log)
        fprintf(stderr, "[card] CARDReadAsync channel=%d file=%d offset=%u length=%u result=%d callback=0x%08X\n",
                channel, file_no, offset, length, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDWriteAsync(CPUState* cpu) {
    u32 file_info = hle_arg_u32(cpu, 0);
    u32 buffer = hle_arg_u32(cpu, 1);
    u32 length = hle_arg_u32(cpu, 2);
    u32 offset = hle_arg_u32(cpu, 3);
    u32 callback = hle_arg_u32(cpu, 4);
    s32 channel = file_info != 0 ? (s32)mem_read32(cpu, file_info + CARD_FILE_INFO_CHAN) : -1;
    s32 file_no = file_info != 0 ? (s32)mem_read32(cpu, file_info + CARD_FILE_INFO_FILENO) : -1;
    DolMemoryCard* card = card_for_channel(channel);
    u8* bytes = length != 0 ? (u8*)malloc(length) : NULL;
    s32 result = length != 0 && bytes == NULL ? DOL_CARD_RESULT_IO_ERROR : DOL_CARD_RESULT_READY;
    if (result == DOL_CARD_RESULT_READY)
        copy_guest_to_host(cpu, buffer, bytes, length);
    if (result == DOL_CARD_RESULT_READY)
        result = card != NULL ? dol_card_write_file(card, file_no, offset, bytes, length)
                             : card_invalid_channel_result(channel);
    free(bytes);
    if (g_card_log)
        fprintf(stderr, "[card] CARDWriteAsync channel=%d file=%d offset=%u length=%u result=%d callback=0x%08X\n",
                channel, file_no, offset, length, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDGetStatus(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    s32 file_no = (s32)hle_arg_u32(cpu, 1);
    u32 status_address = hle_arg_u32(cpu, 2);
    DolMemoryCard* card = card_for_channel(channel);
    DolMemoryCardStat status;
    s32 result = card != NULL ? dol_card_get_status(card, file_no, &status)
                             : card_invalid_channel_result(channel);
    if (result == DOL_CARD_RESULT_READY && status_address != 0)
        card_write_status(cpu, status_address, &status);
    if (g_card_log)
        fprintf(stderr, "[card] CARDGetStatus channel=%d file=%d result=%d\n", channel, file_no, result);
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDSetStatusAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    s32 file_no = (s32)hle_arg_u32(cpu, 1);
    u32 status_address = hle_arg_u32(cpu, 2);
    u32 callback = hle_arg_u32(cpu, 3);
    DolMemoryCard* card = card_for_channel(channel);
    DolMemoryCardStat status;
    card_read_status(cpu, status_address, &status);
    s32 result;
    if ((status.icon_address != 0xFFFFFFFFu && status.icon_address >= 512u) ||
        (status.comment_address != 0xFFFFFFFFu && status.comment_address % DOL_CARD_SECTOR_SIZE > DOL_CARD_SECTOR_SIZE - 64u)) {
        result = DOL_CARD_RESULT_FATAL;
    } else {
        result = card != NULL ? dol_card_set_status(card, file_no, &status)
                             : card_invalid_channel_result(channel);
    }
    if (g_card_log)
        fprintf(stderr, "[card] CARDSetStatusAsync channel=%d file=%d result=%d callback=0x%08X\n",
                channel, file_no, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}

void dol_hle_CARDGetSerialNo(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 serial_address = hle_arg_u32(cpu, 1);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_check(card) : card_invalid_channel_result(channel);
    if (result == DOL_CARD_RESULT_READY && serial_address != 0)
        mem_write64(cpu, serial_address, dol_card_serial(card));
    hle_set_u32(cpu, (u32)result);
}

void dol_hle_CARDFormatAsync(CPUState* cpu) {
    s32 channel = (s32)hle_arg_u32(cpu, 0);
    u32 callback = hle_arg_u32(cpu, 1);
    DolMemoryCard* card = card_for_channel(channel);
    s32 result = card != NULL ? dol_card_format(card) : card_invalid_channel_result(channel);
    if (g_card_log)
        fprintf(stderr, "[card] CARDFormatAsync channel=%d result=%d callback=0x%08X\n",
                channel, result, callback);
    card_set_async_result(cpu, channel, result, callback);
}
