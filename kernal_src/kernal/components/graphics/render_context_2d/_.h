
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/renderer/include/canvas_center.h"
#include "infrastructure/renderer/include/render_util_tools.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/command_buffer/transmitter.h"
#include "kernal/asynchronous/runnable/committer.h"
#include "kernal/basis_service/event_observer.h"
#include "kernal/bestead/puppet.h"
#include "kernal/isolate/related_thread.h"
#include "kernal/cc/care_render_connector.h"
#include "kernal/components/graphics/canvas/_.h"
#include "render_context.h"
#include "render_context_thread_related.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace service;
using namespace renderer;
using namespace asynchronous;
using namespace bestead;
using namespace isolate;
class render_context_2d {
public:
	render_context_2d() = default;
	render_context_2d(__sptr<command_transmitter>, 
		puppet<renderer::canvas>&, 
		std::shared_ptr<alived_token<canvas>>);
	virtual ~render_context_2d();

public:
	// attr
	void anti_alias    			(js_parameter&);
	void set_anti_alias			(js_parameter&);
	void fill_style				(js_parameter&);
	void set_fill_style			(js_parameter&);
	void stroke_style			(js_parameter&);
	void set_stroke_style		(js_parameter&);
	void font					(js_parameter&);
	void set_font				(js_parameter&);
	void global_alpha			(js_parameter&);
	void set_global_alpha		(js_parameter&);
	void global_composite		(js_parameter&);
	void set_global_composite	(js_parameter&);
	void line_cap				(js_parameter&);
	void set_line_cap			(js_parameter&);
	void line_dash_offset		(js_parameter&);
	void set_line_dash_offset	(js_parameter&);
	void line_join				(js_parameter&);
	void set_line_join			(js_parameter&);
	void line_width				(js_parameter&);
	void set_line_width			(js_parameter&);
	void miter_limit			(js_parameter&);
	void set_miter_limit		(js_parameter&);
	void shadow_blur			(js_parameter&);
	void set_shadow_blur		(js_parameter&);
	void shadow_color			(js_parameter&);
	void set_shadow_color		(js_parameter&);
	void shadow_offset_x 		(js_parameter&);
	void set_shadow_offset_x 	(js_parameter&);
	void shadow_offset_y		(js_parameter&);
	void set_shadow_offset_y	(js_parameter&);
	void text_align				(js_parameter&);
	void set_text_align			(js_parameter&);
	void text_baseline			(js_parameter&);
	void set_text_baseline		(js_parameter&);

	// function
	void arc 					(js_parameter&);
	void arc_to 				(js_parameter&);
	void begin_path 			(js_parameter&);
	void bezier_curve_to 		(js_parameter&);
	void clear_rect 			(js_parameter&);
	void clip 					(js_parameter&);
	void close_path 			(js_parameter&);
	void create_image_data 		(js_parameter&);
	void create_linear_gradient (js_parameter&);
	void create_pattern 		(js_parameter&);
	void create_radial_gradient (js_parameter&);
	void draw_image 			(js_parameter&);
	void fill 					(js_parameter&);
	void fill_rect 				(js_parameter&);
	void fill_text 				(js_parameter&);
	void get_image_data 		(js_parameter&);
	void get_line_dash			(js_parameter&);
	void is_point_in_path		(js_parameter&);
	void is_point_in_stroke		(js_parameter&);
	void line_to				(js_parameter&);
	void measure_text			(js_parameter&);
	void move_to				(js_parameter&);
	void put_image_data			(js_parameter&);
	void quadratic_curve_to		(js_parameter&);
	void rect					(js_parameter&);
	void restore				(js_parameter&);
	void rotate					(js_parameter&);
	void save					(js_parameter&);
	void scale					(js_parameter&);
	void set_line_dash			(js_parameter&);
	void set_transform			(js_parameter&);
	void stroke					(js_parameter&);
	void stroke_rect			(js_parameter&);
	void stroke_text			(js_parameter&);
	void transform				(js_parameter&);
	void translate				(js_parameter&);

private:
	void force_commit();

public:
	std::shared_ptr<command_transmitter> transmitter_;
	puppet<canvas_render_2d> raw_context_;
	std::shared_ptr<render_context_thread_related> related_;
	std::shared_ptr<alived_token<canvas>> related_canvas_;

public:
    static void outlet(js_context&, js_object&);
};


}}}