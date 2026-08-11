#include "gxcore_draw.hpp"

#include "../webgpu/gpu.hpp"
#include "../gx/gx.hpp" // UseReversedZ + set_logical_viewport (substrate glue)
#include "texture.hpp"
#include "tex_copy_conv.hpp" // EFB-copy format conversion (63/S16)

#include <gxruntime/gxcore/gxcore.hpp> // EfbCopyCommand
#include <gxruntime/gxcore/texture_decode.hpp>

#include <absl/container/flat_hash_map.h>

#include <algorithm>
#include <cstring>
#include <vector>

namespace aurora::gfx::gxcore {

namespace gxc = gxruntime::gxcore;

using webgpu::g_device;
using webgpu::g_graphicsConfig;

static Module Log("aurora::gfx::gxcore");

namespace {

wgpu::CompareFunction to_compare(gxc::CompareMode func) {
  // GC compare flipped for the substrate's reversed-Z (gx/gx.cpp:526 shape).
  switch (func) {
  case gxc::CompareMode::Never:
    return wgpu::CompareFunction::Never;
  case gxc::CompareMode::Less:
    return gx::UseReversedZ ? wgpu::CompareFunction::Greater
                            : wgpu::CompareFunction::Less;
  case gxc::CompareMode::Equal:
    return wgpu::CompareFunction::Equal;
  case gxc::CompareMode::LEqual:
    return gx::UseReversedZ ? wgpu::CompareFunction::GreaterEqual
                            : wgpu::CompareFunction::LessEqual;
  case gxc::CompareMode::Greater:
    return gx::UseReversedZ ? wgpu::CompareFunction::Less
                            : wgpu::CompareFunction::Greater;
  case gxc::CompareMode::NEqual:
    return wgpu::CompareFunction::NotEqual;
  case gxc::CompareMode::GEqual:
    return gx::UseReversedZ ? wgpu::CompareFunction::LessEqual
                            : wgpu::CompareFunction::GreaterEqual;
  case gxc::CompareMode::Always:
  default:
    return wgpu::CompareFunction::Always;
  }
}

wgpu::BlendFactor to_blend_factor_src(gxc::SrcBlendFactor factor) {
  switch (factor) {
  case gxc::SrcBlendFactor::Zero:
    return wgpu::BlendFactor::Zero;
  case gxc::SrcBlendFactor::One:
    return wgpu::BlendFactor::One;
  case gxc::SrcBlendFactor::DstClr:
    return wgpu::BlendFactor::Dst;
  case gxc::SrcBlendFactor::InvDstClr:
    return wgpu::BlendFactor::OneMinusDst;
  case gxc::SrcBlendFactor::SrcAlpha:
    return wgpu::BlendFactor::SrcAlpha;
  case gxc::SrcBlendFactor::InvSrcAlpha:
    return wgpu::BlendFactor::OneMinusSrcAlpha;
  case gxc::SrcBlendFactor::DstAlpha:
    return wgpu::BlendFactor::DstAlpha;
  case gxc::SrcBlendFactor::InvDstAlpha:
  default:
    return wgpu::BlendFactor::OneMinusDstAlpha;
  }
}

wgpu::BlendFactor to_blend_factor_dst(gxc::DstBlendFactor factor) {
  switch (factor) {
  case gxc::DstBlendFactor::Zero:
    return wgpu::BlendFactor::Zero;
  case gxc::DstBlendFactor::One:
    return wgpu::BlendFactor::One;
  case gxc::DstBlendFactor::SrcClr:
    return wgpu::BlendFactor::Src;
  case gxc::DstBlendFactor::InvSrcClr:
    return wgpu::BlendFactor::OneMinusSrc;
  case gxc::DstBlendFactor::SrcAlpha:
    return wgpu::BlendFactor::SrcAlpha;
  case gxc::DstBlendFactor::InvSrcAlpha:
    return wgpu::BlendFactor::OneMinusSrcAlpha;
  case gxc::DstBlendFactor::DstAlpha:
    return wgpu::BlendFactor::DstAlpha;
  case gxc::DstBlendFactor::InvDstAlpha:
  default:
    return wgpu::BlendFactor::OneMinusDstAlpha;
  }
}

// Texture bind group layout for a used-texmap set (63/Mfin multi-texmap): texmap
// t occupies binding 2t (texture) + 2t+1 (sampler), matching the WGSL. Cached per
// mask; used_mask=1 (texmap 0 only) reproduces the pre-Mfin single-texmap layout.
wgpu::BindGroupLayout texture_bind_group_layout(uint32_t used_mask = 1u) {
  static absl::flat_hash_map<uint32_t, wgpu::BindGroupLayout> cache;
  auto it = cache.find(used_mask);
  if (it != cache.end())
    return it->second;
  std::vector<wgpu::BindGroupLayoutEntry> entries;
  for (uint32_t t = 0; t < 8u; ++t) {
    if ((used_mask & (1u << t)) == 0u)
      continue;
    entries.push_back(wgpu::BindGroupLayoutEntry{
        .binding = 2u * t,
        .visibility = wgpu::ShaderStage::Fragment,
        .texture =
            wgpu::TextureBindingLayout{
                .sampleType = wgpu::TextureSampleType::Float,
                .viewDimension = wgpu::TextureViewDimension::e2D,
            },
    });
    entries.push_back(wgpu::BindGroupLayoutEntry{
        .binding = 2u * t + 1u,
        .visibility = wgpu::ShaderStage::Fragment,
        .sampler =
            wgpu::SamplerBindingLayout{
                .type = wgpu::SamplerBindingType::Filtering,
            },
    });
  }
  const wgpu::BindGroupLayoutDescriptor descriptor{
      .label = "GXCore Texture Bind Group Layout",
      .entryCount = entries.size(),
      .entries = entries.data(),
  };
  auto layout = g_device.CreateBindGroupLayout(&descriptor);
  cache.emplace(used_mask, layout);
  return layout;
}

// Guest-identity texture cache (S13 A3). Keyed by the texture's guest identity
// AND the TLUT identity it indexes: the same CI image bytes re-palettized to a
// different TLUT decode to different pixels, so the palette address/format/
// entries are part of the key. 63/Mfin adds `content_hash` (xxh3 of the actual
// source texels + TLUT): the live game reuses one guest texture-buffer address
// for different images across screens (stadium select overwrites the captain
// art) and streams movie frames through a single buffer, so identity alone would
// bind the stale decode. Hashing the content makes a content change under an
// unchanged identity a distinct entry (Dolphin/Aurora texel-hash model). Static
// replay fixtures never rewrite an address, so the no-reconvert property holds.
struct TextureKey {
  uint32_t address;
  uint32_t size;
  uint32_t format;
  uint32_t width;
  uint32_t height;
  uint32_t tlut_address;
  uint32_t tlut_format;
  uint32_t tlut_entries;
  uint64_t content_hash;
  bool operator==(const TextureKey&) const = default;
  template <typename H>
  friend H AbslHashValue(H h, const TextureKey& key) {
    return H::combine(std::move(h), key.address, key.size, key.format,
                      key.width, key.height, key.tlut_address, key.tlut_format,
                      key.tlut_entries, key.content_hash);
  }
};

absl::flat_hash_map<TextureKey, TextureHandle> g_textureCache;
// address -> the key currently cached at that guest address. When new content
// arrives at an address (movie streaming, screen transitions), the prior entry
// for that address is evicted so the content-hashed cache stays bounded to one
// live entry per buffer instead of accumulating every historical frame.
absl::flat_hash_map<uint32_t, TextureKey> g_textureAddrKey;
TextureCacheStats g_textureCacheStats;

// EFB copy-to-texture destinations (63/S16): dest guest address -> resolved EFB
// texture. A draw binding a texture at one of these addresses samples the copied
// EFB content instead of the (stale, never-written-by-us) guest memory there.
// Mirrors aurora lib/gx GXState::copyTextures. Copies key by dest address only
// (a re-copy to the same address updates in place, matching the live path).
absl::flat_hash_map<uint32_t, TextureHandle> g_efbCopyTextures;

} // namespace

wgpu::RenderPipeline create_pipeline(const PipelineConfig& config) {
  const gxc::PipelineKey& key = config.key;
  const std::string wgsl = gxc::generate_wgsl(key.shader);
  wgpu::ShaderSourceWGSL sourceDescriptor{};
  sourceDescriptor.code = wgsl.c_str();
  const wgpu::ShaderModuleDescriptor moduleDescriptor{
      .nextInChain = &sourceDescriptor,
      .label = "GXCore Shader Module",
  };
  const auto module = g_device.CreateShaderModule(&moduleDescriptor);

  // Group 0 keeps the pass preamble's static bind group compatible (the shader
  // never references it); 1 = shared dynamic VS uniform. On the TEV path (S14)
  // 2 = shared dynamic PS uniform and 3 = texture; else 2 = texture. Putting
  // the PS uniform before the texture keeps an untextured TEV draw gap-free.
  const bool tev = key.shader.tev_valid != 0;
  const bool textured = key.shader.textured != 0;
  // Multi-texmap: the texture group's layout matches the set of texmaps the WGSL
  // declares (derived identically from the shader key), so pipeline and bind
  // group agree. Untextured draws never use the texture group (layoutCount below).
  const uint32_t tex_mask = textured ? gxc::used_texmap_mask(key.shader) : 1u;
  std::array<wgpu::BindGroupLayout, 4> bindGroupLayouts{
      g_staticBindGroupLayout,
      g_uniformBindGroupLayout,
      tev ? g_uniformBindGroupLayout : texture_bind_group_layout(tex_mask),
      texture_bind_group_layout(tex_mask),
  };
  const size_t layoutCount = tev ? (textured ? 4 : 3) : (textured ? 3 : 2);
  const wgpu::PipelineLayoutDescriptor layoutDescriptor{
      .label = "GXCore Pipeline Layout",
      .bindGroupLayoutCount = layoutCount,
      .bindGroupLayouts = bindGroupLayouts.data(),
  };
  const auto pipelineLayout = g_device.CreatePipelineLayout(&layoutDescriptor);

  // Fixed decoded-vertex layout (gxruntime/gxcore/shader.hpp). The normal
  // (location 8) is only declared by the lit shader, so add it to the pipeline
  // only when the key is lit — WGSL requires the vertex layout to satisfy every
  // shader input.
  std::vector<wgpu::VertexAttribute> attributes{
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x3,
          .offset = gxc::kVertexPosOffset,
          .shaderLocation = 0,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Uint32,
          .offset = gxc::kVertexPosMtxOffset,
          .shaderLocation = 1,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x4,
          .offset = gxc::kVertexColor0Offset,
          .shaderLocation = 2,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x4,
          .offset = gxc::kVertexColor1Offset,
          .shaderLocation = 3,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x2,
          .offset = gxc::kVertexUvOffset,
          .shaderLocation = 4,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x2,
          .offset = gxc::kVertexUvOffset + 8,
          .shaderLocation = 5,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x2,
          .offset = gxc::kVertexUvOffset + 16,
          .shaderLocation = 6,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x2,
          .offset = gxc::kVertexUvOffset + 24,
          .shaderLocation = 7,
      },
  };
  // Item-5 texgen inputs must mirror the generator's VertexIn: emboss needs the
  // NBT normal/binormal/tangent + light dir; a Color1/emboss key that is unlit
  // still declares the normal (location 8). Detect emboss demand from the key.
  bool has_emboss = false;
  for (std::uint32_t i = 0; i < key.shader.num_tex_gens; ++i) {
    if (static_cast<gxc::TexGenType>(key.shader.tex_gens[i].texgentype) ==
        gxc::TexGenType::EmbossMap)
      has_emboss = true;
  }
  // Mirror the generator exactly: locations 8/10/11 are declared only when the
  // vertex FORMAT carries that attribute. A lit/emboss draw whose format omits
  // it reads the cached fallback from the uniform instead (I_CACHED_NORMAL), so
  // the shader does not declare the input and the layout must not provide it.
  if ((key.shader.lit_valid != 0 || has_emboss) &&
      key.shader.has_vertex_normal != 0) {
    attributes.push_back(wgpu::VertexAttribute{
        .format = wgpu::VertexFormat::Float32x3,
        .offset = gxc::kVertexNormalOffset,
        .shaderLocation = 8,
    });
  }
  if (key.shader.has_tex_mtx_idx != 0) {
    attributes.push_back(wgpu::VertexAttribute{
        .format = wgpu::VertexFormat::Uint32,
        .offset = gxc::kVertexTexMtxIdxOffset,
        .shaderLocation = 9,
    });
  }
  if (has_emboss && key.shader.has_vertex_binormal != 0) {
    attributes.push_back(wgpu::VertexAttribute{
        .format = wgpu::VertexFormat::Float32x3,
        .offset = gxc::kVertexBinormalOffset,
        .shaderLocation = 10,
    });
  }
  if (has_emboss && key.shader.has_vertex_tangent != 0) {
    attributes.push_back(wgpu::VertexAttribute{
        .format = wgpu::VertexFormat::Float32x3,
        .offset = gxc::kVertexTangentOffset,
        .shaderLocation = 11,
    });
  }
  const wgpu::VertexBufferLayout vertexLayout{
      .arrayStride = gxc::kVertexStrideBytes,
      .stepMode = wgpu::VertexStepMode::Vertex,
      .attributeCount = attributes.size(),
      .attributes = attributes.data(),
  };

