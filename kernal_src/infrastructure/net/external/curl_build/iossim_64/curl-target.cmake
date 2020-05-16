# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget CURL::curl)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target CURL::curl
add_executable(CURL::curl IMPORTED)
set_property(TARGET CURL::curl PROPERTY MACOSX_BUNDLE 1)

# Import target "CURL::curl" for configuration "Debug"
set_property(TARGET CURL::curl APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(CURL::curl PROPERTIES
  IMPORTED_LOCATION_DEBUG "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/iossim_64/src/Debug\${EFFECTIVE_PLATFORM_NAME}/curl.app/curl"
  )

# Import target "CURL::curl" for configuration "Release"
set_property(TARGET CURL::curl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CURL::curl PROPERTIES
  IMPORTED_LOCATION_RELEASE "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/iossim_64/src/Release\${EFFECTIVE_PLATFORM_NAME}/curl.app/curl"
  )

# Import target "CURL::curl" for configuration "MinSizeRel"
set_property(TARGET CURL::curl APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(CURL::curl PROPERTIES
  IMPORTED_LOCATION_MINSIZEREL "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/iossim_64/src/MinSizeRel\${EFFECTIVE_PLATFORM_NAME}/curl.app/curl"
  )

# Import target "CURL::curl" for configuration "RelWithDebInfo"
set_property(TARGET CURL::curl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CURL::curl PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/iossim_64/src/RelWithDebInfo\${EFFECTIVE_PLATFORM_NAME}/curl.app/curl"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
