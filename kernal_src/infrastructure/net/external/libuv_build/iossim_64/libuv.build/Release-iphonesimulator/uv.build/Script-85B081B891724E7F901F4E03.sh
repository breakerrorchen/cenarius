#!/bin/sh
make -C /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_64 -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_64/CMakeScripts/uv_postBuildPhase.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
