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
include CMakeFiles/logging_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/logging_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/logging_test.dir/flags.make

CMakeFiles/logging_test.dir/util/testutil.cc.o: CMakeFiles/logging_test.dir/flags.make
CMakeFiles/logging_test.dir/util/testutil.cc.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/logging_test.dir/util/testutil.cc.o"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logging_test.dir/util/testutil.cc.o -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc

CMakeFiles/logging_test.dir/util/testutil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logging_test.dir/util/testutil.cc.i"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc > CMakeFiles/logging_test.dir/util/testutil.cc.i

CMakeFiles/logging_test.dir/util/testutil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logging_test.dir/util/testutil.cc.s"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/testutil.cc -o CMakeFiles/logging_test.dir/util/testutil.cc.s

CMakeFiles/logging_test.dir/util/logging_test.cc.o: CMakeFiles/logging_test.dir/flags.make
CMakeFiles/logging_test.dir/util/logging_test.cc.o: /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/logging_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/logging_test.dir/util/logging_test.cc.o"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logging_test.dir/util/logging_test.cc.o -c /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/logging_test.cc

CMakeFiles/logging_test.dir/util/logging_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logging_test.dir/util/logging_test.cc.i"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/logging_test.cc > CMakeFiles/logging_test.dir/util/logging_test.cc.i

CMakeFiles/logging_test.dir/util/logging_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logging_test.dir/util/logging_test.cc.s"
	/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=armv7-none-linux-androideabi16 --gcc-toolchain=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64 --sysroot=/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb/util/logging_test.cc -o CMakeFiles/logging_test.dir/util/logging_test.cc.s

# Object files for target logging_test
logging_test_OBJECTS = \
"CMakeFiles/logging_test.dir/util/testutil.cc.o" \
"CMakeFiles/logging_test.dir/util/logging_test.cc.o"

# External object files for target logging_test
logging_test_EXTERNAL_OBJECTS =

logging_test: CMakeFiles/logging_test.dir/util/testutil.cc.o
logging_test: CMakeFiles/logging_test.dir/util/logging_test.cc.o
logging_test: CMakeFiles/logging_test.dir/build.make
logging_test: libleveldb.a
logging_test: lib/libgmock.a
logging_test: lib/libgtest.a
logging_test: CMakeFiles/logging_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable logging_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logging_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/logging_test.dir/build: logging_test

.PHONY : CMakeFiles/logging_test.dir/build

CMakeFiles/logging_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/logging_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/logging_test.dir/clean

CMakeFiles/logging_test.dir/depend:
	cd /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/kv-store/external/leveldb_build/android_armeabi_v7a/CMakeFiles/logging_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/logging_test.dir/depend

