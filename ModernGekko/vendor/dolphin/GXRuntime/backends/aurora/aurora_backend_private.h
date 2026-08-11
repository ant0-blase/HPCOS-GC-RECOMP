// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef AURORA_BACKEND_PRIVATE_H
#define AURORA_BACKEND_PRIVATE_H

#include "gxruntime/aurora_backend.h"
#include "gxruntime/platform.h"
#include <SDL3/SDL_audio.h>
#include <array>
#include <string>
#include <unordered_map>

#if GXRUNTIME_HAS_AURORA_RECOMP
#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"
#include "gxruntime/aurora_recomp/trace.hpp"
#include "gxruntime/gxcore/gxcore.hpp"
#endif

#include <gx/fifo.hpp>
#include <gx/gx.hpp>
#include <gx/recomp.hpp>

#if GXRUNTIME_HAS_AURORA_RECOMP
namespace aurora::gfx::gxcore {
bool submit_draw_plan(const gxruntime::gxcore::DrawPlan& plan);
void copy_efb_to_texture(const gxruntime::gxcore::EfbCopyCommand& cmd);
void reset_texture_cache();
}
#endif

namespace gx_aurora {

extern bool g_initialized;
extern bool g_frame_open;
extern bool g_should_quit;
extern bool g_graphics_log;
extern bool g_force_untextured;
extern bool g_gx_core_enabled;
extern bool g_draw_opcode_pending;
extern bool g_audio_queue_log;
extern bool g_frame_pacing_log;
extern unsigned long long g_present_count;
extern unsigned long long g_fifo_bytes;
extern unsigned long long g_audio_push_count;
extern unsigned long long g_audio_throttle_count;
extern unsigned long long g_audio_low_log_push;
extern u32 g_audio_sample_rate;
extern SDL_AudioStream* g_audio_stream;
extern bool g_audio_playing;
extern int g_audio_prebuffer_ms;
extern int g_audio_max_queue_ms;
extern DolPlatformGuestAddressResolverFn g_guest_address_resolver;
extern void* g_guest_address_resolver_user;

struct PendingTextureMetadata {
    bool valid = false;
    const void* data = nullptr;
    u32 width = 0;
    u32 height = 0;
    u32 format = 0;
    u32 tlut = 0;
    bool mipmap = false;
    u32 object_id = 0;
    u32 data_version = 0;
};

struct PendingTlutMetadata {
    bool valid = false;
    const void* data = nullptr;
    u32 format = 0;
    u16 entries = 0;
    u32 object_id = 0;
    u32 data_version = 0;
};

extern std::array<PendingTextureMetadata, 8> g_pending_textures;
extern std::array<PendingTlutMetadata, 20> g_pending_tluts;

#if GXRUNTIME_HAS_AURORA_RECOMP
extern gxruntime::aurora_recomp::RetailGxFrontend g_shadow_frontend;
extern gxruntime::aurora_recomp::ConsumingAuroraRenderSink g_shadow_packet_sink;
extern bool g_shadow_frontend_enabled;
extern bool g_shadow_frontend_failed;
extern gxruntime::gxcore::GxCoreSink g_core_sink;
extern unsigned long long g_core_submitted;
extern unsigned long long g_core_rejected;



void core_plan_observer(const gxruntime::gxcore::DrawPlan& plan, void*);
void core_copy_observer(const gxruntime::gxcore::EfbCopyCommand& cmd, void*);

extern unsigned long long g_shadow_last_draw_total;
extern unsigned long long g_shadow_last_vertex_total;
extern unsigned long long g_shadow_draw_mismatch_frames;
extern unsigned long long g_shadow_last_rawvert_total;
extern unsigned long long g_shadow_last_topoidx_total;
extern unsigned long long g_shadow_last_storage_total;
extern unsigned long long g_shadow_vert_extent_mismatch_frames;
extern unsigned long long g_shadow_last_zero_draw_total;

extern bool g_shadow_prev_frame_valid;
extern unsigned long long g_shadow_prev_frame_index;
extern unsigned long long g_shadow_prev_draws;
extern unsigned long long g_shadow_prev_zero_draws;
extern unsigned long long g_shadow_prev_verts;
extern unsigned long long g_shadow_prev_rawvert;
extern unsigned long long g_shadow_prev_topoidx;
extern unsigned long long g_shadow_prev_storage;

extern bool g_shadow_transform_log_enabled;
extern bool g_shadow_light_log_enabled;
extern bool g_shadow_light_log_lit_only;
extern bool g_shadow_transform_log_sequence_enabled;
extern unsigned long long g_shadow_transform_log_frame;
extern unsigned long long g_shadow_transform_log_min_frame;
extern long g_shadow_transform_log_draw;
extern unsigned long long g_shadow_transform_log_sequence;
extern unsigned long g_shadow_transform_log_limit;
extern unsigned long g_shadow_transform_log_count;
extern std::size_t g_shadow_transform_next_draw_index;

extern bool g_trace_armed;
extern std::string g_trace_path;
extern unsigned long long g_trace_first_frame;
extern unsigned long long g_trace_last_frame;
extern unsigned long long g_trace_present_scope_frame;
extern bool g_trace_frame_begun;
extern unsigned long long g_trace_frames_recorded;
extern gxruntime::aurora_recomp::trace::TraceWriter g_trace_writer;
extern std::unordered_map<u64, u64> g_trace_mem_dedup;

unsigned long long trace_current_frame();
bool trace_open_now();
bool trace_should_record();
void trace_record_mem_update(u32 address, u32 size, const void* data);
void trace_close_and_log();
void trace_on_present();

void shadow_frontend_fail_metadata(const char* reason, u32 attr, u32 guest_address, u32 value);
void shadow_frontend_set_array(u32 attr, u32 guest_address, u8 stride);
bool frontend_guest_address_resolver_bridge(void*, u32 address, u32 size, DolGuestAddressSpace space, DolGuestResourceKind resource, DolGuestResolvedRange* out);
void shadow_frontend_call_display_list(const void* data, u32 size);
void shadow_frontend_write(u64 value, u8 size);
unsigned long long shadow_transform_frame_number();
void log_transform_matrix(const char* label, unsigned index, const float* values);
void shadow_transform_observer(const gxruntime::aurora_recomp::ConsumedDraw& draw, unsigned long long cumulative_draw, void*);
#endif

// Shared utility helpers
int audio_ms_env(const char* name, int fallback, int min_value, int max_value);
unsigned long long ull_env(const char* name, unsigned long long fallback);
long long_env(const char* name, long fallback);
void log_callback(AuroraLogLevel level, const char* module, const char* message, unsigned int);
void poll_events();
void write_aurora_command(u16 command);
void flush_pending_resource_metadata();
bool gx_attr_to_cp_array(u32 attr, u8* out);
DolGuestAddressSpace map_address_space(aurora::gx::recomp::AddressSpace space);
DolGuestResourceKind map_resource_kind(aurora::gx::recomp::ResourceKind kind);
bool aurora_guest_address_resolver_bridge(void*, std::uint32_t address, std::uint32_t size, aurora::gx::recomp::AddressSpace space, aurora::gx::recomp::ResourceKind resource, const void** data, std::uint32_t* available);

void install_platform_ops();

} // namespace gx_aurora

