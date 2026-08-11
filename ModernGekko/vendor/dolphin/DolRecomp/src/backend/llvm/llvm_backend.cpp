#include "backend/llvm/llvm_backend.h"
#include "backend/llvm/llvm_function_emitter.h"
#include "cpu/cpu.h"

#include <cstdio>
#include <cstring>
#include <memory>
#include <optional>
#include <string>
#include <system_error>

#include <llvm/Analysis/CGSCCPassManager.h>
#include <llvm/Analysis/LoopAnalysisManager.h>
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/Config/llvm-config.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/TargetParser/Host.h>
#include <llvm/TargetParser/Triple.h>

namespace {

using namespace llvm;

static std::string resolveTriple(const char *requested) {
  return requested && requested[0] ? std::string(requested)
                                   : llvm::sys::getDefaultTargetTriple();
}

static const char *pipelineForLevel(int level) {
  if (level <= 0)
    return "none";
  if (level == 1)
    return "function(mem2reg,early-cse,instcombine<no-verify-fixpoint>,"
           "simplifycfg,sccp,dse,adce,tailcallelim),globaldce";
  if (level == 2)
    return "function(mem2reg,early-cse<memssa>,"
           "instcombine<no-verify-fixpoint>,simplifycfg,sccp,"
           "correlated-propagation,jump-threading,gvn,dse,adce,"
           "loop-simplify,loop-rotate,loop-mssa(licm),loop-vectorize,"
           "slp-vectorizer,vector-combine,tailcallelim),cgscc(inline),"
           "ipsccp,globaldce";
  return "function(mem2reg,early-cse<memssa>,"
         "instcombine<no-verify-fixpoint>,simplifycfg,sccp,"
         "correlated-propagation,jump-threading,gvn,dse,adce,"
         "loop-simplify,loop-rotate,loop-mssa(licm),loop-unroll,"
         "loop-vectorize,slp-vectorizer,vector-combine,tailcallelim),"
         "cgscc(inline),ipsccp,globaldce";
}

static CodeGenOptLevel codegenLevel(int level) {
  if (level <= 0)
    return CodeGenOptLevel::None;
  if (level == 1)
    return CodeGenOptLevel::Less;
  if (level == 2)
    return CodeGenOptLevel::Default;
  return CodeGenOptLevel::Aggressive;
}

static TargetMachine *targetMachine(const Target *target,
                                    const std::string &tripleName, int opt) {
  static thread_local std::string cachedTriple;
  static thread_local int cachedOpt = -1;
  static thread_local std::unique_ptr<TargetMachine> cachedMachine;
  if (!cachedMachine || cachedTriple != tripleName || cachedOpt != opt) {
    TargetOptions options;
    cachedMachine.reset(target->createTargetMachine(
        tripleName, "generic", "", options, Reloc::PIC_, std::nullopt,
        codegenLevel(opt)));
    cachedTriple = tripleName;
    cachedOpt = opt;
  }
  return cachedMachine.get();
}

} // namespace

