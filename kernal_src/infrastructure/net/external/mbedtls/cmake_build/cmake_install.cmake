# Install script for directory: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/3rdparty/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/library/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/include/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/library/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/include/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/tests/cmake_install.cmake")
  include("/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
