// SPDX-License-Identifier: GPL-3.0-or-later
#include "aurora_backend_private.h"
#include <aurora/aurora.h>
#include <aurora/event.h>
#include <aurora/gfx.h>
#include <SDL3/SDL_init.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace gx_aurora {

bool g_initialized = false;
bool g_frame_open = false;
bool g_should_quit = false;
bool g_graphics_log = false;
bool g_force_untextured = false;
bool g_gx_core_enabled = true;
bool g_draw_opcode_pending = false;
bool g_audio_queue_log = false;
bool g_frame_pacing_log = false;
unsigned long long g_present_count = 0;
unsigned long long g_fifo_bytes = 0;
unsigned long long g_audio_push_count = 0;
unsigned long long g_audio_throttle_count = 0;
unsigned long long g_audio_low_log_push = 0;
u32 g_audio_sample_rate = 32000;
SDL_AudioStream* g_audio_stream = nullptr;
bool g_audio_playing = false;
int g_audio_prebuffer_ms = 40;
int g_audio_max_queue_ms = 250;
DolPlatformGuestAddressResolverFn g_guest_address_resolver = nullptr;
void* g_guest_address_resolver_user = nullptr;

std::array<PendingTextureMetadata, 8> g_pending_textures{};
std::array<PendingTlutMetadata, 20> g_pending_tluts{};

#if GXRUNTIME_HAS_AURORA_RECOMP
gxruntime::aurora_recomp::RetailGxFrontend g_shadow_frontend;
gxruntime::aurora_recomp::ConsumingAuroraRenderSink g_shadow_packet_sink;
bool g_shadow_frontend_enabled = false;
bool g_shadow_frontend_failed = false;
gxruntime::gxcore::GxCoreSink g_core_sink;
unsigned long long g_core_submitted = 0;
unsigned long long g_core_rejected = 0;

unsigned long long g_shadow_last_draw_total = 0;
unsigned long long g_shadow_last_vertex_total = 0;
unsigned long long g_shadow_draw_mismatch_frames = 0;
unsigned long long g_shadow_last_rawvert_total = 0;
unsigned long long g_shadow_last_topoidx_total = 0;
unsigned long long g_shadow_last_storage_total = 0;
unsigned long long g_shadow_vert_extent_mismatch_frames = 0;
unsigned long long g_shadow_last_zero_draw_total = 0;

bool g_shadow_prev_frame_valid = false;
unsigned long long g_shadow_prev_frame_index = 0;
unsigned long long g_shadow_prev_draws = 0;
unsigned long long g_shadow_prev_zero_draws = 0;
unsigned long long g_shadow_prev_verts = 0;
unsigned long long g_shadow_prev_rawvert = 0;
unsigned long long g_shadow_prev_topoidx = 0;
unsigned long long g_shadow_prev_storage = 0;

bool g_shadow_transform_log_enabled = false;
bool g_shadow_light_log_enabled = false;
bool g_shadow_light_log_lit_only = false;
bool g_shadow_transform_log_sequence_enabled = false;
unsigned long long g_shadow_transform_log_frame = 0;
unsigned long long g_shadow_transform_log_min_frame = 0;
long g_shadow_transform_log_draw = -1;
unsigned long long g_shadow_transform_log_sequence = 0;
unsigned long g_shadow_transform_log_limit = 1;
unsigned long g_shadow_transform_log_count = 0;
std::size_t g_shadow_transform_next_draw_index = 0;

bool g_trace_armed = false;
std::string g_trace_path;
unsigned long long g_trace_first_frame = 1ull;
unsigned long long g_trace_last_frame = ~0ull;
unsigned long long g_trace_present_scope_frame = 0ull;
bool g_trace_frame_begun = false;
unsigned long long g_trace_frames_recorded = 0ull;
gxruntime::aurora_recomp::trace::TraceWriter g_trace_writer;
std::unordered_map<u64, u64> g_trace_mem_dedup;
#endif

