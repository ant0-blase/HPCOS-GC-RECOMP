add_subdirectory(OGL)
add_subdirectory(Null)
add_subdirectory(Software)

if(WIN32)
  if(MSVC)
    add_subdirectory(D3DCommon)
    add_subdirectory(D3D)
    add_subdirectory(D3D12)
  endif()
endif()

if(APPLE)
  add_subdirectory(Metal)
endif()

if(ENABLE_VULKAN)
  add_subdirectory(Vulkan)
endif()
