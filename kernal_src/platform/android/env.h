
#pragma once
#include <common/base_header_inct.h>
#include <common/logger.h>
#include <stdint.h>
#include <unistd.h>
#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/looper.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <sys/eventfd.h>

namespace cenarius { namespace platform {
class env final {
public:
	// gets the Java virtual machine for the current platform
    static JavaVM* vm();

    /**
     * gets the Java environment context of the current thread.
     * if not, one will be installed automatically.
	 * the Java thread context is automatically released as the thread terminates.
	 *
	 * !!! No thread with java context installed, 
	 * calling Java function will operate process Crash
	 * */
    static JNIEnv* current_thread_env();
};


}}