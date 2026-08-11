// SPDX-License-Identifier: GPL-3.0-or-later
#include "gx_test_common.hpp"

#include "gx/recomp.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

namespace aurora::gfx {
extern size_t g_testLastStoragePushSize;
extern uint32_t g_testDrawCount;
} // namespace aurora::gfx

namespace {

constexpr uint32_t DisplayListAddress = 0x200;
constexpr uint32_t PositionArrayAddress = 0x400;
constexpr uint32_t XfArrayAddress = 0x600;
constexpr uint32_t TextureAddress = 0x800;
constexpr uint32_t TlutAddress = 0x1000;
constexpr uint32_t CopyAddress = 0x1200;

struct ResolveRequest {
  uint32_t address;
  uint32_t size;
  aurora::gx::recomp::AddressSpace space;
  aurora::gx::recomp::ResourceKind resource;
};

void push_u8(std::vector<u8>& bytes, u8 value) {
  bytes.push_back(value);
}

void push_u16(std::vector<u8>& bytes, u16 value) {
  bytes.push_back(static_cast<u8>(value >> 8));
  bytes.push_back(static_cast<u8>(value));
}

void push_u32(std::vector<u8>& bytes, u32 value) {
  bytes.push_back(static_cast<u8>(value >> 24));
  bytes.push_back(static_cast<u8>(value >> 16));
  bytes.push_back(static_cast<u8>(value >> 8));
  bytes.push_back(static_cast<u8>(value));
}

void push_cp(std::vector<u8>& bytes, u8 reg, u32 value) {
  push_u8(bytes, 0x08);
  push_u8(bytes, reg);
  push_u32(bytes, value);
}

void push_bp(std::vector<u8>& bytes, u8 reg, u32 value) {
  push_u8(bytes, 0x61);
  push_u32(bytes, static_cast<u32>(reg) << 24 | (value & 0x00FFFFFF));
}

void push_xf(std::vector<u8>& bytes, u16 base, u32 value) {
  push_u8(bytes, 0x10);
  push_u32(bytes, base);
  push_u32(bytes, value);
}

void push_indexed_xf(std::vector<u8>& bytes, u8 command, u16 index, u16 base, u8 count) {
  push_u8(bytes, command);
  push_u32(bytes, static_cast<u32>(index) << 16 | static_cast<u32>(count - 1) << 12 | (base & 0x0FFF));
}

void push_call_dl(std::vector<u8>& bytes, u32 address, u32 size) {
  push_u8(bytes, 0x40);
  push_u32(bytes, address);
  push_u32(bytes, size);
}

u32 texture_image0(u16 width, u16 height, u32 format) {
  return static_cast<u32>(width - 1) | static_cast<u32>(height - 1) << 10 | (format & 0xF) << 20;
}

class AuroraRecompReplayTest : public GXFifoTest {
protected:
  void SetUp() override {
    GXFifoTest::SetUp();
    memory.resize(0x4000);
    requests.clear();
    aurora::gfx::g_testLastStoragePushSize = 0;
    aurora::gfx::g_testDrawCount = 0;
    aurora::gx::recomp::set_guest_address_resolver(resolve, this);
  }

  void TearDown() override {
    aurora::gx::recomp::clear_guest_address_resolver();
    GXFifoTest::TearDown();
  }

  static bool resolve(void* user, uint32_t address, uint32_t size, aurora::gx::recomp::AddressSpace space,
                      aurora::gx::recomp::ResourceKind resource, const void** data, uint32_t* available) {
    auto& self = *static_cast<AuroraRecompReplayTest*>(user);
    self.requests.push_back({address, size, space, resource});
    if (data == nullptr || available == nullptr || size == 0 || address >= self.memory.size() ||
        size > self.memory.size() - address) {
      return false;
    }
    *data = self.memory.data() + address;
    *available = static_cast<uint32_t>(self.memory.size() - address);
    return true;
  }

  bool saw_request(aurora::gx::recomp::ResourceKind resource, uint32_t address, uint32_t size) const {
    for (const auto& request : requests) {
      if (request.resource == resource && request.address == address && request.size == size) {
        return true;
      }
    }
    return false;
  }

