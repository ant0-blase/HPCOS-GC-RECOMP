#ifndef DOLRECOMP_LLVM_BACKEND_H
#define DOLRECOMP_LLVM_BACKEND_H

#include "ir/dolir.h"

#include <stddef.h>

// Increment the aggregate version whenever a backend semantic change can
// alter generated machine code. Component versions make the reason visible in
// cache manifests and tests instead of relying on an output-directory name.
#define DOLLLVM_CODEGEN_VERSION 7u
#define DOLLLVM_EMITTER_VERSION 3u
#define DOLLLVM_SCHEDULER_VERSION 2u
#define DOLLLVM_PIPELINE_VERSION 3u
#define DOLLLVM_CHUNK_LAYOUT_VERSION 1u

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u32 start;
    u32 end;
} DolLLVMFunctionRange;

typedef struct {
    const char* target_triple;
    int optimization_level;
    int verify;
    int emit_ir;
    const char* ir_path;
    const DolLLVMFunctionRange* function_ranges;
    u32 function_range_count;
} DolLLVMOptions;

bool dolllvm_emit_object(const DolIRModule* module, const char* object_path,
                         const DolLLVMOptions* options, FILE* diagnostics);

// Resolve an optional target to the triple actually used for emission.
bool dolllvm_effective_triple(const char* requested, char* out, size_t size);

// Validate an object's container, word size and machine against the effective
// target.
bool dolllvm_object_matches_triple(const char* path, const char* requested);

// Canonical semantic identity shared by object-cache hashing and diagnostics.
// Debug-only output choices (IR dumps and verification) are intentionally not
// included because they do not affect the emitted object.
bool dolllvm_codegen_identity(const DolLLVMOptions* options, char* out,
                              size_t size);

#ifdef __cplusplus
}
#endif

#endif
