
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_class_slot
 * */
class i_class_slot {
    __interpreter_friend_class_declare_list__
private:
    i_class_slot(JSClassRef _class):_$_(_class) {
        if (_$_) { JSClassRetain(_$_); }
    }
    
    virtual ~i_class_slot() {
        if (_$_) { JSClassRelease(_$_); }
    }
private:
    JSClassRef _$_ = nullptr;
};

 
}}