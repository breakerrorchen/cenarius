
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

// virtual machine globally unique execution environment
static std::unique_ptr<Platform> _g_platform;

// initialize the environment of the interpreter
bool i_initializer::start() {
    static std::once_flag _once;
    std::call_once(_once, []() {
        V8::InitializeICU();
        _g_platform = platform::NewDefaultPlatform();
        V8::InitializePlatform(_g_platform.get());
        V8::Initialize();
    });
    return true;
}

// clean up the execution environment of the interpreter
// all interpreter contexts will be unavailable
bool i_initializer::dispose() {
    static std::once_flag _once;
    std::call_once(_once, []() {
        if (!_g_platform) return;
        _g_platform.release();
        V8::Dispose();
        V8::ShutdownPlatform();
    });
    return true;
}

#endif//__use_v8_backend__