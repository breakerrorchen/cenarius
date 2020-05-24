
#include "renderer.h"
#include "render_context.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

inline void enable_and_disable(GLenum cap, bool enable) {
    if (enable) {
        ::glEnable(cap);
    } else {
        ::glDisable(cap);
    }
}

void render_context::make_current(bool _switch) {
    if (_switch) {
        auto related_renderer = related_renderer_.lock();
        assert(related_renderer);
        auto _this = shared_from_this();
        if (related_renderer->current_context_ == _this) {
            return;
        } else {
            related_renderer->current_context_ = _this;
        }
    }

    ::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,  state_.index_array_buffer_binding_);
    ::glBindFramebuffer(GL_FRAMEBUFFER, state_.framebuffer_binding_);
    ::glBindVertexArray(0);
    for (GLint i = 0; i < state_.max_vertex_attribs_; ++i) {
        ::glBindBuffer(GL_ARRAY_BUFFER, 
            state_.vertex_attrib_[i].vertex_attrib_array_buffer_binding);
        ::glVertexAttribPointer(i,
            state_.vertex_attrib_[i].size,
            state_.vertex_attrib_[i].type,
            state_.vertex_attrib_[i].normalized,
            state_.vertex_attrib_[i].stride,
            state_.vertex_attrib_[i].pointer);
        ::glVertexAttrib4fv(i, state_.vertex_attrib_[i].current_vertex_attrib);
        if (state_.vertex_attrib_[i].enabled) {
            ::glEnableVertexAttribArray(i);
        } else {
            ::glDisableVertexAttribArray(i);
        }
    }
    ::glBindVertexArray(state_.vertex_array_bindings_);
    ::glBindBuffer(GL_ARRAY_BUFFER, state_.vertex_array_buffer_binding_);
    for (int i = 0; i < state_.max_texture_units_; ++i) {
        ::glActiveTexture(GL_TEXTURE0 + i);
        texture_bindings& bindings = state_.texture_bindings_[i];
        ::glBindTexture(GL_TEXTURE_2D, bindings.texture_2d);
        ::glBindTexture(GL_TEXTURE_CUBE_MAP, bindings.texture_cube_map);
    }
    ::glActiveTexture(state_.active_texture_);
    ::glPixelStorei(GL_PACK_ALIGNMENT, state_.pack_alignment_);
    ::glPixelStorei(GL_UNPACK_ALIGNMENT, state_.unpack_alignment_);
    ::enable_and_disable(GL_DEPTH_TEST, state_.depth_test_);
    ::enable_and_disable(GL_CULL_FACE, state_.cull_face_);
    ::glCullFace(state_.cull_face_mode_);
    ::glColorMask(state_.color_mask_[0], state_.color_mask_[1],
                  state_.color_mask_[2], state_.color_mask_[3]);
    ::glUseProgram(state_.current_program_);
    ::glClearColor(state_.color_clear_[0], state_.color_clear_[1],
                   state_.color_clear_[2], state_.color_clear_[3]);
    ::glBlendColor(state_.blend_color_[0], state_.blend_color_[1],
                   state_.blend_color_[2], state_.blend_color_[3]);
    ::glClearDepthf(state_.depth_clear_);
    ::glDepthFunc(state_.depth_func_);
    ::glDepthMask(state_.depth_mask_);
    ::glDepthRangef(state_.depth_rage_[0], state_.depth_rage_[1]);
    ::glFrontFace(state_.front_face_);
    ::glHint(GL_GENERATE_MIPMAP_HINT, state_.hint_generate_mipmap_);
    ::glLineWidth(state_.line_width_);
    ::glPolygonOffset(state_.polygon_offset_factor_, state_.polygon_offset_units_);
    ::glSampleCoverage(state_.sample_coverage_value_, state_.sample_coverage_invert_);
    ::glBlendEquationSeparate(state_.blend_equation_rgb_, state_.blend_equation_alpha_);
    ::enable_and_disable(GL_DITHER, state_.enable_dither_);
    ::enable_and_disable(GL_POLYGON_OFFSET_FILL, state_.enable_polygon_offset_fill_);
    ::enable_and_disable(
        GL_SAMPLE_ALPHA_TO_COVERAGE, state_.enable_sample_alpha_to_coverage_);
    ::enable_and_disable(GL_SAMPLE_COVERAGE, state_.enable_sample_coverage_);
    ::enable_and_disable(GL_BLEND, state_.blend_enabled_);
    ::glBlendFuncSeparate(state_.blend_src_rgb_, state_.blend_dest_rgb_,
        state_.blend_src_alpha_, state_.blend_dest_alpha_);
    ::glViewport(state_.viewport_[0], state_.viewport_[1],
        state_.viewport_[2], state_.viewport_[3]);
    ::enable_and_disable(GL_SCISSOR_TEST, state_.scissor_test_);
    ::glScissor(state_.scissor_box_[0], state_.scissor_box_[1],
        state_.scissor_box_[2], state_.scissor_box_[3]);
    ::enable_and_disable(GL_STENCIL_TEST, state_.stencil_state_.stencil_test_enabled);
    ::glStencilFuncSeparate(GL_FRONT, 
        state_.stencil_state_.stencil_front_func,
        state_.stencil_state_.stencil_front_mask,
        state_.stencil_state_.stencil_front_ref);
    ::glStencilFuncSeparate(GL_BACK, 
        state_.stencil_state_.stencil_back_func,
        state_.stencil_state_.stencil_back_mask,
        state_.stencil_state_.stencil_back_ref);
    ::glClearStencil(state_.stencil_state_.stencil_clear);
    ::glStencilMaskSeparate(GL_FRONT, state_.stencil_state_.stencil_front_writemask);
    ::glStencilMaskSeparate(GL_BACK, state_.stencil_state_.stencil_back_writemask);
    ::glStencilOpSeparate(GL_FRONT, 
        state_.stencil_state_.stencil_front_fail_op,
        state_.stencil_state_.stencil_front_z_fail_op,
        state_.stencil_state_.stencil_front_z_pass_op);
    ::glStencilOpSeparate(GL_BACK, 
        state_.stencil_state_.stencil_back_fail_op,
        state_.stencil_state_.stencil_back_z_fail_op,
        state_.stencil_state_.stencil_back_z_pass_op);
}

