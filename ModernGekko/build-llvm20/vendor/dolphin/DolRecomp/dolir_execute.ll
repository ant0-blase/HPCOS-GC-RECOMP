; ModuleID = 'dolrecomp_native'
source_filename = "dolrecomp_native"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@g_mem_write_journal = external global ptr
@g_mem_write_journal_user = external global ptr

define hidden void @func_80001000(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 4
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 16
  %5 = load i32, ptr %4, align 4
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 264
  %7 = load <4 x double>, ptr %6, align 8
  %8 = extractelement <4 x double> %7, i32 0
  %9 = getelementptr inbounds nuw i8, ptr %ctx, i64 520
  %10 = load double, ptr %9, align 8
  %11 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %12 = load i32, ptr %11, align 4
  %13 = getelementptr inbounds nuw i8, ptr %ctx, i64 652
  %14 = load i32, ptr %13, align 4
  %15 = getelementptr inbounds nuw i8, ptr %ctx, i64 656
  %16 = load i32, ptr %15, align 4
  %17 = getelementptr inbounds nuw i8, ptr %ctx, i64 660
  %18 = load i32, ptr %17, align 4
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 664
  %20 = load i32, ptr %19, align 4
  %21 = getelementptr inbounds nuw i8, ptr %ctx, i64 832
  %22 = load i32, ptr %21, align 4
  %23 = getelementptr inbounds nuw i8, ptr %ctx, i64 836
  %24 = load i1, ptr %23, align 1
  %25 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %26 = load i32, ptr %25, align 4
  %fma.result = alloca double, align 8
  %27 = sub i32 %26, -2147479552
  %28 = tail call i32 @llvm.fshl.i32(i32 %27, i32 %27, i32 30)
  switch i32 %28, label %common.ret [
    i32 0, label %guest_80001000_b0
    i32 1, label %guest_80001004_b1
    i32 2, label %guest_80001008_b2
    i32 3, label %entry.guest_8000100C_b3_crit_edge
    i32 4, label %entry.guest_80001010_b4_crit_edge
    i32 5, label %guest_80001014_b5
    i32 6, label %entry.guest_80001018_b6_crit_edge
    i32 7, label %entry.guest_8000101C_b7_crit_edge
    i32 8, label %entry.guest_80001020_b8_crit_edge
    i32 9, label %guest_80001024_b9
  ]

entry.guest_80001020_b8_crit_edge:                ; preds = %entry
  %.phi.trans.insert24 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre25 = load i64, ptr %.phi.trans.insert24, align 8
  br label %guest_80001020_b8

entry.guest_8000101C_b7_crit_edge:                ; preds = %entry
  %.phi.trans.insert22 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre23 = load i64, ptr %.phi.trans.insert22, align 8
  br label %guest_8000101C_b7

entry.guest_80001018_b6_crit_edge:                ; preds = %entry
  %.phi.trans.insert20 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre21 = load i64, ptr %.phi.trans.insert20, align 8
  br label %guest_80001018_b6

entry.guest_80001010_b4_crit_edge:                ; preds = %entry
  %.phi.trans.insert18 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre19 = load i64, ptr %.phi.trans.insert18, align 8
  br label %guest_80001010_b4

entry.guest_8000100C_b3_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  br label %guest_8000100C_b3

guest_80001000_b0:                                ; preds = %entry
  %29 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %30 = load i64, ptr %29, align 8
  %31 = add i64 %30, -1
  store i64 %31, ptr %29, align 8
  br label %guest_80001004_b1

guest_80001004_b1:                                ; preds = %guest_80001000_b0, %entry
  %cycles.0.neg = phi i64 [ 0, %entry ], [ -1, %guest_80001000_b0 ]
  %state1.0 = phi i32 [ %3, %entry ], [ 0, %guest_80001000_b0 ]
  store i32 %state1.0, ptr %2, align 4
  store i32 -2147479548, ptr %25, align 4
  %32 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %33 = load i64, ptr %32, align 8
  %34 = add i64 %cycles.0.neg, %33
  store i64 %34, ptr %32, align 8
  tail call void @ppc_fallback_instruction(ptr nonnull %ctx, i32 0, i32 -2147479548)
  %35 = load i32, ptr %25, align 4
  %36 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %37 = load i32, ptr %36, align 4
  %38 = icmp eq i32 %37, 0
  %39 = icmp eq i32 %35, -2147479544
  %40 = and i1 %39, %38
  br i1 %40, label %fallback_resume, label %common.ret

guest_80001008_b2:                                ; preds = %fallback_resume, %entry
  %state14.0 = phi i1 [ %24, %entry ], [ %114, %fallback_resume ]
  %state13.0 = phi i32 [ %22, %entry ], [ %113, %fallback_resume ]
  %state12.0 = phi i32 [ %20, %entry ], [ %112, %fallback_resume ]
  %state11.0 = phi i32 [ %18, %entry ], [ %111, %fallback_resume ]
  %state10.0 = phi i32 [ %16, %entry ], [ %110, %fallback_resume ]
  %state9.0 = phi i32 [ %14, %entry ], [ %109, %fallback_resume ]
  %state8.0 = phi i32 [ %12, %entry ], [ %108, %fallback_resume ]
  %state7.0 = phi double [ %10, %entry ], [ %107, %fallback_resume ]
  %state1.1 = phi i32 [ %3, %entry ], [ %105, %fallback_resume ]
  %state.0 = phi i32 [ %1, %entry ], [ %104, %fallback_resume ]
  %41 = phi <4 x double> [ %7, %entry ], [ %106, %fallback_resume ]
  %42 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %43 = load i64, ptr %42, align 8
  %44 = add i64 %43, -1
  br label %guest_8000100C_b3

guest_8000100C_b3:                                ; preds = %entry.guest_8000100C_b3_crit_edge, %guest_80001008_b2
  %45 = phi i64 [ %.pre, %entry.guest_8000100C_b3_crit_edge ], [ %44, %guest_80001008_b2 ]
  %cycles.2 = phi i64 [ 1, %entry.guest_8000100C_b3_crit_edge ], [ 2, %guest_80001008_b2 ]
  %state14.1 = phi i1 [ %24, %entry.guest_8000100C_b3_crit_edge ], [ %state14.0, %guest_80001008_b2 ]
  %state13.1 = phi i32 [ %22, %entry.guest_8000100C_b3_crit_edge ], [ %state13.0, %guest_80001008_b2 ]
  %state12.1 = phi i32 [ %20, %entry.guest_8000100C_b3_crit_edge ], [ %state12.0, %guest_80001008_b2 ]
  %state11.1 = phi i32 [ %18, %entry.guest_8000100C_b3_crit_edge ], [ %state11.0, %guest_80001008_b2 ]
  %state10.1 = phi i32 [ %16, %entry.guest_8000100C_b3_crit_edge ], [ %state10.0, %guest_80001008_b2 ]
  %state9.1 = phi i32 [ %14, %entry.guest_8000100C_b3_crit_edge ], [ %state9.0, %guest_80001008_b2 ]
  %state8.1 = phi i32 [ %12, %entry.guest_8000100C_b3_crit_edge ], [ %state8.0, %guest_80001008_b2 ]
  %state7.1 = phi double [ %10, %entry.guest_8000100C_b3_crit_edge ], [ %state7.0, %guest_80001008_b2 ]
  %state2.0 = phi i32 [ %5, %entry.guest_8000100C_b3_crit_edge ], [ 0, %guest_80001008_b2 ]
  %state1.2 = phi i32 [ %3, %entry.guest_8000100C_b3_crit_edge ], [ %state1.1, %guest_80001008_b2 ]
  %state.1 = phi i32 [ %1, %entry.guest_8000100C_b3_crit_edge ], [ %state.0, %guest_80001008_b2 ]
  %46 = phi <4 x double> [ %7, %entry.guest_8000100C_b3_crit_edge ], [ %41, %guest_80001008_b2 ]
  %47 = add i64 %45, -1
  %48 = add i32 %state2.0, %state1.2
  br label %guest_80001010_b4

guest_80001010_b4:                                ; preds = %entry.guest_80001010_b4_crit_edge, %budget_run, %guest_8000100C_b3
  %49 = phi i64 [ %90, %budget_run ], [ %.pre19, %entry.guest_80001010_b4_crit_edge ], [ %47, %guest_8000100C_b3 ]
  %cycles.3 = phi i64 [ %cycles.6, %budget_run ], [ 0, %entry.guest_80001010_b4_crit_edge ], [ %cycles.2, %guest_8000100C_b3 ]
  %state14.2 = phi i1 [ %state14.5, %budget_run ], [ %24, %entry.guest_80001010_b4_crit_edge ], [ %state14.1, %guest_8000100C_b3 ]
  %state13.2 = phi i32 [ %state13.5, %budget_run ], [ %22, %entry.guest_80001010_b4_crit_edge ], [ %state13.1, %guest_8000100C_b3 ]
  %state12.2 = phi i32 [ %state12.5, %budget_run ], [ %20, %entry.guest_80001010_b4_crit_edge ], [ %state12.1, %guest_8000100C_b3 ]
  %state11.2 = phi i32 [ %state11.5, %budget_run ], [ %18, %entry.guest_80001010_b4_crit_edge ], [ %state11.1, %guest_8000100C_b3 ]
  %state10.2 = phi i32 [ %state10.5, %budget_run ], [ %16, %entry.guest_80001010_b4_crit_edge ], [ %state10.1, %guest_8000100C_b3 ]
  %state9.2 = phi i32 [ %state9.5, %budget_run ], [ %14, %entry.guest_80001010_b4_crit_edge ], [ %state9.1, %guest_8000100C_b3 ]
  %state8.2 = phi i32 [ %state8.5, %budget_run ], [ %12, %entry.guest_80001010_b4_crit_edge ], [ %state8.1, %guest_8000100C_b3 ]
  %state7.2 = phi double [ %state7.5, %budget_run ], [ %10, %entry.guest_80001010_b4_crit_edge ], [ %state7.1, %guest_8000100C_b3 ]
  %state2.1 = phi i32 [ %state2.4, %budget_run ], [ %5, %entry.guest_80001010_b4_crit_edge ], [ %48, %guest_8000100C_b3 ]
  %state1.3 = phi i32 [ %state1.6, %budget_run ], [ %3, %entry.guest_80001010_b4_crit_edge ], [ %state1.2, %guest_8000100C_b3 ]
  %state.2 = phi i32 [ %state.5, %budget_run ], [ %1, %entry.guest_80001010_b4_crit_edge ], [ %state.1, %guest_8000100C_b3 ]
  %50 = phi <4 x double> [ %87, %budget_run ], [ %7, %entry.guest_80001010_b4_crit_edge ], [ %46, %guest_8000100C_b3 ]
  %51 = add i64 %cycles.3, 1
  %52 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %53 = add i64 %49, -1
  store i64 %53, ptr %52, align 8
  %54 = xor i32 %state13.2, %state.2
  %55 = icmp ugt i32 %54, 31
  %56 = and i1 %state14.2, %55
  %57 = and i32 %state.2, -1073741825
  %58 = getelementptr inbounds nuw i8, ptr %ctx, i64 3464
  %59 = load i32, ptr %58, align 4
  %60 = xor i32 %57, -2147483648
  %61 = icmp ugt i32 %59, 3
  %62 = add i32 %59, -4
  %63 = icmp ule i32 %60, %62
  %64 = and i1 %61, %63
  br i1 %64, label %store_mem1, label %store_check_mem2

guest_80001014_b5:                                ; preds = %store_join, %entry
  %cycles.4 = phi i64 [ %135, %store_join ], [ 3, %entry ]
  %state14.3 = phi i1 [ %state14.8, %store_join ], [ %24, %entry ]
  %state13.3 = phi i32 [ %state13.6, %store_join ], [ %22, %entry ]
  %state12.3 = phi i32 [ %state12.7, %store_join ], [ %20, %entry ]
  %state11.3 = phi i32 [ %state11.8, %store_join ], [ %18, %entry ]
  %state10.3 = phi i32 [ %state10.6, %store_join ], [ %16, %entry ]
  %state9.3 = phi i32 [ %state9.8, %store_join ], [ %14, %entry ]
  %state8.3 = phi i32 [ %state8.8, %store_join ], [ %12, %entry ]
  %state7.3 = phi double [ %state7.8, %store_join ], [ %10, %entry ]
  %state2.2 = phi i32 [ %state2.7, %store_join ], [ %5, %entry ]
  %state1.4 = phi i32 [ %state1.9, %store_join ], [ %3, %entry ]
  %state.3 = phi i32 [ %state.6, %store_join ], [ %1, %entry ]
  %65 = phi <4 x double> [ %134, %store_join ], [ %7, %entry ]
  %66 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %67 = load i64, ptr %66, align 8
  %68 = add i64 %67, -1
  %69 = add i32 %state1.4, 1
  br label %guest_80001018_b6

guest_80001018_b6:                                ; preds = %entry.guest_80001018_b6_crit_edge, %guest_80001014_b5
  %70 = phi i64 [ %68, %guest_80001014_b5 ], [ %.pre21, %entry.guest_80001018_b6_crit_edge ]
  %cycles.5 = phi i64 [ %cycles.4, %guest_80001014_b5 ], [ 2, %entry.guest_80001018_b6_crit_edge ]
  %state14.4 = phi i1 [ %state14.3, %guest_80001014_b5 ], [ %24, %entry.guest_80001018_b6_crit_edge ]
  %state13.4 = phi i32 [ %state13.3, %guest_80001014_b5 ], [ %22, %entry.guest_80001018_b6_crit_edge ]
  %state12.4 = phi i32 [ %state12.3, %guest_80001014_b5 ], [ %20, %entry.guest_80001018_b6_crit_edge ]
  %state11.4 = phi i32 [ %state11.3, %guest_80001014_b5 ], [ %18, %entry.guest_80001018_b6_crit_edge ]
  %state10.4 = phi i32 [ %state10.3, %guest_80001014_b5 ], [ %16, %entry.guest_80001018_b6_crit_edge ]
  %state9.4 = phi i32 [ %state9.3, %guest_80001014_b5 ], [ %14, %entry.guest_80001018_b6_crit_edge ]
  %state8.4 = phi i32 [ %state8.3, %guest_80001014_b5 ], [ %12, %entry.guest_80001018_b6_crit_edge ]
  %state7.4 = phi double [ %state7.3, %guest_80001014_b5 ], [ %10, %entry.guest_80001018_b6_crit_edge ]
  %state2.3 = phi i32 [ %state2.2, %guest_80001014_b5 ], [ %5, %entry.guest_80001018_b6_crit_edge ]
  %state1.5 = phi i32 [ %69, %guest_80001014_b5 ], [ %3, %entry.guest_80001018_b6_crit_edge ]
  %state.4 = phi i32 [ %state.3, %guest_80001014_b5 ], [ %1, %entry.guest_80001018_b6_crit_edge ]
  %71 = phi <4 x double> [ %65, %guest_80001014_b5 ], [ %7, %entry.guest_80001018_b6_crit_edge ]
  %72 = add i64 %70, -1
  %73 = icmp slt i32 %state1.5, 10
  %74 = icmp sgt i32 %state1.5, 10
  %75 = icmp eq i32 %state1.5, 10
  %76 = select i1 %73, i32 8, i32 0
  %77 = select i1 %74, i32 4, i32 0
  %78 = or disjoint i32 %76, %77
  %79 = select i1 %75, i32 2, i32 0
  %80 = or disjoint i32 %78, %79
  %81 = lshr i32 %state10.4, 31
  %82 = or disjoint i32 %80, %81
  %83 = shl nuw i32 %82, 28
  %84 = and i32 %state9.4, 268435455
  %85 = or disjoint i32 %84, %83
  br label %guest_8000101C_b7

guest_8000101C_b7:                                ; preds = %entry.guest_8000101C_b7_crit_edge, %guest_80001018_b6
  %86 = phi i64 [ %.pre23, %entry.guest_8000101C_b7_crit_edge ], [ %72, %guest_80001018_b6 ]
  %cycles.6 = phi i64 [ 1, %entry.guest_8000101C_b7_crit_edge ], [ %cycles.5, %guest_80001018_b6 ]
  %state14.5 = phi i1 [ %24, %entry.guest_8000101C_b7_crit_edge ], [ %state14.4, %guest_80001018_b6 ]
  %state13.5 = phi i32 [ %22, %entry.guest_8000101C_b7_crit_edge ], [ %state13.4, %guest_80001018_b6 ]
  %state12.5 = phi i32 [ %20, %entry.guest_8000101C_b7_crit_edge ], [ %state12.4, %guest_80001018_b6 ]
  %state11.5 = phi i32 [ %18, %entry.guest_8000101C_b7_crit_edge ], [ %state11.4, %guest_80001018_b6 ]
  %state10.5 = phi i32 [ %16, %entry.guest_8000101C_b7_crit_edge ], [ %state10.4, %guest_80001018_b6 ]
  %state9.5 = phi i32 [ %14, %entry.guest_8000101C_b7_crit_edge ], [ %85, %guest_80001018_b6 ]
  %state8.5 = phi i32 [ %12, %entry.guest_8000101C_b7_crit_edge ], [ %state8.4, %guest_80001018_b6 ]
  %state7.5 = phi double [ %10, %entry.guest_8000101C_b7_crit_edge ], [ %state7.4, %guest_80001018_b6 ]
  %state2.4 = phi i32 [ %5, %entry.guest_8000101C_b7_crit_edge ], [ %state2.3, %guest_80001018_b6 ]
  %state1.6 = phi i32 [ %3, %entry.guest_8000101C_b7_crit_edge ], [ %state1.5, %guest_80001018_b6 ]
  %state.5 = phi i32 [ %1, %entry.guest_8000101C_b7_crit_edge ], [ %state.4, %guest_80001018_b6 ]
  %87 = phi <4 x double> [ %7, %entry.guest_8000101C_b7_crit_edge ], [ %71, %guest_80001018_b6 ]
  %88 = extractelement <4 x double> %87, i32 0
  %89 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %90 = add i64 %86, -1
  store i64 %90, ptr %89, align 8
  %.not16 = icmp sgt i32 %state9.5, -1
  br i1 %.not16, label %guest_80001020_b8, label %cycle_guard

guest_80001020_b8:                                ; preds = %entry.guest_80001020_b8_crit_edge, %guest_8000101C_b7
  %91 = phi i64 [ %.pre25, %entry.guest_80001020_b8_crit_edge ], [ %90, %guest_8000101C_b7 ]
  %cycles.7 = phi i64 [ 0, %entry.guest_80001020_b8_crit_edge ], [ %cycles.6, %guest_8000101C_b7 ]
  %state14.6 = phi i1 [ %24, %entry.guest_80001020_b8_crit_edge ], [ %state14.5, %guest_8000101C_b7 ]
  %state12.6 = phi i32 [ %20, %entry.guest_80001020_b8_crit_edge ], [ %state12.5, %guest_8000101C_b7 ]
  %state11.6 = phi i32 [ %18, %entry.guest_80001020_b8_crit_edge ], [ %state11.5, %guest_8000101C_b7 ]
  %state9.6 = phi i32 [ %14, %entry.guest_80001020_b8_crit_edge ], [ %state9.5, %guest_8000101C_b7 ]
  %state8.6 = phi i32 [ %12, %entry.guest_80001020_b8_crit_edge ], [ %state8.5, %guest_8000101C_b7 ]
  %state7.6 = phi double [ %10, %entry.guest_80001020_b8_crit_edge ], [ %state7.5, %guest_8000101C_b7 ]
  %state3.6 = phi double [ %8, %entry.guest_80001020_b8_crit_edge ], [ %88, %guest_8000101C_b7 ]
  %state2.5 = phi i32 [ %5, %entry.guest_80001020_b8_crit_edge ], [ %state2.4, %guest_8000101C_b7 ]
  %state1.7 = phi i32 [ %3, %entry.guest_80001020_b8_crit_edge ], [ %state1.6, %guest_8000101C_b7 ]
  %92 = phi <4 x double> [ %7, %entry.guest_80001020_b8_crit_edge ], [ %87, %guest_8000101C_b7 ]
  %93 = add i64 %cycles.7, 1
  %94 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %95 = add i64 %91, -1
  store i64 %95, ptr %94, align 8
  %96 = and i32 %state12.6, 8192
  %.not17 = icmp eq i32 %96, 0
  br i1 %.not17, label %fp_check, label %fp_ok

guest_80001024_b9:                                ; preds = %fp_ok, %entry
  %cycles.8.neg = phi i64 [ -1, %entry ], [ %.neg, %fp_ok ]
  %state14.7 = phi i1 [ %24, %entry ], [ %state14.10, %fp_ok ]
  %state11.7 = phi i32 [ %18, %entry ], [ %178, %fp_ok ]
  %state9.7 = phi i32 [ %14, %entry ], [ %state9.10, %fp_ok ]
  %state8.7 = phi i32 [ %12, %entry ], [ %state8.10, %fp_ok ]
  %state7.7 = phi double [ %10, %entry ], [ %177, %fp_ok ]
  %state3.7 = phi double [ %8, %entry ], [ %176, %fp_ok ]
  %state2.6 = phi i32 [ %5, %entry ], [ %state2.9, %fp_ok ]
  %state1.8 = phi i32 [ %3, %entry ], [ %state1.11, %fp_ok ]
  %97 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %98 = load i64, ptr %97, align 8
  %99 = add i64 %98, -1
  store i64 %99, ptr %97, align 8
  %100 = and i32 %state8.7, -4
  store i32 %state1.8, ptr %2, align 4
  store i32 %state2.6, ptr %4, align 4
  store double %state3.7, ptr %6, align 8
  store double %state7.7, ptr %9, align 8
  store i32 %state9.7, ptr %13, align 4
  store i32 %state11.7, ptr %17, align 4
  store i1 %state14.7, ptr %23, align 1
  store i32 %100, ptr %25, align 4
  %101 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %102 = load i64, ptr %101, align 8
  %103 = add i64 %cycles.8.neg, %102
  store i64 %103, ptr %101, align 8
  br label %common.ret

common.ret:                                       ; preds = %fp_check, %write_external, %guest_80001004_b1, %entry, %guest_80001024_b9, %budget_exit
  ret void

fallback_resume:                                  ; preds = %guest_80001004_b1
  %104 = load i32, ptr %0, align 4
  %105 = load i32, ptr %2, align 4
  %106 = load <4 x double>, ptr %6, align 8
  %107 = load double, ptr %9, align 8
  %108 = load i32, ptr %11, align 4
  %109 = load i32, ptr %13, align 4
  %110 = load i32, ptr %15, align 4
  %111 = load i32, ptr %17, align 4
  %112 = load i32, ptr %19, align 4
  %113 = load i32, ptr %21, align 4
  %114 = load i1, ptr %23, align 1
  br label %guest_80001008_b2

store_mem1:                                       ; preds = %guest_80001010_b4
  %115 = getelementptr inbounds nuw i8, ptr %ctx, i64 3456
  %116 = load ptr, ptr %115, align 8
  %117 = load ptr, ptr @g_mem_write_journal, align 8
  %.not15 = icmp eq ptr %117, null
  br i1 %.not15, label %journal_done, label %journal

store_check_mem2:                                 ; preds = %guest_80001010_b4
  %118 = getelementptr inbounds nuw i8, ptr %ctx, i64 3496
  %119 = load i32, ptr %118, align 4
  %120 = getelementptr inbounds nuw i8, ptr %ctx, i64 3488
  %121 = load ptr, ptr %120, align 8
  %122 = add i32 %57, 1879048192
  %123 = icmp ugt i32 %119, 3
  %124 = add i32 %119, -4
  %125 = icmp ule i32 %122, %124
  %126 = and i1 %123, %125
  %127 = icmp ne ptr %121, null
  %128 = and i1 %127, %126
  br i1 %128, label %store_mem2, label %store_slow

store_mem2:                                       ; preds = %store_check_mem2
  %129 = sext i32 %122 to i64
  %130 = getelementptr inbounds i8, ptr %121, i64 %129
  %131 = tail call i32 @llvm.bswap.i32(i32 %state1.3)
  store i32 %131, ptr %130, align 4
  br label %store_join

store_slow:                                       ; preds = %store_check_mem2
  %132 = getelementptr inbounds nuw i8, ptr %ctx, i64 3408
  %133 = load ptr, ptr %132, align 8
  %.not = icmp eq ptr %133, null
  br i1 %.not, label %store_join, label %write_external

store_join:                                       ; preds = %store_slow, %write_slow_resume, %store_mem2, %journal_done
  %cycles.9 = phi i64 [ %51, %journal_done ], [ %51, %store_mem2 ], [ 0, %write_slow_resume ], [ %51, %store_slow ]
  %state14.8 = phi i1 [ %56, %journal_done ], [ %56, %store_mem2 ], [ %159, %write_slow_resume ], [ %56, %store_slow ]
  %state13.6 = phi i32 [ %state13.2, %journal_done ], [ %state13.2, %store_mem2 ], [ %158, %write_slow_resume ], [ %state13.2, %store_slow ]
  %state12.7 = phi i32 [ %state12.2, %journal_done ], [ %state12.2, %store_mem2 ], [ %157, %write_slow_resume ], [ %state12.2, %store_slow ]
  %state11.8 = phi i32 [ %state11.2, %journal_done ], [ %state11.2, %store_mem2 ], [ %156, %write_slow_resume ], [ %state11.2, %store_slow ]
  %state10.6 = phi i32 [ %state10.2, %journal_done ], [ %state10.2, %store_mem2 ], [ %155, %write_slow_resume ], [ %state10.2, %store_slow ]
  %state9.8 = phi i32 [ %state9.2, %journal_done ], [ %state9.2, %store_mem2 ], [ %154, %write_slow_resume ], [ %state9.2, %store_slow ]
  %state8.8 = phi i32 [ %state8.2, %journal_done ], [ %state8.2, %store_mem2 ], [ %153, %write_slow_resume ], [ %state8.2, %store_slow ]
  %state7.8 = phi double [ %state7.2, %journal_done ], [ %state7.2, %store_mem2 ], [ %152, %write_slow_resume ], [ %state7.2, %store_slow ]
  %state2.7 = phi i32 [ %state2.1, %journal_done ], [ %state2.1, %store_mem2 ], [ %150, %write_slow_resume ], [ %state2.1, %store_slow ]
  %state1.9 = phi i32 [ %state1.3, %journal_done ], [ %state1.3, %store_mem2 ], [ %149, %write_slow_resume ], [ %state1.3, %store_slow ]
  %state.6 = phi i32 [ %state.2, %journal_done ], [ %state.2, %store_mem2 ], [ %148, %write_slow_resume ], [ %state.2, %store_slow ]
  %134 = phi <4 x double> [ %50, %journal_done ], [ %50, %store_mem2 ], [ %151, %write_slow_resume ], [ %50, %store_slow ]
  %135 = add i64 %cycles.9, 3
  br label %guest_80001014_b5

journal:                                          ; preds = %store_mem1
  %136 = load ptr, ptr @g_mem_write_journal_user, align 8
  tail call void %117(i32 %60, i32 4, ptr %136)
  br label %journal_done

journal_done:                                     ; preds = %journal, %store_mem1
  %137 = sext i32 %60 to i64
  %138 = getelementptr inbounds i8, ptr %116, i64 %137
  %139 = tail call i32 @llvm.bswap.i32(i32 %state1.3)
  store i32 %139, ptr %138, align 4
  br label %store_join

write_external:                                   ; preds = %store_slow
  store i32 %state1.3, ptr %2, align 4
  store i32 %state2.1, ptr %4, align 4
  %140 = extractelement <4 x double> %50, i32 0
  store double %140, ptr %6, align 8
  store double %state7.2, ptr %9, align 8
  store i32 %state9.2, ptr %13, align 4
  store i32 %state11.2, ptr %17, align 4
  store i1 %56, ptr %23, align 1
  store i32 -2147479536, ptr %25, align 4
  %141 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %142 = load i64, ptr %141, align 8
  %143 = sub i64 %142, %51
  store i64 %143, ptr %141, align 8
  %144 = zext i32 %state1.3 to i64
  tail call void %133(ptr nonnull %ctx, i32 %state.2, i64 %144, i8 4)
  %145 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %146 = load i32, ptr %145, align 4
  %147 = icmp eq i32 %146, 0
  br i1 %147, label %write_slow_resume, label %common.ret

write_slow_resume:                                ; preds = %write_external
  %148 = load i32, ptr %0, align 4
  %149 = load i32, ptr %2, align 4
  %150 = load i32, ptr %4, align 4
  %151 = load <4 x double>, ptr %6, align 8
  %152 = load double, ptr %9, align 8
  %153 = load i32, ptr %11, align 4
  %154 = load i32, ptr %13, align 4
  %155 = load i32, ptr %15, align 4
  %156 = load i32, ptr %17, align 4
  %157 = load i32, ptr %19, align 4
  %158 = load i32, ptr %21, align 4
  %159 = load i1, ptr %23, align 1
  br label %store_join

cycle_guard:                                      ; preds = %guest_8000101C_b7
  %160 = getelementptr inbounds nuw i8, ptr %ctx, i64 3512
  %161 = load i32, ptr %160, align 4
  %162 = icmp slt i64 %90, 1
  %163 = icmp eq i32 %161, 0
  %164 = or i1 %162, %163
  br i1 %164, label %budget_exit, label %budget_run

budget_run:                                       ; preds = %cycle_guard
  %165 = add i32 %161, -1
  store i32 %165, ptr %160, align 4
  br label %guest_80001010_b4

budget_exit:                                      ; preds = %cycle_guard
  store i32 %state1.6, ptr %2, align 4
  store i32 %state2.4, ptr %4, align 4
  store double %88, ptr %6, align 8
  store double %state7.5, ptr %9, align 8
  store i32 %state9.5, ptr %13, align 4
  store i32 %state11.5, ptr %17, align 4
  store i1 %state14.5, ptr %23, align 1
  store i32 -2147479536, ptr %25, align 4
  %166 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %167 = load i64, ptr %166, align 8
  %168 = sub i64 %167, %cycles.6
  store i64 %168, ptr %166, align 8
  br label %common.ret

fp_ok:                                            ; preds = %fp_reload, %guest_80001020_b8
  %cycles.11 = phi i64 [ %93, %guest_80001020_b8 ], [ 0, %fp_reload ]
  %state14.10 = phi i1 [ %state14.6, %guest_80001020_b8 ], [ %190, %fp_reload ]
  %state11.10 = phi i32 [ %state11.6, %guest_80001020_b8 ], [ %189, %fp_reload ]
  %state9.10 = phi i32 [ %state9.6, %guest_80001020_b8 ], [ %188, %fp_reload ]
  %state8.10 = phi i32 [ %state8.6, %guest_80001020_b8 ], [ %187, %fp_reload ]
  %state7.10 = phi double [ %state7.6, %guest_80001020_b8 ], [ %186, %fp_reload ]
  %state2.9 = phi i32 [ %state2.5, %guest_80001020_b8 ], [ %184, %fp_reload ]
  %state1.11 = phi i32 [ %state1.7, %guest_80001020_b8 ], [ %183, %fp_reload ]
  %169 = phi <4 x double> [ %92, %guest_80001020_b8 ], [ %185, %fp_reload ]
  store i32 %state11.10, ptr %17, align 4
  %170 = extractelement <4 x double> %169, i32 0
  store double %170, ptr %fma.result, align 8
  %171 = extractelement <4 x double> %169, i32 1
  %172 = extractelement <4 x double> %169, i32 2
  %173 = extractelement <4 x double> %169, i32 3
  %174 = call i1 @ppc_fma(ptr nonnull %ctx, double %171, double %172, double %173, i1 true, i1 false, i1 false, ptr nonnull %fma.result)
  %175 = load double, ptr %fma.result, align 8
  %176 = select i1 %174, double %175, double %170
  %177 = select i1 %174, double %175, double %state7.10
  %178 = load i32, ptr %17, align 4
  %.neg = xor i64 %cycles.11, -1
  br label %guest_80001024_b9

fp_check:                                         ; preds = %guest_80001020_b8
  store i32 %state1.7, ptr %2, align 4
  store i32 %state2.5, ptr %4, align 4
  store double %state3.6, ptr %6, align 8
  store double %state7.6, ptr %9, align 8
  store i32 %state9.6, ptr %13, align 4
  store i32 %state11.6, ptr %17, align 4
  store i1 %state14.6, ptr %23, align 1
  store i32 -2147479520, ptr %25, align 4
  %179 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %180 = load i64, ptr %179, align 8
  %181 = sub i64 %180, %93
  store i64 %181, ptr %179, align 8
  %182 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147479520)
  br i1 %182, label %fp_reload, label %common.ret

