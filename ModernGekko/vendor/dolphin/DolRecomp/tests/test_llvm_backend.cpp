#include "backend/llvm/llvm_backend.h"
#include "cpu/cpu.h"
#include "ir/dolir_builder.h"

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iterator>
#include <string>

#define CHECK(x) do { if (!(x)) { std::fprintf(stderr, "check failed: %s:%d: %s\n", \
    __FILE__, __LINE__, #x); return 1; } } while (0)

static_assert(DOLRECOMP_CPU_ABI_VERSION == 4u);
static_assert(sizeof(void*) != 8 ||
              offsetof(CPUState, native_cycle_budget) == 3504u);
static_assert(sizeof(void*) != 8 ||
              offsetof(CPUState, native_guard_budget) == 3512u);

static u32 encode_spr(u16 spr) {
    return ((spr & 31u) << 5) | ((spr >> 5) & 31u);
}

static u32 mfspr(u8 destination, u16 spr) {
    return 0x7C0002A6u | (u32(destination) << 21) | (encode_spr(spr) << 11);
}

static u32 mtspr(u8 source, u16 spr) {
    return 0x7C0003A6u | (u32(source) << 21) | (encode_spr(spr) << 11);
}

static bool add_chunk(DolIRModule* module, const u32* words, u32 count,
                      u32 address) {
    PPCInst* instructions = new PPCInst[count];
    for (u32 i = 0; i < count; i++)
        instructions[i] = ppc_decode(words[i], address + i * 4u);
    const bool result = dolir_build_chunk(module, instructions, count, address);
    delete[] instructions;
    return result;
}

