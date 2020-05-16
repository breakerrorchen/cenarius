#pragma once


#define __use_v8_backend__


#if defined(__use_javascriptcore_backend__)
#include "i_javascriptcore.h"
#elif defined(__use_v8_backend__)
#include "i_v8.h"
#endif

namespace interpreter {
template<typename t>
using js_runtime_container = i_runtime_container<t>;
using js_initializer       = i_initializer;
using js_vm                = i_vm;
using js_release_scope     = i_release_scope;
using js_actuator          = i_actuator;
using js_context           = i_context;
using js_value             = i_value;
using js_value_holder      = i_value_holder;
using js_object            = i_object;
using js_object_holder     = i_object_holder;
using js_str               = i_str;
using js_class             = i_class;
using js_parameter         = i_parameter;
using js_runtime_base      = i_runtime_base;
using js_class_extract     = i_class_extract;



} // end.interpreter