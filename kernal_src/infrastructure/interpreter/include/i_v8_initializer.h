
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
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
};


}}