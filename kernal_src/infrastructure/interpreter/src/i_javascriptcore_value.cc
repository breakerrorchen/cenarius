
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_value decalre and implement
 * a javascript value. the base type for all javascript values, 
 * and polymorphic functions on them
 * */
i_value::i_value(const i_context& context) {
    context_ = context;
}

i_value::i_value(const i_value& from) {
    operator=(from);
}

i_value::i_value(i_value&& from) {
    operator=(std::move(from));
}

i_value::i_value(const i_object& from) {
    operator=(from);
}

i_value& i_value::operator=(const i_value& from) {
    if (this != &from) {
        _$_ = from._$_; context_ = from.context_;
    }
    return *this;
}

i_value& i_value::operator=(i_value&& from) {
    if (this != &from) {
        context_ = std::move(from.context_);
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

i_value& i_value::operator=(const i_object& from) {
    context_ = from.context_; _$_ = from._$_;
    return *this;
}

bool i_value::is_undefined() const { return JSValueIsUndefined(context_._$_, _$_); }
bool i_value::is_null()      const { return JSValueIsNull     (context_._$_, _$_); }
bool i_value::is_str()       const { return JSValueIsString   (context_._$_, _$_); }
bool i_value::is_number()    const { return JSValueIsNumber   (context_._$_, _$_); }
bool i_value::is_boolean()   const { return JSValueIsBoolean  (context_._$_, _$_); }
bool i_value::is_object()    const { return JSValueIsObject   (context_._$_, _$_); }
bool i_value::is_array()     const { return JSValueIsArray    (context_._$_, _$_); }

bool i_value::is_function() const {
    if (!context_._$_ || !_$_) return false;
    if (JSValueIsObject(context_._$_, _$_)) {
        auto object = JSValueToObject(context_._$_, _$_, nullptr);
        return JSObjectIsFunction(context_._$_, object);
    }
    return false;
}

bool i_value::is_typed_arr() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeNone != t;
}

bool i_value::is_typed_arr_clamped() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeUint8ClampedArray == t;
}

bool i_value::is_typed_arr_int8() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeInt8Array == t;
}

bool i_value::is_typed_arr_int16() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeInt16Array == t;
}

bool i_value::is_typed_arr_int32() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeInt32Array == t;
}

bool i_value::is_typed_arr_uint8() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeUint8Array == t;
}

bool i_value::is_typed_arr_uint16() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeUint16Array == t;
}

bool i_value::is_typed_arr_uint32() const  {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeUint32Array == t;
}

bool i_value::is_typed_arr_float32() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeFloat32Array == t;
}

bool i_value::is_typed_arr_float64() const {
    if (!context_._$_ || !_$_) return false;
    auto t = JSValueGetTypedArrayType(context_._$_, _$_, nullptr);
    return kJSTypedArrayTypeFloat64Array == t;
}

bool i_value::to_bool() const {
    if (!context_._$_ || !_$_) return false;
    return JSValueToBoolean(context_._$_, _$_);
}

i_value::operator int32_t()  const { return to_int32();  }
i_value::operator bool()     const { return to_bool();   }
i_value::operator long()     const { return to_long();   }
i_value::operator float()    const { return to_float();  }
i_value::operator double()   const { return to_double(); }
i_value::operator i_object() const { return to_object(); }

int32_t i_value::to_int32() const {
    if (!context_._$_ || !_$_) return 0;
    auto v = JSValueToNumber(context_._$_, _$_, nullptr);
    return (int32_t)v;
}

long i_value::to_long() const {
    if (!context_._$_ || !_$_) return 0;
    auto v = JSValueToNumber(context_._$_, _$_, nullptr);
    return (long)v;
}

float i_value::to_float() const {
    if (!context_._$_ || !_$_) return 0;
    auto v = JSValueToNumber(context_._$_, _$_, nullptr);
    return (float)v;
}

double i_value::to_double() const {
    if (!context_._$_ || !_$_) return 0;
    auto v = JSValueToNumber(context_._$_, _$_, nullptr);
    return (double)v;
}

i_object i_value::to_object() const {
    if (!context_._$_ || !_$_) return i_object();
    return i_object(context_._$_, 
        JSValueToObject(context_._$_, _$_, nullptr));
}

std::string i_value::to_string() const {
    if (!context_._$_ || !_$_) return "";
    auto _str = JSValueToStringCopy(context_._$_, _$_, nullptr);
    if (nullptr == _str) return "";
    std::string cxx_str; 
    cxx_str.resize(JSStringGetMaximumUTF8CStringSize(_str));
    if (0 == cxx_str.length()) {
        JSStringRelease(_str); return cxx_str;
    }
    size_t write_size = JSStringGetUTF8CString(
        _str, (char*)(cxx_str.c_str()), cxx_str.length());
    cxx_str.resize(write_size);
    JSStringRelease(_str); return cxx_str;
}

std::string i_value::to_json_string() const {
    if (!context_._$_ || !_$_) return "";
    auto _str = JSValueCreateJSONString(
        context_._$_, _$_, 0, nullptr);
    if (nullptr == _str) return "";
    std::string cxx_str;
    cxx_str.resize(JSStringGetMaximumUTF8CStringSize(_str));
    if (0 == cxx_str.length()) {
        JSStringRelease(_str); return cxx_str;
    }
    size_t write_size = JSStringGetUTF8CString(
        _str, (char*)(cxx_str.c_str()), cxx_str.length());
    cxx_str.resize(write_size);
    JSStringRelease(_str); return cxx_str;
}

