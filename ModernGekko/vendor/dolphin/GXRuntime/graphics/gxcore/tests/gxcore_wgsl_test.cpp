// SPDX-License-Identifier: GPL-3.0-or-later
// gxcore headless conformance test: known register state -> exact
// shader string + decoded draw plan. This is THE synthetic-fixture pattern
// later modules (S13-S16) copy: drive GxCoreState/build_draw_plan with
// hand-built state, assert bytes.

#include "gxruntime/gxcore/gxcore.hpp"

#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

namespace ar = gxruntime::aurora_recomp;
namespace gxc = gxruntime::gxcore;

static int g_failures = 0;

#define CHECK(cond)                                                           \
  do {                                                                        \
    if (!(cond)) {                                                            \
      std::fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond);    \
      ++g_failures;                                                           \
    }                                                                         \
  } while (0)

namespace {

void append_be32(std::vector<std::uint8_t>& out, std::uint32_t value) {
  out.push_back(static_cast<std::uint8_t>(value >> 24));
  out.push_back(static_cast<std::uint8_t>(value >> 16));
  out.push_back(static_cast<std::uint8_t>(value >> 8));
  out.push_back(static_cast<std::uint8_t>(value));
}

void append_be_f32(std::vector<std::uint8_t>& out, float value) {
  std::uint32_t bits;
  std::memcpy(&bits, &value, sizeof bits);
  append_be32(out, bits);
}

ar::RenderStatePacket bp(std::uint32_t reg, std::uint32_t value) {
  return {.kind = ar::RenderStateKind::BpReg, .index = reg, .value = value};
}

// The golden WGSL for the textured 1-texgen key below. Regenerate by running
// this test with GXCORE_PRINT_WGSL=1 in the environment and pasting stdout.
constexpr const char* kGoldenTexturedWgsl =
    R"(// gxcore generated shader (Dolphin VertexShaderGen shape)
struct VertexShaderConstants {
    posnormalmatrix: array<vec4f, 6>,
    projection: array<vec4f, 4>,
    texmatrices: array<vec4f, 24>,
    transformmatrices: array<vec4f, 64>,
};
@group(1) @binding(0) var<uniform> vsc: VertexShaderConstants;
@group(2) @binding(0) var tex0: texture_2d<f32>;
@group(2) @binding(1) var samp0: sampler;
struct VertexIn {
    @location(0) rawpos: vec3f,
    @location(1) posmtx: u32,
    @location(2) rawcolor0: vec4f,
    @location(3) rawcolor1: vec4f,
    @location(4) rawtex0: vec2f,
    @location(5) rawtex1: vec2f,
    @location(6) rawtex2: vec2f,
    @location(7) rawtex3: vec2f,
};
struct VertexOut {
    @builtin(position) pos: vec4f,
    @location(0) color0: vec4f,
    @location(1) uv0: vec3f,
};

@vertex
fn vs_main(in: VertexIn) -> VertexOut {
    var o: VertexOut;
    let p0 = vsc.posnormalmatrix[0];
    let p1 = vsc.posnormalmatrix[1];
    let p2 = vsc.posnormalmatrix[2];
    let pos4 = vec4f(in.rawpos, 1.0);
    let viewpos = vec4f(dot(p0, pos4), dot(p1, pos4), dot(p2, pos4), 1.0);
    var clip = vec4f(dot(vsc.projection[0], viewpos), dot(vsc.projection[1], viewpos), dot(vsc.projection[2], viewpos), dot(vsc.projection[3], viewpos));
    clip.z = -clip.z;
    o.pos = clip;
    o.color0 = vec4f(1.0);
    {
        var coord = vec4f(0.0, 0.0, 1.0, 1.0);
        coord = vec4f(in.rawtex0.x, in.rawtex0.y, 1.0, 1.0);
        coord.z = 1.0;
        var uv = vec3f(dot(coord, vsc.texmatrices[0]), dot(coord, vsc.texmatrices[1]), 1.0);
        if (uv.z == 0.0) { uv = vec3f(clamp(uv.xy * 0.5, vec2f(-1.0), vec2f(1.0)), uv.z); }
        o.uv0 = uv;
    }
    return o;
}

@fragment
fn fs_main(in: VertexOut) -> @location(0) vec4f {
    var prev = in.color0;
    let uv = in.uv0.xy;
    prev = textureSample(tex0, samp0, uv);
    return prev;
}
)";

void test_state_to_plan_and_wgsl() {
  gxc::GxCoreState state;
  state.reset();
  // BP: genMode = 1 texgen + cull back; zmode = test/LEqual/update;
  // cmode0 = blend on, src SrcAlpha, dst InvSrcAlpha, color+alpha update.
  state.apply(bp(0x00, 1u | (1u << 14)));
  state.apply(bp(0x40, 0x17u));
  state.apply(bp(0x41, 1u | (5u << 5) | (4u << 8) | (1u << 3) | (1u << 4)));
  // VCD: position direct f32x3, tex0 direct f32x2.
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0,
               .value = 1u << 9});
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 1, .value = 1u});
  // VAT fmt0: pos 3 elements (bit0), format f32 (4<<1); tex0 2 elements
  // (bit21), format f32 (4<<22).
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1) | (1u << 21) | (4u << 22), .aux0 = 0});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 1});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 2});

  ar::ConsumedDraw draw{};
  draw.primitive = 0x80; // quads
  draw.vtx_fmt = 0;
  draw.vertex_count = 4;
  draw.vertex_size = 20;
  const float quad[4][5] = {
      {-1.f, -1.f, 0.f, 0.f, 0.f},
      {1.f, -1.f, 0.f, 1.f, 0.f},
      {1.f, 1.f, 0.f, 1.f, 1.f},
      {-1.f, 1.f, 0.f, 0.f, 1.f},
  };
  std::vector<std::uint8_t> payload;
  for (const auto& v : quad)
    for (float f : v)
      append_be_f32(payload, f);
  draw.vertex_payload = payload;

  draw.transform_flags =
      ar::kDrawTransformProjectionValid | ar::kDrawTransformViewportValid;
  // Orthographic projection params + identity current PN matrix.
  draw.projection[0] = 1.f;
  draw.projection[1] = 0.f;
  draw.projection[2] = 1.f;
  draw.projection[3] = 0.f;
  draw.projection[4] = -1.f;
  draw.projection[5] = 0.f;
  draw.projection_type = 1;
  draw.current_pn_matrix = 0;
  draw.position_matrix_valid_mask = 1u;
  draw.position_matrices[0][0] = 1.f;
  draw.position_matrices[0][5] = 1.f;
  draw.position_matrices[0][10] = 1.f;
  // XF regs: MatrixIndexA (tex0 -> row 60), numTexGens=1, texgen spec 0
  // (regular, ST, AB11, source Tex0).
  draw.xf_regs[0x00] = 60u << 6;
  draw.xf_regs[0x27] = 1u;
  draw.xf_regs[0x28] = 5u << 7;
  draw.xf_reg_mask = (1ull << 0x00) | (1ull << 0x27) | (1ull << 0x28);
  // Identity texture matrix at rows 60-62 (tex_matrices slot 10).
  draw.tex_matrices[10][0] = 1.f;
  draw.tex_matrices[10][5] = 1.f;
  draw.tex_matrices[10][10] = 1.f;
  draw.tex_matrix_word_mask[10] = 0xFFFu;
  // A bound, resolved texture.
  static const std::uint8_t tex_bytes[32] = {};
  draw.texture.valid = true;
  draw.texture.resolved = true;
  draw.texture.address = 0x80300000u;
  draw.texture.size = sizeof tex_bytes;
  draw.texture.format = 0xE; // CMPR
  draw.texture.width = 8;
  draw.texture.height = 8;
  draw.texture.host_data = tex_bytes;
  draw.texture.host_available = sizeof tex_bytes;
  // Resolved TLUT palette rides through build_draw_plan for the A3 CI decoder.
  static const std::uint8_t tlut_bytes[16 * 2] = {};
  draw.texture.has_tlut = true;
  draw.texture.tlut_format = 2; // RGB5A3
  draw.texture.tlut_entries = 16;
  draw.texture.tlut_host_data = tlut_bytes;
  draw.texture.tlut_host_available = sizeof tlut_bytes;
  draw.viewport[0] = 320.f;
  draw.viewport[1] = -240.f;
  draw.viewport[2] = 16777215.f;
  draw.viewport[3] = 662.f;
  draw.viewport[4] = 582.f;
  draw.viewport[5] = 16777215.f;

  gxc::GapCounters counters;
  const gxc::DrawPlan plan = state.build_draw_plan(draw, counters);
  if (!plan.ok)
    std::fprintf(stderr, "plan skipped: %s\n", plan.skip_reason);
  CHECK(plan.ok);
  CHECK(counters.draws_planned == 1);
  CHECK(counters.draws_skipped == 0);
  CHECK(counters.unresolved_tex_matrix == 0);

  // Shader key.
  const gxc::ShaderKey& key = plan.pipeline.shader;
  CHECK(key.num_tex_gens == 1);
  CHECK(key.has_pos_mtx_idx == 0);
  CHECK(key.has_color0 == 0);
  CHECK(key.uv_mask == 1);
  CHECK(key.textured == 1);
  CHECK(key.tex_gens[0].texgentype == 0);
  CHECK(key.tex_gens[0].sourcerow == 5);
  CHECK(key.tex_gens[0].projection == 0);

  // Pipeline state from BP.
  CHECK(plan.pipeline.cull_mode == 1);
  CHECK(plan.pipeline.depth_test == 1);
  CHECK(plan.pipeline.depth_func == 3);
  CHECK(plan.pipeline.depth_update == 1);
  CHECK(plan.pipeline.blend_enable == 1);
  CHECK(plan.pipeline.src_factor == 4);
  CHECK(plan.pipeline.dst_factor == 5);
  CHECK(plan.pipeline.color_update == 1);
  CHECK(plan.pipeline.alpha_update == 1);

  // Decoded vertices: fixed 20-float layout.
  CHECK(plan.vertex_count == 4);
  CHECK(plan.vertices.size() == 4u * gxc::kVertexFloats);
  for (std::uint32_t v = 0; v < 4; ++v) {
    const float* dec = plan.vertices.data() + v * gxc::kVertexFloats;
    CHECK(dec[0] == quad[v][0]);
    CHECK(dec[1] == quad[v][1]);
    CHECK(dec[2] == quad[v][2]);
    std::uint32_t posmtx;
    std::memcpy(&posmtx, dec + 3, sizeof posmtx);
    CHECK(posmtx == 0);
    CHECK(dec[4] == 1.f && dec[7] == 1.f); // default white color0
    CHECK(dec[12] == quad[v][3]);
    CHECK(dec[13] == quad[v][4]);
  }
  CHECK(plan.indices.size() == 6);

  // Uniforms: ortho projection + identity texmatrix rows resolved via row 60.
  CHECK(plan.constants.projection[0][0] == 1.f);
  CHECK(plan.constants.projection[1][1] == 1.f);
  CHECK(plan.constants.projection[2][2] == -1.f);
  CHECK(plan.constants.projection[3][3] == 1.f);
  CHECK(plan.constants.texmatrices[0][0] == 1.f);
  CHECK(plan.constants.texmatrices[1][1] == 1.f);
  CHECK(plan.constants.texmatrices[2][2] == 1.f);
  CHECK(plan.constants.posnormalmatrix[0][0] == 1.f);

  CHECK(plan.has_texture);
  CHECK(plan.tex_width == 8 && plan.tex_height == 8);
  CHECK(plan.has_tlut);
  CHECK(plan.tlut_format == 2);
  CHECK(plan.tlut_entries == 16);
  CHECK(plan.tlut_data == tlut_bytes);
  CHECK(plan.tlut_available == sizeof tlut_bytes);
  CHECK(plan.viewport_valid);

  // WGSL golden.
  const std::string wgsl = gxc::generate_wgsl(key);
  if (std::getenv("GXCORE_PRINT_WGSL") != nullptr)
    std::printf("%s", wgsl.c_str());
  if (wgsl != kGoldenTexturedWgsl) {
    std::fprintf(stderr,
                 "FAIL WGSL golden mismatch; actual:\n%s\n--- end actual\n",
                 wgsl.c_str());
    ++g_failures;
  }
}

