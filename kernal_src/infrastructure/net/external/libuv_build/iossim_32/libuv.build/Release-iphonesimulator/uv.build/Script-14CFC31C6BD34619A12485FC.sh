#!/bin/sh
make -C /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32 -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/CMakeScripts/uv_postBuildPhase.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
