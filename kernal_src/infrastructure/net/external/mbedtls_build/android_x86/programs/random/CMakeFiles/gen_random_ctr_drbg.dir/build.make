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
include programs/random/CMakeFiles/gen_random_ctr_drbg.dir/depend.make

# Include the progress variables for this target.
include programs/random/CMakeFiles/gen_random_ctr_drbg.dir/progress.make

# Include the compile flags for this target's objects.
include programs/random/CMakeFiles/gen_random_ctr_drbg.dir/flags.make

programs/random/CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.o: programs/random/CMakeFiles/gen_random_ctr_drbg.dir/flags.make
programs/random/CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/random/gen_random_ctr_drbg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/random/CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/random/gen_random_ctr_drbg.c

programs/random/CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/random/gen_random_ctr_drbg.c > CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.i

programs/random/CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/random/gen_random_ctr_drbg.c -o CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.s

# Object files for target gen_random_ctr_drbg
gen_random_ctr_drbg_OBJECTS = \
"CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.o"

# External object files for target gen_random_ctr_drbg
gen_random_ctr_drbg_EXTERNAL_OBJECTS =

programs/random/gen_random_ctr_drbg: programs/random/CMakeFiles/gen_random_ctr_drbg.dir/gen_random_ctr_drbg.c.o
programs/random/gen_random_ctr_drbg: programs/random/CMakeFiles/gen_random_ctr_drbg.dir/build.make
programs/random/gen_random_ctr_drbg: crypto/library/libmbedcrypto.a
programs/random/gen_random_ctr_drbg: programs/random/CMakeFiles/gen_random_ctr_drbg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable gen_random_ctr_drbg"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gen_random_ctr_drbg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/random/CMakeFiles/gen_random_ctr_drbg.dir/build: programs/random/gen_random_ctr_drbg

.PHONY : programs/random/CMakeFiles/gen_random_ctr_drbg.dir/build

programs/random/CMakeFiles/gen_random_ctr_drbg.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random && $(CMAKE_COMMAND) -P CMakeFiles/gen_random_ctr_drbg.dir/cmake_clean.cmake
.PHONY : programs/random/CMakeFiles/gen_random_ctr_drbg.dir/clean

programs/random/CMakeFiles/gen_random_ctr_drbg.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/random /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/random/CMakeFiles/gen_random_ctr_drbg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/random/CMakeFiles/gen_random_ctr_drbg.dir/depend

