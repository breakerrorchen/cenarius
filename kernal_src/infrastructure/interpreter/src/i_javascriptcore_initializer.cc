
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_initializer decalre
 * The global initialization of the interpreter requires
 * an initial change after the first use,
 * and a dispose after the completion
 * */
JSStringRef i_initializer::_$_length_ = nullptr;
JSClassRef  i_initializer::_$_class_  = nullptr;

// initialize the environment of the interpreter
bool i_initializer::start() {
    _$_length_ = JSStringCreateWithUTF8CString("length");
    _$_class_  = JSClassCreate(&kJSClassDefinitionEmpty);
    return true;
}

// clean up the execution environment of the interpreter
// all interpreter contexts will be unavailable
bool i_initializer::dispose() {
    JSStringRelease(_$_length_); 
    JSClassRelease (_$_class_ );
    return true;
}

#endif//__use_javascriptcore_backend__