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
CMAKE_BINARY_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac

# Include any dependencies generated for this target.
include tests/unit/CMakeFiles/unit1330.dir/depend.make

# Include the progress variables for this target.
include tests/unit/CMakeFiles/unit1330.dir/progress.make

# Include the compile flags for this target's objects.
include tests/unit/CMakeFiles/unit1330.dir/flags.make

tests/unit/CMakeFiles/unit1330.dir/unit1330.c.o: tests/unit/CMakeFiles/unit1330.dir/flags.make
tests/unit/CMakeFiles/unit1330.dir/unit1330.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1330.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/unit/CMakeFiles/unit1330.dir/unit1330.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unit1330.dir/unit1330.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1330.c

tests/unit/CMakeFiles/unit1330.dir/unit1330.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unit1330.dir/unit1330.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1330.c > CMakeFiles/unit1330.dir/unit1330.c.i

tests/unit/CMakeFiles/unit1330.dir/unit1330.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unit1330.dir/unit1330.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit/unit1330.c -o CMakeFiles/unit1330.dir/unit1330.c.s

tests/unit/CMakeFiles/unit1330.dir/__/libtest/first.c.o: tests/unit/CMakeFiles/unit1330.dir/flags.make
tests/unit/CMakeFiles/unit1330.dir/__/libtest/first.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/unit/CMakeFiles/unit1330.dir/__/libtest/first.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unit1330.dir/__/libtest/first.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c

tests/unit/CMakeFiles/unit1330.dir/__/libtest/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unit1330.dir/__/libtest/first.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c > CMakeFiles/unit1330.dir/__/libtest/first.c.i

tests/unit/CMakeFiles/unit1330.dir/__/libtest/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unit1330.dir/__/libtest/first.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c -o CMakeFiles/unit1330.dir/__/libtest/first.c.s

# Object files for target unit1330
unit1330_OBJECTS = \
"CMakeFiles/unit1330.dir/unit1330.c.o" \
"CMakeFiles/unit1330.dir/__/libtest/first.c.o"

# External object files for target unit1330
unit1330_EXTERNAL_OBJECTS =

tests/unit/unit1330: tests/unit/CMakeFiles/unit1330.dir/unit1330.c.o
tests/unit/unit1330: tests/unit/CMakeFiles/unit1330.dir/__/libtest/first.c.o
tests/unit/unit1330: tests/unit/CMakeFiles/unit1330.dir/build.make
tests/unit/unit1330: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/unit/unit1330: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/unit/unit1330: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/unit/unit1330: lib/libcurl.a
tests/unit/unit1330: /usr/lib/libz.dylib
tests/unit/unit1330: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/unit/unit1330: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/unit/unit1330: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/unit/unit1330: tests/unit/CMakeFiles/unit1330.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable unit1330"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit1330.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/unit/CMakeFiles/unit1330.dir/build: tests/unit/unit1330

.PHONY : tests/unit/CMakeFiles/unit1330.dir/build

tests/unit/CMakeFiles/unit1330.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit && $(CMAKE_COMMAND) -P CMakeFiles/unit1330.dir/cmake_clean.cmake
.PHONY : tests/unit/CMakeFiles/unit1330.dir/clean

tests/unit/CMakeFiles/unit1330.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/unit /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/unit/CMakeFiles/unit1330.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/unit/CMakeFiles/unit1330.dir/depend