fp_reload:                                        ; preds = %fp_check
  %183 = load i32, ptr %2, align 4
  %184 = load i32, ptr %4, align 4
  %185 = load <4 x double>, ptr %6, align 8
  %186 = load double, ptr %9, align 8
  %187 = load i32, ptr %11, align 4
  %188 = load i32, ptr %13, align 4
  %189 = load i32, ptr %17, align 4
  %190 = load i1, ptr %23, align 1
  br label %fp_ok
}

declare void @ppc_fallback_instruction(ptr, i32, i32)

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.bswap.i32(i32) #0

declare i1 @ppc_fp_available(ptr, i32)

declare i1 @ppc_fma(ptr, double, double, double, i1, i1, i1, ptr)

define hidden void @func_80002000(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 16
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 664
  %6 = load i32, ptr %5, align 4
  %7 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %8 = load i32, ptr %7, align 4
  switch i32 %8, label %common.ret [
    i32 -2147475456, label %guest_80002000_b0
    i32 -2147475452, label %guest_80002004_b1
    i32 -2147475448, label %guest_80002008_b2
  ]

guest_80002000_b0:                                ; preds = %entry
  %9 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %10 = load i64, ptr %9, align 8
  %11 = add i64 %10, -2
  store i64 %11, ptr %9, align 8
  %12 = and i32 %6, 16384
  %.not = icmp eq i32 %12, 0
  br i1 %.not, label %trap_resume, label %trap_taken

guest_80002004_b1:                                ; preds = %mtspr_resume, %entry
  %state3.0 = phi i32 [ %6, %entry ], [ %34, %mtspr_resume ]
  %state1.0 = phi i32 [ %3, %entry ], [ %33, %mtspr_resume ]
  %13 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %14 = load i64, ptr %13, align 8
  %15 = add i64 %14, -1
  store i64 %15, ptr %13, align 8
  %16 = and i32 %state3.0, 16384
  %.not6 = icmp eq i32 %16, 0
  br i1 %.not6, label %trap_resume5, label %trap_taken4

guest_80002008_b2:                                ; preds = %trap_resume5, %entry
  %state1.1 = phi i32 [ %3, %entry ], [ %41, %trap_resume5 ]
  %state2.0 = load i32, ptr %4, align 4
  %17 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %18 = load i64, ptr %17, align 8
  %19 = add i64 %18, -1
  store i64 %19, ptr %17, align 8
  %20 = and i32 %state2.0, -4
  store i32 %state1.1, ptr %2, align 4
  store i32 %20, ptr %7, align 4
  %21 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %22 = load i64, ptr %21, align 8
  %23 = add i64 %22, -1
  store i64 %23, ptr %21, align 8
  br label %common.ret

common.ret:                                       ; preds = %trap_resume5, %trap_resume, %entry, %guest_80002008_b2, %trap_taken4, %trap_taken
  ret void

trap_taken:                                       ; preds = %guest_80002000_b0
  store i32 -2147475456, ptr %7, align 4
  %24 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %25 = load i64, ptr %24, align 8
  %26 = add i64 %25, -2
  store i64 %26, ptr %24, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 262144, i32 -2147475456)
  br label %common.ret

trap_resume:                                      ; preds = %guest_80002000_b0
  store i32 -2147475456, ptr %7, align 4
  %27 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %28 = load i64, ptr %27, align 8
  %29 = add i64 %28, -2
  store i64 %29, ptr %27, align 8
  tail call void @ppc_mtspr(ptr nonnull %ctx, i16 273, i32 %1, i32 -2147475456)
  %30 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %31 = load i32, ptr %30, align 4
  %32 = icmp eq i32 %31, 0
  br i1 %32, label %mtspr_resume, label %common.ret

mtspr_resume:                                     ; preds = %trap_resume
  %33 = load i32, ptr %2, align 4
  %34 = load i32, ptr %5, align 4
  br label %guest_80002004_b1

trap_taken4:                                      ; preds = %guest_80002004_b1
  store i32 %state1.0, ptr %2, align 4
  store i32 -2147475452, ptr %7, align 4
  %35 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %36 = load i64, ptr %35, align 8
  %37 = add i64 %36, -1
  store i64 %37, ptr %35, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 262144, i32 -2147475452)
  br label %common.ret

trap_resume5:                                     ; preds = %guest_80002004_b1
  store i32 %state1.0, ptr %2, align 4
  store i32 -2147475452, ptr %7, align 4
  %38 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %39 = load i64, ptr %38, align 8
  %40 = add i64 %39, -1
  store i64 %40, ptr %38, align 8
  %41 = tail call i32 @ppc_mfspr(ptr nonnull %ctx, i16 273, i32 -2147475452)
  %42 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %43 = load i32, ptr %42, align 4
  %44 = icmp eq i32 %43, 0
  br i1 %44, label %guest_80002008_b2, label %common.ret
}

declare void @ppc_program_exception(ptr, i32, i32)

declare void @ppc_mtspr(ptr, i16, i32, i32)

declare i32 @ppc_mfspr(ptr, i16, i32)

define hidden void @func_80002100(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 44
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 48
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 52
  %5 = load i32, ptr %4, align 4
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 56
  %7 = load i32, ptr %6, align 4
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 60
  %9 = load i32, ptr %8, align 4
  %10 = getelementptr inbounds nuw i8, ptr %ctx, i64 64
  %11 = load i32, ptr %10, align 4
  %12 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %13 = load i32, ptr %12, align 4
  %14 = getelementptr inbounds nuw i8, ptr %ctx, i64 664
  %15 = load i32, ptr %14, align 4
  %16 = getelementptr inbounds nuw i8, ptr %ctx, i64 704
  %17 = load i32, ptr %16, align 4
  %18 = getelementptr inbounds nuw i8, ptr %ctx, i64 708
  %19 = load i32, ptr %18, align 4
  %20 = getelementptr inbounds nuw i8, ptr %ctx, i64 712
  %21 = load i32, ptr %20, align 4
  %22 = getelementptr inbounds nuw i8, ptr %ctx, i64 716
  %23 = load i32, ptr %22, align 4
  %24 = getelementptr inbounds nuw i8, ptr %ctx, i64 720
  %25 = load i32, ptr %24, align 4
  %26 = getelementptr inbounds nuw i8, ptr %ctx, i64 724
  %27 = load <4 x i32>, ptr %26, align 4
  %28 = getelementptr inbounds nuw i8, ptr %ctx, i64 740
  %29 = load <4 x i32>, ptr %28, align 4
  %30 = getelementptr inbounds nuw i8, ptr %ctx, i64 756
  %31 = load i32, ptr %30, align 4
  %32 = getelementptr inbounds nuw i8, ptr %ctx, i64 760
  %33 = load i32, ptr %32, align 4
  %34 = getelementptr inbounds nuw i8, ptr %ctx, i64 764
  %35 = load i32, ptr %34, align 4
  %36 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %37 = load i32, ptr %36, align 4
  %38 = sub i32 %37, -2147475200
  %39 = tail call i32 @llvm.fshl.i32(i32 %38, i32 %38, i32 30)
  switch i32 %39, label %common.ret [
    i32 0, label %guest_80002100_b0
    i32 1, label %entry.guest_80002104_b1_crit_edge
    i32 2, label %entry.guest_80002108_b2_crit_edge
    i32 3, label %entry.guest_8000210C_b3_crit_edge
    i32 4, label %entry.guest_80002110_b4_crit_edge
  ]

entry.guest_80002110_b4_crit_edge:                ; preds = %entry
  %.phi.trans.insert37 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre38 = load i64, ptr %.phi.trans.insert37, align 8
  br label %guest_80002110_b4

entry.guest_8000210C_b3_crit_edge:                ; preds = %entry
  %.phi.trans.insert35 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre36 = load i64, ptr %.phi.trans.insert35, align 8
  %.pre42 = and i32 %15, 16384
  br label %guest_8000210C_b3

entry.guest_80002108_b2_crit_edge:                ; preds = %entry
  %.phi.trans.insert33 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre34 = load i64, ptr %.phi.trans.insert33, align 8
  %.pre40 = and i32 %15, 16384
  br label %guest_80002108_b2

entry.guest_80002104_b1_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  %.pre39 = and i32 %15, 16384
  br label %guest_80002104_b1

guest_80002100_b0:                                ; preds = %entry
  %40 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %41 = load i64, ptr %40, align 8
  %42 = add i64 %41, -1
  store i64 %42, ptr %40, align 8
  %43 = and i32 %15, 16384
  %.not = icmp eq i32 %43, 0
  br i1 %.not, label %guest_80002104_b1, label %trap_taken

guest_80002104_b1:                                ; preds = %entry.guest_80002104_b1_crit_edge, %guest_80002100_b0
  %.pre-phi = phi i32 [ %.pre39, %entry.guest_80002104_b1_crit_edge ], [ 0, %guest_80002100_b0 ]
  %44 = phi i64 [ %.pre, %entry.guest_80002104_b1_crit_edge ], [ %42, %guest_80002100_b0 ]
  %state12.0 = phi i32 [ %25, %entry.guest_80002104_b1_crit_edge ], [ %7, %guest_80002100_b0 ]
  %cycles.0 = phi i64 [ 3, %entry.guest_80002104_b1_crit_edge ], [ 4, %guest_80002100_b0 ]
  %45 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %46 = add i64 %44, -3
  store i64 %46, ptr %45, align 8
  %.not30 = icmp eq i32 %.pre-phi, 0
  br i1 %.not30, label %trap_resume25, label %trap_taken24

guest_80002108_b2:                                ; preds = %entry.guest_80002108_b2_crit_edge, %trap_resume25
  %.pre-phi41 = phi i32 [ %.pre40, %entry.guest_80002108_b2_crit_edge ], [ 0, %trap_resume25 ]
  %47 = phi i64 [ %.pre34, %entry.guest_80002108_b2_crit_edge ], [ %46, %trap_resume25 ]
  %state12.1 = phi i32 [ %25, %entry.guest_80002108_b2_crit_edge ], [ %state12.0, %trap_resume25 ]
  %cycles.1 = phi i64 [ 1, %entry.guest_80002108_b2_crit_edge ], [ %70, %trap_resume25 ]
  %state.0 = phi i32 [ %1, %entry.guest_80002108_b2_crit_edge ], [ %23, %trap_resume25 ]
  %48 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %49 = add i64 %47, -1
  store i64 %49, ptr %48, align 8
  %.not31 = icmp eq i32 %.pre-phi41, 0
  br i1 %.not31, label %trap_resume27, label %trap_taken26

guest_8000210C_b3:                                ; preds = %entry.guest_8000210C_b3_crit_edge, %trap_resume27
  %.pre-phi43 = phi i32 [ %.pre42, %entry.guest_8000210C_b3_crit_edge ], [ 0, %trap_resume27 ]
  %50 = phi i64 [ %.pre36, %entry.guest_8000210C_b3_crit_edge ], [ %49, %trap_resume27 ]
  %state12.2 = phi i32 [ %25, %entry.guest_8000210C_b3_crit_edge ], [ %84, %trap_resume27 ]
  %state11.0 = phi i32 [ %23, %entry.guest_8000210C_b3_crit_edge ], [ %82, %trap_resume27 ]
  %state10.0 = phi i32 [ %21, %entry.guest_8000210C_b3_crit_edge ], [ %80, %trap_resume27 ]
  %state9.0 = phi i32 [ %19, %entry.guest_8000210C_b3_crit_edge ], [ %78, %trap_resume27 ]
  %state8.0 = phi i32 [ %17, %entry.guest_8000210C_b3_crit_edge ], [ %76, %trap_resume27 ]
  %state21.0 = phi i32 [ %31, %entry.guest_8000210C_b3_crit_edge ], [ %94, %trap_resume27 ]
  %state22.0 = phi i32 [ %33, %entry.guest_8000210C_b3_crit_edge ], [ %96, %trap_resume27 ]
  %state23.0 = phi i32 [ %35, %entry.guest_8000210C_b3_crit_edge ], [ %98, %trap_resume27 ]
  %cycles.2 = phi i64 [ 3, %entry.guest_8000210C_b3_crit_edge ], [ %99, %trap_resume27 ]
  %state.1 = phi i32 [ %1, %entry.guest_8000210C_b3_crit_edge ], [ %state.0, %trap_resume27 ]
  %51 = phi <4 x i32> [ %27, %entry.guest_8000210C_b3_crit_edge ], [ %90, %trap_resume27 ]
  %52 = phi <4 x i32> [ %29, %entry.guest_8000210C_b3_crit_edge ], [ %92, %trap_resume27 ]
  %53 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %54 = add i64 %50, -3
  store i64 %54, ptr %53, align 8
  %.not32 = icmp eq i32 %.pre-phi43, 0
  br i1 %.not32, label %trap_resume29, label %trap_taken28

guest_80002110_b4:                                ; preds = %entry.guest_80002110_b4_crit_edge, %trap_resume29
  %55 = phi i64 [ %.pre38, %entry.guest_80002110_b4_crit_edge ], [ %54, %trap_resume29 ]
  %state12.3 = phi i32 [ %25, %entry.guest_80002110_b4_crit_edge ], [ %state12.2, %trap_resume29 ]
  %state11.1 = phi i32 [ %23, %entry.guest_80002110_b4_crit_edge ], [ %state11.0, %trap_resume29 ]
  %state10.1 = phi i32 [ %21, %entry.guest_80002110_b4_crit_edge ], [ %state10.0, %trap_resume29 ]
  %state9.1 = phi i32 [ %19, %entry.guest_80002110_b4_crit_edge ], [ %state9.0, %trap_resume29 ]
  %state8.1 = phi i32 [ %17, %entry.guest_80002110_b4_crit_edge ], [ %state8.0, %trap_resume29 ]
  %state21.1 = phi i32 [ %31, %entry.guest_80002110_b4_crit_edge ], [ %state21.0, %trap_resume29 ]
  %state22.1 = phi i32 [ %33, %entry.guest_80002110_b4_crit_edge ], [ %state22.0, %trap_resume29 ]
  %state23.1 = phi i32 [ %35, %entry.guest_80002110_b4_crit_edge ], [ %state23.0, %trap_resume29 ]
  %cycles.3.neg = phi i64 [ -1, %entry.guest_80002110_b4_crit_edge ], [ %.neg, %trap_resume29 ]
  %state1.0 = phi i32 [ %3, %entry.guest_80002110_b4_crit_edge ], [ %141, %trap_resume29 ]
  %state.2 = phi i32 [ %1, %entry.guest_80002110_b4_crit_edge ], [ %state.1, %trap_resume29 ]
  %56 = phi <4 x i32> [ %27, %entry.guest_80002110_b4_crit_edge ], [ %51, %trap_resume29 ]
  %57 = phi <4 x i32> [ %29, %entry.guest_80002110_b4_crit_edge ], [ %52, %trap_resume29 ]
  %58 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %59 = add i64 %55, -1
  store i64 %59, ptr %58, align 8
  %60 = and i32 %13, -4
  store i32 %state.2, ptr %0, align 4
  store i32 %state1.0, ptr %2, align 4
  store i32 %state8.1, ptr %16, align 4
  store i32 %state9.1, ptr %18, align 4
  store i32 %state10.1, ptr %20, align 4
  store i32 %state11.1, ptr %22, align 4
  store i32 %state12.3, ptr %24, align 4
  store <4 x i32> %56, ptr %26, align 4
  store <4 x i32> %57, ptr %28, align 4
  store i32 %state21.1, ptr %30, align 4
  store i32 %state22.1, ptr %32, align 4
  store i32 %state23.1, ptr %34, align 4
  store i32 %60, ptr %36, align 4
  %61 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %62 = load i64, ptr %61, align 8
  %63 = add i64 %cycles.3.neg, %62
  store i64 %63, ptr %61, align 8
  br label %common.ret

common.ret:                                       ; preds = %entry, %guest_80002110_b4, %trap_taken28, %trap_taken26, %trap_taken24, %trap_taken
  ret void

trap_taken:                                       ; preds = %guest_80002100_b0
  store i32 -2147475200, ptr %36, align 4
  %64 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %65 = load i64, ptr %64, align 8
  %66 = add i64 %65, -1
  store i64 %66, ptr %64, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 262144, i32 -2147475200)
  br label %common.ret

trap_taken24:                                     ; preds = %guest_80002104_b1
  store i32 %state12.0, ptr %24, align 4
  store i32 -2147475196, ptr %36, align 4
  %67 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %68 = load i64, ptr %67, align 8
  %69 = sub i64 %68, %cycles.0
  store i64 %69, ptr %67, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 262144, i32 -2147475196)
  br label %common.ret

trap_resume25:                                    ; preds = %guest_80002104_b1
  %70 = add nuw nsw i64 %cycles.0, 1
  br label %guest_80002108_b2

trap_taken26:                                     ; preds = %guest_80002108_b2
  store i32 %state.0, ptr %0, align 4
  store i32 %state12.1, ptr %24, align 4
  store i32 -2147475192, ptr %36, align 4
  %71 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %72 = load i64, ptr %71, align 8
  %73 = sub i64 %72, %cycles.1
  store i64 %73, ptr %71, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 262144, i32 -2147475192)
  br label %common.ret

trap_resume27:                                    ; preds = %guest_80002108_b2
  %74 = lshr i32 %11, 28
  %75 = icmp ult i32 %11, 268435456
  %76 = select i1 %75, i32 %9, i32 %17
  %77 = icmp eq i32 %74, 1
  %78 = select i1 %77, i32 %9, i32 %19
  %79 = icmp eq i32 %74, 2
  %80 = select i1 %79, i32 %9, i32 %21
  %81 = icmp eq i32 %74, 3
  %82 = select i1 %81, i32 %9, i32 %23
  %83 = icmp eq i32 %74, 4
  %84 = select i1 %83, i32 %9, i32 %state12.1
  %85 = insertelement <4 x i32> poison, i32 %74, i32 0
  %86 = shufflevector <4 x i32> %85, <4 x i32> poison, <4 x i32> zeroinitializer
  %87 = icmp eq <4 x i32> %86, <i32 5, i32 6, i32 7, i32 8>
  %88 = insertelement <4 x i32> poison, i32 %9, i32 0
  %89 = shufflevector <4 x i32> %88, <4 x i32> poison, <4 x i32> zeroinitializer
  %90 = select <4 x i1> %87, <4 x i32> %89, <4 x i32> %27
  %91 = icmp eq <4 x i32> %86, <i32 9, i32 10, i32 11, i32 12>
  %92 = select <4 x i1> %91, <4 x i32> %89, <4 x i32> %29
  %93 = icmp eq i32 %74, 13
  %94 = select i1 %93, i32 %9, i32 %31
  %95 = icmp eq i32 %74, 14
  %96 = select i1 %95, i32 %9, i32 %33
  %97 = icmp eq i32 %74, 15
  %98 = select i1 %97, i32 %9, i32 %35
  %99 = add nuw nsw i64 %cycles.1, 3
  br label %guest_8000210C_b3

trap_taken28:                                     ; preds = %guest_8000210C_b3
  store i32 %state.1, ptr %0, align 4
  store i32 %state8.0, ptr %16, align 4
  store i32 %state9.0, ptr %18, align 4
  store i32 %state10.0, ptr %20, align 4
  store i32 %state11.0, ptr %22, align 4
  store i32 %state12.2, ptr %24, align 4
  store <4 x i32> %51, ptr %26, align 4
  store <4 x i32> %52, ptr %28, align 4
  store i32 %state21.0, ptr %30, align 4
  store i32 %state22.0, ptr %32, align 4
  store i32 %state23.0, ptr %34, align 4
  store i32 -2147475188, ptr %36, align 4
  %100 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %101 = load i64, ptr %100, align 8
  %102 = sub i64 %101, %cycles.2
  store i64 %102, ptr %100, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 262144, i32 -2147475188)
  br label %common.ret