int audio_ms_env(const char* name, int fallback, int min_value, int max_value) {
    const char* text = std::getenv(name);
    if (text == nullptr || text[0] == '\0')
        return fallback;

    char* end = nullptr;
    long value = std::strtol(text, &end, 10);
    if (end == text)
        return fallback;
    if (value < min_value)
        value = min_value;
    if (value > max_value)
        value = max_value;
    return static_cast<int>(value);
}

unsigned long long ull_env(const char* name, unsigned long long fallback) {
    const char* text = std::getenv(name);
    if (text == nullptr || text[0] == '\0')
        return fallback;
    char* end = nullptr;
    const unsigned long long value = std::strtoull(text, &end, 10);
    return end == text ? fallback : value;
}

long long_env(const char* name, long fallback) {
    const char* text = std::getenv(name);
    if (text == nullptr || text[0] == '\0')
        return fallback;
    char* end = nullptr;
    const long value = std::strtol(text, &end, 10);
    return end == text ? fallback : value;
}

void log_callback(AuroraLogLevel level, const char* module, const char* message,
                  unsigned int) {
    const char* level_name = "info";
    switch (level) {
    case LOG_DEBUG:   level_name = "debug"; break;
    case LOG_INFO:    level_name = "info"; break;
    case LOG_WARNING: level_name = "warning"; break;
    case LOG_ERROR:   level_name = "error"; break;
    case LOG_FATAL:   level_name = "fatal"; break;
    }
    std::fprintf(level >= LOG_ERROR ? stderr : stdout, "[aurora:%s:%s] %s\n",
                 level_name, module ? module : "core", message ? message : "");
    if (level == LOG_FATAL)
        std::abort();
}

void poll_events() {
    const AuroraEvent* event = aurora_update();
    while (event != nullptr && event->type != AURORA_NONE) {
        if (event->type == AURORA_EXIT)
            g_should_quit = true;
        ++event;
    }
}

void install_platform_ops() {


    const DolPlatformOps ops = {
        .should_quit = aurora_backend_should_quit,
        .present = aurora_backend_present,
        .mark_gx_begin = aurora_backend_mark_gx_begin,
        .gx_write = aurora_backend_gx_write,
        .call_display_list = aurora_backend_call_display_list,
        .set_array = aurora_backend_set_array,
        .set_array_guest = aurora_backend_set_array_guest,
        .load_texture = aurora_backend_load_texture,
        .load_texture_guest = aurora_backend_load_texture_guest,
        .load_tlut = aurora_backend_load_tlut,
        .load_tlut_guest = aurora_backend_load_tlut_guest,
        .set_copy_destination = aurora_backend_set_copy_destination,
        .set_copy_destination_guest = aurora_backend_set_copy_destination_guest,
        .set_guest_address_resolver = aurora_backend_set_guest_address_resolver,
        .configure_vi = aurora_backend_configure_vi,

        .pad_init = aurora_backend_pad_init,
        .pad_read = aurora_backend_pad_read,
        .pad_reset = aurora_backend_pad_reset,
        .pad_recalibrate = aurora_backend_pad_recalibrate,
        .pad_control_motor = aurora_backend_pad_control_motor,
        .pad_set_spec = aurora_backend_pad_set_spec,

        .audio_set_sample_rate = aurora_backend_audio_set_sample_rate,
        .audio_push = aurora_backend_audio_push,
    };
    dol_platform_install(&ops);
}

} // namespace gx_aurora

