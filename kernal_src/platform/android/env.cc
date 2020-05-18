
#include "env.h"
using namespace cenarius;
using namespace platform;

static thread_local JNIEnv* _g_thread_env = nullptr;
static JavaVM* _g_vm = nullptr; 
class jnienv_watcher final {
public:
	~jnienv_watcher() {
		if (_g_vm) {
			_g_vm->DetachCurrentThread();
			_g_thread_env = nullptr;

		}
	}
};
thread_local std::shared_ptr<jnienv_watcher> thread_env_watcher;

// Called by the jvm when the current module is first pulled up
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = nullptr;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    _g_vm = vm; _g_thread_env = env;
    thread_env_watcher = std::make_shared<jnienv_watcher>();
    return JNI_VERSION_1_4;
}

// 获取VM, 全局就一个VM
JavaVM* cenarius::platform::env::vm() { return _g_vm; }

// Java的JNI调用，需要在当前线程中Attach, 需要在线程结束后Detach
// 这里使用线程局部变量的生命周期来维护env
JNIEnv* cenarius::platform::env::current_thread_env() {
    if (_g_thread_env) { return _g_thread_env; }
    if (!_g_vm) { return nullptr; }
    _g_vm->AttachCurrentThread(&_g_thread_env, nullptr);
    thread_env_watcher = std::make_shared<jnienv_watcher>();
    return _g_thread_env;
}
