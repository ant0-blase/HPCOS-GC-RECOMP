#ifndef STRIKERSRECOMP_HOST_HLE_INPUT_H
#define STRIKERSRECOMP_HOST_HLE_INPUT_H

#include "core/cpu.h"

extern bool g_auto_input;
extern bool g_mash_to_gameplay;
extern bool g_mash_side_assigned;
extern bool g_mash_prematch;
extern bool g_mash_route_complete;

void parse_input_script(const char* text);
bool input_script_apply(CPUState* cpu, u16* buttons, s8* stick_x, s8* stick_y, u8* analog_a);
bool mash_to_gameplay_apply(CPUState* cpu, u16* buttons, s8* stick_x, u8* analog_a);

#endif // STRIKERSRECOMP_HOST_HLE_INPUT_H
