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
CMAKE_SOURCE_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a

# Include any dependencies generated for this target.
include programs/ssl/CMakeFiles/ssl_server2.dir/depend.make

# Include the progress variables for this target.
include programs/ssl/CMakeFiles/ssl_server2.dir/progress.make

# Include the compile flags for this target's objects.
include programs/ssl/CMakeFiles/ssl_server2.dir/flags.make

programs/ssl/CMakeFiles/ssl_server2.dir/ssl_server2.c.o: programs/ssl/CMakeFiles/ssl_server2.dir/flags.make
programs/ssl/CMakeFiles/ssl_server2.dir/ssl_server2.c.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_server2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/ssl/CMakeFiles/ssl_server2.dir/ssl_server2.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ssl_server2.dir/ssl_server2.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_server2.c

programs/ssl/CMakeFiles/ssl_server2.dir/ssl_server2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ssl_server2.dir/ssl_server2.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_server2.c > CMakeFiles/ssl_server2.dir/ssl_server2.c.i

programs/ssl/CMakeFiles/ssl_server2.dir/ssl_server2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ssl_server2.dir/ssl_server2.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_server2.c -o CMakeFiles/ssl_server2.dir/ssl_server2.c.s

programs/ssl/CMakeFiles/ssl_server2.dir/__/test/query_config.c.o: programs/ssl/CMakeFiles/ssl_server2.dir/flags.make
programs/ssl/CMakeFiles/ssl_server2.dir/__/test/query_config.c.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/test/query_config.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object programs/ssl/CMakeFiles/ssl_server2.dir/__/test/query_config.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ssl_server2.dir/__/test/query_config.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/test/query_config.c

programs/ssl/CMakeFiles/ssl_server2.dir/__/test/query_config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ssl_server2.dir/__/test/query_config.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/test/query_config.c > CMakeFiles/ssl_server2.dir/__/test/query_config.c.i

programs/ssl/CMakeFiles/ssl_server2.dir/__/test/query_config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ssl_server2.dir/__/test/query_config.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/test/query_config.c -o CMakeFiles/ssl_server2.dir/__/test/query_config.c.s

# Object files for target ssl_server2
ssl_server2_OBJECTS = \
"CMakeFiles/ssl_server2.dir/ssl_server2.c.o" \
"CMakeFiles/ssl_server2.dir/__/test/query_config.c.o"

# External object files for target ssl_server2
ssl_server2_EXTERNAL_OBJECTS =

programs/ssl/ssl_server2: programs/ssl/CMakeFiles/ssl_server2.dir/ssl_server2.c.o
programs/ssl/ssl_server2: programs/ssl/CMakeFiles/ssl_server2.dir/__/test/query_config.c.o
programs/ssl/ssl_server2: programs/ssl/CMakeFiles/ssl_server2.dir/build.make
programs/ssl/ssl_server2: library/libmbedtls.a
programs/ssl/ssl_server2: library/libmbedx509.a
programs/ssl/ssl_server2: crypto/library/libmbedcrypto.a
programs/ssl/ssl_server2: programs/ssl/CMakeFiles/ssl_server2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ssl_server2"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ssl_server2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/ssl/CMakeFiles/ssl_server2.dir/build: programs/ssl/ssl_server2

.PHONY : programs/ssl/CMakeFiles/ssl_server2.dir/build

programs/ssl/CMakeFiles/ssl_server2.dir/clean:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl && $(CMAKE_COMMAND) -P CMakeFiles/ssl_server2.dir/cmake_clean.cmake
.PHONY : programs/ssl/CMakeFiles/ssl_server2.dir/clean

programs/ssl/CMakeFiles/ssl_server2.dir/depend:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/programs/ssl/CMakeFiles/ssl_server2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/ssl/CMakeFiles/ssl_server2.dir/depend

