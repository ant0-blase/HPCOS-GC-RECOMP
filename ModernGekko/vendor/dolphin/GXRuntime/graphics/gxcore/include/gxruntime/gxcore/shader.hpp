// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// gxcore — Dolphin-ported GX semantics core.
//
// This header is std-only: shader/pipeline keys derived from raw GX register
// state, the WGSL generator, the uniform-block layout, and the DrawPlan a GPU
// submission layer consumes. Semantics are ported from Dolphin
// (VideoCommon/{XFMemory,CPMemory,BPMemory}.h + VertexShaderGen.cpp shapes);
// register bit positions are cited there, not re-derived. No GPU or frontend
// types here — the fork's gxcore_draw module and the headless tests both
// include this file.

#include <cstdint>
#include <string>
#include <type_traits>
#include <vector>

namespace gxruntime::gxcore {

// --- GX register semantics (Dolphin BPMemory.h / XFMemory.h) ---------------

// BP genMode bits 14-15. NOTE: the SDK's GXSetCullMode SWAPS front/back when
// writing genMode (GX_CULL_FRONT=1 writes 2), so these BP-space values are
// Dolphin's CullMode, not the SDK enum.
enum class CullMode : std::uint8_t { None = 0, Back = 1, Front = 2, All = 3 };

// BP zmode (0x40) bits 1-3.
enum class CompareMode : std::uint8_t {
  Never = 0,
  Less = 1,
  Equal = 2,
  LEqual = 3,
  Greater = 4,
  NEqual = 5,
  GEqual = 6,
  Always = 7,
};

// BP cmode0 (0x41) bits 5-7 / 8-10.
enum class SrcBlendFactor : std::uint8_t {
  Zero = 0,
  One = 1,
  DstClr = 2,
  InvDstClr = 3,
  SrcAlpha = 4,
  InvSrcAlpha = 5,
  DstAlpha = 6,
  InvDstAlpha = 7,
};
enum class DstBlendFactor : std::uint8_t {
  Zero = 0,
  One = 1,
  SrcClr = 2,
  InvSrcClr = 3,
  SrcAlpha = 4,
  InvSrcAlpha = 5,
  DstAlpha = 6,
  InvDstAlpha = 7,
};

// XF texgen spec (0x1040+i) fields — XFMemory.h TexMtxInfo.
enum class TexGenType : std::uint8_t {
  Regular = 0,
  EmbossMap = 1,
  Color0 = 2,
  Color1 = 3,
};
enum class TexSourceRow : std::uint8_t {
  Geom = 0,
  Normal = 1,
  Colors = 2,
  BinormalT = 3,
  BinormalB = 4,
  Tex0 = 5, // ..Tex7 = 12
};

// XF channel-control (LitChannel) semantics — XFMemory.h. matsource/ambsource
// 0 = color register, 1 = vertex; diffusefunc {None,Sign,Clamp}; attnfunc
// {None,Spec,Dir,Spot} (S6 verified the SDK encoding = this raw field).
enum class MatSource : std::uint8_t { Register = 0, Vertex = 1 };
enum class DiffuseFunc : std::uint8_t { None = 0, Sign = 1, Clamp = 2 };
enum class AttenuationFunc : std::uint8_t {
  None = 0, // no attenuation
  Spec = 1, // point-light (specular) attenuation
  Dir = 2,  // directional attenuation
  Spot = 3, // spot attenuation
};

// BP fog (0xEE-0xF2) — Dolphin BPMemory.h FogParam3.fsel/proj. FogType values
// are the raw 3-bit fsel field; the odd codes (1,3) are unused by hardware.
enum class FogType : std::uint8_t {
  Off = 0,
  Linear = 2,
  Exp = 4,
  ExpSq = 5,
  BackwardsExp = 6,
  BackwardsExpSq = 7,
};
enum class FogProjection : std::uint8_t { Perspective = 0, Orthographic = 1 };

// --- Shader / pipeline keys -------------------------------------------------

// Slice cap: the S9 corpus histogram shows texgens <= 4 across all scenes.
inline constexpr std::uint32_t kMaxTexGens = 4;

// Slice cap: the S9 gameplay histogram shows numtevstages <= 6.
inline constexpr std::uint32_t kMaxTevStages = 8;

// One TEV stage's structural config (Dolphin PixelShaderGen stagehash shape).
// All fields are raw BP register subfields (BPMemory.h TevStageCombiner /
// TwoTevStageOrders / AllTevKSels); resolved swap tables and konst selectors
// are baked in so the WGSL generator is a pure function of this key. All u8 so
// the key has a unique object representation (memcmp identity).
struct TevStageKey {
  // Color combiner (ColorCombiner, BP 0xC0+2n): a/b/c/d are TevColorArg (0-15).
  std::uint8_t cc_a = 0, cc_b = 0, cc_c = 0, cc_d = 0;
  std::uint8_t cc_bias = 0;  // TevBias (3 == Compare)
  std::uint8_t cc_op = 0;    // TevOp when bias!=Compare, else TevComparison
  std::uint8_t cc_clamp = 0;
  std::uint8_t cc_scale = 0; // TevScale when bias!=Compare, else TevCompareMode
  std::uint8_t cc_dest = 0;  // TevOutput (0 prev..3 c2)
  // Alpha combiner (AlphaCombiner, BP 0xC0+2n+1): a/b/c/d are TevAlphaArg (0-7).
  std::uint8_t ac_a = 0, ac_b = 0, ac_c = 0, ac_d = 0;
  std::uint8_t ac_bias = 0;
  std::uint8_t ac_op = 0;
  std::uint8_t ac_clamp = 0;
  std::uint8_t ac_scale = 0;
  std::uint8_t ac_dest = 0;
  // Konst selectors resolved from AllTevKSels (KonstSel 0-31).
  std::uint8_t ksel_kc = 0;
  std::uint8_t ksel_ka = 0;
  // Resolved swap tables (ColorChannel 0-3 per r/g/b/a channel).
  std::uint8_t ras_swap[4]{};
  std::uint8_t tex_swap[4]{};
  // TwoTevStageOrders (BP 0x28+n/2).
  std::uint8_t tevorders_texcoord = 0;
  std::uint8_t tevorders_texmap = 0;
  std::uint8_t tevorders_colorchan = 0; // RasColorChan
  std::uint8_t tevorders_enable = 0;    // reads texture when set
  std::uint8_t pad0 = 0;
  std::uint8_t pad1 = 0;
};
static_assert(std::has_unique_object_representations_v<TevStageKey>);

struct TexGenKey {
  std::uint8_t enabled = 0;
  std::uint8_t texgentype = 0;         // TexGenType
  std::uint8_t sourcerow = 0;          // TexSourceRow raw (0..12)
  std::uint8_t inputform = 0;          // 0 AB11, 1 ABC1
  std::uint8_t projection = 0;         // 0 ST (2 rows), 1 STQ (3 rows)
  std::uint8_t embosssourceshift = 0;  // XF TexMtxInfo bits 12-14 (emboss src texgen)
  std::uint8_t embosslightshift = 0;   // XF TexMtxInfo bits 15-17 (emboss light index)
  std::uint8_t pad0 = 0;
};

// One XF lighting channel's structural config (Dolphin LightingUidData shape,
// per litchan index 0..3 = color0/color1/alpha0/alpha1). All resolved from the
// LitChannel bitfields (XFMemory.h): matsource@0, enablelighting@1,
// lightMask0_3@2, ambsource@6, diffusefunc@7, attnfunc@9, lightMask4_7@11. All
// u8 for a unique object representation. Ported by generate_wgsl into the
// integer lighting header (LightingShaderGen.cpp GenerateLightShader).
struct LightChanKey {
  std::uint8_t enablelighting = 0; // when 0 the channel is unlit passthrough
  std::uint8_t matsource = 0;      // MatSource
  std::uint8_t ambsource = 0;      // MatSource (register vs vertex ambient)
  std::uint8_t diffusefunc = 0;    // DiffuseFunc
  std::uint8_t attnfunc = 0;       // AttenuationFunc
  std::uint8_t light_mask = 0;     // 8 lights; 0 unless enablelighting
  std::uint8_t pad0 = 0;
  std::uint8_t pad1 = 0;
};
static_assert(std::has_unique_object_representations_v<LightChanKey>);

struct ShaderKey {
  std::uint8_t num_tex_gens = 0;    // XF numTexGens (0x103F), capped kMaxTexGens
  std::uint8_t has_pos_mtx_idx = 0; // per-vertex PNMTXIDX attr present
  std::uint8_t has_tex_mtx_idx = 0; // per-vertex TEXMTXIDX attr present (item 5)
  std::uint8_t has_color0 = 0;
  std::uint8_t has_color1 = 0;
  std::uint8_t uv_mask = 0;  // raw uv inputs present (bit per tex0..3)
  std::uint8_t textured = 0; // fragment samples texmap0 via texcoord0
  // TEV combiner (S14). tev_valid==0 keeps the S12/S13 passthrough fragment
  // (used when combiner regs were never seen, e.g. synthetic slices).
  std::uint8_t tev_valid = 0;
  std::uint8_t num_tev_stages = 0; // 1..kMaxTevStages when tev_valid
  // Alpha test (BP 0xF3 AlphaTest): comp0/comp1 CompareMode, logic AlphaTestOp.
  std::uint8_t alpha_comp0 = 7; // default Always
  std::uint8_t alpha_comp1 = 7;
  std::uint8_t alpha_logic = 0;
  // Lighting (S15). lit_valid==0 keeps the vertex-color passthrough (unlit UI,
  // e.g. start_menu). num_color_chans (XF 0x1009) gates channel output.
  std::uint8_t lit_valid = 0;
  std::uint8_t num_color_chans = 0;
  // Fog (S16, Dolphin PixelShaderGen WriteFog). fog_fsel==Off keeps the fragment
  // fog-free; when active it needs the pixel uniform, so fog only emits on the
  // TEV path (a fog-only, non-TEV draw is counted fog_ignored). These three
  // bytes replace the former pad0/1/2 — the scalar block stays 16 bytes so
  // PipelineConfig has no trailing alignment gap (still unique-object-rep).
  std::uint8_t fog_fsel = 0;  // FogType
  std::uint8_t fog_proj = 0;  // FogProjection
  std::uint8_t fog_range = 0; // fogRange.Base.Enabled
  // Per-texgen bit: texgen i draws its matrix rows from the per-vertex TEXMTXIDX
  // attribute (transformmatrices) instead of the static texmatrices slot. Only
  // meaningful when has_tex_mtx_idx; a subset of texgens may carry the attribute.
  std::uint8_t tex_mtx_idx_mask = 0;
  // Bit j (0..3 = color0/color1/alpha0/alpha1) set when that XF channel-control
  // reg was actually captured. Distinguishes a channel that genuinely selects
  // MatSource::Register (== 0) from one that was never configured (also 0): the
  // former outputs the material register, the latter passes the vertex color
  // through unchanged (Dolphin runs dolphin_calculate_lighting_chn for every
  // configured channel; an unconfigured channel has no material to apply).
  std::uint8_t chan_captured_mask = 0;
  // Vertex-format attribute presence (Dolphin VB_HAS_NORMAL/BINORMAL/TANGENT).
  // A LIT (or emboss) draw whose format lacks the attribute substitutes the
  // last-decoded vertex's value from the uniform (cached_normal/binormal/
  // tangent) instead of reading a per-vertex input — Dolphin's
  // VertexShaderGen I_CACHED_NORMAL fallback (VertexShaderGen.cpp:607-632),
  // sourced from VertexLoaderManager::normal_cache. Without this a lit
  // no-normal draw computes normalize(0) = NaN. GC packs N/B/T as one 9-part
  // attribute, so binormal==tangent presence tracks the NBT flag.
  std::uint8_t has_vertex_normal = 0;
  std::uint8_t has_vertex_binormal = 0;
  std::uint8_t has_vertex_tangent = 0;
  // Re-pad the scalar block to a multiple of 4, keeping ShaderKey a
  // unique-object-representation (memcmp identity) type.
  std::uint8_t pad2 = 0;
  std::uint8_t pad3 = 0;
  LightChanKey litchan[4]{}; // color0, color1, alpha0, alpha1
  TexGenKey tex_gens[kMaxTexGens]{};
  TevStageKey tev_stages[kMaxTevStages]{};
};
static_assert(std::has_unique_object_representations_v<ShaderKey>);
static_assert(sizeof(ShaderKey) % 4 == 0);

struct PipelineKey {
  ShaderKey shader{};
  std::uint8_t cull_mode = 0;  // CullMode (BP genMode bits 14-15)
  std::uint8_t depth_test = 0; // BP zmode bit 0
  std::uint8_t depth_func = 0; // CompareMode (zmode bits 1-3)
  std::uint8_t depth_update = 0; // zmode bit 4
  std::uint8_t blend_enable = 0; // cmode0 bit 0
  std::uint8_t blend_subtract = 0; // cmode0 bit 11
  std::uint8_t src_factor = 0;     // SrcBlendFactor (cmode0 bits 8-10)
  std::uint8_t dst_factor = 0;     // DstBlendFactor (cmode0 bits 5-7)
  std::uint8_t color_update = 0;   // cmode0 bit 3
  std::uint8_t alpha_update = 0;   // cmode0 bit 4
  std::uint8_t pad0 = 0;
  std::uint8_t pad1 = 0;
};
static_assert(std::has_unique_object_representations_v<PipelineKey>);

// --- Uniform block (Dolphin VertexShaderConstants shape, slice subset) ------

// Rows are vec4; matrices are row-major 3x4 like XF memory. transformmatrices
// mirrors XF matrix-memory rows 0..62 (position rows 0-29, texture rows
// 30-62) for per-vertex matrix indexing, exactly Dolphin's I_TRANSFORMMATRICES.
// One XF light object, laid out AoS to match the WGSL `Light` struct exactly
// (color int4, then cosatt/distatt/pos/dir float4) so the fork can bind the
// uniform buffer without repacking. color is Dolphin's I_LIGHTS integer RGBA
// (0..255); the attenuation/position/direction words are the raw XF f32 values.
struct GpuLight {
  std::int32_t color[4]{};
  float cosatt[4]{};
  float distatt[4]{};
  float pos[4]{};
  float dir[4]{};
};
static_assert(sizeof(GpuLight) == 5 * 16);

struct VertexShaderConstants {
  float posnormalmatrix[6][4]{};    // rows 0-2 current pos mtx, 3-5 normal
  float projection[4][4]{};         // row-dot form (VertexShaderGen o.pos)
  float texmatrices[24][4]{};       // per texgen: 3 rows resolved via matidx
  float transformmatrices[64][4]{}; // raw XF matrix memory rows
  // Lighting (S15): the 8 XF lights and the four material/ambient registers
  // (Dolphin I_MATERIALS: [0]=ambient0, [1]=ambient1, [2]=material0,
  // [3]=material1, integer RGBA 0..255). Only read on the lit path.
  GpuLight lights[8]{};
  std::int32_t materials[4][4]{};
  // Cached vertex attributes (Dolphin ConstantManager cached_normal/tangent/
  // binormal): the last-decoded vertex's RAW object-space N/B/T, substituted
  // for the per-vertex input on a draw whose format omits that attribute. The
  // shader applies the same normal matrix it would to a real input. .w unused.
  float cached_normal[4]{0.f, 0.f, 0.f, 0.f};
  float cached_tangent[4]{0.f, 0.f, 0.f, 0.f};
  float cached_binormal[4]{0.f, 0.f, 0.f, 0.f};
};
static_assert(sizeof(VertexShaderConstants) ==
              (6 + 4 + 24 + 64) * 16 + 8 * (5 * 16) + 4 * 16 + 3 * 16);

// Pixel-shader uniforms (Dolphin PixelShaderConstants subset): the four TEV
// color registers (I_COLORS: [0] prev seed, [1..3] c0/c1/c2), the four konst
// registers (I_KCOLORS), and the alpha-test refs (I_ALPHA). Integer 0..255 for
// konst; tev color regs are s11 (-1024..1023). vec4-aligned (std140) so the
// fork can bind it as a WGSL uniform without repacking.
// Fog uniforms mirror Dolphin PixelShaderConstants (ConstantManager.h): fogcolor
// integer rgb, fogi (.y=b_magnitude, .w=b_shift), fogf (.x=A, .y=C,
// .z=range-adjust screen center, .w=range-adjust screen width), and the
// precomputed fogrange K table (std::array<float4,3>). Populated only when
// fog_fsel != Off; std140-aligned (all vec4) so the fork binds without repack.
struct PixelShaderConstants {
  std::int32_t colors[4][4]{};  // rgba per register
  std::int32_t kcolors[4][4]{}; // rgba per konst register
  std::int32_t alpha_ref[4]{};  // ref0, ref1, unused, unused
  std::int32_t fogcolor[4]{};   // r,g,b in .xyz (0..255)
  std::int32_t fogi[4]{};       // .y = b_magnitude, .w = b_shift
  float fogf[4]{};              // .x=A .y=C .z=center .w=width
  float fogrange[3][4]{};       // Dolphin I_FOGRANGE K table (indices 0..9)
};
static_assert(sizeof(PixelShaderConstants) == (4 + 4 + 1 + 1 + 1 + 1 + 3) * 16);

// --- Fixed decoded-vertex layout (slice) ------------------------------------
//
// The CPU vertex decoder (Dolphin VertexLoader semantics) normalizes every
// draw to this one interleaved layout so the pipeline vertex state is
// constant: pos vec3f | posmtx u32 (matrix ROW index) | color0 vec4f |
// color1 vec4f | uv0..3 vec2f | normal vec3f | texmtxidx u32 | binormal vec3f |
// tangent vec3f. Each block is appended at the end so every earlier offset is
// unchanged and shaders that omit the trailing @locations stay byte-identical:
// normal (S15, @location 8), then the item-5 texgen block — per-vertex tex-matrix
// indices packed one byte per texgen (@location 9), and the NBT binormal/tangent
// emboss needs in view space (@location 10/11).
inline constexpr std::uint32_t kVertexFloats =
    3 + 1 + 4 + 4 + 2 * kMaxTexGens + 3 + 1 + 3 + 3;
inline constexpr std::uint32_t kVertexStrideBytes = kVertexFloats * 4;
inline constexpr std::uint32_t kVertexPosOffset = 0;
inline constexpr std::uint32_t kVertexPosMtxOffset = 12;
inline constexpr std::uint32_t kVertexColor0Offset = 16;
inline constexpr std::uint32_t kVertexColor1Offset = 32;
inline constexpr std::uint32_t kVertexUvOffset = 48; // + 8*i
inline constexpr std::uint32_t kVertexNormalOffset = 48 + 8 * kMaxTexGens;
inline constexpr std::uint32_t kVertexTexMtxIdxOffset = kVertexNormalOffset + 12;
inline constexpr std::uint32_t kVertexBinormalOffset = kVertexTexMtxIdxOffset + 4;
inline constexpr std::uint32_t kVertexTangentOffset = kVertexBinormalOffset + 12;

// --- Draw plan ---------------------------------------------------------------

// Everything a GPU submission layer needs for one draw, with no frontend or
// GPU types: decoded vertices in the fixed layout, triangle-list indices,
// Multi-texmap helpers (63/Mfin), shared by the WGSL generator, the plan builder,
// and the substrate binding so all three agree on which texmaps a draw samples.
inline std::uint32_t texmap_popcount(std::uint32_t v) {
  std::uint32_t n = 0;
  for (; v != 0u; v &= v - 1u)
    ++n;
  return n;
}

// Bit t set => an enabled TEV stage samples texmap t. Non-TEV textured draws use
// texmap 0. A result with <=1 bit is the single-texmap fast path.
inline std::uint32_t used_texmap_mask(const ShaderKey& key) {
  if (key.textured == 0u)
    return 0u;
  if (key.tev_valid == 0u)
    return 1u; // passthrough textured fragment samples tex0
  std::uint32_t mask = 0u;
  for (std::uint32_t n = 0; n < key.num_tev_stages; ++n) {
    const TevStageKey& s = key.tev_stages[n];
    if (s.tevorders_enable != 0u)
      mask |= (1u << (s.tevorders_texmap & 7u));
  }
  return mask != 0u ? mask : 1u;
}

// One bound texture for a specific TEV texmap slot (63/Mfin multi-texmap). The
// single-texmap fast path uses DrawPlan's flat tex_*/tlut_* fields; when more
// than one distinct texmap is sampled (e.g. a THP YUV movie draws Y/U/V on
// texmap 0/1/2 and a TEV combines them to RGB) the per-texmap set is carried in
// DrawPlan::textures and texmap_mask marks which slots are live.
struct PlanTexture {
  bool valid = false;
  std::uint32_t address = 0;
  std::uint32_t size = 0;
  std::uint32_t format = 0;
  std::uint32_t width = 0;
  std::uint32_t height = 0;
  const void* data = nullptr;
  std::uint32_t available = 0;
  bool has_tlut = false;
  std::uint32_t tlut_address = 0;
  std::uint32_t tlut_format = 0;
  std::uint32_t tlut_entries = 0;
  const void* tlut_data = nullptr;
  std::uint32_t tlut_available = 0;
};

// packed uniforms, the pipeline key, and the bound texture's guest identity +
// host bytes (converted by the substrate's GX codecs at upload).
struct DrawPlan {
  bool ok = false;
  const char* skip_reason = nullptr; // set when ok==false
  PipelineKey pipeline{};
  VertexShaderConstants constants{};
  PixelShaderConstants pixel_constants{}; // S14 TEV color/konst/alpha uniforms
  std::vector<float> vertices; // kVertexFloats per vertex
  std::vector<std::uint16_t> indices;
  std::uint32_t vertex_count = 0;
  // Viewport, raw XF values (wd/2, -ht/2, zmax*2^24, xorig+342, yorig+342,
  // farz*2^24) — the submission layer maps these through the substrate's
  // logical-viewport scaling.
  bool viewport_valid = false;
  float viewport[6]{};
  bool has_texture = false;
  std::uint32_t tex_address = 0;
  std::uint32_t tex_size = 0;
  std::uint32_t tex_format = 0;
  std::uint32_t tex_width = 0;
  std::uint32_t tex_height = 0;
  const void* tex_data = nullptr; // resolver-owned host bytes; upload-time use
  std::uint32_t tex_available = 0;
  // CI-format textures: the resolved TLUT palette. has_tlut false means either a
  // non-CI texture or an unresolved palette (A3 decode falls back). tlut_format
  // = IA8=0/RGB565=1/RGB5A3=2. tlut_data is resolver-owned.
  bool has_tlut = false;
  std::uint32_t tlut_address = 0; // palette guest address (cache identity)
  std::uint32_t tlut_format = 0;
  std::uint32_t tlut_entries = 0;
  const void* tlut_data = nullptr;
  std::uint32_t tlut_available = 0;
  // Multi-texmap (63/Mfin): bit t of texmap_mask set => textures[t] is sampled
  // by an enabled TEV stage. 0 or a single bit keeps the single-texmap fast path
  // (the flat tex_* fields above); >1 bit makes the per-texmap set authoritative.
  std::uint32_t texmap_mask = 0;
  PlanTexture textures[8]{};
};

// --- EFB copy-to-texture (S16) ------------------------------------------------

// One EFB copy-to-texture request, reconstructed from a BP 0x52 trigger + its
// resolved CopyDestination. A GPU submission layer resolves the current EFB
// region [src_x,src_y]+[width,height] into a texture keyed by dest_address
// (Dolphin GXCopyTex / aurora copy_tex shape). format is the GX copy texture
// format. Std-only (no GPU types): the fork's copy observer turns this into a
// gfx::resolve_pass; lives here (not gxcore.hpp) so the fork header stays free
// of the render_sink dependency.
struct EfbCopyCommand {
  std::uint32_t dest_address = 0;
  std::uint32_t byte_size = 0;
  // TRUE GXTexFmt (incl. Z bit 0x10 for depth-source copies and CTF bit 0x20
  // for channel-select formats); 0xF = display copy (GXCopyDisp, no texture
  // destination — only the copy-clear applies, as the next frame's EFB clear).
  std::uint32_t format = 0;
  std::uint32_t src_x = 0;
  std::uint32_t src_y = 0;
  std::uint32_t width = 0;
  std::uint32_t height = 0;
  bool clear = false;
  // EFB clear color/Z applied after the copy (BP 0x4F/0x50/0x51, read from the
  // sink's live state). rgba 0..255; z is the raw 24-bit copy-clear depth.
  std::uint32_t clear_r = 0, clear_g = 0, clear_b = 0, clear_a = 0;
  std::uint32_t clear_z = 0;
  // Write masks live at the copy (cmode0 bits 3/4, zmode bit 4): a requested
  // clear only touches the enabled planes (Dolphin BPStructs ClearScreen;
  // Strikers glx_ClearZBuffer clears with color/alpha update OFF).
  bool color_update = true;
  bool alpha_update = true;
  bool depth_update = true;
};

// --- WGSL generation ----------------------------------------------------------

// Generate the complete WGSL module (vs_main + fs_main) for a shader key.
// Deterministic: equal keys yield byte-identical source (the headless golden
// test pins this). Shape follows Dolphin VertexShaderGen/PixelShaderGen with
// the fork substrate's conventions: GC clip z in [-w,0] is flipped to
// reversed-Z (graphics/aurora lib/gx/gx.hpp UseReversedZ); bind groups are
// group(1)=dynamic uniform, group(2)=texture+sampler.
std::string generate_wgsl(const ShaderKey& key);
bool channel_lit_path(const ShaderKey& k, unsigned j);

} // namespace gxruntime::gxcore

