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
CMAKE_BINARY_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build

# Include any dependencies generated for this target.
include crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/depend.make

# Include the progress variables for this target.
include crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/flags.make

crypto/tests/test_suite_aes.cbc.c: ../crypto/tests/scripts/generate_test_code.py
crypto/tests/test_suite_aes.cbc.c: crypto/library/libmbedcrypto.a
crypto/tests/test_suite_aes.cbc.c: ../crypto/tests/suites/helpers.function
crypto/tests/test_suite_aes.cbc.c: ../crypto/tests/suites/main_test.function
crypto/tests/test_suite_aes.cbc.c: ../crypto/tests/suites/host_test.function
crypto/tests/test_suite_aes.cbc.c: ../crypto/tests/suites/test_suite_aes.function
crypto/tests/test_suite_aes.cbc.c: ../crypto/tests/suites/test_suite_aes.cbc.data
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_suite_aes.cbc.c"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests && /usr/bin/python3 /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/scripts/generate_test_code.py -f /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_aes.function -d /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_aes.cbc.data -t /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/main_test.function -p /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/host_test.function -s /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites --helpers-file /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/helpers.function -o .

crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.o: crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/flags.make
crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.o: crypto/tests/test_suite_aes.cbc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests/test_suite_aes.cbc.c

crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests/test_suite_aes.cbc.c > CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.i

crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests/test_suite_aes.cbc.c -o CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.s

# Object files for target crypto.test_suite_aes.cbc
crypto_test_suite_aes_cbc_OBJECTS = \
"CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.o"

# External object files for target crypto.test_suite_aes.cbc
crypto_test_suite_aes_cbc_EXTERNAL_OBJECTS =

crypto/tests/crypto.test_suite_aes.cbc: crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/test_suite_aes.cbc.c.o
crypto/tests/crypto.test_suite_aes.cbc: crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/build.make
crypto/tests/crypto.test_suite_aes.cbc: crypto/library/libmbedcrypto.a
crypto/tests/crypto.test_suite_aes.cbc: crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable crypto.test_suite_aes.cbc"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crypto.test_suite_aes.cbc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/build: crypto/tests/crypto.test_suite_aes.cbc

.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/build

crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/clean:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests && $(CMAKE_COMMAND) -P CMakeFiles/crypto.test_suite_aes.cbc.dir/cmake_clean.cmake
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/clean

crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/depend: crypto/tests/test_suite_aes.cbc.c
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_aes.cbc.dir/depend

