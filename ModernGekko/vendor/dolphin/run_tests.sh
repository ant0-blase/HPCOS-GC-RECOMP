#!/bin/bash
# RecompCore Unified Test Runner
# Compiles and runs all test suites across the repository.


# todo: replace with a simpler test suite


# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# CPU cores detection
NCPU=$(sysctl -n hw.ncpu 2>/dev/null || sysctl -n hw.logicalcpu 2>/dev/null || echo 4)

# Generator detection
GENERATOR=""
if command -v ninja >/dev/null 2>&1; then
  GENERATOR="-G Ninja"
fi

# Track results
DOLRECOMP_STATUS="Skipped"
GXRUNTIME_STATUS="Skipped"
CHASSIS_STATUS="Skipped"
MODULE_STATUS="Skipped"

FAILED=0

echo -e "${CYAN}=======================================================${NC}"
echo -e "${CYAN}             RecompCore Unified Test Runner            ${NC}"
echo -e "${CYAN}=======================================================${NC}"

# 1. DolRecomp Test Suite
echo -e "\n${BLUE}[1/4] Building and running DolRecomp tests...${NC}"
if [ -d "DolRecomp" ]; then
  mkdir -p DolRecomp/build
  cmake $GENERATOR -S DolRecomp -B DolRecomp/build -DCMAKE_BUILD_TYPE=Release
  if cmake --build DolRecomp/build -j"$NCPU"; then
    if (cd DolRecomp/build && ctest --output-on-failure); then
      DOLRECOMP_STATUS="${GREEN}PASSED${NC}"
    else
      DOLRECOMP_STATUS="${RED}FAILED (test execution failed)${NC}"
      FAILED=1
    fi
  else
    DOLRECOMP_STATUS="${RED}FAILED (build failed)${NC}"
    FAILED=1
  fi
else
  DOLRECOMP_STATUS="${YELLOW}SKIPPED (directory not found)${NC}"
fi

# 2. GXRuntime Test Suite
echo -e "\n${BLUE}[2/4] Building and running GXRuntime tests...${NC}"
if [ -d "GXRuntime" ]; then
  mkdir -p GXRuntime/build
  cmake $GENERATOR -S GXRuntime -B GXRuntime/build -DCMAKE_BUILD_TYPE=Release
  if cmake --build GXRuntime/build -j"$NCPU"; then
    if (cd GXRuntime/build && ctest --output-on-failure); then
      GXRUNTIME_STATUS="${GREEN}PASSED${NC}"
    else
      GXRUNTIME_STATUS="${RED}FAILED (test execution failed)${NC}"
      FAILED=1
    fi
  else
    GXRUNTIME_STATUS="${RED}FAILED (build failed)${NC}"
    FAILED=1
  fi
else
  GXRUNTIME_STATUS="${YELLOW}SKIPPED (directory not found)${NC}"
fi

# 3. Chassis Core Unit Tests
echo -e "\n${BLUE}[3/4] Building and running Chassis Core Unit Tests...${NC}"
if [ -d "build" ]; then
  # The CMake configuration runs tests as part of the post-build phase of the unittests target.
  if cmake --build build --target unittests -j"$NCPU"; then
    CHASSIS_STATUS="${GREEN}PASSED${NC}"
  else
    CHASSIS_STATUS="${RED}FAILED (build/test execution failed)${NC}"
    FAILED=1
  fi
else
  CHASSIS_STATUS="${YELLOW}SKIPPED (Dolphin build directory not found. Please run ./build.sh first)${NC}"
  FAILED=1
fi

# 4. Static Recomp Module Build Check
echo -e "\n${BLUE}[4/4] Building Static Recomp Module...${NC}"
if [ -d "module-template" ]; then
  mkdir -p module-template/build
  cmake $GENERATOR -S module-template -B module-template/build -DCMAKE_BUILD_TYPE=Release -DGAME_ID=000002
  if cmake --build module-template/build -j"$NCPU"; then
    MODULE_STATUS="${GREEN}PASSED${NC}"
  else
    MODULE_STATUS="${RED}FAILED (build failed)${NC}"
    FAILED=1
  fi
else
  MODULE_STATUS="${YELLOW}SKIPPED (directory not found)${NC}"
fi

# Final Summary
echo -e "\n${CYAN}=======================================================${NC}"
echo -e "${CYAN}                    Test Result Summary                ${NC}"
echo -e "${CYAN}=======================================================${NC}"
echo -e "1. DolRecomp Compiler Tests:      $DOLRECOMP_STATUS"
echo -e "2. GXRuntime Emulation Tests:     $GXRUNTIME_STATUS"
echo -e "3. Chassis Core Unit Tests:       $CHASSIS_STATUS"
echo -e "4. Static Recomp Module Build:    $MODULE_STATUS"
echo -e "${CYAN}=======================================================${NC}"

if [ $FAILED -eq 0 ]; then
  echo -e "${GREEN}🎉 All test suites completed successfully!${NC}\n"
  exit 0
else
  echo -e "${RED}❌ Some test suites failed or were skipped. See details above.${NC}\n"
  exit 1
fi
