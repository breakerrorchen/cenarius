
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_actuator decalre and implement
 * interpreter for executing code, vm life cycle
 * must be valid during the valid period of the actuator
 * */
i_actuator::i_actuator(const i_vm& vm): vm_(vm._$_) {
    HandleScope handle_scope(vm_);
    auto global_template = ObjectTemplate::New(vm_);
    auto context = Context::New(vm_, nullptr, global_template);
    _$_.Reset(vm_, context);
}

i_actuator::i_actuator(const i_vm& vm, const i_class& cls): vm_(vm._$_) {
    HandleScope handle_scope(vm_);
    auto global_template = cls._$_object_template_.Get(vm_);
    if (global_template.IsEmpty()) {
        global_template = ObjectTemplate::New(vm_);
        auto context = Context::New(vm_, nullptr, global_template);
        _$_.Reset(vm_, context);
    } else {
        auto context = Context::New(vm_, nullptr, global_template);
        _$_.Reset(vm_, context);
    }
}

i_actuator::i_actuator(const i_actuator& from) {
    operator=(from);
}

i_actuator::i_actuator(i_actuator&& from) {
    operator=(std::move(from));
}

i_actuator& i_actuator::operator=(const i_actuator& from) {
    if (this != &from) {
        vm_ = from.vm_; _$_ = from._$_;
    }
    return *this;
}

i_actuator& i_actuator::operator=(i_actuator&& from) {
    if (this != &from) {
        vm_ = from.vm_; from.vm_ = nullptr;
        _$_ = std::move(from._$_);
    }
    return *this;
}

i_context i_actuator::get_context() const {
    return i_context(_$_.Get(vm_));
}

#endif//__use_v8_backend__