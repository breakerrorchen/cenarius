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
include crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/depend.make

# Include the progress variables for this target.
include crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/flags.make

crypto/tests/test_suite_cipher.chacha20.c: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/scripts/generate_test_code.py
crypto/tests/test_suite_cipher.chacha20.c: crypto/library/libmbedcrypto.a
crypto/tests/test_suite_cipher.chacha20.c: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/helpers.function
crypto/tests/test_suite_cipher.chacha20.c: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/main_test.function
crypto/tests/test_suite_cipher.chacha20.c: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/host_test.function
crypto/tests/test_suite_cipher.chacha20.c: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_cipher.function
crypto/tests/test_suite_cipher.chacha20.c: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_cipher.chacha20.data
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_suite_cipher.chacha20.c"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests && /usr/bin/python3 /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/scripts/generate_test_code.py -f /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_cipher.function -d /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/test_suite_cipher.chacha20.data -t /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/main_test.function -p /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/host_test.function -s /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites --helpers-file /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests/suites/helpers.function -o .

crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.o: crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/flags.make
crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.o: crypto/tests/test_suite_cipher.chacha20.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests/test_suite_cipher.chacha20.c

crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests/test_suite_cipher.chacha20.c > CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.i

crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests/test_suite_cipher.chacha20.c -o CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.s

# Object files for target crypto.test_suite_cipher.chacha20
crypto_test_suite_cipher_chacha20_OBJECTS = \
"CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.o"

# External object files for target crypto.test_suite_cipher.chacha20
crypto_test_suite_cipher_chacha20_EXTERNAL_OBJECTS =

crypto/tests/crypto.test_suite_cipher.chacha20: crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/test_suite_cipher.chacha20.c.o
crypto/tests/crypto.test_suite_cipher.chacha20: crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/build.make
crypto/tests/crypto.test_suite_cipher.chacha20: crypto/library/libmbedcrypto.a
crypto/tests/crypto.test_suite_cipher.chacha20: crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable crypto.test_suite_cipher.chacha20"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crypto.test_suite_cipher.chacha20.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/build: crypto/tests/crypto.test_suite_cipher.chacha20

.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/build

crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/clean:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests && $(CMAKE_COMMAND) -P CMakeFiles/crypto.test_suite_cipher.chacha20.dir/cmake_clean.cmake
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/clean

crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/depend: crypto/tests/test_suite_cipher.chacha20.c
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/tests /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls_build/android_armeabi_v7a/crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_cipher.chacha20.dir/depend

