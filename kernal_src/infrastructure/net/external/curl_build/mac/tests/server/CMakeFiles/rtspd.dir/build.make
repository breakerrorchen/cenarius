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
include tests/server/CMakeFiles/rtspd.dir/depend.make

# Include the progress variables for this target.
include tests/server/CMakeFiles/rtspd.dir/progress.make

# Include the compile flags for this target's objects.
include tests/server/CMakeFiles/rtspd.dir/flags.make

tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c > CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/mprintf.c -o CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.s

tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/nonblock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/nonblock.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/nonblock.c > CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/nonblock.c -o CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.s

tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/strtoofft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/strtoofft.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/strtoofft.c > CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/strtoofft.c -o CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.s

tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/warnless.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c > CMakeFiles/rtspd.dir/__/__/lib/warnless.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/warnless.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/warnless.c -o CMakeFiles/rtspd.dir/__/__/lib/warnless.c.s

tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c > CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/curl_ctype.c -o CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.s

tests/server/CMakeFiles/rtspd.dir/getpart.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/getpart.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/getpart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object tests/server/CMakeFiles/rtspd.dir/getpart.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/getpart.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/getpart.c

tests/server/CMakeFiles/rtspd.dir/getpart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/getpart.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/getpart.c > CMakeFiles/rtspd.dir/getpart.c.i

tests/server/CMakeFiles/rtspd.dir/getpart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/getpart.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/getpart.c -o CMakeFiles/rtspd.dir/getpart.c.s

tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/base64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/base64.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/base64.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/base64.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/base64.c > CMakeFiles/rtspd.dir/__/__/lib/base64.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/base64.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/base64.c -o CMakeFiles/rtspd.dir/__/__/lib/base64.c.s

tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/memdebug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/memdebug.c

tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/memdebug.c > CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.i

tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/lib/memdebug.c -o CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.s

tests/server/CMakeFiles/rtspd.dir/util.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/util.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object tests/server/CMakeFiles/rtspd.dir/util.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/util.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/util.c

tests/server/CMakeFiles/rtspd.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/util.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/util.c > CMakeFiles/rtspd.dir/util.c.i

tests/server/CMakeFiles/rtspd.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/util.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/util.c -o CMakeFiles/rtspd.dir/util.c.s

tests/server/CMakeFiles/rtspd.dir/rtspd.c.o: tests/server/CMakeFiles/rtspd.dir/flags.make
tests/server/CMakeFiles/rtspd.dir/rtspd.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/rtspd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object tests/server/CMakeFiles/rtspd.dir/rtspd.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/rtspd.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/rtspd.c

tests/server/CMakeFiles/rtspd.dir/rtspd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/rtspd.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/rtspd.c > CMakeFiles/rtspd.dir/rtspd.c.i

tests/server/CMakeFiles/rtspd.dir/rtspd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/rtspd.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server/rtspd.c -o CMakeFiles/rtspd.dir/rtspd.c.s

# Object files for target rtspd
rtspd_OBJECTS = \
"CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o" \
"CMakeFiles/rtspd.dir/getpart.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/base64.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o" \
"CMakeFiles/rtspd.dir/util.c.o" \
"CMakeFiles/rtspd.dir/rtspd.c.o"

# External object files for target rtspd
rtspd_EXTERNAL_OBJECTS =

tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/getpart.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/util.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/rtspd.c.o
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/build.make
tests/server/rtspd: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedx509.a
tests/server/rtspd: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/library/libmbedtls.a
tests/server/rtspd: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/crypto/library/libmbedcrypto.a
tests/server/rtspd: /usr/lib/libz.dylib
tests/server/rtspd: tests/server/CMakeFiles/rtspd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable rtspd"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rtspd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/server/CMakeFiles/rtspd.dir/build: tests/server/rtspd

.PHONY : tests/server/CMakeFiles/rtspd.dir/build

tests/server/CMakeFiles/rtspd.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server && $(CMAKE_COMMAND) -P CMakeFiles/rtspd.dir/cmake_clean.cmake
.PHONY : tests/server/CMakeFiles/rtspd.dir/clean

tests/server/CMakeFiles/rtspd.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl/tests/server /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/curl_build/mac/tests/server/CMakeFiles/rtspd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/server/CMakeFiles/rtspd.dir/depend

