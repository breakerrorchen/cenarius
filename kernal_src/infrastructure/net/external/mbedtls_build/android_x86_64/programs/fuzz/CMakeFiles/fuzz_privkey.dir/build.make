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
CMAKE_BINARY_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64

# Include any dependencies generated for this target.
include programs/fuzz/CMakeFiles/fuzz_privkey.dir/depend.make

# Include the progress variables for this target.
include programs/fuzz/CMakeFiles/fuzz_privkey.dir/progress.make

# Include the compile flags for this target's objects.
include programs/fuzz/CMakeFiles/fuzz_privkey.dir/flags.make

programs/fuzz/CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.o: programs/fuzz/CMakeFiles/fuzz_privkey.dir/flags.make
programs/fuzz/CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/fuzz_privkey.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/fuzz/CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/fuzz_privkey.c

programs/fuzz/CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/fuzz_privkey.c > CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.i

programs/fuzz/CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/fuzz_privkey.c -o CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.s

programs/fuzz/CMakeFiles/fuzz_privkey.dir/onefile.c.o: programs/fuzz/CMakeFiles/fuzz_privkey.dir/flags.make
programs/fuzz/CMakeFiles/fuzz_privkey.dir/onefile.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/onefile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object programs/fuzz/CMakeFiles/fuzz_privkey.dir/onefile.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fuzz_privkey.dir/onefile.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/onefile.c

programs/fuzz/CMakeFiles/fuzz_privkey.dir/onefile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fuzz_privkey.dir/onefile.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/onefile.c > CMakeFiles/fuzz_privkey.dir/onefile.c.i

programs/fuzz/CMakeFiles/fuzz_privkey.dir/onefile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fuzz_privkey.dir/onefile.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz/onefile.c -o CMakeFiles/fuzz_privkey.dir/onefile.c.s

# Object files for target fuzz_privkey
fuzz_privkey_OBJECTS = \
"CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.o" \
"CMakeFiles/fuzz_privkey.dir/onefile.c.o"

# External object files for target fuzz_privkey
fuzz_privkey_EXTERNAL_OBJECTS =

programs/fuzz/fuzz_privkey: programs/fuzz/CMakeFiles/fuzz_privkey.dir/fuzz_privkey.c.o
programs/fuzz/fuzz_privkey: programs/fuzz/CMakeFiles/fuzz_privkey.dir/onefile.c.o
programs/fuzz/fuzz_privkey: programs/fuzz/CMakeFiles/fuzz_privkey.dir/build.make
programs/fuzz/fuzz_privkey: library/libmbedtls.a
programs/fuzz/fuzz_privkey: library/libmbedx509.a
programs/fuzz/fuzz_privkey: crypto/library/libmbedcrypto.a
programs/fuzz/fuzz_privkey: programs/fuzz/CMakeFiles/fuzz_privkey.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable fuzz_privkey"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fuzz_privkey.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/fuzz/CMakeFiles/fuzz_privkey.dir/build: programs/fuzz/fuzz_privkey

.PHONY : programs/fuzz/CMakeFiles/fuzz_privkey.dir/build

programs/fuzz/CMakeFiles/fuzz_privkey.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz && $(CMAKE_COMMAND) -P CMakeFiles/fuzz_privkey.dir/cmake_clean.cmake
.PHONY : programs/fuzz/CMakeFiles/fuzz_privkey.dir/clean

programs/fuzz/CMakeFiles/fuzz_privkey.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/fuzz /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/programs/fuzz/CMakeFiles/fuzz_privkey.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/fuzz/CMakeFiles/fuzz_privkey.dir/depend

