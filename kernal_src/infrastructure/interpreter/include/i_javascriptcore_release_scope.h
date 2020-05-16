
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_release_scope decalre
 * */
class i_release_scope final {
    __interpreter_friend_class_declare_list__
public:
    i_release_scope(const i_release_scope&)             = delete;
    i_release_scope(i_release_scope&&)                  = delete;
    i_release_scope& operator=(const i_release_scope&&) = delete;
    i_release_scope& operator=(i_release_scope&&)       = delete;
    void* operator new(size_t)                          = delete;

public:
    i_release_scope(const i_vm&)            { ; }
    i_release_scope(const i_value_holder&)  { ; }
    i_release_scope(const i_object_holder&) { ; }
    i_release_scope(const i_context&)       { ; }
    i_release_scope(const i_actuator&)      { ; }
};


}}