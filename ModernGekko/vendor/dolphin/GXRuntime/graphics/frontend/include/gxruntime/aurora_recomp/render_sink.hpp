// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include <cstdint>
#include <vector>

extern "C" {
#include "gxruntime/gx_recomp.h"
}

namespace gxruntime::aurora_recomp {

enum class RenderPacketKind : std::uint32_t {
  TraceEvent = 1,
  Stream = 2,
  State = 3,
  Resource = 4,
  Draw = 5,
};

enum class RenderStreamKind : std::uint32_t {
  FifoBytes = 1,
  DisplayList = 2,
};

enum class RenderStateKind : std::uint32_t {
  CpArrayBase = 1,
  CpArrayStride = 2,
  CpVcd = 3,
  CpVat = 4,
  VertexLayout = 5,
  BpReg = 6,
  XfLoad = 7,
  IndexedXfLoad = 8,
  CullAll = 9,
  InvalidateVtxCache = 10,
};

enum class RenderResourceKind : std::uint32_t {
  IndexedArraySpan = 1,
  Texture = 2,
  Tlut = 3,
  CopyDestination = 4,
};

constexpr std::uint32_t kDrawTransformViewportValid = 1u << 0u;
constexpr std::uint32_t kDrawTransformProjectionValid = 1u << 1u;
constexpr std::uint32_t kDrawTransformPayloadPnMatrixValid = 1u << 2u;

struct RenderStreamPacket {
  RenderStreamKind kind = RenderStreamKind::FifoBytes;
  std::uint32_t address = 0;
  std::uint32_t size = 0;
  std::uint32_t address_space = 0;
  std::uint32_t total_size = 0;
};

struct RenderStatePacket {
  RenderStateKind kind = RenderStateKind::CpArrayBase;
  std::uint32_t index = 0;
  std::uint32_t value = 0;
  std::uint32_t aux0 = 0;
  std::uint32_t aux1 = 0;
};

struct RenderResourcePacket {
  RenderResourceKind kind = RenderResourceKind::IndexedArraySpan;
  std::uint32_t index = 0;
  std::uint32_t address = 0;
  std::uint32_t size = 0;
  std::uint32_t format = 0;
  std::uint32_t count = 0;
  std::uint32_t vtx_fmt = 0;
  // IndexedArraySpan decode params (zero for other resources): where each
  // vertex's index sits in the per-vertex stride, the index byte width (1/2),
  // and the element byte size fetched from the resolved array.
  std::uint32_t vertex_offset = 0;
  std::uint32_t index_size = 0;
  std::uint32_t element_size = 0;
  // Texture packets only: decoded image dimensions (texels).
  std::uint32_t width = 0;
  std::uint32_t height = 0;
  // CI-format Texture packets only: the TLUT this texture indexes. tlut_address
  // = palette guest address (0 for non-CI or unresolved), tlut_format = TLUT
  // pixel format (IA8=0/RGB565=1/RGB5A3=2), tlut_entries = palette entry count.
  // Consumed by the Texture resource case → ConsumedTexture.
  std::uint32_t tlut_address = 0;
  std::uint32_t tlut_format = 0;
  std::uint32_t tlut_entries = 0;
  // CopyDestination packets only: the EFB source rect origin
  // and whether the EFB is cleared after the copy. width/height carry the copy
  // dimensions and format carries the GX copy texture format (incl. Z target).
  // Consumed by the gxcore EFB-copy path; in-memory only (never in .dolt).
  std::uint32_t copy_src_x = 0;
  std::uint32_t copy_src_y = 0;
  std::uint32_t copy_clear = 0;
};

struct RenderDrawPacket {
  std::uint32_t primitive = 0;
  std::uint32_t vtx_fmt = 0;
  std::uint32_t vertex_count = 0;
  std::uint32_t vertex_size = 0;
  // Raw per-vertex FIFO payload for this draw: the inline direct-attr values and
  // the per-vertex index bytes that select CP-array elements. This is the data
  // an issuing sink needs to assemble actual vertices (resolved arrays alone are
  // not enough). The bytes live in a frontend-owned buffer that is valid only
  // for the duration of submit_packet(); a retaining sink must copy them. Stays
  // null in pure-state replays that don't carry the draw bytes.
  const std::uint8_t* vertex_payload = nullptr;
  std::uint32_t vertex_payload_size = 0;
  // Transform state snapshotted at draw time. Projection/viewport validity is
  // in transform_flags; position_matrix_valid_mask has one bit per PN matrix.
  // current_pn_matrix is the Aurora uniform fallback when PNMTXIDX is absent;
  // direct PNMTXIDX payload bytes can select any valid position_matrices slot.
  std::uint32_t transform_flags = 0;
  std::uint32_t current_pn_matrix = 0;
  std::uint32_t payload_pn_matrix_mask = 0;
  std::uint32_t position_matrix_valid_mask = 0;
  float viewport[6]{};
  float projection[6]{};
  std::uint32_t projection_type = 0;
  float position_matrices[DOL_GX_RECOMP_POSITION_MATRIX_COUNT]
                         [DOL_GX_RECOMP_POSITION_MATRIX_WORDS]{};
  float normal_matrices[DOL_GX_RECOMP_NORMAL_MATRIX_COUNT]
                       [DOL_GX_RECOMP_NORMAL_MATRIX_WORDS]{};
  std::uint16_t normal_matrix_word_mask[DOL_GX_RECOMP_NORMAL_MATRIX_COUNT]{};
  // XF lighting state snapshotted at draw time (raw words; per-word validity
  // in the masks — layout documented in gx_recomp.h).
  std::uint32_t light_words[DOL_GX_RECOMP_LIGHT_COUNT]
                           [DOL_GX_RECOMP_LIGHT_WORDS]{};
  std::uint16_t light_word_mask[DOL_GX_RECOMP_LIGHT_COUNT]{};
  std::uint32_t chan_regs[DOL_GX_RECOMP_CHAN_REG_COUNT]{};
  std::uint32_t chan_reg_mask = 0;
  // Texture matrices + raw XF register window (0x1018..0x1057) snapshotted at
  // draw time.
  float tex_matrices[DOL_GX_RECOMP_TEX_MATRIX_COUNT]
                    [DOL_GX_RECOMP_TEX_MATRIX_WORDS]{};
  std::uint16_t tex_matrix_word_mask[DOL_GX_RECOMP_TEX_MATRIX_COUNT]{};
  std::uint32_t xf_regs[DOL_GX_RECOMP_XF_REG_COUNT]{};
  std::uint64_t xf_reg_mask = 0;
};

struct RenderPacket {
  RenderPacketKind kind = RenderPacketKind::TraceEvent;
  std::uint32_t sequence = 0;
  DolGxRecompTraceEvent event{};
  RenderStreamPacket stream{};
  RenderStatePacket state{};
  RenderResourcePacket resource{};
  RenderDrawPacket draw{};
};

class AuroraRenderSink {
public:
  virtual ~AuroraRenderSink() = default;

