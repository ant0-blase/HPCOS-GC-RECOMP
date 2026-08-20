// SPDX-License-Identifier: GPL-3.0-or-later

#include "backend/c_cfg.h"

#include <stdlib.h>
#include <string.h>

static bool instruction_uses_fallback(const PPCInst* inst) {
    switch (inst->op) {
    /*
     * dcbst/dcbf/dcbi/icbi are emitted inline through the cache_control hook
     * rather than handed to the interpreter. They were the entirety of the
     * interpreter traffic -- 15.1M calls in a 45s session, 72% of them dcbf --
     * and each one also ended the block, so every single one cost a dispatcher
     * round trip on top of the hook. They cannot fault on memory and only
     * dcbi can raise (privilege), which ppc_cache_control handles.
     */
    case PPC_OP_UNKNOWN:
        return true;
    /*
     * Every mfspr/mtspr is emitted inline: the ones the module models directly
     * stay direct, and the rest go through ppc_mfspr/ppc_mtspr, which route to
     * the chassis SPR hooks and raise the privilege/illegal exceptions
     * themselves. Nothing here needs the interpreter.
     */
    case PPC_OP_MFSPR:
    case PPC_OP_MTSPR:
        return false;
    default:
        return false;
    }
}

static bool instruction_ends_block(const PPCInst* inst) {
    switch (inst->op) {
    case PPC_OP_B:
    case PPC_OP_BC:
    case PPC_OP_BCLR:
    case PPC_OP_BCCTR:
    case PPC_OP_SC:
    case PPC_OP_RFI:
        return true;
    default:
        return instruction_uses_fallback(inst);
    }
}

static u32 instruction_cycles(const PPCInst* inst) {
    if (inst->embedded_data || instruction_uses_fallback(inst))
        return 0;

    switch (inst->op) {
    case PPC_OP_MULLI:
        return 3;
    case PPC_OP_SC:
    case PPC_OP_RFI:
    case PPC_OP_TW:
        return 2;
    case PPC_OP_LMW:
    case PPC_OP_STMW:
        return 11;
    case PPC_OP_MULLW:
    case PPC_OP_MULLWO:
    case PPC_OP_MULHW:
    case PPC_OP_MULHWU:
        return 5;
    case PPC_OP_DIVW:
    case PPC_OP_DIVWO:
    case PPC_OP_DIVWU:
    case PPC_OP_DIVWUO:
        return 40;
    case PPC_OP_DCBZ:
        return 5;
    /* Dolphin's PPCTables costs, previously charged by the fallback hook. */
    case PPC_OP_DCBST:
    case PPC_OP_DCBF:
    case PPC_OP_DCBI:
        return 5;
    case PPC_OP_ICBI:
        return 4;
    case PPC_OP_DCBTST:
    case PPC_OP_DCBT:
        return 2;
    case PPC_OP_MFSR:
    case PPC_OP_MFSRIN:
        return 3;
    case PPC_OP_MTSPR:
        return 2;
    case PPC_OP_SYNC:
        return 3;
    case PPC_OP_MTFSB0:
    case PPC_OP_MTFSB1:
    case PPC_OP_MTFSF:
    case PPC_OP_MTFSFI:
        return 3;
    case PPC_OP_FDIVS:
        return 17;
    case PPC_OP_FDIV:
        return 31;
    case PPC_OP_PS_DIV:
        return 17;
    case PPC_OP_PS_RSQRTE:
        return 2;
    default:
        return 1;
    }
}

