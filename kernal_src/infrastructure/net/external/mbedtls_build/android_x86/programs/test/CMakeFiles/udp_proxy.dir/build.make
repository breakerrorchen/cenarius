# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86

# Include any dependencies generated for this target.
include programs/test/CMakeFiles/udp_proxy.dir/depend.make

# Include the progress variables for this target.
include programs/test/CMakeFiles/udp_proxy.dir/progress.make

# Include the compile flags for this target's objects.
include programs/test/CMakeFiles/udp_proxy.dir/flags.make

programs/test/CMakeFiles/udp_proxy.dir/udp_proxy.c.o: programs/test/CMakeFiles/udp_proxy.dir/flags.make
programs/test/CMakeFiles/udp_proxy.dir/udp_proxy.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/test/udp_proxy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/test/CMakeFiles/udp_proxy.dir/udp_proxy.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/udp_proxy.dir/udp_proxy.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/test/udp_proxy.c

programs/test/CMakeFiles/udp_proxy.dir/udp_proxy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_proxy.dir/udp_proxy.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/test/udp_proxy.c > CMakeFiles/udp_proxy.dir/udp_proxy.c.i

programs/test/CMakeFiles/udp_proxy.dir/udp_proxy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_proxy.dir/udp_proxy.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/test/udp_proxy.c -o CMakeFiles/udp_proxy.dir/udp_proxy.c.s

# Object files for target udp_proxy
udp_proxy_OBJECTS = \
"CMakeFiles/udp_proxy.dir/udp_proxy.c.o"

# External object files for target udp_proxy
udp_proxy_EXTERNAL_OBJECTS =

programs/test/udp_proxy: programs/test/CMakeFiles/udp_proxy.dir/udp_proxy.c.o
programs/test/udp_proxy: programs/test/CMakeFiles/udp_proxy.dir/build.make
programs/test/udp_proxy: library/libmbedtls.a
programs/test/udp_proxy: library/libmbedx509.a
programs/test/udp_proxy: crypto/library/libmbedcrypto.a
programs/test/udp_proxy: programs/test/CMakeFiles/udp_proxy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable udp_proxy"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_proxy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/test/CMakeFiles/udp_proxy.dir/build: programs/test/udp_proxy

.PHONY : programs/test/CMakeFiles/udp_proxy.dir/build

programs/test/CMakeFiles/udp_proxy.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test && $(CMAKE_COMMAND) -P CMakeFiles/udp_proxy.dir/cmake_clean.cmake
.PHONY : programs/test/CMakeFiles/udp_proxy.dir/clean

programs/test/CMakeFiles/udp_proxy.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/test /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/test/CMakeFiles/udp_proxy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/test/CMakeFiles/udp_proxy.dir/depend

