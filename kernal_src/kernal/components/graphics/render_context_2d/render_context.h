
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/renderer/include/canvas_center.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace renderer;
    
enum class render_text_align {
	unknown             = 0x0,
	left                = 0x1,
	right               = 0x2,
	center              = 0x3,
	start               = 0x4,
	end                 = 0x5,
};
    
enum class render_text_baseline {
	unknown             = 0x0,
	top                 = 0x1,
	hanging             = 0x2,
	middle              = 0x3,
	alphabetic          = 0x4,
	ideographic         = 0x5,
	bottom              = 0x6,
};

enum class render_context_2d_shader {
	unknown     		= 0,
	color       		= 1,
	gradient    		= 2,
	pattern     		= 3,
};
    
enum class render_context_2d_status {
	unknown     		= 0,
	stroke      		= 1,
	fill        		= 2,
};
    
struct render_context_2d_shader_data_t {
	SkColor color_              	= SK_ColorTRANSPARENT;
	render_context_2d_shader class_ = render_context_2d_shader::unknown;
	sk_sp<SkShader> gradient_   	= nullptr;
	sk_sp<SkShader> pattern_    	= nullptr;
};

class render_context_2d_context final {
public:
	render_context_2d_context() {
		fill_paint_  .setStyle(SkPaint::Style::kFill_Style  );
		stroke_paint_.setStyle(SkPaint::Style::kStroke_Style);
	}
	render_context_2d_context(const render_context_2d_context&);
	render_context_2d_context(render_context_2d_context&&);
	render_context_2d_context& operator=(const render_context_2d_context&);
	render_context_2d_context& operator=(render_context_2d_context&&);

public:
	SkPaint               			fill_paint_               ;
    SkPaint               			stroke_paint_             ;
	render_context_2d_shader_data_t stroke_style_             ;
	render_context_2d_shader_data_t fill_style_               ;
	U8CPU                 			global_alpha_ = 255       ;
	SkScalar              			typeface_size_ = 0        ;
	sk_sp<SkTypeface>     			typeface_                 ;
	std::vector<SkScalar> 			line_dash_                ;
	SkScalar              			dash_offset_ = 0          ;
	sk_sp<SkPathEffect>   			dash_path_effect_         ;
	SkColor               			shadow_color_ = 0         ;
	SkScalar              			shadow_blur_ = 0          ;
	SkScalar              			shadow_offset_x_ = 0      ;
	SkScalar              			shadow_offset_y_ = 0      ;
	sk_sp<SkDrawLooper>   			shadow_looper_            ;
	sk_sp<SkMaskFilter>				shadow_masker_ 			  ;
	render_text_baseline  			text_baseline_            ;
    float                 			text_baseline_v_          ;
	bool                  			text_baseline_v_useable_ = false ;
	SkTextUtils::Align    			sk_text_align_ = SkTextUtils::kLeft_Align;
	SkMatrix              			current_matrix_ = SkMatrix::I();

public:
	void prepare_for_stroke();
	void prepare_for_fill  ();
	void prepare_for_text  ();
	void convert_color_with_alpha(SkColor, SkColor&);

public:
	bool is_have_shadow();
	
public:
	sk_sp<SkDrawLooper> get_shadow_looper();
};


}}}