static bool instruction_is_pc_transparent(const PPCInst* inst) {
    switch (inst->op) {
    case PPC_OP_MULLI:
    case PPC_OP_SUBFIC:
    case PPC_OP_ADDI:
    case PPC_OP_ADDIC:
    case PPC_OP_ADDIC_DOT:
    case PPC_OP_ADDIS:
    case PPC_OP_CMPI:
    case PPC_OP_CMPLI:
    case PPC_OP_CMP:
    case PPC_OP_CMPL:
    case PPC_OP_ORI:
    case PPC_OP_ORIS:
    case PPC_OP_XORI:
    case PPC_OP_XORIS:
    case PPC_OP_ANDI:
    case PPC_OP_ANDIS:
    case PPC_OP_ADD:
    case PPC_OP_ADDC:
    case PPC_OP_ADDE:
    case PPC_OP_ADDME:
    case PPC_OP_ADDZE:
    case PPC_OP_SUBF:
    case PPC_OP_SUBFC:
    case PPC_OP_SUBFE:
    case PPC_OP_SUBFME:
    case PPC_OP_SUBFZE:
    case PPC_OP_NEG:
    case PPC_OP_AND:
    case PPC_OP_ANDC:
    case PPC_OP_OR:
    case PPC_OP_ORC:
    case PPC_OP_XOR:
    case PPC_OP_NAND:
    case PPC_OP_NOR:
    case PPC_OP_EQV:
    case PPC_OP_CNTLZW:
    case PPC_OP_EXTSB:
    case PPC_OP_EXTSH:
    case PPC_OP_SLW:
    case PPC_OP_SRW:
    case PPC_OP_SRAW:
    case PPC_OP_SRAWI:
    case PPC_OP_RLWINM:
    case PPC_OP_RLWNM:
    case PPC_OP_RLWIMI:
    case PPC_OP_MULLW:
    case PPC_OP_MULHW:
    case PPC_OP_MULHWU:
    case PPC_OP_DIVW:
    case PPC_OP_DIVWU:
    case PPC_OP_CRAND:
    case PPC_OP_CRANDC:
    case PPC_OP_CREQV:
    case PPC_OP_CRNAND:
    case PPC_OP_CRNOR:
    case PPC_OP_CROR:
    case PPC_OP_CRORC:
    case PPC_OP_CRXOR:
    case PPC_OP_MCRF:
    case PPC_OP_MFCR:
    case PPC_OP_MTCRF:
    case PPC_OP_B:
    case PPC_OP_BC:
        return true;
    default:
        return false;
    }
}

static bool instruction_is_outlinable(const PPCInst* inst) {
    if (instruction_is_pc_transparent(inst))
        return true;

    switch (inst->op) {
    case PPC_OP_LWZ:
    case PPC_OP_LWZU:
    case PPC_OP_LBZ:
    case PPC_OP_LBZU:
    case PPC_OP_LHZ:
    case PPC_OP_LHZU:
    case PPC_OP_LHA:
    case PPC_OP_LHAU:
    case PPC_OP_STW:
    case PPC_OP_STWU:
    case PPC_OP_STB:
    case PPC_OP_STBU:
    case PPC_OP_STH:
    case PPC_OP_STHU:
    case PPC_OP_LWZX:
    case PPC_OP_LWZUX:
    case PPC_OP_LBZX:
    case PPC_OP_LBZUX:
    case PPC_OP_LHZX:
    case PPC_OP_LHZUX:
    case PPC_OP_LHAX:
    case PPC_OP_LHAUX:
    case PPC_OP_LWBRX:
    case PPC_OP_LHBRX:
    case PPC_OP_STWX:
    case PPC_OP_STWUX:
    case PPC_OP_STBX:
    case PPC_OP_STBUX:
    case PPC_OP_STHX:
    case PPC_OP_STHUX:
    case PPC_OP_STWBRX:
    case PPC_OP_STHBRX:
        return true;
    default:
        return false;
    }
}

bool c_function_cfg_contains(const CFunctionCFG* cfg, u32 function_address,
                             u32 address) {
    u32 end = function_address + cfg->count * 4u;
    return address >= function_address && address < end &&
           ((address - function_address) & 3u) == 0;
}

