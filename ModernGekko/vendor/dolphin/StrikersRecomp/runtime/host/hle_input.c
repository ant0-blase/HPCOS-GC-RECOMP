#include "host/hle_input.h"
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

bool g_auto_input = false;
bool g_mash_to_gameplay = false;
bool g_mash_side_assigned = false;
bool g_mash_prematch = false;
bool g_mash_route_complete = false;

typedef struct {
    u64 start_frame;
    u64 end_frame; // exclusive
    u16 buttons;
    s8 stick_x;
    s8 stick_y;
    u8 analog_a;
} InputScriptEvent;

#define INPUT_SCRIPT_MAX_EVENTS 256u
#define INPUT_SCRIPT_MAX_TEXT   4096u

static InputScriptEvent g_input_script[INPUT_SCRIPT_MAX_EVENTS];
static unsigned g_input_script_count = 0;
static u64 g_input_script_last_log_frame = ~(u64)0;
static u16 g_input_script_last_buttons = 0;
static s8 g_input_script_last_stick_x = 0;
static s8 g_input_script_last_stick_y = 0;
static u8 g_input_script_last_analog_a = 0;

static char* input_script_trim(char* text) {
    while (*text == ' ' || *text == '\t' || *text == '\n' || *text == '\r')
        ++text;
    char* end = text + strlen(text);
    while (end > text) {
        char c = end[-1];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
            break;
        *--end = '\0';
    }
    return text;
}

void parse_input_script(const char* text) {
    g_input_script_count = 0;
    g_input_script_last_log_frame = ~(u64)0;
    g_input_script_last_buttons = 0;
    g_input_script_last_stick_x = 0;
    g_input_script_last_stick_y = 0;
    g_input_script_last_analog_a = 0;
    if (text == NULL || text[0] == '\0')
        return;
    char buffer[INPUT_SCRIPT_MAX_TEXT];
    strncpy(buffer, text, sizeof buffer - 1u);
    buffer[sizeof buffer - 1u] = '\0';
    unsigned skipped_events = 0;
    for (char* event = buffer; event != NULL && *event != '\0';) {
        char* next_event = strchr(event, ';');
        if (next_event != NULL) {
            *next_event = '\0';
            ++next_event;
        }
        event = input_script_trim(event);
        if (*event == '\0') {
            event = next_event;
            continue;
        }
        char* fields[6] = {0};
        unsigned field_count = 0;
        bool too_many_fields = false;
        for (char* field = event; field != NULL;) {
            char* next_field = strchr(field, ',');
            if (next_field != NULL) {
                *next_field = '\0';
                ++next_field;
            }
            if (field_count < 6u) {
                fields[field_count++] = input_script_trim(field);
            } else {
                too_many_fields = true;
            }
            field = next_field;
        }
        if (field_count < 3u || too_many_fields ||
            g_input_script_count >= INPUT_SCRIPT_MAX_EVENTS) {
            ++skipped_events;
            event = next_event;
            continue;
        }
        InputScriptEvent parsed;
        memset(&parsed, 0, sizeof parsed);
        parsed.start_frame = strtoull(fields[0], NULL, 0);
        parsed.end_frame = strtoull(fields[1], NULL, 0);
        parsed.buttons = (u16)strtoul(fields[2], NULL, 0);
        parsed.stick_x = field_count >= 4u ? (s8)strtol(fields[3], NULL, 0) : 0;
        parsed.stick_y = field_count >= 5u ? (s8)strtol(fields[4], NULL, 0) : 0;
        parsed.analog_a =
            field_count >= 6u ? (u8)strtoul(fields[5], NULL, 0)
                              : ((parsed.buttons & 0x0100u) ? 0xFFu : 0u);
        if (parsed.end_frame <= parsed.start_frame)
            parsed.end_frame = parsed.start_frame + 1u;
        if (parsed.buttons == 0u && parsed.stick_x == 0 && parsed.stick_y == 0 &&
            parsed.analog_a == 0u) {
            ++skipped_events;
            event = next_event;
            continue;
        }
        g_input_script[g_input_script_count++] = parsed;
        event = next_event;
    }
    fprintf(stderr, "[input] script events=%u skipped=%u\n",
            g_input_script_count, skipped_events);
}

bool input_script_apply(CPUState* cpu,
                        u16* buttons,
                        s8* stick_x,
                        s8* stick_y,
                        u8* analog_a) {
    if (g_input_script_count == 0u)
        return false;
    const u64 frame = cpu->timebase / 675000ull;
    bool active = false;
    for (unsigned i = 0; i < g_input_script_count; ++i) {
        const InputScriptEvent* event = &g_input_script[i];
        if (frame < event->start_frame || frame >= event->end_frame)
            continue;
        *buttons |= event->buttons;
        if (event->stick_x != 0)
            *stick_x = event->stick_x;
        if (event->stick_y != 0)
            *stick_y = event->stick_y;
        if (event->analog_a != 0u)
            *analog_a = event->analog_a;
        active = true;
    }
    if (active) {
        const bool continuation =
            g_input_script_last_log_frame + 1u == frame &&
            g_input_script_last_buttons == *buttons &&
            g_input_script_last_stick_x == *stick_x &&
            g_input_script_last_stick_y == *stick_y &&
            g_input_script_last_analog_a == *analog_a;
        g_input_script_last_log_frame = frame;
        g_input_script_last_buttons = *buttons;
        g_input_script_last_stick_x = *stick_x;
        g_input_script_last_stick_y = *stick_y;
        g_input_script_last_analog_a = *analog_a;
        if (continuation)
            return true;
        fprintf(stderr,
                "[input] script frame=%llu buttons=0x%04X stick=%d,%d analog_a=%u\n",
                (unsigned long long)frame, *buttons, *stick_x, *stick_y,
                (unsigned)*analog_a);
    }
    return active;
}

bool mash_to_gameplay_apply(CPUState* cpu,
                            u16* buttons,
                            s8* stick_x,
                            u8* analog_a) {
    if (!g_mash_to_gameplay || g_mash_route_complete)
        return false;
    if (g_mash_prematch) {
        static int s_cutscene_diag = -1;
        if (s_cutscene_diag < 0)
            s_cutscene_diag = getenv("STRIKERS_CUTSCENE_DIAG") != NULL ? 1 : 0;
        if (s_cutscene_diag)
            return false;
    }
    const u64 frame = cpu->timebase / 675000ull;
    if ((frame % 16u) >= 8u)
        return false;
    *buttons |= 0x0100u; // PAD_BUTTON_A
    if (!g_mash_prematch)
        *buttons |= 0x1000u; // PAD_BUTTON_START
    if (!g_mash_side_assigned) {
        *buttons |= 0x0001u; // PAD_BUTTON_LEFT
        *stick_x = -127;
    }
    *analog_a = 0xFFu;
    return true;
}