void render_context::capture(bool with_restore) {
    ::glGetIntegerv(GL_MAX_VERTEX_ATTRIBS,               &state_.max_vertex_attribs_);
    ::glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &state_.max_texture_units_);
    ::glGetBooleanv(GL_STENCIL_TEST,                     &state_.stencil_state_.stencil_test_enabled);
    ::glGetIntegerv(GL_STENCIL_FUNC,                     &state_.stencil_state_.stencil_front_func);
    ::glGetIntegerv(GL_STENCIL_VALUE_MASK,               &state_.stencil_state_.stencil_front_mask);
    ::glGetIntegerv(GL_STENCIL_REF,                      &state_.stencil_state_.stencil_front_ref);
    ::glGetIntegerv(GL_STENCIL_BACK_FUNC,                &state_.stencil_state_.stencil_back_func);
    ::glGetIntegerv(GL_STENCIL_BACK_VALUE_MASK,          &state_.stencil_state_.stencil_back_mask);
    ::glGetIntegerv(GL_STENCIL_BACK_REF,                 &state_.stencil_state_.stencil_back_ref);
    ::glGetIntegerv(GL_STENCIL_CLEAR_VALUE,              &state_.stencil_state_.stencil_clear);
    ::glGetIntegerv(GL_STENCIL_WRITEMASK,                &state_.stencil_state_.stencil_front_writemask);
    ::glGetIntegerv(GL_STENCIL_BACK_WRITEMASK,           &state_.stencil_state_.stencil_back_writemask);
    ::glGetIntegerv(GL_STENCIL_FAIL,                     &state_.stencil_state_.stencil_front_fail_op);
    ::glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL,          &state_.stencil_state_.stencil_front_z_fail_op);
    ::glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS,          &state_.stencil_state_.stencil_front_z_pass_op);
    ::glGetIntegerv(GL_STENCIL_BACK_FAIL,                &state_.stencil_state_.stencil_back_fail_op);
    ::glGetIntegerv(GL_STENCIL_BACK_PASS_DEPTH_FAIL,     &state_.stencil_state_.stencil_back_z_fail_op);
    ::glGetIntegerv(GL_STENCIL_BACK_PASS_DEPTH_PASS,     &state_.stencil_state_.stencil_back_z_pass_op);
    ::glGetIntegerv(GL_FRAMEBUFFER_BINDING,              &state_.framebuffer_binding_);
    ::glGetIntegerv(GL_ARRAY_BUFFER_BINDING,             &state_.vertex_array_buffer_binding_);
    ::glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING,     &state_.index_array_buffer_binding_);
    ::glGetBooleanv(GL_BLEND,                            &state_.blend_enabled_);
    ::glGetIntegerv(GL_BLEND_SRC_RGB,                    &state_.blend_src_rgb_);
    ::glGetIntegerv(GL_BLEND_SRC_ALPHA,                  &state_.blend_src_alpha_);
    ::glGetIntegerv(GL_BLEND_DST_RGB,                    &state_.blend_dest_rgb_);
    ::glGetIntegerv(GL_BLEND_DST_ALPHA,                  &state_.blend_dest_alpha_);
    ::glGetIntegerv(GL_VIEWPORT,                          state_.viewport_);
    ::glGetBooleanv(GL_SCISSOR_TEST,                     &state_.scissor_test_);
    ::glGetIntegerv(GL_SCISSOR_BOX,                       state_.scissor_box_);
    ::glGetIntegerv(GL_PACK_ALIGNMENT,                   &state_.pack_alignment_);
    ::glGetIntegerv(GL_UNPACK_ALIGNMENT,                 &state_.unpack_alignment_);
    ::glGetBooleanv(GL_DEPTH_TEST,                       &state_.depth_test_);
    ::glGetBooleanv(GL_CULL_FACE,                        &state_.cull_face_);
    ::glGetIntegerv(GL_CULL_FACE_MODE,                   &state_.cull_face_mode_);
    ::glGetBooleanv(GL_COLOR_WRITEMASK,                   state_.color_mask_);
    ::glGetIntegerv(GL_CURRENT_PROGRAM,                  &state_.current_program_);
    ::glGetFloatv  (GL_COLOR_CLEAR_VALUE,                 state_.color_clear_);
    ::glGetFloatv  (GL_DEPTH_CLEAR_VALUE,                &state_.depth_clear_);
    ::glGetFloatv  (GL_BLEND_COLOR,                       state_.blend_color_);
    ::glGetIntegerv(GL_DEPTH_FUNC,                       &state_.depth_func_);
    ::glGetBooleanv(GL_DEPTH_WRITEMASK,                  &state_.depth_mask_);
    ::glGetFloatv  (GL_DEPTH_RANGE,                       state_.depth_rage_);
    ::glGetIntegerv(GL_FRONT_FACE,                       &state_.front_face_);
    ::glGetIntegerv(GL_GENERATE_MIPMAP_HINT,             &state_.hint_generate_mipmap_);
    ::glGetFloatv  (GL_LINE_WIDTH,                       &state_.line_width_);
    ::glGetFloatv  (GL_POLYGON_OFFSET_FACTOR,            &state_.polygon_offset_factor_);
    ::glGetFloatv  (GL_POLYGON_OFFSET_UNITS,             &state_.polygon_offset_units_);
    ::glGetFloatv  (GL_SAMPLE_COVERAGE_VALUE,            &state_.sample_coverage_value_);
    ::glGetBooleanv(GL_SAMPLE_COVERAGE_INVERT,           &state_.sample_coverage_invert_);
    ::glGetIntegerv(GL_BLEND_EQUATION_RGB,               &state_.blend_equation_rgb_);
    ::glGetIntegerv(GL_BLEND_EQUATION_ALPHA,             &state_.blend_equation_alpha_);
    ::glGetBooleanv(GL_DITHER,                           &state_.enable_dither_);
    ::glGetBooleanv(GL_POLYGON_OFFSET_FILL,              &state_.enable_polygon_offset_fill_);
    ::glGetBooleanv(GL_SAMPLE_ALPHA_TO_COVERAGE,         &state_.enable_sample_alpha_to_coverage_);
    ::glGetBooleanv(GL_SAMPLE_COVERAGE,                  &state_.enable_sample_coverage_);
    ::glGetIntegerv(GL_ACTIVE_TEXTURE,                   &state_.active_texture_);
    state_.texture_bindings_.resize(state_.max_texture_units_);
    for (int i = 0; i < state_.max_texture_units_; ++i) {
        texture_bindings& bindings = state_.texture_bindings_[i];
        ::glActiveTexture(GL_TEXTURE0 + i);
        ::glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &bindings.texture_cube_map);
        ::glGetIntegerv(GL_TEXTURE_BINDING_2D,       &bindings.texture_2d);
    }
    if (with_restore) { ::glActiveTexture(state_.active_texture_); }
    ::glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &state_.vertex_array_bindings_);
    ::glBindVertexArray(0);
    state_.vertex_attrib_.resize(state_.max_vertex_attribs_);
    for (GLint i = 0; i < state_.max_vertex_attribs_; ++i) {
        ::glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING,
            &state_.vertex_attrib_[i].vertex_attrib_array_buffer_binding);
        ::glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_ENABLED, 
            &state_.vertex_attrib_[i].enabled);
        ::glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_SIZE, 
            &state_.vertex_attrib_[i].size);
        ::glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_TYPE, 
            &state_.vertex_attrib_[i].type);
        ::glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, 
            &state_.vertex_attrib_[i].normalized);
        ::glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_STRIDE, 
            &state_.vertex_attrib_[i].stride);
        ::glGetVertexAttribPointerv(i, GL_VERTEX_ATTRIB_ARRAY_POINTER, 
            &state_.vertex_attrib_[i].pointer);
        ::glGetVertexAttribfv(i, GL_CURRENT_VERTEX_ATTRIB, 
            state_.vertex_attrib_[i].current_vertex_attrib);
    }
    if (with_restore) { ::glBindVertexArray(state_.vertex_array_bindings_); }
}