  const bool depthCompare = key.depth_test != 0;
  const wgpu::DepthStencilState depthStencil{
      .format = g_graphicsConfig.depthFormat,
      .depthWriteEnabled = depthCompare && key.depth_update != 0,
      .depthCompare =
          depthCompare ? to_compare(static_cast<gxc::CompareMode>(
                             key.depth_func))
                       : wgpu::CompareFunction::Always,
  };

  // GC subtract mode forces ONE/ONE with dst - src (Dolphin RenderState).
  wgpu::BlendState blendState{};
  if (key.blend_subtract != 0) {
    blendState.color = {
        .operation = wgpu::BlendOperation::ReverseSubtract,
        .srcFactor = wgpu::BlendFactor::One,
        .dstFactor = wgpu::BlendFactor::One,
    };
    blendState.alpha = blendState.color;
  } else {
    blendState.color = {
        .operation = wgpu::BlendOperation::Add,
        .srcFactor = to_blend_factor_src(
            static_cast<gxc::SrcBlendFactor>(key.src_factor)),
        .dstFactor = to_blend_factor_dst(
            static_cast<gxc::DstBlendFactor>(key.dst_factor)),
    };
    blendState.alpha = blendState.color;
  }
  auto writeMask = wgpu::ColorWriteMask::None;
  if (key.color_update != 0) {
    writeMask |= wgpu::ColorWriteMask::Red | wgpu::ColorWriteMask::Green |
                 wgpu::ColorWriteMask::Blue;
  }
  if (key.alpha_update != 0)
    writeMask |= wgpu::ColorWriteMask::Alpha;
  const bool blending =
      key.blend_enable != 0 || key.blend_subtract != 0;
  const wgpu::ColorTargetState colorTarget{
      .format = g_graphicsConfig.surfaceConfiguration.format,
      .blend = blending ? &blendState : nullptr,
      .writeMask = writeMask,
  };
  const wgpu::FragmentState fragmentState{
      .module = module,
      .entryPoint = "fs_main",
      .targetCount = 1,
      .targets = &colorTarget,
  };