  virtual bool submit_packet(const RenderPacket& packet) = 0;
};

class RecordingAuroraRenderSink final : public AuroraRenderSink {
public:
  bool submit_packet(const RenderPacket& packet) override;

  const std::vector<RenderPacket>& packets() const { return packets_; }
  void clear() { packets_.clear(); }

private:
  std::vector<RenderPacket> packets_;
};

// Renderer-facing model reconstructed from the normalized packet stream.
// A live Aurora sink translates each ConsumedDraw (with its snapshotted state)
// into aurora::gfx draw calls; materializing it as data first lets a headless
// fixture and the backend shadow path validate the consumer before cutover.
struct ConsumedArrayBinding {
  bool base_valid = false;
  bool stride_valid = false;
  std::uint32_t base = 0;
  std::uint32_t stride = 0;
};

struct ConsumedTexture {
  bool valid = false;
  std::uint32_t slot = 0;
  std::uint32_t address = 0;
  std::uint32_t size = 0;
  std::uint32_t format = 0;
  std::uint32_t width = 0;
  std::uint32_t height = 0;
  // Resolved host bytes the renderer reads. Packets stay host-agnostic (guest
  // address only); the sink resolves through the guest resolver when one is
  // installed. host_data stays null in pure validation mode.
  bool resolved = false;
  const void* host_data = nullptr;
  std::uint32_t host_available = 0;
  // CI-format textures: the TLUT palette this texture indexes, resolved to host
  // bytes alongside the image. tlut_format = IA8=0/RGB565=1/RGB5A3=2. Stays
  // has_tlut=false for non-CI textures and CI textures whose TLUT did not
  // resolve (A3 decode falls back). tlut_host_data is resolver-owned.
  bool has_tlut = false;
  std::uint32_t tlut_address = 0; // palette guest address (cache identity)
  std::uint32_t tlut_format = 0;
  std::uint32_t tlut_entries = 0;
  const void* tlut_host_data = nullptr;
  std::uint32_t tlut_host_available = 0;
};

// One vertex array a draw reads, resolved to host bytes. For indexed draws the
// span size comes from the frontend's IndexedArraySpan resource packet; for
// direct draws it is stride * vertex_count.
struct ConsumedArrayInput {
  std::uint32_t attr = 0;
  std::uint32_t base = 0;
  std::uint32_t stride = 0;
  std::uint32_t span_size = 0;
  bool indexed = false;
  bool resolved = false;
  const void* host_data = nullptr;
  std::uint32_t host_available = 0;
  // Decode params (from the IndexedArraySpan packet) needed to read each
  // vertex's index out of the draw payload and fetch its element bytes:
  // vertex_offset = index position within the per-vertex stride,
  // index_size = index byte width (1/2), element_size = bytes fetched at
  // base + index*stride.
  std::uint32_t vertex_offset = 0;
  std::uint32_t index_size = 0;
  std::uint32_t element_size = 0;
};

struct ConsumedDraw {
  static constexpr std::uint32_t kMaxArrays = 16u;

