// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/event_clock.h"

#include <string.h>

void dol_event_clock_init(DolEventClock* clock) {
    if (clock != NULL)
        memset(clock, 0, sizeof(*clock));
}

u64 dol_event_clock_now(const DolEventClock* clock) {
    return clock != NULL ? clock->now : 0u;
}

void dol_event_clock_advance(DolEventClock* clock, u64 work_units) {
    if (clock != NULL)
        clock->now += work_units;
}

// Recompute the cached earliest active deadline. Called only from the rare
// mutation paths (schedule/cancel/pop), never from the per-dispatch fast path.
static void refresh_next_deadline(DolEventClock* clock) {
    bool found = false;
    u64 best = 0;
    for (u32 i = 0; i < DOL_EVENT_CLOCK_MAX_EVENTS; i++) {
        const DolEventClockEvent* event = &clock->events[i];
        if (!event->active)
            continue;
        if (!found || event->deadline < best) {
            best = event->deadline;
            found = true;
        }
    }
    clock->has_next = found;
    clock->next_deadline = best;
}

static DolEventClockEvent* find_event(DolEventClock* clock, u32 id) {
    if (clock == NULL)
        return NULL;
    for (u32 i = 0; i < DOL_EVENT_CLOCK_MAX_EVENTS; i++) {
        if (clock->events[i].active && clock->events[i].id == id)
            return &clock->events[i];
    }
    return NULL;
}

static const DolEventClockEvent* find_event_const(const DolEventClock* clock,
                                                  u32 id) {
    if (clock == NULL)
        return NULL;
    for (u32 i = 0; i < DOL_EVENT_CLOCK_MAX_EVENTS; i++) {
        if (clock->events[i].active && clock->events[i].id == id)
            return &clock->events[i];
    }
    return NULL;
}

bool dol_event_clock_schedule(DolEventClock* clock, u32 id, u64 delay,
                              u64 period) {
    if (clock == NULL)
        return false;

    DolEventClockEvent* event = find_event(clock, id);
    if (event == NULL) {
        for (u32 i = 0; i < DOL_EVENT_CLOCK_MAX_EVENTS; i++) {
            if (!clock->events[i].active) {
                event = &clock->events[i];
                break;
            }
        }
    }
    if (event == NULL)
        return false;

    event->id = id;
    event->deadline = clock->now + delay;
    event->period = period;
    event->active = true;
    refresh_next_deadline(clock);
    return true;
}

bool dol_event_clock_cancel(DolEventClock* clock, u32 id) {
    DolEventClockEvent* event = find_event(clock, id);
    if (event == NULL)
        return false;
    event->active = false;
    refresh_next_deadline(clock);
    return true;
}

bool dol_event_clock_is_scheduled(const DolEventClock* clock, u32 id) {
    return find_event_const(clock, id) != NULL;
}

bool dol_event_clock_next_deadline(const DolEventClock* clock, u64* deadline) {
    if (clock == NULL)
        return false;

    if (!clock->has_next)
        return false;
    if (deadline != NULL)
        *deadline = clock->next_deadline;
    return true;
}

bool dol_event_clock_pop_due(DolEventClock* clock, u32* id, u64* deadline) {
    if (clock == NULL)
        return false;

    // Fast path: nothing active, or the earliest deadline is still in the
    // future. This is the case on virtually every dispatch (a retrace fires once
    // per ~350k advances), so it must not touch the event array.
    if (!clock->has_next || clock->now < clock->next_deadline)
        return false;

    DolEventClockEvent* best = NULL;
    for (u32 i = 0; i < DOL_EVENT_CLOCK_MAX_EVENTS; i++) {
        DolEventClockEvent* event = &clock->events[i];
        if (!event->active || event->deadline > clock->now)
            continue;
        if (best == NULL || event->deadline < best->deadline)
            best = event;
    }
    if (best == NULL)
        return false;

    const u32 popped_id = best->id;
    const u64 popped_deadline = best->deadline;
    const u64 period = best->period;
    if (period != 0)
        best->deadline += period;
    else
        best->active = false;
    refresh_next_deadline(clock);

    if (id != NULL)
        *id = popped_id;
    if (deadline != NULL)
        *deadline = popped_deadline;
    return true;
}