extern "C" {

bool aurora_backend_should_quit(void) {
    return gx_aurora::g_should_quit;
}

bool dol_aurora_initialize(int argc, char** argv,
                           const AuroraBackendConfig* backend_config) {
    if (gx_aurora::g_initialized)
        return true;

    const AuroraBackendConfig defaults = {
        .app_name = "GXRuntime",
        .window_width = 1280,
        .window_height = 960,
        .vsync = true,
        .allow_texture_dumps = false,
        .info_logging = false,
        .graphics_logging = false,
        .force_untextured = false,
    };
    if (backend_config == nullptr)
        backend_config = &defaults;

    AuroraConfig config{};
    config.appName =
        backend_config->app_name != nullptr ? backend_config->app_name
                                            : defaults.app_name;
    config.desiredBackend = BACKEND_AUTO;
    config.vsync = backend_config->vsync;
    config.windowWidth = backend_config->window_width != 0
                             ? backend_config->window_width
                             : defaults.window_width;
    config.windowHeight = backend_config->window_height != 0
                              ? backend_config->window_height
                              : defaults.window_height;
    config.allowTextureDumps = backend_config->allow_texture_dumps;
    config.logCallback = gx_aurora::log_callback;
    config.logLevel = backend_config->info_logging ? LOG_INFO : LOG_ERROR;
    config.mem1Size = 0;
    config.mem2Size = 0;

    const AuroraInfo info = aurora_initialize(argc, argv, &config);
    gx_aurora::g_initialized = info.window != nullptr;
    if (!gx_aurora::g_initialized)
        return false;

    gx_aurora::g_graphics_log = backend_config->graphics_logging;
    gx_aurora::g_force_untextured = backend_config->force_untextured;
    gx_aurora::g_frame_pacing_log = std::getenv("DOL_FRAME_PACING_LOG") != nullptr;
#if GXRUNTIME_HAS_AURORA_RECOMP
    gx_aurora::g_shadow_light_log_enabled =
        std::getenv("DOL_AURORA_RECOMP_DRAW_LIGHT_LOG") != nullptr;
    gx_aurora::g_shadow_light_log_lit_only =
        std::getenv("DOL_AURORA_RECOMP_DRAW_LIGHT_LIT_ONLY") != nullptr;
    gx_aurora::g_shadow_transform_log_enabled =
        std::getenv("DOL_AURORA_RECOMP_DRAW_TRANSFORM_LOG") != nullptr ||
        gx_aurora::g_shadow_light_log_enabled;
    gx_aurora::g_shadow_transform_log_frame =
        gx_aurora::ull_env("DOL_AURORA_RECOMP_DRAW_TRANSFORM_FRAME", 0ull);
    gx_aurora::g_shadow_transform_log_min_frame =
        gx_aurora::ull_env("DOL_AURORA_RECOMP_DRAW_TRANSFORM_MIN_FRAME", 0ull);
    gx_aurora::g_shadow_transform_log_draw =
        gx_aurora::long_env("DOL_AURORA_RECOMP_DRAW_TRANSFORM_DRAW", -1);
    const char* transform_sequence =
        std::getenv("DOL_AURORA_RECOMP_DRAW_TRANSFORM_SEQUENCE");
    gx_aurora::g_shadow_transform_log_sequence_enabled =
        transform_sequence != nullptr && transform_sequence[0] != '\0';
    gx_aurora::g_shadow_transform_log_sequence =
        gx_aurora::ull_env("DOL_AURORA_RECOMP_DRAW_TRANSFORM_SEQUENCE", 0ull);
    gx_aurora::g_shadow_transform_log_limit = static_cast<unsigned long>(
        gx_aurora::ull_env("DOL_AURORA_RECOMP_DRAW_TRANSFORM_LIMIT", 1ull));
    if (gx_aurora::g_shadow_transform_log_limit == 0ul)
        gx_aurora::g_shadow_transform_log_limit = 1ul;
    gx_aurora::g_shadow_transform_log_count = 0;
    gx_aurora::g_shadow_transform_next_draw_index = 0;
    gx_aurora::g_trace_armed = false;
    gx_aurora::g_trace_path.clear();
    gx_aurora::g_trace_first_frame = 1ull;
    gx_aurora::g_trace_last_frame = ~0ull;
    gx_aurora::g_trace_present_scope_frame = 0ull;
    gx_aurora::g_trace_frame_begun = false;
    gx_aurora::g_trace_frames_recorded = 0ull;
    gx_aurora::g_trace_mem_dedup.clear();
    const char* trace_out = std::getenv("DOL_AURORA_RECOMP_TRACE_OUT");
    if (trace_out != nullptr && trace_out[0] != '\0') {
        gx_aurora::g_trace_path = trace_out;
        gx_aurora::g_trace_armed = true;
        const char* trace_window =
            std::getenv("DOL_AURORA_RECOMP_TRACE_FRAMES");
        if (trace_window != nullptr && trace_window[0] != '\0') {
            char* end = nullptr;
            const unsigned long long first =
                std::strtoull(trace_window, &end, 10);
            bool window_ok = end != trace_window && *end == ':';
            if (window_ok) {
                const char* second = end + 1;
                char* end2 = nullptr;
                const unsigned long long last =
                    std::strtoull(second, &end2, 10);
                window_ok = end2 != second && *end2 == '\0' && last >= first;
                if (window_ok) {
                    gx_aurora::g_trace_first_frame = first == 0ull ? 1ull : first;
                    gx_aurora::g_trace_last_frame = last;
                }
            }
            if (!window_ok)
                std::fprintf(stderr,
                             "[trace] ignoring malformed "
                             "DOL_AURORA_RECOMP_TRACE_FRAMES=%s (want A:B); "
                             "recording all frames\n",
                             trace_window);
        }
        std::fprintf(stderr, "[trace] recording armed path=%s frames=%llu:%llu\n",
                     gx_aurora::g_trace_path.c_str(), gx_aurora::g_trace_first_frame,
                     gx_aurora::g_trace_last_frame);
    }
    {
        const char* core_env = std::getenv("DOL_GX_CORE");
        gx_aurora::g_gx_core_enabled = !(core_env != nullptr && core_env[0] == '0');
    }
    gx_aurora::g_shadow_frontend_enabled =
        std::getenv("DOL_AURORA_RECOMP_FRONTEND_SHADOW") != nullptr ||
        gx_aurora::g_shadow_transform_log_enabled || gx_aurora::g_trace_armed || gx_aurora::g_gx_core_enabled;
    if (gx_aurora::g_gx_core_enabled) {
        gx_aurora::g_core_sink.set_plan_observer(gx_aurora::core_plan_observer, nullptr);
        gx_aurora::g_core_sink.set_copy_observer(gx_aurora::core_copy_observer, nullptr);
        gx_aurora::g_core_submitted = 0;
        gx_aurora::g_core_rejected = 0;
        aurora::gfx::gxcore::reset_texture_cache();
        std::fprintf(stderr,
                     "[gx-core] renderer = gxcore (default): draws route "
                     "through the Dolphin-ported gxcore, live Aurora gx layer "
                     "bypassed\n");
    }
    gx_aurora::g_shadow_frontend_failed = false;
    gx_aurora::g_shadow_frontend.reset(nullptr);
    gx_aurora::g_shadow_frontend.set_packet_drain_enabled(gx_aurora::g_shadow_frontend_enabled);
    gx_aurora::g_shadow_packet_sink.reset();
    gx_aurora::g_shadow_packet_sink.set_streaming(true);
    gx_aurora::g_shadow_packet_sink.set_draw_observer(
        gx_aurora::g_shadow_transform_log_enabled ? gx_aurora::shadow_transform_observer : nullptr,
        nullptr);
    gx_aurora::g_shadow_last_draw_total = 0;
    gx_aurora::g_shadow_last_vertex_total = 0;
    gx_aurora::g_shadow_draw_mismatch_frames = 0;
    gx_aurora::g_shadow_last_rawvert_total = 0;
    gx_aurora::g_shadow_last_topoidx_total = 0;
    gx_aurora::g_shadow_last_storage_total = 0;
    gx_aurora::g_shadow_vert_extent_mismatch_frames = 0;
    gx_aurora::g_shadow_last_zero_draw_total = 0;
    gx_aurora::g_shadow_prev_frame_valid = false;
    if (gx_aurora::g_shadow_transform_log_enabled) {
        if (gx_aurora::g_shadow_transform_log_sequence_enabled) {
            std::fprintf(stderr,
                         "[gfx] draw-transform log enabled frame=%llu "
                         "draw=%ld min_frame=%llu sequence=%llu limit=%lu\n",
                         gx_aurora::g_shadow_transform_log_frame,
                         gx_aurora::g_shadow_transform_log_draw,
                         gx_aurora::g_shadow_transform_log_min_frame,
                         gx_aurora::g_shadow_transform_log_sequence,
                         gx_aurora::g_shadow_transform_log_limit);
        } else {
            std::fprintf(stderr,
                         "[gfx] draw-transform log enabled frame=%llu "
                         "draw=%ld min_frame=%llu sequence=any limit=%lu\n",
                         gx_aurora::g_shadow_transform_log_frame,
                         gx_aurora::g_shadow_transform_log_draw,
                         gx_aurora::g_shadow_transform_log_min_frame,
                         gx_aurora::g_shadow_transform_log_limit);
        }
    }
#endif
    gx_aurora::g_audio_queue_log = std::getenv("DOL_AUDIO_QUEUE_LOG") != nullptr;
    gx_aurora::g_audio_prebuffer_ms = gx_aurora::audio_ms_env("DOL_AUDIO_PREBUFFER_MS", 40, 20, 500);
    gx_aurora::g_audio_max_queue_ms =
        gx_aurora::audio_ms_env("DOL_AUDIO_MAX_QUEUE_MS", 250, gx_aurora::g_audio_prebuffer_ms, 1000);
    gx_aurora::g_audio_push_count = 0;
    gx_aurora::g_audio_throttle_count = 0;
    gx_aurora::g_audio_low_log_push = 0;
    gx_aurora::g_audio_sample_rate = 32000;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO)) {
        SDL_AudioSpec spec{};
        spec.format = SDL_AUDIO_S16;
        spec.channels = 2;
        spec.freq = static_cast<int>(gx_aurora::g_audio_sample_rate);
        gx_aurora::g_audio_stream = SDL_OpenAudioDeviceStream(
            SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, nullptr, nullptr);
        if (gx_aurora::g_audio_stream == nullptr)
            std::fprintf(stderr, "[audio] SDL output unavailable: %s\n", SDL_GetError());
        else if (gx_aurora::g_audio_queue_log)
            std::fprintf(stderr, "[audio-queue] prebuffer_ms=%d max_queue_ms=%d\n",
                         gx_aurora::g_audio_prebuffer_ms, gx_aurora::g_audio_max_queue_ms);
    } else {
        std::fprintf(stderr, "[audio] SDL audio initialization failed: %s\n", SDL_GetError());
    }

    gx_aurora::poll_events();
    gx_aurora::g_frame_open = !gx_aurora::g_should_quit && aurora_begin_frame();
    gx_aurora::install_platform_ops();
    return true;
}

void dol_aurora_shutdown(void) {
    if (!gx_aurora::g_initialized)
        return;
    dol_platform_reset();
    if (gx_aurora::g_frame_open) {
        aurora_end_frame();
        gx_aurora::g_frame_open = false;
    }
#if GXRUNTIME_HAS_AURORA_RECOMP
    gx_aurora::trace_close_and_log();
    if (gx_aurora::g_gx_core_enabled) {
        std::fprintf(stderr,
                     "[gx-core] shutdown: submitted=%llu rejected=%llu "
                     "failed=%d\n",
                     gx_aurora::g_core_submitted, gx_aurora::g_core_rejected,
                     gx_aurora::g_shadow_frontend_failed ? 1 : 0);
    }
#endif
    if (gx_aurora::g_audio_stream != nullptr) {
        SDL_DestroyAudioStream(gx_aurora::g_audio_stream);
        gx_aurora::g_audio_stream = nullptr;
        gx_aurora::g_audio_playing = false;
    }
    aurora_shutdown();
    gx_aurora::g_pending_textures = {};
    gx_aurora::g_pending_tluts = {};
    gx_aurora::g_draw_opcode_pending = false;
    gx_aurora::g_initialized = false;
}

} // extern "C"