trap_resume29:                                    ; preds = %guest_8000210C_b3
  %103 = lshr i32 %5, 28
  %104 = icmp eq i32 %103, 1
  %105 = select i1 %104, i32 %state9.0, i32 %state8.0
  %106 = icmp eq i32 %103, 2
  %107 = select i1 %106, i32 %state10.0, i32 %105
  %108 = icmp eq i32 %103, 3
  %109 = select i1 %108, i32 %state11.0, i32 %107
  %110 = icmp eq i32 %103, 4
  %111 = select i1 %110, i32 %state12.2, i32 %109
  %112 = icmp eq i32 %103, 5
  %113 = extractelement <4 x i32> %51, i32 0
  %114 = select i1 %112, i32 %113, i32 %111
  %115 = icmp eq i32 %103, 6
  %116 = extractelement <4 x i32> %51, i32 1
  %117 = select i1 %115, i32 %116, i32 %114
  %118 = icmp eq i32 %103, 7
  %119 = extractelement <4 x i32> %51, i32 2
  %120 = select i1 %118, i32 %119, i32 %117
  %121 = icmp eq i32 %103, 8
  %122 = extractelement <4 x i32> %51, i32 3
  %123 = select i1 %121, i32 %122, i32 %120
  %124 = icmp eq i32 %103, 9
  %125 = extractelement <4 x i32> %52, i32 0
  %126 = select i1 %124, i32 %125, i32 %123
  %127 = icmp eq i32 %103, 10
  %128 = extractelement <4 x i32> %52, i32 1
  %129 = select i1 %127, i32 %128, i32 %126
  %130 = icmp eq i32 %103, 11
  %131 = extractelement <4 x i32> %52, i32 2
  %132 = select i1 %130, i32 %131, i32 %129
  %133 = icmp eq i32 %103, 12
  %134 = extractelement <4 x i32> %52, i32 3
  %135 = select i1 %133, i32 %134, i32 %132
  %136 = icmp eq i32 %103, 13
  %137 = select i1 %136, i32 %state21.0, i32 %135
  %138 = icmp eq i32 %103, 14
  %139 = select i1 %138, i32 %state22.0, i32 %137
  %140 = icmp eq i32 %103, 15
  %141 = select i1 %140, i32 %state23.0, i32 %139
  %.neg = xor i64 %cycles.2, -1
  br label %guest_80002110_b4
}

define hidden void @func_80002200(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 232
  %1 = load double, ptr %0, align 8
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 660
  %5 = load i32, ptr %4, align 4
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 664
  %7 = load i32, ptr %6, align 4
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %9 = load i32, ptr %8, align 4
  switch i32 %9, label %common.ret [
    i32 -2147474944, label %guest_80002200_b0
    i32 -2147474940, label %guest_80002204_b1
    i32 -2147474936, label %guest_80002208_b2
  ]

guest_80002200_b0:                                ; preds = %entry
  %10 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %11 = load i64, ptr %10, align 8
  %12 = add i64 %11, -3
  store i64 %12, ptr %10, align 8
  %13 = and i32 %7, 8192
  %.not = icmp eq i32 %13, 0
  br i1 %.not, label %fp_check, label %fp_ok

guest_80002204_b1:                                ; preds = %fp_ok, %entry
  %cycles.0 = phi i64 [ 1, %entry ], [ %cycles.2, %fp_ok ]
  %state3.0 = phi i32 [ %7, %entry ], [ %state3.1, %fp_ok ]
  %state2.0 = phi i32 [ %5, %entry ], [ %25, %fp_ok ]
  %state1.0 = phi i32 [ %3, %entry ], [ %state1.2, %fp_ok ]
  %state.0 = phi double [ %1, %entry ], [ %state.2, %fp_ok ]
  %14 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %15 = load i64, ptr %14, align 8
  %16 = add i64 %15, -1
  store i64 %16, ptr %14, align 8
  %17 = and i32 %state3.0, 8192
  %.not8 = icmp eq i32 %17, 0
  br i1 %.not8, label %fp_check5, label %fp_ok4

guest_80002208_b2:                                ; preds = %fp_ok4, %entry
  %cycles.1.neg = phi i64 [ -1, %entry ], [ %.neg, %fp_ok4 ]
  %state2.1 = phi i32 [ %5, %entry ], [ %state2.3, %fp_ok4 ]
  %state1.1 = phi i32 [ %3, %entry ], [ %state1.3, %fp_ok4 ]
  %state.1 = phi double [ %1, %entry ], [ %36, %fp_ok4 ]
  %18 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %19 = load i64, ptr %18, align 8
  %20 = add i64 %19, -1
  store i64 %20, ptr %18, align 8
  %21 = and i32 %state1.1, -4
  store double %state.1, ptr %0, align 8
  store i32 %state2.1, ptr %4, align 4
  store i32 %21, ptr %8, align 4
  %22 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %23 = load i64, ptr %22, align 8
  %24 = add i64 %cycles.1.neg, %23
  store i64 %24, ptr %22, align 8
  br label %common.ret

common.ret:                                       ; preds = %fp_check5, %fp_check, %entry, %guest_80002208_b2
  ret void

fp_ok:                                            ; preds = %fp_reload, %guest_80002200_b0
  %cycles.2 = phi i64 [ 4, %guest_80002200_b0 ], [ 1, %fp_reload ]
  %state3.1 = phi i32 [ %7, %guest_80002200_b0 ], [ %33, %fp_reload ]
  %state2.2 = phi i32 [ %5, %guest_80002200_b0 ], [ %32, %fp_reload ]
  %state1.2 = phi i32 [ %3, %guest_80002200_b0 ], [ %31, %fp_reload ]
  %state.2 = phi double [ %1, %guest_80002200_b0 ], [ %30, %fp_reload ]
  store i32 %state2.2, ptr %4, align 4
  tail call void @ppc_mtfsb1_op(ptr nonnull %ctx, i8 31)
  %25 = load i32, ptr %4, align 4
  br label %guest_80002204_b1

fp_check:                                         ; preds = %guest_80002200_b0
  store i32 -2147474944, ptr %8, align 4
  %26 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %27 = load i64, ptr %26, align 8
  %28 = add i64 %27, -3
  store i64 %28, ptr %26, align 8
  %29 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147474944)
  br i1 %29, label %fp_reload, label %common.ret

fp_reload:                                        ; preds = %fp_check
  %30 = load double, ptr %0, align 8
  %31 = load i32, ptr %2, align 4
  %32 = load i32, ptr %4, align 4
  %33 = load i32, ptr %6, align 4
  br label %fp_ok

fp_ok4:                                           ; preds = %fp_reload6, %guest_80002204_b1
  %cycles.3 = phi i64 [ %cycles.0, %guest_80002204_b1 ], [ 0, %fp_reload6 ]
  %state2.3 = phi i32 [ %state2.0, %guest_80002204_b1 ], [ %42, %fp_reload6 ]
  %state1.3 = phi i32 [ %state1.0, %guest_80002204_b1 ], [ %41, %fp_reload6 ]
  %34 = zext i32 %state2.3 to i64
  %35 = or disjoint i64 %34, -2251799813685248
  %36 = bitcast i64 %35 to double
  %.neg = xor i64 %cycles.3, -1
  br label %guest_80002208_b2

fp_check5:                                        ; preds = %guest_80002204_b1
  store double %state.0, ptr %0, align 8
  store i32 %state2.0, ptr %4, align 4
  store i32 -2147474940, ptr %8, align 4
  %37 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %38 = load i64, ptr %37, align 8
  %39 = sub i64 %38, %cycles.0
  store i64 %39, ptr %37, align 8
  %40 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147474940)
  br i1 %40, label %fp_reload6, label %common.ret

fp_reload6:                                       ; preds = %fp_check5
  %41 = load i32, ptr %2, align 4
  %42 = load i32, ptr %4, align 4
  br label %fp_ok4
}

declare void @ppc_mtfsb1_op(ptr, i8)

define hidden void @func_80002300(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 16
  %1 = getelementptr inbounds nuw i8, ptr %ctx, i64 32
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 48
  %3 = getelementptr inbounds nuw i8, ptr %ctx, i64 64
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 80
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 96
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 112
  %7 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %9 = load i32, ptr %8, align 4
  switch i32 %9, label %common.ret [
    i32 -2147474688, label %guest_80002300_b0
    i32 -2147474684, label %guest_80002304_b1
  ]

guest_80002300_b0:                                ; preds = %entry
  %10 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %11 = load i64, ptr %10, align 8
  %12 = add i64 %11, -1
  store i64 %12, ptr %10, align 8
  store i32 -2147474688, ptr %8, align 4
  %13 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %14 = load i64, ptr %13, align 8
  %15 = add i64 %14, -1
  store i64 %15, ptr %13, align 8
  tail call void @ppc_lswx(ptr nonnull %ctx, i8 9, i8 20, i8 21, i32 -2147474688)
  %16 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %17 = load i32, ptr %16, align 4
  %18 = icmp eq i32 %17, 0
  br i1 %18, label %guest_80002304_b1, label %common.ret

guest_80002304_b1:                                ; preds = %guest_80002300_b0, %entry
  %state32.0 = load i32, ptr %7, align 4
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %20 = load i64, ptr %19, align 8
  %21 = add i64 %20, -1
  store i64 %21, ptr %19, align 8
  %22 = and i32 %state32.0, -4
  %23 = load <4 x i32>, ptr %ctx, align 4
  store <4 x i32> %23, ptr %ctx, align 4
  %24 = load <4 x i32>, ptr %0, align 4
  store <4 x i32> %24, ptr %0, align 4
  %25 = load <4 x i32>, ptr %1, align 4
  store <4 x i32> %25, ptr %1, align 4
  %26 = load <4 x i32>, ptr %2, align 4
  store <4 x i32> %26, ptr %2, align 4
  %27 = load <4 x i32>, ptr %3, align 4
  store <4 x i32> %27, ptr %3, align 4
  %28 = load <4 x i32>, ptr %4, align 4
  store <4 x i32> %28, ptr %4, align 4
  %29 = load <4 x i32>, ptr %5, align 4
  store <4 x i32> %29, ptr %5, align 4
  %30 = load <4 x i32>, ptr %6, align 4
  store <4 x i32> %30, ptr %6, align 4
  store i32 %22, ptr %8, align 4
  %31 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %32 = load i64, ptr %31, align 8
  %33 = add i64 %32, -1
  store i64 %33, ptr %31, align 8
  br label %common.ret

common.ret:                                       ; preds = %guest_80002300_b0, %entry, %guest_80002304_b1
  ret void
}

declare void @ppc_lswx(ptr, i8, i8, i8, i32)

define hidden void @func_80002400(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %1 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %2 = load i32, ptr %1, align 4
  switch i32 %2, label %common.ret [
    i32 -2147474432, label %guest_80002400_b0
    i32 -2147474428, label %guest_80002404_b1
  ]

guest_80002400_b0:                                ; preds = %entry
  %3 = getelementptr inbounds nuw i8, ptr %ctx, i64 72
  %4 = load i32, ptr %3, align 4
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 68
  %6 = load i32, ptr %5, align 4
  %7 = add i32 %6, %4
  store i32 -2147474432, ptr %1, align 4
  tail call void @ppc_cache_control(ptr nonnull %ctx, i8 0, i32 %7, i32 -2147474432)
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %9 = load i32, ptr %8, align 4
  %10 = icmp eq i32 %9, 0
  br i1 %10, label %guest_80002404_b1, label %common.ret

guest_80002404_b1:                                ; preds = %guest_80002400_b0, %entry
  %state2.0 = load i32, ptr %0, align 4
  %11 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %12 = load i64, ptr %11, align 8
  %13 = add i64 %12, -1
  store i64 %13, ptr %11, align 8
  %14 = and i32 %state2.0, -4
  store i32 %14, ptr %1, align 4
  %15 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %16 = load i64, ptr %15, align 8
  %17 = add i64 %16, -1
  store i64 %17, ptr %15, align 8
  br label %common.ret

common.ret:                                       ; preds = %guest_80002400_b0, %entry, %guest_80002404_b1
  ret void
}

declare void @ppc_cache_control(ptr, i8, i32, i32)

define hidden void @func_80002500(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %5 = load i32, ptr %4, align 4
  switch i32 %5, label %common.ret [
    i32 -2147474176, label %guest_80002500_b0
    i32 -2147474172, label %entry.guest_80002504_b1_crit_edge
    i32 -2147474168, label %entry.guest_80002508_b2_crit_edge
  ]

entry.guest_80002508_b2_crit_edge:                ; preds = %entry
  %.phi.trans.insert3 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre4 = load i64, ptr %.phi.trans.insert3, align 8
  br label %guest_80002508_b2

entry.guest_80002504_b1_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  br label %guest_80002504_b1

guest_80002500_b0:                                ; preds = %entry
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 20
  %7 = load i32, ptr %6, align 4
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %9 = load i64, ptr %8, align 8
  %10 = add i64 %9, -1
  store i64 %10, ptr %8, align 8
  %11 = icmp eq i32 %7, -2
  br i1 %11, label %trap_taken, label %guest_80002504_b1

guest_80002504_b1:                                ; preds = %entry.guest_80002504_b1_crit_edge, %guest_80002500_b0
  %12 = phi i64 [ %.pre, %entry.guest_80002504_b1_crit_edge ], [ %10, %guest_80002500_b0 ]
  %cycles.0.neg = phi i64 [ -2, %entry.guest_80002504_b1_crit_edge ], [ -3, %guest_80002500_b0 ]
  %13 = add i64 %12, -1
  %14 = add i32 %1, 1
  br label %guest_80002508_b2

guest_80002508_b2:                                ; preds = %entry.guest_80002508_b2_crit_edge, %guest_80002504_b1
  %15 = phi i64 [ %.pre4, %entry.guest_80002508_b2_crit_edge ], [ %13, %guest_80002504_b1 ]
  %cycles.1.neg = phi i64 [ -1, %entry.guest_80002508_b2_crit_edge ], [ %cycles.0.neg, %guest_80002504_b1 ]
  %state.0 = phi i32 [ %1, %entry.guest_80002508_b2_crit_edge ], [ %14, %guest_80002504_b1 ]
  %16 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %17 = add i64 %15, -1
  store i64 %17, ptr %16, align 8
  %18 = and i32 %3, -4
  store i32 %state.0, ptr %0, align 4
  store i32 %18, ptr %4, align 4
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %20 = load i64, ptr %19, align 8
  %21 = add i64 %cycles.1.neg, %20
  store i64 %21, ptr %19, align 8
  br label %common.ret

common.ret:                                       ; preds = %entry, %guest_80002508_b2, %trap_taken
  ret void

trap_taken:                                       ; preds = %guest_80002500_b0
  store i32 -2147474176, ptr %4, align 4
  %22 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %23 = load i64, ptr %22, align 8
  %24 = add i64 %23, -1
  store i64 %24, ptr %22, align 8
  tail call void @ppc_program_exception(ptr nonnull %ctx, i32 131072, i32 -2147474176)
  br label %common.ret
}

define hidden void @func_80002600(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %1 = load i32, ptr %0, align 4
  %cond = icmp eq i32 %1, -2147473920
  br i1 %cond, label %guest_80002600_b0, label %common.ret

common.ret:                                       ; preds = %entry, %guest_80002600_b0
  ret void

guest_80002600_b0:                                ; preds = %entry
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %3 = load i64, ptr %2, align 8
  %4 = add i64 %3, -2
  store i64 %4, ptr %2, align 8
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %6 = load i64, ptr %5, align 8
  %7 = add i64 %6, -2
  store i64 %7, ptr %5, align 8
  tail call void @ppc_system_call_exception(ptr nonnull %ctx, i32 -2147473920)
  br label %common.ret
}

declare void @ppc_system_call_exception(ptr, i32)

define hidden void @func_80002700(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %1 = load i32, ptr %0, align 4
  %cond = icmp eq i32 %1, -2147473664
  br i1 %cond, label %guest_80002700_b0, label %common.ret

common.ret:                                       ; preds = %entry, %guest_80002700_b0
  ret void

guest_80002700_b0:                                ; preds = %entry
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %3 = load i64, ptr %2, align 8
  %4 = add i64 %3, -2
  store i64 %4, ptr %2, align 8
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %6 = load i64, ptr %5, align 8
  %7 = add i64 %6, -2
  store i64 %7, ptr %5, align 8
  tail call void @ppc_rfi(ptr nonnull %ctx, i32 -2147473664)
  br label %common.ret
}

declare void @ppc_rfi(ptr, i32)

define hidden void @func_80002800(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %1 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %2 = load i32, ptr %1, align 4
  switch i32 %2, label %common.ret [
    i32 -2147473408, label %guest_80002800_b0
    i32 -2147473404, label %guest_80002804_b1
  ]

guest_80002800_b0:                                ; preds = %entry
  %3 = getelementptr inbounds nuw i8, ptr %ctx, i64 24
  %4 = load i32, ptr %3, align 4
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 20
  %6 = load i32, ptr %5, align 4
  %7 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %8 = load i64, ptr %7, align 8
  %9 = add i64 %8, -1
  store i64 %9, ptr %7, align 8
  %10 = add i32 %6, %4
  store i32 -2147473408, ptr %1, align 4
  %11 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %12 = load i64, ptr %11, align 8
  %13 = add i64 %12, -1
  store i64 %13, ptr %11, align 8
  tail call void @ppc_dcbz_l(ptr nonnull %ctx, i32 %10, i32 -2147473408)
  %14 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %15 = load i32, ptr %14, align 4
  %16 = icmp eq i32 %15, 0
  br i1 %16, label %guest_80002804_b1, label %common.ret

guest_80002804_b1:                                ; preds = %guest_80002800_b0, %entry
  %state2.0 = load i32, ptr %0, align 4
  %17 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %18 = load i64, ptr %17, align 8
  %19 = add i64 %18, -1
  store i64 %19, ptr %17, align 8
  %20 = and i32 %state2.0, -4
  store i32 %20, ptr %1, align 4
  %21 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %22 = load i64, ptr %21, align 8
  %23 = add i64 %22, -1
  store i64 %23, ptr %21, align 8
  br label %common.ret

common.ret:                                       ; preds = %guest_80002800_b0, %entry, %guest_80002804_b1
  ret void
}

declare void @ppc_dcbz_l(ptr, i32, i32)

define hidden void @func_80002900(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %1 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %2 = load i32, ptr %1, align 4
  switch i32 %2, label %common.ret [
    i32 -2147473152, label %guest_80002900_b0
    i32 -2147473148, label %guest_80002904_b1
  ]

guest_80002900_b0:                                ; preds = %entry
  %3 = getelementptr inbounds nuw i8, ptr %ctx, i64 52
  %4 = load i32, ptr %3, align 4
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 48
  %6 = load i32, ptr %5, align 4
  %7 = getelementptr inbounds nuw i8, ptr %ctx, i64 44
  %8 = load i32, ptr %7, align 4
  %9 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %10 = load i64, ptr %9, align 8
  %11 = add i64 %10, -1
  store i64 %11, ptr %9, align 8
  %12 = add i32 %6, %4
  store i32 -2147473152, ptr %1, align 4
  %13 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %14 = load i64, ptr %13, align 8
  %15 = add i64 %14, -1
  store i64 %15, ptr %13, align 8
  tail call void @ppc_ecowx(ptr nonnull %ctx, i32 %12, i32 %8, i32 -2147473152)
  %16 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %17 = load i32, ptr %16, align 4
  %18 = icmp eq i32 %17, 0
  br i1 %18, label %guest_80002904_b1, label %common.ret

guest_80002904_b1:                                ; preds = %guest_80002900_b0, %entry
  %state3.0 = load i32, ptr %0, align 4
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %20 = load i64, ptr %19, align 8
  %21 = add i64 %20, -1
  store i64 %21, ptr %19, align 8
  %22 = and i32 %state3.0, -4
  store i32 %22, ptr %1, align 4
  %23 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %24 = load i64, ptr %23, align 8
  %25 = add i64 %24, -1
  store i64 %25, ptr %23, align 8
  br label %common.ret

common.ret:                                       ; preds = %guest_80002900_b0, %entry, %guest_80002904_b1
  ret void
}

declare void @ppc_ecowx(ptr, i32, i32, i32)

