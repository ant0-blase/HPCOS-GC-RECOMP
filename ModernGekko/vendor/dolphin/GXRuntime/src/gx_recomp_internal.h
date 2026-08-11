// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef GX_RECOMP_INTERNAL_H
#define GX_RECOMP_INTERNAL_H

#include "gxruntime/gx_recomp.h"

void dol_gx_recomp_trace_event(DolGxRecompState* gx, DolGxRecompEventKind kind,
                               u32 a, u32 b, u32 c, u32 d);

u8 dol_gx_recomp_image0_reg_for_slot(u8 slot);
u8 dol_gx_recomp_image3_reg_for_slot(u8 slot);
bool dol_gx_recomp_map_image0_reg(u8 reg, u8* slot);
bool dol_gx_recomp_map_image3_reg(u8 reg, u8* slot);
bool dol_gx_recomp_map_tlut_reg(u8 reg, u8* slot);
u32 dol_gx_recomp_copy_trigger_texture_format(u32 value);

#endif // GX_RECOMP_INTERNAL_H
