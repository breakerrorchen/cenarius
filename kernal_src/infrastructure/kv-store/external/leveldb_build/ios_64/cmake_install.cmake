# Install script for directory: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
      execute_process(COMMAND "ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
      execute_process(COMMAND "ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
      execute_process(COMMAND "ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
      execute_process(COMMAND "ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libleveldb.a")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/leveldb" TYPE FILE FILES
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/c.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/cache.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/comparator.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/db.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/dumpfile.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/env.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/export.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/filter_policy.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/iterator.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/options.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/slice.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/status.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/table_builder.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/table.h"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/include/leveldb/write_batch.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb/leveldbTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb/leveldbTargets.cmake"
         "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/CMakeFiles/Export/lib/cmake/leveldb/leveldbTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb/leveldbTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb/leveldbTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb" TYPE FILE FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/CMakeFiles/Export/lib/cmake/leveldb/leveldbTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb" TYPE FILE FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/CMakeFiles/Export/lib/cmake/leveldb/leveldbTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb" TYPE FILE FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/CMakeFiles/Export/lib/cmake/leveldb/leveldbTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb" TYPE FILE FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/CMakeFiles/Export/lib/cmake/leveldb/leveldbTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb" TYPE FILE FILES "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/CMakeFiles/Export/lib/cmake/leveldb/leveldbTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/leveldb" TYPE FILE FILES
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/cmake/leveldbConfig.cmake"
    "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/cmake/leveldbConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/third_party/googletest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