define hidden void @func_80002A00(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 136
  %1 = load double, ptr %0, align 8
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 144
  %3 = getelementptr inbounds nuw i8, ptr %ctx, i64 152
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 160
  %5 = load <2 x double>, ptr %4, align 8
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 176
  %7 = load double, ptr %6, align 8
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 184
  %9 = load <2 x double>, ptr %8, align 8
  %10 = getelementptr inbounds nuw i8, ptr %ctx, i64 200
  %11 = load double, ptr %10, align 8
  %12 = getelementptr inbounds nuw i8, ptr %ctx, i64 208
  %13 = load <2 x double>, ptr %12, align 8
  %14 = getelementptr inbounds nuw i8, ptr %ctx, i64 224
  %15 = load double, ptr %14, align 8
  %16 = getelementptr inbounds nuw i8, ptr %ctx, i64 232
  %17 = load <2 x double>, ptr %16, align 8
  %18 = getelementptr inbounds nuw i8, ptr %ctx, i64 248
  %19 = load double, ptr %18, align 8
  %20 = getelementptr inbounds nuw i8, ptr %ctx, i64 256
  %21 = load <2 x double>, ptr %20, align 8
  %22 = getelementptr inbounds nuw i8, ptr %ctx, i64 272
  %23 = load double, ptr %22, align 8
  %24 = getelementptr inbounds nuw i8, ptr %ctx, i64 280
  %25 = load <2 x double>, ptr %24, align 8
  %26 = getelementptr inbounds nuw i8, ptr %ctx, i64 296
  %27 = load double, ptr %26, align 8
  %28 = getelementptr inbounds nuw i8, ptr %ctx, i64 304
  %29 = load <2 x double>, ptr %28, align 8
  %30 = getelementptr inbounds nuw i8, ptr %ctx, i64 320
  %31 = load double, ptr %30, align 8
  %32 = getelementptr inbounds nuw i8, ptr %ctx, i64 392
  %33 = load double, ptr %32, align 8
  %34 = getelementptr inbounds nuw i8, ptr %ctx, i64 416
  %35 = load double, ptr %34, align 8
  %36 = getelementptr inbounds nuw i8, ptr %ctx, i64 440
  %37 = load double, ptr %36, align 8
  %38 = getelementptr inbounds nuw i8, ptr %ctx, i64 464
  %39 = load double, ptr %38, align 8
  %40 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %41 = load i32, ptr %40, align 4
  %42 = getelementptr inbounds nuw i8, ptr %ctx, i64 660
  %43 = load i32, ptr %42, align 4
  %44 = getelementptr inbounds nuw i8, ptr %ctx, i64 664
  %45 = load i32, ptr %44, align 4
  %46 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %47 = load i32, ptr %46, align 4
  %48 = sub i32 %47, -2147472896
  %49 = tail call i32 @llvm.fshl.i32(i32 %48, i32 %48, i32 30)
  %50 = extractelement <2 x double> %29, i32 0
  %51 = extractelement <2 x double> %25, i32 0
  %52 = extractelement <2 x double> %21, i32 0
  %53 = extractelement <2 x double> %17, i32 0
  %54 = extractelement <2 x double> %13, i32 0
  %55 = extractelement <2 x double> %9, i32 0
  %56 = extractelement <2 x double> %5, i32 0
  switch i32 %49, label %common.ret [
    i32 0, label %guest_80002A00_b0
    i32 1, label %guest_80002A04_b1
    i32 2, label %guest_80002A08_b2
    i32 3, label %guest_80002A0C_b3
    i32 4, label %guest_80002A10_b4
    i32 5, label %guest_80002A14_b5
    i32 6, label %guest_80002A18_b6
    i32 7, label %guest_80002A1C_b7
    i32 8, label %guest_80002A20_b8
  ]

guest_80002A00_b0:                                ; preds = %entry
  %57 = load double, ptr %3, align 8
  %58 = load double, ptr %2, align 8
  %59 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %60 = load i64, ptr %59, align 8
  %61 = add i64 %60, -1
  store i64 %61, ptr %59, align 8
  %62 = and i32 %45, 8192
  %.not = icmp eq i32 %62, 0
  %63 = insertelement <2 x double> poison, double %1, i32 0
  %64 = insertelement <2 x double> %63, double %58, i32 1
  br i1 %.not, label %fp_check, label %fp_ok

guest_80002A04_b1:                                ; preds = %fp_ok, %entry
  %cycles.0 = phi i64 [ 1, %entry ], [ %cycles.8, %fp_ok ]
  %state30.0 = phi i32 [ %45, %entry ], [ %state30.7, %fp_ok ]
  %state29.0 = phi i32 [ %43, %entry ], [ %138, %fp_ok ]
  %state28.0 = phi i32 [ %41, %entry ], [ %state28.8, %fp_ok ]
  %state27.0 = phi double [ %39, %entry ], [ %state27.8, %fp_ok ]
  %state26.0 = phi double [ %37, %entry ], [ %state26.8, %fp_ok ]
  %state25.0 = phi double [ %35, %entry ], [ %state25.8, %fp_ok ]
  %state24.0 = phi double [ %33, %entry ], [ %137, %fp_ok ]
  %state23.0 = phi double [ %31, %entry ], [ %state23.7, %fp_ok ]
  %state20.0 = phi double [ %27, %entry ], [ %state20.6, %fp_ok ]
  %state17.0 = phi double [ %23, %entry ], [ %state17.5, %fp_ok ]
  %state14.0 = phi double [ %19, %entry ], [ %state14.4, %fp_ok ]
  %state11.0 = phi double [ %15, %entry ], [ %state11.3, %fp_ok ]
  %state8.0 = phi double [ %11, %entry ], [ %state8.2, %fp_ok ]
  %state5.0 = phi double [ %7, %entry ], [ %state5.1, %fp_ok ]
  %state.0 = phi double [ %1, %entry ], [ %136, %fp_ok ]
  %65 = phi <2 x double> [ %21, %entry ], [ %128, %fp_ok ]
  %66 = phi <2 x double> [ %17, %entry ], [ %129, %fp_ok ]
  %67 = phi <2 x double> [ %13, %entry ], [ %130, %fp_ok ]
  %68 = phi <2 x double> [ %9, %entry ], [ %131, %fp_ok ]
  %69 = phi <2 x double> [ %29, %entry ], [ %132, %fp_ok ]
  %70 = phi <2 x double> [ %5, %entry ], [ %133, %fp_ok ]
  %71 = phi <2 x double> [ %25, %entry ], [ %134, %fp_ok ]
  %72 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %73 = load i64, ptr %72, align 8
  %74 = add i64 %73, -1
  store i64 %74, ptr %72, align 8
  %75 = and i32 %state30.0, 8192
  %.not59 = icmp eq i32 %75, 0
  br i1 %.not59, label %fp_check32, label %fp_ok31

guest_80002A08_b2:                                ; preds = %fp_ok31, %entry
  %cycles.1 = phi i64 [ 1, %entry ], [ %176, %fp_ok31 ]
  %state30.1 = phi i32 [ %45, %entry ], [ %state30.8, %fp_ok31 ]
  %state29.1 = phi i32 [ %43, %entry ], [ %175, %fp_ok31 ]
  %state28.1 = phi i32 [ %41, %entry ], [ %state28.9, %fp_ok31 ]
  %state27.1 = phi double [ %39, %entry ], [ %state27.9, %fp_ok31 ]
  %state26.1 = phi double [ %37, %entry ], [ %state26.9, %fp_ok31 ]
  %state25.1 = phi double [ %35, %entry ], [ %174, %fp_ok31 ]
  %state24.1 = phi double [ %33, %entry ], [ %state24.9, %fp_ok31 ]
  %state23.1 = phi double [ %31, %entry ], [ %state23.8, %fp_ok31 ]
  %state20.1 = phi double [ %27, %entry ], [ %state20.7, %fp_ok31 ]
  %state17.1 = phi double [ %23, %entry ], [ %state17.6, %fp_ok31 ]
  %state14.1 = phi double [ %19, %entry ], [ %state14.5, %fp_ok31 ]
  %state11.1 = phi double [ %15, %entry ], [ %state11.4, %fp_ok31 ]
  %state8.1 = phi double [ %11, %entry ], [ %state8.3, %fp_ok31 ]
  %state3.1 = phi double [ %56, %entry ], [ %173, %fp_ok31 ]
  %state.1 = phi double [ %1, %entry ], [ %state.9, %fp_ok31 ]
  %76 = phi <2 x double> [ %25, %entry ], [ %166, %fp_ok31 ]
  %77 = phi <2 x double> [ %21, %entry ], [ %167, %fp_ok31 ]
  %78 = phi <2 x double> [ %17, %entry ], [ %168, %fp_ok31 ]
  %79 = phi <2 x double> [ %13, %entry ], [ %169, %fp_ok31 ]
  %80 = phi <2 x double> [ %9, %entry ], [ %170, %fp_ok31 ]
  %81 = phi <2 x double> [ %29, %entry ], [ %171, %fp_ok31 ]
  %82 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %83 = load i64, ptr %82, align 8
  %84 = add i64 %83, -1
  store i64 %84, ptr %82, align 8
  %85 = and i32 %state30.1, 8192
  %.not60 = icmp eq i32 %85, 0
  br i1 %.not60, label %fp_check36, label %fp_ok35

guest_80002A0C_b3:                                ; preds = %fp_ok35, %entry
  %cycles.2 = phi i64 [ 17, %entry ], [ %219, %fp_ok35 ]
  %state30.2 = phi i32 [ %45, %entry ], [ %state30.9, %fp_ok35 ]
  %state29.2 = phi i32 [ %43, %entry ], [ %218, %fp_ok35 ]
  %state28.2 = phi i32 [ %41, %entry ], [ %state28.10, %fp_ok35 ]
  %state27.2 = phi double [ %39, %entry ], [ %state27.10, %fp_ok35 ]
  %state26.2 = phi double [ %37, %entry ], [ %217, %fp_ok35 ]
  %state25.2 = phi double [ %35, %entry ], [ %state25.10, %fp_ok35 ]
  %state24.2 = phi double [ %33, %entry ], [ %state24.10, %fp_ok35 ]
  %state23.2 = phi double [ %31, %entry ], [ %state23.9, %fp_ok35 ]
  %state20.2 = phi double [ %27, %entry ], [ %state20.8, %fp_ok35 ]
  %state17.2 = phi double [ %23, %entry ], [ %state17.7, %fp_ok35 ]
  %state14.2 = phi double [ %19, %entry ], [ %state14.6, %fp_ok35 ]
  %state11.2 = phi double [ %15, %entry ], [ %state11.5, %fp_ok35 ]
  %state6.2 = phi double [ %55, %entry ], [ %216, %fp_ok35 ]
  %state3.2 = phi double [ %56, %entry ], [ %state3.10, %fp_ok35 ]
  %state.2 = phi double [ %1, %entry ], [ %state.10, %fp_ok35 ]
  %86 = phi <2 x double> [ %29, %entry ], [ %210, %fp_ok35 ]
  %87 = phi <2 x double> [ %25, %entry ], [ %211, %fp_ok35 ]
  %88 = phi <2 x double> [ %21, %entry ], [ %212, %fp_ok35 ]
  %89 = phi <2 x double> [ %17, %entry ], [ %213, %fp_ok35 ]
  %90 = phi <2 x double> [ %13, %entry ], [ %214, %fp_ok35 ]
  %91 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %92 = load i64, ptr %91, align 8
  %93 = add i64 %92, -17
  store i64 %93, ptr %91, align 8
  %94 = and i32 %state30.2, 8192
  %.not61 = icmp eq i32 %94, 0
  br i1 %.not61, label %fp_check40, label %fp_ok39

guest_80002A10_b4:                                ; preds = %fp_ok39, %entry
  %cycles.3 = phi i64 [ 1, %entry ], [ %259, %fp_ok39 ]
  %state30.3 = phi i32 [ %45, %entry ], [ %state30.10, %fp_ok39 ]
  %state29.3 = phi i32 [ %43, %entry ], [ %258, %fp_ok39 ]
  %state28.3 = phi i32 [ %41, %entry ], [ %state28.11, %fp_ok39 ]
  %state27.3 = phi double [ %39, %entry ], [ %257, %fp_ok39 ]
  %state26.3 = phi double [ %37, %entry ], [ %state26.11, %fp_ok39 ]
  %state25.3 = phi double [ %35, %entry ], [ %state25.11, %fp_ok39 ]
  %state24.3 = phi double [ %33, %entry ], [ %state24.11, %fp_ok39 ]
  %state23.3 = phi double [ %31, %entry ], [ %state23.10, %fp_ok39 ]
  %state20.3 = phi double [ %27, %entry ], [ %state20.9, %fp_ok39 ]
  %state17.3 = phi double [ %23, %entry ], [ %state17.8, %fp_ok39 ]
  %state14.3 = phi double [ %19, %entry ], [ %state14.7, %fp_ok39 ]
  %state9.3 = phi double [ %54, %entry ], [ %256, %fp_ok39 ]
  %state6.3 = phi double [ %55, %entry ], [ %state6.11, %fp_ok39 ]
  %state3.3 = phi double [ %56, %entry ], [ %state3.11, %fp_ok39 ]
  %state.3 = phi double [ %1, %entry ], [ %state.11, %fp_ok39 ]
  %95 = phi <2 x double> [ %29, %entry ], [ %251, %fp_ok39 ]
  %96 = phi <2 x double> [ %25, %entry ], [ %252, %fp_ok39 ]
  %97 = phi <2 x double> [ %21, %entry ], [ %253, %fp_ok39 ]
  %98 = phi <2 x double> [ %17, %entry ], [ %254, %fp_ok39 ]
  %99 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %100 = load i64, ptr %99, align 8
  %101 = add i64 %100, -1
  store i64 %101, ptr %99, align 8
  %102 = and i32 %state30.3, 8192
  %.not62 = icmp eq i32 %102, 0
  br i1 %.not62, label %fp_check44, label %fp_ok43

guest_80002A14_b5:                                ; preds = %fp_ok43, %entry
  %cycles.4 = phi i64 [ 1, %entry ], [ %295, %fp_ok43 ]
  %state30.4 = phi i32 [ %45, %entry ], [ %state30.11, %fp_ok43 ]
  %state29.4 = phi i32 [ %43, %entry ], [ %294, %fp_ok43 ]
  %state28.4 = phi i32 [ %41, %entry ], [ %state28.12, %fp_ok43 ]
  %state27.4 = phi double [ %39, %entry ], [ %state27.12, %fp_ok43 ]
  %state26.4 = phi double [ %37, %entry ], [ %state26.12, %fp_ok43 ]
  %state25.4 = phi double [ %35, %entry ], [ %state25.12, %fp_ok43 ]
  %state24.4 = phi double [ %33, %entry ], [ %state24.12, %fp_ok43 ]
  %state23.4 = phi double [ %31, %entry ], [ %state23.11, %fp_ok43 ]
  %state20.4 = phi double [ %27, %entry ], [ %state20.10, %fp_ok43 ]
  %state17.4 = phi double [ %23, %entry ], [ %state17.9, %fp_ok43 ]
  %state12.4 = phi double [ %53, %entry ], [ %293, %fp_ok43 ]
  %state9.4 = phi double [ %54, %entry ], [ %state9.12, %fp_ok43 ]
  %state6.4 = phi double [ %55, %entry ], [ %state6.12, %fp_ok43 ]
  %state3.4 = phi double [ %56, %entry ], [ %state3.12, %fp_ok43 ]
  %state.4 = phi double [ %1, %entry ], [ %state.12, %fp_ok43 ]
  %103 = phi <2 x double> [ %29, %entry ], [ %289, %fp_ok43 ]
  %104 = phi <2 x double> [ %25, %entry ], [ %290, %fp_ok43 ]
  %105 = phi <2 x double> [ %21, %entry ], [ %291, %fp_ok43 ]
  %106 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %107 = load i64, ptr %106, align 8
  %108 = add i64 %107, -1
  store i64 %108, ptr %106, align 8
  %109 = and i32 %state30.4, 8192
  %.not63 = icmp eq i32 %109, 0
  br i1 %.not63, label %fp_check48, label %fp_ok47

guest_80002A18_b6:                                ; preds = %fp_ok47, %entry
  %cycles.5 = phi i64 [ 1, %entry ], [ %328, %fp_ok47 ]
  %state30.5 = phi i32 [ %45, %entry ], [ %state30.12, %fp_ok47 ]
  %state29.5 = phi i32 [ %43, %entry ], [ %327, %fp_ok47 ]
  %state28.5 = phi i32 [ %41, %entry ], [ %state28.13, %fp_ok47 ]
  %state27.5 = phi double [ %39, %entry ], [ %state27.13, %fp_ok47 ]
  %state26.5 = phi double [ %37, %entry ], [ %state26.13, %fp_ok47 ]
  %state25.5 = phi double [ %35, %entry ], [ %state25.13, %fp_ok47 ]
  %state24.5 = phi double [ %33, %entry ], [ %state24.13, %fp_ok47 ]
  %state23.5 = phi double [ %31, %entry ], [ %state23.12, %fp_ok47 ]
  %state20.5 = phi double [ %27, %entry ], [ %state20.11, %fp_ok47 ]
  %state15.5 = phi double [ %52, %entry ], [ %326, %fp_ok47 ]
  %state12.5 = phi double [ %53, %entry ], [ %state12.13, %fp_ok47 ]
  %state9.5 = phi double [ %54, %entry ], [ %state9.13, %fp_ok47 ]
  %state6.5 = phi double [ %55, %entry ], [ %state6.13, %fp_ok47 ]
  %state3.5 = phi double [ %56, %entry ], [ %state3.13, %fp_ok47 ]
  %state.5 = phi double [ %1, %entry ], [ %state.13, %fp_ok47 ]
  %110 = phi <2 x double> [ %29, %entry ], [ %323, %fp_ok47 ]
  %111 = phi <2 x double> [ %25, %entry ], [ %324, %fp_ok47 ]
  %112 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %113 = load i64, ptr %112, align 8
  %114 = add i64 %113, -1
  store i64 %114, ptr %112, align 8
  %115 = and i32 %state30.5, 8192
  %.not64 = icmp eq i32 %115, 0
  br i1 %.not64, label %fp_check52, label %fp_ok51

guest_80002A1C_b7:                                ; preds = %fp_ok51, %entry
  %cycles.6 = phi i64 [ 31, %entry ], [ %358, %fp_ok51 ]
  %state30.6 = phi i32 [ %45, %entry ], [ %state30.13, %fp_ok51 ]
  %state29.6 = phi i32 [ %43, %entry ], [ %357, %fp_ok51 ]
  %state28.6 = phi i32 [ %41, %entry ], [ %state28.14, %fp_ok51 ]
  %state27.6 = phi double [ %39, %entry ], [ %state27.14, %fp_ok51 ]
  %state26.6 = phi double [ %37, %entry ], [ %state26.14, %fp_ok51 ]
  %state25.6 = phi double [ %35, %entry ], [ %state25.14, %fp_ok51 ]
  %state24.6 = phi double [ %33, %entry ], [ %state24.14, %fp_ok51 ]
  %state23.6 = phi double [ %31, %entry ], [ %state23.13, %fp_ok51 ]
  %state18.6 = phi double [ %51, %entry ], [ %356, %fp_ok51 ]
  %state15.6 = phi double [ %52, %entry ], [ %state15.14, %fp_ok51 ]
  %state12.6 = phi double [ %53, %entry ], [ %state12.14, %fp_ok51 ]
  %state9.6 = phi double [ %54, %entry ], [ %state9.14, %fp_ok51 ]
  %state6.6 = phi double [ %55, %entry ], [ %state6.14, %fp_ok51 ]
  %state3.6 = phi double [ %56, %entry ], [ %state3.14, %fp_ok51 ]
  %state.6 = phi double [ %1, %entry ], [ %state.14, %fp_ok51 ]
  %116 = phi <2 x double> [ %29, %entry ], [ %354, %fp_ok51 ]
  %117 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %118 = load i64, ptr %117, align 8
  %119 = add i64 %118, -31
  store i64 %119, ptr %117, align 8
  %120 = and i32 %state30.6, 8192
  %.not65 = icmp eq i32 %120, 0
  br i1 %.not65, label %fp_check56, label %fp_ok55

guest_80002A20_b8:                                ; preds = %fp_ok55, %entry
  %cycles.7.neg = phi i64 [ -1, %entry ], [ %.neg, %fp_ok55 ]
  %state29.7 = phi i32 [ %43, %entry ], [ %384, %fp_ok55 ]
  %state28.7 = phi i32 [ %41, %entry ], [ %state28.15, %fp_ok55 ]
  %state27.7 = phi double [ %39, %entry ], [ %state27.15, %fp_ok55 ]
  %state26.7 = phi double [ %37, %entry ], [ %state26.15, %fp_ok55 ]
  %state25.7 = phi double [ %35, %entry ], [ %state25.15, %fp_ok55 ]
  %state24.7 = phi double [ %33, %entry ], [ %state24.15, %fp_ok55 ]
  %state21.7 = phi double [ %50, %entry ], [ %383, %fp_ok55 ]
  %state18.7 = phi double [ %51, %entry ], [ %state18.15, %fp_ok55 ]
  %state15.7 = phi double [ %52, %entry ], [ %state15.15, %fp_ok55 ]
  %state12.7 = phi double [ %53, %entry ], [ %state12.15, %fp_ok55 ]
  %state9.7 = phi double [ %54, %entry ], [ %state9.15, %fp_ok55 ]
  %state6.7 = phi double [ %55, %entry ], [ %state6.15, %fp_ok55 ]
  %state3.7 = phi double [ %56, %entry ], [ %state3.15, %fp_ok55 ]
  %state.7 = phi double [ %1, %entry ], [ %state.15, %fp_ok55 ]
  %121 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %122 = load i64, ptr %121, align 8
  %123 = add i64 %122, -1
  store i64 %123, ptr %121, align 8
  %124 = and i32 %state28.7, -4
  store double %state.7, ptr %0, align 8
  store double %state3.7, ptr %4, align 8
  store double %state6.7, ptr %8, align 8
  store double %state9.7, ptr %12, align 8
  store double %state12.7, ptr %16, align 8
  store double %state15.7, ptr %20, align 8
  store double %state18.7, ptr %24, align 8
  store double %state21.7, ptr %28, align 8
  store double %state24.7, ptr %32, align 8
  store double %state25.7, ptr %34, align 8
  store double %state26.7, ptr %36, align 8
  store double %state27.7, ptr %38, align 8
  store i32 %state29.7, ptr %42, align 4
  store i32 %124, ptr %46, align 4
  %125 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %126 = load i64, ptr %125, align 8
  %127 = add i64 %cycles.7.neg, %126
  store i64 %127, ptr %125, align 8
  br label %common.ret

common.ret:                                       ; preds = %fp_check56, %fp_check52, %fp_check48, %fp_check44, %fp_check40, %fp_check36, %fp_check32, %fp_check, %entry, %guest_80002A20_b8
  ret void

fp_ok:                                            ; preds = %fp_reload, %guest_80002A00_b0
  %cycles.8 = phi i64 [ 2, %guest_80002A00_b0 ], [ 1, %fp_reload ]
  %state30.7 = phi i32 [ %45, %guest_80002A00_b0 ], [ %165, %fp_reload ]
  %state29.8 = phi i32 [ %43, %guest_80002A00_b0 ], [ %164, %fp_reload ]
  %state28.8 = phi i32 [ %41, %guest_80002A00_b0 ], [ %163, %fp_reload ]
  %state27.8 = phi double [ %39, %guest_80002A00_b0 ], [ %162, %fp_reload ]
  %state26.8 = phi double [ %37, %guest_80002A00_b0 ], [ %161, %fp_reload ]
  %state25.8 = phi double [ %35, %guest_80002A00_b0 ], [ %160, %fp_reload ]
  %state24.8 = phi double [ %33, %guest_80002A00_b0 ], [ %159, %fp_reload ]
  %state23.7 = phi double [ %31, %guest_80002A00_b0 ], [ %158, %fp_reload ]
  %state20.6 = phi double [ %27, %guest_80002A00_b0 ], [ %156, %fp_reload ]
  %state17.5 = phi double [ %23, %guest_80002A00_b0 ], [ %154, %fp_reload ]
  %state14.4 = phi double [ %19, %guest_80002A00_b0 ], [ %152, %fp_reload ]
  %state11.3 = phi double [ %15, %guest_80002A00_b0 ], [ %150, %fp_reload ]
  %state8.2 = phi double [ %11, %guest_80002A00_b0 ], [ %148, %fp_reload ]
  %state5.1 = phi double [ %7, %guest_80002A00_b0 ], [ %146, %fp_reload ]
  %state2.0 = phi double [ %57, %guest_80002A00_b0 ], [ %144, %fp_reload ]
  %128 = phi <2 x double> [ %21, %guest_80002A00_b0 ], [ %153, %fp_reload ]
  %129 = phi <2 x double> [ %17, %guest_80002A00_b0 ], [ %151, %fp_reload ]
  %130 = phi <2 x double> [ %13, %guest_80002A00_b0 ], [ %149, %fp_reload ]
  %131 = phi <2 x double> [ %9, %guest_80002A00_b0 ], [ %147, %fp_reload ]
  %132 = phi <2 x double> [ %29, %guest_80002A00_b0 ], [ %157, %fp_reload ]
  %133 = phi <2 x double> [ %5, %guest_80002A00_b0 ], [ %145, %fp_reload ]
  %134 = phi <2 x double> [ %25, %guest_80002A00_b0 ], [ %155, %fp_reload ]
  %135 = phi <2 x double> [ %64, %guest_80002A00_b0 ], [ %143, %fp_reload ]
  store i32 %state29.8, ptr %42, align 4
  store double %state24.8, ptr %32, align 8
  store <2 x double> %135, ptr %0, align 8
  store double %state2.0, ptr %3, align 8
  tail call void @ppc_fadds(ptr nonnull %ctx, i8 1, i8 2, i8 3)
  %136 = load double, ptr %0, align 8
  %137 = load double, ptr %32, align 8
  %138 = load i32, ptr %42, align 4
  br label %guest_80002A04_b1

fp_check:                                         ; preds = %guest_80002A00_b0
  store i32 -2147472896, ptr %46, align 4
  %139 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %140 = load i64, ptr %139, align 8
  %141 = add i64 %140, -1
  store i64 %141, ptr %139, align 8
  %142 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472896)
  br i1 %142, label %fp_reload, label %common.ret

fp_reload:                                        ; preds = %fp_check
  %143 = load <2 x double>, ptr %0, align 8
  %144 = load double, ptr %3, align 8
  %145 = load <2 x double>, ptr %4, align 8
  %146 = load double, ptr %6, align 8
  %147 = load <2 x double>, ptr %8, align 8
  %148 = load double, ptr %10, align 8
  %149 = load <2 x double>, ptr %12, align 8
  %150 = load double, ptr %14, align 8
  %151 = load <2 x double>, ptr %16, align 8
  %152 = load double, ptr %18, align 8
  %153 = load <2 x double>, ptr %20, align 8
  %154 = load double, ptr %22, align 8
  %155 = load <2 x double>, ptr %24, align 8
  %156 = load double, ptr %26, align 8
  %157 = load <2 x double>, ptr %28, align 8
  %158 = load double, ptr %30, align 8
  %159 = load double, ptr %32, align 8
  %160 = load double, ptr %34, align 8
  %161 = load double, ptr %36, align 8
  %162 = load double, ptr %38, align 8
  %163 = load i32, ptr %40, align 4
  %164 = load i32, ptr %42, align 4
  %165 = load i32, ptr %44, align 4
  br label %fp_ok

fp_ok31:                                          ; preds = %fp_reload33, %guest_80002A04_b1
  %cycles.9 = phi i64 [ %cycles.0, %guest_80002A04_b1 ], [ 0, %fp_reload33 ]
  %state30.8 = phi i32 [ %state30.0, %guest_80002A04_b1 ], [ %209, %fp_reload33 ]
  %state29.9 = phi i32 [ %state29.0, %guest_80002A04_b1 ], [ %208, %fp_reload33 ]
  %state28.9 = phi i32 [ %state28.0, %guest_80002A04_b1 ], [ %207, %fp_reload33 ]
  %state27.9 = phi double [ %state27.0, %guest_80002A04_b1 ], [ %206, %fp_reload33 ]
  %state26.9 = phi double [ %state26.0, %guest_80002A04_b1 ], [ %205, %fp_reload33 ]
  %state25.9 = phi double [ %state25.0, %guest_80002A04_b1 ], [ %204, %fp_reload33 ]
  %state24.9 = phi double [ %state24.0, %guest_80002A04_b1 ], [ %203, %fp_reload33 ]
  %state23.8 = phi double [ %state23.0, %guest_80002A04_b1 ], [ %202, %fp_reload33 ]
  %state20.7 = phi double [ %state20.0, %guest_80002A04_b1 ], [ %200, %fp_reload33 ]
  %state17.6 = phi double [ %state17.0, %guest_80002A04_b1 ], [ %198, %fp_reload33 ]
  %state14.5 = phi double [ %state14.0, %guest_80002A04_b1 ], [ %196, %fp_reload33 ]
  %state11.4 = phi double [ %state11.0, %guest_80002A04_b1 ], [ %194, %fp_reload33 ]
  %state8.3 = phi double [ %state8.0, %guest_80002A04_b1 ], [ %192, %fp_reload33 ]
  %state5.2 = phi double [ %state5.0, %guest_80002A04_b1 ], [ %190, %fp_reload33 ]
  %state.9 = phi double [ %state.0, %guest_80002A04_b1 ], [ %188, %fp_reload33 ]
  %166 = phi <2 x double> [ %71, %guest_80002A04_b1 ], [ %199, %fp_reload33 ]
  %167 = phi <2 x double> [ %65, %guest_80002A04_b1 ], [ %197, %fp_reload33 ]
  %168 = phi <2 x double> [ %66, %guest_80002A04_b1 ], [ %195, %fp_reload33 ]
  %169 = phi <2 x double> [ %67, %guest_80002A04_b1 ], [ %193, %fp_reload33 ]
  %170 = phi <2 x double> [ %68, %guest_80002A04_b1 ], [ %191, %fp_reload33 ]
  %171 = phi <2 x double> [ %69, %guest_80002A04_b1 ], [ %201, %fp_reload33 ]
  %172 = phi <2 x double> [ %70, %guest_80002A04_b1 ], [ %189, %fp_reload33 ]
  store i32 %state29.9, ptr %42, align 4
  store double %state25.9, ptr %34, align 8
  store <2 x double> %172, ptr %4, align 8
  store double %state5.2, ptr %6, align 8
  tail call void @ppc_fsubs(ptr nonnull %ctx, i8 4, i8 5, i8 6)
  %173 = load double, ptr %4, align 8
  %174 = load double, ptr %34, align 8
  %175 = load i32, ptr %42, align 4
  %176 = add nuw nsw i64 %cycles.9, 1
  br label %guest_80002A08_b2

fp_check32:                                       ; preds = %guest_80002A04_b1
  store double %state.0, ptr %0, align 8
  %177 = extractelement <2 x double> %70, i32 0
  store double %177, ptr %4, align 8
  %178 = extractelement <2 x double> %68, i32 0
  store double %178, ptr %8, align 8
  %179 = extractelement <2 x double> %67, i32 0
  store double %179, ptr %12, align 8
  %180 = extractelement <2 x double> %66, i32 0
  store double %180, ptr %16, align 8
  %181 = extractelement <2 x double> %65, i32 0
  store double %181, ptr %20, align 8
  %182 = extractelement <2 x double> %71, i32 0
  store double %182, ptr %24, align 8
  %183 = extractelement <2 x double> %69, i32 0
  store double %183, ptr %28, align 8
  store double %state24.0, ptr %32, align 8
  store double %state25.0, ptr %34, align 8
  store double %state26.0, ptr %36, align 8
  store double %state27.0, ptr %38, align 8
  store i32 %state29.0, ptr %42, align 4
  store i32 -2147472892, ptr %46, align 4
  %184 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %185 = load i64, ptr %184, align 8
  %186 = sub i64 %185, %cycles.0
  store i64 %186, ptr %184, align 8
  %187 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472892)
  br i1 %187, label %fp_reload33, label %common.ret

