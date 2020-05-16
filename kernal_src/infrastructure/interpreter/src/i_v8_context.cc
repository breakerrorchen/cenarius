
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_context decalre and implement
 * interpreter actuator context
 * */
i_context::i_context(const i_context& from) {
    _$_ = from._$_;
}

i_context::i_context(i_context&& from) {
    _$_ = std::move(from._$_);
}

i_context& i_context::operator=(const i_context& from) {
    if (this != &from) {
        _$_ = from._$_;
    }
    return *this;
}

i_context& i_context::operator=(i_context&& from) {
    if (this != &from) {
        _$_ = std::move(from._$_);
    }
    return *this;
}

i_object i_context::get_global_object() const {
    return i_object(_$_, _$_->Global());
}

i_value i_context::eval(const char* code, i_value* exception) const {
    auto raw_isolate = _$_->GetIsolate();
    EscapableHandleScope handle_scope(raw_isolate);
    Context::Scope context_scope(_$_);
    Local<String> str;
    String::NewFromUtf8(raw_isolate, 
        code, NewStringType::kNormal).ToLocal(&str);
    TryCatch try_catch(raw_isolate);
    Local<Script> script;
    Script::Compile(_$_, str).ToLocal(&script);
    if (script.IsEmpty()) { return i_value(); }
    Handle<Value> result;
    if (!script->Run(_$_).ToLocal(&result)) {
        if (try_catch.HasCaught() && exception) {
            exception->context_._$_ = _$_;
            exception->_$_ = try_catch.Exception();
        }
    }
    return i_value(_$_, handle_scope.Escape(result));
}

void i_context::gc() {
    if (!_$_.IsEmpty()) {
        _$_->GetIsolate()->IdleNotificationDeadline(1);
    }
}

#endif//__use_v8_backend__