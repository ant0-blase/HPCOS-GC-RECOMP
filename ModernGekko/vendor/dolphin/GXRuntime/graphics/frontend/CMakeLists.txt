add_library(gxruntime_aurora_render_sink STATIC
    src/render_sink.cpp
)
add_library(GXRuntime::aurora_render_sink ALIAS gxruntime_aurora_render_sink)

target_compile_features(gxruntime_aurora_render_sink PUBLIC cxx_std_20)
target_include_directories(gxruntime_aurora_render_sink
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)
target_link_libraries(gxruntime_aurora_render_sink
    PUBLIC
        GXRuntime::runtime
)

add_library(gxruntime_trace_io STATIC
    src/trace_io.cpp
)
add_library(GXRuntime::trace_io ALIAS gxruntime_trace_io)

target_compile_features(gxruntime_trace_io PUBLIC cxx_std_20)
target_include_directories(gxruntime_trace_io
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

add_library(gxruntime_retail_gx_frontend STATIC
    src/retail_gx_frontend.cpp
)
add_library(GXRuntime::retail_gx_frontend ALIAS gxruntime_retail_gx_frontend)

target_compile_features(gxruntime_retail_gx_frontend PUBLIC cxx_std_20)
target_include_directories(gxruntime_retail_gx_frontend
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)
target_link_libraries(gxruntime_retail_gx_frontend
    PUBLIC
        GXRuntime::runtime
        GXRuntime::aurora_render_sink
)

add_library(gxruntime_replay_core STATIC
    src/replay.cpp
)
add_library(GXRuntime::replay_core ALIAS gxruntime_replay_core)

target_compile_features(gxruntime_replay_core PUBLIC cxx_std_20)
target_link_libraries(gxruntime_replay_core
    PUBLIC
        GXRuntime::retail_gx_frontend
        GXRuntime::trace_io
)

add_executable(dolgx_replay
    tools/dolgx_replay.cpp
)
target_link_libraries(dolgx_replay
    PRIVATE
        GXRuntime::replay_core
)

add_library(gxruntime_dff2dolt STATIC
    src/dff2dolt.cpp
)
add_library(GXRuntime::dff2dolt ALIAS gxruntime_dff2dolt)

target_compile_features(gxruntime_dff2dolt PUBLIC cxx_std_20)
target_link_libraries(gxruntime_dff2dolt
    PUBLIC
        GXRuntime::trace_io
)

add_executable(dff2dolt
    tools/dff2dolt.cpp
)
target_link_libraries(dff2dolt
    PRIVATE
        GXRuntime::dff2dolt
)

if(BUILD_TESTING)
    add_executable(aurora_recomp_frontend_tests
        tests/frontend_replay_test.cpp
    )
    target_link_libraries(aurora_recomp_frontend_tests
        PRIVATE
            GXRuntime::retail_gx_frontend
    )
    add_test(NAME aurora_recomp_frontend_tests
             COMMAND aurora_recomp_frontend_tests)

    add_executable(trace_io_tests
        tests/trace_io_test.cpp
    )
    target_link_libraries(trace_io_tests
        PRIVATE
            GXRuntime::trace_io
    )
    add_test(NAME trace_io_tests COMMAND trace_io_tests)

    add_executable(replay_digest_tests
        tests/replay_digest_test.cpp
    )
    target_link_libraries(replay_digest_tests
        PRIVATE
            GXRuntime::replay_core
    )
    add_test(NAME replay_digest_tests COMMAND replay_digest_tests)

    add_executable(dff2dolt_tests
        tests/dff2dolt_test.cpp
    )
    target_link_libraries(dff2dolt_tests
        PRIVATE
            GXRuntime::dff2dolt
            GXRuntime::replay_core
    )
    add_test(NAME dff2dolt_tests COMMAND dff2dolt_tests)

    # Game-recorded FE menu trace fixture. Trace + golden are game
    # data and live in StrikersRecomp; the test registers only when present,
    # keeping GXRuntime buildable without game assets.
    set(DOLGX_FE_TRACE_DIR
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../StrikersRecomp/tests/traces"
        CACHE PATH "Directory holding fe_menu.dolt + fe_menu.digest")
    if(EXISTS "${DOLGX_FE_TRACE_DIR}/fe_menu.dolt"
       AND EXISTS "${DOLGX_FE_TRACE_DIR}/fe_menu.digest")
        add_test(NAME dolgx_replay_fe_trace
                 COMMAND dolgx_replay
                         "${DOLGX_FE_TRACE_DIR}/fe_menu.dolt"
                         --against-stats
                         --digest "${DOLGX_FE_TRACE_DIR}/fe_menu.digest"
                         --quiet)
    endif()
    # Gameplay trace fixture: mid-match window recorded via the
    # STRIKERS_MASH_TO_GAMEPLAY route, exercises the HLE display-list mirror.
    if(EXISTS "${DOLGX_FE_TRACE_DIR}/gameplay_kickoff.dolt"
       AND EXISTS "${DOLGX_FE_TRACE_DIR}/gameplay_kickoff.digest")
        add_test(NAME dolgx_replay_gameplay_trace
                 COMMAND dolgx_replay
                         "${DOLGX_FE_TRACE_DIR}/gameplay_kickoff.dolt"
                         --against-stats
                         --digest "${DOLGX_FE_TRACE_DIR}/gameplay_kickoff.digest"
                         --quiet)
    endif()
    # From-boot trace fixture: frames 1:1210 of the mash route. Being
    # from reset, it is self-contained for PIXEL replay too (windowed traces
    # lack boot-time state); boot_menus.pixels holds the pixel golden for the
    # Aurora-enabled tool (manual gate — GPU runs don't belong in ctest).
    if(EXISTS "${DOLGX_FE_TRACE_DIR}/boot_menus.dolt"
       AND EXISTS "${DOLGX_FE_TRACE_DIR}/boot_menus.digest")
        add_test(NAME dolgx_replay_boot_trace
                 COMMAND dolgx_replay
                         "${DOLGX_FE_TRACE_DIR}/boot_menus.dolt"
                         --against-stats
                         --digest "${DOLGX_FE_TRACE_DIR}/boot_menus.digest"
                         --quiet)
    endif()
    # Dolphin FIFO-log fixtures: each scene is a Dolphin-recorded
    # .dff converted by dff2dolt at test time (the .dolt is derived, only the
    # .dff + golden digest are committed). No against-stats gate — Dolphin
    # recordings carry no Aurora PRESENT_STATS; pixels are their oracle.
    foreach(dff_scene start_menu fe_menu gameplay)
        if(EXISTS "${DOLGX_FE_TRACE_DIR}/dff/${dff_scene}.dff"
           AND EXISTS "${DOLGX_FE_TRACE_DIR}/dff/${dff_scene}.digest")
            add_test(NAME dff2dolt_convert_${dff_scene}
                     COMMAND dff2dolt
                             "${DOLGX_FE_TRACE_DIR}/dff/${dff_scene}.dff"
                             "${CMAKE_CURRENT_BINARY_DIR}/dff_${dff_scene}.dolt")
            set_tests_properties(dff2dolt_convert_${dff_scene} PROPERTIES
                                 FIXTURES_SETUP dff_${dff_scene})
            add_test(NAME dolgx_replay_dff_${dff_scene}
                     COMMAND dolgx_replay
                             "${CMAKE_CURRENT_BINARY_DIR}/dff_${dff_scene}.dolt"
                             --digest "${DOLGX_FE_TRACE_DIR}/dff/${dff_scene}.digest"
                             --quiet)
            set_tests_properties(dolgx_replay_dff_${dff_scene} PROPERTIES
                                 FIXTURES_REQUIRED dff_${dff_scene})
        endif()
    endforeach()
endif()