fp_reload33:                                      ; preds = %fp_check32
  %188 = load double, ptr %0, align 8
  %189 = load <2 x double>, ptr %4, align 8
  %190 = load double, ptr %6, align 8
  %191 = load <2 x double>, ptr %8, align 8
  %192 = load double, ptr %10, align 8
  %193 = load <2 x double>, ptr %12, align 8
  %194 = load double, ptr %14, align 8
  %195 = load <2 x double>, ptr %16, align 8
  %196 = load double, ptr %18, align 8
  %197 = load <2 x double>, ptr %20, align 8
  %198 = load double, ptr %22, align 8
  %199 = load <2 x double>, ptr %24, align 8
  %200 = load double, ptr %26, align 8
  %201 = load <2 x double>, ptr %28, align 8
  %202 = load double, ptr %30, align 8
  %203 = load double, ptr %32, align 8
  %204 = load double, ptr %34, align 8
  %205 = load double, ptr %36, align 8
  %206 = load double, ptr %38, align 8
  %207 = load i32, ptr %40, align 4
  %208 = load i32, ptr %42, align 4
  %209 = load i32, ptr %44, align 4
  br label %fp_ok31

fp_ok35:                                          ; preds = %fp_reload37, %guest_80002A08_b2
  %cycles.10 = phi i64 [ %cycles.1, %guest_80002A08_b2 ], [ 0, %fp_reload37 ]
  %state30.9 = phi i32 [ %state30.1, %guest_80002A08_b2 ], [ %250, %fp_reload37 ]
  %state29.10 = phi i32 [ %state29.1, %guest_80002A08_b2 ], [ %249, %fp_reload37 ]
  %state28.10 = phi i32 [ %state28.1, %guest_80002A08_b2 ], [ %248, %fp_reload37 ]
  %state27.10 = phi double [ %state27.1, %guest_80002A08_b2 ], [ %247, %fp_reload37 ]
  %state26.10 = phi double [ %state26.1, %guest_80002A08_b2 ], [ %246, %fp_reload37 ]
  %state25.10 = phi double [ %state25.1, %guest_80002A08_b2 ], [ %245, %fp_reload37 ]
  %state24.10 = phi double [ %state24.1, %guest_80002A08_b2 ], [ %244, %fp_reload37 ]
  %state23.9 = phi double [ %state23.1, %guest_80002A08_b2 ], [ %243, %fp_reload37 ]
  %state20.8 = phi double [ %state20.1, %guest_80002A08_b2 ], [ %241, %fp_reload37 ]
  %state17.7 = phi double [ %state17.1, %guest_80002A08_b2 ], [ %239, %fp_reload37 ]
  %state14.6 = phi double [ %state14.1, %guest_80002A08_b2 ], [ %237, %fp_reload37 ]
  %state11.5 = phi double [ %state11.1, %guest_80002A08_b2 ], [ %235, %fp_reload37 ]
  %state8.4 = phi double [ %state8.1, %guest_80002A08_b2 ], [ %233, %fp_reload37 ]
  %state3.10 = phi double [ %state3.1, %guest_80002A08_b2 ], [ %231, %fp_reload37 ]
  %state.10 = phi double [ %state.1, %guest_80002A08_b2 ], [ %230, %fp_reload37 ]
  %210 = phi <2 x double> [ %81, %guest_80002A08_b2 ], [ %242, %fp_reload37 ]
  %211 = phi <2 x double> [ %76, %guest_80002A08_b2 ], [ %240, %fp_reload37 ]
  %212 = phi <2 x double> [ %77, %guest_80002A08_b2 ], [ %238, %fp_reload37 ]
  %213 = phi <2 x double> [ %78, %guest_80002A08_b2 ], [ %236, %fp_reload37 ]
  %214 = phi <2 x double> [ %79, %guest_80002A08_b2 ], [ %234, %fp_reload37 ]
  %215 = phi <2 x double> [ %80, %guest_80002A08_b2 ], [ %232, %fp_reload37 ]
  store i32 %state29.10, ptr %42, align 4
  store double %state26.10, ptr %36, align 8
  store <2 x double> %215, ptr %8, align 8
  store double %state8.4, ptr %10, align 8
  tail call void @ppc_fmuls(ptr nonnull %ctx, i8 7, i8 8, i8 9)
  %216 = load double, ptr %8, align 8
  %217 = load double, ptr %36, align 8
  %218 = load i32, ptr %42, align 4
  %219 = add nuw nsw i64 %cycles.10, 17
  br label %guest_80002A0C_b3

fp_check36:                                       ; preds = %guest_80002A08_b2
  store double %state.1, ptr %0, align 8
  store double %state3.1, ptr %4, align 8
  %220 = extractelement <2 x double> %80, i32 0
  store double %220, ptr %8, align 8
  %221 = extractelement <2 x double> %79, i32 0
  store double %221, ptr %12, align 8
  %222 = extractelement <2 x double> %78, i32 0
  store double %222, ptr %16, align 8
  %223 = extractelement <2 x double> %77, i32 0
  store double %223, ptr %20, align 8
  %224 = extractelement <2 x double> %76, i32 0
  store double %224, ptr %24, align 8
  %225 = extractelement <2 x double> %81, i32 0
  store double %225, ptr %28, align 8
  store double %state24.1, ptr %32, align 8
  store double %state25.1, ptr %34, align 8
  store double %state26.1, ptr %36, align 8
  store double %state27.1, ptr %38, align 8
  store i32 %state29.1, ptr %42, align 4
  store i32 -2147472888, ptr %46, align 4
  %226 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %227 = load i64, ptr %226, align 8
  %228 = sub i64 %227, %cycles.1
  store i64 %228, ptr %226, align 8
  %229 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472888)
  br i1 %229, label %fp_reload37, label %common.ret

fp_reload37:                                      ; preds = %fp_check36
  %230 = load double, ptr %0, align 8
  %231 = load double, ptr %4, align 8
  %232 = load <2 x double>, ptr %8, align 8
  %233 = load double, ptr %10, align 8
  %234 = load <2 x double>, ptr %12, align 8
  %235 = load double, ptr %14, align 8
  %236 = load <2 x double>, ptr %16, align 8
  %237 = load double, ptr %18, align 8
  %238 = load <2 x double>, ptr %20, align 8
  %239 = load double, ptr %22, align 8
  %240 = load <2 x double>, ptr %24, align 8
  %241 = load double, ptr %26, align 8
  %242 = load <2 x double>, ptr %28, align 8
  %243 = load double, ptr %30, align 8
  %244 = load double, ptr %32, align 8
  %245 = load double, ptr %34, align 8
  %246 = load double, ptr %36, align 8
  %247 = load double, ptr %38, align 8
  %248 = load i32, ptr %40, align 4
  %249 = load i32, ptr %42, align 4
  %250 = load i32, ptr %44, align 4
  br label %fp_ok35

fp_ok39:                                          ; preds = %fp_reload41, %guest_80002A0C_b3
  %cycles.11 = phi i64 [ %cycles.2, %guest_80002A0C_b3 ], [ 0, %fp_reload41 ]
  %state30.10 = phi i32 [ %state30.2, %guest_80002A0C_b3 ], [ %288, %fp_reload41 ]
  %state29.11 = phi i32 [ %state29.2, %guest_80002A0C_b3 ], [ %287, %fp_reload41 ]
  %state28.11 = phi i32 [ %state28.2, %guest_80002A0C_b3 ], [ %286, %fp_reload41 ]
  %state27.11 = phi double [ %state27.2, %guest_80002A0C_b3 ], [ %285, %fp_reload41 ]
  %state26.11 = phi double [ %state26.2, %guest_80002A0C_b3 ], [ %284, %fp_reload41 ]
  %state25.11 = phi double [ %state25.2, %guest_80002A0C_b3 ], [ %283, %fp_reload41 ]
  %state24.11 = phi double [ %state24.2, %guest_80002A0C_b3 ], [ %282, %fp_reload41 ]
  %state23.10 = phi double [ %state23.2, %guest_80002A0C_b3 ], [ %281, %fp_reload41 ]
  %state20.9 = phi double [ %state20.2, %guest_80002A0C_b3 ], [ %279, %fp_reload41 ]
  %state17.8 = phi double [ %state17.2, %guest_80002A0C_b3 ], [ %277, %fp_reload41 ]
  %state14.7 = phi double [ %state14.2, %guest_80002A0C_b3 ], [ %275, %fp_reload41 ]
  %state11.6 = phi double [ %state11.2, %guest_80002A0C_b3 ], [ %273, %fp_reload41 ]
  %state6.11 = phi double [ %state6.2, %guest_80002A0C_b3 ], [ %271, %fp_reload41 ]
  %state3.11 = phi double [ %state3.2, %guest_80002A0C_b3 ], [ %270, %fp_reload41 ]
  %state.11 = phi double [ %state.2, %guest_80002A0C_b3 ], [ %269, %fp_reload41 ]
  %251 = phi <2 x double> [ %86, %guest_80002A0C_b3 ], [ %280, %fp_reload41 ]
  %252 = phi <2 x double> [ %87, %guest_80002A0C_b3 ], [ %278, %fp_reload41 ]
  %253 = phi <2 x double> [ %88, %guest_80002A0C_b3 ], [ %276, %fp_reload41 ]
  %254 = phi <2 x double> [ %89, %guest_80002A0C_b3 ], [ %274, %fp_reload41 ]
  %255 = phi <2 x double> [ %90, %guest_80002A0C_b3 ], [ %272, %fp_reload41 ]
  store i32 %state29.11, ptr %42, align 4
  store double %state27.11, ptr %38, align 8
  store <2 x double> %255, ptr %12, align 8
  store double %state11.6, ptr %14, align 8
  tail call void @ppc_fdivs(ptr nonnull %ctx, i8 10, i8 11, i8 12)
  %256 = load double, ptr %12, align 8
  %257 = load double, ptr %38, align 8
  %258 = load i32, ptr %42, align 4
  %259 = add nuw nsw i64 %cycles.11, 1
  br label %guest_80002A10_b4

fp_check40:                                       ; preds = %guest_80002A0C_b3
  store double %state.2, ptr %0, align 8
  store double %state3.2, ptr %4, align 8
  store double %state6.2, ptr %8, align 8
  %260 = extractelement <2 x double> %90, i32 0
  store double %260, ptr %12, align 8
  %261 = extractelement <2 x double> %89, i32 0
  store double %261, ptr %16, align 8
  %262 = extractelement <2 x double> %88, i32 0
  store double %262, ptr %20, align 8
  %263 = extractelement <2 x double> %87, i32 0
  store double %263, ptr %24, align 8
  %264 = extractelement <2 x double> %86, i32 0
  store double %264, ptr %28, align 8
  store double %state24.2, ptr %32, align 8
  store double %state25.2, ptr %34, align 8
  store double %state26.2, ptr %36, align 8
  store double %state27.2, ptr %38, align 8
  store i32 %state29.2, ptr %42, align 4
  store i32 -2147472884, ptr %46, align 4
  %265 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %266 = load i64, ptr %265, align 8
  %267 = sub i64 %266, %cycles.2
  store i64 %267, ptr %265, align 8
  %268 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472884)
  br i1 %268, label %fp_reload41, label %common.ret

fp_reload41:                                      ; preds = %fp_check40
  %269 = load double, ptr %0, align 8
  %270 = load double, ptr %4, align 8
  %271 = load double, ptr %8, align 8
  %272 = load <2 x double>, ptr %12, align 8
  %273 = load double, ptr %14, align 8
  %274 = load <2 x double>, ptr %16, align 8
  %275 = load double, ptr %18, align 8
  %276 = load <2 x double>, ptr %20, align 8
  %277 = load double, ptr %22, align 8
  %278 = load <2 x double>, ptr %24, align 8
  %279 = load double, ptr %26, align 8
  %280 = load <2 x double>, ptr %28, align 8
  %281 = load double, ptr %30, align 8
  %282 = load double, ptr %32, align 8
  %283 = load double, ptr %34, align 8
  %284 = load double, ptr %36, align 8
  %285 = load double, ptr %38, align 8
  %286 = load i32, ptr %40, align 4
  %287 = load i32, ptr %42, align 4
  %288 = load i32, ptr %44, align 4
  br label %fp_ok39

fp_ok43:                                          ; preds = %fp_reload45, %guest_80002A10_b4
  %cycles.12 = phi i64 [ %cycles.3, %guest_80002A10_b4 ], [ 0, %fp_reload45 ]
  %state30.11 = phi i32 [ %state30.3, %guest_80002A10_b4 ], [ %322, %fp_reload45 ]
  %state29.12 = phi i32 [ %state29.3, %guest_80002A10_b4 ], [ %321, %fp_reload45 ]
  %state28.12 = phi i32 [ %state28.3, %guest_80002A10_b4 ], [ %320, %fp_reload45 ]
  %state27.12 = phi double [ %state27.3, %guest_80002A10_b4 ], [ %319, %fp_reload45 ]
  %state26.12 = phi double [ %state26.3, %guest_80002A10_b4 ], [ %318, %fp_reload45 ]
  %state25.12 = phi double [ %state25.3, %guest_80002A10_b4 ], [ %317, %fp_reload45 ]
  %state24.12 = phi double [ %state24.3, %guest_80002A10_b4 ], [ %316, %fp_reload45 ]
  %state23.11 = phi double [ %state23.3, %guest_80002A10_b4 ], [ %315, %fp_reload45 ]
  %state20.10 = phi double [ %state20.3, %guest_80002A10_b4 ], [ %313, %fp_reload45 ]
  %state17.9 = phi double [ %state17.3, %guest_80002A10_b4 ], [ %311, %fp_reload45 ]
  %state14.8 = phi double [ %state14.3, %guest_80002A10_b4 ], [ %309, %fp_reload45 ]
  %state9.12 = phi double [ %state9.3, %guest_80002A10_b4 ], [ %307, %fp_reload45 ]
  %state6.12 = phi double [ %state6.3, %guest_80002A10_b4 ], [ %306, %fp_reload45 ]
  %state3.12 = phi double [ %state3.3, %guest_80002A10_b4 ], [ %305, %fp_reload45 ]
  %state.12 = phi double [ %state.3, %guest_80002A10_b4 ], [ %304, %fp_reload45 ]
  %289 = phi <2 x double> [ %95, %guest_80002A10_b4 ], [ %314, %fp_reload45 ]
  %290 = phi <2 x double> [ %96, %guest_80002A10_b4 ], [ %312, %fp_reload45 ]
  %291 = phi <2 x double> [ %97, %guest_80002A10_b4 ], [ %310, %fp_reload45 ]
  %292 = phi <2 x double> [ %98, %guest_80002A10_b4 ], [ %308, %fp_reload45 ]
  store i32 %state29.12, ptr %42, align 4
  store <2 x double> %292, ptr %16, align 8
  store double %state14.8, ptr %18, align 8
  tail call void @ppc_fadd(ptr nonnull %ctx, i8 13, i8 14, i8 15)
  %293 = load double, ptr %16, align 8
  %294 = load i32, ptr %42, align 4
  %295 = add nuw nsw i64 %cycles.12, 1
  br label %guest_80002A14_b5

fp_check44:                                       ; preds = %guest_80002A10_b4
  store double %state.3, ptr %0, align 8
  store double %state3.3, ptr %4, align 8
  store double %state6.3, ptr %8, align 8
  store double %state9.3, ptr %12, align 8
  %296 = extractelement <2 x double> %98, i32 0
  store double %296, ptr %16, align 8
  %297 = extractelement <2 x double> %97, i32 0
  store double %297, ptr %20, align 8
  %298 = extractelement <2 x double> %96, i32 0
  store double %298, ptr %24, align 8
  %299 = extractelement <2 x double> %95, i32 0
  store double %299, ptr %28, align 8
  store double %state24.3, ptr %32, align 8
  store double %state25.3, ptr %34, align 8
  store double %state26.3, ptr %36, align 8
  store double %state27.3, ptr %38, align 8
  store i32 %state29.3, ptr %42, align 4
  store i32 -2147472880, ptr %46, align 4
  %300 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %301 = load i64, ptr %300, align 8
  %302 = sub i64 %301, %cycles.3
  store i64 %302, ptr %300, align 8
  %303 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472880)
  br i1 %303, label %fp_reload45, label %common.ret

fp_reload45:                                      ; preds = %fp_check44
  %304 = load double, ptr %0, align 8
  %305 = load double, ptr %4, align 8
  %306 = load double, ptr %8, align 8
  %307 = load double, ptr %12, align 8
  %308 = load <2 x double>, ptr %16, align 8
  %309 = load double, ptr %18, align 8
  %310 = load <2 x double>, ptr %20, align 8
  %311 = load double, ptr %22, align 8
  %312 = load <2 x double>, ptr %24, align 8
  %313 = load double, ptr %26, align 8
  %314 = load <2 x double>, ptr %28, align 8
  %315 = load double, ptr %30, align 8
  %316 = load double, ptr %32, align 8
  %317 = load double, ptr %34, align 8
  %318 = load double, ptr %36, align 8
  %319 = load double, ptr %38, align 8
  %320 = load i32, ptr %40, align 4
  %321 = load i32, ptr %42, align 4
  %322 = load i32, ptr %44, align 4
  br label %fp_ok43

fp_ok47:                                          ; preds = %fp_reload49, %guest_80002A14_b5
  %cycles.13 = phi i64 [ %cycles.4, %guest_80002A14_b5 ], [ 0, %fp_reload49 ]
  %state30.12 = phi i32 [ %state30.4, %guest_80002A14_b5 ], [ %353, %fp_reload49 ]
  %state29.13 = phi i32 [ %state29.4, %guest_80002A14_b5 ], [ %352, %fp_reload49 ]
  %state28.13 = phi i32 [ %state28.4, %guest_80002A14_b5 ], [ %351, %fp_reload49 ]
  %state27.13 = phi double [ %state27.4, %guest_80002A14_b5 ], [ %350, %fp_reload49 ]
  %state26.13 = phi double [ %state26.4, %guest_80002A14_b5 ], [ %349, %fp_reload49 ]
  %state25.13 = phi double [ %state25.4, %guest_80002A14_b5 ], [ %348, %fp_reload49 ]
  %state24.13 = phi double [ %state24.4, %guest_80002A14_b5 ], [ %347, %fp_reload49 ]
  %state23.12 = phi double [ %state23.4, %guest_80002A14_b5 ], [ %346, %fp_reload49 ]
  %state20.11 = phi double [ %state20.4, %guest_80002A14_b5 ], [ %344, %fp_reload49 ]
  %state17.10 = phi double [ %state17.4, %guest_80002A14_b5 ], [ %342, %fp_reload49 ]
  %state12.13 = phi double [ %state12.4, %guest_80002A14_b5 ], [ %340, %fp_reload49 ]
  %state9.13 = phi double [ %state9.4, %guest_80002A14_b5 ], [ %339, %fp_reload49 ]
  %state6.13 = phi double [ %state6.4, %guest_80002A14_b5 ], [ %338, %fp_reload49 ]
  %state3.13 = phi double [ %state3.4, %guest_80002A14_b5 ], [ %337, %fp_reload49 ]
  %state.13 = phi double [ %state.4, %guest_80002A14_b5 ], [ %336, %fp_reload49 ]
  %323 = phi <2 x double> [ %103, %guest_80002A14_b5 ], [ %345, %fp_reload49 ]
  %324 = phi <2 x double> [ %104, %guest_80002A14_b5 ], [ %343, %fp_reload49 ]
  %325 = phi <2 x double> [ %105, %guest_80002A14_b5 ], [ %341, %fp_reload49 ]
  store i32 %state29.13, ptr %42, align 4
  store <2 x double> %325, ptr %20, align 8
  store double %state17.10, ptr %22, align 8
  tail call void @ppc_fsub(ptr nonnull %ctx, i8 16, i8 17, i8 18)
  %326 = load double, ptr %20, align 8
  %327 = load i32, ptr %42, align 4
  %328 = add nuw nsw i64 %cycles.13, 1
  br label %guest_80002A18_b6

fp_check48:                                       ; preds = %guest_80002A14_b5
  store double %state.4, ptr %0, align 8
  store double %state3.4, ptr %4, align 8
  store double %state6.4, ptr %8, align 8
  store double %state9.4, ptr %12, align 8
  store double %state12.4, ptr %16, align 8
  %329 = extractelement <2 x double> %105, i32 0
  store double %329, ptr %20, align 8
  %330 = extractelement <2 x double> %104, i32 0
  store double %330, ptr %24, align 8
  %331 = extractelement <2 x double> %103, i32 0
  store double %331, ptr %28, align 8
  store double %state24.4, ptr %32, align 8
  store double %state25.4, ptr %34, align 8
  store double %state26.4, ptr %36, align 8
  store double %state27.4, ptr %38, align 8
  store i32 %state29.4, ptr %42, align 4
  store i32 -2147472876, ptr %46, align 4
  %332 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %333 = load i64, ptr %332, align 8
  %334 = sub i64 %333, %cycles.4
  store i64 %334, ptr %332, align 8
  %335 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472876)
  br i1 %335, label %fp_reload49, label %common.ret

fp_reload49:                                      ; preds = %fp_check48
  %336 = load double, ptr %0, align 8
  %337 = load double, ptr %4, align 8
  %338 = load double, ptr %8, align 8
  %339 = load double, ptr %12, align 8
  %340 = load double, ptr %16, align 8
  %341 = load <2 x double>, ptr %20, align 8
  %342 = load double, ptr %22, align 8
  %343 = load <2 x double>, ptr %24, align 8
  %344 = load double, ptr %26, align 8
  %345 = load <2 x double>, ptr %28, align 8
  %346 = load double, ptr %30, align 8
  %347 = load double, ptr %32, align 8
  %348 = load double, ptr %34, align 8
  %349 = load double, ptr %36, align 8
  %350 = load double, ptr %38, align 8
  %351 = load i32, ptr %40, align 4
  %352 = load i32, ptr %42, align 4
  %353 = load i32, ptr %44, align 4
  br label %fp_ok47

fp_ok51:                                          ; preds = %fp_reload53, %guest_80002A18_b6
  %cycles.14 = phi i64 [ %cycles.5, %guest_80002A18_b6 ], [ 0, %fp_reload53 ]
  %state30.13 = phi i32 [ %state30.5, %guest_80002A18_b6 ], [ %381, %fp_reload53 ]
  %state29.14 = phi i32 [ %state29.5, %guest_80002A18_b6 ], [ %380, %fp_reload53 ]
  %state28.14 = phi i32 [ %state28.5, %guest_80002A18_b6 ], [ %379, %fp_reload53 ]
  %state27.14 = phi double [ %state27.5, %guest_80002A18_b6 ], [ %378, %fp_reload53 ]
  %state26.14 = phi double [ %state26.5, %guest_80002A18_b6 ], [ %377, %fp_reload53 ]
  %state25.14 = phi double [ %state25.5, %guest_80002A18_b6 ], [ %376, %fp_reload53 ]
  %state24.14 = phi double [ %state24.5, %guest_80002A18_b6 ], [ %375, %fp_reload53 ]
  %state23.13 = phi double [ %state23.5, %guest_80002A18_b6 ], [ %374, %fp_reload53 ]
  %state20.12 = phi double [ %state20.5, %guest_80002A18_b6 ], [ %372, %fp_reload53 ]
  %state15.14 = phi double [ %state15.5, %guest_80002A18_b6 ], [ %370, %fp_reload53 ]
  %state12.14 = phi double [ %state12.5, %guest_80002A18_b6 ], [ %369, %fp_reload53 ]
  %state9.14 = phi double [ %state9.5, %guest_80002A18_b6 ], [ %368, %fp_reload53 ]
  %state6.14 = phi double [ %state6.5, %guest_80002A18_b6 ], [ %367, %fp_reload53 ]
  %state3.14 = phi double [ %state3.5, %guest_80002A18_b6 ], [ %366, %fp_reload53 ]
  %state.14 = phi double [ %state.5, %guest_80002A18_b6 ], [ %365, %fp_reload53 ]
  %354 = phi <2 x double> [ %110, %guest_80002A18_b6 ], [ %373, %fp_reload53 ]
  %355 = phi <2 x double> [ %111, %guest_80002A18_b6 ], [ %371, %fp_reload53 ]
  store i32 %state29.14, ptr %42, align 4
  store <2 x double> %355, ptr %24, align 8
  store double %state20.12, ptr %26, align 8
  tail call void @ppc_fmul(ptr nonnull %ctx, i8 19, i8 20, i8 21)
  %356 = load double, ptr %24, align 8
  %357 = load i32, ptr %42, align 4
  %358 = add nuw nsw i64 %cycles.14, 31
  br label %guest_80002A1C_b7

fp_check52:                                       ; preds = %guest_80002A18_b6
  store double %state.5, ptr %0, align 8
  store double %state3.5, ptr %4, align 8
  store double %state6.5, ptr %8, align 8
  store double %state9.5, ptr %12, align 8
  store double %state12.5, ptr %16, align 8
  store double %state15.5, ptr %20, align 8
  %359 = extractelement <2 x double> %111, i32 0
  store double %359, ptr %24, align 8
  %360 = extractelement <2 x double> %110, i32 0
  store double %360, ptr %28, align 8
  store double %state24.5, ptr %32, align 8
  store double %state25.5, ptr %34, align 8
  store double %state26.5, ptr %36, align 8
  store double %state27.5, ptr %38, align 8
  store i32 %state29.5, ptr %42, align 4
  store i32 -2147472872, ptr %46, align 4
  %361 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %362 = load i64, ptr %361, align 8
  %363 = sub i64 %362, %cycles.5
  store i64 %363, ptr %361, align 8
  %364 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472872)
  br i1 %364, label %fp_reload53, label %common.ret

