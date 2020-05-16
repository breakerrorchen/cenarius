
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/renderer/include/canvas_center.h"
#include "infrastructure/renderer/include/render_attitude.h"
#include "infrastructure/renderer/include/render_util_tools.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/command_buffer/transmitter.h"
#include "kernal/asynchronous/runnable/committer.h"
#include "kernal/basis_service/event_observer.h"
#include "kernal/bestead/puppet.h"
#include "kernal/bestead/alived_token.h"
#include "kernal/isolate/related_thread.h"
#include "kernal/cc/care_render_connector.h"
#include "kernal/components/graphics/canvas/_.h"
#include "render_constants.h"
#include "render_context_local.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace service;
using namespace renderer;
using namespace asynchronous;
using namespace bestead;
using namespace isolate;
class render_context_3d {
public:
    render_context_3d(): alived_watcher_(this) { }
    render_context_3d(__sptr<command_transmitter>, 
	    puppet<renderer::canvas>&,
        std::shared_ptr<render_attitude>,
        std::shared_ptr<alived_token<canvas>>);
    virtual ~render_context_3d();

public:
	// attr
	void drawbuffer_w    		    (js_parameter&);
	void drawbuffer_h			    (js_parameter&);

    // func
    void active_texture             (js_parameter&);
    void attach_shader              (js_parameter&);
    void bind_attrib_location       (js_parameter&);
    void bind_buffer                (js_parameter&);
    void bind_framebuffer           (js_parameter&);
    void bind_renderbuffer          (js_parameter&);
    void bind_texture               (js_parameter&);
    void blend_color                (js_parameter&);
    void blend_equation             (js_parameter&);
    void blend_equation_separate    (js_parameter&);
    void blend_func                 (js_parameter&);
    void blend_func_separate        (js_parameter&);
    void buffer_data                (js_parameter&);
    void buffer_sub_data            (js_parameter&);
    void check_framebuffer_status   (js_parameter&);
    void clear                      (js_parameter&);
    void clear_color                (js_parameter&);
    void clear_depth                (js_parameter&);
    void clear_stencil              (js_parameter&);
    void color_mask                 (js_parameter&);
    void commit                     (js_parameter&);
    void compile_shader             (js_parameter&);
    void compressed_teximage_2d     (js_parameter&);
    void compressed_teximage_3d     (js_parameter&);
    void compressed_texsubimage_2d  (js_parameter&);
    void copy_teximage_2d           (js_parameter&);
    void copy_texsubimage_2d        (js_parameter&);
    void create_buffer              (js_parameter&);
    void create_framebuffer         (js_parameter&);
    void create_program             (js_parameter&);
    void create_renderbuffer        (js_parameter&);
    void create_shader              (js_parameter&);
    void create_texture             (js_parameter&);
    void cull_face                  (js_parameter&);
    void delete_buffer              (js_parameter&);
    void delete_framebuffer         (js_parameter&);
    void delete_program             (js_parameter&);
    void delete_renderbuffer        (js_parameter&);
    void delete_shader              (js_parameter&);
    void delete_texture             (js_parameter&);
    void depth_func                 (js_parameter&);
    void depth_mask                 (js_parameter&);
    void depth_range                (js_parameter&);
    void detach_shader              (js_parameter&);
    void disable                    (js_parameter&);
    void disable_vertex_attrib_arr  (js_parameter&);
    void draw_arrays                (js_parameter&);
    void draw_elements              (js_parameter&);
    void enable                     (js_parameter&);
    void enable_vertex_attrib_arr   (js_parameter&);
    void finish                     (js_parameter&);
    void flush                      (js_parameter&);
    void framebuffer_renderbuffer   (js_parameter&);
    void framebuffer_texture_2d     (js_parameter&);
    void front_face                 (js_parameter&);
    void generate_mipmap            (js_parameter&);
    void get_active_attrib          (js_parameter&);
    void get_active_uniform         (js_parameter&);
    void get_attached_shaders       (js_parameter&);
    void get_attrib_location        (js_parameter&);
    void get_buffer_parameter       (js_parameter&);
    void get_context_attributes     (js_parameter&);
    void get_error                  (js_parameter&);
    void get_extension              (js_parameter&);
    void get_framebuffer_attachment (js_parameter&);
    void get_parameter              (js_parameter&);
    void get_program_info_log       (js_parameter&);
    void get_program_parameter      (js_parameter&);
    void get_renderbuffer_parameter (js_parameter&);
    void get_shader_info_log        (js_parameter&);
    void get_shader_parameter       (js_parameter&);
    void get_shader_precision_format(js_parameter&);
    void get_shader_source          (js_parameter&);
    void get_supported_extensions   (js_parameter&);
    void get_tex_parameter          (js_parameter&);
    void get_uniform                (js_parameter&);
    void get_uniform_location       (js_parameter&);
    void get_vertex_attrib          (js_parameter&);
    void get_vertex_attrib_offset   (js_parameter&);
    void hint                       (js_parameter&);
    void is_buffer                  (js_parameter&);
    void is_context_lost            (js_parameter&);
    void is_enabled                 (js_parameter&);
    void is_framebuffer             (js_parameter&);
    void is_program                 (js_parameter&);
    void is_renderbuffer            (js_parameter&);
    void is_shader                  (js_parameter&);
    void is_texture                 (js_parameter&);
    void line_width                 (js_parameter&);
    void link_program               (js_parameter&);
    void pixel_store_i              (js_parameter&);
    void polygon_offset             (js_parameter&);
    void read_pixels                (js_parameter&);
    void renderbuffer_storage       (js_parameter&);
    void sample_coverage            (js_parameter&);
    void scissor                    (js_parameter&);
    void shader_source              (js_parameter&);
    void stencil_func               (js_parameter&);
    void stencil_func_separate      (js_parameter&);
    void stencil_mask               (js_parameter&);
    void stencil_mask_separate      (js_parameter&);
    void stencil_op                 (js_parameter&);
    void stencil_op_separate        (js_parameter&);
    void teximage_2d                (js_parameter&);
    void texparameter_f             (js_parameter&);
    void texparameter_i             (js_parameter&);
    void texsubimage_2d             (js_parameter&);
    void uniform_1_f                (js_parameter&);
    void uniform_1_f_v              (js_parameter&);
    void uniform_1_i                (js_parameter&);
    void uniform_1_i_v              (js_parameter&);
    void uniform_2_f                (js_parameter&);
    void uniform_2_f_v              (js_parameter&);
    void uniform_2_i                (js_parameter&);
    void uniform_2_i_v              (js_parameter&);
    void uniform_3_f                (js_parameter&);
    void uniform_3_f_v              (js_parameter&);
    void uniform_3_i                (js_parameter&);
    void uniform_3_i_v              (js_parameter&);
    void uniform_4_f                (js_parameter&);
    void uniform_4_f_v              (js_parameter&);
    void uniform_4_i                (js_parameter&);
    void uniform_4_i_v              (js_parameter&);
    void uniform_matrix_2_f_v       (js_parameter&);
    void uniform_matrix_3_f_v       (js_parameter&);
    void uniform_matrix_4_f_v       (js_parameter&);
    void use_program                (js_parameter&);
    void validate_program           (js_parameter&);
    void vertex_attrib_1_f          (js_parameter&);
    void vertex_attrib_2_f          (js_parameter&);
    void vertex_attrib_3_f          (js_parameter&);
    void vertex_attrib_4_f          (js_parameter&);
    void vertex_attrib_1_f_v        (js_parameter&);
    void vertex_attrib_2_f_v        (js_parameter&);
    void vertex_attrib_3_f_v        (js_parameter&);
    void vertex_attrib_4_f_v        (js_parameter&);
    void vertex_attrib_pointer      (js_parameter&);
    void viewport                   (js_parameter&);

public:
	std::shared_ptr<command_transmitter> transmitter_;
    puppet<canvas_render_3d> raw_context_;
    std::shared_ptr<render_attitude> render_attitude_;
    render_context_3d_context_local context_cache_;
    std::shared_ptr<alived_token<canvas>> related_canvas_;
    alived_watcher<render_context_3d> alived_watcher_;

public:
    static void outlet(js_context&, js_object&);
};


}}}