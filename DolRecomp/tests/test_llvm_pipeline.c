#include "common/types.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#if defined(_WIN32)
#include <direct.h>
#include <process.h>
#else
#include <sys/wait.h>
#include <unistd.h>
#endif

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "check failed: %s:%d: %s\n", \
    __FILE__, __LINE__, #x); return 1; } } while (0)

static int make_dir(const char* path) {
#if defined(_WIN32)
    return _mkdir(path) == 0 || errno == EEXIST;
#else
    return mkdir(path, 0777) == 0 || errno == EEXIST;
#endif
}

// The emitted object format follows the default target triple, so this cannot
// assume ELF: a Windows host produces COFF, whose x86-64 objects start with the
// machine type IMAGE_FILE_MACHINE_AMD64 (0x8664) stored little-endian.
static int is_native_object(const u8* magic) {
#if defined(_WIN32)
    return magic[0] == 0x64 && magic[1] == 0x86;
#else
    return magic[0] == 0x7F && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F';
#endif
}

static int write_dol(const char* path) {
    u8 bytes[0x1100];
    memset(bytes, 0, sizeof(bytes));
    write_be32(bytes + 0x00, 0x100);
    write_be32(bytes + 0x48, 0x80003100u);
    write_be32(bytes + 0x90, 0x1000);
    write_be32(bytes + 0xE0, 0x80003100u);
    for (size_t offset = 0x100; offset < sizeof(bytes); offset += 4)
        write_be32(bytes + offset, 0x60000000u);
    write_be32(bytes + 0x100, 0x38600000u);
    write_be32(bytes + 0x104, 0x38630001u);
    write_be32(bytes + 0x108, 0x4200FFFCu);
    write_be32(bytes + 0x10C, 0x4E800020u);
    write_be32(bytes + 0x110, 0x60000000u);
    write_be32(bytes + 0x114, 0x60000000u);
    write_be32(bytes + 0x118, 0x60000000u);
    write_be32(bytes + 0x11C, 0x60000000u);
    FILE* file = fopen(path, "wb");
    if (!file)
        return 0;
    int ok = fwrite(bytes, 1, sizeof(bytes), file) == sizeof(bytes);
    return fclose(file) == 0 && ok;
}

int main(int argc, char** argv) {
    CHECK(argc == 3);
    CHECK(make_dir(argv[2]));
    char dol[1200];
    char output[1200];
    char header[1200];
    char object[1200];
    char second_object[1200];
    snprintf(dol, sizeof(dol), "%s/sample.dol", argv[2]);
    snprintf(output, sizeof(output), "%s/out", argv[2]);
    snprintf(header, sizeof(header), "%s/out/generated/generated.h", argv[2]);
    snprintf(object, sizeof(object),
             "%s/out/generated/chunks/chunk_0000_text0_80003100.o", argv[2]);
    snprintf(second_object, sizeof(second_object),
             "%s/out/generated/chunks/chunk_0001_text0_80003900.o", argv[2]);
    CHECK(write_dol(dol));
#if defined(_WIN32)
    // Windows has no fork. _spawnl with _P_WAIT runs the child to completion and
    // returns its exit status directly, and the child inherits this process's
    // environment, so the chunk-size override is set here rather than between
    // fork and exec.
    CHECK(_putenv_s("DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS", "512") == 0);
    CHECK(_spawnl(_P_WAIT, argv[1], argv[1], "--gamecube", "--backend=llvm",
                  "-j2", dol, output, NULL) == 0);
#else
    pid_t child = fork();
    CHECK(child >= 0);
    if (child == 0) {
        setenv("DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS", "512", 1);
        execl(argv[1], argv[1], "--gamecube", "--backend=llvm", "-j2", dol,
              output, NULL);
        _exit(127);
    }
    int status = 0;
    CHECK(waitpid(child, &status, 0) == child);
    CHECK(WIFEXITED(status) && WEXITSTATUS(status) == 0);
#endif
    FILE* file = fopen(header, "rb");
    CHECK(file != NULL);
    char text[4096];
    size_t length = fread(text, 1, sizeof(text) - 1, file);
    text[length] = '\0';
    fclose(file);
    CHECK(strstr(text, "DOLRECOMP_BACKEND_LLVM") != NULL);
    file = fopen(object, "rb");
    CHECK(file != NULL);
    u8 magic[4];
    CHECK(fread(magic, 1, 4, file) == 4);
    fclose(file);
    CHECK(is_native_object(magic));
    file = fopen(second_object, "rb");
    CHECK(file != NULL);
    CHECK(fread(magic, 1, 4, file) == 4);
    fclose(file);
    CHECK(is_native_object(magic));
    return 0;
}