fp_reload53:                                      ; preds = %fp_check52
  %365 = load double, ptr %0, align 8
  %366 = load double, ptr %4, align 8
  %367 = load double, ptr %8, align 8
  %368 = load double, ptr %12, align 8
  %369 = load double, ptr %16, align 8
  %370 = load double, ptr %20, align 8
  %371 = load <2 x double>, ptr %24, align 8
  %372 = load double, ptr %26, align 8
  %373 = load <2 x double>, ptr %28, align 8
  %374 = load double, ptr %30, align 8
  %375 = load double, ptr %32, align 8
  %376 = load double, ptr %34, align 8
  %377 = load double, ptr %36, align 8
  %378 = load double, ptr %38, align 8
  %379 = load i32, ptr %40, align 4
  %380 = load i32, ptr %42, align 4
  %381 = load i32, ptr %44, align 4
  br label %fp_ok51

fp_ok55:                                          ; preds = %fp_reload57, %guest_80002A1C_b7
  %cycles.15 = phi i64 [ %cycles.6, %guest_80002A1C_b7 ], [ 0, %fp_reload57 ]
  %state29.15 = phi i32 [ %state29.6, %guest_80002A1C_b7 ], [ %404, %fp_reload57 ]
  %state28.15 = phi i32 [ %state28.6, %guest_80002A1C_b7 ], [ %403, %fp_reload57 ]
  %state27.15 = phi double [ %state27.6, %guest_80002A1C_b7 ], [ %402, %fp_reload57 ]
  %state26.15 = phi double [ %state26.6, %guest_80002A1C_b7 ], [ %401, %fp_reload57 ]
  %state25.15 = phi double [ %state25.6, %guest_80002A1C_b7 ], [ %400, %fp_reload57 ]
  %state24.15 = phi double [ %state24.6, %guest_80002A1C_b7 ], [ %399, %fp_reload57 ]
  %state23.14 = phi double [ %state23.6, %guest_80002A1C_b7 ], [ %398, %fp_reload57 ]
  %state18.15 = phi double [ %state18.6, %guest_80002A1C_b7 ], [ %396, %fp_reload57 ]
  %state15.15 = phi double [ %state15.6, %guest_80002A1C_b7 ], [ %395, %fp_reload57 ]
  %state12.15 = phi double [ %state12.6, %guest_80002A1C_b7 ], [ %394, %fp_reload57 ]
  %state9.15 = phi double [ %state9.6, %guest_80002A1C_b7 ], [ %393, %fp_reload57 ]
  %state6.15 = phi double [ %state6.6, %guest_80002A1C_b7 ], [ %392, %fp_reload57 ]
  %state3.15 = phi double [ %state3.6, %guest_80002A1C_b7 ], [ %391, %fp_reload57 ]
  %state.15 = phi double [ %state.6, %guest_80002A1C_b7 ], [ %390, %fp_reload57 ]
  %382 = phi <2 x double> [ %116, %guest_80002A1C_b7 ], [ %397, %fp_reload57 ]
  store i32 %state29.15, ptr %42, align 4
  store <2 x double> %382, ptr %28, align 8
  store double %state23.14, ptr %30, align 8
  tail call void @ppc_fdiv(ptr nonnull %ctx, i8 22, i8 23, i8 24)
  %383 = load double, ptr %28, align 8
  %384 = load i32, ptr %42, align 4
  %.neg = xor i64 %cycles.15, -1
  br label %guest_80002A20_b8

fp_check56:                                       ; preds = %guest_80002A1C_b7
  store double %state.6, ptr %0, align 8
  store double %state3.6, ptr %4, align 8
  store double %state6.6, ptr %8, align 8
  store double %state9.6, ptr %12, align 8
  store double %state12.6, ptr %16, align 8
  store double %state15.6, ptr %20, align 8
  store double %state18.6, ptr %24, align 8
  %385 = extractelement <2 x double> %116, i32 0
  store double %385, ptr %28, align 8
  store double %state24.6, ptr %32, align 8
  store double %state25.6, ptr %34, align 8
  store double %state26.6, ptr %36, align 8
  store double %state27.6, ptr %38, align 8
  store i32 %state29.6, ptr %42, align 4
  store i32 -2147472868, ptr %46, align 4
  %386 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %387 = load i64, ptr %386, align 8
  %388 = sub i64 %387, %cycles.6
  store i64 %388, ptr %386, align 8
  %389 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472868)
  br i1 %389, label %fp_reload57, label %common.ret

fp_reload57:                                      ; preds = %fp_check56
  %390 = load double, ptr %0, align 8
  %391 = load double, ptr %4, align 8
  %392 = load double, ptr %8, align 8
  %393 = load double, ptr %12, align 8
  %394 = load double, ptr %16, align 8
  %395 = load double, ptr %20, align 8
  %396 = load double, ptr %24, align 8
  %397 = load <2 x double>, ptr %28, align 8
  %398 = load double, ptr %30, align 8
  %399 = load double, ptr %32, align 8
  %400 = load double, ptr %34, align 8
  %401 = load double, ptr %36, align 8
  %402 = load double, ptr %38, align 8
  %403 = load i32, ptr %40, align 4
  %404 = load i32, ptr %42, align 4
  br label %fp_ok55
}

declare void @ppc_fadds(ptr, i8, i8, i8)

declare void @ppc_fsubs(ptr, i8, i8, i8)

declare void @ppc_fmuls(ptr, i8, i8, i8)

declare void @ppc_fdivs(ptr, i8, i8, i8)

declare void @ppc_fadd(ptr, i8, i8, i8)

declare void @ppc_fsub(ptr, i8, i8, i8)

declare void @ppc_fmul(ptr, i8, i8, i8)

declare void @ppc_fdiv(ptr, i8, i8, i8)

define hidden void @func_80002B00(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 136
  %1 = load double, ptr %0, align 8
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 144
  %3 = getelementptr inbounds nuw i8, ptr %ctx, i64 152
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 160
  %5 = load double, ptr %4, align 8
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 168
  %7 = load <2 x double>, ptr %6, align 8
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 184
  %9 = load <2 x double>, ptr %8, align 8
  %10 = getelementptr inbounds nuw i8, ptr %ctx, i64 200
  %11 = load double, ptr %10, align 8
  %12 = getelementptr inbounds nuw i8, ptr %ctx, i64 232
  %13 = load <2 x double>, ptr %12, align 8
  %14 = extractelement <2 x double> %13, i32 0
  %15 = getelementptr inbounds nuw i8, ptr %ctx, i64 248
  %16 = load <2 x double>, ptr %15, align 8
  %17 = getelementptr inbounds nuw i8, ptr %ctx, i64 392
  %18 = load double, ptr %17, align 8
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 400
  %20 = getelementptr inbounds nuw i8, ptr %ctx, i64 408
  %21 = getelementptr inbounds nuw i8, ptr %ctx, i64 416
  %22 = load double, ptr %21, align 8
  %23 = getelementptr inbounds nuw i8, ptr %ctx, i64 424
  %24 = getelementptr inbounds nuw i8, ptr %ctx, i64 432
  %25 = load <2 x double>, ptr %23, align 8
  %26 = getelementptr inbounds nuw i8, ptr %ctx, i64 440
  %27 = load <2 x double>, ptr %26, align 8
  %28 = getelementptr inbounds nuw i8, ptr %ctx, i64 456
  %29 = load double, ptr %28, align 8
  %30 = getelementptr inbounds nuw i8, ptr %ctx, i64 488
  %31 = load <2 x double>, ptr %30, align 8
  %32 = extractelement <2 x double> %31, i32 0
  %33 = getelementptr inbounds nuw i8, ptr %ctx, i64 504
  %34 = load <2 x double>, ptr %33, align 8
  %35 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %36 = load i32, ptr %35, align 4
  %37 = getelementptr inbounds nuw i8, ptr %ctx, i64 652
  %38 = load i32, ptr %37, align 4
  %39 = getelementptr inbounds nuw i8, ptr %ctx, i64 660
  %40 = load i32, ptr %39, align 4
  %41 = getelementptr inbounds nuw i8, ptr %ctx, i64 664
  %42 = load i32, ptr %41, align 4
  %43 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %44 = load i32, ptr %43, align 4
  %45 = sub i32 %44, -2147472640
  %46 = tail call i32 @llvm.fshl.i32(i32 %45, i32 %45, i32 30)
  %47 = extractelement <2 x double> %7, i32 0
  %48 = extractelement <2 x double> %25, i32 0
  %49 = extractelement <2 x double> %25, i32 1
  %50 = extractelement <2 x double> %9, i32 0
  %51 = extractelement <2 x double> %27, i32 0
  switch i32 %46, label %common.ret [
    i32 0, label %guest_80002B00_b0
    i32 1, label %guest_80002B04_b1
    i32 2, label %guest_80002B08_b2
    i32 3, label %guest_80002B0C_b3
    i32 4, label %guest_80002B10_b4
    i32 5, label %guest_80002B14_b5
    i32 6, label %guest_80002B18_b6
  ]

guest_80002B00_b0:                                ; preds = %entry
  %52 = load double, ptr %20, align 8
  %53 = load double, ptr %19, align 8
  %54 = load double, ptr %3, align 8
  %55 = load double, ptr %2, align 8
  %56 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %57 = load i64, ptr %56, align 8
  %58 = add i64 %57, -1
  store i64 %58, ptr %56, align 8
  %59 = and i32 %42, 8192
  %.not = icmp eq i32 %59, 0
  %60 = insertelement <2 x double> poison, double %1, i32 0
  %61 = insertelement <2 x double> %60, double %55, i32 1
  %62 = insertelement <2 x double> poison, double %18, i32 0
  %63 = insertelement <2 x double> %62, double %53, i32 1
  br i1 %.not, label %fp_check, label %fp_ok

guest_80002B04_b1:                                ; preds = %fp_ok, %entry
  %cycles.0 = phi i64 [ 1, %entry ], [ %cycles.6, %fp_ok ]
  %state29.0 = phi i32 [ %42, %entry ], [ %state29.5, %fp_ok ]
  %state28.0 = phi i32 [ %40, %entry ], [ %123, %fp_ok ]
  %state27.0 = phi i32 [ %38, %entry ], [ %state27.6, %fp_ok ]
  %state26.0 = phi i32 [ %36, %entry ], [ %state26.6, %fp_ok ]
  %state21.0 = phi double [ %29, %entry ], [ %state21.1, %fp_ok ]
  %state16.0 = phi double [ %22, %entry ], [ %state16.6, %fp_ok ]
  %state13.0 = phi double [ %18, %entry ], [ %122, %fp_ok ]
  %state8.0 = phi double [ %11, %entry ], [ %state8.1, %fp_ok ]
  %state3.0 = phi double [ %5, %entry ], [ %state3.6, %fp_ok ]
  %state.0 = phi double [ %1, %entry ], [ %121, %fp_ok ]
  %64 = phi <2 x double> [ %7, %entry ], [ %111, %fp_ok ]
  %65 = phi <2 x double> [ %25, %entry ], [ %112, %fp_ok ]
  %66 = phi <2 x double> [ %13, %entry ], [ %113, %fp_ok ]
  %67 = phi <2 x double> [ %16, %entry ], [ %114, %fp_ok ]
  %68 = phi <2 x double> [ %31, %entry ], [ %115, %fp_ok ]
  %69 = phi <2 x double> [ %34, %entry ], [ %116, %fp_ok ]
  %70 = phi <2 x double> [ %9, %entry ], [ %117, %fp_ok ]
  %71 = phi <2 x double> [ %27, %entry ], [ %118, %fp_ok ]
  %72 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %73 = load i64, ptr %72, align 8
  %74 = add i64 %73, -1
  store i64 %74, ptr %72, align 8
  %75 = and i32 %state29.0, 8192
  %.not50 = icmp eq i32 %75, 0
  br i1 %.not50, label %fp_check31, label %fp_ok30

guest_80002B08_b2:                                ; preds = %fp_ok30, %entry
  %cycles.1 = phi i64 [ 1, %entry ], [ %159, %fp_ok30 ]
  %state29.1 = phi i32 [ %42, %entry ], [ %state29.6, %fp_ok30 ]
  %state28.1 = phi i32 [ %40, %entry ], [ %158, %fp_ok30 ]
  %state27.1 = phi i32 [ %38, %entry ], [ %state27.7, %fp_ok30 ]
  %state26.1 = phi i32 [ %36, %entry ], [ %state26.7, %fp_ok30 ]
  %state19.1 = phi double [ %51, %entry ], [ %157, %fp_ok30 ]
  %state16.1 = phi double [ %22, %entry ], [ %state16.7, %fp_ok30 ]
  %state13.1 = phi double [ %18, %entry ], [ %state13.7, %fp_ok30 ]
  %state6.1 = phi double [ %50, %entry ], [ %156, %fp_ok30 ]
  %state3.1 = phi double [ %5, %entry ], [ %state3.7, %fp_ok30 ]
  %state.1 = phi double [ %1, %entry ], [ %state.7, %fp_ok30 ]
  %76 = phi <2 x double> [ %7, %entry ], [ %148, %fp_ok30 ]
  %77 = phi <2 x double> [ %25, %entry ], [ %149, %fp_ok30 ]
  %78 = phi <2 x double> [ %13, %entry ], [ %150, %fp_ok30 ]
  %79 = phi <2 x double> [ %16, %entry ], [ %151, %fp_ok30 ]
  %80 = phi <2 x double> [ %31, %entry ], [ %152, %fp_ok30 ]
  %81 = phi <2 x double> [ %34, %entry ], [ %153, %fp_ok30 ]
  %82 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %83 = load i64, ptr %82, align 8
  %84 = add i64 %83, -1
  store i64 %84, ptr %82, align 8
  %85 = and i32 %state29.1, 8192
  %.not51 = icmp eq i32 %85, 0
  br i1 %.not51, label %fp_check35, label %fp_ok34

guest_80002B0C_b3:                                ; preds = %fp_ok34, %entry
  %cycles.2 = phi i64 [ 1, %entry ], [ %197, %fp_ok34 ]
  %state29.2 = phi i32 [ %42, %entry ], [ %state29.7, %fp_ok34 ]
  %state28.2 = phi i32 [ %40, %entry ], [ %196, %fp_ok34 ]
  %state27.2 = phi i32 [ %38, %entry ], [ %state27.8, %fp_ok34 ]
  %state26.2 = phi i32 [ %36, %entry ], [ %state26.8, %fp_ok34 ]
  %state22.2 = phi double [ %32, %entry ], [ %195, %fp_ok34 ]
  %state19.2 = phi double [ %51, %entry ], [ %state19.8, %fp_ok34 ]
  %state16.2 = phi double [ %22, %entry ], [ %state16.8, %fp_ok34 ]
  %state13.2 = phi double [ %18, %entry ], [ %state13.8, %fp_ok34 ]
  %state9.2 = phi double [ %14, %entry ], [ %194, %fp_ok34 ]
  %state6.2 = phi double [ %50, %entry ], [ %state6.8, %fp_ok34 ]
  %state3.2 = phi double [ %5, %entry ], [ %state3.8, %fp_ok34 ]
  %state.2 = phi double [ %1, %entry ], [ %state.8, %fp_ok34 ]
  %86 = phi <2 x double> [ %13, %entry ], [ %199, %fp_ok34 ]
  %87 = phi <2 x double> [ %31, %entry ], [ %201, %fp_ok34 ]
  %88 = phi <2 x double> [ %7, %entry ], [ %188, %fp_ok34 ]
  %89 = phi <2 x double> [ %25, %entry ], [ %189, %fp_ok34 ]
  %90 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %91 = load i64, ptr %90, align 8
  %92 = add i64 %91, -1
  store i64 %92, ptr %90, align 8
  %93 = and i32 %state29.2, 8192
  %.not52 = icmp eq i32 %93, 0
  br i1 %.not52, label %fp_check39, label %fp_ok38

guest_80002B10_b4:                                ; preds = %fp_ok38, %entry
  %cycles.3 = phi i64 [ 1, %entry ], [ %233, %fp_ok38 ]
  %state29.3 = phi i32 [ %42, %entry ], [ %state29.8, %fp_ok38 ]
  %state28.3 = phi i32 [ %40, %entry ], [ %232, %fp_ok38 ]
  %state27.3 = phi i32 [ %38, %entry ], [ %state27.9, %fp_ok38 ]
  %state26.3 = phi i32 [ %36, %entry ], [ %state26.9, %fp_ok38 ]
  %state19.3 = phi double [ %51, %entry ], [ %state19.9, %fp_ok38 ]
  %state18.3 = phi double [ %49, %entry ], [ %234, %fp_ok38 ]
  %state17.3 = phi double [ %48, %entry ], [ %231, %fp_ok38 ]
  %state16.3 = phi double [ %22, %entry ], [ %state16.9, %fp_ok38 ]
  %state13.3 = phi double [ %18, %entry ], [ %state13.9, %fp_ok38 ]
  %state6.3 = phi double [ %50, %entry ], [ %state6.9, %fp_ok38 ]
  %state4.3 = phi double [ %47, %entry ], [ %230, %fp_ok38 ]
  %state3.3 = phi double [ %5, %entry ], [ %state3.9, %fp_ok38 ]
  %state.3 = phi double [ %1, %entry ], [ %state.9, %fp_ok38 ]
  %94 = phi <2 x double> [ %13, %entry ], [ %226, %fp_ok38 ]
  %95 = phi <2 x double> [ %31, %entry ], [ %227, %fp_ok38 ]
  %96 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %97 = load i64, ptr %96, align 8
  %98 = add i64 %97, -1
  store i64 %98, ptr %96, align 8
  %99 = and i32 %state29.3, 8192
  %.not53 = icmp eq i32 %99, 0
  br i1 %.not53, label %fp_check43, label %fp_ok42

guest_80002B14_b5:                                ; preds = %fp_ok42, %entry
  %cycles.4 = phi i64 [ 1, %entry ], [ %261, %fp_ok42 ]
  %state29.4 = phi i32 [ %42, %entry ], [ %state29.9, %fp_ok42 ]
  %state28.4 = phi i32 [ %40, %entry ], [ %260, %fp_ok42 ]
  %state27.4 = phi i32 [ %38, %entry ], [ %259, %fp_ok42 ]
  %state26.4 = phi i32 [ %36, %entry ], [ %state26.10, %fp_ok42 ]
  %state22.4 = phi double [ %32, %entry ], [ %262, %fp_ok42 ]
  %state19.4 = phi double [ %51, %entry ], [ %state19.10, %fp_ok42 ]
  %state18.4 = phi double [ %49, %entry ], [ %state18.9, %fp_ok42 ]
  %state17.4 = phi double [ %48, %entry ], [ %state17.10, %fp_ok42 ]
  %state16.4 = phi double [ %22, %entry ], [ %state16.10, %fp_ok42 ]
  %state13.4 = phi double [ %18, %entry ], [ %state13.10, %fp_ok42 ]
  %state9.4 = phi double [ %14, %entry ], [ %257, %fp_ok42 ]
  %state6.4 = phi double [ %50, %entry ], [ %state6.10, %fp_ok42 ]
  %state4.4 = phi double [ %47, %entry ], [ %state4.10, %fp_ok42 ]
  %state3.4 = phi double [ %5, %entry ], [ %state3.10, %fp_ok42 ]
  %state.4 = phi double [ %1, %entry ], [ %state.10, %fp_ok42 ]
  %100 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %101 = load i64, ptr %100, align 8
  %102 = add i64 %101, -1
  store i64 %102, ptr %100, align 8
  %103 = and i32 %state29.4, 8192
  %.not54 = icmp eq i32 %103, 0
  br i1 %.not54, label %fp_check47, label %fp_ok46

guest_80002B18_b6:                                ; preds = %fp_ok46, %entry
  %cycles.5.neg = phi i64 [ -1, %entry ], [ %.neg, %fp_ok46 ]
  %state28.5 = phi i32 [ %40, %entry ], [ %state28.11, %fp_ok46 ]
  %state27.5 = phi i32 [ %38, %entry ], [ %state27.11, %fp_ok46 ]
  %state26.5 = phi i32 [ %36, %entry ], [ %state26.11, %fp_ok46 ]
  %state22.5 = phi double [ %32, %entry ], [ %state22.11, %fp_ok46 ]
  %state19.5 = phi double [ %51, %entry ], [ %state19.11, %fp_ok46 ]
  %state17.5 = phi double [ %48, %entry ], [ %state17.11, %fp_ok46 ]
  %state16.5 = phi double [ %22, %entry ], [ %state18.10, %fp_ok46 ]
  %state13.5 = phi double [ %18, %entry ], [ %state13.11, %fp_ok46 ]
  %state9.5 = phi double [ %14, %entry ], [ %state9.11, %fp_ok46 ]
  %state6.5 = phi double [ %50, %entry ], [ %state6.11, %fp_ok46 ]
  %state4.5 = phi double [ %47, %entry ], [ %state4.11, %fp_ok46 ]
  %state3.5 = phi double [ %5, %entry ], [ %state4.11, %fp_ok46 ]
  %state.5 = phi double [ %1, %entry ], [ %state.11, %fp_ok46 ]
  %104 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %105 = load i64, ptr %104, align 8
  %106 = add i64 %105, -1
  store i64 %106, ptr %104, align 8
  %107 = and i32 %state26.5, -4
  store double %state.5, ptr %0, align 8
  store double %state3.5, ptr %4, align 8
  store double %state4.5, ptr %6, align 8
  store double %state6.5, ptr %8, align 8
  store double %state9.5, ptr %12, align 8
  store double %state13.5, ptr %17, align 8
  store double %state16.5, ptr %21, align 8
  store double %state17.5, ptr %23, align 8
  store double %state19.5, ptr %26, align 8
  store double %state22.5, ptr %30, align 8
  store i32 %state27.5, ptr %37, align 4
  store i32 %state28.5, ptr %39, align 4
  store i32 %107, ptr %43, align 4
  %108 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %109 = load i64, ptr %108, align 8
  %110 = add i64 %cycles.5.neg, %109
  store i64 %110, ptr %108, align 8
  br label %common.ret

common.ret:                                       ; preds = %fp_check47, %fp_check43, %fp_check39, %fp_check35, %fp_check31, %fp_check, %entry, %guest_80002B18_b6
  ret void

fp_ok:                                            ; preds = %fp_reload, %guest_80002B00_b0
  %cycles.6 = phi i64 [ 2, %guest_80002B00_b0 ], [ 1, %fp_reload ]
  %state29.5 = phi i32 [ %42, %guest_80002B00_b0 ], [ %147, %fp_reload ]
  %state28.6 = phi i32 [ %40, %guest_80002B00_b0 ], [ %146, %fp_reload ]
  %state27.6 = phi i32 [ %38, %guest_80002B00_b0 ], [ %145, %fp_reload ]
  %state26.6 = phi i32 [ %36, %guest_80002B00_b0 ], [ %144, %fp_reload ]
  %state21.1 = phi double [ %29, %guest_80002B00_b0 ], [ %141, %fp_reload ]
  %state16.6 = phi double [ %22, %guest_80002B00_b0 ], [ %138, %fp_reload ]
  %state15.0 = phi double [ %52, %guest_80002B00_b0 ], [ %137, %fp_reload ]
  %state8.1 = phi double [ %11, %guest_80002B00_b0 ], [ %133, %fp_reload ]
  %state3.6 = phi double [ %5, %guest_80002B00_b0 ], [ %130, %fp_reload ]
  %state2.0 = phi double [ %54, %guest_80002B00_b0 ], [ %129, %fp_reload ]
  %111 = phi <2 x double> [ %7, %guest_80002B00_b0 ], [ %131, %fp_reload ]
  %112 = phi <2 x double> [ %25, %guest_80002B00_b0 ], [ %139, %fp_reload ]
  %113 = phi <2 x double> [ %13, %guest_80002B00_b0 ], [ %134, %fp_reload ]
  %114 = phi <2 x double> [ %16, %guest_80002B00_b0 ], [ %135, %fp_reload ]
  %115 = phi <2 x double> [ %31, %guest_80002B00_b0 ], [ %142, %fp_reload ]
  %116 = phi <2 x double> [ %34, %guest_80002B00_b0 ], [ %143, %fp_reload ]
  %117 = phi <2 x double> [ %9, %guest_80002B00_b0 ], [ %132, %fp_reload ]
  %118 = phi <2 x double> [ %27, %guest_80002B00_b0 ], [ %140, %fp_reload ]
  %119 = phi <2 x double> [ %61, %guest_80002B00_b0 ], [ %128, %fp_reload ]
  %120 = phi <2 x double> [ %63, %guest_80002B00_b0 ], [ %136, %fp_reload ]
  store i32 %state28.6, ptr %39, align 4
  store <2 x double> %119, ptr %0, align 8
  store <2 x double> %120, ptr %17, align 8
  store double %state2.0, ptr %3, align 8
  store double %state15.0, ptr %20, align 8
  tail call void @ppc_ps_add_op(ptr nonnull %ctx, i8 1, i8 2, i8 3)
  %121 = load double, ptr %0, align 8
  %122 = load double, ptr %17, align 8
  %123 = load i32, ptr %39, align 4
  br label %guest_80002B04_b1

fp_check:                                         ; preds = %guest_80002B00_b0
  store i32 -2147472640, ptr %43, align 4
  %124 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %125 = load i64, ptr %124, align 8
  %126 = add i64 %125, -1
  store i64 %126, ptr %124, align 8
  %127 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472640)
  br i1 %127, label %fp_reload, label %common.ret

fp_reload:                                        ; preds = %fp_check
  %128 = load <2 x double>, ptr %0, align 8
  %129 = load double, ptr %3, align 8
  %130 = load double, ptr %4, align 8
  %131 = load <2 x double>, ptr %6, align 8
  %132 = load <2 x double>, ptr %8, align 8
  %133 = load double, ptr %10, align 8
  %134 = load <2 x double>, ptr %12, align 8
  %135 = load <2 x double>, ptr %15, align 8
  %136 = load <2 x double>, ptr %17, align 8
  %137 = load double, ptr %20, align 8
  %138 = load double, ptr %21, align 8
  %139 = load <2 x double>, ptr %23, align 8
  %140 = load <2 x double>, ptr %26, align 8
  %141 = load double, ptr %28, align 8
  %142 = load <2 x double>, ptr %30, align 8
  %143 = load <2 x double>, ptr %33, align 8
  %144 = load i32, ptr %35, align 4
  %145 = load i32, ptr %37, align 4
  %146 = load i32, ptr %39, align 4
  %147 = load i32, ptr %41, align 4
  br label %fp_ok