void test_untextured_defaults() {
  gxc::ShaderKey key{};
  key.num_tex_gens = 0;
  key.has_color0 = 1;
  const std::string wgsl = gxc::generate_wgsl(key);
  CHECK(wgsl.find("@group(2)") == std::string::npos);
  CHECK(wgsl.find("o.color0 = in.rawcolor0;") != std::string::npos);
  CHECK(wgsl.find("textureSample") == std::string::npos);
  // Per-vertex position matrix variant.
  gxc::ShaderKey pnkey{};
  pnkey.has_pos_mtx_idx = 1;
  const std::string pn = gxc::generate_wgsl(pnkey);
  CHECK(pn.find("vsc.transformmatrices[posidx]") != std::string::npos);
}

// Item 5: the vertex decoder packs the per-vertex TEXMTXIDX byte into the fixed
// layout and decodes NBT binormal/tangent (emboss inputs). No real Strikers/Melee
// scene exercises these attributes, so this synthetic draw is their coverage.
void test_vertex_texmtxidx_and_nbt() {
  gxc::GxCoreState state;
  state.reset();
  state.apply(bp(0x00, 1u | (1u << 14))); // 1 texgen, cull back
  state.apply(bp(0x40, 0x17u));
  state.apply(bp(0x41, 1u));
  // VCD lo: TexMatIdx0 (bit1), position direct (bits 9-10=1), normal direct
  // (bits 11-12=1), tex0 direct (bit21=1).
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0,
               .value = (1u << 1) | (1u << 9) | (1u << 11)});
  // VCD hi: tex0 present (direct).
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 1, .value = 1u});
  // VAT fmt0: pos 3-elem f32; normal NBT (bit9) f32 (bits10-12=4); tex0 2-elem
  // f32.
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1) | (1u << 9) | (4u << 10) | (1u << 21) |
                        (4u << 22),
               .aux0 = 0});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 1});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 2});

  ar::ConsumedDraw draw{};
  draw.primitive = 0x80; // quads
  draw.vtx_fmt = 0;
  draw.vertex_count = 4;
  // Per vertex: texmtxidx(1) + pos(12) + NBT(36) + tex0(8) = 57 bytes.
  draw.vertex_size = 57;
  std::vector<std::uint8_t> payload;
  for (int v = 0; v < 4; ++v) {
    payload.push_back(33u); // GX_TEXMTX1 row index
    append_be_f32(payload, static_cast<float>(v)); // pos x
    append_be_f32(payload, 0.f);
    append_be_f32(payload, 0.f);
    append_be_f32(payload, 1.f); // normal
    append_be_f32(payload, 0.f);
    append_be_f32(payload, 0.f);
    append_be_f32(payload, 0.f); // binormal
    append_be_f32(payload, 2.f);
    append_be_f32(payload, 0.f);
    append_be_f32(payload, 0.f); // tangent
    append_be_f32(payload, 0.f);
    append_be_f32(payload, 3.f);
    append_be_f32(payload, 0.f); // tex0
    append_be_f32(payload, 0.f);
  }
  draw.vertex_payload = payload;
  draw.transform_flags = ar::kDrawTransformProjectionValid;
  draw.projection[0] = 1.f;
  draw.projection[2] = 1.f;
  draw.projection[4] = -1.f;
  draw.projection_type = 1;
  draw.current_pn_matrix = 0;
  draw.position_matrix_valid_mask = 1u;
  draw.position_matrices[0][0] = 1.f;
  draw.position_matrices[0][5] = 1.f;
  draw.position_matrices[0][10] = 1.f;
  draw.xf_regs[0x27] = 1u; // numTexGens = 1
  draw.xf_reg_mask = (1ull << 0x27);

  gxc::GapCounters counters;
  const gxc::DrawPlan plan = state.build_draw_plan(draw, counters);
  if (!plan.ok)
    std::fprintf(stderr, "nbt plan skipped: %s\n", plan.skip_reason);
  CHECK(plan.ok);
  const gxc::ShaderKey& key = plan.pipeline.shader;
  CHECK(key.has_tex_mtx_idx == 1);
  CHECK(key.tex_mtx_idx_mask == 0x1);
  // Vertex 1 (pos.x == 1): TEXMTXIDX byte round-trips as a u32; binormal.y == 2,
  // tangent.z == 3.
  const float* vtx = plan.vertices.data() + gxc::kVertexFloats; // vertex 1
  std::uint32_t ti = 0;
  std::memcpy(&ti, vtx + gxc::kVertexTexMtxIdxOffset / 4u, sizeof ti);
  CHECK(ti == 33u);
  CHECK(vtx[gxc::kVertexBinormalOffset / 4u + 1u] == 2.f);
  CHECK(vtx[gxc::kVertexTangentOffset / 4u + 2u] == 3.f);
}

// Item 5: Color0/Color1 texgens drive the texcoord from a lit color channel
// (Dolphin VertexShaderGen). Color1 forces the color1 varying even off the TEV
// path, shifting the texcoord @locations up by one.
void test_texgen_color() {
  gxc::ShaderKey key{};
  key.num_tex_gens = 2;
  key.has_color0 = 1;
  key.has_color1 = 1;
  key.tex_gens[0].enabled = 1;
  key.tex_gens[0].texgentype = static_cast<std::uint8_t>(gxc::TexGenType::Color0);
  key.tex_gens[1].enabled = 1;
  key.tex_gens[1].texgentype = static_cast<std::uint8_t>(gxc::TexGenType::Color1);
  const std::string w = gxc::generate_wgsl(key);
  CHECK(w.find("@location(1) color1: vec4f,") != std::string::npos);
  CHECK(w.find("o.uv0 = vec3f(o.color0.x, o.color0.y, 1.0);") !=
        std::string::npos);
  CHECK(w.find("o.uv1 = vec3f(o.color1.x, o.color1.y, 1.0);") !=
        std::string::npos);
  // color1 lives at @location(1); the two texcoords shift to 2 and 3.
  CHECK(w.find("@location(2) uv0: vec3f,") != std::string::npos);
  CHECK(w.find("@location(3) uv1: vec3f,") != std::string::npos);
}