  auto cullMode = wgpu::CullMode::None;
  switch (static_cast<gxc::CullMode>(key.cull_mode)) {
  case gxc::CullMode::Back:
    cullMode = wgpu::CullMode::Back;
    break;
  case gxc::CullMode::Front:
    cullMode = wgpu::CullMode::Front;
    break;
  default:
    break; // None here; All was skipped at plan time
  }

  const wgpu::RenderPipelineDescriptor descriptor{
      .label = "GXCore Pipeline",
      .layout = pipelineLayout,
      .vertex =
          wgpu::VertexState{
              .module = module,
              .entryPoint = "vs_main",
              .bufferCount = 1,
              .buffers = &vertexLayout,
          },
      .primitive =
          wgpu::PrimitiveState{
              .topology = wgpu::PrimitiveTopology::TriangleList,
              // Substrate winding convention (gx/gx.cpp to_primitive_state).
              .frontFace = wgpu::FrontFace::CW,
              .cullMode = cullMode,
          },
      .depthStencil = &depthStencil,
      .multisample =
          wgpu::MultisampleState{
              .count = config.msaaSamples,
          },
      .fragment = &fragmentState,
  };
  return g_device.CreateRenderPipeline(&descriptor);
}

void render(const DrawData& data, const wgpu::RenderPassEncoder& pass) {
  if (!bind_pipeline(data.pipeline, pass)) {
    return;
  }
  const std::array vsOffsets{data.uniformRange.offset};
  pass.SetBindGroup(1, g_uniformBindGroup, vsOffsets.size(), vsOffsets.data());
  if (data.tev) {
    // group 2 = PS uniform (same dynamic-uniform bind group, its own offset);
    // group 3 = texture.
    const std::array psOffsets{data.pixelUniformRange.offset};
    pass.SetBindGroup(2, g_uniformBindGroup, psOffsets.size(),
                      psOffsets.data());
    if (data.textureBindGroup != 0) {
      pass.SetBindGroup(3, find_bind_group(data.textureBindGroup));
    }
  } else if (data.textureBindGroup != 0) {
    pass.SetBindGroup(2, find_bind_group(data.textureBindGroup));
  }
  pass.SetVertexBuffer(0, g_vertexBuffer, data.vertRange.offset,
                       data.vertRange.size);
  pass.SetIndexBuffer(g_indexBuffer, wgpu::IndexFormat::Uint16,
                      data.idxRange.offset, data.idxRange.size);
  pass.DrawIndexed(data.indexCount);
}

