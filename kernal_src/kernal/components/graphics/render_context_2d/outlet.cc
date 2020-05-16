
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_2d::outlet(js_context& _context, js_object& _object) {
	auto thread_related = related_thread::obtain();
	assert(thread_related);
	assert(_context.is_useable() && _object.is_useable());
	using __class_t__ = render_context_2d;
	js_class _class(_context);

#ifndef __render_context_2d_attr
#define __render_context_2d_attr(name, _attr)									\
	_class.attr(#name, 															\
		_I_BIND(render_context_2d, set_##_attr),								\
		_I_BIND(render_context_2d, _attr));
	__render_context_2d_attr(antialias, 		anti_alias		);
	__render_context_2d_attr(fillStyle, 		fill_style		);
	__render_context_2d_attr(strokeStyle, 		stroke_style	);
	__render_context_2d_attr(font, 				font			);
	__render_context_2d_attr(globalAlpha, 		global_alpha	);
	__render_context_2d_attr(globalComposite,	global_composite);
	__render_context_2d_attr(lineCap, 			line_cap		);
	__render_context_2d_attr(lineDashOffset, 	line_dash_offset);
	__render_context_2d_attr(lineJoin, 			line_join		);
	__render_context_2d_attr(lineWidth, 		line_width		);
	__render_context_2d_attr(miterLimit, 		miter_limit		);
	__render_context_2d_attr(shadowBlur, 		shadow_blur		);
	__render_context_2d_attr(shadowColor, 		shadow_color	);
	__render_context_2d_attr(shadowOffsetX, 	shadow_offset_x	);
	__render_context_2d_attr(shadowOffsetY, 	shadow_offset_y	);
	__render_context_2d_attr(strokeStyle, 		stroke_style	);
	__render_context_2d_attr(textAlign, 		text_align		);
	__render_context_2d_attr(textBaseline, 		text_baseline	);
#undef __render_context_2d_attr
#endif

#ifndef __render_context_2d_func
#define __render_context_2d_func(name, _func)									\
	_class.function(#name, _I_BIND(render_context_2d, _func));
	__render_context_2d_func(arc, 					arc						);
	__render_context_2d_func(arcTo, 				arc_to					);
	__render_context_2d_func(beginPath, 			begin_path				);
	__render_context_2d_func(bezierCurveTo, 		bezier_curve_to			);
	__render_context_2d_func(clearRect, 			clear_rect				);
	__render_context_2d_func(clip, 					clip					);
	__render_context_2d_func(closePath, 			close_path				);
	__render_context_2d_func(createImageData, 		create_image_data		);
	__render_context_2d_func(createLinearGradient, 	create_linear_gradient	);
	__render_context_2d_func(createPattern, 		create_pattern			);
	__render_context_2d_func(createRadialGradient, 	create_radial_gradient	);
	__render_context_2d_func(drawImage, 			draw_image				);
	__render_context_2d_func(fill, 					fill					);
	__render_context_2d_func(fillRect, 				fill_rect				);
	__render_context_2d_func(fillText, 				fill_text				);
	__render_context_2d_func(getImageData, 			get_image_data			);
	__render_context_2d_func(getLineDash, 			get_line_dash			);
	__render_context_2d_func(isPointInPath, 		is_point_in_path		);
	__render_context_2d_func(isPointInStroke, 		is_point_in_stroke		);
	__render_context_2d_func(lineTo, 				line_to					);
	__render_context_2d_func(measureText, 			measure_text			);
	__render_context_2d_func(moveTo, 				move_to					);
	__render_context_2d_func(putImageData, 			put_image_data			);
	__render_context_2d_func(quadraticCurveTo, 		quadratic_curve_to		);
	__render_context_2d_func(rect, 					rect					);
	__render_context_2d_func(restore, 				restore					);
	__render_context_2d_func(rotate, 				rotate					);
	__render_context_2d_func(save, 					save					);
	__render_context_2d_func(scale, 				scale					);
	__render_context_2d_func(setLineDash, 			set_line_dash			);
	__render_context_2d_func(setTransform, 			set_transform			);
	__render_context_2d_func(stroke, 				stroke					);
	__render_context_2d_func(strokeRect, 			stroke_rect				);
	__render_context_2d_func(transform, 			transform				);
	__render_context_2d_func(translate, 			translate				);
#undef __render_context_2d_func
#endif
	_class.build();
	_object["CanvasRenderingContext2D"] = _class.to_value(_context);
	thread_related->cls_render_context_2d_ = std::move(_class);
}