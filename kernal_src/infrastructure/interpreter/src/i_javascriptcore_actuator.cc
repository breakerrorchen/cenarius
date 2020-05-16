
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_actuator decalre and implement
 * interpreter for executing code, vm life cycle
 * must be valid during the valid period of the actuator
 * */
i_actuator::~i_actuator() {
    if (_$_) {
        JSGlobalContextRelease(_$_);
    }
}

i_actuator::i_actuator(const i_vm& vm) {
    _$_ = JSGlobalContextCreateInGroup(vm._$_, nullptr);
}

i_actuator::i_actuator(const i_vm& vm, const i_class& _class) {
    _$_ = JSGlobalContextCreateInGroup(vm._$_, _class._$_);
}

i_actuator::i_actuator(const i_actuator& from) {
    _$_ = JSGlobalContextRetain(from._$_);
}

i_actuator::i_actuator(i_actuator&& from) {
    _$_ = from._$_; from._$_ = nullptr;
}

i_actuator& i_actuator::operator=(const i_actuator& from) {
    if (this != &from) {
        if (_$_) {
            JSGlobalContextRelease(_$_);
        }
        _$_ = nullptr;
        _$_ = JSGlobalContextRetain(from._$_);
    }
    return *this;
}

i_actuator& i_actuator::operator=(i_actuator&& from) {
    if (this != &from) {
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

// get related context
i_context i_actuator::get_context() const {
    return i_context(_$_);
}

#endif//__use_javascriptcore_backend__