  std::uint32_t sequence = 0;
  std::uint32_t primitive = 0;
  std::uint32_t vtx_fmt = 0;
  std::uint32_t vertex_count = 0;
  std::uint32_t vertex_size = 0;
  bool cull_all = false;
  std::uint32_t active_array_mask = 0; // bit per attr with base+stride bound
  ConsumedTexture texture{};           // most recently bound texture at draw
  // Per-texmap bound textures (63/Mfin multi-texmap): textures[t] is the texture
  // in TEV texmap slot t at draw time. Single-texmap draws use `texture`; a
  // draw that samples >1 texmap (THP YUV Y/U/V) reads the slot set here.
  static constexpr std::uint32_t kMaxTexmaps = 8u;
  ConsumedTexture textures[kMaxTexmaps]{};
  std::uint32_t array_input_count = 0;
  ConsumedArrayInput arrays[kMaxArrays]{};
  // Copy of the draw's raw per-vertex FIFO payload (inline direct attrs +
  // per-vertex indices), retained from the Draw packet so an issuing sink can
  // assemble vertices after submit. Empty when the packet carried no payload.
  std::vector<std::uint8_t> vertex_payload;
  std::uint32_t transform_flags = 0;
  std::uint32_t current_pn_matrix = 0;
  std::uint32_t payload_pn_matrix_mask = 0;
  std::uint32_t position_matrix_valid_mask = 0;
  float viewport[6]{};
  float projection[6]{};
  std::uint32_t projection_type = 0;
  float position_matrices[DOL_GX_RECOMP_POSITION_MATRIX_COUNT]
                         [DOL_GX_RECOMP_POSITION_MATRIX_WORDS]{};
  float normal_matrices[DOL_GX_RECOMP_NORMAL_MATRIX_COUNT]
                       [DOL_GX_RECOMP_NORMAL_MATRIX_WORDS]{};
  std::uint16_t normal_matrix_word_mask[DOL_GX_RECOMP_NORMAL_MATRIX_COUNT]{};
  std::uint32_t light_words[DOL_GX_RECOMP_LIGHT_COUNT]
                           [DOL_GX_RECOMP_LIGHT_WORDS]{};
  std::uint16_t light_word_mask[DOL_GX_RECOMP_LIGHT_COUNT]{};
  std::uint32_t chan_regs[DOL_GX_RECOMP_CHAN_REG_COUNT]{};
  std::uint32_t chan_reg_mask = 0;
  float tex_matrices[DOL_GX_RECOMP_TEX_MATRIX_COUNT]
                    [DOL_GX_RECOMP_TEX_MATRIX_WORDS]{};
  std::uint16_t tex_matrix_word_mask[DOL_GX_RECOMP_TEX_MATRIX_COUNT]{};
  std::uint32_t xf_regs[DOL_GX_RECOMP_XF_REG_COUNT]{};
  std::uint64_t xf_reg_mask = 0;
};

using ConsumedDrawObserver = void (*)(const ConsumedDraw& draw,
                                      unsigned long long cumulative_draw,
                                      void* user);

// AuroraRenderSink that accumulates state/resource packets and snapshots a
// concrete draw model on every Draw packet. Also enforces the same shape
// invariants the backend shadow validator required (monotonic sequence,
// non-empty stream/resource/draw payloads), so it can replace the ad-hoc
// validating sink rather than run beside it.
class ConsumingAuroraRenderSink final : public AuroraRenderSink {
public:
  bool submit_packet(const RenderPacket& packet) override;

