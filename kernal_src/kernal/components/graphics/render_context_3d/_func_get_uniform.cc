
#include "../render_context_3d_program/_.h"
#include "../render_context_3d_uniform_location/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getUniform(program, location);
 *
 * program
 *      A WebGLProgram containing the uniform attribute.
 *
 * location
 *      A WebGLUniformLocation object 
 *      containing the location of the uniform attribute to get.
 * 
 * Return value
 *      WebGL 1 only
 *      boolean	            GLBoolean
 *      int                 GLint
 *      float               GLfloat
 *      vec2                Float32Array (with 2 elements)
 *      ivec2               Int32Array (with 2 elements)
 *      bvec2	            Array of GLBoolean (with 2 elements)
 *      vec3                Float32Array (with 3 elements)
 *      ivec3	            Int32Array (with 3 elements)
 *      bvec3               Array of GLBoolean (with 3 elements)
 *      vec4                Float32Array (with 4 elements)
 *      ivec4	            Int32Array (with 4 elements)
 *      bvec4	            Array of GLBoolean (with 4 elements)
 *      mat2                Float32Array (with 4 elements)
 *      mat3                Float32Array (with 9 elements)
 *      mat4	            Float32Array (with 16 elements)
 *      sampler2D           GLint
 *      samplerCube         GLint
 * 
 *      Additionally available in WebGL 2
 *      uint	            GLuint
 *      uvec2	            Uint32Array (with 2 elements)
 *      uvec3	            Uint32Array (with 3 elements)
 *      uvec4	            Uint32Array (with 4 elements)
 *      mat2x3	            Float32Array (with 6 elements)
 *      mat2x4	            Float32Array (with 8 elements)
 *      mat3x2	            Float32Array (with 6 elements)
 *      mat3x4  	        Float32Array (with 12 elements)
 *      mat4x2	            Float32Array (with 8 elements)
 *      mat4x3	            Float32Array (with 12 elements)
 *      any sampler type	GLint
 */
void render_context_3d::get_uniform(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    auto location = js_class_extract::extract<
        render_context_3d_uniform_location>(_1);
    if (!program || !location) return;
    if (!program || !program->is_useable()) return;
    shader_uniform* current_item = nullptr;
    auto& all_uniforms = program->reflection_.uniforms_;
    for (auto& item: all_uniforms) {
        if (item.location_index_ == location->location_) {
            current_item = &item;
            break;
        }
    }
    if (nullptr == current_item) return;

    auto js_context = _parameter.get_context();
    if (current_item->type_ == DWL_BOOL) {
        _parameter.set_return(js_value::create(js_context, 
            current_item->value_.b_16_[0]));
    }
    else if (current_item->type_ == DWL_INT) {
        _parameter.set_return(js_value::create(js_context, 
            current_item->value_.i_16_[0]));
    }
    else if (current_item->type_ == DWL_FLOAT) {
        _parameter.set_return(js_value::create(js_context, 
            current_item->value_.f_16_[0]));
    }
    else if (current_item->type_ == DWL_FLOAT_VEC2) {
        i_typedarr_buffer buffer; float data[2];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 2;
        data[0] = current_item->value_.f_16_[0];
        data[1] = current_item->value_.f_16_[1];
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_INT_VEC2) {
        i_typedarr_buffer buffer; int32_t data[2];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(int32_t) * 2;
        data[0] = current_item->value_.i_16_[0];
        data[1] = current_item->value_.i_16_[1];
        _parameter.set_return(
            js_value::create_typed_arr_int32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_BOOL_VEC2) {
        js_value arr[2];
        for (int i = 0; i < 2; ++i) {
            arr[i] = js_value::create(js_context, 
                current_item->value_.b_16_[i]);
        }
        _parameter.set_return(
            js_value::create(js_context, arr, 2));
    } 
    else if (current_item->type_ == DWL_FLOAT_VEC3) {
        i_typedarr_buffer buffer; float data[3];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 3;
        data[0] = current_item->value_.f_16_[0];
        data[1] = current_item->value_.f_16_[1];
        data[2] = current_item->value_.f_16_[2];
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_INT_VEC3) {
        i_typedarr_buffer buffer; int32_t data[3];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(int32_t) * 3;
        data[0] = current_item->value_.i_16_[0];
        data[1] = current_item->value_.i_16_[1];
        data[2] = current_item->value_.i_16_[2];
        _parameter.set_return(
            js_value::create_typed_arr_int32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_BOOL_VEC3) {
        js_value arr[3];
        for (int i = 0; i < 3; ++i) {
            arr[i] = js_value::create(js_context, 
                current_item->value_.b_16_[i]);
        }
        _parameter.set_return(
            js_value::create(js_context, arr, 3));
    } 
    else if (current_item->type_ == DWL_FLOAT_VEC4) {
        i_typedarr_buffer buffer; float data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 4;
        data[0] = current_item->value_.f_16_[0];
        data[1] = current_item->value_.f_16_[1];
        data[2] = current_item->value_.f_16_[2];
        data[3] = current_item->value_.f_16_[3];
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_INT_VEC4) {
        i_typedarr_buffer buffer; int32_t data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(int32_t) * 4;
        data[0] = current_item->value_.i_16_[0];
        data[1] = current_item->value_.i_16_[1];
        data[2] = current_item->value_.i_16_[2];
        data[3] = current_item->value_.i_16_[3];
        _parameter.set_return(
            js_value::create_typed_arr_int32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_BOOL_VEC4) {
        js_value arr[4];
        for (int i = 0; i < 4; ++i) {
            arr[i] = js_value::create(js_context, 
                current_item->value_.b_16_[i]);
        }
        _parameter.set_return(
            js_value::create(js_context, arr, 4));
    }
    else if (current_item->type_ == DWL_FLOAT_MAT2) {
        i_typedarr_buffer buffer; float data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 4;
        data[0] = current_item->value_.f_16_[0];
        data[1] = current_item->value_.f_16_[1];
        data[2] = current_item->value_.f_16_[2];
        data[3] = current_item->value_.f_16_[3];
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_FLOAT_MAT3) {
        i_typedarr_buffer buffer; float data[9];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 9;
        for (int i = 0; i < 9; ++i) {
            data[i] = current_item->value_.f_16_[i];
        }
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_FLOAT_MAT4) {
        i_typedarr_buffer buffer; float data[16];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 16;
        for (int i = 0; i < 16; ++i) {
            data[i] = current_item->value_.f_16_[i];
        }
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (current_item->type_ == DWL_SAMPLER_2D) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)current_item->value_.sampler_));
    }
    else if (current_item->type_ == DWL_SAMPLER_CUBE) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)current_item->value_.sampler_));
    }
}