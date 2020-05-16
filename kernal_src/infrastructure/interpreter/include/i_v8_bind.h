
#pragma once
#include "i_v8_base.h"

#define _I_BIND_NULL() (::interpreter::i_invoker())
#define _I_BIND_FUNCTION(FUNCTION)                                                          \
    [&]()->::interpreter::i_invoker {                                                       \
        struct _{};                                                                         \
        i_invoke_function<_> connection;                                                    \
        i_invoke_function<_>::invoker_ = FUNCTION;                                          \
        return connection;                                                                  \
    }()                                                        
#define _I_BIND_1(CLASS_NAME)                                                               \
    [&]()->::interpreter::i_invoker {                                                       \
        struct _{};                                                                         \
        i_invoke_connection<CLASS_NAME, _> connection;                                      \
        i_invoke_connection<CLASS_NAME, _>::invoke_target_ = nullptr;                       \
        return connection;                                                                  \
    }()
#define _I_BIND_2(CLASS_NAME, FUNCTION)                                                     \
    [&]()->::interpreter::i_invoker {                                                       \
        using callback_t = void(CLASS_NAME::*)(::interpreter::i_parameter&);                \
        callback_t callback = &CLASS_NAME::FUNCTION;                                        \
        struct _{};                                                                         \
        i_invoke_connection<CLASS_NAME, _> connection;                                      \
        i_invoke_connection<CLASS_NAME, _>::invoke_target_ = callback;                      \
        return connection;                                                                  \
    }()
#define _I_MACRO_SELECT(_1, _2, NAME, ...) NAME
#define _I_BIND(...) _I_MACRO_SELECT(__VA_ARGS__, _I_BIND_2, _I_BIND_1, ...)(__VA_ARGS__)