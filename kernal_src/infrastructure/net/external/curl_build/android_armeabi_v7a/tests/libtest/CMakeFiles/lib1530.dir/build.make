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
CMAKE_SOURCE_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a

# Include any dependencies generated for this target.
include tests/libtest/CMakeFiles/lib1530.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib1530.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib1530.dir/flags.make

tests/libtest/CMakeFiles/lib1530.dir/lib1530.c.o: tests/libtest/CMakeFiles/lib1530.dir/flags.make
tests/libtest/CMakeFiles/lib1530.dir/lib1530.c.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/lib1530.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib1530.dir/lib1530.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib1530.dir/lib1530.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/lib1530.c

tests/libtest/CMakeFiles/lib1530.dir/lib1530.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1530.dir/lib1530.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/lib1530.c > CMakeFiles/lib1530.dir/lib1530.c.i

tests/libtest/CMakeFiles/lib1530.dir/lib1530.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1530.dir/lib1530.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/lib1530.c -o CMakeFiles/lib1530.dir/lib1530.c.s

tests/libtest/CMakeFiles/lib1530.dir/first.c.o: tests/libtest/CMakeFiles/lib1530.dir/flags.make
tests/libtest/CMakeFiles/lib1530.dir/first.c.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib1530.dir/first.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib1530.dir/first.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/first.c

tests/libtest/CMakeFiles/lib1530.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1530.dir/first.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/first.c > CMakeFiles/lib1530.dir/first.c.i

tests/libtest/CMakeFiles/lib1530.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1530.dir/first.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/first.c -o CMakeFiles/lib1530.dir/first.c.s

tests/libtest/CMakeFiles/lib1530.dir/testutil.c.o: tests/libtest/CMakeFiles/lib1530.dir/flags.make
tests/libtest/CMakeFiles/lib1530.dir/testutil.c.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/testutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libtest/CMakeFiles/lib1530.dir/testutil.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib1530.dir/testutil.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/testutil.c

tests/libtest/CMakeFiles/lib1530.dir/testutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1530.dir/testutil.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/testutil.c > CMakeFiles/lib1530.dir/testutil.c.i

tests/libtest/CMakeFiles/lib1530.dir/testutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1530.dir/testutil.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest/testutil.c -o CMakeFiles/lib1530.dir/testutil.c.s

tests/libtest/CMakeFiles/lib1530.dir/__/__/lib/warnless.c.o: tests/libtest/CMakeFiles/lib1530.dir/flags.make
tests/libtest/CMakeFiles/lib1530.dir/__/__/lib/warnless.c.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/libtest/CMakeFiles/lib1530.dir/__/__/lib/warnless.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib1530.dir/__/__/lib/warnless.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/lib/warnless.c

tests/libtest/CMakeFiles/lib1530.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1530.dir/__/__/lib/warnless.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/lib/warnless.c > CMakeFiles/lib1530.dir/__/__/lib/warnless.c.i

tests/libtest/CMakeFiles/lib1530.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1530.dir/__/__/lib/warnless.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/lib/warnless.c -o CMakeFiles/lib1530.dir/__/__/lib/warnless.c.s

# Object files for target lib1530
lib1530_OBJECTS = \
"CMakeFiles/lib1530.dir/lib1530.c.o" \
"CMakeFiles/lib1530.dir/first.c.o" \
"CMakeFiles/lib1530.dir/testutil.c.o" \
"CMakeFiles/lib1530.dir/__/__/lib/warnless.c.o"

# External object files for target lib1530
lib1530_EXTERNAL_OBJECTS =

tests/libtest/lib1530: tests/libtest/CMakeFiles/lib1530.dir/lib1530.c.o
tests/libtest/lib1530: tests/libtest/CMakeFiles/lib1530.dir/first.c.o
tests/libtest/lib1530: tests/libtest/CMakeFiles/lib1530.dir/testutil.c.o
tests/libtest/lib1530: tests/libtest/CMakeFiles/lib1530.dir/__/__/lib/warnless.c.o
tests/libtest/lib1530: tests/libtest/CMakeFiles/lib1530.dir/build.make
tests/libtest/lib1530: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/libtest/lib1530: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/libtest/lib1530: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/libtest/lib1530: lib/libcurl.a
tests/libtest/lib1530: /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/arm-linux-androideabi/libz.a
tests/libtest/lib1530: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/libtest/lib1530: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/libtest/lib1530: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/libtest/lib1530: tests/libtest/CMakeFiles/lib1530.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable lib1530"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib1530.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib1530.dir/build: tests/libtest/lib1530

.PHONY : tests/libtest/CMakeFiles/lib1530.dir/build

tests/libtest/CMakeFiles/lib1530.dir/clean:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib1530.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib1530.dir/clean

tests/libtest/CMakeFiles/lib1530.dir/depend:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/tests/libtest /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl_build/android_armeabi_v7a/tests/libtest/CMakeFiles/lib1530.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib1530.dir/depend