extern "C" bool dolllvm_emit_object(const DolIRModule *source,
                                    const char *object_path,
                                    const DolLLVMOptions *options,
                                    FILE *diagnostics) {
  if (!source || !object_path || !diagnostics)
    return false;
  static bool initialized = [] {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
    return true;
  }();
  (void)initialized;

  int opt = options ? options->optimization_level : 2;
  if (opt < 0 || opt > 3) {
    fprintf(diagnostics, "dolllvm: optimization level must be 0..3\n");
    return false;
  }
  std::string tripleName =
      resolveTriple(options ? options->target_triple : nullptr);
  const llvm::Triple triple(tripleName);
  if (triple.getArch() != llvm::Triple::x86_64 ||
      (!triple.isOSLinux() && !triple.isOSWindows())) {
    fprintf(
        diagnostics,
        "dolllvm: supported production targets are x86-64 Linux and Windows\n");
    return false;
  }

  std::string error;
  const llvm::Target *target =
      llvm::TargetRegistry::lookupTarget(tripleName, error);
  if (!target) {
    fprintf(diagnostics, "dolllvm: %s\n", error.c_str());
    return false;
  }
  llvm::TargetMachine *machine = targetMachine(target, tripleName, opt);
  if (!machine) {
    fprintf(diagnostics, "dolllvm: failed to create target machine\n");
    return false;
  }

  llvm::LLVMContext context;
  llvm::Module module("dolrecomp_native", context);
  module.setTargetTriple(tripleName);
  module.setDataLayout(machine->createDataLayout());
  std::string diagnosticText;
  llvm::raw_string_ostream diagnosticStream(diagnosticText);
  for (u32 i = 0; i < source->function_count; i++) {
    dolllvm::FunctionEmitter emitter(
        context, module, source->functions[i],
        options ? options->function_ranges : nullptr,
        options ? options->function_range_count : 0);
    if (!emitter.emit(diagnosticStream)) {
      diagnosticStream.flush();
      fprintf(diagnostics, "%s", diagnosticText.c_str());
      return false;
    }
  }
  if (llvm::verifyModule(module, &diagnosticStream)) {
    diagnosticStream.flush();
    fprintf(diagnostics, "%s", diagnosticText.c_str());
    return false;
  }

  if (opt > 0) {
    llvm::LoopAnalysisManager lam;
    llvm::FunctionAnalysisManager fam;
    llvm::CGSCCAnalysisManager cgam;
    llvm::ModuleAnalysisManager mam;
    llvm::PassBuilder passBuilder(machine);
    passBuilder.registerModuleAnalyses(mam);
    passBuilder.registerCGSCCAnalyses(cgam);
    passBuilder.registerFunctionAnalyses(fam);
    passBuilder.registerLoopAnalyses(lam);
    passBuilder.crossRegisterProxies(lam, fam, cgam, mam);
    llvm::ModulePassManager passes;
    const std::string pipeline = pipelineForLevel(opt);
    if (llvm::Error error = passBuilder.parsePassPipeline(passes, pipeline)) {
      fprintf(diagnostics,
              "dolllvm: cannot construct optimization pipeline: %s\n",
              llvm::toString(std::move(error)).c_str());
      return false;
    }
    passes.run(module, mam);
  }
  if (llvm::verifyModule(module, &diagnosticStream)) {
    diagnosticStream.flush();
    fprintf(diagnostics, "%s", diagnosticText.c_str());
    return false;
  }

  if (options && options->emit_ir && options->ir_path) {
    std::error_code irError;
    llvm::raw_fd_ostream irFile(options->ir_path, irError,
                                llvm::sys::fs::OF_Text);
    if (irError) {
      fprintf(diagnostics, "dolllvm: cannot write IR: %s\n",
              irError.message().c_str());
      return false;
    }
    module.print(irFile, nullptr);
  }

  std::error_code objectError;
  llvm::raw_fd_ostream objectFile(object_path, objectError,
                                  llvm::sys::fs::OF_None);
  if (objectError) {
    fprintf(diagnostics, "dolllvm: cannot write object: %s\n",
            objectError.message().c_str());
    return false;
  }
  llvm::legacy::PassManager codegen;
  if (machine->addPassesToEmitFile(codegen, objectFile, nullptr,
                                   llvm::CodeGenFileType::ObjectFile)) {
    fprintf(diagnostics, "dolllvm: target cannot emit objects\n");
    return false;
  }
  codegen.run(module);
  objectFile.flush();
  return true;
}

extern "C" bool dolllvm_effective_triple(const char *requested, char *out,
                                         size_t size) {
  if (!out || size == 0)
    return false;
  const std::string triple = resolveTriple(requested);
  if (triple.size() + 1 > size)
    return false;
  std::memcpy(out, triple.c_str(), triple.size() + 1);
  return true;
}

extern "C" bool dolllvm_object_matches_triple(const char *path,
                                              const char *requested) {
  FILE *file = std::fopen(path, "rb");
  if (!file)
    return false;
  unsigned char header[20] = {};
  const size_t read = std::fread(header, 1, sizeof(header), file);
  std::fclose(file);
  if (read != sizeof(header))
    return false;

  const llvm::Triple triple(resolveTriple(requested));
  if (triple.isOSBinFormatCOFF())
    // IMAGE_FILE_MACHINE_AMD64 in little-endian COFF object headers.
    return header[0] == 0x64 && header[1] == 0x86;
  if (triple.isOSBinFormatELF())
    // ELF64, little endian, EM_X86_64. Checking only the ELF magic would let
    // an object for a different host architecture masquerade as a cache hit.
    return header[0] == 0x7f && header[1] == 'E' && header[2] == 'L' &&
           header[3] == 'F' && header[4] == 2 && header[5] == 1 &&
           header[18] == 0x3e && header[19] == 0;
  return false;
}

extern "C" bool dolllvm_codegen_identity(const DolLLVMOptions *options,
                                         char *out, size_t size) {
  if (!out || size == 0)
    return false;
  const int opt = options ? options->optimization_level : 2;
  if (opt < 0 || opt > 3)
    return false;
  const std::string triple =
      resolveTriple(options ? options->target_triple : nullptr);
  const int written = std::snprintf(
      out, size,
      "dolllvm-codegen=%u;emitter=%u;scheduler=%u;pipeline-version=%u;"
      "chunk-layout=%u;cpu-abi=%u;cpu-state-size=%zu;llvm=%s;"
      "triple=%s;cpu=generic;features=;reloc=pic;opt=%d;pipeline=%s",
      DOLLLVM_CODEGEN_VERSION, DOLLLVM_EMITTER_VERSION,
      DOLLLVM_SCHEDULER_VERSION, DOLLLVM_PIPELINE_VERSION,
      DOLLLVM_CHUNK_LAYOUT_VERSION, DOLRECOMP_CPU_ABI_VERSION,
      sizeof(CPUState), LLVM_VERSION_STRING, triple.c_str(), opt,
      pipelineForLevel(opt));
  return written >= 0 && static_cast<size_t>(written) < size;
}
