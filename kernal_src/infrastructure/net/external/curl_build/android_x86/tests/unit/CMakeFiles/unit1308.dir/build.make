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
CMAKE_SOURCE_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86

# Include any dependencies generated for this target.
include tests/unit/CMakeFiles/unit1308.dir/depend.make

# Include the progress variables for this target.
include tests/unit/CMakeFiles/unit1308.dir/progress.make

# Include the compile flags for this target's objects.
include tests/unit/CMakeFiles/unit1308.dir/flags.make

tests/unit/CMakeFiles/unit1308.dir/unit1308.c.o: tests/unit/CMakeFiles/unit1308.dir/flags.make
tests/unit/CMakeFiles/unit1308.dir/unit1308.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1308.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/unit/CMakeFiles/unit1308.dir/unit1308.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unit1308.dir/unit1308.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1308.c

tests/unit/CMakeFiles/unit1308.dir/unit1308.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unit1308.dir/unit1308.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1308.c > CMakeFiles/unit1308.dir/unit1308.c.i

tests/unit/CMakeFiles/unit1308.dir/unit1308.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unit1308.dir/unit1308.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1308.c -o CMakeFiles/unit1308.dir/unit1308.c.s

tests/unit/CMakeFiles/unit1308.dir/__/libtest/first.c.o: tests/unit/CMakeFiles/unit1308.dir/flags.make
tests/unit/CMakeFiles/unit1308.dir/__/libtest/first.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/unit/CMakeFiles/unit1308.dir/__/libtest/first.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unit1308.dir/__/libtest/first.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c

tests/unit/CMakeFiles/unit1308.dir/__/libtest/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unit1308.dir/__/libtest/first.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c > CMakeFiles/unit1308.dir/__/libtest/first.c.i

tests/unit/CMakeFiles/unit1308.dir/__/libtest/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unit1308.dir/__/libtest/first.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c -o CMakeFiles/unit1308.dir/__/libtest/first.c.s

# Object files for target unit1308
unit1308_OBJECTS = \
"CMakeFiles/unit1308.dir/unit1308.c.o" \
"CMakeFiles/unit1308.dir/__/libtest/first.c.o"

# External object files for target unit1308
unit1308_EXTERNAL_OBJECTS =

tests/unit/unit1308: tests/unit/CMakeFiles/unit1308.dir/unit1308.c.o
tests/unit/unit1308: tests/unit/CMakeFiles/unit1308.dir/__/libtest/first.c.o
tests/unit/unit1308: tests/unit/CMakeFiles/unit1308.dir/build.make
tests/unit/unit1308: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/crypto/library/libmbedcrypto.a
tests/unit/unit1308: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedtls.a
tests/unit/unit1308: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedx509.a
tests/unit/unit1308: lib/libcurl.a
tests/unit/unit1308: /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/i686-linux-android/libz.a
tests/unit/unit1308: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/crypto/library/libmbedcrypto.a
tests/unit/unit1308: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedtls.a
tests/unit/unit1308: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedx509.a
tests/unit/unit1308: tests/unit/CMakeFiles/unit1308.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable unit1308"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit1308.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/unit/CMakeFiles/unit1308.dir/build: tests/unit/unit1308

.PHONY : tests/unit/CMakeFiles/unit1308.dir/build

tests/unit/CMakeFiles/unit1308.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit && $(CMAKE_COMMAND) -P CMakeFiles/unit1308.dir/cmake_clean.cmake
.PHONY : tests/unit/CMakeFiles/unit1308.dir/clean

tests/unit/CMakeFiles/unit1308.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/unit/CMakeFiles/unit1308.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/unit/CMakeFiles/unit1308.dir/depend

