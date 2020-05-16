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
include programs/ssl/CMakeFiles/ssl_pthread_server.dir/depend.make

# Include the progress variables for this target.
include programs/ssl/CMakeFiles/ssl_pthread_server.dir/progress.make

# Include the compile flags for this target's objects.
include programs/ssl/CMakeFiles/ssl_pthread_server.dir/flags.make

programs/ssl/CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.o: programs/ssl/CMakeFiles/ssl_pthread_server.dir/flags.make
programs/ssl/CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.o: ../programs/ssl/ssl_pthread_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/ssl/CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.o"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.o   -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_pthread_server.c

programs/ssl/CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.i"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_pthread_server.c > CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.i

programs/ssl/CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.s"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl/ssl_pthread_server.c -o CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.s

# Object files for target ssl_pthread_server
ssl_pthread_server_OBJECTS = \
"CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.o"

# External object files for target ssl_pthread_server
ssl_pthread_server_EXTERNAL_OBJECTS =

programs/ssl/ssl_pthread_server: programs/ssl/CMakeFiles/ssl_pthread_server.dir/ssl_pthread_server.c.o
programs/ssl/ssl_pthread_server: programs/ssl/CMakeFiles/ssl_pthread_server.dir/build.make
programs/ssl/ssl_pthread_server: library/libmbedtls.a
programs/ssl/ssl_pthread_server: library/libmbedx509.a
programs/ssl/ssl_pthread_server: crypto/library/libmbedcrypto.a
programs/ssl/ssl_pthread_server: programs/ssl/CMakeFiles/ssl_pthread_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ssl_pthread_server"
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ssl_pthread_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/ssl/CMakeFiles/ssl_pthread_server.dir/build: programs/ssl/ssl_pthread_server

.PHONY : programs/ssl/CMakeFiles/ssl_pthread_server.dir/build

programs/ssl/CMakeFiles/ssl_pthread_server.dir/clean:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl && $(CMAKE_COMMAND) -P CMakeFiles/ssl_pthread_server.dir/cmake_clean.cmake
.PHONY : programs/ssl/CMakeFiles/ssl_pthread_server.dir/clean

programs/ssl/CMakeFiles/ssl_pthread_server.dir/depend:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/programs/ssl /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/cmake_build/programs/ssl/CMakeFiles/ssl_pthread_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/ssl/CMakeFiles/ssl_pthread_server.dir/depend

