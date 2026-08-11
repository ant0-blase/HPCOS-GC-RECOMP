#pragma once

// gxcore substrate integration (63/S12): the 4th per-type draw module beside
// clear/gx/rmlui. Pipelines and WGSL come from the headless
// gxruntime::gxcore lib; this file owns only the wgpu plumbing (pipeline
// descriptor, bind groups, buffer pushes, draw submission).

#include "common.hpp"

#include <gxruntime/gxcore/shader.hpp>

#include <webgpu/webgpu_cpp.h>

namespace aurora::gfx::gxcore {

struct DrawData {
  PipelineRef pipeline;
  Range vertRange;
  Range idxRange;
  Range uniformRange;       // VertexShaderConstants (group 1)
  Range pixelUniformRange;  // PixelShaderConstants (group 2), TEV path only
  uint32_t indexCount;
  BindGroupRef textureBindGroup; // 0 when untextured
  bool tev = false; // TEV path: PS uniform at group 2, texture at group 3
};

// Bump when generate_wgsl output or the DrawData/vertex layout changes: the
// persisted pipeline cache precompiles stored configs at startup, and a
// layout/semantics drift under an unchanged key is the S8 poisoned-cache
// failure shape. v2: S14 TEV path (PS uniform group 2, texture group 3).
// v3: S15 lit vertex layout. v4: S16 fog (PixelShaderConstants grows +
// fog fragment on the TEV path). v5: Mfin multi-texmap (a TEV combining >1 texmap
// now emits per-texmap samplers + a wider texture bind group under an unchanged
// key, so a persisted v4 pipeline for such a draw is stale).
constexpr uint32_t GXCorePipelineConfigVersion = 5;

struct PipelineConfig {
  uint32_t version = GXCorePipelineConfigVersion;
  gxruntime::gxcore::PipelineKey key;
  uint32_t msaaSamples = 1;
};
static_assert(std::has_unique_object_representations_v<PipelineConfig>);

wgpu::RenderPipeline create_pipeline(const PipelineConfig& config);
void render(const DrawData& data, const wgpu::RenderPassEncoder& pass);

// Perform one EFB copy-to-texture (63/S16): resolve the current EFB region into
// a texture keyed by the copy destination address, so a later draw binding that
// address samples the copied EFB instead of stale guest memory. Called by the
// GxCoreSink copy observer at the copy's stream position (pending draw flushed).
void copy_efb_to_texture(const gxruntime::gxcore::EfbCopyCommand& cmd);

// Submission layer: turn one headless DrawPlan into buffer pushes, texture
// upload (guest-identity cache keyed incl. TLUT identity; gxcore decodes every
// format to RGBA8, S13 A3), viewport state, and a queued draw command on the
// current pass. False = plan not drawable.
bool submit_draw_plan(const gxruntime::gxcore::DrawPlan& plan);
// Drop the texture cache + reset its stats (start of a replay run).
void reset_texture_cache();

// Texture-cache telemetry (S13 A3): proves the no-reconvert property. `uploads`
// counts actual decode+upload (cache miss); `hits` counts cache reuse (no
// re-decode) — on a static replay scene `uploads` must go to 0 after warm-up.
// `ci_uploads` = CI textures decoded through a TLUT; `raw_fallback` = decode
// produced nothing (CI without a resolved palette / unsupported) so the raw GX
// bytes were uploaded under the original format instead.
struct TextureCacheStats {
  unsigned long long uploads = 0;
  unsigned long long hits = 0;
  unsigned long long ci_uploads = 0;
  unsigned long long raw_fallback = 0;
};
const TextureCacheStats& texture_cache_stats();

} // namespace aurora::gfx::gxcore
