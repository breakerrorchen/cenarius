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
include programs/aes/CMakeFiles/aescrypt2.dir/depend.make

# Include the progress variables for this target.
include programs/aes/CMakeFiles/aescrypt2.dir/progress.make

# Include the compile flags for this target's objects.
include programs/aes/CMakeFiles/aescrypt2.dir/flags.make

programs/aes/CMakeFiles/aescrypt2.dir/aescrypt2.c.o: programs/aes/CMakeFiles/aescrypt2.dir/flags.make
programs/aes/CMakeFiles/aescrypt2.dir/aescrypt2.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/aes/aescrypt2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/aes/CMakeFiles/aescrypt2.dir/aescrypt2.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aescrypt2.dir/aescrypt2.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/aes/aescrypt2.c

programs/aes/CMakeFiles/aescrypt2.dir/aescrypt2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aescrypt2.dir/aescrypt2.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/aes/aescrypt2.c > CMakeFiles/aescrypt2.dir/aescrypt2.c.i

programs/aes/CMakeFiles/aescrypt2.dir/aescrypt2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aescrypt2.dir/aescrypt2.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/aes/aescrypt2.c -o CMakeFiles/aescrypt2.dir/aescrypt2.c.s

# Object files for target aescrypt2
aescrypt2_OBJECTS = \
"CMakeFiles/aescrypt2.dir/aescrypt2.c.o"

# External object files for target aescrypt2
aescrypt2_EXTERNAL_OBJECTS =

programs/aes/aescrypt2: programs/aes/CMakeFiles/aescrypt2.dir/aescrypt2.c.o
programs/aes/aescrypt2: programs/aes/CMakeFiles/aescrypt2.dir/build.make
programs/aes/aescrypt2: crypto/library/libmbedcrypto.a
programs/aes/aescrypt2: programs/aes/CMakeFiles/aescrypt2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable aescrypt2"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aescrypt2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/aes/CMakeFiles/aescrypt2.dir/build: programs/aes/aescrypt2

.PHONY : programs/aes/CMakeFiles/aescrypt2.dir/build

programs/aes/CMakeFiles/aescrypt2.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes && $(CMAKE_COMMAND) -P CMakeFiles/aescrypt2.dir/cmake_clean.cmake
.PHONY : programs/aes/CMakeFiles/aescrypt2.dir/clean

programs/aes/CMakeFiles/aescrypt2.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/aes /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/programs/aes/CMakeFiles/aescrypt2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/aes/CMakeFiles/aescrypt2.dir/depend

