// DolRecomp output
#include "../generated.h"

static void loop_8018762C(CPUState* ctx) {
label_8018762C:
    ctx->downcount -= 7;
    ctx->pc = 0x8018762Cu;
    // 8018762C: lhz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 80187630: or   r6, r7, r7
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[7];
    }

    ctx->pc = 0x80187634u;
    // 80187634: lhz     r3, 46(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(46);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 80187638: rlwinm r7, r0, 0, 21, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

    // 8018763C: cmplw   r6, r7
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80187640: rlwinm r6, r3, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000007FFu;
    }

    // 80187644: bc    4, 2, 0x8018762C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018762Cu;
                return;
            }
            goto label_8018762C;
        }
    }

    ctx->pc = 0x80187648u;
}

static void loop_8018767C(CPUState* ctx) {
label_8018767C:
    ctx->downcount -= 7;
    ctx->pc = 0x8018767Cu;
    // 8018767C: lhz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 80187680: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

    ctx->pc = 0x80187684u;
    // 80187684: lhz     r3, 46(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(46);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 80187688: rlwinm r5, r0, 0, 21, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

    // 8018768C: cmplw   r6, r5
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80187690: rlwinm r3, r3, 0, 21, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000007FFu;
    }

    // 80187694: bc    4, 2, 0x8018767C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018767Cu;
                return;
            }
            goto label_8018767C;
        }
    }

    ctx->pc = 0x80187698u;
}

static void loop_801876F8(CPUState* ctx) {
label_801876F8:
    ctx->downcount -= 7;
    ctx->pc = 0x801876F8u;
    // 801876F8: lhz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 801876FC: or   r7, r6, r6
    {
        ctx->gpr[7] = ctx->gpr[6] | ctx->gpr[6];
    }

    ctx->pc = 0x80187700u;
    // 80187700: lhz     r4, 46(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(46);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    // 80187704: rlwinm r6, r0, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

    // 80187708: cmplw   r7, r6
    {
        u32 val_a = (u32)(ctx->gpr[7]);
        u32 val_b = (u32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8018770C: rlwinm r4, r4, 0, 21, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000007FFu;
    }

    // 80187710: bc    4, 2, 0x801876F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801876F8u;
                return;
            }
            goto label_801876F8;
        }
    }

    ctx->pc = 0x80187714u;
}

static void loop_801877A8(CPUState* ctx) {
label_801877A8:
    ctx->downcount -= 7;
    ctx->pc = 0x801877A8u;
    // 801877A8: lhz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 801877AC: or   r7, r6, r6
    {
        ctx->gpr[7] = ctx->gpr[6] | ctx->gpr[6];
    }

    ctx->pc = 0x801877B0u;
    // 801877B0: lhz     r4, 46(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(46);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    // 801877B4: rlwinm r6, r0, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

    // 801877B8: cmplw   r7, r6
    {
        u32 val_a = (u32)(ctx->gpr[7]);
        u32 val_b = (u32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801877BC: rlwinm r7, r4, 0, 21, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000007FFu;
    }

    // 801877C0: bc    4, 2, 0x801877A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801877A8u;
                return;
            }
            goto label_801877A8;
        }
    }

    ctx->pc = 0x801877C4u;
}

static void loop_80187E60(CPUState* ctx) {
label_80187E60:
    ctx->downcount -= 41;
    // 80187E60: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

    ctx->pc = 0x80187E64u;
    // 80187E64: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E68u;
    // 80187E68: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E6Cu;
    // 80187E6C: stb     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E70u;
    // 80187E70: stb     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E74u;
    // 80187E74: stb     r0, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E78u;
    // 80187E78: stb     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E7Cu;
    // 80187E7C: stb     r0, 7(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E80u;
    // 80187E80: stb     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E84u;
    // 80187E84: stb     r0, 9(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E88u;
    // 80187E88: stb     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E8Cu;
    // 80187E8C: sth     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E90u;
    // 80187E90: sth     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E94u;
    // 80187E94: sth     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E98u;
    // 80187E98: sth     r0, 18(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(18);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187E9Cu;
    // 80187E9C: sth     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EA0u;
    // 80187EA0: sth     r0, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EA4u;
    // 80187EA4: sth     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EA8u;
    // 80187EA8: sth     r0, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EACu;
    // 80187EAC: sth     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EB0u;
    // 80187EB0: sth     r0, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EB4u;
    // 80187EB4: stb     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EB8u;
    // 80187EB8: stb     r0, 33(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(33);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EBCu;
    // 80187EBC: stb     r0, 34(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(34);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EC0u;
    // 80187EC0: stb     r0, 35(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(35);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EC4u;
    // 80187EC4: stb     r0, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EC8u;
    // 80187EC8: stb     r0, 37(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(37);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187ECCu;
    // 80187ECC: stb     r0, 38(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(38);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187ED0u;
    // 80187ED0: stb     r0, 39(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(39);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187ED4u;
    // 80187ED4: stb     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x80187ED8u;
    // 80187ED8: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EDCu;
    // 80187EDC: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EE0u;
    // 80187EE0: sth     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EE4u;
    // 80187EE4: sth     r0, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EE8u;
    // 80187EE8: sth     r0, 50(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EECu;
    // 80187EEC: sth     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EF0u;
    // 80187EF0: sth     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EF4u;
    // 80187EF4: sth     r0, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x80187EF8u;
    // 80187EF8: sth     r0, 58(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(58);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    // 80187EFC: addi    r3, r3, 60
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(60);

    // 80187F00: bc    16, 0, 0x80187E60
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187E60u;
                return;
            }
            goto label_80187E60;
        }
    }

    ctx->pc = 0x80187F04u;
}

static void loop_8018A8E8(CPUState* ctx) {
label_8018A8E8:
    ctx->downcount -= 3;
    ctx->pc = 0x8018A8E8u;
    // 8018A8E8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8018A8EC: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8018A8F0: bc    12, 2, 0x8018A8E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A8E8u;
                return;
            }
            goto label_8018A8E8;
        }
    }

    ctx->pc = 0x8018A8F4u;
}

static void loop_8018A92C(CPUState* ctx) {
label_8018A92C:
    ctx->downcount -= 3;
    ctx->pc = 0x8018A92Cu;
    // 8018A92C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8018A930: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8018A934: bc    12, 2, 0x8018A92C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A92Cu;
                return;
            }
            goto label_8018A92C;
        }
    }

    ctx->pc = 0x8018A938u;
}

static void loop_8018AED8(CPUState* ctx) {
label_8018AED8:
    ctx->downcount -= 3;
    ctx->pc = 0x8018AED8u;
    // 8018AED8: lhz     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 8018AEDC: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8018AEE0: bc    4, 2, 0x8018AED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018AED8u;
                return;
            }
            goto label_8018AED8;
        }
    }

    ctx->pc = 0x8018AEE4u;
}

static void loop_8018AF70(CPUState* ctx) {
label_8018AF70:
    ctx->downcount -= 4;
    // 8018AF70: addi    r4, r6, 20480
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(20480);

    ctx->pc = 0x8018AF74u;
    // 8018AF74: lhzu     r0, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

    // 8018AF78: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8018AF7C: bc    4, 2, 0x8018AF70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018AF70u;
                return;
            }
            goto label_8018AF70;
        }
    }

    ctx->pc = 0x8018AF80u;
}

static void loop_8018B020(CPUState* ctx) {
label_8018B020:
    ctx->downcount -= 4;
    // 8018B020: addi    r4, r6, 20480
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(20480);

    ctx->pc = 0x8018B024u;
    // 8018B024: lhzu     r0, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

    // 8018B028: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8018B02C: bc    4, 2, 0x8018B020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B020u;
                return;
            }
            goto label_8018B020;
        }
    }

    ctx->pc = 0x8018B030u;
}

static void loop_8018B060(CPUState* ctx) {
label_8018B060:
    ctx->downcount -= 3;
    ctx->pc = 0x8018B060u;
    // 8018B060: lhz     r0, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 8018B064: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8018B068: bc    12, 2, 0x8018B060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B060u;
                return;
            }
            goto label_8018B060;
        }
    }

    ctx->pc = 0x8018B06Cu;
}

static void loop_8018B1B0(CPUState* ctx) {
label_8018B1B0:
    ctx->downcount -= 4;
    // 8018B1B0: addi    r31, r22, 20480
    ctx->gpr[31] = ctx->gpr[22] + (u32)(s32)(20480);

    ctx->pc = 0x8018B1B4u;
    // 8018B1B4: lhzu     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[31] = ea;
    }

    // 8018B1B8: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8018B1BC: bc    4, 2, 0x8018B1B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B1B0u;
                return;
            }
            goto label_8018B1B0;
        }
    }

    ctx->pc = 0x8018B1C0u;
}

static void loop_8018B25C(CPUState* ctx) {
label_8018B25C:
    ctx->downcount -= 3;
    ctx->pc = 0x8018B25Cu;
    // 8018B25C: lhz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 8018B260: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8018B264: bc    4, 2, 0x8018B25C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B25Cu;
                return;
            }
            goto label_8018B25C;
        }
    }

    ctx->pc = 0x8018B268u;
}

void func_801872C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x801872C0u: goto label_801872C0;
    case 0x801872C4u: goto label_801872C4;
    case 0x801872C8u: goto label_801872C8;
    case 0x801872CCu: goto label_801872CC;
    case 0x801872D0u: goto label_801872D0;
    case 0x801872D4u: goto label_801872D4;
    case 0x801872D8u: goto label_801872D8;
    case 0x801872DCu: goto label_801872DC;
    case 0x801872E0u: goto label_801872E0;
    case 0x801872E4u: goto label_801872E4;
    case 0x801872E8u: goto label_801872E8;
    case 0x801872ECu: goto label_801872EC;
    case 0x801872F0u: goto label_801872F0;
    case 0x801872F4u: goto label_801872F4;
    case 0x801872F8u: goto label_801872F8;
    case 0x801872FCu: goto label_801872FC;
    case 0x80187300u: goto label_80187300;
    case 0x80187304u: goto label_80187304;
    case 0x80187308u: goto label_80187308;
    case 0x8018730Cu: goto label_8018730C;
    case 0x80187310u: goto label_80187310;
    case 0x80187314u: goto label_80187314;
    case 0x80187318u: goto label_80187318;
    case 0x8018731Cu: goto label_8018731C;
    case 0x80187320u: goto label_80187320;
    case 0x80187324u: goto label_80187324;
    case 0x80187328u: goto label_80187328;
    case 0x8018732Cu: goto label_8018732C;
    case 0x80187330u: goto label_80187330;
    case 0x80187334u: goto label_80187334;
    case 0x80187338u: goto label_80187338;
    case 0x8018733Cu: goto label_8018733C;
    case 0x80187340u: goto label_80187340;
    case 0x80187344u: goto label_80187344;
    case 0x80187348u: goto label_80187348;
    case 0x8018734Cu: goto label_8018734C;
    case 0x80187350u: goto label_80187350;
    case 0x80187354u: goto label_80187354;
    case 0x80187358u: goto label_80187358;
    case 0x8018735Cu: goto label_8018735C;
    case 0x80187360u: goto label_80187360;
    case 0x80187364u: goto label_80187364;
    case 0x80187368u: goto label_80187368;
    case 0x8018736Cu: goto label_8018736C;
    case 0x80187370u: goto label_80187370;
    case 0x80187374u: goto label_80187374;
    case 0x80187378u: goto label_80187378;
    case 0x8018737Cu: goto label_8018737C;
    case 0x80187380u: goto label_80187380;
    case 0x80187384u: goto label_80187384;
    case 0x80187388u: goto label_80187388;
    case 0x8018738Cu: goto label_8018738C;
    case 0x80187390u: goto label_80187390;
    case 0x80187394u: goto label_80187394;
    case 0x80187398u: goto label_80187398;
    case 0x8018739Cu: goto label_8018739C;
    case 0x801873A0u: goto label_801873A0;
    case 0x801873A4u: goto label_801873A4;
    case 0x801873A8u: goto label_801873A8;
    case 0x801873ACu: goto label_801873AC;
    case 0x801873B0u: goto label_801873B0;
    case 0x801873B4u: goto label_801873B4;
    case 0x801873B8u: goto label_801873B8;
    case 0x801873BCu: goto label_801873BC;
    case 0x801873C0u: goto label_801873C0;
    case 0x801873C4u: goto label_801873C4;
    case 0x801873C8u: goto label_801873C8;
    case 0x801873CCu: goto label_801873CC;
    case 0x801873D0u: goto label_801873D0;
    case 0x801873D4u: goto label_801873D4;
    case 0x801873D8u: goto label_801873D8;
    case 0x801873DCu: goto label_801873DC;
    case 0x801873E0u: goto label_801873E0;
    case 0x801873E4u: goto label_801873E4;
    case 0x801873E8u: goto label_801873E8;
    case 0x801873ECu: goto label_801873EC;
    case 0x801873F0u: goto label_801873F0;
    case 0x801873F4u: goto label_801873F4;
    case 0x801873F8u: goto label_801873F8;
    case 0x801873FCu: goto label_801873FC;
    case 0x80187400u: goto label_80187400;
    case 0x80187404u: goto label_80187404;
    case 0x80187408u: goto label_80187408;
    case 0x8018740Cu: goto label_8018740C;
    case 0x80187410u: goto label_80187410;
    case 0x80187414u: goto label_80187414;
    case 0x80187418u: goto label_80187418;
    case 0x8018741Cu: goto label_8018741C;
    case 0x80187420u: goto label_80187420;
    case 0x80187424u: goto label_80187424;
    case 0x80187428u: goto label_80187428;
    case 0x8018742Cu: goto label_8018742C;
    case 0x80187430u: goto label_80187430;
    case 0x80187434u: goto label_80187434;
    case 0x80187438u: goto label_80187438;
    case 0x8018743Cu: goto label_8018743C;
    case 0x80187440u: goto label_80187440;
    case 0x80187444u: goto label_80187444;
    case 0x80187448u: goto label_80187448;
    case 0x8018744Cu: goto label_8018744C;
    case 0x80187450u: goto label_80187450;
    case 0x80187454u: goto label_80187454;
    case 0x80187458u: goto label_80187458;
    case 0x8018745Cu: goto label_8018745C;
    case 0x80187460u: goto label_80187460;
    case 0x80187464u: goto label_80187464;
    case 0x80187468u: goto label_80187468;
    case 0x8018746Cu: goto label_8018746C;
    case 0x80187470u: goto label_80187470;
    case 0x80187474u: goto label_80187474;
    case 0x80187478u: goto label_80187478;
    case 0x8018747Cu: goto label_8018747C;
    case 0x80187480u: goto label_80187480;
    case 0x80187484u: goto label_80187484;
    case 0x80187488u: goto label_80187488;
    case 0x8018748Cu: goto label_8018748C;
    case 0x80187490u: goto label_80187490;
    case 0x80187494u: goto label_80187494;
    case 0x80187498u: goto label_80187498;
    case 0x8018749Cu: goto label_8018749C;
    case 0x801874A0u: goto label_801874A0;
    case 0x801874A4u: goto label_801874A4;
    case 0x801874A8u: goto label_801874A8;
    case 0x801874ACu: goto label_801874AC;
    case 0x801874B0u: goto label_801874B0;
    case 0x801874B4u: goto label_801874B4;
    case 0x801874B8u: goto label_801874B8;
    case 0x801874BCu: goto label_801874BC;
    case 0x801874C0u: goto label_801874C0;
    case 0x801874C4u: goto label_801874C4;
    case 0x801874C8u: goto label_801874C8;
    case 0x801874CCu: goto label_801874CC;
    case 0x801874D0u: goto label_801874D0;
    case 0x801874D4u: goto label_801874D4;
    case 0x801874D8u: goto label_801874D8;
    case 0x801874DCu: goto label_801874DC;
    case 0x801874E0u: goto label_801874E0;
    case 0x801874E4u: goto label_801874E4;
    case 0x801874E8u: goto label_801874E8;
    case 0x801874ECu: goto label_801874EC;
    case 0x801874F0u: goto label_801874F0;
    case 0x801874F4u: goto label_801874F4;
    case 0x801874F8u: goto label_801874F8;
    case 0x801874FCu: goto label_801874FC;
    case 0x80187500u: goto label_80187500;
    case 0x80187504u: goto label_80187504;
    case 0x80187508u: goto label_80187508;
    case 0x8018750Cu: goto label_8018750C;
    case 0x80187510u: goto label_80187510;
    case 0x80187514u: goto label_80187514;
    case 0x80187518u: goto label_80187518;
    case 0x8018751Cu: goto label_8018751C;
    case 0x80187520u: goto label_80187520;
    case 0x80187524u: goto label_80187524;
    case 0x80187528u: goto label_80187528;
    case 0x8018752Cu: goto label_8018752C;
    case 0x80187530u: goto label_80187530;
    case 0x80187534u: goto label_80187534;
    case 0x80187538u: goto label_80187538;
    case 0x8018753Cu: goto label_8018753C;
    case 0x80187540u: goto label_80187540;
    case 0x80187544u: goto label_80187544;
    case 0x80187548u: goto label_80187548;
    case 0x8018754Cu: goto label_8018754C;
    case 0x80187550u: goto label_80187550;
    case 0x80187554u: goto label_80187554;
    case 0x80187558u: goto label_80187558;
    case 0x8018755Cu: goto label_8018755C;
    case 0x80187560u: goto label_80187560;
    case 0x80187564u: goto label_80187564;
    case 0x80187568u: goto label_80187568;
    case 0x8018756Cu: goto label_8018756C;
    case 0x80187570u: goto label_80187570;
    case 0x80187574u: goto label_80187574;
    case 0x80187578u: goto label_80187578;
    case 0x8018757Cu: goto label_8018757C;
    case 0x80187580u: goto label_80187580;
    case 0x80187584u: goto label_80187584;
    case 0x80187588u: goto label_80187588;
    case 0x8018758Cu: goto label_8018758C;
    case 0x80187590u: goto label_80187590;
    case 0x80187594u: goto label_80187594;
    case 0x80187598u: goto label_80187598;
    case 0x8018759Cu: goto label_8018759C;
    case 0x801875A0u: goto label_801875A0;
    case 0x801875A4u: goto label_801875A4;
    case 0x801875A8u: goto label_801875A8;
    case 0x801875ACu: goto label_801875AC;
    case 0x801875B0u: goto label_801875B0;
    case 0x801875B4u: goto label_801875B4;
    case 0x801875B8u: goto label_801875B8;
    case 0x801875BCu: goto label_801875BC;
    case 0x801875C0u: goto label_801875C0;
    case 0x801875C4u: goto label_801875C4;
    case 0x801875C8u: goto label_801875C8;
    case 0x801875CCu: goto label_801875CC;
    case 0x801875D0u: goto label_801875D0;
    case 0x801875D4u: goto label_801875D4;
    case 0x801875D8u: goto label_801875D8;
    case 0x801875DCu: goto label_801875DC;
    case 0x801875E0u: goto label_801875E0;
    case 0x801875E4u: goto label_801875E4;
    case 0x801875E8u: goto label_801875E8;
    case 0x801875ECu: goto label_801875EC;
    case 0x801875F0u: goto label_801875F0;
    case 0x801875F4u: goto label_801875F4;
    case 0x801875F8u: goto label_801875F8;
    case 0x801875FCu: goto label_801875FC;
    case 0x80187600u: goto label_80187600;
    case 0x80187604u: goto label_80187604;
    case 0x80187608u: goto label_80187608;
    case 0x8018760Cu: goto label_8018760C;
    case 0x80187610u: goto label_80187610;
    case 0x80187614u: goto label_80187614;
    case 0x80187618u: goto label_80187618;
    case 0x8018761Cu: goto label_8018761C;
    case 0x80187620u: goto label_80187620;
    case 0x80187624u: goto label_80187624;
    case 0x80187628u: goto label_80187628;
    case 0x8018762Cu: goto label_8018762C;
    case 0x80187630u: goto label_80187630;
    case 0x80187634u: goto label_80187634;
    case 0x80187638u: goto label_80187638;
    case 0x8018763Cu: goto label_8018763C;
    case 0x80187640u: goto label_80187640;
    case 0x80187644u: goto label_80187644;
    case 0x80187648u: goto label_80187648;
    case 0x8018764Cu: goto label_8018764C;
    case 0x80187650u: goto label_80187650;
    case 0x80187654u: goto label_80187654;
    case 0x80187658u: goto label_80187658;
    case 0x8018765Cu: goto label_8018765C;
    case 0x80187660u: goto label_80187660;
    case 0x80187664u: goto label_80187664;
    case 0x80187668u: goto label_80187668;
    case 0x8018766Cu: goto label_8018766C;
    case 0x80187670u: goto label_80187670;
    case 0x80187674u: goto label_80187674;
    case 0x80187678u: goto label_80187678;
    case 0x8018767Cu: goto label_8018767C;
    case 0x80187680u: goto label_80187680;
    case 0x80187684u: goto label_80187684;
    case 0x80187688u: goto label_80187688;
    case 0x8018768Cu: goto label_8018768C;
    case 0x80187690u: goto label_80187690;
    case 0x80187694u: goto label_80187694;
    case 0x80187698u: goto label_80187698;
    case 0x8018769Cu: goto label_8018769C;
    case 0x801876A0u: goto label_801876A0;
    case 0x801876A4u: goto label_801876A4;
    case 0x801876A8u: goto label_801876A8;
    case 0x801876ACu: goto label_801876AC;
    case 0x801876B0u: goto label_801876B0;
    case 0x801876B4u: goto label_801876B4;
    case 0x801876B8u: goto label_801876B8;
    case 0x801876BCu: goto label_801876BC;
    case 0x801876C0u: goto label_801876C0;
    case 0x801876C4u: goto label_801876C4;
    case 0x801876C8u: goto label_801876C8;
    case 0x801876CCu: goto label_801876CC;
    case 0x801876D0u: goto label_801876D0;
    case 0x801876D4u: goto label_801876D4;
    case 0x801876D8u: goto label_801876D8;
    case 0x801876DCu: goto label_801876DC;
    case 0x801876E0u: goto label_801876E0;
    case 0x801876E4u: goto label_801876E4;
    case 0x801876E8u: goto label_801876E8;
    case 0x801876ECu: goto label_801876EC;
    case 0x801876F0u: goto label_801876F0;
    case 0x801876F4u: goto label_801876F4;
    case 0x801876F8u: goto label_801876F8;
    case 0x801876FCu: goto label_801876FC;
    case 0x80187700u: goto label_80187700;
    case 0x80187704u: goto label_80187704;
    case 0x80187708u: goto label_80187708;
    case 0x8018770Cu: goto label_8018770C;
    case 0x80187710u: goto label_80187710;
    case 0x80187714u: goto label_80187714;
    case 0x80187718u: goto label_80187718;
    case 0x8018771Cu: goto label_8018771C;
    case 0x80187720u: goto label_80187720;
    case 0x80187724u: goto label_80187724;
    case 0x80187728u: goto label_80187728;
    case 0x8018772Cu: goto label_8018772C;
    case 0x80187730u: goto label_80187730;
    case 0x80187734u: goto label_80187734;
    case 0x80187738u: goto label_80187738;
    case 0x8018773Cu: goto label_8018773C;
    case 0x80187740u: goto label_80187740;
    case 0x80187744u: goto label_80187744;
    case 0x80187748u: goto label_80187748;
    case 0x8018774Cu: goto label_8018774C;
    case 0x80187750u: goto label_80187750;
    case 0x80187754u: goto label_80187754;
    case 0x80187758u: goto label_80187758;
    case 0x8018775Cu: goto label_8018775C;
    case 0x80187760u: goto label_80187760;
    case 0x80187764u: goto label_80187764;
    case 0x80187768u: goto label_80187768;
    case 0x8018776Cu: goto label_8018776C;
    case 0x80187770u: goto label_80187770;
    case 0x80187774u: goto label_80187774;
    case 0x80187778u: goto label_80187778;
    case 0x8018777Cu: goto label_8018777C;
    case 0x80187780u: goto label_80187780;
    case 0x80187784u: goto label_80187784;
    case 0x80187788u: goto label_80187788;
    case 0x8018778Cu: goto label_8018778C;
    case 0x80187790u: goto label_80187790;
    case 0x80187794u: goto label_80187794;
    case 0x80187798u: goto label_80187798;
    case 0x8018779Cu: goto label_8018779C;
    case 0x801877A0u: goto label_801877A0;
    case 0x801877A4u: goto label_801877A4;
    case 0x801877A8u: goto label_801877A8;
    case 0x801877ACu: goto label_801877AC;
    case 0x801877B0u: goto label_801877B0;
    case 0x801877B4u: goto label_801877B4;
    case 0x801877B8u: goto label_801877B8;
    case 0x801877BCu: goto label_801877BC;
    case 0x801877C0u: goto label_801877C0;
    case 0x801877C4u: goto label_801877C4;
    case 0x801877C8u: goto label_801877C8;
    case 0x801877CCu: goto label_801877CC;
    case 0x801877D0u: goto label_801877D0;
    case 0x801877D4u: goto label_801877D4;
    case 0x801877D8u: goto label_801877D8;
    case 0x801877DCu: goto label_801877DC;
    case 0x801877E0u: goto label_801877E0;
    case 0x801877E4u: goto label_801877E4;
    case 0x801877E8u: goto label_801877E8;
    case 0x801877ECu: goto label_801877EC;
    case 0x801877F0u: goto label_801877F0;
    case 0x801877F4u: goto label_801877F4;
    case 0x801877F8u: goto label_801877F8;
    case 0x801877FCu: goto label_801877FC;
    case 0x80187800u: goto label_80187800;
    case 0x80187804u: goto label_80187804;
    case 0x80187808u: goto label_80187808;
    case 0x8018780Cu: goto label_8018780C;
    case 0x80187810u: goto label_80187810;
    case 0x80187814u: goto label_80187814;
    case 0x80187818u: goto label_80187818;
    case 0x8018781Cu: goto label_8018781C;
    case 0x80187820u: goto label_80187820;
    case 0x80187824u: goto label_80187824;
    case 0x80187828u: goto label_80187828;
    case 0x8018782Cu: goto label_8018782C;
    case 0x80187830u: goto label_80187830;
    case 0x80187834u: goto label_80187834;
    case 0x80187838u: goto label_80187838;
    case 0x8018783Cu: goto label_8018783C;
    case 0x80187840u: goto label_80187840;
    case 0x80187844u: goto label_80187844;
    case 0x80187848u: goto label_80187848;
    case 0x8018784Cu: goto label_8018784C;
    case 0x80187850u: goto label_80187850;
    case 0x80187854u: goto label_80187854;
    case 0x80187858u: goto label_80187858;
    case 0x8018785Cu: goto label_8018785C;
    case 0x80187860u: goto label_80187860;
    case 0x80187864u: goto label_80187864;
    case 0x80187868u: goto label_80187868;
    case 0x8018786Cu: goto label_8018786C;
    case 0x80187870u: goto label_80187870;
    case 0x80187874u: goto label_80187874;
    case 0x80187878u: goto label_80187878;
    case 0x8018787Cu: goto label_8018787C;
    case 0x80187880u: goto label_80187880;
    case 0x80187884u: goto label_80187884;
    case 0x80187888u: goto label_80187888;
    case 0x8018788Cu: goto label_8018788C;
    case 0x80187890u: goto label_80187890;
    case 0x80187894u: goto label_80187894;
    case 0x80187898u: goto label_80187898;
    case 0x8018789Cu: goto label_8018789C;
    case 0x801878A0u: goto label_801878A0;
    case 0x801878A4u: goto label_801878A4;
    case 0x801878A8u: goto label_801878A8;
    case 0x801878ACu: goto label_801878AC;
    case 0x801878B0u: goto label_801878B0;
    case 0x801878B4u: goto label_801878B4;
    case 0x801878B8u: goto label_801878B8;
    case 0x801878BCu: goto label_801878BC;
    case 0x801878C0u: goto label_801878C0;
    case 0x801878C4u: goto label_801878C4;
    case 0x801878C8u: goto label_801878C8;
    case 0x801878CCu: goto label_801878CC;
    case 0x801878D0u: goto label_801878D0;
    case 0x801878D4u: goto label_801878D4;
    case 0x801878D8u: goto label_801878D8;
    case 0x801878DCu: goto label_801878DC;
    case 0x801878E0u: goto label_801878E0;
    case 0x801878E4u: goto label_801878E4;
    case 0x801878E8u: goto label_801878E8;
    case 0x801878ECu: goto label_801878EC;
    case 0x801878F0u: goto label_801878F0;
    case 0x801878F4u: goto label_801878F4;
    case 0x801878F8u: goto label_801878F8;
    case 0x801878FCu: goto label_801878FC;
    case 0x80187900u: goto label_80187900;
    case 0x80187904u: goto label_80187904;
    case 0x80187908u: goto label_80187908;
    case 0x8018790Cu: goto label_8018790C;
    case 0x80187910u: goto label_80187910;
    case 0x80187914u: goto label_80187914;
    case 0x80187918u: goto label_80187918;
    case 0x8018791Cu: goto label_8018791C;
    case 0x80187920u: goto label_80187920;
    case 0x80187924u: goto label_80187924;
    case 0x80187928u: goto label_80187928;
    case 0x8018792Cu: goto label_8018792C;
    case 0x80187930u: goto label_80187930;
    case 0x80187934u: goto label_80187934;
    case 0x80187938u: goto label_80187938;
    case 0x8018793Cu: goto label_8018793C;
    case 0x80187940u: goto label_80187940;
    case 0x80187944u: goto label_80187944;
    case 0x80187948u: goto label_80187948;
    case 0x8018794Cu: goto label_8018794C;
    case 0x80187950u: goto label_80187950;
    case 0x80187954u: goto label_80187954;
    case 0x80187958u: goto label_80187958;
    case 0x8018795Cu: goto label_8018795C;
    case 0x80187960u: goto label_80187960;
    case 0x80187964u: goto label_80187964;
    case 0x80187968u: goto label_80187968;
    case 0x8018796Cu: goto label_8018796C;
    case 0x80187970u: goto label_80187970;
    case 0x80187974u: goto label_80187974;
    case 0x80187978u: goto label_80187978;
    case 0x8018797Cu: goto label_8018797C;
    case 0x80187980u: goto label_80187980;
    case 0x80187984u: goto label_80187984;
    case 0x80187988u: goto label_80187988;
    case 0x8018798Cu: goto label_8018798C;
    case 0x80187990u: goto label_80187990;
    case 0x80187994u: goto label_80187994;
    case 0x80187998u: goto label_80187998;
    case 0x8018799Cu: goto label_8018799C;
    case 0x801879A0u: goto label_801879A0;
    case 0x801879A4u: goto label_801879A4;
    case 0x801879A8u: goto label_801879A8;
    case 0x801879ACu: goto label_801879AC;
    case 0x801879B0u: goto label_801879B0;
    case 0x801879B4u: goto label_801879B4;
    case 0x801879B8u: goto label_801879B8;
    case 0x801879BCu: goto label_801879BC;
    case 0x801879C0u: goto label_801879C0;
    case 0x801879C4u: goto label_801879C4;
    case 0x801879C8u: goto label_801879C8;
    case 0x801879CCu: goto label_801879CC;
    case 0x801879D0u: goto label_801879D0;
    case 0x801879D4u: goto label_801879D4;
    case 0x801879D8u: goto label_801879D8;
    case 0x801879DCu: goto label_801879DC;
    case 0x801879E0u: goto label_801879E0;
    case 0x801879E4u: goto label_801879E4;
    case 0x801879E8u: goto label_801879E8;
    case 0x801879ECu: goto label_801879EC;
    case 0x801879F0u: goto label_801879F0;
    case 0x801879F4u: goto label_801879F4;
    case 0x801879F8u: goto label_801879F8;
    case 0x801879FCu: goto label_801879FC;
    case 0x80187A00u: goto label_80187A00;
    case 0x80187A04u: goto label_80187A04;
    case 0x80187A08u: goto label_80187A08;
    case 0x80187A0Cu: goto label_80187A0C;
    case 0x80187A10u: goto label_80187A10;
    case 0x80187A14u: goto label_80187A14;
    case 0x80187A18u: goto label_80187A18;
    case 0x80187A1Cu: goto label_80187A1C;
    case 0x80187A20u: goto label_80187A20;
    case 0x80187A24u: goto label_80187A24;
    case 0x80187A28u: goto label_80187A28;
    case 0x80187A2Cu: goto label_80187A2C;
    case 0x80187A30u: goto label_80187A30;
    case 0x80187A34u: goto label_80187A34;
    case 0x80187A38u: goto label_80187A38;
    case 0x80187A3Cu: goto label_80187A3C;
    case 0x80187A40u: goto label_80187A40;
    case 0x80187A44u: goto label_80187A44;
    case 0x80187A48u: goto label_80187A48;
    case 0x80187A4Cu: goto label_80187A4C;
    case 0x80187A50u: goto label_80187A50;
    case 0x80187A54u: goto label_80187A54;
    case 0x80187A58u: goto label_80187A58;
    case 0x80187A5Cu: goto label_80187A5C;
    case 0x80187A60u: goto label_80187A60;
    case 0x80187A64u: goto label_80187A64;
    case 0x80187A68u: goto label_80187A68;
    case 0x80187A6Cu: goto label_80187A6C;
    case 0x80187A70u: goto label_80187A70;
    case 0x80187A74u: goto label_80187A74;
    case 0x80187A78u: goto label_80187A78;
    case 0x80187A7Cu: goto label_80187A7C;
    case 0x80187A80u: goto label_80187A80;
    case 0x80187A84u: goto label_80187A84;
    case 0x80187A88u: goto label_80187A88;
    case 0x80187A8Cu: goto label_80187A8C;
    case 0x80187A90u: goto label_80187A90;
    case 0x80187A94u: goto label_80187A94;
    case 0x80187A98u: goto label_80187A98;
    case 0x80187A9Cu: goto label_80187A9C;
    case 0x80187AA0u: goto label_80187AA0;
    case 0x80187AA4u: goto label_80187AA4;
    case 0x80187AA8u: goto label_80187AA8;
    case 0x80187AACu: goto label_80187AAC;
    case 0x80187AB0u: goto label_80187AB0;
    case 0x80187AB4u: goto label_80187AB4;
    case 0x80187AB8u: goto label_80187AB8;
    case 0x80187ABCu: goto label_80187ABC;
    case 0x80187AC0u: goto label_80187AC0;
    case 0x80187AC4u: goto label_80187AC4;
    case 0x80187AC8u: goto label_80187AC8;
    case 0x80187ACCu: goto label_80187ACC;
    case 0x80187AD0u: goto label_80187AD0;
    case 0x80187AD4u: goto label_80187AD4;
    case 0x80187AD8u: goto label_80187AD8;
    case 0x80187ADCu: goto label_80187ADC;
    case 0x80187AE0u: goto label_80187AE0;
    case 0x80187AE4u: goto label_80187AE4;
    case 0x80187AE8u: goto label_80187AE8;
    case 0x80187AECu: goto label_80187AEC;
    case 0x80187AF0u: goto label_80187AF0;
    case 0x80187AF4u: goto label_80187AF4;
    case 0x80187AF8u: goto label_80187AF8;
    case 0x80187AFCu: goto label_80187AFC;
    case 0x80187B00u: goto label_80187B00;
    case 0x80187B04u: goto label_80187B04;
    case 0x80187B08u: goto label_80187B08;
    case 0x80187B0Cu: goto label_80187B0C;
    case 0x80187B10u: goto label_80187B10;
    case 0x80187B14u: goto label_80187B14;
    case 0x80187B18u: goto label_80187B18;
    case 0x80187B1Cu: goto label_80187B1C;
    case 0x80187B20u: goto label_80187B20;
    case 0x80187B24u: goto label_80187B24;
    case 0x80187B28u: goto label_80187B28;
    case 0x80187B2Cu: goto label_80187B2C;
    case 0x80187B30u: goto label_80187B30;
    case 0x80187B34u: goto label_80187B34;
    case 0x80187B38u: goto label_80187B38;
    case 0x80187B3Cu: goto label_80187B3C;
    case 0x80187B40u: goto label_80187B40;
    case 0x80187B44u: goto label_80187B44;
    case 0x80187B48u: goto label_80187B48;
    case 0x80187B4Cu: goto label_80187B4C;
    case 0x80187B50u: goto label_80187B50;
    case 0x80187B54u: goto label_80187B54;
    case 0x80187B58u: goto label_80187B58;
    case 0x80187B5Cu: goto label_80187B5C;
    case 0x80187B60u: goto label_80187B60;
    case 0x80187B64u: goto label_80187B64;
    case 0x80187B68u: goto label_80187B68;
    case 0x80187B6Cu: goto label_80187B6C;
    case 0x80187B70u: goto label_80187B70;
    case 0x80187B74u: goto label_80187B74;
    case 0x80187B78u: goto label_80187B78;
    case 0x80187B7Cu: goto label_80187B7C;
    case 0x80187B80u: goto label_80187B80;
    case 0x80187B84u: goto label_80187B84;
    case 0x80187B88u: goto label_80187B88;
    case 0x80187B8Cu: goto label_80187B8C;
    case 0x80187B90u: goto label_80187B90;
    case 0x80187B94u: goto label_80187B94;
    case 0x80187B98u: goto label_80187B98;
    case 0x80187B9Cu: goto label_80187B9C;
    case 0x80187BA0u: goto label_80187BA0;
    case 0x80187BA4u: goto label_80187BA4;
    case 0x80187BA8u: goto label_80187BA8;
    case 0x80187BACu: goto label_80187BAC;
    case 0x80187BB0u: goto label_80187BB0;
    case 0x80187BB4u: goto label_80187BB4;
    case 0x80187BB8u: goto label_80187BB8;
    case 0x80187BBCu: goto label_80187BBC;
    case 0x80187BC0u: goto label_80187BC0;
    case 0x80187BC4u: goto label_80187BC4;
    case 0x80187BC8u: goto label_80187BC8;
    case 0x80187BCCu: goto label_80187BCC;
    case 0x80187BD0u: goto label_80187BD0;
    case 0x80187BD4u: goto label_80187BD4;
    case 0x80187BD8u: goto label_80187BD8;
    case 0x80187BDCu: goto label_80187BDC;
    case 0x80187BE0u: goto label_80187BE0;
    case 0x80187BE4u: goto label_80187BE4;
    case 0x80187BE8u: goto label_80187BE8;
    case 0x80187BECu: goto label_80187BEC;
    case 0x80187BF0u: goto label_80187BF0;
    case 0x80187BF4u: goto label_80187BF4;
    case 0x80187BF8u: goto label_80187BF8;
    case 0x80187BFCu: goto label_80187BFC;
    case 0x80187C00u: goto label_80187C00;
    case 0x80187C04u: goto label_80187C04;
    case 0x80187C08u: goto label_80187C08;
    case 0x80187C0Cu: goto label_80187C0C;
    case 0x80187C10u: goto label_80187C10;
    case 0x80187C14u: goto label_80187C14;
    case 0x80187C18u: goto label_80187C18;
    case 0x80187C1Cu: goto label_80187C1C;
    case 0x80187C20u: goto label_80187C20;
    case 0x80187C24u: goto label_80187C24;
    case 0x80187C28u: goto label_80187C28;
    case 0x80187C2Cu: goto label_80187C2C;
    case 0x80187C30u: goto label_80187C30;
    case 0x80187C34u: goto label_80187C34;
    case 0x80187C38u: goto label_80187C38;
    case 0x80187C3Cu: goto label_80187C3C;
    case 0x80187C40u: goto label_80187C40;
    case 0x80187C44u: goto label_80187C44;
    case 0x80187C48u: goto label_80187C48;
    case 0x80187C4Cu: goto label_80187C4C;
    case 0x80187C50u: goto label_80187C50;
    case 0x80187C54u: goto label_80187C54;
    case 0x80187C58u: goto label_80187C58;
    case 0x80187C5Cu: goto label_80187C5C;
    case 0x80187C60u: goto label_80187C60;
    case 0x80187C64u: goto label_80187C64;
    case 0x80187C68u: goto label_80187C68;
    case 0x80187C6Cu: goto label_80187C6C;
    case 0x80187C70u: goto label_80187C70;
    case 0x80187C74u: goto label_80187C74;
    case 0x80187C78u: goto label_80187C78;
    case 0x80187C7Cu: goto label_80187C7C;
    case 0x80187C80u: goto label_80187C80;
    case 0x80187C84u: goto label_80187C84;
    case 0x80187C88u: goto label_80187C88;
    case 0x80187C8Cu: goto label_80187C8C;
    case 0x80187C90u: goto label_80187C90;
    case 0x80187C94u: goto label_80187C94;
    case 0x80187C98u: goto label_80187C98;
    case 0x80187C9Cu: goto label_80187C9C;
    case 0x80187CA0u: goto label_80187CA0;
    case 0x80187CA4u: goto label_80187CA4;
    case 0x80187CA8u: goto label_80187CA8;
    case 0x80187CACu: goto label_80187CAC;
    case 0x80187CB0u: goto label_80187CB0;
    case 0x80187CB4u: goto label_80187CB4;
    case 0x80187CB8u: goto label_80187CB8;
    case 0x80187CBCu: goto label_80187CBC;
    case 0x80187CC0u: goto label_80187CC0;
    case 0x80187CC4u: goto label_80187CC4;
    case 0x80187CC8u: goto label_80187CC8;
    case 0x80187CCCu: goto label_80187CCC;
    case 0x80187CD0u: goto label_80187CD0;
    case 0x80187CD4u: goto label_80187CD4;
    case 0x80187CD8u: goto label_80187CD8;
    case 0x80187CDCu: goto label_80187CDC;
    case 0x80187CE0u: goto label_80187CE0;
    case 0x80187CE4u: goto label_80187CE4;
    case 0x80187CE8u: goto label_80187CE8;
    case 0x80187CECu: goto label_80187CEC;
    case 0x80187CF0u: goto label_80187CF0;
    case 0x80187CF4u: goto label_80187CF4;
    case 0x80187CF8u: goto label_80187CF8;
    case 0x80187CFCu: goto label_80187CFC;
    case 0x80187D00u: goto label_80187D00;
    case 0x80187D04u: goto label_80187D04;
    case 0x80187D08u: goto label_80187D08;
    case 0x80187D0Cu: goto label_80187D0C;
    case 0x80187D10u: goto label_80187D10;
    case 0x80187D14u: goto label_80187D14;
    case 0x80187D18u: goto label_80187D18;
    case 0x80187D1Cu: goto label_80187D1C;
    case 0x80187D20u: goto label_80187D20;
    case 0x80187D24u: goto label_80187D24;
    case 0x80187D28u: goto label_80187D28;
    case 0x80187D2Cu: goto label_80187D2C;
    case 0x80187D30u: goto label_80187D30;
    case 0x80187D34u: goto label_80187D34;
    case 0x80187D38u: goto label_80187D38;
    case 0x80187D3Cu: goto label_80187D3C;
    case 0x80187D40u: goto label_80187D40;
    case 0x80187D44u: goto label_80187D44;
    case 0x80187D48u: goto label_80187D48;
    case 0x80187D4Cu: goto label_80187D4C;
    case 0x80187D50u: goto label_80187D50;
    case 0x80187D54u: goto label_80187D54;
    case 0x80187D58u: goto label_80187D58;
    case 0x80187D5Cu: goto label_80187D5C;
    case 0x80187D60u: goto label_80187D60;
    case 0x80187D64u: goto label_80187D64;
    case 0x80187D68u: goto label_80187D68;
    case 0x80187D6Cu: goto label_80187D6C;
    case 0x80187D70u: goto label_80187D70;
    case 0x80187D74u: goto label_80187D74;
    case 0x80187D78u: goto label_80187D78;
    case 0x80187D7Cu: goto label_80187D7C;
    case 0x80187D80u: goto label_80187D80;
    case 0x80187D84u: goto label_80187D84;
    case 0x80187D88u: goto label_80187D88;
    case 0x80187D8Cu: goto label_80187D8C;
    case 0x80187D90u: goto label_80187D90;
    case 0x80187D94u: goto label_80187D94;
    case 0x80187D98u: goto label_80187D98;
    case 0x80187D9Cu: goto label_80187D9C;
    case 0x80187DA0u: goto label_80187DA0;
    case 0x80187DA4u: goto label_80187DA4;
    case 0x80187DA8u: goto label_80187DA8;
    case 0x80187DACu: goto label_80187DAC;
    case 0x80187DB0u: goto label_80187DB0;
    case 0x80187DB4u: goto label_80187DB4;
    case 0x80187DB8u: goto label_80187DB8;
    case 0x80187DBCu: goto label_80187DBC;
    case 0x80187DC0u: goto label_80187DC0;
    case 0x80187DC4u: goto label_80187DC4;
    case 0x80187DC8u: goto label_80187DC8;
    case 0x80187DCCu: goto label_80187DCC;
    case 0x80187DD0u: goto label_80187DD0;
    case 0x80187DD4u: goto label_80187DD4;
    case 0x80187DD8u: goto label_80187DD8;
    case 0x80187DDCu: goto label_80187DDC;
    case 0x80187DE0u: goto label_80187DE0;
    case 0x80187DE4u: goto label_80187DE4;
    case 0x80187DE8u: goto label_80187DE8;
    case 0x80187DECu: goto label_80187DEC;
    case 0x80187DF0u: goto label_80187DF0;
    case 0x80187DF4u: goto label_80187DF4;
    case 0x80187DF8u: goto label_80187DF8;
    case 0x80187DFCu: goto label_80187DFC;
    case 0x80187E00u: goto label_80187E00;
    case 0x80187E04u: goto label_80187E04;
    case 0x80187E08u: goto label_80187E08;
    case 0x80187E0Cu: goto label_80187E0C;
    case 0x80187E10u: goto label_80187E10;
    case 0x80187E14u: goto label_80187E14;
    case 0x80187E18u: goto label_80187E18;
    case 0x80187E1Cu: goto label_80187E1C;
    case 0x80187E20u: goto label_80187E20;
    case 0x80187E24u: goto label_80187E24;
    case 0x80187E28u: goto label_80187E28;
    case 0x80187E2Cu: goto label_80187E2C;
    case 0x80187E30u: goto label_80187E30;
    case 0x80187E34u: goto label_80187E34;
    case 0x80187E38u: goto label_80187E38;
    case 0x80187E3Cu: goto label_80187E3C;
    case 0x80187E40u: goto label_80187E40;
    case 0x80187E44u: goto label_80187E44;
    case 0x80187E48u: goto label_80187E48;
    case 0x80187E4Cu: goto label_80187E4C;
    case 0x80187E50u: goto label_80187E50;
    case 0x80187E54u: goto label_80187E54;
    case 0x80187E58u: goto label_80187E58;
    case 0x80187E5Cu: goto label_80187E5C;
    case 0x80187E60u: goto label_80187E60;
    case 0x80187E64u: goto label_80187E64;
    case 0x80187E68u: goto label_80187E68;
    case 0x80187E6Cu: goto label_80187E6C;
    case 0x80187E70u: goto label_80187E70;
    case 0x80187E74u: goto label_80187E74;
    case 0x80187E78u: goto label_80187E78;
    case 0x80187E7Cu: goto label_80187E7C;
    case 0x80187E80u: goto label_80187E80;
    case 0x80187E84u: goto label_80187E84;
    case 0x80187E88u: goto label_80187E88;
    case 0x80187E8Cu: goto label_80187E8C;
    case 0x80187E90u: goto label_80187E90;
    case 0x80187E94u: goto label_80187E94;
    case 0x80187E98u: goto label_80187E98;
    case 0x80187E9Cu: goto label_80187E9C;
    case 0x80187EA0u: goto label_80187EA0;
    case 0x80187EA4u: goto label_80187EA4;
    case 0x80187EA8u: goto label_80187EA8;
    case 0x80187EACu: goto label_80187EAC;
    case 0x80187EB0u: goto label_80187EB0;
    case 0x80187EB4u: goto label_80187EB4;
    case 0x80187EB8u: goto label_80187EB8;
    case 0x80187EBCu: goto label_80187EBC;
    case 0x80187EC0u: goto label_80187EC0;
    case 0x80187EC4u: goto label_80187EC4;
    case 0x80187EC8u: goto label_80187EC8;
    case 0x80187ECCu: goto label_80187ECC;
    case 0x80187ED0u: goto label_80187ED0;
    case 0x80187ED4u: goto label_80187ED4;
    case 0x80187ED8u: goto label_80187ED8;
    case 0x80187EDCu: goto label_80187EDC;
    case 0x80187EE0u: goto label_80187EE0;
    case 0x80187EE4u: goto label_80187EE4;
    case 0x80187EE8u: goto label_80187EE8;
    case 0x80187EECu: goto label_80187EEC;
    case 0x80187EF0u: goto label_80187EF0;
    case 0x80187EF4u: goto label_80187EF4;
    case 0x80187EF8u: goto label_80187EF8;
    case 0x80187EFCu: goto label_80187EFC;
    case 0x80187F00u: goto label_80187F00;
    case 0x80187F04u: goto label_80187F04;
    case 0x80187F08u: goto label_80187F08;
    case 0x80187F0Cu: goto label_80187F0C;
    case 0x80187F10u: goto label_80187F10;
    case 0x80187F14u: goto label_80187F14;
    case 0x80187F18u: goto label_80187F18;
    case 0x80187F1Cu: goto label_80187F1C;
    case 0x80187F20u: goto label_80187F20;
    case 0x80187F24u: goto label_80187F24;
    case 0x80187F28u: goto label_80187F28;
    case 0x80187F2Cu: goto label_80187F2C;
    case 0x80187F30u: goto label_80187F30;
    case 0x80187F34u: goto label_80187F34;
    case 0x80187F38u: goto label_80187F38;
    case 0x80187F3Cu: goto label_80187F3C;
    case 0x80187F40u: goto label_80187F40;
    case 0x80187F44u: goto label_80187F44;
    case 0x80187F48u: goto label_80187F48;
    case 0x80187F4Cu: goto label_80187F4C;
    case 0x80187F50u: goto label_80187F50;
    case 0x80187F54u: goto label_80187F54;
    case 0x80187F58u: goto label_80187F58;
    case 0x80187F5Cu: goto label_80187F5C;
    case 0x80187F60u: goto label_80187F60;
    case 0x80187F64u: goto label_80187F64;
    case 0x80187F68u: goto label_80187F68;
    case 0x80187F6Cu: goto label_80187F6C;
    case 0x80187F70u: goto label_80187F70;
    case 0x80187F74u: goto label_80187F74;
    case 0x80187F78u: goto label_80187F78;
    case 0x80187F7Cu: goto label_80187F7C;
    case 0x80187F80u: goto label_80187F80;
    case 0x80187F84u: goto label_80187F84;
    case 0x80187F88u: goto label_80187F88;
    case 0x80187F8Cu: goto label_80187F8C;
    case 0x80187F90u: goto label_80187F90;
    case 0x80187F94u: goto label_80187F94;
    case 0x80187F98u: goto label_80187F98;
    case 0x80187F9Cu: goto label_80187F9C;
    case 0x80187FA0u: goto label_80187FA0;
    case 0x80187FA4u: goto label_80187FA4;
    case 0x80187FA8u: goto label_80187FA8;
    case 0x80187FACu: goto label_80187FAC;
    case 0x80187FB0u: goto label_80187FB0;
    case 0x80187FB4u: goto label_80187FB4;
    case 0x80187FB8u: goto label_80187FB8;
    case 0x80187FBCu: goto label_80187FBC;
    case 0x80187FC0u: goto label_80187FC0;
    case 0x80187FC4u: goto label_80187FC4;
    case 0x80187FC8u: goto label_80187FC8;
    case 0x80187FCCu: goto label_80187FCC;
    case 0x80187FD0u: goto label_80187FD0;
    case 0x80187FD4u: goto label_80187FD4;
    case 0x80187FD8u: goto label_80187FD8;
    case 0x80187FDCu: goto label_80187FDC;
    case 0x80187FE0u: goto label_80187FE0;
    case 0x80187FE4u: goto label_80187FE4;
    case 0x80187FE8u: goto label_80187FE8;
    case 0x80187FECu: goto label_80187FEC;
    case 0x80187FF0u: goto label_80187FF0;
    case 0x80187FF4u: goto label_80187FF4;
    case 0x80187FF8u: goto label_80187FF8;
    case 0x80187FFCu: goto label_80187FFC;
    case 0x80188000u: goto label_80188000;
    case 0x80188004u: goto label_80188004;
    case 0x80188008u: goto label_80188008;
    case 0x8018800Cu: goto label_8018800C;
    case 0x80188010u: goto label_80188010;
    case 0x80188014u: goto label_80188014;
    case 0x80188018u: goto label_80188018;
    case 0x8018801Cu: goto label_8018801C;
    case 0x80188020u: goto label_80188020;
    case 0x80188024u: goto label_80188024;
    case 0x80188028u: goto label_80188028;
    case 0x8018802Cu: goto label_8018802C;
    case 0x80188030u: goto label_80188030;
    case 0x80188034u: goto label_80188034;
    case 0x80188038u: goto label_80188038;
    case 0x8018803Cu: goto label_8018803C;
    case 0x80188040u: goto label_80188040;
    case 0x80188044u: goto label_80188044;
    case 0x80188048u: goto label_80188048;
    case 0x8018804Cu: goto label_8018804C;
    case 0x80188050u: goto label_80188050;
    case 0x80188054u: goto label_80188054;
    case 0x80188058u: goto label_80188058;
    case 0x8018805Cu: goto label_8018805C;
    case 0x80188060u: goto label_80188060;
    case 0x80188064u: goto label_80188064;
    case 0x80188068u: goto label_80188068;
    case 0x8018806Cu: goto label_8018806C;
    case 0x80188070u: goto label_80188070;
    case 0x80188074u: goto label_80188074;
    case 0x80188078u: goto label_80188078;
    case 0x8018807Cu: goto label_8018807C;
    case 0x80188080u: goto label_80188080;
    case 0x80188084u: goto label_80188084;
    case 0x80188088u: goto label_80188088;
    case 0x8018808Cu: goto label_8018808C;
    case 0x80188090u: goto label_80188090;
    case 0x80188094u: goto label_80188094;
    case 0x80188098u: goto label_80188098;
    case 0x8018809Cu: goto label_8018809C;
    case 0x801880A0u: goto label_801880A0;
    case 0x801880A4u: goto label_801880A4;
    case 0x801880A8u: goto label_801880A8;
    case 0x801880ACu: goto label_801880AC;
    case 0x801880B0u: goto label_801880B0;
    case 0x801880B4u: goto label_801880B4;
    case 0x801880B8u: goto label_801880B8;
    case 0x801880BCu: goto label_801880BC;
    case 0x801880C0u: goto label_801880C0;
    case 0x801880C4u: goto label_801880C4;
    case 0x801880C8u: goto label_801880C8;
    case 0x801880CCu: goto label_801880CC;
    case 0x801880D0u: goto label_801880D0;
    case 0x801880D4u: goto label_801880D4;
    case 0x801880D8u: goto label_801880D8;
    case 0x801880DCu: goto label_801880DC;
    case 0x801880E0u: goto label_801880E0;
    case 0x801880E4u: goto label_801880E4;
    case 0x801880E8u: goto label_801880E8;
    case 0x801880ECu: goto label_801880EC;
    case 0x801880F0u: goto label_801880F0;
    case 0x801880F4u: goto label_801880F4;
    case 0x801880F8u: goto label_801880F8;
    case 0x801880FCu: goto label_801880FC;
    case 0x80188100u: goto label_80188100;
    case 0x80188104u: goto label_80188104;
    case 0x80188108u: goto label_80188108;
    case 0x8018810Cu: goto label_8018810C;
    case 0x80188110u: goto label_80188110;
    case 0x80188114u: goto label_80188114;
    case 0x80188118u: goto label_80188118;
    case 0x8018811Cu: goto label_8018811C;
    case 0x80188120u: goto label_80188120;
    case 0x80188124u: goto label_80188124;
    case 0x80188128u: goto label_80188128;
    case 0x8018812Cu: goto label_8018812C;
    case 0x80188130u: goto label_80188130;
    case 0x80188134u: goto label_80188134;
    case 0x80188138u: goto label_80188138;
    case 0x8018813Cu: goto label_8018813C;
    case 0x80188140u: goto label_80188140;
    case 0x80188144u: goto label_80188144;
    case 0x80188148u: goto label_80188148;
    case 0x8018814Cu: goto label_8018814C;
    case 0x80188150u: goto label_80188150;
    case 0x80188154u: goto label_80188154;
    case 0x80188158u: goto label_80188158;
    case 0x8018815Cu: goto label_8018815C;
    case 0x80188160u: goto label_80188160;
    case 0x80188164u: goto label_80188164;
    case 0x80188168u: goto label_80188168;
    case 0x8018816Cu: goto label_8018816C;
    case 0x80188170u: goto label_80188170;
    case 0x80188174u: goto label_80188174;
    case 0x80188178u: goto label_80188178;
    case 0x8018817Cu: goto label_8018817C;
    case 0x80188180u: goto label_80188180;
    case 0x80188184u: goto label_80188184;
    case 0x80188188u: goto label_80188188;
    case 0x8018818Cu: goto label_8018818C;
    case 0x80188190u: goto label_80188190;
    case 0x80188194u: goto label_80188194;
    case 0x80188198u: goto label_80188198;
    case 0x8018819Cu: goto label_8018819C;
    case 0x801881A0u: goto label_801881A0;
    case 0x801881A4u: goto label_801881A4;
    case 0x801881A8u: goto label_801881A8;
    case 0x801881ACu: goto label_801881AC;
    case 0x801881B0u: goto label_801881B0;
    case 0x801881B4u: goto label_801881B4;
    case 0x801881B8u: goto label_801881B8;
    case 0x801881BCu: goto label_801881BC;
    case 0x801881C0u: goto label_801881C0;
    case 0x801881C4u: goto label_801881C4;
    case 0x801881C8u: goto label_801881C8;
    case 0x801881CCu: goto label_801881CC;
    case 0x801881D0u: goto label_801881D0;
    case 0x801881D4u: goto label_801881D4;
    case 0x801881D8u: goto label_801881D8;
    case 0x801881DCu: goto label_801881DC;
    case 0x801881E0u: goto label_801881E0;
    case 0x801881E4u: goto label_801881E4;
    case 0x801881E8u: goto label_801881E8;
    case 0x801881ECu: goto label_801881EC;
    case 0x801881F0u: goto label_801881F0;
    case 0x801881F4u: goto label_801881F4;
    case 0x801881F8u: goto label_801881F8;
    case 0x801881FCu: goto label_801881FC;
    case 0x80188200u: goto label_80188200;
    case 0x80188204u: goto label_80188204;
    case 0x80188208u: goto label_80188208;
    case 0x8018820Cu: goto label_8018820C;
    case 0x80188210u: goto label_80188210;
    case 0x80188214u: goto label_80188214;
    case 0x80188218u: goto label_80188218;
    case 0x8018821Cu: goto label_8018821C;
    case 0x80188220u: goto label_80188220;
    case 0x80188224u: goto label_80188224;
    case 0x80188228u: goto label_80188228;
    case 0x8018822Cu: goto label_8018822C;
    case 0x80188230u: goto label_80188230;
    case 0x80188234u: goto label_80188234;
    case 0x80188238u: goto label_80188238;
    case 0x8018823Cu: goto label_8018823C;
    case 0x80188240u: goto label_80188240;
    case 0x80188244u: goto label_80188244;
    case 0x80188248u: goto label_80188248;
    case 0x8018824Cu: goto label_8018824C;
    case 0x80188250u: goto label_80188250;
    case 0x80188254u: goto label_80188254;
    case 0x80188258u: goto label_80188258;
    case 0x8018825Cu: goto label_8018825C;
    case 0x80188260u: goto label_80188260;
    case 0x80188264u: goto label_80188264;
    case 0x80188268u: goto label_80188268;
    case 0x8018826Cu: goto label_8018826C;
    case 0x80188270u: goto label_80188270;
    case 0x80188274u: goto label_80188274;
    case 0x80188278u: goto label_80188278;
    case 0x8018827Cu: goto label_8018827C;
    case 0x80188280u: goto label_80188280;
    case 0x80188284u: goto label_80188284;
    case 0x80188288u: goto label_80188288;
    case 0x8018828Cu: goto label_8018828C;
    case 0x80188290u: goto label_80188290;
    case 0x80188294u: goto label_80188294;
    case 0x80188298u: goto label_80188298;
    case 0x8018829Cu: goto label_8018829C;
    case 0x801882A0u: goto label_801882A0;
    case 0x801882A4u: goto label_801882A4;
    case 0x801882A8u: goto label_801882A8;
    case 0x801882ACu: goto label_801882AC;
    case 0x801882B0u: goto label_801882B0;
    case 0x801882B4u: goto label_801882B4;
    case 0x801882B8u: goto label_801882B8;
    case 0x801882BCu: goto label_801882BC;
    case 0x801882C0u: goto label_801882C0;
    case 0x801882C4u: goto label_801882C4;
    case 0x801882C8u: goto label_801882C8;
    case 0x801882CCu: goto label_801882CC;
    case 0x801882D0u: goto label_801882D0;
    case 0x801882D4u: goto label_801882D4;
    case 0x801882D8u: goto label_801882D8;
    case 0x801882DCu: goto label_801882DC;
    case 0x801882E0u: goto label_801882E0;
    case 0x801882E4u: goto label_801882E4;
    case 0x801882E8u: goto label_801882E8;
    case 0x801882ECu: goto label_801882EC;
    case 0x801882F0u: goto label_801882F0;
    case 0x801882F4u: goto label_801882F4;
    case 0x801882F8u: goto label_801882F8;
    case 0x801882FCu: goto label_801882FC;
    case 0x80188300u: goto label_80188300;
    case 0x80188304u: goto label_80188304;
    case 0x80188308u: goto label_80188308;
    case 0x8018830Cu: goto label_8018830C;
    case 0x80188310u: goto label_80188310;
    case 0x80188314u: goto label_80188314;
    case 0x80188318u: goto label_80188318;
    case 0x8018831Cu: goto label_8018831C;
    case 0x80188320u: goto label_80188320;
    case 0x80188324u: goto label_80188324;
    case 0x80188328u: goto label_80188328;
    case 0x8018832Cu: goto label_8018832C;
    case 0x80188330u: goto label_80188330;
    case 0x80188334u: goto label_80188334;
    case 0x80188338u: goto label_80188338;
    case 0x8018833Cu: goto label_8018833C;
    case 0x80188340u: goto label_80188340;
    case 0x80188344u: goto label_80188344;
    case 0x80188348u: goto label_80188348;
    case 0x8018834Cu: goto label_8018834C;
    case 0x80188350u: goto label_80188350;
    case 0x80188354u: goto label_80188354;
    case 0x80188358u: goto label_80188358;
    case 0x8018835Cu: goto label_8018835C;
    case 0x80188360u: goto label_80188360;
    case 0x80188364u: goto label_80188364;
    case 0x80188368u: goto label_80188368;
    case 0x8018836Cu: goto label_8018836C;
    case 0x80188370u: goto label_80188370;
    case 0x80188374u: goto label_80188374;
    case 0x80188378u: goto label_80188378;
    case 0x8018837Cu: goto label_8018837C;
    case 0x80188380u: goto label_80188380;
    case 0x80188384u: goto label_80188384;
    case 0x80188388u: goto label_80188388;
    case 0x8018838Cu: goto label_8018838C;
    case 0x80188390u: goto label_80188390;
    case 0x80188394u: goto label_80188394;
    case 0x80188398u: goto label_80188398;
    case 0x8018839Cu: goto label_8018839C;
    case 0x801883A0u: goto label_801883A0;
    case 0x801883A4u: goto label_801883A4;
    case 0x801883A8u: goto label_801883A8;
    case 0x801883ACu: goto label_801883AC;
    case 0x801883B0u: goto label_801883B0;
    case 0x801883B4u: goto label_801883B4;
    case 0x801883B8u: goto label_801883B8;
    case 0x801883BCu: goto label_801883BC;
    case 0x801883C0u: goto label_801883C0;
    case 0x801883C4u: goto label_801883C4;
    case 0x801883C8u: goto label_801883C8;
    case 0x801883CCu: goto label_801883CC;
    case 0x801883D0u: goto label_801883D0;
    case 0x801883D4u: goto label_801883D4;
    case 0x801883D8u: goto label_801883D8;
    case 0x801883DCu: goto label_801883DC;
    case 0x801883E0u: goto label_801883E0;
    case 0x801883E4u: goto label_801883E4;
    case 0x801883E8u: goto label_801883E8;
    case 0x801883ECu: goto label_801883EC;
    case 0x801883F0u: goto label_801883F0;
    case 0x801883F4u: goto label_801883F4;
    case 0x801883F8u: goto label_801883F8;
    case 0x801883FCu: goto label_801883FC;
    case 0x80188400u: goto label_80188400;
    case 0x80188404u: goto label_80188404;
    case 0x80188408u: goto label_80188408;
    case 0x8018840Cu: goto label_8018840C;
    case 0x80188410u: goto label_80188410;
    case 0x80188414u: goto label_80188414;
    case 0x80188418u: goto label_80188418;
    case 0x8018841Cu: goto label_8018841C;
    case 0x80188420u: goto label_80188420;
    case 0x80188424u: goto label_80188424;
    case 0x80188428u: goto label_80188428;
    case 0x8018842Cu: goto label_8018842C;
    case 0x80188430u: goto label_80188430;
    case 0x80188434u: goto label_80188434;
    case 0x80188438u: goto label_80188438;
    case 0x8018843Cu: goto label_8018843C;
    case 0x80188440u: goto label_80188440;
    case 0x80188444u: goto label_80188444;
    case 0x80188448u: goto label_80188448;
    case 0x8018844Cu: goto label_8018844C;
    case 0x80188450u: goto label_80188450;
    case 0x80188454u: goto label_80188454;
    case 0x80188458u: goto label_80188458;
    case 0x8018845Cu: goto label_8018845C;
    case 0x80188460u: goto label_80188460;
    case 0x80188464u: goto label_80188464;
    case 0x80188468u: goto label_80188468;
    case 0x8018846Cu: goto label_8018846C;
    case 0x80188470u: goto label_80188470;
    case 0x80188474u: goto label_80188474;
    case 0x80188478u: goto label_80188478;
    case 0x8018847Cu: goto label_8018847C;
    case 0x80188480u: goto label_80188480;
    case 0x80188484u: goto label_80188484;
    case 0x80188488u: goto label_80188488;
    case 0x8018848Cu: goto label_8018848C;
    case 0x80188490u: goto label_80188490;
    case 0x80188494u: goto label_80188494;
    case 0x80188498u: goto label_80188498;
    case 0x8018849Cu: goto label_8018849C;
    case 0x801884A0u: goto label_801884A0;
    case 0x801884A4u: goto label_801884A4;
    case 0x801884A8u: goto label_801884A8;
    case 0x801884ACu: goto label_801884AC;
    case 0x801884B0u: goto label_801884B0;
    case 0x801884B4u: goto label_801884B4;
    case 0x801884B8u: goto label_801884B8;
    case 0x801884BCu: goto label_801884BC;
    case 0x801884C0u: goto label_801884C0;
    case 0x801884C4u: goto label_801884C4;
    case 0x801884C8u: goto label_801884C8;
    case 0x801884CCu: goto label_801884CC;
    case 0x801884D0u: goto label_801884D0;
    case 0x801884D4u: goto label_801884D4;
    case 0x801884D8u: goto label_801884D8;
    case 0x801884DCu: goto label_801884DC;
    case 0x801884E0u: goto label_801884E0;
    case 0x801884E4u: goto label_801884E4;
    case 0x801884E8u: goto label_801884E8;
    case 0x801884ECu: goto label_801884EC;
    case 0x801884F0u: goto label_801884F0;
    case 0x801884F4u: goto label_801884F4;
    case 0x801884F8u: goto label_801884F8;
    case 0x801884FCu: goto label_801884FC;
    case 0x80188500u: goto label_80188500;
    case 0x80188504u: goto label_80188504;
    case 0x80188508u: goto label_80188508;
    case 0x8018850Cu: goto label_8018850C;
    case 0x80188510u: goto label_80188510;
    case 0x80188514u: goto label_80188514;
    case 0x80188518u: goto label_80188518;
    case 0x8018851Cu: goto label_8018851C;
    case 0x80188520u: goto label_80188520;
    case 0x80188524u: goto label_80188524;
    case 0x80188528u: goto label_80188528;
    case 0x8018852Cu: goto label_8018852C;
    case 0x80188530u: goto label_80188530;
    case 0x80188534u: goto label_80188534;
    case 0x80188538u: goto label_80188538;
    case 0x8018853Cu: goto label_8018853C;
    case 0x80188540u: goto label_80188540;
    case 0x80188544u: goto label_80188544;
    case 0x80188548u: goto label_80188548;
    case 0x8018854Cu: goto label_8018854C;
    case 0x80188550u: goto label_80188550;
    case 0x80188554u: goto label_80188554;
    case 0x80188558u: goto label_80188558;
    case 0x8018855Cu: goto label_8018855C;
    case 0x80188560u: goto label_80188560;
    case 0x80188564u: goto label_80188564;
    case 0x80188568u: goto label_80188568;
    case 0x8018856Cu: goto label_8018856C;
    case 0x80188570u: goto label_80188570;
    case 0x80188574u: goto label_80188574;
    case 0x80188578u: goto label_80188578;
    case 0x8018857Cu: goto label_8018857C;
    case 0x80188580u: goto label_80188580;
    case 0x80188584u: goto label_80188584;
    case 0x80188588u: goto label_80188588;
    case 0x8018858Cu: goto label_8018858C;
    case 0x80188590u: goto label_80188590;
    case 0x80188594u: goto label_80188594;
    case 0x80188598u: goto label_80188598;
    case 0x8018859Cu: goto label_8018859C;
    case 0x801885A0u: goto label_801885A0;
    case 0x801885A4u: goto label_801885A4;
    case 0x801885A8u: goto label_801885A8;
    case 0x801885ACu: goto label_801885AC;
    case 0x801885B0u: goto label_801885B0;
    case 0x801885B4u: goto label_801885B4;
    case 0x801885B8u: goto label_801885B8;
    case 0x801885BCu: goto label_801885BC;
    case 0x801885C0u: goto label_801885C0;
    case 0x801885C4u: goto label_801885C4;
    case 0x801885C8u: goto label_801885C8;
    case 0x801885CCu: goto label_801885CC;
    case 0x801885D0u: goto label_801885D0;
    case 0x801885D4u: goto label_801885D4;
    case 0x801885D8u: goto label_801885D8;
    case 0x801885DCu: goto label_801885DC;
    case 0x801885E0u: goto label_801885E0;
    case 0x801885E4u: goto label_801885E4;
    case 0x801885E8u: goto label_801885E8;
    case 0x801885ECu: goto label_801885EC;
    case 0x801885F0u: goto label_801885F0;
    case 0x801885F4u: goto label_801885F4;
    case 0x801885F8u: goto label_801885F8;
    case 0x801885FCu: goto label_801885FC;
    case 0x80188600u: goto label_80188600;
    case 0x80188604u: goto label_80188604;
    case 0x80188608u: goto label_80188608;
    case 0x8018860Cu: goto label_8018860C;
    case 0x80188610u: goto label_80188610;
    case 0x80188614u: goto label_80188614;
    case 0x80188618u: goto label_80188618;
    case 0x8018861Cu: goto label_8018861C;
    case 0x80188620u: goto label_80188620;
    case 0x80188624u: goto label_80188624;
    case 0x80188628u: goto label_80188628;
    case 0x8018862Cu: goto label_8018862C;
    case 0x80188630u: goto label_80188630;
    case 0x80188634u: goto label_80188634;
    case 0x80188638u: goto label_80188638;
    case 0x8018863Cu: goto label_8018863C;
    case 0x80188640u: goto label_80188640;
    case 0x80188644u: goto label_80188644;
    case 0x80188648u: goto label_80188648;
    case 0x8018864Cu: goto label_8018864C;
    case 0x80188650u: goto label_80188650;
    case 0x80188654u: goto label_80188654;
    case 0x80188658u: goto label_80188658;
    case 0x8018865Cu: goto label_8018865C;
    case 0x80188660u: goto label_80188660;
    case 0x80188664u: goto label_80188664;
    case 0x80188668u: goto label_80188668;
    case 0x8018866Cu: goto label_8018866C;
    case 0x80188670u: goto label_80188670;
    case 0x80188674u: goto label_80188674;
    case 0x80188678u: goto label_80188678;
    case 0x8018867Cu: goto label_8018867C;
    case 0x80188680u: goto label_80188680;
    case 0x80188684u: goto label_80188684;
    case 0x80188688u: goto label_80188688;
    case 0x8018868Cu: goto label_8018868C;
    case 0x80188690u: goto label_80188690;
    case 0x80188694u: goto label_80188694;
    case 0x80188698u: goto label_80188698;
    case 0x8018869Cu: goto label_8018869C;
    case 0x801886A0u: goto label_801886A0;
    case 0x801886A4u: goto label_801886A4;
    case 0x801886A8u: goto label_801886A8;
    case 0x801886ACu: goto label_801886AC;
    case 0x801886B0u: goto label_801886B0;
    case 0x801886B4u: goto label_801886B4;
    case 0x801886B8u: goto label_801886B8;
    case 0x801886BCu: goto label_801886BC;
    case 0x801886C0u: goto label_801886C0;
    case 0x801886C4u: goto label_801886C4;
    case 0x801886C8u: goto label_801886C8;
    case 0x801886CCu: goto label_801886CC;
    case 0x801886D0u: goto label_801886D0;
    case 0x801886D4u: goto label_801886D4;
    case 0x801886D8u: goto label_801886D8;
    case 0x801886DCu: goto label_801886DC;
    case 0x801886E0u: goto label_801886E0;
    case 0x801886E4u: goto label_801886E4;
    case 0x801886E8u: goto label_801886E8;
    case 0x801886ECu: goto label_801886EC;
    case 0x801886F0u: goto label_801886F0;
    case 0x801886F4u: goto label_801886F4;
    case 0x801886F8u: goto label_801886F8;
    case 0x801886FCu: goto label_801886FC;
    case 0x80188700u: goto label_80188700;
    case 0x80188704u: goto label_80188704;
    case 0x80188708u: goto label_80188708;
    case 0x8018870Cu: goto label_8018870C;
    case 0x80188710u: goto label_80188710;
    case 0x80188714u: goto label_80188714;
    case 0x80188718u: goto label_80188718;
    case 0x8018871Cu: goto label_8018871C;
    case 0x80188720u: goto label_80188720;
    case 0x80188724u: goto label_80188724;
    case 0x80188728u: goto label_80188728;
    case 0x8018872Cu: goto label_8018872C;
    case 0x80188730u: goto label_80188730;
    case 0x80188734u: goto label_80188734;
    case 0x80188738u: goto label_80188738;
    case 0x8018873Cu: goto label_8018873C;
    case 0x80188740u: goto label_80188740;
    case 0x80188744u: goto label_80188744;
    case 0x80188748u: goto label_80188748;
    case 0x8018874Cu: goto label_8018874C;
    case 0x80188750u: goto label_80188750;
    case 0x80188754u: goto label_80188754;
    case 0x80188758u: goto label_80188758;
    case 0x8018875Cu: goto label_8018875C;
    case 0x80188760u: goto label_80188760;
    case 0x80188764u: goto label_80188764;
    case 0x80188768u: goto label_80188768;
    case 0x8018876Cu: goto label_8018876C;
    case 0x80188770u: goto label_80188770;
    case 0x80188774u: goto label_80188774;
    case 0x80188778u: goto label_80188778;
    case 0x8018877Cu: goto label_8018877C;
    case 0x80188780u: goto label_80188780;
    case 0x80188784u: goto label_80188784;
    case 0x80188788u: goto label_80188788;
    case 0x8018878Cu: goto label_8018878C;
    case 0x80188790u: goto label_80188790;
    case 0x80188794u: goto label_80188794;
    case 0x80188798u: goto label_80188798;
    case 0x8018879Cu: goto label_8018879C;
    case 0x801887A0u: goto label_801887A0;
    case 0x801887A4u: goto label_801887A4;
    case 0x801887A8u: goto label_801887A8;
    case 0x801887ACu: goto label_801887AC;
    case 0x801887B0u: goto label_801887B0;
    case 0x801887B4u: goto label_801887B4;
    case 0x801887B8u: goto label_801887B8;
    case 0x801887BCu: goto label_801887BC;
    case 0x801887C0u: goto label_801887C0;
    case 0x801887C4u: goto label_801887C4;
    case 0x801887C8u: goto label_801887C8;
    case 0x801887CCu: goto label_801887CC;
    case 0x801887D0u: goto label_801887D0;
    case 0x801887D4u: goto label_801887D4;
    case 0x801887D8u: goto label_801887D8;
    case 0x801887DCu: goto label_801887DC;
    case 0x801887E0u: goto label_801887E0;
    case 0x801887E4u: goto label_801887E4;
    case 0x801887E8u: goto label_801887E8;
    case 0x801887ECu: goto label_801887EC;
    case 0x801887F0u: goto label_801887F0;
    case 0x801887F4u: goto label_801887F4;
    case 0x801887F8u: goto label_801887F8;
    case 0x801887FCu: goto label_801887FC;
    case 0x80188800u: goto label_80188800;
    case 0x80188804u: goto label_80188804;
    case 0x80188808u: goto label_80188808;
    case 0x8018880Cu: goto label_8018880C;
    case 0x80188810u: goto label_80188810;
    case 0x80188814u: goto label_80188814;
    case 0x80188818u: goto label_80188818;
    case 0x8018881Cu: goto label_8018881C;
    case 0x80188820u: goto label_80188820;
    case 0x80188824u: goto label_80188824;
    case 0x80188828u: goto label_80188828;
    case 0x8018882Cu: goto label_8018882C;
    case 0x80188830u: goto label_80188830;
    case 0x80188834u: goto label_80188834;
    case 0x80188838u: goto label_80188838;
    case 0x8018883Cu: goto label_8018883C;
    case 0x80188840u: goto label_80188840;
    case 0x80188844u: goto label_80188844;
    case 0x80188848u: goto label_80188848;
    case 0x8018884Cu: goto label_8018884C;
    case 0x80188850u: goto label_80188850;
    case 0x80188854u: goto label_80188854;
    case 0x80188858u: goto label_80188858;
    case 0x8018885Cu: goto label_8018885C;
    case 0x80188860u: goto label_80188860;
    case 0x80188864u: goto label_80188864;
    case 0x80188868u: goto label_80188868;
    case 0x8018886Cu: goto label_8018886C;
    case 0x80188870u: goto label_80188870;
    case 0x80188874u: goto label_80188874;
    case 0x80188878u: goto label_80188878;
    case 0x8018887Cu: goto label_8018887C;
    case 0x80188880u: goto label_80188880;
    case 0x80188884u: goto label_80188884;
    case 0x80188888u: goto label_80188888;
    case 0x8018888Cu: goto label_8018888C;
    case 0x80188890u: goto label_80188890;
    case 0x80188894u: goto label_80188894;
    case 0x80188898u: goto label_80188898;
    case 0x8018889Cu: goto label_8018889C;
    case 0x801888A0u: goto label_801888A0;
    case 0x801888A4u: goto label_801888A4;
    case 0x801888A8u: goto label_801888A8;
    case 0x801888ACu: goto label_801888AC;
    case 0x801888B0u: goto label_801888B0;
    case 0x801888B4u: goto label_801888B4;
    case 0x801888B8u: goto label_801888B8;
    case 0x801888BCu: goto label_801888BC;
    case 0x801888C0u: goto label_801888C0;
    case 0x801888C4u: goto label_801888C4;
    case 0x801888C8u: goto label_801888C8;
    case 0x801888CCu: goto label_801888CC;
    case 0x801888D0u: goto label_801888D0;
    case 0x801888D4u: goto label_801888D4;
    case 0x801888D8u: goto label_801888D8;
    case 0x801888DCu: goto label_801888DC;
    case 0x801888E0u: goto label_801888E0;
    case 0x801888E4u: goto label_801888E4;
    case 0x801888E8u: goto label_801888E8;
    case 0x801888ECu: goto label_801888EC;
    case 0x801888F0u: goto label_801888F0;
    case 0x801888F4u: goto label_801888F4;
    case 0x801888F8u: goto label_801888F8;
    case 0x801888FCu: goto label_801888FC;
    case 0x80188900u: goto label_80188900;
    case 0x80188904u: goto label_80188904;
    case 0x80188908u: goto label_80188908;
    case 0x8018890Cu: goto label_8018890C;
    case 0x80188910u: goto label_80188910;
    case 0x80188914u: goto label_80188914;
    case 0x80188918u: goto label_80188918;
    case 0x8018891Cu: goto label_8018891C;
    case 0x80188920u: goto label_80188920;
    case 0x80188924u: goto label_80188924;
    case 0x80188928u: goto label_80188928;
    case 0x8018892Cu: goto label_8018892C;
    case 0x80188930u: goto label_80188930;
    case 0x80188934u: goto label_80188934;
    case 0x80188938u: goto label_80188938;
    case 0x8018893Cu: goto label_8018893C;
    case 0x80188940u: goto label_80188940;
    case 0x80188944u: goto label_80188944;
    case 0x80188948u: goto label_80188948;
    case 0x8018894Cu: goto label_8018894C;
    case 0x80188950u: goto label_80188950;
    case 0x80188954u: goto label_80188954;
    case 0x80188958u: goto label_80188958;
    case 0x8018895Cu: goto label_8018895C;
    case 0x80188960u: goto label_80188960;
    case 0x80188964u: goto label_80188964;
    case 0x80188968u: goto label_80188968;
    case 0x8018896Cu: goto label_8018896C;
    case 0x80188970u: goto label_80188970;
    case 0x80188974u: goto label_80188974;
    case 0x80188978u: goto label_80188978;
    case 0x8018897Cu: goto label_8018897C;
    case 0x80188980u: goto label_80188980;
    case 0x80188984u: goto label_80188984;
    case 0x80188988u: goto label_80188988;
    case 0x8018898Cu: goto label_8018898C;
    case 0x80188990u: goto label_80188990;
    case 0x80188994u: goto label_80188994;
    case 0x80188998u: goto label_80188998;
    case 0x8018899Cu: goto label_8018899C;
    case 0x801889A0u: goto label_801889A0;
    case 0x801889A4u: goto label_801889A4;
    case 0x801889A8u: goto label_801889A8;
    case 0x801889ACu: goto label_801889AC;
    case 0x801889B0u: goto label_801889B0;
    case 0x801889B4u: goto label_801889B4;
    case 0x801889B8u: goto label_801889B8;
    case 0x801889BCu: goto label_801889BC;
    case 0x801889C0u: goto label_801889C0;
    case 0x801889C4u: goto label_801889C4;
    case 0x801889C8u: goto label_801889C8;
    case 0x801889CCu: goto label_801889CC;
    case 0x801889D0u: goto label_801889D0;
    case 0x801889D4u: goto label_801889D4;
    case 0x801889D8u: goto label_801889D8;
    case 0x801889DCu: goto label_801889DC;
    case 0x801889E0u: goto label_801889E0;
    case 0x801889E4u: goto label_801889E4;
    case 0x801889E8u: goto label_801889E8;
    case 0x801889ECu: goto label_801889EC;
    case 0x801889F0u: goto label_801889F0;
    case 0x801889F4u: goto label_801889F4;
    case 0x801889F8u: goto label_801889F8;
    case 0x801889FCu: goto label_801889FC;
    case 0x80188A00u: goto label_80188A00;
    case 0x80188A04u: goto label_80188A04;
    case 0x80188A08u: goto label_80188A08;
    case 0x80188A0Cu: goto label_80188A0C;
    case 0x80188A10u: goto label_80188A10;
    case 0x80188A14u: goto label_80188A14;
    case 0x80188A18u: goto label_80188A18;
    case 0x80188A1Cu: goto label_80188A1C;
    case 0x80188A20u: goto label_80188A20;
    case 0x80188A24u: goto label_80188A24;
    case 0x80188A28u: goto label_80188A28;
    case 0x80188A2Cu: goto label_80188A2C;
    case 0x80188A30u: goto label_80188A30;
    case 0x80188A34u: goto label_80188A34;
    case 0x80188A38u: goto label_80188A38;
    case 0x80188A3Cu: goto label_80188A3C;
    case 0x80188A40u: goto label_80188A40;
    case 0x80188A44u: goto label_80188A44;
    case 0x80188A48u: goto label_80188A48;
    case 0x80188A4Cu: goto label_80188A4C;
    case 0x80188A50u: goto label_80188A50;
    case 0x80188A54u: goto label_80188A54;
    case 0x80188A58u: goto label_80188A58;
    case 0x80188A5Cu: goto label_80188A5C;
    case 0x80188A60u: goto label_80188A60;
    case 0x80188A64u: goto label_80188A64;
    case 0x80188A68u: goto label_80188A68;
    case 0x80188A6Cu: goto label_80188A6C;
    case 0x80188A70u: goto label_80188A70;
    case 0x80188A74u: goto label_80188A74;
    case 0x80188A78u: goto label_80188A78;
    case 0x80188A7Cu: goto label_80188A7C;
    case 0x80188A80u: goto label_80188A80;
    case 0x80188A84u: goto label_80188A84;
    case 0x80188A88u: goto label_80188A88;
    case 0x80188A8Cu: goto label_80188A8C;
    case 0x80188A90u: goto label_80188A90;
    case 0x80188A94u: goto label_80188A94;
    case 0x80188A98u: goto label_80188A98;
    case 0x80188A9Cu: goto label_80188A9C;
    case 0x80188AA0u: goto label_80188AA0;
    case 0x80188AA4u: goto label_80188AA4;
    case 0x80188AA8u: goto label_80188AA8;
    case 0x80188AACu: goto label_80188AAC;
    case 0x80188AB0u: goto label_80188AB0;
    case 0x80188AB4u: goto label_80188AB4;
    case 0x80188AB8u: goto label_80188AB8;
    case 0x80188ABCu: goto label_80188ABC;
    case 0x80188AC0u: goto label_80188AC0;
    case 0x80188AC4u: goto label_80188AC4;
    case 0x80188AC8u: goto label_80188AC8;
    case 0x80188ACCu: goto label_80188ACC;
    case 0x80188AD0u: goto label_80188AD0;
    case 0x80188AD4u: goto label_80188AD4;
    case 0x80188AD8u: goto label_80188AD8;
    case 0x80188ADCu: goto label_80188ADC;
    case 0x80188AE0u: goto label_80188AE0;
    case 0x80188AE4u: goto label_80188AE4;
    case 0x80188AE8u: goto label_80188AE8;
    case 0x80188AECu: goto label_80188AEC;
    case 0x80188AF0u: goto label_80188AF0;
    case 0x80188AF4u: goto label_80188AF4;
    case 0x80188AF8u: goto label_80188AF8;
    case 0x80188AFCu: goto label_80188AFC;
    case 0x80188B00u: goto label_80188B00;
    case 0x80188B04u: goto label_80188B04;
    case 0x80188B08u: goto label_80188B08;
    case 0x80188B0Cu: goto label_80188B0C;
    case 0x80188B10u: goto label_80188B10;
    case 0x80188B14u: goto label_80188B14;
    case 0x80188B18u: goto label_80188B18;
    case 0x80188B1Cu: goto label_80188B1C;
    case 0x80188B20u: goto label_80188B20;
    case 0x80188B24u: goto label_80188B24;
    case 0x80188B28u: goto label_80188B28;
    case 0x80188B2Cu: goto label_80188B2C;
    case 0x80188B30u: goto label_80188B30;
    case 0x80188B34u: goto label_80188B34;
    case 0x80188B38u: goto label_80188B38;
    case 0x80188B3Cu: goto label_80188B3C;
    case 0x80188B40u: goto label_80188B40;
    case 0x80188B44u: goto label_80188B44;
    case 0x80188B48u: goto label_80188B48;
    case 0x80188B4Cu: goto label_80188B4C;
    case 0x80188B50u: goto label_80188B50;
    case 0x80188B54u: goto label_80188B54;
    case 0x80188B58u: goto label_80188B58;
    case 0x80188B5Cu: goto label_80188B5C;
    case 0x80188B60u: goto label_80188B60;
    case 0x80188B64u: goto label_80188B64;
    case 0x80188B68u: goto label_80188B68;
    case 0x80188B6Cu: goto label_80188B6C;
    case 0x80188B70u: goto label_80188B70;
    case 0x80188B74u: goto label_80188B74;
    case 0x80188B78u: goto label_80188B78;
    case 0x80188B7Cu: goto label_80188B7C;
    case 0x80188B80u: goto label_80188B80;
    case 0x80188B84u: goto label_80188B84;
    case 0x80188B88u: goto label_80188B88;
    case 0x80188B8Cu: goto label_80188B8C;
    case 0x80188B90u: goto label_80188B90;
    case 0x80188B94u: goto label_80188B94;
    case 0x80188B98u: goto label_80188B98;
    case 0x80188B9Cu: goto label_80188B9C;
    case 0x80188BA0u: goto label_80188BA0;
    case 0x80188BA4u: goto label_80188BA4;
    case 0x80188BA8u: goto label_80188BA8;
    case 0x80188BACu: goto label_80188BAC;
    case 0x80188BB0u: goto label_80188BB0;
    case 0x80188BB4u: goto label_80188BB4;
    case 0x80188BB8u: goto label_80188BB8;
    case 0x80188BBCu: goto label_80188BBC;
    case 0x80188BC0u: goto label_80188BC0;
    case 0x80188BC4u: goto label_80188BC4;
    case 0x80188BC8u: goto label_80188BC8;
    case 0x80188BCCu: goto label_80188BCC;
    case 0x80188BD0u: goto label_80188BD0;
    case 0x80188BD4u: goto label_80188BD4;
    case 0x80188BD8u: goto label_80188BD8;
    case 0x80188BDCu: goto label_80188BDC;
    case 0x80188BE0u: goto label_80188BE0;
    case 0x80188BE4u: goto label_80188BE4;
    case 0x80188BE8u: goto label_80188BE8;
    case 0x80188BECu: goto label_80188BEC;
    case 0x80188BF0u: goto label_80188BF0;
    case 0x80188BF4u: goto label_80188BF4;
    case 0x80188BF8u: goto label_80188BF8;
    case 0x80188BFCu: goto label_80188BFC;
    case 0x80188C00u: goto label_80188C00;
    case 0x80188C04u: goto label_80188C04;
    case 0x80188C08u: goto label_80188C08;
    case 0x80188C0Cu: goto label_80188C0C;
    case 0x80188C10u: goto label_80188C10;
    case 0x80188C14u: goto label_80188C14;
    case 0x80188C18u: goto label_80188C18;
    case 0x80188C1Cu: goto label_80188C1C;
    case 0x80188C20u: goto label_80188C20;
    case 0x80188C24u: goto label_80188C24;
    case 0x80188C28u: goto label_80188C28;
    case 0x80188C2Cu: goto label_80188C2C;
    case 0x80188C30u: goto label_80188C30;
    case 0x80188C34u: goto label_80188C34;
    case 0x80188C38u: goto label_80188C38;
    case 0x80188C3Cu: goto label_80188C3C;
    case 0x80188C40u: goto label_80188C40;
    case 0x80188C44u: goto label_80188C44;
    case 0x80188C48u: goto label_80188C48;
    case 0x80188C4Cu: goto label_80188C4C;
    case 0x80188C50u: goto label_80188C50;
    case 0x80188C54u: goto label_80188C54;
    case 0x80188C58u: goto label_80188C58;
    case 0x80188C5Cu: goto label_80188C5C;
    case 0x80188C60u: goto label_80188C60;
    case 0x80188C64u: goto label_80188C64;
    case 0x80188C68u: goto label_80188C68;
    case 0x80188C6Cu: goto label_80188C6C;
    case 0x80188C70u: goto label_80188C70;
    case 0x80188C74u: goto label_80188C74;
    case 0x80188C78u: goto label_80188C78;
    case 0x80188C7Cu: goto label_80188C7C;
    case 0x80188C80u: goto label_80188C80;
    case 0x80188C84u: goto label_80188C84;
    case 0x80188C88u: goto label_80188C88;
    case 0x80188C8Cu: goto label_80188C8C;
    case 0x80188C90u: goto label_80188C90;
    case 0x80188C94u: goto label_80188C94;
    case 0x80188C98u: goto label_80188C98;
    case 0x80188C9Cu: goto label_80188C9C;
    case 0x80188CA0u: goto label_80188CA0;
    case 0x80188CA4u: goto label_80188CA4;
    case 0x80188CA8u: goto label_80188CA8;
    case 0x80188CACu: goto label_80188CAC;
    case 0x80188CB0u: goto label_80188CB0;
    case 0x80188CB4u: goto label_80188CB4;
    case 0x80188CB8u: goto label_80188CB8;
    case 0x80188CBCu: goto label_80188CBC;
    case 0x80188CC0u: goto label_80188CC0;
    case 0x80188CC4u: goto label_80188CC4;
    case 0x80188CC8u: goto label_80188CC8;
    case 0x80188CCCu: goto label_80188CCC;
    case 0x80188CD0u: goto label_80188CD0;
    case 0x80188CD4u: goto label_80188CD4;
    case 0x80188CD8u: goto label_80188CD8;
    case 0x80188CDCu: goto label_80188CDC;
    case 0x80188CE0u: goto label_80188CE0;
    case 0x80188CE4u: goto label_80188CE4;
    case 0x80188CE8u: goto label_80188CE8;
    case 0x80188CECu: goto label_80188CEC;
    case 0x80188CF0u: goto label_80188CF0;
    case 0x80188CF4u: goto label_80188CF4;
    case 0x80188CF8u: goto label_80188CF8;
    case 0x80188CFCu: goto label_80188CFC;
    case 0x80188D00u: goto label_80188D00;
    case 0x80188D04u: goto label_80188D04;
    case 0x80188D08u: goto label_80188D08;
    case 0x80188D0Cu: goto label_80188D0C;
    case 0x80188D10u: goto label_80188D10;
    case 0x80188D14u: goto label_80188D14;
    case 0x80188D18u: goto label_80188D18;
    case 0x80188D1Cu: goto label_80188D1C;
    case 0x80188D20u: goto label_80188D20;
    case 0x80188D24u: goto label_80188D24;
    case 0x80188D28u: goto label_80188D28;
    case 0x80188D2Cu: goto label_80188D2C;
    case 0x80188D30u: goto label_80188D30;
    case 0x80188D34u: goto label_80188D34;
    case 0x80188D38u: goto label_80188D38;
    case 0x80188D3Cu: goto label_80188D3C;
    case 0x80188D40u: goto label_80188D40;
    case 0x80188D44u: goto label_80188D44;
    case 0x80188D48u: goto label_80188D48;
    case 0x80188D4Cu: goto label_80188D4C;
    case 0x80188D50u: goto label_80188D50;
    case 0x80188D54u: goto label_80188D54;
    case 0x80188D58u: goto label_80188D58;
    case 0x80188D5Cu: goto label_80188D5C;
    case 0x80188D60u: goto label_80188D60;
    case 0x80188D64u: goto label_80188D64;
    case 0x80188D68u: goto label_80188D68;
    case 0x80188D6Cu: goto label_80188D6C;
    case 0x80188D70u: goto label_80188D70;
    case 0x80188D74u: goto label_80188D74;
    case 0x80188D78u: goto label_80188D78;
    case 0x80188D7Cu: goto label_80188D7C;
    case 0x80188D80u: goto label_80188D80;
    case 0x80188D84u: goto label_80188D84;
    case 0x80188D88u: goto label_80188D88;
    case 0x80188D8Cu: goto label_80188D8C;
    case 0x80188D90u: goto label_80188D90;
    case 0x80188D94u: goto label_80188D94;
    case 0x80188D98u: goto label_80188D98;
    case 0x80188D9Cu: goto label_80188D9C;
    case 0x80188DA0u: goto label_80188DA0;
    case 0x80188DA4u: goto label_80188DA4;
    case 0x80188DA8u: goto label_80188DA8;
    case 0x80188DACu: goto label_80188DAC;
    case 0x80188DB0u: goto label_80188DB0;
    case 0x80188DB4u: goto label_80188DB4;
    case 0x80188DB8u: goto label_80188DB8;
    case 0x80188DBCu: goto label_80188DBC;
    case 0x80188DC0u: goto label_80188DC0;
    case 0x80188DC4u: goto label_80188DC4;
    case 0x80188DC8u: goto label_80188DC8;
    case 0x80188DCCu: goto label_80188DCC;
    case 0x80188DD0u: goto label_80188DD0;
    case 0x80188DD4u: goto label_80188DD4;
    case 0x80188DD8u: goto label_80188DD8;
    case 0x80188DDCu: goto label_80188DDC;
    case 0x80188DE0u: goto label_80188DE0;
    case 0x80188DE4u: goto label_80188DE4;
    case 0x80188DE8u: goto label_80188DE8;
    case 0x80188DECu: goto label_80188DEC;
    case 0x80188DF0u: goto label_80188DF0;
    case 0x80188DF4u: goto label_80188DF4;
    case 0x80188DF8u: goto label_80188DF8;
    case 0x80188DFCu: goto label_80188DFC;
    case 0x80188E00u: goto label_80188E00;
    case 0x80188E04u: goto label_80188E04;
    case 0x80188E08u: goto label_80188E08;
    case 0x80188E0Cu: goto label_80188E0C;
    case 0x80188E10u: goto label_80188E10;
    case 0x80188E14u: goto label_80188E14;
    case 0x80188E18u: goto label_80188E18;
    case 0x80188E1Cu: goto label_80188E1C;
    case 0x80188E20u: goto label_80188E20;
    case 0x80188E24u: goto label_80188E24;
    case 0x80188E28u: goto label_80188E28;
    case 0x80188E2Cu: goto label_80188E2C;
    case 0x80188E30u: goto label_80188E30;
    case 0x80188E34u: goto label_80188E34;
    case 0x80188E38u: goto label_80188E38;
    case 0x80188E3Cu: goto label_80188E3C;
    case 0x80188E40u: goto label_80188E40;
    case 0x80188E44u: goto label_80188E44;
    case 0x80188E48u: goto label_80188E48;
    case 0x80188E4Cu: goto label_80188E4C;
    case 0x80188E50u: goto label_80188E50;
    case 0x80188E54u: goto label_80188E54;
    case 0x80188E58u: goto label_80188E58;
    case 0x80188E5Cu: goto label_80188E5C;
    case 0x80188E60u: goto label_80188E60;
    case 0x80188E64u: goto label_80188E64;
    case 0x80188E68u: goto label_80188E68;
    case 0x80188E6Cu: goto label_80188E6C;
    case 0x80188E70u: goto label_80188E70;
    case 0x80188E74u: goto label_80188E74;
    case 0x80188E78u: goto label_80188E78;
    case 0x80188E7Cu: goto label_80188E7C;
    case 0x80188E80u: goto label_80188E80;
    case 0x80188E84u: goto label_80188E84;
    case 0x80188E88u: goto label_80188E88;
    case 0x80188E8Cu: goto label_80188E8C;
    case 0x80188E90u: goto label_80188E90;
    case 0x80188E94u: goto label_80188E94;
    case 0x80188E98u: goto label_80188E98;
    case 0x80188E9Cu: goto label_80188E9C;
    case 0x80188EA0u: goto label_80188EA0;
    case 0x80188EA4u: goto label_80188EA4;
    case 0x80188EA8u: goto label_80188EA8;
    case 0x80188EACu: goto label_80188EAC;
    case 0x80188EB0u: goto label_80188EB0;
    case 0x80188EB4u: goto label_80188EB4;
    case 0x80188EB8u: goto label_80188EB8;
    case 0x80188EBCu: goto label_80188EBC;
    case 0x80188EC0u: goto label_80188EC0;
    case 0x80188EC4u: goto label_80188EC4;
    case 0x80188EC8u: goto label_80188EC8;
    case 0x80188ECCu: goto label_80188ECC;
    case 0x80188ED0u: goto label_80188ED0;
    case 0x80188ED4u: goto label_80188ED4;
    case 0x80188ED8u: goto label_80188ED8;
    case 0x80188EDCu: goto label_80188EDC;
    case 0x80188EE0u: goto label_80188EE0;
    case 0x80188EE4u: goto label_80188EE4;
    case 0x80188EE8u: goto label_80188EE8;
    case 0x80188EECu: goto label_80188EEC;
    case 0x80188EF0u: goto label_80188EF0;
    case 0x80188EF4u: goto label_80188EF4;
    case 0x80188EF8u: goto label_80188EF8;
    case 0x80188EFCu: goto label_80188EFC;
    case 0x80188F00u: goto label_80188F00;
    case 0x80188F04u: goto label_80188F04;
    case 0x80188F08u: goto label_80188F08;
    case 0x80188F0Cu: goto label_80188F0C;
    case 0x80188F10u: goto label_80188F10;
    case 0x80188F14u: goto label_80188F14;
    case 0x80188F18u: goto label_80188F18;
    case 0x80188F1Cu: goto label_80188F1C;
    case 0x80188F20u: goto label_80188F20;
    case 0x80188F24u: goto label_80188F24;
    case 0x80188F28u: goto label_80188F28;
    case 0x80188F2Cu: goto label_80188F2C;
    case 0x80188F30u: goto label_80188F30;
    case 0x80188F34u: goto label_80188F34;
    case 0x80188F38u: goto label_80188F38;
    case 0x80188F3Cu: goto label_80188F3C;
    case 0x80188F40u: goto label_80188F40;
    case 0x80188F44u: goto label_80188F44;
    case 0x80188F48u: goto label_80188F48;
    case 0x80188F4Cu: goto label_80188F4C;
    case 0x80188F50u: goto label_80188F50;
    case 0x80188F54u: goto label_80188F54;
    case 0x80188F58u: goto label_80188F58;
    case 0x80188F5Cu: goto label_80188F5C;
    case 0x80188F60u: goto label_80188F60;
    case 0x80188F64u: goto label_80188F64;
    case 0x80188F68u: goto label_80188F68;
    case 0x80188F6Cu: goto label_80188F6C;
    case 0x80188F70u: goto label_80188F70;
    case 0x80188F74u: goto label_80188F74;
    case 0x80188F78u: goto label_80188F78;
    case 0x80188F7Cu: goto label_80188F7C;
    case 0x80188F80u: goto label_80188F80;
    case 0x80188F84u: goto label_80188F84;
    case 0x80188F88u: goto label_80188F88;
    case 0x80188F8Cu: goto label_80188F8C;
    case 0x80188F90u: goto label_80188F90;
    case 0x80188F94u: goto label_80188F94;
    case 0x80188F98u: goto label_80188F98;
    case 0x80188F9Cu: goto label_80188F9C;
    case 0x80188FA0u: goto label_80188FA0;
    case 0x80188FA4u: goto label_80188FA4;
    case 0x80188FA8u: goto label_80188FA8;
    case 0x80188FACu: goto label_80188FAC;
    case 0x80188FB0u: goto label_80188FB0;
    case 0x80188FB4u: goto label_80188FB4;
    case 0x80188FB8u: goto label_80188FB8;
    case 0x80188FBCu: goto label_80188FBC;
    case 0x80188FC0u: goto label_80188FC0;
    case 0x80188FC4u: goto label_80188FC4;
    case 0x80188FC8u: goto label_80188FC8;
    case 0x80188FCCu: goto label_80188FCC;
    case 0x80188FD0u: goto label_80188FD0;
    case 0x80188FD4u: goto label_80188FD4;
    case 0x80188FD8u: goto label_80188FD8;
    case 0x80188FDCu: goto label_80188FDC;
    case 0x80188FE0u: goto label_80188FE0;
    case 0x80188FE4u: goto label_80188FE4;
    case 0x80188FE8u: goto label_80188FE8;
    case 0x80188FECu: goto label_80188FEC;
    case 0x80188FF0u: goto label_80188FF0;
    case 0x80188FF4u: goto label_80188FF4;
    case 0x80188FF8u: goto label_80188FF8;
    case 0x80188FFCu: goto label_80188FFC;
    case 0x80189000u: goto label_80189000;
    case 0x80189004u: goto label_80189004;
    case 0x80189008u: goto label_80189008;
    case 0x8018900Cu: goto label_8018900C;
    case 0x80189010u: goto label_80189010;
    case 0x80189014u: goto label_80189014;
    case 0x80189018u: goto label_80189018;
    case 0x8018901Cu: goto label_8018901C;
    case 0x80189020u: goto label_80189020;
    case 0x80189024u: goto label_80189024;
    case 0x80189028u: goto label_80189028;
    case 0x8018902Cu: goto label_8018902C;
    case 0x80189030u: goto label_80189030;
    case 0x80189034u: goto label_80189034;
    case 0x80189038u: goto label_80189038;
    case 0x8018903Cu: goto label_8018903C;
    case 0x80189040u: goto label_80189040;
    case 0x80189044u: goto label_80189044;
    case 0x80189048u: goto label_80189048;
    case 0x8018904Cu: goto label_8018904C;
    case 0x80189050u: goto label_80189050;
    case 0x80189054u: goto label_80189054;
    case 0x80189058u: goto label_80189058;
    case 0x8018905Cu: goto label_8018905C;
    case 0x80189060u: goto label_80189060;
    case 0x80189064u: goto label_80189064;
    case 0x80189068u: goto label_80189068;
    case 0x8018906Cu: goto label_8018906C;
    case 0x80189070u: goto label_80189070;
    case 0x80189074u: goto label_80189074;
    case 0x80189078u: goto label_80189078;
    case 0x8018907Cu: goto label_8018907C;
    case 0x80189080u: goto label_80189080;
    case 0x80189084u: goto label_80189084;
    case 0x80189088u: goto label_80189088;
    case 0x8018908Cu: goto label_8018908C;
    case 0x80189090u: goto label_80189090;
    case 0x80189094u: goto label_80189094;
    case 0x80189098u: goto label_80189098;
    case 0x8018909Cu: goto label_8018909C;
    case 0x801890A0u: goto label_801890A0;
    case 0x801890A4u: goto label_801890A4;
    case 0x801890A8u: goto label_801890A8;
    case 0x801890ACu: goto label_801890AC;
    case 0x801890B0u: goto label_801890B0;
    case 0x801890B4u: goto label_801890B4;
    case 0x801890B8u: goto label_801890B8;
    case 0x801890BCu: goto label_801890BC;
    case 0x801890C0u: goto label_801890C0;
    case 0x801890C4u: goto label_801890C4;
    case 0x801890C8u: goto label_801890C8;
    case 0x801890CCu: goto label_801890CC;
    case 0x801890D0u: goto label_801890D0;
    case 0x801890D4u: goto label_801890D4;
    case 0x801890D8u: goto label_801890D8;
    case 0x801890DCu: goto label_801890DC;
    case 0x801890E0u: goto label_801890E0;
    case 0x801890E4u: goto label_801890E4;
    case 0x801890E8u: goto label_801890E8;
    case 0x801890ECu: goto label_801890EC;
    case 0x801890F0u: goto label_801890F0;
    case 0x801890F4u: goto label_801890F4;
    case 0x801890F8u: goto label_801890F8;
    case 0x801890FCu: goto label_801890FC;
    case 0x80189100u: goto label_80189100;
    case 0x80189104u: goto label_80189104;
    case 0x80189108u: goto label_80189108;
    case 0x8018910Cu: goto label_8018910C;
    case 0x80189110u: goto label_80189110;
    case 0x80189114u: goto label_80189114;
    case 0x80189118u: goto label_80189118;
    case 0x8018911Cu: goto label_8018911C;
    case 0x80189120u: goto label_80189120;
    case 0x80189124u: goto label_80189124;
    case 0x80189128u: goto label_80189128;
    case 0x8018912Cu: goto label_8018912C;
    case 0x80189130u: goto label_80189130;
    case 0x80189134u: goto label_80189134;
    case 0x80189138u: goto label_80189138;
    case 0x8018913Cu: goto label_8018913C;
    case 0x80189140u: goto label_80189140;
    case 0x80189144u: goto label_80189144;
    case 0x80189148u: goto label_80189148;
    case 0x8018914Cu: goto label_8018914C;
    case 0x80189150u: goto label_80189150;
    case 0x80189154u: goto label_80189154;
    case 0x80189158u: goto label_80189158;
    case 0x8018915Cu: goto label_8018915C;
    case 0x80189160u: goto label_80189160;
    case 0x80189164u: goto label_80189164;
    case 0x80189168u: goto label_80189168;
    case 0x8018916Cu: goto label_8018916C;
    case 0x80189170u: goto label_80189170;
    case 0x80189174u: goto label_80189174;
    case 0x80189178u: goto label_80189178;
    case 0x8018917Cu: goto label_8018917C;
    case 0x80189180u: goto label_80189180;
    case 0x80189184u: goto label_80189184;
    case 0x80189188u: goto label_80189188;
    case 0x8018918Cu: goto label_8018918C;
    case 0x80189190u: goto label_80189190;
    case 0x80189194u: goto label_80189194;
    case 0x80189198u: goto label_80189198;
    case 0x8018919Cu: goto label_8018919C;
    case 0x801891A0u: goto label_801891A0;
    case 0x801891A4u: goto label_801891A4;
    case 0x801891A8u: goto label_801891A8;
    case 0x801891ACu: goto label_801891AC;
    case 0x801891B0u: goto label_801891B0;
    case 0x801891B4u: goto label_801891B4;
    case 0x801891B8u: goto label_801891B8;
    case 0x801891BCu: goto label_801891BC;
    case 0x801891C0u: goto label_801891C0;
    case 0x801891C4u: goto label_801891C4;
    case 0x801891C8u: goto label_801891C8;
    case 0x801891CCu: goto label_801891CC;
    case 0x801891D0u: goto label_801891D0;
    case 0x801891D4u: goto label_801891D4;
    case 0x801891D8u: goto label_801891D8;
    case 0x801891DCu: goto label_801891DC;
    case 0x801891E0u: goto label_801891E0;
    case 0x801891E4u: goto label_801891E4;
    case 0x801891E8u: goto label_801891E8;
    case 0x801891ECu: goto label_801891EC;
    case 0x801891F0u: goto label_801891F0;
    case 0x801891F4u: goto label_801891F4;
    case 0x801891F8u: goto label_801891F8;
    case 0x801891FCu: goto label_801891FC;
    case 0x80189200u: goto label_80189200;
    case 0x80189204u: goto label_80189204;
    case 0x80189208u: goto label_80189208;
    case 0x8018920Cu: goto label_8018920C;
    case 0x80189210u: goto label_80189210;
    case 0x80189214u: goto label_80189214;
    case 0x80189218u: goto label_80189218;
    case 0x8018921Cu: goto label_8018921C;
    case 0x80189220u: goto label_80189220;
    case 0x80189224u: goto label_80189224;
    case 0x80189228u: goto label_80189228;
    case 0x8018922Cu: goto label_8018922C;
    case 0x80189230u: goto label_80189230;
    case 0x80189234u: goto label_80189234;
    case 0x80189238u: goto label_80189238;
    case 0x8018923Cu: goto label_8018923C;
    case 0x80189240u: goto label_80189240;
    case 0x80189244u: goto label_80189244;
    case 0x80189248u: goto label_80189248;
    case 0x8018924Cu: goto label_8018924C;
    case 0x80189250u: goto label_80189250;
    case 0x80189254u: goto label_80189254;
    case 0x80189258u: goto label_80189258;
    case 0x8018925Cu: goto label_8018925C;
    case 0x80189260u: goto label_80189260;
    case 0x80189264u: goto label_80189264;
    case 0x80189268u: goto label_80189268;
    case 0x8018926Cu: goto label_8018926C;
    case 0x80189270u: goto label_80189270;
    case 0x80189274u: goto label_80189274;
    case 0x80189278u: goto label_80189278;
    case 0x8018927Cu: goto label_8018927C;
    case 0x80189280u: goto label_80189280;
    case 0x80189284u: goto label_80189284;
    case 0x80189288u: goto label_80189288;
    case 0x8018928Cu: goto label_8018928C;
    case 0x80189290u: goto label_80189290;
    case 0x80189294u: goto label_80189294;
    case 0x80189298u: goto label_80189298;
    case 0x8018929Cu: goto label_8018929C;
    case 0x801892A0u: goto label_801892A0;
    case 0x801892A4u: goto label_801892A4;
    case 0x801892A8u: goto label_801892A8;
    case 0x801892ACu: goto label_801892AC;
    case 0x801892B0u: goto label_801892B0;
    case 0x801892B4u: goto label_801892B4;
    case 0x801892B8u: goto label_801892B8;
    case 0x801892BCu: goto label_801892BC;
    case 0x801892C0u: goto label_801892C0;
    case 0x801892C4u: goto label_801892C4;
    case 0x801892C8u: goto label_801892C8;
    case 0x801892CCu: goto label_801892CC;
    case 0x801892D0u: goto label_801892D0;
    case 0x801892D4u: goto label_801892D4;
    case 0x801892D8u: goto label_801892D8;
    case 0x801892DCu: goto label_801892DC;
    case 0x801892E0u: goto label_801892E0;
    case 0x801892E4u: goto label_801892E4;
    case 0x801892E8u: goto label_801892E8;
    case 0x801892ECu: goto label_801892EC;
    case 0x801892F0u: goto label_801892F0;
    case 0x801892F4u: goto label_801892F4;
    case 0x801892F8u: goto label_801892F8;
    case 0x801892FCu: goto label_801892FC;
    case 0x80189300u: goto label_80189300;
    case 0x80189304u: goto label_80189304;
    case 0x80189308u: goto label_80189308;
    case 0x8018930Cu: goto label_8018930C;
    case 0x80189310u: goto label_80189310;
    case 0x80189314u: goto label_80189314;
    case 0x80189318u: goto label_80189318;
    case 0x8018931Cu: goto label_8018931C;
    case 0x80189320u: goto label_80189320;
    case 0x80189324u: goto label_80189324;
    case 0x80189328u: goto label_80189328;
    case 0x8018932Cu: goto label_8018932C;
    case 0x80189330u: goto label_80189330;
    case 0x80189334u: goto label_80189334;
    case 0x80189338u: goto label_80189338;
    case 0x8018933Cu: goto label_8018933C;
    case 0x80189340u: goto label_80189340;
    case 0x80189344u: goto label_80189344;
    case 0x80189348u: goto label_80189348;
    case 0x8018934Cu: goto label_8018934C;
    case 0x80189350u: goto label_80189350;
    case 0x80189354u: goto label_80189354;
    case 0x80189358u: goto label_80189358;
    case 0x8018935Cu: goto label_8018935C;
    case 0x80189360u: goto label_80189360;
    case 0x80189364u: goto label_80189364;
    case 0x80189368u: goto label_80189368;
    case 0x8018936Cu: goto label_8018936C;
    case 0x80189370u: goto label_80189370;
    case 0x80189374u: goto label_80189374;
    case 0x80189378u: goto label_80189378;
    case 0x8018937Cu: goto label_8018937C;
    case 0x80189380u: goto label_80189380;
    case 0x80189384u: goto label_80189384;
    case 0x80189388u: goto label_80189388;
    case 0x8018938Cu: goto label_8018938C;
    case 0x80189390u: goto label_80189390;
    case 0x80189394u: goto label_80189394;
    case 0x80189398u: goto label_80189398;
    case 0x8018939Cu: goto label_8018939C;
    case 0x801893A0u: goto label_801893A0;
    case 0x801893A4u: goto label_801893A4;
    case 0x801893A8u: goto label_801893A8;
    case 0x801893ACu: goto label_801893AC;
    case 0x801893B0u: goto label_801893B0;
    case 0x801893B4u: goto label_801893B4;
    case 0x801893B8u: goto label_801893B8;
    case 0x801893BCu: goto label_801893BC;
    case 0x801893C0u: goto label_801893C0;
    case 0x801893C4u: goto label_801893C4;
    case 0x801893C8u: goto label_801893C8;
    case 0x801893CCu: goto label_801893CC;
    case 0x801893D0u: goto label_801893D0;
    case 0x801893D4u: goto label_801893D4;
    case 0x801893D8u: goto label_801893D8;
    case 0x801893DCu: goto label_801893DC;
    case 0x801893E0u: goto label_801893E0;
    case 0x801893E4u: goto label_801893E4;
    case 0x801893E8u: goto label_801893E8;
    case 0x801893ECu: goto label_801893EC;
    case 0x801893F0u: goto label_801893F0;
    case 0x801893F4u: goto label_801893F4;
    case 0x801893F8u: goto label_801893F8;
    case 0x801893FCu: goto label_801893FC;
    case 0x80189400u: goto label_80189400;
    case 0x80189404u: goto label_80189404;
    case 0x80189408u: goto label_80189408;
    case 0x8018940Cu: goto label_8018940C;
    case 0x80189410u: goto label_80189410;
    case 0x80189414u: goto label_80189414;
    case 0x80189418u: goto label_80189418;
    case 0x8018941Cu: goto label_8018941C;
    case 0x80189420u: goto label_80189420;
    case 0x80189424u: goto label_80189424;
    case 0x80189428u: goto label_80189428;
    case 0x8018942Cu: goto label_8018942C;
    case 0x80189430u: goto label_80189430;
    case 0x80189434u: goto label_80189434;
    case 0x80189438u: goto label_80189438;
    case 0x8018943Cu: goto label_8018943C;
    case 0x80189440u: goto label_80189440;
    case 0x80189444u: goto label_80189444;
    case 0x80189448u: goto label_80189448;
    case 0x8018944Cu: goto label_8018944C;
    case 0x80189450u: goto label_80189450;
    case 0x80189454u: goto label_80189454;
    case 0x80189458u: goto label_80189458;
    case 0x8018945Cu: goto label_8018945C;
    case 0x80189460u: goto label_80189460;
    case 0x80189464u: goto label_80189464;
    case 0x80189468u: goto label_80189468;
    case 0x8018946Cu: goto label_8018946C;
    case 0x80189470u: goto label_80189470;
    case 0x80189474u: goto label_80189474;
    case 0x80189478u: goto label_80189478;
    case 0x8018947Cu: goto label_8018947C;
    case 0x80189480u: goto label_80189480;
    case 0x80189484u: goto label_80189484;
    case 0x80189488u: goto label_80189488;
    case 0x8018948Cu: goto label_8018948C;
    case 0x80189490u: goto label_80189490;
    case 0x80189494u: goto label_80189494;
    case 0x80189498u: goto label_80189498;
    case 0x8018949Cu: goto label_8018949C;
    case 0x801894A0u: goto label_801894A0;
    case 0x801894A4u: goto label_801894A4;
    case 0x801894A8u: goto label_801894A8;
    case 0x801894ACu: goto label_801894AC;
    case 0x801894B0u: goto label_801894B0;
    case 0x801894B4u: goto label_801894B4;
    case 0x801894B8u: goto label_801894B8;
    case 0x801894BCu: goto label_801894BC;
    case 0x801894C0u: goto label_801894C0;
    case 0x801894C4u: goto label_801894C4;
    case 0x801894C8u: goto label_801894C8;
    case 0x801894CCu: goto label_801894CC;
    case 0x801894D0u: goto label_801894D0;
    case 0x801894D4u: goto label_801894D4;
    case 0x801894D8u: goto label_801894D8;
    case 0x801894DCu: goto label_801894DC;
    case 0x801894E0u: goto label_801894E0;
    case 0x801894E4u: goto label_801894E4;
    case 0x801894E8u: goto label_801894E8;
    case 0x801894ECu: goto label_801894EC;
    case 0x801894F0u: goto label_801894F0;
    case 0x801894F4u: goto label_801894F4;
    case 0x801894F8u: goto label_801894F8;
    case 0x801894FCu: goto label_801894FC;
    case 0x80189500u: goto label_80189500;
    case 0x80189504u: goto label_80189504;
    case 0x80189508u: goto label_80189508;
    case 0x8018950Cu: goto label_8018950C;
    case 0x80189510u: goto label_80189510;
    case 0x80189514u: goto label_80189514;
    case 0x80189518u: goto label_80189518;
    case 0x8018951Cu: goto label_8018951C;
    case 0x80189520u: goto label_80189520;
    case 0x80189524u: goto label_80189524;
    case 0x80189528u: goto label_80189528;
    case 0x8018952Cu: goto label_8018952C;
    case 0x80189530u: goto label_80189530;
    case 0x80189534u: goto label_80189534;
    case 0x80189538u: goto label_80189538;
    case 0x8018953Cu: goto label_8018953C;
    case 0x80189540u: goto label_80189540;
    case 0x80189544u: goto label_80189544;
    case 0x80189548u: goto label_80189548;
    case 0x8018954Cu: goto label_8018954C;
    case 0x80189550u: goto label_80189550;
    case 0x80189554u: goto label_80189554;
    case 0x80189558u: goto label_80189558;
    case 0x8018955Cu: goto label_8018955C;
    case 0x80189560u: goto label_80189560;
    case 0x80189564u: goto label_80189564;
    case 0x80189568u: goto label_80189568;
    case 0x8018956Cu: goto label_8018956C;
    case 0x80189570u: goto label_80189570;
    case 0x80189574u: goto label_80189574;
    case 0x80189578u: goto label_80189578;
    case 0x8018957Cu: goto label_8018957C;
    case 0x80189580u: goto label_80189580;
    case 0x80189584u: goto label_80189584;
    case 0x80189588u: goto label_80189588;
    case 0x8018958Cu: goto label_8018958C;
    case 0x80189590u: goto label_80189590;
    case 0x80189594u: goto label_80189594;
    case 0x80189598u: goto label_80189598;
    case 0x8018959Cu: goto label_8018959C;
    case 0x801895A0u: goto label_801895A0;
    case 0x801895A4u: goto label_801895A4;
    case 0x801895A8u: goto label_801895A8;
    case 0x801895ACu: goto label_801895AC;
    case 0x801895B0u: goto label_801895B0;
    case 0x801895B4u: goto label_801895B4;
    case 0x801895B8u: goto label_801895B8;
    case 0x801895BCu: goto label_801895BC;
    case 0x801895C0u: goto label_801895C0;
    case 0x801895C4u: goto label_801895C4;
    case 0x801895C8u: goto label_801895C8;
    case 0x801895CCu: goto label_801895CC;
    case 0x801895D0u: goto label_801895D0;
    case 0x801895D4u: goto label_801895D4;
    case 0x801895D8u: goto label_801895D8;
    case 0x801895DCu: goto label_801895DC;
    case 0x801895E0u: goto label_801895E0;
    case 0x801895E4u: goto label_801895E4;
    case 0x801895E8u: goto label_801895E8;
    case 0x801895ECu: goto label_801895EC;
    case 0x801895F0u: goto label_801895F0;
    case 0x801895F4u: goto label_801895F4;
    case 0x801895F8u: goto label_801895F8;
    case 0x801895FCu: goto label_801895FC;
    case 0x80189600u: goto label_80189600;
    case 0x80189604u: goto label_80189604;
    case 0x80189608u: goto label_80189608;
    case 0x8018960Cu: goto label_8018960C;
    case 0x80189610u: goto label_80189610;
    case 0x80189614u: goto label_80189614;
    case 0x80189618u: goto label_80189618;
    case 0x8018961Cu: goto label_8018961C;
    case 0x80189620u: goto label_80189620;
    case 0x80189624u: goto label_80189624;
    case 0x80189628u: goto label_80189628;
    case 0x8018962Cu: goto label_8018962C;
    case 0x80189630u: goto label_80189630;
    case 0x80189634u: goto label_80189634;
    case 0x80189638u: goto label_80189638;
    case 0x8018963Cu: goto label_8018963C;
    case 0x80189640u: goto label_80189640;
    case 0x80189644u: goto label_80189644;
    case 0x80189648u: goto label_80189648;
    case 0x8018964Cu: goto label_8018964C;
    case 0x80189650u: goto label_80189650;
    case 0x80189654u: goto label_80189654;
    case 0x80189658u: goto label_80189658;
    case 0x8018965Cu: goto label_8018965C;
    case 0x80189660u: goto label_80189660;
    case 0x80189664u: goto label_80189664;
    case 0x80189668u: goto label_80189668;
    case 0x8018966Cu: goto label_8018966C;
    case 0x80189670u: goto label_80189670;
    case 0x80189674u: goto label_80189674;
    case 0x80189678u: goto label_80189678;
    case 0x8018967Cu: goto label_8018967C;
    case 0x80189680u: goto label_80189680;
    case 0x80189684u: goto label_80189684;
    case 0x80189688u: goto label_80189688;
    case 0x8018968Cu: goto label_8018968C;
    case 0x80189690u: goto label_80189690;
    case 0x80189694u: goto label_80189694;
    case 0x80189698u: goto label_80189698;
    case 0x8018969Cu: goto label_8018969C;
    case 0x801896A0u: goto label_801896A0;
    case 0x801896A4u: goto label_801896A4;
    case 0x801896A8u: goto label_801896A8;
    case 0x801896ACu: goto label_801896AC;
    case 0x801896B0u: goto label_801896B0;
    case 0x801896B4u: goto label_801896B4;
    case 0x801896B8u: goto label_801896B8;
    case 0x801896BCu: goto label_801896BC;
    case 0x801896C0u: goto label_801896C0;
    case 0x801896C4u: goto label_801896C4;
    case 0x801896C8u: goto label_801896C8;
    case 0x801896CCu: goto label_801896CC;
    case 0x801896D0u: goto label_801896D0;
    case 0x801896D4u: goto label_801896D4;
    case 0x801896D8u: goto label_801896D8;
    case 0x801896DCu: goto label_801896DC;
    case 0x801896E0u: goto label_801896E0;
    case 0x801896E4u: goto label_801896E4;
    case 0x801896E8u: goto label_801896E8;
    case 0x801896ECu: goto label_801896EC;
    case 0x801896F0u: goto label_801896F0;
    case 0x801896F4u: goto label_801896F4;
    case 0x801896F8u: goto label_801896F8;
    case 0x801896FCu: goto label_801896FC;
    case 0x80189700u: goto label_80189700;
    case 0x80189704u: goto label_80189704;
    case 0x80189708u: goto label_80189708;
    case 0x8018970Cu: goto label_8018970C;
    case 0x80189710u: goto label_80189710;
    case 0x80189714u: goto label_80189714;
    case 0x80189718u: goto label_80189718;
    case 0x8018971Cu: goto label_8018971C;
    case 0x80189720u: goto label_80189720;
    case 0x80189724u: goto label_80189724;
    case 0x80189728u: goto label_80189728;
    case 0x8018972Cu: goto label_8018972C;
    case 0x80189730u: goto label_80189730;
    case 0x80189734u: goto label_80189734;
    case 0x80189738u: goto label_80189738;
    case 0x8018973Cu: goto label_8018973C;
    case 0x80189740u: goto label_80189740;
    case 0x80189744u: goto label_80189744;
    case 0x80189748u: goto label_80189748;
    case 0x8018974Cu: goto label_8018974C;
    case 0x80189750u: goto label_80189750;
    case 0x80189754u: goto label_80189754;
    case 0x80189758u: goto label_80189758;
    case 0x8018975Cu: goto label_8018975C;
    case 0x80189760u: goto label_80189760;
    case 0x80189764u: goto label_80189764;
    case 0x80189768u: goto label_80189768;
    case 0x8018976Cu: goto label_8018976C;
    case 0x80189770u: goto label_80189770;
    case 0x80189774u: goto label_80189774;
    case 0x80189778u: goto label_80189778;
    case 0x8018977Cu: goto label_8018977C;
    case 0x80189780u: goto label_80189780;
    case 0x80189784u: goto label_80189784;
    case 0x80189788u: goto label_80189788;
    case 0x8018978Cu: goto label_8018978C;
    case 0x80189790u: goto label_80189790;
    case 0x80189794u: goto label_80189794;
    case 0x80189798u: goto label_80189798;
    case 0x8018979Cu: goto label_8018979C;
    case 0x801897A0u: goto label_801897A0;
    case 0x801897A4u: goto label_801897A4;
    case 0x801897A8u: goto label_801897A8;
    case 0x801897ACu: goto label_801897AC;
    case 0x801897B0u: goto label_801897B0;
    case 0x801897B4u: goto label_801897B4;
    case 0x801897B8u: goto label_801897B8;
    case 0x801897BCu: goto label_801897BC;
    case 0x801897C0u: goto label_801897C0;
    case 0x801897C4u: goto label_801897C4;
    case 0x801897C8u: goto label_801897C8;
    case 0x801897CCu: goto label_801897CC;
    case 0x801897D0u: goto label_801897D0;
    case 0x801897D4u: goto label_801897D4;
    case 0x801897D8u: goto label_801897D8;
    case 0x801897DCu: goto label_801897DC;
    case 0x801897E0u: goto label_801897E0;
    case 0x801897E4u: goto label_801897E4;
    case 0x801897E8u: goto label_801897E8;
    case 0x801897ECu: goto label_801897EC;
    case 0x801897F0u: goto label_801897F0;
    case 0x801897F4u: goto label_801897F4;
    case 0x801897F8u: goto label_801897F8;
    case 0x801897FCu: goto label_801897FC;
    case 0x80189800u: goto label_80189800;
    case 0x80189804u: goto label_80189804;
    case 0x80189808u: goto label_80189808;
    case 0x8018980Cu: goto label_8018980C;
    case 0x80189810u: goto label_80189810;
    case 0x80189814u: goto label_80189814;
    case 0x80189818u: goto label_80189818;
    case 0x8018981Cu: goto label_8018981C;
    case 0x80189820u: goto label_80189820;
    case 0x80189824u: goto label_80189824;
    case 0x80189828u: goto label_80189828;
    case 0x8018982Cu: goto label_8018982C;
    case 0x80189830u: goto label_80189830;
    case 0x80189834u: goto label_80189834;
    case 0x80189838u: goto label_80189838;
    case 0x8018983Cu: goto label_8018983C;
    case 0x80189840u: goto label_80189840;
    case 0x80189844u: goto label_80189844;
    case 0x80189848u: goto label_80189848;
    case 0x8018984Cu: goto label_8018984C;
    case 0x80189850u: goto label_80189850;
    case 0x80189854u: goto label_80189854;
    case 0x80189858u: goto label_80189858;
    case 0x8018985Cu: goto label_8018985C;
    case 0x80189860u: goto label_80189860;
    case 0x80189864u: goto label_80189864;
    case 0x80189868u: goto label_80189868;
    case 0x8018986Cu: goto label_8018986C;
    case 0x80189870u: goto label_80189870;
    case 0x80189874u: goto label_80189874;
    case 0x80189878u: goto label_80189878;
    case 0x8018987Cu: goto label_8018987C;
    case 0x80189880u: goto label_80189880;
    case 0x80189884u: goto label_80189884;
    case 0x80189888u: goto label_80189888;
    case 0x8018988Cu: goto label_8018988C;
    case 0x80189890u: goto label_80189890;
    case 0x80189894u: goto label_80189894;
    case 0x80189898u: goto label_80189898;
    case 0x8018989Cu: goto label_8018989C;
    case 0x801898A0u: goto label_801898A0;
    case 0x801898A4u: goto label_801898A4;
    case 0x801898A8u: goto label_801898A8;
    case 0x801898ACu: goto label_801898AC;
    case 0x801898B0u: goto label_801898B0;
    case 0x801898B4u: goto label_801898B4;
    case 0x801898B8u: goto label_801898B8;
    case 0x801898BCu: goto label_801898BC;
    case 0x801898C0u: goto label_801898C0;
    case 0x801898C4u: goto label_801898C4;
    case 0x801898C8u: goto label_801898C8;
    case 0x801898CCu: goto label_801898CC;
    case 0x801898D0u: goto label_801898D0;
    case 0x801898D4u: goto label_801898D4;
    case 0x801898D8u: goto label_801898D8;
    case 0x801898DCu: goto label_801898DC;
    case 0x801898E0u: goto label_801898E0;
    case 0x801898E4u: goto label_801898E4;
    case 0x801898E8u: goto label_801898E8;
    case 0x801898ECu: goto label_801898EC;
    case 0x801898F0u: goto label_801898F0;
    case 0x801898F4u: goto label_801898F4;
    case 0x801898F8u: goto label_801898F8;
    case 0x801898FCu: goto label_801898FC;
    case 0x80189900u: goto label_80189900;
    case 0x80189904u: goto label_80189904;
    case 0x80189908u: goto label_80189908;
    case 0x8018990Cu: goto label_8018990C;
    case 0x80189910u: goto label_80189910;
    case 0x80189914u: goto label_80189914;
    case 0x80189918u: goto label_80189918;
    case 0x8018991Cu: goto label_8018991C;
    case 0x80189920u: goto label_80189920;
    case 0x80189924u: goto label_80189924;
    case 0x80189928u: goto label_80189928;
    case 0x8018992Cu: goto label_8018992C;
    case 0x80189930u: goto label_80189930;
    case 0x80189934u: goto label_80189934;
    case 0x80189938u: goto label_80189938;
    case 0x8018993Cu: goto label_8018993C;
    case 0x80189940u: goto label_80189940;
    case 0x80189944u: goto label_80189944;
    case 0x80189948u: goto label_80189948;
    case 0x8018994Cu: goto label_8018994C;
    case 0x80189950u: goto label_80189950;
    case 0x80189954u: goto label_80189954;
    case 0x80189958u: goto label_80189958;
    case 0x8018995Cu: goto label_8018995C;
    case 0x80189960u: goto label_80189960;
    case 0x80189964u: goto label_80189964;
    case 0x80189968u: goto label_80189968;
    case 0x8018996Cu: goto label_8018996C;
    case 0x80189970u: goto label_80189970;
    case 0x80189974u: goto label_80189974;
    case 0x80189978u: goto label_80189978;
    case 0x8018997Cu: goto label_8018997C;
    case 0x80189980u: goto label_80189980;
    case 0x80189984u: goto label_80189984;
    case 0x80189988u: goto label_80189988;
    case 0x8018998Cu: goto label_8018998C;
    case 0x80189990u: goto label_80189990;
    case 0x80189994u: goto label_80189994;
    case 0x80189998u: goto label_80189998;
    case 0x8018999Cu: goto label_8018999C;
    case 0x801899A0u: goto label_801899A0;
    case 0x801899A4u: goto label_801899A4;
    case 0x801899A8u: goto label_801899A8;
    case 0x801899ACu: goto label_801899AC;
    case 0x801899B0u: goto label_801899B0;
    case 0x801899B4u: goto label_801899B4;
    case 0x801899B8u: goto label_801899B8;
    case 0x801899BCu: goto label_801899BC;
    case 0x801899C0u: goto label_801899C0;
    case 0x801899C4u: goto label_801899C4;
    case 0x801899C8u: goto label_801899C8;
    case 0x801899CCu: goto label_801899CC;
    case 0x801899D0u: goto label_801899D0;
    case 0x801899D4u: goto label_801899D4;
    case 0x801899D8u: goto label_801899D8;
    case 0x801899DCu: goto label_801899DC;
    case 0x801899E0u: goto label_801899E0;
    case 0x801899E4u: goto label_801899E4;
    case 0x801899E8u: goto label_801899E8;
    case 0x801899ECu: goto label_801899EC;
    case 0x801899F0u: goto label_801899F0;
    case 0x801899F4u: goto label_801899F4;
    case 0x801899F8u: goto label_801899F8;
    case 0x801899FCu: goto label_801899FC;
    case 0x80189A00u: goto label_80189A00;
    case 0x80189A04u: goto label_80189A04;
    case 0x80189A08u: goto label_80189A08;
    case 0x80189A0Cu: goto label_80189A0C;
    case 0x80189A10u: goto label_80189A10;
    case 0x80189A14u: goto label_80189A14;
    case 0x80189A18u: goto label_80189A18;
    case 0x80189A1Cu: goto label_80189A1C;
    case 0x80189A20u: goto label_80189A20;
    case 0x80189A24u: goto label_80189A24;
    case 0x80189A28u: goto label_80189A28;
    case 0x80189A2Cu: goto label_80189A2C;
    case 0x80189A30u: goto label_80189A30;
    case 0x80189A34u: goto label_80189A34;
    case 0x80189A38u: goto label_80189A38;
    case 0x80189A3Cu: goto label_80189A3C;
    case 0x80189A40u: goto label_80189A40;
    case 0x80189A44u: goto label_80189A44;
    case 0x80189A48u: goto label_80189A48;
    case 0x80189A4Cu: goto label_80189A4C;
    case 0x80189A50u: goto label_80189A50;
    case 0x80189A54u: goto label_80189A54;
    case 0x80189A58u: goto label_80189A58;
    case 0x80189A5Cu: goto label_80189A5C;
    case 0x80189A60u: goto label_80189A60;
    case 0x80189A64u: goto label_80189A64;
    case 0x80189A68u: goto label_80189A68;
    case 0x80189A6Cu: goto label_80189A6C;
    case 0x80189A70u: goto label_80189A70;
    case 0x80189A74u: goto label_80189A74;
    case 0x80189A78u: goto label_80189A78;
    case 0x80189A7Cu: goto label_80189A7C;
    case 0x80189A80u: goto label_80189A80;
    case 0x80189A84u: goto label_80189A84;
    case 0x80189A88u: goto label_80189A88;
    case 0x80189A8Cu: goto label_80189A8C;
    case 0x80189A90u: goto label_80189A90;
    case 0x80189A94u: goto label_80189A94;
    case 0x80189A98u: goto label_80189A98;
    case 0x80189A9Cu: goto label_80189A9C;
    case 0x80189AA0u: goto label_80189AA0;
    case 0x80189AA4u: goto label_80189AA4;
    case 0x80189AA8u: goto label_80189AA8;
    case 0x80189AACu: goto label_80189AAC;
    case 0x80189AB0u: goto label_80189AB0;
    case 0x80189AB4u: goto label_80189AB4;
    case 0x80189AB8u: goto label_80189AB8;
    case 0x80189ABCu: goto label_80189ABC;
    case 0x80189AC0u: goto label_80189AC0;
    case 0x80189AC4u: goto label_80189AC4;
    case 0x80189AC8u: goto label_80189AC8;
    case 0x80189ACCu: goto label_80189ACC;
    case 0x80189AD0u: goto label_80189AD0;
    case 0x80189AD4u: goto label_80189AD4;
    case 0x80189AD8u: goto label_80189AD8;
    case 0x80189ADCu: goto label_80189ADC;
    case 0x80189AE0u: goto label_80189AE0;
    case 0x80189AE4u: goto label_80189AE4;
    case 0x80189AE8u: goto label_80189AE8;
    case 0x80189AECu: goto label_80189AEC;
    case 0x80189AF0u: goto label_80189AF0;
    case 0x80189AF4u: goto label_80189AF4;
    case 0x80189AF8u: goto label_80189AF8;
    case 0x80189AFCu: goto label_80189AFC;
    case 0x80189B00u: goto label_80189B00;
    case 0x80189B04u: goto label_80189B04;
    case 0x80189B08u: goto label_80189B08;
    case 0x80189B0Cu: goto label_80189B0C;
    case 0x80189B10u: goto label_80189B10;
    case 0x80189B14u: goto label_80189B14;
    case 0x80189B18u: goto label_80189B18;
    case 0x80189B1Cu: goto label_80189B1C;
    case 0x80189B20u: goto label_80189B20;
    case 0x80189B24u: goto label_80189B24;
    case 0x80189B28u: goto label_80189B28;
    case 0x80189B2Cu: goto label_80189B2C;
    case 0x80189B30u: goto label_80189B30;
    case 0x80189B34u: goto label_80189B34;
    case 0x80189B38u: goto label_80189B38;
    case 0x80189B3Cu: goto label_80189B3C;
    case 0x80189B40u: goto label_80189B40;
    case 0x80189B44u: goto label_80189B44;
    case 0x80189B48u: goto label_80189B48;
    case 0x80189B4Cu: goto label_80189B4C;
    case 0x80189B50u: goto label_80189B50;
    case 0x80189B54u: goto label_80189B54;
    case 0x80189B58u: goto label_80189B58;
    case 0x80189B5Cu: goto label_80189B5C;
    case 0x80189B60u: goto label_80189B60;
    case 0x80189B64u: goto label_80189B64;
    case 0x80189B68u: goto label_80189B68;
    case 0x80189B6Cu: goto label_80189B6C;
    case 0x80189B70u: goto label_80189B70;
    case 0x80189B74u: goto label_80189B74;
    case 0x80189B78u: goto label_80189B78;
    case 0x80189B7Cu: goto label_80189B7C;
    case 0x80189B80u: goto label_80189B80;
    case 0x80189B84u: goto label_80189B84;
    case 0x80189B88u: goto label_80189B88;
    case 0x80189B8Cu: goto label_80189B8C;
    case 0x80189B90u: goto label_80189B90;
    case 0x80189B94u: goto label_80189B94;
    case 0x80189B98u: goto label_80189B98;
    case 0x80189B9Cu: goto label_80189B9C;
    case 0x80189BA0u: goto label_80189BA0;
    case 0x80189BA4u: goto label_80189BA4;
    case 0x80189BA8u: goto label_80189BA8;
    case 0x80189BACu: goto label_80189BAC;
    case 0x80189BB0u: goto label_80189BB0;
    case 0x80189BB4u: goto label_80189BB4;
    case 0x80189BB8u: goto label_80189BB8;
    case 0x80189BBCu: goto label_80189BBC;
    case 0x80189BC0u: goto label_80189BC0;
    case 0x80189BC4u: goto label_80189BC4;
    case 0x80189BC8u: goto label_80189BC8;
    case 0x80189BCCu: goto label_80189BCC;
    case 0x80189BD0u: goto label_80189BD0;
    case 0x80189BD4u: goto label_80189BD4;
    case 0x80189BD8u: goto label_80189BD8;
    case 0x80189BDCu: goto label_80189BDC;
    case 0x80189BE0u: goto label_80189BE0;
    case 0x80189BE4u: goto label_80189BE4;
    case 0x80189BE8u: goto label_80189BE8;
    case 0x80189BECu: goto label_80189BEC;
    case 0x80189BF0u: goto label_80189BF0;
    case 0x80189BF4u: goto label_80189BF4;
    case 0x80189BF8u: goto label_80189BF8;
    case 0x80189BFCu: goto label_80189BFC;
    case 0x80189C00u: goto label_80189C00;
    case 0x80189C04u: goto label_80189C04;
    case 0x80189C08u: goto label_80189C08;
    case 0x80189C0Cu: goto label_80189C0C;
    case 0x80189C10u: goto label_80189C10;
    case 0x80189C14u: goto label_80189C14;
    case 0x80189C18u: goto label_80189C18;
    case 0x80189C1Cu: goto label_80189C1C;
    case 0x80189C20u: goto label_80189C20;
    case 0x80189C24u: goto label_80189C24;
    case 0x80189C28u: goto label_80189C28;
    case 0x80189C2Cu: goto label_80189C2C;
    case 0x80189C30u: goto label_80189C30;
    case 0x80189C34u: goto label_80189C34;
    case 0x80189C38u: goto label_80189C38;
    case 0x80189C3Cu: goto label_80189C3C;
    case 0x80189C40u: goto label_80189C40;
    case 0x80189C44u: goto label_80189C44;
    case 0x80189C48u: goto label_80189C48;
    case 0x80189C4Cu: goto label_80189C4C;
    case 0x80189C50u: goto label_80189C50;
    case 0x80189C54u: goto label_80189C54;
    case 0x80189C58u: goto label_80189C58;
    case 0x80189C5Cu: goto label_80189C5C;
    case 0x80189C60u: goto label_80189C60;
    case 0x80189C64u: goto label_80189C64;
    case 0x80189C68u: goto label_80189C68;
    case 0x80189C6Cu: goto label_80189C6C;
    case 0x80189C70u: goto label_80189C70;
    case 0x80189C74u: goto label_80189C74;
    case 0x80189C78u: goto label_80189C78;
    case 0x80189C7Cu: goto label_80189C7C;
    case 0x80189C80u: goto label_80189C80;
    case 0x80189C84u: goto label_80189C84;
    case 0x80189C88u: goto label_80189C88;
    case 0x80189C8Cu: goto label_80189C8C;
    case 0x80189C90u: goto label_80189C90;
    case 0x80189C94u: goto label_80189C94;
    case 0x80189C98u: goto label_80189C98;
    case 0x80189C9Cu: goto label_80189C9C;
    case 0x80189CA0u: goto label_80189CA0;
    case 0x80189CA4u: goto label_80189CA4;
    case 0x80189CA8u: goto label_80189CA8;
    case 0x80189CACu: goto label_80189CAC;
    case 0x80189CB0u: goto label_80189CB0;
    case 0x80189CB4u: goto label_80189CB4;
    case 0x80189CB8u: goto label_80189CB8;
    case 0x80189CBCu: goto label_80189CBC;
    case 0x80189CC0u: goto label_80189CC0;
    case 0x80189CC4u: goto label_80189CC4;
    case 0x80189CC8u: goto label_80189CC8;
    case 0x80189CCCu: goto label_80189CCC;
    case 0x80189CD0u: goto label_80189CD0;
    case 0x80189CD4u: goto label_80189CD4;
    case 0x80189CD8u: goto label_80189CD8;
    case 0x80189CDCu: goto label_80189CDC;
    case 0x80189CE0u: goto label_80189CE0;
    case 0x80189CE4u: goto label_80189CE4;
    case 0x80189CE8u: goto label_80189CE8;
    case 0x80189CECu: goto label_80189CEC;
    case 0x80189CF0u: goto label_80189CF0;
    case 0x80189CF4u: goto label_80189CF4;
    case 0x80189CF8u: goto label_80189CF8;
    case 0x80189CFCu: goto label_80189CFC;
    case 0x80189D00u: goto label_80189D00;
    case 0x80189D04u: goto label_80189D04;
    case 0x80189D08u: goto label_80189D08;
    case 0x80189D0Cu: goto label_80189D0C;
    case 0x80189D10u: goto label_80189D10;
    case 0x80189D14u: goto label_80189D14;
    case 0x80189D18u: goto label_80189D18;
    case 0x80189D1Cu: goto label_80189D1C;
    case 0x80189D20u: goto label_80189D20;
    case 0x80189D24u: goto label_80189D24;
    case 0x80189D28u: goto label_80189D28;
    case 0x80189D2Cu: goto label_80189D2C;
    case 0x80189D30u: goto label_80189D30;
    case 0x80189D34u: goto label_80189D34;
    case 0x80189D38u: goto label_80189D38;
    case 0x80189D3Cu: goto label_80189D3C;
    case 0x80189D40u: goto label_80189D40;
    case 0x80189D44u: goto label_80189D44;
    case 0x80189D48u: goto label_80189D48;
    case 0x80189D4Cu: goto label_80189D4C;
    case 0x80189D50u: goto label_80189D50;
    case 0x80189D54u: goto label_80189D54;
    case 0x80189D58u: goto label_80189D58;
    case 0x80189D5Cu: goto label_80189D5C;
    case 0x80189D60u: goto label_80189D60;
    case 0x80189D64u: goto label_80189D64;
    case 0x80189D68u: goto label_80189D68;
    case 0x80189D6Cu: goto label_80189D6C;
    case 0x80189D70u: goto label_80189D70;
    case 0x80189D74u: goto label_80189D74;
    case 0x80189D78u: goto label_80189D78;
    case 0x80189D7Cu: goto label_80189D7C;
    case 0x80189D80u: goto label_80189D80;
    case 0x80189D84u: goto label_80189D84;
    case 0x80189D88u: goto label_80189D88;
    case 0x80189D8Cu: goto label_80189D8C;
    case 0x80189D90u: goto label_80189D90;
    case 0x80189D94u: goto label_80189D94;
    case 0x80189D98u: goto label_80189D98;
    case 0x80189D9Cu: goto label_80189D9C;
    case 0x80189DA0u: goto label_80189DA0;
    case 0x80189DA4u: goto label_80189DA4;
    case 0x80189DA8u: goto label_80189DA8;
    case 0x80189DACu: goto label_80189DAC;
    case 0x80189DB0u: goto label_80189DB0;
    case 0x80189DB4u: goto label_80189DB4;
    case 0x80189DB8u: goto label_80189DB8;
    case 0x80189DBCu: goto label_80189DBC;
    case 0x80189DC0u: goto label_80189DC0;
    case 0x80189DC4u: goto label_80189DC4;
    case 0x80189DC8u: goto label_80189DC8;
    case 0x80189DCCu: goto label_80189DCC;
    case 0x80189DD0u: goto label_80189DD0;
    case 0x80189DD4u: goto label_80189DD4;
    case 0x80189DD8u: goto label_80189DD8;
    case 0x80189DDCu: goto label_80189DDC;
    case 0x80189DE0u: goto label_80189DE0;
    case 0x80189DE4u: goto label_80189DE4;
    case 0x80189DE8u: goto label_80189DE8;
    case 0x80189DECu: goto label_80189DEC;
    case 0x80189DF0u: goto label_80189DF0;
    case 0x80189DF4u: goto label_80189DF4;
    case 0x80189DF8u: goto label_80189DF8;
    case 0x80189DFCu: goto label_80189DFC;
    case 0x80189E00u: goto label_80189E00;
    case 0x80189E04u: goto label_80189E04;
    case 0x80189E08u: goto label_80189E08;
    case 0x80189E0Cu: goto label_80189E0C;
    case 0x80189E10u: goto label_80189E10;
    case 0x80189E14u: goto label_80189E14;
    case 0x80189E18u: goto label_80189E18;
    case 0x80189E1Cu: goto label_80189E1C;
    case 0x80189E20u: goto label_80189E20;
    case 0x80189E24u: goto label_80189E24;
    case 0x80189E28u: goto label_80189E28;
    case 0x80189E2Cu: goto label_80189E2C;
    case 0x80189E30u: goto label_80189E30;
    case 0x80189E34u: goto label_80189E34;
    case 0x80189E38u: goto label_80189E38;
    case 0x80189E3Cu: goto label_80189E3C;
    case 0x80189E40u: goto label_80189E40;
    case 0x80189E44u: goto label_80189E44;
    case 0x80189E48u: goto label_80189E48;
    case 0x80189E4Cu: goto label_80189E4C;
    case 0x80189E50u: goto label_80189E50;
    case 0x80189E54u: goto label_80189E54;
    case 0x80189E58u: goto label_80189E58;
    case 0x80189E5Cu: goto label_80189E5C;
    case 0x80189E60u: goto label_80189E60;
    case 0x80189E64u: goto label_80189E64;
    case 0x80189E68u: goto label_80189E68;
    case 0x80189E6Cu: goto label_80189E6C;
    case 0x80189E70u: goto label_80189E70;
    case 0x80189E74u: goto label_80189E74;
    case 0x80189E78u: goto label_80189E78;
    case 0x80189E7Cu: goto label_80189E7C;
    case 0x80189E80u: goto label_80189E80;
    case 0x80189E84u: goto label_80189E84;
    case 0x80189E88u: goto label_80189E88;
    case 0x80189E8Cu: goto label_80189E8C;
    case 0x80189E90u: goto label_80189E90;
    case 0x80189E94u: goto label_80189E94;
    case 0x80189E98u: goto label_80189E98;
    case 0x80189E9Cu: goto label_80189E9C;
    case 0x80189EA0u: goto label_80189EA0;
    case 0x80189EA4u: goto label_80189EA4;
    case 0x80189EA8u: goto label_80189EA8;
    case 0x80189EACu: goto label_80189EAC;
    case 0x80189EB0u: goto label_80189EB0;
    case 0x80189EB4u: goto label_80189EB4;
    case 0x80189EB8u: goto label_80189EB8;
    case 0x80189EBCu: goto label_80189EBC;
    case 0x80189EC0u: goto label_80189EC0;
    case 0x80189EC4u: goto label_80189EC4;
    case 0x80189EC8u: goto label_80189EC8;
    case 0x80189ECCu: goto label_80189ECC;
    case 0x80189ED0u: goto label_80189ED0;
    case 0x80189ED4u: goto label_80189ED4;
    case 0x80189ED8u: goto label_80189ED8;
    case 0x80189EDCu: goto label_80189EDC;
    case 0x80189EE0u: goto label_80189EE0;
    case 0x80189EE4u: goto label_80189EE4;
    case 0x80189EE8u: goto label_80189EE8;
    case 0x80189EECu: goto label_80189EEC;
    case 0x80189EF0u: goto label_80189EF0;
    case 0x80189EF4u: goto label_80189EF4;
    case 0x80189EF8u: goto label_80189EF8;
    case 0x80189EFCu: goto label_80189EFC;
    case 0x80189F00u: goto label_80189F00;
    case 0x80189F04u: goto label_80189F04;
    case 0x80189F08u: goto label_80189F08;
    case 0x80189F0Cu: goto label_80189F0C;
    case 0x80189F10u: goto label_80189F10;
    case 0x80189F14u: goto label_80189F14;
    case 0x80189F18u: goto label_80189F18;
    case 0x80189F1Cu: goto label_80189F1C;
    case 0x80189F20u: goto label_80189F20;
    case 0x80189F24u: goto label_80189F24;
    case 0x80189F28u: goto label_80189F28;
    case 0x80189F2Cu: goto label_80189F2C;
    case 0x80189F30u: goto label_80189F30;
    case 0x80189F34u: goto label_80189F34;
    case 0x80189F38u: goto label_80189F38;
    case 0x80189F3Cu: goto label_80189F3C;
    case 0x80189F40u: goto label_80189F40;
    case 0x80189F44u: goto label_80189F44;
    case 0x80189F48u: goto label_80189F48;
    case 0x80189F4Cu: goto label_80189F4C;
    case 0x80189F50u: goto label_80189F50;
    case 0x80189F54u: goto label_80189F54;
    case 0x80189F58u: goto label_80189F58;
    case 0x80189F5Cu: goto label_80189F5C;
    case 0x80189F60u: goto label_80189F60;
    case 0x80189F64u: goto label_80189F64;
    case 0x80189F68u: goto label_80189F68;
    case 0x80189F6Cu: goto label_80189F6C;
    case 0x80189F70u: goto label_80189F70;
    case 0x80189F74u: goto label_80189F74;
    case 0x80189F78u: goto label_80189F78;
    case 0x80189F7Cu: goto label_80189F7C;
    case 0x80189F80u: goto label_80189F80;
    case 0x80189F84u: goto label_80189F84;
    case 0x80189F88u: goto label_80189F88;
    case 0x80189F8Cu: goto label_80189F8C;
    case 0x80189F90u: goto label_80189F90;
    case 0x80189F94u: goto label_80189F94;
    case 0x80189F98u: goto label_80189F98;
    case 0x80189F9Cu: goto label_80189F9C;
    case 0x80189FA0u: goto label_80189FA0;
    case 0x80189FA4u: goto label_80189FA4;
    case 0x80189FA8u: goto label_80189FA8;
    case 0x80189FACu: goto label_80189FAC;
    case 0x80189FB0u: goto label_80189FB0;
    case 0x80189FB4u: goto label_80189FB4;
    case 0x80189FB8u: goto label_80189FB8;
    case 0x80189FBCu: goto label_80189FBC;
    case 0x80189FC0u: goto label_80189FC0;
    case 0x80189FC4u: goto label_80189FC4;
    case 0x80189FC8u: goto label_80189FC8;
    case 0x80189FCCu: goto label_80189FCC;
    case 0x80189FD0u: goto label_80189FD0;
    case 0x80189FD4u: goto label_80189FD4;
    case 0x80189FD8u: goto label_80189FD8;
    case 0x80189FDCu: goto label_80189FDC;
    case 0x80189FE0u: goto label_80189FE0;
    case 0x80189FE4u: goto label_80189FE4;
    case 0x80189FE8u: goto label_80189FE8;
    case 0x80189FECu: goto label_80189FEC;
    case 0x80189FF0u: goto label_80189FF0;
    case 0x80189FF4u: goto label_80189FF4;
    case 0x80189FF8u: goto label_80189FF8;
    case 0x80189FFCu: goto label_80189FFC;
    case 0x8018A000u: goto label_8018A000;
    case 0x8018A004u: goto label_8018A004;
    case 0x8018A008u: goto label_8018A008;
    case 0x8018A00Cu: goto label_8018A00C;
    case 0x8018A010u: goto label_8018A010;
    case 0x8018A014u: goto label_8018A014;
    case 0x8018A018u: goto label_8018A018;
    case 0x8018A01Cu: goto label_8018A01C;
    case 0x8018A020u: goto label_8018A020;
    case 0x8018A024u: goto label_8018A024;
    case 0x8018A028u: goto label_8018A028;
    case 0x8018A02Cu: goto label_8018A02C;
    case 0x8018A030u: goto label_8018A030;
    case 0x8018A034u: goto label_8018A034;
    case 0x8018A038u: goto label_8018A038;
    case 0x8018A03Cu: goto label_8018A03C;
    case 0x8018A040u: goto label_8018A040;
    case 0x8018A044u: goto label_8018A044;
    case 0x8018A048u: goto label_8018A048;
    case 0x8018A04Cu: goto label_8018A04C;
    case 0x8018A050u: goto label_8018A050;
    case 0x8018A054u: goto label_8018A054;
    case 0x8018A058u: goto label_8018A058;
    case 0x8018A05Cu: goto label_8018A05C;
    case 0x8018A060u: goto label_8018A060;
    case 0x8018A064u: goto label_8018A064;
    case 0x8018A068u: goto label_8018A068;
    case 0x8018A06Cu: goto label_8018A06C;
    case 0x8018A070u: goto label_8018A070;
    case 0x8018A074u: goto label_8018A074;
    case 0x8018A078u: goto label_8018A078;
    case 0x8018A07Cu: goto label_8018A07C;
    case 0x8018A080u: goto label_8018A080;
    case 0x8018A084u: goto label_8018A084;
    case 0x8018A088u: goto label_8018A088;
    case 0x8018A08Cu: goto label_8018A08C;
    case 0x8018A090u: goto label_8018A090;
    case 0x8018A094u: goto label_8018A094;
    case 0x8018A098u: goto label_8018A098;
    case 0x8018A09Cu: goto label_8018A09C;
    case 0x8018A0A0u: goto label_8018A0A0;
    case 0x8018A0A4u: goto label_8018A0A4;
    case 0x8018A0A8u: goto label_8018A0A8;
    case 0x8018A0ACu: goto label_8018A0AC;
    case 0x8018A0B0u: goto label_8018A0B0;
    case 0x8018A0B4u: goto label_8018A0B4;
    case 0x8018A0B8u: goto label_8018A0B8;
    case 0x8018A0BCu: goto label_8018A0BC;
    case 0x8018A0C0u: goto label_8018A0C0;
    case 0x8018A0C4u: goto label_8018A0C4;
    case 0x8018A0C8u: goto label_8018A0C8;
    case 0x8018A0CCu: goto label_8018A0CC;
    case 0x8018A0D0u: goto label_8018A0D0;
    case 0x8018A0D4u: goto label_8018A0D4;
    case 0x8018A0D8u: goto label_8018A0D8;
    case 0x8018A0DCu: goto label_8018A0DC;
    case 0x8018A0E0u: goto label_8018A0E0;
    case 0x8018A0E4u: goto label_8018A0E4;
    case 0x8018A0E8u: goto label_8018A0E8;
    case 0x8018A0ECu: goto label_8018A0EC;
    case 0x8018A0F0u: goto label_8018A0F0;
    case 0x8018A0F4u: goto label_8018A0F4;
    case 0x8018A0F8u: goto label_8018A0F8;
    case 0x8018A0FCu: goto label_8018A0FC;
    case 0x8018A100u: goto label_8018A100;
    case 0x8018A104u: goto label_8018A104;
    case 0x8018A108u: goto label_8018A108;
    case 0x8018A10Cu: goto label_8018A10C;
    case 0x8018A110u: goto label_8018A110;
    case 0x8018A114u: goto label_8018A114;
    case 0x8018A118u: goto label_8018A118;
    case 0x8018A11Cu: goto label_8018A11C;
    case 0x8018A120u: goto label_8018A120;
    case 0x8018A124u: goto label_8018A124;
    case 0x8018A128u: goto label_8018A128;
    case 0x8018A12Cu: goto label_8018A12C;
    case 0x8018A130u: goto label_8018A130;
    case 0x8018A134u: goto label_8018A134;
    case 0x8018A138u: goto label_8018A138;
    case 0x8018A13Cu: goto label_8018A13C;
    case 0x8018A140u: goto label_8018A140;
    case 0x8018A144u: goto label_8018A144;
    case 0x8018A148u: goto label_8018A148;
    case 0x8018A14Cu: goto label_8018A14C;
    case 0x8018A150u: goto label_8018A150;
    case 0x8018A154u: goto label_8018A154;
    case 0x8018A158u: goto label_8018A158;
    case 0x8018A15Cu: goto label_8018A15C;
    case 0x8018A160u: goto label_8018A160;
    case 0x8018A164u: goto label_8018A164;
    case 0x8018A168u: goto label_8018A168;
    case 0x8018A16Cu: goto label_8018A16C;
    case 0x8018A170u: goto label_8018A170;
    case 0x8018A174u: goto label_8018A174;
    case 0x8018A178u: goto label_8018A178;
    case 0x8018A17Cu: goto label_8018A17C;
    case 0x8018A180u: goto label_8018A180;
    case 0x8018A184u: goto label_8018A184;
    case 0x8018A188u: goto label_8018A188;
    case 0x8018A18Cu: goto label_8018A18C;
    case 0x8018A190u: goto label_8018A190;
    case 0x8018A194u: goto label_8018A194;
    case 0x8018A198u: goto label_8018A198;
    case 0x8018A19Cu: goto label_8018A19C;
    case 0x8018A1A0u: goto label_8018A1A0;
    case 0x8018A1A4u: goto label_8018A1A4;
    case 0x8018A1A8u: goto label_8018A1A8;
    case 0x8018A1ACu: goto label_8018A1AC;
    case 0x8018A1B0u: goto label_8018A1B0;
    case 0x8018A1B4u: goto label_8018A1B4;
    case 0x8018A1B8u: goto label_8018A1B8;
    case 0x8018A1BCu: goto label_8018A1BC;
    case 0x8018A1C0u: goto label_8018A1C0;
    case 0x8018A1C4u: goto label_8018A1C4;
    case 0x8018A1C8u: goto label_8018A1C8;
    case 0x8018A1CCu: goto label_8018A1CC;
    case 0x8018A1D0u: goto label_8018A1D0;
    case 0x8018A1D4u: goto label_8018A1D4;
    case 0x8018A1D8u: goto label_8018A1D8;
    case 0x8018A1DCu: goto label_8018A1DC;
    case 0x8018A1E0u: goto label_8018A1E0;
    case 0x8018A1E4u: goto label_8018A1E4;
    case 0x8018A1E8u: goto label_8018A1E8;
    case 0x8018A1ECu: goto label_8018A1EC;
    case 0x8018A1F0u: goto label_8018A1F0;
    case 0x8018A1F4u: goto label_8018A1F4;
    case 0x8018A1F8u: goto label_8018A1F8;
    case 0x8018A1FCu: goto label_8018A1FC;
    case 0x8018A200u: goto label_8018A200;
    case 0x8018A204u: goto label_8018A204;
    case 0x8018A208u: goto label_8018A208;
    case 0x8018A20Cu: goto label_8018A20C;
    case 0x8018A210u: goto label_8018A210;
    case 0x8018A214u: goto label_8018A214;
    case 0x8018A218u: goto label_8018A218;
    case 0x8018A21Cu: goto label_8018A21C;
    case 0x8018A220u: goto label_8018A220;
    case 0x8018A224u: goto label_8018A224;
    case 0x8018A228u: goto label_8018A228;
    case 0x8018A22Cu: goto label_8018A22C;
    case 0x8018A230u: goto label_8018A230;
    case 0x8018A234u: goto label_8018A234;
    case 0x8018A238u: goto label_8018A238;
    case 0x8018A23Cu: goto label_8018A23C;
    case 0x8018A240u: goto label_8018A240;
    case 0x8018A244u: goto label_8018A244;
    case 0x8018A248u: goto label_8018A248;
    case 0x8018A24Cu: goto label_8018A24C;
    case 0x8018A250u: goto label_8018A250;
    case 0x8018A254u: goto label_8018A254;
    case 0x8018A258u: goto label_8018A258;
    case 0x8018A25Cu: goto label_8018A25C;
    case 0x8018A260u: goto label_8018A260;
    case 0x8018A264u: goto label_8018A264;
    case 0x8018A268u: goto label_8018A268;
    case 0x8018A26Cu: goto label_8018A26C;
    case 0x8018A270u: goto label_8018A270;
    case 0x8018A274u: goto label_8018A274;
    case 0x8018A278u: goto label_8018A278;
    case 0x8018A27Cu: goto label_8018A27C;
    case 0x8018A280u: goto label_8018A280;
    case 0x8018A284u: goto label_8018A284;
    case 0x8018A288u: goto label_8018A288;
    case 0x8018A28Cu: goto label_8018A28C;
    case 0x8018A290u: goto label_8018A290;
    case 0x8018A294u: goto label_8018A294;
    case 0x8018A298u: goto label_8018A298;
    case 0x8018A29Cu: goto label_8018A29C;
    case 0x8018A2A0u: goto label_8018A2A0;
    case 0x8018A2A4u: goto label_8018A2A4;
    case 0x8018A2A8u: goto label_8018A2A8;
    case 0x8018A2ACu: goto label_8018A2AC;
    case 0x8018A2B0u: goto label_8018A2B0;
    case 0x8018A2B4u: goto label_8018A2B4;
    case 0x8018A2B8u: goto label_8018A2B8;
    case 0x8018A2BCu: goto label_8018A2BC;
    case 0x8018A2C0u: goto label_8018A2C0;
    case 0x8018A2C4u: goto label_8018A2C4;
    case 0x8018A2C8u: goto label_8018A2C8;
    case 0x8018A2CCu: goto label_8018A2CC;
    case 0x8018A2D0u: goto label_8018A2D0;
    case 0x8018A2D4u: goto label_8018A2D4;
    case 0x8018A2D8u: goto label_8018A2D8;
    case 0x8018A2DCu: goto label_8018A2DC;
    case 0x8018A2E0u: goto label_8018A2E0;
    case 0x8018A2E4u: goto label_8018A2E4;
    case 0x8018A2E8u: goto label_8018A2E8;
    case 0x8018A2ECu: goto label_8018A2EC;
    case 0x8018A2F0u: goto label_8018A2F0;
    case 0x8018A2F4u: goto label_8018A2F4;
    case 0x8018A2F8u: goto label_8018A2F8;
    case 0x8018A2FCu: goto label_8018A2FC;
    case 0x8018A300u: goto label_8018A300;
    case 0x8018A304u: goto label_8018A304;
    case 0x8018A308u: goto label_8018A308;
    case 0x8018A30Cu: goto label_8018A30C;
    case 0x8018A310u: goto label_8018A310;
    case 0x8018A314u: goto label_8018A314;
    case 0x8018A318u: goto label_8018A318;
    case 0x8018A31Cu: goto label_8018A31C;
    case 0x8018A320u: goto label_8018A320;
    case 0x8018A324u: goto label_8018A324;
    case 0x8018A328u: goto label_8018A328;
    case 0x8018A32Cu: goto label_8018A32C;
    case 0x8018A330u: goto label_8018A330;
    case 0x8018A334u: goto label_8018A334;
    case 0x8018A338u: goto label_8018A338;
    case 0x8018A33Cu: goto label_8018A33C;
    case 0x8018A340u: goto label_8018A340;
    case 0x8018A344u: goto label_8018A344;
    case 0x8018A348u: goto label_8018A348;
    case 0x8018A34Cu: goto label_8018A34C;
    case 0x8018A350u: goto label_8018A350;
    case 0x8018A354u: goto label_8018A354;
    case 0x8018A358u: goto label_8018A358;
    case 0x8018A35Cu: goto label_8018A35C;
    case 0x8018A360u: goto label_8018A360;
    case 0x8018A364u: goto label_8018A364;
    case 0x8018A368u: goto label_8018A368;
    case 0x8018A36Cu: goto label_8018A36C;
    case 0x8018A370u: goto label_8018A370;
    case 0x8018A374u: goto label_8018A374;
    case 0x8018A378u: goto label_8018A378;
    case 0x8018A37Cu: goto label_8018A37C;
    case 0x8018A380u: goto label_8018A380;
    case 0x8018A384u: goto label_8018A384;
    case 0x8018A388u: goto label_8018A388;
    case 0x8018A38Cu: goto label_8018A38C;
    case 0x8018A390u: goto label_8018A390;
    case 0x8018A394u: goto label_8018A394;
    case 0x8018A398u: goto label_8018A398;
    case 0x8018A39Cu: goto label_8018A39C;
    case 0x8018A3A0u: goto label_8018A3A0;
    case 0x8018A3A4u: goto label_8018A3A4;
    case 0x8018A3A8u: goto label_8018A3A8;
    case 0x8018A3ACu: goto label_8018A3AC;
    case 0x8018A3B0u: goto label_8018A3B0;
    case 0x8018A3B4u: goto label_8018A3B4;
    case 0x8018A3B8u: goto label_8018A3B8;
    case 0x8018A3BCu: goto label_8018A3BC;
    case 0x8018A3C0u: goto label_8018A3C0;
    case 0x8018A3C4u: goto label_8018A3C4;
    case 0x8018A3C8u: goto label_8018A3C8;
    case 0x8018A3CCu: goto label_8018A3CC;
    case 0x8018A3D0u: goto label_8018A3D0;
    case 0x8018A3D4u: goto label_8018A3D4;
    case 0x8018A3D8u: goto label_8018A3D8;
    case 0x8018A3DCu: goto label_8018A3DC;
    case 0x8018A3E0u: goto label_8018A3E0;
    case 0x8018A3E4u: goto label_8018A3E4;
    case 0x8018A3E8u: goto label_8018A3E8;
    case 0x8018A3ECu: goto label_8018A3EC;
    case 0x8018A3F0u: goto label_8018A3F0;
    case 0x8018A3F4u: goto label_8018A3F4;
    case 0x8018A3F8u: goto label_8018A3F8;
    case 0x8018A3FCu: goto label_8018A3FC;
    case 0x8018A400u: goto label_8018A400;
    case 0x8018A404u: goto label_8018A404;
    case 0x8018A408u: goto label_8018A408;
    case 0x8018A40Cu: goto label_8018A40C;
    case 0x8018A410u: goto label_8018A410;
    case 0x8018A414u: goto label_8018A414;
    case 0x8018A418u: goto label_8018A418;
    case 0x8018A41Cu: goto label_8018A41C;
    case 0x8018A420u: goto label_8018A420;
    case 0x8018A424u: goto label_8018A424;
    case 0x8018A428u: goto label_8018A428;
    case 0x8018A42Cu: goto label_8018A42C;
    case 0x8018A430u: goto label_8018A430;
    case 0x8018A434u: goto label_8018A434;
    case 0x8018A438u: goto label_8018A438;
    case 0x8018A43Cu: goto label_8018A43C;
    case 0x8018A440u: goto label_8018A440;
    case 0x8018A444u: goto label_8018A444;
    case 0x8018A448u: goto label_8018A448;
    case 0x8018A44Cu: goto label_8018A44C;
    case 0x8018A450u: goto label_8018A450;
    case 0x8018A454u: goto label_8018A454;
    case 0x8018A458u: goto label_8018A458;
    case 0x8018A45Cu: goto label_8018A45C;
    case 0x8018A460u: goto label_8018A460;
    case 0x8018A464u: goto label_8018A464;
    case 0x8018A468u: goto label_8018A468;
    case 0x8018A46Cu: goto label_8018A46C;
    case 0x8018A470u: goto label_8018A470;
    case 0x8018A474u: goto label_8018A474;
    case 0x8018A478u: goto label_8018A478;
    case 0x8018A47Cu: goto label_8018A47C;
    case 0x8018A480u: goto label_8018A480;
    case 0x8018A484u: goto label_8018A484;
    case 0x8018A488u: goto label_8018A488;
    case 0x8018A48Cu: goto label_8018A48C;
    case 0x8018A490u: goto label_8018A490;
    case 0x8018A494u: goto label_8018A494;
    case 0x8018A498u: goto label_8018A498;
    case 0x8018A49Cu: goto label_8018A49C;
    case 0x8018A4A0u: goto label_8018A4A0;
    case 0x8018A4A4u: goto label_8018A4A4;
    case 0x8018A4A8u: goto label_8018A4A8;
    case 0x8018A4ACu: goto label_8018A4AC;
    case 0x8018A4B0u: goto label_8018A4B0;
    case 0x8018A4B4u: goto label_8018A4B4;
    case 0x8018A4B8u: goto label_8018A4B8;
    case 0x8018A4BCu: goto label_8018A4BC;
    case 0x8018A4C0u: goto label_8018A4C0;
    case 0x8018A4C4u: goto label_8018A4C4;
    case 0x8018A4C8u: goto label_8018A4C8;
    case 0x8018A4CCu: goto label_8018A4CC;
    case 0x8018A4D0u: goto label_8018A4D0;
    case 0x8018A4D4u: goto label_8018A4D4;
    case 0x8018A4D8u: goto label_8018A4D8;
    case 0x8018A4DCu: goto label_8018A4DC;
    case 0x8018A4E0u: goto label_8018A4E0;
    case 0x8018A4E4u: goto label_8018A4E4;
    case 0x8018A4E8u: goto label_8018A4E8;
    case 0x8018A4ECu: goto label_8018A4EC;
    case 0x8018A4F0u: goto label_8018A4F0;
    case 0x8018A4F4u: goto label_8018A4F4;
    case 0x8018A4F8u: goto label_8018A4F8;
    case 0x8018A4FCu: goto label_8018A4FC;
    case 0x8018A500u: goto label_8018A500;
    case 0x8018A504u: goto label_8018A504;
    case 0x8018A508u: goto label_8018A508;
    case 0x8018A50Cu: goto label_8018A50C;
    case 0x8018A510u: goto label_8018A510;
    case 0x8018A514u: goto label_8018A514;
    case 0x8018A518u: goto label_8018A518;
    case 0x8018A51Cu: goto label_8018A51C;
    case 0x8018A520u: goto label_8018A520;
    case 0x8018A524u: goto label_8018A524;
    case 0x8018A528u: goto label_8018A528;
    case 0x8018A52Cu: goto label_8018A52C;
    case 0x8018A530u: goto label_8018A530;
    case 0x8018A534u: goto label_8018A534;
    case 0x8018A538u: goto label_8018A538;
    case 0x8018A53Cu: goto label_8018A53C;
    case 0x8018A540u: goto label_8018A540;
    case 0x8018A544u: goto label_8018A544;
    case 0x8018A548u: goto label_8018A548;
    case 0x8018A54Cu: goto label_8018A54C;
    case 0x8018A550u: goto label_8018A550;
    case 0x8018A554u: goto label_8018A554;
    case 0x8018A558u: goto label_8018A558;
    case 0x8018A55Cu: goto label_8018A55C;
    case 0x8018A560u: goto label_8018A560;
    case 0x8018A564u: goto label_8018A564;
    case 0x8018A568u: goto label_8018A568;
    case 0x8018A56Cu: goto label_8018A56C;
    case 0x8018A570u: goto label_8018A570;
    case 0x8018A574u: goto label_8018A574;
    case 0x8018A578u: goto label_8018A578;
    case 0x8018A57Cu: goto label_8018A57C;
    case 0x8018A580u: goto label_8018A580;
    case 0x8018A584u: goto label_8018A584;
    case 0x8018A588u: goto label_8018A588;
    case 0x8018A58Cu: goto label_8018A58C;
    case 0x8018A590u: goto label_8018A590;
    case 0x8018A594u: goto label_8018A594;
    case 0x8018A598u: goto label_8018A598;
    case 0x8018A59Cu: goto label_8018A59C;
    case 0x8018A5A0u: goto label_8018A5A0;
    case 0x8018A5A4u: goto label_8018A5A4;
    case 0x8018A5A8u: goto label_8018A5A8;
    case 0x8018A5ACu: goto label_8018A5AC;
    case 0x8018A5B0u: goto label_8018A5B0;
    case 0x8018A5B4u: goto label_8018A5B4;
    case 0x8018A5B8u: goto label_8018A5B8;
    case 0x8018A5BCu: goto label_8018A5BC;
    case 0x8018A5C0u: goto label_8018A5C0;
    case 0x8018A5C4u: goto label_8018A5C4;
    case 0x8018A5C8u: goto label_8018A5C8;
    case 0x8018A5CCu: goto label_8018A5CC;
    case 0x8018A5D0u: goto label_8018A5D0;
    case 0x8018A5D4u: goto label_8018A5D4;
    case 0x8018A5D8u: goto label_8018A5D8;
    case 0x8018A5DCu: goto label_8018A5DC;
    case 0x8018A5E0u: goto label_8018A5E0;
    case 0x8018A5E4u: goto label_8018A5E4;
    case 0x8018A5E8u: goto label_8018A5E8;
    case 0x8018A5ECu: goto label_8018A5EC;
    case 0x8018A5F0u: goto label_8018A5F0;
    case 0x8018A5F4u: goto label_8018A5F4;
    case 0x8018A5F8u: goto label_8018A5F8;
    case 0x8018A5FCu: goto label_8018A5FC;
    case 0x8018A600u: goto label_8018A600;
    case 0x8018A604u: goto label_8018A604;
    case 0x8018A608u: goto label_8018A608;
    case 0x8018A60Cu: goto label_8018A60C;
    case 0x8018A610u: goto label_8018A610;
    case 0x8018A614u: goto label_8018A614;
    case 0x8018A618u: goto label_8018A618;
    case 0x8018A61Cu: goto label_8018A61C;
    case 0x8018A620u: goto label_8018A620;
    case 0x8018A624u: goto label_8018A624;
    case 0x8018A628u: goto label_8018A628;
    case 0x8018A62Cu: goto label_8018A62C;
    case 0x8018A630u: goto label_8018A630;
    case 0x8018A634u: goto label_8018A634;
    case 0x8018A638u: goto label_8018A638;
    case 0x8018A63Cu: goto label_8018A63C;
    case 0x8018A640u: goto label_8018A640;
    case 0x8018A644u: goto label_8018A644;
    case 0x8018A648u: goto label_8018A648;
    case 0x8018A64Cu: goto label_8018A64C;
    case 0x8018A650u: goto label_8018A650;
    case 0x8018A654u: goto label_8018A654;
    case 0x8018A658u: goto label_8018A658;
    case 0x8018A65Cu: goto label_8018A65C;
    case 0x8018A660u: goto label_8018A660;
    case 0x8018A664u: goto label_8018A664;
    case 0x8018A668u: goto label_8018A668;
    case 0x8018A66Cu: goto label_8018A66C;
    case 0x8018A670u: goto label_8018A670;
    case 0x8018A674u: goto label_8018A674;
    case 0x8018A678u: goto label_8018A678;
    case 0x8018A67Cu: goto label_8018A67C;
    case 0x8018A680u: goto label_8018A680;
    case 0x8018A684u: goto label_8018A684;
    case 0x8018A688u: goto label_8018A688;
    case 0x8018A68Cu: goto label_8018A68C;
    case 0x8018A690u: goto label_8018A690;
    case 0x8018A694u: goto label_8018A694;
    case 0x8018A698u: goto label_8018A698;
    case 0x8018A69Cu: goto label_8018A69C;
    case 0x8018A6A0u: goto label_8018A6A0;
    case 0x8018A6A4u: goto label_8018A6A4;
    case 0x8018A6A8u: goto label_8018A6A8;
    case 0x8018A6ACu: goto label_8018A6AC;
    case 0x8018A6B0u: goto label_8018A6B0;
    case 0x8018A6B4u: goto label_8018A6B4;
    case 0x8018A6B8u: goto label_8018A6B8;
    case 0x8018A6BCu: goto label_8018A6BC;
    case 0x8018A6C0u: goto label_8018A6C0;
    case 0x8018A6C4u: goto label_8018A6C4;
    case 0x8018A6C8u: goto label_8018A6C8;
    case 0x8018A6CCu: goto label_8018A6CC;
    case 0x8018A6D0u: goto label_8018A6D0;
    case 0x8018A6D4u: goto label_8018A6D4;
    case 0x8018A6D8u: goto label_8018A6D8;
    case 0x8018A6DCu: goto label_8018A6DC;
    case 0x8018A6E0u: goto label_8018A6E0;
    case 0x8018A6E4u: goto label_8018A6E4;
    case 0x8018A6E8u: goto label_8018A6E8;
    case 0x8018A6ECu: goto label_8018A6EC;
    case 0x8018A6F0u: goto label_8018A6F0;
    case 0x8018A6F4u: goto label_8018A6F4;
    case 0x8018A6F8u: goto label_8018A6F8;
    case 0x8018A6FCu: goto label_8018A6FC;
    case 0x8018A700u: goto label_8018A700;
    case 0x8018A704u: goto label_8018A704;
    case 0x8018A708u: goto label_8018A708;
    case 0x8018A70Cu: goto label_8018A70C;
    case 0x8018A710u: goto label_8018A710;
    case 0x8018A714u: goto label_8018A714;
    case 0x8018A718u: goto label_8018A718;
    case 0x8018A71Cu: goto label_8018A71C;
    case 0x8018A720u: goto label_8018A720;
    case 0x8018A724u: goto label_8018A724;
    case 0x8018A728u: goto label_8018A728;
    case 0x8018A72Cu: goto label_8018A72C;
    case 0x8018A730u: goto label_8018A730;
    case 0x8018A734u: goto label_8018A734;
    case 0x8018A738u: goto label_8018A738;
    case 0x8018A73Cu: goto label_8018A73C;
    case 0x8018A740u: goto label_8018A740;
    case 0x8018A744u: goto label_8018A744;
    case 0x8018A748u: goto label_8018A748;
    case 0x8018A74Cu: goto label_8018A74C;
    case 0x8018A750u: goto label_8018A750;
    case 0x8018A754u: goto label_8018A754;
    case 0x8018A758u: goto label_8018A758;
    case 0x8018A75Cu: goto label_8018A75C;
    case 0x8018A760u: goto label_8018A760;
    case 0x8018A764u: goto label_8018A764;
    case 0x8018A768u: goto label_8018A768;
    case 0x8018A76Cu: goto label_8018A76C;
    case 0x8018A770u: goto label_8018A770;
    case 0x8018A774u: goto label_8018A774;
    case 0x8018A778u: goto label_8018A778;
    case 0x8018A77Cu: goto label_8018A77C;
    case 0x8018A780u: goto label_8018A780;
    case 0x8018A784u: goto label_8018A784;
    case 0x8018A788u: goto label_8018A788;
    case 0x8018A78Cu: goto label_8018A78C;
    case 0x8018A790u: goto label_8018A790;
    case 0x8018A794u: goto label_8018A794;
    case 0x8018A798u: goto label_8018A798;
    case 0x8018A79Cu: goto label_8018A79C;
    case 0x8018A7A0u: goto label_8018A7A0;
    case 0x8018A7A4u: goto label_8018A7A4;
    case 0x8018A7A8u: goto label_8018A7A8;
    case 0x8018A7ACu: goto label_8018A7AC;
    case 0x8018A7B0u: goto label_8018A7B0;
    case 0x8018A7B4u: goto label_8018A7B4;
    case 0x8018A7B8u: goto label_8018A7B8;
    case 0x8018A7BCu: goto label_8018A7BC;
    case 0x8018A7C0u: goto label_8018A7C0;
    case 0x8018A7C4u: goto label_8018A7C4;
    case 0x8018A7C8u: goto label_8018A7C8;
    case 0x8018A7CCu: goto label_8018A7CC;
    case 0x8018A7D0u: goto label_8018A7D0;
    case 0x8018A7D4u: goto label_8018A7D4;
    case 0x8018A7D8u: goto label_8018A7D8;
    case 0x8018A7DCu: goto label_8018A7DC;
    case 0x8018A7E0u: goto label_8018A7E0;
    case 0x8018A7E4u: goto label_8018A7E4;
    case 0x8018A7E8u: goto label_8018A7E8;
    case 0x8018A7ECu: goto label_8018A7EC;
    case 0x8018A7F0u: goto label_8018A7F0;
    case 0x8018A7F4u: goto label_8018A7F4;
    case 0x8018A7F8u: goto label_8018A7F8;
    case 0x8018A7FCu: goto label_8018A7FC;
    case 0x8018A800u: goto label_8018A800;
    case 0x8018A804u: goto label_8018A804;
    case 0x8018A808u: goto label_8018A808;
    case 0x8018A80Cu: goto label_8018A80C;
    case 0x8018A810u: goto label_8018A810;
    case 0x8018A814u: goto label_8018A814;
    case 0x8018A818u: goto label_8018A818;
    case 0x8018A81Cu: goto label_8018A81C;
    case 0x8018A820u: goto label_8018A820;
    case 0x8018A824u: goto label_8018A824;
    case 0x8018A828u: goto label_8018A828;
    case 0x8018A82Cu: goto label_8018A82C;
    case 0x8018A830u: goto label_8018A830;
    case 0x8018A834u: goto label_8018A834;
    case 0x8018A838u: goto label_8018A838;
    case 0x8018A83Cu: goto label_8018A83C;
    case 0x8018A840u: goto label_8018A840;
    case 0x8018A844u: goto label_8018A844;
    case 0x8018A848u: goto label_8018A848;
    case 0x8018A84Cu: goto label_8018A84C;
    case 0x8018A850u: goto label_8018A850;
    case 0x8018A854u: goto label_8018A854;
    case 0x8018A858u: goto label_8018A858;
    case 0x8018A85Cu: goto label_8018A85C;
    case 0x8018A860u: goto label_8018A860;
    case 0x8018A864u: goto label_8018A864;
    case 0x8018A868u: goto label_8018A868;
    case 0x8018A86Cu: goto label_8018A86C;
    case 0x8018A870u: goto label_8018A870;
    case 0x8018A874u: goto label_8018A874;
    case 0x8018A878u: goto label_8018A878;
    case 0x8018A87Cu: goto label_8018A87C;
    case 0x8018A880u: goto label_8018A880;
    case 0x8018A884u: goto label_8018A884;
    case 0x8018A888u: goto label_8018A888;
    case 0x8018A88Cu: goto label_8018A88C;
    case 0x8018A890u: goto label_8018A890;
    case 0x8018A894u: goto label_8018A894;
    case 0x8018A898u: goto label_8018A898;
    case 0x8018A89Cu: goto label_8018A89C;
    case 0x8018A8A0u: goto label_8018A8A0;
    case 0x8018A8A4u: goto label_8018A8A4;
    case 0x8018A8A8u: goto label_8018A8A8;
    case 0x8018A8ACu: goto label_8018A8AC;
    case 0x8018A8B0u: goto label_8018A8B0;
    case 0x8018A8B4u: goto label_8018A8B4;
    case 0x8018A8B8u: goto label_8018A8B8;
    case 0x8018A8BCu: goto label_8018A8BC;
    case 0x8018A8C0u: goto label_8018A8C0;
    case 0x8018A8C4u: goto label_8018A8C4;
    case 0x8018A8C8u: goto label_8018A8C8;
    case 0x8018A8CCu: goto label_8018A8CC;
    case 0x8018A8D0u: goto label_8018A8D0;
    case 0x8018A8D4u: goto label_8018A8D4;
    case 0x8018A8D8u: goto label_8018A8D8;
    case 0x8018A8DCu: goto label_8018A8DC;
    case 0x8018A8E0u: goto label_8018A8E0;
    case 0x8018A8E4u: goto label_8018A8E4;
    case 0x8018A8E8u: goto label_8018A8E8;
    case 0x8018A8ECu: goto label_8018A8EC;
    case 0x8018A8F0u: goto label_8018A8F0;
    case 0x8018A8F4u: goto label_8018A8F4;
    case 0x8018A8F8u: goto label_8018A8F8;
    case 0x8018A8FCu: goto label_8018A8FC;
    case 0x8018A900u: goto label_8018A900;
    case 0x8018A904u: goto label_8018A904;
    case 0x8018A908u: goto label_8018A908;
    case 0x8018A90Cu: goto label_8018A90C;
    case 0x8018A910u: goto label_8018A910;
    case 0x8018A914u: goto label_8018A914;
    case 0x8018A918u: goto label_8018A918;
    case 0x8018A91Cu: goto label_8018A91C;
    case 0x8018A920u: goto label_8018A920;
    case 0x8018A924u: goto label_8018A924;
    case 0x8018A928u: goto label_8018A928;
    case 0x8018A92Cu: goto label_8018A92C;
    case 0x8018A930u: goto label_8018A930;
    case 0x8018A934u: goto label_8018A934;
    case 0x8018A938u: goto label_8018A938;
    case 0x8018A93Cu: goto label_8018A93C;
    case 0x8018A940u: goto label_8018A940;
    case 0x8018A944u: goto label_8018A944;
    case 0x8018A948u: goto label_8018A948;
    case 0x8018A94Cu: goto label_8018A94C;
    case 0x8018A950u: goto label_8018A950;
    case 0x8018A954u: goto label_8018A954;
    case 0x8018A958u: goto label_8018A958;
    case 0x8018A95Cu: goto label_8018A95C;
    case 0x8018A960u: goto label_8018A960;
    case 0x8018A964u: goto label_8018A964;
    case 0x8018A968u: goto label_8018A968;
    case 0x8018A96Cu: goto label_8018A96C;
    case 0x8018A970u: goto label_8018A970;
    case 0x8018A974u: goto label_8018A974;
    case 0x8018A978u: goto label_8018A978;
    case 0x8018A97Cu: goto label_8018A97C;
    case 0x8018A980u: goto label_8018A980;
    case 0x8018A984u: goto label_8018A984;
    case 0x8018A988u: goto label_8018A988;
    case 0x8018A98Cu: goto label_8018A98C;
    case 0x8018A990u: goto label_8018A990;
    case 0x8018A994u: goto label_8018A994;
    case 0x8018A998u: goto label_8018A998;
    case 0x8018A99Cu: goto label_8018A99C;
    case 0x8018A9A0u: goto label_8018A9A0;
    case 0x8018A9A4u: goto label_8018A9A4;
    case 0x8018A9A8u: goto label_8018A9A8;
    case 0x8018A9ACu: goto label_8018A9AC;
    case 0x8018A9B0u: goto label_8018A9B0;
    case 0x8018A9B4u: goto label_8018A9B4;
    case 0x8018A9B8u: goto label_8018A9B8;
    case 0x8018A9BCu: goto label_8018A9BC;
    case 0x8018A9C0u: goto label_8018A9C0;
    case 0x8018A9C4u: goto label_8018A9C4;
    case 0x8018A9C8u: goto label_8018A9C8;
    case 0x8018A9CCu: goto label_8018A9CC;
    case 0x8018A9D0u: goto label_8018A9D0;
    case 0x8018A9D4u: goto label_8018A9D4;
    case 0x8018A9D8u: goto label_8018A9D8;
    case 0x8018A9DCu: goto label_8018A9DC;
    case 0x8018A9E0u: goto label_8018A9E0;
    case 0x8018A9E4u: goto label_8018A9E4;
    case 0x8018A9E8u: goto label_8018A9E8;
    case 0x8018A9ECu: goto label_8018A9EC;
    case 0x8018A9F0u: goto label_8018A9F0;
    case 0x8018A9F4u: goto label_8018A9F4;
    case 0x8018A9F8u: goto label_8018A9F8;
    case 0x8018A9FCu: goto label_8018A9FC;
    case 0x8018AA00u: goto label_8018AA00;
    case 0x8018AA04u: goto label_8018AA04;
    case 0x8018AA08u: goto label_8018AA08;
    case 0x8018AA0Cu: goto label_8018AA0C;
    case 0x8018AA10u: goto label_8018AA10;
    case 0x8018AA14u: goto label_8018AA14;
    case 0x8018AA18u: goto label_8018AA18;
    case 0x8018AA1Cu: goto label_8018AA1C;
    case 0x8018AA20u: goto label_8018AA20;
    case 0x8018AA24u: goto label_8018AA24;
    case 0x8018AA28u: goto label_8018AA28;
    case 0x8018AA2Cu: goto label_8018AA2C;
    case 0x8018AA30u: goto label_8018AA30;
    case 0x8018AA34u: goto label_8018AA34;
    case 0x8018AA38u: goto label_8018AA38;
    case 0x8018AA3Cu: goto label_8018AA3C;
    case 0x8018AA40u: goto label_8018AA40;
    case 0x8018AA44u: goto label_8018AA44;
    case 0x8018AA48u: goto label_8018AA48;
    case 0x8018AA4Cu: goto label_8018AA4C;
    case 0x8018AA50u: goto label_8018AA50;
    case 0x8018AA54u: goto label_8018AA54;
    case 0x8018AA58u: goto label_8018AA58;
    case 0x8018AA5Cu: goto label_8018AA5C;
    case 0x8018AA60u: goto label_8018AA60;
    case 0x8018AA64u: goto label_8018AA64;
    case 0x8018AA68u: goto label_8018AA68;
    case 0x8018AA6Cu: goto label_8018AA6C;
    case 0x8018AA70u: goto label_8018AA70;
    case 0x8018AA74u: goto label_8018AA74;
    case 0x8018AA78u: goto label_8018AA78;
    case 0x8018AA7Cu: goto label_8018AA7C;
    case 0x8018AA80u: goto label_8018AA80;
    case 0x8018AA84u: goto label_8018AA84;
    case 0x8018AA88u: goto label_8018AA88;
    case 0x8018AA8Cu: goto label_8018AA8C;
    case 0x8018AA90u: goto label_8018AA90;
    case 0x8018AA94u: goto label_8018AA94;
    case 0x8018AA98u: goto label_8018AA98;
    case 0x8018AA9Cu: goto label_8018AA9C;
    case 0x8018AAA0u: goto label_8018AAA0;
    case 0x8018AAA4u: goto label_8018AAA4;
    case 0x8018AAA8u: goto label_8018AAA8;
    case 0x8018AAACu: goto label_8018AAAC;
    case 0x8018AAB0u: goto label_8018AAB0;
    case 0x8018AAB4u: goto label_8018AAB4;
    case 0x8018AAB8u: goto label_8018AAB8;
    case 0x8018AABCu: goto label_8018AABC;
    case 0x8018AAC0u: goto label_8018AAC0;
    case 0x8018AAC4u: goto label_8018AAC4;
    case 0x8018AAC8u: goto label_8018AAC8;
    case 0x8018AACCu: goto label_8018AACC;
    case 0x8018AAD0u: goto label_8018AAD0;
    case 0x8018AAD4u: goto label_8018AAD4;
    case 0x8018AAD8u: goto label_8018AAD8;
    case 0x8018AADCu: goto label_8018AADC;
    case 0x8018AAE0u: goto label_8018AAE0;
    case 0x8018AAE4u: goto label_8018AAE4;
    case 0x8018AAE8u: goto label_8018AAE8;
    case 0x8018AAECu: goto label_8018AAEC;
    case 0x8018AAF0u: goto label_8018AAF0;
    case 0x8018AAF4u: goto label_8018AAF4;
    case 0x8018AAF8u: goto label_8018AAF8;
    case 0x8018AAFCu: goto label_8018AAFC;
    case 0x8018AB00u: goto label_8018AB00;
    case 0x8018AB04u: goto label_8018AB04;
    case 0x8018AB08u: goto label_8018AB08;
    case 0x8018AB0Cu: goto label_8018AB0C;
    case 0x8018AB10u: goto label_8018AB10;
    case 0x8018AB14u: goto label_8018AB14;
    case 0x8018AB18u: goto label_8018AB18;
    case 0x8018AB1Cu: goto label_8018AB1C;
    case 0x8018AB20u: goto label_8018AB20;
    case 0x8018AB24u: goto label_8018AB24;
    case 0x8018AB28u: goto label_8018AB28;
    case 0x8018AB2Cu: goto label_8018AB2C;
    case 0x8018AB30u: goto label_8018AB30;
    case 0x8018AB34u: goto label_8018AB34;
    case 0x8018AB38u: goto label_8018AB38;
    case 0x8018AB3Cu: goto label_8018AB3C;
    case 0x8018AB40u: goto label_8018AB40;
    case 0x8018AB44u: goto label_8018AB44;
    case 0x8018AB48u: goto label_8018AB48;
    case 0x8018AB4Cu: goto label_8018AB4C;
    case 0x8018AB50u: goto label_8018AB50;
    case 0x8018AB54u: goto label_8018AB54;
    case 0x8018AB58u: goto label_8018AB58;
    case 0x8018AB5Cu: goto label_8018AB5C;
    case 0x8018AB60u: goto label_8018AB60;
    case 0x8018AB64u: goto label_8018AB64;
    case 0x8018AB68u: goto label_8018AB68;
    case 0x8018AB6Cu: goto label_8018AB6C;
    case 0x8018AB70u: goto label_8018AB70;
    case 0x8018AB74u: goto label_8018AB74;
    case 0x8018AB78u: goto label_8018AB78;
    case 0x8018AB7Cu: goto label_8018AB7C;
    case 0x8018AB80u: goto label_8018AB80;
    case 0x8018AB84u: goto label_8018AB84;
    case 0x8018AB88u: goto label_8018AB88;
    case 0x8018AB8Cu: goto label_8018AB8C;
    case 0x8018AB90u: goto label_8018AB90;
    case 0x8018AB94u: goto label_8018AB94;
    case 0x8018AB98u: goto label_8018AB98;
    case 0x8018AB9Cu: goto label_8018AB9C;
    case 0x8018ABA0u: goto label_8018ABA0;
    case 0x8018ABA4u: goto label_8018ABA4;
    case 0x8018ABA8u: goto label_8018ABA8;
    case 0x8018ABACu: goto label_8018ABAC;
    case 0x8018ABB0u: goto label_8018ABB0;
    case 0x8018ABB4u: goto label_8018ABB4;
    case 0x8018ABB8u: goto label_8018ABB8;
    case 0x8018ABBCu: goto label_8018ABBC;
    case 0x8018ABC0u: goto label_8018ABC0;
    case 0x8018ABC4u: goto label_8018ABC4;
    case 0x8018ABC8u: goto label_8018ABC8;
    case 0x8018ABCCu: goto label_8018ABCC;
    case 0x8018ABD0u: goto label_8018ABD0;
    case 0x8018ABD4u: goto label_8018ABD4;
    case 0x8018ABD8u: goto label_8018ABD8;
    case 0x8018ABDCu: goto label_8018ABDC;
    case 0x8018ABE0u: goto label_8018ABE0;
    case 0x8018ABE4u: goto label_8018ABE4;
    case 0x8018ABE8u: goto label_8018ABE8;
    case 0x8018ABECu: goto label_8018ABEC;
    case 0x8018ABF0u: goto label_8018ABF0;
    case 0x8018ABF4u: goto label_8018ABF4;
    case 0x8018ABF8u: goto label_8018ABF8;
    case 0x8018ABFCu: goto label_8018ABFC;
    case 0x8018AC00u: goto label_8018AC00;
    case 0x8018AC04u: goto label_8018AC04;
    case 0x8018AC08u: goto label_8018AC08;
    case 0x8018AC0Cu: goto label_8018AC0C;
    case 0x8018AC10u: goto label_8018AC10;
    case 0x8018AC14u: goto label_8018AC14;
    case 0x8018AC18u: goto label_8018AC18;
    case 0x8018AC1Cu: goto label_8018AC1C;
    case 0x8018AC20u: goto label_8018AC20;
    case 0x8018AC24u: goto label_8018AC24;
    case 0x8018AC28u: goto label_8018AC28;
    case 0x8018AC2Cu: goto label_8018AC2C;
    case 0x8018AC30u: goto label_8018AC30;
    case 0x8018AC34u: goto label_8018AC34;
    case 0x8018AC38u: goto label_8018AC38;
    case 0x8018AC3Cu: goto label_8018AC3C;
    case 0x8018AC40u: goto label_8018AC40;
    case 0x8018AC44u: goto label_8018AC44;
    case 0x8018AC48u: goto label_8018AC48;
    case 0x8018AC4Cu: goto label_8018AC4C;
    case 0x8018AC50u: goto label_8018AC50;
    case 0x8018AC54u: goto label_8018AC54;
    case 0x8018AC58u: goto label_8018AC58;
    case 0x8018AC5Cu: goto label_8018AC5C;
    case 0x8018AC60u: goto label_8018AC60;
    case 0x8018AC64u: goto label_8018AC64;
    case 0x8018AC68u: goto label_8018AC68;
    case 0x8018AC6Cu: goto label_8018AC6C;
    case 0x8018AC70u: goto label_8018AC70;
    case 0x8018AC74u: goto label_8018AC74;
    case 0x8018AC78u: goto label_8018AC78;
    case 0x8018AC7Cu: goto label_8018AC7C;
    case 0x8018AC80u: goto label_8018AC80;
    case 0x8018AC84u: goto label_8018AC84;
    case 0x8018AC88u: goto label_8018AC88;
    case 0x8018AC8Cu: goto label_8018AC8C;
    case 0x8018AC90u: goto label_8018AC90;
    case 0x8018AC94u: goto label_8018AC94;
    case 0x8018AC98u: goto label_8018AC98;
    case 0x8018AC9Cu: goto label_8018AC9C;
    case 0x8018ACA0u: goto label_8018ACA0;
    case 0x8018ACA4u: goto label_8018ACA4;
    case 0x8018ACA8u: goto label_8018ACA8;
    case 0x8018ACACu: goto label_8018ACAC;
    case 0x8018ACB0u: goto label_8018ACB0;
    case 0x8018ACB4u: goto label_8018ACB4;
    case 0x8018ACB8u: goto label_8018ACB8;
    case 0x8018ACBCu: goto label_8018ACBC;
    case 0x8018ACC0u: goto label_8018ACC0;
    case 0x8018ACC4u: goto label_8018ACC4;
    case 0x8018ACC8u: goto label_8018ACC8;
    case 0x8018ACCCu: goto label_8018ACCC;
    case 0x8018ACD0u: goto label_8018ACD0;
    case 0x8018ACD4u: goto label_8018ACD4;
    case 0x8018ACD8u: goto label_8018ACD8;
    case 0x8018ACDCu: goto label_8018ACDC;
    case 0x8018ACE0u: goto label_8018ACE0;
    case 0x8018ACE4u: goto label_8018ACE4;
    case 0x8018ACE8u: goto label_8018ACE8;
    case 0x8018ACECu: goto label_8018ACEC;
    case 0x8018ACF0u: goto label_8018ACF0;
    case 0x8018ACF4u: goto label_8018ACF4;
    case 0x8018ACF8u: goto label_8018ACF8;
    case 0x8018ACFCu: goto label_8018ACFC;
    case 0x8018AD00u: goto label_8018AD00;
    case 0x8018AD04u: goto label_8018AD04;
    case 0x8018AD08u: goto label_8018AD08;
    case 0x8018AD0Cu: goto label_8018AD0C;
    case 0x8018AD10u: goto label_8018AD10;
    case 0x8018AD14u: goto label_8018AD14;
    case 0x8018AD18u: goto label_8018AD18;
    case 0x8018AD1Cu: goto label_8018AD1C;
    case 0x8018AD20u: goto label_8018AD20;
    case 0x8018AD24u: goto label_8018AD24;
    case 0x8018AD28u: goto label_8018AD28;
    case 0x8018AD2Cu: goto label_8018AD2C;
    case 0x8018AD30u: goto label_8018AD30;
    case 0x8018AD34u: goto label_8018AD34;
    case 0x8018AD38u: goto label_8018AD38;
    case 0x8018AD3Cu: goto label_8018AD3C;
    case 0x8018AD40u: goto label_8018AD40;
    case 0x8018AD44u: goto label_8018AD44;
    case 0x8018AD48u: goto label_8018AD48;
    case 0x8018AD4Cu: goto label_8018AD4C;
    case 0x8018AD50u: goto label_8018AD50;
    case 0x8018AD54u: goto label_8018AD54;
    case 0x8018AD58u: goto label_8018AD58;
    case 0x8018AD5Cu: goto label_8018AD5C;
    case 0x8018AD60u: goto label_8018AD60;
    case 0x8018AD64u: goto label_8018AD64;
    case 0x8018AD68u: goto label_8018AD68;
    case 0x8018AD6Cu: goto label_8018AD6C;
    case 0x8018AD70u: goto label_8018AD70;
    case 0x8018AD74u: goto label_8018AD74;
    case 0x8018AD78u: goto label_8018AD78;
    case 0x8018AD7Cu: goto label_8018AD7C;
    case 0x8018AD80u: goto label_8018AD80;
    case 0x8018AD84u: goto label_8018AD84;
    case 0x8018AD88u: goto label_8018AD88;
    case 0x8018AD8Cu: goto label_8018AD8C;
    case 0x8018AD90u: goto label_8018AD90;
    case 0x8018AD94u: goto label_8018AD94;
    case 0x8018AD98u: goto label_8018AD98;
    case 0x8018AD9Cu: goto label_8018AD9C;
    case 0x8018ADA0u: goto label_8018ADA0;
    case 0x8018ADA4u: goto label_8018ADA4;
    case 0x8018ADA8u: goto label_8018ADA8;
    case 0x8018ADACu: goto label_8018ADAC;
    case 0x8018ADB0u: goto label_8018ADB0;
    case 0x8018ADB4u: goto label_8018ADB4;
    case 0x8018ADB8u: goto label_8018ADB8;
    case 0x8018ADBCu: goto label_8018ADBC;
    case 0x8018ADC0u: goto label_8018ADC0;
    case 0x8018ADC4u: goto label_8018ADC4;
    case 0x8018ADC8u: goto label_8018ADC8;
    case 0x8018ADCCu: goto label_8018ADCC;
    case 0x8018ADD0u: goto label_8018ADD0;
    case 0x8018ADD4u: goto label_8018ADD4;
    case 0x8018ADD8u: goto label_8018ADD8;
    case 0x8018ADDCu: goto label_8018ADDC;
    case 0x8018ADE0u: goto label_8018ADE0;
    case 0x8018ADE4u: goto label_8018ADE4;
    case 0x8018ADE8u: goto label_8018ADE8;
    case 0x8018ADECu: goto label_8018ADEC;
    case 0x8018ADF0u: goto label_8018ADF0;
    case 0x8018ADF4u: goto label_8018ADF4;
    case 0x8018ADF8u: goto label_8018ADF8;
    case 0x8018ADFCu: goto label_8018ADFC;
    case 0x8018AE00u: goto label_8018AE00;
    case 0x8018AE04u: goto label_8018AE04;
    case 0x8018AE08u: goto label_8018AE08;
    case 0x8018AE0Cu: goto label_8018AE0C;
    case 0x8018AE10u: goto label_8018AE10;
    case 0x8018AE14u: goto label_8018AE14;
    case 0x8018AE18u: goto label_8018AE18;
    case 0x8018AE1Cu: goto label_8018AE1C;
    case 0x8018AE20u: goto label_8018AE20;
    case 0x8018AE24u: goto label_8018AE24;
    case 0x8018AE28u: goto label_8018AE28;
    case 0x8018AE2Cu: goto label_8018AE2C;
    case 0x8018AE30u: goto label_8018AE30;
    case 0x8018AE34u: goto label_8018AE34;
    case 0x8018AE38u: goto label_8018AE38;
    case 0x8018AE3Cu: goto label_8018AE3C;
    case 0x8018AE40u: goto label_8018AE40;
    case 0x8018AE44u: goto label_8018AE44;
    case 0x8018AE48u: goto label_8018AE48;
    case 0x8018AE4Cu: goto label_8018AE4C;
    case 0x8018AE50u: goto label_8018AE50;
    case 0x8018AE54u: goto label_8018AE54;
    case 0x8018AE58u: goto label_8018AE58;
    case 0x8018AE5Cu: goto label_8018AE5C;
    case 0x8018AE60u: goto label_8018AE60;
    case 0x8018AE64u: goto label_8018AE64;
    case 0x8018AE68u: goto label_8018AE68;
    case 0x8018AE6Cu: goto label_8018AE6C;
    case 0x8018AE70u: goto label_8018AE70;
    case 0x8018AE74u: goto label_8018AE74;
    case 0x8018AE78u: goto label_8018AE78;
    case 0x8018AE7Cu: goto label_8018AE7C;
    case 0x8018AE80u: goto label_8018AE80;
    case 0x8018AE84u: goto label_8018AE84;
    case 0x8018AE88u: goto label_8018AE88;
    case 0x8018AE8Cu: goto label_8018AE8C;
    case 0x8018AE90u: goto label_8018AE90;
    case 0x8018AE94u: goto label_8018AE94;
    case 0x8018AE98u: goto label_8018AE98;
    case 0x8018AE9Cu: goto label_8018AE9C;
    case 0x8018AEA0u: goto label_8018AEA0;
    case 0x8018AEA4u: goto label_8018AEA4;
    case 0x8018AEA8u: goto label_8018AEA8;
    case 0x8018AEACu: goto label_8018AEAC;
    case 0x8018AEB0u: goto label_8018AEB0;
    case 0x8018AEB4u: goto label_8018AEB4;
    case 0x8018AEB8u: goto label_8018AEB8;
    case 0x8018AEBCu: goto label_8018AEBC;
    case 0x8018AEC0u: goto label_8018AEC0;
    case 0x8018AEC4u: goto label_8018AEC4;
    case 0x8018AEC8u: goto label_8018AEC8;
    case 0x8018AECCu: goto label_8018AECC;
    case 0x8018AED0u: goto label_8018AED0;
    case 0x8018AED4u: goto label_8018AED4;
    case 0x8018AED8u: goto label_8018AED8;
    case 0x8018AEDCu: goto label_8018AEDC;
    case 0x8018AEE0u: goto label_8018AEE0;
    case 0x8018AEE4u: goto label_8018AEE4;
    case 0x8018AEE8u: goto label_8018AEE8;
    case 0x8018AEECu: goto label_8018AEEC;
    case 0x8018AEF0u: goto label_8018AEF0;
    case 0x8018AEF4u: goto label_8018AEF4;
    case 0x8018AEF8u: goto label_8018AEF8;
    case 0x8018AEFCu: goto label_8018AEFC;
    case 0x8018AF00u: goto label_8018AF00;
    case 0x8018AF04u: goto label_8018AF04;
    case 0x8018AF08u: goto label_8018AF08;
    case 0x8018AF0Cu: goto label_8018AF0C;
    case 0x8018AF10u: goto label_8018AF10;
    case 0x8018AF14u: goto label_8018AF14;
    case 0x8018AF18u: goto label_8018AF18;
    case 0x8018AF1Cu: goto label_8018AF1C;
    case 0x8018AF20u: goto label_8018AF20;
    case 0x8018AF24u: goto label_8018AF24;
    case 0x8018AF28u: goto label_8018AF28;
    case 0x8018AF2Cu: goto label_8018AF2C;
    case 0x8018AF30u: goto label_8018AF30;
    case 0x8018AF34u: goto label_8018AF34;
    case 0x8018AF38u: goto label_8018AF38;
    case 0x8018AF3Cu: goto label_8018AF3C;
    case 0x8018AF40u: goto label_8018AF40;
    case 0x8018AF44u: goto label_8018AF44;
    case 0x8018AF48u: goto label_8018AF48;
    case 0x8018AF4Cu: goto label_8018AF4C;
    case 0x8018AF50u: goto label_8018AF50;
    case 0x8018AF54u: goto label_8018AF54;
    case 0x8018AF58u: goto label_8018AF58;
    case 0x8018AF5Cu: goto label_8018AF5C;
    case 0x8018AF60u: goto label_8018AF60;
    case 0x8018AF64u: goto label_8018AF64;
    case 0x8018AF68u: goto label_8018AF68;
    case 0x8018AF6Cu: goto label_8018AF6C;
    case 0x8018AF70u: goto label_8018AF70;
    case 0x8018AF74u: goto label_8018AF74;
    case 0x8018AF78u: goto label_8018AF78;
    case 0x8018AF7Cu: goto label_8018AF7C;
    case 0x8018AF80u: goto label_8018AF80;
    case 0x8018AF84u: goto label_8018AF84;
    case 0x8018AF88u: goto label_8018AF88;
    case 0x8018AF8Cu: goto label_8018AF8C;
    case 0x8018AF90u: goto label_8018AF90;
    case 0x8018AF94u: goto label_8018AF94;
    case 0x8018AF98u: goto label_8018AF98;
    case 0x8018AF9Cu: goto label_8018AF9C;
    case 0x8018AFA0u: goto label_8018AFA0;
    case 0x8018AFA4u: goto label_8018AFA4;
    case 0x8018AFA8u: goto label_8018AFA8;
    case 0x8018AFACu: goto label_8018AFAC;
    case 0x8018AFB0u: goto label_8018AFB0;
    case 0x8018AFB4u: goto label_8018AFB4;
    case 0x8018AFB8u: goto label_8018AFB8;
    case 0x8018AFBCu: goto label_8018AFBC;
    case 0x8018AFC0u: goto label_8018AFC0;
    case 0x8018AFC4u: goto label_8018AFC4;
    case 0x8018AFC8u: goto label_8018AFC8;
    case 0x8018AFCCu: goto label_8018AFCC;
    case 0x8018AFD0u: goto label_8018AFD0;
    case 0x8018AFD4u: goto label_8018AFD4;
    case 0x8018AFD8u: goto label_8018AFD8;
    case 0x8018AFDCu: goto label_8018AFDC;
    case 0x8018AFE0u: goto label_8018AFE0;
    case 0x8018AFE4u: goto label_8018AFE4;
    case 0x8018AFE8u: goto label_8018AFE8;
    case 0x8018AFECu: goto label_8018AFEC;
    case 0x8018AFF0u: goto label_8018AFF0;
    case 0x8018AFF4u: goto label_8018AFF4;
    case 0x8018AFF8u: goto label_8018AFF8;
    case 0x8018AFFCu: goto label_8018AFFC;
    case 0x8018B000u: goto label_8018B000;
    case 0x8018B004u: goto label_8018B004;
    case 0x8018B008u: goto label_8018B008;
    case 0x8018B00Cu: goto label_8018B00C;
    case 0x8018B010u: goto label_8018B010;
    case 0x8018B014u: goto label_8018B014;
    case 0x8018B018u: goto label_8018B018;
    case 0x8018B01Cu: goto label_8018B01C;
    case 0x8018B020u: goto label_8018B020;
    case 0x8018B024u: goto label_8018B024;
    case 0x8018B028u: goto label_8018B028;
    case 0x8018B02Cu: goto label_8018B02C;
    case 0x8018B030u: goto label_8018B030;
    case 0x8018B034u: goto label_8018B034;
    case 0x8018B038u: goto label_8018B038;
    case 0x8018B03Cu: goto label_8018B03C;
    case 0x8018B040u: goto label_8018B040;
    case 0x8018B044u: goto label_8018B044;
    case 0x8018B048u: goto label_8018B048;
    case 0x8018B04Cu: goto label_8018B04C;
    case 0x8018B050u: goto label_8018B050;
    case 0x8018B054u: goto label_8018B054;
    case 0x8018B058u: goto label_8018B058;
    case 0x8018B05Cu: goto label_8018B05C;
    case 0x8018B060u: goto label_8018B060;
    case 0x8018B064u: goto label_8018B064;
    case 0x8018B068u: goto label_8018B068;
    case 0x8018B06Cu: goto label_8018B06C;
    case 0x8018B070u: goto label_8018B070;
    case 0x8018B074u: goto label_8018B074;
    case 0x8018B078u: goto label_8018B078;
    case 0x8018B07Cu: goto label_8018B07C;
    case 0x8018B080u: goto label_8018B080;
    case 0x8018B084u: goto label_8018B084;
    case 0x8018B088u: goto label_8018B088;
    case 0x8018B08Cu: goto label_8018B08C;
    case 0x8018B090u: goto label_8018B090;
    case 0x8018B094u: goto label_8018B094;
    case 0x8018B098u: goto label_8018B098;
    case 0x8018B09Cu: goto label_8018B09C;
    case 0x8018B0A0u: goto label_8018B0A0;
    case 0x8018B0A4u: goto label_8018B0A4;
    case 0x8018B0A8u: goto label_8018B0A8;
    case 0x8018B0ACu: goto label_8018B0AC;
    case 0x8018B0B0u: goto label_8018B0B0;
    case 0x8018B0B4u: goto label_8018B0B4;
    case 0x8018B0B8u: goto label_8018B0B8;
    case 0x8018B0BCu: goto label_8018B0BC;
    case 0x8018B0C0u: goto label_8018B0C0;
    case 0x8018B0C4u: goto label_8018B0C4;
    case 0x8018B0C8u: goto label_8018B0C8;
    case 0x8018B0CCu: goto label_8018B0CC;
    case 0x8018B0D0u: goto label_8018B0D0;
    case 0x8018B0D4u: goto label_8018B0D4;
    case 0x8018B0D8u: goto label_8018B0D8;
    case 0x8018B0DCu: goto label_8018B0DC;
    case 0x8018B0E0u: goto label_8018B0E0;
    case 0x8018B0E4u: goto label_8018B0E4;
    case 0x8018B0E8u: goto label_8018B0E8;
    case 0x8018B0ECu: goto label_8018B0EC;
    case 0x8018B0F0u: goto label_8018B0F0;
    case 0x8018B0F4u: goto label_8018B0F4;
    case 0x8018B0F8u: goto label_8018B0F8;
    case 0x8018B0FCu: goto label_8018B0FC;
    case 0x8018B100u: goto label_8018B100;
    case 0x8018B104u: goto label_8018B104;
    case 0x8018B108u: goto label_8018B108;
    case 0x8018B10Cu: goto label_8018B10C;
    case 0x8018B110u: goto label_8018B110;
    case 0x8018B114u: goto label_8018B114;
    case 0x8018B118u: goto label_8018B118;
    case 0x8018B11Cu: goto label_8018B11C;
    case 0x8018B120u: goto label_8018B120;
    case 0x8018B124u: goto label_8018B124;
    case 0x8018B128u: goto label_8018B128;
    case 0x8018B12Cu: goto label_8018B12C;
    case 0x8018B130u: goto label_8018B130;
    case 0x8018B134u: goto label_8018B134;
    case 0x8018B138u: goto label_8018B138;
    case 0x8018B13Cu: goto label_8018B13C;
    case 0x8018B140u: goto label_8018B140;
    case 0x8018B144u: goto label_8018B144;
    case 0x8018B148u: goto label_8018B148;
    case 0x8018B14Cu: goto label_8018B14C;
    case 0x8018B150u: goto label_8018B150;
    case 0x8018B154u: goto label_8018B154;
    case 0x8018B158u: goto label_8018B158;
    case 0x8018B15Cu: goto label_8018B15C;
    case 0x8018B160u: goto label_8018B160;
    case 0x8018B164u: goto label_8018B164;
    case 0x8018B168u: goto label_8018B168;
    case 0x8018B16Cu: goto label_8018B16C;
    case 0x8018B170u: goto label_8018B170;
    case 0x8018B174u: goto label_8018B174;
    case 0x8018B178u: goto label_8018B178;
    case 0x8018B17Cu: goto label_8018B17C;
    case 0x8018B180u: goto label_8018B180;
    case 0x8018B184u: goto label_8018B184;
    case 0x8018B188u: goto label_8018B188;
    case 0x8018B18Cu: goto label_8018B18C;
    case 0x8018B190u: goto label_8018B190;
    case 0x8018B194u: goto label_8018B194;
    case 0x8018B198u: goto label_8018B198;
    case 0x8018B19Cu: goto label_8018B19C;
    case 0x8018B1A0u: goto label_8018B1A0;
    case 0x8018B1A4u: goto label_8018B1A4;
    case 0x8018B1A8u: goto label_8018B1A8;
    case 0x8018B1ACu: goto label_8018B1AC;
    case 0x8018B1B0u: goto label_8018B1B0;
    case 0x8018B1B4u: goto label_8018B1B4;
    case 0x8018B1B8u: goto label_8018B1B8;
    case 0x8018B1BCu: goto label_8018B1BC;
    case 0x8018B1C0u: goto label_8018B1C0;
    case 0x8018B1C4u: goto label_8018B1C4;
    case 0x8018B1C8u: goto label_8018B1C8;
    case 0x8018B1CCu: goto label_8018B1CC;
    case 0x8018B1D0u: goto label_8018B1D0;
    case 0x8018B1D4u: goto label_8018B1D4;
    case 0x8018B1D8u: goto label_8018B1D8;
    case 0x8018B1DCu: goto label_8018B1DC;
    case 0x8018B1E0u: goto label_8018B1E0;
    case 0x8018B1E4u: goto label_8018B1E4;
    case 0x8018B1E8u: goto label_8018B1E8;
    case 0x8018B1ECu: goto label_8018B1EC;
    case 0x8018B1F0u: goto label_8018B1F0;
    case 0x8018B1F4u: goto label_8018B1F4;
    case 0x8018B1F8u: goto label_8018B1F8;
    case 0x8018B1FCu: goto label_8018B1FC;
    case 0x8018B200u: goto label_8018B200;
    case 0x8018B204u: goto label_8018B204;
    case 0x8018B208u: goto label_8018B208;
    case 0x8018B20Cu: goto label_8018B20C;
    case 0x8018B210u: goto label_8018B210;
    case 0x8018B214u: goto label_8018B214;
    case 0x8018B218u: goto label_8018B218;
    case 0x8018B21Cu: goto label_8018B21C;
    case 0x8018B220u: goto label_8018B220;
    case 0x8018B224u: goto label_8018B224;
    case 0x8018B228u: goto label_8018B228;
    case 0x8018B22Cu: goto label_8018B22C;
    case 0x8018B230u: goto label_8018B230;
    case 0x8018B234u: goto label_8018B234;
    case 0x8018B238u: goto label_8018B238;
    case 0x8018B23Cu: goto label_8018B23C;
    case 0x8018B240u: goto label_8018B240;
    case 0x8018B244u: goto label_8018B244;
    case 0x8018B248u: goto label_8018B248;
    case 0x8018B24Cu: goto label_8018B24C;
    case 0x8018B250u: goto label_8018B250;
    case 0x8018B254u: goto label_8018B254;
    case 0x8018B258u: goto label_8018B258;
    case 0x8018B25Cu: goto label_8018B25C;
    case 0x8018B260u: goto label_8018B260;
    case 0x8018B264u: goto label_8018B264;
    case 0x8018B268u: goto label_8018B268;
    case 0x8018B26Cu: goto label_8018B26C;
    case 0x8018B270u: goto label_8018B270;
    case 0x8018B274u: goto label_8018B274;
    case 0x8018B278u: goto label_8018B278;
    case 0x8018B27Cu: goto label_8018B27C;
    case 0x8018B280u: goto label_8018B280;
    case 0x8018B284u: goto label_8018B284;
    case 0x8018B288u: goto label_8018B288;
    case 0x8018B28Cu: goto label_8018B28C;
    case 0x8018B290u: goto label_8018B290;
    case 0x8018B294u: goto label_8018B294;
    case 0x8018B298u: goto label_8018B298;
    case 0x8018B29Cu: goto label_8018B29C;
    case 0x8018B2A0u: goto label_8018B2A0;
    case 0x8018B2A4u: goto label_8018B2A4;
    case 0x8018B2A8u: goto label_8018B2A8;
    case 0x8018B2ACu: goto label_8018B2AC;
    case 0x8018B2B0u: goto label_8018B2B0;
    case 0x8018B2B4u: goto label_8018B2B4;
    case 0x8018B2B8u: goto label_8018B2B8;
    case 0x8018B2BCu: goto label_8018B2BC;
    default: return;
    }
label_801872C0:
    ctx->pc = 0x801872C0u;
    ctx->downcount -= 17;
    // 801872C0: lwz     r6, -26472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26472);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801872C4:
    ctx->pc = 0x801872C4u;
    // 801872C4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801872C8:
    ctx->pc = 0x801872C8u;
    // 801872C8: addi    r29, r4, 2480
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(2480);

label_801872CC:
    ctx->pc = 0x801872CCu;
    // 801872CC: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_801872D0:
    ctx->pc = 0x801872D0u;
    // 801872D0: stw     r6, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801872D4:
    ctx->pc = 0x801872D4u;
    // 801872D4: addi    r31, r5, 2360
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(2360);

label_801872D8:
    ctx->pc = 0x801872D8u;
    // 801872D8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801872DC:
    ctx->pc = 0x801872DCu;
    // 801872DC: stw     r0, -26472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26472);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801872E0:
    ctx->pc = 0x801872E0u;
    // 801872E0: lwz     r4, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801872E4:
    ctx->pc = 0x801872E4u;
    // 801872E4: lwz     r5, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801872E8:
    ctx->pc = 0x801872E8u;
    // 801872E8: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801872EC:
    ctx->pc = 0x801872ECu;
    // 801872EC: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801872F0:
    ctx->pc = 0x801872F0u;
    // 801872F0: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801872F4:
    ctx->pc = 0x801872F4u;
    // 801872F4: or   r3, r5, r3
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[3];
    }

label_801872F8:
    ctx->pc = 0x801872F8u;
    // 801872F8: stw     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801872FC:
    ctx->pc = 0x801872FCu;
    // 801872FC: stw     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187300:
    ctx->pc = 0x80187300u;
    // 80187300: b       0x8018737C
    {
            goto label_8018737C;
    }

label_80187304:
    ctx->pc = 0x80187304u;
    ctx->downcount -= 5;
    // 80187304: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80187308:
    // 80187308: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8018730C:
    ctx->pc = 0x8018730Cu;
    // 8018730C: lwz     r27, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80187310:
    // 80187310: addi    r4, r27, 0
    ctx->gpr[4] = ctx->gpr[27] + (u32)(s32)(0);

label_80187314:
    // 80187314: bl      0x801632BC
    {
            ctx->lr = 0x80187318u;
            ctx->pc = 0x801632BCu;
            return;
    }

label_80187318:
    ctx->downcount -= 5;
    // 80187318: cntlzw r4, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[4] = n;
    }

label_8018731C:
    // 8018731C: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187320:
    // 80187320: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80187324:
    // 80187324: and   r0, r27, r0
    {
        ctx->gpr[0] = ctx->gpr[27] & ctx->gpr[0];
    }

label_80187328:
    // 80187328: bc    4, 0, 0x80187330
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187330;
        }
    }

label_8018732C:
    ctx->downcount -= 1;
    // 8018732C: b       0x80187338
    {
            goto label_80187338;
    }

label_80187330:
    ctx->downcount -= 2;
    // 80187330: cntlzw r3, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_80187334:
    // 80187334: addi    r4, r3, 32
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(32);

label_80187338:
    ctx->downcount -= 9;
    // 80187338: rlwinm r5, r4, 1, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_8018733C:
    // 8018733C: add   r3, r31, r5
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80187340:
    ctx->pc = 0x80187340u;
    // 80187340: lhz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187344:
    // 80187344: add   r3, r29, r5
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80187348:
    // 80187348: subfic  r5, r4, 63
    {
        u64 res = (u64)(u32)(s32)(63) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8018734C:
    ctx->pc = 0x8018734Cu;
    // 8018734C: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187350:
    // 80187350: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80187354:
    // 80187354: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80187358:
    // 80187358: bl      0x801632C4
    {
            ctx->lr = 0x8018735Cu;
            ctx->pc = 0x801632C4u;
            return;
    }

label_8018735C:
    ctx->pc = 0x8018735Cu;
    ctx->downcount -= 8;
    // 8018735C: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187360:
    // 80187360: nor   r5, r3, r3
    {
        ctx->gpr[5] = ~(ctx->gpr[3] | ctx->gpr[3]);
    }

label_80187364:
    // 80187364: nor   r4, r4, r4
    {
        ctx->gpr[4] = ~(ctx->gpr[4] | ctx->gpr[4]);
    }

label_80187368:
    ctx->pc = 0x80187368u;
    // 80187368: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018736C:
    // 8018736C: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80187370:
    // 80187370: and   r3, r3, r4
    {
        ctx->gpr[3] = ctx->gpr[3] & ctx->gpr[4];
    }

label_80187374:
    ctx->pc = 0x80187374u;
    // 80187374: stw     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80187378:
    ctx->pc = 0x80187378u;
    // 80187378: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018737C:
    ctx->pc = 0x8018737Cu;
    ctx->downcount -= 7;
    // 8018737C: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187380:
    // 80187380: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80187384:
    ctx->pc = 0x80187384u;
    // 80187384: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80187388:
    // 80187388: xor   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[3];
    }

label_8018738C:
    // 8018738C: xor   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] ^ ctx->gpr[3];
    }

label_80187390:
    // 80187390: or.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187394:
    // 80187394: bc    4, 2, 0x80187304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187304u;
                return;
            }
            goto label_80187304;
        }
    }

label_80187398:
    ctx->pc = 0x80187398u;
    ctx->downcount -= 4;
    // 80187398: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018739C:
    ctx->pc = 0x8018739Cu;
    // 8018739C: stw     r0, -26500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26500);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801873A0:
    ctx->pc = 0x801873A0u;
    // 801873A0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801873A4:
    ctx->pc = 0x801873A4u;
    // 801873A4: bl      0x80173F54
    {
            ctx->lr = 0x801873A8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801873A8:
    ctx->pc = 0x801873A8u;
    ctx->downcount -= 16;
    // 801873A8: lmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801873AC:
    ctx->pc = 0x801873ACu;
    // 801873AC: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801873B0:
    ctx->pc = 0x801873B0u;
    // 801873B0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_801873B4:
    ctx->pc = 0x801873B4u;
    // 801873B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801873B8:
    ctx->pc = 0x801873B8u;
    // 801873B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801873BC:
    ctx->pc = 0x801873BCu;
    ctx->downcount -= 9;
    // 801873BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801873C0:
    ctx->pc = 0x801873C0u;
    // 801873C0: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_801873C4:
    ctx->pc = 0x801873C4u;
    // 801873C4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801873C8:
    ctx->pc = 0x801873C8u;
    // 801873C8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801873CC:
    ctx->pc = 0x801873CCu;
    // 801873CC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801873D0:
    ctx->pc = 0x801873D0u;
    // 801873D0: addi    r31, r4, 2360
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(2360);

label_801873D4:
    ctx->pc = 0x801873D4u;
    // 801873D4: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801873D8:
    ctx->pc = 0x801873D8u;
    // 801873D8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801873DC:
    ctx->pc = 0x801873DCu;
    // 801873DC: bl      0x80173F2C
    {
            ctx->lr = 0x801873E0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801873E0:
    ctx->pc = 0x801873E0u;
    ctx->downcount -= 10;
    // 801873E0: stw     r30, 288(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(288);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801873E4:
    ctx->pc = 0x801873E4u;
    // 801873E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801873E8:
    ctx->pc = 0x801873E8u;
    // 801873E8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801873EC:
    ctx->pc = 0x801873ECu;
    // 801873EC: stw     r0, -26432(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26432);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801873F0:
    ctx->pc = 0x801873F0u;
    // 801873F0: addi    r3, r31, 240
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(240);

label_801873F4:
    ctx->pc = 0x801873F4u;
    // 801873F4: addi    r4, r31, 292
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(292);

label_801873F8:
    ctx->pc = 0x801873F8u;
    // 801873F8: addi    r5, r31, 296
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(296);

label_801873FC:
    ctx->pc = 0x801873FCu;
    // 801873FC: addi    r6, r31, 316
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(316);

label_80187400:
    ctx->pc = 0x80187400u;
    // 80187400: addi    r7, r31, 320
    ctx->gpr[7] = ctx->gpr[31] + (u32)(s32)(320);

label_80187404:
    ctx->pc = 0x80187404u;
    // 80187404: bl      0x8018619C
    {
            ctx->lr = 0x80187408u;
            ctx->pc = 0x8018619Cu;
            return;
    }

label_80187408:
    ctx->pc = 0x80187408u;
    ctx->downcount -= 2;
    // 80187408: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018740C:
    ctx->pc = 0x8018740Cu;
    // 8018740C: bl      0x80173F54
    {
            ctx->lr = 0x80187410u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80187410:
    ctx->pc = 0x80187410u;
    ctx->downcount -= 7;
    // 80187410: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187414:
    ctx->pc = 0x80187414u;
    // 80187414: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187418:
    ctx->pc = 0x80187418u;
    // 80187418: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018741C:
    ctx->pc = 0x8018741Cu;
    // 8018741C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80187420:
    ctx->pc = 0x80187420u;
    // 80187420: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187424:
    ctx->pc = 0x80187424u;
    // 80187424: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187428:
    ctx->pc = 0x80187428u;
    ctx->downcount -= 9;
    // 80187428: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018742C:
    ctx->pc = 0x8018742Cu;
    // 8018742C: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80187430:
    ctx->pc = 0x80187430u;
    // 80187430: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187434:
    ctx->pc = 0x80187434u;
    // 80187434: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187438:
    ctx->pc = 0x80187438u;
    // 80187438: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018743C:
    ctx->pc = 0x8018743Cu;
    // 8018743C: addi    r31, r4, 2360
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(2360);

label_80187440:
    ctx->pc = 0x80187440u;
    // 80187440: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80187444:
    ctx->pc = 0x80187444u;
    // 80187444: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80187448:
    ctx->pc = 0x80187448u;
    // 80187448: bl      0x80173F2C
    {
            ctx->lr = 0x8018744Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018744C:
    ctx->pc = 0x8018744Cu;
    ctx->downcount -= 10;
    // 8018744C: stw     r30, 312(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(312);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80187450:
    ctx->pc = 0x80187450u;
    // 80187450: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80187454:
    ctx->pc = 0x80187454u;
    // 80187454: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80187458:
    ctx->pc = 0x80187458u;
    // 80187458: stw     r0, -26432(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26432);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018745C:
    ctx->pc = 0x8018745Cu;
    // 8018745C: addi    r3, r31, 240
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(240);

label_80187460:
    ctx->pc = 0x80187460u;
    // 80187460: addi    r4, r31, 292
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(292);

label_80187464:
    ctx->pc = 0x80187464u;
    // 80187464: addi    r5, r31, 296
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(296);

label_80187468:
    ctx->pc = 0x80187468u;
    // 80187468: addi    r6, r31, 316
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(316);

label_8018746C:
    ctx->pc = 0x8018746Cu;
    // 8018746C: addi    r7, r31, 320
    ctx->gpr[7] = ctx->gpr[31] + (u32)(s32)(320);

label_80187470:
    ctx->pc = 0x80187470u;
    // 80187470: bl      0x8018619C
    {
            ctx->lr = 0x80187474u;
            ctx->pc = 0x8018619Cu;
            return;
    }

label_80187474:
    ctx->pc = 0x80187474u;
    ctx->downcount -= 2;
    // 80187474: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80187478:
    ctx->pc = 0x80187478u;
    // 80187478: bl      0x80173F54
    {
            ctx->lr = 0x8018747Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018747C:
    ctx->pc = 0x8018747Cu;
    ctx->downcount -= 7;
    // 8018747C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187480:
    ctx->pc = 0x80187480u;
    // 80187480: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187484:
    ctx->pc = 0x80187484u;
    // 80187484: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80187488:
    ctx->pc = 0x80187488u;
    // 80187488: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018748C:
    ctx->pc = 0x8018748Cu;
    // 8018748C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187490:
    ctx->pc = 0x80187490u;
    // 80187490: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187494:
    ctx->pc = 0x80187494u;
    ctx->downcount -= 9;
    // 80187494: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187498:
    ctx->pc = 0x80187498u;
    // 80187498: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_8018749C:
    ctx->pc = 0x8018749Cu;
    // 8018749C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801874A0:
    ctx->pc = 0x801874A0u;
    // 801874A0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801874A4:
    ctx->pc = 0x801874A4u;
    // 801874A4: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801874A8:
    ctx->pc = 0x801874A8u;
    // 801874A8: addi    r31, r4, 2360
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(2360);

label_801874AC:
    ctx->pc = 0x801874ACu;
    // 801874AC: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801874B0:
    ctx->pc = 0x801874B0u;
    // 801874B0: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801874B4:
    ctx->pc = 0x801874B4u;
    // 801874B4: bl      0x80173F2C
    {
            ctx->lr = 0x801874B8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801874B8:
    ctx->pc = 0x801874B8u;
    ctx->downcount -= 14;
    // 801874B8: stw     r30, 304(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(304);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801874BC:
    ctx->pc = 0x801874BCu;
    // 801874BC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801874C0:
    ctx->pc = 0x801874C0u;
    // 801874C0: lwz     r10, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801874C4:
    ctx->pc = 0x801874C4u;
    // 801874C4: lwz     r0, 304(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801874C8:
    ctx->pc = 0x801874C8u;
    // 801874C8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801874CC:
    ctx->pc = 0x801874CCu;
    // 801874CC: lhz     r3, 250(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(250);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801874D0:
    ctx->pc = 0x801874D0u;
    // 801874D0: lhz     r4, 246(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(246);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_801874D4:
    ctx->pc = 0x801874D4u;
    // 801874D4: lbz     r5, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_801874D8:
    ctx->pc = 0x801874D8u;
    // 801874D8: lhz     r6, 2(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_801874DC:
    ctx->pc = 0x801874DCu;
    // 801874DC: lhz     r7, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_801874E0:
    ctx->pc = 0x801874E0u;
    // 801874E0: lhz     r8, 6(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_801874E4:
    ctx->pc = 0x801874E4u;
    // 801874E4: lhz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_801874E8:
    ctx->pc = 0x801874E8u;
    // 801874E8: lhz     r10, 10(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(10);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_801874EC:
    ctx->pc = 0x801874ECu;
    // 801874EC: bl      0x8018653C
    {
            ctx->lr = 0x801874F0u;
            ctx->pc = 0x8018653Cu;
            return;
    }

label_801874F0:
    ctx->pc = 0x801874F0u;
    ctx->downcount -= 2;
    // 801874F0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801874F4:
    ctx->pc = 0x801874F4u;
    // 801874F4: bl      0x80173F54
    {
            ctx->lr = 0x801874F8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801874F8:
    ctx->pc = 0x801874F8u;
    ctx->downcount -= 7;
    // 801874F8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801874FC:
    ctx->pc = 0x801874FCu;
    // 801874FC: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187500:
    ctx->pc = 0x80187500u;
    // 80187500: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80187504:
    ctx->pc = 0x80187504u;
    // 80187504: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80187508:
    ctx->pc = 0x80187508u;
    // 80187508: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018750C:
    ctx->pc = 0x8018750Cu;
    // 8018750C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187510:
    ctx->pc = 0x80187510u;
    ctx->downcount -= 9;
    // 80187510: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187514:
    ctx->pc = 0x80187514u;
    // 80187514: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80187518:
    ctx->pc = 0x80187518u;
    // 80187518: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018751C:
    ctx->pc = 0x8018751Cu;
    // 8018751C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187520:
    ctx->pc = 0x80187520u;
    // 80187520: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80187524:
    ctx->pc = 0x80187524u;
    // 80187524: addi    r31, r4, 2360
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(2360);

label_80187528:
    ctx->pc = 0x80187528u;
    // 80187528: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018752C:
    ctx->pc = 0x8018752Cu;
    // 8018752C: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80187530:
    ctx->pc = 0x80187530u;
    // 80187530: bl      0x80173F2C
    {
            ctx->lr = 0x80187534u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80187534:
    ctx->pc = 0x80187534u;
    ctx->downcount -= 17;
    // 80187534: stw     r30, 308(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(308);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80187538:
    ctx->pc = 0x80187538u;
    // 80187538: lis     r0, 16384
    ctx->gpr[0] = ((u32)(s32)(16384) << 16);

label_8018753C:
    ctx->pc = 0x8018753Cu;
    // 8018753C: lwz     r7, 308(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(308);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80187540:
    ctx->pc = 0x80187540u;
    // 80187540: lhz     r5, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80187544:
    ctx->pc = 0x80187544u;
    // 80187544: rlwinm r4, r7, 3, 0, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[7], 3u) & 0xFFFFFFF8u;
    }

label_80187548:
    ctx->pc = 0x80187548u;
    // 80187548: rlwinm r5, r5, 0, 29, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF7u;
    }

label_8018754C:
    ctx->pc = 0x8018754Cu;
    // 8018754C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80187550:
    ctx->pc = 0x80187550u;
    // 80187550: sth     r4, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80187554:
    ctx->pc = 0x80187554u;
    // 80187554: cmpwi   r7, 0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187558:
    ctx->pc = 0x80187558u;
    // 80187558: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018755C:
    ctx->pc = 0x8018755Cu;
    // 8018755C: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80187560:
    ctx->pc = 0x80187560u;
    // 80187560: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80187564:
    ctx->pc = 0x80187564u;
    // 80187564: stw     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80187568:
    ctx->pc = 0x80187568u;
    // 80187568: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018756C:
    ctx->pc = 0x8018756Cu;
    // 8018756C: lhz     r5, 244(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(244);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80187570:
    ctx->pc = 0x80187570u;
    // 80187570: lhz     r0, 266(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(266);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187574:
    ctx->pc = 0x80187574u;
    // 80187574: bc    12, 2, 0x8018757C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018757C;
        }
    }

label_80187578:
    ctx->pc = 0x80187578u;
    ctx->downcount -= 1;
    // 80187578: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_8018757C:
    ctx->pc = 0x8018757Cu;
    ctx->downcount -= 3;
    // 8018757C: rlwinm r6, r0, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_80187580:
    ctx->pc = 0x80187580u;
    // 80187580: cmplw   r6, r5
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187584:
    ctx->pc = 0x80187584u;
    // 80187584: bc    4, 0, 0x801875D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801875D4;
        }
    }

label_80187588:
    ctx->pc = 0x80187588u;
    ctx->downcount -= 58;
    // 80187588: rlwinm r4, r6, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0xFFFFFF00u;
    }

label_8018758C:
    ctx->pc = 0x8018758Cu;
    // 8018758C: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_80187590:
    ctx->pc = 0x80187590u;
    // 80187590: add   r0, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80187594:
    ctx->pc = 0x80187594u;
    // 80187594: divwu   r0, r0, r5
    {
        u32 divisor = ctx->gpr[5];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_80187598:
    ctx->pc = 0x80187598u;
    // 80187598: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_8018759C:
    ctx->pc = 0x8018759Cu;
    // 8018759C: sth     r0, 74(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801875A0:
    ctx->pc = 0x801875A0u;
    // 801875A0: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_801875A4:
    ctx->pc = 0x801875A4u;
    // 801875A4: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801875A8:
    ctx->pc = 0x801875A8u;
    // 801875A8: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801875AC:
    ctx->pc = 0x801875ACu;
    // 801875AC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_801875B0:
    ctx->pc = 0x801875B0u;
    // 801875B0: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801875B4:
    ctx->pc = 0x801875B4u;
    // 801875B4: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801875B8:
    ctx->pc = 0x801875B8u;
    // 801875B8: sth     r6, 112(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(112);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_801875BC:
    ctx->pc = 0x801875BCu;
    // 801875BC: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801875C0:
    ctx->pc = 0x801875C0u;
    // 801875C0: lwz     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801875C4:
    ctx->pc = 0x801875C4u;
    // 801875C4: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_801875C8:
    ctx->pc = 0x801875C8u;
    // 801875C8: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801875CC:
    ctx->pc = 0x801875CCu;
    // 801875CC: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801875D0:
    ctx->pc = 0x801875D0u;
    // 801875D0: b       0x801875F4
    {
            goto label_801875F4;
    }

label_801875D4:
    ctx->pc = 0x801875D4u;
    ctx->downcount -= 8;
    // 801875D4: li      r0, 256
    ctx->gpr[0] = (u32)(s32)(256);

label_801875D8:
    ctx->pc = 0x801875D8u;
    // 801875D8: sth     r0, 74(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801875DC:
    ctx->pc = 0x801875DCu;
    // 801875DC: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_801875E0:
    ctx->pc = 0x801875E0u;
    // 801875E0: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801875E4:
    ctx->pc = 0x801875E4u;
    // 801875E4: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801875E8:
    ctx->pc = 0x801875E8u;
    // 801875E8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_801875EC:
    ctx->pc = 0x801875ECu;
    // 801875EC: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801875F0:
    ctx->pc = 0x801875F0u;
    // 801875F0: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801875F4:
    ctx->pc = 0x801875F4u;
    ctx->downcount -= 1;
    // 801875F4: bl      0x80173F54
    {
            ctx->lr = 0x801875F8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801875F8:
    ctx->pc = 0x801875F8u;
    ctx->downcount -= 7;
    // 801875F8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801875FC:
    ctx->pc = 0x801875FCu;
    // 801875FC: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187600:
    ctx->pc = 0x80187600u;
    // 80187600: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80187604:
    ctx->pc = 0x80187604u;
    // 80187604: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80187608:
    ctx->pc = 0x80187608u;
    // 80187608: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018760C:
    ctx->pc = 0x8018760Cu;
    // 8018760C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187610:
    ctx->pc = 0x80187610u;
    ctx->downcount -= 2;
    // 80187610: lwz     r3, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80187614:
    ctx->pc = 0x80187614u;
    // 80187614: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187618:
    ctx->pc = 0x80187618u;
    ctx->downcount -= 5;
    // 80187618: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018761C:
    ctx->pc = 0x8018761Cu;
    // 8018761C: addi    r5, r3, 8192
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(8192);

label_80187620:
    ctx->pc = 0x80187620u;
    // 80187620: lhzu     r0, 44(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[5] = ea;
    }

label_80187624:
    ctx->pc = 0x80187624u;
    // 80187624: addi    r4, r3, 8192
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(8192);

label_80187628:
    ctx->pc = 0x80187628u;
    // 80187628: rlwinm r7, r0, 0, 21, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_8018762C:
    loop_8018762C(ctx);
    if (ctx->pc == 0x80187648u) goto label_80187648;
    return;
label_80187630:
    // 80187630: or   r6, r7, r7
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80187634:
    ctx->pc = 0x80187634u;
    // 80187634: lhz     r3, 46(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(46);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187638:
    // 80187638: rlwinm r7, r0, 0, 21, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_8018763C:
    // 8018763C: cmplw   r6, r7
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187640:
    // 80187640: rlwinm r6, r3, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000007FFu;
    }

label_80187644:
    // 80187644: bc    4, 2, 0x8018762C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018762Cu;
                return;
            }
            goto label_8018762C;
        }
    }

label_80187648:
    ctx->pc = 0x80187648u;
    ctx->downcount -= 47;
    // 80187648: lwz     r3, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018764C:
    ctx->pc = 0x8018764Cu;
    // 8018764C: addi    r5, r7, -1
    ctx->gpr[5] = ctx->gpr[7] + (u32)(s32)(-1);

label_80187650:
    ctx->pc = 0x80187650u;
    // 80187650: addi    r4, r6, -1
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(-1);

label_80187654:
    ctx->pc = 0x80187654u;
    // 80187654: lhz     r0, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187658:
    ctx->pc = 0x80187658u;
    // 80187658: rlwinm r3, r5, 1, 0, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 1u) & 0xFFFFFFFEu;
    }

label_8018765C:
    ctx->pc = 0x8018765Cu;
    // 8018765C: divwu   r0, r4, r0
    {
        u32 divisor = ctx->gpr[0];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[4] / divisor;
    }

label_80187660:
    ctx->pc = 0x80187660u;
    // 80187660: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80187664:
    ctx->pc = 0x80187664u;
    // 80187664: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187668:
    ctx->pc = 0x80187668u;
    ctx->downcount -= 5;
    // 80187668: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018766C:
    ctx->pc = 0x8018766Cu;
    // 8018766C: addi    r7, r3, 8192
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(8192);

label_80187670:
    ctx->pc = 0x80187670u;
    // 80187670: lhzu     r0, 44(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[7] = ea;
    }

label_80187674:
    ctx->pc = 0x80187674u;
    // 80187674: addi    r4, r3, 8192
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(8192);

label_80187678:
    ctx->pc = 0x80187678u;
    // 80187678: rlwinm r5, r0, 0, 21, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_8018767C:
    loop_8018767C(ctx);
    if (ctx->pc == 0x80187698u) goto label_80187698;
    return;
label_80187680:
    // 80187680: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80187684:
    ctx->pc = 0x80187684u;
    // 80187684: lhz     r3, 46(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(46);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187688:
    // 80187688: rlwinm r5, r0, 0, 21, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_8018768C:
    // 8018768C: cmplw   r6, r5
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187690:
    // 80187690: rlwinm r3, r3, 0, 21, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000007FFu;
    }

label_80187694:
    // 80187694: bc    4, 2, 0x8018767C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018767Cu;
                return;
            }
            goto label_8018767C;
        }
    }

label_80187698:
    ctx->pc = 0x80187698u;
    ctx->downcount -= 49;
    // 80187698: lwz     r6, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8018769C:
    ctx->pc = 0x8018769Cu;
    // 8018769C: addi    r0, r5, -1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-1);

label_801876A0:
    ctx->pc = 0x801876A0u;
    // 801876A0: addi    r4, r3, -1
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-1);

label_801876A4:
    ctx->pc = 0x801876A4u;
    // 801876A4: lhz     r3, 26(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(26);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801876A8:
    ctx->pc = 0x801876A8u;
    // 801876A8: rlwinm r5, r0, 1, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_801876AC:
    ctx->pc = 0x801876ACu;
    // 801876AC: lhz     r0, 24(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801876B0:
    ctx->pc = 0x801876B0u;
    // 801876B0: divwu   r3, r4, r3
    {
        u32 divisor = ctx->gpr[3];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[4] / divisor;
    }

label_801876B4:
    ctx->pc = 0x801876B4u;
    // 801876B4: add   r3, r5, r3
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801876B8:
    ctx->pc = 0x801876B8u;
    // 801876B8: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801876BC:
    ctx->pc = 0x801876BCu;
    // 801876BC: bc    4, 0, 0x801876C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801876C8;
        }
    }

label_801876C0:
    ctx->pc = 0x801876C0u;
    ctx->downcount -= 2;
    // 801876C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801876C4:
    ctx->pc = 0x801876C4u;
    // 801876C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801876C8:
    ctx->pc = 0x801876C8u;
    ctx->downcount -= 2;
    // 801876C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801876CC:
    ctx->pc = 0x801876CCu;
    // 801876CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801876D0:
    ctx->pc = 0x801876D0u;
    ctx->downcount -= 5;
    // 801876D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801876D4:
    ctx->pc = 0x801876D4u;
    // 801876D4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801876D8:
    ctx->pc = 0x801876D8u;
    // 801876D8: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801876DC:
    ctx->pc = 0x801876DCu;
    // 801876DC: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801876E0:
    ctx->pc = 0x801876E0u;
    // 801876E0: bl      0x80173F2C
    {
            ctx->lr = 0x801876E4u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801876E4:
    ctx->pc = 0x801876E4u;
    ctx->downcount -= 5;
    // 801876E4: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_801876E8:
    ctx->pc = 0x801876E8u;
    // 801876E8: addi    r8, r4, 8192
    ctx->gpr[8] = ctx->gpr[4] + (u32)(s32)(8192);

label_801876EC:
    ctx->pc = 0x801876ECu;
    // 801876EC: lhzu     r0, 44(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[8] = ea;
    }

label_801876F0:
    ctx->pc = 0x801876F0u;
    // 801876F0: addi    r5, r4, 8192
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(8192);

label_801876F4:
    ctx->pc = 0x801876F4u;
    // 801876F4: rlwinm r6, r0, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_801876F8:
    loop_801876F8(ctx);
    if (ctx->pc == 0x80187714u) goto label_80187714;
    return;
label_801876FC:
    // 801876FC: or   r7, r6, r6
    {
        ctx->gpr[7] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80187700:
    ctx->pc = 0x80187700u;
    // 80187700: lhz     r4, 46(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(46);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80187704:
    // 80187704: rlwinm r6, r0, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_80187708:
    // 80187708: cmplw   r7, r6
    {
        u32 val_a = (u32)(ctx->gpr[7]);
        u32 val_b = (u32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018770C:
    // 8018770C: rlwinm r4, r4, 0, 21, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000007FFu;
    }

label_80187710:
    // 80187710: bc    4, 2, 0x801876F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801876F8u;
                return;
            }
            goto label_801876F8;
        }
    }

label_80187714:
    ctx->pc = 0x80187714u;
    ctx->downcount -= 49;
    // 80187714: lwz     r7, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80187718:
    ctx->pc = 0x80187718u;
    // 80187718: addi    r0, r6, -1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-1);

label_8018771C:
    ctx->pc = 0x8018771Cu;
    // 8018771C: addi    r5, r4, -1
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(-1);

label_80187720:
    ctx->pc = 0x80187720u;
    // 80187720: lhz     r4, 26(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(26);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80187724:
    ctx->pc = 0x80187724u;
    // 80187724: rlwinm r6, r0, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80187728:
    ctx->pc = 0x80187728u;
    // 80187728: lhz     r0, 24(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018772C:
    ctx->pc = 0x8018772Cu;
    // 8018772C: divwu   r4, r5, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[4] = divisor == 0 ? 0u : ctx->gpr[5] / divisor;
    }

label_80187730:
    ctx->pc = 0x80187730u;
    // 80187730: add   r4, r6, r4
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80187734:
    ctx->pc = 0x80187734u;
    // 80187734: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187738:
    ctx->pc = 0x80187738u;
    // 80187738: bc    4, 0, 0x80187744
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187744;
        }
    }

label_8018773C:
    ctx->pc = 0x8018773Cu;
    ctx->downcount -= 2;
    // 8018773C: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_80187740:
    ctx->pc = 0x80187740u;
    // 80187740: b       0x80187748
    {
            goto label_80187748;
    }

label_80187744:
    ctx->pc = 0x80187744u;
    ctx->downcount -= 1;
    // 80187744: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80187748:
    ctx->pc = 0x80187748u;
    ctx->downcount -= 1;
    // 80187748: bl      0x80173F54
    {
            ctx->lr = 0x8018774Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018774C:
    ctx->pc = 0x8018774Cu;
    ctx->downcount -= 12;
    // 8018774C: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80187750:
    ctx->pc = 0x80187750u;
    // 80187750: addi    r3, r3, 2600
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2600);

label_80187754:
    ctx->pc = 0x80187754u;
    // 80187754: lhz     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187758:
    ctx->pc = 0x80187758u;
    // 80187758: xori    r3, r31, 0x0001
    ctx->gpr[3] = ctx->gpr[31] ^ 0x0001u;

label_8018775C:
    ctx->pc = 0x8018775Cu;
    // 8018775C: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80187760:
    ctx->pc = 0x80187760u;
    // 80187760: xor   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] ^ ctx->gpr[0];
    }

label_80187764:
    ctx->pc = 0x80187764u;
    // 80187764: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187768:
    ctx->pc = 0x80187768u;
    // 80187768: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018776C:
    ctx->pc = 0x8018776Cu;
    // 8018776C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80187770:
    ctx->pc = 0x80187770u;
    // 80187770: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187774:
    ctx->pc = 0x80187774u;
    // 80187774: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187778:
    ctx->pc = 0x80187778u;
    ctx->downcount -= 7;
    // 80187778: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018777C:
    ctx->pc = 0x8018777Cu;
    // 8018777C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187780:
    ctx->pc = 0x80187780u;
    // 80187780: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187784:
    ctx->pc = 0x80187784u;
    // 80187784: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80187788:
    ctx->pc = 0x80187788u;
    // 80187788: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018778C:
    ctx->pc = 0x8018778Cu;
    // 8018778C: lwz     r31, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187790:
    ctx->pc = 0x80187790u;
    // 80187790: bl      0x80173F2C
    {
            ctx->lr = 0x80187794u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80187794:
    ctx->pc = 0x80187794u;
    ctx->downcount -= 5;
    // 80187794: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80187798:
    ctx->pc = 0x80187798u;
    // 80187798: addi    r8, r4, 8192
    ctx->gpr[8] = ctx->gpr[4] + (u32)(s32)(8192);

label_8018779C:
    ctx->pc = 0x8018779Cu;
    // 8018779C: lhzu     r0, 44(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[8] = ea;
    }

label_801877A0:
    ctx->pc = 0x801877A0u;
    // 801877A0: addi    r5, r4, 8192
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(8192);

label_801877A4:
    ctx->pc = 0x801877A4u;
    // 801877A4: rlwinm r6, r0, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_801877A8:
    loop_801877A8(ctx);
    if (ctx->pc == 0x801877C4u) goto label_801877C4;
    return;
label_801877AC:
    // 801877AC: or   r7, r6, r6
    {
        ctx->gpr[7] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801877B0:
    ctx->pc = 0x801877B0u;
    // 801877B0: lhz     r4, 46(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(46);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_801877B4:
    // 801877B4: rlwinm r6, r0, 0, 21, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000007FFu;
    }

label_801877B8:
    // 801877B8: cmplw   r7, r6
    {
        u32 val_a = (u32)(ctx->gpr[7]);
        u32 val_b = (u32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801877BC:
    // 801877BC: rlwinm r7, r4, 0, 21, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000007FFu;
    }

label_801877C0:
    // 801877C0: bc    4, 2, 0x801877A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801877A8u;
                return;
            }
            goto label_801877A8;
        }
    }

label_801877C4:
    ctx->pc = 0x801877C4u;
    ctx->downcount -= 47;
    // 801877C4: lwz     r4, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801877C8:
    ctx->pc = 0x801877C8u;
    // 801877C8: addi    r5, r7, -1
    ctx->gpr[5] = ctx->gpr[7] + (u32)(s32)(-1);

label_801877CC:
    ctx->pc = 0x801877CCu;
    // 801877CC: addi    r6, r6, -1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-1);

label_801877D0:
    ctx->pc = 0x801877D0u;
    // 801877D0: lhz     r0, 26(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(26);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801877D4:
    ctx->pc = 0x801877D4u;
    // 801877D4: rlwinm r4, r6, 1, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_801877D8:
    ctx->pc = 0x801877D8u;
    // 801877D8: divwu   r0, r5, r0
    {
        u32 divisor = ctx->gpr[0];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[5] / divisor;
    }

label_801877DC:
    ctx->pc = 0x801877DCu;
    // 801877DC: add   r30, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_801877E0:
    ctx->pc = 0x801877E0u;
    // 801877E0: bl      0x80173F54
    {
            ctx->lr = 0x801877E4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801877E4:
    ctx->pc = 0x801877E4u;
    ctx->downcount -= 3;
    // 801877E4: lhz     r0, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801877E8:
    ctx->pc = 0x801877E8u;
    // 801877E8: cmplw   r30, r0
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801877EC:
    ctx->pc = 0x801877ECu;
    // 801877EC: bc    12, 0, 0x801877F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801877F4;
        }
    }

label_801877F0:
    ctx->pc = 0x801877F0u;
    ctx->downcount -= 1;
    // 801877F0: subf   r30, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_801877F4:
    ctx->pc = 0x801877F4u;
    ctx->downcount -= 8;
    // 801877F4: rlwinm r3, r30, 31, 1, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 31u) & 0x7FFFFFFFu;
    }

label_801877F8:
    ctx->pc = 0x801877F8u;
    // 801877F8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801877FC:
    ctx->pc = 0x801877FCu;
    // 801877FC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187800:
    ctx->pc = 0x80187800u;
    // 80187800: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80187804:
    ctx->pc = 0x80187804u;
    // 80187804: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80187808:
    ctx->pc = 0x80187808u;
    // 80187808: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018780C:
    ctx->pc = 0x8018780Cu;
    // 8018780C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187810:
    ctx->pc = 0x80187810u;
    ctx->downcount -= 5;
    // 80187810: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187814:
    ctx->pc = 0x80187814u;
    // 80187814: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187818:
    ctx->pc = 0x80187818u;
    // 80187818: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018781C:
    ctx->pc = 0x8018781Cu;
    // 8018781C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80187820:
    ctx->pc = 0x80187820u;
    // 80187820: bl      0x80173F2C
    {
            ctx->lr = 0x80187824u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80187824:
    ctx->pc = 0x80187824u;
    ctx->downcount -= 3;
    // 80187824: lwz     r0, -26436(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26436);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187828:
    ctx->pc = 0x80187828u;
    // 80187828: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018782C:
    ctx->pc = 0x8018782Cu;
    // 8018782C: bc    12, 2, 0x8018785C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018785C;
        }
    }

label_80187830:
    ctx->pc = 0x80187830u;
    ctx->downcount -= 1;
    // 80187830: bc    4, 0, 0x8018784C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018784C;
        }
    }

label_80187834:
    ctx->pc = 0x80187834u;
    ctx->downcount -= 2;
    // 80187834: cmpwi   r0, 1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187838:
    ctx->pc = 0x80187838u;
    // 80187838: bc    12, 2, 0x80187864
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187864;
        }
    }

label_8018783C:
    ctx->pc = 0x8018783Cu;
    ctx->downcount -= 1;
    // 8018783C: bc    4, 0, 0x8018786C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018786C;
        }
    }

label_80187840:
    ctx->pc = 0x80187840u;
    ctx->downcount -= 2;
    // 80187840: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187844:
    ctx->pc = 0x80187844u;
    // 80187844: bc    4, 0, 0x8018785C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018785C;
        }
    }

label_80187848:
    ctx->pc = 0x80187848u;
    ctx->downcount -= 1;
    // 80187848: b       0x80187870
    {
            goto label_80187870;
    }

label_8018784C:
    ctx->pc = 0x8018784Cu;
    ctx->downcount -= 2;
    // 8018784C: cmpwi   r0, 5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187850:
    ctx->pc = 0x80187850u;
    // 80187850: bc    12, 2, 0x8018786C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018786C;
        }
    }

label_80187854:
    ctx->pc = 0x80187854u;
    ctx->downcount -= 1;
    // 80187854: bc    4, 0, 0x80187870
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187870;
        }
    }

label_80187858:
    ctx->pc = 0x80187858u;
    ctx->downcount -= 1;
    // 80187858: b       0x80187864
    {
            goto label_80187864;
    }

label_8018785C:
    ctx->pc = 0x8018785Cu;
    ctx->downcount -= 2;
    // 8018785C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80187860:
    ctx->pc = 0x80187860u;
    // 80187860: b       0x80187870
    {
            goto label_80187870;
    }

label_80187864:
    ctx->pc = 0x80187864u;
    ctx->downcount -= 2;
    // 80187864: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_80187868:
    ctx->pc = 0x80187868u;
    // 80187868: b       0x80187870
    {
            goto label_80187870;
    }

label_8018786C:
    ctx->pc = 0x8018786Cu;
    ctx->downcount -= 1;
    // 8018786C: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80187870:
    ctx->pc = 0x80187870u;
    ctx->downcount -= 1;
    // 80187870: bl      0x80173F54
    {
            ctx->lr = 0x80187874u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80187874:
    ctx->pc = 0x80187874u;
    ctx->downcount -= 7;
    // 80187874: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80187878:
    ctx->pc = 0x80187878u;
    // 80187878: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018787C:
    ctx->pc = 0x8018787Cu;
    // 8018787C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187880:
    ctx->pc = 0x80187880u;
    // 80187880: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80187884:
    ctx->pc = 0x80187884u;
    // 80187884: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187888:
    ctx->pc = 0x80187888u;
    // 80187888: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018788C:
    ctx->pc = 0x8018788Cu;
    ctx->downcount -= 5;
    // 8018788C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187890:
    ctx->pc = 0x80187890u;
    // 80187890: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187894:
    ctx->pc = 0x80187894u;
    // 80187894: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187898:
    ctx->pc = 0x80187898u;
    // 80187898: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018789C:
    ctx->pc = 0x8018789Cu;
    // 8018789C: bl      0x80173F2C
    {
            ctx->lr = 0x801878A0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801878A0:
    ctx->pc = 0x801878A0u;
    ctx->downcount -= 4;
    // 801878A0: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_801878A4:
    ctx->pc = 0x801878A4u;
    // 801878A4: lhz     r0, 8302(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8302);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801878A8:
    ctx->pc = 0x801878A8u;
    // 801878A8: rlwinm r31, r0, 0, 30, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000003u;
    }

label_801878AC:
    ctx->pc = 0x801878ACu;
    // 801878AC: bl      0x80173F54
    {
            ctx->lr = 0x801878B0u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801878B0:
    ctx->pc = 0x801878B0u;
    ctx->downcount -= 7;
    // 801878B0: rlwinm r3, r31, 0, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000001u;
    }

label_801878B4:
    ctx->pc = 0x801878B4u;
    // 801878B4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801878B8:
    ctx->pc = 0x801878B8u;
    // 801878B8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801878BC:
    ctx->pc = 0x801878BCu;
    // 801878BC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801878C0:
    ctx->pc = 0x801878C0u;
    // 801878C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801878C4:
    ctx->pc = 0x801878C4u;
    // 801878C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801878C8:
    ctx->pc = 0x801878C8u;
    ctx->downcount -= 19;
    // 801878C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801878CC:
    ctx->pc = 0x801878CCu;
    // 801878CC: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

label_801878D0:
    ctx->pc = 0x801878D0u;
    // 801878D0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801878D4:
    ctx->pc = 0x801878D4u;
    // 801878D4: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801878D8:
    ctx->pc = 0x801878D8u;
    // 801878D8: stmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801878DC:
    ctx->pc = 0x801878DCu;
    // 801878DC: addi    r28, r3, 0
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(0);

label_801878E0:
    ctx->pc = 0x801878E0u;
    // 801878E0: addi    r27, r4, 0
    ctx->gpr[27] = ctx->gpr[4] + (u32)(s32)(0);

label_801878E4:
    ctx->pc = 0x801878E4u;
    // 801878E4: addi    r30, r5, 2360
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(2360);

label_801878E8:
    ctx->pc = 0x801878E8u;
    // 801878E8: bl      0x80173F2C
    {
            ctx->lr = 0x801878ECu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801878EC:
    ctx->pc = 0x801878ECu;
    ctx->downcount -= 13;
    // 801878EC: sth     r28, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_801878F0:
    ctx->pc = 0x801878F0u;
    // 801878F0: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_801878F4:
    ctx->pc = 0x801878F4u;
    // 801878F4: extsh r4, r28
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_801878F8:
    ctx->pc = 0x801878F8u;
    // 801878F8: sth     r27, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        mem_write16(ctx, ea, (u16)ctx->gpr[27]);
    }

label_801878FC:
    ctx->pc = 0x801878FCu;
    // 801878FC: addi    r9, r30, 244
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(244);

label_80187900:
    ctx->pc = 0x80187900u;
    // 80187900: lha     r3, 240(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(240);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187904:
    ctx->pc = 0x80187904u;
    // 80187904: lhz     r0, 244(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187908:
    ctx->pc = 0x80187908u;
    // 80187908: lwz     r29, 324(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(324);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018790C:
    ctx->pc = 0x8018790Cu;
    // 8018790C: add   r3, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80187910:
    ctx->pc = 0x80187910u;
    // 80187910: subfic  r0, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80187914:
    ctx->pc = 0x80187914u;
    // 80187914: cmpw    r3, r0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187918:
    ctx->pc = 0x80187918u;
    // 80187918: lhz     r6, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8018791C:
    ctx->pc = 0x8018791Cu;
    // 8018791C: bc    4, 1, 0x80187924
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187924;
        }
    }

label_80187920:
    ctx->pc = 0x80187920u;
    ctx->downcount -= 1;
    // 80187920: b       0x80187934
    {
            goto label_80187934;
    }

label_80187924:
    ctx->pc = 0x80187924u;
    ctx->downcount -= 2;
    // 80187924: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187928:
    ctx->pc = 0x80187928u;
    // 80187928: bc    4, 0, 0x80187930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187930;
        }
    }

label_8018792C:
    ctx->pc = 0x8018792Cu;
    ctx->downcount -= 1;
    // 8018792C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80187930:
    ctx->pc = 0x80187930u;
    ctx->downcount -= 1;
    // 80187930: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80187934:
    ctx->pc = 0x80187934u;
    ctx->downcount -= 5;
    // 80187934: sth     r0, 248(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(248);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187938:
    ctx->pc = 0x80187938u;
    // 80187938: addi    r8, r30, 248
    ctx->gpr[8] = ctx->gpr[30] + (u32)(s32)(248);

label_8018793C:
    ctx->pc = 0x8018793Cu;
    // 8018793C: lwz     r0, 272(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187940:
    ctx->pc = 0x80187940u;
    // 80187940: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187944:
    ctx->pc = 0x80187944u;
    // 80187944: bc    4, 2, 0x80187950
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187950;
        }
    }

label_80187948:
    ctx->pc = 0x80187948u;
    ctx->downcount -= 2;
    // 80187948: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8018794C:
    ctx->pc = 0x8018794Cu;
    // 8018794C: b       0x80187954
    {
            goto label_80187954;
    }

label_80187950:
    ctx->pc = 0x80187950u;
    ctx->downcount -= 1;
    // 80187950: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80187954:
    ctx->pc = 0x80187954u;
    ctx->downcount -= 8;
    // 80187954: lhz     r3, 242(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(242);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187958:
    ctx->pc = 0x80187958u;
    // 80187958: extsh r4, r27
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[27];
    }

label_8018795C:
    ctx->pc = 0x8018795Cu;
    // 8018795C: addi    r5, r30, 242
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(242);

label_80187960:
    ctx->pc = 0x80187960u;
    // 80187960: extsh r7, r3
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_80187964:
    ctx->pc = 0x80187964u;
    // 80187964: rlwinm r3, r3, 0, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
    }

label_80187968:
    ctx->pc = 0x80187968u;
    // 80187968: add   r7, r7, r4
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8018796C:
    ctx->pc = 0x8018796Cu;
    // 8018796C: cmpw    r7, r3
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187970:
    ctx->pc = 0x80187970u;
    // 80187970: bc    4, 1, 0x80187978
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187978;
        }
    }

label_80187974:
    ctx->pc = 0x80187974u;
    ctx->downcount -= 1;
    // 80187974: b       0x8018797C
    {
            goto label_8018797C;
    }

label_80187978:
    ctx->pc = 0x80187978u;
    ctx->downcount -= 1;
    // 80187978: or   r7, r3, r3
    {
        ctx->gpr[7] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018797C:
    ctx->pc = 0x8018797Cu;
    ctx->downcount -= 13;
    // 8018797C: sth     r7, 250(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(250);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80187980:
    ctx->pc = 0x80187980u;
    // 80187980: extsh r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s16)ctx->gpr[6];
    }

label_80187984:
    ctx->pc = 0x80187984u;
    // 80187984: rlwinm r6, r6, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_80187988:
    ctx->pc = 0x80187988u;
    // 80187988: lhz     r28, 246(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(246);
        ctx->gpr[28] = mem_read16(ctx, ea);
    }

label_8018798C:
    ctx->pc = 0x8018798Cu;
    // 8018798C: subf   r6, r3, r6
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80187990:
    ctx->pc = 0x80187990u;
    // 80187990: lha     r12, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[12] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187994:
    ctx->pc = 0x80187994u;
    // 80187994: addi    r27, r30, 250
    ctx->gpr[27] = ctx->gpr[30] + (u32)(s32)(250);

label_80187998:
    ctx->pc = 0x80187998u;
    // 80187998: extsh r10, r28
    {
        ctx->gpr[10] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_8018799C:
    ctx->pc = 0x8018799Cu;
    // 8018799C: add   r11, r10, r4
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801879A0:
    ctx->pc = 0x801879A0u;
    // 801879A0: add   r11, r12, r11
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801879A4:
    ctx->pc = 0x801879A4u;
    // 801879A4: subf.   r10, r6, r11
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801879A8:
    ctx->pc = 0x801879A8u;
    // 801879A8: addi    r7, r30, 246
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(246);

label_801879AC:
    ctx->pc = 0x801879ACu;
    // 801879AC: bc    4, 1, 0x801879B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801879B8;
        }
    }

label_801879B0:
    ctx->pc = 0x801879B0u;
    ctx->downcount -= 2;
    // 801879B0: subf   r11, r6, r11
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[11] = res;
    }

label_801879B4:
    ctx->pc = 0x801879B4u;
    // 801879B4: b       0x801879BC
    {
            goto label_801879BC;
    }

label_801879B8:
    ctx->pc = 0x801879B8u;
    ctx->downcount -= 1;
    // 801879B8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_801879BC:
    ctx->pc = 0x801879BCu;
    ctx->downcount -= 3;
    // 801879BC: add   r12, r12, r4
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[12] = res;
    }

label_801879C0:
    ctx->pc = 0x801879C0u;
    // 801879C0: subf.   r10, r3, r12
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[12];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801879C4:
    ctx->pc = 0x801879C4u;
    // 801879C4: bc    4, 0, 0x801879D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801879D0;
        }
    }

label_801879C8:
    ctx->pc = 0x801879C8u;
    ctx->downcount -= 2;
    // 801879C8: subf   r10, r3, r12
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[12];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801879CC:
    ctx->pc = 0x801879CCu;
    // 801879CC: b       0x801879D4
    {
            goto label_801879D4;
    }

label_801879D0:
    ctx->pc = 0x801879D0u;
    ctx->downcount -= 1;
    // 801879D0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801879D4:
    ctx->pc = 0x801879D4u;
    ctx->downcount -= 8;
    // 801879D4: add   r10, r28, r10
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_801879D8:
    ctx->pc = 0x801879D8u;
    // 801879D8: subf   r10, r11, r10
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801879DC:
    ctx->pc = 0x801879DCu;
    // 801879DC: addi    r28, r30, 252
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(252);

label_801879E0:
    ctx->pc = 0x801879E0u;
    // 801879E0: sth     r10, 252(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(252);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_801879E4:
    ctx->pc = 0x801879E4u;
    // 801879E4: lha     r10, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801879E8:
    ctx->pc = 0x801879E8u;
    // 801879E8: add   r11, r10, r4
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_801879EC:
    ctx->pc = 0x801879ECu;
    // 801879EC: subf.   r10, r3, r11
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801879F0:
    ctx->pc = 0x801879F0u;
    // 801879F0: bc    4, 0, 0x801879FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801879FC;
        }
    }

label_801879F4:
    ctx->pc = 0x801879F4u;
    ctx->downcount -= 2;
    // 801879F4: subf   r10, r3, r11
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_801879F8:
    ctx->pc = 0x801879F8u;
    // 801879F8: b       0x80187A00
    {
            goto label_80187A00;
    }

label_801879FC:
    ctx->pc = 0x801879FCu;
    ctx->downcount -= 1;
    // 801879FC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80187A00:
    ctx->pc = 0x80187A00u;
    ctx->downcount -= 49;
    // 80187A00: divw   r11, r10, r0
    {
        s32 dividend = (s32)ctx->gpr[10];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[11] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80187A04:
    ctx->pc = 0x80187A04u;
    // 80187A04: lhz     r10, 264(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(264);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_80187A08:
    ctx->pc = 0x80187A08u;
    // 80187A08: subf   r10, r11, r10
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[10] = res;
    }

label_80187A0C:
    ctx->pc = 0x80187A0Cu;
    // 80187A0C: sth     r10, 254(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(254);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_80187A10:
    ctx->pc = 0x80187A10u;
    // 80187A10: lha     r7, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187A14:
    ctx->pc = 0x80187A14u;
    // 80187A14: lha     r10, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187A18:
    ctx->pc = 0x80187A18u;
    // 80187A18: add   r7, r7, r4
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80187A1C:
    ctx->pc = 0x80187A1Cu;
    // 80187A1C: add   r7, r10, r7
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80187A20:
    ctx->pc = 0x80187A20u;
    // 80187A20: subf.   r5, r6, r7
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187A24:
    ctx->pc = 0x80187A24u;
    // 80187A24: bc    4, 1, 0x80187A30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187A30;
        }
    }

label_80187A28:
    ctx->pc = 0x80187A28u;
    ctx->downcount -= 2;
    // 80187A28: subf   r5, r6, r7
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80187A2C:
    ctx->pc = 0x80187A2Cu;
    // 80187A2C: b       0x80187A34
    {
            goto label_80187A34;
    }

label_80187A30:
    ctx->pc = 0x80187A30u;
    ctx->downcount -= 1;
    // 80187A30: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80187A34:
    ctx->pc = 0x80187A34u;
    ctx->downcount -= 3;
    // 80187A34: add   r6, r10, r4
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80187A38:
    ctx->pc = 0x80187A38u;
    // 80187A38: subf.   r4, r3, r6
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187A3C:
    ctx->pc = 0x80187A3Cu;
    // 80187A3C: bc    4, 0, 0x80187A48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187A48;
        }
    }

label_80187A40:
    ctx->pc = 0x80187A40u;
    ctx->downcount -= 2;
    // 80187A40: subf   r3, r3, r6
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80187A44:
    ctx->pc = 0x80187A44u;
    // 80187A44: b       0x80187A4C
    {
            goto label_80187A4C;
    }

label_80187A48:
    ctx->pc = 0x80187A48u;
    ctx->downcount -= 1;
    // 80187A48: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80187A4C:
    ctx->pc = 0x80187A4Cu;
    ctx->downcount -= 135;
    // 80187A4C: divw   r3, r3, r0
    {
        s32 dividend = (s32)ctx->gpr[3];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[3] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80187A50:
    ctx->pc = 0x80187A50u;
    // 80187A50: lhz     r4, 268(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(268);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80187A54:
    ctx->pc = 0x80187A54u;
    // 80187A54: divw   r5, r5, r0
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80187A58:
    ctx->pc = 0x80187A58u;
    // 80187A58: add   r0, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80187A5C:
    ctx->pc = 0x80187A5Cu;
    // 80187A5C: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80187A60:
    ctx->pc = 0x80187A60u;
    // 80187A60: sth     r0, 256(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(256);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187A64:
    ctx->pc = 0x80187A64u;
    // 80187A64: lis     r5, 4096
    ctx->gpr[5] = ((u32)(s32)(4096) << 16);

label_80187A68:
    ctx->pc = 0x80187A68u;
    // 80187A68: lis     r4, 8192
    ctx->gpr[4] = ((u32)(s32)(8192) << 16);

label_80187A6C:
    ctx->pc = 0x80187A6Cu;
    // 80187A6C: lhz     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_80187A70:
    ctx->pc = 0x80187A70u;
    // 80187A70: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_80187A74:
    ctx->pc = 0x80187A74u;
    // 80187A74: lhz     r6, 26(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(26);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80187A78:
    ctx->pc = 0x80187A78u;
    // 80187A78: lis     r3, 2048
    ctx->gpr[3] = ((u32)(s32)(2048) << 16);

label_80187A7C:
    ctx->pc = 0x80187A7Cu;
    // 80187A7C: sth     r6, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80187A80:
    ctx->pc = 0x80187A80u;
    // 80187A80: lwz     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80187A84:
    ctx->pc = 0x80187A84u;
    // 80187A84: lwz     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80187A88:
    ctx->pc = 0x80187A88u;
    // 80187A88: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80187A8C:
    ctx->pc = 0x80187A8Cu;
    // 80187A8C: stw     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80187A90:
    ctx->pc = 0x80187A90u;
    // 80187A90: stw     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80187A94:
    ctx->pc = 0x80187A94u;
    // 80187A94: lbz     r5, 29(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(29);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187A98:
    ctx->pc = 0x80187A98u;
    // 80187A98: lbz     r6, 30(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(30);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80187A9C:
    ctx->pc = 0x80187A9Cu;
    // 80187A9C: rlwimi r6, r5, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[5], 8u);
        ctx->gpr[6] = (ctx->gpr[6] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_80187AA0:
    ctx->pc = 0x80187AA0u;
    // 80187AA0: sth     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80187AA4:
    ctx->pc = 0x80187AA4u;
    // 80187AA4: lwz     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80187AA8:
    ctx->pc = 0x80187AA8u;
    // 80187AA8: lwz     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80187AAC:
    ctx->pc = 0x80187AACu;
    // 80187AAC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80187AB0:
    ctx->pc = 0x80187AB0u;
    // 80187AB0: stw     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80187AB4:
    ctx->pc = 0x80187AB4u;
    // 80187AB4: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80187AB8:
    ctx->pc = 0x80187AB8u;
    // 80187AB8: lbz     r4, 31(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(31);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80187ABC:
    ctx->pc = 0x80187ABCu;
    // 80187ABC: lbz     r5, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187AC0:
    ctx->pc = 0x80187AC0u;
    // 80187AC0: add   r8, r4, r10
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80187AC4:
    ctx->pc = 0x80187AC4u;
    // 80187AC4: lhz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80187AC8:
    ctx->pc = 0x80187AC8u;
    // 80187AC8: addi    r8, r8, -40
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-40);

label_80187ACC:
    ctx->pc = 0x80187ACCu;
    // 80187ACC: lhz     r6, 32(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(32);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80187AD0:
    ctx->pc = 0x80187AD0u;
    // 80187AD0: rlwinm r4, r8, 7, 16, 24
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 7u) & 0x0000FF80u;
    }

label_80187AD4:
    ctx->pc = 0x80187AD4u;
    // 80187AD4: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80187AD8:
    ctx->pc = 0x80187AD8u;
    // 80187AD8: add   r5, r6, r10
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80187ADC:
    ctx->pc = 0x80187ADCu;
    // 80187ADC: sth     r4, 10(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80187AE0:
    ctx->pc = 0x80187AE0u;
    // 80187AE0: subfic  r6, r7, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80187AE4:
    ctx->pc = 0x80187AE4u;
    // 80187AE4: addi    r5, r5, 40
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(40);

label_80187AE8:
    ctx->pc = 0x80187AE8u;
    // 80187AE8: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80187AEC:
    ctx->pc = 0x80187AECu;
    // 80187AEC: subf   r7, r6, r5
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80187AF0:
    ctx->pc = 0x80187AF0u;
    // 80187AF0: or   r5, r4, r0
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80187AF4:
    ctx->pc = 0x80187AF4u;
    // 80187AF4: lwz     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80187AF8:
    ctx->pc = 0x80187AF8u;
    // 80187AF8: rlwinm r4, r8, 23, 9, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 23u) & 0x007FFFFFu;
    }

label_80187AFC:
    ctx->pc = 0x80187AFCu;
    // 80187AFC: stw     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80187B00:
    ctx->pc = 0x80187B00u;
    // 80187B00: rlwinm r0, r7, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 1u) & 0xFFFFFFFEu;
    }

label_80187B04:
    ctx->pc = 0x80187B04u;
    // 80187B04: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80187B08:
    ctx->pc = 0x80187B08u;
    // 80187B08: stw     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80187B0C:
    ctx->pc = 0x80187B0Cu;
    // 80187B0C: sth     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187B10:
    ctx->pc = 0x80187B10u;
    // 80187B10: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80187B14:
    ctx->pc = 0x80187B14u;
    // 80187B14: lwz     r0, -26432(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26432);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187B18:
    ctx->pc = 0x80187B18u;
    // 80187B18: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80187B1C:
    ctx->pc = 0x80187B1Cu;
    // 80187B1C: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80187B20:
    ctx->pc = 0x80187B20u;
    // 80187B20: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187B24:
    ctx->pc = 0x80187B24u;
    // 80187B24: stw     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80187B28:
    ctx->pc = 0x80187B28u;
    // 80187B28: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80187B2C:
    ctx->pc = 0x80187B2Cu;
    // 80187B2C: bc    12, 2, 0x80187B48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187B48;
        }
    }

label_80187B30:
    ctx->pc = 0x80187B30u;
    ctx->downcount -= 6;
    // 80187B30: addi    r3, r30, 240
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(240);

label_80187B34:
    ctx->pc = 0x80187B34u;
    // 80187B34: addi    r4, r30, 292
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(292);

label_80187B38:
    ctx->pc = 0x80187B38u;
    // 80187B38: addi    r5, r30, 296
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(296);

label_80187B3C:
    ctx->pc = 0x80187B3Cu;
    // 80187B3C: addi    r6, r30, 316
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(316);

label_80187B40:
    ctx->pc = 0x80187B40u;
    // 80187B40: addi    r7, r30, 320
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(320);

label_80187B44:
    ctx->pc = 0x80187B44u;
    // 80187B44: bl      0x8018619C
    {
            ctx->lr = 0x80187B48u;
            ctx->pc = 0x8018619Cu;
            return;
    }

label_80187B48:
    ctx->pc = 0x80187B48u;
    ctx->downcount -= 11;
    // 80187B48: lwz     r0, 304(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187B4C:
    ctx->pc = 0x80187B4Cu;
    // 80187B4C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187B50:
    ctx->pc = 0x80187B50u;
    // 80187B50: lhz     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187B54:
    ctx->pc = 0x80187B54u;
    // 80187B54: lhz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80187B58:
    ctx->pc = 0x80187B58u;
    // 80187B58: lbz     r5, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187B5C:
    ctx->pc = 0x80187B5Cu;
    // 80187B5C: lhz     r6, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80187B60:
    ctx->pc = 0x80187B60u;
    // 80187B60: lhz     r7, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80187B64:
    ctx->pc = 0x80187B64u;
    // 80187B64: lhz     r8, 6(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_80187B68:
    ctx->pc = 0x80187B68u;
    // 80187B68: lhz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80187B6C:
    ctx->pc = 0x80187B6Cu;
    // 80187B6C: lhz     r10, 10(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(10);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_80187B70:
    ctx->pc = 0x80187B70u;
    // 80187B70: bl      0x8018653C
    {
            ctx->lr = 0x80187B74u;
            ctx->pc = 0x8018653Cu;
            return;
    }

label_80187B74:
    ctx->pc = 0x80187B74u;
    ctx->downcount -= 2;
    // 80187B74: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80187B78:
    ctx->pc = 0x80187B78u;
    // 80187B78: bl      0x80173F54
    {
            ctx->lr = 0x80187B7Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80187B7C:
    ctx->pc = 0x80187B7Cu;
    ctx->downcount -= 16;
    // 80187B7C: lmw     r27, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80187B80:
    ctx->pc = 0x80187B80u;
    // 80187B80: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187B84:
    ctx->pc = 0x80187B84u;
    // 80187B84: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_80187B88:
    ctx->pc = 0x80187B88u;
    // 80187B88: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187B8C:
    ctx->pc = 0x80187B8Cu;
    // 80187B8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187B90:
    ctx->pc = 0x80187B90u;
    ctx->downcount -= 8;
    // 80187B90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187B94:
    ctx->pc = 0x80187B94u;
    // 80187B94: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187B98:
    ctx->pc = 0x80187B98u;
    // 80187B98: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187B9C:
    ctx->pc = 0x80187B9Cu;
    // 80187B9C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80187BA0:
    ctx->pc = 0x80187BA0u;
    // 80187BA0: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80187BA4:
    ctx->pc = 0x80187BA4u;
    // 80187BA4: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80187BA8:
    ctx->pc = 0x80187BA8u;
    // 80187BA8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80187BAC:
    ctx->pc = 0x80187BACu;
    // 80187BAC: bl      0x80173F2C
    {
            ctx->lr = 0x80187BB0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80187BB0:
    ctx->pc = 0x80187BB0u;
    ctx->downcount -= 5;
    // 80187BB0: lha     r0, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187BB4:
    ctx->pc = 0x80187BB4u;
    // 80187BB4: sth     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187BB8:
    ctx->pc = 0x80187BB8u;
    // 80187BB8: lha     r0, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187BBC:
    ctx->pc = 0x80187BBCu;
    // 80187BBC: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187BC0:
    ctx->pc = 0x80187BC0u;
    // 80187BC0: bl      0x80173F54
    {
            ctx->lr = 0x80187BC4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80187BC4:
    ctx->pc = 0x80187BC4u;
    ctx->downcount -= 7;
    // 80187BC4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187BC8:
    ctx->pc = 0x80187BC8u;
    // 80187BC8: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80187BCC:
    ctx->pc = 0x80187BCCu;
    // 80187BCC: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80187BD0:
    ctx->pc = 0x80187BD0u;
    // 80187BD0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80187BD4:
    ctx->pc = 0x80187BD4u;
    // 80187BD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187BD8:
    ctx->pc = 0x80187BD8u;
    // 80187BD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187BDC:
    ctx->pc = 0x80187BDCu;
    ctx->downcount -= 4;
    // 80187BDC: lbz     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187BE0:
    ctx->pc = 0x80187BE0u;
    // 80187BE0: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80187BE4:
    ctx->pc = 0x80187BE4u;
    // 80187BE4: cmpwi   r0, -3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187BE8:
    ctx->pc = 0x80187BE8u;
    // 80187BE8: bc    12, 2, 0x80187D4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187D4C;
        }
    }

label_80187BEC:
    ctx->pc = 0x80187BECu;
    ctx->downcount -= 5;
    // 80187BEC: lbz     r5, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187BF0:
    ctx->pc = 0x80187BF0u;
    // 80187BF0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80187BF4:
    ctx->pc = 0x80187BF4u;
    // 80187BF4: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187BF8:
    ctx->pc = 0x80187BF8u;
    // 80187BF8: cmpwi   r0, -48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187BFC:
    ctx->pc = 0x80187BFCu;
    // 80187BFC: bc    4, 0, 0x80187C04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C04;
        }
    }

label_80187C00:
    ctx->pc = 0x80187C00u;
    ctx->downcount -= 1;
    // 80187C00: ori     r7, r7, 0x4000
    ctx->gpr[7] = ctx->gpr[7] | 0x4000u;

label_80187C04:
    ctx->pc = 0x80187C04u;
    ctx->downcount -= 3;
    // 80187C04: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C08:
    ctx->pc = 0x80187C08u;
    // 80187C08: cmpwi   r0, 48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C0C:
    ctx->pc = 0x80187C0Cu;
    // 80187C0C: bc    4, 1, 0x80187C14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C14;
        }
    }

label_80187C10:
    ctx->pc = 0x80187C10u;
    ctx->downcount -= 1;
    // 80187C10: ori     r7, r7, 0x8000
    ctx->gpr[7] = ctx->gpr[7] | 0x8000u;

label_80187C14:
    ctx->pc = 0x80187C14u;
    ctx->downcount -= 4;
    // 80187C14: lbz     r5, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187C18:
    ctx->pc = 0x80187C18u;
    // 80187C18: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C1C:
    ctx->pc = 0x80187C1Cu;
    // 80187C1C: cmpwi   r0, -48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C20:
    ctx->pc = 0x80187C20u;
    // 80187C20: bc    4, 0, 0x80187C28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C28;
        }
    }

label_80187C24:
    ctx->pc = 0x80187C24u;
    ctx->downcount -= 1;
    // 80187C24: ori     r7, r7, 0x2000
    ctx->gpr[7] = ctx->gpr[7] | 0x2000u;

label_80187C28:
    ctx->pc = 0x80187C28u;
    ctx->downcount -= 3;
    // 80187C28: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C2C:
    ctx->pc = 0x80187C2Cu;
    // 80187C2C: cmpwi   r0, 48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C30:
    ctx->pc = 0x80187C30u;
    // 80187C30: bc    4, 1, 0x80187C38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C38;
        }
    }

label_80187C34:
    ctx->pc = 0x80187C34u;
    ctx->downcount -= 1;
    // 80187C34: ori     r7, r7, 0x1000
    ctx->gpr[7] = ctx->gpr[7] | 0x1000u;

label_80187C38:
    ctx->pc = 0x80187C38u;
    ctx->downcount -= 4;
    // 80187C38: lbz     r5, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187C3C:
    ctx->pc = 0x80187C3Cu;
    // 80187C3C: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C40:
    ctx->pc = 0x80187C40u;
    // 80187C40: cmpwi   r0, -48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C44:
    ctx->pc = 0x80187C44u;
    // 80187C44: bc    4, 0, 0x80187C4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C4C;
        }
    }

label_80187C48:
    ctx->pc = 0x80187C48u;
    ctx->downcount -= 1;
    // 80187C48: ori     r7, r7, 0x0400
    ctx->gpr[7] = ctx->gpr[7] | 0x0400u;

label_80187C4C:
    ctx->pc = 0x80187C4Cu;
    ctx->downcount -= 3;
    // 80187C4C: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C50:
    ctx->pc = 0x80187C50u;
    // 80187C50: cmpwi   r0, 48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C54:
    ctx->pc = 0x80187C54u;
    // 80187C54: bc    4, 1, 0x80187C5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C5C;
        }
    }

label_80187C58:
    ctx->pc = 0x80187C58u;
    ctx->downcount -= 1;
    // 80187C58: ori     r7, r7, 0x0800
    ctx->gpr[7] = ctx->gpr[7] | 0x0800u;

label_80187C5C:
    ctx->pc = 0x80187C5Cu;
    ctx->downcount -= 4;
    // 80187C5C: lbz     r5, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187C60:
    ctx->pc = 0x80187C60u;
    // 80187C60: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C64:
    ctx->pc = 0x80187C64u;
    // 80187C64: cmpwi   r0, -48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C68:
    ctx->pc = 0x80187C68u;
    // 80187C68: bc    4, 0, 0x80187C70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C70;
        }
    }

label_80187C6C:
    ctx->pc = 0x80187C6Cu;
    ctx->downcount -= 1;
    // 80187C6C: ori     r7, r7, 0x0200
    ctx->gpr[7] = ctx->gpr[7] | 0x0200u;

label_80187C70:
    ctx->pc = 0x80187C70u;
    ctx->downcount -= 3;
    // 80187C70: extsb r0, r5
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187C74:
    ctx->pc = 0x80187C74u;
    // 80187C74: cmpwi   r0, 48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187C78:
    ctx->pc = 0x80187C78u;
    // 80187C78: bc    4, 1, 0x80187C80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187C80;
        }
    }

label_80187C7C:
    ctx->pc = 0x80187C7Cu;
    ctx->downcount -= 1;
    // 80187C7C: ori     r7, r7, 0x0100
    ctx->gpr[7] = ctx->gpr[7] | 0x0100u;

label_80187C80:
    ctx->pc = 0x80187C80u;
    ctx->downcount -= 51;
    // 80187C80: lhz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187C84:
    ctx->pc = 0x80187C84u;
    // 80187C84: rlwinm r5, r7, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x0000FFFFu;
    }

label_80187C88:
    ctx->pc = 0x80187C88u;
    // 80187C88: xor   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[5];
    }

label_80187C8C:
    ctx->pc = 0x80187C8Cu;
    // 80187C8C: and   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ctx->gpr[0];
    }

label_80187C90:
    ctx->pc = 0x80187C90u;
    // 80187C90: sth     r0, 18(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(18);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187C94:
    ctx->pc = 0x80187C94u;
    // 80187C94: lhz     r6, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80187C98:
    ctx->pc = 0x80187C98u;
    // 80187C98: xor   r0, r6, r5
    {
        ctx->gpr[0] = ctx->gpr[6] ^ ctx->gpr[5];
    }

label_80187C9C:
    ctx->pc = 0x80187C9Cu;
    // 80187C9C: and   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] & ctx->gpr[0];
    }

label_80187CA0:
    ctx->pc = 0x80187CA0u;
    // 80187CA0: sth     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187CA4:
    ctx->pc = 0x80187CA4u;
    // 80187CA4: sth     r7, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80187CA8:
    ctx->pc = 0x80187CA8u;
    // 80187CA8: lhz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80187CAC:
    ctx->pc = 0x80187CACu;
    // 80187CAC: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187CB0:
    ctx->pc = 0x80187CB0u;
    // 80187CB0: xor   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[5];
    }

label_80187CB4:
    ctx->pc = 0x80187CB4u;
    // 80187CB4: and   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ctx->gpr[0];
    }

label_80187CB8:
    ctx->pc = 0x80187CB8u;
    // 80187CB8: sth     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187CBC:
    ctx->pc = 0x80187CBCu;
    // 80187CBC: lhz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80187CC0:
    ctx->pc = 0x80187CC0u;
    // 80187CC0: lhz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80187CC4:
    ctx->pc = 0x80187CC4u;
    // 80187CC4: xor   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] ^ ctx->gpr[0];
    }

label_80187CC8:
    ctx->pc = 0x80187CC8u;
    // 80187CC8: and   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ctx->gpr[0];
    }

label_80187CCC:
    ctx->pc = 0x80187CCCu;
    // 80187CCC: sth     r0, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187CD0:
    ctx->pc = 0x80187CD0u;
    // 80187CD0: lbz     r5, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187CD4:
    ctx->pc = 0x80187CD4u;
    // 80187CD4: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187CD8:
    ctx->pc = 0x80187CD8u;
    // 80187CD8: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187CDC:
    ctx->pc = 0x80187CDCu;
    // 80187CDC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80187CE0:
    ctx->pc = 0x80187CE0u;
    // 80187CE0: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80187CE4:
    ctx->pc = 0x80187CE4u;
    // 80187CE4: sth     r0, 22(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187CE8:
    ctx->pc = 0x80187CE8u;
    // 80187CE8: lbz     r5, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187CEC:
    ctx->pc = 0x80187CECu;
    // 80187CEC: lbz     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187CF0:
    ctx->pc = 0x80187CF0u;
    // 80187CF0: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187CF4:
    ctx->pc = 0x80187CF4u;
    // 80187CF4: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80187CF8:
    ctx->pc = 0x80187CF8u;
    // 80187CF8: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80187CFC:
    ctx->pc = 0x80187CFCu;
    // 80187CFC: sth     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D00:
    ctx->pc = 0x80187D00u;
    // 80187D00: lbz     r5, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187D04:
    ctx->pc = 0x80187D04u;
    // 80187D04: lbz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187D08:
    ctx->pc = 0x80187D08u;
    // 80187D08: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187D0C:
    ctx->pc = 0x80187D0Cu;
    // 80187D0C: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80187D10:
    ctx->pc = 0x80187D10u;
    // 80187D10: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80187D14:
    ctx->pc = 0x80187D14u;
    // 80187D14: sth     r0, 26(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D18:
    ctx->pc = 0x80187D18u;
    // 80187D18: lbz     r5, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80187D1C:
    ctx->pc = 0x80187D1Cu;
    // 80187D1C: lbz     r0, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187D20:
    ctx->pc = 0x80187D20u;
    // 80187D20: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187D24:
    ctx->pc = 0x80187D24u;
    // 80187D24: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80187D28:
    ctx->pc = 0x80187D28u;
    // 80187D28: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80187D2C:
    ctx->pc = 0x80187D2Cu;
    // 80187D2C: sth     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D30:
    ctx->pc = 0x80187D30u;
    // 80187D30: lwz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80187D34:
    ctx->pc = 0x80187D34u;
    // 80187D34: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187D38:
    ctx->pc = 0x80187D38u;
    // 80187D38: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80187D3C:
    ctx->pc = 0x80187D3Cu;
    // 80187D3C: stw     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187D40:
    ctx->pc = 0x80187D40u;
    // 80187D40: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187D44:
    ctx->pc = 0x80187D44u;
    // 80187D44: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187D48:
    ctx->pc = 0x80187D48u;
    // 80187D48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187D4C:
    ctx->pc = 0x80187D4Cu;
    ctx->downcount -= 10;
    // 80187D4C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80187D50:
    ctx->pc = 0x80187D50u;
    // 80187D50: sth     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D54:
    ctx->pc = 0x80187D54u;
    // 80187D54: sth     r0, 18(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(18);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D58:
    ctx->pc = 0x80187D58u;
    // 80187D58: sth     r0, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D5C:
    ctx->pc = 0x80187D5Cu;
    // 80187D5C: sth     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D60:
    ctx->pc = 0x80187D60u;
    // 80187D60: sth     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D64:
    ctx->pc = 0x80187D64u;
    // 80187D64: sth     r0, 22(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D68:
    ctx->pc = 0x80187D68u;
    // 80187D68: sth     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D6C:
    ctx->pc = 0x80187D6Cu;
    // 80187D6C: sth     r0, 26(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187D70:
    ctx->pc = 0x80187D70u;
    // 80187D70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187D74:
    ctx->pc = 0x80187D74u;
    ctx->downcount -= 19;
    // 80187D74: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187D78:
    ctx->pc = 0x80187D78u;
    // 80187D78: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80187D7C:
    ctx->pc = 0x80187D7Cu;
    // 80187D7C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187D80:
    ctx->pc = 0x80187D80u;
    // 80187D80: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187D84:
    ctx->pc = 0x80187D84u;
    // 80187D84: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80187D88:
    ctx->pc = 0x80187D88u;
    // 80187D88: addi    r31, r3, 2688
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2688);

label_80187D8C:
    ctx->pc = 0x80187D8Cu;
    // 80187D8C: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80187D90:
    ctx->pc = 0x80187D90u;
    // 80187D90: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80187D94:
    ctx->pc = 0x80187D94u;
    // 80187D94: bl      0x80188F6C
    {
            ctx->lr = 0x80187D98u;
            goto label_80188F6C;
    }

label_80187D98:
    ctx->pc = 0x80187D98u;
    ctx->downcount -= 2;
    // 80187D98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80187D9C:
    ctx->pc = 0x80187D9Cu;
    // 80187D9C: bl      0x80188088
    {
            ctx->lr = 0x80187DA0u;
            goto label_80188088;
    }

label_80187DA0:
    ctx->pc = 0x80187DA0u;
    ctx->downcount -= 10;
    // 80187DA0: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80187DA4:
    ctx->pc = 0x80187DA4u;
    // 80187DA4: mulli   r0, r28, 30
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[28] * (s64)(s32)30);

label_80187DA8:
    ctx->pc = 0x80187DA8u;
    // 80187DA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80187DAC:
    ctx->pc = 0x80187DACu;
    // 80187DAC: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_80187DB0:
    ctx->pc = 0x80187DB0u;
    // 80187DB0: stw     r4, -26424(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26424);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80187DB4:
    ctx->pc = 0x80187DB4u;
    // 80187DB4: add   r29, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_80187DB8:
    ctx->pc = 0x80187DB8u;
    // 80187DB8: addi    r30, r3, -5088
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(-5088);

label_80187DBC:
    ctx->pc = 0x80187DBCu;
    // 80187DBC: addi    r29, r29, 48
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(48);

label_80187DC0:
    ctx->pc = 0x80187DC0u;
    ctx->downcount -= 3;
    // 80187DC0: lbz     r3, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80187DC4:
    // 80187DC4: extsb. r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187DC8:
    // 80187DC8: bc    12, 2, 0x80187DD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187DD8;
        }
    }

label_80187DCC:
    ctx->downcount -= 3;
    // 80187DCC: extsb r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_80187DD0:
    // 80187DD0: cmpwi   r0, -3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187DD4:
    // 80187DD4: bc    4, 2, 0x80187DE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187DE8;
        }
    }

label_80187DD8:
    ctx->pc = 0x80187DD8u;
    ctx->downcount -= 4;
    // 80187DD8: lwz     r3, -26424(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26424);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80187DDC:
    // 80187DDC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_80187DE0:
    ctx->pc = 0x80187DE0u;
    // 80187DE0: stw     r0, -26424(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26424);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187DE4:
    // 80187DE4: b       0x80187DF8
    {
            goto label_80187DF8;
    }

label_80187DE8:
    ctx->downcount -= 2;
    // 80187DE8: cmpwi   r0, -1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187DEC:
    // 80187DEC: bc    4, 2, 0x80187DF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187DF8;
        }
    }

label_80187DF0:
    ctx->pc = 0x80187DF0u;
    ctx->downcount -= 2;
    // 80187DF0: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187DF4:
    // 80187DF4: or   r27, r27, r0
    {
        ctx->gpr[27] = ctx->gpr[27] | ctx->gpr[0];
    }

label_80187DF8:
    ctx->downcount -= 3;
    // 80187DF8: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80187DFC:
    // 80187DFC: addi    r4, r29, 0
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(0);

label_80187E00:
    // 80187E00: bl      0x80187BDC
    {
            ctx->lr = 0x80187E04u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187BDCu;
                return;
            }
            goto label_80187BDC;
    }

label_80187E04:
    ctx->downcount -= 6;
    // 80187E04: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_80187E08:
    // 80187E08: cmpwi   r28, 4
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187E0C:
    // 80187E0C: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_80187E10:
    // 80187E10: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80187E14:
    // 80187E14: addi    r29, r29, 30
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(30);

label_80187E18:
    // 80187E18: bc    12, 0, 0x80187DC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187DC0u;
                return;
            }
            goto label_80187DC0;
        }
    }

label_80187E1C:
    ctx->pc = 0x80187E1Cu;
    ctx->downcount -= 2;
    // 80187E1C: cmplwi  r27, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187E20:
    ctx->pc = 0x80187E20u;
    // 80187E20: bc    12, 2, 0x80187E2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187E2C;
        }
    }

label_80187E24:
    ctx->pc = 0x80187E24u;
    ctx->downcount -= 2;
    // 80187E24: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80187E28:
    ctx->pc = 0x80187E28u;
    // 80187E28: bl      0x80188B58
    {
            ctx->lr = 0x80187E2Cu;
            goto label_80188B58;
    }

label_80187E2C:
    ctx->pc = 0x80187E2Cu;
    ctx->downcount -= 16;
    // 80187E2C: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80187E30:
    ctx->pc = 0x80187E30u;
    // 80187E30: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187E34:
    ctx->pc = 0x80187E34u;
    // 80187E34: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80187E38:
    ctx->pc = 0x80187E38u;
    // 80187E38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187E3C:
    ctx->pc = 0x80187E3Cu;
    // 80187E3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187E40:
    ctx->pc = 0x80187E40u;
    ctx->downcount -= 4;
    // 80187E40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80187E44:
    ctx->pc = 0x80187E44u;
    // 80187E44: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187E48:
    ctx->pc = 0x80187E48u;
    // 80187E48: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80187E4C:
    ctx->pc = 0x80187E4Cu;
    // 80187E4C: bl      0x80188D5C
    {
            ctx->lr = 0x80187E50u;
            goto label_80188D5C;
    }

label_80187E50:
    ctx->pc = 0x80187E50u;
    ctx->downcount -= 5;
    // 80187E50: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80187E54:
    ctx->pc = 0x80187E54u;
    // 80187E54: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80187E58:
    ctx->pc = 0x80187E58u;
    // 80187E58: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80187E5C:
    ctx->pc = 0x80187E5Cu;
    // 80187E5C: addi    r3, r3, 2736
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2736);

label_80187E60:
    loop_80187E60(ctx);
    if (ctx->pc == 0x80187F04u) goto label_80187F04;
    return;
label_80187E64:
    ctx->pc = 0x80187E64u;
    // 80187E64: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187E68:
    ctx->pc = 0x80187E68u;
    // 80187E68: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E6C:
    ctx->pc = 0x80187E6Cu;
    // 80187E6C: stb     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E70:
    ctx->pc = 0x80187E70u;
    // 80187E70: stb     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E74:
    ctx->pc = 0x80187E74u;
    // 80187E74: stb     r0, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E78:
    ctx->pc = 0x80187E78u;
    // 80187E78: stb     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E7C:
    ctx->pc = 0x80187E7Cu;
    // 80187E7C: stb     r0, 7(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E80:
    ctx->pc = 0x80187E80u;
    // 80187E80: stb     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E84:
    ctx->pc = 0x80187E84u;
    // 80187E84: stb     r0, 9(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E88:
    ctx->pc = 0x80187E88u;
    // 80187E88: stb     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187E8C:
    ctx->pc = 0x80187E8Cu;
    // 80187E8C: sth     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187E90:
    ctx->pc = 0x80187E90u;
    // 80187E90: sth     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187E94:
    ctx->pc = 0x80187E94u;
    // 80187E94: sth     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187E98:
    ctx->pc = 0x80187E98u;
    // 80187E98: sth     r0, 18(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(18);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187E9C:
    ctx->pc = 0x80187E9Cu;
    // 80187E9C: sth     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EA0:
    ctx->pc = 0x80187EA0u;
    // 80187EA0: sth     r0, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EA4:
    ctx->pc = 0x80187EA4u;
    // 80187EA4: sth     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EA8:
    ctx->pc = 0x80187EA8u;
    // 80187EA8: sth     r0, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EAC:
    ctx->pc = 0x80187EACu;
    // 80187EAC: sth     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EB0:
    ctx->pc = 0x80187EB0u;
    // 80187EB0: sth     r0, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EB4:
    ctx->pc = 0x80187EB4u;
    // 80187EB4: stb     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187EB8:
    ctx->pc = 0x80187EB8u;
    // 80187EB8: stb     r0, 33(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(33);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187EBC:
    ctx->pc = 0x80187EBCu;
    // 80187EBC: stb     r0, 34(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(34);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187EC0:
    ctx->pc = 0x80187EC0u;
    // 80187EC0: stb     r0, 35(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(35);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187EC4:
    ctx->pc = 0x80187EC4u;
    // 80187EC4: stb     r0, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187EC8:
    ctx->pc = 0x80187EC8u;
    // 80187EC8: stb     r0, 37(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(37);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187ECC:
    ctx->pc = 0x80187ECCu;
    // 80187ECC: stb     r0, 38(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(38);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187ED0:
    ctx->pc = 0x80187ED0u;
    // 80187ED0: stb     r0, 39(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(39);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187ED4:
    ctx->pc = 0x80187ED4u;
    // 80187ED4: stb     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187ED8:
    ctx->pc = 0x80187ED8u;
    // 80187ED8: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EDC:
    ctx->pc = 0x80187EDCu;
    // 80187EDC: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EE0:
    ctx->pc = 0x80187EE0u;
    // 80187EE0: sth     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EE4:
    ctx->pc = 0x80187EE4u;
    // 80187EE4: sth     r0, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EE8:
    ctx->pc = 0x80187EE8u;
    // 80187EE8: sth     r0, 50(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EEC:
    ctx->pc = 0x80187EECu;
    // 80187EEC: sth     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EF0:
    ctx->pc = 0x80187EF0u;
    // 80187EF0: sth     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EF4:
    ctx->pc = 0x80187EF4u;
    // 80187EF4: sth     r0, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EF8:
    ctx->pc = 0x80187EF8u;
    // 80187EF8: sth     r0, 58(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(58);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187EFC:
    // 80187EFC: addi    r3, r3, 60
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(60);

label_80187F00:
    // 80187F00: bc    16, 0, 0x80187E60
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187E60u;
                return;
            }
            goto label_80187E60;
        }
    }

label_80187F04:
    ctx->pc = 0x80187F04u;
    ctx->downcount -= 5;
    // 80187F04: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187F08:
    ctx->pc = 0x80187F08u;
    // 80187F08: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80187F0C:
    ctx->pc = 0x80187F0Cu;
    // 80187F0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80187F10:
    ctx->pc = 0x80187F10u;
    // 80187F10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187F14:
    ctx->pc = 0x80187F14u;
    ctx->downcount -= 6;
    // 80187F14: lbz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187F18:
    ctx->pc = 0x80187F18u;
    // 80187F18: lbz     r12, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

label_80187F1C:
    ctx->pc = 0x80187F1Cu;
    // 80187F1C: extsb. r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187F20:
    ctx->pc = 0x80187F20u;
    // 80187F20: extsb r12, r12
    {
        ctx->gpr[12] = (u32)(s32)(s8)ctx->gpr[12];
    }

label_80187F24:
    ctx->pc = 0x80187F24u;
    // 80187F24: or   r11, r0, r0
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80187F28:
    ctx->pc = 0x80187F28u;
    // 80187F28: bc    12, 0, 0x80187F34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187F34;
        }
    }

label_80187F2C:
    ctx->pc = 0x80187F2Cu;
    ctx->downcount -= 2;
    // 80187F2C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80187F30:
    ctx->pc = 0x80187F30u;
    // 80187F30: b       0x80187F3C
    {
            goto label_80187F3C;
    }

label_80187F34:
    ctx->pc = 0x80187F34u;
    ctx->downcount -= 2;
    // 80187F34: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80187F38:
    ctx->pc = 0x80187F38u;
    // 80187F38: neg  r11, r11
    {
        u32 a = ctx->gpr[11];
        ctx->gpr[11] = (~a) + 1u;
    }

label_80187F3C:
    ctx->pc = 0x80187F3Cu;
    ctx->downcount -= 2;
    // 80187F3C: cmpwi   r12, 0
    {
        s32 val_a = (s32)(ctx->gpr[12]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187F40:
    ctx->pc = 0x80187F40u;
    // 80187F40: bc    12, 0, 0x80187F4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187F4C;
        }
    }

label_80187F44:
    ctx->pc = 0x80187F44u;
    ctx->downcount -= 2;
    // 80187F44: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80187F48:
    ctx->pc = 0x80187F48u;
    // 80187F48: b       0x80187F54
    {
            goto label_80187F54;
    }

label_80187F4C:
    ctx->pc = 0x80187F4Cu;
    ctx->downcount -= 2;
    // 80187F4C: li      r8, -1
    ctx->gpr[8] = (u32)(s32)(-1);

label_80187F50:
    ctx->pc = 0x80187F50u;
    // 80187F50: neg  r12, r12
    {
        u32 a = ctx->gpr[12];
        ctx->gpr[12] = (~a) + 1u;
    }

label_80187F54:
    ctx->pc = 0x80187F54u;
    ctx->downcount -= 3;
    // 80187F54: extsb r7, r7
    {
        ctx->gpr[7] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80187F58:
    ctx->pc = 0x80187F58u;
    // 80187F58: cmpw    r11, r7
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187F5C:
    ctx->pc = 0x80187F5Cu;
    // 80187F5C: bc    12, 1, 0x80187F68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187F68;
        }
    }

label_80187F60:
    ctx->pc = 0x80187F60u;
    ctx->downcount -= 2;
    // 80187F60: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80187F64:
    ctx->pc = 0x80187F64u;
    // 80187F64: b       0x80187F6C
    {
            goto label_80187F6C;
    }

label_80187F68:
    ctx->pc = 0x80187F68u;
    ctx->downcount -= 1;
    // 80187F68: subf   r11, r7, r11
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[11] = res;
    }

label_80187F6C:
    ctx->pc = 0x80187F6Cu;
    ctx->downcount -= 2;
    // 80187F6C: cmpw    r12, r7
    {
        s32 val_a = (s32)(ctx->gpr[12]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187F70:
    ctx->pc = 0x80187F70u;
    // 80187F70: bc    12, 1, 0x80187F7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187F7C;
        }
    }

label_80187F74:
    ctx->pc = 0x80187F74u;
    ctx->downcount -= 2;
    // 80187F74: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_80187F78:
    ctx->pc = 0x80187F78u;
    // 80187F78: b       0x80187F80
    {
            goto label_80187F80;
    }

label_80187F7C:
    ctx->pc = 0x80187F7Cu;
    ctx->downcount -= 1;
    // 80187F7C: subf   r12, r7, r12
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[12];
        u32 res = a + b + 1u;
        ctx->gpr[12] = res;
    }

label_80187F80:
    ctx->pc = 0x80187F80u;
    ctx->downcount -= 2;
    // 80187F80: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187F84:
    ctx->pc = 0x80187F84u;
    // 80187F84: bc    4, 2, 0x80187FA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187FA0;
        }
    }

label_80187F88:
    ctx->pc = 0x80187F88u;
    ctx->downcount -= 2;
    // 80187F88: cmpwi   r12, 0
    {
        s32 val_a = (s32)(ctx->gpr[12]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187F8C:
    ctx->pc = 0x80187F8Cu;
    // 80187F8C: bc    4, 2, 0x80187FA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187FA0;
        }
    }

label_80187F90:
    ctx->pc = 0x80187F90u;
    ctx->downcount -= 4;
    // 80187F90: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80187F94:
    ctx->pc = 0x80187F94u;
    // 80187F94: stb     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187F98:
    ctx->pc = 0x80187F98u;
    // 80187F98: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187F9C:
    ctx->pc = 0x80187F9Cu;
    // 80187F9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80187FA0:
    ctx->pc = 0x80187FA0u;
    ctx->downcount -= 13;
    // 80187FA0: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80187FA4:
    ctx->pc = 0x80187FA4u;
    // 80187FA4: mullw   r9, r6, r12
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[12];
        ctx->gpr[9] = (u32)product;
    }

label_80187FA8:
    ctx->pc = 0x80187FA8u;
    // 80187FA8: mullw   r7, r6, r11
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[11];
        ctx->gpr[7] = (u32)product;
    }

label_80187FAC:
    ctx->pc = 0x80187FACu;
    // 80187FAC: cmpw    r9, r7
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187FB0:
    ctx->pc = 0x80187FB0u;
    // 80187FB0: bc    12, 1, 0x80187FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187FF4;
        }
    }

label_80187FB4:
    ctx->pc = 0x80187FB4u;
    ctx->downcount -= 15;
    // 80187FB4: extsb r9, r5
    {
        ctx->gpr[9] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187FB8:
    ctx->pc = 0x80187FB8u;
    // 80187FB8: subf   r5, r6, r9
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80187FBC:
    ctx->pc = 0x80187FBCu;
    // 80187FBC: mullw   r5, r12, r5
    {
        s64 product = (s64)(s32)ctx->gpr[12] * (s64)(s32)ctx->gpr[5];
        ctx->gpr[5] = (u32)product;
    }

label_80187FC0:
    ctx->pc = 0x80187FC0u;
    // 80187FC0: mullw   r9, r6, r9
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[9] = (u32)product;
    }

label_80187FC4:
    ctx->pc = 0x80187FC4u;
    // 80187FC4: add   r7, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80187FC8:
    ctx->pc = 0x80187FC8u;
    // 80187FC8: cmpw    r9, r7
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187FCC:
    ctx->pc = 0x80187FCCu;
    // 80187FCC: bc    4, 0, 0x80188030
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188030;
        }
    }

label_80187FD0:
    ctx->pc = 0x80187FD0u;
    ctx->downcount -= 95;
    // 80187FD0: mullw   r6, r11, r9
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[6] = (u32)product;
    }

label_80187FD4:
    ctx->pc = 0x80187FD4u;
    // 80187FD4: mullw   r5, r12, r9
    {
        s64 product = (s64)(s32)ctx->gpr[12] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[5] = (u32)product;
    }

label_80187FD8:
    ctx->pc = 0x80187FD8u;
    // 80187FD8: divw   r6, r6, r7
    {
        s32 dividend = (s32)ctx->gpr[6];
        s32 divisor = (s32)ctx->gpr[7];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[6] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80187FDC:
    ctx->pc = 0x80187FDCu;
    // 80187FDC: divw   r5, r5, r7
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[7];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80187FE0:
    ctx->pc = 0x80187FE0u;
    // 80187FE0: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80187FE4:
    ctx->pc = 0x80187FE4u;
    // 80187FE4: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187FE8:
    ctx->pc = 0x80187FE8u;
    // 80187FE8: addi    r11, r6, 0
    ctx->gpr[11] = ctx->gpr[6] + (u32)(s32)(0);

label_80187FEC:
    ctx->pc = 0x80187FECu;
    // 80187FEC: addi    r12, r5, 0
    ctx->gpr[12] = ctx->gpr[5] + (u32)(s32)(0);

label_80187FF0:
    ctx->pc = 0x80187FF0u;
    // 80187FF0: b       0x80188030
    {
            goto label_80188030;
    }

label_80187FF4:
    ctx->pc = 0x80187FF4u;
    ctx->downcount -= 15;
    // 80187FF4: extsb r7, r5
    {
        ctx->gpr[7] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80187FF8:
    ctx->pc = 0x80187FF8u;
    // 80187FF8: subf   r5, r6, r7
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80187FFC:
    ctx->pc = 0x80187FFCu;
    // 80187FFC: mullw   r5, r11, r5
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[5];
        ctx->gpr[5] = (u32)product;
    }

label_80188000:
    ctx->pc = 0x80188000u;
    // 80188000: mullw   r10, r6, r7
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[7];
        ctx->gpr[10] = (u32)product;
    }

label_80188004:
    ctx->pc = 0x80188004u;
    // 80188004: add   r7, r9, r5
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80188008:
    ctx->pc = 0x80188008u;
    // 80188008: cmpw    r10, r7
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018800C:
    ctx->pc = 0x8018800Cu;
    // 8018800C: bc    4, 0, 0x80188030
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188030;
        }
    }

label_80188010:
    ctx->pc = 0x80188010u;
    ctx->downcount -= 94;
    // 80188010: mullw   r6, r11, r10
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[10];
        ctx->gpr[6] = (u32)product;
    }

label_80188014:
    ctx->pc = 0x80188014u;
    // 80188014: mullw   r5, r12, r10
    {
        s64 product = (s64)(s32)ctx->gpr[12] * (s64)(s32)ctx->gpr[10];
        ctx->gpr[5] = (u32)product;
    }

label_80188018:
    ctx->pc = 0x80188018u;
    // 80188018: divw   r6, r6, r7
    {
        s32 dividend = (s32)ctx->gpr[6];
        s32 divisor = (s32)ctx->gpr[7];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[6] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8018801C:
    ctx->pc = 0x8018801Cu;
    // 8018801C: divw   r5, r5, r7
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[7];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80188020:
    ctx->pc = 0x80188020u;
    // 80188020: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80188024:
    ctx->pc = 0x80188024u;
    // 80188024: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80188028:
    ctx->pc = 0x80188028u;
    // 80188028: addi    r11, r6, 0
    ctx->gpr[11] = ctx->gpr[6] + (u32)(s32)(0);

label_8018802C:
    ctx->pc = 0x8018802Cu;
    // 8018802C: addi    r12, r5, 0
    ctx->gpr[12] = ctx->gpr[5] + (u32)(s32)(0);

label_80188030:
    ctx->pc = 0x80188030u;
    ctx->downcount -= 13;
    // 80188030: mullw   r5, r0, r11
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[11];
        ctx->gpr[5] = (u32)product;
    }

label_80188034:
    ctx->pc = 0x80188034u;
    // 80188034: mullw   r0, r8, r12
    {
        s64 product = (s64)(s32)ctx->gpr[8] * (s64)(s32)ctx->gpr[12];
        ctx->gpr[0] = (u32)product;
    }

label_80188038:
    ctx->pc = 0x80188038u;
    // 80188038: stb     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8018803C:
    ctx->pc = 0x8018803Cu;
    // 8018803C: stb     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188040:
    ctx->pc = 0x80188040u;
    // 80188040: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188044:
    ctx->pc = 0x80188044u;
    ctx->downcount -= 4;
    // 80188044: lbz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80188048:
    ctx->pc = 0x80188048u;
    // 80188048: lbz     r0, -28752(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28752);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018804C:
    ctx->pc = 0x8018804Cu;
    // 8018804C: cmplw   r5, r0
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188050:
    ctx->pc = 0x80188050u;
    // 80188050: bc    12, 1, 0x80188060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188060;
        }
    }

label_80188054:
    ctx->pc = 0x80188054u;
    ctx->downcount -= 3;
    // 80188054: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80188058:
    ctx->pc = 0x80188058u;
    // 80188058: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018805C:
    ctx->pc = 0x8018805Cu;
    // 8018805C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188060:
    ctx->pc = 0x80188060u;
    ctx->downcount -= 4;
    // 80188060: addi    r4, r13, -28752
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28752);

label_80188064:
    ctx->pc = 0x80188064u;
    // 80188064: lbz     r0, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80188068:
    ctx->pc = 0x80188068u;
    // 80188068: cmplw   r0, r5
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018806C:
    ctx->pc = 0x8018806Cu;
    // 8018806C: bc    4, 0, 0x80188074
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188074;
        }
    }

label_80188070:
    ctx->pc = 0x80188070u;
    ctx->downcount -= 1;
    // 80188070: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188074:
    ctx->pc = 0x80188074u;
    ctx->downcount -= 5;
    // 80188074: lbz     r4, -28752(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28752);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188078:
    ctx->pc = 0x80188078u;
    // 80188078: lbz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018807C:
    ctx->pc = 0x8018807Cu;
    // 8018807C: subf   r0, r4, r0
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80188080:
    ctx->pc = 0x80188080u;
    // 80188080: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188084:
    ctx->pc = 0x80188084u;
    // 80188084: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188088:
    ctx->pc = 0x80188088u;
    ctx->downcount -= 8;
    // 80188088: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018808C:
    ctx->pc = 0x8018808Cu;
    // 8018808C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188090:
    ctx->pc = 0x80188090u;
    // 80188090: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188094:
    ctx->pc = 0x80188094u;
    // 80188094: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188098:
    ctx->pc = 0x80188098u;
    // 80188098: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8018809C:
    ctx->pc = 0x8018809Cu;
    // 8018809C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801880A0:
    ctx->pc = 0x801880A0u;
    // 801880A0: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801880A4:
    ctx->pc = 0x801880A4u;
    // 801880A4: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801880A8:
    ctx->pc = 0x801880A8u;
    ctx->downcount -= 3;
    // 801880A8: lbz     r0, 10(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801880AC:
    // 801880AC: extsb. r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801880B0:
    // 801880B0: bc    4, 2, 0x80188164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188164;
        }
    }

label_801880B4:
    ctx->downcount -= 7;
    // 801880B4: addi    r29, r13, -28752
    ctx->gpr[29] = ctx->gpr[13] + (u32)(s32)(-28752);

label_801880B8:
    ctx->pc = 0x801880B8u;
    // 801880B8: lbz     r5, 3(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_801880BC:
    // 801880BC: addi    r3, r30, 2
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(2);

label_801880C0:
    ctx->pc = 0x801880C0u;
    // 801880C0: lbz     r6, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_801880C4:
    // 801880C4: addi    r4, r30, 3
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(3);

label_801880C8:
    ctx->pc = 0x801880C8u;
    // 801880C8: lbz     r7, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_801880CC:
    // 801880CC: bl      0x80187F14
    {
            ctx->lr = 0x801880D0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187F14u;
                return;
            }
            goto label_80187F14;
    }

label_801880D0:
    ctx->pc = 0x801880D0u;
    ctx->downcount -= 6;
    // 801880D0: lbz     r5, 6(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_801880D4:
    // 801880D4: addi    r3, r30, 4
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(4);

label_801880D8:
    ctx->pc = 0x801880D8u;
    // 801880D8: lbz     r6, 7(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(7);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_801880DC:
    // 801880DC: addi    r4, r30, 5
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(5);

label_801880E0:
    ctx->pc = 0x801880E0u;
    // 801880E0: lbz     r7, 5(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_801880E4:
    // 801880E4: bl      0x80187F14
    {
            ctx->lr = 0x801880E8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80187F14u;
                return;
            }
            goto label_80187F14;
    }

label_801880E8:
    ctx->pc = 0x801880E8u;
    ctx->downcount -= 4;
    // 801880E8: lbz     r3, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_801880EC:
    ctx->pc = 0x801880ECu;
    // 801880EC: lbz     r0, -28752(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28752);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801880F0:
    // 801880F0: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801880F4:
    // 801880F4: bc    12, 1, 0x80188104
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188104;
        }
    }

label_801880F8:
    ctx->downcount -= 3;
    // 801880F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801880FC:
    ctx->pc = 0x801880FCu;
    // 801880FC: stb     r0, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188100:
    // 80188100: b       0x80188124
    {
            goto label_80188124;
    }

label_80188104:
    ctx->pc = 0x80188104u;
    ctx->downcount -= 3;
    // 80188104: lbz     r0, 1(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80188108:
    // 80188108: cmplw   r0, r3
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018810C:
    // 8018810C: bc    4, 0, 0x80188114
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188114;
        }
    }

label_80188110:
    ctx->pc = 0x80188110u;
    ctx->downcount -= 1;
    // 80188110: stb     r0, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188114:
    ctx->pc = 0x80188114u;
    ctx->downcount -= 4;
    // 80188114: lbz     r3, -28752(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28752);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80188118:
    ctx->pc = 0x80188118u;
    // 80188118: lbz     r0, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018811C:
    // 8018811C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80188120:
    ctx->pc = 0x80188120u;
    // 80188120: stb     r0, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188124:
    ctx->pc = 0x80188124u;
    ctx->downcount -= 4;
    // 80188124: lbz     r4, 7(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(7);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188128:
    ctx->pc = 0x80188128u;
    // 80188128: lbz     r0, -28752(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28752);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018812C:
    // 8018812C: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188130:
    // 80188130: bc    12, 1, 0x80188140
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188140;
        }
    }

label_80188134:
    ctx->downcount -= 3;
    // 80188134: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80188138:
    ctx->pc = 0x80188138u;
    // 80188138: stb     r0, 7(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018813C:
    // 8018813C: b       0x80188164
    {
            goto label_80188164;
    }

label_80188140:
    ctx->downcount -= 4;
    // 80188140: addi    r3, r13, -28752
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-28752);

label_80188144:
    ctx->pc = 0x80188144u;
    // 80188144: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80188148:
    // 80188148: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018814C:
    // 8018814C: bc    4, 0, 0x80188154
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188154;
        }
    }

label_80188150:
    ctx->pc = 0x80188150u;
    ctx->downcount -= 1;
    // 80188150: stb     r0, 7(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188154:
    ctx->pc = 0x80188154u;
    ctx->downcount -= 4;
    // 80188154: lbz     r3, -28752(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28752);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80188158:
    ctx->pc = 0x80188158u;
    // 80188158: lbz     r0, 7(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(7);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018815C:
    // 8018815C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80188160:
    ctx->pc = 0x80188160u;
    // 80188160: stb     r0, 7(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188164:
    ctx->downcount -= 4;
    // 80188164: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80188168:
    // 80188168: cmpwi   r31, 4
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018816C:
    // 8018816C: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_80188170:
    // 80188170: bc    12, 0, 0x801880A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801880A8u;
                return;
            }
            goto label_801880A8;
        }
    }

label_80188174:
    ctx->pc = 0x80188174u;
    ctx->downcount -= 8;
    // 80188174: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188178:
    ctx->pc = 0x80188178u;
    // 80188178: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018817C:
    ctx->pc = 0x8018817Cu;
    // 8018817C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188180:
    ctx->pc = 0x80188180u;
    // 80188180: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80188184:
    ctx->pc = 0x80188184u;
    // 80188184: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80188188:
    ctx->pc = 0x80188188u;
    // 80188188: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018818C:
    ctx->pc = 0x8018818Cu;
    // 8018818C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188190:
    ctx->pc = 0x80188190u;
    ctx->downcount -= 13;
    // 80188190: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188194:
    ctx->pc = 0x80188194u;
    // 80188194: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188198:
    ctx->pc = 0x80188198u;
    // 80188198: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_8018819C:
    ctx->pc = 0x8018819Cu;
    // 8018819C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801881A0:
    ctx->pc = 0x801881A0u;
    // 801881A0: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801881A4:
    ctx->pc = 0x801881A4u;
    // 801881A4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801881A8:
    ctx->pc = 0x801881A8u;
    // 801881A8: srw   r0, r0, r31
    {
        u32 sh = ctx->gpr[31] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_801881AC:
    ctx->pc = 0x801881ACu;
    // 801881AC: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801881B0:
    ctx->pc = 0x801881B0u;
    // 801881B0: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_801881B4:
    ctx->pc = 0x801881B4u;
    // 801881B4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801881B8:
    ctx->pc = 0x801881B8u;
    // 801881B8: stw     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801881BC:
    ctx->pc = 0x801881BCu;
    // 801881BC: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801881C0:
    ctx->pc = 0x801881C0u;
    // 801881C0: bl      0x801A423C
    {
            ctx->lr = 0x801881C4u;
            ctx->pc = 0x801A423Cu;
            return;
    }

label_801881C4:
    ctx->pc = 0x801881C4u;
    ctx->downcount -= 4;
    // 801881C4: lwz     r0, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801881C8:
    ctx->pc = 0x801881C8u;
    // 801881C8: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801881CC:
    ctx->pc = 0x801881CCu;
    // 801881CC: oris    r4, r0, 0x0040
    ctx->gpr[4] = ctx->gpr[0] | (0x0040u << 16);

label_801881D0:
    ctx->pc = 0x801881D0u;
    // 801881D0: bl      0x801A3FBC
    {
            ctx->lr = 0x801881D4u;
            ctx->pc = 0x801A3FBCu;
            return;
    }

label_801881D4:
    ctx->pc = 0x801881D4u;
    ctx->downcount -= 2;
    // 801881D4: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801881D8:
    ctx->pc = 0x801881D8u;
    // 801881D8: bl      0x801A4060
    {
            ctx->lr = 0x801881DCu;
            ctx->pc = 0x801A4060u;
            return;
    }

label_801881DC:
    ctx->pc = 0x801881DCu;
    ctx->downcount -= 6;
    // 801881DC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801881E0:
    ctx->pc = 0x801881E0u;
    // 801881E0: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801881E4:
    ctx->pc = 0x801881E4u;
    // 801881E4: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801881E8:
    ctx->pc = 0x801881E8u;
    // 801881E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801881EC:
    ctx->pc = 0x801881ECu;
    // 801881EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801881F0:
    ctx->pc = 0x801881F0u;
    ctx->downcount -= 8;
    // 801881F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801881F4:
    ctx->pc = 0x801881F4u;
    // 801881F4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801881F8:
    ctx->pc = 0x801881F8u;
    // 801881F8: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801881FC:
    ctx->pc = 0x801881FCu;
    // 801881FC: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188200:
    ctx->pc = 0x80188200u;
    // 80188200: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80188204:
    ctx->pc = 0x80188204u;
    // 80188204: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80188208:
    ctx->pc = 0x80188208u;
    // 80188208: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018820C:
    ctx->pc = 0x8018820Cu;
    // 8018820C: bl      0x80173F2C
    {
            ctx->lr = 0x80188210u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188210:
    ctx->pc = 0x80188210u;
    ctx->downcount -= 5;
    // 80188210: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80188214:
    ctx->pc = 0x80188214u;
    // 80188214: srw   r30, r0, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[30] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80188218:
    ctx->pc = 0x80188218u;
    // 80188218: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_8018821C:
    ctx->pc = 0x8018821Cu;
    // 8018821C: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_80188220:
    ctx->pc = 0x80188220u;
    // 80188220: bl      0x801A40FC
    {
            ctx->lr = 0x80188224u;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80188224:
    ctx->pc = 0x80188224u;
    ctx->downcount -= 16;
    // 80188224: lwz     r6, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80188228:
    ctx->pc = 0x80188228u;
    // 80188228: nor   r8, r30, r30
    {
        ctx->gpr[8] = ~(ctx->gpr[30] | ctx->gpr[30]);
    }

label_8018822C:
    ctx->pc = 0x8018822Cu;
    // 8018822C: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188230:
    ctx->pc = 0x80188230u;
    // 80188230: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80188234:
    ctx->pc = 0x80188234u;
    // 80188234: lwz     r4, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188238:
    ctx->pc = 0x80188238u;
    // 80188238: lwz     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018823C:
    ctx->pc = 0x8018823Cu;
    // 8018823C: and   r7, r6, r8
    {
        ctx->gpr[7] = ctx->gpr[6] & ctx->gpr[8];
    }

label_80188240:
    ctx->pc = 0x80188240u;
    // 80188240: and   r6, r5, r8
    {
        ctx->gpr[6] = ctx->gpr[5] & ctx->gpr[8];
    }

label_80188244:
    ctx->pc = 0x80188244u;
    // 80188244: stw     r7, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80188248:
    ctx->pc = 0x80188248u;
    // 80188248: and   r5, r4, r8
    {
        ctx->gpr[5] = ctx->gpr[4] & ctx->gpr[8];
    }

label_8018824C:
    ctx->pc = 0x8018824Cu;
    // 8018824C: and   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[8];
    }

label_80188250:
    ctx->pc = 0x80188250u;
    // 80188250: stw     r6, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80188254:
    ctx->pc = 0x80188254u;
    // 80188254: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188258:
    ctx->pc = 0x80188258u;
    // 80188258: stw     r5, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018825C:
    ctx->pc = 0x8018825Cu;
    // 8018825C: stw     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188260:
    ctx->pc = 0x80188260u;
    // 80188260: bl      0x80177DA4
    {
            ctx->lr = 0x80188264u;
            ctx->pc = 0x80177DA4u;
            return;
    }

label_80188264:
    ctx->pc = 0x80188264u;
    ctx->downcount -= 2;
    // 80188264: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80188268:
    ctx->pc = 0x80188268u;
    // 80188268: bl      0x80173F54
    {
            ctx->lr = 0x8018826Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018826C:
    ctx->pc = 0x8018826Cu;
    ctx->downcount -= 8;
    // 8018826C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188270:
    ctx->pc = 0x80188270u;
    // 80188270: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188274:
    ctx->pc = 0x80188274u;
    // 80188274: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188278:
    ctx->pc = 0x80188278u;
    // 80188278: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018827C:
    ctx->pc = 0x8018827Cu;
    // 8018827C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80188280:
    ctx->pc = 0x80188280u;
    // 80188280: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188284:
    ctx->pc = 0x80188284u;
    // 80188284: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188288:
    ctx->pc = 0x80188288u;
    ctx->downcount -= 9;
    // 80188288: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018828C:
    ctx->pc = 0x8018828Cu;
    // 8018828C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188290:
    ctx->pc = 0x80188290u;
    // 80188290: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188294:
    ctx->pc = 0x80188294u;
    // 80188294: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188298:
    ctx->pc = 0x80188298u;
    // 80188298: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8018829C:
    ctx->pc = 0x8018829Cu;
    // 8018829C: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801882A0:
    ctx->pc = 0x801882A0u;
    // 801882A0: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801882A4:
    ctx->pc = 0x801882A4u;
    // 801882A4: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801882A8:
    ctx->pc = 0x801882A8u;
    // 801882A8: bc    12, 2, 0x801882E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801882E8;
        }
    }

label_801882AC:
    ctx->pc = 0x801882ACu;
    ctx->downcount -= 13;
    // 801882AC: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_801882B0:
    ctx->pc = 0x801882B0u;
    // 801882B0: srw   r0, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_801882B4:
    ctx->pc = 0x801882B4u;
    // 801882B4: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_801882B8:
    ctx->pc = 0x801882B8u;
    // 801882B8: mulli   r4, r4, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_801882BC:
    ctx->pc = 0x801882BCu;
    // 801882BC: stw     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801882C0:
    ctx->pc = 0x801882C0u;
    // 801882C0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_801882C4:
    ctx->pc = 0x801882C4u;
    // 801882C4: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_801882C8:
    ctx->pc = 0x801882C8u;
    // 801882C8: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801882CC:
    ctx->pc = 0x801882CCu;
    // 801882CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801882D0:
    ctx->pc = 0x801882D0u;
    // 801882D0: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_801882D4:
    ctx->pc = 0x801882D4u;
    // 801882D4: bl      0x801698F0
    {
            ctx->lr = 0x801882D8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801882D8:
    ctx->pc = 0x801882D8u;
    ctx->downcount -= 4;
    // 801882D8: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801882DC:
    ctx->pc = 0x801882DCu;
    // 801882DC: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801882E0:
    ctx->pc = 0x801882E0u;
    // 801882E0: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_801882E4:
    ctx->pc = 0x801882E4u;
    // 801882E4: bl      0x801A49CC
    {
            ctx->lr = 0x801882E8u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_801882E8:
    ctx->pc = 0x801882E8u;
    ctx->downcount -= 5;
    // 801882E8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801882EC:
    ctx->pc = 0x801882ECu;
    // 801882EC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801882F0:
    ctx->pc = 0x801882F0u;
    // 801882F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801882F4:
    ctx->pc = 0x801882F4u;
    // 801882F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801882F8:
    ctx->pc = 0x801882F8u;
    ctx->downcount -= 16;
    // 801882F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801882FC:
    ctx->pc = 0x801882FCu;
    // 801882FC: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

label_80188300:
    ctx->pc = 0x80188300u;
    // 80188300: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188304:
    ctx->pc = 0x80188304u;
    // 80188304: mulli   r6, r3, 12
    ctx->gpr[6] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)12);

label_80188308:
    ctx->pc = 0x80188308u;
    // 80188308: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018830C:
    ctx->pc = 0x8018830Cu;
    // 8018830C: addi    r5, r5, 2872
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(2872);

label_80188310:
    ctx->pc = 0x80188310u;
    // 80188310: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188314:
    ctx->pc = 0x80188314u;
    // 80188314: add   r31, r5, r6
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80188318:
    ctx->pc = 0x80188318u;
    // 80188318: lwz     r0, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018831C:
    ctx->pc = 0x8018831Cu;
    // 8018831C: rlwinm r4, r0, 0, 21, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000700u;
    }

label_80188320:
    ctx->pc = 0x80188320u;
    // 80188320: cmpwi   r4, 1024
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1024);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188324:
    ctx->pc = 0x80188324u;
    // 80188324: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80188328:
    ctx->pc = 0x80188328u;
    // 80188328: srw   r0, r0, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_8018832C:
    ctx->pc = 0x8018832Cu;
    // 8018832C: bc    12, 2, 0x80188420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188420;
        }
    }

label_80188330:
    ctx->pc = 0x80188330u;
    ctx->downcount -= 1;
    // 80188330: bc    4, 0, 0x80188364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188364;
        }
    }

label_80188334:
    ctx->pc = 0x80188334u;
    ctx->downcount -= 2;
    // 80188334: cmpwi   r4, 512
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(512);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188338:
    ctx->pc = 0x80188338u;
    // 80188338: bc    12, 2, 0x801883F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801883F0;
        }
    }

label_8018833C:
    ctx->pc = 0x8018833Cu;
    ctx->downcount -= 1;
    // 8018833C: bc    4, 0, 0x80188358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188358;
        }
    }

label_80188340:
    ctx->pc = 0x80188340u;
    ctx->downcount -= 2;
    // 80188340: cmpwi   r4, 256
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188344:
    ctx->pc = 0x80188344u;
    // 80188344: bc    12, 2, 0x801883BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801883BC;
        }
    }

label_80188348:
    ctx->pc = 0x80188348u;
    ctx->downcount -= 1;
    // 80188348: bc    4, 0, 0x80188420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188420;
        }
    }

label_8018834C:
    ctx->pc = 0x8018834Cu;
    ctx->downcount -= 2;
    // 8018834C: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188350:
    ctx->pc = 0x80188350u;
    // 80188350: bc    12, 2, 0x80188388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188388;
        }
    }

label_80188354:
    ctx->pc = 0x80188354u;
    ctx->downcount -= 1;
    // 80188354: b       0x80188420
    {
            goto label_80188420;
    }

label_80188358:
    ctx->pc = 0x80188358u;
    ctx->downcount -= 2;
    // 80188358: cmpwi   r4, 768
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(768);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018835C:
    ctx->pc = 0x8018835Cu;
    // 8018835C: bc    12, 2, 0x80188420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188420;
        }
    }

label_80188360:
    ctx->pc = 0x80188360u;
    ctx->downcount -= 1;
    // 80188360: b       0x80188420
    {
            goto label_80188420;
    }

label_80188364:
    ctx->pc = 0x80188364u;
    ctx->downcount -= 2;
    // 80188364: cmpwi   r4, 1536
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1536);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188368:
    ctx->pc = 0x80188368u;
    // 80188368: bc    12, 2, 0x80188388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188388;
        }
    }

label_8018836C:
    ctx->pc = 0x8018836Cu;
    ctx->downcount -= 1;
    // 8018836C: bc    4, 0, 0x8018837C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018837C;
        }
    }

label_80188370:
    ctx->pc = 0x80188370u;
    ctx->downcount -= 2;
    // 80188370: cmpwi   r4, 1280
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1280);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188374:
    ctx->pc = 0x80188374u;
    // 80188374: bc    12, 2, 0x80188388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188388;
        }
    }

label_80188378:
    ctx->pc = 0x80188378u;
    ctx->downcount -= 1;
    // 80188378: b       0x80188420
    {
            goto label_80188420;
    }

label_8018837C:
    ctx->pc = 0x8018837Cu;
    ctx->downcount -= 2;
    // 8018837C: cmpwi   r4, 1792
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1792);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188380:
    ctx->pc = 0x80188380u;
    // 80188380: bc    12, 2, 0x80188388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188388;
        }
    }

label_80188384:
    ctx->pc = 0x80188384u;
    ctx->downcount -= 1;
    // 80188384: b       0x80188420
    {
            goto label_80188420;
    }

label_80188388:
    ctx->pc = 0x80188388u;
    ctx->downcount -= 13;
    // 80188388: lbz     r4, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8018838C:
    ctx->pc = 0x8018838Cu;
    // 8018838C: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_80188390:
    ctx->pc = 0x80188390u;
    // 80188390: stb     r4, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188394:
    ctx->pc = 0x80188394u;
    // 80188394: lbz     r4, 7(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(7);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188398:
    ctx->pc = 0x80188398u;
    // 80188398: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_8018839C:
    ctx->pc = 0x8018839Cu;
    // 8018839C: stb     r4, 7(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883A0:
    ctx->pc = 0x801883A0u;
    // 801883A0: lbz     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883A4:
    ctx->pc = 0x801883A4u;
    // 801883A4: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883A8:
    ctx->pc = 0x801883A8u;
    // 801883A8: stb     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883AC:
    ctx->pc = 0x801883ACu;
    // 801883AC: lbz     r4, 9(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(9);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883B0:
    ctx->pc = 0x801883B0u;
    // 801883B0: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883B4:
    ctx->pc = 0x801883B4u;
    // 801883B4: stb     r4, 9(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883B8:
    ctx->pc = 0x801883B8u;
    // 801883B8: b       0x80188420
    {
            goto label_80188420;
    }

label_801883BC:
    ctx->pc = 0x801883BCu;
    ctx->downcount -= 13;
    // 801883BC: lbz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883C0:
    ctx->pc = 0x801883C0u;
    // 801883C0: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883C4:
    ctx->pc = 0x801883C4u;
    // 801883C4: stb     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883C8:
    ctx->pc = 0x801883C8u;
    // 801883C8: lbz     r4, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883CC:
    ctx->pc = 0x801883CCu;
    // 801883CC: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883D0:
    ctx->pc = 0x801883D0u;
    // 801883D0: stb     r4, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883D4:
    ctx->pc = 0x801883D4u;
    // 801883D4: lbz     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883D8:
    ctx->pc = 0x801883D8u;
    // 801883D8: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883DC:
    ctx->pc = 0x801883DCu;
    // 801883DC: stb     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883E0:
    ctx->pc = 0x801883E0u;
    // 801883E0: lbz     r4, 9(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(9);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883E4:
    ctx->pc = 0x801883E4u;
    // 801883E4: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883E8:
    ctx->pc = 0x801883E8u;
    // 801883E8: stb     r4, 9(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883EC:
    ctx->pc = 0x801883ECu;
    // 801883EC: b       0x80188420
    {
            goto label_80188420;
    }

label_801883F0:
    ctx->pc = 0x801883F0u;
    ctx->downcount -= 12;
    // 801883F0: lbz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801883F4:
    ctx->pc = 0x801883F4u;
    // 801883F4: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_801883F8:
    ctx->pc = 0x801883F8u;
    // 801883F8: stb     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801883FC:
    ctx->pc = 0x801883FCu;
    // 801883FC: lbz     r4, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188400:
    ctx->pc = 0x80188400u;
    // 80188400: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_80188404:
    ctx->pc = 0x80188404u;
    // 80188404: stb     r4, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188408:
    ctx->pc = 0x80188408u;
    // 80188408: lbz     r4, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8018840C:
    ctx->pc = 0x8018840Cu;
    // 8018840C: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_80188410:
    ctx->pc = 0x80188410u;
    // 80188410: stb     r4, 6(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188414:
    ctx->pc = 0x80188414u;
    // 80188414: lbz     r4, 7(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(7);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188418:
    ctx->pc = 0x80188418u;
    // 80188418: rlwinm r4, r4, 0, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFF0u;
    }

label_8018841C:
    ctx->pc = 0x8018841Cu;
    // 8018841C: stb     r4, 7(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188420:
    ctx->pc = 0x80188420u;
    ctx->downcount -= 15;
    // 80188420: lbz     r4, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188424:
    ctx->pc = 0x80188424u;
    // 80188424: addi    r4, r4, -128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-128);

label_80188428:
    ctx->pc = 0x80188428u;
    // 80188428: stb     r4, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8018842C:
    ctx->pc = 0x8018842Cu;
    // 8018842C: lbz     r4, 3(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188430:
    ctx->pc = 0x80188430u;
    // 80188430: addi    r4, r4, -128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-128);

label_80188434:
    ctx->pc = 0x80188434u;
    // 80188434: stb     r4, 3(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188438:
    ctx->pc = 0x80188438u;
    // 80188438: lbz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8018843C:
    ctx->pc = 0x8018843Cu;
    // 8018843C: addi    r4, r4, -128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-128);

label_80188440:
    ctx->pc = 0x80188440u;
    // 80188440: stb     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188444:
    ctx->pc = 0x80188444u;
    // 80188444: lbz     r4, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80188448:
    ctx->pc = 0x80188448u;
    // 80188448: addi    r4, r4, -128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-128);

label_8018844C:
    ctx->pc = 0x8018844Cu;
    // 8018844C: stb     r4, 5(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80188450:
    ctx->pc = 0x80188450u;
    // 80188450: lwz     r4, -28740(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28740);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188454:
    ctx->pc = 0x80188454u;
    // 80188454: and.   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188458:
    ctx->pc = 0x80188458u;
    // 80188458: bc    12, 2, 0x80188488
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188488;
        }
    }

label_8018845C:
    ctx->pc = 0x8018845Cu;
    ctx->downcount -= 4;
    // 8018845C: lbz     r0, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80188460:
    ctx->pc = 0x80188460u;
    // 80188460: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80188464:
    ctx->pc = 0x80188464u;
    // 80188464: cmpwi   r0, 64
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(64);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188468:
    ctx->pc = 0x80188468u;
    // 80188468: bc    4, 1, 0x80188488
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188488;
        }
    }

label_8018846C:
    ctx->pc = 0x8018846Cu;
    ctx->downcount -= 1;
    // 8018846C: bl      0x801A4808
    {
            ctx->lr = 0x80188470u;
            ctx->pc = 0x801A4808u;
            return;
    }

label_80188470:
    ctx->pc = 0x80188470u;
    ctx->downcount -= 4;
    // 80188470: rlwinm r3, r3, 0, 0, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF0000u;
    }

label_80188474:
    ctx->pc = 0x80188474u;
    // 80188474: addis   r0, r3, -2304
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-2304) << 16);

label_80188478:
    ctx->pc = 0x80188478u;
    // 80188478: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018847C:
    ctx->pc = 0x8018847Cu;
    // 8018847C: bc    4, 2, 0x80188488
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188488;
        }
    }

label_80188480:
    ctx->pc = 0x80188480u;
    ctx->downcount -= 2;
    // 80188480: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80188484:
    ctx->pc = 0x80188484u;
    // 80188484: stb     r0, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80188488:
    ctx->pc = 0x80188488u;
    ctx->downcount -= 6;
    // 80188488: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018848C:
    ctx->pc = 0x8018848Cu;
    // 8018848C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188490:
    ctx->pc = 0x80188490u;
    // 80188490: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80188494:
    ctx->pc = 0x80188494u;
    // 80188494: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188498:
    ctx->pc = 0x80188498u;
    // 80188498: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018849C:
    ctx->pc = 0x8018849Cu;
    ctx->downcount -= 6;
    // 8018849C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801884A0:
    ctx->pc = 0x801884A0u;
    // 801884A0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801884A4:
    ctx->pc = 0x801884A4u;
    // 801884A4: rlwinm. r0, r4, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801884A8:
    ctx->pc = 0x801884A8u;
    // 801884A8: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801884AC:
    ctx->pc = 0x801884ACu;
    // 801884AC: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801884B0:
    ctx->pc = 0x801884B0u;
    // 801884B0: bc    4, 2, 0x801884F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801884F8;
        }
    }

label_801884B4:
    ctx->pc = 0x801884B4u;
    ctx->downcount -= 2;
    // 801884B4: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801884B8:
    ctx->pc = 0x801884B8u;
    // 801884B8: bl      0x801882F8
    {
            ctx->lr = 0x801884BCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801882F8u;
                return;
            }
            goto label_801882F8;
    }

label_801884BC:
    ctx->pc = 0x801884BCu;
    ctx->downcount -= 9;
    // 801884BC: lwz     r31, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801884C0:
    ctx->pc = 0x801884C0u;
    // 801884C0: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_801884C4:
    ctx->pc = 0x801884C4u;
    // 801884C4: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801884C8:
    ctx->pc = 0x801884C8u;
    // 801884C8: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_801884CC:
    ctx->pc = 0x801884CCu;
    // 801884CC: srw   r0, r0, r31
    {
        u32 sh = ctx->gpr[31] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_801884D0:
    ctx->pc = 0x801884D0u;
    // 801884D0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801884D4:
    ctx->pc = 0x801884D4u;
    // 801884D4: stw     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801884D8:
    ctx->pc = 0x801884D8u;
    // 801884D8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801884DC:
    ctx->pc = 0x801884DCu;
    // 801884DC: bl      0x801A423C
    {
            ctx->lr = 0x801884E0u;
            ctx->pc = 0x801A423Cu;
            return;
    }

label_801884E0:
    ctx->pc = 0x801884E0u;
    ctx->downcount -= 4;
    // 801884E0: lwz     r0, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801884E4:
    ctx->pc = 0x801884E4u;
    // 801884E4: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801884E8:
    ctx->pc = 0x801884E8u;
    // 801884E8: oris    r4, r0, 0x0040
    ctx->gpr[4] = ctx->gpr[0] | (0x0040u << 16);

label_801884EC:
    ctx->pc = 0x801884ECu;
    // 801884EC: bl      0x801A3FBC
    {
            ctx->lr = 0x801884F0u;
            ctx->pc = 0x801A3FBCu;
            return;
    }

label_801884F0:
    ctx->pc = 0x801884F0u;
    ctx->downcount -= 2;
    // 801884F0: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801884F4:
    ctx->pc = 0x801884F4u;
    // 801884F4: bl      0x801A4060
    {
            ctx->lr = 0x801884F8u;
            ctx->pc = 0x801A4060u;
            return;
    }

label_801884F8:
    ctx->pc = 0x801884F8u;
    ctx->downcount -= 6;
    // 801884F8: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801884FC:
    ctx->pc = 0x801884FCu;
    // 801884FC: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80188500:
    ctx->pc = 0x80188500u;
    // 80188500: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188504:
    ctx->pc = 0x80188504u;
    // 80188504: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188508:
    ctx->pc = 0x80188508u;
    // 80188508: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018850C:
    ctx->pc = 0x8018850Cu;
    // 8018850C: bc    12, 2, 0x8018854C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018854C;
        }
    }

label_80188510:
    ctx->pc = 0x80188510u;
    ctx->downcount -= 13;
    // 80188510: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80188514:
    ctx->pc = 0x80188514u;
    // 80188514: srw   r0, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80188518:
    ctx->pc = 0x80188518u;
    // 80188518: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_8018851C:
    ctx->pc = 0x8018851Cu;
    // 8018851C: mulli   r4, r4, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_80188520:
    ctx->pc = 0x80188520u;
    // 80188520: stw     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188524:
    ctx->pc = 0x80188524u;
    // 80188524: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80188528:
    ctx->pc = 0x80188528u;
    // 80188528: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_8018852C:
    ctx->pc = 0x8018852Cu;
    // 8018852C: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80188530:
    ctx->pc = 0x80188530u;
    // 80188530: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188534:
    ctx->pc = 0x80188534u;
    // 80188534: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_80188538:
    ctx->pc = 0x80188538u;
    // 80188538: bl      0x801698F0
    {
            ctx->lr = 0x8018853Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8018853C:
    ctx->pc = 0x8018853Cu;
    ctx->downcount -= 4;
    // 8018853C: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188540:
    ctx->pc = 0x80188540u;
    // 80188540: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188544:
    ctx->pc = 0x80188544u;
    // 80188544: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188548:
    ctx->pc = 0x80188548u;
    // 80188548: bl      0x801A49CC
    {
            ctx->lr = 0x8018854Cu;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_8018854C:
    ctx->pc = 0x8018854Cu;
    ctx->downcount -= 6;
    // 8018854C: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188550:
    ctx->pc = 0x80188550u;
    // 80188550: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188554:
    ctx->pc = 0x80188554u;
    // 80188554: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80188558:
    ctx->pc = 0x80188558u;
    // 80188558: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018855C:
    ctx->pc = 0x8018855Cu;
    // 8018855C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188560:
    ctx->pc = 0x80188560u;
    ctx->downcount -= 13;
    // 80188560: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188564:
    ctx->pc = 0x80188564u;
    // 80188564: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188568:
    ctx->pc = 0x80188568u;
    // 80188568: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_8018856C:
    ctx->pc = 0x8018856Cu;
    // 8018856C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188570:
    ctx->pc = 0x80188570u;
    // 80188570: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188574:
    ctx->pc = 0x80188574u;
    // 80188574: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80188578:
    ctx->pc = 0x80188578u;
    // 80188578: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018857C:
    ctx->pc = 0x8018857Cu;
    // 8018857C: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80188580:
    ctx->pc = 0x80188580u;
    // 80188580: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80188584:
    ctx->pc = 0x80188584u;
    // 80188584: srw   r30, r0, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[30] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80188588:
    ctx->pc = 0x80188588u;
    // 80188588: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018858C:
    ctx->pc = 0x8018858Cu;
    // 8018858C: and.   r0, r3, r30
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188590:
    ctx->pc = 0x80188590u;
    // 80188590: bc    12, 2, 0x80188604
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188604;
        }
    }

label_80188594:
    ctx->pc = 0x80188594u;
    ctx->downcount -= 2;
    // 80188594: rlwinm. r0, r31, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x0000000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188598:
    ctx->pc = 0x80188598u;
    // 80188598: bc    4, 2, 0x801885A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801885A4;
        }
    }

label_8018859C:
    ctx->pc = 0x8018859Cu;
    ctx->downcount -= 2;
    // 8018859C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801885A0:
    ctx->pc = 0x801885A0u;
    // 801885A0: bl      0x801882F8
    {
            ctx->lr = 0x801885A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801882F8u;
                return;
            }
            goto label_801882F8;
    }

label_801885A4:
    ctx->pc = 0x801885A4u;
    ctx->downcount -= 2;
    // 801885A4: rlwinm. r0, r31, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801885A8:
    ctx->pc = 0x801885A8u;
    // 801885A8: bc    12, 2, 0x80188604
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188604;
        }
    }

label_801885AC:
    ctx->pc = 0x801885ACu;
    ctx->downcount -= 1;
    // 801885AC: bl      0x80173F2C
    {
            ctx->lr = 0x801885B0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801885B0:
    ctx->pc = 0x801885B0u;
    ctx->downcount -= 3;
    // 801885B0: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_801885B4:
    ctx->pc = 0x801885B4u;
    // 801885B4: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_801885B8:
    ctx->pc = 0x801885B8u;
    // 801885B8: bl      0x801A40FC
    {
            ctx->lr = 0x801885BCu;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_801885BC:
    ctx->pc = 0x801885BCu;
    ctx->downcount -= 16;
    // 801885BC: lwz     r6, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801885C0:
    ctx->pc = 0x801885C0u;
    // 801885C0: nor   r8, r30, r30
    {
        ctx->gpr[8] = ~(ctx->gpr[30] | ctx->gpr[30]);
    }

label_801885C4:
    ctx->pc = 0x801885C4u;
    // 801885C4: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801885C8:
    ctx->pc = 0x801885C8u;
    // 801885C8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801885CC:
    ctx->pc = 0x801885CCu;
    // 801885CC: lwz     r4, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801885D0:
    ctx->pc = 0x801885D0u;
    // 801885D0: lwz     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801885D4:
    ctx->pc = 0x801885D4u;
    // 801885D4: and   r7, r6, r8
    {
        ctx->gpr[7] = ctx->gpr[6] & ctx->gpr[8];
    }

label_801885D8:
    ctx->pc = 0x801885D8u;
    // 801885D8: and   r6, r5, r8
    {
        ctx->gpr[6] = ctx->gpr[5] & ctx->gpr[8];
    }

label_801885DC:
    ctx->pc = 0x801885DCu;
    // 801885DC: stw     r7, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_801885E0:
    ctx->pc = 0x801885E0u;
    // 801885E0: and   r5, r4, r8
    {
        ctx->gpr[5] = ctx->gpr[4] & ctx->gpr[8];
    }

label_801885E4:
    ctx->pc = 0x801885E4u;
    // 801885E4: and   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[8];
    }

label_801885E8:
    ctx->pc = 0x801885E8u;
    // 801885E8: stw     r6, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801885EC:
    ctx->pc = 0x801885ECu;
    // 801885EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801885F0:
    ctx->pc = 0x801885F0u;
    // 801885F0: stw     r5, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801885F4:
    ctx->pc = 0x801885F4u;
    // 801885F4: stw     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801885F8:
    ctx->pc = 0x801885F8u;
    // 801885F8: bl      0x80177DA4
    {
            ctx->lr = 0x801885FCu;
            ctx->pc = 0x80177DA4u;
            return;
    }

label_801885FC:
    ctx->pc = 0x801885FCu;
    ctx->downcount -= 2;
    // 801885FC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80188600:
    ctx->pc = 0x80188600u;
    // 80188600: bl      0x80173F54
    {
            ctx->lr = 0x80188604u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80188604:
    ctx->pc = 0x80188604u;
    ctx->downcount -= 8;
    // 80188604: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188608:
    ctx->pc = 0x80188608u;
    // 80188608: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018860C:
    ctx->pc = 0x8018860Cu;
    // 8018860C: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188610:
    ctx->pc = 0x80188610u;
    // 80188610: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80188614:
    ctx->pc = 0x80188614u;
    // 80188614: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_80188618:
    ctx->pc = 0x80188618u;
    // 80188618: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018861C:
    ctx->pc = 0x8018861Cu;
    // 8018861C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188620:
    ctx->pc = 0x80188620u;
    ctx->downcount -= 7;
    // 80188620: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188624:
    ctx->pc = 0x80188624u;
    // 80188624: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188628:
    ctx->pc = 0x80188628u;
    // 80188628: rlwinm. r0, r4, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018862C:
    ctx->pc = 0x8018862Cu;
    // 8018862C: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188630:
    ctx->pc = 0x80188630u;
    // 80188630: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188634:
    ctx->pc = 0x80188634u;
    // 80188634: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80188638:
    ctx->pc = 0x80188638u;
    // 80188638: bc    4, 2, 0x8018868C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018868C;
        }
    }

label_8018863C:
    ctx->pc = 0x8018863Cu;
    ctx->downcount -= 9;
    // 8018863C: lwz     r30, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188640:
    ctx->pc = 0x80188640u;
    // 80188640: lis     r31, -32768
    ctx->gpr[31] = ((u32)(s32)(-32768) << 16);

label_80188644:
    ctx->pc = 0x80188644u;
    // 80188644: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188648:
    ctx->pc = 0x80188648u;
    // 80188648: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_8018864C:
    ctx->pc = 0x8018864Cu;
    // 8018864C: srw   r0, r31, r30
    {
        u32 sh = ctx->gpr[30] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[31] >> sh);
    }

label_80188650:
    ctx->pc = 0x80188650u;
    // 80188650: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80188654:
    ctx->pc = 0x80188654u;
    // 80188654: stw     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188658:
    ctx->pc = 0x80188658u;
    // 80188658: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018865C:
    ctx->pc = 0x8018865Cu;
    // 8018865C: bl      0x801A423C
    {
            ctx->lr = 0x80188660u;
            ctx->pc = 0x801A423Cu;
            return;
    }

label_80188660:
    ctx->pc = 0x80188660u;
    ctx->downcount -= 4;
    // 80188660: lwz     r0, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188664:
    ctx->pc = 0x80188664u;
    // 80188664: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_80188668:
    ctx->pc = 0x80188668u;
    // 80188668: oris    r4, r0, 0x0040
    ctx->gpr[4] = ctx->gpr[0] | (0x0040u << 16);

label_8018866C:
    ctx->pc = 0x8018866Cu;
    // 8018866C: bl      0x801A3FBC
    {
            ctx->lr = 0x80188670u;
            ctx->pc = 0x801A3FBCu;
            return;
    }

label_80188670:
    ctx->pc = 0x80188670u;
    ctx->downcount -= 2;
    // 80188670: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188674:
    ctx->pc = 0x80188674u;
    // 80188674: bl      0x801A4060
    {
            ctx->lr = 0x80188678u;
            ctx->pc = 0x801A4060u;
            return;
    }

label_80188678:
    ctx->pc = 0x80188678u;
    ctx->downcount -= 5;
    // 80188678: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018867C:
    ctx->pc = 0x8018867Cu;
    // 8018867C: lwz     r3, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188680:
    ctx->pc = 0x80188680u;
    // 80188680: srw   r0, r31, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[31] >> sh);
    }

label_80188684:
    ctx->pc = 0x80188684u;
    // 80188684: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80188688:
    ctx->pc = 0x80188688u;
    // 80188688: stw     r0, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018868C:
    ctx->pc = 0x8018868Cu;
    ctx->downcount -= 6;
    // 8018868C: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188690:
    ctx->pc = 0x80188690u;
    // 80188690: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80188694:
    ctx->pc = 0x80188694u;
    // 80188694: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188698:
    ctx->pc = 0x80188698u;
    // 80188698: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018869C:
    ctx->pc = 0x8018869Cu;
    // 8018869C: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801886A0:
    ctx->pc = 0x801886A0u;
    // 801886A0: bc    12, 2, 0x801886E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801886E0;
        }
    }

label_801886A4:
    ctx->pc = 0x801886A4u;
    ctx->downcount -= 13;
    // 801886A4: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_801886A8:
    ctx->pc = 0x801886A8u;
    // 801886A8: srw   r0, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_801886AC:
    ctx->pc = 0x801886ACu;
    // 801886AC: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_801886B0:
    ctx->pc = 0x801886B0u;
    // 801886B0: mulli   r4, r4, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_801886B4:
    ctx->pc = 0x801886B4u;
    // 801886B4: stw     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801886B8:
    ctx->pc = 0x801886B8u;
    // 801886B8: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_801886BC:
    ctx->pc = 0x801886BCu;
    // 801886BC: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_801886C0:
    ctx->pc = 0x801886C0u;
    // 801886C0: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801886C4:
    ctx->pc = 0x801886C4u;
    // 801886C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801886C8:
    ctx->pc = 0x801886C8u;
    // 801886C8: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_801886CC:
    ctx->pc = 0x801886CCu;
    // 801886CC: bl      0x801698F0
    {
            ctx->lr = 0x801886D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801886D0:
    ctx->pc = 0x801886D0u;
    ctx->downcount -= 4;
    // 801886D0: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801886D4:
    ctx->pc = 0x801886D4u;
    // 801886D4: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801886D8:
    ctx->pc = 0x801886D8u;
    // 801886D8: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_801886DC:
    ctx->pc = 0x801886DCu;
    // 801886DC: bl      0x801A49CC
    {
            ctx->lr = 0x801886E0u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_801886E0:
    ctx->pc = 0x801886E0u;
    ctx->downcount -= 7;
    // 801886E0: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801886E4:
    ctx->pc = 0x801886E4u;
    // 801886E4: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801886E8:
    ctx->pc = 0x801886E8u;
    // 801886E8: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801886EC:
    ctx->pc = 0x801886ECu;
    // 801886EC: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_801886F0:
    ctx->pc = 0x801886F0u;
    // 801886F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801886F4:
    ctx->pc = 0x801886F4u;
    // 801886F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801886F8:
    ctx->pc = 0x801886F8u;
    ctx->downcount -= 19;
    // 801886F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801886FC:
    ctx->pc = 0x801886FCu;
    // 801886FC: lis     r6, -32697
    ctx->gpr[6] = ((u32)(s32)(-32697) << 16);

label_80188700:
    ctx->pc = 0x80188700u;
    // 80188700: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188704:
    ctx->pc = 0x80188704u;
    // 80188704: rlwinm. r0, r4, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188708:
    ctx->pc = 0x80188708u;
    // 80188708: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018870C:
    ctx->pc = 0x8018870Cu;
    // 8018870C: stw     r31, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188710:
    ctx->pc = 0x80188710u;
    // 80188710: lis     r31, -32768
    ctx->gpr[31] = ((u32)(s32)(-32768) << 16);

label_80188714:
    ctx->pc = 0x80188714u;
    // 80188714: stw     r30, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80188718:
    ctx->pc = 0x80188718u;
    // 80188718: addi    r30, r6, 2856
    ctx->gpr[30] = ctx->gpr[6] + (u32)(s32)(2856);

label_8018871C:
    ctx->pc = 0x8018871Cu;
    // 8018871C: stw     r29, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80188720:
    ctx->pc = 0x80188720u;
    // 80188720: stw     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80188724:
    ctx->pc = 0x80188724u;
    // 80188724: lwz     r29, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80188728:
    ctx->pc = 0x80188728u;
    // 80188728: lwz     r5, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018872C:
    ctx->pc = 0x8018872Cu;
    // 8018872C: srw   r28, r31, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[28] = sh > 31 ? 0u : (ctx->gpr[31] >> sh);
    }

label_80188730:
    ctx->pc = 0x80188730u;
    // 80188730: andc   r3, r5, r28
    {
        ctx->gpr[3] = ctx->gpr[5] & ~ctx->gpr[28];
    }

label_80188734:
    ctx->pc = 0x80188734u;
    // 80188734: stw     r3, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80188738:
    ctx->pc = 0x80188738u;
    // 80188738: and   r5, r5, r28
    {
        ctx->gpr[5] = ctx->gpr[5] & ctx->gpr[28];
    }

label_8018873C:
    ctx->pc = 0x8018873Cu;
    // 8018873C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80188740:
    ctx->pc = 0x80188740u;
    // 80188740: bc    12, 2, 0x80188794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188794;
        }
    }

label_80188744:
    ctx->pc = 0x80188744u;
    ctx->downcount -= 6;
    // 80188744: lwz     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188748:
    ctx->pc = 0x80188748u;
    // 80188748: cntlzw r0, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8018874C:
    ctx->pc = 0x8018874Cu;
    // 8018874C: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188750:
    ctx->pc = 0x80188750u;
    // 80188750: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188754:
    ctx->pc = 0x80188754u;
    // 80188754: cmpwi   r3, 32
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188758:
    ctx->pc = 0x80188758u;
    // 80188758: bc    12, 2, 0x80188A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188A04;
        }
    }

label_8018875C:
    ctx->pc = 0x8018875Cu;
    ctx->downcount -= 11;
    // 8018875C: mulli   r0, r3, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)12);

label_80188760:
    ctx->pc = 0x80188760u;
    // 80188760: srw   r3, r31, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[31] >> sh);
    }

label_80188764:
    ctx->pc = 0x80188764u;
    // 80188764: andc   r4, r4, r3
    {
        ctx->gpr[4] = ctx->gpr[4] & ~ctx->gpr[3];
    }

label_80188768:
    ctx->pc = 0x80188768u;
    // 80188768: add   r3, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8018876C:
    ctx->pc = 0x8018876Cu;
    // 8018876C: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188770:
    ctx->pc = 0x80188770u;
    // 80188770: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188774:
    ctx->pc = 0x80188774u;
    // 80188774: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_80188778:
    ctx->pc = 0x80188778u;
    // 80188778: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_8018877C:
    ctx->pc = 0x8018877Cu;
    // 8018877C: bl      0x801698F0
    {
            ctx->lr = 0x80188780u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80188780:
    ctx->pc = 0x80188780u;
    ctx->downcount -= 4;
    // 80188780: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188784:
    ctx->pc = 0x80188784u;
    // 80188784: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188788:
    ctx->pc = 0x80188788u;
    // 80188788: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_8018878C:
    ctx->pc = 0x8018878Cu;
    // 8018878C: bl      0x801A49CC
    {
            ctx->lr = 0x80188790u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188790:
    ctx->pc = 0x80188790u;
    ctx->downcount -= 1;
    // 80188790: b       0x80188A04
    {
            goto label_80188A04;
    }

label_80188794:
    ctx->pc = 0x80188794u;
    ctx->downcount -= 7;
    // 80188794: rlwinm r6, r4, 0, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFF00u;
    }

label_80188798:
    ctx->pc = 0x80188798u;
    // 80188798: rlwinm r4, r4, 0, 3, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x18000000u;
    }

label_8018879C:
    ctx->pc = 0x8018879Cu;
    // 8018879C: addis   r0, r4, -2048
    ctx->gpr[0] = ctx->gpr[4] + ((u32)(s32)(-2048) << 16);

label_801887A0:
    ctx->pc = 0x801887A0u;
    // 801887A0: rlwinm r4, r29, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[29], 2u) & 0xFFFFFFFCu;
    }

label_801887A4:
    ctx->pc = 0x801887A4u;
    // 801887A4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801887A8:
    ctx->pc = 0x801887A8u;
    // 801887A8: stwx    r6, r30, r4
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[4];
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801887AC:
    ctx->pc = 0x801887ACu;
    // 801887AC: bc    4, 2, 0x801887B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801887B8;
        }
    }

label_801887B0:
    ctx->pc = 0x801887B0u;
    ctx->downcount -= 2;
    // 801887B0: rlwinm. r0, r6, 0, 7, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x01000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801887B4:
    ctx->pc = 0x801887B4u;
    // 801887B4: bc    4, 2, 0x8018880C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018880C;
        }
    }

label_801887B8:
    ctx->pc = 0x801887B8u;
    ctx->downcount -= 6;
    // 801887B8: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801887BC:
    ctx->pc = 0x801887BCu;
    // 801887BC: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_801887C0:
    ctx->pc = 0x801887C0u;
    // 801887C0: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801887C4:
    ctx->pc = 0x801887C4u;
    // 801887C4: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801887C8:
    ctx->pc = 0x801887C8u;
    // 801887C8: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801887CC:
    ctx->pc = 0x801887CCu;
    // 801887CC: bc    12, 2, 0x80188A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188A04;
        }
    }

label_801887D0:
    ctx->pc = 0x801887D0u;
    ctx->downcount -= 12;
    // 801887D0: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_801887D4:
    ctx->pc = 0x801887D4u;
    // 801887D4: mulli   r0, r4, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_801887D8:
    ctx->pc = 0x801887D8u;
    // 801887D8: srw   r3, r3, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_801887DC:
    ctx->pc = 0x801887DCu;
    // 801887DC: andc   r4, r5, r3
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[3];
    }

label_801887E0:
    ctx->pc = 0x801887E0u;
    // 801887E0: add   r3, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801887E4:
    ctx->pc = 0x801887E4u;
    // 801887E4: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801887E8:
    ctx->pc = 0x801887E8u;
    // 801887E8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801887EC:
    ctx->pc = 0x801887ECu;
    // 801887EC: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_801887F0:
    ctx->pc = 0x801887F0u;
    // 801887F0: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_801887F4:
    ctx->pc = 0x801887F4u;
    // 801887F4: bl      0x801698F0
    {
            ctx->lr = 0x801887F8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801887F8:
    ctx->pc = 0x801887F8u;
    ctx->downcount -= 4;
    // 801887F8: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801887FC:
    ctx->pc = 0x801887FCu;
    // 801887FC: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188800:
    ctx->pc = 0x80188800u;
    // 80188800: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188804:
    ctx->pc = 0x80188804u;
    // 80188804: bl      0x801A49CC
    {
            ctx->lr = 0x80188808u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188808:
    ctx->pc = 0x80188808u;
    ctx->downcount -= 1;
    // 80188808: b       0x80188A04
    {
            goto label_80188A04;
    }

label_8018880C:
    ctx->pc = 0x8018880Cu;
    ctx->downcount -= 3;
    // 8018880C: lwz     r0, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188810:
    ctx->pc = 0x80188810u;
    // 80188810: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188814:
    ctx->pc = 0x80188814u;
    // 80188814: bc    4, 0, 0x80188898
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188898;
        }
    }

label_80188818:
    ctx->pc = 0x80188818u;
    ctx->downcount -= 6;
    // 80188818: lwz     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018881C:
    ctx->pc = 0x8018881Cu;
    // 8018881C: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80188820:
    ctx->pc = 0x80188820u;
    // 80188820: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_80188824:
    ctx->pc = 0x80188824u;
    // 80188824: or   r0, r0, r28
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[28];
    }

label_80188828:
    ctx->pc = 0x80188828u;
    // 80188828: stw     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018882C:
    ctx->pc = 0x8018882Cu;
    // 8018882C: bl      0x801A423C
    {
            ctx->lr = 0x80188830u;
            ctx->pc = 0x801A423Cu;
            return;
    }

label_80188830:
    ctx->pc = 0x80188830u;
    ctx->downcount -= 4;
    // 80188830: lwz     r0, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188834:
    ctx->pc = 0x80188834u;
    // 80188834: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80188838:
    ctx->pc = 0x80188838u;
    // 80188838: oris    r4, r0, 0x0040
    ctx->gpr[4] = ctx->gpr[0] | (0x0040u << 16);

label_8018883C:
    ctx->pc = 0x8018883Cu;
    // 8018883C: bl      0x801A3FBC
    {
            ctx->lr = 0x80188840u;
            ctx->pc = 0x801A3FBCu;
            return;
    }

label_80188840:
    ctx->pc = 0x80188840u;
    ctx->downcount -= 2;
    // 80188840: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188844:
    ctx->pc = 0x80188844u;
    // 80188844: bl      0x801A4060
    {
            ctx->lr = 0x80188848u;
            ctx->pc = 0x801A4060u;
            return;
    }

label_80188848:
    ctx->pc = 0x80188848u;
    ctx->downcount -= 6;
    // 80188848: lwz     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018884C:
    ctx->pc = 0x8018884Cu;
    // 8018884C: cntlzw r0, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80188850:
    ctx->pc = 0x80188850u;
    // 80188850: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188854:
    ctx->pc = 0x80188854u;
    // 80188854: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188858:
    ctx->pc = 0x80188858u;
    // 80188858: cmpwi   r3, 32
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018885C:
    ctx->pc = 0x8018885Cu;
    // 8018885C: bc    12, 2, 0x80188A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188A04;
        }
    }

label_80188860:
    ctx->pc = 0x80188860u;
    ctx->downcount -= 11;
    // 80188860: mulli   r0, r3, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)12);

label_80188864:
    ctx->pc = 0x80188864u;
    // 80188864: srw   r3, r31, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[31] >> sh);
    }

label_80188868:
    ctx->pc = 0x80188868u;
    // 80188868: andc   r4, r4, r3
    {
        ctx->gpr[4] = ctx->gpr[4] & ~ctx->gpr[3];
    }

label_8018886C:
    ctx->pc = 0x8018886Cu;
    // 8018886C: add   r3, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80188870:
    ctx->pc = 0x80188870u;
    // 80188870: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188874:
    ctx->pc = 0x80188874u;
    // 80188874: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188878:
    ctx->pc = 0x80188878u;
    // 80188878: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_8018887C:
    ctx->pc = 0x8018887Cu;
    // 8018887C: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_80188880:
    ctx->pc = 0x80188880u;
    // 80188880: bl      0x801698F0
    {
            ctx->lr = 0x80188884u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80188884:
    ctx->pc = 0x80188884u;
    ctx->downcount -= 4;
    // 80188884: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188888:
    ctx->pc = 0x80188888u;
    // 80188888: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018888C:
    ctx->pc = 0x8018888Cu;
    // 8018888C: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188890:
    ctx->pc = 0x80188890u;
    // 80188890: bl      0x801A49CC
    {
            ctx->lr = 0x80188894u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188894:
    ctx->pc = 0x80188894u;
    ctx->downcount -= 1;
    // 80188894: b       0x80188A04
    {
            goto label_80188A04;
    }

label_80188898:
    ctx->pc = 0x80188898u;
    ctx->downcount -= 2;
    // 80188898: rlwinm. r0, r6, 0, 0, 0
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x80000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018889C:
    ctx->pc = 0x8018889Cu;
    // 8018889C: bc    12, 2, 0x801888A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801888A8;
        }
    }

label_801888A0:
    ctx->pc = 0x801888A0u;
    ctx->downcount -= 2;
    // 801888A0: rlwinm. r0, r6, 0, 5, 5
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x04000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801888A4:
    ctx->pc = 0x801888A4u;
    // 801888A4: bc    12, 2, 0x80188918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188918;
        }
    }

label_801888A8:
    ctx->pc = 0x801888A8u;
    ctx->downcount -= 2;
    // 801888A8: cmplwi  r5, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801888AC:
    ctx->pc = 0x801888ACu;
    // 801888AC: bc    12, 2, 0x801888E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801888E4;
        }
    }

label_801888B0:
    ctx->pc = 0x801888B0u;
    ctx->downcount -= 14;
    // 801888B0: mulli   r0, r29, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801888B4:
    ctx->pc = 0x801888B4u;
    // 801888B4: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_801888B8:
    ctx->pc = 0x801888B8u;
    // 801888B8: add   r6, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801888BC:
    ctx->pc = 0x801888BCu;
    // 801888BC: addi    r8, r3, -31588
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(-31588);

label_801888C0:
    ctx->pc = 0x801888C0u;
    // 801888C0: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_801888C4:
    ctx->pc = 0x801888C4u;
    // 801888C4: addi    r4, r13, -28720
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28720);

label_801888C8:
    ctx->pc = 0x801888C8u;
    // 801888C8: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_801888CC:
    ctx->pc = 0x801888CCu;
    // 801888CC: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_801888D0:
    ctx->pc = 0x801888D0u;
    // 801888D0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801888D4:
    ctx->pc = 0x801888D4u;
    // 801888D4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801888D8:
    ctx->pc = 0x801888D8u;
    // 801888D8: addi    r6, r6, 16
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(16);

label_801888DC:
    ctx->pc = 0x801888DCu;
    // 801888DC: bl      0x801A438C
    {
            ctx->lr = 0x801888E0u;
            ctx->pc = 0x801A438Cu;
            return;
    }

label_801888E0:
    ctx->pc = 0x801888E0u;
    ctx->downcount -= 1;
    // 801888E0: b       0x801889A0
    {
            goto label_801889A0;
    }

label_801888E4:
    ctx->pc = 0x801888E4u;
    ctx->downcount -= 14;
    // 801888E4: mulli   r0, r29, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801888E8:
    ctx->pc = 0x801888E8u;
    // 801888E8: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_801888EC:
    ctx->pc = 0x801888ECu;
    // 801888EC: add   r6, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801888F0:
    ctx->pc = 0x801888F0u;
    // 801888F0: addi    r8, r3, -31588
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(-31588);

label_801888F4:
    ctx->pc = 0x801888F4u;
    // 801888F4: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_801888F8:
    ctx->pc = 0x801888F8u;
    // 801888F8: addi    r4, r13, -28724
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28724);

label_801888FC:
    ctx->pc = 0x801888FCu;
    // 801888FC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80188900:
    ctx->pc = 0x80188900u;
    // 80188900: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80188904:
    ctx->pc = 0x80188904u;
    // 80188904: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80188908:
    ctx->pc = 0x80188908u;
    // 80188908: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8018890C:
    ctx->pc = 0x8018890Cu;
    // 8018890C: addi    r6, r6, 16
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(16);

label_80188910:
    ctx->pc = 0x80188910u;
    // 80188910: bl      0x801A438C
    {
            ctx->lr = 0x80188914u;
            ctx->pc = 0x801A438Cu;
            return;
    }

label_80188914:
    ctx->pc = 0x80188914u;
    ctx->downcount -= 1;
    // 80188914: b       0x801889A0
    {
            goto label_801889A0;
    }

label_80188918:
    ctx->pc = 0x80188918u;
    ctx->downcount -= 2;
    // 80188918: rlwinm. r0, r6, 0, 11, 11
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00100000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018891C:
    ctx->pc = 0x8018891Cu;
    // 8018891C: bc    12, 2, 0x801889A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801889A0;
        }
    }

label_80188920:
    ctx->pc = 0x80188920u;
    ctx->downcount -= 2;
    // 80188920: rlwinm. r0, r6, 0, 12, 12
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00080000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188924:
    ctx->pc = 0x80188924u;
    // 80188924: bc    4, 2, 0x801889A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801889A0;
        }
    }

label_80188928:
    ctx->pc = 0x80188928u;
    ctx->downcount -= 2;
    // 80188928: rlwinm. r0, r6, 0, 13, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00040000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018892C:
    ctx->pc = 0x8018892Cu;
    // 8018892C: bc    4, 2, 0x801889A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801889A0;
        }
    }

label_80188930:
    ctx->pc = 0x80188930u;
    ctx->downcount -= 2;
    // 80188930: rlwinm. r0, r6, 0, 1, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x40000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188934:
    ctx->pc = 0x80188934u;
    // 80188934: bc    12, 2, 0x8018896C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018896C;
        }
    }

label_80188938:
    ctx->pc = 0x80188938u;
    ctx->downcount -= 14;
    // 80188938: mulli   r0, r29, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_8018893C:
    ctx->pc = 0x8018893Cu;
    // 8018893C: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_80188940:
    ctx->pc = 0x80188940u;
    // 80188940: add   r6, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80188944:
    ctx->pc = 0x80188944u;
    // 80188944: addi    r8, r3, -31588
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(-31588);

label_80188948:
    ctx->pc = 0x80188948u;
    // 80188948: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_8018894C:
    ctx->pc = 0x8018894Cu;
    // 8018894C: addi    r4, r13, -28724
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28724);

label_80188950:
    ctx->pc = 0x80188950u;
    // 80188950: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80188954:
    ctx->pc = 0x80188954u;
    // 80188954: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80188958:
    ctx->pc = 0x80188958u;
    // 80188958: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8018895C:
    ctx->pc = 0x8018895Cu;
    // 8018895C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80188960:
    ctx->pc = 0x80188960u;
    // 80188960: addi    r6, r6, 16
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(16);

label_80188964:
    ctx->pc = 0x80188964u;
    // 80188964: bl      0x801A438C
    {
            ctx->lr = 0x80188968u;
            ctx->pc = 0x801A438Cu;
            return;
    }

label_80188968:
    ctx->pc = 0x80188968u;
    ctx->downcount -= 1;
    // 80188968: b       0x801889A0
    {
            goto label_801889A0;
    }

label_8018896C:
    ctx->pc = 0x8018896Cu;
    ctx->downcount -= 15;
    // 8018896C: mulli   r0, r29, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_80188970:
    ctx->pc = 0x80188970u;
    // 80188970: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_80188974:
    ctx->pc = 0x80188974u;
    // 80188974: add   r4, r30, r4
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80188978:
    ctx->pc = 0x80188978u;
    // 80188978: add   r6, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8018897C:
    ctx->pc = 0x8018897Cu;
    // 8018897C: addi    r8, r3, -31200
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(-31200);

label_80188980:
    ctx->pc = 0x80188980u;
    // 80188980: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80188984:
    ctx->pc = 0x80188984u;
    // 80188984: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80188988:
    ctx->pc = 0x80188988u;
    // 80188988: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_8018898C:
    ctx->pc = 0x8018898Cu;
    // 8018898C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80188990:
    ctx->pc = 0x80188990u;
    // 80188990: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80188994:
    ctx->pc = 0x80188994u;
    // 80188994: addi    r4, r4, 64
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(64);

label_80188998:
    ctx->pc = 0x80188998u;
    // 80188998: addi    r6, r6, 16
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(16);

label_8018899C:
    ctx->pc = 0x8018899Cu;
    // 8018899C: bl      0x801A438C
    {
            ctx->lr = 0x801889A0u;
            ctx->pc = 0x801A438Cu;
            return;
    }

label_801889A0:
    ctx->pc = 0x801889A0u;
    ctx->downcount -= 2;
    // 801889A0: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801889A4:
    ctx->pc = 0x801889A4u;
    // 801889A4: bc    4, 2, 0x80188A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188A04;
        }
    }

label_801889A8:
    ctx->pc = 0x801889A8u;
    ctx->downcount -= 9;
    // 801889A8: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801889AC:
    ctx->pc = 0x801889ACu;
    // 801889AC: lwz     r3, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801889B0:
    ctx->pc = 0x801889B0u;
    // 801889B0: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_801889B4:
    ctx->pc = 0x801889B4u;
    // 801889B4: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801889B8:
    ctx->pc = 0x801889B8u;
    // 801889B8: or   r0, r3, r28
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[28];
    }

label_801889BC:
    ctx->pc = 0x801889BCu;
    // 801889BC: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801889C0:
    ctx->pc = 0x801889C0u;
    // 801889C0: stw     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801889C4:
    ctx->pc = 0x801889C4u;
    // 801889C4: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801889C8:
    ctx->pc = 0x801889C8u;
    // 801889C8: bc    12, 2, 0x80188A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188A04;
        }
    }

label_801889CC:
    ctx->pc = 0x801889CCu;
    ctx->downcount -= 12;
    // 801889CC: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_801889D0:
    ctx->pc = 0x801889D0u;
    // 801889D0: mulli   r0, r4, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_801889D4:
    ctx->pc = 0x801889D4u;
    // 801889D4: srw   r3, r3, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_801889D8:
    ctx->pc = 0x801889D8u;
    // 801889D8: andc   r4, r5, r3
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[3];
    }

label_801889DC:
    ctx->pc = 0x801889DCu;
    // 801889DC: add   r3, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801889E0:
    ctx->pc = 0x801889E0u;
    // 801889E0: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801889E4:
    ctx->pc = 0x801889E4u;
    // 801889E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801889E8:
    ctx->pc = 0x801889E8u;
    // 801889E8: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_801889EC:
    ctx->pc = 0x801889ECu;
    // 801889EC: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_801889F0:
    ctx->pc = 0x801889F0u;
    // 801889F0: bl      0x801698F0
    {
            ctx->lr = 0x801889F4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801889F4:
    ctx->pc = 0x801889F4u;
    ctx->downcount -= 4;
    // 801889F4: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801889F8:
    ctx->pc = 0x801889F8u;
    // 801889F8: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801889FC:
    ctx->pc = 0x801889FCu;
    // 801889FC: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188A00:
    ctx->pc = 0x80188A00u;
    // 80188A00: bl      0x801A49CC
    {
            ctx->lr = 0x80188A04u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188A04:
    ctx->pc = 0x80188A04u;
    ctx->downcount -= 9;
    // 80188A04: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188A08:
    ctx->pc = 0x80188A08u;
    // 80188A08: lwz     r31, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188A0C:
    ctx->pc = 0x80188A0Cu;
    // 80188A0C: lwz     r30, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188A10:
    ctx->pc = 0x80188A10u;
    // 80188A10: lwz     r29, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80188A14:
    ctx->pc = 0x80188A14u;
    // 80188A14: lwz     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80188A18:
    ctx->pc = 0x80188A18u;
    // 80188A18: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_80188A1C:
    ctx->pc = 0x80188A1Cu;
    // 80188A1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188A20:
    ctx->pc = 0x80188A20u;
    // 80188A20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188A24:
    ctx->pc = 0x80188A24u;
    ctx->downcount -= 12;
    // 80188A24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188A28:
    ctx->pc = 0x80188A28u;
    // 80188A28: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188A2C:
    ctx->pc = 0x80188A2Cu;
    // 80188A2C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188A30:
    ctx->pc = 0x80188A30u;
    // 80188A30: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188A34:
    ctx->pc = 0x80188A34u;
    // 80188A34: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80188A38:
    ctx->pc = 0x80188A38u;
    // 80188A38: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80188A3C:
    ctx->pc = 0x80188A3Cu;
    // 80188A3C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80188A40:
    ctx->pc = 0x80188A40u;
    // 80188A40: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80188A44:
    ctx->pc = 0x80188A44u;
    // 80188A44: srw   r29, r3, r31
    {
        u32 sh = ctx->gpr[31] & 0x3Fu;
        ctx->gpr[29] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_80188A48:
    ctx->pc = 0x80188A48u;
    // 80188A48: lwz     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188A4C:
    ctx->pc = 0x80188A4Cu;
    // 80188A4C: and.   r0, r0, r29
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[29];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188A50:
    ctx->pc = 0x80188A50u;
    // 80188A50: bc    12, 2, 0x80188B3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188B3C;
        }
    }

label_80188A54:
    ctx->pc = 0x80188A54u;
    ctx->downcount -= 10;
    // 80188A54: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188A58:
    ctx->pc = 0x80188A58u;
    // 80188A58: nor   r6, r29, r29
    {
        ctx->gpr[6] = ~(ctx->gpr[29] | ctx->gpr[29]);
    }

label_80188A5C:
    ctx->pc = 0x80188A5Cu;
    // 80188A5C: lwz     r3, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188A60:
    ctx->pc = 0x80188A60u;
    // 80188A60: rlwinm. r0, r4, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188A64:
    ctx->pc = 0x80188A64u;
    // 80188A64: and   r5, r5, r6
    {
        ctx->gpr[5] = ctx->gpr[5] & ctx->gpr[6];
    }

label_80188A68:
    ctx->pc = 0x80188A68u;
    // 80188A68: and   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] & ctx->gpr[6];
    }

label_80188A6C:
    ctx->pc = 0x80188A6Cu;
    // 80188A6C: stw     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80188A70:
    ctx->pc = 0x80188A70u;
    // 80188A70: stw     r3, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80188A74:
    ctx->pc = 0x80188A74u;
    // 80188A74: rlwinm r3, r4, 0, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFF00u;
    }

label_80188A78:
    ctx->pc = 0x80188A78u;
    // 80188A78: bc    4, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188A7C:
    ctx->pc = 0x80188A7Cu;
    ctx->downcount -= 2;
    // 80188A7C: rlwinm. r0, r3, 0, 0, 0
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x80000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188A80:
    ctx->pc = 0x80188A80u;
    // 80188A80: bc    12, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188A84:
    ctx->pc = 0x80188A84u;
    ctx->downcount -= 2;
    // 80188A84: rlwinm. r0, r3, 0, 11, 11
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00100000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188A88:
    ctx->pc = 0x80188A88u;
    // 80188A88: bc    12, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188A8C:
    ctx->pc = 0x80188A8Cu;
    ctx->downcount -= 2;
    // 80188A8C: rlwinm. r0, r3, 0, 1, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x40000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188A90:
    ctx->pc = 0x80188A90u;
    // 80188A90: bc    12, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188A94:
    ctx->pc = 0x80188A94u;
    ctx->downcount -= 2;
    // 80188A94: rlwinm. r0, r3, 0, 5, 5
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x04000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188A98:
    ctx->pc = 0x80188A98u;
    // 80188A98: bc    4, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188A9C:
    ctx->pc = 0x80188A9Cu;
    ctx->downcount -= 2;
    // 80188A9C: rlwinm. r0, r3, 0, 12, 12
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00080000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188AA0:
    ctx->pc = 0x80188AA0u;
    // 80188AA0: bc    4, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188AA4:
    ctx->pc = 0x80188AA4u;
    ctx->downcount -= 2;
    // 80188AA4: rlwinm. r0, r3, 0, 13, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00040000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188AA8:
    ctx->pc = 0x80188AA8u;
    // 80188AA8: bc    4, 2, 0x80188AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188AE4;
        }
    }

label_80188AAC:
    ctx->pc = 0x80188AACu;
    ctx->downcount -= 15;
    // 80188AAC: mulli   r4, r31, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[31] * (s64)(s32)12);

label_80188AB0:
    ctx->pc = 0x80188AB0u;
    // 80188AB0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80188AB4:
    ctx->pc = 0x80188AB4u;
    // 80188AB4: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_80188AB8:
    ctx->pc = 0x80188AB8u;
    // 80188AB8: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_80188ABC:
    ctx->pc = 0x80188ABCu;
    // 80188ABC: add   r6, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80188AC0:
    ctx->pc = 0x80188AC0u;
    // 80188AC0: addi    r8, r3, -31392
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(-31392);

label_80188AC4:
    ctx->pc = 0x80188AC4u;
    // 80188AC4: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80188AC8:
    ctx->pc = 0x80188AC8u;
    // 80188AC8: addi    r4, r13, -28724
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28724);

label_80188ACC:
    ctx->pc = 0x80188ACCu;
    // 80188ACC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80188AD0:
    ctx->pc = 0x80188AD0u;
    // 80188AD0: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80188AD4:
    ctx->pc = 0x80188AD4u;
    // 80188AD4: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80188AD8:
    ctx->pc = 0x80188AD8u;
    // 80188AD8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80188ADC:
    ctx->pc = 0x80188ADCu;
    // 80188ADC: bl      0x801A438C
    {
            ctx->lr = 0x80188AE0u;
            ctx->pc = 0x801A438Cu;
            return;
    }

label_80188AE0:
    ctx->pc = 0x80188AE0u;
    ctx->downcount -= 1;
    // 80188AE0: b       0x80188B3C
    {
            goto label_80188B3C;
    }

label_80188AE4:
    ctx->pc = 0x80188AE4u;
    ctx->downcount -= 1;
    // 80188AE4: bl      0x80173F2C
    {
            ctx->lr = 0x80188AE8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188AE8:
    ctx->pc = 0x80188AE8u;
    ctx->downcount -= 3;
    // 80188AE8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80188AEC:
    ctx->pc = 0x80188AECu;
    // 80188AEC: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80188AF0:
    ctx->pc = 0x80188AF0u;
    // 80188AF0: bl      0x801A40FC
    {
            ctx->lr = 0x80188AF4u;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80188AF4:
    ctx->pc = 0x80188AF4u;
    ctx->downcount -= 16;
    // 80188AF4: lwz     r6, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80188AF8:
    ctx->pc = 0x80188AF8u;
    // 80188AF8: nor   r8, r29, r29
    {
        ctx->gpr[8] = ~(ctx->gpr[29] | ctx->gpr[29]);
    }

label_80188AFC:
    ctx->pc = 0x80188AFCu;
    // 80188AFC: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188B00:
    ctx->pc = 0x80188B00u;
    // 80188B00: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80188B04:
    ctx->pc = 0x80188B04u;
    // 80188B04: lwz     r4, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188B08:
    ctx->pc = 0x80188B08u;
    // 80188B08: lwz     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188B0C:
    ctx->pc = 0x80188B0Cu;
    // 80188B0C: and   r7, r6, r8
    {
        ctx->gpr[7] = ctx->gpr[6] & ctx->gpr[8];
    }

label_80188B10:
    ctx->pc = 0x80188B10u;
    // 80188B10: and   r6, r5, r8
    {
        ctx->gpr[6] = ctx->gpr[5] & ctx->gpr[8];
    }

label_80188B14:
    ctx->pc = 0x80188B14u;
    // 80188B14: stw     r7, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80188B18:
    ctx->pc = 0x80188B18u;
    // 80188B18: and   r5, r4, r8
    {
        ctx->gpr[5] = ctx->gpr[4] & ctx->gpr[8];
    }

label_80188B1C:
    ctx->pc = 0x80188B1Cu;
    // 80188B1C: and   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[8];
    }

label_80188B20:
    ctx->pc = 0x80188B20u;
    // 80188B20: stw     r6, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80188B24:
    ctx->pc = 0x80188B24u;
    // 80188B24: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188B28:
    ctx->pc = 0x80188B28u;
    // 80188B28: stw     r5, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80188B2C:
    ctx->pc = 0x80188B2Cu;
    // 80188B2C: stw     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188B30:
    ctx->pc = 0x80188B30u;
    // 80188B30: bl      0x80177DA4
    {
            ctx->lr = 0x80188B34u;
            ctx->pc = 0x80177DA4u;
            return;
    }

label_80188B34:
    ctx->pc = 0x80188B34u;
    ctx->downcount -= 2;
    // 80188B34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80188B38:
    ctx->pc = 0x80188B38u;
    // 80188B38: bl      0x80173F54
    {
            ctx->lr = 0x80188B3Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80188B3C:
    ctx->pc = 0x80188B3Cu;
    ctx->downcount -= 8;
    // 80188B3C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188B40:
    ctx->pc = 0x80188B40u;
    // 80188B40: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188B44:
    ctx->pc = 0x80188B44u;
    // 80188B44: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188B48:
    ctx->pc = 0x80188B48u;
    // 80188B48: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80188B4C:
    ctx->pc = 0x80188B4Cu;
    // 80188B4C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80188B50:
    ctx->pc = 0x80188B50u;
    // 80188B50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188B54:
    ctx->pc = 0x80188B54u;
    // 80188B54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188B58:
    ctx->pc = 0x80188B58u;
    ctx->downcount -= 7;
    // 80188B58: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188B5C:
    ctx->pc = 0x80188B5Cu;
    // 80188B5C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188B60:
    ctx->pc = 0x80188B60u;
    // 80188B60: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188B64:
    ctx->pc = 0x80188B64u;
    // 80188B64: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188B68:
    ctx->pc = 0x80188B68u;
    // 80188B68: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80188B6C:
    ctx->pc = 0x80188B6Cu;
    // 80188B6C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80188B70:
    ctx->pc = 0x80188B70u;
    // 80188B70: bl      0x80173F2C
    {
            ctx->lr = 0x80188B74u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188B74:
    ctx->pc = 0x80188B74u;
    ctx->downcount -= 20;
    // 80188B74: lwz     r4, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188B78:
    ctx->pc = 0x80188B78u;
    // 80188B78: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80188B7C:
    ctx->pc = 0x80188B7Cu;
    // 80188B7C: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188B80:
    ctx->pc = 0x80188B80u;
    // 80188B80: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_80188B84:
    ctx->pc = 0x80188B84u;
    // 80188B84: lwz     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188B88:
    ctx->pc = 0x80188B88u;
    // 80188B88: or   r30, r30, r4
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[4];
    }

label_80188B8C:
    ctx->pc = 0x80188B8Cu;
    // 80188B8C: lwz     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188B90:
    ctx->pc = 0x80188B90u;
    // 80188B90: or   r5, r5, r0
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80188B94:
    ctx->pc = 0x80188B94u;
    // 80188B94: lwz     r0, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188B98:
    ctx->pc = 0x80188B98u;
    // 80188B98: andc   r30, r30, r5
    {
        ctx->gpr[30] = ctx->gpr[30] & ~ctx->gpr[5];
    }

label_80188B9C:
    ctx->pc = 0x80188B9Cu;
    // 80188B9C: lwz     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188BA0:
    ctx->pc = 0x80188BA0u;
    // 80188BA0: or   r6, r4, r30
    {
        ctx->gpr[6] = ctx->gpr[4] | ctx->gpr[30];
    }

label_80188BA4:
    ctx->pc = 0x80188BA4u;
    // 80188BA4: stw     r7, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80188BA8:
    ctx->pc = 0x80188BA8u;
    // 80188BA8: andc   r4, r5, r30
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[30];
    }

label_80188BAC:
    ctx->pc = 0x80188BACu;
    // 80188BAC: stw     r6, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80188BB0:
    ctx->pc = 0x80188BB0u;
    // 80188BB0: cmplwi  r0, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188BB4:
    ctx->pc = 0x80188BB4u;
    // 80188BB4: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188BB8:
    ctx->pc = 0x80188BB8u;
    // 80188BB8: stw     r4, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188BBC:
    ctx->pc = 0x80188BBCu;
    // 80188BBC: and   r3, r0, r5
    {
        ctx->gpr[3] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80188BC0:
    ctx->pc = 0x80188BC0u;
    // 80188BC0: bc    4, 2, 0x80188BD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188BD0;
        }
    }

label_80188BC4:
    ctx->pc = 0x80188BC4u;
    ctx->downcount -= 3;
    // 80188BC4: lwz     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188BC8:
    ctx->pc = 0x80188BC8u;
    // 80188BC8: or   r0, r0, r30
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[30];
    }

label_80188BCC:
    ctx->pc = 0x80188BCCu;
    // 80188BCC: stw     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188BD0:
    ctx->pc = 0x80188BD0u;
    ctx->downcount -= 1;
    // 80188BD0: bl      0x801A40FC
    {
            ctx->lr = 0x80188BD4u;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80188BD4:
    ctx->pc = 0x80188BD4u;
    ctx->downcount -= 3;
    // 80188BD4: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188BD8:
    ctx->pc = 0x80188BD8u;
    // 80188BD8: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188BDC:
    ctx->pc = 0x80188BDCu;
    // 80188BDC: bc    4, 2, 0x80188C34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188C34;
        }
    }

label_80188BE0:
    ctx->pc = 0x80188BE0u;
    ctx->downcount -= 6;
    // 80188BE0: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188BE4:
    ctx->pc = 0x80188BE4u;
    // 80188BE4: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80188BE8:
    ctx->pc = 0x80188BE8u;
    // 80188BE8: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188BEC:
    ctx->pc = 0x80188BECu;
    // 80188BEC: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188BF0:
    ctx->pc = 0x80188BF0u;
    // 80188BF0: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188BF4:
    ctx->pc = 0x80188BF4u;
    // 80188BF4: bc    12, 2, 0x80188C34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188C34;
        }
    }

label_80188BF8:
    ctx->pc = 0x80188BF8u;
    ctx->downcount -= 13;
    // 80188BF8: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80188BFC:
    ctx->pc = 0x80188BFCu;
    // 80188BFC: srw   r0, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80188C00:
    ctx->pc = 0x80188C00u;
    // 80188C00: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_80188C04:
    ctx->pc = 0x80188C04u;
    // 80188C04: mulli   r4, r4, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_80188C08:
    ctx->pc = 0x80188C08u;
    // 80188C08: stw     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188C0C:
    ctx->pc = 0x80188C0Cu;
    // 80188C0C: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80188C10:
    ctx->pc = 0x80188C10u;
    // 80188C10: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_80188C14:
    ctx->pc = 0x80188C14u;
    // 80188C14: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80188C18:
    ctx->pc = 0x80188C18u;
    // 80188C18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188C1C:
    ctx->pc = 0x80188C1Cu;
    // 80188C1C: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_80188C20:
    ctx->pc = 0x80188C20u;
    // 80188C20: bl      0x801698F0
    {
            ctx->lr = 0x80188C24u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80188C24:
    ctx->pc = 0x80188C24u;
    ctx->downcount -= 4;
    // 80188C24: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188C28:
    ctx->pc = 0x80188C28u;
    // 80188C28: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188C2C:
    ctx->pc = 0x80188C2Cu;
    // 80188C2C: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188C30:
    ctx->pc = 0x80188C30u;
    // 80188C30: bl      0x801A49CC
    {
            ctx->lr = 0x80188C34u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188C34:
    ctx->pc = 0x80188C34u;
    ctx->downcount -= 2;
    // 80188C34: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80188C38:
    ctx->pc = 0x80188C38u;
    // 80188C38: bl      0x80173F54
    {
            ctx->lr = 0x80188C3Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80188C3C:
    ctx->pc = 0x80188C3Cu;
    ctx->downcount -= 8;
    // 80188C3C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188C40:
    ctx->pc = 0x80188C40u;
    // 80188C40: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80188C44:
    ctx->pc = 0x80188C44u;
    // 80188C44: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188C48:
    ctx->pc = 0x80188C48u;
    // 80188C48: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188C4C:
    ctx->pc = 0x80188C4Cu;
    // 80188C4C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80188C50:
    ctx->pc = 0x80188C50u;
    // 80188C50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188C54:
    ctx->pc = 0x80188C54u;
    // 80188C54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188C58:
    ctx->pc = 0x80188C58u;
    ctx->downcount -= 7;
    // 80188C58: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188C5C:
    ctx->pc = 0x80188C5Cu;
    // 80188C5C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188C60:
    ctx->pc = 0x80188C60u;
    // 80188C60: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188C64:
    ctx->pc = 0x80188C64u;
    // 80188C64: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80188C68:
    ctx->pc = 0x80188C68u;
    // 80188C68: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80188C6C:
    ctx->pc = 0x80188C6Cu;
    // 80188C6C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80188C70:
    ctx->pc = 0x80188C70u;
    // 80188C70: bl      0x80173F2C
    {
            ctx->lr = 0x80188C74u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188C74:
    ctx->pc = 0x80188C74u;
    ctx->downcount -= 21;
    // 80188C74: lwz     r6, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80188C78:
    ctx->pc = 0x80188C78u;
    // 80188C78: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80188C7C:
    ctx->pc = 0x80188C7Cu;
    // 80188C7C: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188C80:
    ctx->pc = 0x80188C80u;
    // 80188C80: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80188C84:
    ctx->pc = 0x80188C84u;
    // 80188C84: lwz     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188C88:
    ctx->pc = 0x80188C88u;
    // 80188C88: or   r30, r30, r6
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[6];
    }

label_80188C8C:
    ctx->pc = 0x80188C8Cu;
    // 80188C8C: lwz     r6, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80188C90:
    ctx->pc = 0x80188C90u;
    // 80188C90: or   r5, r5, r0
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80188C94:
    ctx->pc = 0x80188C94u;
    // 80188C94: lbz     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80188C98:
    ctx->pc = 0x80188C98u;
    // 80188C98: andc   r30, r30, r5
    {
        ctx->gpr[30] = ctx->gpr[30] & ~ctx->gpr[5];
    }

label_80188C9C:
    ctx->pc = 0x80188C9Cu;
    // 80188C9C: lwz     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188CA0:
    ctx->pc = 0x80188CA0u;
    // 80188CA0: or   r4, r6, r30
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[30];
    }

label_80188CA4:
    ctx->pc = 0x80188CA4u;
    // 80188CA4: stw     r7, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80188CA8:
    ctx->pc = 0x80188CA8u;
    // 80188CA8: rlwinm. r0, r0, 0, 25, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000040u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188CAC:
    ctx->pc = 0x80188CACu;
    // 80188CAC: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188CB0:
    ctx->pc = 0x80188CB0u;
    // 80188CB0: andc   r4, r5, r30
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[30];
    }

label_80188CB4:
    ctx->pc = 0x80188CB4u;
    // 80188CB4: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_80188CB8:
    ctx->pc = 0x80188CB8u;
    // 80188CB8: lwz     r6, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80188CBC:
    ctx->pc = 0x80188CBCu;
    // 80188CBC: stw     r4, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188CC0:
    ctx->pc = 0x80188CC0u;
    // 80188CC0: and   r3, r6, r5
    {
        ctx->gpr[3] = ctx->gpr[6] & ctx->gpr[5];
    }

label_80188CC4:
    ctx->pc = 0x80188CC4u;
    // 80188CC4: bc    4, 2, 0x80188CD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188CD4;
        }
    }

label_80188CC8:
    ctx->pc = 0x80188CC8u;
    ctx->downcount -= 3;
    // 80188CC8: lwz     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188CCC:
    ctx->pc = 0x80188CCCu;
    // 80188CCC: or   r0, r0, r30
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[30];
    }

label_80188CD0:
    ctx->pc = 0x80188CD0u;
    // 80188CD0: stw     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188CD4:
    ctx->pc = 0x80188CD4u;
    ctx->downcount -= 1;
    // 80188CD4: bl      0x801A40FC
    {
            ctx->lr = 0x80188CD8u;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80188CD8:
    ctx->pc = 0x80188CD8u;
    ctx->downcount -= 3;
    // 80188CD8: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188CDC:
    ctx->pc = 0x80188CDCu;
    // 80188CDC: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188CE0:
    ctx->pc = 0x80188CE0u;
    // 80188CE0: bc    4, 2, 0x80188D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188D38;
        }
    }

label_80188CE4:
    ctx->pc = 0x80188CE4u;
    ctx->downcount -= 6;
    // 80188CE4: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188CE8:
    ctx->pc = 0x80188CE8u;
    // 80188CE8: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80188CEC:
    ctx->pc = 0x80188CECu;
    // 80188CEC: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188CF0:
    ctx->pc = 0x80188CF0u;
    // 80188CF0: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188CF4:
    ctx->pc = 0x80188CF4u;
    // 80188CF4: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188CF8:
    ctx->pc = 0x80188CF8u;
    // 80188CF8: bc    12, 2, 0x80188D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188D38;
        }
    }

label_80188CFC:
    ctx->pc = 0x80188CFCu;
    ctx->downcount -= 13;
    // 80188CFC: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80188D00:
    ctx->pc = 0x80188D00u;
    // 80188D00: srw   r0, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80188D04:
    ctx->pc = 0x80188D04u;
    // 80188D04: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_80188D08:
    ctx->pc = 0x80188D08u;
    // 80188D08: mulli   r4, r4, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_80188D0C:
    ctx->pc = 0x80188D0Cu;
    // 80188D0C: stw     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188D10:
    ctx->pc = 0x80188D10u;
    // 80188D10: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80188D14:
    ctx->pc = 0x80188D14u;
    // 80188D14: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_80188D18:
    ctx->pc = 0x80188D18u;
    // 80188D18: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80188D1C:
    ctx->pc = 0x80188D1Cu;
    // 80188D1C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188D20:
    ctx->pc = 0x80188D20u;
    // 80188D20: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_80188D24:
    ctx->pc = 0x80188D24u;
    // 80188D24: bl      0x801698F0
    {
            ctx->lr = 0x80188D28u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80188D28:
    ctx->pc = 0x80188D28u;
    ctx->downcount -= 4;
    // 80188D28: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188D2C:
    ctx->pc = 0x80188D2Cu;
    // 80188D2C: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188D30:
    ctx->pc = 0x80188D30u;
    // 80188D30: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188D34:
    ctx->pc = 0x80188D34u;
    // 80188D34: bl      0x801A49CC
    {
            ctx->lr = 0x80188D38u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188D38:
    ctx->pc = 0x80188D38u;
    ctx->downcount -= 2;
    // 80188D38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80188D3C:
    ctx->pc = 0x80188D3Cu;
    // 80188D3C: bl      0x80173F54
    {
            ctx->lr = 0x80188D40u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80188D40:
    ctx->pc = 0x80188D40u;
    ctx->downcount -= 8;
    // 80188D40: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188D44:
    ctx->pc = 0x80188D44u;
    // 80188D44: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80188D48:
    ctx->pc = 0x80188D48u;
    // 80188D48: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80188D4C:
    ctx->pc = 0x80188D4Cu;
    // 80188D4C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80188D50:
    ctx->pc = 0x80188D50u;
    // 80188D50: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80188D54:
    ctx->pc = 0x80188D54u;
    // 80188D54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188D58:
    ctx->pc = 0x80188D58u;
    // 80188D58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188D5C:
    ctx->pc = 0x80188D5Cu;
    ctx->downcount -= 19;
    // 80188D5C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188D60:
    ctx->pc = 0x80188D60u;
    // 80188D60: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80188D64:
    ctx->pc = 0x80188D64u;
    // 80188D64: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188D68:
    ctx->pc = 0x80188D68u;
    // 80188D68: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188D6C:
    ctx->pc = 0x80188D6Cu;
    // 80188D6C: stmw     r25, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80188D70:
    ctx->pc = 0x80188D70u;
    // 80188D70: addi    r31, r3, 2856
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2856);

label_80188D74:
    ctx->pc = 0x80188D74u;
    // 80188D74: lwz     r0, -26416(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26416);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188D78:
    ctx->pc = 0x80188D78u;
    // 80188D78: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188D7C:
    ctx->pc = 0x80188D7Cu;
    // 80188D7C: bc    12, 2, 0x80188D88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188D88;
        }
    }

label_80188D80:
    ctx->pc = 0x80188D80u;
    ctx->downcount -= 2;
    // 80188D80: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80188D84:
    ctx->pc = 0x80188D84u;
    // 80188D84: b       0x80188F58
    {
            goto label_80188F58;
    }

label_80188D88:
    ctx->pc = 0x80188D88u;
    ctx->downcount -= 3;
    // 80188D88: lwz     r3, -26376(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26376);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188D8C:
    ctx->pc = 0x80188D8Cu;
    // 80188D8C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188D90:
    ctx->pc = 0x80188D90u;
    // 80188D90: bc    12, 2, 0x80188D98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188D98;
        }
    }

label_80188D94:
    ctx->pc = 0x80188D94u;
    ctx->downcount -= 1;
    // 80188D94: bl      0x80189494
    {
            ctx->lr = 0x80188D98u;
            goto label_80189494;
    }

label_80188D98:
    ctx->pc = 0x80188D98u;
    ctx->downcount -= 5;
    // 80188D98: lwz     r0, -26040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188D9C:
    ctx->pc = 0x80188D9Cu;
    // 80188D9C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80188DA0:
    ctx->pc = 0x80188DA0u;
    // 80188DA0: stw     r3, -26416(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26416);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80188DA4:
    ctx->pc = 0x80188DA4u;
    // 80188DA4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188DA8:
    ctx->pc = 0x80188DA8u;
    // 80188DA8: bc    12, 2, 0x80188E34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188E34;
        }
    }

label_80188DAC:
    ctx->pc = 0x80188DACu;
    ctx->downcount -= 1;
    // 80188DAC: bl      0x80179FF4
    {
            ctx->lr = 0x80188DB0u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_80188DB0:
    ctx->pc = 0x80188DB0u;
    ctx->downcount -= 4;
    // 80188DB0: addi    r25, r4, 0
    ctx->gpr[25] = ctx->gpr[4] + (u32)(s32)(0);

label_80188DB4:
    ctx->pc = 0x80188DB4u;
    // 80188DB4: addi    r26, r3, 0
    ctx->gpr[26] = ctx->gpr[3] + (u32)(s32)(0);

label_80188DB8:
    ctx->pc = 0x80188DB8u;
    // 80188DB8: li      r5, 16
    ctx->gpr[5] = (u32)(s32)(16);

label_80188DBC:
    ctx->pc = 0x80188DBCu;
    // 80188DBC: bl      0x801632CC
    {
            ctx->lr = 0x80188DC0u;
            ctx->pc = 0x801632CCu;
            return;
    }

label_80188DC0:
    ctx->pc = 0x80188DC0u;
    ctx->downcount -= 13;
    // 80188DC0: lis     r5, 1
    ctx->gpr[5] = ((u32)(s32)(1) << 16);

label_80188DC4:
    ctx->pc = 0x80188DC4u;
    // 80188DC4: addi    r27, r5, -1
    ctx->gpr[27] = ctx->gpr[5] + (u32)(s32)(-1);

label_80188DC8:
    ctx->pc = 0x80188DC8u;
    // 80188DC8: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80188DCC:
    ctx->pc = 0x80188DCCu;
    // 80188DCC: and   r6, r4, r27
    {
        ctx->gpr[6] = ctx->gpr[4] & ctx->gpr[27];
    }

label_80188DD0:
    ctx->pc = 0x80188DD0u;
    // 80188DD0: and   r4, r25, r27
    {
        ctx->gpr[4] = ctx->gpr[25] & ctx->gpr[27];
    }

label_80188DD4:
    ctx->pc = 0x80188DD4u;
    // 80188DD4: and   r5, r3, r28
    {
        ctx->gpr[5] = ctx->gpr[3] & ctx->gpr[28];
    }

label_80188DD8:
    ctx->pc = 0x80188DD8u;
    // 80188DD8: and   r0, r26, r28
    {
        ctx->gpr[0] = ctx->gpr[26] & ctx->gpr[28];
    }

label_80188DDC:
    ctx->pc = 0x80188DDCu;
    // 80188DDC: addc   r29, r4, r6
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[6];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[29] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80188DE0:
    ctx->pc = 0x80188DE0u;
    // 80188DE0: addi    r3, r26, 0
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(0);

label_80188DE4:
    ctx->pc = 0x80188DE4u;
    // 80188DE4: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_80188DE8:
    ctx->pc = 0x80188DE8u;
    // 80188DE8: adde   r30, r0, r5
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[30] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80188DEC:
    ctx->pc = 0x80188DECu;
    // 80188DEC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80188DF0:
    ctx->pc = 0x80188DF0u;
    // 80188DF0: bl      0x801632CC
    {
            ctx->lr = 0x80188DF4u;
            ctx->pc = 0x801632CCu;
            return;
    }

label_80188DF4:
    ctx->pc = 0x80188DF4u;
    ctx->downcount -= 8;
    // 80188DF4: and   r4, r4, r27
    {
        ctx->gpr[4] = ctx->gpr[4] & ctx->gpr[27];
    }

label_80188DF8:
    ctx->pc = 0x80188DF8u;
    // 80188DF8: and   r0, r3, r28
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[28];
    }

label_80188DFC:
    ctx->pc = 0x80188DFCu;
    // 80188DFC: addc   r29, r4, r29
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[29] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80188E00:
    ctx->pc = 0x80188E00u;
    // 80188E00: addi    r3, r26, 0
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(0);

label_80188E04:
    ctx->pc = 0x80188E04u;
    // 80188E04: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_80188E08:
    ctx->pc = 0x80188E08u;
    // 80188E08: adde   r30, r0, r30
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[30] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80188E0C:
    ctx->pc = 0x80188E0Cu;
    // 80188E0C: li      r5, 48
    ctx->gpr[5] = (u32)(s32)(48);

label_80188E10:
    ctx->pc = 0x80188E10u;
    // 80188E10: bl      0x801632CC
    {
            ctx->lr = 0x80188E14u;
            ctx->pc = 0x801632CCu;
            return;
    }

label_80188E14:
    ctx->pc = 0x80188E14u;
    ctx->downcount -= 8;
    // 80188E14: and   r0, r4, r27
    {
        ctx->gpr[0] = ctx->gpr[4] & ctx->gpr[27];
    }

label_80188E18:
    ctx->pc = 0x80188E18u;
    // 80188E18: addc   r5, r0, r29
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80188E1C:
    ctx->pc = 0x80188E1Cu;
    // 80188E1C: lis     r0, -4096
    ctx->gpr[0] = ((u32)(s32)(-4096) << 16);

label_80188E20:
    ctx->pc = 0x80188E20u;
    // 80188E20: li      r4, 16383
    ctx->gpr[4] = (u32)(s32)(16383);

label_80188E24:
    ctx->pc = 0x80188E24u;
    // 80188E24: stw     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188E28:
    ctx->pc = 0x80188E28u;
    // 80188E28: and   r0, r5, r4
    {
        ctx->gpr[0] = ctx->gpr[5] & ctx->gpr[4];
    }

label_80188E2C:
    ctx->pc = 0x80188E2Cu;
    // 80188E2C: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80188E30:
    ctx->pc = 0x80188E30u;
    // 80188E30: sth     r0, 12512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12512);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80188E34:
    ctx->pc = 0x80188E34u;
    ctx->downcount -= 18;
    // 80188E34: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80188E38:
    ctx->pc = 0x80188E38u;
    // 80188E38: lhz     r0, 12512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80188E3C:
    ctx->pc = 0x80188E3Cu;
    // 80188E3C: rlwinm r0, r0, 8, 10, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x003FFF00u;
    }

label_80188E40:
    ctx->pc = 0x80188E40u;
    // 80188E40: oris    r0, r0, 0x4D00
    ctx->gpr[0] = ctx->gpr[0] | (0x4D00u << 16);

label_80188E44:
    ctx->pc = 0x80188E44u;
    // 80188E44: stw     r0, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188E48:
    ctx->pc = 0x80188E48u;
    // 80188E48: lhz     r0, 12512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80188E4C:
    ctx->pc = 0x80188E4Cu;
    // 80188E4C: rlwinm r0, r0, 8, 10, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x003FFF00u;
    }

label_80188E50:
    ctx->pc = 0x80188E50u;
    // 80188E50: oris    r0, r0, 0x4D40
    ctx->gpr[0] = ctx->gpr[0] | (0x4D40u << 16);

label_80188E54:
    ctx->pc = 0x80188E54u;
    // 80188E54: stw     r0, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188E58:
    ctx->pc = 0x80188E58u;
    // 80188E58: lhz     r0, 12512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80188E5C:
    ctx->pc = 0x80188E5Cu;
    // 80188E5C: rlwinm r0, r0, 8, 10, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x003FFF00u;
    }

label_80188E60:
    ctx->pc = 0x80188E60u;
    // 80188E60: oris    r0, r0, 0x4D80
    ctx->gpr[0] = ctx->gpr[0] | (0x4D80u << 16);

label_80188E64:
    ctx->pc = 0x80188E64u;
    // 80188E64: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188E68:
    ctx->pc = 0x80188E68u;
    // 80188E68: lhz     r0, 12512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80188E6C:
    ctx->pc = 0x80188E6Cu;
    // 80188E6C: rlwinm r0, r0, 8, 10, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x003FFF00u;
    }

label_80188E70:
    ctx->pc = 0x80188E70u;
    // 80188E70: oris    r0, r0, 0x4DC0
    ctx->gpr[0] = ctx->gpr[0] | (0x4DC0u << 16);

label_80188E74:
    ctx->pc = 0x80188E74u;
    // 80188E74: stw     r0, 76(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188E78:
    ctx->pc = 0x80188E78u;
    // 80188E78: bl      0x801A4EB4
    {
            ctx->lr = 0x80188E7Cu;
            ctx->pc = 0x801A4EB4u;
            return;
    }

label_80188E7C:
    ctx->pc = 0x80188E7Cu;
    ctx->downcount -= 3;
    // 80188E7C: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_80188E80:
    ctx->pc = 0x80188E80u;
    // 80188E80: addi    r3, r3, -5072
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-5072);

label_80188E84:
    ctx->pc = 0x80188E84u;
    // 80188E84: bl      0x80175CE8
    {
            ctx->lr = 0x80188E88u;
            ctx->pc = 0x80175CE8u;
            return;
    }

label_80188E88:
    ctx->pc = 0x80188E88u;
    ctx->downcount -= 2;
    // 80188E88: lis     r28, -4096
    ctx->gpr[28] = ((u32)(s32)(-4096) << 16);

label_80188E8C:
    ctx->pc = 0x80188E8Cu;
    // 80188E8C: bl      0x80173F2C
    {
            ctx->lr = 0x80188E90u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188E90:
    ctx->pc = 0x80188E90u;
    ctx->downcount -= 20;
    // 80188E90: lwz     r4, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188E94:
    ctx->pc = 0x80188E94u;
    // 80188E94: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80188E98:
    ctx->pc = 0x80188E98u;
    // 80188E98: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188E9C:
    ctx->pc = 0x80188E9Cu;
    // 80188E9C: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_80188EA0:
    ctx->pc = 0x80188EA0u;
    // 80188EA0: lwz     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188EA4:
    ctx->pc = 0x80188EA4u;
    // 80188EA4: or   r28, r28, r4
    {
        ctx->gpr[28] = ctx->gpr[28] | ctx->gpr[4];
    }

label_80188EA8:
    ctx->pc = 0x80188EA8u;
    // 80188EA8: lwz     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188EAC:
    ctx->pc = 0x80188EACu;
    // 80188EAC: or   r5, r5, r0
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80188EB0:
    ctx->pc = 0x80188EB0u;
    // 80188EB0: lwz     r0, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188EB4:
    ctx->pc = 0x80188EB4u;
    // 80188EB4: andc   r28, r28, r5
    {
        ctx->gpr[28] = ctx->gpr[28] & ~ctx->gpr[5];
    }

label_80188EB8:
    ctx->pc = 0x80188EB8u;
    // 80188EB8: lwz     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188EBC:
    ctx->pc = 0x80188EBCu;
    // 80188EBC: or   r6, r4, r28
    {
        ctx->gpr[6] = ctx->gpr[4] | ctx->gpr[28];
    }

label_80188EC0:
    ctx->pc = 0x80188EC0u;
    // 80188EC0: stw     r7, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80188EC4:
    ctx->pc = 0x80188EC4u;
    // 80188EC4: andc   r4, r5, r28
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[28];
    }

label_80188EC8:
    ctx->pc = 0x80188EC8u;
    // 80188EC8: stw     r6, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80188ECC:
    ctx->pc = 0x80188ECCu;
    // 80188ECC: cmplwi  r0, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188ED0:
    ctx->pc = 0x80188ED0u;
    // 80188ED0: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188ED4:
    ctx->pc = 0x80188ED4u;
    // 80188ED4: stw     r4, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188ED8:
    ctx->pc = 0x80188ED8u;
    // 80188ED8: and   r3, r0, r5
    {
        ctx->gpr[3] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80188EDC:
    ctx->pc = 0x80188EDCu;
    // 80188EDC: bc    4, 2, 0x80188EEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188EEC;
        }
    }

label_80188EE0:
    ctx->pc = 0x80188EE0u;
    ctx->downcount -= 3;
    // 80188EE0: lwz     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188EE4:
    ctx->pc = 0x80188EE4u;
    // 80188EE4: or   r0, r0, r28
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[28];
    }

label_80188EE8:
    ctx->pc = 0x80188EE8u;
    // 80188EE8: stw     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188EEC:
    ctx->pc = 0x80188EECu;
    ctx->downcount -= 1;
    // 80188EEC: bl      0x801A40FC
    {
            ctx->lr = 0x80188EF0u;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80188EF0:
    ctx->pc = 0x80188EF0u;
    ctx->downcount -= 3;
    // 80188EF0: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188EF4:
    ctx->pc = 0x80188EF4u;
    // 80188EF4: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188EF8:
    ctx->pc = 0x80188EF8u;
    // 80188EF8: bc    4, 2, 0x80188F4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80188F4C;
        }
    }

label_80188EFC:
    ctx->pc = 0x80188EFCu;
    ctx->downcount -= 6;
    // 80188EFC: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188F00:
    ctx->pc = 0x80188F00u;
    // 80188F00: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80188F04:
    ctx->pc = 0x80188F04u;
    // 80188F04: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188F08:
    ctx->pc = 0x80188F08u;
    // 80188F08: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188F0C:
    ctx->pc = 0x80188F0Cu;
    // 80188F0C: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80188F10:
    ctx->pc = 0x80188F10u;
    // 80188F10: bc    12, 2, 0x80188F4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80188F4C;
        }
    }

label_80188F14:
    ctx->pc = 0x80188F14u;
    ctx->downcount -= 12;
    // 80188F14: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80188F18:
    ctx->pc = 0x80188F18u;
    // 80188F18: mulli   r0, r4, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_80188F1C:
    ctx->pc = 0x80188F1Cu;
    // 80188F1C: srw   r3, r3, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_80188F20:
    ctx->pc = 0x80188F20u;
    // 80188F20: andc   r4, r5, r3
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[3];
    }

label_80188F24:
    ctx->pc = 0x80188F24u;
    // 80188F24: add   r3, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80188F28:
    ctx->pc = 0x80188F28u;
    // 80188F28: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80188F2C:
    ctx->pc = 0x80188F2Cu;
    // 80188F2C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80188F30:
    ctx->pc = 0x80188F30u;
    // 80188F30: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_80188F34:
    ctx->pc = 0x80188F34u;
    // 80188F34: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_80188F38:
    ctx->pc = 0x80188F38u;
    // 80188F38: bl      0x801698F0
    {
            ctx->lr = 0x80188F3Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80188F3C:
    ctx->pc = 0x80188F3Cu;
    ctx->downcount -= 4;
    // 80188F3C: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188F40:
    ctx->pc = 0x80188F40u;
    // 80188F40: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80188F44:
    ctx->pc = 0x80188F44u;
    // 80188F44: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80188F48:
    ctx->pc = 0x80188F48u;
    // 80188F48: bl      0x801A49CC
    {
            ctx->lr = 0x80188F4Cu;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80188F4C:
    ctx->pc = 0x80188F4Cu;
    ctx->downcount -= 2;
    // 80188F4C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80188F50:
    ctx->pc = 0x80188F50u;
    // 80188F50: bl      0x80173F54
    {
            ctx->lr = 0x80188F54u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80188F54:
    ctx->pc = 0x80188F54u;
    ctx->downcount -= 1;
    // 80188F54: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80188F58:
    ctx->pc = 0x80188F58u;
    ctx->downcount -= 16;
    // 80188F58: lmw     r25, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80188F5C:
    ctx->pc = 0x80188F5Cu;
    // 80188F5C: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188F60:
    ctx->pc = 0x80188F60u;
    // 80188F60: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_80188F64:
    ctx->pc = 0x80188F64u;
    // 80188F64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80188F68:
    ctx->pc = 0x80188F68u;
    // 80188F68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80188F6C:
    ctx->pc = 0x80188F6Cu;
    ctx->downcount -= 16;
    // 80188F6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80188F70:
    ctx->pc = 0x80188F70u;
    // 80188F70: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80188F74:
    ctx->pc = 0x80188F74u;
    // 80188F74: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80188F78:
    ctx->pc = 0x80188F78u;
    // 80188F78: stmw     r20, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 20; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80188F7C:
    ctx->pc = 0x80188F7Cu;
    // 80188F7C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80188F80:
    ctx->pc = 0x80188F80u;
    // 80188F80: bl      0x80173F2C
    {
            ctx->lr = 0x80188F84u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188F84:
    ctx->pc = 0x80188F84u;
    ctx->downcount -= 16;
    // 80188F84: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_80188F88:
    ctx->pc = 0x80188F88u;
    // 80188F88: mulli   r0, r21, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[21] * (s64)(s32)12);

label_80188F8C:
    ctx->pc = 0x80188F8Cu;
    // 80188F8C: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80188F90:
    ctx->pc = 0x80188F90u;
    // 80188F90: addi    r26, r4, 2872
    ctx->gpr[26] = ctx->gpr[4] + (u32)(s32)(2872);

label_80188F94:
    ctx->pc = 0x80188F94u;
    // 80188F94: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80188F98:
    ctx->pc = 0x80188F98u;
    // 80188F98: lis     r5, -32743
    ctx->gpr[5] = ((u32)(s32)(-32743) << 16);

label_80188F9C:
    ctx->pc = 0x80188F9Cu;
    // 80188F9C: lis     r6, -32743
    ctx->gpr[6] = ((u32)(s32)(-32743) << 16);

label_80188FA0:
    ctx->pc = 0x80188FA0u;
    // 80188FA0: add   r24, r26, r0
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[24] = res;
    }

label_80188FA4:
    ctx->pc = 0x80188FA4u;
    // 80188FA4: addi    r22, r3, 0
    ctx->gpr[22] = ctx->gpr[3] + (u32)(s32)(0);

label_80188FA8:
    ctx->pc = 0x80188FA8u;
    // 80188FA8: addi    r30, r4, -31392
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(-31392);

label_80188FAC:
    ctx->pc = 0x80188FACu;
    // 80188FAC: addi    r29, r5, -30172
    ctx->gpr[29] = ctx->gpr[5] + (u32)(s32)(-30172);

label_80188FB0:
    ctx->pc = 0x80188FB0u;
    // 80188FB0: addi    r28, r6, -30984
    ctx->gpr[28] = ctx->gpr[6] + (u32)(s32)(-30984);

label_80188FB4:
    ctx->pc = 0x80188FB4u;
    // 80188FB4: li      r20, 0
    ctx->gpr[20] = (u32)(s32)(0);

label_80188FB8:
    ctx->pc = 0x80188FB8u;
    // 80188FB8: lis     r27, -32768
    ctx->gpr[27] = ((u32)(s32)(-32768) << 16);

label_80188FBC:
    ctx->pc = 0x80188FBCu;
    ctx->downcount -= 4;
    // 80188FBC: lwz     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188FC0:
    // 80188FC0: srw   r23, r27, r21
    {
        u32 sh = ctx->gpr[21] & 0x3Fu;
        ctx->gpr[23] = sh > 31 ? 0u : (ctx->gpr[27] >> sh);
    }

label_80188FC4:
    // 80188FC4: and.   r0, r0, r23
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[23];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80188FC8:
    // 80188FC8: bc    12, 2, 0x801890A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801890A0;
        }
    }

label_80188FCC:
    ctx->downcount -= 1;
    // 80188FCC: bl      0x80173F2C
    {
            ctx->lr = 0x80188FD0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80188FD0:
    ctx->pc = 0x80188FD0u;
    ctx->downcount -= 19;
    // 80188FD0: lwz     r4, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80188FD4:
    // 80188FD4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80188FD8:
    ctx->pc = 0x80188FD8u;
    // 80188FD8: lwz     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188FDC:
    // 80188FDC: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80188FE0:
    ctx->pc = 0x80188FE0u;
    // 80188FE0: lwz     r5, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188FE4:
    // 80188FE4: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80188FE8:
    ctx->pc = 0x80188FE8u;
    // 80188FE8: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188FEC:
    // 80188FEC: andc   r7, r5, r4
    {
        ctx->gpr[7] = ctx->gpr[5] & ~ctx->gpr[4];
    }

label_80188FF0:
    ctx->pc = 0x80188FF0u;
    // 80188FF0: lwz     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80188FF4:
    // 80188FF4: or   r4, r0, r7
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[7];
    }

label_80188FF8:
    ctx->pc = 0x80188FF8u;
    // 80188FF8: lwz     r0, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80188FFC:
    ctx->pc = 0x80188FFCu;
    // 80188FFC: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80189000:
    // 80189000: andc   r4, r5, r7
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[7];
    }

label_80189004:
    // 80189004: cmplwi  r0, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189008:
    ctx->pc = 0x80189008u;
    // 80189008: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018900C:
    ctx->pc = 0x8018900Cu;
    // 8018900C: stw     r6, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80189010:
    // 80189010: and   r3, r0, r5
    {
        ctx->gpr[3] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80189014:
    ctx->pc = 0x80189014u;
    // 80189014: stw     r4, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80189018:
    // 80189018: bc    4, 2, 0x80189028
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189028;
        }
    }

label_8018901C:
    ctx->pc = 0x8018901Cu;
    ctx->downcount -= 3;
    // 8018901C: lwz     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189020:
    // 80189020: or   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[7];
    }

label_80189024:
    ctx->pc = 0x80189024u;
    // 80189024: stw     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189028:
    ctx->downcount -= 1;
    // 80189028: bl      0x801A40FC
    {
            ctx->lr = 0x8018902Cu;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_8018902C:
    ctx->pc = 0x8018902Cu;
    ctx->downcount -= 3;
    // 8018902C: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189030:
    // 80189030: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189034:
    // 80189034: bc    4, 2, 0x8018907C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018907C;
        }
    }

label_80189038:
    ctx->pc = 0x80189038u;
    ctx->downcount -= 6;
    // 80189038: lwz     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018903C:
    // 8018903C: cntlzw r0, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80189040:
    ctx->pc = 0x80189040u;
    // 80189040: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189044:
    ctx->pc = 0x80189044u;
    // 80189044: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189048:
    // 80189048: cmpwi   r3, 32
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018904C:
    // 8018904C: bc    12, 2, 0x8018907C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018907C;
        }
    }

label_80189050:
    ctx->downcount -= 10;
    // 80189050: mulli   r0, r3, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)12);

label_80189054:
    // 80189054: srw   r3, r27, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[27] >> sh);
    }

label_80189058:
    // 80189058: andc   r4, r4, r3
    {
        ctx->gpr[4] = ctx->gpr[4] & ~ctx->gpr[3];
    }

label_8018905C:
    ctx->pc = 0x8018905Cu;
    // 8018905C: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80189060:
    // 80189060: add   r3, r26, r0
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80189064:
    // 80189064: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80189068:
    // 80189068: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_8018906C:
    // 8018906C: bl      0x801698F0
    {
            ctx->lr = 0x80189070u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80189070:
    ctx->pc = 0x80189070u;
    ctx->downcount -= 3;
    // 80189070: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189074:
    // 80189074: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80189078:
    // 80189078: bl      0x801A49CC
    {
            ctx->lr = 0x8018907Cu;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_8018907C:
    ctx->downcount -= 2;
    // 8018907C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80189080:
    // 80189080: bl      0x80173F54
    {
            ctx->lr = 0x80189084u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80189084:
    ctx->downcount -= 6;
    // 80189084: li      r0, -2
    ctx->gpr[0] = (u32)(s32)(-2);

label_80189088:
    ctx->pc = 0x80189088u;
    // 80189088: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018908C:
    // 8018908C: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80189090:
    // 80189090: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80189094:
    // 80189094: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_80189098:
    // 80189098: bl      0x801698F0
    {
            ctx->lr = 0x8018909Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8018909C:
    ctx->downcount -= 1;
    // 8018909C: b       0x801892E4
    {
            goto label_801892E4;
    }

label_801890A0:
    ctx->pc = 0x801890A0u;
    ctx->downcount -= 3;
    // 801890A0: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801890A4:
    // 801890A4: and.   r0, r0, r23
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[23];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801890A8:
    // 801890A8: bc    4, 2, 0x801890B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801890B8;
        }
    }

label_801890AC:
    ctx->pc = 0x801890ACu;
    ctx->downcount -= 3;
    // 801890AC: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801890B0:
    // 801890B0: cmpw    r0, r21
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[21]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801890B4:
    // 801890B4: bc    4, 2, 0x801890D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801890D4;
        }
    }

label_801890B8:
    ctx->downcount -= 6;
    // 801890B8: li      r0, -2
    ctx->gpr[0] = (u32)(s32)(-2);

label_801890BC:
    ctx->pc = 0x801890BCu;
    // 801890BC: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801890C0:
    // 801890C0: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801890C4:
    // 801890C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801890C8:
    // 801890C8: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_801890CC:
    // 801890CC: bl      0x801698F0
    {
            ctx->lr = 0x801890D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801890D0:
    ctx->downcount -= 1;
    // 801890D0: b       0x801892E4
    {
            goto label_801892E4;
    }

label_801890D4:
    ctx->pc = 0x801890D4u;
    ctx->downcount -= 3;
    // 801890D4: lwz     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801890D8:
    // 801890D8: and.   r0, r0, r23
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[23];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801890DC:
    // 801890DC: bc    4, 2, 0x801890FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801890FC;
        }
    }

label_801890E0:
    ctx->downcount -= 6;
    // 801890E0: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_801890E4:
    ctx->pc = 0x801890E4u;
    // 801890E4: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801890E8:
    // 801890E8: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801890EC:
    // 801890EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801890F0:
    // 801890F0: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_801890F4:
    // 801890F4: bl      0x801698F0
    {
            ctx->lr = 0x801890F8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801890F8:
    ctx->downcount -= 1;
    // 801890F8: b       0x801892E4
    {
            goto label_801892E4;
    }

label_801890FC:
    ctx->downcount -= 2;
    // 801890FC: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80189100:
    // 80189100: bl      0x801A31A8
    {
            ctx->lr = 0x80189104u;
            ctx->pc = 0x801A31A8u;
            return;
    }

label_80189104:
    ctx->downcount -= 2;
    // 80189104: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189108:
    // 80189108: bc    12, 2, 0x80189128
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189128;
        }
    }

label_8018910C:
    ctx->downcount -= 6;
    // 8018910C: li      r0, -3
    ctx->gpr[0] = (u32)(s32)(-3);

label_80189110:
    ctx->pc = 0x80189110u;
    // 80189110: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189114:
    // 80189114: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80189118:
    // 80189118: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8018911C:
    // 8018911C: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_80189120:
    // 80189120: bl      0x801698F0
    {
            ctx->lr = 0x80189124u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80189124:
    ctx->downcount -= 1;
    // 80189124: b       0x801892E4
    {
            goto label_801892E4;
    }

label_80189128:
    ctx->downcount -= 2;
    // 80189128: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8018912C:
    // 8018912C: bl      0x801A3F40
    {
            ctx->lr = 0x80189130u;
            ctx->pc = 0x801A3F40u;
            return;
    }

label_80189130:
    ctx->downcount -= 2;
    // 80189130: rlwinm. r0, r3, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189134:
    // 80189134: bc    12, 2, 0x80189200
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189200;
        }
    }

label_80189138:
    ctx->downcount -= 3;
    // 80189138: addi    r3, r21, 0
    ctx->gpr[3] = ctx->gpr[21] + (u32)(s32)(0);

label_8018913C:
    // 8018913C: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_80189140:
    // 80189140: bl      0x801A423C
    {
            ctx->lr = 0x80189144u;
            ctx->pc = 0x801A423Cu;
            return;
    }

label_80189144:
    ctx->pc = 0x80189144u;
    ctx->downcount -= 3;
    // 80189144: lwz     r0, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189148:
    // 80189148: and.   r0, r0, r23
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[23];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018914C:
    // 8018914C: bc    12, 2, 0x8018918C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018918C;
        }
    }

label_80189150:
    ctx->downcount -= 6;
    // 80189150: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80189154:
    ctx->pc = 0x80189154u;
    // 80189154: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189158:
    // 80189158: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_8018915C:
    // 8018915C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80189160:
    // 80189160: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_80189164:
    // 80189164: bl      0x801698F0
    {
            ctx->lr = 0x80189168u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80189168:
    ctx->pc = 0x80189168u;
    ctx->downcount -= 3;
    // 80189168: lwz     r3, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018916C:
    // 8018916C: and.   r0, r3, r23
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[23];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189170:
    // 80189170: bc    4, 2, 0x801892E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801892E4;
        }
    }

label_80189174:
    ctx->downcount -= 5;
    // 80189174: or   r0, r3, r23
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[23];
    }

label_80189178:
    ctx->pc = 0x80189178u;
    // 80189178: stw     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018917C:
    // 8018917C: addi    r3, r21, 0
    ctx->gpr[3] = ctx->gpr[21] + (u32)(s32)(0);

label_80189180:
    // 80189180: addi    r4, r29, 0
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(0);

label_80189184:
    // 80189184: bl      0x801A49CC
    {
            ctx->lr = 0x80189188u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80189188:
    ctx->downcount -= 1;
    // 80189188: b       0x801892E4
    {
            goto label_801892E4;
    }

label_8018918C:
    ctx->downcount -= 1;
    // 8018918C: bl      0x80173F2C
    {
            ctx->lr = 0x80189190u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80189190:
    ctx->downcount -= 3;
    // 80189190: addi    r25, r3, 0
    ctx->gpr[25] = ctx->gpr[3] + (u32)(s32)(0);

label_80189194:
    // 80189194: addi    r3, r23, 0
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(0);

label_80189198:
    // 80189198: bl      0x801A40FC
    {
            ctx->lr = 0x8018919Cu;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_8018919C:
    ctx->pc = 0x8018919Cu;
    ctx->downcount -= 16;
    // 8018919C: lwz     r6, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801891A0:
    // 801891A0: nor   r8, r23, r23
    {
        ctx->gpr[8] = ~(ctx->gpr[23] | ctx->gpr[23]);
    }

label_801891A4:
    ctx->pc = 0x801891A4u;
    // 801891A4: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801891A8:
    // 801891A8: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_801891AC:
    ctx->pc = 0x801891ACu;
    // 801891AC: lwz     r4, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801891B0:
    ctx->pc = 0x801891B0u;
    // 801891B0: lwz     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801891B4:
    // 801891B4: and   r7, r6, r8
    {
        ctx->gpr[7] = ctx->gpr[6] & ctx->gpr[8];
    }

label_801891B8:
    // 801891B8: and   r6, r5, r8
    {
        ctx->gpr[6] = ctx->gpr[5] & ctx->gpr[8];
    }

label_801891BC:
    ctx->pc = 0x801891BCu;
    // 801891BC: stw     r7, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_801891C0:
    // 801891C0: and   r5, r4, r8
    {
        ctx->gpr[5] = ctx->gpr[4] & ctx->gpr[8];
    }

label_801891C4:
    // 801891C4: and   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[8];
    }

label_801891C8:
    ctx->pc = 0x801891C8u;
    // 801891C8: stw     r6, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801891CC:
    // 801891CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801891D0:
    ctx->pc = 0x801891D0u;
    // 801891D0: stw     r5, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801891D4:
    ctx->pc = 0x801891D4u;
    // 801891D4: stw     r0, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801891D8:
    // 801891D8: bl      0x80177DA4
    {
            ctx->lr = 0x801891DCu;
            ctx->pc = 0x80177DA4u;
            return;
    }

label_801891DC:
    ctx->downcount -= 2;
    // 801891DC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801891E0:
    // 801891E0: bl      0x80173F54
    {
            ctx->lr = 0x801891E4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801891E4:
    ctx->downcount -= 6;
    // 801891E4: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_801891E8:
    ctx->pc = 0x801891E8u;
    // 801891E8: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801891EC:
    // 801891EC: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801891F0:
    // 801891F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801891F4:
    // 801891F4: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_801891F8:
    // 801891F8: bl      0x801698F0
    {
            ctx->lr = 0x801891FCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801891FC:
    ctx->downcount -= 1;
    // 801891FC: b       0x801892E4
    {
            goto label_801892E4;
    }

label_80189200:
    ctx->downcount -= 2;
    // 80189200: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_80189204:
    // 80189204: bl      0x801A4808
    {
            ctx->lr = 0x80189208u;
            ctx->pc = 0x801A4808u;
            return;
    }

label_80189208:
    ctx->downcount -= 2;
    // 80189208: rlwinm. r0, r3, 0, 2, 2
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x20000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018920C:
    // 8018920C: bc    4, 2, 0x80189214
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189214;
        }
    }

label_80189210:
    ctx->downcount -= 1;
    // 80189210: or   r20, r20, r23
    {
        ctx->gpr[20] = ctx->gpr[20] | ctx->gpr[23];
    }

label_80189214:
    ctx->downcount -= 3;
    // 80189214: addi    r3, r21, 0
    ctx->gpr[3] = ctx->gpr[21] + (u32)(s32)(0);

label_80189218:
    // 80189218: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8018921C:
    // 8018921C: bl      0x801A423C
    {
            ctx->lr = 0x80189220u;
            ctx->pc = 0x801A423Cu;
            return;
    }

label_80189220:
    ctx->downcount -= 2;
    // 80189220: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189224:
    // 80189224: bc    4, 2, 0x80189244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189244;
        }
    }

label_80189228:
    ctx->downcount -= 6;
    // 80189228: li      r0, -3
    ctx->gpr[0] = (u32)(s32)(-3);

label_8018922C:
    ctx->pc = 0x8018922Cu;
    // 8018922C: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189230:
    // 80189230: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80189234:
    // 80189234: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80189238:
    // 80189238: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_8018923C:
    // 8018923C: bl      0x801698F0
    {
            ctx->lr = 0x80189240u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80189240:
    ctx->downcount -= 1;
    // 80189240: b       0x801892E4
    {
            goto label_801892E4;
    }

label_80189244:
    ctx->pc = 0x80189244u;
    ctx->downcount -= 3;
    // 80189244: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189248:
    // 80189248: rlwinm. r0, r0, 0, 0, 0
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x80000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018924C:
    // 8018924C: bc    12, 2, 0x8018926C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018926C;
        }
    }

label_80189250:
    ctx->downcount -= 6;
    // 80189250: li      r0, -3
    ctx->gpr[0] = (u32)(s32)(-3);

label_80189254:
    ctx->pc = 0x80189254u;
    // 80189254: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189258:
    // 80189258: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_8018925C:
    // 8018925C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80189260:
    // 80189260: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_80189264:
    // 80189264: bl      0x801698F0
    {
            ctx->lr = 0x80189268u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80189268:
    ctx->downcount -= 1;
    // 80189268: b       0x801892E4
    {
            goto label_801892E4;
    }

label_8018926C:
    ctx->pc = 0x8018926Cu;
    ctx->downcount -= 7;
    // 8018926C: lwz     r12, -28728(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28728);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80189270:
    // 80189270: addi    r3, r21, 0
    ctx->gpr[3] = ctx->gpr[21] + (u32)(s32)(0);

label_80189274:
    // 80189274: addi    r4, r31, 0
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(0);

label_80189278:
    ctx->pc = 0x80189278u;
    // 80189278: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_8018927C:
    // 8018927C: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_80189280:
    ctx->pc = 0x80189280u;
    // 80189280: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80189284u;
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189284:
    ctx->pc = 0x80189284u;
    ctx->downcount -= 3;
    // 80189284: lhz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80189288:
    // 80189288: rlwinm. r0, r0, 0, 18, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00002000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018928C:
    // 8018928C: bc    12, 2, 0x801892D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801892D0;
        }
    }

label_80189290:
    ctx->downcount -= 6;
    // 80189290: li      r0, -3
    ctx->gpr[0] = (u32)(s32)(-3);

label_80189294:
    ctx->pc = 0x80189294u;
    // 80189294: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189298:
    // 80189298: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_8018929C:
    // 8018929C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801892A0:
    // 801892A0: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_801892A4:
    // 801892A4: bl      0x801698F0
    {
            ctx->lr = 0x801892A8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801892A8:
    ctx->downcount -= 9;
    // 801892A8: addi    r3, r21, 0
    ctx->gpr[3] = ctx->gpr[21] + (u32)(s32)(0);

label_801892AC:
    // 801892AC: addi    r6, r24, 0
    ctx->gpr[6] = ctx->gpr[24] + (u32)(s32)(0);

label_801892B0:
    // 801892B0: addi    r8, r30, 0
    ctx->gpr[8] = ctx->gpr[30] + (u32)(s32)(0);

label_801892B4:
    // 801892B4: addi    r4, r13, -28724
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28724);

label_801892B8:
    // 801892B8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801892BC:
    // 801892BC: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_801892C0:
    // 801892C0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801892C4:
    // 801892C4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801892C8:
    // 801892C8: bl      0x801A438C
    {
            ctx->lr = 0x801892CCu;
            ctx->pc = 0x801A438Cu;
            return;
    }

label_801892CC:
    ctx->downcount -= 1;
    // 801892CC: b       0x801892E4
    {
            goto label_801892E4;
    }

label_801892D0:
    ctx->downcount -= 5;
    // 801892D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801892D4:
    ctx->pc = 0x801892D4u;
    // 801892D4: stb     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801892D8:
    ctx->pc = 0x801892D8u;
    // 801892D8: lhz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801892DC:
    // 801892DC: rlwinm r0, r0, 0, 25, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF7Fu;
    }

label_801892E0:
    ctx->pc = 0x801892E0u;
    // 801892E0: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801892E4:
    ctx->downcount -= 5;
    // 801892E4: addi    r21, r21, 1
    ctx->gpr[21] = ctx->gpr[21] + (u32)(s32)(1);

label_801892E8:
    // 801892E8: cmpwi   r21, 4
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801892EC:
    // 801892EC: addi    r24, r24, 12
    ctx->gpr[24] = ctx->gpr[24] + (u32)(s32)(12);

label_801892F0:
    // 801892F0: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801892F4:
    // 801892F4: bc    12, 0, 0x80188FBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80188FBCu;
                return;
            }
            goto label_80188FBC;
        }
    }

label_801892F8:
    ctx->pc = 0x801892F8u;
    ctx->downcount -= 2;
    // 801892F8: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_801892FC:
    ctx->pc = 0x801892FCu;
    // 801892FC: bl      0x80173F54
    {
            ctx->lr = 0x80189300u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80189300:
    ctx->pc = 0x80189300u;
    ctx->downcount -= 17;
    // 80189300: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80189304:
    ctx->pc = 0x80189304u;
    // 80189304: lmw     r20, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 20; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80189308:
    ctx->pc = 0x80189308u;
    // 80189308: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018930C:
    ctx->pc = 0x8018930Cu;
    // 8018930C: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_80189310:
    ctx->pc = 0x80189310u;
    // 80189310: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189314:
    ctx->pc = 0x80189314u;
    // 80189314: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189318:
    ctx->pc = 0x80189318u;
    ctx->downcount -= 4;
    // 80189318: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018931C:
    ctx->pc = 0x8018931Cu;
    // 8018931C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189320:
    ctx->pc = 0x80189320u;
    // 80189320: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189324:
    ctx->pc = 0x80189324u;
    // 80189324: bl      0x801A4DD0
    {
            ctx->lr = 0x80189328u;
            ctx->pc = 0x801A4DD0u;
            return;
    }

label_80189328:
    ctx->pc = 0x80189328u;
    ctx->downcount -= 5;
    // 80189328: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018932C:
    ctx->pc = 0x8018932Cu;
    // 8018932C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80189330:
    ctx->pc = 0x80189330u;
    // 80189330: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189334:
    ctx->pc = 0x80189334u;
    // 80189334: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189338:
    ctx->pc = 0x80189338u;
    ctx->downcount -= 16;
    // 80189338: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018933C:
    ctx->pc = 0x8018933Cu;
    // 8018933C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189340:
    ctx->pc = 0x80189340u;
    // 80189340: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189344:
    ctx->pc = 0x80189344u;
    // 80189344: stmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80189348:
    ctx->pc = 0x80189348u;
    // 80189348: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018934C:
    ctx->pc = 0x8018934Cu;
    // 8018934C: bl      0x80173F2C
    {
            ctx->lr = 0x80189350u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80189350:
    ctx->pc = 0x80189350u;
    ctx->downcount -= 4;
    // 80189350: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80189354:
    ctx->pc = 0x80189354u;
    // 80189354: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80189358:
    ctx->pc = 0x80189358u;
    // 80189358: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8018935C:
    ctx->pc = 0x8018935Cu;
    // 8018935C: lis     r31, -32768
    ctx->gpr[31] = ((u32)(s32)(-32768) << 16);

label_80189360:
    ctx->pc = 0x80189360u;
    ctx->downcount -= 4;
    // 80189360: lwz     r3, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189364:
    // 80189364: srw   r0, r31, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[31] >> sh);
    }

label_80189368:
    // 80189368: and.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018936C:
    // 8018936C: bc    12, 2, 0x801893B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801893B8;
        }
    }

label_80189370:
    ctx->downcount -= 2;
    // 80189370: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80189374:
    // 80189374: bl      0x801A4808
    {
            ctx->lr = 0x80189378u;
            ctx->pc = 0x801A4808u;
            return;
    }

label_80189378:
    ctx->downcount -= 2;
    // 80189378: rlwinm. r0, r3, 0, 2, 2
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x20000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018937C:
    // 8018937C: bc    4, 2, 0x801893B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801893B8;
        }
    }

label_80189380:
    ctx->pc = 0x80189380u;
    ctx->downcount -= 4;
    // 80189380: lwz     r0, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189384:
    ctx->pc = 0x80189384u;
    // 80189384: lwz     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189388:
    // 80189388: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018938C:
    // 8018938C: bc    4, 0, 0x8018939C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018939C;
        }
    }

label_80189390:
    ctx->downcount -= 2;
    // 80189390: cmplwi  r3, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189394:
    // 80189394: bc    4, 2, 0x8018939C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018939C;
        }
    }

label_80189398:
    ctx->downcount -= 1;
    // 80189398: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018939C:
    ctx->pc = 0x8018939Cu;
    ctx->downcount -= 6;
    // 8018939C: lwz     r4, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801893A0:
    // 801893A0: rlwinm r0, r3, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000003u;
    }

label_801893A4:
    // 801893A4: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_801893A8:
    // 801893A8: oris    r4, r4, 0x0040
    ctx->gpr[4] = ctx->gpr[4] | (0x0040u << 16);

label_801893AC:
    // 801893AC: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801893B0:
    // 801893B0: bl      0x801A3FBC
    {
            ctx->lr = 0x801893B4u;
            ctx->pc = 0x801A3FBCu;
            return;
    }

label_801893B4:
    ctx->downcount -= 1;
    // 801893B4: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_801893B8:
    ctx->downcount -= 4;
    // 801893B8: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_801893BC:
    // 801893BC: cmpwi   r29, 4
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801893C0:
    // 801893C0: addi    r27, r27, 4
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(4);

label_801893C4:
    // 801893C4: bc    12, 0, 0x80189360
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80189360u;
                return;
            }
            goto label_80189360;
        }
    }

label_801893C8:
    ctx->pc = 0x801893C8u;
    ctx->downcount -= 2;
    // 801893C8: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801893CC:
    ctx->pc = 0x801893CCu;
    // 801893CC: bc    12, 2, 0x801893D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801893D4;
        }
    }

label_801893D0:
    ctx->pc = 0x801893D0u;
    ctx->downcount -= 1;
    // 801893D0: bl      0x801A3FE4
    {
            ctx->lr = 0x801893D4u;
            ctx->pc = 0x801A3FE4u;
            return;
    }

label_801893D4:
    ctx->pc = 0x801893D4u;
    ctx->downcount -= 2;
    // 801893D4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801893D8:
    ctx->pc = 0x801893D8u;
    // 801893D8: bl      0x80173F54
    {
            ctx->lr = 0x801893DCu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801893DC:
    ctx->pc = 0x801893DCu;
    ctx->downcount -= 16;
    // 801893DC: lmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801893E0:
    ctx->pc = 0x801893E0u;
    // 801893E0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801893E4:
    ctx->pc = 0x801893E4u;
    // 801893E4: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_801893E8:
    ctx->pc = 0x801893E8u;
    // 801893E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801893EC:
    ctx->pc = 0x801893ECu;
    // 801893EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801893F0:
    ctx->pc = 0x801893F0u;
    ctx->downcount -= 9;
    // 801893F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801893F4:
    ctx->pc = 0x801893F4u;
    // 801893F4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801893F8:
    ctx->pc = 0x801893F8u;
    // 801893F8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801893FC:
    ctx->pc = 0x801893FCu;
    // 801893FC: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189400:
    ctx->pc = 0x80189400u;
    // 80189400: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80189404:
    ctx->pc = 0x80189404u;
    // 80189404: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_80189408:
    ctx->pc = 0x80189408u;
    // 80189408: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018940C:
    ctx->pc = 0x8018940Cu;
    // 8018940C: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80189410:
    ctx->pc = 0x80189410u;
    // 80189410: bl      0x80173F2C
    {
            ctx->lr = 0x80189414u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80189414:
    ctx->pc = 0x80189414u;
    ctx->downcount -= 6;
    // 80189414: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80189418:
    ctx->pc = 0x80189418u;
    // 80189418: lwz     r4, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018941C:
    ctx->pc = 0x8018941Cu;
    // 8018941C: srw   r0, r0, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80189420:
    ctx->pc = 0x80189420u;
    // 80189420: and.   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189424:
    ctx->pc = 0x80189424u;
    // 80189424: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_80189428:
    ctx->pc = 0x80189428u;
    // 80189428: bc    12, 2, 0x80189470
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189470;
        }
    }

label_8018942C:
    ctx->pc = 0x8018942Cu;
    ctx->downcount -= 2;
    // 8018942C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80189430:
    ctx->pc = 0x80189430u;
    // 80189430: bl      0x801A4808
    {
            ctx->lr = 0x80189434u;
            ctx->pc = 0x801A4808u;
            return;
    }

label_80189434:
    ctx->pc = 0x80189434u;
    ctx->downcount -= 2;
    // 80189434: rlwinm. r0, r3, 0, 2, 2
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x20000000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189438:
    ctx->pc = 0x80189438u;
    // 80189438: bc    4, 2, 0x80189470
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189470;
        }
    }

label_8018943C:
    ctx->pc = 0x8018943Cu;
    ctx->downcount -= 3;
    // 8018943C: lwz     r0, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189440:
    ctx->pc = 0x80189440u;
    // 80189440: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189444:
    ctx->pc = 0x80189444u;
    // 80189444: bc    4, 0, 0x80189454
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189454;
        }
    }

label_80189448:
    ctx->pc = 0x80189448u;
    ctx->downcount -= 2;
    // 80189448: cmplwi  r30, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018944C:
    ctx->pc = 0x8018944Cu;
    // 8018944C: bc    4, 2, 0x80189454
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189454;
        }
    }

label_80189450:
    ctx->pc = 0x80189450u;
    ctx->downcount -= 1;
    // 80189450: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80189454:
    ctx->pc = 0x80189454u;
    ctx->downcount -= 6;
    // 80189454: lwz     r4, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80189458:
    ctx->pc = 0x80189458u;
    // 80189458: rlwinm r0, r30, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x00000003u;
    }

label_8018945C:
    ctx->pc = 0x8018945Cu;
    // 8018945C: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80189460:
    ctx->pc = 0x80189460u;
    // 80189460: oris    r4, r4, 0x0040
    ctx->gpr[4] = ctx->gpr[4] | (0x0040u << 16);

label_80189464:
    ctx->pc = 0x80189464u;
    // 80189464: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80189468:
    ctx->pc = 0x80189468u;
    // 80189468: bl      0x801A3FBC
    {
            ctx->lr = 0x8018946Cu;
            ctx->pc = 0x801A3FBCu;
            return;
    }

label_8018946C:
    ctx->pc = 0x8018946Cu;
    ctx->downcount -= 1;
    // 8018946C: bl      0x801A3FE4
    {
            ctx->lr = 0x80189470u;
            ctx->pc = 0x801A3FE4u;
            return;
    }

label_80189470:
    ctx->pc = 0x80189470u;
    ctx->downcount -= 2;
    // 80189470: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80189474:
    ctx->pc = 0x80189474u;
    // 80189474: bl      0x80173F54
    {
            ctx->lr = 0x80189478u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80189478:
    ctx->pc = 0x80189478u;
    ctx->downcount -= 8;
    // 80189478: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018947C:
    ctx->pc = 0x8018947Cu;
    // 8018947C: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189480:
    ctx->pc = 0x80189480u;
    // 80189480: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80189484:
    ctx->pc = 0x80189484u;
    // 80189484: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80189488:
    ctx->pc = 0x80189488u;
    // 80189488: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8018948C:
    ctx->pc = 0x8018948Cu;
    // 8018948C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189490:
    ctx->pc = 0x80189490u;
    // 80189490: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189494:
    ctx->pc = 0x80189494u;
    ctx->downcount -= 4;
    // 80189494: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80189498:
    ctx->pc = 0x80189498u;
    // 80189498: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018949C:
    ctx->pc = 0x8018949Cu;
    // 8018949C: stw     r0, -26376(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26376);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801894A0:
    ctx->pc = 0x801894A0u;
    // 801894A0: bc    12, 2, 0x801894D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801894D0;
        }
    }

label_801894A4:
    ctx->pc = 0x801894A4u;
    ctx->downcount -= 1;
    // 801894A4: bc    4, 0, 0x801894B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801894B4;
        }
    }

label_801894A8:
    ctx->pc = 0x801894A8u;
    ctx->downcount -= 2;
    // 801894A8: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801894AC:
    ctx->pc = 0x801894ACu;
    // 801894AC: bc    4, 0, 0x801894C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801894C0;
        }
    }

label_801894B0:
    ctx->pc = 0x801894B0u;
    ctx->downcount -= 1;
    // 801894B0: b       0x801894EC
    {
            goto label_801894EC;
    }

label_801894B4:
    ctx->pc = 0x801894B4u;
    ctx->downcount -= 2;
    // 801894B4: cmpwi   r3, 6
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801894B8:
    ctx->pc = 0x801894B8u;
    // 801894B8: bc    4, 0, 0x801894EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801894EC;
        }
    }

label_801894BC:
    ctx->pc = 0x801894BCu;
    ctx->downcount -= 1;
    // 801894BC: b       0x801894E0
    {
            goto label_801894E0;
    }

label_801894C0:
    ctx->pc = 0x801894C0u;
    ctx->downcount -= 4;
    // 801894C0: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801894C4:
    ctx->pc = 0x801894C4u;
    // 801894C4: addi    r0, r4, -27396
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-27396);

label_801894C8:
    ctx->pc = 0x801894C8u;
    // 801894C8: stw     r0, -28728(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28728);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801894CC:
    ctx->pc = 0x801894CCu;
    // 801894CC: b       0x801894EC
    {
            goto label_801894EC;
    }

label_801894D0:
    ctx->pc = 0x801894D0u;
    ctx->downcount -= 4;
    // 801894D0: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801894D4:
    ctx->pc = 0x801894D4u;
    // 801894D4: addi    r0, r4, -27024
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-27024);

label_801894D8:
    ctx->pc = 0x801894D8u;
    // 801894D8: stw     r0, -28728(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28728);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801894DC:
    ctx->pc = 0x801894DCu;
    // 801894DC: b       0x801894EC
    {
            goto label_801894EC;
    }

label_801894E0:
    ctx->pc = 0x801894E0u;
    ctx->downcount -= 3;
    // 801894E0: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_801894E4:
    ctx->pc = 0x801894E4u;
    // 801894E4: addi    r0, r4, -26540
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-26540);

label_801894E8:
    ctx->pc = 0x801894E8u;
    // 801894E8: stw     r0, -28728(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28728);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801894EC:
    ctx->pc = 0x801894ECu;
    ctx->downcount -= 2;
    // 801894EC: stw     r3, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801894F0:
    ctx->pc = 0x801894F0u;
    // 801894F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801894F4:
    ctx->pc = 0x801894F4u;
    ctx->downcount -= 2;
    // 801894F4: lwz     r3, -28732(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28732);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801894F8:
    ctx->pc = 0x801894F8u;
    // 801894F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801894FC:
    ctx->pc = 0x801894FCu;
    ctx->downcount -= 5;
    // 801894FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189500:
    ctx->pc = 0x80189500u;
    // 80189500: sth     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80189504:
    ctx->pc = 0x80189504u;
    // 80189504: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189508:
    ctx->pc = 0x80189508u;
    // 80189508: rlwinm. r0, r0, 16, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018950C:
    ctx->pc = 0x8018950Cu;
    // 8018950C: bc    12, 2, 0x80189514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189514;
        }
    }

label_80189510:
    ctx->pc = 0x80189510u;
    ctx->downcount -= 1;
    // 80189510: li      r3, 256
    ctx->gpr[3] = (u32)(s32)(256);

label_80189514:
    ctx->pc = 0x80189514u;
    ctx->downcount -= 6;
    // 80189514: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80189518:
    ctx->pc = 0x80189518u;
    // 80189518: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_8018951C:
    ctx->pc = 0x8018951Cu;
    // 8018951C: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189520:
    ctx->pc = 0x80189520u;
    // 80189520: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189524:
    ctx->pc = 0x80189524u;
    // 80189524: rlwinm. r0, r0, 16, 26, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000020u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189528:
    ctx->pc = 0x80189528u;
    // 80189528: bc    12, 2, 0x80189534
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189534;
        }
    }

label_8018952C:
    ctx->pc = 0x8018952Cu;
    ctx->downcount -= 2;
    // 8018952C: li      r3, 512
    ctx->gpr[3] = (u32)(s32)(512);

label_80189530:
    ctx->pc = 0x80189530u;
    // 80189530: b       0x80189538
    {
            goto label_80189538;
    }

label_80189534:
    ctx->pc = 0x80189534u;
    ctx->downcount -= 1;
    // 80189534: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189538:
    ctx->pc = 0x80189538u;
    ctx->downcount -= 6;
    // 80189538: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018953C:
    ctx->pc = 0x8018953Cu;
    // 8018953C: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_80189540:
    ctx->pc = 0x80189540u;
    // 80189540: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189544:
    ctx->pc = 0x80189544u;
    // 80189544: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189548:
    ctx->pc = 0x80189548u;
    // 80189548: rlwinm. r0, r0, 16, 23, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000100u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018954C:
    ctx->pc = 0x8018954Cu;
    // 8018954C: bc    12, 2, 0x80189558
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189558;
        }
    }

label_80189550:
    ctx->pc = 0x80189550u;
    ctx->downcount -= 2;
    // 80189550: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_80189554:
    ctx->pc = 0x80189554u;
    // 80189554: b       0x8018955C
    {
            goto label_8018955C;
    }

label_80189558:
    ctx->pc = 0x80189558u;
    ctx->downcount -= 1;
    // 80189558: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018955C:
    ctx->pc = 0x8018955Cu;
    ctx->downcount -= 6;
    // 8018955C: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80189560:
    ctx->pc = 0x80189560u;
    // 80189560: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_80189564:
    ctx->pc = 0x80189564u;
    // 80189564: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189568:
    ctx->pc = 0x80189568u;
    // 80189568: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018956C:
    ctx->pc = 0x8018956Cu;
    // 8018956C: rlwinm. r0, r0, 16, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189570:
    ctx->pc = 0x80189570u;
    // 80189570: bc    12, 2, 0x8018957C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018957C;
        }
    }

label_80189574:
    ctx->pc = 0x80189574u;
    ctx->downcount -= 2;
    // 80189574: li      r3, 2048
    ctx->gpr[3] = (u32)(s32)(2048);

label_80189578:
    ctx->pc = 0x80189578u;
    // 80189578: b       0x80189580
    {
            goto label_80189580;
    }

label_8018957C:
    ctx->pc = 0x8018957Cu;
    ctx->downcount -= 1;
    // 8018957C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189580:
    ctx->pc = 0x80189580u;
    ctx->downcount -= 6;
    // 80189580: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80189584:
    ctx->pc = 0x80189584u;
    // 80189584: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_80189588:
    ctx->pc = 0x80189588u;
    // 80189588: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018958C:
    ctx->pc = 0x8018958Cu;
    // 8018958C: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189590:
    ctx->pc = 0x80189590u;
    // 80189590: rlwinm. r0, r0, 16, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189594:
    ctx->pc = 0x80189594u;
    // 80189594: bc    12, 2, 0x801895A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801895A0;
        }
    }

label_80189598:
    ctx->pc = 0x80189598u;
    ctx->downcount -= 2;
    // 80189598: li      r6, 4096
    ctx->gpr[6] = (u32)(s32)(4096);

label_8018959C:
    ctx->pc = 0x8018959Cu;
    // 8018959C: b       0x801895A4
    {
            goto label_801895A4;
    }

label_801895A0:
    ctx->pc = 0x801895A0u;
    ctx->downcount -= 1;
    // 801895A0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801895A4:
    ctx->pc = 0x801895A4u;
    ctx->downcount -= 29;
    // 801895A4: lhz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801895A8:
    ctx->pc = 0x801895A8u;
    // 801895A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801895AC:
    ctx->pc = 0x801895ACu;
    // 801895AC: or   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[6];
    }

label_801895B0:
    ctx->pc = 0x801895B0u;
    // 801895B0: sth     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801895B4:
    ctx->pc = 0x801895B4u;
    // 801895B4: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801895B8:
    ctx->pc = 0x801895B8u;
    // 801895B8: rlwinm r3, r3, 16, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_801895BC:
    ctx->pc = 0x801895BCu;
    // 801895BC: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_801895C0:
    ctx->pc = 0x801895C0u;
    // 801895C0: stb     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_801895C4:
    ctx->pc = 0x801895C4u;
    // 801895C4: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801895C8:
    ctx->pc = 0x801895C8u;
    // 801895C8: rlwinm r3, r3, 8, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x000000FFu;
    }

label_801895CC:
    ctx->pc = 0x801895CCu;
    // 801895CC: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_801895D0:
    ctx->pc = 0x801895D0u;
    // 801895D0: stb     r3, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_801895D4:
    ctx->pc = 0x801895D4u;
    // 801895D4: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801895D8:
    ctx->pc = 0x801895D8u;
    // 801895D8: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_801895DC:
    ctx->pc = 0x801895DCu;
    // 801895DC: stb     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_801895E0:
    ctx->pc = 0x801895E0u;
    // 801895E0: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801895E4:
    ctx->pc = 0x801895E4u;
    // 801895E4: rlwinm r3, r3, 24, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 24u) & 0x00FFFFFFu;
    }

label_801895E8:
    ctx->pc = 0x801895E8u;
    // 801895E8: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_801895EC:
    ctx->pc = 0x801895ECu;
    // 801895EC: stb     r3, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_801895F0:
    ctx->pc = 0x801895F0u;
    // 801895F0: lwz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801895F4:
    ctx->pc = 0x801895F4u;
    // 801895F4: rlwinm r3, r3, 24, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 24u) & 0x000000FFu;
    }

label_801895F8:
    ctx->pc = 0x801895F8u;
    // 801895F8: stb     r3, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_801895FC:
    ctx->pc = 0x801895FCu;
    // 801895FC: lwz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189600:
    ctx->pc = 0x80189600u;
    // 80189600: stb     r3, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189604:
    ctx->pc = 0x80189604u;
    // 80189604: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189608:
    ctx->pc = 0x80189608u;
    // 80189608: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018960C:
    ctx->pc = 0x8018960Cu;
    // 8018960C: lbz     r0, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80189610:
    ctx->pc = 0x80189610u;
    // 80189610: cmplwi  r0, 0x00AA
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00AAu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189614:
    ctx->pc = 0x80189614u;
    // 80189614: bc    12, 0, 0x80189624
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189624;
        }
    }

label_80189618:
    ctx->pc = 0x80189618u;
    ctx->downcount -= 3;
    // 80189618: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018961C:
    ctx->pc = 0x8018961Cu;
    // 8018961C: ori     r0, r0, 0x0040
    ctx->gpr[0] = ctx->gpr[0] | 0x0040u;

label_80189620:
    ctx->pc = 0x80189620u;
    // 80189620: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189624:
    ctx->pc = 0x80189624u;
    ctx->downcount -= 3;
    // 80189624: lbz     r0, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80189628:
    ctx->pc = 0x80189628u;
    // 80189628: cmplwi  r0, 0x00AA
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00AAu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018962C:
    ctx->pc = 0x8018962Cu;
    // 8018962C: bc    12, 0, 0x8018963C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018963C;
        }
    }

label_80189630:
    ctx->pc = 0x80189630u;
    ctx->downcount -= 3;
    // 80189630: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80189634:
    ctx->pc = 0x80189634u;
    // 80189634: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_80189638:
    ctx->pc = 0x80189638u;
    // 80189638: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018963C:
    ctx->pc = 0x8018963Cu;
    ctx->downcount -= 13;
    // 8018963C: lbz     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80189640:
    ctx->pc = 0x80189640u;
    // 80189640: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_80189644:
    ctx->pc = 0x80189644u;
    // 80189644: stb     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189648:
    ctx->pc = 0x80189648u;
    // 80189648: lbz     r3, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8018964C:
    ctx->pc = 0x8018964Cu;
    // 8018964C: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_80189650:
    ctx->pc = 0x80189650u;
    // 80189650: stb     r0, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189654:
    ctx->pc = 0x80189654u;
    // 80189654: lbz     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80189658:
    ctx->pc = 0x80189658u;
    // 80189658: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_8018965C:
    ctx->pc = 0x8018965Cu;
    // 8018965C: stb     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189660:
    ctx->pc = 0x80189660u;
    // 80189660: lbz     r3, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80189664:
    ctx->pc = 0x80189664u;
    // 80189664: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_80189668:
    ctx->pc = 0x80189668u;
    // 80189668: stb     r0, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018966C:
    ctx->pc = 0x8018966Cu;
    // 8018966C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189670:
    ctx->pc = 0x80189670u;
    ctx->downcount -= 5;
    // 80189670: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189674:
    ctx->pc = 0x80189674u;
    // 80189674: sth     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80189678:
    ctx->pc = 0x80189678u;
    // 80189678: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018967C:
    ctx->pc = 0x8018967Cu;
    // 8018967C: rlwinm. r0, r0, 16, 24, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000080u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189680:
    ctx->pc = 0x80189680u;
    // 80189680: bc    12, 2, 0x80189688
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189688;
        }
    }

label_80189684:
    ctx->pc = 0x80189684u;
    ctx->downcount -= 1;
    // 80189684: li      r3, 256
    ctx->gpr[3] = (u32)(s32)(256);

label_80189688:
    ctx->pc = 0x80189688u;
    ctx->downcount -= 6;
    // 80189688: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018968C:
    ctx->pc = 0x8018968Cu;
    // 8018968C: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_80189690:
    ctx->pc = 0x80189690u;
    // 80189690: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189694:
    ctx->pc = 0x80189694u;
    // 80189694: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189698:
    ctx->pc = 0x80189698u;
    // 80189698: rlwinm. r0, r0, 16, 23, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000100u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018969C:
    ctx->pc = 0x8018969Cu;
    // 8018969C: bc    12, 2, 0x801896A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801896A8;
        }
    }

label_801896A0:
    ctx->pc = 0x801896A0u;
    ctx->downcount -= 2;
    // 801896A0: li      r3, 512
    ctx->gpr[3] = (u32)(s32)(512);

label_801896A4:
    ctx->pc = 0x801896A4u;
    // 801896A4: b       0x801896AC
    {
            goto label_801896AC;
    }

label_801896A8:
    ctx->pc = 0x801896A8u;
    ctx->downcount -= 1;
    // 801896A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801896AC:
    ctx->pc = 0x801896ACu;
    ctx->downcount -= 6;
    // 801896AC: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801896B0:
    ctx->pc = 0x801896B0u;
    // 801896B0: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_801896B4:
    ctx->pc = 0x801896B4u;
    // 801896B4: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801896B8:
    ctx->pc = 0x801896B8u;
    // 801896B8: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801896BC:
    ctx->pc = 0x801896BCu;
    // 801896BC: rlwinm. r0, r0, 16, 26, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000020u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801896C0:
    ctx->pc = 0x801896C0u;
    // 801896C0: bc    12, 2, 0x801896CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801896CC;
        }
    }

label_801896C4:
    ctx->pc = 0x801896C4u;
    ctx->downcount -= 2;
    // 801896C4: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_801896C8:
    ctx->pc = 0x801896C8u;
    // 801896C8: b       0x801896D0
    {
            goto label_801896D0;
    }

label_801896CC:
    ctx->pc = 0x801896CCu;
    ctx->downcount -= 1;
    // 801896CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801896D0:
    ctx->pc = 0x801896D0u;
    ctx->downcount -= 6;
    // 801896D0: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801896D4:
    ctx->pc = 0x801896D4u;
    // 801896D4: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_801896D8:
    ctx->pc = 0x801896D8u;
    // 801896D8: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801896DC:
    ctx->pc = 0x801896DCu;
    // 801896DC: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801896E0:
    ctx->pc = 0x801896E0u;
    // 801896E0: rlwinm. r0, r0, 16, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801896E4:
    ctx->pc = 0x801896E4u;
    // 801896E4: bc    12, 2, 0x801896F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801896F0;
        }
    }

label_801896E8:
    ctx->pc = 0x801896E8u;
    ctx->downcount -= 2;
    // 801896E8: li      r3, 2048
    ctx->gpr[3] = (u32)(s32)(2048);

label_801896EC:
    ctx->pc = 0x801896ECu;
    // 801896EC: b       0x801896F4
    {
            goto label_801896F4;
    }

label_801896F0:
    ctx->pc = 0x801896F0u;
    ctx->downcount -= 1;
    // 801896F0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801896F4:
    ctx->pc = 0x801896F4u;
    ctx->downcount -= 6;
    // 801896F4: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801896F8:
    ctx->pc = 0x801896F8u;
    // 801896F8: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_801896FC:
    ctx->pc = 0x801896FCu;
    // 801896FC: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189700:
    ctx->pc = 0x80189700u;
    // 80189700: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189704:
    ctx->pc = 0x80189704u;
    // 80189704: rlwinm. r0, r0, 16, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189708:
    ctx->pc = 0x80189708u;
    // 80189708: bc    12, 2, 0x80189714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189714;
        }
    }

label_8018970C:
    ctx->pc = 0x8018970Cu;
    ctx->downcount -= 2;
    // 8018970C: li      r6, 4096
    ctx->gpr[6] = (u32)(s32)(4096);

label_80189710:
    ctx->pc = 0x80189710u;
    // 80189710: b       0x80189718
    {
            goto label_80189718;
    }

label_80189714:
    ctx->pc = 0x80189714u;
    ctx->downcount -= 1;
    // 80189714: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80189718:
    ctx->pc = 0x80189718u;
    ctx->downcount -= 29;
    // 80189718: lhz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018971C:
    ctx->pc = 0x8018971Cu;
    // 8018971C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80189720:
    ctx->pc = 0x80189720u;
    // 80189720: or   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[6];
    }

label_80189724:
    ctx->pc = 0x80189724u;
    // 80189724: sth     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80189728:
    ctx->pc = 0x80189728u;
    // 80189728: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018972C:
    ctx->pc = 0x8018972Cu;
    // 8018972C: rlwinm r3, r3, 16, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_80189730:
    ctx->pc = 0x80189730u;
    // 80189730: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_80189734:
    ctx->pc = 0x80189734u;
    // 80189734: stb     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189738:
    ctx->pc = 0x80189738u;
    // 80189738: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018973C:
    ctx->pc = 0x8018973Cu;
    // 8018973C: rlwinm r3, r3, 8, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x000000FFu;
    }

label_80189740:
    ctx->pc = 0x80189740u;
    // 80189740: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_80189744:
    ctx->pc = 0x80189744u;
    // 80189744: stb     r3, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189748:
    ctx->pc = 0x80189748u;
    // 80189748: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018974C:
    ctx->pc = 0x8018974Cu;
    // 8018974C: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_80189750:
    ctx->pc = 0x80189750u;
    // 80189750: stb     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189754:
    ctx->pc = 0x80189754u;
    // 80189754: lwz     r3, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189758:
    ctx->pc = 0x80189758u;
    // 80189758: rlwinm r3, r3, 24, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 24u) & 0x00FFFFFFu;
    }

label_8018975C:
    ctx->pc = 0x8018975Cu;
    // 8018975C: extsb r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_80189760:
    ctx->pc = 0x80189760u;
    // 80189760: stb     r3, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189764:
    ctx->pc = 0x80189764u;
    // 80189764: lwz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189768:
    ctx->pc = 0x80189768u;
    // 80189768: rlwinm r3, r3, 24, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 24u) & 0x000000FFu;
    }

label_8018976C:
    ctx->pc = 0x8018976Cu;
    // 8018976C: stb     r3, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189770:
    ctx->pc = 0x80189770u;
    // 80189770: lwz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189774:
    ctx->pc = 0x80189774u;
    // 80189774: stb     r3, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189778:
    ctx->pc = 0x80189778u;
    // 80189778: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018977C:
    ctx->pc = 0x8018977Cu;
    // 8018977C: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189780:
    ctx->pc = 0x80189780u;
    // 80189780: lbz     r0, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80189784:
    ctx->pc = 0x80189784u;
    // 80189784: cmplwi  r0, 0x00AA
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00AAu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189788:
    ctx->pc = 0x80189788u;
    // 80189788: bc    12, 0, 0x80189798
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189798;
        }
    }

label_8018978C:
    ctx->pc = 0x8018978Cu;
    ctx->downcount -= 3;
    // 8018978C: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80189790:
    ctx->pc = 0x80189790u;
    // 80189790: ori     r0, r0, 0x0040
    ctx->gpr[0] = ctx->gpr[0] | 0x0040u;

label_80189794:
    ctx->pc = 0x80189794u;
    // 80189794: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189798:
    ctx->pc = 0x80189798u;
    ctx->downcount -= 3;
    // 80189798: lbz     r0, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018979C:
    ctx->pc = 0x8018979Cu;
    // 8018979C: cmplwi  r0, 0x00AA
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00AAu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801897A0:
    ctx->pc = 0x801897A0u;
    // 801897A0: bc    12, 0, 0x801897B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801897B0;
        }
    }

label_801897A4:
    ctx->pc = 0x801897A4u;
    ctx->downcount -= 3;
    // 801897A4: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801897A8:
    ctx->pc = 0x801897A8u;
    // 801897A8: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_801897AC:
    ctx->pc = 0x801897ACu;
    // 801897AC: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801897B0:
    ctx->pc = 0x801897B0u;
    ctx->downcount -= 13;
    // 801897B0: lbz     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_801897B4:
    ctx->pc = 0x801897B4u;
    // 801897B4: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_801897B8:
    ctx->pc = 0x801897B8u;
    // 801897B8: stb     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801897BC:
    ctx->pc = 0x801897BCu;
    // 801897BC: lbz     r3, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_801897C0:
    ctx->pc = 0x801897C0u;
    // 801897C0: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_801897C4:
    ctx->pc = 0x801897C4u;
    // 801897C4: stb     r0, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801897C8:
    ctx->pc = 0x801897C8u;
    // 801897C8: lbz     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_801897CC:
    ctx->pc = 0x801897CCu;
    // 801897CC: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_801897D0:
    ctx->pc = 0x801897D0u;
    // 801897D0: stb     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801897D4:
    ctx->pc = 0x801897D4u;
    // 801897D4: lbz     r3, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_801897D8:
    ctx->pc = 0x801897D8u;
    // 801897D8: addi    r0, r3, -128
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-128);

label_801897DC:
    ctx->pc = 0x801897DCu;
    // 801897DC: stb     r0, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801897E0:
    ctx->pc = 0x801897E0u;
    // 801897E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_801897E4:
    ctx->pc = 0x801897E4u;
    ctx->downcount -= 2;
    // 801897E4: extsb. r0, r4
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801897E8:
    ctx->pc = 0x801897E8u;
    // 801897E8: bc    4, 1, 0x8018980C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018980C;
        }
    }

label_801897EC:
    ctx->pc = 0x801897ECu;
    ctx->downcount -= 6;
    // 801897EC: extsb r5, r4
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_801897F0:
    ctx->pc = 0x801897F0u;
    // 801897F0: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_801897F4:
    ctx->pc = 0x801897F4u;
    // 801897F4: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_801897F8:
    ctx->pc = 0x801897F8u;
    // 801897F8: extsb r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_801897FC:
    ctx->pc = 0x801897FCu;
    // 801897FC: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189800:
    ctx->pc = 0x80189800u;
    // 80189800: bc    4, 0, 0x80189830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189830;
        }
    }

label_80189804:
    ctx->pc = 0x80189804u;
    ctx->downcount -= 2;
    // 80189804: or   r3, r5, r5
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189808:
    ctx->pc = 0x80189808u;
    // 80189808: b       0x80189830
    {
            goto label_80189830;
    }

label_8018980C:
    ctx->pc = 0x8018980Cu;
    ctx->downcount -= 2;
    // 8018980C: extsb. r0, r4
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189810:
    ctx->pc = 0x80189810u;
    // 80189810: bc    4, 0, 0x80189830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189830;
        }
    }

label_80189814:
    ctx->pc = 0x80189814u;
    ctx->downcount -= 6;
    // 80189814: extsb r5, r4
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_80189818:
    ctx->pc = 0x80189818u;
    // 80189818: addi    r0, r5, 127
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(127);

label_8018981C:
    ctx->pc = 0x8018981Cu;
    // 8018981C: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189820:
    ctx->pc = 0x80189820u;
    // 80189820: extsb r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_80189824:
    ctx->pc = 0x80189824u;
    // 80189824: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189828:
    ctx->pc = 0x80189828u;
    // 80189828: bc    4, 0, 0x80189830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189830;
        }
    }

label_8018982C:
    ctx->pc = 0x8018982Cu;
    ctx->downcount -= 1;
    // 8018982C: or   r3, r5, r5
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189830:
    ctx->pc = 0x80189830u;
    ctx->downcount -= 2;
    // 80189830: subf   r3, r4, r3
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80189834:
    ctx->pc = 0x80189834u;
    // 80189834: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189838:
    ctx->pc = 0x80189838u;
    ctx->downcount -= 4;
    // 80189838: rlwinm r5, r3, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8018983C:
    ctx->pc = 0x8018983Cu;
    // 8018983C: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_80189840:
    ctx->pc = 0x80189840u;
    // 80189840: cmplw   r5, r0
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189844:
    ctx->pc = 0x80189844u;
    // 80189844: bc    4, 0, 0x8018984C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018984C;
        }
    }

label_80189848:
    ctx->pc = 0x80189848u;
    ctx->downcount -= 1;
    // 80189848: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8018984C:
    ctx->pc = 0x8018984Cu;
    ctx->downcount -= 2;
    // 8018984C: subf   r3, r4, r3
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80189850:
    ctx->pc = 0x80189850u;
    // 80189850: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189854:
    ctx->pc = 0x80189854u;
    ctx->downcount -= 14;
    // 80189854: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189858:
    ctx->pc = 0x80189858u;
    // 80189858: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_8018985C:
    ctx->pc = 0x8018985Cu;
    // 8018985C: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80189860:
    ctx->pc = 0x80189860u;
    // 80189860: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189864:
    ctx->pc = 0x80189864u;
    // 80189864: rlwinm r0, r0, 24, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00FFFFFFu;
    }

label_80189868:
    ctx->pc = 0x80189868u;
    // 80189868: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8018986C:
    ctx->pc = 0x8018986Cu;
    // 8018986C: stb     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189870:
    ctx->pc = 0x80189870u;
    // 80189870: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189874:
    ctx->pc = 0x80189874u;
    // 80189874: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189878:
    ctx->pc = 0x80189878u;
    // 80189878: stb     r0, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018987C:
    ctx->pc = 0x8018987Cu;
    // 8018987C: lwz     r0, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189880:
    ctx->pc = 0x80189880u;
    // 80189880: rlwinm r0, r0, 0, 21, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000700u;
    }

label_80189884:
    ctx->pc = 0x80189884u;
    // 80189884: cmpwi   r0, 1024
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1024);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189888:
    ctx->pc = 0x80189888u;
    // 80189888: bc    12, 2, 0x80189A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189A20;
        }
    }

label_8018988C:
    ctx->pc = 0x8018988Cu;
    ctx->downcount -= 1;
    // 8018988C: bc    4, 0, 0x801898C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801898C0;
        }
    }

label_80189890:
    ctx->pc = 0x80189890u;
    ctx->downcount -= 2;
    // 80189890: cmpwi   r0, 512
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(512);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189894:
    ctx->pc = 0x80189894u;
    // 80189894: bc    12, 2, 0x8018998C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018998C;
        }
    }

label_80189898:
    ctx->pc = 0x80189898u;
    ctx->downcount -= 1;
    // 80189898: bc    4, 0, 0x801898B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801898B4;
        }
    }

label_8018989C:
    ctx->pc = 0x8018989Cu;
    ctx->downcount -= 2;
    // 8018989C: cmpwi   r0, 256
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801898A0:
    ctx->pc = 0x801898A0u;
    // 801898A0: bc    12, 2, 0x80189938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189938;
        }
    }

label_801898A4:
    ctx->pc = 0x801898A4u;
    ctx->downcount -= 1;
    // 801898A4: bc    4, 0, 0x80189A60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189A60;
        }
    }

label_801898A8:
    ctx->pc = 0x801898A8u;
    ctx->downcount -= 2;
    // 801898A8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801898AC:
    ctx->pc = 0x801898ACu;
    // 801898AC: bc    12, 2, 0x801898E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801898E4;
        }
    }

label_801898B0:
    ctx->pc = 0x801898B0u;
    ctx->downcount -= 1;
    // 801898B0: b       0x80189A60
    {
            goto label_80189A60;
    }

label_801898B4:
    ctx->pc = 0x801898B4u;
    ctx->downcount -= 2;
    // 801898B4: cmpwi   r0, 768
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(768);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801898B8:
    ctx->pc = 0x801898B8u;
    // 801898B8: bc    12, 2, 0x801899DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801899DC;
        }
    }

label_801898BC:
    ctx->pc = 0x801898BCu;
    ctx->downcount -= 1;
    // 801898BC: b       0x80189A60
    {
            goto label_80189A60;
    }

label_801898C0:
    ctx->pc = 0x801898C0u;
    ctx->downcount -= 2;
    // 801898C0: cmpwi   r0, 1536
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1536);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801898C4:
    ctx->pc = 0x801898C4u;
    // 801898C4: bc    12, 2, 0x801898E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801898E4;
        }
    }

label_801898C8:
    ctx->pc = 0x801898C8u;
    ctx->downcount -= 1;
    // 801898C8: bc    4, 0, 0x801898D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801898D8;
        }
    }

label_801898CC:
    ctx->pc = 0x801898CCu;
    ctx->downcount -= 2;
    // 801898CC: cmpwi   r0, 1280
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1280);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801898D0:
    ctx->pc = 0x801898D0u;
    // 801898D0: bc    12, 2, 0x801898E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801898E4;
        }
    }

label_801898D4:
    ctx->pc = 0x801898D4u;
    ctx->downcount -= 1;
    // 801898D4: b       0x80189A60
    {
            goto label_80189A60;
    }

label_801898D8:
    ctx->pc = 0x801898D8u;
    ctx->downcount -= 2;
    // 801898D8: cmpwi   r0, 1792
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1792);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801898DC:
    ctx->pc = 0x801898DCu;
    // 801898DC: bc    12, 2, 0x801898E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801898E4;
        }
    }

label_801898E0:
    ctx->pc = 0x801898E0u;
    ctx->downcount -= 1;
    // 801898E0: b       0x80189A60
    {
            goto label_80189A60;
    }

label_801898E4:
    ctx->pc = 0x801898E4u;
    ctx->downcount -= 21;
    // 801898E4: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801898E8:
    ctx->pc = 0x801898E8u;
    // 801898E8: rlwinm r0, r0, 8, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x000000FFu;
    }

label_801898EC:
    ctx->pc = 0x801898ECu;
    // 801898EC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_801898F0:
    ctx->pc = 0x801898F0u;
    // 801898F0: stb     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801898F4:
    ctx->pc = 0x801898F4u;
    // 801898F4: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801898F8:
    ctx->pc = 0x801898F8u;
    // 801898F8: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_801898FC:
    ctx->pc = 0x801898FCu;
    // 801898FC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189900:
    ctx->pc = 0x80189900u;
    // 80189900: stb     r0, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189904:
    ctx->pc = 0x80189904u;
    // 80189904: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189908:
    ctx->pc = 0x80189908u;
    // 80189908: rlwinm r0, r0, 24, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x000000F0u;
    }

label_8018990C:
    ctx->pc = 0x8018990Cu;
    // 8018990C: stb     r0, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189910:
    ctx->pc = 0x80189910u;
    // 80189910: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189914:
    ctx->pc = 0x80189914u;
    // 80189914: rlwinm r0, r0, 28, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x000000F0u;
    }

label_80189918:
    ctx->pc = 0x80189918u;
    // 80189918: stb     r0, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018991C:
    ctx->pc = 0x8018991Cu;
    // 8018991C: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189920:
    ctx->pc = 0x80189920u;
    // 80189920: rlwinm r0, r0, 0, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000F0u;
    }

label_80189924:
    ctx->pc = 0x80189924u;
    // 80189924: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189928:
    ctx->pc = 0x80189928u;
    // 80189928: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018992C:
    ctx->pc = 0x8018992Cu;
    // 8018992C: rlwinm r0, r0, 4, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0x000000F0u;
    }

label_80189930:
    ctx->pc = 0x80189930u;
    // 80189930: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189934:
    ctx->pc = 0x80189934u;
    // 80189934: b       0x80189A60
    {
            goto label_80189A60;
    }

label_80189938:
    ctx->pc = 0x80189938u;
    ctx->downcount -= 21;
    // 80189938: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018993C:
    ctx->pc = 0x8018993Cu;
    // 8018993C: rlwinm r0, r0, 8, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x000000F0u;
    }

label_80189940:
    ctx->pc = 0x80189940u;
    // 80189940: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189944:
    ctx->pc = 0x80189944u;
    // 80189944: stb     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189948:
    ctx->pc = 0x80189948u;
    // 80189948: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018994C:
    ctx->pc = 0x8018994Cu;
    // 8018994C: rlwinm r0, r0, 12, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0x000000F0u;
    }

label_80189950:
    ctx->pc = 0x80189950u;
    // 80189950: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189954:
    ctx->pc = 0x80189954u;
    // 80189954: stb     r0, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189958:
    ctx->pc = 0x80189958u;
    // 80189958: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018995C:
    ctx->pc = 0x8018995Cu;
    // 8018995C: rlwinm r0, r0, 16, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x000000FFu;
    }

label_80189960:
    ctx->pc = 0x80189960u;
    // 80189960: stb     r0, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189964:
    ctx->pc = 0x80189964u;
    // 80189964: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189968:
    ctx->pc = 0x80189968u;
    // 80189968: rlwinm r0, r0, 24, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x000000FFu;
    }

label_8018996C:
    ctx->pc = 0x8018996Cu;
    // 8018996C: stb     r0, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189970:
    ctx->pc = 0x80189970u;
    // 80189970: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189974:
    ctx->pc = 0x80189974u;
    // 80189974: rlwinm r0, r0, 0, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000F0u;
    }

label_80189978:
    ctx->pc = 0x80189978u;
    // 80189978: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018997C:
    ctx->pc = 0x8018997Cu;
    // 8018997C: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189980:
    ctx->pc = 0x80189980u;
    // 80189980: rlwinm r0, r0, 4, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0x000000F0u;
    }

label_80189984:
    ctx->pc = 0x80189984u;
    // 80189984: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189988:
    ctx->pc = 0x80189988u;
    // 80189988: b       0x80189A60
    {
            goto label_80189A60;
    }

label_8018998C:
    ctx->pc = 0x8018998Cu;
    ctx->downcount -= 20;
    // 8018998C: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189990:
    ctx->pc = 0x80189990u;
    // 80189990: rlwinm r0, r0, 8, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x000000F0u;
    }

label_80189994:
    ctx->pc = 0x80189994u;
    // 80189994: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189998:
    ctx->pc = 0x80189998u;
    // 80189998: stb     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018999C:
    ctx->pc = 0x8018999Cu;
    // 8018999C: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801899A0:
    ctx->pc = 0x801899A0u;
    // 801899A0: rlwinm r0, r0, 12, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0x000000F0u;
    }

label_801899A4:
    ctx->pc = 0x801899A4u;
    // 801899A4: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_801899A8:
    ctx->pc = 0x801899A8u;
    // 801899A8: stb     r0, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801899AC:
    ctx->pc = 0x801899ACu;
    // 801899AC: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801899B0:
    ctx->pc = 0x801899B0u;
    // 801899B0: rlwinm r0, r0, 16, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x000000F0u;
    }

label_801899B4:
    ctx->pc = 0x801899B4u;
    // 801899B4: stb     r0, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801899B8:
    ctx->pc = 0x801899B8u;
    // 801899B8: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801899BC:
    ctx->pc = 0x801899BCu;
    // 801899BC: rlwinm r0, r0, 20, 24, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 20u) & 0x000000F0u;
    }

label_801899C0:
    ctx->pc = 0x801899C0u;
    // 801899C0: stb     r0, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801899C4:
    ctx->pc = 0x801899C4u;
    // 801899C4: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801899C8:
    ctx->pc = 0x801899C8u;
    // 801899C8: rlwinm r0, r0, 24, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x000000FFu;
    }

label_801899CC:
    ctx->pc = 0x801899CCu;
    // 801899CC: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801899D0:
    ctx->pc = 0x801899D0u;
    // 801899D0: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801899D4:
    ctx->pc = 0x801899D4u;
    // 801899D4: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801899D8:
    ctx->pc = 0x801899D8u;
    // 801899D8: b       0x80189A60
    {
            goto label_80189A60;
    }

label_801899DC:
    ctx->pc = 0x801899DCu;
    ctx->downcount -= 17;
    // 801899DC: lwz     r6, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801899E0:
    ctx->pc = 0x801899E0u;
    // 801899E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801899E4:
    ctx->pc = 0x801899E4u;
    // 801899E4: rlwinm r6, r6, 8, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0x000000FFu;
    }

label_801899E8:
    ctx->pc = 0x801899E8u;
    // 801899E8: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_801899EC:
    ctx->pc = 0x801899ECu;
    // 801899EC: stb     r6, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_801899F0:
    ctx->pc = 0x801899F0u;
    // 801899F0: lwz     r6, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801899F4:
    ctx->pc = 0x801899F4u;
    // 801899F4: rlwinm r6, r6, 16, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 16u) & 0x0000FFFFu;
    }

label_801899F8:
    ctx->pc = 0x801899F8u;
    // 801899F8: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_801899FC:
    ctx->pc = 0x801899FCu;
    // 801899FC: stb     r6, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189A00:
    ctx->pc = 0x80189A00u;
    // 80189A00: lwz     r6, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80189A04:
    ctx->pc = 0x80189A04u;
    // 80189A04: rlwinm r6, r6, 24, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0x000000FFu;
    }

label_80189A08:
    ctx->pc = 0x80189A08u;
    // 80189A08: stb     r6, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189A0C:
    ctx->pc = 0x80189A0Cu;
    // 80189A0C: lwz     r5, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80189A10:
    ctx->pc = 0x80189A10u;
    // 80189A10: stb     r5, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80189A14:
    ctx->pc = 0x80189A14u;
    // 80189A14: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A18:
    ctx->pc = 0x80189A18u;
    // 80189A18: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A1C:
    ctx->pc = 0x80189A1Cu;
    // 80189A1C: b       0x80189A60
    {
            goto label_80189A60;
    }

label_80189A20:
    ctx->pc = 0x80189A20u;
    ctx->downcount -= 16;
    // 80189A20: lwz     r6, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80189A24:
    ctx->pc = 0x80189A24u;
    // 80189A24: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80189A28:
    ctx->pc = 0x80189A28u;
    // 80189A28: rlwinm r6, r6, 8, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0x000000FFu;
    }

label_80189A2C:
    ctx->pc = 0x80189A2Cu;
    // 80189A2C: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189A30:
    ctx->pc = 0x80189A30u;
    // 80189A30: stb     r6, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189A34:
    ctx->pc = 0x80189A34u;
    // 80189A34: lwz     r6, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80189A38:
    ctx->pc = 0x80189A38u;
    // 80189A38: rlwinm r6, r6, 16, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 16u) & 0x0000FFFFu;
    }

label_80189A3C:
    ctx->pc = 0x80189A3Cu;
    // 80189A3C: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189A40:
    ctx->pc = 0x80189A40u;
    // 80189A40: stb     r6, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189A44:
    ctx->pc = 0x80189A44u;
    // 80189A44: stb     r0, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A48:
    ctx->pc = 0x80189A48u;
    // 80189A48: stb     r0, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A4C:
    ctx->pc = 0x80189A4Cu;
    // 80189A4C: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189A50:
    ctx->pc = 0x80189A50u;
    // 80189A50: rlwinm r0, r0, 24, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x000000FFu;
    }

label_80189A54:
    ctx->pc = 0x80189A54u;
    // 80189A54: stb     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A58:
    ctx->pc = 0x80189A58u;
    // 80189A58: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189A5C:
    ctx->pc = 0x80189A5Cu;
    // 80189A5C: stb     r0, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A60:
    ctx->pc = 0x80189A60u;
    ctx->downcount -= 22;
    // 80189A60: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80189A64:
    ctx->pc = 0x80189A64u;
    // 80189A64: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

label_80189A68:
    ctx->pc = 0x80189A68u;
    // 80189A68: mulli   r3, r3, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)12);

label_80189A6C:
    ctx->pc = 0x80189A6Cu;
    // 80189A6C: addi    r0, r6, -128
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-128);

label_80189A70:
    ctx->pc = 0x80189A70u;
    // 80189A70: stb     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A74:
    ctx->pc = 0x80189A74u;
    // 80189A74: addi    r0, r5, 2872
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(2872);

label_80189A78:
    ctx->pc = 0x80189A78u;
    // 80189A78: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80189A7C:
    ctx->pc = 0x80189A7Cu;
    // 80189A7C: lbz     r5, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80189A80:
    ctx->pc = 0x80189A80u;
    // 80189A80: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189A84:
    ctx->pc = 0x80189A84u;
    // 80189A84: stb     r0, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A88:
    ctx->pc = 0x80189A88u;
    // 80189A88: lbz     r5, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80189A8C:
    ctx->pc = 0x80189A8Cu;
    // 80189A8C: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189A90:
    ctx->pc = 0x80189A90u;
    // 80189A90: stb     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189A94:
    ctx->pc = 0x80189A94u;
    // 80189A94: lbz     r5, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80189A98:
    ctx->pc = 0x80189A98u;
    // 80189A98: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189A9C:
    ctx->pc = 0x80189A9Cu;
    // 80189A9C: stb     r0, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80189AA0:
    ctx->pc = 0x80189AA0u;
    // 80189AA0: lbz     r7, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80189AA4:
    ctx->pc = 0x80189AA4u;
    // 80189AA4: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80189AA8:
    ctx->pc = 0x80189AA8u;
    // 80189AA8: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189AAC:
    ctx->pc = 0x80189AACu;
    // 80189AAC: bc    4, 1, 0x80189AD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189AD0;
        }
    }

label_80189AB0:
    ctx->pc = 0x80189AB0u;
    ctx->downcount -= 6;
    // 80189AB0: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189AB4:
    ctx->pc = 0x80189AB4u;
    // 80189AB4: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189AB8:
    ctx->pc = 0x80189AB8u;
    // 80189AB8: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189ABC:
    ctx->pc = 0x80189ABCu;
    // 80189ABC: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189AC0:
    ctx->pc = 0x80189AC0u;
    // 80189AC0: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189AC4:
    ctx->pc = 0x80189AC4u;
    // 80189AC4: bc    4, 0, 0x80189AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189AF4;
        }
    }

label_80189AC8:
    ctx->pc = 0x80189AC8u;
    ctx->downcount -= 2;
    // 80189AC8: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189ACC:
    ctx->pc = 0x80189ACCu;
    // 80189ACC: b       0x80189AF4
    {
            goto label_80189AF4;
    }

label_80189AD0:
    ctx->pc = 0x80189AD0u;
    ctx->downcount -= 2;
    // 80189AD0: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189AD4:
    ctx->pc = 0x80189AD4u;
    // 80189AD4: bc    4, 0, 0x80189AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189AF4;
        }
    }

label_80189AD8:
    ctx->pc = 0x80189AD8u;
    ctx->downcount -= 6;
    // 80189AD8: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189ADC:
    ctx->pc = 0x80189ADCu;
    // 80189ADC: addi    r0, r5, 127
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(127);

label_80189AE0:
    ctx->pc = 0x80189AE0u;
    // 80189AE0: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189AE4:
    ctx->pc = 0x80189AE4u;
    // 80189AE4: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189AE8:
    ctx->pc = 0x80189AE8u;
    // 80189AE8: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189AEC:
    ctx->pc = 0x80189AECu;
    // 80189AEC: bc    4, 0, 0x80189AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189AF4;
        }
    }

label_80189AF0:
    ctx->pc = 0x80189AF0u;
    ctx->downcount -= 1;
    // 80189AF0: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189AF4:
    ctx->pc = 0x80189AF4u;
    ctx->downcount -= 6;
    // 80189AF4: subf   r6, r7, r6
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80189AF8:
    ctx->pc = 0x80189AF8u;
    // 80189AF8: stb     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189AFC:
    ctx->pc = 0x80189AFCu;
    // 80189AFC: lbz     r7, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80189B00:
    ctx->pc = 0x80189B00u;
    // 80189B00: lbz     r6, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80189B04:
    ctx->pc = 0x80189B04u;
    // 80189B04: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189B08:
    ctx->pc = 0x80189B08u;
    // 80189B08: bc    4, 1, 0x80189B2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189B2C;
        }
    }

label_80189B0C:
    ctx->pc = 0x80189B0Cu;
    ctx->downcount -= 6;
    // 80189B0C: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189B10:
    ctx->pc = 0x80189B10u;
    // 80189B10: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189B14:
    ctx->pc = 0x80189B14u;
    // 80189B14: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189B18:
    ctx->pc = 0x80189B18u;
    // 80189B18: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189B1C:
    ctx->pc = 0x80189B1Cu;
    // 80189B1C: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189B20:
    ctx->pc = 0x80189B20u;
    // 80189B20: bc    4, 0, 0x80189B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189B50;
        }
    }

label_80189B24:
    ctx->pc = 0x80189B24u;
    ctx->downcount -= 2;
    // 80189B24: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189B28:
    ctx->pc = 0x80189B28u;
    // 80189B28: b       0x80189B50
    {
            goto label_80189B50;
    }

label_80189B2C:
    ctx->pc = 0x80189B2Cu;
    ctx->downcount -= 2;
    // 80189B2C: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189B30:
    ctx->pc = 0x80189B30u;
    // 80189B30: bc    4, 0, 0x80189B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189B50;
        }
    }

label_80189B34:
    ctx->pc = 0x80189B34u;
    ctx->downcount -= 6;
    // 80189B34: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189B38:
    ctx->pc = 0x80189B38u;
    // 80189B38: addi    r0, r5, 127
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(127);

label_80189B3C:
    ctx->pc = 0x80189B3Cu;
    // 80189B3C: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189B40:
    ctx->pc = 0x80189B40u;
    // 80189B40: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189B44:
    ctx->pc = 0x80189B44u;
    // 80189B44: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189B48:
    ctx->pc = 0x80189B48u;
    // 80189B48: bc    4, 0, 0x80189B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189B50;
        }
    }

label_80189B4C:
    ctx->pc = 0x80189B4Cu;
    ctx->downcount -= 1;
    // 80189B4C: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189B50:
    ctx->pc = 0x80189B50u;
    ctx->downcount -= 6;
    // 80189B50: subf   r6, r7, r6
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80189B54:
    ctx->pc = 0x80189B54u;
    // 80189B54: stb     r6, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189B58:
    ctx->pc = 0x80189B58u;
    // 80189B58: lbz     r7, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80189B5C:
    ctx->pc = 0x80189B5Cu;
    // 80189B5C: lbz     r6, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80189B60:
    ctx->pc = 0x80189B60u;
    // 80189B60: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189B64:
    ctx->pc = 0x80189B64u;
    // 80189B64: bc    4, 1, 0x80189B88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189B88;
        }
    }

label_80189B68:
    ctx->pc = 0x80189B68u;
    ctx->downcount -= 6;
    // 80189B68: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189B6C:
    ctx->pc = 0x80189B6Cu;
    // 80189B6C: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189B70:
    ctx->pc = 0x80189B70u;
    // 80189B70: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189B74:
    ctx->pc = 0x80189B74u;
    // 80189B74: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189B78:
    ctx->pc = 0x80189B78u;
    // 80189B78: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189B7C:
    ctx->pc = 0x80189B7Cu;
    // 80189B7C: bc    4, 0, 0x80189BAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189BAC;
        }
    }

label_80189B80:
    ctx->pc = 0x80189B80u;
    ctx->downcount -= 2;
    // 80189B80: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189B84:
    ctx->pc = 0x80189B84u;
    // 80189B84: b       0x80189BAC
    {
            goto label_80189BAC;
    }

label_80189B88:
    ctx->pc = 0x80189B88u;
    ctx->downcount -= 2;
    // 80189B88: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189B8C:
    ctx->pc = 0x80189B8Cu;
    // 80189B8C: bc    4, 0, 0x80189BAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189BAC;
        }
    }

label_80189B90:
    ctx->pc = 0x80189B90u;
    ctx->downcount -= 6;
    // 80189B90: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189B94:
    ctx->pc = 0x80189B94u;
    // 80189B94: addi    r0, r5, 127
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(127);

label_80189B98:
    ctx->pc = 0x80189B98u;
    // 80189B98: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189B9C:
    ctx->pc = 0x80189B9Cu;
    // 80189B9C: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189BA0:
    ctx->pc = 0x80189BA0u;
    // 80189BA0: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189BA4:
    ctx->pc = 0x80189BA4u;
    // 80189BA4: bc    4, 0, 0x80189BAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189BAC;
        }
    }

label_80189BA8:
    ctx->pc = 0x80189BA8u;
    ctx->downcount -= 1;
    // 80189BA8: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189BAC:
    ctx->pc = 0x80189BACu;
    ctx->downcount -= 6;
    // 80189BAC: subf   r6, r7, r6
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80189BB0:
    ctx->pc = 0x80189BB0u;
    // 80189BB0: stb     r6, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189BB4:
    ctx->pc = 0x80189BB4u;
    // 80189BB4: lbz     r7, 5(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(5);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80189BB8:
    ctx->pc = 0x80189BB8u;
    // 80189BB8: lbz     r6, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80189BBC:
    ctx->pc = 0x80189BBCu;
    // 80189BBC: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189BC0:
    ctx->pc = 0x80189BC0u;
    // 80189BC0: bc    4, 1, 0x80189BE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189BE4;
        }
    }

label_80189BC4:
    ctx->pc = 0x80189BC4u;
    ctx->downcount -= 6;
    // 80189BC4: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189BC8:
    ctx->pc = 0x80189BC8u;
    // 80189BC8: addi    r0, r5, -128
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-128);

label_80189BCC:
    ctx->pc = 0x80189BCCu;
    // 80189BCC: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189BD0:
    ctx->pc = 0x80189BD0u;
    // 80189BD0: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189BD4:
    ctx->pc = 0x80189BD4u;
    // 80189BD4: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189BD8:
    ctx->pc = 0x80189BD8u;
    // 80189BD8: bc    4, 0, 0x80189C08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189C08;
        }
    }

label_80189BDC:
    ctx->pc = 0x80189BDCu;
    ctx->downcount -= 2;
    // 80189BDC: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189BE0:
    ctx->pc = 0x80189BE0u;
    // 80189BE0: b       0x80189C08
    {
            goto label_80189C08;
    }

label_80189BE4:
    ctx->pc = 0x80189BE4u;
    ctx->downcount -= 2;
    // 80189BE4: extsb. r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189BE8:
    ctx->pc = 0x80189BE8u;
    // 80189BE8: bc    4, 0, 0x80189C08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189C08;
        }
    }

label_80189BEC:
    ctx->pc = 0x80189BECu;
    ctx->downcount -= 6;
    // 80189BEC: extsb r5, r7
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80189BF0:
    ctx->pc = 0x80189BF0u;
    // 80189BF0: addi    r0, r5, 127
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(127);

label_80189BF4:
    ctx->pc = 0x80189BF4u;
    // 80189BF4: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80189BF8:
    ctx->pc = 0x80189BF8u;
    // 80189BF8: extsb r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80189BFC:
    ctx->pc = 0x80189BFCu;
    // 80189BFC: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189C00:
    ctx->pc = 0x80189C00u;
    // 80189C00: bc    4, 0, 0x80189C08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189C08;
        }
    }

label_80189C04:
    ctx->pc = 0x80189C04u;
    ctx->downcount -= 1;
    // 80189C04: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80189C08:
    ctx->pc = 0x80189C08u;
    ctx->downcount -= 6;
    // 80189C08: subf   r6, r7, r6
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80189C0C:
    ctx->pc = 0x80189C0Cu;
    // 80189C0C: stb     r6, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80189C10:
    ctx->pc = 0x80189C10u;
    // 80189C10: lbz     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80189C14:
    ctx->pc = 0x80189C14u;
    // 80189C14: lbz     r5, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80189C18:
    ctx->pc = 0x80189C18u;
    // 80189C18: cmplw   r5, r0
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189C1C:
    ctx->pc = 0x80189C1Cu;
    // 80189C1C: bc    4, 0, 0x80189C24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189C24;
        }
    }

label_80189C20:
    ctx->pc = 0x80189C20u;
    ctx->downcount -= 1;
    // 80189C20: or   r5, r0, r0
    {
        ctx->gpr[5] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80189C24:
    ctx->pc = 0x80189C24u;
    ctx->downcount -= 6;
    // 80189C24: subf   r5, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_80189C28:
    ctx->pc = 0x80189C28u;
    // 80189C28: stb     r5, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80189C2C:
    ctx->pc = 0x80189C2Cu;
    // 80189C2C: lbz     r0, 7(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(7);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80189C30:
    ctx->pc = 0x80189C30u;
    // 80189C30: lbz     r3, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80189C34:
    ctx->pc = 0x80189C34u;
    // 80189C34: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189C38:
    ctx->pc = 0x80189C38u;
    // 80189C38: bc    4, 0, 0x80189C40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189C40;
        }
    }

label_80189C3C:
    ctx->pc = 0x80189C3Cu;
    ctx->downcount -= 1;
    // 80189C3C: or   r3, r0, r0
    {
        ctx->gpr[3] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80189C40:
    ctx->pc = 0x80189C40u;
    ctx->downcount -= 3;
    // 80189C40: subf   r3, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80189C44:
    ctx->pc = 0x80189C44u;
    // 80189C44: stb     r3, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80189C48:
    ctx->pc = 0x80189C48u;
    // 80189C48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189C4C:
    ctx->pc = 0x80189C4Cu;
    ctx->downcount -= 8;
    // 80189C4C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189C50:
    ctx->pc = 0x80189C50u;
    // 80189C50: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189C54:
    ctx->pc = 0x80189C54u;
    // 80189C54: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189C58:
    ctx->pc = 0x80189C58u;
    // 80189C58: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189C5C:
    ctx->pc = 0x80189C5Cu;
    // 80189C5C: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80189C60:
    ctx->pc = 0x80189C60u;
    // 80189C60: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80189C64:
    ctx->pc = 0x80189C64u;
    // 80189C64: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80189C68:
    ctx->pc = 0x80189C68u;
    // 80189C68: bl      0x801A4808
    {
            ctx->lr = 0x80189C6Cu;
            ctx->pc = 0x801A4808u;
            return;
    }

label_80189C6C:
    ctx->pc = 0x80189C6Cu;
    ctx->downcount -= 6;
    // 80189C6C: stw     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80189C70:
    ctx->pc = 0x80189C70u;
    // 80189C70: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80189C74:
    ctx->pc = 0x80189C74u;
    // 80189C74: srw   r3, r0, r30
    {
        u32 sh = ctx->gpr[30] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80189C78:
    ctx->pc = 0x80189C78u;
    // 80189C78: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189C7C:
    ctx->pc = 0x80189C7Cu;
    // 80189C7C: and.   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189C80:
    ctx->pc = 0x80189C80u;
    // 80189C80: bc    4, 2, 0x80189C9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189C9C;
        }
    }

label_80189C84:
    ctx->pc = 0x80189C84u;
    ctx->downcount -= 3;
    // 80189C84: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189C88:
    ctx->pc = 0x80189C88u;
    // 80189C88: cmpw    r0, r30
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189C8C:
    ctx->pc = 0x80189C8Cu;
    // 80189C8C: bc    12, 2, 0x80189C9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189C9C;
        }
    }

label_80189C90:
    ctx->pc = 0x80189C90u;
    ctx->downcount -= 3;
    // 80189C90: lwz     r0, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189C94:
    ctx->pc = 0x80189C94u;
    // 80189C94: and.   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189C98:
    ctx->pc = 0x80189C98u;
    // 80189C98: bc    4, 2, 0x80189CA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189CA4;
        }
    }

label_80189C9C:
    ctx->pc = 0x80189C9Cu;
    ctx->downcount -= 2;
    // 80189C9C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189CA0:
    ctx->pc = 0x80189CA0u;
    // 80189CA0: b       0x80189CA8
    {
            goto label_80189CA8;
    }

label_80189CA4:
    ctx->pc = 0x80189CA4u;
    ctx->downcount -= 1;
    // 80189CA4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80189CA8:
    ctx->pc = 0x80189CA8u;
    ctx->downcount -= 7;
    // 80189CA8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189CAC:
    ctx->pc = 0x80189CACu;
    // 80189CAC: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189CB0:
    ctx->pc = 0x80189CB0u;
    // 80189CB0: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80189CB4:
    ctx->pc = 0x80189CB4u;
    // 80189CB4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80189CB8:
    ctx->pc = 0x80189CB8u;
    // 80189CB8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189CBC:
    ctx->pc = 0x80189CBCu;
    // 80189CBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189CC0:
    ctx->pc = 0x80189CC0u;
    ctx->downcount -= 9;
    // 80189CC0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189CC4:
    ctx->pc = 0x80189CC4u;
    // 80189CC4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189CC8:
    ctx->pc = 0x80189CC8u;
    // 80189CC8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189CCC:
    ctx->pc = 0x80189CCCu;
    // 80189CCC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189CD0:
    ctx->pc = 0x80189CD0u;
    // 80189CD0: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80189CD4:
    ctx->pc = 0x80189CD4u;
    // 80189CD4: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80189CD8:
    ctx->pc = 0x80189CD8u;
    // 80189CD8: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189CDC:
    ctx->pc = 0x80189CDCu;
    // 80189CDC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189CE0:
    ctx->pc = 0x80189CE0u;
    // 80189CE0: bc    4, 2, 0x80189CF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189CF4;
        }
    }

label_80189CE4:
    ctx->pc = 0x80189CE4u;
    ctx->downcount -= 3;
    // 80189CE4: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189CE8:
    ctx->pc = 0x80189CE8u;
    // 80189CE8: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189CEC:
    ctx->pc = 0x80189CECu;
    // 80189CEC: bc    4, 2, 0x80189CF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189CF4;
        }
    }

label_80189CF0:
    ctx->pc = 0x80189CF0u;
    ctx->downcount -= 1;
    // 80189CF0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80189CF4:
    ctx->pc = 0x80189CF4u;
    ctx->downcount -= 2;
    // 80189CF4: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189CF8:
    ctx->pc = 0x80189CF8u;
    // 80189CF8: bc    12, 2, 0x80189D0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189D0C;
        }
    }

label_80189CFC:
    ctx->pc = 0x80189CFCu;
    ctx->downcount -= 1;
    // 80189CFC: bl      0x801A3188
    {
            ctx->lr = 0x80189D00u;
            ctx->pc = 0x801A3188u;
            return;
    }

label_80189D00:
    ctx->pc = 0x80189D00u;
    ctx->downcount -= 2;
    // 80189D00: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189D04:
    ctx->pc = 0x80189D04u;
    // 80189D04: bc    4, 2, 0x80189D0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189D0C;
        }
    }

label_80189D08:
    ctx->pc = 0x80189D08u;
    ctx->downcount -= 1;
    // 80189D08: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_80189D0C:
    ctx->pc = 0x80189D0Cu;
    ctx->downcount -= 7;
    // 80189D0C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80189D10:
    ctx->pc = 0x80189D10u;
    // 80189D10: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189D14:
    ctx->pc = 0x80189D14u;
    // 80189D14: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189D18:
    ctx->pc = 0x80189D18u;
    // 80189D18: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80189D1C:
    ctx->pc = 0x80189D1Cu;
    // 80189D1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189D20:
    ctx->pc = 0x80189D20u;
    // 80189D20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189D24:
    ctx->pc = 0x80189D24u;
    ctx->downcount -= 6;
    // 80189D24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189D28:
    ctx->pc = 0x80189D28u;
    // 80189D28: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189D2C:
    ctx->pc = 0x80189D2Cu;
    // 80189D2C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189D30:
    ctx->pc = 0x80189D30u;
    // 80189D30: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189D34:
    ctx->pc = 0x80189D34u;
    // 80189D34: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80189D38:
    ctx->pc = 0x80189D38u;
    // 80189D38: bl      0x80173F2C
    {
            ctx->lr = 0x80189D3Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80189D3C:
    ctx->pc = 0x80189D3Cu;
    ctx->downcount -= 16;
    // 80189D3C: lwz     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80189D40:
    ctx->pc = 0x80189D40u;
    // 80189D40: rlwinm r6, r31, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_80189D44:
    ctx->pc = 0x80189D44u;
    // 80189D44: lwz     r4, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80189D48:
    ctx->pc = 0x80189D48u;
    // 80189D48: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80189D4C:
    ctx->pc = 0x80189D4Cu;
    // 80189D4C: addi    r8, r5, 0
    ctx->gpr[8] = ctx->gpr[5] + (u32)(s32)(0);

label_80189D50:
    ctx->pc = 0x80189D50u;
    // 80189D50: nor   r7, r8, r8
    {
        ctx->gpr[7] = ~(ctx->gpr[8] | ctx->gpr[8]);
    }

label_80189D54:
    ctx->pc = 0x80189D54u;
    // 80189D54: lwz     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189D58:
    ctx->pc = 0x80189D58u;
    // 80189D58: andc   r5, r5, r5
    {
        ctx->gpr[5] = ctx->gpr[5] & ~ctx->gpr[5];
    }

label_80189D5C:
    ctx->pc = 0x80189D5Cu;
    // 80189D5C: stw     r6, -28736(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28736);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80189D60:
    ctx->pc = 0x80189D60u;
    // 80189D60: and   r4, r4, r7
    {
        ctx->gpr[4] = ctx->gpr[4] & ctx->gpr[7];
    }

label_80189D64:
    ctx->pc = 0x80189D64u;
    // 80189D64: and   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[7];
    }

label_80189D68:
    ctx->pc = 0x80189D68u;
    // 80189D68: stw     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80189D6C:
    ctx->pc = 0x80189D6Cu;
    // 80189D6C: or   r3, r8, r8
    {
        ctx->gpr[3] = ctx->gpr[8] | ctx->gpr[8];
    }

label_80189D70:
    ctx->pc = 0x80189D70u;
    // 80189D70: stw     r4, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80189D74:
    ctx->pc = 0x80189D74u;
    // 80189D74: stw     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189D78:
    ctx->pc = 0x80189D78u;
    // 80189D78: bl      0x801A40FC
    {
            ctx->lr = 0x80189D7Cu;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80189D7C:
    ctx->pc = 0x80189D7Cu;
    ctx->downcount -= 2;
    // 80189D7C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80189D80:
    ctx->pc = 0x80189D80u;
    // 80189D80: bl      0x80173F54
    {
            ctx->lr = 0x80189D84u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80189D84:
    ctx->pc = 0x80189D84u;
    ctx->downcount -= 6;
    // 80189D84: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189D88:
    ctx->pc = 0x80189D88u;
    // 80189D88: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189D8C:
    ctx->pc = 0x80189D8Cu;
    // 80189D8C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80189D90:
    ctx->pc = 0x80189D90u;
    // 80189D90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189D94:
    ctx->pc = 0x80189D94u;
    // 80189D94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189D98:
    ctx->pc = 0x80189D98u;
    ctx->downcount -= 9;
    // 80189D98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189D9C:
    ctx->pc = 0x80189D9Cu;
    // 80189D9C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189DA0:
    ctx->pc = 0x80189DA0u;
    // 80189DA0: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189DA4:
    ctx->pc = 0x80189DA4u;
    // 80189DA4: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189DA8:
    ctx->pc = 0x80189DA8u;
    // 80189DA8: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80189DAC:
    ctx->pc = 0x80189DACu;
    // 80189DAC: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80189DB0:
    ctx->pc = 0x80189DB0u;
    // 80189DB0: lwz     r0, -26384(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26384);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189DB4:
    ctx->pc = 0x80189DB4u;
    // 80189DB4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189DB8:
    ctx->pc = 0x80189DB8u;
    // 80189DB8: bc    12, 2, 0x80189DC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189DC4;
        }
    }

label_80189DBC:
    ctx->pc = 0x80189DBCu;
    ctx->downcount -= 2;
    // 80189DBC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189DC0:
    ctx->pc = 0x80189DC0u;
    // 80189DC0: bl      0x80189F98
    {
            ctx->lr = 0x80189DC4u;
            goto label_80189F98;
    }

label_80189DC4:
    ctx->pc = 0x80189DC4u;
    ctx->downcount -= 2;
    // 80189DC4: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189DC8:
    ctx->pc = 0x80189DC8u;
    // 80189DC8: bc    4, 2, 0x80189F08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189F08;
        }
    }

label_80189DCC:
    ctx->pc = 0x80189DCCu;
    ctx->downcount -= 5;
    // 80189DCC: lwz     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189DD0:
    ctx->pc = 0x80189DD0u;
    // 80189DD0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80189DD4:
    ctx->pc = 0x80189DD4u;
    // 80189DD4: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_80189DD8:
    ctx->pc = 0x80189DD8u;
    // 80189DD8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189DDC:
    ctx->pc = 0x80189DDCu;
    // 80189DDC: bc    4, 2, 0x80189DF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189DF0;
        }
    }

label_80189DE0:
    ctx->pc = 0x80189DE0u;
    ctx->downcount -= 3;
    // 80189DE0: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189DE4:
    ctx->pc = 0x80189DE4u;
    // 80189DE4: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189DE8:
    ctx->pc = 0x80189DE8u;
    // 80189DE8: bc    4, 2, 0x80189DF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189DF0;
        }
    }

label_80189DEC:
    ctx->pc = 0x80189DECu;
    ctx->downcount -= 1;
    // 80189DEC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80189DF0:
    ctx->pc = 0x80189DF0u;
    ctx->downcount -= 2;
    // 80189DF0: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189DF4:
    ctx->pc = 0x80189DF4u;
    // 80189DF4: bc    12, 2, 0x80189E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189E08;
        }
    }

label_80189DF8:
    ctx->pc = 0x80189DF8u;
    ctx->downcount -= 1;
    // 80189DF8: bl      0x801A3188
    {
            ctx->lr = 0x80189DFCu;
            ctx->pc = 0x801A3188u;
            return;
    }

label_80189DFC:
    ctx->pc = 0x80189DFCu;
    ctx->downcount -= 2;
    // 80189DFC: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189E00:
    ctx->pc = 0x80189E00u;
    // 80189E00: bc    4, 2, 0x80189E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189E08;
        }
    }

label_80189E04:
    ctx->pc = 0x80189E04u;
    ctx->downcount -= 1;
    // 80189E04: li      r30, 1
    ctx->gpr[30] = (u32)(s32)(1);

label_80189E08:
    ctx->pc = 0x80189E08u;
    ctx->downcount -= 3;
    // 80189E08: lwz     r0, -26380(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26380);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189E0C:
    ctx->pc = 0x80189E0Cu;
    // 80189E0C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189E10:
    ctx->pc = 0x80189E10u;
    // 80189E10: bc    4, 2, 0x80189F00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189F00;
        }
    }

label_80189E14:
    ctx->pc = 0x80189E14u;
    ctx->downcount -= 2;
    // 80189E14: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189E18:
    ctx->pc = 0x80189E18u;
    // 80189E18: bc    12, 2, 0x80189F00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189F00;
        }
    }

label_80189E1C:
    ctx->pc = 0x80189E1Cu;
    ctx->downcount -= 2;
    // 80189E1C: lis     r30, -4096
    ctx->gpr[30] = ((u32)(s32)(-4096) << 16);

label_80189E20:
    ctx->pc = 0x80189E20u;
    // 80189E20: bl      0x80173F2C
    {
            ctx->lr = 0x80189E24u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80189E24:
    ctx->pc = 0x80189E24u;
    ctx->downcount -= 21;
    // 80189E24: lwz     r6, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80189E28:
    ctx->pc = 0x80189E28u;
    // 80189E28: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80189E2C:
    ctx->pc = 0x80189E2Cu;
    // 80189E2C: lwz     r5, -26400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26400);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80189E30:
    ctx->pc = 0x80189E30u;
    // 80189E30: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80189E34:
    ctx->pc = 0x80189E34u;
    // 80189E34: lwz     r0, -26396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189E38:
    ctx->pc = 0x80189E38u;
    // 80189E38: or   r30, r30, r6
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[6];
    }

label_80189E3C:
    ctx->pc = 0x80189E3Cu;
    // 80189E3C: lwz     r6, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80189E40:
    ctx->pc = 0x80189E40u;
    // 80189E40: or   r5, r5, r0
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80189E44:
    ctx->pc = 0x80189E44u;
    // 80189E44: lbz     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80189E48:
    ctx->pc = 0x80189E48u;
    // 80189E48: andc   r30, r30, r5
    {
        ctx->gpr[30] = ctx->gpr[30] & ~ctx->gpr[5];
    }

label_80189E4C:
    ctx->pc = 0x80189E4Cu;
    // 80189E4C: lwz     r5, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80189E50:
    ctx->pc = 0x80189E50u;
    // 80189E50: or   r4, r6, r30
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[30];
    }

label_80189E54:
    ctx->pc = 0x80189E54u;
    // 80189E54: stw     r7, -26392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26392);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80189E58:
    ctx->pc = 0x80189E58u;
    // 80189E58: rlwinm. r0, r0, 0, 25, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000040u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80189E5C:
    ctx->pc = 0x80189E5Cu;
    // 80189E5C: stw     r4, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80189E60:
    ctx->pc = 0x80189E60u;
    // 80189E60: andc   r4, r5, r30
    {
        ctx->gpr[4] = ctx->gpr[5] & ~ctx->gpr[30];
    }

label_80189E64:
    ctx->pc = 0x80189E64u;
    // 80189E64: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_80189E68:
    ctx->pc = 0x80189E68u;
    // 80189E68: lwz     r6, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80189E6C:
    ctx->pc = 0x80189E6Cu;
    // 80189E6C: stw     r4, -26412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26412);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80189E70:
    ctx->pc = 0x80189E70u;
    // 80189E70: and   r3, r6, r5
    {
        ctx->gpr[3] = ctx->gpr[6] & ctx->gpr[5];
    }

label_80189E74:
    ctx->pc = 0x80189E74u;
    // 80189E74: bc    4, 2, 0x80189E84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189E84;
        }
    }

label_80189E78:
    ctx->pc = 0x80189E78u;
    ctx->downcount -= 3;
    // 80189E78: lwz     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189E7C:
    ctx->pc = 0x80189E7Cu;
    // 80189E7C: or   r0, r0, r30
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[30];
    }

label_80189E80:
    ctx->pc = 0x80189E80u;
    // 80189E80: stw     r0, -26404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189E84:
    ctx->pc = 0x80189E84u;
    ctx->downcount -= 1;
    // 80189E84: bl      0x801A40FC
    {
            ctx->lr = 0x80189E88u;
            ctx->pc = 0x801A40FCu;
            return;
    }

label_80189E88:
    ctx->pc = 0x80189E88u;
    ctx->downcount -= 3;
    // 80189E88: lwz     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189E8C:
    ctx->pc = 0x80189E8Cu;
    // 80189E8C: cmpwi   r0, 32
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189E90:
    ctx->pc = 0x80189E90u;
    // 80189E90: bc    4, 2, 0x80189EE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80189EE8;
        }
    }

label_80189E94:
    ctx->pc = 0x80189E94u;
    ctx->downcount -= 6;
    // 80189E94: lwz     r5, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80189E98:
    ctx->pc = 0x80189E98u;
    // 80189E98: cntlzw r0, r5
    {
        u32 v = ctx->gpr[5];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80189E9C:
    ctx->pc = 0x80189E9Cu;
    // 80189E9C: stw     r0, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189EA0:
    ctx->pc = 0x80189EA0u;
    // 80189EA0: lwz     r4, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80189EA4:
    ctx->pc = 0x80189EA4u;
    // 80189EA4: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189EA8:
    ctx->pc = 0x80189EA8u;
    // 80189EA8: bc    12, 2, 0x80189EE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189EE8;
        }
    }

label_80189EAC:
    ctx->pc = 0x80189EACu;
    ctx->downcount -= 13;
    // 80189EAC: lis     r0, -32768
    ctx->gpr[0] = ((u32)(s32)(-32768) << 16);

label_80189EB0:
    ctx->pc = 0x80189EB0u;
    // 80189EB0: srw   r0, r0, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] >> sh);
    }

label_80189EB4:
    ctx->pc = 0x80189EB4u;
    // 80189EB4: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_80189EB8:
    ctx->pc = 0x80189EB8u;
    // 80189EB8: mulli   r4, r4, 12
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_80189EBC:
    ctx->pc = 0x80189EBCu;
    // 80189EBC: stw     r0, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189EC0:
    ctx->pc = 0x80189EC0u;
    // 80189EC0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80189EC4:
    ctx->pc = 0x80189EC4u;
    // 80189EC4: addi    r0, r3, 2872
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2872);

label_80189EC8:
    ctx->pc = 0x80189EC8u;
    // 80189EC8: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80189ECC:
    ctx->pc = 0x80189ECCu;
    // 80189ECC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80189ED0:
    ctx->pc = 0x80189ED0u;
    // 80189ED0: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_80189ED4:
    ctx->pc = 0x80189ED4u;
    // 80189ED4: bl      0x801698F0
    {
            ctx->lr = 0x80189ED8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80189ED8:
    ctx->pc = 0x80189ED8u;
    ctx->downcount -= 4;
    // 80189ED8: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_80189EDC:
    ctx->pc = 0x80189EDCu;
    // 80189EDC: lwz     r3, -28744(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28744);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80189EE0:
    ctx->pc = 0x80189EE0u;
    // 80189EE0: addi    r4, r4, -30984
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-30984);

label_80189EE4:
    ctx->pc = 0x80189EE4u;
    // 80189EE4: bl      0x801A49CC
    {
            ctx->lr = 0x80189EE8u;
            ctx->pc = 0x801A49CCu;
            return;
    }

label_80189EE8:
    ctx->pc = 0x80189EE8u;
    ctx->downcount -= 2;
    // 80189EE8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80189EEC:
    ctx->pc = 0x80189EECu;
    // 80189EEC: bl      0x80173F54
    {
            ctx->lr = 0x80189EF0u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80189EF0:
    ctx->pc = 0x80189EF0u;
    ctx->downcount -= 4;
    // 80189EF0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80189EF4:
    ctx->pc = 0x80189EF4u;
    // 80189EF4: stw     r0, -26380(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26380);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189EF8:
    ctx->pc = 0x80189EF8u;
    // 80189EF8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80189EFC:
    ctx->pc = 0x80189EFCu;
    // 80189EFC: b       0x80189F14
    {
            goto label_80189F14;
    }

label_80189F00:
    ctx->pc = 0x80189F00u;
    ctx->downcount -= 2;
    // 80189F00: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80189F04:
    ctx->pc = 0x80189F04u;
    // 80189F04: b       0x80189F14
    {
            goto label_80189F14;
    }

label_80189F08:
    ctx->pc = 0x80189F08u;
    ctx->downcount -= 3;
    // 80189F08: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80189F0C:
    ctx->pc = 0x80189F0Cu;
    // 80189F0C: stw     r0, -26380(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26380);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189F10:
    ctx->pc = 0x80189F10u;
    // 80189F10: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80189F14:
    ctx->pc = 0x80189F14u;
    ctx->downcount -= 7;
    // 80189F14: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189F18:
    ctx->pc = 0x80189F18u;
    // 80189F18: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189F1C:
    ctx->pc = 0x80189F1Cu;
    // 80189F1C: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80189F20:
    ctx->pc = 0x80189F20u;
    // 80189F20: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_80189F24:
    ctx->pc = 0x80189F24u;
    // 80189F24: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189F28:
    ctx->pc = 0x80189F28u;
    // 80189F28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189F2C:
    ctx->pc = 0x80189F2Cu;
    ctx->downcount -= 3;
    // 80189F2C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80189F30:
    ctx->pc = 0x80189F30u;
    // 80189F30: stw     r0, -28740(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28740);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189F34:
    ctx->pc = 0x80189F34u;
    // 80189F34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189F38:
    ctx->pc = 0x80189F38u;
    ctx->downcount -= 8;
    // 80189F38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189F3C:
    ctx->pc = 0x80189F3Cu;
    // 80189F3C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189F40:
    ctx->pc = 0x80189F40u;
    // 80189F40: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189F44:
    ctx->pc = 0x80189F44u;
    // 80189F44: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189F48:
    ctx->pc = 0x80189F48u;
    // 80189F48: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80189F4C:
    ctx->pc = 0x80189F4Cu;
    // 80189F4C: lwz     r0, -26384(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26384);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189F50:
    ctx->pc = 0x80189F50u;
    // 80189F50: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189F54:
    ctx->pc = 0x80189F54u;
    // 80189F54: bc    12, 2, 0x80189F84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189F84;
        }
    }

label_80189F58:
    ctx->pc = 0x80189F58u;
    ctx->downcount -= 2;
    // 80189F58: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80189F5C:
    ctx->pc = 0x80189F5Cu;
    // 80189F5C: bl      0x8017248C
    {
            ctx->lr = 0x80189F60u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80189F60:
    ctx->pc = 0x80189F60u;
    ctx->downcount -= 2;
    // 80189F60: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80189F64:
    ctx->pc = 0x80189F64u;
    // 80189F64: bl      0x80172284
    {
            ctx->lr = 0x80189F68u;
            ctx->pc = 0x80172284u;
            return;
    }

label_80189F68:
    ctx->pc = 0x80189F68u;
    ctx->downcount -= 4;
    // 80189F68: lwz     r12, -26384(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26384);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80189F6C:
    ctx->pc = 0x80189F6Cu;
    // 80189F6C: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80189F70:
    ctx->pc = 0x80189F70u;
    // 80189F70: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80189F74u;
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189F74:
    ctx->pc = 0x80189F74u;
    ctx->downcount -= 2;
    // 80189F74: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80189F78:
    ctx->pc = 0x80189F78u;
    // 80189F78: bl      0x8017248C
    {
            ctx->lr = 0x80189F7Cu;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80189F7C:
    ctx->pc = 0x80189F7Cu;
    ctx->downcount -= 2;
    // 80189F7C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80189F80:
    ctx->pc = 0x80189F80u;
    // 80189F80: bl      0x80172284
    {
            ctx->lr = 0x80189F84u;
            ctx->pc = 0x80172284u;
            return;
    }

label_80189F84:
    ctx->pc = 0x80189F84u;
    ctx->downcount -= 6;
    // 80189F84: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189F88:
    ctx->pc = 0x80189F88u;
    // 80189F88: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189F8C:
    ctx->pc = 0x80189F8Cu;
    // 80189F8C: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_80189F90:
    ctx->pc = 0x80189F90u;
    // 80189F90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189F94:
    ctx->pc = 0x80189F94u;
    // 80189F94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189F98:
    ctx->pc = 0x80189F98u;
    ctx->downcount -= 8;
    // 80189F98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189F9C:
    ctx->pc = 0x80189F9Cu;
    // 80189F9C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80189FA0:
    ctx->pc = 0x80189FA0u;
    // 80189FA0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189FA4:
    ctx->pc = 0x80189FA4u;
    // 80189FA4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189FA8:
    ctx->pc = 0x80189FA8u;
    // 80189FA8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189FAC:
    ctx->pc = 0x80189FACu;
    // 80189FAC: lwz     r31, -26384(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26384);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189FB0:
    ctx->pc = 0x80189FB0u;
    // 80189FB0: stw     r3, -26384(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26384);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80189FB4:
    ctx->pc = 0x80189FB4u;
    // 80189FB4: bc    12, 2, 0x80189FC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80189FC8;
        }
    }

label_80189FB8:
    ctx->pc = 0x80189FB8u;
    ctx->downcount -= 3;
    // 80189FB8: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_80189FBC:
    ctx->pc = 0x80189FBCu;
    // 80189FBC: addi    r3, r3, -24776
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-24776);

label_80189FC0:
    ctx->pc = 0x80189FC0u;
    // 80189FC0: bl      0x801A39C8
    {
            ctx->lr = 0x80189FC4u;
            ctx->pc = 0x801A39C8u;
            return;
    }

label_80189FC4:
    ctx->pc = 0x80189FC4u;
    ctx->downcount -= 1;
    // 80189FC4: b       0x80189FD4
    {
            goto label_80189FD4;
    }

label_80189FC8:
    ctx->pc = 0x80189FC8u;
    ctx->downcount -= 3;
    // 80189FC8: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_80189FCC:
    ctx->pc = 0x80189FCCu;
    // 80189FCC: addi    r3, r3, -24776
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-24776);

label_80189FD0:
    ctx->pc = 0x80189FD0u;
    // 80189FD0: bl      0x801A3A94
    {
            ctx->lr = 0x80189FD4u;
            ctx->pc = 0x801A3A94u;
            return;
    }

label_80189FD4:
    ctx->pc = 0x80189FD4u;
    ctx->downcount -= 7;
    // 80189FD4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80189FD8:
    ctx->pc = 0x80189FD8u;
    // 80189FD8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80189FDC:
    ctx->pc = 0x80189FDCu;
    // 80189FDC: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80189FE0:
    ctx->pc = 0x80189FE0u;
    // 80189FE0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80189FE4:
    ctx->pc = 0x80189FE4u;
    // 80189FE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80189FE8:
    ctx->pc = 0x80189FE8u;
    // 80189FE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_80189FEC:
    ctx->pc = 0x80189FECu;
    ctx->downcount -= 7;
    // 80189FEC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80189FF0:
    ctx->pc = 0x80189FF0u;
    // 80189FF0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80189FF4:
    ctx->pc = 0x80189FF4u;
    // 80189FF4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80189FF8:
    ctx->pc = 0x80189FF8u;
    // 80189FF8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80189FFC:
    ctx->pc = 0x80189FFCu;
    // 80189FFC: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A000:
    ctx->pc = 0x8018A000u;
    // 8018A000: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A004:
    ctx->pc = 0x8018A004u;
    // 8018A004: bl      0x80173F2C
    {
            ctx->lr = 0x8018A008u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A008:
    ctx->pc = 0x8018A008u;
    ctx->downcount -= 4;
    // 8018A008: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_8018A00C:
    ctx->pc = 0x8018A00Cu;
    // 8018A00C: lbz     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018A010:
    ctx->pc = 0x8018A010u;
    // 8018A010: rlwinm. r0, r0, 0, 25, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000040u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018A014:
    ctx->pc = 0x8018A014u;
    // 8018A014: bc    12, 2, 0x8018A020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A020;
        }
    }

label_8018A018:
    ctx->pc = 0x8018A018u;
    ctx->downcount -= 2;
    // 8018A018: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_8018A01C:
    ctx->pc = 0x8018A01Cu;
    // 8018A01C: b       0x8018A024
    {
            goto label_8018A024;
    }

label_8018A020:
    ctx->pc = 0x8018A020u;
    ctx->downcount -= 1;
    // 8018A020: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8018A024:
    ctx->pc = 0x8018A024u;
    ctx->downcount -= 6;
    // 8018A024: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_8018A028:
    ctx->pc = 0x8018A028u;
    // 8018A028: lbz     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018A02C:
    ctx->pc = 0x8018A02Cu;
    // 8018A02C: andi.   r0, r0, 0x00BF
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x00BFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018A030:
    ctx->pc = 0x8018A030u;
    // 8018A030: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A034:
    ctx->pc = 0x8018A034u;
    // 8018A034: stb     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018A038:
    ctx->pc = 0x8018A038u;
    // 8018A038: bc    12, 2, 0x8018A048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A048;
        }
    }

label_8018A03C:
    ctx->pc = 0x8018A03Cu;
    ctx->downcount -= 3;
    // 8018A03C: lbz     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8018A040:
    ctx->pc = 0x8018A040u;
    // 8018A040: ori     r0, r0, 0x0040
    ctx->gpr[0] = ctx->gpr[0] | 0x0040u;

label_8018A044:
    ctx->pc = 0x8018A044u;
    // 8018A044: stb     r0, 12515(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12515);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8018A048:
    ctx->pc = 0x8018A048u;
    ctx->downcount -= 1;
    // 8018A048: bl      0x80173F54
    {
            ctx->lr = 0x8018A04Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A04C:
    ctx->pc = 0x8018A04Cu;
    ctx->downcount -= 8;
    // 8018A04C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018A050:
    ctx->pc = 0x8018A050u;
    // 8018A050: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A054:
    ctx->pc = 0x8018A054u;
    // 8018A054: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A058:
    ctx->pc = 0x8018A058u;
    // 8018A058: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A05C:
    ctx->pc = 0x8018A05Cu;
    // 8018A05C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018A060:
    ctx->pc = 0x8018A060u;
    // 8018A060: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A064:
    ctx->pc = 0x8018A064u;
    // 8018A064: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A068:
    ctx->pc = 0x8018A068u;
    ctx->downcount -= 8;
    // 8018A068: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A06C:
    ctx->pc = 0x8018A06Cu;
    // 8018A06C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A070:
    ctx->pc = 0x8018A070u;
    // 8018A070: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A074:
    ctx->pc = 0x8018A074u;
    // 8018A074: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A078:
    ctx->pc = 0x8018A078u;
    // 8018A078: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A07C:
    ctx->pc = 0x8018A07Cu;
    // 8018A07C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A080:
    ctx->pc = 0x8018A080u;
    // 8018A080: lwz     r31, -26364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26364);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A084:
    ctx->pc = 0x8018A084u;
    // 8018A084: bl      0x80173F2C
    {
            ctx->lr = 0x8018A088u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A088:
    ctx->pc = 0x8018A088u;
    ctx->downcount -= 2;
    // 8018A088: stw     r30, -26364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26364);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A08C:
    ctx->pc = 0x8018A08Cu;
    // 8018A08C: bl      0x80173F54
    {
            ctx->lr = 0x8018A090u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A090:
    ctx->pc = 0x8018A090u;
    ctx->downcount -= 8;
    // 8018A090: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018A094:
    ctx->pc = 0x8018A094u;
    // 8018A094: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A098:
    ctx->pc = 0x8018A098u;
    // 8018A098: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A09C:
    ctx->pc = 0x8018A09Cu;
    // 8018A09C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A0A0:
    ctx->pc = 0x8018A0A0u;
    // 8018A0A0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018A0A4:
    ctx->pc = 0x8018A0A4u;
    // 8018A0A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A0A8:
    ctx->pc = 0x8018A0A8u;
    // 8018A0A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A0AC:
    ctx->pc = 0x8018A0ACu;
    ctx->downcount -= 8;
    // 8018A0AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A0B0:
    ctx->pc = 0x8018A0B0u;
    // 8018A0B0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A0B4:
    ctx->pc = 0x8018A0B4u;
    // 8018A0B4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A0B8:
    ctx->pc = 0x8018A0B8u;
    // 8018A0B8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A0BC:
    ctx->pc = 0x8018A0BCu;
    // 8018A0BC: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_8018A0C0:
    ctx->pc = 0x8018A0C0u;
    // 8018A0C0: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A0C4:
    ctx->pc = 0x8018A0C4u;
    // 8018A0C4: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A0C8:
    ctx->pc = 0x8018A0C8u;
    // 8018A0C8: bl      0x80173F2C
    {
            ctx->lr = 0x8018A0CCu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A0CC:
    ctx->pc = 0x8018A0CCu;
    ctx->downcount -= 20;
    // 8018A0CC: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018A0D0:
    ctx->pc = 0x8018A0D0u;
    // 8018A0D0: lhz     r0, 20528(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20528);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A0D4:
    ctx->pc = 0x8018A0D4u;
    // 8018A0D4: addi    r5, r4, 20480
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(20480);

label_8018A0D8:
    ctx->pc = 0x8018A0D8u;
    // 8018A0D8: addi    r6, r4, 20480
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(20480);

label_8018A0DC:
    ctx->pc = 0x8018A0DCu;
    // 8018A0DC: addi    r7, r4, 20480
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(20480);

label_8018A0E0:
    ctx->pc = 0x8018A0E0u;
    // 8018A0E0: rlwinm r4, r0, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018A0E4:
    ctx->pc = 0x8018A0E4u;
    // 8018A0E4: rlwinm r0, r30, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 16u) & 0x0000FFFFu;
    }

label_8018A0E8:
    ctx->pc = 0x8018A0E8u;
    // 8018A0E8: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018A0EC:
    ctx->pc = 0x8018A0ECu;
    // 8018A0EC: sth     r0, 48(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018A0F0:
    ctx->pc = 0x8018A0F0u;
    // 8018A0F0: rlwinm r0, r30, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_8018A0F4:
    ctx->pc = 0x8018A0F4u;
    // 8018A0F4: lhz     r4, 50(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(50);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018A0F8:
    ctx->pc = 0x8018A0F8u;
    // 8018A0F8: rlwinm r4, r4, 0, 27, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF001Fu;
    }

label_8018A0FC:
    ctx->pc = 0x8018A0FCu;
    // 8018A0FC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018A100:
    ctx->pc = 0x8018A100u;
    // 8018A100: sth     r0, 50(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018A104:
    ctx->pc = 0x8018A104u;
    // 8018A104: rlwinm r0, r31, 27, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 27u) & 0x0000FFFFu;
    }

label_8018A108:
    ctx->pc = 0x8018A108u;
    // 8018A108: lhz     r4, 54(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(54);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018A10C:
    ctx->pc = 0x8018A10Cu;
    // 8018A10C: rlwinm r4, r4, 0, 0, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF8000u;
    }

label_8018A110:
    ctx->pc = 0x8018A110u;
    // 8018A110: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018A114:
    ctx->pc = 0x8018A114u;
    // 8018A114: sth     r0, 54(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018A118:
    ctx->pc = 0x8018A118u;
    // 8018A118: bl      0x80173F54
    {
            ctx->lr = 0x8018A11Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A11C:
    ctx->pc = 0x8018A11Cu;
    ctx->downcount -= 7;
    // 8018A11C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A120:
    ctx->pc = 0x8018A120u;
    // 8018A120: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A124:
    ctx->pc = 0x8018A124u;
    // 8018A124: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A128:
    ctx->pc = 0x8018A128u;
    // 8018A128: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018A12C:
    ctx->pc = 0x8018A12Cu;
    // 8018A12C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A130:
    ctx->pc = 0x8018A130u;
    // 8018A130: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A134:
    ctx->pc = 0x8018A134u;
    ctx->downcount -= 4;
    // 8018A134: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A138:
    ctx->pc = 0x8018A138u;
    // 8018A138: lhz     r0, 20534(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20534);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A13C:
    ctx->pc = 0x8018A13Cu;
    // 8018A13C: rlwinm r3, r0, 17, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000001u;
    }

label_8018A140:
    ctx->pc = 0x8018A140u;
    // 8018A140: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A144:
    ctx->pc = 0x8018A144u;
    ctx->downcount -= 6;
    // 8018A144: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A148:
    ctx->pc = 0x8018A148u;
    // 8018A148: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018A14C:
    ctx->pc = 0x8018A14Cu;
    // 8018A14C: lhz     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A150:
    ctx->pc = 0x8018A150u;
    // 8018A150: ori     r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | 0x8000u;

label_8018A154:
    ctx->pc = 0x8018A154u;
    // 8018A154: sth     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018A158:
    ctx->pc = 0x8018A158u;
    // 8018A158: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A15C:
    ctx->pc = 0x8018A15Cu;
    ctx->downcount -= 6;
    // 8018A15C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A160:
    ctx->pc = 0x8018A160u;
    // 8018A160: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018A164:
    ctx->pc = 0x8018A164u;
    // 8018A164: lhz     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A168:
    ctx->pc = 0x8018A168u;
    // 8018A168: rlwinm r0, r0, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF7FFFu;
    }

label_8018A16C:
    ctx->pc = 0x8018A16Cu;
    // 8018A16C: sth     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018A170:
    ctx->pc = 0x8018A170u;
    // 8018A170: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A174:
    ctx->pc = 0x8018A174u;
    ctx->downcount -= 4;
    // 8018A174: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A178:
    ctx->pc = 0x8018A178u;
    // 8018A178: lhz     r0, 20538(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20538);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A17C:
    ctx->pc = 0x8018A17Cu;
    // 8018A17C: rlwinm r3, r0, 5, 12, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x000FFFE0u;
    }

label_8018A180:
    ctx->pc = 0x8018A180u;
    // 8018A180: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A184:
    ctx->pc = 0x8018A184u;
    ctx->downcount -= 7;
    // 8018A184: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A188:
    ctx->pc = 0x8018A188u;
    // 8018A188: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018A18C:
    ctx->pc = 0x8018A18Cu;
    // 8018A18C: lhz     r4, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018A190:
    ctx->pc = 0x8018A190u;
    // 8018A190: lhz     r0, 50(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(50);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A194:
    ctx->pc = 0x8018A194u;
    // 8018A194: rlwinm r3, r0, 0, 16, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFE0u;
    }

label_8018A198:
    ctx->pc = 0x8018A198u;
    // 8018A198: rlwimi r3, r4, 16, 6, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 16u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x03FF0000u) | (rot & 0x03FF0000u);
    }

label_8018A19C:
    ctx->pc = 0x8018A19Cu;
    // 8018A19C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A1A0:
    ctx->pc = 0x8018A1A0u;
    ctx->downcount -= 4;
    // 8018A1A0: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A1A4:
    ctx->pc = 0x8018A1A4u;
    // 8018A1A4: lhz     r0, 20534(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20534);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018A1A8:
    ctx->pc = 0x8018A1A8u;
    // 8018A1A8: rlwinm r3, r0, 5, 12, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x000FFFE0u;
    }

label_8018A1AC:
    ctx->pc = 0x8018A1ACu;
    // 8018A1AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A1B0:
    ctx->pc = 0x8018A1B0u;
    ctx->downcount -= 2;
    // 8018A1B0: lwz     r3, -26352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26352);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A1B4:
    ctx->pc = 0x8018A1B4u;
    // 8018A1B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A1B8:
    ctx->pc = 0x8018A1B8u;
    ctx->downcount -= 8;
    // 8018A1B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A1BC:
    ctx->pc = 0x8018A1BCu;
    // 8018A1BC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A1C0:
    ctx->pc = 0x8018A1C0u;
    // 8018A1C0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A1C4:
    ctx->pc = 0x8018A1C4u;
    // 8018A1C4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A1C8:
    ctx->pc = 0x8018A1C8u;
    // 8018A1C8: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A1CC:
    ctx->pc = 0x8018A1CCu;
    // 8018A1CC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A1D0:
    ctx->pc = 0x8018A1D0u;
    // 8018A1D0: lwz     r31, -26368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26368);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A1D4:
    ctx->pc = 0x8018A1D4u;
    // 8018A1D4: bl      0x80173F2C
    {
            ctx->lr = 0x8018A1D8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A1D8:
    ctx->pc = 0x8018A1D8u;
    ctx->downcount -= 2;
    // 8018A1D8: stw     r30, -26368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26368);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A1DC:
    ctx->pc = 0x8018A1DCu;
    // 8018A1DC: bl      0x80173F54
    {
            ctx->lr = 0x8018A1E0u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A1E0:
    ctx->pc = 0x8018A1E0u;
    ctx->downcount -= 8;
    // 8018A1E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018A1E4:
    ctx->pc = 0x8018A1E4u;
    // 8018A1E4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A1E8:
    ctx->pc = 0x8018A1E8u;
    // 8018A1E8: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A1EC:
    ctx->pc = 0x8018A1ECu;
    // 8018A1EC: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A1F0:
    ctx->pc = 0x8018A1F0u;
    // 8018A1F0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018A1F4:
    ctx->pc = 0x8018A1F4u;
    // 8018A1F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A1F8:
    ctx->pc = 0x8018A1F8u;
    // 8018A1F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A1FC:
    ctx->pc = 0x8018A1FCu;
    ctx->downcount -= 4;
    // 8018A1FC: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A200:
    ctx->pc = 0x8018A200u;
    // 8018A200: addi    r3, r3, 27648
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(27648);

label_8018A204:
    ctx->pc = 0x8018A204u;
    // 8018A204: lwz     r3, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A208:
    ctx->pc = 0x8018A208u;
    // 8018A208: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A20C:
    ctx->pc = 0x8018A20Cu;
    ctx->downcount -= 6;
    // 8018A20C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A210:
    ctx->pc = 0x8018A210u;
    // 8018A210: lwz     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A214:
    ctx->pc = 0x8018A214u;
    // 8018A214: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_8018A218:
    ctx->pc = 0x8018A218u;
    // 8018A218: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018A21C:
    ctx->pc = 0x8018A21Cu;
    // 8018A21C: stw     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A220:
    ctx->pc = 0x8018A220u;
    // 8018A220: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A224:
    ctx->pc = 0x8018A224u;
    ctx->downcount -= 3;
    // 8018A224: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018A228:
    ctx->pc = 0x8018A228u;
    // 8018A228: stw     r3, 27660(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(27660);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018A22C:
    ctx->pc = 0x8018A22Cu;
    // 8018A22C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A230:
    ctx->pc = 0x8018A230u;
    ctx->downcount -= 4;
    // 8018A230: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A234:
    ctx->pc = 0x8018A234u;
    // 8018A234: addi    r3, r3, 27648
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(27648);

label_8018A238:
    ctx->pc = 0x8018A238u;
    // 8018A238: lwz     r3, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A23C:
    ctx->pc = 0x8018A23Cu;
    // 8018A23C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A240:
    ctx->pc = 0x8018A240u;
    ctx->downcount -= 8;
    // 8018A240: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A244:
    ctx->pc = 0x8018A244u;
    // 8018A244: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A248:
    ctx->pc = 0x8018A248u;
    // 8018A248: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A24C:
    ctx->pc = 0x8018A24Cu;
    // 8018A24C: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A250:
    ctx->pc = 0x8018A250u;
    // 8018A250: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A254:
    ctx->pc = 0x8018A254u;
    // 8018A254: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018A258:
    ctx->pc = 0x8018A258u;
    // 8018A258: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A25C:
    ctx->pc = 0x8018A25Cu;
    // 8018A25C: bl      0x8018A318
    {
            ctx->lr = 0x8018A260u;
            goto label_8018A318;
    }

label_8018A260:
    ctx->pc = 0x8018A260u;
    ctx->downcount -= 2;
    // 8018A260: cmplw   r29, r3
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A264:
    ctx->pc = 0x8018A264u;
    // 8018A264: bc    12, 2, 0x8018A2FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A2FC;
        }
    }

label_8018A268:
    ctx->pc = 0x8018A268u;
    ctx->downcount -= 1;
    // 8018A268: bl      0x8018A538
    {
            ctx->lr = 0x8018A26Cu;
            goto label_8018A538;
    }

label_8018A26C:
    ctx->pc = 0x8018A26Cu;
    ctx->downcount -= 2;
    // 8018A26C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A270:
    ctx->pc = 0x8018A270u;
    // 8018A270: bc    4, 2, 0x8018A2E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018A2E8;
        }
    }

label_8018A274:
    ctx->pc = 0x8018A274u;
    ctx->downcount -= 2;
    // 8018A274: cmplwi  r29, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A278:
    ctx->pc = 0x8018A278u;
    // 8018A278: bc    4, 2, 0x8018A2E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018A2E8;
        }
    }

label_8018A27C:
    ctx->pc = 0x8018A27Cu;
    ctx->downcount -= 1;
    // 8018A27C: bl      0x8018A590
    {
            ctx->lr = 0x8018A280u;
            goto label_8018A590;
    }

label_8018A280:
    ctx->pc = 0x8018A280u;
    ctx->downcount -= 2;
    // 8018A280: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A284:
    ctx->pc = 0x8018A284u;
    // 8018A284: bl      0x8018A564
    {
            ctx->lr = 0x8018A288u;
            goto label_8018A564;
    }

label_8018A288:
    ctx->pc = 0x8018A288u;
    ctx->downcount -= 3;
    // 8018A288: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A28C:
    ctx->pc = 0x8018A28Cu;
    // 8018A28C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A290:
    ctx->pc = 0x8018A290u;
    // 8018A290: bl      0x8018A574
    {
            ctx->lr = 0x8018A294u;
            goto label_8018A574;
    }

label_8018A294:
    ctx->pc = 0x8018A294u;
    ctx->downcount -= 2;
    // 8018A294: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A298:
    ctx->pc = 0x8018A298u;
    // 8018A298: bl      0x8018A548
    {
            ctx->lr = 0x8018A29Cu;
            goto label_8018A548;
    }

label_8018A29C:
    ctx->pc = 0x8018A29Cu;
    ctx->downcount -= 1;
    // 8018A29C: bl      0x80173F2C
    {
            ctx->lr = 0x8018A2A0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A2A0:
    ctx->pc = 0x8018A2A0u;
    ctx->downcount -= 2;
    // 8018A2A0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A2A4:
    ctx->pc = 0x8018A2A4u;
    // 8018A2A4: bl      0x8018A874
    {
            ctx->lr = 0x8018A2A8u;
            goto label_8018A874;
    }

label_8018A2A8:
    ctx->pc = 0x8018A2A8u;
    ctx->downcount -= 11;
    // 8018A2A8: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018A2AC:
    ctx->pc = 0x8018A2ACu;
    // 8018A2AC: lwz     r0, 27648(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A2B0:
    ctx->pc = 0x8018A2B0u;
    // 8018A2B0: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_8018A2B4:
    ctx->pc = 0x8018A2B4u;
    // 8018A2B4: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_8018A2B8:
    ctx->pc = 0x8018A2B8u;
    // 8018A2B8: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018A2BC:
    ctx->pc = 0x8018A2BCu;
    // 8018A2BC: stw     r0, 27648(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A2C0:
    ctx->pc = 0x8018A2C0u;
    // 8018A2C0: lwz     r0, 27648(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A2C4:
    ctx->pc = 0x8018A2C4u;
    // 8018A2C4: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8018A2C8:
    ctx->pc = 0x8018A2C8u;
    // 8018A2C8: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_8018A2CC:
    ctx->pc = 0x8018A2CCu;
    // 8018A2CC: stw     r0, 27648(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A2D0:
    ctx->pc = 0x8018A2D0u;
    // 8018A2D0: bl      0x80173F54
    {
            ctx->lr = 0x8018A2D4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A2D4:
    ctx->pc = 0x8018A2D4u;
    ctx->downcount -= 2;
    // 8018A2D4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018A2D8:
    ctx->pc = 0x8018A2D8u;
    // 8018A2D8: bl      0x8018A548
    {
            ctx->lr = 0x8018A2DCu;
            goto label_8018A548;
    }

label_8018A2DC:
    ctx->pc = 0x8018A2DCu;
    ctx->downcount -= 2;
    // 8018A2DC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018A2E0:
    ctx->pc = 0x8018A2E0u;
    // 8018A2E0: bl      0x8018A574
    {
            ctx->lr = 0x8018A2E4u;
            goto label_8018A574;
    }

label_8018A2E4:
    ctx->pc = 0x8018A2E4u;
    ctx->downcount -= 1;
    // 8018A2E4: b       0x8018A2FC
    {
            goto label_8018A2FC;
    }

label_8018A2E8:
    ctx->pc = 0x8018A2E8u;
    ctx->downcount -= 5;
    // 8018A2E8: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A2EC:
    ctx->pc = 0x8018A2ECu;
    // 8018A2EC: lwz     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A2F0:
    ctx->pc = 0x8018A2F0u;
    // 8018A2F0: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8018A2F4:
    ctx->pc = 0x8018A2F4u;
    // 8018A2F4: or   r0, r0, r29
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[29];
    }

label_8018A2F8:
    ctx->pc = 0x8018A2F8u;
    // 8018A2F8: stw     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A2FC:
    ctx->pc = 0x8018A2FCu;
    ctx->downcount -= 8;
    // 8018A2FC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A300:
    ctx->pc = 0x8018A300u;
    // 8018A300: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A304:
    ctx->pc = 0x8018A304u;
    // 8018A304: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A308:
    ctx->pc = 0x8018A308u;
    // 8018A308: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018A30C:
    ctx->pc = 0x8018A30Cu;
    // 8018A30C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8018A310:
    ctx->pc = 0x8018A310u;
    // 8018A310: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A314:
    ctx->pc = 0x8018A314u;
    // 8018A314: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A318:
    ctx->pc = 0x8018A318u;
    ctx->downcount -= 4;
    // 8018A318: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A31C:
    ctx->pc = 0x8018A31Cu;
    // 8018A31C: lwz     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A320:
    ctx->pc = 0x8018A320u;
    // 8018A320: rlwinm r3, r0, 0, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8018A324:
    ctx->pc = 0x8018A324u;
    // 8018A324: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A328:
    ctx->pc = 0x8018A328u;
    ctx->downcount -= 16;
    // 8018A328: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A32C:
    ctx->pc = 0x8018A32Cu;
    // 8018A32C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A330:
    ctx->pc = 0x8018A330u;
    // 8018A330: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A334:
    ctx->pc = 0x8018A334u;
    // 8018A334: stmw     r26, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8018A338:
    ctx->pc = 0x8018A338u;
    // 8018A338: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A33C:
    ctx->pc = 0x8018A33Cu;
    // 8018A33C: bl      0x8018A408
    {
            ctx->lr = 0x8018A340u;
            goto label_8018A408;
    }

label_8018A340:
    ctx->pc = 0x8018A340u;
    ctx->downcount -= 2;
    // 8018A340: cmplw   r26, r3
    {
        u32 val_a = (u32)(ctx->gpr[26]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A344:
    ctx->pc = 0x8018A344u;
    // 8018A344: bc    12, 2, 0x8018A3F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A3F4;
        }
    }

label_8018A348:
    ctx->pc = 0x8018A348u;
    ctx->downcount -= 6;
    // 8018A348: lis     r31, -13312
    ctx->gpr[31] = ((u32)(s32)(-13312) << 16);

label_8018A34C:
    ctx->pc = 0x8018A34Cu;
    // 8018A34C: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A350:
    ctx->pc = 0x8018A350u;
    // 8018A350: cmplwi  r26, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[26]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A354:
    ctx->pc = 0x8018A354u;
    // 8018A354: rlwinm r0, r0, 0, 26, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFBFu;
    }

label_8018A358:
    ctx->pc = 0x8018A358u;
    // 8018A358: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A35C:
    ctx->pc = 0x8018A35Cu;
    // 8018A35C: bc    4, 2, 0x8018A3F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018A3F4;
        }
    }

label_8018A360:
    ctx->pc = 0x8018A360u;
    ctx->downcount -= 1;
    // 8018A360: bl      0x8018A564
    {
            ctx->lr = 0x8018A364u;
            goto label_8018A564;
    }

label_8018A364:
    ctx->pc = 0x8018A364u;
    ctx->downcount -= 2;
    // 8018A364: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A368:
    ctx->pc = 0x8018A368u;
    // 8018A368: bl      0x8018A590
    {
            ctx->lr = 0x8018A36Cu;
            goto label_8018A590;
    }

label_8018A36C:
    ctx->pc = 0x8018A36Cu;
    ctx->downcount -= 4;
    // 8018A36C: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A370:
    ctx->pc = 0x8018A370u;
    // 8018A370: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A374:
    ctx->pc = 0x8018A374u;
    // 8018A374: rlwinm r27, r0, 0, 31, 31
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8018A378:
    ctx->pc = 0x8018A378u;
    // 8018A378: bl      0x8018A538
    {
            ctx->lr = 0x8018A37Cu;
            goto label_8018A538;
    }

label_8018A37C:
    ctx->pc = 0x8018A37Cu;
    ctx->downcount -= 3;
    // 8018A37C: addi    r28, r3, 0
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A380:
    ctx->pc = 0x8018A380u;
    // 8018A380: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A384:
    ctx->pc = 0x8018A384u;
    // 8018A384: bl      0x8018A548
    {
            ctx->lr = 0x8018A388u;
            goto label_8018A548;
    }

label_8018A388:
    ctx->pc = 0x8018A388u;
    ctx->downcount -= 2;
    // 8018A388: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A38C:
    ctx->pc = 0x8018A38Cu;
    // 8018A38C: bl      0x8018A574
    {
            ctx->lr = 0x8018A390u;
            goto label_8018A574;
    }

label_8018A390:
    ctx->pc = 0x8018A390u;
    ctx->downcount -= 1;
    // 8018A390: bl      0x80173F2C
    {
            ctx->lr = 0x8018A394u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A394:
    ctx->pc = 0x8018A394u;
    ctx->downcount -= 2;
    // 8018A394: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A398:
    ctx->pc = 0x8018A398u;
    // 8018A398: bl      0x8018A874
    {
            ctx->lr = 0x8018A39Cu;
            goto label_8018A874;
    }

label_8018A39C:
    ctx->pc = 0x8018A39Cu;
    ctx->downcount -= 18;
    // 8018A39C: lwz     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018A3A0:
    ctx->pc = 0x8018A3A0u;
    // 8018A3A0: rlwinm r0, r28, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 1u) & 0xFFFFFFFEu;
    }

label_8018A3A4:
    ctx->pc = 0x8018A3A4u;
    // 8018A3A4: addi    r3, r26, 0
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(0);

label_8018A3A8:
    ctx->pc = 0x8018A3A8u;
    // 8018A3A8: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_8018A3AC:
    ctx->pc = 0x8018A3ACu;
    // 8018A3AC: ori     r4, r4, 0x0020
    ctx->gpr[4] = ctx->gpr[4] | 0x0020u;

label_8018A3B0:
    ctx->pc = 0x8018A3B0u;
    // 8018A3B0: stw     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018A3B4:
    ctx->pc = 0x8018A3B4u;
    // 8018A3B4: lwz     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018A3B8:
    ctx->pc = 0x8018A3B8u;
    // 8018A3B8: rlwinm r4, r4, 0, 31, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFDu;
    }

label_8018A3BC:
    ctx->pc = 0x8018A3BCu;
    // 8018A3BC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018A3C0:
    ctx->pc = 0x8018A3C0u;
    // 8018A3C0: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A3C4:
    ctx->pc = 0x8018A3C4u;
    // 8018A3C4: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A3C8:
    ctx->pc = 0x8018A3C8u;
    // 8018A3C8: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8018A3CC:
    ctx->pc = 0x8018A3CCu;
    // 8018A3CC: or   r0, r0, r27
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[27];
    }

label_8018A3D0:
    ctx->pc = 0x8018A3D0u;
    // 8018A3D0: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A3D4:
    ctx->pc = 0x8018A3D4u;
    // 8018A3D4: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A3D8:
    ctx->pc = 0x8018A3D8u;
    // 8018A3D8: ori     r0, r0, 0x0040
    ctx->gpr[0] = ctx->gpr[0] | 0x0040u;

label_8018A3DC:
    ctx->pc = 0x8018A3DCu;
    // 8018A3DC: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A3E0:
    ctx->pc = 0x8018A3E0u;
    // 8018A3E0: bl      0x80173F54
    {
            ctx->lr = 0x8018A3E4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A3E4:
    ctx->pc = 0x8018A3E4u;
    ctx->downcount -= 2;
    // 8018A3E4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018A3E8:
    ctx->pc = 0x8018A3E8u;
    // 8018A3E8: bl      0x8018A548
    {
            ctx->lr = 0x8018A3ECu;
            goto label_8018A548;
    }

label_8018A3EC:
    ctx->pc = 0x8018A3ECu;
    ctx->downcount -= 2;
    // 8018A3EC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018A3F0:
    ctx->pc = 0x8018A3F0u;
    // 8018A3F0: bl      0x8018A574
    {
            ctx->lr = 0x8018A3F4u;
            goto label_8018A574;
    }

label_8018A3F4:
    ctx->pc = 0x8018A3F4u;
    ctx->downcount -= 16;
    // 8018A3F4: lmw     r26, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8018A3F8:
    ctx->pc = 0x8018A3F8u;
    // 8018A3F8: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A3FC:
    ctx->pc = 0x8018A3FCu;
    // 8018A3FC: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8018A400:
    ctx->pc = 0x8018A400u;
    // 8018A400: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A404:
    ctx->pc = 0x8018A404u;
    // 8018A404: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A408:
    ctx->pc = 0x8018A408u;
    ctx->downcount -= 5;
    // 8018A408: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A40C:
    ctx->pc = 0x8018A40Cu;
    // 8018A40C: lwz     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A410:
    ctx->pc = 0x8018A410u;
    // 8018A410: rlwinm r0, r0, 26, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000001u;
    }

label_8018A414:
    ctx->pc = 0x8018A414u;
    // 8018A414: xori    r3, r0, 0x0001
    ctx->gpr[3] = ctx->gpr[0] ^ 0x0001u;

label_8018A418:
    ctx->pc = 0x8018A418u;
    // 8018A418: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A41C:
    ctx->pc = 0x8018A41Cu;
    ctx->downcount -= 5;
    // 8018A41C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A420:
    ctx->pc = 0x8018A420u;
    // 8018A420: cmplwi  r3, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A424:
    ctx->pc = 0x8018A424u;
    // 8018A424: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A428:
    ctx->pc = 0x8018A428u;
    // 8018A428: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A42C:
    ctx->pc = 0x8018A42Cu;
    // 8018A42C: bc    4, 2, 0x8018A434
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018A434;
        }
    }

label_8018A430:
    ctx->pc = 0x8018A430u;
    ctx->downcount -= 1;
    // 8018A430: bl      0x8018A464
    {
            ctx->lr = 0x8018A434u;
            goto label_8018A464;
    }

label_8018A434:
    ctx->pc = 0x8018A434u;
    ctx->downcount -= 5;
    // 8018A434: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A438:
    ctx->pc = 0x8018A438u;
    // 8018A438: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8018A43C:
    ctx->pc = 0x8018A43Cu;
    // 8018A43C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A440:
    ctx->pc = 0x8018A440u;
    // 8018A440: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A444:
    ctx->pc = 0x8018A444u;
    ctx->downcount -= 4;
    // 8018A444: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A448:
    ctx->pc = 0x8018A448u;
    // 8018A448: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A44C:
    ctx->pc = 0x8018A44Cu;
    // 8018A44C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A450:
    ctx->pc = 0x8018A450u;
    // 8018A450: bl      0x8018A464
    {
            ctx->lr = 0x8018A454u;
            goto label_8018A464;
    }

label_8018A454:
    ctx->pc = 0x8018A454u;
    ctx->downcount -= 5;
    // 8018A454: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A458:
    ctx->pc = 0x8018A458u;
    // 8018A458: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8018A45C:
    ctx->pc = 0x8018A45Cu;
    // 8018A45C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A460:
    ctx->pc = 0x8018A460u;
    // 8018A460: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A464:
    ctx->pc = 0x8018A464u;
    ctx->downcount -= 16;
    // 8018A464: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A468:
    ctx->pc = 0x8018A468u;
    // 8018A468: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A46C:
    ctx->pc = 0x8018A46Cu;
    // 8018A46C: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A470:
    ctx->pc = 0x8018A470u;
    // 8018A470: stmw     r25, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8018A474:
    ctx->pc = 0x8018A474u;
    // 8018A474: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A478:
    ctx->pc = 0x8018A478u;
    // 8018A478: bl      0x8018A538
    {
            ctx->lr = 0x8018A47Cu;
            goto label_8018A538;
    }

label_8018A47C:
    ctx->pc = 0x8018A47Cu;
    ctx->downcount -= 2;
    // 8018A47C: cmplw   r25, r3
    {
        u32 val_a = (u32)(ctx->gpr[25]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A480:
    ctx->pc = 0x8018A480u;
    // 8018A480: bc    12, 2, 0x8018A524
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A524;
        }
    }

label_8018A484:
    ctx->pc = 0x8018A484u;
    ctx->downcount -= 5;
    // 8018A484: lis     r31, -13312
    ctx->gpr[31] = ((u32)(s32)(-13312) << 16);

label_8018A488:
    ctx->pc = 0x8018A488u;
    // 8018A488: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A48C:
    ctx->pc = 0x8018A48Cu;
    // 8018A48C: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8018A490:
    ctx->pc = 0x8018A490u;
    // 8018A490: or   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8018A494:
    ctx->pc = 0x8018A494u;
    // 8018A494: bl      0x8018A564
    {
            ctx->lr = 0x8018A498u;
            goto label_8018A564;
    }

label_8018A498:
    ctx->pc = 0x8018A498u;
    ctx->downcount -= 2;
    // 8018A498: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A49C:
    ctx->pc = 0x8018A49Cu;
    // 8018A49C: bl      0x8018A590
    {
            ctx->lr = 0x8018A4A0u;
            goto label_8018A590;
    }

label_8018A4A0:
    ctx->pc = 0x8018A4A0u;
    ctx->downcount -= 3;
    // 8018A4A0: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A4A4:
    ctx->pc = 0x8018A4A4u;
    // 8018A4A4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A4A8:
    ctx->pc = 0x8018A4A8u;
    // 8018A4A8: bl      0x8018A574
    {
            ctx->lr = 0x8018A4ACu;
            goto label_8018A574;
    }

label_8018A4AC:
    ctx->pc = 0x8018A4ACu;
    ctx->downcount -= 2;
    // 8018A4AC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A4B0:
    ctx->pc = 0x8018A4B0u;
    // 8018A4B0: bl      0x8018A548
    {
            ctx->lr = 0x8018A4B4u;
            goto label_8018A548;
    }

label_8018A4B4:
    ctx->pc = 0x8018A4B4u;
    ctx->downcount -= 6;
    // 8018A4B4: lwz     r3, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A4B8:
    ctx->pc = 0x8018A4B8u;
    // 8018A4B8: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A4BC:
    ctx->pc = 0x8018A4BCu;
    // 8018A4BC: rlwinm r26, r3, 0, 25, 25
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000040u;
    }

label_8018A4C0:
    ctx->pc = 0x8018A4C0u;
    // 8018A4C0: rlwinm r0, r0, 0, 26, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFBFu;
    }

label_8018A4C4:
    ctx->pc = 0x8018A4C4u;
    // 8018A4C4: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A4C8:
    ctx->pc = 0x8018A4C8u;
    // 8018A4C8: bl      0x80173F2C
    {
            ctx->lr = 0x8018A4CCu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018A4CC:
    ctx->pc = 0x8018A4CCu;
    ctx->downcount -= 2;
    // 8018A4CC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A4D0:
    ctx->pc = 0x8018A4D0u;
    // 8018A4D0: bl      0x8018A874
    {
            ctx->lr = 0x8018A4D4u;
            goto label_8018A874;
    }

label_8018A4D4:
    ctx->pc = 0x8018A4D4u;
    ctx->downcount -= 14;
    // 8018A4D4: lwz     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018A4D8:
    ctx->pc = 0x8018A4D8u;
    // 8018A4D8: rlwinm r0, r25, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[25], 1u) & 0xFFFFFFFEu;
    }

label_8018A4DC:
    ctx->pc = 0x8018A4DCu;
    // 8018A4DC: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_8018A4E0:
    ctx->pc = 0x8018A4E0u;
    // 8018A4E0: or   r4, r4, r26
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[26];
    }

label_8018A4E4:
    ctx->pc = 0x8018A4E4u;
    // 8018A4E4: stw     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018A4E8:
    ctx->pc = 0x8018A4E8u;
    // 8018A4E8: lwz     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018A4EC:
    ctx->pc = 0x8018A4ECu;
    // 8018A4EC: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_8018A4F0:
    ctx->pc = 0x8018A4F0u;
    // 8018A4F0: ori     r4, r4, 0x0020
    ctx->gpr[4] = ctx->gpr[4] | 0x0020u;

label_8018A4F4:
    ctx->pc = 0x8018A4F4u;
    // 8018A4F4: stw     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018A4F8:
    ctx->pc = 0x8018A4F8u;
    // 8018A4F8: lwz     r4, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018A4FC:
    ctx->pc = 0x8018A4FCu;
    // 8018A4FC: rlwinm r4, r4, 0, 31, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFDu;
    }

label_8018A500:
    ctx->pc = 0x8018A500u;
    // 8018A500: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018A504:
    ctx->pc = 0x8018A504u;
    // 8018A504: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A508:
    ctx->pc = 0x8018A508u;
    // 8018A508: bl      0x80173F54
    {
            ctx->lr = 0x8018A50Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018A50C:
    ctx->pc = 0x8018A50Cu;
    ctx->downcount -= 2;
    // 8018A50C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8018A510:
    ctx->pc = 0x8018A510u;
    // 8018A510: bl      0x8018A240
    {
            ctx->lr = 0x8018A514u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A240u;
                return;
            }
            goto label_8018A240;
    }

label_8018A514:
    ctx->pc = 0x8018A514u;
    ctx->downcount -= 2;
    // 8018A514: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8018A518:
    ctx->pc = 0x8018A518u;
    // 8018A518: bl      0x8018A548
    {
            ctx->lr = 0x8018A51Cu;
            goto label_8018A548;
    }

label_8018A51C:
    ctx->pc = 0x8018A51Cu;
    ctx->downcount -= 2;
    // 8018A51C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8018A520:
    ctx->pc = 0x8018A520u;
    // 8018A520: bl      0x8018A574
    {
            ctx->lr = 0x8018A524u;
            goto label_8018A574;
    }

label_8018A524:
    ctx->pc = 0x8018A524u;
    ctx->downcount -= 16;
    // 8018A524: lmw     r25, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8018A528:
    ctx->pc = 0x8018A528u;
    // 8018A528: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A52C:
    ctx->pc = 0x8018A52Cu;
    // 8018A52C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8018A530:
    ctx->pc = 0x8018A530u;
    // 8018A530: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A534:
    ctx->pc = 0x8018A534u;
    // 8018A534: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A538:
    ctx->pc = 0x8018A538u;
    ctx->downcount -= 4;
    // 8018A538: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A53C:
    ctx->pc = 0x8018A53Cu;
    // 8018A53C: lwz     r0, 27648(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A540:
    ctx->pc = 0x8018A540u;
    // 8018A540: rlwinm r3, r0, 31, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
    }

label_8018A544:
    ctx->pc = 0x8018A544u;
    // 8018A544: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A548:
    ctx->pc = 0x8018A548u;
    ctx->downcount -= 7;
    // 8018A548: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018A54C:
    ctx->pc = 0x8018A54Cu;
    // 8018A54C: addi    r4, r4, 27648
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(27648);

label_8018A550:
    ctx->pc = 0x8018A550u;
    // 8018A550: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A554:
    ctx->pc = 0x8018A554u;
    // 8018A554: rlwinm r0, r0, 0, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF00u;
    }

label_8018A558:
    ctx->pc = 0x8018A558u;
    // 8018A558: rlwimi r0, r3, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8018A55C:
    ctx->pc = 0x8018A55Cu;
    // 8018A55C: stw     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A560:
    ctx->pc = 0x8018A560u;
    // 8018A560: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A564:
    ctx->pc = 0x8018A564u;
    ctx->downcount -= 4;
    // 8018A564: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A568:
    ctx->pc = 0x8018A568u;
    // 8018A568: lwz     r0, 27652(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27652);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A56C:
    ctx->pc = 0x8018A56Cu;
    // 8018A56C: rlwinm r3, r0, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8018A570:
    ctx->pc = 0x8018A570u;
    // 8018A570: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A574:
    ctx->pc = 0x8018A574u;
    ctx->downcount -= 7;
    // 8018A574: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018A578:
    ctx->pc = 0x8018A578u;
    // 8018A578: addi    r4, r4, 27648
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(27648);

label_8018A57C:
    ctx->pc = 0x8018A57Cu;
    // 8018A57C: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A580:
    ctx->pc = 0x8018A580u;
    // 8018A580: rlwinm r0, r0, 0, 24, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF00FFu;
    }

label_8018A584:
    ctx->pc = 0x8018A584u;
    // 8018A584: rlwimi r0, r3, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_8018A588:
    ctx->pc = 0x8018A588u;
    // 8018A588: stw     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A58C:
    ctx->pc = 0x8018A58Cu;
    // 8018A58C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A590:
    ctx->pc = 0x8018A590u;
    ctx->downcount -= 4;
    // 8018A590: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A594:
    ctx->pc = 0x8018A594u;
    // 8018A594: lwz     r0, 27652(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(27652);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A598:
    ctx->pc = 0x8018A598u;
    // 8018A598: rlwinm r3, r0, 24, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x000000FFu;
    }

label_8018A59C:
    ctx->pc = 0x8018A59Cu;
    // 8018A59C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A5A0:
    ctx->pc = 0x8018A5A0u;
    ctx->downcount -= 9;
    // 8018A5A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A5A4:
    ctx->pc = 0x8018A5A4u;
    // 8018A5A4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A5A8:
    ctx->pc = 0x8018A5A8u;
    // 8018A5A8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A5AC:
    ctx->pc = 0x8018A5ACu;
    // 8018A5AC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A5B0:
    ctx->pc = 0x8018A5B0u;
    // 8018A5B0: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A5B4:
    ctx->pc = 0x8018A5B4u;
    // 8018A5B4: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A5B8:
    ctx->pc = 0x8018A5B8u;
    // 8018A5B8: lwz     r0, -26352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26352);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A5BC:
    ctx->pc = 0x8018A5BCu;
    // 8018A5BC: cmpwi   r0, 1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A5C0:
    ctx->pc = 0x8018A5C0u;
    // 8018A5C0: bc    12, 2, 0x8018A6EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A6EC;
        }
    }

label_8018A5C4:
    ctx->pc = 0x8018A5C4u;
    ctx->downcount -= 95;
    // 8018A5C4: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_8018A5C8:
    ctx->pc = 0x8018A5C8u;
    // 8018A5C8: lwz     r0, 248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A5CC:
    ctx->pc = 0x8018A5CCu;
    // 8018A5CC: lis     r3, 17180
    ctx->gpr[3] = ((u32)(s32)(17180) << 16);

label_8018A5D0:
    ctx->pc = 0x8018A5D0u;
    // 8018A5D0: lis     r4, 1
    ctx->gpr[4] = ((u32)(s32)(1) << 16);

label_8018A5D4:
    ctx->pc = 0x8018A5D4u;
    // 8018A5D4: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_8018A5D8:
    ctx->pc = 0x8018A5D8u;
    // 8018A5D8: addi    r3, r3, -8573
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-8573);

label_8018A5DC:
    ctx->pc = 0x8018A5DCu;
    // 8018A5DC: mulhwu   r0, r3, r0
    {
        u64 product = (u64)ctx->gpr[3] * (u64)ctx->gpr[0];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_8018A5E0:
    ctx->pc = 0x8018A5E0u;
    // 8018A5E0: rlwinm r9, r0, 17, 15, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_8018A5E4:
    ctx->pc = 0x8018A5E4u;
    // 8018A5E4: addi    r5, r4, -23512
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(-23512);

label_8018A5E8:
    ctx->pc = 0x8018A5E8u;
    // 8018A5E8: addi    r3, r4, -23536
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(-23536);

label_8018A5EC:
    ctx->pc = 0x8018A5ECu;
    // 8018A5EC: addi    r0, r4, -2536
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-2536);

label_8018A5F0:
    ctx->pc = 0x8018A5F0u;
    // 8018A5F0: lis     r4, 4194
    ctx->gpr[4] = ((u32)(s32)(4194) << 16);

label_8018A5F4:
    ctx->pc = 0x8018A5F4u;
    // 8018A5F4: mullw   r7, r9, r5
    {
        s64 product = (s64)(s32)ctx->gpr[9] * (s64)(s32)ctx->gpr[5];
        ctx->gpr[7] = (u32)product;
    }

label_8018A5F8:
    ctx->pc = 0x8018A5F8u;
    // 8018A5F8: addi    r10, r4, 19923
    ctx->gpr[10] = ctx->gpr[4] + (u32)(s32)(19923);

label_8018A5FC:
    ctx->pc = 0x8018A5FCu;
    // 8018A5FC: mullw   r5, r9, r3
    {
        s64 product = (s64)(s32)ctx->gpr[9] * (s64)(s32)ctx->gpr[3];
        ctx->gpr[5] = (u32)product;
    }

label_8018A600:
    ctx->pc = 0x8018A600u;
    // 8018A600: mullw   r4, r9, r0
    {
        s64 product = (s64)(s32)ctx->gpr[9] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[4] = (u32)product;
    }

label_8018A604:
    ctx->pc = 0x8018A604u;
    // 8018A604: mulli   r8, r9, 31524
    ctx->gpr[8] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)31524);

label_8018A608:
    ctx->pc = 0x8018A608u;
    // 8018A608: mulli   r3, r9, 3000
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)3000);

label_8018A60C:
    ctx->pc = 0x8018A60Cu;
    // 8018A60C: mulhwu   r8, r10, r8
    {
        u64 product = (u64)ctx->gpr[10] * (u64)ctx->gpr[8];
        ctx->gpr[8] = (u32)(product >> 32);
    }

label_8018A610:
    ctx->pc = 0x8018A610u;
    // 8018A610: mulhwu   r7, r10, r7
    {
        u64 product = (u64)ctx->gpr[10] * (u64)ctx->gpr[7];
        ctx->gpr[7] = (u32)(product >> 32);
    }

label_8018A614:
    ctx->pc = 0x8018A614u;
    // 8018A614: mulhwu   r5, r10, r5
    {
        u64 product = (u64)ctx->gpr[10] * (u64)ctx->gpr[5];
        ctx->gpr[5] = (u32)(product >> 32);
    }

label_8018A618:
    ctx->pc = 0x8018A618u;
    // 8018A618: mulhwu   r4, r10, r4
    {
        u64 product = (u64)ctx->gpr[10] * (u64)ctx->gpr[4];
        ctx->gpr[4] = (u32)(product >> 32);
    }

label_8018A61C:
    ctx->pc = 0x8018A61Cu;
    // 8018A61C: mulhwu   r3, r10, r3
    {
        u64 product = (u64)ctx->gpr[10] * (u64)ctx->gpr[3];
        ctx->gpr[3] = (u32)(product >> 32);
    }

label_8018A620:
    ctx->pc = 0x8018A620u;
    // 8018A620: rlwinm r8, r8, 23, 9, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 23u) & 0x007FFFFFu;
    }

label_8018A624:
    ctx->pc = 0x8018A624u;
    // 8018A624: rlwinm r7, r7, 23, 9, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 23u) & 0x007FFFFFu;
    }

label_8018A628:
    ctx->pc = 0x8018A628u;
    // 8018A628: stw     r8, -26340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26340);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8018A62C:
    ctx->pc = 0x8018A62Cu;
    // 8018A62C: rlwinm r5, r5, 23, 9, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 23u) & 0x007FFFFFu;
    }

label_8018A630:
    ctx->pc = 0x8018A630u;
    // 8018A630: rlwinm r4, r4, 23, 9, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 23u) & 0x007FFFFFu;
    }

label_8018A634:
    ctx->pc = 0x8018A634u;
    // 8018A634: stw     r7, -26332(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26332);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8018A638:
    ctx->pc = 0x8018A638u;
    // 8018A638: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8018A63C:
    ctx->pc = 0x8018A63Cu;
    // 8018A63C: rlwinm r3, r3, 23, 9, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 23u) & 0x007FFFFFu;
    }

label_8018A640:
    ctx->pc = 0x8018A640u;
    // 8018A640: stw     r5, -26324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26324);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018A644:
    ctx->pc = 0x8018A644u;
    // 8018A644: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_8018A648:
    ctx->pc = 0x8018A648u;
    // 8018A648: stw     r3, -26308(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26308);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018A64C:
    ctx->pc = 0x8018A64Cu;
    // 8018A64C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8018A650:
    ctx->pc = 0x8018A650u;
    // 8018A650: lwz     r0, 27648(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A654:
    ctx->pc = 0x8018A654u;
    // 8018A654: stw     r4, -26316(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26316);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018A658:
    ctx->pc = 0x8018A658u;
    // 8018A658: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_8018A65C:
    ctx->pc = 0x8018A65Cu;
    // 8018A65C: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018A660:
    ctx->pc = 0x8018A660u;
    // 8018A660: stw     r31, -26344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26344);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A664:
    ctx->pc = 0x8018A664u;
    // 8018A664: stw     r31, -26336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26336);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A668:
    ctx->pc = 0x8018A668u;
    // 8018A668: stw     r31, -26328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26328);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A66C:
    ctx->pc = 0x8018A66Cu;
    // 8018A66C: stw     r31, -26320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26320);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A670:
    ctx->pc = 0x8018A670u;
    // 8018A670: stw     r31, -26312(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26312);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A674:
    ctx->pc = 0x8018A674u;
    // 8018A674: lwz     r5, 27652(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27652);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018A678:
    ctx->pc = 0x8018A678u;
    // 8018A678: stw     r0, 27648(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A67C:
    ctx->pc = 0x8018A67Cu;
    // 8018A67C: rlwinm r0, r5, 0, 24, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF00FFu;
    }

label_8018A680:
    ctx->pc = 0x8018A680u;
    // 8018A680: nop
    // nop

label_8018A684:
    ctx->pc = 0x8018A684u;
    // 8018A684: stw     r0, 27652(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27652);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A688:
    ctx->pc = 0x8018A688u;
    // 8018A688: lwz     r0, 27652(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27652);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A68C:
    ctx->pc = 0x8018A68Cu;
    // 8018A68C: rlwinm r0, r0, 0, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF00u;
    }

label_8018A690:
    ctx->pc = 0x8018A690u;
    // 8018A690: nop
    // nop

label_8018A694:
    ctx->pc = 0x8018A694u;
    // 8018A694: stw     r0, 27652(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27652);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A698:
    ctx->pc = 0x8018A698u;
    // 8018A698: stw     r31, 27660(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(27660);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A69C:
    ctx->pc = 0x8018A69Cu;
    // 8018A69C: bl      0x8018A464
    {
            ctx->lr = 0x8018A6A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A464u;
                return;
            }
            goto label_8018A464;
    }

label_8018A6A0:
    ctx->pc = 0x8018A6A0u;
    ctx->downcount -= 2;
    // 8018A6A0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A6A4:
    ctx->pc = 0x8018A6A4u;
    // 8018A6A4: bl      0x8018A328
    {
            ctx->lr = 0x8018A6A8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A328u;
                return;
            }
            goto label_8018A328;
    }

label_8018A6A8:
    ctx->pc = 0x8018A6A8u;
    ctx->downcount -= 7;
    // 8018A6A8: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_8018A6AC:
    ctx->pc = 0x8018A6ACu;
    // 8018A6AC: stw     r31, -26368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26368);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A6B0:
    ctx->pc = 0x8018A6B0u;
    // 8018A6B0: addi    r4, r3, -22644
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-22644);

label_8018A6B4:
    ctx->pc = 0x8018A6B4u;
    // 8018A6B4: stw     r31, -26364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26364);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A6B8:
    ctx->pc = 0x8018A6B8u;
    // 8018A6B8: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8018A6BC:
    ctx->pc = 0x8018A6BCu;
    // 8018A6BC: stw     r30, -26360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26360);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A6C0:
    ctx->pc = 0x8018A6C0u;
    // 8018A6C0: bl      0x80173F78
    {
            ctx->lr = 0x8018A6C4u;
            ctx->pc = 0x80173F78u;
            return;
    }

label_8018A6C4:
    ctx->pc = 0x8018A6C4u;
    ctx->downcount -= 2;
    // 8018A6C4: lis     r3, 1024
    ctx->gpr[3] = ((u32)(s32)(1024) << 16);

label_8018A6C8:
    ctx->pc = 0x8018A6C8u;
    // 8018A6C8: bl      0x80174418
    {
            ctx->lr = 0x8018A6CCu;
            ctx->pc = 0x80174418u;
            return;
    }

label_8018A6CC:
    ctx->pc = 0x8018A6CCu;
    ctx->downcount -= 4;
    // 8018A6CC: lis     r3, -32743
    ctx->gpr[3] = ((u32)(s32)(-32743) << 16);

label_8018A6D0:
    ctx->pc = 0x8018A6D0u;
    // 8018A6D0: addi    r4, r3, -22768
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-22768);

label_8018A6D4:
    ctx->pc = 0x8018A6D4u;
    // 8018A6D4: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_8018A6D8:
    ctx->pc = 0x8018A6D8u;
    // 8018A6D8: bl      0x80173F78
    {
            ctx->lr = 0x8018A6DCu;
            ctx->pc = 0x80173F78u;
            return;
    }

label_8018A6DC:
    ctx->pc = 0x8018A6DCu;
    ctx->downcount -= 2;
    // 8018A6DC: lis     r3, 128
    ctx->gpr[3] = ((u32)(s32)(128) << 16);

label_8018A6E0:
    ctx->pc = 0x8018A6E0u;
    // 8018A6E0: bl      0x80174418
    {
            ctx->lr = 0x8018A6E4u;
            ctx->pc = 0x80174418u;
            return;
    }

label_8018A6E4:
    ctx->pc = 0x8018A6E4u;
    ctx->downcount -= 2;
    // 8018A6E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018A6E8:
    ctx->pc = 0x8018A6E8u;
    // 8018A6E8: stw     r0, -26352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26352);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A6EC:
    ctx->pc = 0x8018A6ECu;
    ctx->downcount -= 7;
    // 8018A6EC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A6F0:
    ctx->pc = 0x8018A6F0u;
    // 8018A6F0: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A6F4:
    ctx->pc = 0x8018A6F4u;
    // 8018A6F4: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A6F8:
    ctx->pc = 0x8018A6F8u;
    // 8018A6F8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018A6FC:
    ctx->pc = 0x8018A6FCu;
    // 8018A6FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A700:
    ctx->pc = 0x8018A700u;
    // 8018A700: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A704:
    ctx->pc = 0x8018A704u;
    ctx->downcount -= 3;
    // 8018A704: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018A708:
    ctx->pc = 0x8018A708u;
    // 8018A708: stw     r0, -26352(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26352);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A70C:
    ctx->pc = 0x8018A70Cu;
    // 8018A70C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A710:
    ctx->pc = 0x8018A710u;
    ctx->downcount -= 12;
    // 8018A710: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A714:
    ctx->pc = 0x8018A714u;
    // 8018A714: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A718:
    ctx->pc = 0x8018A718u;
    // 8018A718: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A71C:
    ctx->pc = 0x8018A71Cu;
    // 8018A71C: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A720:
    ctx->pc = 0x8018A720u;
    // 8018A720: lis     r31, -13312
    ctx->gpr[31] = ((u32)(s32)(-13312) << 16);

label_8018A724:
    ctx->pc = 0x8018A724u;
    // 8018A724: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A728:
    ctx->pc = 0x8018A728u;
    // 8018A728: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018A72C:
    ctx->pc = 0x8018A72Cu;
    // 8018A72C: stw     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018A730:
    ctx->pc = 0x8018A730u;
    // 8018A730: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_8018A734:
    ctx->pc = 0x8018A734u;
    // 8018A734: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A738:
    ctx->pc = 0x8018A738u;
    // 8018A738: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_8018A73C:
    ctx->pc = 0x8018A73Cu;
    // 8018A73C: bl      0x8017248C
    {
            ctx->lr = 0x8018A740u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018A740:
    ctx->pc = 0x8018A740u;
    ctx->downcount -= 2;
    // 8018A740: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018A744:
    ctx->pc = 0x8018A744u;
    // 8018A744: bl      0x80172284
    {
            ctx->lr = 0x8018A748u;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018A748:
    ctx->pc = 0x8018A748u;
    ctx->downcount -= 3;
    // 8018A748: lwz     r12, -26368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26368);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8018A74C:
    ctx->pc = 0x8018A74Cu;
    // 8018A74C: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A750:
    ctx->pc = 0x8018A750u;
    // 8018A750: bc    12, 2, 0x8018A764
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A764;
        }
    }

label_8018A754:
    ctx->pc = 0x8018A754u;
    ctx->downcount -= 5;
    // 8018A754: addi    r3, r31, 27648
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(27648);

label_8018A758:
    ctx->pc = 0x8018A758u;
    // 8018A758: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_8018A75C:
    ctx->pc = 0x8018A75Cu;
    // 8018A75C: lwz     r3, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A760:
    ctx->pc = 0x8018A760u;
    // 8018A760: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8018A764u;
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A764:
    ctx->pc = 0x8018A764u;
    ctx->downcount -= 2;
    // 8018A764: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018A768:
    ctx->pc = 0x8018A768u;
    // 8018A768: bl      0x8017248C
    {
            ctx->lr = 0x8018A76Cu;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018A76C:
    ctx->pc = 0x8018A76Cu;
    ctx->downcount -= 2;
    // 8018A76C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8018A770:
    ctx->pc = 0x8018A770u;
    // 8018A770: bl      0x80172284
    {
            ctx->lr = 0x8018A774u;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018A774:
    ctx->pc = 0x8018A774u;
    ctx->downcount -= 7;
    // 8018A774: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A778:
    ctx->pc = 0x8018A778u;
    // 8018A778: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A77C:
    ctx->pc = 0x8018A77Cu;
    // 8018A77C: lwz     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018A780:
    ctx->pc = 0x8018A780u;
    // 8018A780: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_8018A784:
    ctx->pc = 0x8018A784u;
    // 8018A784: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A788:
    ctx->pc = 0x8018A788u;
    // 8018A788: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A78C:
    ctx->pc = 0x8018A78Cu;
    ctx->downcount -= 14;
    // 8018A78C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A790:
    ctx->pc = 0x8018A790u;
    // 8018A790: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018A794:
    ctx->pc = 0x8018A794u;
    // 8018A794: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A798:
    ctx->pc = 0x8018A798u;
    // 8018A798: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018A79C:
    ctx->pc = 0x8018A79Cu;
    // 8018A79C: li      r0, -161
    ctx->gpr[0] = (u32)(s32)(-161);

label_8018A7A0:
    ctx->pc = 0x8018A7A0u;
    // 8018A7A0: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A7A4:
    ctx->pc = 0x8018A7A4u;
    // 8018A7A4: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A7A8:
    ctx->pc = 0x8018A7A8u;
    // 8018A7A8: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_8018A7AC:
    ctx->pc = 0x8018A7ACu;
    // 8018A7AC: lhz     r5, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8018A7B0:
    ctx->pc = 0x8018A7B0u;
    // 8018A7B0: and   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ctx->gpr[0];
    }

label_8018A7B4:
    ctx->pc = 0x8018A7B4u;
    // 8018A7B4: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_8018A7B8:
    ctx->pc = 0x8018A7B8u;
    // 8018A7B8: sth     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018A7BC:
    ctx->pc = 0x8018A7BCu;
    // 8018A7BC: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018A7C0:
    ctx->pc = 0x8018A7C0u;
    // 8018A7C0: bl      0x8017248C
    {
            ctx->lr = 0x8018A7C4u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018A7C4:
    ctx->pc = 0x8018A7C4u;
    ctx->downcount -= 2;
    // 8018A7C4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018A7C8:
    ctx->pc = 0x8018A7C8u;
    // 8018A7C8: bl      0x80172284
    {
            ctx->lr = 0x8018A7CCu;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018A7CC:
    ctx->pc = 0x8018A7CCu;
    ctx->downcount -= 3;
    // 8018A7CC: lwz     r3, -26364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26364);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A7D0:
    ctx->pc = 0x8018A7D0u;
    // 8018A7D0: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A7D4:
    ctx->pc = 0x8018A7D4u;
    // 8018A7D4: bc    12, 2, 0x8018A7F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A7F8;
        }
    }

label_8018A7D8:
    ctx->pc = 0x8018A7D8u;
    ctx->downcount -= 3;
    // 8018A7D8: lwz     r0, -26360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26360);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A7DC:
    ctx->pc = 0x8018A7DCu;
    // 8018A7DC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A7E0:
    ctx->pc = 0x8018A7E0u;
    // 8018A7E0: bc    12, 2, 0x8018A7EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A7EC;
        }
    }

label_8018A7E4:
    ctx->pc = 0x8018A7E4u;
    ctx->downcount -= 1;
    // 8018A7E4: bl      0x8018A81C
    {
            ctx->lr = 0x8018A7E8u;
            goto label_8018A81C;
    }

label_8018A7E8:
    ctx->pc = 0x8018A7E8u;
    ctx->downcount -= 1;
    // 8018A7E8: b       0x8018A7F8
    {
            goto label_8018A7F8;
    }

label_8018A7EC:
    ctx->pc = 0x8018A7ECu;
    ctx->downcount -= 4;
    // 8018A7EC: addi    r12, r3, 0
    ctx->gpr[12] = ctx->gpr[3] + (u32)(s32)(0);

label_8018A7F0:
    ctx->pc = 0x8018A7F0u;
    // 8018A7F0: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_8018A7F4:
    ctx->pc = 0x8018A7F4u;
    // 8018A7F4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8018A7F8u;
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A7F8:
    ctx->pc = 0x8018A7F8u;
    ctx->downcount -= 2;
    // 8018A7F8: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018A7FC:
    ctx->pc = 0x8018A7FCu;
    // 8018A7FC: bl      0x8017248C
    {
            ctx->lr = 0x8018A800u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018A800:
    ctx->pc = 0x8018A800u;
    ctx->downcount -= 2;
    // 8018A800: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018A804:
    ctx->pc = 0x8018A804u;
    // 8018A804: bl      0x80172284
    {
            ctx->lr = 0x8018A808u;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018A808:
    ctx->pc = 0x8018A808u;
    ctx->downcount -= 6;
    // 8018A808: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A80C:
    ctx->pc = 0x8018A80Cu;
    // 8018A80C: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A810:
    ctx->pc = 0x8018A810u;
    // 8018A810: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_8018A814:
    ctx->pc = 0x8018A814u;
    // 8018A814: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A818:
    ctx->pc = 0x8018A818u;
    // 8018A818: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A81C:
    ctx->pc = 0x8018A81Cu;
    ctx->downcount -= 15;
    // 8018A81C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A820:
    ctx->pc = 0x8018A820u;
    // 8018A820: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A824:
    ctx->pc = 0x8018A824u;
    // 8018A824: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A828:
    ctx->pc = 0x8018A828u;
    // 8018A828: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018A82C:
    ctx->pc = 0x8018A82Cu;
    // 8018A82C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A830:
    ctx->pc = 0x8018A830u;
    // 8018A830: lis     r5, -32694
    ctx->gpr[5] = ((u32)(s32)(-32694) << 16);

label_8018A834:
    ctx->pc = 0x8018A834u;
    // 8018A834: addi    r5, r5, 748
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(748);

label_8018A838:
    ctx->pc = 0x8018A838u;
    // 8018A838: stw     r1, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
    }

label_8018A83C:
    ctx->pc = 0x8018A83Cu;
    // 8018A83C: lis     r5, -32694
    ctx->gpr[5] = ((u32)(s32)(-32694) << 16);

label_8018A840:
    ctx->pc = 0x8018A840u;
    // 8018A840: addi    r5, r5, 744
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(744);

label_8018A844:
    ctx->pc = 0x8018A844u;
    // 8018A844: lwz     r1, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[1] = mem_read32(ctx, ea);
    }

label_8018A848:
    ctx->pc = 0x8018A848u;
    // 8018A848: addi    r1, r1, -8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(-8);

label_8018A84C:
    ctx->pc = 0x8018A84Cu;
    // 8018A84C: mtlr    r31
    ctx->lr = ctx->gpr[31];

label_8018A850:
    ctx->pc = 0x8018A850u;
    // 8018A850: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8018A854u;
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A854:
    ctx->pc = 0x8018A854u;
    ctx->downcount -= 9;
    // 8018A854: lis     r5, -32694
    ctx->gpr[5] = ((u32)(s32)(-32694) << 16);

label_8018A858:
    ctx->pc = 0x8018A858u;
    // 8018A858: addi    r5, r5, 748
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(748);

label_8018A85C:
    ctx->pc = 0x8018A85Cu;
    // 8018A85C: lwz     r1, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[1] = mem_read32(ctx, ea);
    }

label_8018A860:
    ctx->pc = 0x8018A860u;
    // 8018A860: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A864:
    ctx->pc = 0x8018A864u;
    // 8018A864: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018A868:
    ctx->pc = 0x8018A868u;
    // 8018A868: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018A86C:
    ctx->pc = 0x8018A86Cu;
    // 8018A86C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018A870:
    ctx->pc = 0x8018A870u;
    // 8018A870: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018A874:
    ctx->pc = 0x8018A874u;
    ctx->downcount -= 20;
    // 8018A874: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018A878:
    ctx->pc = 0x8018A878u;
    // 8018A878: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A87C:
    ctx->pc = 0x8018A87Cu;
    // 8018A87C: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018A880:
    ctx->pc = 0x8018A880u;
    // 8018A880: stmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8018A884:
    ctx->pc = 0x8018A884u;
    // 8018A884: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8018A888:
    ctx->pc = 0x8018A888u;
    // 8018A888: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018A88C:
    ctx->pc = 0x8018A88Cu;
    // 8018A88C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018A890:
    ctx->pc = 0x8018A890u;
    // 8018A890: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8018A894:
    ctx->pc = 0x8018A894u;
    // 8018A894: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8018A898:
    ctx->pc = 0x8018A898u;
    // 8018A898: b       0x8018A89C
    {
            goto label_8018A89C;
    }

label_8018A89C:
    ctx->pc = 0x8018A89Cu;
    ctx->downcount -= 2;
    // 8018A89C: lis     r31, -13312
    ctx->gpr[31] = ((u32)(s32)(-13312) << 16);

label_8018A8A0:
    ctx->pc = 0x8018A8A0u;
    // 8018A8A0: b       0x8018A8A4
    {
            goto label_8018A8A4;
    }

label_8018A8A4:
    ctx->pc = 0x8018A8A4u;
    ctx->downcount -= 1;
    // 8018A8A4: b       0x8018AA08
    {
            goto label_8018AA08;
    }

label_8018A8A8:
    ctx->pc = 0x8018A8A8u;
    ctx->downcount -= 15;
    // 8018A8A8: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A8AC:
    // 8018A8AC: addi    r30, r31, 27648
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(27648);

label_8018A8B0:
    // 8018A8B0: addi    r30, r30, 8
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(8);

label_8018A8B4:
    // 8018A8B4: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_8018A8B8:
    // 8018A8B8: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018A8BC:
    ctx->pc = 0x8018A8BCu;
    // 8018A8BC: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A8C0:
    ctx->pc = 0x8018A8C0u;
    // 8018A8C0: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A8C4:
    // 8018A8C4: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_8018A8C8:
    ctx->pc = 0x8018A8C8u;
    // 8018A8C8: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A8CC:
    ctx->pc = 0x8018A8CCu;
    // 8018A8CC: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A8D0:
    // 8018A8D0: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8018A8D4:
    // 8018A8D4: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_8018A8D8:
    ctx->pc = 0x8018A8D8u;
    // 8018A8D8: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A8DC:
    ctx->pc = 0x8018A8DCu;
    // 8018A8DC: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A8E0:
    // 8018A8E0: b       0x8018A8E4
    {
            goto label_8018A8E4;
    }

label_8018A8E4:
    ctx->downcount -= 1;
    // 8018A8E4: b       0x8018A8E8
    {
            goto label_8018A8E8;
    }

label_8018A8E8:
    loop_8018A8E8(ctx);
    if (ctx->pc == 0x8018A8F4u) goto label_8018A8F4;
    return;
label_8018A8EC:
    // 8018A8EC: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A8F0:
    // 8018A8F0: bc    12, 2, 0x8018A8E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A8E8u;
                return;
            }
            goto label_8018A8E8;
        }
    }

label_8018A8F4:
    ctx->downcount -= 1;
    // 8018A8F4: bl      0x80179FF4
    {
            ctx->lr = 0x8018A8F8u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_8018A8F8:
    ctx->pc = 0x8018A8F8u;
    ctx->downcount -= 12;
    // 8018A8F8: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A8FC:
    // 8018A8FC: or   r26, r4, r4
    {
        ctx->gpr[26] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8018A900:
    // 8018A900: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018A904:
    // 8018A904: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_8018A908:
    // 8018A908: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_8018A90C:
    ctx->pc = 0x8018A90Cu;
    // 8018A90C: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A910:
    ctx->pc = 0x8018A910u;
    // 8018A910: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A914:
    // 8018A914: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8018A918:
    // 8018A918: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_8018A91C:
    ctx->pc = 0x8018A91Cu;
    // 8018A91C: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A920:
    ctx->pc = 0x8018A920u;
    // 8018A920: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018A924:
    // 8018A924: b       0x8018A928
    {
            goto label_8018A928;
    }

label_8018A928:
    ctx->downcount -= 1;
    // 8018A928: b       0x8018A92C
    {
            goto label_8018A92C;
    }

label_8018A92C:
    loop_8018A92C(ctx);
    if (ctx->pc == 0x8018A938u) goto label_8018A938;
    return;
label_8018A930:
    // 8018A930: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A934:
    // 8018A934: bc    12, 2, 0x8018A92C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A92Cu;
                return;
            }
            goto label_8018A92C;
        }
    }

label_8018A938:
    ctx->downcount -= 1;
    // 8018A938: bl      0x80179FF4
    {
            ctx->lr = 0x8018A93Cu;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_8018A93C:
    ctx->downcount -= 22;
    // 8018A93C: subfc   r8, r26, r4
    {
        u32 a = ~ctx->gpr[26];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[8] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A940:
    ctx->pc = 0x8018A940u;
    // 8018A940: lwz     r12, -26340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26340);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8018A944:
    ctx->pc = 0x8018A944u;
    // 8018A944: lwz     r5, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018A948:
    // 8018A948: subfe   r7, r27, r3
    {
        u32 a = ~ctx->gpr[27];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[7] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A94C:
    ctx->pc = 0x8018A94Cu;
    // 8018A94C: lwz     r10, -26308(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26308);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8018A950:
    // 8018A950: xoris   r7, r7, 0x8000
    ctx->gpr[7] = ctx->gpr[7] ^ (0x8000u << 16);

label_8018A954:
    // 8018A954: rlwinm r5, r5, 0, 31, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFDu;
    }

label_8018A958:
    ctx->pc = 0x8018A958u;
    // 8018A958: lwz     r11, -26344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26344);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8018A95C:
    // 8018A95C: subfc   r6, r10, r12
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[12];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[6] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A960:
    ctx->pc = 0x8018A960u;
    // 8018A960: lwz     r9, -26312(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26312);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8018A964:
    ctx->pc = 0x8018A964u;
    // 8018A964: stw     r5, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018A968:
    // 8018A968: subfe   r0, r9, r11
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A96C:
    // 8018A96C: xoris   r5, r0, 0x8000
    ctx->gpr[5] = ctx->gpr[0] ^ (0x8000u << 16);

label_8018A970:
    // 8018A970: subfc   r0, r6, r8
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A974:
    ctx->pc = 0x8018A974u;
    // 8018A974: lwz     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A978:
    // 8018A978: subfe   r5, r5, r7
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A97C:
    // 8018A97C: subfe   r5, r7, r7
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[7];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A980:
    // 8018A980: neg  r5, r5
    {
        u32 a = ctx->gpr[5];
        ctx->gpr[5] = (~a) + 1u;
    }

label_8018A984:
    // 8018A984: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8018A988:
    // 8018A988: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A98C:
    ctx->pc = 0x8018A98Cu;
    // 8018A98C: stw     r0, 27648(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27648);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018A990:
    // 8018A990: bc    12, 2, 0x8018A9A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018A9A4;
        }
    }

label_8018A994:
    ctx->pc = 0x8018A994u;
    ctx->downcount -= 4;
    // 8018A994: lwz     r29, -26328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26328);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018A998:
    // 8018A998: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018A99C:
    ctx->pc = 0x8018A99Cu;
    // 8018A99C: lwz     r28, -26324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26324);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8018A9A0:
    // 8018A9A0: b       0x8018AA08
    {
            goto label_8018AA08;
    }

label_8018A9A4:
    ctx->downcount -= 9;
    // 8018A9A4: addc   r6, r12, r10
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[10];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[6] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9A8:
    // 8018A9A8: adde   r0, r11, r9
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9AC:
    // 8018A9AC: xoris   r5, r0, 0x8000
    ctx->gpr[5] = ctx->gpr[0] ^ (0x8000u << 16);

label_8018A9B0:
    // 8018A9B0: subfc   r0, r6, r8
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9B4:
    // 8018A9B4: subfe   r5, r5, r7
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9B8:
    // 8018A9B8: subfe   r5, r7, r7
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[7];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9BC:
    // 8018A9BC: neg  r5, r5
    {
        u32 a = ctx->gpr[5];
        ctx->gpr[5] = (~a) + 1u;
    }

label_8018A9C0:
    // 8018A9C0: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A9C4:
    // 8018A9C4: bc    4, 2, 0x8018AA04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018AA04;
        }
    }

label_8018A9C8:
    ctx->pc = 0x8018A9C8u;
    ctx->downcount -= 11;
    // 8018A9C8: lwz     r5, -26332(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26332);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018A9CC:
    ctx->pc = 0x8018A9CCu;
    // 8018A9CC: lwz     r0, -26336(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26336);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018A9D0:
    // 8018A9D0: subfc   r6, r10, r5
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[6] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9D4:
    // 8018A9D4: subfe   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9D8:
    // 8018A9D8: xoris   r5, r0, 0x8000
    ctx->gpr[5] = ctx->gpr[0] ^ (0x8000u << 16);

label_8018A9DC:
    // 8018A9DC: subfc   r0, r6, r8
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9E0:
    // 8018A9E0: subfe   r5, r5, r7
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9E4:
    // 8018A9E4: subfe   r5, r7, r7
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[7];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018A9E8:
    // 8018A9E8: neg  r5, r5
    {
        u32 a = ctx->gpr[5];
        ctx->gpr[5] = (~a) + 1u;
    }

label_8018A9EC:
    // 8018A9EC: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018A9F0:
    // 8018A9F0: bc    12, 2, 0x8018AA04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AA04;
        }
    }

label_8018A9F4:
    ctx->pc = 0x8018A9F4u;
    ctx->downcount -= 4;
    // 8018A9F4: lwz     r29, -26320(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26320);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018A9F8:
    // 8018A9F8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018A9FC:
    ctx->pc = 0x8018A9FCu;
    // 8018A9FC: lwz     r28, -26316(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26316);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8018AA00:
    // 8018AA00: b       0x8018AA08
    {
            goto label_8018AA08;
    }

label_8018AA04:
    ctx->downcount -= 1;
    // 8018AA04: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018AA08:
    ctx->downcount -= 2;
    // 8018AA08: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018AA0C:
    // 8018AA0C: bc    12, 2, 0x8018A8A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018A8A8u;
                return;
            }
            goto label_8018A8A8;
        }
    }

label_8018AA10:
    ctx->pc = 0x8018AA10u;
    ctx->downcount -= 3;
    // 8018AA10: addc   r27, r4, r28
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[28];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[27] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018AA14:
    ctx->pc = 0x8018AA14u;
    // 8018AA14: adde   r26, r3, r29
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[26] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018AA18:
    ctx->pc = 0x8018AA18u;
    // 8018AA18: b       0x8018AA1C
    {
            goto label_8018AA1C;
    }

label_8018AA1C:
    ctx->pc = 0x8018AA1Cu;
    ctx->downcount -= 1;
    // 8018AA1C: b       0x8018AA20
    {
            goto label_8018AA20;
    }

label_8018AA20:
    ctx->downcount -= 1;
    // 8018AA20: bl      0x80179FF4
    {
            ctx->lr = 0x8018AA24u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_8018AA24:
    ctx->downcount -= 8;
    // 8018AA24: xoris   r5, r3, 0x8000
    ctx->gpr[5] = ctx->gpr[3] ^ (0x8000u << 16);

label_8018AA28:
    // 8018AA28: xoris   r3, r26, 0x8000
    ctx->gpr[3] = ctx->gpr[26] ^ (0x8000u << 16);

label_8018AA2C:
    // 8018AA2C: subfc   r0, r27, r4
    {
        u32 a = ~ctx->gpr[27];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018AA30:
    // 8018AA30: subfe   r3, r3, r5
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018AA34:
    // 8018AA34: subfe   r3, r5, r5
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[5];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018AA38:
    // 8018AA38: neg  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
    }

label_8018AA3C:
    // 8018AA3C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018AA40:
    // 8018AA40: bc    4, 2, 0x8018AA20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018AA20u;
                return;
            }
            goto label_8018AA20;
        }
    }

label_8018AA44:
    ctx->pc = 0x8018AA44u;
    ctx->downcount -= 16;
    // 8018AA44: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8018AA48:
    ctx->pc = 0x8018AA48u;
    // 8018AA48: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AA4C:
    ctx->pc = 0x8018AA4Cu;
    // 8018AA4C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8018AA50:
    ctx->pc = 0x8018AA50u;
    // 8018AA50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AA54:
    ctx->pc = 0x8018AA54u;
    // 8018AA54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AA58:
    ctx->pc = 0x8018AA58u;
    ctx->downcount -= 2;
    // 8018AA58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018AA5C:
    ctx->pc = 0x8018AA5Cu;
    // 8018AA5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AA60:
    ctx->pc = 0x8018AA60u;
    ctx->downcount -= 8;
    // 8018AA60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018AA64:
    ctx->pc = 0x8018AA64u;
    // 8018AA64: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AA68:
    ctx->pc = 0x8018AA68u;
    // 8018AA68: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018AA6C:
    ctx->pc = 0x8018AA6Cu;
    // 8018AA6C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018AA70:
    ctx->pc = 0x8018AA70u;
    // 8018AA70: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018AA74:
    ctx->pc = 0x8018AA74u;
    // 8018AA74: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018AA78:
    ctx->pc = 0x8018AA78u;
    // 8018AA78: lwz     r31, -26288(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26288);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018AA7C:
    ctx->pc = 0x8018AA7Cu;
    // 8018AA7C: bl      0x80173F2C
    {
            ctx->lr = 0x8018AA80u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018AA80:
    ctx->pc = 0x8018AA80u;
    ctx->downcount -= 2;
    // 8018AA80: stw     r30, -26288(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26288);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018AA84:
    ctx->pc = 0x8018AA84u;
    // 8018AA84: bl      0x80173F54
    {
            ctx->lr = 0x8018AA88u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018AA88:
    ctx->pc = 0x8018AA88u;
    ctx->downcount -= 8;
    // 8018AA88: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018AA8C:
    ctx->pc = 0x8018AA8Cu;
    // 8018AA8C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AA90:
    ctx->pc = 0x8018AA90u;
    // 8018AA90: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018AA94:
    ctx->pc = 0x8018AA94u;
    // 8018AA94: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018AA98:
    ctx->pc = 0x8018AA98u;
    // 8018AA98: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018AA9C:
    ctx->pc = 0x8018AA9Cu;
    // 8018AA9C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AAA0:
    ctx->pc = 0x8018AAA0u;
    // 8018AAA0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AAA4:
    ctx->pc = 0x8018AAA4u;
    ctx->downcount -= 5;
    // 8018AAA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018AAA8:
    ctx->pc = 0x8018AAA8u;
    // 8018AAA8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AAAC:
    ctx->pc = 0x8018AAACu;
    // 8018AAAC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018AAB0:
    ctx->pc = 0x8018AAB0u;
    // 8018AAB0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018AAB4:
    ctx->pc = 0x8018AAB4u;
    // 8018AAB4: bl      0x80173F2C
    {
            ctx->lr = 0x8018AAB8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018AAB8:
    ctx->pc = 0x8018AAB8u;
    ctx->downcount -= 4;
    // 8018AAB8: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018AABC:
    ctx->pc = 0x8018AABCu;
    // 8018AABC: lhz     r0, 20490(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20490);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018AAC0:
    ctx->pc = 0x8018AAC0u;
    // 8018AAC0: rlwinm r31, r0, 0, 22, 22
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_8018AAC4:
    ctx->pc = 0x8018AAC4u;
    // 8018AAC4: bl      0x80173F54
    {
            ctx->lr = 0x8018AAC8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018AAC8:
    ctx->pc = 0x8018AAC8u;
    ctx->downcount -= 7;
    // 8018AAC8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018AACC:
    ctx->pc = 0x8018AACCu;
    // 8018AACC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AAD0:
    ctx->pc = 0x8018AAD0u;
    // 8018AAD0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018AAD4:
    ctx->pc = 0x8018AAD4u;
    // 8018AAD4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8018AAD8:
    ctx->pc = 0x8018AAD8u;
    // 8018AAD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AADC:
    ctx->pc = 0x8018AADCu;
    // 8018AADC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AAE0:
    ctx->pc = 0x8018AAE0u;
    ctx->downcount -= 12;
    // 8018AAE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018AAE4:
    ctx->pc = 0x8018AAE4u;
    // 8018AAE4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AAE8:
    ctx->pc = 0x8018AAE8u;
    // 8018AAE8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018AAEC:
    ctx->pc = 0x8018AAECu;
    // 8018AAEC: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018AAF0:
    ctx->pc = 0x8018AAF0u;
    // 8018AAF0: addi    r31, r6, 0
    ctx->gpr[31] = ctx->gpr[6] + (u32)(s32)(0);

label_8018AAF4:
    ctx->pc = 0x8018AAF4u;
    // 8018AAF4: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018AAF8:
    ctx->pc = 0x8018AAF8u;
    // 8018AAF8: addi    r30, r5, 0
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(0);

label_8018AAFC:
    ctx->pc = 0x8018AAFCu;
    // 8018AAFC: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018AB00:
    ctx->pc = 0x8018AB00u;
    // 8018AB00: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_8018AB04:
    ctx->pc = 0x8018AB04u;
    // 8018AB04: stw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8018AB08:
    ctx->pc = 0x8018AB08u;
    // 8018AB08: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_8018AB0C:
    ctx->pc = 0x8018AB0Cu;
    // 8018AB0C: bl      0x80173F2C
    {
            ctx->lr = 0x8018AB10u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018AB10:
    ctx->pc = 0x8018AB10u;
    ctx->downcount -= 40;
    // 8018AB10: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_8018AB14:
    ctx->pc = 0x8018AB14u;
    // 8018AB14: lhz     r0, 20512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018AB18:
    ctx->pc = 0x8018AB18u;
    // 8018AB18: addi    r8, r6, 20480
    ctx->gpr[8] = ctx->gpr[6] + (u32)(s32)(20480);

label_8018AB1C:
    ctx->pc = 0x8018AB1Cu;
    // 8018AB1C: addi    r9, r6, 20480
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(20480);

label_8018AB20:
    ctx->pc = 0x8018AB20u;
    // 8018AB20: rlwinm r4, r0, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018AB24:
    ctx->pc = 0x8018AB24u;
    // 8018AB24: rlwinm r0, r28, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 16u) & 0x0000FFFFu;
    }

label_8018AB28:
    ctx->pc = 0x8018AB28u;
    // 8018AB28: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018AB2C:
    ctx->pc = 0x8018AB2Cu;
    // 8018AB2C: sth     r0, 20512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20512);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AB30:
    ctx->pc = 0x8018AB30u;
    // 8018AB30: rlwinm r0, r28, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x0000FFFFu;
    }

label_8018AB34:
    ctx->pc = 0x8018AB34u;
    // 8018AB34: addi    r4, r6, 20480
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(20480);

label_8018AB38:
    ctx->pc = 0x8018AB38u;
    // 8018AB38: lhz     r5, 20514(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20514);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8018AB3C:
    ctx->pc = 0x8018AB3Cu;
    // 8018AB3C: rlwinm r5, r5, 0, 27, 15
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF001Fu;
    }

label_8018AB40:
    ctx->pc = 0x8018AB40u;
    // 8018AB40: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8018AB44:
    ctx->pc = 0x8018AB44u;
    // 8018AB44: sth     r0, 20514(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20514);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AB48:
    ctx->pc = 0x8018AB48u;
    // 8018AB48: addi    r5, r6, 20480
    ctx->gpr[5] = ctx->gpr[6] + (u32)(s32)(20480);

label_8018AB4C:
    ctx->pc = 0x8018AB4Cu;
    // 8018AB4C: rlwinm r0, r30, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 16u) & 0x0000FFFFu;
    }

label_8018AB50:
    ctx->pc = 0x8018AB50u;
    // 8018AB50: lhz     r6, 20516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20516);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8018AB54:
    ctx->pc = 0x8018AB54u;
    // 8018AB54: rlwinm r6, r6, 0, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFC00u;
    }

label_8018AB58:
    ctx->pc = 0x8018AB58u;
    // 8018AB58: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_8018AB5C:
    ctx->pc = 0x8018AB5Cu;
    // 8018AB5C: sth     r0, 36(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(36);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AB60:
    ctx->pc = 0x8018AB60u;
    // 8018AB60: rlwinm r0, r30, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_8018AB64:
    ctx->pc = 0x8018AB64u;
    // 8018AB64: lhz     r6, 38(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(38);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8018AB68:
    ctx->pc = 0x8018AB68u;
    // 8018AB68: rlwinm r6, r6, 0, 27, 15
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFF001Fu;
    }

label_8018AB6C:
    ctx->pc = 0x8018AB6Cu;
    // 8018AB6C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_8018AB70:
    ctx->pc = 0x8018AB70u;
    // 8018AB70: sth     r0, 38(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AB74:
    ctx->pc = 0x8018AB74u;
    // 8018AB74: rlwinm r6, r31, 16, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[31], 16u) & 0x0000FFFFu;
    }

label_8018AB78:
    ctx->pc = 0x8018AB78u;
    // 8018AB78: rlwinm r0, r31, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x0000FFFFu;
    }

label_8018AB7C:
    ctx->pc = 0x8018AB7Cu;
    // 8018AB7C: lhz     r7, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_8018AB80:
    ctx->pc = 0x8018AB80u;
    // 8018AB80: rlwinm r7, r7, 0, 17, 15
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFF7FFFu;
    }

label_8018AB84:
    ctx->pc = 0x8018AB84u;
    // 8018AB84: rlwimi r7, r29, 15, 0, 16
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[29], 15u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0xFFFF8000u) | (rot & 0xFFFF8000u);
    }

label_8018AB88:
    ctx->pc = 0x8018AB88u;
    // 8018AB88: sth     r7, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8018AB8C:
    ctx->pc = 0x8018AB8Cu;
    // 8018AB8C: lhz     r7, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_8018AB90:
    ctx->pc = 0x8018AB90u;
    // 8018AB90: rlwinm r7, r7, 0, 0, 21
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFC00u;
    }

label_8018AB94:
    ctx->pc = 0x8018AB94u;
    // 8018AB94: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_8018AB98:
    ctx->pc = 0x8018AB98u;
    // 8018AB98: sth     r6, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8018AB9C:
    ctx->pc = 0x8018AB9Cu;
    // 8018AB9C: lhz     r4, 42(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(42);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018ABA0:
    ctx->pc = 0x8018ABA0u;
    // 8018ABA0: rlwinm r4, r4, 0, 27, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF001Fu;
    }

label_8018ABA4:
    ctx->pc = 0x8018ABA4u;
    // 8018ABA4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018ABA8:
    ctx->pc = 0x8018ABA8u;
    // 8018ABA8: sth     r0, 42(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018ABAC:
    ctx->pc = 0x8018ABACu;
    // 8018ABAC: bl      0x80173F54
    {
            ctx->lr = 0x8018ABB0u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018ABB0:
    ctx->pc = 0x8018ABB0u;
    ctx->downcount -= 9;
    // 8018ABB0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018ABB4:
    ctx->pc = 0x8018ABB4u;
    // 8018ABB4: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018ABB8:
    ctx->pc = 0x8018ABB8u;
    // 8018ABB8: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018ABBC:
    ctx->pc = 0x8018ABBCu;
    // 8018ABBC: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018ABC0:
    ctx->pc = 0x8018ABC0u;
    // 8018ABC0: lwz     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8018ABC4:
    ctx->pc = 0x8018ABC4u;
    // 8018ABC4: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8018ABC8:
    ctx->pc = 0x8018ABC8u;
    // 8018ABC8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018ABCC:
    ctx->pc = 0x8018ABCCu;
    // 8018ABCC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018ABD0:
    ctx->pc = 0x8018ABD0u;
    ctx->downcount -= 7;
    // 8018ABD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018ABD4:
    ctx->pc = 0x8018ABD4u;
    // 8018ABD4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018ABD8:
    ctx->pc = 0x8018ABD8u;
    // 8018ABD8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018ABDC:
    ctx->pc = 0x8018ABDCu;
    // 8018ABDC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018ABE0:
    ctx->pc = 0x8018ABE0u;
    // 8018ABE0: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018ABE4:
    ctx->pc = 0x8018ABE4u;
    // 8018ABE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018ABE8:
    ctx->pc = 0x8018ABE8u;
    // 8018ABE8: bl      0x80173F2C
    {
            ctx->lr = 0x8018ABECu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018ABEC:
    ctx->pc = 0x8018ABECu;
    ctx->downcount -= 12;
    // 8018ABEC: lwz     r31, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018ABF0:
    ctx->pc = 0x8018ABF0u;
    // 8018ABF0: lwz     r4, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018ABF4:
    ctx->pc = 0x8018ABF4u;
    // 8018ABF4: add   r0, r31, r30
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018ABF8:
    ctx->pc = 0x8018ABF8u;
    // 8018ABF8: stw     r0, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018ABFC:
    ctx->pc = 0x8018ABFCu;
    // 8018ABFC: stw     r30, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018AC00:
    ctx->pc = 0x8018AC00u;
    // 8018AC00: lwz     r5, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018AC04:
    ctx->pc = 0x8018AC04u;
    // 8018AC04: lwz     r4, -26268(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018AC08:
    ctx->pc = 0x8018AC08u;
    // 8018AC08: addi    r5, r5, 4
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(4);

label_8018AC0C:
    ctx->pc = 0x8018AC0Cu;
    // 8018AC0C: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_8018AC10:
    ctx->pc = 0x8018AC10u;
    // 8018AC10: stw     r5, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018AC14:
    ctx->pc = 0x8018AC14u;
    // 8018AC14: stw     r0, -26268(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AC18:
    ctx->pc = 0x8018AC18u;
    // 8018AC18: bl      0x80173F54
    {
            ctx->lr = 0x8018AC1Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018AC1C:
    ctx->pc = 0x8018AC1Cu;
    ctx->downcount -= 8;
    // 8018AC1C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018AC20:
    ctx->pc = 0x8018AC20u;
    // 8018AC20: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AC24:
    ctx->pc = 0x8018AC24u;
    // 8018AC24: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018AC28:
    ctx->pc = 0x8018AC28u;
    // 8018AC28: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018AC2C:
    ctx->pc = 0x8018AC2Cu;
    // 8018AC2C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018AC30:
    ctx->pc = 0x8018AC30u;
    // 8018AC30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AC34:
    ctx->pc = 0x8018AC34u;
    // 8018AC34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AC38:
    ctx->pc = 0x8018AC38u;
    ctx->downcount -= 6;
    // 8018AC38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018AC3C:
    ctx->pc = 0x8018AC3Cu;
    // 8018AC3C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AC40:
    ctx->pc = 0x8018AC40u;
    // 8018AC40: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018AC44:
    ctx->pc = 0x8018AC44u;
    // 8018AC44: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018AC48:
    ctx->pc = 0x8018AC48u;
    // 8018AC48: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018AC4C:
    ctx->pc = 0x8018AC4Cu;
    // 8018AC4C: bl      0x80173F2C
    {
            ctx->lr = 0x8018AC50u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018AC50:
    ctx->pc = 0x8018AC50u;
    ctx->downcount -= 5;
    // 8018AC50: lwz     r4, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018AC54:
    ctx->pc = 0x8018AC54u;
    // 8018AC54: cmplwi  r31, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018AC58:
    ctx->pc = 0x8018AC58u;
    // 8018AC58: addi    r0, r4, -4
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-4);

label_8018AC5C:
    ctx->pc = 0x8018AC5Cu;
    // 8018AC5C: stw     r0, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AC60:
    ctx->pc = 0x8018AC60u;
    // 8018AC60: bc    12, 2, 0x8018AC70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AC70;
        }
    }

label_8018AC64:
    ctx->pc = 0x8018AC64u;
    ctx->downcount -= 3;
    // 8018AC64: lwz     r4, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018AC68:
    ctx->pc = 0x8018AC68u;
    // 8018AC68: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AC6C:
    ctx->pc = 0x8018AC6Cu;
    // 8018AC6C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AC70:
    ctx->pc = 0x8018AC70u;
    ctx->downcount -= 9;
    // 8018AC70: lwz     r5, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018AC74:
    ctx->pc = 0x8018AC74u;
    // 8018AC74: lwz     r4, -26268(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018AC78:
    ctx->pc = 0x8018AC78u;
    // 8018AC78: lwz     r6, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8018AC7C:
    ctx->pc = 0x8018AC7Cu;
    // 8018AC7C: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_8018AC80:
    ctx->pc = 0x8018AC80u;
    // 8018AC80: lwz     r5, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018AC84:
    ctx->pc = 0x8018AC84u;
    // 8018AC84: stw     r0, -26268(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AC88:
    ctx->pc = 0x8018AC88u;
    // 8018AC88: subf   r0, r6, r5
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8018AC8C:
    ctx->pc = 0x8018AC8Cu;
    // 8018AC8C: stw     r0, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AC90:
    ctx->pc = 0x8018AC90u;
    // 8018AC90: bl      0x80173F54
    {
            ctx->lr = 0x8018AC94u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018AC94:
    ctx->pc = 0x8018AC94u;
    ctx->downcount -= 7;
    // 8018AC94: lwz     r3, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018AC98:
    ctx->pc = 0x8018AC98u;
    // 8018AC98: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AC9C:
    ctx->pc = 0x8018AC9Cu;
    // 8018AC9C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018ACA0:
    ctx->pc = 0x8018ACA0u;
    // 8018ACA0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018ACA4:
    ctx->pc = 0x8018ACA4u;
    // 8018ACA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018ACA8:
    ctx->pc = 0x8018ACA8u;
    // 8018ACA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018ACAC:
    ctx->pc = 0x8018ACACu;
    ctx->downcount -= 2;
    // 8018ACAC: lwz     r3, -26260(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26260);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018ACB0:
    ctx->pc = 0x8018ACB0u;
    // 8018ACB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018ACB4:
    ctx->pc = 0x8018ACB4u;
    ctx->downcount -= 11;
    // 8018ACB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018ACB8:
    ctx->pc = 0x8018ACB8u;
    // 8018ACB8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018ACBC:
    ctx->pc = 0x8018ACBCu;
    // 8018ACBC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018ACC0:
    ctx->pc = 0x8018ACC0u;
    // 8018ACC0: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018ACC4:
    ctx->pc = 0x8018ACC4u;
    // 8018ACC4: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018ACC8:
    ctx->pc = 0x8018ACC8u;
    // 8018ACC8: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_8018ACCC:
    ctx->pc = 0x8018ACCCu;
    // 8018ACCC: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018ACD0:
    ctx->pc = 0x8018ACD0u;
    // 8018ACD0: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_8018ACD4:
    ctx->pc = 0x8018ACD4u;
    // 8018ACD4: lwz     r0, -26260(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26260);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018ACD8:
    ctx->pc = 0x8018ACD8u;
    // 8018ACD8: cmpwi   r0, 1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018ACDC:
    ctx->pc = 0x8018ACDCu;
    // 8018ACDC: bc    4, 2, 0x8018ACE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018ACE8;
        }
    }

label_8018ACE0:
    ctx->pc = 0x8018ACE0u;
    ctx->downcount -= 2;
    // 8018ACE0: li      r3, 16384
    ctx->gpr[3] = (u32)(s32)(16384);

label_8018ACE4:
    ctx->pc = 0x8018ACE4u;
    // 8018ACE4: b       0x8018AD54
    {
            goto label_8018AD54;
    }

label_8018ACE8:
    ctx->pc = 0x8018ACE8u;
    ctx->downcount -= 1;
    // 8018ACE8: bl      0x80173F2C
    {
            ctx->lr = 0x8018ACECu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018ACEC:
    ctx->pc = 0x8018ACECu;
    ctx->downcount -= 7;
    // 8018ACEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018ACF0:
    ctx->pc = 0x8018ACF0u;
    // 8018ACF0: lis     r4, -32743
    ctx->gpr[4] = ((u32)(s32)(-32743) << 16);

label_8018ACF4:
    ctx->pc = 0x8018ACF4u;
    // 8018ACF4: stw     r0, -26288(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26288);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018ACF8:
    ctx->pc = 0x8018ACF8u;
    // 8018ACF8: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_8018ACFC:
    ctx->pc = 0x8018ACFCu;
    // 8018ACFC: addi    r4, r4, -20952
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-20952);

label_8018AD00:
    ctx->pc = 0x8018AD00u;
    // 8018AD00: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_8018AD04:
    ctx->pc = 0x8018AD04u;
    // 8018AD04: bl      0x80173F78
    {
            ctx->lr = 0x8018AD08u;
            ctx->pc = 0x80173F78u;
            return;
    }

label_8018AD08:
    ctx->pc = 0x8018AD08u;
    ctx->downcount -= 2;
    // 8018AD08: lis     r3, 512
    ctx->gpr[3] = ((u32)(s32)(512) << 16);

label_8018AD0C:
    ctx->pc = 0x8018AD0Cu;
    // 8018AD0C: bl      0x80174418
    {
            ctx->lr = 0x8018AD10u;
            ctx->pc = 0x80174418u;
            return;
    }

label_8018AD10:
    ctx->pc = 0x8018AD10u;
    ctx->downcount -= 12;
    // 8018AD10: li      r0, 16384
    ctx->gpr[0] = (u32)(s32)(16384);

label_8018AD14:
    ctx->pc = 0x8018AD14u;
    // 8018AD14: stw     r30, -26268(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26268);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018AD18:
    ctx->pc = 0x8018AD18u;
    // 8018AD18: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018AD1C:
    ctx->pc = 0x8018AD1Cu;
    // 8018AD1C: stw     r0, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AD20:
    ctx->pc = 0x8018AD20u;
    // 8018AD20: addi    r4, r3, 20480
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018AD24:
    ctx->pc = 0x8018AD24u;
    // 8018AD24: stw     r29, -26264(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26264);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018AD28:
    ctx->pc = 0x8018AD28u;
    // 8018AD28: lhz     r0, 26(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(26);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018AD2C:
    ctx->pc = 0x8018AD2Cu;
    // 8018AD2C: lhz     r3, 20506(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20506);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018AD30:
    ctx->pc = 0x8018AD30u;
    // 8018AD30: rlwinm r0, r0, 0, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF00u;
    }

label_8018AD34:
    ctx->pc = 0x8018AD34u;
    // 8018AD34: rlwimi r0, r3, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8018AD38:
    ctx->pc = 0x8018AD38u;
    // 8018AD38: sth     r0, 26(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AD3C:
    ctx->pc = 0x8018AD3Cu;
    // 8018AD3C: bl      0x8018B048
    {
            ctx->lr = 0x8018AD40u;
            goto label_8018B048;
    }

label_8018AD40:
    ctx->pc = 0x8018AD40u;
    ctx->downcount -= 4;
    // 8018AD40: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018AD44:
    ctx->pc = 0x8018AD44u;
    // 8018AD44: stw     r0, -26260(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26260);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AD48:
    ctx->pc = 0x8018AD48u;
    // 8018AD48: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018AD4C:
    ctx->pc = 0x8018AD4Cu;
    // 8018AD4C: bl      0x80173F54
    {
            ctx->lr = 0x8018AD50u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018AD50:
    ctx->pc = 0x8018AD50u;
    ctx->downcount -= 1;
    // 8018AD50: lwz     r3, -26272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26272);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018AD54:
    ctx->pc = 0x8018AD54u;
    ctx->downcount -= 8;
    // 8018AD54: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AD58:
    ctx->pc = 0x8018AD58u;
    // 8018AD58: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018AD5C:
    ctx->pc = 0x8018AD5Cu;
    // 8018AD5C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018AD60:
    ctx->pc = 0x8018AD60u;
    // 8018AD60: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018AD64:
    ctx->pc = 0x8018AD64u;
    // 8018AD64: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8018AD68:
    ctx->pc = 0x8018AD68u;
    // 8018AD68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AD6C:
    ctx->pc = 0x8018AD6Cu;
    // 8018AD6C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AD70:
    ctx->pc = 0x8018AD70u;
    ctx->downcount -= 3;
    // 8018AD70: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018AD74:
    ctx->pc = 0x8018AD74u;
    // 8018AD74: stw     r0, -26260(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26260);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AD78:
    ctx->pc = 0x8018AD78u;
    // 8018AD78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AD7C:
    ctx->pc = 0x8018AD7Cu;
    ctx->downcount -= 1;
    // 8018AD7C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AD80:
    ctx->pc = 0x8018AD80u;
    ctx->downcount -= 2;
    // 8018AD80: li      r3, 16384
    ctx->gpr[3] = (u32)(s32)(16384);

label_8018AD84:
    ctx->pc = 0x8018AD84u;
    // 8018AD84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AD88:
    ctx->pc = 0x8018AD88u;
    ctx->downcount -= 2;
    // 8018AD88: lwz     r3, -26284(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26284);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018AD8C:
    ctx->pc = 0x8018AD8Cu;
    // 8018AD8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AD90:
    ctx->pc = 0x8018AD90u;
    ctx->downcount -= 2;
    // 8018AD90: lwz     r3, -26280(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26280);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018AD94:
    ctx->pc = 0x8018AD94u;
    // 8018AD94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AD98:
    ctx->pc = 0x8018AD98u;
    ctx->downcount -= 5;
    // 8018AD98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018AD9C:
    ctx->pc = 0x8018AD9Cu;
    // 8018AD9C: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018ADA0:
    ctx->pc = 0x8018ADA0u;
    // 8018ADA0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018ADA4:
    ctx->pc = 0x8018ADA4u;
    // 8018ADA4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018ADA8:
    ctx->pc = 0x8018ADA8u;
    // 8018ADA8: bc    12, 2, 0x8018ADE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018ADE0;
        }
    }

label_8018ADAC:
    ctx->pc = 0x8018ADACu;
    ctx->downcount -= 1;
    // 8018ADAC: bc    4, 0, 0x8018ADBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018ADBC;
        }
    }

label_8018ADB0:
    ctx->pc = 0x8018ADB0u;
    ctx->downcount -= 2;
    // 8018ADB0: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018ADB4:
    ctx->pc = 0x8018ADB4u;
    // 8018ADB4: bc    4, 0, 0x8018ADC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018ADC8;
        }
    }

label_8018ADB8:
    ctx->pc = 0x8018ADB8u;
    ctx->downcount -= 1;
    // 8018ADB8: b       0x8018AE18
    {
            goto label_8018AE18;
    }

label_8018ADBC:
    ctx->pc = 0x8018ADBCu;
    ctx->downcount -= 2;
    // 8018ADBC: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018ADC0:
    ctx->pc = 0x8018ADC0u;
    // 8018ADC0: bc    4, 0, 0x8018AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018AE18;
        }
    }

label_8018ADC4:
    ctx->pc = 0x8018ADC4u;
    ctx->downcount -= 1;
    // 8018ADC4: b       0x8018ADFC
    {
            goto label_8018ADFC;
    }

label_8018ADC8:
    ctx->pc = 0x8018ADC8u;
    ctx->downcount -= 3;
    // 8018ADC8: lwz     r4, -26280(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26280);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018ADCC:
    ctx->pc = 0x8018ADCCu;
    // 8018ADCC: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018ADD0:
    ctx->pc = 0x8018ADD0u;
    // 8018ADD0: bc    12, 2, 0x8018AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AE18;
        }
    }

label_8018ADD4:
    ctx->pc = 0x8018ADD4u;
    ctx->downcount -= 2;
    // 8018ADD4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018ADD8:
    ctx->pc = 0x8018ADD8u;
    // 8018ADD8: bl      0x8018B95C
    {
            ctx->lr = 0x8018ADDCu;
            ctx->pc = 0x8018B95Cu;
            return;
    }

label_8018ADDC:
    ctx->pc = 0x8018ADDCu;
    ctx->downcount -= 1;
    // 8018ADDC: b       0x8018AE18
    {
            goto label_8018AE18;
    }

label_8018ADE0:
    ctx->pc = 0x8018ADE0u;
    ctx->downcount -= 3;
    // 8018ADE0: lwz     r4, -26280(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26280);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018ADE4:
    ctx->pc = 0x8018ADE4u;
    // 8018ADE4: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018ADE8:
    ctx->pc = 0x8018ADE8u;
    // 8018ADE8: bc    12, 2, 0x8018AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AE18;
        }
    }

label_8018ADEC:
    ctx->pc = 0x8018ADECu;
    ctx->downcount -= 3;
    // 8018ADEC: li      r3, 16384
    ctx->gpr[3] = (u32)(s32)(16384);

label_8018ADF0:
    ctx->pc = 0x8018ADF0u;
    // 8018ADF0: addi    r4, r4, -16384
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-16384);

label_8018ADF4:
    ctx->pc = 0x8018ADF4u;
    // 8018ADF4: bl      0x8018B95C
    {
            ctx->lr = 0x8018ADF8u;
            ctx->pc = 0x8018B95Cu;
            return;
    }

label_8018ADF8:
    ctx->pc = 0x8018ADF8u;
    ctx->downcount -= 1;
    // 8018ADF8: b       0x8018AE18
    {
            goto label_8018AE18;
    }

label_8018ADFC:
    ctx->pc = 0x8018ADFCu;
    ctx->downcount -= 3;
    // 8018ADFC: lwz     r3, -26280(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26280);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018AE00:
    ctx->pc = 0x8018AE00u;
    // 8018AE00: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018AE04:
    ctx->pc = 0x8018AE04u;
    // 8018AE04: bc    12, 2, 0x8018AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AE18;
        }
    }

label_8018AE08:
    ctx->pc = 0x8018AE08u;
    ctx->downcount -= 3;
    // 8018AE08: lwz     r4, -26276(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26276);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018AE0C:
    ctx->pc = 0x8018AE0Cu;
    // 8018AE0C: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018AE10:
    ctx->pc = 0x8018AE10u;
    // 8018AE10: bc    12, 2, 0x8018AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AE18;
        }
    }

label_8018AE14:
    ctx->pc = 0x8018AE14u;
    ctx->downcount -= 1;
    // 8018AE14: bl      0x8018B95C
    {
            ctx->lr = 0x8018AE18u;
            ctx->pc = 0x8018B95Cu;
            return;
    }

label_8018AE18:
    ctx->pc = 0x8018AE18u;
    ctx->downcount -= 5;
    // 8018AE18: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AE1C:
    ctx->pc = 0x8018AE1Cu;
    // 8018AE1C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8018AE20:
    ctx->pc = 0x8018AE20u;
    // 8018AE20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AE24:
    ctx->pc = 0x8018AE24u;
    // 8018AE24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AE28:
    ctx->pc = 0x8018AE28u;
    ctx->downcount -= 14;
    // 8018AE28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018AE2C:
    ctx->pc = 0x8018AE2Cu;
    // 8018AE2C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018AE30:
    ctx->pc = 0x8018AE30u;
    // 8018AE30: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018AE34:
    ctx->pc = 0x8018AE34u;
    // 8018AE34: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018AE38:
    ctx->pc = 0x8018AE38u;
    // 8018AE38: li      r0, -137
    ctx->gpr[0] = (u32)(s32)(-137);

label_8018AE3C:
    ctx->pc = 0x8018AE3Cu;
    // 8018AE3C: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018AE40:
    ctx->pc = 0x8018AE40u;
    // 8018AE40: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018AE44:
    ctx->pc = 0x8018AE44u;
    // 8018AE44: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_8018AE48:
    ctx->pc = 0x8018AE48u;
    // 8018AE48: lhz     r5, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8018AE4C:
    ctx->pc = 0x8018AE4Cu;
    // 8018AE4C: and   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ctx->gpr[0];
    }

label_8018AE50:
    ctx->pc = 0x8018AE50u;
    // 8018AE50: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018AE54:
    ctx->pc = 0x8018AE54u;
    // 8018AE54: sth     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AE58:
    ctx->pc = 0x8018AE58u;
    // 8018AE58: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018AE5C:
    ctx->pc = 0x8018AE5Cu;
    // 8018AE5C: bl      0x8017248C
    {
            ctx->lr = 0x8018AE60u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018AE60:
    ctx->pc = 0x8018AE60u;
    ctx->downcount -= 2;
    // 8018AE60: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018AE64:
    ctx->pc = 0x8018AE64u;
    // 8018AE64: bl      0x80172284
    {
            ctx->lr = 0x8018AE68u;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018AE68:
    ctx->pc = 0x8018AE68u;
    ctx->downcount -= 3;
    // 8018AE68: lwz     r12, -26288(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26288);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8018AE6C:
    ctx->pc = 0x8018AE6Cu;
    // 8018AE6C: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018AE70:
    ctx->pc = 0x8018AE70u;
    // 8018AE70: bc    12, 2, 0x8018AE7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018AE7C;
        }
    }

label_8018AE74:
    ctx->pc = 0x8018AE74u;
    ctx->downcount -= 3;
    // 8018AE74: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_8018AE78:
    ctx->pc = 0x8018AE78u;
    // 8018AE78: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8018AE7Cu;
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AE7C:
    ctx->pc = 0x8018AE7Cu;
    ctx->downcount -= 2;
    // 8018AE7C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8018AE80:
    ctx->pc = 0x8018AE80u;
    // 8018AE80: bl      0x8017248C
    {
            ctx->lr = 0x8018AE84u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018AE84:
    ctx->pc = 0x8018AE84u;
    ctx->downcount -= 2;
    // 8018AE84: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018AE88:
    ctx->pc = 0x8018AE88u;
    // 8018AE88: bl      0x80172284
    {
            ctx->lr = 0x8018AE8Cu;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018AE8C:
    ctx->pc = 0x8018AE8Cu;
    ctx->downcount -= 6;
    // 8018AE8C: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018AE90:
    ctx->pc = 0x8018AE90u;
    // 8018AE90: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018AE94:
    ctx->pc = 0x8018AE94u;
    // 8018AE94: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_8018AE98:
    ctx->pc = 0x8018AE98u;
    // 8018AE98: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018AE9C:
    ctx->pc = 0x8018AE9Cu;
    // 8018AE9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AEA0:
    ctx->pc = 0x8018AEA0u;
    ctx->downcount -= 8;
    // 8018AEA0: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018AEA4:
    ctx->pc = 0x8018AEA4u;
    // 8018AEA4: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018AEA8:
    ctx->pc = 0x8018AEA8u;
    // 8018AEA8: lhz     r4, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018AEAC:
    ctx->pc = 0x8018AEACu;
    // 8018AEAC: li      r0, -137
    ctx->gpr[0] = (u32)(s32)(-137);

label_8018AEB0:
    ctx->pc = 0x8018AEB0u;
    // 8018AEB0: and   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] & ctx->gpr[0];
    }

label_8018AEB4:
    ctx->pc = 0x8018AEB4u;
    // 8018AEB4: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018AEB8:
    ctx->pc = 0x8018AEB8u;
    // 8018AEB8: sth     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AEBC:
    ctx->pc = 0x8018AEBCu;
    // 8018AEBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AEC0:
    ctx->pc = 0x8018AEC0u;
    ctx->downcount -= 4;
    // 8018AEC0: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018AEC4:
    ctx->pc = 0x8018AEC4u;
    // 8018AEC4: lhz     r0, 20490(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20490);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018AEC8:
    ctx->pc = 0x8018AEC8u;
    // 8018AEC8: rlwinm r3, r0, 0, 26, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000020u;
    }

label_8018AECC:
    ctx->pc = 0x8018AECCu;
    // 8018AECC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AED0:
    ctx->pc = 0x8018AED0u;
    ctx->downcount -= 2;
    // 8018AED0: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018AED4:
    ctx->pc = 0x8018AED4u;
    // 8018AED4: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018AED8:
    loop_8018AED8(ctx);
    if (ctx->pc == 0x8018AEE4u) goto label_8018AEE4;
    return;
label_8018AEDC:
    // 8018AEDC: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018AEE0:
    // 8018AEE0: bc    4, 2, 0x8018AED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018AED8u;
                return;
            }
            goto label_8018AED8;
        }
    }

label_8018AEE4:
    ctx->pc = 0x8018AEE4u;
    ctx->downcount -= 1;
    // 8018AEE4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AEE8:
    ctx->pc = 0x8018AEE8u;
    ctx->downcount -= 34;
    // 8018AEE8: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_8018AEEC:
    ctx->pc = 0x8018AEECu;
    // 8018AEEC: lhz     r0, 20512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018AEF0:
    ctx->pc = 0x8018AEF0u;
    // 8018AEF0: rlwinm r7, r0, 0, 0, 21
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018AEF4:
    ctx->pc = 0x8018AEF4u;
    // 8018AEF4: rlwinm r0, r3, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_8018AEF8:
    ctx->pc = 0x8018AEF8u;
    // 8018AEF8: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_8018AEFC:
    ctx->pc = 0x8018AEFCu;
    // 8018AEFC: sth     r0, 20512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20512);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AF00:
    ctx->pc = 0x8018AF00u;
    // 8018AF00: rlwinm r0, r3, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8018AF04:
    ctx->pc = 0x8018AF04u;
    // 8018AF04: lhz     r7, 20514(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20514);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_8018AF08:
    ctx->pc = 0x8018AF08u;
    // 8018AF08: rlwinm r3, r7, 0, 27, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFF001Fu;
    }

label_8018AF0C:
    ctx->pc = 0x8018AF0Cu;
    // 8018AF0C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018AF10:
    ctx->pc = 0x8018AF10u;
    // 8018AF10: sth     r0, 20514(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20514);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AF14:
    ctx->pc = 0x8018AF14u;
    // 8018AF14: rlwinm r0, r4, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0x0000FFFFu;
    }

label_8018AF18:
    ctx->pc = 0x8018AF18u;
    // 8018AF18: lhz     r3, 20516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20516);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018AF1C:
    ctx->pc = 0x8018AF1Cu;
    // 8018AF1C: rlwinm r3, r3, 0, 0, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFC00u;
    }

label_8018AF20:
    ctx->pc = 0x8018AF20u;
    // 8018AF20: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018AF24:
    ctx->pc = 0x8018AF24u;
    // 8018AF24: sth     r0, 20516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20516);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AF28:
    ctx->pc = 0x8018AF28u;
    // 8018AF28: rlwinm r0, r4, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_8018AF2C:
    ctx->pc = 0x8018AF2Cu;
    // 8018AF2C: rlwinm r3, r5, 16, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0x0000FFFFu;
    }

label_8018AF30:
    ctx->pc = 0x8018AF30u;
    // 8018AF30: lhz     r4, 20518(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20518);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018AF34:
    ctx->pc = 0x8018AF34u;
    // 8018AF34: rlwinm r4, r4, 0, 27, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF001Fu;
    }

label_8018AF38:
    ctx->pc = 0x8018AF38u;
    // 8018AF38: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018AF3C:
    ctx->pc = 0x8018AF3Cu;
    // 8018AF3C: sth     r0, 20518(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20518);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AF40:
    ctx->pc = 0x8018AF40u;
    // 8018AF40: rlwinm r0, r5, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_8018AF44:
    ctx->pc = 0x8018AF44u;
    // 8018AF44: lhz     r4, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018AF48:
    ctx->pc = 0x8018AF48u;
    // 8018AF48: rlwinm r4, r4, 0, 17, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF7FFFu;
    }

label_8018AF4C:
    ctx->pc = 0x8018AF4Cu;
    // 8018AF4C: sth     r4, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8018AF50:
    ctx->pc = 0x8018AF50u;
    // 8018AF50: lhz     r4, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018AF54:
    ctx->pc = 0x8018AF54u;
    // 8018AF54: rlwinm r4, r4, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_8018AF58:
    ctx->pc = 0x8018AF58u;
    // 8018AF58: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8018AF5C:
    ctx->pc = 0x8018AF5Cu;
    // 8018AF5C: sth     r3, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8018AF60:
    ctx->pc = 0x8018AF60u;
    // 8018AF60: lhz     r3, 20522(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20522);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018AF64:
    ctx->pc = 0x8018AF64u;
    // 8018AF64: rlwinm r3, r3, 0, 27, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF001Fu;
    }

label_8018AF68:
    ctx->pc = 0x8018AF68u;
    // 8018AF68: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018AF6C:
    ctx->pc = 0x8018AF6Cu;
    // 8018AF6C: sth     r0, 20522(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20522);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AF70:
    loop_8018AF70(ctx);
    if (ctx->pc == 0x8018AF80u) goto label_8018AF80;
    return;
label_8018AF74:
    ctx->pc = 0x8018AF74u;
    // 8018AF74: lhzu     r0, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8018AF78:
    // 8018AF78: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018AF7C:
    // 8018AF7C: bc    4, 2, 0x8018AF70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018AF70u;
                return;
            }
            goto label_8018AF70;
        }
    }

label_8018AF80:
    ctx->pc = 0x8018AF80u;
    ctx->downcount -= 6;
    // 8018AF80: lhz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018AF84:
    ctx->pc = 0x8018AF84u;
    // 8018AF84: li      r0, -137
    ctx->gpr[0] = (u32)(s32)(-137);

label_8018AF88:
    ctx->pc = 0x8018AF88u;
    // 8018AF88: and   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
    }

label_8018AF8C:
    ctx->pc = 0x8018AF8Cu;
    // 8018AF8C: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018AF90:
    ctx->pc = 0x8018AF90u;
    // 8018AF90: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AF94:
    ctx->pc = 0x8018AF94u;
    // 8018AF94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018AF98:
    ctx->pc = 0x8018AF98u;
    ctx->downcount -= 34;
    // 8018AF98: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_8018AF9C:
    ctx->pc = 0x8018AF9Cu;
    // 8018AF9C: lhz     r0, 20512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018AFA0:
    ctx->pc = 0x8018AFA0u;
    // 8018AFA0: rlwinm r7, r0, 0, 0, 21
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018AFA4:
    ctx->pc = 0x8018AFA4u;
    // 8018AFA4: rlwinm r0, r3, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_8018AFA8:
    ctx->pc = 0x8018AFA8u;
    // 8018AFA8: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_8018AFAC:
    ctx->pc = 0x8018AFACu;
    // 8018AFAC: sth     r0, 20512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20512);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AFB0:
    ctx->pc = 0x8018AFB0u;
    // 8018AFB0: rlwinm r0, r3, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8018AFB4:
    ctx->pc = 0x8018AFB4u;
    // 8018AFB4: lhz     r7, 20514(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20514);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_8018AFB8:
    ctx->pc = 0x8018AFB8u;
    // 8018AFB8: rlwinm r3, r7, 0, 27, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFF001Fu;
    }

label_8018AFBC:
    ctx->pc = 0x8018AFBCu;
    // 8018AFBC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018AFC0:
    ctx->pc = 0x8018AFC0u;
    // 8018AFC0: sth     r0, 20514(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20514);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AFC4:
    ctx->pc = 0x8018AFC4u;
    // 8018AFC4: rlwinm r0, r4, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0x0000FFFFu;
    }

label_8018AFC8:
    ctx->pc = 0x8018AFC8u;
    // 8018AFC8: lhz     r3, 20516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20516);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018AFCC:
    ctx->pc = 0x8018AFCCu;
    // 8018AFCC: rlwinm r3, r3, 0, 0, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFC00u;
    }

label_8018AFD0:
    ctx->pc = 0x8018AFD0u;
    // 8018AFD0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018AFD4:
    ctx->pc = 0x8018AFD4u;
    // 8018AFD4: sth     r0, 20516(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20516);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AFD8:
    ctx->pc = 0x8018AFD8u;
    // 8018AFD8: rlwinm r0, r4, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_8018AFDC:
    ctx->pc = 0x8018AFDCu;
    // 8018AFDC: rlwinm r3, r5, 16, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0x0000FFFFu;
    }

label_8018AFE0:
    ctx->pc = 0x8018AFE0u;
    // 8018AFE0: lhz     r4, 20518(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20518);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018AFE4:
    ctx->pc = 0x8018AFE4u;
    // 8018AFE4: rlwinm r4, r4, 0, 27, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF001Fu;
    }

label_8018AFE8:
    ctx->pc = 0x8018AFE8u;
    // 8018AFE8: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8018AFEC:
    ctx->pc = 0x8018AFECu;
    // 8018AFEC: sth     r0, 20518(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20518);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018AFF0:
    ctx->pc = 0x8018AFF0u;
    // 8018AFF0: rlwinm r0, r5, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_8018AFF4:
    ctx->pc = 0x8018AFF4u;
    // 8018AFF4: lhz     r4, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018AFF8:
    ctx->pc = 0x8018AFF8u;
    // 8018AFF8: ori     r4, r4, 0x8000
    ctx->gpr[4] = ctx->gpr[4] | 0x8000u;

label_8018AFFC:
    ctx->pc = 0x8018AFFCu;
    // 8018AFFC: sth     r4, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8018B000:
    ctx->pc = 0x8018B000u;
    // 8018B000: lhz     r4, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018B004:
    ctx->pc = 0x8018B004u;
    // 8018B004: rlwinm r4, r4, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_8018B008:
    ctx->pc = 0x8018B008u;
    // 8018B008: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8018B00C:
    ctx->pc = 0x8018B00Cu;
    // 8018B00C: sth     r3, 20520(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20520);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8018B010:
    ctx->pc = 0x8018B010u;
    // 8018B010: lhz     r3, 20522(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20522);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018B014:
    ctx->pc = 0x8018B014u;
    // 8018B014: rlwinm r3, r3, 0, 27, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF001Fu;
    }

label_8018B018:
    ctx->pc = 0x8018B018u;
    // 8018B018: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018B01C:
    ctx->pc = 0x8018B01Cu;
    // 8018B01C: sth     r0, 20522(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20522);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B020:
    loop_8018B020(ctx);
    if (ctx->pc == 0x8018B030u) goto label_8018B030;
    return;
label_8018B024:
    ctx->pc = 0x8018B024u;
    // 8018B024: lhzu     r0, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8018B028:
    // 8018B028: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018B02C:
    // 8018B02C: bc    4, 2, 0x8018B020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B020u;
                return;
            }
            goto label_8018B020;
        }
    }

label_8018B030:
    ctx->pc = 0x8018B030u;
    ctx->downcount -= 6;
    // 8018B030: lhz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8018B034:
    ctx->pc = 0x8018B034u;
    // 8018B034: li      r0, -137
    ctx->gpr[0] = (u32)(s32)(-137);

label_8018B038:
    ctx->pc = 0x8018B038u;
    // 8018B038: and   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
    }

label_8018B03C:
    ctx->pc = 0x8018B03Cu;
    // 8018B03C: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018B040:
    ctx->pc = 0x8018B040u;
    // 8018B040: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B044:
    ctx->pc = 0x8018B044u;
    // 8018B044: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801872C0;
        }
    }

label_8018B048:
    ctx->pc = 0x8018B048u;
    ctx->downcount -= 16;
    // 8018B048: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018B04C:
    ctx->pc = 0x8018B04Cu;
    // 8018B04C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018B050:
    ctx->pc = 0x8018B050u;
    // 8018B050: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B054:
    ctx->pc = 0x8018B054u;
    // 8018B054: addi    r3, r3, 20480
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20480);

label_8018B058:
    ctx->pc = 0x8018B058u;
    // 8018B058: stwu     r1, -312(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-312);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018B05C:
    ctx->pc = 0x8018B05Cu;
    // 8018B05C: stmw     r14, 240(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8018B060:
    loop_8018B060(ctx);
    if (ctx->pc == 0x8018B06Cu) goto label_8018B06C;
    return;
label_8018B064:
    // 8018B064: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018B068:
    // 8018B068: bc    12, 2, 0x8018B060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B060u;
                return;
            }
            goto label_8018B060;
        }
    }

label_8018B06C:
    ctx->pc = 0x8018B06Cu;
    ctx->downcount -= 39;
    // 8018B06C: lis     r3, 256
    ctx->gpr[3] = ((u32)(s32)(256) << 16);

label_8018B070:
    ctx->pc = 0x8018B070u;
    // 8018B070: stw     r3, -26280(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26280);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018B074:
    ctx->pc = 0x8018B074u;
    // 8018B074: lis     r22, -13312
    ctx->gpr[22] = ((u32)(s32)(-13312) << 16);

label_8018B078:
    ctx->pc = 0x8018B078u;
    // 8018B078: addi    r0, r1, 179
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(179);

label_8018B07C:
    ctx->pc = 0x8018B07Cu;
    // 8018B07C: lhz     r5, 20498(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20498);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8018B080:
    ctx->pc = 0x8018B080u;
    // 8018B080: rlwinm r23, r0, 0, 0, 26
    {
        ctx->gpr[23] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_8018B084:
    ctx->pc = 0x8018B084u;
    // 8018B084: addi    r0, r1, 115
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(115);

label_8018B088:
    ctx->pc = 0x8018B088u;
    // 8018B088: rlwinm r5, r5, 0, 0, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFC0u;
    }

label_8018B08C:
    ctx->pc = 0x8018B08Cu;
    // 8018B08C: ori     r5, r5, 0x0023
    ctx->gpr[5] = ctx->gpr[5] | 0x0023u;

label_8018B090:
    ctx->pc = 0x8018B090u;
    // 8018B090: addi    r18, r22, 20480
    ctx->gpr[18] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B094:
    ctx->pc = 0x8018B094u;
    // 8018B094: sthu     r5, 18(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(18);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
        ctx->gpr[18] = ea;
    }

label_8018B098:
    ctx->pc = 0x8018B098u;
    // 8018B098: lis     r4, -8530
    ctx->gpr[4] = ((u32)(s32)(-8530) << 16);

label_8018B09C:
    ctx->pc = 0x8018B09Cu;
    // 8018B09C: addi    r5, r4, -16657
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(-16657);

label_8018B0A0:
    ctx->pc = 0x8018B0A0u;
    // 8018B0A0: stw     r5, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0A4:
    ctx->pc = 0x8018B0A4u;
    // 8018B0A4: lis     r4, -17711
    ctx->gpr[4] = ((u32)(s32)(-17711) << 16);

label_8018B0A8:
    ctx->pc = 0x8018B0A8u;
    // 8018B0A8: rlwinm r28, r0, 0, 0, 26
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_8018B0AC:
    ctx->pc = 0x8018B0ACu;
    // 8018B0AC: addi    r0, r4, -17712
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-17712);

label_8018B0B0:
    ctx->pc = 0x8018B0B0u;
    // 8018B0B0: stw     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0B4:
    ctx->pc = 0x8018B0B4u;
    // 8018B0B4: addi    r4, r1, 51
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(51);

label_8018B0B8:
    ctx->pc = 0x8018B0B8u;
    // 8018B0B8: addi    r21, r3, 0
    ctx->gpr[21] = ctx->gpr[3] + (u32)(s32)(0);

label_8018B0BC:
    ctx->pc = 0x8018B0BCu;
    // 8018B0BC: stw     r5, 4(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0C0:
    ctx->pc = 0x8018B0C0u;
    // 8018B0C0: rlwinm r24, r4, 0, 0, 26
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_8018B0C4:
    ctx->pc = 0x8018B0C4u;
    // 8018B0C4: addi    r3, r23, 0
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(0);

label_8018B0C8:
    ctx->pc = 0x8018B0C8u;
    // 8018B0C8: stw     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0CC:
    ctx->pc = 0x8018B0CCu;
    // 8018B0CC: li      r19, 3
    ctx->gpr[19] = (u32)(s32)(3);

label_8018B0D0:
    ctx->pc = 0x8018B0D0u;
    // 8018B0D0: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_8018B0D4:
    ctx->pc = 0x8018B0D4u;
    // 8018B0D4: stw     r5, 8(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0D8:
    ctx->pc = 0x8018B0D8u;
    // 8018B0D8: stw     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0DC:
    ctx->pc = 0x8018B0DCu;
    // 8018B0DC: stw     r5, 12(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0E0:
    ctx->pc = 0x8018B0E0u;
    // 8018B0E0: stw     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0E4:
    ctx->pc = 0x8018B0E4u;
    // 8018B0E4: stw     r5, 16(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0E8:
    ctx->pc = 0x8018B0E8u;
    // 8018B0E8: stw     r0, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0EC:
    ctx->pc = 0x8018B0ECu;
    // 8018B0EC: stw     r5, 20(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0F0:
    ctx->pc = 0x8018B0F0u;
    // 8018B0F0: stw     r0, 20(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0F4:
    ctx->pc = 0x8018B0F4u;
    // 8018B0F4: stw     r5, 24(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B0F8:
    ctx->pc = 0x8018B0F8u;
    // 8018B0F8: stw     r0, 24(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B0FC:
    ctx->pc = 0x8018B0FCu;
    // 8018B0FC: stw     r5, 28(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018B100:
    ctx->pc = 0x8018B100u;
    // 8018B100: stw     r0, 28(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B104:
    ctx->pc = 0x8018B104u;
    // 8018B104: bl      0x801715DC
    {
            ctx->lr = 0x8018B108u;
            ctx->pc = 0x801715DCu;
            return;
    }

label_8018B108:
    ctx->pc = 0x8018B108u;
    ctx->downcount -= 3;
    // 8018B108: addi    r3, r28, 0
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(0);

label_8018B10C:
    ctx->pc = 0x8018B10Cu;
    // 8018B10C: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_8018B110:
    ctx->pc = 0x8018B110u;
    // 8018B110: bl      0x801715DC
    {
            ctx->lr = 0x8018B114u;
            ctx->pc = 0x801715DCu;
            return;
    }

label_8018B114:
    ctx->pc = 0x8018B114u;
    ctx->downcount -= 39;
    // 8018B114: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018B118:
    ctx->pc = 0x8018B118u;
    // 8018B118: stw     r0, -26276(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26276);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B11C:
    ctx->pc = 0x8018B11Cu;
    // 8018B11C: rlwinm r5, r28, 16, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[28], 16u) & 0x0000FFFFu;
    }

label_8018B120:
    ctx->pc = 0x8018B120u;
    // 8018B120: rlwinm r6, r28, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x0000FFFFu;
    }

label_8018B124:
    ctx->pc = 0x8018B124u;
    // 8018B124: lhz     r0, 20512(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20512);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B128:
    ctx->pc = 0x8018B128u;
    // 8018B128: addi    r25, r22, 20480
    ctx->gpr[25] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B12C:
    ctx->pc = 0x8018B12Cu;
    // 8018B12C: addi    r26, r22, 20480
    ctx->gpr[26] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B130:
    ctx->pc = 0x8018B130u;
    // 8018B130: rlwinm r0, r0, 0, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018B134:
    ctx->pc = 0x8018B134u;
    // 8018B134: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_8018B138:
    ctx->pc = 0x8018B138u;
    // 8018B138: sthu     r0, 32(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[25] = ea;
    }

label_8018B13C:
    ctx->pc = 0x8018B13Cu;
    // 8018B13C: rlwinm r16, r21, 16, 16, 31
    {
        ctx->gpr[16] = dolrecomp_rotl32(ctx->gpr[21], 16u) & 0x0000FFFFu;
    }

label_8018B140:
    ctx->pc = 0x8018B140u;
    // 8018B140: addi    r27, r22, 20480
    ctx->gpr[27] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B144:
    ctx->pc = 0x8018B144u;
    // 8018B144: lhz     r0, 20514(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20514);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B148:
    ctx->pc = 0x8018B148u;
    // 8018B148: rlwinm r17, r21, 0, 16, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[21], 0u) & 0x0000FFFFu;
    }

label_8018B14C:
    ctx->pc = 0x8018B14Cu;
    // 8018B14C: addi    r28, r22, 20480
    ctx->gpr[28] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B150:
    ctx->pc = 0x8018B150u;
    // 8018B150: rlwinm r0, r0, 0, 27, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B154:
    ctx->pc = 0x8018B154u;
    // 8018B154: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_8018B158:
    ctx->pc = 0x8018B158u;
    // 8018B158: sthu     r0, 34(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[26] = ea;
    }

label_8018B15C:
    ctx->pc = 0x8018B15Cu;
    // 8018B15C: addi    r30, r22, 20480
    ctx->gpr[30] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B160:
    ctx->pc = 0x8018B160u;
    // 8018B160: addi    r29, r22, 20480
    ctx->gpr[29] = ctx->gpr[22] + (u32)(s32)(20480);

label_8018B164:
    ctx->pc = 0x8018B164u;
    // 8018B164: lhz     r0, 20516(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20516);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B168:
    ctx->pc = 0x8018B168u;
    // 8018B168: rlwinm r0, r0, 0, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018B16C:
    ctx->pc = 0x8018B16Cu;
    // 8018B16C: or   r0, r0, r16
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[16];
    }

label_8018B170:
    ctx->pc = 0x8018B170u;
    // 8018B170: sthu     r0, 36(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(36);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[27] = ea;
    }

label_8018B174:
    ctx->pc = 0x8018B174u;
    // 8018B174: lhz     r0, 20518(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20518);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B178:
    ctx->pc = 0x8018B178u;
    // 8018B178: rlwinm r0, r0, 0, 27, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B17C:
    ctx->pc = 0x8018B17Cu;
    // 8018B17C: or   r0, r0, r17
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[17];
    }

label_8018B180:
    ctx->pc = 0x8018B180u;
    // 8018B180: sthu     r0, 38(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[28] = ea;
    }

label_8018B184:
    ctx->pc = 0x8018B184u;
    // 8018B184: lhz     r0, 20520(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20520);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B188:
    ctx->pc = 0x8018B188u;
    // 8018B188: rlwinm r0, r0, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF7FFFu;
    }

label_8018B18C:
    ctx->pc = 0x8018B18Cu;
    // 8018B18C: sth     r0, 20520(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20520);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B190:
    ctx->pc = 0x8018B190u;
    // 8018B190: lhz     r0, 20520(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20520);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B194:
    ctx->pc = 0x8018B194u;
    // 8018B194: rlwinm r0, r0, 0, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018B198:
    ctx->pc = 0x8018B198u;
    // 8018B198: nop
    // nop

label_8018B19C:
    ctx->pc = 0x8018B19Cu;
    // 8018B19C: sthu     r0, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[30] = ea;
    }

label_8018B1A0:
    ctx->pc = 0x8018B1A0u;
    // 8018B1A0: lhz     r0, 20522(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(20522);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B1A4:
    ctx->pc = 0x8018B1A4u;
    // 8018B1A4: rlwinm r0, r0, 0, 27, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B1A8:
    ctx->pc = 0x8018B1A8u;
    // 8018B1A8: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018B1AC:
    ctx->pc = 0x8018B1ACu;
    // 8018B1AC: sthu     r0, 42(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[29] = ea;
    }

label_8018B1B0:
    loop_8018B1B0(ctx);
    if (ctx->pc == 0x8018B1C0u) goto label_8018B1C0;
    return;
label_8018B1B4:
    ctx->pc = 0x8018B1B4u;
    // 8018B1B4: lhzu     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[31] = ea;
    }

label_8018B1B8:
    // 8018B1B8: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018B1BC:
    // 8018B1BC: bc    4, 2, 0x8018B1B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B1B0u;
                return;
            }
            goto label_8018B1B0;
        }
    }

label_8018B1C0:
    ctx->pc = 0x8018B1C0u;
    ctx->downcount -= 39;
    // 8018B1C0: lhz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B1C4:
    ctx->pc = 0x8018B1C4u;
    // 8018B1C4: li      r4, -137
    ctx->gpr[4] = (u32)(s32)(-137);

label_8018B1C8:
    ctx->pc = 0x8018B1C8u;
    // 8018B1C8: addis   r3, r21, 32
    ctx->gpr[3] = ctx->gpr[21] + ((u32)(s32)(32) << 16);

label_8018B1CC:
    ctx->pc = 0x8018B1CCu;
    // 8018B1CC: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_8018B1D0:
    ctx->pc = 0x8018B1D0u;
    // 8018B1D0: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018B1D4:
    ctx->pc = 0x8018B1D4u;
    // 8018B1D4: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B1D8:
    ctx->pc = 0x8018B1D8u;
    // 8018B1D8: rlwinm r0, r3, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_8018B1DC:
    ctx->pc = 0x8018B1DCu;
    // 8018B1DC: lhz     r4, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018B1E0:
    ctx->pc = 0x8018B1E0u;
    // 8018B1E0: stw     r0, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B1E4:
    ctx->pc = 0x8018B1E4u;
    // 8018B1E4: rlwinm r0, r3, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8018B1E8:
    ctx->pc = 0x8018B1E8u;
    // 8018B1E8: stw     r0, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B1EC:
    ctx->pc = 0x8018B1ECu;
    // 8018B1EC: rlwinm r0, r4, 0, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_8018B1F0:
    ctx->pc = 0x8018B1F0u;
    // 8018B1F0: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_8018B1F4:
    ctx->pc = 0x8018B1F4u;
    // 8018B1F4: sth     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B1F8:
    ctx->pc = 0x8018B1F8u;
    // 8018B1F8: lhz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B1FC:
    ctx->pc = 0x8018B1FCu;
    // 8018B1FC: rlwinm r0, r0, 0, 27, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B200:
    ctx->pc = 0x8018B200u;
    // 8018B200: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_8018B204:
    ctx->pc = 0x8018B204u;
    // 8018B204: sth     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B208:
    ctx->pc = 0x8018B208u;
    // 8018B208: lhz     r0, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B20C:
    ctx->pc = 0x8018B20Cu;
    // 8018B20C: rlwinm r3, r0, 0, 0, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018B210:
    ctx->pc = 0x8018B210u;
    // 8018B210: lwz     r0, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018B214:
    ctx->pc = 0x8018B214u;
    // 8018B214: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018B218:
    ctx->pc = 0x8018B218u;
    // 8018B218: sth     r0, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B21C:
    ctx->pc = 0x8018B21Cu;
    // 8018B21C: lhz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B220:
    ctx->pc = 0x8018B220u;
    // 8018B220: rlwinm r3, r0, 0, 27, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B224:
    ctx->pc = 0x8018B224u;
    // 8018B224: lwz     r0, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018B228:
    ctx->pc = 0x8018B228u;
    // 8018B228: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8018B22C:
    ctx->pc = 0x8018B22Cu;
    // 8018B22C: sth     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B230:
    ctx->pc = 0x8018B230u;
    // 8018B230: lhz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B234:
    ctx->pc = 0x8018B234u;
    // 8018B234: rlwinm r0, r0, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF7FFFu;
    }

label_8018B238:
    ctx->pc = 0x8018B238u;
    // 8018B238: sth     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B23C:
    ctx->pc = 0x8018B23Cu;
    // 8018B23C: lhz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B240:
    ctx->pc = 0x8018B240u;
    // 8018B240: rlwinm r0, r0, 0, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018B244:
    ctx->pc = 0x8018B244u;
    // 8018B244: nop
    // nop

label_8018B248:
    ctx->pc = 0x8018B248u;
    // 8018B248: sth     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B24C:
    ctx->pc = 0x8018B24Cu;
    // 8018B24C: lhz     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B250:
    ctx->pc = 0x8018B250u;
    // 8018B250: rlwinm r0, r0, 0, 27, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B254:
    ctx->pc = 0x8018B254u;
    // 8018B254: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018B258:
    ctx->pc = 0x8018B258u;
    // 8018B258: sth     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B25C:
    loop_8018B25C(ctx);
    if (ctx->pc == 0x8018B268u) goto label_8018B268;
    return;
label_8018B260:
    // 8018B260: rlwinm. r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018B264:
    // 8018B264: bc    4, 2, 0x8018B25C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018B25Cu;
                return;
            }
            goto label_8018B25C;
        }
    }

label_8018B268:
    ctx->pc = 0x8018B268u;
    ctx->downcount -= 22;
    // 8018B268: lhz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B26C:
    ctx->pc = 0x8018B26Cu;
    // 8018B26C: li      r4, -137
    ctx->gpr[4] = (u32)(s32)(-137);

label_8018B270:
    ctx->pc = 0x8018B270u;
    // 8018B270: addis   r3, r21, 256
    ctx->gpr[3] = ctx->gpr[21] + ((u32)(s32)(256) << 16);

label_8018B274:
    ctx->pc = 0x8018B274u;
    // 8018B274: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_8018B278:
    ctx->pc = 0x8018B278u;
    // 8018B278: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8018B27C:
    ctx->pc = 0x8018B27Cu;
    // 8018B27C: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B280:
    ctx->pc = 0x8018B280u;
    // 8018B280: rlwinm r0, r3, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_8018B284:
    ctx->pc = 0x8018B284u;
    // 8018B284: lhz     r4, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8018B288:
    ctx->pc = 0x8018B288u;
    // 8018B288: stw     r0, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B28C:
    ctx->pc = 0x8018B28Cu;
    // 8018B28C: rlwinm r0, r3, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8018B290:
    ctx->pc = 0x8018B290u;
    // 8018B290: stw     r0, 228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(228);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018B294:
    ctx->pc = 0x8018B294u;
    // 8018B294: rlwinm r0, r4, 0, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_8018B298:
    ctx->pc = 0x8018B298u;
    // 8018B298: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_8018B29C:
    ctx->pc = 0x8018B29Cu;
    // 8018B29C: sth     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B2A0:
    ctx->pc = 0x8018B2A0u;
    // 8018B2A0: lhz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B2A4:
    ctx->pc = 0x8018B2A4u;
    // 8018B2A4: rlwinm r0, r0, 0, 27, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF001Fu;
    }

label_8018B2A8:
    ctx->pc = 0x8018B2A8u;
    // 8018B2A8: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_8018B2AC:
    ctx->pc = 0x8018B2ACu;
    // 8018B2AC: sth     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018B2B0:
    ctx->pc = 0x8018B2B0u;
    // 8018B2B0: lhz     r0, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018B2B4:
    ctx->pc = 0x8018B2B4u;
    // 8018B2B4: rlwinm r3, r0, 0, 0, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFC00u;
    }

label_8018B2B8:
    ctx->pc = 0x8018B2B8u;
    // 8018B2B8: lwz     r0, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018B2BC:
    ctx->pc = 0x8018B2BCu;
    // 8018B2BC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

    ctx->pc = 0x8018B2C0u;
    return;
return_dispatch_801872C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x80187318u: goto label_80187318;
    case 0x8018735Cu: goto label_8018735C;
    case 0x801873A8u: goto label_801873A8;
    case 0x801873E0u: goto label_801873E0;
    case 0x80187408u: goto label_80187408;
    case 0x80187410u: goto label_80187410;
    case 0x8018744Cu: goto label_8018744C;
    case 0x80187474u: goto label_80187474;
    case 0x8018747Cu: goto label_8018747C;
    case 0x801874B8u: goto label_801874B8;
    case 0x801874F0u: goto label_801874F0;
    case 0x801874F8u: goto label_801874F8;
    case 0x80187534u: goto label_80187534;
    case 0x801875F8u: goto label_801875F8;
    case 0x801876E4u: goto label_801876E4;
    case 0x8018774Cu: goto label_8018774C;
    case 0x80187794u: goto label_80187794;
    case 0x801877E4u: goto label_801877E4;
    case 0x80187824u: goto label_80187824;
    case 0x80187874u: goto label_80187874;
    case 0x801878A0u: goto label_801878A0;
    case 0x801878B0u: goto label_801878B0;
    case 0x801878ECu: goto label_801878EC;
    case 0x80187B48u: goto label_80187B48;
    case 0x80187B74u: goto label_80187B74;
    case 0x80187B7Cu: goto label_80187B7C;
    case 0x80187BB0u: goto label_80187BB0;
    case 0x80187BC4u: goto label_80187BC4;
    case 0x80187D98u: goto label_80187D98;
    case 0x80187DA0u: goto label_80187DA0;
    case 0x80187E04u: goto label_80187E04;
    case 0x80187E2Cu: goto label_80187E2C;
    case 0x80187E50u: goto label_80187E50;
    case 0x801880D0u: goto label_801880D0;
    case 0x801880E8u: goto label_801880E8;
    case 0x801881C4u: goto label_801881C4;
    case 0x801881D4u: goto label_801881D4;
    case 0x801881DCu: goto label_801881DC;
    case 0x80188210u: goto label_80188210;
    case 0x80188224u: goto label_80188224;
    case 0x80188264u: goto label_80188264;
    case 0x8018826Cu: goto label_8018826C;
    case 0x801882D8u: goto label_801882D8;
    case 0x801882E8u: goto label_801882E8;
    case 0x80188470u: goto label_80188470;
    case 0x801884BCu: goto label_801884BC;
    case 0x801884E0u: goto label_801884E0;
    case 0x801884F0u: goto label_801884F0;
    case 0x801884F8u: goto label_801884F8;
    case 0x8018853Cu: goto label_8018853C;
    case 0x8018854Cu: goto label_8018854C;
    case 0x801885A4u: goto label_801885A4;
    case 0x801885B0u: goto label_801885B0;
    case 0x801885BCu: goto label_801885BC;
    case 0x801885FCu: goto label_801885FC;
    case 0x80188604u: goto label_80188604;
    case 0x80188660u: goto label_80188660;
    case 0x80188670u: goto label_80188670;
    case 0x80188678u: goto label_80188678;
    case 0x801886D0u: goto label_801886D0;
    case 0x801886E0u: goto label_801886E0;
    case 0x80188780u: goto label_80188780;
    case 0x80188790u: goto label_80188790;
    case 0x801887F8u: goto label_801887F8;
    case 0x80188808u: goto label_80188808;
    case 0x80188830u: goto label_80188830;
    case 0x80188840u: goto label_80188840;
    case 0x80188848u: goto label_80188848;
    case 0x80188884u: goto label_80188884;
    case 0x80188894u: goto label_80188894;
    case 0x801888E0u: goto label_801888E0;
    case 0x80188914u: goto label_80188914;
    case 0x80188968u: goto label_80188968;
    case 0x801889A0u: goto label_801889A0;
    case 0x801889F4u: goto label_801889F4;
    case 0x80188A04u: goto label_80188A04;
    case 0x80188AE0u: goto label_80188AE0;
    case 0x80188AE8u: goto label_80188AE8;
    case 0x80188AF4u: goto label_80188AF4;
    case 0x80188B34u: goto label_80188B34;
    case 0x80188B3Cu: goto label_80188B3C;
    case 0x80188B74u: goto label_80188B74;
    case 0x80188BD4u: goto label_80188BD4;
    case 0x80188C24u: goto label_80188C24;
    case 0x80188C34u: goto label_80188C34;
    case 0x80188C3Cu: goto label_80188C3C;
    case 0x80188C74u: goto label_80188C74;
    case 0x80188CD8u: goto label_80188CD8;
    case 0x80188D28u: goto label_80188D28;
    case 0x80188D38u: goto label_80188D38;
    case 0x80188D40u: goto label_80188D40;
    case 0x80188D98u: goto label_80188D98;
    case 0x80188DB0u: goto label_80188DB0;
    case 0x80188DC0u: goto label_80188DC0;
    case 0x80188DF4u: goto label_80188DF4;
    case 0x80188E14u: goto label_80188E14;
    case 0x80188E7Cu: goto label_80188E7C;
    case 0x80188E88u: goto label_80188E88;
    case 0x80188E90u: goto label_80188E90;
    case 0x80188EF0u: goto label_80188EF0;
    case 0x80188F3Cu: goto label_80188F3C;
    case 0x80188F4Cu: goto label_80188F4C;
    case 0x80188F54u: goto label_80188F54;
    case 0x80188F84u: goto label_80188F84;
    case 0x80188FD0u: goto label_80188FD0;
    case 0x8018902Cu: goto label_8018902C;
    case 0x80189070u: goto label_80189070;
    case 0x8018907Cu: goto label_8018907C;
    case 0x80189084u: goto label_80189084;
    case 0x8018909Cu: goto label_8018909C;
    case 0x801890D0u: goto label_801890D0;
    case 0x801890F8u: goto label_801890F8;
    case 0x80189104u: goto label_80189104;
    case 0x80189124u: goto label_80189124;
    case 0x80189130u: goto label_80189130;
    case 0x80189144u: goto label_80189144;
    case 0x80189168u: goto label_80189168;
    case 0x80189188u: goto label_80189188;
    case 0x80189190u: goto label_80189190;
    case 0x8018919Cu: goto label_8018919C;
    case 0x801891DCu: goto label_801891DC;
    case 0x801891E4u: goto label_801891E4;
    case 0x801891FCu: goto label_801891FC;
    case 0x80189208u: goto label_80189208;
    case 0x80189220u: goto label_80189220;
    case 0x80189240u: goto label_80189240;
    case 0x80189268u: goto label_80189268;
    case 0x80189284u: goto label_80189284;
    case 0x801892A8u: goto label_801892A8;
    case 0x801892CCu: goto label_801892CC;
    case 0x80189300u: goto label_80189300;
    case 0x80189328u: goto label_80189328;
    case 0x80189350u: goto label_80189350;
    case 0x80189378u: goto label_80189378;
    case 0x801893B4u: goto label_801893B4;
    case 0x801893D4u: goto label_801893D4;
    case 0x801893DCu: goto label_801893DC;
    case 0x80189414u: goto label_80189414;
    case 0x80189434u: goto label_80189434;
    case 0x8018946Cu: goto label_8018946C;
    case 0x80189470u: goto label_80189470;
    case 0x80189478u: goto label_80189478;
    case 0x80189C6Cu: goto label_80189C6C;
    case 0x80189D00u: goto label_80189D00;
    case 0x80189D3Cu: goto label_80189D3C;
    case 0x80189D7Cu: goto label_80189D7C;
    case 0x80189D84u: goto label_80189D84;
    case 0x80189DC4u: goto label_80189DC4;
    case 0x80189DFCu: goto label_80189DFC;
    case 0x80189E24u: goto label_80189E24;
    case 0x80189E88u: goto label_80189E88;
    case 0x80189ED8u: goto label_80189ED8;
    case 0x80189EE8u: goto label_80189EE8;
    case 0x80189EF0u: goto label_80189EF0;
    case 0x80189F60u: goto label_80189F60;
    case 0x80189F68u: goto label_80189F68;
    case 0x80189F74u: goto label_80189F74;
    case 0x80189F7Cu: goto label_80189F7C;
    case 0x80189F84u: goto label_80189F84;
    case 0x80189FC4u: goto label_80189FC4;
    case 0x80189FD4u: goto label_80189FD4;
    case 0x8018A008u: goto label_8018A008;
    case 0x8018A04Cu: goto label_8018A04C;
    case 0x8018A088u: goto label_8018A088;
    case 0x8018A090u: goto label_8018A090;
    case 0x8018A0CCu: goto label_8018A0CC;
    case 0x8018A11Cu: goto label_8018A11C;
    case 0x8018A1D8u: goto label_8018A1D8;
    case 0x8018A1E0u: goto label_8018A1E0;
    case 0x8018A260u: goto label_8018A260;
    case 0x8018A26Cu: goto label_8018A26C;
    case 0x8018A280u: goto label_8018A280;
    case 0x8018A288u: goto label_8018A288;
    case 0x8018A294u: goto label_8018A294;
    case 0x8018A29Cu: goto label_8018A29C;
    case 0x8018A2A0u: goto label_8018A2A0;
    case 0x8018A2A8u: goto label_8018A2A8;
    case 0x8018A2D4u: goto label_8018A2D4;
    case 0x8018A2DCu: goto label_8018A2DC;
    case 0x8018A2E4u: goto label_8018A2E4;
    case 0x8018A340u: goto label_8018A340;
    case 0x8018A364u: goto label_8018A364;
    case 0x8018A36Cu: goto label_8018A36C;
    case 0x8018A37Cu: goto label_8018A37C;
    case 0x8018A388u: goto label_8018A388;
    case 0x8018A390u: goto label_8018A390;
    case 0x8018A394u: goto label_8018A394;
    case 0x8018A39Cu: goto label_8018A39C;
    case 0x8018A3E4u: goto label_8018A3E4;
    case 0x8018A3ECu: goto label_8018A3EC;
    case 0x8018A3F4u: goto label_8018A3F4;
    case 0x8018A434u: goto label_8018A434;
    case 0x8018A454u: goto label_8018A454;
    case 0x8018A47Cu: goto label_8018A47C;
    case 0x8018A498u: goto label_8018A498;
    case 0x8018A4A0u: goto label_8018A4A0;
    case 0x8018A4ACu: goto label_8018A4AC;
    case 0x8018A4B4u: goto label_8018A4B4;
    case 0x8018A4CCu: goto label_8018A4CC;
    case 0x8018A4D4u: goto label_8018A4D4;
    case 0x8018A50Cu: goto label_8018A50C;
    case 0x8018A514u: goto label_8018A514;
    case 0x8018A51Cu: goto label_8018A51C;
    case 0x8018A524u: goto label_8018A524;
    case 0x8018A6A0u: goto label_8018A6A0;
    case 0x8018A6A8u: goto label_8018A6A8;
    case 0x8018A6C4u: goto label_8018A6C4;
    case 0x8018A6CCu: goto label_8018A6CC;
    case 0x8018A6DCu: goto label_8018A6DC;
    case 0x8018A6E4u: goto label_8018A6E4;
    case 0x8018A740u: goto label_8018A740;
    case 0x8018A748u: goto label_8018A748;
    case 0x8018A764u: goto label_8018A764;
    case 0x8018A76Cu: goto label_8018A76C;
    case 0x8018A774u: goto label_8018A774;
    case 0x8018A7C4u: goto label_8018A7C4;
    case 0x8018A7CCu: goto label_8018A7CC;
    case 0x8018A7E8u: goto label_8018A7E8;
    case 0x8018A7F8u: goto label_8018A7F8;
    case 0x8018A800u: goto label_8018A800;
    case 0x8018A808u: goto label_8018A808;
    case 0x8018A854u: goto label_8018A854;
    case 0x8018A8F8u: goto label_8018A8F8;
    case 0x8018A93Cu: goto label_8018A93C;
    case 0x8018AA24u: goto label_8018AA24;
    case 0x8018AA80u: goto label_8018AA80;
    case 0x8018AA88u: goto label_8018AA88;
    case 0x8018AAB8u: goto label_8018AAB8;
    case 0x8018AAC8u: goto label_8018AAC8;
    case 0x8018AB10u: goto label_8018AB10;
    case 0x8018ABB0u: goto label_8018ABB0;
    case 0x8018ABECu: goto label_8018ABEC;
    case 0x8018AC1Cu: goto label_8018AC1C;
    case 0x8018AC50u: goto label_8018AC50;
    case 0x8018AC94u: goto label_8018AC94;
    case 0x8018ACECu: goto label_8018ACEC;
    case 0x8018AD08u: goto label_8018AD08;
    case 0x8018AD10u: goto label_8018AD10;
    case 0x8018AD40u: goto label_8018AD40;
    case 0x8018AD50u: goto label_8018AD50;
    case 0x8018ADDCu: goto label_8018ADDC;
    case 0x8018ADF8u: goto label_8018ADF8;
    case 0x8018AE18u: goto label_8018AE18;
    case 0x8018AE60u: goto label_8018AE60;
    case 0x8018AE68u: goto label_8018AE68;
    case 0x8018AE7Cu: goto label_8018AE7C;
    case 0x8018AE84u: goto label_8018AE84;
    case 0x8018AE8Cu: goto label_8018AE8C;
    case 0x8018B108u: goto label_8018B108;
    case 0x8018B114u: goto label_8018B114;
    default: return;
    }
}