fp_ok30:                                          ; preds = %fp_reload32, %guest_80002B04_b1
  %cycles.7 = phi i64 [ %cycles.0, %guest_80002B04_b1 ], [ 0, %fp_reload32 ]
  %state29.6 = phi i32 [ %state29.0, %guest_80002B04_b1 ], [ %187, %fp_reload32 ]
  %state28.7 = phi i32 [ %state28.0, %guest_80002B04_b1 ], [ %186, %fp_reload32 ]
  %state27.7 = phi i32 [ %state27.0, %guest_80002B04_b1 ], [ %185, %fp_reload32 ]
  %state26.7 = phi i32 [ %state26.0, %guest_80002B04_b1 ], [ %184, %fp_reload32 ]
  %state21.2 = phi double [ %state21.0, %guest_80002B04_b1 ], [ %181, %fp_reload32 ]
  %state16.7 = phi double [ %state16.0, %guest_80002B04_b1 ], [ %178, %fp_reload32 ]
  %state13.7 = phi double [ %state13.0, %guest_80002B04_b1 ], [ %177, %fp_reload32 ]
  %state8.2 = phi double [ %state8.0, %guest_80002B04_b1 ], [ %174, %fp_reload32 ]
  %state3.7 = phi double [ %state3.0, %guest_80002B04_b1 ], [ %171, %fp_reload32 ]
  %state.7 = phi double [ %state.0, %guest_80002B04_b1 ], [ %170, %fp_reload32 ]
  %148 = phi <2 x double> [ %64, %guest_80002B04_b1 ], [ %172, %fp_reload32 ]
  %149 = phi <2 x double> [ %65, %guest_80002B04_b1 ], [ %179, %fp_reload32 ]
  %150 = phi <2 x double> [ %66, %guest_80002B04_b1 ], [ %175, %fp_reload32 ]
  %151 = phi <2 x double> [ %67, %guest_80002B04_b1 ], [ %176, %fp_reload32 ]
  %152 = phi <2 x double> [ %68, %guest_80002B04_b1 ], [ %182, %fp_reload32 ]
  %153 = phi <2 x double> [ %69, %guest_80002B04_b1 ], [ %183, %fp_reload32 ]
  %154 = phi <2 x double> [ %70, %guest_80002B04_b1 ], [ %173, %fp_reload32 ]
  %155 = phi <2 x double> [ %71, %guest_80002B04_b1 ], [ %180, %fp_reload32 ]
  store i32 %state28.7, ptr %39, align 4
  store <2 x double> %154, ptr %8, align 8
  store <2 x double> %155, ptr %26, align 8
  store double %state8.2, ptr %10, align 8
  store double %state21.2, ptr %28, align 8
  tail call void @ppc_ps_mul_op(ptr nonnull %ctx, i8 7, i8 8, i8 9)
  %156 = load double, ptr %8, align 8
  %157 = load double, ptr %26, align 8
  %158 = load i32, ptr %39, align 4
  %159 = add nuw nsw i64 %cycles.7, 1
  br label %guest_80002B08_b2

fp_check31:                                       ; preds = %guest_80002B04_b1
  store double %state.0, ptr %0, align 8
  store double %state3.0, ptr %4, align 8
  %160 = extractelement <2 x double> %64, i32 0
  store double %160, ptr %6, align 8
  %161 = extractelement <2 x double> %70, i32 0
  store double %161, ptr %8, align 8
  %162 = extractelement <2 x double> %66, i32 0
  store double %162, ptr %12, align 8
  store double %state13.0, ptr %17, align 8
  store double %state16.0, ptr %21, align 8
  %163 = extractelement <2 x double> %65, i32 0
  store double %163, ptr %23, align 8
  %164 = extractelement <2 x double> %71, i32 0
  store double %164, ptr %26, align 8
  %165 = extractelement <2 x double> %68, i32 0
  store double %165, ptr %30, align 8
  store i32 %state27.0, ptr %37, align 4
  store i32 %state28.0, ptr %39, align 4
  store i32 -2147472636, ptr %43, align 4
  %166 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %167 = load i64, ptr %166, align 8
  %168 = sub i64 %167, %cycles.0
  store i64 %168, ptr %166, align 8
  %169 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472636)
  br i1 %169, label %fp_reload32, label %common.ret

fp_reload32:                                      ; preds = %fp_check31
  %170 = load double, ptr %0, align 8
  %171 = load double, ptr %4, align 8
  %172 = load <2 x double>, ptr %6, align 8
  %173 = load <2 x double>, ptr %8, align 8
  %174 = load double, ptr %10, align 8
  %175 = load <2 x double>, ptr %12, align 8
  %176 = load <2 x double>, ptr %15, align 8
  %177 = load double, ptr %17, align 8
  %178 = load double, ptr %21, align 8
  %179 = load <2 x double>, ptr %23, align 8
  %180 = load <2 x double>, ptr %26, align 8
  %181 = load double, ptr %28, align 8
  %182 = load <2 x double>, ptr %30, align 8
  %183 = load <2 x double>, ptr %33, align 8
  %184 = load i32, ptr %35, align 4
  %185 = load i32, ptr %37, align 4
  %186 = load i32, ptr %39, align 4
  %187 = load i32, ptr %41, align 4
  br label %fp_ok30

fp_ok34:                                          ; preds = %fp_reload36, %guest_80002B08_b2
  %cycles.8 = phi i64 [ %cycles.1, %guest_80002B08_b2 ], [ 0, %fp_reload36 ]
  %state29.7 = phi i32 [ %state29.1, %guest_80002B08_b2 ], [ %225, %fp_reload36 ]
  %state28.8 = phi i32 [ %state28.1, %guest_80002B08_b2 ], [ %224, %fp_reload36 ]
  %state27.8 = phi i32 [ %state27.1, %guest_80002B08_b2 ], [ %223, %fp_reload36 ]
  %state26.8 = phi i32 [ %state26.1, %guest_80002B08_b2 ], [ %222, %fp_reload36 ]
  %state19.8 = phi double [ %state19.1, %guest_80002B08_b2 ], [ %219, %fp_reload36 ]
  %state16.8 = phi double [ %state16.1, %guest_80002B08_b2 ], [ %217, %fp_reload36 ]
  %state13.8 = phi double [ %state13.1, %guest_80002B08_b2 ], [ %216, %fp_reload36 ]
  %state6.8 = phi double [ %state6.1, %guest_80002B08_b2 ], [ %213, %fp_reload36 ]
  %state3.8 = phi double [ %state3.1, %guest_80002B08_b2 ], [ %211, %fp_reload36 ]
  %state.8 = phi double [ %state.1, %guest_80002B08_b2 ], [ %210, %fp_reload36 ]
  %188 = phi <2 x double> [ %76, %guest_80002B08_b2 ], [ %212, %fp_reload36 ]
  %189 = phi <2 x double> [ %77, %guest_80002B08_b2 ], [ %218, %fp_reload36 ]
  %190 = phi <2 x double> [ %78, %guest_80002B08_b2 ], [ %214, %fp_reload36 ]
  %191 = phi <2 x double> [ %79, %guest_80002B08_b2 ], [ %215, %fp_reload36 ]
  %192 = phi <2 x double> [ %80, %guest_80002B08_b2 ], [ %220, %fp_reload36 ]
  %193 = phi <2 x double> [ %81, %guest_80002B08_b2 ], [ %221, %fp_reload36 ]
  store i32 %state28.8, ptr %39, align 4
  store <2 x double> %190, ptr %12, align 8
  store <2 x double> %192, ptr %30, align 8
  store <2 x double> %191, ptr %15, align 8
  store <2 x double> %193, ptr %33, align 8
  tail call void @ppc_ps_madd_op(ptr nonnull %ctx, i8 13, i8 14, i8 15, i8 16, i1 false, i1 false)
  %194 = load double, ptr %12, align 8
  %195 = load double, ptr %30, align 8
  %196 = load i32, ptr %39, align 4
  %197 = add nuw nsw i64 %cycles.8, 1
  %198 = insertelement <2 x double> poison, double %194, i32 0
  %199 = shufflevector <2 x double> %198, <2 x double> %190, <2 x i32> <i32 0, i32 3>
  %200 = insertelement <2 x double> poison, double %195, i32 0
  %201 = shufflevector <2 x double> %200, <2 x double> %192, <2 x i32> <i32 0, i32 3>
  br label %guest_80002B0C_b3

fp_check35:                                       ; preds = %guest_80002B08_b2
  store double %state.1, ptr %0, align 8
  store double %state3.1, ptr %4, align 8
  %202 = extractelement <2 x double> %76, i32 0
  store double %202, ptr %6, align 8
  store double %state6.1, ptr %8, align 8
  %203 = extractelement <2 x double> %78, i32 0
  store double %203, ptr %12, align 8
  store double %state13.1, ptr %17, align 8
  store double %state16.1, ptr %21, align 8
  %204 = extractelement <2 x double> %77, i32 0
  store double %204, ptr %23, align 8
  store double %state19.1, ptr %26, align 8
  %205 = extractelement <2 x double> %80, i32 0
  store double %205, ptr %30, align 8
  store i32 %state27.1, ptr %37, align 4
  store i32 %state28.1, ptr %39, align 4
  store i32 -2147472632, ptr %43, align 4
  %206 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %207 = load i64, ptr %206, align 8
  %208 = sub i64 %207, %cycles.1
  store i64 %208, ptr %206, align 8
  %209 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472632)
  br i1 %209, label %fp_reload36, label %common.ret

fp_reload36:                                      ; preds = %fp_check35
  %210 = load double, ptr %0, align 8
  %211 = load double, ptr %4, align 8
  %212 = load <2 x double>, ptr %6, align 8
  %213 = load double, ptr %8, align 8
  %214 = load <2 x double>, ptr %12, align 8
  %215 = load <2 x double>, ptr %15, align 8
  %216 = load double, ptr %17, align 8
  %217 = load double, ptr %21, align 8
  %218 = load <2 x double>, ptr %23, align 8
  %219 = load double, ptr %26, align 8
  %220 = load <2 x double>, ptr %30, align 8
  %221 = load <2 x double>, ptr %33, align 8
  %222 = load i32, ptr %35, align 4
  %223 = load i32, ptr %37, align 4
  %224 = load i32, ptr %39, align 4
  %225 = load i32, ptr %41, align 4
  br label %fp_ok34

fp_ok38:                                          ; preds = %fp_reload40, %guest_80002B0C_b3
  %cycles.9 = phi i64 [ %cycles.2, %guest_80002B0C_b3 ], [ 0, %fp_reload40 ]
  %state29.8 = phi i32 [ %state29.2, %guest_80002B0C_b3 ], [ %254, %fp_reload40 ]
  %state28.9 = phi i32 [ %state28.2, %guest_80002B0C_b3 ], [ %253, %fp_reload40 ]
  %state27.9 = phi i32 [ %state27.2, %guest_80002B0C_b3 ], [ %252, %fp_reload40 ]
  %state26.9 = phi i32 [ %state26.2, %guest_80002B0C_b3 ], [ %251, %fp_reload40 ]
  %state19.9 = phi double [ %state19.2, %guest_80002B0C_b3 ], [ %249, %fp_reload40 ]
  %state16.9 = phi double [ %state16.2, %guest_80002B0C_b3 ], [ %247, %fp_reload40 ]
  %state13.9 = phi double [ %state13.2, %guest_80002B0C_b3 ], [ %246, %fp_reload40 ]
  %state6.9 = phi double [ %state6.2, %guest_80002B0C_b3 ], [ %244, %fp_reload40 ]
  %state3.9 = phi double [ %state3.2, %guest_80002B0C_b3 ], [ %242, %fp_reload40 ]
  %state.9 = phi double [ %state.2, %guest_80002B0C_b3 ], [ %241, %fp_reload40 ]
  %226 = phi <2 x double> [ %86, %guest_80002B0C_b3 ], [ %245, %fp_reload40 ]
  %227 = phi <2 x double> [ %87, %guest_80002B0C_b3 ], [ %250, %fp_reload40 ]
  %228 = phi <2 x double> [ %88, %guest_80002B0C_b3 ], [ %243, %fp_reload40 ]
  %229 = phi <2 x double> [ %89, %guest_80002B0C_b3 ], [ %248, %fp_reload40 ]
  store i32 %state28.9, ptr %39, align 4
  store <2 x double> %228, ptr %6, align 8
  store <2 x double> %229, ptr %23, align 8
  tail call void @ppc_ps_res_op(ptr nonnull %ctx, i8 5, i8 6)
  %230 = load double, ptr %6, align 8
  %231 = load double, ptr %23, align 8
  %232 = load i32, ptr %39, align 4
  %233 = add nuw nsw i64 %cycles.9, 1
  %234 = extractelement <2 x double> %229, i32 1
  br label %guest_80002B10_b4

fp_check39:                                       ; preds = %guest_80002B0C_b3
  store double %state.2, ptr %0, align 8
  store double %state3.2, ptr %4, align 8
  %235 = extractelement <2 x double> %88, i32 0
  store double %235, ptr %6, align 8
  store double %state6.2, ptr %8, align 8
  store double %state9.2, ptr %12, align 8
  store double %state13.2, ptr %17, align 8
  store double %state16.2, ptr %21, align 8
  %236 = extractelement <2 x double> %89, i32 0
  store double %236, ptr %23, align 8
  store double %state19.2, ptr %26, align 8
  store double %state22.2, ptr %30, align 8
  store i32 %state27.2, ptr %37, align 4
  store i32 %state28.2, ptr %39, align 4
  store i32 -2147472628, ptr %43, align 4
  %237 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %238 = load i64, ptr %237, align 8
  %239 = sub i64 %238, %cycles.2
  store i64 %239, ptr %237, align 8
  %240 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472628)
  br i1 %240, label %fp_reload40, label %common.ret

fp_reload40:                                      ; preds = %fp_check39
  %241 = load double, ptr %0, align 8
  %242 = load double, ptr %4, align 8
  %243 = load <2 x double>, ptr %6, align 8
  %244 = load double, ptr %8, align 8
  %245 = load <2 x double>, ptr %12, align 8
  %246 = load double, ptr %17, align 8
  %247 = load double, ptr %21, align 8
  %248 = load <2 x double>, ptr %23, align 8
  %249 = load double, ptr %26, align 8
  %250 = load <2 x double>, ptr %30, align 8
  %251 = load i32, ptr %35, align 4
  %252 = load i32, ptr %37, align 4
  %253 = load i32, ptr %39, align 4
  %254 = load i32, ptr %41, align 4
  br label %fp_ok38

fp_ok42:                                          ; preds = %fp_reload44, %guest_80002B10_b4
  %cycles.10 = phi i64 [ %cycles.3, %guest_80002B10_b4 ], [ 0, %fp_reload44 ]
  %state29.9 = phi i32 [ %state29.3, %guest_80002B10_b4 ], [ %283, %fp_reload44 ]
  %state28.10 = phi i32 [ %state28.3, %guest_80002B10_b4 ], [ %282, %fp_reload44 ]
  %state27.10 = phi i32 [ %state27.3, %guest_80002B10_b4 ], [ %281, %fp_reload44 ]
  %state26.10 = phi i32 [ %state26.3, %guest_80002B10_b4 ], [ %280, %fp_reload44 ]
  %state19.10 = phi double [ %state19.3, %guest_80002B10_b4 ], [ %278, %fp_reload44 ]
  %state18.9 = phi double [ %state18.3, %guest_80002B10_b4 ], [ %277, %fp_reload44 ]
  %state17.10 = phi double [ %state17.3, %guest_80002B10_b4 ], [ %276, %fp_reload44 ]
  %state16.10 = phi double [ %state16.3, %guest_80002B10_b4 ], [ %275, %fp_reload44 ]
  %state13.10 = phi double [ %state13.3, %guest_80002B10_b4 ], [ %274, %fp_reload44 ]
  %state6.10 = phi double [ %state6.3, %guest_80002B10_b4 ], [ %272, %fp_reload44 ]
  %state4.10 = phi double [ %state4.3, %guest_80002B10_b4 ], [ %271, %fp_reload44 ]
  %state3.10 = phi double [ %state3.3, %guest_80002B10_b4 ], [ %270, %fp_reload44 ]
  %state.10 = phi double [ %state.3, %guest_80002B10_b4 ], [ %269, %fp_reload44 ]
  %255 = phi <2 x double> [ %94, %guest_80002B10_b4 ], [ %273, %fp_reload44 ]
  %256 = phi <2 x double> [ %95, %guest_80002B10_b4 ], [ %279, %fp_reload44 ]
  store i32 %state28.10, ptr %39, align 4
  store i32 %state27.10, ptr %37, align 4
  store <2 x double> %255, ptr %12, align 8
  store <2 x double> %256, ptr %30, align 8
  %257 = extractelement <2 x double> %255, i32 0
  %258 = extractelement <2 x double> %255, i32 1
  tail call void @ppc_fcmp(ptr nonnull %ctx, i8 2, double %257, double %258, i1 false)
  %259 = load i32, ptr %37, align 4
  %260 = load i32, ptr %39, align 4
  %261 = add nuw nsw i64 %cycles.10, 1
  %262 = extractelement <2 x double> %256, i32 0
  br label %guest_80002B14_b5

fp_check43:                                       ; preds = %guest_80002B10_b4
  store double %state.3, ptr %0, align 8
  store double %state3.3, ptr %4, align 8
  store double %state4.3, ptr %6, align 8
  store double %state6.3, ptr %8, align 8
  %263 = extractelement <2 x double> %94, i32 0
  store double %263, ptr %12, align 8
  store double %state13.3, ptr %17, align 8
  store double %state16.3, ptr %21, align 8
  store double %state17.3, ptr %23, align 8
  store double %state19.3, ptr %26, align 8
  %264 = extractelement <2 x double> %95, i32 0
  store double %264, ptr %30, align 8
  store i32 %state27.3, ptr %37, align 4
  store i32 %state28.3, ptr %39, align 4
  store i32 -2147472624, ptr %43, align 4
  %265 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %266 = load i64, ptr %265, align 8
  %267 = sub i64 %266, %cycles.3
  store i64 %267, ptr %265, align 8
  %268 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472624)
  br i1 %268, label %fp_reload44, label %common.ret

fp_reload44:                                      ; preds = %fp_check43
  %269 = load double, ptr %0, align 8
  %270 = load double, ptr %4, align 8
  %271 = load double, ptr %6, align 8
  %272 = load double, ptr %8, align 8
  %273 = load <2 x double>, ptr %12, align 8
  %274 = load double, ptr %17, align 8
  %275 = load double, ptr %21, align 8
  %276 = load double, ptr %23, align 8
  %277 = load double, ptr %24, align 8
  %278 = load double, ptr %26, align 8
  %279 = load <2 x double>, ptr %30, align 8
  %280 = load i32, ptr %35, align 4
  %281 = load i32, ptr %37, align 4
  %282 = load i32, ptr %39, align 4
  %283 = load i32, ptr %41, align 4
  br label %fp_ok42

fp_ok46:                                          ; preds = %fp_reload48, %guest_80002B14_b5
  %cycles.11 = phi i64 [ %cycles.4, %guest_80002B14_b5 ], [ 0, %fp_reload48 ]
  %state28.11 = phi i32 [ %state28.4, %guest_80002B14_b5 ], [ %299, %fp_reload48 ]
  %state27.11 = phi i32 [ %state27.4, %guest_80002B14_b5 ], [ %298, %fp_reload48 ]
  %state26.11 = phi i32 [ %state26.4, %guest_80002B14_b5 ], [ %297, %fp_reload48 ]
  %state22.11 = phi double [ %state22.4, %guest_80002B14_b5 ], [ %296, %fp_reload48 ]
  %state19.11 = phi double [ %state19.4, %guest_80002B14_b5 ], [ %295, %fp_reload48 ]
  %state18.10 = phi double [ %state18.4, %guest_80002B14_b5 ], [ %294, %fp_reload48 ]
  %state17.11 = phi double [ %state17.4, %guest_80002B14_b5 ], [ %293, %fp_reload48 ]
  %state13.11 = phi double [ %state13.4, %guest_80002B14_b5 ], [ %292, %fp_reload48 ]
  %state9.11 = phi double [ %state9.4, %guest_80002B14_b5 ], [ %291, %fp_reload48 ]
  %state6.11 = phi double [ %state6.4, %guest_80002B14_b5 ], [ %290, %fp_reload48 ]
  %state4.11 = phi double [ %state4.4, %guest_80002B14_b5 ], [ %289, %fp_reload48 ]
  %state.11 = phi double [ %state.4, %guest_80002B14_b5 ], [ %288, %fp_reload48 ]
  %.neg = xor i64 %cycles.11, -1
  br label %guest_80002B18_b6

fp_check47:                                       ; preds = %guest_80002B14_b5
  store double %state.4, ptr %0, align 8
  store double %state3.4, ptr %4, align 8
  store double %state4.4, ptr %6, align 8
  store double %state6.4, ptr %8, align 8
  store double %state9.4, ptr %12, align 8
  store double %state13.4, ptr %17, align 8
  store double %state16.4, ptr %21, align 8
  store double %state17.4, ptr %23, align 8
  store double %state19.4, ptr %26, align 8
  store double %state22.4, ptr %30, align 8
  store i32 %state27.4, ptr %37, align 4
  store i32 %state28.4, ptr %39, align 4
  store i32 -2147472620, ptr %43, align 4
  %284 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %285 = load i64, ptr %284, align 8
  %286 = sub i64 %285, %cycles.4
  store i64 %286, ptr %284, align 8
  %287 = tail call i1 @ppc_fp_available(ptr nonnull %ctx, i32 -2147472620)
  br i1 %287, label %fp_reload48, label %common.ret

fp_reload48:                                      ; preds = %fp_check47
  %288 = load double, ptr %0, align 8
  %289 = load double, ptr %6, align 8
  %290 = load double, ptr %8, align 8
  %291 = load double, ptr %12, align 8
  %292 = load double, ptr %17, align 8
  %293 = load double, ptr %23, align 8
  %294 = load double, ptr %24, align 8
  %295 = load double, ptr %26, align 8
  %296 = load double, ptr %30, align 8
  %297 = load i32, ptr %35, align 4
  %298 = load i32, ptr %37, align 4
  %299 = load i32, ptr %39, align 4
  br label %fp_ok46
}

declare void @ppc_ps_add_op(ptr, i8, i8, i8)

declare void @ppc_ps_mul_op(ptr, i8, i8, i8)

declare void @ppc_ps_madd_op(ptr, i8, i8, i8, i8, i1, i1)

declare void @ppc_ps_res_op(ptr, i8, i8)

declare void @ppc_fcmp(ptr, i8, double, double, i1)