  void reset();

  // Install the guest resolver used to turn packet guest addresses into host
  // bytes. Pass nullptr for pure validation (no resolution).
  void set_guest_resolver(const DolGuestAddressResolver* resolver) {
    resolver_ = resolver;
  }

  // Streaming mode (backend shadow path): keep only the most recent draw so
  // `draws_` cannot grow without bound across a long run. Counters still
  // accumulate. The immediately-following INDEXED_SPAN packets still patch the
  // retained draw. Tests leave this off to inspect the full draw list.
  void set_streaming(bool streaming) { streaming_ = streaming; }
  // Optional observer called exactly once when a draw becomes span-complete:
  // either when the next draw arrives or when flush_assembly() is called at a
  // frame boundary. This lets a live backend export focused diagnostics without
  // retaining every draw in non-streaming mode.
  void set_draw_observer(ConsumedDrawObserver observer, void* user) {
    draw_observer_ = observer;
    draw_observer_user_ = user;
  }

  const std::vector<ConsumedDraw>& draws() const { return draws_; }
  unsigned long long packets() const { return packets_; }
  unsigned long long stream_packets() const { return stream_packets_; }
  unsigned long long state_packets() const { return state_packets_; }
  unsigned long long resource_packets() const { return resource_packets_; }
  // Cumulative count of DRAW packets seen. Must NOT be draws_.size(): streaming
  // mode keeps only the latest draw, so the vector size is ≤1.
  unsigned long long draw_packets() const { return total_draws_; }
  // Cumulative sum of vertex_count across all DRAW packets. Paired with
  // draw_packets() this lets the backend compute a per-frame draw/vertex delta
  // and diff it against Aurora's per-frame drawCallCount (the live push_gx_draw
  // count), validating that the consumer decodes the same draw stream Aurora
  // renders before any renderer cutover.
  unsigned long long vertex_inputs() const { return total_vertices_; }
  // Cumulative raw per-vertex payload bytes retained across all draws. Lets the
  // issuing path confirm every draw carried its assemble-able vertex bytes.
  unsigned long long payload_bytes() const { return payload_bytes_; }
  unsigned long long texture_count() const { return texture_count_; }
  unsigned long long tlut_count() const { return tlut_count_; }
  unsigned long long copy_count() const { return copy_count_; }
  unsigned long long indexed_span_count() const { return indexed_span_count_; }
  // Diagnostics for the resolved-draw bridge: how many array inputs across all
  // draws resolved to host bytes vs. failed to resolve. Used by the backend
  // shadow path to report whether every real draw's inputs map to host memory.
  unsigned long long resolved_array_inputs() const {
    return resolved_array_inputs_;
  }
  unsigned long long unresolved_array_inputs() const {
    return unresolved_array_inputs_;
  }

