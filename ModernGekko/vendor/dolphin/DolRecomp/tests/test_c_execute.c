#include <stdio.h>

#include "../src/cpu/cpu.h"

void func_80004020(CPUState* ctx);
void func_80004040(CPUState* ctx);

int main(void) {
    CPUState cpu;
    if (!cpu_init(&cpu))
        return 1;

    cpu.pc = 0x80004020u;
    cpu.lr = 0x81234564u;
    cpu.gpr[3] = 1000;

    u32 calls = 0;
    while (cpu.pc != cpu.lr && calls < 32) {
        cpu.downcount = 0;
        func_80004020(&cpu);
        calls++;
    }

    int integer_ok = cpu.pc == cpu.lr && cpu.gpr[3] == 0 &&
                     (cpu.cr & 0xF0000000u) == 0x20000000u && calls < 20;
    if (!integer_ok) {
        fprintf(stderr, "pc=%08X r3=%u cr=%08X calls=%u\n",
                cpu.pc, cpu.gpr[3], cpu.cr, calls);
    }
    for (u32 i = 0; i < 1000; ++i)
        mem_write32(&cpu, 0x80001000u + i * 4u, i);
    cpu.pc = 0x80004040u;
    cpu.lr = 0x81234564u;
    cpu.gpr[3] = 1000;
    cpu.gpr[5] = 0x80001000u;
    calls = 0;
    while (cpu.pc != cpu.lr && calls < 32) {
        cpu.downcount = 0;
        func_80004040(&cpu);
        calls++;
    }
    int memory_ok = cpu.pc == cpu.lr && cpu.gpr[3] == 0 &&
                    cpu.gpr[4] == 999 && cpu.gpr[5] == 0x80001FA0u &&
                    calls < 24;
    if (!memory_ok) {
        fprintf(stderr, "memory pc=%08X r3=%u r4=%u r5=%08X calls=%u\n",
                cpu.pc, cpu.gpr[3], cpu.gpr[4], cpu.gpr[5], calls);
    }

    cpu_free(&cpu);
    return !(integer_ok && memory_ok);
}