int main(int argc, char** argv) {
    CHECK(argc == 3);
    DolIRModule module;
    dolir_module_init(&module);

    const u32 main_words[] = {
        0x38600000u, 0x00000000u, 0x38800000u, 0x7C841A14u,
        0x90610000u, 0x38630001u, 0x2C03000Au, 0x4180FFF4u,
        0xEE32A4FAu, 0x4E800020u,
    };
    CHECK(add_chunk(&module, main_words, 10, 0x80001000u));

    const u32 spr_words[] = {
        mtspr(3, 273), mfspr(4, 273), 0x4E800020u,
    };
    CHECK(add_chunk(&module, spr_words, 3, 0x80002000u));

    const u32 segment_words[] = {
        0x7DC401A4u, 0x7D6304A6u, 0x7DE081E4u, 0x7D806D26u,
        0x4E800020u,
    };
    CHECK(add_chunk(&module, segment_words, 5, 0x80002100u));

    const u32 fpscr_words[] = {
        0xFFE0004Cu, 0xFDA0048Eu, 0x4E800020u,
    };
    CHECK(add_chunk(&module, fpscr_words, 3, 0x80002200u));

    const u32 lswx_words[] = {
        0x7D34AC2Au, 0x4E800020u,
    };
    CHECK(add_chunk(&module, lswx_words, 2, 0x80002300u));

    const u32 cache_words[] = {
        0x7C11906Cu, 0x4E800020u,
    };
    CHECK(add_chunk(&module, cache_words, 2, 0x80002400u));

    const u32 trap_words[] = {
        0x0C85FFFEu, 0x38630001u, 0x4E800020u,
    };
    CHECK(add_chunk(&module, trap_words, 3, 0x80002500u));

    const u32 sc_words[] = {0x44000002u};
    CHECK(add_chunk(&module, sc_words, 1, 0x80002600u));

    const u32 rfi_words[] = {0x4C000064u};
    CHECK(add_chunk(&module, rfi_words, 1, 0x80002700u));

    const u32 dcbz_l_words[] = {
        0x100537ECu, 0x4E800020u,
    };
    CHECK(add_chunk(&module, dcbz_l_words, 2, 0x80002800u));

    const u32 ecowx_words[] = {
        0x7D6C6B6Cu, 0x4E800020u,
    };
    CHECK(add_chunk(&module, ecowx_words, 2, 0x80002900u));

    const u32 float_words[] = {
        0xEC22182Au, 0xEC853028u, 0xECE80272u, 0xED4B6024u,
        0xFDAE782Au, 0xFE119028u, 0xFE740572u, 0xFED7C024u,
        0x4E800020u,
    };
    CHECK(add_chunk(&module, float_words, 9, 0x80002A00u));

    const u32 paired_words[] = {
        0x1022182Au, 0x10E80272u, 0x11AE83FAu, 0x10A03030u,
        0x110D7000u, 0x10853460u, 0x4E800020u,
    };
    CHECK(add_chunk(&module, paired_words, 7, 0x80002B00u));

    // A fallback helper inside a native loop must not reset the persistent
    // dispatch budget when local cycle materialization is cleared.
    const u32 fallback_poll_words[] = {
        0x38630001u, 0x00000000u, 0x2C032710u, 0x4180FFF4u,
        0x4E800020u,
    };
    CHECK(add_chunk(&module, fallback_poll_words, 5, 0x80002C00u));

    // Synthetic MMIO polling regression: lwz/cmp/beq must yield before the
    // next read once its cycle edge exhausts the native quantum.
    const u32 external_poll_words[] = {
        0x80830000u, 0x2C040000u, 0x4182FFF8u, 0x4E800020u,
    };
    CHECK(add_chunk(&module, external_poll_words, 4, 0x80002D00u));

    // The only cycle here closes through an indirect LR continuation.
    const u32 indirect_cycle_words[] = {
        0x48000009u, 0x48000004u, 0x38630001u, 0x4E800020u,
    };
    CHECK(add_chunk(&module, indirect_cycle_words, 4, 0x80002E00u));

    // Even when both targets are known generated ranges, crossing a chunk
    // must side-exit through the runtime chassis instead of recursing.
    const u32 cross_chunk_a[] = {0x48000100u};
    const u32 cross_chunk_b[] = {0x38630001u, 0x4BFFFFFCu};
    CHECK(add_chunk(&module, cross_chunk_a, 1, 0x80003100u));
    CHECK(add_chunk(&module, cross_chunk_b, 2, 0x80003200u));

    CHECK(dolir_verify(&module, stderr));
    DolLLVMOptions options{};
    options.optimization_level = 2;
    options.verify = 1;
    options.emit_ir = 1;
    options.ir_path = argv[2];
    const DolLLVMFunctionRange ranges[] = {
        {0x80003100u, 0x80003104u},
        {0x80003200u, 0x80003208u},
    };
    options.function_ranges = ranges;
    options.function_range_count = 2;
    char developmentIdentity[2048]{};
    char productionIdentity[2048]{};
    options.optimization_level = 1;
    CHECK(dolllvm_codegen_identity(&options, developmentIdentity,
                                   sizeof(developmentIdentity)));
    options.optimization_level = 3;
    CHECK(dolllvm_codegen_identity(&options, productionIdentity,
                                   sizeof(productionIdentity)));
    CHECK(std::strcmp(developmentIdentity, productionIdentity) != 0);
    CHECK(std::strstr(developmentIdentity, "scheduler=2") != nullptr);
    CHECK(std::strstr(productionIdentity,
                      "instcombine<no-verify-fixpoint>") != nullptr);
    // Emit with the production pipeline as well as hashing it above. This
    // catches pass-name or nesting mistakes that a cache-identity-only check
    // cannot detect.
    options.optimization_level = 3;
    CHECK(dolllvm_emit_object(&module, argv[1], &options, stderr));
    FILE* object = std::fopen(argv[1], "rb");
    CHECK(object != nullptr);
    unsigned char magic[4]{};
    CHECK(std::fread(magic, 1, sizeof(magic), object) == sizeof(magic));
    std::fclose(object);
    CHECK(dolllvm_object_matches_triple(argv[1], options.target_triple));
    const std::string wrongArchPath = std::string(argv[1]) + ".wrong-arch";
    {
      // AArch64 ELF64 header: a container-only cache check would incorrectly
      // accept this for the x86-64 backend.
      unsigned char wrongArchHeader[20] = {
          0x7f, 'E', 'L', 'F', 2, 1, 1, 0, 0, 0,
          0,    0,   0,   0,   0, 0, 0, 0, 0xb7, 0,
      };
      std::ofstream wrongArch(wrongArchPath, std::ios::binary);
      wrongArch.write(reinterpret_cast<const char*>(wrongArchHeader),
                      sizeof(wrongArchHeader));
    }
    CHECK(!dolllvm_object_matches_triple(wrongArchPath.c_str(),
                                         options.target_triple));
    CHECK(std::remove(wrongArchPath.c_str()) == 0);
    std::ifstream ir(argv[2]);
    const std::string irText((std::istreambuf_iterator<char>(ir)),
                             std::istreambuf_iterator<char>());
    CHECK(irText.find("define hidden void @func_80001000") !=
          std::string::npos);
    CHECK(irText.find("cycle_guard") != std::string::npos);
    CHECK(irText.find("call void @func_80003200") == std::string::npos);
    dolir_module_free(&module);
    return 0;
}
