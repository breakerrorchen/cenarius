
#pragma once
#include "conf.h"
#include "shader_reflection.h"
#include "syncer.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_connector {
public:
    void active_texture                 (uint32_t);
    void attach_shader                  (uint32_t, uint32_t);
    void begin_query                    (uint32_t, uint32_t);
    void begin_transform_feedback       (uint32_t);
    void bind_attrib_location           (uint32_t, uint32_t, const char*);
    void bind_buffer                    (uint32_t, uint32_t);
    void bind_buffer_base               (uint32_t, uint32_t, uint32_t);
    void bind_buffer_range              (uint32_t, uint32_t, uint32_t, intptr_t, uint32_t);
    void bind_frame_buffer              (uint32_t);
    void bind_frame_buffer              (uint32_t, uint32_t);
    void bind_render_buffer             (uint32_t);
    void bind_render_buffer             (uint32_t, uint32_t);
    void bind_sampler                   (uint32_t, uint32_t);
    void bind_texture                   (uint32_t, uint32_t);
    void bind_transform_feedback        (uint32_t, uint32_t);
    void bind_vertx_array               (uint32_t);
    void blend_color                    (float, float, float, float);
    void blend_equation                 (uint32_t);
    void blend_equation_separate        (uint32_t, uint32_t);
    void blend_func                     (uint32_t, uint32_t);
    void blend_func_separate            (uint32_t, uint32_t, uint32_t, uint32_t);
    void blit_frame_buffer              (int32_t, int32_t, int32_t, int32_t,
                                         int32_t, int32_t, int32_t, int32_t,
                                         uint32_t, uint32_t);
    void buffer_data                    (uint32_t, intptr_t, const void*, uint32_t);
    void buffer_sub_data                (uint32_t, intptr_t, intptr_t, const void*);
    void check_frame_buffer_status      (uint32_t, uint32_t*);
    void clear                          (uint32_t);
    void clear_buffer_i_v               (uint32_t, int32_t, int32_t*);
    void clear_buffer_u_i_v             (uint32_t, int32_t, uint32_t*);
    void clear_buffer_f_v               (uint32_t, int32_t, float*);
    void clear_buffer_f_i               (uint32_t, int32_t, float, int32_t);
    void clear_color                    (float, float, float, float);
    void clear_depth_f                  (float);
    void clear_stencil                  (int32_t);
    void client_wait_sync               (render_syncer*, uint32_t, uint64_t, uint32_t*);
    void color_mask                     (bool, bool, bool, bool);
    void compile_shader                 (uint32_t);
    void compressed_tex_image2d         (); // !!! not support
    void compressed_tex_image3d         (); // !!! not support
    void compressed_tex_sub_image2d     (); // !!! not support
    void compressed_tex_sub_image3d     (); // !!! not support
    void copy_tex_image2d               (uint32_t, int32_t, uint32_t, int32_t,
                                         int32_t, uint32_t, uint32_t, int32_t);
    void copy_tex_sub_image2d           (uint32_t, int32_t, int32_t, int32_t,
                                         int32_t, int32_t, uint32_t, uint32_t);
    void copy_tex_sub_image3d           (uint32_t, int32_t, int32_t, int32_t,
                                         int32_t, int32_t, int32_t, uint32_t, 
                                         uint32_t);
    void create_program                 (uint32_t*);
    void create_shader                  (uint32_t, uint32_t*);
    void cull_face                      (uint32_t);
    void delete_buffers                 (int32_t, const uint32_t*);
    void delete_frame_buffers           (int32_t, const uint32_t*);
    void delete_program                 (int32_t);
    void delete_queries                 (int32_t, const uint32_t*);
    void delete_render_buffers          (int32_t, const uint32_t*);
    void delete_samplers                (int32_t, const uint32_t*);
    void delete_shader                  (uint32_t);
    void delete_sync                    (render_syncer*);
    void delete_textures                (int32_t, const uint32_t*);
    void delete_transform_feedbacks     (int32_t, const uint32_t*);
    void delete_vertex_arrays           (int32_t, const uint32_t*);
    void depth_func                     (uint32_t);
    void depth_mask                     (bool);
    void depth_range_f                  (float, float);
    void detach_shader                  (uint32_t, uint32_t);
    void disable                        (uint32_t);
    void disable_vertex_attr_arr        (uint32_t);
    void draw_arrays                    (uint32_t, int32_t, int32_t);
    void draw_arrays_instanced          (uint32_t, int32_t, int32_t, int32_t);
    void draw_buffers                   (int32_t, const uint32_t*);
    void draw_elements                  (uint32_t, int32_t, uint32_t, const void*);
    void draw_elements_instance         (uint32_t, int32_t, uint32_t, 
                                         const void*, int32_t);
    void draw_range_elements            (uint32_t, uint32_t, uint32_t, int32_t,
                                         uint32_t, const void*);
    void enable                         (uint32_t);
    void enable_vertex_attr_arr         (uint32_t);
    void end_query                      (uint32_t);
    void end_transform_feedback         ();
    void fence_sync                     (uint32_t, uint32_t);
    void finish                         ();
    void flush                          ();
    void flush_mapped_buffer_range      (uint32_t, intptr_t, int32_t);
    void frame_buffer_render_buffer     (uint32_t, uint32_t, uint32_t, uint32_t);
    void frame_buffer_texture2d         (uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
    void frame_buffer_texture_layer     (uint32_t, uint32_t, uint32_t, int32_t, int32_t);
    void front_face                     (uint32_t);
    void gen_buffers                    (int32_t, uint32_t*);
    void gen_frame_buffers              (int32_t, uint32_t*);
    void gen_queries                    (int32_t, uint32_t*);
    void gen_render_buffers             (int32_t, uint32_t*);
    void gen_samplers                   (int32_t, uint32_t*);
    void gen_textures                   (int32_t, uint32_t*);
    void gen_transform_feedbacks        (int32_t, uint32_t*);
    void gen_vertex_arrays              (int32_t, uint32_t*);
    void generate_mipmap                (uint32_t);
    void get_boolean_v                  (uint32_t, bool*);
    void get_float_v                    (uint32_t, float*);
    void get_integer_v                  (uint32_t, int32_t*);
    void get_integer64_v                (uint32_t, int64_t*);
    void get_integer_i_v                (uint32_t, uint32_t, int32_t*);
    void get_integer64_i_v              (uint32_t, uint32_t, int64_t*);
    void get_active_attrib              (uint32_t, uint32_t, int32_t,
                                         int32_t*, int32_t*, uint32_t*, char*);
    void get_active_uniform             (uint32_t, uint32_t, int32_t,
                                         int32_t*, int32_t*, uint32_t*, char*);
    void get_active_uniform_block_i_v   (uint32_t, uint32_t, uint32_t, int32_t*);
    void get_active_uniform_block_name  (uint32_t, uint32_t, int32_t, int32_t*, char*);
    void get_active_uniform_s_i_v       (uint32_t, int32_t, const uint32_t*, 
                                         uint32_t, int32_t*);
    void get_attached_shaders           (uint32_t, int32_t, int32_t*, uint32_t*);
    void get_attrib_location            (uint32_t, const char*, int32_t*);
    void get_buffer_parameter_i_v       (uint32_t, uint32_t, int32_t*);
    void get_buffer_parameter_i64_v     (uint32_t, uint32_t, int64_t*);
    void get_buffer_pointer_v           (uint32_t, uint32_t, void**);
    void get_frag_data_location         (uint32_t, const char*, int32_t*);
    void get_error                      (uint32_t*);
    void get_frame_buffer_attach_param_v(uint32_t, uint32_t, uint32_t, int32_t*);
    void get_internal_format_i_v        (uint32_t, uint32_t, uint32_t, int32_t, int32_t*);
    void get_program_binary             (uint32_t, int32_t, int32_t*, uint32_t*, void*);
    void get_program_info_log           (uint32_t, int32_t, int32_t*, char*);
    void get_program_i_v                (uint32_t, uint32_t, int32_t*);
    void get_query_i_v                  (uint32_t, uint32_t, int32_t*);
    void get_query_object_u_i_v         (uint32_t, uint32_t, uint32_t*);
    void get_render_buffer_parameteri_v (uint32_t, uint32_t, int32_t*);
    void get_sampler_parameter_f_v      (uint32_t, uint32_t, float*);
    void get_sampler_parameter_i_v      (uint32_t, uint32_t, int32_t*);
    void get_shader_info_log            (uint32_t, int32_t, int32_t*, char*);
    void get_shader_precision_format    (uint32_t, uint32_t, int32_t*, int32_t*);
    void get_shader_source              (uint32_t, uint32_t, uint32_t*, char*);
    void get_shader_i_v                 (uint32_t, uint32_t, int32_t*);
    void get_string                     (uint32_t, std::string&);
    void get_string_i                   (uint32_t, uint32_t, std::string&);
    void get_sync_i_v                   (render_syncer*, uint32_t, int32_t,
                                         int32_t*, int32_t*);
    void get_tex_parameter_f_v          (uint32_t, uint32_t, float*);
    void get_tex_parameter_i_v          (uint32_t, uint32_t, int32_t*);
    void get_transform_feedback_varying (uint32_t, uint32_t, int32_t, int32_t*,
                                         int32_t*, uint32_t*, char*);
    void get_uniform_f_v                (uint32_t, uint32_t, float*);
    void get_uniform_i_v                (uint32_t, uint32_t, int32_t*);
    void get_uniform_u_i_v              (uint32_t, uint32_t, uint32_t*);
    void get_uniform_block_index        (uint32_t, const char*, uint32_t*);
    void get_uniform_indices            (uint32_t, int32_t, const char**, uint32_t*);
    void get_uniform_location           (uint32_t, const char*, int32_t*);
    void get_vertex_attrib_f_v          (uint32_t, uint32_t, float*);
    void get_vertex_attrib_i_v          (uint32_t, uint32_t, int32_t*);
    void get_vertex_attrib_i_i_v        (uint32_t, uint32_t, int32_t*);
    void get_vertex_attrib_i_u_i_v      (uint32_t, uint32_t, uint32_t*);
    void get_vertex_attrib_pointer_v    (uint32_t, uint32_t, void**);
    void hint                           (uint32_t, uint32_t);
    void invalidate_frame_buffer        (uint32_t, int32_t, const uint32_t*);
    void invalidate_sub_frame_buffer    (uint32_t, int32_t, const uint32_t*,
                                         int32_t, int32_t, int32_t, int32_t);
    void is_buffer                      (uint32_t, bool*);
    void is_enabled                     (uint32_t, bool*);
    void is_frame_buffer                (uint32_t, bool*);
    void is_program                     (uint32_t, bool*);
    void is_query                       (uint32_t, bool*);
    void is_render_buffer               (uint32_t, bool*);
    void is_sampler                     (uint32_t, bool*);
    void is_shader                      (uint32_t, bool*);
    void is_sync                        (render_syncer*, bool*);
    void is_texture                     (uint32_t, bool*);
    void is_transform_feedback          (uint32_t, bool*);
    void line_width                     (float);
    void link_program                   (uint32_t, shader_reflection*);
    void map_buffer_range               (uint32_t, intptr_t, int32_t, uint32_t, void**);
    void pause_transform_feedback       ();
    void pixel_store_i                  (uint32_t, int32_t);
    void polygon_offset                 (float, float);
    void program_binary                 (uint32_t, uint32_t, void*, int32_t);
    void program_parameter_i            (uint32_t, uint32_t, int32_t);
    void read_pixels                    (int32_t, int32_t, uint32_t,
                                         uint32_t, uint32_t, uint32_t, void*);
    void read_buffer                    (uint32_t);
    void release_shader_compiler        ();
    void render_buffer_storage          (uint32_t, uint32_t, uint32_t, uint32_t);
    void render_buffer_storage_ms       (uint32_t, int32_t, uint32_t, int32_t, int32_t);
    void resume_transform_feedback      ();
    void sample_coverage                (float, bool);
    void sample_parameter_f             (uint32_t, uint32_t, float);
    void sample_parameter_i             (uint32_t, uint32_t, int32_t);
    void sample_parameter_f_v           (uint32_t, uint32_t, float*);
    void sample_parameter_i_v           (uint32_t, uint32_t, int32_t*);
    void scissor                        (int32_t, int32_t, uint32_t, uint32_t);
    void shader_binary                  (int32_t, const uint32_t*, uint32_t,
                                         const void*, int32_t);
    void shader_source                  (uint32_t, const char*, int32_t);
    void stencil_func                   (uint32_t, int32_t, uint32_t);
    void stencil_func_separate          (uint32_t, uint32_t, int32_t, uint32_t);
    void stencil_mask                   (uint32_t);
    void stencil_mask_separate          (uint32_t, uint32_t);
    void stencil_op                     (uint32_t, uint32_t, uint32_t);
    void stencil_op_separate            (uint32_t, uint32_t, uint32_t, uint32_t);
    void tex_image2d                    (uint32_t, int32_t, int32_t, int32_t, int32_t,
                                         int32_t, uint32_t, uint32_t, const void*);
    void tex_image3d                    (uint32_t, int32_t, int32_t, int32_t, int32_t,
                                         int32_t, int32_t, uint32_t, uint32_t, const void*);
    void tex_parameter_f                (uint32_t, uint32_t, float);
    void tex_parameter_i                (uint32_t, uint32_t, int32_t);
    void tex_parameter_f_v              (uint32_t, uint32_t, float*);
    void tex_parameter_i_v              (uint32_t, uint32_t, int32_t*);
    void tex_storage2d                  (uint32_t, int32_t, uint32_t, int32_t, int32_t);
    void tex_storage3d                  (uint32_t, int32_t, uint32_t, int32_t, int32_t, int32_t);
    void tex_sub_image2d                (uint32_t, int32_t, int32_t, int32_t, uint32_t,
                                         uint32_t, uint32_t, uint32_t, const void*);
    void tex_sub_image3d                (uint32_t, int32_t, int32_t, int32_t, int32_t,
                                         int32_t, int32_t, int32_t, uint32_t, uint32_t,
                                         const void*);
    void transform_feedback_varyings    (uint32_t, int32_t, const char**, uint32_t);
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
public:
    uint32_t related_frambuffer_id_ = 0;
};


}}}