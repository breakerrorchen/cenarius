
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_value decalre and implement
 * a javascript value. the base type for all javascript values, 
 * and polymorphic functions on them
 * */
class i_value final {
    __interpreter_friend_class_declare_list__
private:
    i_value(JSContextRef context, JSValueRef val)
        :_$_(val), context_(context) {
        assert(nullptr != context);
    }
public:
    i_value() = default;
    i_value(const i_context&);
    i_value(const i_value&);
    i_value(i_value&&);
    i_value(const i_object&);
    i_value& operator=(const i_value&);
    i_value& operator=(i_value&&);
    i_value& operator=(const i_object&);

public:
    // check is value is useable
    inline bool is_useable() const { 
        return _$_ && context_.is_useable(); 
    }

    // get related context
    inline i_context get_context() const {
        return context_;
    } 

public:
    bool is_undefined()         const;
    bool is_null()              const;
    bool is_str()               const;
    bool is_number()            const;
    bool is_boolean()           const;
    bool is_object()            const;
    bool is_array()             const;
    bool is_function()          const;
    bool is_typed_arr()         const;
    bool is_typed_arr_clamped() const;
    bool is_typed_arr_int8()    const;
    bool is_typed_arr_int16()   const;
    bool is_typed_arr_int32()   const;
    bool is_typed_arr_uint8()   const;
    bool is_typed_arr_uint16()  const;
    bool is_typed_arr_uint32()  const;
    bool is_typed_arr_float32() const;
    bool is_typed_arr_float64() const;

public:
    operator int32_t()   const;
    operator bool()      const;
    operator long()      const;
    operator float()     const;
    operator double()    const;
    operator i_object()  const;
    int32_t  to_int32()  const;
    bool     to_bool()   const;
    long     to_long()   const;
    float    to_float()  const;
    double   to_double() const;
    i_object to_object() const;

public:
    std::string to_string     () const;
    std::string to_json_string() const;
    
public:
    // normal array extract
    i_value value_arr_at(int) const;
    // normal array
    int value_arr_size() const;
    // typedarray 
    i_typedarr_buffer typedarr_buffer() const;

public:
    // function invoke
    // this / argument / argument count / exception
    i_value function_invoke(const i_object*, const i_value*, int, i_value*) const;

public:
    /**
     * create null and undefined and base data
     * */
    static i_value create(const i_context&, std::nullptr_t);
    static i_value create(const i_context&, ...);
    static i_value create(const i_context&, long   );
    static i_value create(const i_context&, int32_t);
    static i_value create(const i_context&, float  );
    static i_value create(const i_context&, double );
    static i_value create(const i_context&, bool   );

    /**
     * create value array
     * */
    static i_value create(const i_context&, const i_value*, int);

    /**
     * create value from `json string` or `string`
     * */
    static i_value create(const i_context&, const char*, bool);

    /**
     * 创建一个函数
     * */
    static i_value create(const i_context&, i_invoker);

    /**
     * create ClampedArray Buffer
     * */
    static i_value create_clamped_arr(const i_context&, size_t);

    /**
     * create typedarray
     * */
    // static i_value create_typed_arr_clamped(const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_int8   (const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_int16  (const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_int32  (const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_uint8  (const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_uint16 (const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_uint32 (const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_float32(const i_context&, i_typedarr_buffer*);
    // static i_value create_typed_arr_float64(const i_context&, i_typedarr_buffer*);

protected:
    i_context context_; JSValueRef _$_ = nullptr;
};

    
}}