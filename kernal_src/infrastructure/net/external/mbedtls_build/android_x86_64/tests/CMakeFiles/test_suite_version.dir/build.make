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
include tests/CMakeFiles/test_suite_version.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_suite_version.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_suite_version.dir/flags.make

tests/test_suite_version.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/scripts/generate_test_code.py
tests/test_suite_version.c: library/libmbedtls.a
tests/test_suite_version.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/helpers.function
tests/test_suite_version.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/main_test.function
tests/test_suite_version.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/host_test.function
tests/test_suite_version.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/test_suite_version.function
tests/test_suite_version.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/test_suite_version.data
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_suite_version.c"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests && /usr/bin/python3 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/scripts/generate_test_code.py -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/test_suite_version.function -d /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/test_suite_version.data -t /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/main_test.function -p /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/host_test.function -s /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites --helpers-file /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests/suites/helpers.function -o .

tests/CMakeFiles/test_suite_version.dir/test_suite_version.c.o: tests/CMakeFiles/test_suite_version.dir/flags.make
tests/CMakeFiles/test_suite_version.dir/test_suite_version.c.o: tests/test_suite_version.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/test_suite_version.dir/test_suite_version.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_suite_version.dir/test_suite_version.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests/test_suite_version.c

tests/CMakeFiles/test_suite_version.dir/test_suite_version.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_suite_version.dir/test_suite_version.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests/test_suite_version.c > CMakeFiles/test_suite_version.dir/test_suite_version.c.i

tests/CMakeFiles/test_suite_version.dir/test_suite_version.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_suite_version.dir/test_suite_version.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests/test_suite_version.c -o CMakeFiles/test_suite_version.dir/test_suite_version.c.s

# Object files for target test_suite_version
test_suite_version_OBJECTS = \
"CMakeFiles/test_suite_version.dir/test_suite_version.c.o"

# External object files for target test_suite_version
test_suite_version_EXTERNAL_OBJECTS =

tests/test_suite_version: tests/CMakeFiles/test_suite_version.dir/test_suite_version.c.o
tests/test_suite_version: tests/CMakeFiles/test_suite_version.dir/build.make
tests/test_suite_version: library/libmbedtls.a
tests/test_suite_version: library/libmbedx509.a
tests/test_suite_version: crypto/library/libmbedcrypto.a
tests/test_suite_version: tests/CMakeFiles/test_suite_version.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_suite_version"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_suite_version.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_suite_version.dir/build: tests/test_suite_version

.PHONY : tests/CMakeFiles/test_suite_version.dir/build

tests/CMakeFiles/test_suite_version.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_suite_version.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_suite_version.dir/clean

tests/CMakeFiles/test_suite_version.dir/depend: tests/test_suite_version.c
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/tests /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/tests/CMakeFiles/test_suite_version.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_suite_version.dir/depend

