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
include tests/libtest/CMakeFiles/lib1551.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib1551.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib1551.dir/flags.make

tests/libtest/CMakeFiles/lib1551.dir/lib1551.c.o: tests/libtest/CMakeFiles/lib1551.dir/flags.make
tests/libtest/CMakeFiles/lib1551.dir/lib1551.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib1551.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib1551.dir/lib1551.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib1551.dir/lib1551.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib1551.c

tests/libtest/CMakeFiles/lib1551.dir/lib1551.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1551.dir/lib1551.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib1551.c > CMakeFiles/lib1551.dir/lib1551.c.i

tests/libtest/CMakeFiles/lib1551.dir/lib1551.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1551.dir/lib1551.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib1551.c -o CMakeFiles/lib1551.dir/lib1551.c.s

tests/libtest/CMakeFiles/lib1551.dir/first.c.o: tests/libtest/CMakeFiles/lib1551.dir/flags.make
tests/libtest/CMakeFiles/lib1551.dir/first.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib1551.dir/first.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib1551.dir/first.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c

tests/libtest/CMakeFiles/lib1551.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib1551.dir/first.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c > CMakeFiles/lib1551.dir/first.c.i

tests/libtest/CMakeFiles/lib1551.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib1551.dir/first.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c -o CMakeFiles/lib1551.dir/first.c.s

# Object files for target lib1551
lib1551_OBJECTS = \
"CMakeFiles/lib1551.dir/lib1551.c.o" \
"CMakeFiles/lib1551.dir/first.c.o"

# External object files for target lib1551
lib1551_EXTERNAL_OBJECTS =

tests/libtest/lib1551: tests/libtest/CMakeFiles/lib1551.dir/lib1551.c.o
tests/libtest/lib1551: tests/libtest/CMakeFiles/lib1551.dir/first.c.o
tests/libtest/lib1551: tests/libtest/CMakeFiles/lib1551.dir/build.make
tests/libtest/lib1551: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/libtest/lib1551: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/libtest/lib1551: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/libtest/lib1551: lib/libcurl.a
tests/libtest/lib1551: /usr/lib/libz.dylib
tests/libtest/lib1551: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/libtest/lib1551: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/libtest/lib1551: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/libtest/lib1551: tests/libtest/CMakeFiles/lib1551.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lib1551"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib1551.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib1551.dir/build: tests/libtest/lib1551

.PHONY : tests/libtest/CMakeFiles/lib1551.dir/build

tests/libtest/CMakeFiles/lib1551.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib1551.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib1551.dir/clean

tests/libtest/CMakeFiles/lib1551.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest/CMakeFiles/lib1551.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib1551.dir/depend

