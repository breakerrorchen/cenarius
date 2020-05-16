
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_value decalre and implement
 * a javascript value. the base type for all javascript values, 
 * and polymorphic functions on them
 * */
i_value::i_value(const i_context& context)
    : context_(context) {
    ;
}

i_value::i_value(const i_value& from)
    : context_(from.context_), _$_(from._$_) {
    ;
}

i_value::i_value(i_value&& from) {
    context_ = std::move(from.context_);
    _$_      = std::move(from._$_);
}

i_value::i_value(const i_object& from)
    : context_(from.context_) {
    _$_ = Local<Value>::Cast(from._$_);
}

i_value& i_value::operator=(const i_value& from) {
    if (this != &from) {
        context_ = from.context_; _$_ = from._$_;
    }
    return *this;
}

i_value& i_value::operator=(i_value&& from) {
    if (this != &from) {
        context_ = std::move(from.context_);
        _$_      = std::move(from._$_);
    }
    return *this;
}

i_value& i_value::operator=(const i_object& from) {
    context_ = from.context_;
    _$_ = Local<Value>::Cast(from._$_);
    return *this;
}

bool i_value::is_undefined() const {
    return _$_->IsUndefined();
}

bool i_value::is_null() const {
    return _$_->IsNull();
}

bool i_value::is_str() const {
    return _$_->IsString();
}

bool i_value::is_number() const {
    return _$_->IsNumber();
}

bool i_value::is_boolean() const {
    return _$_->IsBoolean();
}

bool i_value::is_object() const {
    return _$_->IsObject();
}

bool i_value::is_array() const {
    return _$_->IsArray();
}

bool i_value::is_function() const {
    return _$_->IsFunction();
}

bool i_value::is_typed_arr() const {
    return _$_->IsTypedArray();
}

bool i_value::is_typed_arr_clamped() const {
    return _$_->IsUint8ClampedArray();
}

bool i_value::is_typed_arr_int8() const {
    return _$_->IsInt8Array();
}

bool i_value::is_typed_arr_int16() const {
    return _$_->IsInt16Array();
}

bool i_value::is_typed_arr_int32() const {
    return _$_->IsInt32Array();
}

bool i_value::is_typed_arr_uint8() const {
    return _$_->IsUint8Array();
}

bool i_value::is_typed_arr_uint16() const {
    return _$_->IsUint16Array();
}

bool i_value::is_typed_arr_uint32() const {
    return _$_->IsUint32Array();
}

bool i_value::is_typed_arr_float32() const {
    return _$_->IsFloat32Array();
}

bool i_value::is_typed_arr_float64() const {
    return _$_->IsFloat64Array();
}

i_value::operator int32_t()  const { return to_int32();  }
i_value::operator bool()     const { return to_bool();   }
i_value::operator long()     const { return to_long();   }
i_value::operator float()    const { return to_float();  }
i_value::operator double()   const { return to_double(); }
i_value::operator i_object() const { return to_object(); }

int32_t i_value::to_int32() const {
    auto value = _$_->Int32Value(context_._$_);
    if (value.IsNothing()) return 0;
    return (int32_t)value.ToChecked();
}

bool i_value::to_bool() const {
    return _$_->IsTrue();
}

long i_value::to_long() const {
    auto value = _$_->IntegerValue(context_._$_);
    if (value.IsNothing()) return 0;
    return (long)value.ToChecked();
}

float i_value::to_float() const {
    auto value = _$_->NumberValue(context_._$_);
    if (value.IsNothing()) return 0;
    return (float)value.ToChecked();
}

double i_value::to_double() const {
    auto value = _$_->NumberValue(context_._$_);
    if (value.IsNothing()) return 0;
    return (double)value.ToChecked();
}

i_object i_value::to_object() const {
    return i_object(context_._$_, Local<Object>::Cast(_$_));
}

std::string i_value::to_string() const {
    std::string cxx_str = *(String::Utf8Value(
        context_._$_->GetIsolate(), _$_));
    return cxx_str;
}

std::string i_value::to_json_string() const {
    Local<String> str;
    if (!JSON::Stringify(context_._$_, _$_).ToLocal(&str)) {
        return "";
    }
    if (str.IsEmpty()) return "";
    std::string cxx_str = *(String::Utf8Value(
        context_._$_->GetIsolate(), Local<Value>::Cast(str)));
    return cxx_str;
}

i_value i_value::value_arr_at(int index) const {
    auto arr = Local<Array>::Cast(_$_);
    if (arr.IsEmpty()) return i_value();
    return i_value(context_._$_, 
        arr->Get(context_._$_, index).ToLocalChecked());
}

int i_value::value_arr_size() const {
    auto arr = Local<Array>::Cast(_$_);
    if (arr.IsEmpty()) return 0;
    return (int)arr->Length();
}

i_typedarr_buffer i_value::typedarr_buffer() const {
    i_typedarr_buffer buffer;
    auto buffer_view = Local<ArrayBufferView>::Cast(_$_);
    if (buffer_view.IsEmpty()) return buffer;
    auto buffer_data  = buffer_view->Buffer();
    auto content_data = buffer_data->GetContents(); 
    buffer.addr_   = content_data.Data();
    buffer.size_   = (size_t)content_data.ByteLength();
    buffer.offset_ = (size_t)buffer_view->ByteOffset();
    return buffer;
}

