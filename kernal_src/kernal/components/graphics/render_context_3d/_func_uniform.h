
#include "../render_context_3d_program/_.h"
#include "../render_context_3d_uniform_location/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

#define render_context_3d_uniform_intend_code(_parameter)           \
    auto current_program = context_cache_.raw_current_program_;     \
    if (!current_program) return;                                   \
    if (_parameter.get_argument_count() == 0) return;               \
    auto location = _parameter.get_argument_at(0);                  \
    auto raw_location = js_class_extract::extract<                  \
        render_context_3d_uniform_location>(location);              \
    if (nullptr == raw_location) return;                            \
    auto& shader_env = current_program->reflection_;                \
    auto local_uniform = shader_env                                 \
        .find_uniform(raw_location->location_);                     \
    if (nullptr == local_uniform) return;                           \
    int32_t location_index = raw_location->location_;

namespace cenarius { namespace kernal { namespace components {
// 从buffer中提取 float和int和bool数组
// 如果和期待的size不一样，就直接返回失败
template<class cls> inline bool buffer_extract(
    cls* out, int want_size, js_value& v) {
    if (nullptr == out || 0 >= want_size) return false;
    auto typedarr_buffer = v.typedarr_buffer();
#ifndef buffer_extract_t
#define buffer_extract_t(__t__)                         \
    if (typedarr_buffer.size<__t__>() != want_size) {   \
        return false;                                   \
    }                                                   \
    for (int i = 0; i < want_size; ++i) {               \
        out[i] = (cls)typedarr_buffer.at<__t__>(i);     \
    }
    
    if (v.is_typed_arr_clamped()) {
        buffer_extract_t(uint8_t);      return true;
    } else if (v.is_typed_arr_int8()) {
        buffer_extract_t(int8_t);       return true;
    } else if (v.is_typed_arr_int16()) {
        buffer_extract_t(int16_t);      return true;
    } else if (v.is_typed_arr_int32()) {
        buffer_extract_t(int32_t);      return true;
    } else if (v.is_typed_arr_uint8()) {
        buffer_extract_t(uint8_t);      return true;
    } else if (v.is_typed_arr_uint16()) {
        buffer_extract_t(uint16_t);     return true;
    } else if (v.is_typed_arr_uint32()) {
        buffer_extract_t(uint32_t);     return true;
    } else if (v.is_typed_arr_float32()) {
        buffer_extract_t(float);        return true;
    } else if (v.is_typed_arr_float64()) {
        buffer_extract_t(double);       return true;
    } else if (v.is_array()) {
        if (want_size != v.value_arr_size()) {
            return false;
        }
        for (int i = 0; i < want_size; ++i) {
             out[i] = (cls)v.value_arr_at(i).to_float();
        }
        return true;
    }
    
#undef  buffer_extract_t
#endif//buffer_extract_t
    return false;
};


}}}