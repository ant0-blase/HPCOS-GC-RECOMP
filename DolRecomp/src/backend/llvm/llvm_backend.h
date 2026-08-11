#ifndef DOLRECOMP_LLVM_BACKEND_H
#define DOLRECOMP_LLVM_BACKEND_H

#include "ir/dolir.h"

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

// Resolve an optional target to the triple used for emission.
bool dolllvm_effective_triple(const char* requested, char* out, size_t size);

// Validate an object's magic against the effective target triple.
bool dolllvm_object_matches_triple(const char* path, const char* requested);

#ifdef __cplusplus
}
#endif

#endif
