
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_class_extract
 * */
class i_class_extract final {
    __interpreter_friend_class_declare_list__
public:
    template<typename t>static t* extract(i_value& val) {
        if (!val.is_useable()) return nullptr;
        return i_runtime_base::cast<t>(
            Local<Object>::Cast(val._$_));
    }

    template<typename t>static t* extract(i_object& obj) {
        if (!obj.is_useable()) return nullptr;
        return i_runtime_base::cast<t>(obj._$_);
    }
};


}}