// Item 5: Emboss texgen (Dolphin VertexShaderGen) adds the view-space light dir
// projected onto tangent/binormal to the emboss-source texgen's coords. Needs
// the lights uniform + NBT vertex inputs even on an unlit draw.
void test_texgen_emboss() {
  gxc::ShaderKey key{};
  key.num_tex_gens = 2;
  // Real emboss draws carry the NBT (normal/binormal/tangent) attribute.
  key.has_vertex_normal = 1;
  key.has_vertex_binormal = 1;
  key.has_vertex_tangent = 1;
  key.tex_gens[0].enabled = 1; // regular source texgen
  key.tex_gens[0].texgentype = static_cast<std::uint8_t>(gxc::TexGenType::Regular);
  key.tex_gens[1].enabled = 1;
  key.tex_gens[1].texgentype =
      static_cast<std::uint8_t>(gxc::TexGenType::EmbossMap);
  key.tex_gens[1].embosssourceshift = 0; // source = texgen 0
  key.tex_gens[1].embosslightshift = 2;  // light index 2
  const std::string w = gxc::generate_wgsl(key);
  CHECK(w.find("struct Light {") != std::string::npos); // emboss forces lights
  CHECK(w.find("lights: array<Light, 8>,") != std::string::npos);
  CHECK(w.find("@location(8) rawnormal: vec3f,") != std::string::npos);
  CHECK(w.find("@location(10) rawbinormal: vec3f,") != std::string::npos);
  CHECK(w.find("@location(11) rawtangent: vec3f,") != std::string::npos);
  CHECK(w.find("normalize(vsc.lights[2u].pos.xyz - viewpos.xyz)") !=
        std::string::npos);
  // uv1 (emboss) offsets uv0 (its source texgen).
  CHECK(w.find("o.uv1 = o.uv0 + vec3f(dot(ld1, tn1), dot(ld1, bn1), 0.0);") !=
        std::string::npos);
}

// Item 5: per-vertex TEXMTXIDX selects a Regular texgen's matrix rows from the
// vertex attribute (transformmatrices) instead of the static texmatrices slot.
void test_texgen_per_vertex_mtx() {
  gxc::ShaderKey key{};
  key.num_tex_gens = 1;
  key.has_tex_mtx_idx = 1;
  key.tex_mtx_idx_mask = 0x1; // texgen 0 carries the attribute
  key.tex_gens[0].enabled = 1;
  key.tex_gens[0].texgentype = static_cast<std::uint8_t>(gxc::TexGenType::Regular);
  const std::string w = gxc::generate_wgsl(key);
  CHECK(w.find("@location(9) texmtxidx: u32,") != std::string::npos);
  CHECK(w.find("(in.texmtxidx >> (8u * 0u)) & 0xFFu") != std::string::npos);
  CHECK(w.find("vsc.transformmatrices[ti0]") != std::string::npos);
  // A texgen NOT in the mask keeps the static slot.
  gxc::ShaderKey key2{};
  key2.num_tex_gens = 1;
  key2.has_tex_mtx_idx = 1;
  key2.tex_mtx_idx_mask = 0x0; // texgen 0 does not carry it
  key2.tex_gens[0].enabled = 1;
  const std::string w2 = gxc::generate_wgsl(key2);
  CHECK(w2.find("vsc.texmatrices[0]") != std::string::npos);
  CHECK(w2.find("in.texmtxidx") == std::string::npos);
}

// Golden WGSL for the 1-stage modulate TEV key (tex * rasterized color0).
// Regenerate with GXCORE_PRINT_WGSL=1.
constexpr const char* kGoldenTevWgsl =
    R"(// gxcore generated shader (Dolphin VertexShaderGen shape)
struct VertexShaderConstants {
    posnormalmatrix: array<vec4f, 6>,
    projection: array<vec4f, 4>,
    texmatrices: array<vec4f, 24>,
    transformmatrices: array<vec4f, 64>,
};
@group(1) @binding(0) var<uniform> vsc: VertexShaderConstants;
struct PixelShaderConstants {
    colors: array<vec4i, 4>,
    kcolors: array<vec4i, 4>,
    alpha_ref: vec4i,
    fogcolor: vec4i,
    fogi: vec4i,
    fogf: vec4f,
    fogrange: array<vec4f, 3>,
};
@group(2) @binding(0) var<uniform> psc: PixelShaderConstants;
@group(3) @binding(0) var tex0: texture_2d<f32>;
@group(3) @binding(1) var samp0: sampler;
struct VertexIn {
    @location(0) rawpos: vec3f,
    @location(1) posmtx: u32,
    @location(2) rawcolor0: vec4f,
    @location(3) rawcolor1: vec4f,
    @location(4) rawtex0: vec2f,
    @location(5) rawtex1: vec2f,
    @location(6) rawtex2: vec2f,
    @location(7) rawtex3: vec2f,
};
struct VertexOut {
    @builtin(position) pos: vec4f,
    @location(0) color0: vec4f,
    @location(1) color1: vec4f,
    @location(2) uv0: vec3f,
};

@vertex
fn vs_main(in: VertexIn) -> VertexOut {
    var o: VertexOut;
    let p0 = vsc.posnormalmatrix[0];
    let p1 = vsc.posnormalmatrix[1];
    let p2 = vsc.posnormalmatrix[2];
    let pos4 = vec4f(in.rawpos, 1.0);
    let viewpos = vec4f(dot(p0, pos4), dot(p1, pos4), dot(p2, pos4), 1.0);
    var clip = vec4f(dot(vsc.projection[0], viewpos), dot(vsc.projection[1], viewpos), dot(vsc.projection[2], viewpos), dot(vsc.projection[3], viewpos));
    clip.z = -clip.z;
    o.pos = clip;
    o.color0 = vec4f(1.0);
    o.color1 = vec4f(1.0);
    {
        var coord = vec4f(0.0, 0.0, 1.0, 1.0);
        coord = vec4f(in.rawtex0.x, in.rawtex0.y, 1.0, 1.0);
        coord.z = 1.0;
        var uv = vec3f(dot(coord, vsc.texmatrices[0]), dot(coord, vsc.texmatrices[1]), 1.0);
        if (uv.z == 0.0) { uv = vec3f(clamp(uv.xy * 0.5, vec2f(-1.0), vec2f(1.0)), uv.z); }
        o.uv0 = uv;
    }
    return o;
}

@fragment
fn fs_main(in: VertexOut) -> @location(0) vec4f {
    var prev = psc.colors[0];
    var c0 = psc.colors[1];
    var c1 = psc.colors[2];
    var c2 = psc.colors[3];
    var rastemp = vec4i(0,0,0,0);
    var rawtextemp = vec4i(0,0,0,0);
    var textemp = vec4i(0,0,0,0);
    var konsttemp = vec4i(0,0,0,0);
    var tevin_a = vec4i(0,0,0,0);
    var tevin_b = vec4i(0,0,0,0);
    var tevin_c = vec4i(0,0,0,0);
    var tevin_d = vec4i(0,0,0,0);
    let col0i = vec4i(round(in.color0 * 255.0));
    let col1i = vec4i(round(in.color1 * 255.0));
    // TEV stage 0
    rastemp = col0i.rgba;
    { let uv = in.uv0.xy; rawtextemp = vec4i(round(textureSample(tex0, samp0, uv) * 255.0)); }
    textemp = rawtextemp.rgba;
    tevin_a = vec4i(vec3i(0,0,0), 0) & vec4i(255,255,255,255);
    tevin_b = vec4i(textemp.rgb, textemp.a) & vec4i(255,255,255,255);
    tevin_c = vec4i(rastemp.rgb, rastemp.a) & vec4i(255,255,255,255);
    tevin_d = vec4i(vec3i(0,0,0), 0);
    prev = vec4i(clamp(((tevin_d.rgb) + ((((tevin_a.rgb << vec3u(8u)) + (tevin_b.rgb - tevin_a.rgb) * (tevin_c.rgb + (tevin_c.rgb >> vec3u(7u)))) + 128) >> vec3u(8u))), vec3i(0,0,0), vec3i(255,255,255)), prev.a);
    prev = vec4i(prev.rgb, clamp(((tevin_d.a) + ((((tevin_a.a << 8u) + (tevin_b.a - tevin_a.a) * (tevin_c.a + (tevin_c.a >> 7u))) + 128) >> 8u)), 0, 255));
    if (!( (true) && (true) )) { discard; }
    return vec4f(prev) / 255.0;
}
)";

