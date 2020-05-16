if(NOT EXISTS "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86_64/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86_64/install_manifest.txt")
endif()

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
message(${CMAKE_INSTALL_PREFIX})

file(READ "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86_64/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/usr/local/Cellar/cmake/3.16.4/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif()
  else()
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif()
endforeach()
