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
include tests/libtest/CMakeFiles/chkdecimalpoint.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/chkdecimalpoint.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/chkdecimalpoint.dir/flags.make

tests/libtest/CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.o: tests/libtest/CMakeFiles/chkdecimalpoint.dir/flags.make
tests/libtest/CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/chkdecimalpoint.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/chkdecimalpoint.c

tests/libtest/CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/chkdecimalpoint.c > CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.i

tests/libtest/CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/chkdecimalpoint.c -o CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.s

tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.o: tests/libtest/CMakeFiles/chkdecimalpoint.dir/flags.make
tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c

tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c > CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.i

tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c -o CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.s

tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.o: tests/libtest/CMakeFiles/chkdecimalpoint.dir/flags.make
tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c

tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c > CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.i

tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang --target=i686-none-linux-android16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c -o CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.s

# Object files for target chkdecimalpoint
chkdecimalpoint_OBJECTS = \
"CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.o" \
"CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.o" \
"CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.o"

# External object files for target chkdecimalpoint
chkdecimalpoint_EXTERNAL_OBJECTS =

tests/libtest/chkdecimalpoint: tests/libtest/CMakeFiles/chkdecimalpoint.dir/chkdecimalpoint.c.o
tests/libtest/chkdecimalpoint: tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/mprintf.c.o
tests/libtest/chkdecimalpoint: tests/libtest/CMakeFiles/chkdecimalpoint.dir/__/__/lib/curl_ctype.c.o
tests/libtest/chkdecimalpoint: tests/libtest/CMakeFiles/chkdecimalpoint.dir/build.make
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/crypto/library/libmbedcrypto.a
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedtls.a
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedx509.a
tests/libtest/chkdecimalpoint: lib/libcurl.a
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/lib/i686-linux-android/libz.a
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/crypto/library/libmbedcrypto.a
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedtls.a
tests/libtest/chkdecimalpoint: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/android_x86/library/libmbedx509.a
tests/libtest/chkdecimalpoint: tests/libtest/CMakeFiles/chkdecimalpoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable chkdecimalpoint"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chkdecimalpoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/chkdecimalpoint.dir/build: tests/libtest/chkdecimalpoint

.PHONY : tests/libtest/CMakeFiles/chkdecimalpoint.dir/build

tests/libtest/CMakeFiles/chkdecimalpoint.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/chkdecimalpoint.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/chkdecimalpoint.dir/clean

tests/libtest/CMakeFiles/chkdecimalpoint.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86 /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/android_x86/tests/libtest/CMakeFiles/chkdecimalpoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/chkdecimalpoint.dir/depend