void test_tev_modulate() {
  gxc::GxCoreState state;
  state.reset();
  // genMode: 1 texgen, cull back, 1 TEV stage (numtevstages field 0 => 1).
  state.apply(bp(0x00, 1u | (1u << 14)));
  state.apply(bp(0x40, 0x17u));
  state.apply(bp(0x41, 1u | (5u << 5) | (4u << 8) | (1u << 3) | (1u << 4)));
  // ColorCombiner (0xC0): a=ZERO(15) b=TEXC(8) c=RASC(10) d=ZERO(15), clamp,
  // dest=prev => prev.rgb = tex * ras (modulate).
  state.apply(bp(0xC0, 15u | (10u << 4) | (8u << 8) | (15u << 12) | (1u << 19)));
  // AlphaCombiner (0xC1): a=ZERO(7) b=TEXA(4) c=RASA(5) d=ZERO(7), clamp.
  state.apply(bp(0xC1, (7u << 4) | (5u << 7) | (4u << 10) | (7u << 13) | (1u << 19)));
  // TwoTevStageOrders (0x28) stage0: texmap0, texcoord0, enable, colorchan0.
  state.apply(bp(0x28, (1u << 6)));
  // Swap table 0 = RGBA identity (ksel 0xF6/0xF7 swap fields).
  state.apply(bp(0xF6, 0u | (1u << 2)));
  state.apply(bp(0xF7, 2u | (3u << 2)));
  // AlphaTest (0xF3): Always/Always.
  state.apply(bp(0xF3, (7u << 16) | (7u << 19)));
  // TEV color reg0 (type 0): r=100 a=200 (RA), b=50 g=150 (BG). Then konst reg0
  // (type 1) ALIASES the same 0xE0/0xE1 address: r=30 a=40, b=20 g=10.
  state.apply(bp(0xE0, 100u | (200u << 12)));
  state.apply(bp(0xE1, 50u | (150u << 12)));
  state.apply(bp(0xE0, 30u | (40u << 12) | (1u << 23)));
  state.apply(bp(0xE1, 20u | (10u << 12) | (1u << 23)));
  // VCD/VAT: pos direct f32x3, tex0 direct f32x2 (same as textured test).
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0,
               .value = 1u << 9});
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 1, .value = 1u});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1) | (1u << 21) | (4u << 22), .aux0 = 0});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 1});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 2});

  ar::ConsumedDraw draw{};
  draw.primitive = 0x80;
  draw.vtx_fmt = 0;
  draw.vertex_count = 4;
  draw.vertex_size = 20;
  const float quad[4][5] = {{-1.f, -1.f, 0.f, 0.f, 0.f},
                            {1.f, -1.f, 0.f, 1.f, 0.f},
                            {1.f, 1.f, 0.f, 1.f, 1.f},
                            {-1.f, 1.f, 0.f, 0.f, 1.f}};
  std::vector<std::uint8_t> payload;
  for (const auto& v : quad)
    for (float f : v)
      append_be_f32(payload, f);
  draw.vertex_payload = payload;
  draw.transform_flags =
      ar::kDrawTransformProjectionValid | ar::kDrawTransformViewportValid;
  draw.projection[0] = 1.f;
  draw.projection[2] = 1.f;
  draw.projection[4] = -1.f;
  draw.projection_type = 1;
  draw.current_pn_matrix = 0;
  draw.position_matrix_valid_mask = 1u;
  draw.position_matrices[0][0] = 1.f;
  draw.position_matrices[0][5] = 1.f;
  draw.position_matrices[0][10] = 1.f;
  draw.xf_regs[0x00] = 60u << 6;
  draw.xf_regs[0x27] = 1u;
  draw.xf_regs[0x28] = 5u << 7;
  draw.xf_reg_mask = (1ull << 0x00) | (1ull << 0x27) | (1ull << 0x28);
  draw.tex_matrices[10][0] = 1.f;
  draw.tex_matrices[10][5] = 1.f;
  draw.tex_matrices[10][10] = 1.f;
  draw.tex_matrix_word_mask[10] = 0xFFFu;
  static const std::uint8_t tex_bytes[32] = {};
  draw.texture.valid = true;
  draw.texture.resolved = true;
  draw.texture.address = 0x80300000u;
  draw.texture.size = sizeof tex_bytes;
  draw.texture.format = 0xE;
  draw.texture.width = 8;
  draw.texture.height = 8;
  draw.texture.host_data = tex_bytes;
  draw.texture.host_available = sizeof tex_bytes;

  gxc::GapCounters counters;
  const gxc::DrawPlan plan = state.build_draw_plan(draw, counters);
  if (!plan.ok)
    std::fprintf(stderr, "tev plan skipped: %s\n", plan.skip_reason);
  CHECK(plan.ok);

  const gxc::ShaderKey& key = plan.pipeline.shader;
  CHECK(key.tev_valid == 1);
  CHECK(key.num_tev_stages == 1);
  CHECK(key.tev_stages[0].cc_a == 15);
  CHECK(key.tev_stages[0].cc_b == 8);
  CHECK(key.tev_stages[0].cc_c == 10);
  CHECK(key.tev_stages[0].cc_d == 15);
  CHECK(key.tev_stages[0].cc_clamp == 1);
  CHECK(key.tev_stages[0].cc_dest == 0);
  CHECK(key.tev_stages[0].ac_b == 4);
  CHECK(key.tev_stages[0].ac_c == 5);
  CHECK(key.tev_stages[0].tevorders_enable == 1);
  CHECK(key.tev_stages[0].tevorders_texmap == 0);
  CHECK(key.tev_stages[0].tevorders_colorchan == 0);
  CHECK(key.tev_stages[0].ras_swap[0] == 0 && key.tev_stages[0].ras_swap[3] == 3);
  CHECK(key.alpha_comp0 == 7 && key.alpha_comp1 == 7);
  CHECK(counters.tev_stages_over == 0);
  CHECK(counters.tev_multi_texmap == 0);
  CHECK(counters.alpha_compare_ignored == 0);

  // Aliased tev-color vs konst decode (both live off 0xE0/0xE1).
  CHECK(plan.pixel_constants.colors[0][0] == 100);
  CHECK(plan.pixel_constants.colors[0][1] == 150);
  CHECK(plan.pixel_constants.colors[0][2] == 50);
  CHECK(plan.pixel_constants.colors[0][3] == 200);
  CHECK(plan.pixel_constants.kcolors[0][0] == 30);
  CHECK(plan.pixel_constants.kcolors[0][1] == 10);
  CHECK(plan.pixel_constants.kcolors[0][2] == 20);
  CHECK(plan.pixel_constants.kcolors[0][3] == 40);

  const std::string wgsl = gxc::generate_wgsl(key);
  if (std::getenv("GXCORE_PRINT_WGSL") != nullptr)
    std::printf("%s", wgsl.c_str());
  if (wgsl != kGoldenTevWgsl) {
    std::fprintf(stderr, "FAIL TEV WGSL golden mismatch; actual:\n%s\n--- end\n",
                 wgsl.c_str());
    ++g_failures;
  }
}

void test_tev_konst_and_alpha() {
  // A stage that references KONST and a real alpha test => exercises the konst
  // table and the discard tail.
  gxc::ShaderKey key{};
  key.textured = 1;
  key.num_tex_gens = 1;
  key.tev_valid = 1;
  key.num_tev_stages = 1;
  key.alpha_comp0 = 4; // Greater
  key.alpha_comp1 = 7; // Always
  key.alpha_logic = 0; // and
  gxc::TevStageKey& s = key.tev_stages[0];
  s.cc_a = 8;  // TEXC
  s.cc_b = 14; // KONST
  s.cc_c = 8;  // TEXC
  s.cc_d = 15; // ZERO
  s.cc_clamp = 1;
  s.ac_a = 4; // TEXA
  s.ac_d = 7; // ZERO
  s.ac_clamp = 1;
  s.ksel_kc = 0x0C; // K0 rgb
  s.ksel_ka = 0x1C; // K0 a
  s.tevorders_enable = 1;
  const std::string wgsl = gxc::generate_wgsl(key);
  CHECK(wgsl.find("konsttemp = vec4i(psc.kcolors[0].rgb, psc.kcolors[0].a);") !=
        std::string::npos);
  CHECK(wgsl.find("if (!( (prev.a > psc.alpha_ref.x) && (true) )) { discard; }") !=
        std::string::npos);
  CHECK(wgsl.find("textureSample(tex0, samp0, uv)") != std::string::npos);
}

// Golden WGSL for the lit key below: color channel 0 lit by one directional
// light (attnfunc Dir, diffusefunc Clamp, matsource Vertex, ambsource Register),
// no texgens, TEV off. Regenerate with GXCORE_PRINT_WGSL=1.
constexpr const char* kGoldenLitWgsl =
    R"(// gxcore generated shader (Dolphin VertexShaderGen shape)
struct Light {
    color: vec4i,
    cosatt: vec4f,
    distatt: vec4f,
    pos: vec4f,
    dir: vec4f,
};
struct VertexShaderConstants {
    posnormalmatrix: array<vec4f, 6>,
    projection: array<vec4f, 4>,
    texmatrices: array<vec4f, 24>,
    transformmatrices: array<vec4f, 64>,
    lights: array<Light, 8>,
    materials: array<vec4i, 4>,
};
@group(1) @binding(0) var<uniform> vsc: VertexShaderConstants;
struct VertexIn {
    @location(0) rawpos: vec3f,
    @location(1) posmtx: u32,
    @location(2) rawcolor0: vec4f,
    @location(3) rawcolor1: vec4f,
    @location(4) rawtex0: vec2f,
    @location(5) rawtex1: vec2f,
    @location(6) rawtex2: vec2f,
    @location(7) rawtex3: vec2f,
    @location(8) rawnormal: vec3f,
};
struct VertexOut {
    @builtin(position) pos: vec4f,
    @location(0) color0: vec4f,
};

fn calc_lighting_chn0(base_color: vec4f, pos: vec3f, _normal: vec3f) -> vec4f {
    var lacc: vec4i;
    var mat: vec4i;
    var ldir: vec3f;
    var cosAttn: vec3f;
    var distAttn: vec3f;
    var dist: f32;
    var dist2: f32;
    var attn: f32;
    mat = vec4i(round(base_color * 255.0));
    lacc = vsc.materials[0];
    lacc.w = 255;
        { // light 0
            ldir = normalize(vsc.lights[0].pos.xyz - pos);
            attn = 1.0;
            if (length(ldir) == 0.0) { ldir = _normal; }
            lacc = lacc + vec4i(vec3i(round(attn * max(0.0, dot(ldir, _normal)) * vec3f(vsc.lights[0].color.rgb))), 0);
        }
    lacc = clamp(lacc, vec4i(0), vec4i(255));
    return vec4f((mat * (lacc + (lacc >> vec4u(7)))) >> vec4u(8)) / 255.0;
}

