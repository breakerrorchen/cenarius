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
CMAKE_BINARY_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a

# Include any dependencies generated for this target.
include programs/util/CMakeFiles/strerror.dir/depend.make

# Include the progress variables for this target.
include programs/util/CMakeFiles/strerror.dir/progress.make

# Include the compile flags for this target's objects.
include programs/util/CMakeFiles/strerror.dir/flags.make

programs/util/CMakeFiles/strerror.dir/strerror.c.o: programs/util/CMakeFiles/strerror.dir/flags.make
programs/util/CMakeFiles/strerror.dir/strerror.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/util/strerror.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/util/CMakeFiles/strerror.dir/strerror.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strerror.dir/strerror.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/util/strerror.c

programs/util/CMakeFiles/strerror.dir/strerror.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strerror.dir/strerror.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/util/strerror.c > CMakeFiles/strerror.dir/strerror.c.i

programs/util/CMakeFiles/strerror.dir/strerror.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strerror.dir/strerror.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/util/strerror.c -o CMakeFiles/strerror.dir/strerror.c.s

# Object files for target strerror
strerror_OBJECTS = \
"CMakeFiles/strerror.dir/strerror.c.o"

# External object files for target strerror
strerror_EXTERNAL_OBJECTS =

programs/util/strerror: programs/util/CMakeFiles/strerror.dir/strerror.c.o
programs/util/strerror: programs/util/CMakeFiles/strerror.dir/build.make
programs/util/strerror: crypto/library/libmbedcrypto.a
programs/util/strerror: programs/util/CMakeFiles/strerror.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable strerror"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strerror.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/util/CMakeFiles/strerror.dir/build: programs/util/strerror

.PHONY : programs/util/CMakeFiles/strerror.dir/build

programs/util/CMakeFiles/strerror.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util && $(CMAKE_COMMAND) -P CMakeFiles/strerror.dir/cmake_clean.cmake
.PHONY : programs/util/CMakeFiles/strerror.dir/clean

programs/util/CMakeFiles/strerror.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/util /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_arm64_v8a/programs/util/CMakeFiles/strerror.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/util/CMakeFiles/strerror.dir/depend

