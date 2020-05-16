
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_parameter
 * */
i_context i_parameter::get_context() const {
    Isolate* isolate = nullptr;
    if (0 == kind_) {
        isolate = function_.GetIsolate();
    } else if (1 == kind_) {
        isolate = getter_.GetIsolate();
    } else if (2 == kind_) {
        isolate = setter_.GetIsolate();
    }

    if (isolate) {
        return i_context(isolate->GetCurrentContext());
    }
    return i_context();
}

i_object i_parameter::get_this() const {
    Isolate* isolate = nullptr; Local<Object> object;
    if (0 == kind_) {
        isolate = function_.GetIsolate();
        object  = function_.This();
    } else if (1 == kind_) {
        isolate = getter_.GetIsolate();
        object  = getter_.This();
    } else if (2 == kind_) {
        isolate = setter_.GetIsolate();
        object  = setter_.This();
    }
    if (isolate) {
        return i_object(isolate->GetCurrentContext(), object);
    }
    return i_object();
}

i_value i_parameter::get_argument_at(int index) const {
    if (0 == kind_) {
        return i_value(function_.GetIsolate()
            ->GetCurrentContext(), function_[index]);
    } else if (1 == kind_) {
        return i_value();
    } else if (2 == kind_) {
        if (0 != index) {
            return i_value();
        } else {
            return i_value(setter_.GetIsolate()
                ->GetCurrentContext(), setter_value_);
        }
    } else {
        return i_value();
    }
}

size_t i_parameter::get_argument_count() const {
    if (0 == kind_) {
        return (size_t)function_.Length();
    } else if (1 == kind_) {
        return 0;
    } else if (2 == kind_) {
        return 1;
    } else {
        return 0;
    }
}

i_value i_parameter::operator[](int index) const {
    return get_argument_at(index);
}

void i_parameter::set_return(i_value v) {
    if (0 == kind_) {
        function_.GetReturnValue().Set(v._$_);
    } else if (1 == kind_) {
        getter_.GetReturnValue().Set(v._$_);
    } else if (2 == kind_) {
        setter_.GetReturnValue().Set(v._$_);
    }
}

void i_parameter::set_exception(i_value v) {
    Isolate* isolate = nullptr;
    if (0 == kind_) {
        isolate = function_.GetIsolate();
    } else if (1 == kind_) {
        isolate = getter_.GetIsolate();
    } else if (2 == kind_) {
        isolate = setter_.GetIsolate();
    }
    if (isolate) { isolate->ThrowException(v._$_); }
}

#endif//__use_v8_backend__