@vertex
fn vs_main(in: VertexIn) -> VertexOut {
    var o: VertexOut;
    let p0 = vsc.posnormalmatrix[0];
    let p1 = vsc.posnormalmatrix[1];
    let p2 = vsc.posnormalmatrix[2];
    let pos4 = vec4f(in.rawpos, 1.0);
    let viewpos = vec4f(dot(p0, pos4), dot(p1, pos4), dot(p2, pos4), 1.0);
    var clip = vec4f(dot(vsc.projection[0], viewpos), dot(vsc.projection[1], viewpos), dot(vsc.projection[2], viewpos), dot(vsc.projection[3], viewpos));
    clip.z = -clip.z;
    o.pos = clip;
    let _normal = normalize(vec3f(dot(vsc.posnormalmatrix[3].xyz, in.rawnormal), dot(vsc.posnormalmatrix[4].xyz, in.rawnormal), dot(vsc.posnormalmatrix[5].xyz, in.rawnormal)));
    o.color0 = calc_lighting_chn0(in.rawcolor0, viewpos.xyz, _normal);
    return o;
}

@fragment
fn fs_main(in: VertexOut) -> @location(0) vec4f {
    var prev = in.color0;
    return prev;
}
)";

void test_lighting() {
  gxc::GxCoreState state;
  state.reset();
  // BP: genMode = 0 texgens, cull none; zmode test/LEqual/update.
  state.apply(bp(0x00, 0u));
  state.apply(bp(0x40, 0x17u));
  // VCD: position + normal + color0, all direct.
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0,
               .value = (1u << 9) | (1u << 11) | (1u << 13)});
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 1, .value = 0u});
  // VAT fmt0: pos 3xf32; normal s8x3 (format 1 @ bit10); color0 RGBA8888
  // (format 5 @ bit14).
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1) | (1u << 10) | (5u << 14), .aux0 = 0});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 1});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0,
               .aux0 = 2});

  ar::ConsumedDraw draw{};
  draw.primitive = 0x80; // quads
  draw.vtx_fmt = 0;
  draw.vertex_count = 4;
  draw.vertex_size = 12 + 3 + 4; // pos f32x3 + normal s8x3 + color RGBA8
  // Payload per vertex: pos (3xf32 BE), normal (3x s8), color0 (RGBA8).
  const float pos[4][3] = {
      {-1.f, -1.f, 0.f}, {1.f, -1.f, 0.f}, {1.f, 1.f, 0.f}, {-1.f, 1.f, 0.f}};
  std::vector<std::uint8_t> payload;
  for (int v = 0; v < 4; ++v) {
    for (float f : pos[v])
      append_be_f32(payload, f);
    payload.push_back(0u);   // normal x = 0
    payload.push_back(0u);   // normal y = 0
    payload.push_back(64u);  // normal z = 64/64 = 1.0 (s8 frac 6)
    payload.push_back(0x40); // color rgba = (64,128,192,255)
    payload.push_back(0x80);
    payload.push_back(0xC0);
    payload.push_back(0xFF);
  }
  draw.vertex_payload = payload;

  draw.transform_flags =
      ar::kDrawTransformProjectionValid | ar::kDrawTransformViewportValid;
  draw.projection[0] = 1.f;
  draw.projection[2] = 1.f;
  draw.projection[4] = -1.f;
  draw.projection_type = 1;
  draw.current_pn_matrix = 0;
  draw.position_matrix_valid_mask = 1u;
  draw.position_matrices[0][0] = 1.f;
  draw.position_matrices[0][5] = 1.f;
  draw.position_matrices[0][10] = 1.f;

  // Channel control: color0 lit (Dir attn, Clamp diffuse, matsource Vertex,
  // ambsource Register, light 0). alpha0 unlit, matsource Vertex (matches color
  // so no mat.w override). numColorChans = 1.
  draw.chan_regs[0] = 1u; // numColorChans
  draw.chan_regs[1] = 0x20202080u; // ambient color reg (I_MATERIALS[0])
  draw.chan_regs[3] = 0x10101040u; // material color reg (I_MATERIALS[2])
  draw.chan_regs[5] = 1u | (1u << 1) | (1u << 2) | (2u << 7) | (2u << 9);
  draw.chan_regs[7] = 1u; // alpha0: matsource Vertex, lighting off
  draw.chan_reg_mask = (1u << 0) | (1u << 1) | (1u << 3) | (1u << 5) | (1u << 7);
  // Light 0: red directional (S6 kickoff rig: color 0xE50000E5, |pos|=2^20).
  auto set_lf = [&](std::uint32_t word, float f) {
    std::uint32_t b;
    std::memcpy(&b, &f, sizeof b);
    draw.light_words[0][word] = b;
  };
  draw.light_words[0][3] = 0xE50000E5u; // color RGBA
  set_lf(4, 1.f); // cosatt
  set_lf(7, 1.f); // distatt
  set_lf(10, 1048576.f); // pos.x = 2^20
  draw.light_word_mask[0] = 0xFFFFu;
  // Normal matrix (XF 0x400, S15 A2) for matrix 0: 3 rows of 3. Use a distinct
  // (non-identity) matrix so the load is observable vs the pos-row fallback.
  const float nm[9] = {2.f, 0.f, 0.f, 0.f, 3.f, 0.f, 0.f, 0.f, 4.f};
  for (int i = 0; i < 9; ++i)
    draw.normal_matrices[0][i] = nm[i];
  draw.normal_matrix_word_mask[0] = (1u << 9) - 1u;

  gxc::GapCounters counters;
  const gxc::DrawPlan plan = state.build_draw_plan(draw, counters);
  if (!plan.ok)
    std::fprintf(stderr, "lit plan skipped: %s\n", plan.skip_reason);
  CHECK(plan.ok);
  CHECK(counters.lighting_ignored == 0);
  CHECK(counters.normals_ignored == 0);

  const gxc::ShaderKey& key = plan.pipeline.shader;
  CHECK(key.lit_valid == 1);
  CHECK(key.num_color_chans == 1);
  CHECK(key.litchan[0].enablelighting == 1);
  CHECK(key.litchan[0].matsource == 1);   // Vertex
  CHECK(key.litchan[0].ambsource == 0);   // Register
  CHECK(key.litchan[0].diffusefunc == 2); // Clamp
  CHECK(key.litchan[0].attnfunc == 2);    // Dir
  CHECK(key.litchan[0].light_mask == 1);  // light 0
  CHECK(key.litchan[2].enablelighting == 0);
  CHECK(key.litchan[2].matsource == 1);

  // Decoded normal in the trailing vertex slot (z = 1.0).
  const float* n0 = plan.vertices.data() + gxc::kVertexNormalOffset / 4u;
  CHECK(n0[0] == 0.f);
  CHECK(n0[1] == 0.f);
  CHECK(n0[2] == 1.f);
  // Decoded vertex color0 = (64,128,192,255)/255.
  const float* dec = plan.vertices.data();
  CHECK(dec[4] == 64.f / 255.f);
  CHECK(dec[7] == 1.f);

  // Light + material uniforms.
  CHECK(plan.constants.lights[0].color[0] == 0xE5);
  CHECK(plan.constants.lights[0].color[1] == 0x00);
  CHECK(plan.constants.lights[0].color[3] == 0xE5);
  CHECK(plan.constants.lights[0].pos[0] == 1048576.f);
  CHECK(plan.constants.materials[0][0] == 0x20); // ambient reg
  CHECK(plan.constants.materials[0][3] == 0x80);
  CHECK(plan.constants.materials[2][0] == 0x10); // material reg
  // Normal matrix loaded into posnormalmatrix rows 3-5 (col 3 zeroed), not the
  // pos-row fallback (which would be identity here).
  CHECK(plan.constants.posnormalmatrix[3][0] == 2.f);
  CHECK(plan.constants.posnormalmatrix[3][3] == 0.f);
  CHECK(plan.constants.posnormalmatrix[4][1] == 3.f);
  CHECK(plan.constants.posnormalmatrix[5][2] == 4.f);

  const std::string wgsl = gxc::generate_wgsl(key);
  if (std::getenv("GXCORE_PRINT_WGSL") != nullptr)
    std::printf("%s", wgsl.c_str());
  // Structural checks (oracle-verifiable) in addition to the byte golden.
  CHECK(wgsl.find("fn calc_lighting_chn0(") != std::string::npos);
  CHECK(wgsl.find("fn calc_lighting_chn1(") == std::string::npos); // TEV off
  CHECK(wgsl.find("struct Light {") != std::string::npos);
  CHECK(wgsl.find("lights: array<Light, 8>,") != std::string::npos);
  CHECK(wgsl.find("@location(8) rawnormal: vec3f,") != std::string::npos);
  CHECK(wgsl.find("mat = vec4i(round(base_color * 255.0));") != std::string::npos);
  CHECK(wgsl.find("lacc = vsc.materials[0];") != std::string::npos); // ambsource Register
  CHECK(wgsl.find("lacc.w = 255;") != std::string::npos);            // alpha lighting off
  CHECK(wgsl.find("ldir = normalize(vsc.lights[0].pos.xyz - pos);") != std::string::npos);
  CHECK(wgsl.find("max(0.0, dot(ldir, _normal)) * vec3f(vsc.lights[0].color.rgb)") !=
        std::string::npos);
  CHECK(wgsl.find("o.color0 = calc_lighting_chn0(in.rawcolor0, viewpos.xyz, _normal);") !=
        std::string::npos);
  CHECK(wgsl.find("mat.w =") == std::string::npos); // alpha matsource matches color
  if (wgsl != kGoldenLitWgsl) {
    std::fprintf(stderr,
                 "FAIL lit WGSL golden mismatch; actual:\n%s\n--- end actual\n",
                 wgsl.c_str());
    ++g_failures;
  }
}