void reset_texture_cache() {
  g_textureCache.clear();
  g_textureAddrKey.clear();
  g_efbCopyTextures.clear();
  g_textureCacheStats = {};
}

const TextureCacheStats& texture_cache_stats() { return g_textureCacheStats; }

// Resolve the current EFB region into a texture the guest-identity path can bind
// later, keyed by the copy's destination address (63/S16). Mirrors aurora
// lib/dolphin/gx/GXFrameBuffer.cpp copy_tex on the same substrate: map the EFB
// source rect through the logical->render scaling, allocate (or reuse) a resolve
// target, then gfx::resolve_pass — which converts per format (tex_copy_conv,
// incl. depth targets) and optionally clears the EFB to the game's copy-clear
// color/Z afterwards. The bound draw's geometry is already in the pass (the
// sink flushed the pending draw before firing this).
void copy_efb_to_texture(const gxc::EfbCopyCommand& cmd) {
  // Mirror the copy-clear color/Z (BP 0x4F-0x51 at this copy) into the gx
  // state GXSetCopyClear would have written: begin_frame's pass-0 EFB clear
  // reads g_gxState.clearColor/clearDepth, and in gxcore mode the live gx
  // layer that normally maintains them is bypassed. Without this every frame
  // cleared to the default alpha=1 and e.g. the Strikers shadow-grab alpha
  // background inverted (glxSwap display-copy clears to {0,0,0,0}).
  gx::g_gxState.clearColor = {
      static_cast<float>(cmd.clear_r) / 255.f,
      static_cast<float>(cmd.clear_g) / 255.f,
      static_cast<float>(cmd.clear_b) / 255.f,
      static_cast<float>(cmd.clear_a) / 255.f,
  };
  gx::g_gxState.clearDepth = cmd.clear_z;
  if (cmd.format == 0xFu) {
    // Display copy (GXCopyDisp): no texture destination; its requested clear
    // becomes the next frame's EFB clear via the state mirrored above.
    return;
  }
  const auto fmt = static_cast<GXTexFmt>(cmd.format);
  const gfx::ClipRect srcRect = gx::map_logical_scissor(gfx::ClipRect{
      .x = static_cast<int32_t>(cmd.src_x),
      .y = static_cast<int32_t>(cmd.src_y),
      .width = static_cast<int32_t>(cmd.width),
      .height = static_cast<int32_t>(cmd.height),
  });
  const uint32_t dstWidth = static_cast<uint32_t>(std::max(srcRect.width, 1));
  const uint32_t dstHeight = static_cast<uint32_t>(std::max(srcRect.height, 1));

  auto it = g_efbCopyTextures.find(cmd.dest_address);
  if (it == g_efbCopyTextures.end() || !it->second) {
    TextureHandle handle;
    if (gfx::tex_copy_conv::needs_conversion(fmt)) {
      handle = gfx::new_conv_texture(dstWidth, dstHeight, fmt, "GXCore Copy Conv");
    } else {
      handle = gfx::new_render_texture(dstWidth, dstHeight, GX_TF_RGBA8,
                                       "GXCore Copy");
    }
    it = g_efbCopyTextures.insert_or_assign(cmd.dest_address, handle).first;
  }
  if (!it->second) {
    return;
  }
  float clearDepthValue = static_cast<float>(cmd.clear_z) / 16777215.f;
  if (gx::UseReversedZ) {
    clearDepthValue = 1.f - clearDepthValue;
  }
  gfx::resolve_pass(it->second, srcRect, cmd.clear && cmd.color_update,
                    cmd.clear && cmd.alpha_update,
                    cmd.clear && cmd.depth_update,
                    Vec4<float>{static_cast<float>(cmd.clear_r) / 255.f,
                                static_cast<float>(cmd.clear_g) / 255.f,
                                static_cast<float>(cmd.clear_b) / 255.f,
                                static_cast<float>(cmd.clear_a) / 255.f},
                    clearDepthValue, fmt);
}

