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
include crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/depend.make

# Include the progress variables for this target.
include crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/flags.make

crypto/tests/test_suite_cipher.nist_kw.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/scripts/generate_test_code.py
crypto/tests/test_suite_cipher.nist_kw.c: crypto/library/libmbedcrypto.a
crypto/tests/test_suite_cipher.nist_kw.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/helpers.function
crypto/tests/test_suite_cipher.nist_kw.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/main_test.function
crypto/tests/test_suite_cipher.nist_kw.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/host_test.function
crypto/tests/test_suite_cipher.nist_kw.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function
crypto/tests/test_suite_cipher.nist_kw.c: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.nist_kw.data
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_suite_cipher.nist_kw.c"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests && /usr/bin/python3 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/scripts/generate_test_code.py -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.function -d /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/test_suite_cipher.nist_kw.data -t /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/main_test.function -p /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/host_test.function -s /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites --helpers-file /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests/suites/helpers.function -o .

crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.o: crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/flags.make
crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.o: crypto/tests/test_suite_cipher.nist_kw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests/test_suite_cipher.nist_kw.c

crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests/test_suite_cipher.nist_kw.c > CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.i

crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=x86_64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests/test_suite_cipher.nist_kw.c -o CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.s

# Object files for target crypto.test_suite_cipher.nist_kw
crypto_test_suite_cipher_nist_kw_OBJECTS = \
"CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.o"

# External object files for target crypto.test_suite_cipher.nist_kw
crypto_test_suite_cipher_nist_kw_EXTERNAL_OBJECTS =

crypto/tests/crypto.test_suite_cipher.nist_kw: crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/test_suite_cipher.nist_kw.c.o
crypto/tests/crypto.test_suite_cipher.nist_kw: crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/build.make
crypto/tests/crypto.test_suite_cipher.nist_kw: crypto/library/libmbedcrypto.a
crypto/tests/crypto.test_suite_cipher.nist_kw: crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable crypto.test_suite_cipher.nist_kw"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/build: crypto/tests/crypto.test_suite_cipher.nist_kw

.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/build

crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests && $(CMAKE_COMMAND) -P CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/cmake_clean.cmake
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/clean

crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/depend: crypto/tests/test_suite_cipher.nist_kw.c
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/crypto/tests /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86_64/crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_cipher.nist_kw.dir/depend

