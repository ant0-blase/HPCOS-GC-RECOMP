include(ExternalProject)

set(MOLTENVK_VERSION "v1.2.8")

if(APPLE)
  set(MOLTENVK_BUILD_CMD ${CMAKE_COMMAND} -E env "XCODEBUILD=set -o pipefail && xcodebuild OTHER_LDFLAGS=-Wl,-ld_classic" make -e -C <SOURCE_DIR> macos)
else()
  set(MOLTENVK_BUILD_CMD make -C <SOURCE_DIR> macos)
endif()

ExternalProject_Add(MoltenVK
  GIT_REPOSITORY https://github.com/KhronosGroup/MoltenVK.git
  GIT_TAG ${MOLTENVK_VERSION}

  CONFIGURE_COMMAND ${CMAKE_CURRENT_LIST_DIR}/configure.sh <LOG_DIR> <SOURCE_DIR> ${MOLTENVK_VERSION}

  PATCH_COMMAND ${CMAKE_CURRENT_LIST_DIR}/patch.sh ${CMAKE_SOURCE_DIR}/Externals/MoltenVK/patches/ ${MOLTENVK_VERSION}

  BUILD_COMMAND ${MOLTENVK_BUILD_CMD}
  BUILD_IN_SOURCE ON
  BUILD_BYPRODUCTS <SOURCE_DIR>/Package/Release/MoltenVK/dynamic/dylib/macOS/libMoltenVK.dylib

  INSTALL_COMMAND ""

  LOG_CONFIGURE ON
  LOG_BUILD ON
  LOG_OUTPUT_ON_FAILURE ON
)
