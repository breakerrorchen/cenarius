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
CMAKE_BINARY_DIR = /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a

# Include any dependencies generated for this target.
include CMakeFiles/table_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/table_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/table_test.dir/flags.make

CMakeFiles/table_test.dir/util/testutil.cc.o: CMakeFiles/table_test.dir/flags.make
CMakeFiles/table_test.dir/util/testutil.cc.o: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/table_test.dir/util/testutil.cc.o"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/table_test.dir/util/testutil.cc.o -c /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc

CMakeFiles/table_test.dir/util/testutil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/table_test.dir/util/testutil.cc.i"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc > CMakeFiles/table_test.dir/util/testutil.cc.i

CMakeFiles/table_test.dir/util/testutil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/table_test.dir/util/testutil.cc.s"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/util/testutil.cc -o CMakeFiles/table_test.dir/util/testutil.cc.s

CMakeFiles/table_test.dir/table/table_test.cc.o: CMakeFiles/table_test.dir/flags.make
CMakeFiles/table_test.dir/table/table_test.cc.o: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/table/table_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/table_test.dir/table/table_test.cc.o"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/table_test.dir/table/table_test.cc.o -c /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/table/table_test.cc

CMakeFiles/table_test.dir/table/table_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/table_test.dir/table/table_test.cc.i"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/table/table_test.cc > CMakeFiles/table_test.dir/table/table_test.cc.i

CMakeFiles/table_test.dir/table/table_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/table_test.dir/table/table_test.cc.s"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb/table/table_test.cc -o CMakeFiles/table_test.dir/table/table_test.cc.s

# Object files for target table_test
table_test_OBJECTS = \
"CMakeFiles/table_test.dir/util/testutil.cc.o" \
"CMakeFiles/table_test.dir/table/table_test.cc.o"

# External object files for target table_test
table_test_EXTERNAL_OBJECTS =

table_test: CMakeFiles/table_test.dir/util/testutil.cc.o
table_test: CMakeFiles/table_test.dir/table/table_test.cc.o
table_test: CMakeFiles/table_test.dir/build.make
table_test: libleveldb.a
table_test: lib/libgmock.a
table_test: lib/libgtest.a
table_test: CMakeFiles/table_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable table_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/table_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/table_test.dir/build: table_test

.PHONY : CMakeFiles/table_test.dir/build

CMakeFiles/table_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/table_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/table_test.dir/clean

CMakeFiles/table_test.dir/depend:
	cd /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/android_arm64_v8a/CMakeFiles/table_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/table_test.dir/depend

