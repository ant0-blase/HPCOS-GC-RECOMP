#include "common/types.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "check failed: %s:%d: %s\n", \
    __FILE__, __LINE__, #x); return 1; } } while (0)

static int make_dir(const char* path) {
    return mkdir(path, 0777) == 0 || errno == EEXIST;
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
    CHECK(magic[0] == 0x7F && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F');
    file = fopen(second_object, "rb");
    CHECK(file != NULL);
    CHECK(fread(magic, 1, 4, file) == 4);
    fclose(file);
    CHECK(magic[0] == 0x7F && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F');
    return 0;
}