i_value i_value::function_invoke(const i_object* _this, 
    const i_value* arr, int size, i_value* exception_value) const {
    if (_$_.IsEmpty() || context_._$_.IsEmpty()) return i_value();
    auto function = Local<Function>::Cast(_$_);    
    if (function.IsEmpty()) return i_value();
    auto raw_isolate = context_._$_->GetIsolate();
    auto raw_context = context_._$_;
    EscapableHandleScope handle_scope(raw_isolate);
    Context::Scope context_scope(raw_context);
    TryCatch try_catch(raw_isolate);
    Local<Value> _this_value;
    if (nullptr != _this) {
        _this_value = Local<Value>::Cast(_this->_$_);
    }

    // 坑爹玩意，这货不能是empty对象
    if (_this_value.IsEmpty()) {
        _this_value = Null(raw_isolate);
    }

    Local<Value> value;
    if (size <= 16) {  
        Local<Value> arguments[16];
        for (int i = 0; i < size; ++i) {
            arguments[i] = arr[i]._$_;
        }
        auto ret = function->Call(
            raw_context, _this_value, (int)size, arguments);
        ret.ToLocal(&value);
    } else {
        std::vector<Local<Value>> arguments;
        arguments.reserve(size);
        for (int i =0; i < size; ++i) {
            arguments.push_back(arr[i]._$_);
        }
        auto ret = function->Call(raw_context, 
            _this_value, (int)size, &(arguments[0]));
        ret.ToLocal(&value);
    }

    if (try_catch.HasCaught() && exception_value) {
        exception_value->context_._$_ = context_._$_;
        exception_value->_$_ = try_catch.Exception();
    }
    return i_value(raw_context, value);
}

i_value i_value::create(const i_context& context, std::nullptr_t) {
    if (!context.is_useable()) return i_value();
    auto _null = Null(context._$_->GetIsolate());
    return i_value(context._$_, Local<Value>::Cast(_null));
}

i_value i_value::create(const i_context& context, ...) {
    if (!context.is_useable()) return i_value();
    auto _undf = Undefined(context._$_->GetIsolate());
    return i_value(context._$_, Local<Value>::Cast(_undf));
}

i_value i_value::create(const i_context& context, long v) {
    return create(context, (int32_t)v);
}

i_value i_value::create(const i_context& context, int32_t v) {
    if (!context.is_useable()) return i_value();
    auto value = Integer::New(
        context._$_->GetIsolate(), (int32_t)v);
    return i_value(context._$_, Local<Value>::Cast(value));
}

i_value i_value::create(const i_context& context, float v) {
    return create(context, (double)v);
}

i_value i_value::create(const i_context& context, double v) {
    if (!context.is_useable()) return i_value();
    auto value = Number::New(
        context._$_->GetIsolate(), (double)v);
    return i_value(context._$_, Local<Value>::Cast(value));
}

i_value i_value::create(const i_context& context, bool v) {
    if (!context.is_useable()) return i_value();
    auto value = Boolean::New(
        context._$_->GetIsolate(), v);
    return i_value(context._$_, Local<Value>::Cast(value));
}

i_value i_value::create(const i_context& context, const i_value* ptr, int size) {
    if (!context.is_useable()) return i_value();
    auto isolate = context._$_->GetIsolate();
    auto array = Array::New(isolate, size);
    if (array.IsEmpty()) return i_value();
    for (int index = 0; index < size; ++index) {
        array->Set(context._$_, index, ptr[index]._$_);
    }
    return i_value(context._$_, Local<Value>::Cast(array));
}

i_value i_value::create(const i_context& context, const char* str, bool json) {
    if (!context.is_useable()) return i_value();
    auto isolate = context._$_->GetIsolate();
    if (json) {
        Local<String> json_str;
        String::NewFromUtf8(isolate, str, 
            NewStringType::kNormal).ToLocal(&json_str);
        auto value = JSON::Parse(context._$_, json_str);
        if (value.IsEmpty()) return i_value();
        return i_value(context._$_, value.ToLocalChecked());
    } else {
        Local<String> js_str;
        String::NewFromUtf8(isolate, str, 
            NewStringType::kNormal).ToLocal(&js_str);
        if (js_str.IsEmpty()) return i_value();
        return i_value(context._$_, Local<Value>::Cast(js_str));
    }
}

i_value i_value::create(const i_context& context, i_invoker _callback) {
    if (!context.is_useable() || !_callback.as_function_) {
        return i_value();
    }
    auto isolate = context._$_->GetIsolate();
    auto func_tmpl = FunctionTemplate::New(
        isolate, _callback.as_function_);
    Local<Function> function;
    func_tmpl->GetFunction(context._$_).ToLocal(&function);
    return i_value(context._$_, Local<Value>::Cast(function));
}

i_value i_value::create_clamped_arr(const i_context& context, size_t size) {
    if (!context.is_useable()) return i_value();
    auto isolate = context._$_->GetIsolate();
    auto value = Uint8ClampedArray::New(
        ArrayBuffer::New(isolate, size), 0, size);
    return i_value(context._$_, Local<Value>::Cast(value));
}
#endif//__use_v8_backend__