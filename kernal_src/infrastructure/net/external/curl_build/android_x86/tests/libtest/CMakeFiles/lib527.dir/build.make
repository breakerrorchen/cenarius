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
include tests/libtest/CMakeFiles/lib527.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib527.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib527.dir/flags.make

tests/libtest/CMakeFiles/lib527.dir/lib526.c.o: tests/libtest/CMakeFiles/lib527.dir/flags.make
tests/libtest/CMakeFiles/lib527.dir/lib526.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib526.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib527.dir/lib526.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib527.dir/lib526.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib526.c

tests/libtest/CMakeFiles/lib527.dir/lib526.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib527.dir/lib526.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib526.c > CMakeFiles/lib527.dir/lib526.c.i

tests/libtest/CMakeFiles/lib527.dir/lib526.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib527.dir/lib526.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib526.c -o CMakeFiles/lib527.dir/lib526.c.s

tests/libtest/CMakeFiles/lib527.dir/first.c.o: tests/libtest/CMakeFiles/lib527.dir/flags.make
tests/libtest/CMakeFiles/lib527.dir/first.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib527.dir/first.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib527.dir/first.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c

tests/libtest/CMakeFiles/lib527.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib527.dir/first.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c > CMakeFiles/lib527.dir/first.c.i

tests/libtest/CMakeFiles/lib527.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib527.dir/first.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c -o CMakeFiles/lib527.dir/first.c.s

tests/libtest/CMakeFiles/lib527.dir/testutil.c.o: tests/libtest/CMakeFiles/lib527.dir/flags.make
tests/libtest/CMakeFiles/lib527.dir/testutil.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/testutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libtest/CMakeFiles/lib527.dir/testutil.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib527.dir/testutil.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/testutil.c

tests/libtest/CMakeFiles/lib527.dir/testutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib527.dir/testutil.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/testutil.c > CMakeFiles/lib527.dir/testutil.c.i

tests/libtest/CMakeFiles/lib527.dir/testutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib527.dir/testutil.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/testutil.c -o CMakeFiles/lib527.dir/testutil.c.s

tests/libtest/CMakeFiles/lib527.dir/__/__/lib/warnless.c.o: tests/libtest/CMakeFiles/lib527.dir/flags.make
tests/libtest/CMakeFiles/lib527.dir/__/__/lib/warnless.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/libtest/CMakeFiles/lib527.dir/__/__/lib/warnless.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib527.dir/__/__/lib/warnless.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c

tests/libtest/CMakeFiles/lib527.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib527.dir/__/__/lib/warnless.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c > CMakeFiles/lib527.dir/__/__/lib/warnless.c.i

tests/libtest/CMakeFiles/lib527.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib527.dir/__/__/lib/warnless.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c -o CMakeFiles/lib527.dir/__/__/lib/warnless.c.s

# Object files for target lib527
lib527_OBJECTS = \
"CMakeFiles/lib527.dir/lib526.c.o" \
"CMakeFiles/lib527.dir/first.c.o" \
"CMakeFiles/lib527.dir/testutil.c.o" \
"CMakeFiles/lib527.dir/__/__/lib/warnless.c.o"

# External object files for target lib527
lib527_EXTERNAL_OBJECTS =

tests/libtest/lib527: tests/libtest/CMakeFiles/lib527.dir/lib526.c.o
tests/libtest/lib527: tests/libtest/CMakeFiles/lib527.dir/first.c.o
tests/libtest/lib527: tests/libtest/CMakeFiles/lib527.dir/testutil.c.o
tests/libtest/lib527: tests/libtest/CMakeFiles/lib527.dir/__/__/lib/warnless.c.o
tests/libtest/lib527: tests/libtest/CMakeFiles/lib527.dir/build.make
tests/libtest/lib527: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/crypto/library/libmbedcrypto.a
tests/libtest/lib527: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedtls.a
tests/libtest/lib527: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedx509.a
tests/libtest/lib527: lib/libcurl.a
tests/libtest/lib527: /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/i686-linux-android/libz.a
tests/libtest/lib527: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/crypto/library/libmbedcrypto.a
tests/libtest/lib527: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedtls.a
tests/libtest/lib527: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedx509.a
tests/libtest/lib527: tests/libtest/CMakeFiles/lib527.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable lib527"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib527.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib527.dir/build: tests/libtest/lib527

.PHONY : tests/libtest/CMakeFiles/lib527.dir/build

tests/libtest/CMakeFiles/lib527.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib527.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib527.dir/clean

tests/libtest/CMakeFiles/lib527.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest/CMakeFiles/lib527.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib527.dir/depend

