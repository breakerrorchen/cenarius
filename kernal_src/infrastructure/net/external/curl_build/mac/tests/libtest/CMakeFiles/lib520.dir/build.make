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
include tests/libtest/CMakeFiles/lib520.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib520.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib520.dir/flags.make

tests/libtest/CMakeFiles/lib520.dir/lib520.c.o: tests/libtest/CMakeFiles/lib520.dir/flags.make
tests/libtest/CMakeFiles/lib520.dir/lib520.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib520.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib520.dir/lib520.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib520.dir/lib520.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib520.c

tests/libtest/CMakeFiles/lib520.dir/lib520.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib520.dir/lib520.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib520.c > CMakeFiles/lib520.dir/lib520.c.i

tests/libtest/CMakeFiles/lib520.dir/lib520.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib520.dir/lib520.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/lib520.c -o CMakeFiles/lib520.dir/lib520.c.s

tests/libtest/CMakeFiles/lib520.dir/first.c.o: tests/libtest/CMakeFiles/lib520.dir/flags.make
tests/libtest/CMakeFiles/lib520.dir/first.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib520.dir/first.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lib520.dir/first.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c

tests/libtest/CMakeFiles/lib520.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib520.dir/first.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c > CMakeFiles/lib520.dir/first.c.i

tests/libtest/CMakeFiles/lib520.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib520.dir/first.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest/first.c -o CMakeFiles/lib520.dir/first.c.s

# Object files for target lib520
lib520_OBJECTS = \
"CMakeFiles/lib520.dir/lib520.c.o" \
"CMakeFiles/lib520.dir/first.c.o"

# External object files for target lib520
lib520_EXTERNAL_OBJECTS =

tests/libtest/lib520: tests/libtest/CMakeFiles/lib520.dir/lib520.c.o
tests/libtest/lib520: tests/libtest/CMakeFiles/lib520.dir/first.c.o
tests/libtest/lib520: tests/libtest/CMakeFiles/lib520.dir/build.make
tests/libtest/lib520: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/libtest/lib520: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/libtest/lib520: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/libtest/lib520: lib/libcurl.a
tests/libtest/lib520: /usr/lib/libz.dylib
tests/libtest/lib520: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/libtest/lib520: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/libtest/lib520: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/libtest/lib520: tests/libtest/CMakeFiles/lib520.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lib520"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib520.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib520.dir/build: tests/libtest/lib520

.PHONY : tests/libtest/CMakeFiles/lib520.dir/build

tests/libtest/CMakeFiles/lib520.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib520.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib520.dir/clean

tests/libtest/CMakeFiles/lib520.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/libtest/CMakeFiles/lib520.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib520.dir/depend