i_value i_value::value_arr_at(int index) const {
    if (!context_._$_ || !_$_) return i_value();
    auto& raw_context = context_._$_;
    auto object = JSValueToObject(raw_context, _$_, nullptr);
    if (!object) return i_value();
    auto v = ::JSObjectGetPropertyAtIndex(
        raw_context, object, (unsigned)index, nullptr);
    return i_value(context_._$_, v);
}

int i_value::value_arr_size() const {
    if (!context_._$_ || !_$_) return 0;
    auto& raw_context = context_._$_;
    auto object = JSValueToObject(raw_context, _$_, nullptr);
    if (!object || !JSValueIsArray(raw_context, _$_)) {
        return 0;
    }
    return JSValueToNumber(
        raw_context, JSObjectGetProperty(raw_context, 
        object, i_initializer::_$_length_, nullptr), nullptr);
}

i_typedarr_buffer i_value::typedarr_buffer() const {
    if (!context_._$_ || !_$_) return i_typedarr_buffer();
    auto& raw_context = context_._$_;
    i_typedarr_buffer buffer;
    auto t = JSValueGetTypedArrayType(raw_context, _$_, nullptr);
    if (kJSTypedArrayTypeNone == t) { return buffer; }
    auto object = JSValueToObject(raw_context, _$_, nullptr);
    if (!object) { return buffer; }
    buffer.size_   = JSObjectGetTypedArrayByteLength(
        raw_context, object, nullptr);
    buffer.addr_   = JSObjectGetTypedArrayBytesPtr(
        raw_context, object, nullptr);
    buffer.offset_ = JSObjectGetTypedArrayByteOffset(
        raw_context, object, nullptr);
    return buffer;
}

i_value i_value::function_invoke(const i_object* _this, 
    const i_value* arr, int size, i_value* exception_value) const {
    if (!_$_ || !context_._$_) return i_value();
    auto function = JSValueToObject(context_._$_, _$_, nullptr);
    if (!function) return i_value();
    JSObjectRef this_object = nullptr; 
    if (nullptr != _this) { 
        this_object = _this->_$_; 
    }
    JSValueRef value = nullptr; JSValueRef exception = nullptr;
    if (size <= 16) {
        JSValueRef arguments[16] = { nullptr };
        for (int i =0; i < size; ++i) {  arguments[i] = arr[i]._$_; }
        value = JSObjectCallAsFunction(context_._$_, 
            function, this_object, size, arguments, &exception);
    } else {
        std::vector<JSValueRef> arguments; arguments.reserve(size);
        for (int i =0; i < size; ++i) { arguments.push_back(arr[i]._$_); }
        value = JSObjectCallAsFunction(context_._$_, 
            function, this_object, size, &(arguments[0]), &exception);
    }
    if (nullptr != exception_value) {
        exception_value->context_._$_ = context_._$_; 
        exception_value->_$_ = exception;
    }
    return i_value(context_._$_, value);
}

i_value i_value::create(const i_context& context, std::nullptr_t) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeNull(context._$_);
    return i_value(context._$_, val);
}

i_value i_value::create(const i_context& context, ...) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeUndefined(context._$_);
    return i_value(context._$_, val);
}

i_value i_value::create(const i_context& context, long v) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeNumber(context._$_, (double)v);
    return i_value(context._$_, val);
}

i_value i_value::create(const i_context& context, int32_t v) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeNumber(context._$_, (double)v);
    return i_value(context._$_, val);
}

i_value i_value::create(const i_context& context, float v) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeNumber(context._$_, (double)v);
    return i_value(context._$_, val);
}

i_value i_value::create(const i_context& context, double v) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeNumber(context._$_, (double)v);
    return i_value(context._$_, val);   
}

i_value i_value::create(const i_context& context, bool v) {
    if (!context._$_) return i_value();
    auto val = JSValueMakeBoolean(context._$_, v);
    return i_value(context._$_, val);       
}

i_value i_value::create(const i_context& context, const i_value* arr, int size) {
    if (!context._$_) return i_value();
    if (size > 0) {
        std::vector<JSValueRef> _vec(size);
        for (uint32_t i = 0; i < size; ++i) {
            _vec[i] = arr[i]._$_;
        }
        auto object = JSObjectMakeArray(
            context._$_, size, &_vec[0], nullptr);
        return i_value(context._$_, object);
    } else {
        auto object = JSObjectMakeArray(
            context._$_, 0, nullptr, nullptr);
        return i_value(context._$_, object);
    }
}

i_value i_value::create(const i_context& context, const char* src, bool json) {
    if (!context._$_) return i_value();
    JSValueRef value = nullptr;
    if (json) {
        auto _str = JSStringCreateWithUTF8CString(src);
        value = JSValueMakeFromJSONString(context._$_, _str);
        JSStringRelease(_str);
    } else {
        auto _str = ::JSStringCreateWithUTF8CString(src);
        value = JSValueMakeString(context._$_, _str);
        JSStringRelease(_str);
    }
    return i_value(context._$_, value);
}

i_value i_value::create(const i_context& context, i_invoker _callback) {
    if (!context._$_ || !_callback.as_function_) {
        return i_value();
    }
    auto object = ::JSObjectMakeFunctionWithCallback(
        context._$_, nullptr, _callback.as_function_);
    return i_value(context._$_, object);
}

i_value i_value::create_clamped_arr(const i_context& context, size_t size) {
    if (!context._$_) return i_value();
    auto value = ::JSObjectMakeTypedArray(
        context._$_, kJSTypedArrayTypeUint8ClampedArray, size, nullptr);
    return i_value(context._$_, value);
}
#endif//__use_javascriptcore_backend__