// Spot-attenuation config emits the spot math; a differing alpha matsource
// emits the mat.w override (both are LightingShaderGen branches not covered by
// the Dir golden above).
void test_lighting_spot_and_matw() {
  gxc::ShaderKey key{};
  key.lit_valid = 1;
  key.has_vertex_normal = 1; // real lit draw carries a per-vertex normal
  key.num_color_chans = 2;
  key.tev_valid = 1;
  key.num_tev_stages = 1;
  key.chan_captured_mask = 0x1; // channel 0 control regs (color0 + alpha0) seen
  key.litchan[0].enablelighting = 1;
  key.litchan[0].matsource = 0;    // Register
  key.litchan[0].ambsource = 1;    // Vertex
  key.litchan[0].diffusefunc = 1;  // Sign
  key.litchan[0].attnfunc = 3;     // Spot
  key.litchan[0].light_mask = 0x2; // light 1
  key.litchan[2].enablelighting = 1;
  key.litchan[2].matsource = 1; // Vertex (differs from color -> mat.w override)
  key.litchan[2].attnfunc = 1;  // Spec
  key.litchan[2].light_mask = 0x1;
  const std::string wgsl = gxc::generate_wgsl(key);
  // Channel 1 is unconfigured, so its lighting function is not emitted even with
  // TEV on; o.color1 passes the vertex color through (identical to running the
  // unlit lighting function). The spot/spec math below lives in chn0.
  CHECK(wgsl.find("fn calc_lighting_chn0(") != std::string::npos);
  CHECK(wgsl.find("fn calc_lighting_chn1(") == std::string::npos);
  CHECK(wgsl.find("o.color1 = in.rawcolor1;") != std::string::npos ||
        wgsl.find("o.color1 = vec4f(1.0);") != std::string::npos);
  CHECK(wgsl.find("dist2 = dot(ldir, ldir);") != std::string::npos); // Spot
  CHECK(wgsl.find("mat.w = i32(round(base_color.w * 255.0));") != std::string::npos);
  CHECK(wgsl.find("lacc = vec4i(round(base_color * 255.0));") != std::string::npos); // ambsource Vertex
  CHECK(wgsl.find("(dot(ldir, _normal)) * vec3f") != std::string::npos); // Sign (no max)
  // Spec alpha light: select() attenuation.
  CHECK(wgsl.find("attn = select(0.0, max(0.0, dot(_normal, vsc.lights[0].dir.xyz))") !=
        std::string::npos);
}

// Completeness cases that the all-or-nothing lit gate used to miss (Dolphin
// VertexShaderGen WriteVertexBody runs dolphin_calculate_lighting_chn for every
// configured channel, applying register material/ambient and the vertex-color
// presence rules even when no light is enabled).
void test_lighting_completeness() {
  // (A) Unlit channel that selects a REGISTER material must output the material
  // register, not the vertex color. The channel is captured, lighting off, no
  // normal — the full uniform is still needed for vsc.materials, and _normal is
  // a constant since no light reads it.
  {
    gxc::ShaderKey key{};
    key.num_color_chans = 1;
    key.has_color0 = 1;
    key.chan_captured_mask = 0x1; // color0 + alpha0 control regs seen
    key.litchan[0].enablelighting = 0;
    key.litchan[0].matsource = 0; // Register
    key.litchan[2].matsource = 0; // Register (alpha)
    const std::string wgsl = gxc::generate_wgsl(key);
    CHECK(wgsl.find("fn calc_lighting_chn0(") != std::string::npos);
    CHECK(wgsl.find("materials: array<vec4i, 4>,") != std::string::npos);
    CHECK(wgsl.find("@location(8) rawnormal: vec3f,") == std::string::npos);
    CHECK(wgsl.find("let _normal = vec3f(0.0, 0.0, 1.0);") != std::string::npos);
    CHECK(wgsl.find("mat = vsc.materials[2];") != std::string::npos); // register mat
    CHECK(wgsl.find("lacc = vec4i(255, 255, 255, 255);") != std::string::npos); // unlit seed
    CHECK(wgsl.find("vsc.lights[") == std::string::npos); // no light loop body
    CHECK(wgsl.find("o.color0 = calc_lighting_chn0(in.rawcolor0, viewpos.xyz, _normal);") !=
          std::string::npos);
  }
  // (B) Vertex-color presence rules: with only color1 present, channel 0 falls
  // back to rawcolor1 and channel 1 uses the white missing value (Dolphin
  // WriteVertexBody select loop). All channels unlit (passthrough).
  {
    gxc::ShaderKey key{};
    key.num_color_chans = 2;
    key.has_color0 = 0;
    key.has_color1 = 1;
    key.tev_valid = 1; // emit color1 varying
    key.num_tev_stages = 1;
    const std::string wgsl = gxc::generate_wgsl(key);
    CHECK(wgsl.find("fn calc_lighting_chn0(") == std::string::npos); // passthrough
    CHECK(wgsl.find("o.color0 = in.rawcolor1;") != std::string::npos); // fallback
    CHECK(wgsl.find("o.color1 = vec4f(1.0);") != std::string::npos);   // missing
  }
  // (C) numColorChans gating applies on the passthrough path too: a 0-channel
  // unlit draw zeroes color0.
  {
    gxc::ShaderKey key{};
    key.num_color_chans = 0;
    key.has_color0 = 1;
    const std::string wgsl = gxc::generate_wgsl(key);
    CHECK(wgsl.find("o.color0 = in.rawcolor0;") != std::string::npos);
    CHECK(wgsl.find("o.color0 = vec4f(0.0);") != std::string::npos);
  }
}

