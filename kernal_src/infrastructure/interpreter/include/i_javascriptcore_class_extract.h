
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_class_extract
 * */
class i_class_extract final {
    __interpreter_friend_class_declare_list__
public:
    template<typename t> static t* extract(i_value& val) {
        if (!val.is_useable()) return nullptr;
        if (!::JSValueIsObject(val.context_, val._$_) {
            return nullptr;
        }
        auto _object = ::JSValueToObject(
            val.context_, val._$_, nullptr);
        return cast<t>(_object);
    }

    template<typename t> static t* extract(i_object& obj) {
        if (!obj.is_useable()) return nullptr;
        return cast<t>(obj._$_);
    }
};

    
}}