#include "common/logger.h"
#include "env.h"
#include "runtime_isolate.h"
using namespace cenarius;
using namespace platform;

#define CENARIUS_PACKAGE(CLASS_NAME, FUNC)              \
    Java_com_cenarius_component_##CLASS_NAME##_##FUNC

// TorchController.ntCreate
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntCreateInstance)(
    JNIEnv* env, jobject) {
    auto isolate = new(std::nothrow)runtime_isolate();
    if (isolate) {
        isolate->on_create();
    }
    return reinterpret_cast<jlong>(isolate);
}

// TorchController.ntStartupScript
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntStartupScript)(
    JNIEnv* env, jobject, jlong instance, jstring script)  {
    auto ptr = reinterpret_cast<runtime_isolate*>(instance);
    if (nullptr == ptr) return 0;
    std::string code;
    if (env && script) {
        const jsize len = env->GetStringUTFLength(script);
        const char* buffer = env
            ->GetStringUTFChars(script, (jboolean*)0);
        code.append(buffer, len);
        env->ReleaseStringUTFChars(script, buffer);
    }

    if (!code.empty()) {
        ptr->startup_script(code, true);
    }
    return 0;
}

// TorchController.ntSendVsyncEvent
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntSendVsyncEvent)(
    JNIEnv* env, jobject, jlong instance) {
    auto ptr = reinterpret_cast<runtime_isolate*>(instance);
    if (ptr) {
        ptr->on_receive_vsync();
    }
    return 0;
}

// TorchController.ntSurfaceCreated
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntSurfaceCreated)(
    JNIEnv* env, jobject, jlong instance, jobject surface) {
    auto _surface = ::ANativeWindow_fromSurface(env, surface);
    auto ptr = reinterpret_cast<runtime_isolate*>(instance);
    if (ptr) {
        ptr->on_surface_created(_surface);
    } else if (_surface) {
        ::ANativeWindow_release(_surface);
    }
    return 0;
}

// TorchController.ntSurfaceChanged
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntSurfaceChanged)(JNIEnv* env, 
    jobject, jlong instance, jobject surface, jfloat scale) {
    auto _surface = ::ANativeWindow_fromSurface(env, surface);
    auto ptr = reinterpret_cast<runtime_isolate*>(instance);
    if (ptr) {
        ptr->on_surface_changed(_surface, scale);
    } else if (_surface) {
        ::ANativeWindow_release(_surface);
    }
    return 0;
}

// TorchController.ntSurfaceDestroyed
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntSurfaceDestroyed)(
    JNIEnv* env, jobject, jlong instance) {
    auto ptr = reinterpret_cast<runtime_isolate*>(instance);
    if (ptr) {
        ptr->on_surface_destroy();
    }
    return 0;
}

// TorchController.ntFinalization
extern "C" JNIEXPORT jlong JNICALL CENARIUS_PACKAGE(
    TorchController, ntFinalization)(
    JNIEnv* env, jobject, jlong instance) {
    auto ptr = reinterpret_cast<runtime_isolate*>(instance);
    if (ptr) {
        ptr->on_finalization(); delete ptr;
    }
    return 0;
}