  std::vector<u8> memory;
  std::vector<ResolveRequest> requests;
};

TEST_F(AuroraRecompReplayTest, RetailReplayResolvesAllRecompResources) {
  for (uint32_t i = 0; i < 256; ++i) {
    memory[PositionArrayAddress + i] = static_cast<u8>(0x10 + i);
    memory[TextureAddress + i] = static_cast<u8>(0x40 + i);
    memory[TlutAddress + i] = static_cast<u8>(0x20 + i);
    memory[CopyAddress + i] = static_cast<u8>(0x60 + i);
  }

  const std::array<u32, 12> indexedMatrix{
      0x3F800000, 0x40000000, 0x40400000, 0x40800000,
      0x40A00000, 0x40C00000, 0x40E00000, 0x41000000,
      0x41100000, 0x41200000, 0x41300000, 0x41400000,
  };
  size_t matrixPos = XfArrayAddress + 48;
  for (u32 value : indexedMatrix) {
    memory[matrixPos++] = static_cast<u8>(value >> 24);
    memory[matrixPos++] = static_cast<u8>(value >> 16);
    memory[matrixPos++] = static_cast<u8>(value >> 8);
    memory[matrixPos++] = static_cast<u8>(value);
  }

  std::vector<u8> displayList;
  push_bp(displayList, 0x00, 3u << 14);
  push_bp(displayList, 0x64, TlutAddress >> 5);
  push_bp(displayList, 0x65, 0x20u | (1u << 10));
  push_bp(displayList, 0x99, 0x20u | (1u << 10));
  push_bp(displayList, 0x89, texture_image0(16, 8, GX_TF_I8));
  push_bp(displayList, 0x95, TextureAddress >> 5);
  push_bp(displayList, 0x49, 0);
  push_bp(displayList, 0x4A, (7u << 10) | 7u);
  push_bp(displayList, 0x4B, CopyAddress >> 5);
  push_bp(displayList, 0x52, 2u << 3);
  push_xf(displayList, 0x1008, 0x12345678);
  push_indexed_xf(displayList, 0x20, 1, 0, 12);
  push_u8(displayList, GX_DRAW_TRIANGLES);
  push_u16(displayList, 3);
  push_u8(displayList, 2);
  push_u8(displayList, 5);
  push_u8(displayList, 1);

  std::memcpy(memory.data() + DisplayListAddress, displayList.data(), displayList.size());

  std::vector<u8> fifo;
  push_cp(fifo, 0x50, static_cast<u32>(GX_INDEX8) << 9);
  push_cp(fifo, 0x70, 0);
  push_cp(fifo, 0xA0, PositionArrayAddress);
  push_cp(fifo, 0xB0, 12);
  push_cp(fifo, 0xAC, XfArrayAddress);
  push_cp(fifo, 0xBC, 48);
  push_call_dl(fifo, DisplayListAddress, static_cast<u32>(displayList.size()));

  decode_fifo(fifo);

  EXPECT_EQ(gxState().arrays[GX_VA_POS].data, memory.data() + PositionArrayAddress);
  EXPECT_EQ(gxState().arrays[GX_VA_POS].stride, 12);
  EXPECT_EQ(aurora::gfx::g_testLastStoragePushSize, 72u);
  EXPECT_EQ(aurora::gfx::g_testDrawCount, 1u);

  const float* matrix = reinterpret_cast<const float*>(&gxState().pnMtx[0].pos);
  for (size_t i = 0; i < indexedMatrix.size(); ++i) {
    float expected;
    std::memcpy(&expected, &indexedMatrix[i], sizeof(expected));
    EXPECT_FLOAT_EQ(matrix[i], expected);
  }
  EXPECT_EQ(gxState().xfRegCache[8], 0x12345678u);
  EXPECT_EQ(gxState().cullMode, GX_CULL_ALL);

  auto texture = gxState().loadedTextures[1];
  ASSERT_TRUE(aurora::gx::recomp::resolve_texture_data(texture));
  EXPECT_EQ(aurora::gx::recomp::texture_byte_size(texture), 128u);
  EXPECT_EQ(texture.data, memory.data() + TextureAddress);

  GXTlutObj_ tlut{};
  ASSERT_TRUE(aurora::gx::recomp::resolve_texture_tlut(1, &tlut));
  EXPECT_EQ(tlut.data, memory.data() + TlutAddress);
  EXPECT_EQ(tlut.numEntries, 16);
  EXPECT_EQ(tlut.format, GX_TL_RGB565);

  EXPECT_EQ(gxState().texCopyDest, memory.data() + CopyAddress);
  EXPECT_EQ(gxState().texCopyDstWidth, 8u);
  EXPECT_EQ(gxState().texCopyDstHeight, 8u);

  EXPECT_TRUE(saw_request(aurora::gx::recomp::ResourceKind::DisplayList, DisplayListAddress,
                          static_cast<uint32_t>(displayList.size())));
  EXPECT_TRUE(saw_request(aurora::gx::recomp::ResourceKind::VertexArray, PositionArrayAddress, 1));
  EXPECT_TRUE(saw_request(aurora::gx::recomp::ResourceKind::VertexArray, XfArrayAddress, 1));
  EXPECT_TRUE(saw_request(aurora::gx::recomp::ResourceKind::Texture, TextureAddress, 128));
  EXPECT_TRUE(saw_request(aurora::gx::recomp::ResourceKind::Tlut, TlutAddress, 32));
  EXPECT_TRUE(saw_request(aurora::gx::recomp::ResourceKind::CopyDestination, CopyAddress, 64));
}

} // namespace
