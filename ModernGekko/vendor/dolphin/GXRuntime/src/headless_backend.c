// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/headless_backend.h"

#include <string.h>

static DolHeadlessBackend* g_active;

static bool hb_should_quit(void) {
    return g_active != NULL && g_active->should_quit;
}

static void hb_present(void) {
    if (g_active != NULL)
        g_active->present_count++;
}

static void hb_mark_gx_begin(void) {
    if (g_active != NULL)
        g_active->begin_count++;
}

// Graphics resource metadata and raw FIFO writes are deliberately no-ops: the
// provisional native-pointer surface is not recorded, and durable GX trace
// replay waits for the Aurora guest-memory/raw-FIFO resolver seam.

static bool hb_pad_init(void) {
    return true;
}

static u32 hb_pad_read(DolPadState state[4]) {
    if (g_active == NULL) {
        memset(state, 0, sizeof(*state) * 4u);
        return 0;
    }
    for (u32 i = 0; i < 4u; i++)
        state[i] = g_active->pad[i];
    g_active->pad_read_count++;
    return g_active->pad_mask;
}

static bool hb_pad_reset(u32 mask) {
    (void)mask;
    return true;
}

static bool hb_pad_recalibrate(u32 mask) {
    (void)mask;
    return true;
}

static void hb_configure_vi(u32 tv_mode, u16 fb_width, u16 efb_height,
                            u16 xfb_height, u16 vi_width, u16 vi_height) {
    if (g_active == NULL)
        return;
    g_active->configure_vi_count++;
    g_active->vi.tv_mode = tv_mode;
    g_active->vi.fb_width = fb_width;
    g_active->vi.efb_height = efb_height;
    g_active->vi.xfb_height = xfb_height;
    g_active->vi.vi_width = vi_width;
    g_active->vi.vi_height = vi_height;
}

static void hb_audio_set_sample_rate(u32 sample_rate) {
    if (g_active != NULL)
        g_active->audio_sample_rate = sample_rate;
}

static void hb_audio_push(const s16* samples, u32 frames) {
    (void)samples;
    if (g_active != NULL) {
        g_active->audio_frames += frames;
        g_active->audio_push_count++;
    }
}

static const DolPlatformOps k_ops = {
    .should_quit = hb_should_quit,
    .present = hb_present,
    .mark_gx_begin = hb_mark_gx_begin,
    .pad_init = hb_pad_init,
    .pad_read = hb_pad_read,
    .pad_reset = hb_pad_reset,
    .pad_recalibrate = hb_pad_recalibrate,
    .configure_vi = hb_configure_vi,
    .audio_set_sample_rate = hb_audio_set_sample_rate,
    .audio_push = hb_audio_push,
};

void dol_headless_backend_init(DolHeadlessBackend* backend) {
    if (backend == NULL)
        return;
    memset(backend, 0, sizeof(*backend));
}

const DolPlatformOps* dol_headless_backend_ops(void) {
    return &k_ops;
}

void dol_headless_backend_install(DolHeadlessBackend* backend) {
    g_active = backend;
    dol_platform_install(dol_headless_backend_ops());
}
