# Install script for directory: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/certs.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/check_config.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/compat-1.3.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/config.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/debug.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/error.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/net.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/net_sockets.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/pkcs11.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/ssl.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/ssl_cache.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/ssl_cookie.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/ssl_internal.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/ssl_ticket.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/version.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/x509.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/x509_crl.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/x509_crt.h"
    "/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/include/mbedtls/x509_csr.h"
    )
endif()

