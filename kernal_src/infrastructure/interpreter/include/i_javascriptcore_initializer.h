
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_initializer decalre
 * The global initialization of the interpreter requires
 * an initial change after the first use,
 * and a dispose after the completion
 * */
class i_initializer final {
    __interpreter_friend_class_declare_list__
public:
    // initialize the environment of the interpreter
    static bool start();
    // clean up the execution environment of the interpreter
    // all interpreter contexts will be unavailable
    static bool dispose();

protected:
    // javascript string stands for `length`
    // in order to improve performance, 
    // this string will be used in many subsequent places, 
    // so define it here in advance
    static JSStringRef _$_length_;

    // empty class
    static JSClassRef _$_class_;
};

    
}}