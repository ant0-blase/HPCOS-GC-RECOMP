#ifndef AURORA_GFX_H
#define AURORA_GFX_H

#ifdef __cplusplus
#include <cstdint>

extern "C" {
#else
#include "stdint.h"
#endif

#if !defined(NDEBUG) && !defined(AURORA_GFX_DEBUG_GROUPS)
#define AURORA_GFX_DEBUG_GROUPS
#endif

void push_debug_group(const char* label);
void pop_debug_group();

typedef struct {
  uint32_t queuedPipelines;
  uint32_t createdPipelines;
  uint32_t drawCallCount;
  uint32_t mergedDrawCallCount;
  uint32_t lastVertSize;
  uint32_t lastUniformSize;
  uint32_t lastIndexSize;
  uint32_t lastStorageSize;
  uint32_t lastTextureUploadSize;
} AuroraStats;

const AuroraStats* aurora_get_stats();
float aurora_get_fps();

void aurora_enable_vsync(bool enabled);

/*
 * EFB readback (GXRuntime recomp patch): arm a one-shot copy of the next
 * submitted frame's present source; take returns tightly packed RGBA8 rows
 * (top-left origin) once the copy completed and consumes the result. The
 * returned pointer stays valid until the next readback completes.
 * Upstream remedy: a public aurora framebuffer readback API.
 */
void aurora_request_framebuffer_readback();
bool aurora_take_framebuffer_readback(const uint8_t** rgba, uint32_t* width, uint32_t* height);
/* Drive GPU event processing while waiting for take (no frame, no present). */
void aurora_pump_framebuffer_readback();

#ifdef __cplusplus
}
#endif

#endif