extern "C" {
bool aurora_backend_should_quit(void);
void aurora_backend_present(void);
void aurora_backend_mark_gx_begin(void);
void aurora_backend_gx_write(u64 value, u8 size);
void aurora_backend_call_display_list(const void* data, u32 size);
void aurora_backend_set_array(u32 attr, const void* data, u32 size, u8 stride);
void aurora_backend_set_array_guest(u32 attr, u32 guest_address, const void* data, u32 size, u8 stride);
void aurora_backend_load_texture(u8 slot, const void* data, u32 width, u32 height, u32 format, u32 tlut, bool mipmap, u32 object_id, u32 data_version);
void aurora_backend_load_texture_guest(u8 slot, u32 guest_address, const void* data, u32 width, u32 height, u32 format, u32 tlut, bool mipmap, u32 object_id, u32 data_version);
void aurora_backend_load_tlut(u8 slot, const void* data, u32 format, u16 entries, u32 object_id, u32 data_version);
void aurora_backend_load_tlut_guest(u8 slot, u32 guest_address, const void* data, u32 format, u16 entries, u32 object_id, u32 data_version);
void aurora_backend_set_copy_destination(const void* data);
void aurora_backend_set_copy_destination_guest(u32 guest_address, const void* data);
void aurora_backend_set_guest_address_resolver(DolPlatformGuestAddressResolverFn resolve, void* user);
void aurora_backend_configure_vi(u32 tv_mode, u16 fb_width, u16 efb_height, u16 xfb_height, u16 vi_width, u16 vi_height);

bool aurora_backend_pad_init(void);
u32 aurora_backend_pad_read(DolPadState state[4]);
bool aurora_backend_pad_reset(u32 mask);
bool aurora_backend_pad_recalibrate(u32 mask);
void aurora_backend_pad_control_motor(u32 channel, u32 command);
void aurora_backend_pad_set_spec(u32 spec);

void aurora_backend_audio_set_sample_rate(u32 sample_rate);
void aurora_backend_audio_push(const s16* samples, u32 frames);
}

#endif // AURORA_BACKEND_PRIVATE_H
