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
CMAKE_SOURCE_DIR = /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac

# Include any dependencies generated for this target.
include CMakeFiles/version_set_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/version_set_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/version_set_test.dir/flags.make

CMakeFiles/version_set_test.dir/util/testutil.cc.o: CMakeFiles/version_set_test.dir/flags.make
CMakeFiles/version_set_test.dir/util/testutil.cc.o: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/version_set_test.dir/util/testutil.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/version_set_test.dir/util/testutil.cc.o -c /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc

CMakeFiles/version_set_test.dir/util/testutil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/version_set_test.dir/util/testutil.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc > CMakeFiles/version_set_test.dir/util/testutil.cc.i

CMakeFiles/version_set_test.dir/util/testutil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/version_set_test.dir/util/testutil.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc -o CMakeFiles/version_set_test.dir/util/testutil.cc.s

CMakeFiles/version_set_test.dir/db/version_set_test.cc.o: CMakeFiles/version_set_test.dir/flags.make
CMakeFiles/version_set_test.dir/db/version_set_test.cc.o: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/db/version_set_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/version_set_test.dir/db/version_set_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/version_set_test.dir/db/version_set_test.cc.o -c /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/db/version_set_test.cc

CMakeFiles/version_set_test.dir/db/version_set_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/version_set_test.dir/db/version_set_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/db/version_set_test.cc > CMakeFiles/version_set_test.dir/db/version_set_test.cc.i

CMakeFiles/version_set_test.dir/db/version_set_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/version_set_test.dir/db/version_set_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/db/version_set_test.cc -o CMakeFiles/version_set_test.dir/db/version_set_test.cc.s

# Object files for target version_set_test
version_set_test_OBJECTS = \
"CMakeFiles/version_set_test.dir/util/testutil.cc.o" \
"CMakeFiles/version_set_test.dir/db/version_set_test.cc.o"

# External object files for target version_set_test
version_set_test_EXTERNAL_OBJECTS =

version_set_test: CMakeFiles/version_set_test.dir/util/testutil.cc.o
version_set_test: CMakeFiles/version_set_test.dir/db/version_set_test.cc.o
version_set_test: CMakeFiles/version_set_test.dir/build.make
version_set_test: libleveldb.a
version_set_test: lib/libgmock.a
version_set_test: lib/libgtest.a
version_set_test: CMakeFiles/version_set_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable version_set_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/version_set_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/version_set_test.dir/build: version_set_test

.PHONY : CMakeFiles/version_set_test.dir/build

CMakeFiles/version_set_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/version_set_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/version_set_test.dir/clean

CMakeFiles/version_set_test.dir/depend:
	cd /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/mac/CMakeFiles/version_set_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/version_set_test.dir/depend

