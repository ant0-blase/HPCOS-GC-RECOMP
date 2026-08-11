#include "cpu/cpu.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func_80003100(CPUState* cpu);

static double seconds(void) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (double)now.tv_sec + (double)now.tv_nsec * 1e-9;
}

int main(int argc, char** argv) {
    u32 iterations = argc > 1 ? (u32)strtoul(argv[1], NULL, 0) : 5000000u;
    CPUState cpu;
    if (!cpu_init(&cpu))
        return 1;
    volatile u64 checksum = 0;
    double begin = seconds();
    for (u32 i = 0; i < iterations; i++) {
        cpu.pc = 0x80003100u;
        cpu.lr = 0x81234567u;
        cpu.ctr = 200;
        cpu.downcount = 1000;
        do {
            func_80003100(&cpu);
        } while (cpu.pc != 0x81234564u);
        checksum += cpu.gpr[3];
    }
    double elapsed = seconds() - begin;
    printf("iterations=%u seconds=%.6f ns_per_iteration=%.2f checksum=%llu\n",
           iterations, elapsed, elapsed * 1e9 / iterations,
           (unsigned long long)checksum);
    cpu_free(&cpu);
    return checksum == (u64)iterations * 200u ? 0 : 2;
}
