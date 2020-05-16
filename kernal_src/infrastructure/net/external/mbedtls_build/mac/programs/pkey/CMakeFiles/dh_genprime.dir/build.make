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
CMAKE_BINARY_DIR = /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac

# Include any dependencies generated for this target.
include programs/pkey/CMakeFiles/dh_genprime.dir/depend.make

# Include the progress variables for this target.
include programs/pkey/CMakeFiles/dh_genprime.dir/progress.make

# Include the compile flags for this target's objects.
include programs/pkey/CMakeFiles/dh_genprime.dir/flags.make

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o: programs/pkey/CMakeFiles/dh_genprime.dir/flags.make
programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/pkey/dh_genprime.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dh_genprime.dir/dh_genprime.c.o   -c /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/pkey/dh_genprime.c

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dh_genprime.dir/dh_genprime.c.i"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/pkey/dh_genprime.c > CMakeFiles/dh_genprime.dir/dh_genprime.c.i

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dh_genprime.dir/dh_genprime.c.s"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/pkey/dh_genprime.c -o CMakeFiles/dh_genprime.dir/dh_genprime.c.s

# Object files for target dh_genprime
dh_genprime_OBJECTS = \
"CMakeFiles/dh_genprime.dir/dh_genprime.c.o"

# External object files for target dh_genprime
dh_genprime_EXTERNAL_OBJECTS =

programs/pkey/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o
programs/pkey/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/build.make
programs/pkey/dh_genprime: crypto/library/libmbedcrypto.a
programs/pkey/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dh_genprime"
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dh_genprime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/pkey/CMakeFiles/dh_genprime.dir/build: programs/pkey/dh_genprime

.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/build

programs/pkey/CMakeFiles/dh_genprime.dir/clean:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey && $(CMAKE_COMMAND) -P CMakeFiles/dh_genprime.dir/cmake_clean.cmake
.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/clean

programs/pkey/CMakeFiles/dh_genprime.dir/depend:
	cd /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls/programs/pkey /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/mbedtls_build/mac/programs/pkey/CMakeFiles/dh_genprime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/depend

