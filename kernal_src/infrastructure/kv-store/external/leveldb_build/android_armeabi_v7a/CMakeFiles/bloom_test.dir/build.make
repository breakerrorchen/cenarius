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
CMAKE_SOURCE_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a

# Include any dependencies generated for this target.
include CMakeFiles/bloom_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bloom_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bloom_test.dir/flags.make

CMakeFiles/bloom_test.dir/util/testutil.cc.o: CMakeFiles/bloom_test.dir/flags.make
CMakeFiles/bloom_test.dir/util/testutil.cc.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bloom_test.dir/util/testutil.cc.o"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bloom_test.dir/util/testutil.cc.o -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc

CMakeFiles/bloom_test.dir/util/testutil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bloom_test.dir/util/testutil.cc.i"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc > CMakeFiles/bloom_test.dir/util/testutil.cc.i

CMakeFiles/bloom_test.dir/util/testutil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bloom_test.dir/util/testutil.cc.s"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc -o CMakeFiles/bloom_test.dir/util/testutil.cc.s

CMakeFiles/bloom_test.dir/util/bloom_test.cc.o: CMakeFiles/bloom_test.dir/flags.make
CMakeFiles/bloom_test.dir/util/bloom_test.cc.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/bloom_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bloom_test.dir/util/bloom_test.cc.o"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bloom_test.dir/util/bloom_test.cc.o -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/bloom_test.cc

CMakeFiles/bloom_test.dir/util/bloom_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bloom_test.dir/util/bloom_test.cc.i"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/bloom_test.cc > CMakeFiles/bloom_test.dir/util/bloom_test.cc.i

CMakeFiles/bloom_test.dir/util/bloom_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bloom_test.dir/util/bloom_test.cc.s"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/bloom_test.cc -o CMakeFiles/bloom_test.dir/util/bloom_test.cc.s

# Object files for target bloom_test
bloom_test_OBJECTS = \
"CMakeFiles/bloom_test.dir/util/testutil.cc.o" \
"CMakeFiles/bloom_test.dir/util/bloom_test.cc.o"

# External object files for target bloom_test
bloom_test_EXTERNAL_OBJECTS =

bloom_test: CMakeFiles/bloom_test.dir/util/testutil.cc.o
bloom_test: CMakeFiles/bloom_test.dir/util/bloom_test.cc.o
bloom_test: CMakeFiles/bloom_test.dir/build.make
bloom_test: libleveldb.a
bloom_test: lib/libgmock.a
bloom_test: lib/libgtest.a
bloom_test: CMakeFiles/bloom_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bloom_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bloom_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bloom_test.dir/build: bloom_test

.PHONY : CMakeFiles/bloom_test.dir/build

CMakeFiles/bloom_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bloom_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bloom_test.dir/clean

CMakeFiles/bloom_test.dir/depend:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles/bloom_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bloom_test.dir/depend

