
#pragma once
#if !defined(__use_javascriptcore_backend__)
#error only build for javascriptcore
#endif

/**
 * i_invoke_connection
 * */
#define __interpreter_constructor_args__                                                \
    JSContextRef context, JSObjectRef constructor, size_t argument_count,               \
    const JSValueRef arguments[], JSValueRef* exception
#define __interpreter_func_args__                                                       \
    JSContextRef context, JSObjectRef function, JSObjectRef this_object,                \
    size_t argument_count, const JSValueRef arguments[], JSValueRef* exception
#define __interpreter_attr_getter_args__                                                \
    JSContextRef context, JSObjectRef object, JSStringRef name, JSValueRef* exception
#define __interpreter_attr_setter_args__                                                \
    JSContextRef context, JSObjectRef object, JSStringRef name, JSValueRef value,       \
    JSValueRef* exception

#ifndef __interpreter_friend_class_declare_list__
#define __interpreter_friend_class_declare_list__                                       \
    friend class i_initializer;                                                         \
    friend class i_vm;                                                                  \
    friend class i_release_scope;                                                       \
    friend class i_actuator;                                                            \
    friend class i_context;                                                             \
    friend class i_value;                                                               \
    friend class i_value_holder;                                                        \
    friend class i_object;                                                              \
    friend class i_object_field;                                                        \
    friend class i_object_holder;                                                       \
    friend class i_str;                                                                 \
    friend class i_class;                                                               \
    friend class i_class_slot;                                                          \
    friend class i_class_extract;                                                       \
    friend class i_parameter;                                                           \
    friend class i_invoker;                                                             \
    friend class i_runtime_base;                                                        \
    template<typename t> friend class i_runtime_container;                              \
    template<typename t> friend class i_invoke_function;                                \
    template<typename cls, typename t> friend class i_invoke_connection;
#endif//__interpreter_friend_class_declare_list__

#include "i_javascriptcore_base.h"
#include "i_javascriptcore_initializer.h"
#include "i_javascriptcore_vm.h"
#include "i_javascriptcore_actuator.h"
#include "i_javascriptcore_context.h"
#include "i_javascriptcore_str.h"
#include "i_javascriptcore_typedarr_buffer.h"
#include "i_javascriptcore_value.h"
#include "i_javascriptcore_value_holder.h"
#include "i_javascriptcore_object_field.h"
#include "i_javascriptcore_object.h"
#include "i_javascriptcore_object_holder.h"
#include "i_javascriptcore_release_scope.h"
#include "i_javascriptcore_class_slot.h"
#include "i_javascriptcore_parameter.h"
#include "i_javascriptcore_invoker.h"
#include "i_javascriptcore_invoke_function.h"
#include "i_javascriptcore_invoke_connection.h"
#include "i_javascriptcore_class.h"
#include "i_javascriptcore_class_extract.h"
#include "i_javascriptcore_bind.h"

#undef __interpreter_friend_class_declare_list__
#undef __interpreter_attr_setter_args__
#undef __interpreter_attr_getter_args__
#undef __interpreter_func_args__
#undef __interpreter_constructor_args__