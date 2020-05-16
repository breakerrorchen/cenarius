
#pragma once
#include "conf.h"
#include "shader_reflection.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_connector {
public:
    // for webgl 1.0
    void active_texture                 (uint32_t);
    void attach_shader                  (uint32_t, uint32_t);
    void bind_attrib_location           (uint32_t, uint32_t, const char*);
    void bind_buffer                    (uint32_t, uint32_t);
    void bind_frame_buffer              (uint32_t);
    void bind_frame_buffer              (uint32_t, uint32_t);
    void bind_render_buffer             (uint32_t);
    void bind_render_buffer             (uint32_t, uint32_t);
    void bind_texture                   (uint32_t, uint32_t);
    void blend_color                    (float, float, float, float);
    void blend_equation                 (uint32_t);
    void blend_equation_separate        (uint32_t, uint32_t);
    void blend_func                     (uint32_t, uint32_t);
    void blend_func_separate            (uint32_t, uint32_t, uint32_t, uint32_t);
    void buffer_data                    (uint32_t, intptr_t, const void*, uint32_t);
    void buffer_sub_data                (uint32_t, intptr_t, intptr_t, const void*);
    void check_frame_buffer_status      (uint32_t, uint32_t*);
    void clear                          (uint32_t);
    void clear_color                    (float, float, float, float);
    void clear_depth_f                  (float);
    void clear_stencil                  (int32_t);
    void color_mask                     (bool, bool, bool, bool);
    void compile_shader                 (uint32_t);
    void compressed_tex_image2d         (); // !!! not support
    void compressed_tex_sub_image2d     (); // !!! not support
    void copy_tex_image2d               (uint32_t, int32_t, uint32_t, int32_t,
                                         int32_t, uint32_t, uint32_t, int32_t);
    void copy_tex_sub_image2d           (uint32_t, int32_t, int32_t, int32_t,
                                         int32_t, int32_t, uint32_t, uint32_t);
    void create_program                 (uint32_t*);
    void create_shader                  (uint32_t, uint32_t*);
    void cull_face                      (uint32_t);
    void delete_buffers                 (int32_t, const uint32_t*);
    void delete_frame_buffers           (int32_t, const uint32_t*);
    void delete_program                 (int32_t);
    void delete_render_buffers          (int32_t, const uint32_t*);
    void delete_shader                  (uint32_t);
    void delete_textures                (int32_t, const uint32_t*);
    void depth_func                     (uint32_t);
    void depth_mask                     (bool);
    void depth_range_f                  (float, float);
    void detach_shader                  (uint32_t, uint32_t);
    void disable                        (uint32_t);
    void disable_vertex_attr_arr        (uint32_t);
    void draw_arrays                    (uint32_t, int32_t, int32_t);
    void draw_elements                  (uint32_t, int32_t, uint32_t, const void*);
    void enable                         (uint32_t);
    void enable_vertex_attr_arr         (uint32_t);
    void finish                         ();
    void flush                          ();
    void frame_buffer_render_buffer     (uint32_t, uint32_t, uint32_t, uint32_t);
    void frame_buffer_texture2d         (uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
    void front_face                     (uint32_t);
    void gen_buffers                    (int32_t, uint32_t*);
    void gen_frame_buffers              (int32_t, uint32_t*);
    void gen_render_buffers             (int32_t, uint32_t*);
    void gen_textures                   (int32_t, uint32_t*);
    void generate_mipmap                (uint32_t);
    void get_boolean_v                  (uint32_t, bool*);
    void get_float_v                    (uint32_t, float*);
    void get_integer_v                  (uint32_t, int32_t*);
    void get_active_attrib              (uint32_t, uint32_t, int32_t,
                                         int32_t*, int32_t*, uint32_t*, char*);
    void get_active_uniform             (uint32_t, uint32_t, int32_t,
                                         int32_t*, int32_t*, uint32_t*, char*);
    void get_attached_shaders           (uint32_t, int32_t, int32_t*, uint32_t*);
    void get_attrib_location            (uint32_t, const char*, int32_t*);
    void get_buffer_parameteri_v        (uint32_t, uint32_t, int32_t*);
    void get_error                      (uint32_t*);
    void get_frame_buffer_attach_param_v(uint32_t, uint32_t, uint32_t, int32_t*);
    void get_program_info_log           (uint32_t, int32_t, int32_t*, char*);
    void get_program_i_v                (uint32_t, uint32_t, int32_t*);
    void get_render_buffer_parameteri_v (uint32_t, uint32_t, int32_t*);
    void get_shader_info_log            (uint32_t, int32_t, int32_t*, char*);
    void get_shader_precision_format    (uint32_t, uint32_t, int32_t*, int32_t*);
    void get_shader_source              (uint32_t, uint32_t, uint32_t*, char*);
    void get_shader_i_v                 (uint32_t, uint32_t, int32_t*);
    void get_string                     (uint32_t, std::string&);
    void get_tex_parameter_f_v          (uint32_t, uint32_t, float*);
    void get_tex_parameter_i_v          (uint32_t, uint32_t, int32_t*);
    void get_uniform_f_v                (uint32_t, uint32_t, float*);
    void get_uniform_i_v                (uint32_t, uint32_t, int32_t*);
    void get_uniform_location           (uint32_t, const char*, int32_t*);
    void get_vertex_attrib_f_v          (uint32_t, uint32_t, float*);
    void get_vertex_attrib_i_v          (uint32_t, uint32_t, int32_t*);
    void get_vertex_attrib_pointer_v    (uint32_t, uint32_t, void**);
    void hint                           (uint32_t, uint32_t);
    void is_buffer                      (uint32_t, bool*);
    void is_enabled                     (uint32_t, bool*);
    void is_frame_buffer                (uint32_t, bool*);
    void is_program                     (uint32_t, bool*);
    void is_render_buffer               (uint32_t, bool*);
    void is_shader                      (uint32_t, bool*);
    void is_texture                     (uint32_t, bool*);
    void line_width                     (float);
    void link_program                   (uint32_t, shader_reflection*);
    void pixel_store_i                  (uint32_t, int32_t);
    void polygon_offset                 (float, float);
    void read_pixels                    (int32_t, int32_t, uint32_t,
                                         uint32_t, uint32_t, uint32_t, void*);
    void release_shader_compiler        ();
    void render_buffer_storage          (uint32_t, uint32_t, uint32_t, uint32_t);
    void sample_coverage                (float, bool);
    void scissor                        (int32_t, int32_t, uint32_t, uint32_t);
    void shader_binary                  ();
    void shader_source                  (uint32_t, const char*, int32_t);
    void stencil_func                   (uint32_t, int32_t, uint32_t);
    void stencil_func_separate          (uint32_t, uint32_t, int32_t, uint32_t);
    void stencil_mask                   (uint32_t);
    void stencil_mask_separate          (uint32_t, uint32_t);
    void stencil_op                     (uint32_t, uint32_t, uint32_t);
    void stencil_op_separate            (uint32_t, uint32_t, uint32_t, uint32_t);
    void tex_image2d                    (uint32_t, int32_t, int32_t, uint32_t, uint32_t,
                                         int32_t, uint32_t, uint32_t, const void*);
    void tex_parameter_f                (uint32_t, uint32_t, float);
    void tex_parameter_i                (uint32_t, uint32_t, int32_t);
    void tex_sub_image2d                (uint32_t, int32_t, int32_t, int32_t, uint32_t,
                                         uint32_t, uint32_t, uint32_t, const void*);
    void uniform_1_f                    (int32_t, float);
    void uniform_2_f                    (int32_t, float, float);
    void uniform_3_f                    (int32_t, float, float, float);
    void uniform_4_f                    (int32_t, float, float, float, float);
    void uniform_1_i                    (int32_t, int32_t);
    void uniform_2_i                    (int32_t, int32_t, int32_t);
    void uniform_3_i                    (int32_t, int32_t, int32_t, int32_t);
    void uniform_4_i                    (int32_t, int32_t, int32_t, int32_t, int32_t);
        
    void uniform_1_f_v                  (int32_t, uint32_t, float*);
    void uniform_2_f_v                  (int32_t, uint32_t, float*);
    void uniform_3_f_v                  (int32_t, uint32_t, float*);
    void uniform_4_f_v                  (int32_t, uint32_t, float*);
    void uniform_1_i_v                  (int32_t, uint32_t, int32_t*);
    void uniform_2_i_v                  (int32_t, uint32_t, int32_t*);
    void uniform_3_i_v                  (int32_t, uint32_t, int32_t*);
    void uniform_4_i_v                  (int32_t, uint32_t, int32_t*);
    void uniform_matrix_2_f_v           (int32_t, uint32_t, bool, float*);
    void uniform_matrix_3_f_v           (int32_t, uint32_t, bool, float*);
    void uniform_matrix_4_f_v           (int32_t, uint32_t, bool, float*);
        
    void use_program                    (uint32_t);
    void validate_program               (uint32_t);
    void vertex_attrib_1_f              (uint32_t, float);
    void vertex_attrib_2_f              (uint32_t, float, float);
    void vertex_attrib_3_f              (uint32_t, float, float, float);
    void vertex_attrib_4_f              (uint32_t, float, float, float, float);
    void vertex_attrib_1_f_v            (uint32_t, float*);
    void vertex_attrib_2_f_v            (uint32_t, float*);
    void vertex_attrib_3_f_v            (uint32_t, float*);
    void vertex_attrib_4_f_v            (uint32_t, float*);
    void vertex_attrib_pointer          (uint32_t, int32_t,
                                         uint32_t, bool, uint32_t, const void*);
    void viewport                       (int32_t, int32_t, uint32_t, uint32_t);

    // for webgl 2.0
    
public:
    uint32_t related_frambuffer_id_ = 0;
};


}}}