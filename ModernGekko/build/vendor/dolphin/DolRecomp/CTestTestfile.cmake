# CMake generated Testfile for 
# Source directory: /home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp
# Build directory: /home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opcodes "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_opcodes")
set_tests_properties(opcodes PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;168;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(cross_check "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_cross_check")
set_tests_properties(cross_check PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;172;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(dol "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_dol")
set_tests_properties(dol PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;176;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(rel "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_rel")
set_tests_properties(rel PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;180;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(rpx "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_rpx")
set_tests_properties(rpx PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;184;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(disc_extract "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_disc_extract" "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/dolrecomp" "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/disc_extract_test")
set_tests_properties(disc_extract PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;188;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(pc_reference "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_pc_reference")
set_tests_properties(pc_reference PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;196;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(jumptables "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_jumptables")
set_tests_properties(jumptables PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;200;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(dispatch "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_dispatch")
set_tests_properties(dispatch PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;204;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(c_cfg "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_c_cfg")
set_tests_properties(c_cfg PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;208;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(symbols "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_symbols" "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/tests/fixtures/codewarrior.map")
set_tests_properties(symbols PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;212;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(codegen_compile "/usr/bin/cmake" "-DGENERATOR_EXE=/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_codegen_emit" "-DOUTPUT_C=/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/codegen_check.c" "-DREPO_SRC=/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/src" "-DHOST_GENERATOR=Ninja" "-DHOST_GENERATOR_PLATFORM=" "-DHOST_GENERATOR_TOOLSET=" "-DHOST_C_COMPILER=/usr/bin/cc" "-DHOST_BUILD_CONFIG=Release" "-P" "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/tests/cmake/codegen_compile.cmake")
set_tests_properties(codegen_compile PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;217;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(c_execute "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_c_execute")
set_tests_properties(c_execute PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;242;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
add_test(dolir "/home/linux/HPCOS-GC-RECOMP/ModernGekko/build/vendor/dolphin/DolRecomp/test_dolir")
set_tests_properties(dolir PROPERTIES  _BACKTRACE_TRIPLES "/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;246;add_test;/home/linux/HPCOS-GC-RECOMP/ModernGekko/vendor/dolphin/DolRecomp/CMakeLists.txt;0;")