  // Assemble the most-recent (span-complete) draw if it has not been assembled
  // yet. Call at a frame boundary so the final draw of the frame is counted —
  // intermediate draws are assembled automatically when the next draw arrives.
  void flush_assembly();
  // Cumulative assembly results across the run (driven by the shadow path):
  // draws assembled, per-vertex indexed elements resolved to host bytes, and
  // draws whose assembly failed (an index/element fell outside resolved memory).
  unsigned long long assembled_draws() const { return assembled_draws_; }
  unsigned long long assembled_elements() const { return assembled_elements_; }
  unsigned long long assemble_failed_draws() const {
    return assemble_failed_draws_;
  }
  // Cumulative assembled geometry byte extents (index bytes read from payloads,
  // element bytes gathered from resolved arrays) for the Aurora-extent gate.
  unsigned long long assembled_index_bytes() const {
    return assembled_index_bytes_;
  }
  unsigned long long assembled_element_bytes() const {
    return assembled_element_bytes_;
  }
  // Cumulative DRAW-INPUT byte extents an issued draw would actually submit to
  // Aurora, computed from each consumed draw via the cutover input-builders:
  //   raw_vertex_bytes  = Σ vertex_payload_size            -> gfx::push_verts
  //   topology_index_bytes = Σ build_topology_indices()*2  -> gfx::push_indices
  //   storage_bytes     = Σ build_array_sizes()            -> gfx::push_storage
  // These are diffed against Aurora's native per-frame frame.verts/indices/
  // storage sizes (lastVertSize/lastIndexSize/lastStorageSize) as the final
  // parity gate before issuing real draws. raw_vertex_bytes is merge-invariant
  // (alignment only); topology/storage carry Aurora merge/cache caveats (see
  // aurora-runtime.md) so they are logged, not hard-gated.
  unsigned long long raw_vertex_bytes() const { return payload_bytes_; }
  unsigned long long topology_index_bytes() const {
    return topology_index_bytes_;
  }
  unsigned long long storage_bytes() const { return storage_bytes_; }

  const ConsumedArrayBinding& array(std::uint32_t index) const;
  const ConsumedTexture& bound_texture() const { return bound_texture_; }
  bool cull_all() const { return cull_all_; }

  const char* failure_reason() const { return failure_reason_; }
  const RenderPacket& failed_packet() const { return failed_packet_; }

private:
  bool fail(const char* reason, const RenderPacket& packet);

  static constexpr std::uint32_t kArrayCount = 16u;

  bool resolve_array_input(ConsumedArrayInput& input);
  void tally_array_input(bool resolved);
  void untally_array_input(bool resolved);
  // Assemble `draw` (if its trailing spans are in) and fold the result into the
  // cumulative counters, guarded by back_assembled_ so a draw is counted once.
  void accumulate_assembly(const ConsumedDraw& draw);

  const DolGuestAddressResolver* resolver_ = nullptr;
  bool streaming_ = false;
  ConsumedDrawObserver draw_observer_ = nullptr;
  void* draw_observer_user_ = nullptr;
  ConsumedArrayBinding arrays_[kArrayCount]{};
  ConsumedTexture bound_texture_{};
  ConsumedTexture bound_textures_[ConsumedDraw::kMaxTexmaps]{}; // per-texmap slot
  bool cull_all_ = false;