define hidden void @func_80002C00(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 652
  %5 = load i32, ptr %4, align 4
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 656
  %7 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %8 = load i32, ptr %7, align 4
  %9 = sub i32 %8, -2147472384
  %10 = tail call i32 @llvm.fshl.i32(i32 %9, i32 %9, i32 30)
  switch i32 %10, label %common.ret [
    i32 0, label %entry.guest_80002C00_b0_crit_edge
    i32 1, label %guest_80002C04_b1
    i32 2, label %guest_80002C08_b2
    i32 3, label %entry.guest_80002C0C_b3_crit_edge
    i32 4, label %entry.guest_80002C10_b4_crit_edge
  ]

entry.guest_80002C10_b4_crit_edge:                ; preds = %entry
  %.phi.trans.insert7 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre8 = load i64, ptr %.phi.trans.insert7, align 8
  br label %guest_80002C10_b4

entry.guest_80002C0C_b3_crit_edge:                ; preds = %entry
  %.phi.trans.insert5 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre6 = load i64, ptr %.phi.trans.insert5, align 8
  br label %guest_80002C0C_b3

entry.guest_80002C00_b0_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  br label %guest_80002C00_b0

guest_80002C00_b0:                                ; preds = %entry.guest_80002C00_b0_crit_edge, %budget_run
  %11 = phi i64 [ %42, %budget_run ], [ %.pre, %entry.guest_80002C00_b0_crit_edge ]
  %cycles.0 = phi i64 [ %cycles.3, %budget_run ], [ 0, %entry.guest_80002C00_b0_crit_edge ]
  %state2.0 = phi i32 [ %state2.3, %budget_run ], [ %5, %entry.guest_80002C00_b0_crit_edge ]
  %state.0 = phi i32 [ %state.3, %budget_run ], [ %1, %entry.guest_80002C00_b0_crit_edge ]
  %.neg = xor i64 %cycles.0, -1
  %12 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %13 = add i64 %11, -1
  store i64 %13, ptr %12, align 8
  %14 = add i32 %state.0, 1
  br label %guest_80002C04_b1

guest_80002C04_b1:                                ; preds = %guest_80002C00_b0, %entry
  %cycles.1.neg = phi i64 [ %.neg, %guest_80002C00_b0 ], [ 0, %entry ]
  %state2.1 = phi i32 [ %state2.0, %guest_80002C00_b0 ], [ %5, %entry ]
  %state.1 = phi i32 [ %14, %guest_80002C00_b0 ], [ %1, %entry ]
  store i32 %state.1, ptr %0, align 4
  store i32 %state2.1, ptr %4, align 4
  store i32 -2147472380, ptr %7, align 4
  %15 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %16 = load i64, ptr %15, align 8
  %17 = add i64 %cycles.1.neg, %16
  store i64 %17, ptr %15, align 8
  tail call void @ppc_fallback_instruction(ptr nonnull %ctx, i32 0, i32 -2147472380)
  %18 = load i32, ptr %7, align 4
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %20 = load i32, ptr %19, align 4
  %21 = icmp eq i32 %20, 0
  %22 = icmp eq i32 %18, -2147472376
  %23 = and i1 %22, %21
  br i1 %23, label %fallback_resume, label %common.ret

guest_80002C08_b2:                                ; preds = %fallback_resume, %entry
  %state2.2 = phi i32 [ %52, %fallback_resume ], [ %5, %entry ]
  %state1.0 = phi i32 [ %51, %fallback_resume ], [ %3, %entry ]
  %state.2 = phi i32 [ %50, %fallback_resume ], [ %1, %entry ]
  %state3.0 = load i32, ptr %6, align 4
  %24 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %25 = load i64, ptr %24, align 8
  %26 = add i64 %25, -1
  %27 = icmp slt i32 %state.2, 10000
  %28 = icmp sgt i32 %state.2, 10000
  %29 = icmp eq i32 %state.2, 10000
  %30 = select i1 %27, i32 8, i32 10000
  %31 = select i1 %28, i32 4, i32 10000
  %32 = or i32 %30, %31
  %33 = select i1 %29, i32 2, i32 10000
  %34 = or i32 %32, %33
  %35 = lshr i32 %state3.0, 31
  %36 = or disjoint i32 %34, %35
  %37 = shl i32 %36, 28
  %38 = and i32 %state2.2, 268435455
  %39 = or disjoint i32 %38, %37
  br label %guest_80002C0C_b3

guest_80002C0C_b3:                                ; preds = %entry.guest_80002C0C_b3_crit_edge, %guest_80002C08_b2
  %40 = phi i64 [ %.pre6, %entry.guest_80002C0C_b3_crit_edge ], [ %26, %guest_80002C08_b2 ]
  %cycles.3 = phi i64 [ 1, %entry.guest_80002C0C_b3_crit_edge ], [ 2, %guest_80002C08_b2 ]
  %state2.3 = phi i32 [ %5, %entry.guest_80002C0C_b3_crit_edge ], [ %39, %guest_80002C08_b2 ]
  %state1.1 = phi i32 [ %3, %entry.guest_80002C0C_b3_crit_edge ], [ %state1.0, %guest_80002C08_b2 ]
  %state.3 = phi i32 [ %1, %entry.guest_80002C0C_b3_crit_edge ], [ %state.2, %guest_80002C08_b2 ]
  %41 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %42 = add i64 %40, -1
  store i64 %42, ptr %41, align 8
  %.not = icmp sgt i32 %state2.3, -1
  br i1 %.not, label %guest_80002C10_b4, label %cycle_guard

guest_80002C10_b4:                                ; preds = %entry.guest_80002C10_b4_crit_edge, %guest_80002C0C_b3
  %43 = phi i64 [ %.pre8, %entry.guest_80002C10_b4_crit_edge ], [ %42, %guest_80002C0C_b3 ]
  %cycles.4 = phi i64 [ 0, %entry.guest_80002C10_b4_crit_edge ], [ %cycles.3, %guest_80002C0C_b3 ]
  %state2.4 = phi i32 [ %5, %entry.guest_80002C10_b4_crit_edge ], [ %state2.3, %guest_80002C0C_b3 ]
  %state1.2 = phi i32 [ %3, %entry.guest_80002C10_b4_crit_edge ], [ %state1.1, %guest_80002C0C_b3 ]
  %state.4 = phi i32 [ %1, %entry.guest_80002C10_b4_crit_edge ], [ %state.3, %guest_80002C0C_b3 ]
  %44 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %45 = add i64 %43, -1
  store i64 %45, ptr %44, align 8
  %46 = and i32 %state1.2, -4
  %.neg4 = xor i64 %cycles.4, -1
  store i32 %state.4, ptr %0, align 4
  store i32 %state2.4, ptr %4, align 4
  store i32 %46, ptr %7, align 4
  %47 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %48 = load i64, ptr %47, align 8
  %49 = add i64 %48, %.neg4
  store i64 %49, ptr %47, align 8
  br label %common.ret

common.ret:                                       ; preds = %guest_80002C04_b1, %entry, %guest_80002C10_b4, %budget_exit
  ret void

fallback_resume:                                  ; preds = %guest_80002C04_b1
  %50 = load i32, ptr %0, align 4
  %51 = load i32, ptr %2, align 4
  %52 = load i32, ptr %4, align 4
  br label %guest_80002C08_b2

cycle_guard:                                      ; preds = %guest_80002C0C_b3
  %53 = getelementptr inbounds nuw i8, ptr %ctx, i64 3512
  %54 = load i32, ptr %53, align 4
  %55 = icmp slt i64 %42, 1
  %56 = icmp eq i32 %54, 0
  %57 = or i1 %55, %56
  br i1 %57, label %budget_exit, label %budget_run

budget_run:                                       ; preds = %cycle_guard
  %58 = add i32 %54, -1
  store i32 %58, ptr %53, align 4
  br label %guest_80002C00_b0

budget_exit:                                      ; preds = %cycle_guard
  store i32 %state.3, ptr %0, align 4
  store i32 %state2.3, ptr %4, align 4
  store i32 -2147472384, ptr %7, align 4
  %59 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %60 = load i64, ptr %59, align 8
  %61 = sub i64 %60, %cycles.3
  store i64 %61, ptr %59, align 8
  br label %common.ret
}

define hidden void @func_80002D00(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 16
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %5 = load i32, ptr %4, align 4
  %6 = getelementptr inbounds nuw i8, ptr %ctx, i64 652
  %7 = load i32, ptr %6, align 4
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 656
  %9 = load i32, ptr %8, align 4
  %10 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %11 = load i32, ptr %10, align 4
  %12 = sub i32 %11, -2147472128
  %13 = tail call i32 @llvm.fshl.i32(i32 %12, i32 %12, i32 30)
  switch i32 %13, label %common.ret [
    i32 0, label %entry.guest_80002D00_b0_crit_edge
    i32 1, label %guest_80002D04_b1
    i32 2, label %entry.guest_80002D08_b2_crit_edge
    i32 3, label %entry.guest_80002D0C_b3_crit_edge
  ]

entry.guest_80002D0C_b3_crit_edge:                ; preds = %entry
  %.phi.trans.insert8 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre9 = load i64, ptr %.phi.trans.insert8, align 8
  br label %guest_80002D0C_b3

entry.guest_80002D08_b2_crit_edge:                ; preds = %entry
  %.phi.trans.insert6 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre7 = load i64, ptr %.phi.trans.insert6, align 8
  br label %guest_80002D08_b2

entry.guest_80002D00_b0_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  br label %guest_80002D00_b0

guest_80002D00_b0:                                ; preds = %entry.guest_80002D00_b0_crit_edge, %budget_run
  %14 = phi i64 [ %44, %budget_run ], [ %.pre, %entry.guest_80002D00_b0_crit_edge ]
  %cycles.0 = phi i64 [ %cycles.2, %budget_run ], [ 0, %entry.guest_80002D00_b0_crit_edge ]
  %state4.0 = phi i32 [ %state4.2, %budget_run ], [ %9, %entry.guest_80002D00_b0_crit_edge ]
  %state3.0 = phi i32 [ %state3.2, %budget_run ], [ %7, %entry.guest_80002D00_b0_crit_edge ]
  %state2.0 = phi i32 [ %state2.2, %budget_run ], [ %5, %entry.guest_80002D00_b0_crit_edge ]
  %state1.0 = phi i32 [ %state1.2, %budget_run ], [ %3, %entry.guest_80002D00_b0_crit_edge ]
  %state.0 = phi i32 [ %state.2, %budget_run ], [ %1, %entry.guest_80002D00_b0_crit_edge ]
  %15 = add i64 %cycles.0, 1
  %16 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %17 = add i64 %14, -1
  store i64 %17, ptr %16, align 8
  %18 = and i32 %state.0, -1073741825
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 3464
  %20 = load i32, ptr %19, align 4
  %21 = xor i32 %18, -2147483648
  %22 = icmp ugt i32 %20, 3
  %23 = add i32 %20, -4
  %24 = icmp ule i32 %21, %23
  %25 = and i1 %22, %24
  br i1 %25, label %load_mem1, label %load_check_mem2

guest_80002D04_b1:                                ; preds = %load_join, %entry
  %cycles.1 = phi i64 [ %77, %load_join ], [ 2, %entry ]
  %state4.1 = phi i32 [ %state4.3, %load_join ], [ %9, %entry ]
  %state3.1 = phi i32 [ %state3.4, %load_join ], [ %7, %entry ]
  %state2.1 = phi i32 [ %state2.4, %load_join ], [ %5, %entry ]
  %state1.1 = phi i32 [ %76, %load_join ], [ %3, %entry ]
  %state.1 = phi i32 [ %state.3, %load_join ], [ %1, %entry ]
  %26 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %27 = load i64, ptr %26, align 8
  %28 = add i64 %27, -1
  %29 = icmp sgt i32 %state1.1, 0
  %30 = icmp eq i32 %state1.1, 0
  %31 = lshr i32 %state1.1, 28
  %32 = and i32 %31, 8
  %33 = select i1 %29, i32 4, i32 0
  %34 = or disjoint i32 %32, %33
  %35 = select i1 %30, i32 2, i32 0
  %36 = or disjoint i32 %34, %35
  %37 = lshr i32 %state4.1, 31
  %38 = or disjoint i32 %36, %37
  %39 = shl nuw i32 %38, 28
  %40 = and i32 %state3.1, 268435455
  %41 = or disjoint i32 %40, %39
  br label %guest_80002D08_b2

guest_80002D08_b2:                                ; preds = %entry.guest_80002D08_b2_crit_edge, %guest_80002D04_b1
  %42 = phi i64 [ %.pre7, %entry.guest_80002D08_b2_crit_edge ], [ %28, %guest_80002D04_b1 ]
  %cycles.2 = phi i64 [ 1, %entry.guest_80002D08_b2_crit_edge ], [ %cycles.1, %guest_80002D04_b1 ]
  %state4.2 = phi i32 [ %9, %entry.guest_80002D08_b2_crit_edge ], [ %state4.1, %guest_80002D04_b1 ]
  %state3.2 = phi i32 [ %7, %entry.guest_80002D08_b2_crit_edge ], [ %41, %guest_80002D04_b1 ]
  %state2.2 = phi i32 [ %5, %entry.guest_80002D08_b2_crit_edge ], [ %state2.1, %guest_80002D04_b1 ]
  %state1.2 = phi i32 [ %3, %entry.guest_80002D08_b2_crit_edge ], [ %state1.1, %guest_80002D04_b1 ]
  %state.2 = phi i32 [ %1, %entry.guest_80002D08_b2_crit_edge ], [ %state.1, %guest_80002D04_b1 ]
  %43 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %44 = add i64 %42, -1
  store i64 %44, ptr %43, align 8
  %45 = and i32 %state3.2, 536870912
  %.not5 = icmp eq i32 %45, 0
  br i1 %.not5, label %guest_80002D0C_b3, label %cycle_guard

guest_80002D0C_b3:                                ; preds = %entry.guest_80002D0C_b3_crit_edge, %guest_80002D08_b2
  %46 = phi i64 [ %.pre9, %entry.guest_80002D0C_b3_crit_edge ], [ %44, %guest_80002D08_b2 ]
  %cycles.3 = phi i64 [ 0, %entry.guest_80002D0C_b3_crit_edge ], [ %cycles.2, %guest_80002D08_b2 ]
  %state3.3 = phi i32 [ %7, %entry.guest_80002D0C_b3_crit_edge ], [ %state3.2, %guest_80002D08_b2 ]
  %state2.3 = phi i32 [ %5, %entry.guest_80002D0C_b3_crit_edge ], [ %state2.2, %guest_80002D08_b2 ]
  %state1.3 = phi i32 [ %3, %entry.guest_80002D0C_b3_crit_edge ], [ %state1.2, %guest_80002D08_b2 ]
  %47 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %48 = add i64 %46, -1
  store i64 %48, ptr %47, align 8
  %49 = and i32 %state2.3, -4
  %.neg = xor i64 %cycles.3, -1
  store i32 %state1.3, ptr %2, align 4
  store i32 %state3.3, ptr %6, align 4
  store i32 %49, ptr %10, align 4
  %50 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %51 = load i64, ptr %50, align 8
  %52 = add i64 %51, %.neg
  store i64 %52, ptr %50, align 8
  br label %common.ret

common.ret:                                       ; preds = %read_external, %entry, %guest_80002D0C_b3, %budget_exit
  ret void

load_mem1:                                        ; preds = %guest_80002D00_b0
  %53 = getelementptr inbounds nuw i8, ptr %ctx, i64 3456
  %54 = load ptr, ptr %53, align 8
  %55 = sext i32 %21 to i64
  %56 = getelementptr inbounds i8, ptr %54, i64 %55
  %57 = load i32, ptr %56, align 4
  %58 = tail call i32 @llvm.bswap.i32(i32 %57)
  br label %load_join

load_check_mem2:                                  ; preds = %guest_80002D00_b0
  %59 = getelementptr inbounds nuw i8, ptr %ctx, i64 3496
  %60 = load i32, ptr %59, align 4
  %61 = getelementptr inbounds nuw i8, ptr %ctx, i64 3488
  %62 = load ptr, ptr %61, align 8
  %63 = add i32 %18, 1879048192
  %64 = icmp ugt i32 %60, 3
  %65 = add i32 %60, -4
  %66 = icmp ule i32 %63, %65
  %67 = and i1 %64, %66
  %68 = icmp ne ptr %62, null
  %69 = and i1 %68, %67
  br i1 %69, label %load_mem2, label %load_slow

load_mem2:                                        ; preds = %load_check_mem2
  %70 = sext i32 %63 to i64
  %71 = getelementptr inbounds i8, ptr %62, i64 %70
  %72 = load i32, ptr %71, align 4
  %73 = tail call i32 @llvm.bswap.i32(i32 %72)
  br label %load_join

load_slow:                                        ; preds = %load_check_mem2
  %74 = getelementptr inbounds nuw i8, ptr %ctx, i64 3400
  %75 = load ptr, ptr %74, align 8
  %.not = icmp eq ptr %75, null
  br i1 %.not, label %load_join, label %read_external

load_join:                                        ; preds = %read_slow_resume, %load_slow, %load_mem2, %load_mem1
  %cycles.4 = phi i64 [ %15, %load_mem1 ], [ %15, %load_mem2 ], [ 0, %read_slow_resume ], [ %15, %load_slow ]
  %state4.3 = phi i32 [ %state4.0, %load_mem1 ], [ %state4.0, %load_mem2 ], [ %88, %read_slow_resume ], [ %state4.0, %load_slow ]
  %state3.4 = phi i32 [ %state3.0, %load_mem1 ], [ %state3.0, %load_mem2 ], [ %87, %read_slow_resume ], [ %state3.0, %load_slow ]
  %state2.4 = phi i32 [ %state2.0, %load_mem1 ], [ %state2.0, %load_mem2 ], [ %86, %read_slow_resume ], [ %state2.0, %load_slow ]
  %state.3 = phi i32 [ %state.0, %load_mem1 ], [ %state.0, %load_mem2 ], [ %85, %read_slow_resume ], [ %state.0, %load_slow ]
  %76 = phi i32 [ %58, %load_mem1 ], [ %73, %load_mem2 ], [ %89, %read_slow_resume ], [ 0, %load_slow ]
  %77 = add i64 %cycles.4, 2
  br label %guest_80002D04_b1

read_external:                                    ; preds = %load_slow
  store i32 %state1.0, ptr %2, align 4
  store i32 %state3.0, ptr %6, align 4
  store i32 -2147472128, ptr %10, align 4
  %78 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %79 = load i64, ptr %78, align 8
  %80 = sub i64 %79, %15
  store i64 %80, ptr %78, align 8
  %81 = tail call i64 %75(ptr nonnull %ctx, i32 %state.0, i8 4)
  %82 = getelementptr inbounds nuw i8, ptr %ctx, i64 800
  %83 = load i32, ptr %82, align 4
  %84 = icmp eq i32 %83, 0
  br i1 %84, label %read_slow_resume, label %common.ret

read_slow_resume:                                 ; preds = %read_external
  %85 = load i32, ptr %0, align 4
  %86 = load i32, ptr %4, align 4
  %87 = load i32, ptr %6, align 4
  %88 = load i32, ptr %8, align 4
  %89 = trunc i64 %81 to i32
  br label %load_join

cycle_guard:                                      ; preds = %guest_80002D08_b2
  %90 = getelementptr inbounds nuw i8, ptr %ctx, i64 3512
  %91 = load i32, ptr %90, align 4
  %92 = icmp slt i64 %44, 1
  %93 = icmp eq i32 %91, 0
  %94 = or i1 %92, %93
  br i1 %94, label %budget_exit, label %budget_run

budget_run:                                       ; preds = %cycle_guard
  %95 = add i32 %91, -1
  store i32 %95, ptr %90, align 4
  br label %guest_80002D00_b0

budget_exit:                                      ; preds = %cycle_guard
  store i32 %state1.2, ptr %2, align 4
  store i32 %state3.2, ptr %6, align 4
  store i32 -2147472128, ptr %10, align 4
  %96 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %97 = load i64, ptr %96, align 8
  %98 = sub i64 %97, %cycles.2
  store i64 %98, ptr %96, align 8
  br label %common.ret
}

define hidden void @func_80002E00(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 644
  %3 = load i32, ptr %2, align 4
  %4 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %5 = load i32, ptr %4, align 4
  %6 = sub i32 %5, -2147471872
  %7 = tail call i32 @llvm.fshl.i32(i32 %6, i32 %6, i32 30)
  switch i32 %7, label %common.ret [
    i32 0, label %guest_80002E00_b0
    i32 1, label %entry.guest_80002E04_b1_crit_edge
    i32 2, label %entry.guest_80002E08_b2_crit_edge
    i32 3, label %entry.guest_80002E0C_b3_crit_edge
  ]

entry.guest_80002E04_b1_crit_edge:                ; preds = %entry
  %.phi.trans.insert4 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre5 = load i64, ptr %.phi.trans.insert4, align 8
  br label %guest_80002E04_b1

entry.guest_80002E0C_b3_crit_edge:                ; preds = %entry
  %.phi.trans.insert2 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre3 = load i64, ptr %.phi.trans.insert2, align 8
  br label %guest_80002E0C_b3

entry.guest_80002E08_b2_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  br label %guest_80002E08_b2

guest_80002E00_b0:                                ; preds = %entry
  %8 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %9 = load i64, ptr %8, align 8
  %10 = add i64 %9, -1
  br label %guest_80002E08_b2

guest_80002E04_b1:                                ; preds = %entry.guest_80002E04_b1_crit_edge, %budget_run
  %11 = phi i64 [ %20, %budget_run ], [ %.pre5, %entry.guest_80002E04_b1_crit_edge ]
  %cycles.0 = phi i64 [ %31, %budget_run ], [ 1, %entry.guest_80002E04_b1_crit_edge ]
  %state1.0 = phi i32 [ %state1.2, %budget_run ], [ %3, %entry.guest_80002E04_b1_crit_edge ]
  %state.0 = phi i32 [ %state.2, %budget_run ], [ %1, %entry.guest_80002E04_b1_crit_edge ]
  %12 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %13 = add i64 %11, -1
  store i64 %13, ptr %12, align 8
  br label %guest_80002E08_b2

guest_80002E08_b2:                                ; preds = %entry.guest_80002E08_b2_crit_edge, %guest_80002E04_b1, %guest_80002E00_b0
  %14 = phi i64 [ %13, %guest_80002E04_b1 ], [ %.pre, %entry.guest_80002E08_b2_crit_edge ], [ %10, %guest_80002E00_b0 ]
  %cycles.1 = phi i64 [ %cycles.0, %guest_80002E04_b1 ], [ 0, %entry.guest_80002E08_b2_crit_edge ], [ 1, %guest_80002E00_b0 ]
  %state1.1 = phi i32 [ %state1.0, %guest_80002E04_b1 ], [ %3, %entry.guest_80002E08_b2_crit_edge ], [ -2147471868, %guest_80002E00_b0 ]
  %state.1 = phi i32 [ %state.0, %guest_80002E04_b1 ], [ %1, %entry.guest_80002E08_b2_crit_edge ], [ %1, %guest_80002E00_b0 ]
  %15 = add i64 %14, -1
  %16 = add i32 %state.1, 1
  %17 = add i64 %cycles.1, 2
  br label %guest_80002E0C_b3

guest_80002E0C_b3:                                ; preds = %entry.guest_80002E0C_b3_crit_edge, %guest_80002E08_b2
  %18 = phi i64 [ %.pre3, %entry.guest_80002E0C_b3_crit_edge ], [ %15, %guest_80002E08_b2 ]
  %cycles.2 = phi i64 [ 1, %entry.guest_80002E0C_b3_crit_edge ], [ %17, %guest_80002E08_b2 ]
  %state1.2 = phi i32 [ %3, %entry.guest_80002E0C_b3_crit_edge ], [ %state1.1, %guest_80002E08_b2 ]
  %state.2 = phi i32 [ %1, %entry.guest_80002E0C_b3_crit_edge ], [ %16, %guest_80002E08_b2 ]
  %19 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %20 = add i64 %18, -1
  store i64 %20, ptr %19, align 8
  %21 = and i32 %state1.2, -4
  %cond = icmp eq i32 %21, -2147471868
  br i1 %cond, label %cycle_guard, label %indirect_exit

common.ret:                                       ; preds = %entry, %budget_exit, %indirect_exit
  ret void

indirect_exit:                                    ; preds = %guest_80002E0C_b3
  store i32 %state.2, ptr %0, align 4
  store i32 %state1.2, ptr %2, align 4
  store i32 %21, ptr %4, align 4
  %22 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %23 = load i64, ptr %22, align 8
  %24 = sub i64 %23, %cycles.2
  store i64 %24, ptr %22, align 8
  br label %common.ret

cycle_guard:                                      ; preds = %guest_80002E0C_b3
  %25 = getelementptr inbounds nuw i8, ptr %ctx, i64 3512
  %26 = load i32, ptr %25, align 4
  %27 = icmp slt i64 %20, 1
  %28 = icmp eq i32 %26, 0
  %29 = or i1 %27, %28
  br i1 %29, label %budget_exit, label %budget_run

budget_run:                                       ; preds = %cycle_guard
  %30 = add i32 %26, -1
  store i32 %30, ptr %25, align 4
  %31 = add i64 %cycles.2, 1
  br label %guest_80002E04_b1

budget_exit:                                      ; preds = %cycle_guard
  store i32 %state.2, ptr %0, align 4
  store i32 %state1.2, ptr %2, align 4
  store i32 -2147471868, ptr %4, align 4
  %32 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %33 = load i64, ptr %32, align 8
  %34 = sub i64 %33, %cycles.2
  store i64 %34, ptr %32, align 8
  br label %common.ret
}

define hidden void @func_80003100(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %1 = load i32, ptr %0, align 4
  %cond = icmp eq i32 %1, -2147471104
  br i1 %cond, label %guest_80003100_b0, label %common.ret

guest_80003100_b0:                                ; preds = %entry
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %3 = load i64, ptr %2, align 8
  %4 = add i64 %3, -1
  store i64 %4, ptr %2, align 8
  store i32 -2147470848, ptr %0, align 4
  %5 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %6 = load i64, ptr %5, align 8
  %7 = add i64 %6, -1
  store i64 %7, ptr %5, align 8
  br label %common.ret

common.ret:                                       ; preds = %entry, %guest_80003100_b0
  ret void
}

define hidden void @func_80003200(ptr %ctx) {
entry:
  %0 = getelementptr inbounds nuw i8, ptr %ctx, i64 12
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr inbounds nuw i8, ptr %ctx, i64 640
  %3 = load i32, ptr %2, align 4
  switch i32 %3, label %common.ret [
    i32 -2147470848, label %entry.guest_80003200_b0_crit_edge
    i32 -2147470844, label %entry.guest_80003204_b1_crit_edge
  ]

entry.guest_80003204_b1_crit_edge:                ; preds = %entry
  %.phi.trans.insert1 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre2 = load i64, ptr %.phi.trans.insert1, align 8
  br label %guest_80003204_b1

entry.guest_80003200_b0_crit_edge:                ; preds = %entry
  %.phi.trans.insert = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %.pre = load i64, ptr %.phi.trans.insert, align 8
  br label %guest_80003200_b0

guest_80003200_b0:                                ; preds = %entry.guest_80003200_b0_crit_edge, %budget_run
  %4 = phi i64 [ %10, %budget_run ], [ %.pre, %entry.guest_80003200_b0_crit_edge ]
  %cycles.0 = phi i64 [ %cycles.1, %budget_run ], [ 0, %entry.guest_80003200_b0_crit_edge ]
  %state.0 = phi i32 [ %state.1, %budget_run ], [ %1, %entry.guest_80003200_b0_crit_edge ]
  %5 = add i64 %4, -1
  %6 = add i32 %state.0, 1
  %7 = add i64 %cycles.0, 2
  br label %guest_80003204_b1

guest_80003204_b1:                                ; preds = %entry.guest_80003204_b1_crit_edge, %guest_80003200_b0
  %8 = phi i64 [ %.pre2, %entry.guest_80003204_b1_crit_edge ], [ %5, %guest_80003200_b0 ]
  %cycles.1 = phi i64 [ 1, %entry.guest_80003204_b1_crit_edge ], [ %7, %guest_80003200_b0 ]
  %state.1 = phi i32 [ %1, %entry.guest_80003204_b1_crit_edge ], [ %6, %guest_80003200_b0 ]
  %9 = getelementptr inbounds nuw i8, ptr %ctx, i64 3504
  %10 = add i64 %8, -1
  store i64 %10, ptr %9, align 8
  %11 = getelementptr inbounds nuw i8, ptr %ctx, i64 3512
  %12 = load i32, ptr %11, align 4
  %13 = icmp slt i64 %10, 1
  %14 = icmp eq i32 %12, 0
  %15 = or i1 %13, %14
  br i1 %15, label %budget_exit, label %budget_run

common.ret:                                       ; preds = %entry, %budget_exit
  ret void

budget_run:                                       ; preds = %guest_80003204_b1
  %16 = add i32 %12, -1
  store i32 %16, ptr %11, align 4
  br label %guest_80003200_b0

budget_exit:                                      ; preds = %guest_80003204_b1
  store i32 %state.1, ptr %0, align 4
  store i32 -2147470848, ptr %2, align 4
  %17 = getelementptr inbounds nuw i8, ptr %ctx, i64 3480
  %18 = load i64, ptr %17, align 8
  %19 = sub i64 %18, %cycles.1
  store i64 %19, ptr %17, align 8
  br label %common.ret
}

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.fshl.i32(i32, i32, i32) #0

attributes #0 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
