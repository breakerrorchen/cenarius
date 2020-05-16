
#pragma once
#if !defined(__use_v8_backend__)
#error only build for v8
#endif

#ifndef __interpreter_friend_class_declare_list__
#define __interpreter_friend_class_declare_list__                                   \
    friend class i_initializer;                                                     \
    friend class i_vm;                                                              \
    friend class i_release_scope;                                                   \
    friend class i_actuator;                                                        \
    friend class i_context;                                                         \
    friend class i_value;                                                           \
    friend class i_value_holder;                                                    \
    friend class i_object;                                                          \
    friend class i_object_field;                                                    \
    friend class i_object_holder;                                                   \
    friend class i_str;                                                             \
    friend class i_class;                                                           \
    friend class i_class_slot;                                                      \
    friend class i_class_extract;                                                   \
    friend class i_parameter;                                                       \
    friend class i_invoker;                                                         \
    friend class i_runtime_base;                                                    \
    template<typename t> friend class i_runtime_container;                          \
    template<typename t> friend class i_invoke_function;                            \
    template<typename cls, typename t> friend class i_invoke_connection;
#endif//__interpreter_friend_class_declare_list__

#include "i_v8_base.h"
#include "i_v8_initializer.h"
#include "i_v8_vm.h"
#include "i_v8_actuator.h"
#include "i_v8_context.h"
#include "i_v8_str.h"
#include "i_v8_typedarr_buffer.h"
#include "i_v8_value.h"
#include "i_v8_value_holder.h"
#include "i_v8_object_field.h"
#include "i_v8_object.h"
#include "i_v8_object_holder.h"
#include "i_v8_release_scope.h"
#include "i_v8_parameter.h"
#include "i_v8_invoker.h"
#include "i_v8_invoke_function.h"
#include "i_v8_invoke_connection.h"
#include "i_v8_class.h"
#include "i_v8_class_extract.h"
#include "i_v8_bind.h"

#undef __interpreter_friend_class_declare_list__