  std::vector<ConsumedDraw> draws_;
  unsigned long long total_draws_ = 0;
  unsigned long long total_vertices_ = 0;
  unsigned long long payload_bytes_ = 0;
  unsigned long long packets_ = 0;
  unsigned long long stream_packets_ = 0;
  unsigned long long state_packets_ = 0;
  unsigned long long resource_packets_ = 0;
  unsigned long long texture_count_ = 0;
  unsigned long long tlut_count_ = 0;
  unsigned long long copy_count_ = 0;
  unsigned long long indexed_span_count_ = 0;
  unsigned long long resolved_array_inputs_ = 0;
  unsigned long long unresolved_array_inputs_ = 0;
  unsigned long long assembled_draws_ = 0;
  unsigned long long assembled_elements_ = 0;
  unsigned long long assemble_failed_draws_ = 0;
  unsigned long long assembled_index_bytes_ = 0;
  unsigned long long assembled_element_bytes_ = 0;
  unsigned long long topology_index_bytes_ = 0;
  unsigned long long storage_bytes_ = 0;
  bool back_assembled_ = false;
  std::uint32_t last_sequence_ = 0;
  bool has_last_sequence_ = false;
  const char* failure_reason_ = nullptr;
  RenderPacket failed_packet_{};
};

// One resolved indexed-attribute element for one vertex: the decoded index and
// a host pointer to its element_size bytes in the resolved CP array. This is the
// per-vertex data Aurora's push_gx_draw gathers for indexed attrs.
struct AssembledElement {
  std::uint32_t attr = 0;
  std::uint32_t vertex = 0;
  std::uint32_t index = 0;
  const std::uint8_t* host_element = nullptr;
  std::uint32_t element_size = 0;
};

struct AssembledDrawStats {
  bool ok = true;
  std::uint32_t vertex_count = 0;
  std::uint32_t indexed_attr_count = 0;
  std::uint32_t element_reads = 0; // (vertex × indexed-attr) elements resolved
  std::uint32_t failed_reads = 0;
  // Geometry byte extents this draw assembles: total index bytes read from the
  // payload and total element bytes gathered from resolved arrays. These let the
  // backend compare assembled extents against Aurora's lastIndexSize/lastVertSize
  // as the next cutover gate.
  std::uint32_t index_bytes = 0;
  std::uint32_t element_bytes = 0;
  std::uint32_t failure_attr = 0;
  const char* failure_reason = nullptr;
};

// Assemble a ConsumedDraw into per-vertex resolved indexed-attribute elements:
// for each indexed array input, read each vertex's index out of the retained raw
// payload (big-endian, at vertex_offset within the per-vertex stride) and resolve
// element_size bytes at host_data + index*stride. Direct (inline) attrs already
// live in the payload and need no resolution. `out` (optional) receives every
// resolved element; the stats summarize success/failure. This is the issuing
// sink's core — what a live Aurora draw would consume — validated against a
// fixture before exclusive renderer cutover.
AssembledDrawStats assemble_consumed_draw(const ConsumedDraw& draw,
                                          std::vector<AssembledElement>* out);

// GameCube primitive opcodes (the draw command's top 5 bits, as stored in
// ConsumedDraw.primitive = command & 0xF8).
enum class GxPrimitive : std::uint32_t {
  Quads = 0x80,
  Triangles = 0x90,
  TriangleStrip = 0x98,
  TriangleFan = 0xA0,
  Lines = 0xA8,
  LineStrip = 0xB0,
  Points = 0xB8,
};

// Build the triangle-list topology index buffer for `primitive` over
// [vtx_start, vtx_start+vtx_count), mirroring Aurora's prepare_idx_buffer
// (command_processor.cpp:27). Aurora issues every primitive as an indexed
// triangle list; this is the idxRange a cutover draw must supply. Appends u16
// indices to `out` and returns the number appended. Returns 0 for line/point
// primitives (Aurora handles those separately) and unknown opcodes.
std::uint32_t build_topology_indices(GxPrimitive primitive,
                                     std::uint16_t vtx_start,
                                     std::uint16_t vtx_count,
                                     std::vector<std::uint16_t>* out);

// Fill per-attr `arraySizes` (the storage-buffer byte size Aurora uploads for
// each indexed attribute) for a draw. Aurora derives this as
// max((index+1)*stride) across the draw's vertices (calculate_indexed_array_sizes
// command_processor.cpp:1756) — which is exactly the indexed span the frontend
// already resolved into ConsumedArrayInput.span_size. So this is a direct map,
// not a re-walk. `out` is indexed by CP attr (0..count-1); slots are zeroed then
// set from the draw's indexed inputs. Returns the number of non-zero entries.
std::uint32_t build_array_sizes(const ConsumedDraw& draw, std::uint32_t* out,
                                std::size_t count);

RenderPacket make_render_packet(std::uint32_t sequence,
                                const DolGxRecompTraceEvent& event);
const char* trace_event_name(DolGxRecompEventKind kind);

} // namespace gxruntime::aurora_recomp
