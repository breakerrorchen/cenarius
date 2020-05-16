
#pragma once
#include "render_care.h"

namespace cenarius { namespace infrastructure { namespace renderer {
struct stencil_state {
    unsigned char stencil_test_enabled;
    int stencil_front_func;
    int stencil_front_ref;
    int stencil_front_mask;
    int stencil_back_func;
    int stencil_back_ref;
    int stencil_back_mask;
    int stencil_clear;
    int stencil_front_writemask;
    int stencil_back_writemask;
    int stencil_front_fail_op;
    int stencil_front_z_fail_op;
    int stencil_front_z_pass_op;
    int stencil_back_fail_op;
    int stencil_back_z_fail_op;
    int stencil_back_z_pass_op;
};

struct vertex_attributes {
    GLint enabled;
    GLint size;
    GLint type;
    GLint normalized;
    GLint stride;
    GLvoid* pointer;
    GLint vertex_attrib_array_buffer_binding;
    GLfloat current_vertex_attrib[4];
};

struct texture_bindings {
    GLint texture_2d;
    GLint texture_cube_map;
    GLint texture_external_oes;
};

struct context_state {
    GLint max_vertex_attribs_;
    GLint max_texture_units_;
    GLint pack_alignment_;
    GLint unpack_alignment_;
    GLint vertex_array_buffer_binding_;
    GLint index_array_buffer_binding_;
    GLboolean depth_test_;
    GLboolean cull_face_;
    GLint cull_face_mode_;
    GLboolean color_mask_[4];
    GLfloat color_clear_[4];
    GLfloat blend_color_[4];
    GLfloat depth_clear_;
    GLint current_program_;
    GLint depth_func_;
    GLboolean depth_mask_;
    GLfloat depth_rage_[2];
    GLint front_face_;
    GLint hint_generate_mipmap_;
    GLfloat line_width_;
    GLfloat polygon_offset_factor_;
    GLfloat polygon_offset_units_;
    GLfloat sample_coverage_value_;
    GLboolean sample_coverage_invert_;
    GLint blend_equation_rgb_;
    GLint blend_equation_alpha_;
    GLboolean enable_dither_;
    GLboolean enable_polygon_offset_fill_;
    GLboolean enable_sample_alpha_to_coverage_;
    GLboolean enable_sample_coverage_;
    GLboolean blend_enabled_;
    GLint blend_src_rgb_;
    GLint blend_src_alpha_;
    GLint blend_dest_rgb_;
    GLint blend_dest_alpha_;
    GLint active_texture_;
    GLint viewport_[4];
    GLboolean scissor_test_;
    GLint scissor_box_[4];
    GLint framebuffer_binding_;
    GLint vertex_array_bindings_;
    std::vector<vertex_attributes> vertex_attrib_;
    stencil_state stencil_state_;
    std::vector<texture_bindings> texture_bindings_;
};


}}}