bool c_function_cfg_build(CFunctionCFG* cfg, const PPCInst* insts, u32 count,
                          u32 function_address) {
    memset(cfg, 0, sizeof(*cfg));
    cfg->count = count;
    cfg->leaders = (u8*)calloc(count ? count : 1u, sizeof(*cfg->leaders));
    cfg->block_cycles =
        (u32*)calloc(count ? count : 1u, sizeof(*cfg->block_cycles));
    cfg->materialize_pc =
        (u8*)malloc((count ? count : 1u) * sizeof(*cfg->materialize_pc));
    cfg->return_targets =
        (u8*)calloc(count ? count : 1u, sizeof(*cfg->return_targets));
    cfg->loop_ends =
        (u32*)malloc((count ? count : 1u) * sizeof(*cfg->loop_ends));
    if (!cfg->leaders || !cfg->block_cycles || !cfg->materialize_pc ||
        !cfg->return_targets || !cfg->loop_ends) {
        c_function_cfg_destroy(cfg);
        return false;
    }
    memset(cfg->materialize_pc, 1, count ? count : 1u);
    for (u32 i = 0; i < (count ? count : 1u); ++i)
        cfg->loop_ends[i] = UINT32_MAX;

    if (count)
        cfg->leaders[0] = 1;

    for (u32 i = 0; i < count; ++i) {
        const PPCInst* inst = &insts[i];
        if (inst->embedded_data)
            continue;
        if (instruction_ends_block(inst) && i + 1u < count)
            cfg->leaders[i + 1u] = 1;
        if (inst->lk && i + 1u < count)
            cfg->return_targets[i + 1u] = 1;
        if ((inst->op == PPC_OP_B || inst->op == PPC_OP_BC) &&
            c_function_cfg_contains(cfg, function_address,
                                    inst->branch_target)) {
            cfg->leaders[(inst->branch_target - function_address) / 4u] = 1;
        }
    }

    for (u32 i = 0; i < count; ++i) {
        if (!cfg->leaders[i])
            continue;
        for (u32 j = i; j < count; ++j) {
            cfg->block_cycles[i] += instruction_cycles(&insts[j]);
            if (instruction_ends_block(&insts[j]) || j + 1u == count ||
                cfg->leaders[j + 1u]) {
                break;
            }
        }
    }

    /*
     * Drop the ctx->pc store ahead of every PC-transparent instruction, not
     * just the ones inside a directly-looping block.
     *
     * materialize_pc starts as all-ones, and instruction_is_pc_transparent only
     * accepts pure ALU forms: no memory access, no branch, no trap, no SPR or
     * cache op. Everything that can fault, redirect control flow or hand back
     * to the dispatcher therefore still writes its own address before running,
     * which is the invariant the loop case above already relied on -- this only
     * widens its scope from loop bodies to whole functions.
     *
     * It matters because the store is pure overhead paid per guest instruction:
     * the emitted chunks carried roughly 3700 of them per 4200 guest
     * instructions before this ran.
     */
    for (u32 i = 0; i < count; ++i) {
        if (!insts[i].embedded_data && instruction_is_pc_transparent(&insts[i]))
            cfg->materialize_pc[i] = 0;
    }

    for (u32 last = 0; last < count; ++last) {
        if (!c_function_cfg_can_loop_directly(cfg, insts, function_address,
                                              last)) {
            continue;
        }
        u32 first =
            (insts[last].branch_target - function_address) / 4u;

        bool straight_line = true;
        bool outlinable = true;
        for (u32 i = first; i < last; ++i)
            straight_line &= !instruction_ends_block(&insts[i]);
        for (u32 i = first; i <= last; ++i)
            outlinable &= instruction_is_outlinable(&insts[i]);
        if (straight_line && outlinable && first < last)
            cfg->loop_ends[first] = last;
    }
    return true;
}

void c_function_cfg_destroy(CFunctionCFG* cfg) {
    free(cfg->leaders);
    free(cfg->block_cycles);
    free(cfg->materialize_pc);
    free(cfg->return_targets);
    free(cfg->loop_ends);
    memset(cfg, 0, sizeof(*cfg));
}

bool c_function_cfg_can_loop_directly(const CFunctionCFG* cfg,
                                      const PPCInst* insts,
                                      u32 function_address,
                                      u32 branch_index) {
    const PPCInst* branch = &insts[branch_index];
    if ((branch->op != PPC_OP_B && branch->op != PPC_OP_BC) ||
        branch->lk ||
        !c_function_cfg_contains(cfg, function_address, branch->branch_target) ||
        branch->branch_target > branch->address) {
        return false;
    }

    u32 first = (branch->branch_target - function_address) / 4u;
    for (u32 i = first; i <= branch_index; ++i) {
        if (insts[i].op == PPC_OP_MFTB ||
            (insts[i].op == PPC_OP_MFSPR &&
             (insts[i].spr == 268 || insts[i].spr == 269))) {
            return false;
        }
    }
    return true;
}
