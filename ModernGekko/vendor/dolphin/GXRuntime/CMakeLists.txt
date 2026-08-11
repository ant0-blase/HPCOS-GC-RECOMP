cmake_minimum_required(VERSION 3.16)
project(GXRuntime LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(CTest)

add_library(gxruntime STATIC
    src/core/cpu.c
    src/core/cpu_exception.c
    src/core/cpu_interpreter.c
    src/core/cpu_interpreter_table.c
    src/core/cpu_interpreter_float.c
    src/core/cpu_interpreter_integer.c
    src/loader.c
    src/boot.c
    src/aram.c
    src/dvd.c
    src/event_clock.c
    src/guest_memory.c
    src/gx_recomp.c
    src/gx_recomp_parser.c
    src/interrupts.c
    src/si.c
    src/exi.c
    src/di.c
    src/mmio_bus.c
    src/platform.c
    src/audio_dma.c
    src/vi_clock.c
    src/memory_card.c
    src/headless_backend.c
    src/savestate.c
    src/hle/hle_abi.c
    src/hle/hle_core.c
    src/hle/hle_card.c
    src/hle/hle_dvd.c
    src/hle/hle_input.c
)
add_library(GXRuntime::runtime ALIAS gxruntime)

target_include_directories(gxruntime
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
)

include(CheckLibraryExists)
check_library_exists(m sqrt "" GXRUNTIME_HAVE_LIBM)
if(GXRUNTIME_HAVE_LIBM)
    target_link_libraries(gxruntime PUBLIC m)
endif()

option(GXRUNTIME_ENABLE_AURORA
       "Build the Aurora graphics/input/audio backend" ON)
option(GXRUNTIME_ENABLE_AURORA_RECOMP
       "Build GXRuntime-owned Aurora recomp-mode frontend/sink modules" ON)
set(GXRUNTIME_AURORA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/graphics/aurora"
    CACHE PATH "Path to the GXRuntime-owned Aurora fork (graphics/aurora)")

if(GXRUNTIME_ENABLE_AURORA_RECOMP)
    enable_language(CXX)
    add_subdirectory(graphics/frontend)
    add_subdirectory(graphics/gxcore)
endif()

if(GXRUNTIME_ENABLE_AURORA)
    if(NOT EXISTS "${GXRUNTIME_AURORA_DIR}/include/aurora/aurora.h")
        message(FATAL_ERROR
            "Aurora not found at ${GXRUNTIME_AURORA_DIR}. Set "
            "-DGXRUNTIME_AURORA_DIR=<path> or disable "
            "GXRUNTIME_ENABLE_AURORA.")
    endif()

    enable_language(CXX)
    set(AURORA_RECOMP_TEST_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/graphics/frontend/tests/recomp_fifo_test.cpp")
    add_subdirectory("${GXRUNTIME_AURORA_DIR}"
                     "${CMAKE_BINARY_DIR}/aurora" EXCLUDE_FROM_ALL)

    add_library(gxruntime_aurora STATIC
        backends/aurora/aurora_backend.cpp
        backends/aurora/aurora_graphics.cpp
        backends/aurora/aurora_audio.cpp
        backends/aurora/aurora_input.cpp
    )
    add_library(GXRuntime::aurora ALIAS gxruntime_aurora)
    target_include_directories(gxruntime_aurora
        PUBLIC
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:include>"
        PRIVATE
            "${GXRUNTIME_AURORA_DIR}/lib"
    )
    target_compile_features(gxruntime_aurora PUBLIC cxx_std_20)
    target_link_libraries(gxruntime_aurora
        PUBLIC
            gxruntime
            aurora::core aurora::gx aurora::vi aurora::os
            aurora::pad aurora::si aurora::mtx aurora::main
            absl::flat_hash_map
    )
    if(GXRUNTIME_ENABLE_AURORA_RECOMP)
        target_compile_definitions(gxruntime_aurora
            PRIVATE GXRUNTIME_HAS_AURORA_RECOMP=1)
        target_link_libraries(gxruntime_aurora
            PUBLIC GXRuntime::retail_gx_frontend GXRuntime::trace_io)
        # 63/Mfin live cutover: the backend drives a GxCoreSink directly (bypasses
        # live Aurora gx under DOL_GX_CORE), so it needs the gxcore headers and
        # symbols — not just the transitive link through aurora::gx.
        target_link_libraries(gxruntime_aurora PRIVATE GXRuntime::gxcore)
        # pixel replay (Mode B) — the same dolgx_replay tool gains
        # --pixels when built in an Aurora-enabled tree (the StrikersRecomp
        # GUI build); build-headless keeps the digest-only tool.
        # --core (Mode B2) routes draws through the gxcore modules
        # instead of the live Aurora gx layer; it reaches into the fork's
        # lib/ for the gxcore_draw submission seam.
        target_sources(dolgx_replay PRIVATE
            graphics/frontend/tools/dolgx_replay_pixels.cpp
            graphics/frontend/tools/dolgx_replay_core.cpp)
        target_compile_definitions(dolgx_replay
            PRIVATE DOLGX_REPLAY_HAS_PIXELS=1 DOLGX_REPLAY_HAS_CORE=1)
        target_include_directories(dolgx_replay
            PRIVATE "${GXRUNTIME_AURORA_DIR}/lib")
        target_link_libraries(dolgx_replay
            PRIVATE GXRuntime::aurora GXRuntime::gxcore)
    else()
        target_compile_definitions(gxruntime_aurora
            PRIVATE GXRUNTIME_HAS_AURORA_RECOMP=0)
    endif()
endif()

if(BUILD_TESTING)
    add_executable(gxruntime_tests
        tests/runtime_tests.c
    )
    target_link_libraries(gxruntime_tests PRIVATE GXRuntime::runtime)
    add_test(NAME gxruntime_tests COMMAND gxruntime_tests)
endif()
