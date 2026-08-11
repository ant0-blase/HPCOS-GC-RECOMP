// SPDX-License-Identifier: GPL-3.0-or-later
#include "aurora_backend_private.h"
#include <dolphin/pad.h>
#include <SDL3/SDL_scancode.h>
#include <cstring>

extern "C" {

bool aurora_backend_pad_init(void) {
    if (PADInit() == FALSE)
        return false;

    // Force Aurora to load any persisted keyboard mapping first. Install a
    // usable port-0 fallback only when the user has not configured one.
    PADStatus initial[4]{};
    (void)PADRead(initial);
    u32 count = 0;
    if (PADGetKeyButtonBindings(0, &count) == nullptr) {
        PADKeyButtonBinding buttons[PAD_BUTTON_COUNT] = {
            {SDL_SCANCODE_LEFT,   PAD_BUTTON_LEFT},
            {SDL_SCANCODE_RIGHT,  PAD_BUTTON_RIGHT},
            {SDL_SCANCODE_DOWN,   PAD_BUTTON_DOWN},
            {SDL_SCANCODE_UP,     PAD_BUTTON_UP},
            {SDL_SCANCODE_Q,      PAD_TRIGGER_Z},
            {SDL_SCANCODE_R,      PAD_TRIGGER_R},
            {SDL_SCANCODE_E,      PAD_TRIGGER_L},
            {SDL_SCANCODE_J,      PAD_BUTTON_A},
            {SDL_SCANCODE_K,      PAD_BUTTON_B},
            {SDL_SCANCODE_U,      PAD_BUTTON_X},
            {SDL_SCANCODE_I,      PAD_BUTTON_Y},
            {SDL_SCANCODE_RETURN, PAD_BUTTON_START},
        };
        PADKeyAxisBinding axes[PAD_AXIS_COUNT] = {
            {SDL_SCANCODE_D, PAD_AXIS_LEFT_X_POS, 32767},
            {SDL_SCANCODE_A, PAD_AXIS_LEFT_X_NEG, 32767},
            {SDL_SCANCODE_W, PAD_AXIS_LEFT_Y_POS, 32767},
            {SDL_SCANCODE_S, PAD_AXIS_LEFT_Y_NEG, 32767},
            {SDL_SCANCODE_H, PAD_AXIS_RIGHT_X_POS, 32767},
            {SDL_SCANCODE_F, PAD_AXIS_RIGHT_X_NEG, 32767},
            {SDL_SCANCODE_T, PAD_AXIS_RIGHT_Y_POS, 32767},
            {SDL_SCANCODE_G, PAD_AXIS_RIGHT_Y_NEG, 32767},
            {SDL_SCANCODE_E, PAD_AXIS_TRIGGER_L, 32767},
            {SDL_SCANCODE_R, PAD_AXIS_TRIGGER_R, 32767},
        };
        PADSetKeyButtonBindings(0, buttons);
        PADSetKeyAxisBindings(0, axes);
        PADSetKeyboardActive(0, TRUE);
    }
    return true;
}

u32 aurora_backend_pad_read(DolPadState state[4]) {
    PADStatus status[4]{};
    const u32 motor_mask = PADRead(status);
    for (u32 i = 0; i < 4; i++) {
        state[i] = {
            .button = status[i].button,
            .stick_x = status[i].stickX,
            .stick_y = status[i].stickY,
            .substick_x = status[i].substickX,
            .substick_y = status[i].substickY,
            .trigger_left = status[i].triggerLeft,
            .trigger_right = status[i].triggerRight,
            .analog_a = status[i].analogA,
            .analog_b = status[i].analogB,
            .error = status[i].err,
        };
    }
    return motor_mask;
}

bool aurora_backend_pad_reset(u32 mask) {
    return PADReset(mask) != FALSE;
}

bool aurora_backend_pad_recalibrate(u32 mask) {
    return PADRecalibrate(mask) != FALSE;
}

void aurora_backend_pad_control_motor(u32 channel, u32 command) {
    PADControlMotor(channel, command);
}

void aurora_backend_pad_set_spec(u32 spec) {
    PADSetSpec(spec);
}

} // extern "C"
