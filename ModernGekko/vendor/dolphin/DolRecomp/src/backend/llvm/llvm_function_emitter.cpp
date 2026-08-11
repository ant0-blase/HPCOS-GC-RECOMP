#include "backend/llvm/llvm_function_emitter.h"
#include "cpu/cpu.h"

#include <algorithm>
#include <cstdio>
#include <functional>

#include <llvm/ADT/SmallVector.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/Format.h>
#include <llvm/Support/raw_ostream.h>

namespace dolllvm {

using namespace llvm;

FunctionEmitter::FunctionEmitter(LLVMContext &context, Module &module,
                                 const DolIRFunction &source,
                                 const DolLLVMFunctionRange *ranges,
                                 u32 range_count)
    : context_(context), module_(module), source_(source), builder_(context) {
  // Cross-chunk generated calls intentionally side-exit through the runtime
  // chassis. Keep these parameters in the public constructor for source/API
  // compatibility with callers that also use ranges for module dispatch.
  (void)ranges;
  (void)range_count;
}

bool FunctionEmitter::emit(raw_ostream &diagnostics) {
  auto *type = FunctionType::get(Type::getVoidTy(context_),
                                 {PointerType::getUnqual(context_)}, false);
  function_ = Function::Create(type, GlobalValue::ExternalLinkage, source_.name,
                               module_);
  function_->setCallingConv(CallingConv::C);
  function_->setVisibility(GlobalValue::HiddenVisibility);
  function_->setDSOLocal(true);
  ctx_ = function_->getArg(0);
  ctx_->setName("ctx");

  entry_ = BasicBlock::Create(context_, "entry", function_);
  for (u32 i = 0; i < source_.block_count; i++)
    blocks_.push_back(BasicBlock::Create(context_, blockName(i), function_));
  scanState();
  scanContinuations();
  scanCycleGuards();
  emitEntry();
  for (u32 i = 0; i < source_.block_count; i++)
    if (!emitBlock(i, diagnostics))
      return false;
  return !verifyFunction(*function_, &diagnostics);
}

std::string FunctionEmitter::blockName(u32 index) const {
  char text[40];
  snprintf(text, sizeof(text), "guest_%08X_b%u",
           source_.blocks[index].guest_address, index);
  return text;
}

Type *FunctionEmitter::type(DolIRType t) {
  switch (t) {
  case DOLIR_TYPE_I1:
    return Type::getInt1Ty(context_);
  case DOLIR_TYPE_I8:
    return Type::getInt8Ty(context_);
  case DOLIR_TYPE_I16:
    return Type::getInt16Ty(context_);
  case DOLIR_TYPE_I32:
    return Type::getInt32Ty(context_);
  case DOLIR_TYPE_I64:
    return Type::getInt64Ty(context_);
  case DOLIR_TYPE_F32:
    return Type::getFloatTy(context_);
  case DOLIR_TYPE_F64:
    return Type::getDoubleTy(context_);
  case DOLIR_TYPE_V2F32:
    return FixedVectorType::get(Type::getFloatTy(context_), 2);
  case DOLIR_TYPE_V2F64:
    return FixedVectorType::get(Type::getDoubleTy(context_), 2);
  default:
    return Type::getVoidTy(context_);
  }
}

size_t FunctionEmitter::stateOffset(DolIRStateSlot slot) const {
  if (slot >= DOLIR_STATE_GPR0 && slot <= DOLIR_STATE_GPR31)
    return offsetof(CPUState, gpr) + 4u * (slot - DOLIR_STATE_GPR0);
  if (slot >= DOLIR_STATE_FPR0 && slot <= DOLIR_STATE_FPR31)
    return offsetof(CPUState, fpr) + 8u * (slot - DOLIR_STATE_FPR0);
  if (slot >= DOLIR_STATE_PS1_0 && slot <= DOLIR_STATE_PS1_31)
    return offsetof(CPUState, ps1) + 8u * (slot - DOLIR_STATE_PS1_0);
  if (slot >= DOLIR_STATE_SR0 && slot <= DOLIR_STATE_SR15)
    return offsetof(CPUState, sr) + 4u * (slot - DOLIR_STATE_SR0);
  if (slot >= DOLIR_STATE_GQR0 && slot <= DOLIR_STATE_GQR7)
    return offsetof(CPUState, gqr) + 4u * (slot - DOLIR_STATE_GQR0);
  switch (slot) {
  case DOLIR_STATE_PC:
    return offsetof(CPUState, pc);
  case DOLIR_STATE_LR:
    return offsetof(CPUState, lr);
  case DOLIR_STATE_CTR:
    return offsetof(CPUState, ctr);
  case DOLIR_STATE_CR:
    return offsetof(CPUState, cr);
  case DOLIR_STATE_XER:
    return offsetof(CPUState, xer);
  case DOLIR_STATE_FPSCR:
    return offsetof(CPUState, fpscr);
  case DOLIR_STATE_MSR:
    return offsetof(CPUState, msr);
  case DOLIR_STATE_SRR0:
    return offsetof(CPUState, srr0);
  case DOLIR_STATE_SRR1:
    return offsetof(CPUState, srr1);
  case DOLIR_STATE_DAR:
    return offsetof(CPUState, dar);
  case DOLIR_STATE_DSISR:
    return offsetof(CPUState, dsisr);
  case DOLIR_STATE_EAR:
    return offsetof(CPUState, ear);
  case DOLIR_STATE_HID2:
    return offsetof(CPUState, hid2);
  case DOLIR_STATE_TIMEBASE:
    return offsetof(CPUState, timebase);
  case DOLIR_STATE_EXCEPTION:
    return offsetof(CPUState, exception);
  case DOLIR_STATE_PROGRAM_EXCEPTION:
    return offsetof(CPUState, program_exception);
  case DOLIR_STATE_RESERVE_ADDR:
    return offsetof(CPUState, reserve_addr);
  case DOLIR_STATE_RESERVE_VALID:
    return offsetof(CPUState, reserve_valid);
  case DOLIR_STATE_DOWNCOUNT:
    return offsetof(CPUState, downcount);
  default:
    return 0;
  }
}

Value *FunctionEmitter::bytePtr(size_t offset) {
  return builder_.CreateInBoundsGEP(
      Type::getInt8Ty(context_), ctx_,
      ConstantInt::get(Type::getInt64Ty(context_), offset));
}

Value *FunctionEmitter::loadContext(DolIRStateSlot slot) {
  return builder_.CreateLoad(type(dolir_state_type(slot)),
                             bytePtr(stateOffset(slot)));
}

void FunctionEmitter::storeContext(DolIRStateSlot slot, Value *value) {
  builder_.CreateStore(value, bytePtr(stateOffset(slot)));
}

Value *FunctionEmitter::loadOffset(Type *valueType, size_t offset) {
  return builder_.CreateLoad(valueType, bytePtr(offset));
}

void FunctionEmitter::scanState() {
  for (u32 b = 0; b < source_.block_count; b++) {
    const DolIRBlock &block = source_.blocks[b];
    for (u32 i = 0; i < block.instruction_count; i++) {
      const DolIRInstruction &inst = block.instructions[i];
      if (inst.op == DOLIR_OP_STATE_READ || inst.op == DOLIR_OP_STATE_WRITE)
        used_[inst.aux] = true;
      if (inst.op == DOLIR_OP_STATE_WRITE)
        dirty_[inst.aux] = true;
      if (inst.op == DOLIR_OP_HELPER_CALL &&
          inst.aux == DOLIR_HELPER_FP_AVAILABLE)
        used_[DOLIR_STATE_MSR] = true;
      if (inst.op == DOLIR_OP_HELPER_CALL &&
          inst.aux == DOLIR_HELPER_EXACT_FLOAT)
        scanExactFloat(inst.immediate);
      if (inst.op == DOLIR_OP_HELPER_CALL &&
          inst.aux == DOLIR_HELPER_EXACT_PAIRED)
        scanExactPaired(inst.immediate);
      if (inst.op == DOLIR_OP_HELPER_CALL &&
          inst.aux == DOLIR_HELPER_PSQ_LOAD) {
        u32 reg = inst.immediate & 0xFFu;
        used_[DOLIR_STATE_FPR0 + reg] = true;
        dirty_[DOLIR_STATE_FPR0 + reg] = true;
        used_[DOLIR_STATE_PS1_0 + reg] = true;
        dirty_[DOLIR_STATE_PS1_0 + reg] = true;
      }
      if (inst.op == DOLIR_OP_HELPER_CALL &&
          inst.aux == DOLIR_HELPER_STORE_CONDITIONAL) {
        used_[DOLIR_STATE_CR] = true;
        dirty_[DOLIR_STATE_CR] = true;
        used_[DOLIR_STATE_RESERVE_VALID] = true;
        dirty_[DOLIR_STATE_RESERVE_VALID] = true;
        used_[DOLIR_STATE_RESERVE_ADDR] = true;
      }
      if (inst.op == DOLIR_OP_HELPER_CALL &&
          (inst.aux == DOLIR_HELPER_FPSCR_UPDATED ||
           inst.aux == DOLIR_HELPER_FPSCR_BIT)) {
        used_[DOLIR_STATE_FPSCR] = true;
        dirty_[DOLIR_STATE_FPSCR] = true;
      }
      if (inst.op == DOLIR_OP_HELPER_CALL && inst.aux == DOLIR_HELPER_LSWX) {
        used_[DOLIR_STATE_XER] = true;
        for (u32 reg = 0; reg < 32; reg++) {
          used_[DOLIR_STATE_GPR0 + reg] = true;
          dirty_[DOLIR_STATE_GPR0 + reg] = true;
        }
      }
      if (inst.op == DOLIR_OP_GUEST_STORE) {
        used_[DOLIR_STATE_RESERVE_ADDR] = true;
        used_[DOLIR_STATE_RESERVE_VALID] = true;
        dirty_[DOLIR_STATE_RESERVE_VALID] = true;
      }
    }
  }
}

void FunctionEmitter::scanExactFloat(u64 descriptor) {
  auto op = static_cast<DolIRExactFloat>(descriptor & 0xFFu);
  u32 d = (descriptor >> 8) & 0xFFu;
  u32 a = (descriptor >> 16) & 0xFFu;
  u32 b = (descriptor >> 24) & 0xFFu;
  u32 c = (descriptor >> 32) & 0xFFu;
  used_[DOLIR_STATE_FPSCR] = true;
  dirty_[DOLIR_STATE_FPSCR] = true;
  if (op == DOLIR_EXACT_FCMPU || op == DOLIR_EXACT_FCMPO) {
    used_[DOLIR_STATE_CR] = true;
    dirty_[DOLIR_STATE_CR] = true;
    used_[DOLIR_STATE_FPR0 + a] = true;
    used_[DOLIR_STATE_FPR0 + b] = true;
    return;
  }
  used_[DOLIR_STATE_FPR0 + d] = true;
  dirty_[DOLIR_STATE_FPR0 + d] = true;
  if (op == DOLIR_EXACT_FRES ||
      (op >= DOLIR_EXACT_FADDS && op <= DOLIR_EXACT_FDIVS) ||
      op == DOLIR_EXACT_FRSP ||
      (op >= DOLIR_EXACT_FMADDS && op <= DOLIR_EXACT_FNMSUBS)) {
    used_[DOLIR_STATE_PS1_0 + d] = true;
    dirty_[DOLIR_STATE_PS1_0 + d] = true;
  }
  if (op == DOLIR_EXACT_FRES || op == DOLIR_EXACT_FRSQRTE ||
      op == DOLIR_EXACT_FCTIW || op == DOLIR_EXACT_FCTIWZ ||
      op == DOLIR_EXACT_FRSP) {
    used_[DOLIR_STATE_FPR0 + b] = true;
  } else if (op == DOLIR_EXACT_FMULS || op == DOLIR_EXACT_FMUL) {
    used_[DOLIR_STATE_FPR0 + a] = true;
    used_[DOLIR_STATE_FPR0 + c] = true;
  } else if ((op >= DOLIR_EXACT_FADDS && op <= DOLIR_EXACT_FDIVS) ||
             (op >= DOLIR_EXACT_FADD && op <= DOLIR_EXACT_FDIV)) {
    used_[DOLIR_STATE_FPR0 + a] = true;
    used_[DOLIR_STATE_FPR0 + b] = true;
  } else {
    used_[DOLIR_STATE_FPR0 + a] = true;
    used_[DOLIR_STATE_FPR0 + b] = true;
    used_[DOLIR_STATE_FPR0 + c] = true;
  }
}

void FunctionEmitter::scanExactPaired(u64 descriptor) {
  auto op = static_cast<DolIRExactPaired>(descriptor & 0xFFu);
  u32 d = (descriptor >> 8) & 0xFFu;
  u32 a = (descriptor >> 16) & 0xFFu;
  u32 b = (descriptor >> 24) & 0xFFu;
  u32 c = (descriptor >> 32) & 0xFFu;
  used_[DOLIR_STATE_FPSCR] = true;
  dirty_[DOLIR_STATE_FPSCR] = true;
  if (op >= DOLIR_EXACT_PS_CMPU0) {
    used_[DOLIR_STATE_CR] = true;
    dirty_[DOLIR_STATE_CR] = true;
    used_[DOLIR_STATE_FPR0 + a] = true;
    used_[DOLIR_STATE_PS1_0 + a] = true;
    used_[DOLIR_STATE_FPR0 + b] = true;
    used_[DOLIR_STATE_PS1_0 + b] = true;
    return;
  }
  used_[DOLIR_STATE_FPR0 + d] = true;
  dirty_[DOLIR_STATE_FPR0 + d] = true;
  used_[DOLIR_STATE_PS1_0 + d] = true;
  dirty_[DOLIR_STATE_PS1_0 + d] = true;
  auto usePair = [this](u32 reg) {
    used_[DOLIR_STATE_FPR0 + reg] = true;
    used_[DOLIR_STATE_PS1_0 + reg] = true;
  };
  if (op == DOLIR_EXACT_PS_RES || op == DOLIR_EXACT_PS_RSQRTE) {
    usePair(b);
    return;
  }
  usePair(a);
  if (op == DOLIR_EXACT_PS_MUL || op == DOLIR_EXACT_PS_MULS0 ||
      op == DOLIR_EXACT_PS_MULS1) {
    usePair(c);
    return;
  }
  usePair(b);
  if (op >= DOLIR_EXACT_PS_MADD && op <= DOLIR_EXACT_PS_SUM1)
    usePair(c);
}

void FunctionEmitter::scanContinuations() {
  for (u32 i = 0; i < source_.block_count; i++) {
    const DolIRTerminator &term = source_.blocks[i].terminator;
    if (!term.linked)
      continue;
    u32 continuation = term.guest_pc + 4u;
    u32 block = 0;
    if (continuation >= source_.guest_start &&
        continuation < source_.guest_end &&
        ((continuation - source_.guest_start) & 3u) == 0) {
      block = (continuation - source_.guest_start) / 4u;
      if (block < source_.block_count)
        continuations_.push_back(block);
    }
  }
}

void FunctionEmitter::scanCycleGuards() {
  const u32 count = source_.block_count;
  std::vector<std::vector<u32>> successors(count);
  auto addSuccessor = [&](u32 source, u32 destination) {
    if (source >= count || destination == DOLIR_NO_BLOCK ||
        destination >= count)
      return;
    auto &edges = successors[source];
    if (std::find(edges.begin(), edges.end(), destination) == edges.end())
      edges.push_back(destination);
  };

  /*
   * This graph must describe every edge which LLVM can keep inside this
   * generated function. In particular, the indirect switch in
   * llvm_control_flow.cpp can target every local linked-call continuation.
   * Runtime/fallback resume is also an in-function edge. Cross-chunk edges are
   * deliberately absent because they side-exit to the chassis.
   */
  for (u32 source = 0; source < count; ++source) {
    const DolIRTerminator &term = source_.blocks[source].terminator;
    switch (term.kind) {
    case DOLIR_TERM_BRANCH:
      addSuccessor(source, term.targets[0]);
      break;
    case DOLIR_TERM_COND_BRANCH:
      addSuccessor(source, term.targets[0]);
      addSuccessor(source, term.targets[1]);
      break;
    case DOLIR_TERM_INDIRECT:
      addSuccessor(source, term.targets[1]);
      for (u32 continuation : continuations_)
        addSuccessor(source, continuation);
      break;
    case DOLIR_TERM_FALLBACK: {
      const u32 next = term.guest_pc + 4u;
      if (next >= source_.guest_start && next < source_.guest_end &&
          ((next - source_.guest_start) & 3u) == 0)
        addSuccessor(source, (next - source_.guest_start) / 4u);
      break;
    }
    default:
      break;
    }
  }

  // Tarjan SCC decomposition identifies precisely which local edges can be
  // part of a cycle. Recursion depth is bounded by the configured chunk size.
  std::vector<int> index(count, -1);
  std::vector<int> lowlink(count, -1);
  std::vector<int> component(count, -1);
  std::vector<u32> stack;
  std::vector<bool> onStack(count, false);
  std::vector<u32> componentSize;
  int nextIndex = 0;
  int nextComponent = 0;
  std::function<void(u32)> connect = [&](u32 source) {
    index[source] = nextIndex;
    lowlink[source] = nextIndex;
    ++nextIndex;
    stack.push_back(source);
    onStack[source] = true;

    for (u32 destination : successors[source]) {
      if (index[destination] < 0) {
        connect(destination);
        lowlink[source] = std::min(lowlink[source], lowlink[destination]);
      } else if (onStack[destination]) {
        lowlink[source] = std::min(lowlink[source], index[destination]);
      }
    }

    if (lowlink[source] != index[source])
      return;
    u32 size = 0;
    while (true) {
      const u32 member = stack.back();
      stack.pop_back();
      onStack[member] = false;
      component[member] = nextComponent;
      ++size;
      if (member == source)
        break;
    }
    componentSize.push_back(size);
    ++nextComponent;
  };

  for (u32 block = 0; block < count; ++block) {
    if (index[block] < 0)
      connect(block);
  }

  std::vector<bool> cyclic(componentSize.size(), false);
  for (u32 block = 0; block < count; ++block) {
    const int id = component[block];
    if (id >= 0 && componentSize[static_cast<u32>(id)] > 1)
      cyclic[static_cast<u32>(id)] = true;
    for (u32 destination : successors[block]) {
      if (destination == block)
        cyclic[static_cast<u32>(id)] = true;
    }
  }

  guarded_successors_.assign(count, {});
  for (u32 source = 0; source < count; ++source) {
    for (u32 destination : successors[source]) {
      const int id = component[source];
      if (id != component[destination] || !cyclic[static_cast<u32>(id)])
        continue;

      /*
       * Guard every non-increasing edge inside a cyclic SCC. Every directed
       * cycle contains at least one such edge: block indices cannot increase
       * strictly all the way around a closed path. Therefore removing these
       * guarded edges makes every SCC acyclic, including cycles formed by an
       * indirect LR/CTR continuation. This is the completeness invariant the
       * old inferred loop-header scan lacked.
       */
      if (destination <= source)
        guarded_successors_[source].push_back(destination);
    }
  }
}

bool FunctionEmitter::needsCycleGuard(u32 source, u32 destination) const {
  if (source >= guarded_successors_.size())
    return false;
  const auto &destinations = guarded_successors_[source];
  return std::find(destinations.begin(), destinations.end(), destination) !=
         destinations.end();
}

BasicBlock *FunctionEmitter::cycleGuardDestination(u32 source,
                                                   u32 destination) {
  if (!needsCycleGuard(source, destination))
    return blocks_[destination];

  BasicBlock *guard = BasicBlock::Create(context_, "cycle_guard", function_);
  const IRBuilderBase::InsertPoint saved = builder_.saveIP();
  builder_.SetInsertPoint(guard);
  emitBudgetGuard(source_.blocks[destination].guest_address);
  builder_.CreateBr(blocks_[destination]);
  builder_.restoreIP(saved);
  return guard;
}

void FunctionEmitter::emitEntry() {
  builder_.SetInsertPoint(entry_);
  for (u32 slot = 0; slot < DOLIR_STATE_COUNT; slot++) {
    if (!used_[slot])
      continue;
    auto stateSlot = static_cast<DolIRStateSlot>(slot);
    state_[slot] = builder_.CreateAlloca(type(dolir_state_type(stateSlot)),
                                         nullptr, "state");
    builder_.CreateStore(loadContext(stateSlot), state_[slot]);
  }
  cycles_ =
      builder_.CreateAlloca(Type::getInt64Ty(context_), nullptr, "cycles");
  builder_.CreateStore(ConstantInt::get(Type::getInt64Ty(context_), 0),
                       cycles_);
  Value *pc = loadOffset(Type::getInt32Ty(context_), offsetof(CPUState, pc));
  BasicBlock *bad = BasicBlock::Create(context_, "entry_miss", function_);
  auto *dispatch = builder_.CreateSwitch(pc, bad, source_.block_count);
  for (u32 i = 0; i < source_.block_count; i++)
    dispatch->addCase(ConstantInt::get(Type::getInt32Ty(context_),
                                       source_.blocks[i].guest_address),
                      blocks_[i]);
  builder_.SetInsertPoint(bad);
  builder_.CreateRetVoid();
}

void FunctionEmitter::chargeCycles(u32 cycles) {
  Value *old = builder_.CreateLoad(Type::getInt64Ty(context_), cycles_);
  Value *next = builder_.CreateAdd(
      old, ConstantInt::get(Type::getInt64Ty(context_), cycles));
  builder_.CreateStore(next, cycles_);

  // The scheduler budget lives in CPUState, so helper/MMIO boundaries which
  // materialize and clear the local cycle accumulator cannot reset it.
  Value *budget = loadOffset(Type::getInt64Ty(context_),
                             offsetof(CPUState, native_cycle_budget));
  builder_.CreateStore(
      builder_.CreateSub(
          budget, ConstantInt::get(Type::getInt64Ty(context_), cycles)),
      bytePtr(offsetof(CPUState, native_cycle_budget)));
}

void FunctionEmitter::materialize(u32 pc) {
  for (u32 slot = 0; slot < DOLIR_STATE_COUNT; slot++) {
    if (!dirty_[slot])
      continue;
    auto stateSlot = static_cast<DolIRStateSlot>(slot);
    storeContext(
        stateSlot,
        builder_.CreateLoad(type(dolir_state_type(stateSlot)), state_[slot]));
  }
  storeContext(DOLIR_STATE_PC,
               ConstantInt::get(Type::getInt32Ty(context_), pc));
  Value *downcount =
      loadOffset(Type::getInt64Ty(context_), offsetof(CPUState, downcount));
  Value *cycles = builder_.CreateLoad(Type::getInt64Ty(context_), cycles_);
  builder_.CreateStore(builder_.CreateSub(downcount, cycles),
                       bytePtr(offsetof(CPUState, downcount)));
}

void FunctionEmitter::sideExit(u32 pc) {
  materialize(pc);
  builder_.CreateRetVoid();
}

void FunctionEmitter::emitBudgetGuard(u32 pc) {
  Value *cycleBudget = loadOffset(Type::getInt64Ty(context_),
                                  offsetof(CPUState, native_cycle_budget));
  Value *guardBudget = loadOffset(Type::getInt32Ty(context_),
                                  offsetof(CPUState, native_guard_budget));
  Value *cyclesExhausted = builder_.CreateICmpSLE(
      cycleBudget, ConstantInt::get(Type::getInt64Ty(context_), 0));
  Value *guardsExhausted = builder_.CreateICmpEQ(
      guardBudget, ConstantInt::get(Type::getInt32Ty(context_), 0));
  Value *exhausted = builder_.CreateOr(cyclesExhausted, guardsExhausted);

  BasicBlock *run = BasicBlock::Create(context_, "budget_run", function_);
  BasicBlock *exit = BasicBlock::Create(context_, "budget_exit", function_);

  builder_.CreateCondBr(exhausted, exit, run);

  builder_.SetInsertPoint(exit);
  sideExit(pc);

  builder_.SetInsertPoint(run);
  builder_.CreateStore(
      builder_.CreateSub(
          guardBudget, ConstantInt::get(Type::getInt32Ty(context_), 1)),
      bytePtr(offsetof(CPUState, native_guard_budget)));
}

bool FunctionEmitter::emitBlock(u32 index, raw_ostream &diagnostics) {
  const DolIRBlock &block = source_.blocks[index];
  builder_.SetInsertPoint(blocks_[index]);
  chargeCycles(block.cycle_cost);
  values_.assign(source_.value_count, nullptr);
  for (u32 i = 0; i < block.instruction_count; i++) {
    if (!emitInstruction(block.instructions[i], diagnostics))
      return false;
  }
  return emitTerminator(block.terminator, diagnostics);
}

Value *FunctionEmitter::operand(const DolIRInstruction &inst, u32 index) {
  return values_[inst.operands[index]];
}

Value *FunctionEmitter::castValue(DolIROp op, Type *resultType, Value *value) {
  switch (op) {
  case DOLIR_OP_TRUNC:
    return builder_.CreateTrunc(value, resultType);
  case DOLIR_OP_ZEXT:
    return builder_.CreateZExt(value, resultType);
  case DOLIR_OP_SEXT:
    return builder_.CreateSExt(value, resultType);
  case DOLIR_OP_BITCAST:
    return builder_.CreateBitCast(value, resultType);
  case DOLIR_OP_FPTRUNC:
    return builder_.CreateFPTrunc(value, resultType);
  case DOLIR_OP_FPEXT:
    return builder_.CreateFPExt(value, resultType);
  default:
    return nullptr;
  }
}

Value *FunctionEmitter::bswap(Value *value) {
  auto *integer = cast<IntegerType>(value->getType());
  if (integer->getBitWidth() == 8)
    return value;
  Function *intrinsic =
      Intrinsic::getDeclaration(&module_, Intrinsic::bswap, {value->getType()});
  return builder_.CreateCall(intrinsic, {value});
}

bool FunctionEmitter::emitInstruction(const DolIRInstruction &inst,
                                      raw_ostream &diagnostics) {
  current_pc_ = inst.guest_pc;
  Value *result = nullptr;
  Type *resultType = type(inst.type);
  switch (inst.op) {
  case DOLIR_OP_CONSTANT:
    if (inst.type == DOLIR_TYPE_F32)
      result = ConstantFP::get(
          context_, APFloat(APFloat::IEEEsingle(), APInt(32, inst.immediate)));
    else if (inst.type == DOLIR_TYPE_F64)
      result = ConstantFP::get(
          context_, APFloat(APFloat::IEEEdouble(), APInt(64, inst.immediate)));
    else
      result = ConstantInt::get(resultType, inst.immediate);
    break;
  case DOLIR_OP_STATE_READ:
    result = builder_.CreateLoad(resultType, state_[inst.aux]);
    break;
  case DOLIR_OP_STATE_WRITE:
    builder_.CreateStore(operand(inst, 0), state_[inst.aux]);
    break;
  case DOLIR_OP_ADD:
    result = builder_.CreateAdd(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_SUB:
    result = builder_.CreateSub(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_MUL:
    result = builder_.CreateMul(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_UDIV:
    result = builder_.CreateUDiv(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_SDIV:
    result = builder_.CreateSDiv(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_AND:
    result = builder_.CreateAnd(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_OR:
    result = builder_.CreateOr(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_XOR:
    result = builder_.CreateXor(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_NOT:
    result = builder_.CreateNot(operand(inst, 0));
    break;
  case DOLIR_OP_SHL:
    result = builder_.CreateShl(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_LSHR:
    result = builder_.CreateLShr(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ASHR:
    result = builder_.CreateAShr(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ROTL: {
    Function *intrinsic =
        Intrinsic::getDeclaration(&module_, Intrinsic::fshl, {resultType});
    result = builder_.CreateCall(
        intrinsic, {operand(inst, 0), operand(inst, 0), operand(inst, 1)});
    break;
  }
  case DOLIR_OP_CLZ: {
    Function *intrinsic =
        Intrinsic::getDeclaration(&module_, Intrinsic::ctlz, {resultType});
    result = builder_.CreateCall(
        intrinsic, {operand(inst, 0), ConstantInt::getFalse(context_)});
    break;
  }
  case DOLIR_OP_BSWAP:
    result = bswap(operand(inst, 0));
    break;
  case DOLIR_OP_TRUNC:
  case DOLIR_OP_ZEXT:
  case DOLIR_OP_SEXT:
  case DOLIR_OP_BITCAST:
  case DOLIR_OP_FPTRUNC:
  case DOLIR_OP_FPEXT:
    result = castValue(inst.op, resultType, operand(inst, 0));
    break;
  case DOLIR_OP_ICMP_EQ:
    result = builder_.CreateICmpEQ(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ICMP_NE:
    result = builder_.CreateICmpNE(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ICMP_ULT:
    result = builder_.CreateICmpULT(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ICMP_ULE:
    result = builder_.CreateICmpULE(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ICMP_SLT:
    result = builder_.CreateICmpSLT(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_ICMP_SLE:
    result = builder_.CreateICmpSLE(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FCMP_OEQ:
    result = builder_.CreateFCmpOEQ(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FCMP_OLT:
    result = builder_.CreateFCmpOLT(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FCMP_OGE:
    result = builder_.CreateFCmpOGE(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_SELECT:
    result = builder_.CreateSelect(operand(inst, 0), operand(inst, 1),
                                   operand(inst, 2));
    break;
  case DOLIR_OP_FADD:
    result = builder_.CreateFAdd(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FSUB:
    result = builder_.CreateFSub(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FMUL:
    result = builder_.CreateFMul(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FDIV:
    result = builder_.CreateFDiv(operand(inst, 0), operand(inst, 1));
    break;
  case DOLIR_OP_FNEG:
    result = builder_.CreateFNeg(operand(inst, 0));
    break;
  case DOLIR_OP_FABS: {
    Function *intrinsic =
        Intrinsic::getDeclaration(&module_, Intrinsic::fabs, {resultType});
    result = builder_.CreateCall(intrinsic, {operand(inst, 0)});
    break;
  }
  case DOLIR_OP_VECTOR_BUILD: {
    result = PoisonValue::get(resultType);
    result =
        builder_.CreateInsertElement(result, operand(inst, 0), uint64_t{0});
    result = builder_.CreateInsertElement(result, operand(inst, 1), 1u);
    break;
  }
  case DOLIR_OP_VECTOR_EXTRACT:
    result = builder_.CreateExtractElement(operand(inst, 0), inst.aux);
    break;
  case DOLIR_OP_VECTOR_SHUFFLE:
    result = builder_.CreateShuffleVector(
        operand(inst, 0), operand(inst, 1),
        {static_cast<int>(inst.aux & 0xFFu),
         static_cast<int>((inst.aux >> 8) & 0xFFu)});
    break;
  case DOLIR_OP_GUEST_LOAD:
    result = emitGuestLoad(operand(inst, 0), resultType, inst.aux & 0xffu,
                           (inst.aux & 0x100u) != 0);
    break;
  case DOLIR_OP_GUEST_STORE:
    emitGuestStore(operand(inst, 0), operand(inst, 1), inst.aux & 0xffu);
    break;
  case DOLIR_OP_HELPER_CALL:
    if (inst.aux == DOLIR_HELPER_FP_AVAILABLE)
      result = emitFPAvailable(inst.guest_pc);
    else if (inst.aux == DOLIR_HELPER_MEMORY_FENCE)
      builder_.CreateFence(AtomicOrdering::SequentiallyConsistent);
    else if (inst.aux == DOLIR_HELPER_EXACT_FLOAT)
      emitExactFloat(inst.immediate);
    else if (inst.aux == DOLIR_HELPER_EXACT_PAIRED)
      emitExactPaired(inst.immediate);
    else if (inst.aux == DOLIR_HELPER_PSQ_LOAD ||
             inst.aux == DOLIR_HELPER_PSQ_STORE)
      result = emitPSQ(inst);
    else if (inst.aux == DOLIR_HELPER_STORE_CONDITIONAL)
      emitStoreConditional(inst);
    else if (inst.aux == DOLIR_HELPER_FPSCR_UPDATED)
      emitFPSCRUpdated();
    else if (inst.aux == DOLIR_HELPER_FPSCR_BIT)
      emitFPSCRBit(inst.immediate);
    else if (inst.aux == DOLIR_HELPER_PROGRAM_EXCEPTION)
      emitProgramException(inst);
    else if (inst.aux == DOLIR_HELPER_SPR_READ)
      result = emitSPRRead(inst);
    else if (inst.aux == DOLIR_HELPER_SPR_WRITE)
      emitSPRWrite(inst);
    else if (inst.aux == DOLIR_HELPER_LSWX)
      emitLSWX(inst);
    else if (inst.aux == DOLIR_HELPER_DCBZ_L ||
             inst.aux == DOLIR_HELPER_ECIWX || inst.aux == DOLIR_HELPER_ECOWX ||
             inst.aux == DOLIR_HELPER_TLBIE ||
             inst.aux == DOLIR_HELPER_CACHE_CONTROL)
      result = emitRuntimeBoundary(inst);
    else {
      diagnostics << "dolllvm: unsupported helper " << inst.aux << " at 0x"
                  << format_hex_no_prefix(inst.guest_pc, 8) << "\n";
      return false;
    }
    break;
  default:
    diagnostics << "dolllvm: unsupported DolIR op " << unsigned(inst.op)
                << " at 0x" << format_hex_no_prefix(inst.guest_pc, 8) << "\n";
    return false;
  }
  if (inst.result)
    values_[inst.result] = result;
  return inst.type == DOLIR_TYPE_VOID || result != nullptr;
}

} // namespace dolllvm
