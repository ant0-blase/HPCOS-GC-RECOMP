// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/vi_clock.h"

#define DOL_VI_RETRACE_EVENT 1u

void dol_vi_clock_init(DolViClock* vi) {
    if (vi == NULL)
        return;
    dol_event_clock_init(&vi->events);
    dol_vi_clock_configure(vi, 1u, DOL_VI_DEFAULT_REFRESH_HZ,
                           DOL_VI_DEFAULT_TIMEBASE_HZ);
}

void dol_vi_clock_configure(DolViClock* vi, u64 work_units_per_retrace,
                            u32 refresh_hz, u64 timebase_hz) {
    if (vi == NULL)
        return;
    if (work_units_per_retrace == 0)
        work_units_per_retrace = 1;
    if (refresh_hz == 0)
        refresh_hz = DOL_VI_DEFAULT_REFRESH_HZ;
    if (timebase_hz == 0)
        timebase_hz = DOL_VI_DEFAULT_TIMEBASE_HZ;

    const u64 now = dol_event_clock_now(&vi->events);
    vi->work_units_per_retrace = work_units_per_retrace;
    vi->refresh_hz = refresh_hz;
    vi->timebase_hz = timebase_hz;
    vi->timebase_ticks_per_retrace = timebase_hz / (u64)refresh_hz;

    // Preserve elapsed work when reconfiguring, but reset the next retrace to
    // one full period from the current point. This matches the current
    // Strikers use: cadence is chosen during boot before work advances.
    dol_event_clock_init(&vi->events);
    dol_event_clock_advance(&vi->events, now);
    (void)dol_event_clock_schedule(&vi->events, DOL_VI_RETRACE_EVENT,
                                   work_units_per_retrace,
                                   work_units_per_retrace);
}

void dol_vi_clock_advance(DolViClock* vi, u64 work_units) {
    if (vi != NULL)
        dol_event_clock_advance(&vi->events, work_units);
}

bool dol_vi_clock_pop_retrace(DolViClock* vi, u64* timebase_ticks) {
    if (vi == NULL)
        return false;
    u32 id = 0;
    if (!dol_event_clock_pop_due(&vi->events, &id, NULL))
        return false;
    if (id != DOL_VI_RETRACE_EVENT)
        return false;
    if (timebase_ticks != NULL)
        *timebase_ticks = vi->timebase_ticks_per_retrace;
    return true;
}

u64 dol_vi_clock_now(const DolViClock* vi) {
    return vi != NULL ? dol_event_clock_now(&vi->events) : 0u;
}

u64 dol_vi_clock_work_units_per_retrace(const DolViClock* vi) {
    return vi != NULL ? vi->work_units_per_retrace : 0u;
}

u32 dol_vi_clock_refresh_hz(const DolViClock* vi) {
    return vi != NULL ? vi->refresh_hz : DOL_VI_DEFAULT_REFRESH_HZ;
}

u64 dol_vi_clock_timebase_ticks_per_retrace(const DolViClock* vi) {
    return vi != NULL ? vi->timebase_ticks_per_retrace : 0u;
}
