// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/DSPHLE/UCodes/Zelda.h"

namespace DSP::HLE
{

const std::map<u32, u32> UCODE_FLAGS = {
    // GameCube IPL/BIOS, NTSC.
    {0x24B22038, LIGHT_PROTOCOL | FOUR_MIXING_DESTS | TINY_VPB | VOLUME_EXPLICIT_STEP | NO_CMD_0D |
                     WEIRD_CMD_0C},
    // GameCube IPL/BIOS, PAL.
    {0x6BA3B3EA, LIGHT_PROTOCOL | FOUR_MIXING_DESTS | NO_CMD_0D},
    // Pikmin 1 GC NTSC Demo.
    {0xDF059F68, LIGHT_PROTOCOL | NO_CMD_0D | SUPPORTS_GBA_CRYPTO},
    // Pikmin 1 GC NTSC.
    // Animal Crossing.
    {0x4BE6A5CB, LIGHT_PROTOCOL | NO_CMD_0D | SUPPORTS_GBA_CRYPTO},
    // Luigi's Mansion.
    {0x42F64AC4, LIGHT_PROTOCOL | NO_CMD_0D | WEIRD_CMD_0C},
    // Pikmin 1 GC PAL.
    {0x267FD05A, SYNC_PER_FRAME | NO_CMD_0D},
    // Super Mario Sunshine.
    {0x56D36052, SYNC_PER_FRAME | NO_CMD_0D},
    // The Legend of Zelda: The Wind Waker.
    {0x86840740, 0},
    // The Legend of Zelda: Collector's Edition (except Wind Waker).
    // The Legend of Zelda: Four Swords Adventures.
    // Mario Kart: Double Dash.
    // Pikmin 2 GC NTSC.
    {0x2FCDF1EC, MAKE_DOLBY_LOUDER},
    // The Legend of Zelda: Twilight Princess / GC.
    // Donkey Kong Jungle Beat GC.
    //
    // TODO: These do additional filtering at frame rendering time. We don't
    // implement this yet.
    {0x6CA33A6D, MAKE_DOLBY_LOUDER | COMBINED_CMD_0D},
    // The Legend of Zelda: Twilight Princess / Wii.
    // Link's Crossbow Training.
    {0x6C3F6F94, NO_ARAM | MAKE_DOLBY_LOUDER | COMBINED_CMD_0D},
    // Super Mario Galaxy.
    // Super Mario Galaxy 2.
    // Donkey Kong Jungle Beat Wii.
    {0xD643001F, NO_ARAM | MAKE_DOLBY_LOUDER | COMBINED_CMD_0D},
    // Pikmin 1 NPC.
    {0xB7EB9A9C, NO_ARAM | MAKE_DOLBY_LOUDER | COMBINED_CMD_0D},
    // Pikmin 2 NPC.
    {0xEAEB38CC, NO_ARAM | MAKE_DOLBY_LOUDER | COMBINED_CMD_0D},
};

}  // namespace DSP::HLE
