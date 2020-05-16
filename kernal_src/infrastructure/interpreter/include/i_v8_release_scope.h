
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_release_scope decalre
 * */
class i_release_scope final: public HandleScope {
    __interpreter_friend_class_declare_list__
public:
    i_release_scope(const i_release_scope&)             = delete;
    i_release_scope(i_release_scope&&)                  = delete;
    i_release_scope& operator=(const i_release_scope&&) = delete;
    i_release_scope& operator=(i_release_scope&&)       = delete;
    void* operator new(size_t)                          = delete;

public:
    i_release_scope(const i_vm& vm): HandleScope(vm._$_) {
        ;
    }

    i_release_scope(const i_value_holder& holder)
        : HandleScope(holder.isolate_) {
        ;
    }

    i_release_scope(const i_object_holder& holder)
        : HandleScope(holder.isolate_) {
        ;
    }

    i_release_scope(const i_context& context)
        : HandleScope(context._$_->GetIsolate()) {
        ;
    }

    i_release_scope(const i_actuator& actuator)
        : HandleScope(actuator.vm_) {
        ;
    }
};


}}