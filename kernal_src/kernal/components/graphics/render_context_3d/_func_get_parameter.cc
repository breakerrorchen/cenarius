
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.renderbufferStorage(target, internalFormat, width, height);
 * pname
 *      A GLenum specifying which parameter value to return. 
 *      See below for possible values.
 * 
 * Return value
 *      Depends on the parameter.
 */
void render_context_3d::get_parameter(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto js_context = _parameter.get_context();
    auto pname = (uint32_t)_parameter[0].to_int32();
    if (DWL_ACTIVE_TEXTURE == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)context_cache_.ative_texture_));
    }
    else if (DWL_ALIASED_LINE_WIDTH_RANGE == pname) {
        i_typedarr_buffer buffer; float data[2];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 2;
        data[0] = render_attitude_->aliased_line_width_range_[0];
        data[1] = render_attitude_->aliased_line_width_range_[1];
        _parameter.set_return(js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (DWL_ALIASED_POINT_SIZE_RANGE == pname) {
        i_typedarr_buffer buffer; float data[2];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 2;
        data[0] = render_attitude_->aliased_point_size_range_[0];
        data[1] = render_attitude_->aliased_point_size_range_[1];
        _parameter.set_return(js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (DWL_ALPHA_BITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_->alpha_bits_));
    }
    else if (DWL_ARRAY_BUFFER_BINDING == pname) {
        _parameter.set_return(
            (js_value)context_cache_.arraybuffer_bind_);
    }
    else if (DWL_BLEND == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)context_cache_.enable_blend_));
    }
    else if (DWL_BLEND_COLOR == pname) {
        i_typedarr_buffer buffer; float data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 4;
        data[0] = context_cache_.blend_color_[0];
        data[1] = context_cache_.blend_color_[1];
        data[2] = context_cache_.blend_color_[2];
        data[3] = context_cache_.blend_color_[3];
        _parameter.set_return(js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (DWL_BLEND_DST_ALPHA == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_func_dst_alpha_));
    }
    else if (DWL_BLEND_DST_RGB == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_func_dst_rgb_));
    }
    else if (DWL_BLEND_EQUATION == pname) {
        // 当rgb和alpha不一样的时候，以rgb为准
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_equation_rgb_mode_));
    }
    else if (DWL_BLEND_EQUATION_ALPHA == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_equation_alpha_mode_));
    }
    else if (DWL_BLEND_EQUATION_RGB == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_equation_rgb_mode_));
    }
    else if (DWL_BLEND_SRC_ALPHA == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_func_src_alpha_));
    }
    else if (DWL_BLEND_SRC_RGB == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.blend_func_src_rgb_));
    }
    else if (DWL_BLUE_BITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_->blue_bits_));
    }
    else if (DWL_COLOR_CLEAR_VALUE == pname) {
        i_typedarr_buffer buffer; float data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 4;
        data[0] = context_cache_.clear_color_[0];
        data[1] = context_cache_.clear_color_[1];
        data[2] = context_cache_.clear_color_[2];
        data[3] = context_cache_.clear_color_[3];
        _parameter.set_return(js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else if (DWL_COLOR_WRITEMASK == pname) {
        js_value arr[4];
        for (int i = 0; i < 4; ++i) {
            arr[i] = js_value::create(js_context, 
                context_cache_.color_write_mask_[i]);
        }
        _parameter.set_return(
            js_value::create(js_context, arr, 4));
    }
    else if (DWL_COMPRESSED_TEXTURE_FORMATS == pname) {
        ;
    }
    else if (DWL_CULL_FACE == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.enable_cull_face_));
    }
    else if (DWL_CULL_FACE_MODE == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.cull_face_mode_));
    }
    else if (DWL_CURRENT_PROGRAM == pname) {
        _parameter.set_return(
            (js_value)context_cache_.current_program_);
    }
    else if (DWL_DEPTH_BITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_->depth_bits_));
    }
    else if (DWL_DEPTH_CLEAR_VALUE == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (float)context_cache_.clear_depth_value_));
    }
    else if (DWL_DEPTH_FUNC == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.depth_func_));
    }
    else if (DWL_DEPTH_RANGE == pname) {
        i_typedarr_buffer buffer; float data[2];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 2;
        data[0] = context_cache_.depth_range_[0];
        data[1] = context_cache_.depth_range_[1];
        _parameter.set_return(js_value::create_typed_arr_float32(
            js_context, &buffer));
    } 
    else if (DWL_DEPTH_TEST == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (bool)context_cache_.enable_depth_test_));
    }
    else if (DWL_DEPTH_WRITEMASK == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (bool)context_cache_.depth_mask_));
    }
    else if (DWL_DITHER == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (bool)context_cache_.enable_dither_));
    }
    else if (DWL_ELEMENT_ARRAY_BUFFER_BINDING == pname) {
        _parameter.set_return((js_value)
            context_cache_.element_arraybuffer_bind_);
    }
    else if (DWL_FRAMEBUFFER_BINDING == pname) {
        _parameter.set_return((js_value)
            context_cache_.framebuffer_bind_);
    }
    else if (DWL_FRONT_FACE == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.front_face_));
    }
    else if (DWL_GENERATE_MIPMAP_HINT == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.generate_mipmap_hint_));
    }
    else if (DWL_GREEN_BITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_->green_bits_));
    }
    else if (DWL_IMPLEMENTATION_COLOR_READ_FORMAT == pname) {

    }
    else if (DWL_IMPLEMENTATION_COLOR_READ_TYPE == pname) {

    }
    else if (DWL_LINE_WIDTH == pname) {
        _parameter.set_return(js_value::create(
            js_context, (float)context_cache_.line_width_));
    }
    else if (DWL_MAX_COMBINED_TEXTURE_IMAGE_UNITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_combined_texture_image_units_));
    }
    else if (DWL_MAX_CUBE_MAP_TEXTURE_SIZE == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_cube_map_texture_size_));
    }
    else if (DWL_MAX_FRAGMENT_UNIFORM_VECTORS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_fragment_uniform_vectors_));
    }
    else if (DWL_MAX_RENDERBUFFER_SIZE == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_renderbuffer_size_));
    }
    else if (DWL_MAX_TEXTURE_IMAGE_UNITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_texture_image_units_));
    }
    else if (DWL_MAX_VARYING_VECTORS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_varying_vectors_));
    }
    else if (DWL_MAX_VERTEX_ATTRIBS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_vertex_attribs_));
    }
    else if (DWL_MAX_VERTEX_TEXTURE_IMAGE_UNITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_vertex_texture_image_units_));
    }
    else if (DWL_MAX_VERTEX_UNIFORM_VECTORS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_
                ->max_vertex_uniform_vectors_));
    }
    else if (DWL_MAX_VIEWPORT_DIMS == pname) {
        i_typedarr_buffer buffer; int32_t data[2];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(int32_t) * 2;
        data[0] = render_attitude_->max_viewport_size_[0];
        data[1] = render_attitude_->max_viewport_size_[1];
        _parameter.set_return(js_value::create_typed_arr_int32(
            js_context, &buffer));
    }
    else if (DWL_PACK_ALIGNMENT == pname) {
        _parameter.set_return(js_value::create(
            js_context, (float)context_cache_.pack_alignment_));
    }
    else if (DWL_POLYGON_OFFSET_FACTOR == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (float)context_cache_.polygon_offset_factor_));
    }
    else if (DWL_POLYGON_OFFSET_FILL == pname) {
        _parameter.set_return(js_value::create(js_context, 
            context_cache_.enable_polygon_offset_fill_));
    }
    else if (DWL_POLYGON_OFFSET_UNITS == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (float)context_cache_.polygon_offset_units_));
    }
    else if (DWL_ALPHA_BITS == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)render_attitude_->red_bits_));
    }
    else if (DWL_RENDERBUFFER_BINDING == pname) {
        _parameter.set_return(
            (js_value)context_cache_.renderbuffer_bind_);
    }
    else if (DWL_RENDERER == pname) {
        static const char* renderer = "cenarius webgl";
        _parameter.set_return(js_value::create(
            js_context, renderer, false));
    }
    else if (DWL_SAMPLE_BUFFERS == pname) {
        _parameter.set_return(
            js_value::create(js_context, 1));
    }
    else if (DWL_SAMPLE_COVERAGE_INVERT == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (bool)context_cache_.sample_coverage_invert_));
    }
    else if (DWL_SAMPLE_COVERAGE_VALUE == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (float)context_cache_.sample_coverage_value_));
    }
    else if (DWL_SAMPLES == pname) {
        _parameter.set_return(
            js_value::create(js_context, 8));
    }
    else if (DWL_SCISSOR_BOX == pname) {
        i_typedarr_buffer buffer; int32_t data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(int32_t) * 4;
        data[0] = context_cache_.scissor_[0];
        data[1] = context_cache_.scissor_[1];
        data[2] = context_cache_.scissor_[2];
        data[3] = context_cache_.scissor_[3];
        _parameter.set_return(js_value::create_typed_arr_int32(
            js_context, &buffer));
    }
    else if (DWL_SCISSOR_TEST == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (bool)context_cache_.enable_scissor_test_));
    }
    else if (DWL_SHADING_LANGUAGE_VERSION == pname) {
        static const char* shading_lang_string = 
            "WebGL GLSL ES 1.0 (OpenGL ES GLSL ES 1.0 Cenarius)";
        _parameter.set_return(js_value::create(
            js_context, shading_lang_string, false));
    }
    else if (DWL_STENCIL_BACK_FAIL == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_stencil_op_fail_));
    }
    else if (DWL_STENCIL_BACK_FUNC == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_face_stencil_func_));
    }
    else if (DWL_STENCIL_BACK_PASS_DEPTH_FAIL == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_stencil_op_z_fail_));
    }
    else if (DWL_STENCIL_BACK_PASS_DEPTH_PASS == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_stencil_op_z_pass_));
    }
    else if (DWL_STENCIL_BACK_REF == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_face_stencil_func_ref_));
    }
    else if (DWL_STENCIL_BACK_VALUE_MASK == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_face_stencil_func_mask_));
    }
    else if (DWL_STENCIL_BACK_WRITEMASK == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.stencil_back_write_mask_));
    }
    else if (DWL_STENCIL_BITS == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)render_attitude_->stencil_bits_));
    }
    else if (DWL_STENCIL_CLEAR_VALUE == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (float)context_cache_.clear_stencil_value_));
    }
    else if (DWL_STENCIL_FAIL == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.front_stencil_op_fail_));
    }
    else if (DWL_STENCIL_FUNC == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.front_face_stencil_func_));
    }
    else if (DWL_STENCIL_PASS_DEPTH_FAIL == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_stencil_op_z_fail_));
    }
    else if (DWL_STENCIL_PASS_DEPTH_PASS == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.back_stencil_op_z_pass_));
    }
    else if (DWL_STENCIL_REF == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.front_face_stencil_func_ref_));
    }
    else if (DWL_STENCIL_TEST == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.enable_stencil_test_));
    }
    else if (DWL_STENCIL_VALUE_MASK == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.front_face_stencil_func_mask_));
    }
    else if (DWL_STENCIL_WRITEMASK == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)context_cache_.stencil_write_mask_));
    }
    else if (DWL_SUBPIXEL_BITS == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)render_attitude_->subpixel_bits_));
    }
    else if (DWL_TEXTURE_BINDING_2D == pname) {
        _parameter.set_return(
            (js_value)(context_cache_.texture_2d_bind_));
    }
    else if (DWL_TEXTURE_BINDING_CUBE_MAP == pname) {
        _parameter.set_return(
            (js_value)(context_cache_.texture_cube_bind_));
    }
    else if (DWL_UNPACK_ALIGNMENT == pname) {
        _parameter.set_return(js_value::create(js_context,
            (int32_t)context_cache_.unpack_alignment_));
    }
    else if (DWL_UNPACK_COLORSPACE_CONVERSION_WEBGL == pname) {
        
    }
    else if (DWL_UNPACK_FLIP_Y_WEBGL == pname) {
        _parameter.set_return(js_value::create(js_context,
            (bool)context_cache_.unpack_filp_y_webgl_));
    }
    else if (DWL_UNPACK_PREMULTIPLY_ALPHA_WEBGL == pname) {
        _parameter.set_return(js_value::create(js_context,
            (bool)context_cache_.unpack_premu_alpha_webgl_));
    }
    else if (DWL_VENDOR == pname) {
        static const char* vendor_string = "Cenarius";
        _parameter.set_return(js_value::create(
            js_context, vendor_string, false));
    }
    else if (DWL_VERSION == pname) {
        static const char* version_string = 
            "WebGL 1.0 (OpenGL ES 2.0 CerdaCore)";
        _parameter.set_return(js_value::create(
            js_context, version_string, false));
    }
    else if (DWL_VIEWPORT == pname) {
        i_typedarr_buffer buffer; int32_t data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(int32_t) * 4;
        data[0] = context_cache_.viewport_[0];
        data[1] = context_cache_.viewport_[1];
        data[2] = context_cache_.viewport_[2];
        data[3] = context_cache_.viewport_[3];
        _parameter.set_return(js_value::create_typed_arr_int32(
            js_context, &buffer));
    } 
    else {

    }
}