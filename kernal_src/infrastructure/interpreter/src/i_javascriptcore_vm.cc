
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_vm decalre
 * represents the isolation of runtime data.
 * representing an interpreter virtual machine instance.
 * */
i_vm::~i_vm() {
    if (_$_) {
        ::JSContextGroupRelease(_$_); 
    }
}

i_vm::i_vm():_$_(JSContextGroupCreate()) {
    ;
}

i_vm::i_vm(i_vm&& from) {
    _$_ = from._$_; from._$_ = nullptr;
}

i_vm& i_vm::operator=(i_vm&& from) {
    if (this != &from) {
        if (_$_) {
            ::JSContextGroupRelease(_$_);
        }
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

#endif//__use_javascriptcore_backend__