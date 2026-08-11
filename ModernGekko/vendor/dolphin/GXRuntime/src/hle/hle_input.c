// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/hle.h"
#include "gxruntime/hle_abi.h"
#include "gxruntime/platform.h"
#include <string.h>

void dol_hle_PADInit(CPUState* cpu) {
    hle_set_u32(cpu, dol_platform_pad_init() ? 1u : 0u);
}

void dol_hle_PADRead(CPUState* cpu) {
    u32 out = hle_arg_u32(cpu, 0);
    DolPadState state[4];
    memset(state, 0, sizeof state);
    u32 motor_mask = dol_platform_pad_read(state);

    for (u32 i = 0; i < 4; i++) {
        u32 p = out + i * 12u;
        mem_write16(cpu, p, state[i].button);
        mem_write8(cpu, p + 2u, (u8)state[i].stick_x);
        mem_write8(cpu, p + 3u, (u8)state[i].stick_y);
        mem_write8(cpu, p + 4u, (u8)state[i].substick_x);
        mem_write8(cpu, p + 5u, (u8)state[i].substick_y);
        mem_write8(cpu, p + 6u, state[i].trigger_left);
        mem_write8(cpu, p + 7u, state[i].trigger_right);
        mem_write8(cpu, p + 8u, state[i].analog_a);
        mem_write8(cpu, p + 9u, state[i].analog_b);
        mem_write8(cpu, p + 10u, (u8)state[i].error);
        mem_write8(cpu, p + 11u, 0);
    }
    hle_set_u32(cpu, motor_mask);
}

void dol_hle_PADReset(CPUState* cpu) {
    hle_set_u32(cpu, dol_platform_pad_reset(hle_arg_u32(cpu, 0)) ? 1u : 0u);
}

void dol_hle_PADRecalibrate(CPUState* cpu) {
    hle_set_u32(cpu, dol_platform_pad_recalibrate(hle_arg_u32(cpu, 0)) ? 1u : 0u);
}

void dol_hle_PADControlMotor(CPUState* cpu) {
    dol_platform_pad_control_motor(hle_arg_u32(cpu, 0), hle_arg_u32(cpu, 1));
}

void dol_hle_PADSetSpec(CPUState* cpu) {
    dol_platform_pad_set_spec(hle_arg_u32(cpu, 0));
}
