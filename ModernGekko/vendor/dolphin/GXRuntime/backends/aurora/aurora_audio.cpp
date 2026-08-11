// SPDX-License-Identifier: GPL-3.0-or-later
#include "aurora_backend_private.h"
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_timer.h>
#include <cstdio>

extern "C" {

void aurora_backend_audio_set_sample_rate(u32 sample_rate) {
    if (sample_rate != 48000)
        sample_rate = 32000;
    if (gx_aurora::g_audio_sample_rate == sample_rate)
        return;
    gx_aurora::g_audio_sample_rate = sample_rate;
    if (gx_aurora::g_audio_stream == nullptr)
        return;

    SDL_AudioSpec spec{};
    spec.format = SDL_AUDIO_S16;
    spec.channels = 2;
    spec.freq = static_cast<int>(gx_aurora::g_audio_sample_rate);
    if (!SDL_SetAudioStreamFormat(gx_aurora::g_audio_stream, &spec, nullptr))
        std::fprintf(stderr, "[audio] failed to set input rate %u: %s\n",
                     gx_aurora::g_audio_sample_rate, SDL_GetError());
    else if (gx_aurora::g_audio_queue_log)
        std::fprintf(stderr, "[audio-queue] input-rate=%u\n",
                     gx_aurora::g_audio_sample_rate);
}

void aurora_backend_audio_push(const s16* samples, u32 frames) {
    if (gx_aurora::g_audio_stream == nullptr || samples == nullptr || frames == 0)
        return;
    const int bytes_per_second =
        static_cast<int>(gx_aurora::g_audio_sample_rate) * 2 * static_cast<int>(sizeof(s16));
    const int prebuffer_bytes = bytes_per_second * gx_aurora::g_audio_prebuffer_ms / 1000;
    const int max_queued_bytes = bytes_per_second * gx_aurora::g_audio_max_queue_ms / 1000;
    const int bytes = static_cast<int>(frames * 2u * sizeof(s16));
    gx_aurora::g_audio_push_count++;

    int queued = SDL_GetAudioStreamQueued(gx_aurora::g_audio_stream);
    unsigned waited_ms = 0;
    while (queued > max_queued_bytes && waited_ms < 20u) {
        gx_aurora::g_audio_throttle_count++;
        if (gx_aurora::g_audio_queue_log &&
            (gx_aurora::g_audio_throttle_count <= 8 ||
             (gx_aurora::g_audio_throttle_count % 100) == 0))
            std::fprintf(stderr,
                         "[audio-queue] throttle push=%llu waits=%llu queued=%d "
                         "max=%d\n",
                         gx_aurora::g_audio_push_count, gx_aurora::g_audio_throttle_count, queued,
                         max_queued_bytes);
        SDL_Delay(1);
        waited_ms++;
        queued = SDL_GetAudioStreamQueued(gx_aurora::g_audio_stream);
    }

    const bool low_queue =
        queued >= 0 && queued < bytes_per_second / 100;
    if (gx_aurora::g_audio_queue_log &&
        (gx_aurora::g_audio_push_count <= 16 || (gx_aurora::g_audio_push_count % 4000) == 0 ||
         (low_queue && gx_aurora::g_audio_push_count - gx_aurora::g_audio_low_log_push >= 4000))) {
        if (low_queue)
            gx_aurora::g_audio_low_log_push = gx_aurora::g_audio_push_count;
        std::fprintf(stderr,
                     "[audio-queue] push=%llu queued_before=%d queued_after=%d "
                     "playing=%u throttles=%llu\n",
                     gx_aurora::g_audio_push_count, queued, queued + bytes,
                     gx_aurora::g_audio_playing ? 1u : 0u, gx_aurora::g_audio_throttle_count);
    }
    if (!SDL_PutAudioStreamData(gx_aurora::g_audio_stream, samples, bytes))
        std::fprintf(stderr, "[audio] failed to queue samples: %s\n", SDL_GetError());
    else if (!gx_aurora::g_audio_playing && queued + bytes >= prebuffer_bytes) {
        if (SDL_ResumeAudioStreamDevice(gx_aurora::g_audio_stream))
            gx_aurora::g_audio_playing = true;
        else
            std::fprintf(stderr, "[audio] failed to start playback: %s\n", SDL_GetError());
    }
}

} // extern "C"