// I_CACHED_NORMAL (Dolphin VertexShaderGen.cpp:607-632): a LIT draw whose vertex
// format omits the normal reuses the last-decoded vertex's normal from the
// uniform (cross-draw normal_cache) instead of a zeroed input (normalize(0)=NaN).
void test_cached_normal() {
  // --- (A) WGSL: lit key without a per-vertex normal reads the cached fallback.
  {
    gxc::ShaderKey key{};
    key.lit_valid = 1;
    key.has_vertex_normal = 0; // format carries no normal
    key.num_color_chans = 1;
    key.has_color0 = 1;
    key.chan_captured_mask = 0x1;
    key.litchan[0].enablelighting = 1;
    key.litchan[0].attnfunc = 2; // Dir
    key.litchan[0].diffusefunc = 2;
    key.litchan[0].light_mask = 0x1;
    const std::string wgsl = gxc::generate_wgsl(key);
    // No per-vertex normal input; the cached uniform field is declared instead.
    CHECK(wgsl.find("@location(8) rawnormal: vec3f,") == std::string::npos);
    CHECK(wgsl.find("cached_normal: vec4f,") != std::string::npos);
    CHECK(wgsl.find("cached_tangent: vec4f,") != std::string::npos);
    CHECK(wgsl.find("cached_binormal: vec4f,") != std::string::npos);
    // _normal is transformed from the cached value, not a per-vertex input.
    CHECK(wgsl.find("dot(vsc.posnormalmatrix[3].xyz, vsc.cached_normal.xyz)") !=
          std::string::npos);
    CHECK(wgsl.find("in.rawnormal") == std::string::npos);
    // A lit draw WITH a normal keeps the per-vertex input and omits the cached
    // field (existing goldens stay byte-identical).
    gxc::ShaderKey key2 = key;
    key2.has_vertex_normal = 1;
    const std::string wgsl2 = gxc::generate_wgsl(key2);
    CHECK(wgsl2.find("@location(8) rawnormal: vec3f,") != std::string::npos);
    CHECK(wgsl2.find("cached_normal: vec4f,") == std::string::npos);
    CHECK(wgsl2.find("dot(vsc.posnormalmatrix[3].xyz, in.rawnormal)") !=
          std::string::npos);
  }

  // --- (B) Decode: a draw carrying a normal advances the cross-draw cache to
  // its LAST vertex; a following lit no-normal draw reads that value into the
  // uniform (Dolphin normal_cache -> cached_normal).
  gxc::GxCoreState state;
  state.reset();
  state.apply(bp(0x00, 0u));
  state.apply(bp(0x40, 0x17u));

  // Shared channel/light/projection config for a lit draw (color0 lit, light 0).
  auto configure_lit = [](ar::ConsumedDraw& draw) {
    draw.primitive = 0x80; // quads
    draw.transform_flags =
        ar::kDrawTransformProjectionValid | ar::kDrawTransformViewportValid;
    draw.projection[0] = 1.f;
    draw.projection[2] = 1.f;
    draw.projection[4] = -1.f;
    draw.projection_type = 1;
    draw.current_pn_matrix = 0;
    draw.position_matrix_valid_mask = 1u;
    draw.position_matrices[0][0] = 1.f;
    draw.position_matrices[0][5] = 1.f;
    draw.position_matrices[0][10] = 1.f;
    draw.chan_regs[0] = 1u; // numColorChans
    draw.chan_regs[5] = 1u | (1u << 1) | (1u << 2) | (2u << 7) | (2u << 9);
    draw.chan_reg_mask = (1u << 0) | (1u << 5);
    draw.light_words[0][3] = 0xE50000E5u;
    draw.light_word_mask[0] = 0xFFFFu;
    const float nm[9] = {1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f};
    for (int i = 0; i < 9; ++i)
      draw.normal_matrices[0][i] = nm[i];
    draw.normal_matrix_word_mask[0] = (1u << 9) - 1u;
  };
  const float quad[4][3] = {
      {-1.f, -1.f, 0.f}, {1.f, -1.f, 0.f}, {1.f, 1.f, 0.f}, {-1.f, 1.f, 0.f}};

  // Draw A: pos + normal + color0. Last vertex's normal is (0, 1, 0) (s8 z=0,
  // y=64/64=1) so the cache should hold that after the draw.
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0,
               .value = (1u << 9) | (1u << 11) | (1u << 13)});
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 1, .value = 0u});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1) | (1u << 10) | (5u << 14), .aux0 = 0});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0, .aux0 = 1});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0, .aux0 = 2});
  ar::ConsumedDraw draw_a{};
  configure_lit(draw_a);
  draw_a.vertex_count = 4;
  draw_a.vertex_size = 12 + 3 + 4;
  {
    std::vector<std::uint8_t> payload;
    for (int v = 0; v < 4; ++v) {
      for (float f : quad[v])
        append_be_f32(payload, f);
      payload.push_back(0u);   // normal x = 0
      payload.push_back(64u);  // normal y = 64/64 = 1.0 (s8 frac 6)
      payload.push_back(0u);   // normal z = 0
      payload.push_back(0x40); payload.push_back(0x80);
      payload.push_back(0xC0); payload.push_back(0xFF);
    }
    draw_a.vertex_payload = payload;
  }

  gxc::CachedVertexAttrs cache{};
  gxc::GapCounters counters;
  const gxc::DrawPlan plan_a = state.build_draw_plan(draw_a, counters, &cache);
  CHECK(plan_a.ok);
  CHECK(plan_a.pipeline.shader.has_vertex_normal == 1);
  // Cache advanced to the last vertex's raw object-space normal (0, 1, 0).
  CHECK(std::fabs(cache.normal[0] - 0.f) < 1e-4f);
  CHECK(std::fabs(cache.normal[1] - 1.f) < 1e-4f);
  CHECK(std::fabs(cache.normal[2] - 0.f) < 1e-4f);

  // Draw B: pos + color0 only (NO normal), same lit channel config.
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0,
               .value = (1u << 9) | (1u << 13)});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1) | (5u << 14), .aux0 = 0});
  ar::ConsumedDraw draw_b{};
  configure_lit(draw_b);
  draw_b.vertex_count = 4;
  draw_b.vertex_size = 12 + 4;
  {
    std::vector<std::uint8_t> payload;
    for (int v = 0; v < 4; ++v) {
      for (float f : quad[v])
        append_be_f32(payload, f);
      payload.push_back(0x40); payload.push_back(0x80);
      payload.push_back(0xC0); payload.push_back(0xFF);
    }
    draw_b.vertex_payload = payload;
  }
  const gxc::DrawPlan plan_b = state.build_draw_plan(draw_b, counters, &cache);
  CHECK(plan_b.ok);
  CHECK(plan_b.pipeline.shader.lit_valid == 1);
  CHECK(plan_b.pipeline.shader.has_vertex_normal == 0);
  // The no-normal lit draw carries the cached normal into its uniform, so the
  // shader's cached fallback resolves to a real direction instead of NaN.
  CHECK(std::fabs(plan_b.constants.cached_normal[0] - 0.f) < 1e-4f);
  CHECK(std::fabs(plan_b.constants.cached_normal[1] - 1.f) < 1e-4f);
  CHECK(std::fabs(plan_b.constants.cached_normal[2] - 0.f) < 1e-4f);
  const std::string wgsl_b = gxc::generate_wgsl(plan_b.pipeline.shader);
  CHECK(wgsl_b.find("vsc.cached_normal.xyz") != std::string::npos);
  CHECK(wgsl_b.find("in.rawnormal") == std::string::npos);
}

// S16 fog: the WGSL fragment lines (all fog curves + range adjust) generated
// directly from a key, and the plan uniforms (A/C/b/color/range) decoded from
// the BP fog registers through the full state path.
void test_fog() {
  // --- WGSL golden per fog type (direct key) -------------------------------
  auto fog_key = [](gxc::FogType t, gxc::FogProjection p, bool range) {
    gxc::ShaderKey k{};
    k.num_tex_gens = 1;
    k.textured = 1;
    k.tev_valid = 1;
    k.num_tev_stages = 1;
    k.tev_stages[0].tevorders_enable = 1;
    k.fog_fsel = static_cast<std::uint8_t>(t);
    k.fog_proj = static_cast<std::uint8_t>(p);
    k.fog_range = range ? 1 : 0;
    return k;
  };
  const std::string persp = gxc::generate_wgsl(
      fog_key(gxc::FogType::BackwardsExpSq, gxc::FogProjection::Perspective, true));
  // GC zCoord (reversed-Z) + perspective ze + range adjust + BackExpSq curve +
  // integer fog blend — exactly Dolphin PixelShaderGen WriteFog.
  CHECK(persp.find("var zCoord = i32((1.0 - in.pos.z) * 16777216.0);") !=
        std::string::npos);
  CHECK(persp.find("var ze = (psc.fogf.x * 16777216.0) / f32(psc.fogi.y - "
                   "(zCoord >> u32(psc.fogi.w)));") != std::string::npos);
  CHECK(persp.find("let x_adjust = sqrt(offset * offset + k * k) / k;") !=
        std::string::npos);
  CHECK(persp.find("fogv = 1.0 - fogv;\n    fogv = exp2(-8.0 * fogv * fogv);") !=
        std::string::npos);
  CHECK(persp.find("prev = vec4i((prev.rgb * (256 - ifog) + psc.fogcolor.rgb * "
                   "ifog) >> vec3u(8u), prev.a);") != std::string::npos);

  // Orthographic ze, no range adjust.
  const std::string ortho = gxc::generate_wgsl(
      fog_key(gxc::FogType::Linear, gxc::FogProjection::Orthographic, false));
  CHECK(ortho.find("var ze = psc.fogf.x * f32(zCoord) / 16777216.0;") !=
        std::string::npos);
  CHECK(ortho.find("x_adjust") == std::string::npos); // range off
  CHECK(ortho.find("fogv = 1.0 - exp2") == std::string::npos); // linear: no curve

  // Each remaining curve emits its Dolphin table line.
  CHECK(gxc::generate_wgsl(fog_key(gxc::FogType::Exp,
                                   gxc::FogProjection::Perspective, false))
            .find("fogv = 1.0 - exp2(-8.0 * fogv);") != std::string::npos);
  CHECK(gxc::generate_wgsl(fog_key(gxc::FogType::ExpSq,
                                   gxc::FogProjection::Perspective, false))
            .find("fogv = 1.0 - exp2(-8.0 * fogv * fogv);") != std::string::npos);
  CHECK(gxc::generate_wgsl(fog_key(gxc::FogType::BackwardsExp,
                                   gxc::FogProjection::Perspective, false))
            .find("fogv = exp2(-8.0 * (1.0 - fogv));") != std::string::npos);
  // Off => no fog fragment at all.
  CHECK(gxc::generate_wgsl(fog_key(gxc::FogType::Off,
                                   gxc::FogProjection::Perspective, false))
            .find("// Fog (Dolphin WriteFog)") == std::string::npos);

  // --- Plan uniforms decoded from BP fog registers (state path) ------------
  gxc::GxCoreState state;
  state.reset();
  state.apply(bp(0x00, 1u | (1u << 14)));       // 1 texgen, cull back
  state.apply(bp(0x40, 0x17u));                 // zmode
  state.apply(bp(0xC0, 0u));                    // a combiner => tev_valid
  // Fog: A=1.0 (0x3F800), C=0.5 perspective BackExpSq (0xE3F000), b_mag=256,
  // b_shift=4, color rgb=(128,64,32), range enabled center=662, K=(LO256,HI512).
  state.apply(bp(0xEE, 0x3F800u));
  state.apply(bp(0xEF, 256u));
  state.apply(bp(0xF0, 4u));
  state.apply(bp(0xF1, 0xE3F000u));
  state.apply(bp(0xF2, 0x804020u));
  state.apply(bp(0xE8, 662u | (1u << 10)));
  for (std::uint32_t i = 0; i < 5u; ++i)
    state.apply(bp(0xE9u + i, (256u << 12) | 512u));
  // VCD/VAT: pos direct f32x3 (matches test_state_to_plan_and_wgsl).
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 0, .value = 1u << 9});
  state.apply({.kind = ar::RenderStateKind::CpVcd, .index = 1, .value = 0u});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0,
               .value = 1u | (4u << 1), .aux0 = 0});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0, .aux0 = 1});
  state.apply({.kind = ar::RenderStateKind::CpVat, .index = 0, .value = 0, .aux0 = 2});

  ar::ConsumedDraw draw{};
  draw.primitive = 0x90; // triangles
  draw.vtx_fmt = 0;
  draw.vertex_count = 3;
  draw.vertex_size = 12;
  const float tri[3][3] = {{-1.f, -1.f, 0.f}, {1.f, -1.f, 0.f}, {0.f, 1.f, 0.f}};
  std::vector<std::uint8_t> payload;
  for (const auto& v : tri)
    for (float f : v)
      append_be_f32(payload, f);
  draw.vertex_payload = payload;
  draw.transform_flags =
      ar::kDrawTransformProjectionValid | ar::kDrawTransformViewportValid;
  draw.projection[0] = 1.f;
  draw.projection[2] = 1.f;
  draw.projection[4] = -1.f;
  draw.projection_type = 1;
  draw.current_pn_matrix = 0;
  draw.position_matrix_valid_mask = 1u;
  draw.position_matrices[0][0] = 1.f;
  draw.position_matrices[0][5] = 1.f;
  draw.position_matrices[0][10] = 1.f;
  draw.xf_regs[0x27] = 1u;    // numTexGens=1
  draw.xf_regs[0x28] = 5u << 7; // texgen0 source Tex0
  draw.xf_reg_mask = (1ull << 0x27) | (1ull << 0x28);
  static const std::uint8_t tex_bytes[32] = {};
  draw.texture.valid = true;
  draw.texture.resolved = true;
  draw.texture.address = 0x80300000u;
  draw.texture.size = sizeof tex_bytes;
  draw.texture.format = 0xE; // CMPR
  draw.texture.width = 8;
  draw.texture.height = 8;
  draw.texture.host_data = tex_bytes;
  draw.texture.host_available = sizeof tex_bytes;
  draw.viewport[0] = 320.f; // wd/2 => two_wd = 1280
  draw.viewport[1] = -240.f;
  draw.viewport[2] = 16777215.f;
  draw.viewport[3] = 662.f;
  draw.viewport[4] = 582.f;
  draw.viewport[5] = 16777215.f;

  gxc::GapCounters counters;
  const gxc::DrawPlan plan = state.build_draw_plan(draw, counters);
  if (!plan.ok)
    std::fprintf(stderr, "fog plan skipped: %s\n", plan.skip_reason);
  CHECK(plan.ok);
  const gxc::ShaderKey& key = plan.pipeline.shader;
  CHECK(key.fog_fsel == static_cast<std::uint8_t>(gxc::FogType::BackwardsExpSq));
  CHECK(key.fog_proj == static_cast<std::uint8_t>(gxc::FogProjection::Perspective));
  CHECK(key.fog_range == 1);
  CHECK(plan.pixel_constants.fogf[0] == 1.0f);  // A
  CHECK(plan.pixel_constants.fogf[1] == 0.5f);  // C
  CHECK(plan.pixel_constants.fogi[1] == 256);   // b_magnitude
  CHECK(plan.pixel_constants.fogi[3] == 4);     // b_shift
  CHECK(plan.pixel_constants.fogcolor[0] == 128);
  CHECK(plan.pixel_constants.fogcolor[1] == 64);
  CHECK(plan.pixel_constants.fogcolor[2] == 32);
  // Range: center=(662-342)=320, two_wd=1280 => ssc = 320/1280*2-1 = -0.5.
  CHECK(plan.pixel_constants.fogf[2] == -0.5f);
  CHECK(plan.pixel_constants.fogf[3] == 1280.f);
  // K table: LO/256*4 = 4.0, HI/256*4 = 8.0, alternating over indices 0..9.
  CHECK(plan.pixel_constants.fogrange[0][0] == 4.0f);
  CHECK(plan.pixel_constants.fogrange[0][1] == 8.0f);
  CHECK(plan.pixel_constants.fogrange[2][1] == 8.0f); // index 9 (K[4].HI)
  CHECK(counters.fog_ignored == 0);
}

