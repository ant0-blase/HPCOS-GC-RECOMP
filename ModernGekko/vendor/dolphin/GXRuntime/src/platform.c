// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/platform.h"

#include <string.h>

static DolPlatformOps g_ops;
static bool g_available;

void dol_platform_install(const DolPlatformOps* ops) {
    if (ops == NULL) {
        dol_platform_reset();
        return;
    }
    if (g_ops.set_guest_address_resolver != NULL)
        g_ops.set_guest_address_resolver(NULL, NULL);
    g_ops = *ops;
    g_available = true;
}

void dol_platform_reset(void) {
    if (g_ops.set_guest_address_resolver != NULL)
        g_ops.set_guest_address_resolver(NULL, NULL);
    memset(&g_ops, 0, sizeof(g_ops));
    g_available = false;
}

bool dol_platform_available(void) {
    return g_available;
}

bool dol_platform_should_quit(void) {
    return g_ops.should_quit != NULL && g_ops.should_quit();
}

void dol_platform_present(void) {
    if (g_ops.present != NULL)
        g_ops.present();
}

void dol_platform_mark_gx_begin(void) {
    if (g_ops.mark_gx_begin != NULL)
        g_ops.mark_gx_begin();
}

void dol_platform_gx_write(u64 value, u8 size) {
    if (g_ops.gx_write != NULL)
        g_ops.gx_write(value, size);
}

void dol_platform_call_display_list(const void* data, u32 size) {
    if (g_ops.call_display_list != NULL && data != NULL && size != 0)
        g_ops.call_display_list(data, size);
}

void dol_platform_set_array(u32 attr, const void* data, u32 size, u8 stride) {
    if (g_ops.set_array != NULL)
        g_ops.set_array(attr, data, size, stride);
}

void dol_platform_set_array_guest(u32 attr, u32 guest_address,
                                  const void* data, u32 size, u8 stride) {
    if (g_ops.set_array_guest != NULL)
        g_ops.set_array_guest(attr, guest_address, data, size, stride);
    else
        dol_platform_set_array(attr, data, size, stride);
}

void dol_platform_load_texture(u8 slot, const void* data, u32 width, u32 height,
                               u32 format, u32 tlut, bool mipmap,
                               u32 object_id, u32 data_version) {
    if (g_ops.load_texture != NULL)
        g_ops.load_texture(slot, data, width, height, format, tlut, mipmap,
                           object_id, data_version);
}

void dol_platform_load_texture_guest(u8 slot, u32 guest_address,
                                     const void* data, u32 width, u32 height,
                                     u32 format, u32 tlut, bool mipmap,
                                     u32 object_id, u32 data_version) {
    if (g_ops.load_texture_guest != NULL) {
        g_ops.load_texture_guest(slot, guest_address, data, width, height,
                                 format, tlut, mipmap, object_id,
                                 data_version);
    } else {
        dol_platform_load_texture(slot, data, width, height, format, tlut,
                                  mipmap, object_id, data_version);
    }
}

void dol_platform_load_tlut(u8 slot, const void* data, u32 format, u16 entries,
                            u32 object_id, u32 data_version) {
    if (g_ops.load_tlut != NULL)
        g_ops.load_tlut(slot, data, format, entries, object_id, data_version);
}

void dol_platform_load_tlut_guest(u8 slot, u32 guest_address,
                                  const void* data, u32 format, u16 entries,
                                  u32 object_id, u32 data_version) {
    if (g_ops.load_tlut_guest != NULL)
        g_ops.load_tlut_guest(slot, guest_address, data, format, entries,
                              object_id, data_version);
    else
        dol_platform_load_tlut(slot, data, format, entries, object_id,
                               data_version);
}

void dol_platform_set_copy_destination(const void* data) {
    if (g_ops.set_copy_destination != NULL)
        g_ops.set_copy_destination(data);
}

void dol_platform_set_copy_destination_guest(u32 guest_address,
                                             const void* data) {
    if (g_ops.set_copy_destination_guest != NULL)
        g_ops.set_copy_destination_guest(guest_address, data);
    else
        dol_platform_set_copy_destination(data);
}

void dol_platform_set_guest_address_resolver(
    DolPlatformGuestAddressResolverFn resolve, void* user) {
    if (g_ops.set_guest_address_resolver != NULL)
        g_ops.set_guest_address_resolver(resolve, user);
}

void dol_platform_configure_vi(u32 tv_mode, u16 fb_width, u16 efb_height,
                               u16 xfb_height, u16 vi_width, u16 vi_height) {
    if (g_ops.configure_vi != NULL)
        g_ops.configure_vi(tv_mode, fb_width, efb_height, xfb_height, vi_width,
                           vi_height);
}

bool dol_platform_pad_init(void) {
    return g_ops.pad_init != NULL && g_ops.pad_init();
}

u32 dol_platform_pad_read(DolPadState state[4]) {
    if (g_ops.pad_read != NULL)
        return g_ops.pad_read(state);
    memset(state, 0, sizeof(*state) * 4u);
    return 0;
}

bool dol_platform_pad_reset(u32 mask) {
    return g_ops.pad_reset == NULL || g_ops.pad_reset(mask);
}

bool dol_platform_pad_recalibrate(u32 mask) {
    return g_ops.pad_recalibrate == NULL || g_ops.pad_recalibrate(mask);
}

void dol_platform_pad_control_motor(u32 channel, u32 command) {
    if (g_ops.pad_control_motor != NULL)
        g_ops.pad_control_motor(channel, command);
}

void dol_platform_pad_set_spec(u32 spec) {
    if (g_ops.pad_set_spec != NULL)
        g_ops.pad_set_spec(spec);
}

void dol_platform_audio_set_sample_rate(u32 sample_rate) {
    if (g_ops.audio_set_sample_rate != NULL)
        g_ops.audio_set_sample_rate(sample_rate);
}

void dol_platform_audio_push(const s16* samples, u32 frames) {
    if (g_ops.audio_push != NULL)
        g_ops.audio_push(samples, frames);
}