bool submit_draw_plan(const gxc::DrawPlan& plan) {
  if (!plan.ok || plan.vertex_count == 0 || plan.indices.empty()) {
    return false;
  }

  if (plan.viewport_valid) {
    // Raw XF viewport -> logical viewport, the raw path's own formula
    // (gx/command_processor.cpp XF 0x1A case).
    const float sx = plan.viewport[0];
    const float sy = plan.viewport[1];
    const float sz = plan.viewport[2];
    const float ox = plan.viewport[3];
    const float oy = plan.viewport[4];
    const float oz = plan.viewport[5];
    const float width = sx * 2.0f;
    const float height = -sy * 2.0f;
    gx::set_logical_viewport({
        .left = ox - 340.0f - width / 2.0f,
        .top = oy - 340.0f - height / 2.0f,
        .width = width,
        .height = height,
        .znear = (oz - sz) / 1.6777215e7f,
        .zfar = oz / 1.6777215e7f,
    });
  }

  // Resolve one texmap's texture to a GPU handle: EFB-copy shadow first, else the
  // guest-identity + content-hash decode cache. Shared by the single-texmap fast
  // path and the multi-texmap path (63/Mfin, e.g. THP YUV Y/U/V on texmap 0/1/2).
  auto resolve_texture_handle =
      [&](uint32_t address, uint32_t tsize, uint32_t format, uint32_t width,
          uint32_t height, const void* data, uint32_t available, bool has_tlut,
          uint32_t tlut_address, uint32_t tlut_format, uint32_t tlut_entries,
          const void* tlut_data, uint32_t tlut_available) -> TextureHandle {
    auto efbIt = g_efbCopyTextures.find(address);
    if (efbIt != g_efbCopyTextures.end() && efbIt->second) {
      ++g_textureCacheStats.hits;
      return efbIt->second;
    }
    if (data == nullptr)
      return TextureHandle{};
    const auto* bytes = static_cast<const uint8_t*>(data);
    const uint32_t size = std::min(tsize, available);
    // Hash the actual source texels (+ TLUT for CI) so a content change under an
    // unchanged guest identity is a distinct cache entry — see TextureKey.
    uint64_t content_hash = XXH3_64bits(bytes, size);
    if (gxc::is_ci_format(format) && has_tlut && tlut_data != nullptr)
      content_hash =
          XXH3_64bits_withSeed(tlut_data, tlut_available, content_hash);
    const TextureKey key{address,     tsize,        format,      width,
                         height,      tlut_address, tlut_format, tlut_entries,
                         content_hash};
    auto it = g_textureCache.find(key);
    if (it != g_textureCache.end()) {
      ++g_textureCacheStats.hits;
      return it->second;
    }
    // New content for this identity: evict any prior entry cached at the same
    // guest address (its buffer was overwritten) to keep the cache bounded.
    auto addrIt = g_textureAddrKey.find(address);
    if (addrIt != g_textureAddrKey.end())
      g_textureCache.erase(addrIt->second);
    // gxcore owns the decode for every format: produce tightly-packed RGBA8 and
    // upload it as a pre-decoded PC texture (no substrate re-conversion).
    std::vector<uint8_t> decoded;
    if (gxc::is_ci_format(format)) {
      if (has_tlut && tlut_data != nullptr)
        decoded = gxc::decode_ci(format, width, height, bytes, size, tlut_format,
                                 tlut_entries,
                                 static_cast<const uint8_t*>(tlut_data),
                                 tlut_available);
    } else {
      decoded = gxc::decode_texture(format, width, height, bytes, size);
    }
    TextureHandle handle;
    if (!decoded.empty()) {
      handle = new_static_texture_2d(
          width, height, 1, GX_TF_RGBA8_PC,
          ArrayRef<uint8_t>{decoded.data(), decoded.size()}, false,
          "GXCore Texture");
      ++g_textureCacheStats.uploads;
      if (gxc::is_ci_format(format))
        ++g_textureCacheStats.ci_uploads;
    } else {
      // CI without a resolved palette, or a format gxcore does not decode: upload
      // the raw GX bytes under the original format (old behavior).
      handle = new_static_texture_2d(width, height, 1, format,
                                     ArrayRef<uint8_t>{bytes, size}, false,
                                     "GXCore Texture");
      ++g_textureCacheStats.uploads;
      ++g_textureCacheStats.raw_fallback;
    }
    g_textureCache.emplace(key, handle);
    g_textureAddrKey[address] = key;
    return handle;
  };

  BindGroupRef textureBindGroup = 0;
  if (plan.pipeline.shader.textured != 0) {
    const wgpu::SamplerDescriptor samplerDescriptor{
        .label = "GXCore Sampler",
        .addressModeU = wgpu::AddressMode::Repeat,
        .addressModeV = wgpu::AddressMode::Repeat,
        .magFilter = wgpu::FilterMode::Linear,
        .minFilter = wgpu::FilterMode::Linear,
        .mipmapFilter = wgpu::MipmapFilterMode::Nearest,
    };
    const auto sampler = sampler_ref(samplerDescriptor);
    if (plan.texmap_mask == 0u) {
      // Single-texmap fast path: primary texture at binding 0/1 (unchanged).
      if (plan.has_texture) {
        TextureHandle bound = resolve_texture_handle(
            plan.tex_address, plan.tex_size, plan.tex_format, plan.tex_width,
            plan.tex_height, plan.tex_data, plan.tex_available, plan.has_tlut,
            plan.tlut_address, plan.tlut_format, plan.tlut_entries,
            plan.tlut_data, plan.tlut_available);
        if (bound) {
          const std::array entries{
              WGPUBindGroupEntry{.binding = 0,
                                 .textureView =
                                     bound->sampleTextureView.Get()},
              WGPUBindGroupEntry{.binding = 1, .sampler = sampler.Get()},
          };
          const WGPUBindGroupDescriptor descriptor{
              .label = {"GXCore Texture Bind Group", WGPU_STRLEN},
              .layout = texture_bind_group_layout(1u).Get(),
              .entryCount = entries.size(),
              .entries = entries.data(),
          };
          textureBindGroup = bind_group_ref(descriptor);
        }
      }
    } else {
      // Multi-texmap: bind each used texmap at 2t (texture) / 2t+1 (sampler),
      // matching the WGSL declarations. If any referenced texmap fails to
      // resolve the draw is not drawable (avoids a missing-bind-group error).
      std::vector<TextureHandle> held;
      std::vector<WGPUBindGroupEntry> entries;
      bool complete = true;
      for (uint32_t t = 0; t < 8u; ++t) {
        if ((plan.texmap_mask & (1u << t)) == 0u)
          continue;
        const gxc::PlanTexture& pt = plan.textures[t];
        TextureHandle bound;
        if (pt.valid)
          bound = resolve_texture_handle(
              pt.address, pt.size, pt.format, pt.width, pt.height, pt.data,
              pt.available, pt.has_tlut, pt.tlut_address, pt.tlut_format,
              pt.tlut_entries, pt.tlut_data, pt.tlut_available);
        if (!bound) {
          complete = false;
          break;
        }
        held.push_back(bound);
        entries.push_back(WGPUBindGroupEntry{
            .binding = 2u * t, .textureView = bound->sampleTextureView.Get()});
        entries.push_back(WGPUBindGroupEntry{.binding = 2u * t + 1u,
                                             .sampler = sampler.Get()});
      }
      if (!complete)
        return false;
      const WGPUBindGroupDescriptor descriptor{
          .label = {"GXCore Texture Bind Group", WGPU_STRLEN},
          .layout = texture_bind_group_layout(plan.texmap_mask).Get(),
          .entryCount = entries.size(),
          .entries = entries.data(),
      };
      textureBindGroup = bind_group_ref(descriptor);
    }
  }

  const auto vertRange = push_verts(
      reinterpret_cast<const uint8_t*>(plan.vertices.data()),
      plan.vertices.size() * sizeof(float), 4);
  const auto idxRange = push_indices(
      reinterpret_cast<const uint8_t*>(plan.indices.data()),
      plan.indices.size() * sizeof(uint16_t), 4);
  const auto uniformRange = push_uniform(
      reinterpret_cast<const uint8_t*>(&plan.constants),
      sizeof(plan.constants));
  const bool tev = plan.pipeline.shader.tev_valid != 0;
  Range pixelUniformRange{};
  if (tev) {
    pixelUniformRange = push_uniform(
        reinterpret_cast<const uint8_t*>(&plan.pixel_constants),
        sizeof(plan.pixel_constants));
  }

  push_draw_command(DrawData{
      .pipeline = pipeline_ref(PipelineConfig{
          .version = GXCorePipelineConfigVersion,
          .key = plan.pipeline,
          .msaaSamples = get_sample_count(),
      }),
      .vertRange = vertRange,
      .idxRange = idxRange,
      .uniformRange = uniformRange,
      .pixelUniformRange = pixelUniformRange,
      .indexCount = static_cast<uint32_t>(plan.indices.size()),
      .textureBindGroup = textureBindGroup,
      .tev = tev,
  });
  return true;
}

} // namespace aurora::gfx::gxcore