// S16 EFB copy: the GxCoreSink turns a resolved CopyDestination packet into an
// EfbCopyCommand carrying the dest/rect/format + the copy-clear color/Z from
// live BP state, and only when a copy observer is registered (else it counts
// efb_copy_ignored). GPU resolve is out of scope headlessly; this pins the
// packet->command decode + counter behavior.
gxc::EfbCopyCommand g_captured_copy;
int g_copy_fire_count = 0;
void capture_copy(const gxc::EfbCopyCommand& cmd, void*) {
  g_captured_copy = cmd;
  ++g_copy_fire_count;
}

ar::RenderPacket state_packet(std::uint32_t reg, std::uint32_t value) {
  ar::RenderPacket p;
  p.kind = ar::RenderPacketKind::State;
  p.state = bp(reg, value);
  return p;
}

void test_efb_copy_sink() {
  // A CopyDestination with no observer counts efb_copy_ignored (Mode A stub).
  {
    gxc::GxCoreSink sink;
    ar::RenderPacket copy;
    copy.kind = ar::RenderPacketKind::Resource;
    copy.resource.kind = ar::RenderResourceKind::CopyDestination;
    copy.resource.address = 0x00528BC0u;
    copy.resource.size = 71680u;
    // BP 0x52 is the trigger the frontend also emits as state; count that.
    sink.submit_packet(state_packet(0x52u, 0u));
    sink.submit_packet(copy);
    CHECK(sink.counters().efb_copy_ignored == 1);
    CHECK(sink.counters().efb_copies == 0);
  }
  // With an observer: no ignored count, the command carries the resolved copy
  // params + the clear color/Z decoded from BP 0x4F/0x50/0x51 live state.
  {
    gxc::GxCoreSink sink;
    g_copy_fire_count = 0;
    sink.set_copy_observer(capture_copy, nullptr);
    // GXSetCopyClear encoding: 0x4F = R | A<<8, 0x50 = B | G<<8, 0x51 = Z(24).
    sink.submit_packet(state_packet(0x4Fu, 0x10u | (0x40u << 8)));   // R=16 A=64
    sink.submit_packet(state_packet(0x50u, 0x20u | (0x80u << 8)));   // B=32 G=128
    sink.submit_packet(state_packet(0x51u, 0x00ABCDEFu & 0xFFFFFFu)); // Z
    sink.submit_packet(state_packet(0x52u, 0u)); // trigger (no ignored w/ observer)
    ar::RenderPacket copy;
    copy.kind = ar::RenderPacketKind::Resource;
    copy.resource.kind = ar::RenderResourceKind::CopyDestination;
    copy.resource.address = 0x0053A4E0u;
    copy.resource.size = 6080u;
    copy.resource.format = 1u; // I8
    copy.resource.width = 96u;
    copy.resource.height = 32u;
    copy.resource.copy_src_x = 12u;
    copy.resource.copy_src_y = 34u;
    copy.resource.copy_clear = 1u;
    sink.submit_packet(copy);
    CHECK(g_copy_fire_count == 1);
    CHECK(sink.counters().efb_copy_ignored == 0);
    CHECK(sink.counters().efb_copies == 1);
    CHECK(g_captured_copy.dest_address == 0x0053A4E0u);
    CHECK(g_captured_copy.byte_size == 6080u);
    CHECK(g_captured_copy.format == 1u);
    CHECK(g_captured_copy.width == 96u);
    CHECK(g_captured_copy.height == 32u);
    CHECK(g_captured_copy.src_x == 12u);
    CHECK(g_captured_copy.src_y == 34u);
    CHECK(g_captured_copy.clear == true);
    CHECK(g_captured_copy.clear_r == 16u);
    CHECK(g_captured_copy.clear_g == 128u);
    CHECK(g_captured_copy.clear_b == 32u);
    CHECK(g_captured_copy.clear_a == 64u);
    CHECK(g_captured_copy.clear_z == 0xABCDEFu);
    CHECK(sink.counters().efb_copy_depth == 0);
    // A Z-source copy (frontend folded PE_CONTROL Z24 into the GXTexFmt Z
    // bit) fires the same observer and is tallied separately.
    copy.resource.format = 0x16u; // GX_TF_Z24X8
    sink.submit_packet(copy);
    CHECK(g_copy_fire_count == 2);
    CHECK(g_captured_copy.format == 0x16u);
    CHECK(sink.counters().efb_copies == 2);
    CHECK(sink.counters().efb_copy_depth == 1);
  }
}

} // namespace

int main() {
  test_state_to_plan_and_wgsl();
  test_untextured_defaults();
  test_texgen_color();
  test_texgen_emboss();
  test_texgen_per_vertex_mtx();
  test_vertex_texmtxidx_and_nbt();
  test_tev_modulate();
  test_tev_konst_and_alpha();
  test_lighting();
  test_lighting_spot_and_matw();
  test_lighting_completeness();
  test_cached_normal();
  test_fog();
  test_efb_copy_sink();
  if (g_failures != 0) {
    std::fprintf(stderr, "gxcore_tests: %d failure(s)\n", g_failures);
    return 1;
  }
  std::printf("gxcore_tests: OK\n");
  return 0;
}
