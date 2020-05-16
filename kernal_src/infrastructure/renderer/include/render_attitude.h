
#pragma once
#include <assert.h>
#include <stdio.h>
#include <memory>

namespace cenarius { namespace infrastructure { namespace renderer {
class render_attitude final {
public:
    uint32_t alpha_bits_;
    uint32_t red_bits_;
    uint32_t blue_bits_;
    uint32_t green_bits_;
    uint32_t depth_bits_;
    uint32_t stencil_bits_;
    uint32_t max_3d_texture_size_;
    uint32_t max_array_texture_layers_;
    uint32_t aliased_line_width_range_[2];
    uint32_t aliased_point_size_range_[2];
    uint32_t max_combined_texture_image_units_;
    uint32_t max_cube_map_texture_size_;
    uint32_t max_fragment_uniform_vectors_;
    uint32_t max_renderbuffer_size_;
    uint32_t max_texture_image_units_;
    uint32_t max_texture_size_;
    uint32_t max_varying_vectors_;
    uint32_t max_vertex_attribs_;
    uint32_t max_vertex_texture_image_units_;
    uint32_t max_vertex_uniform_vectors_;
    uint32_t max_viewport_size_[2];
    uint32_t subpixel_bits_;    

    struct shader_precision {
        float range_min_, range_max_, precision_;
    };
    shader_precision vs_l_f_, vs_m_f_, vs_h_f_;
    shader_precision vs_l_i_, vs_m_i_, vs_h_i_;
    shader_precision fs_l_f_, fs_m_f_, fs_h_f_;
    shader_precision fs_l_i_, fs_m_i_, fs_h_i_;
};


}}}