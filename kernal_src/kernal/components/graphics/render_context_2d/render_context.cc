
#include "render_context.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace infrastructure;
using namespace renderer;

render_context_2d_context::render_context_2d_context(
	const render_context_2d_context& that) {
	operator=(that);
}

render_context_2d_context::render_context_2d_context(
	render_context_2d_context&& that) {
	operator=(std::move(that));
}

render_context_2d_context& render_context_2d_context::operator=(
	const render_context_2d_context& that) {
	if (&that != this) {
		fill_paint_ 			 = that.fill_paint_;
		stroke_paint_ 			 = that.stroke_paint_;
		stroke_style_ 		 	 = that.stroke_style_;
		fill_style_ 			 = that.fill_style_;
		global_alpha_ 			 = that.global_alpha_;
		typeface_size_ 			 = that.typeface_size_;
		typeface_ 				 = that.typeface_;
		line_dash_ 				 = that.line_dash_;
		dash_offset_ 			 = that.dash_offset_;
		dash_path_effect_ 		 = that.dash_path_effect_;
		shadow_color_ 			 = that.shadow_color_;
		shadow_blur_ 			 = that.shadow_blur_;
		shadow_offset_x_ 		 = that.shadow_offset_x_;
		shadow_offset_y_ 		 = that.shadow_offset_y_;
		shadow_looper_ 			 = that.shadow_looper_;
		shadow_masker_ 			 = that.shadow_masker_;
		text_baseline_ 			 = that.text_baseline_;
		text_baseline_v_ 		 = that.text_baseline_v_;
		text_baseline_v_useable_ = that.text_baseline_v_useable_;
		sk_text_align_ 			 = that.sk_text_align_;
		current_matrix_ 		 = that.current_matrix_;
	}
	return *this;	
}

render_context_2d_context& render_context_2d_context::operator=(
	render_context_2d_context&& that) {
	if (&that != this) {
		fill_paint_ 			 = std::move(that.fill_paint_);
		stroke_paint_ 			 = std::move(that.stroke_paint_);
		stroke_style_ 		 	 = that.stroke_style_;
		fill_style_ 			 = that.fill_style_;
		global_alpha_ 			 = that.global_alpha_;
		typeface_size_ 			 = that.typeface_size_;
		typeface_ 				 = std::move(that.typeface_);
		line_dash_ 				 = std::move(that.line_dash_);
		dash_offset_ 			 = that.dash_offset_;
		dash_path_effect_ 		 = std::move(that.dash_path_effect_);
		shadow_color_ 			 = that.shadow_color_;
		shadow_blur_ 			 = that.shadow_blur_;
		shadow_offset_x_ 		 = that.shadow_offset_x_;
		shadow_offset_y_ 		 = that.shadow_offset_y_;
		shadow_masker_			 = std::move(that.shadow_masker_);
		shadow_looper_ 			 = std::move(that.shadow_looper_);
		text_baseline_ 			 = that.text_baseline_;
		text_baseline_v_ 		 = that.text_baseline_v_;
		text_baseline_v_useable_ = that.text_baseline_v_useable_;
		sk_text_align_ 			 = that.sk_text_align_;
		current_matrix_ 		 = std::move(that.current_matrix_);
	}
	return *this;	
}

void render_context_2d_context::prepare_for_stroke() {
	// guodong test
	stroke_paint_.setColor(SK_ColorRED);
	switch(stroke_style_.class_) {
	case render_context_2d_shader::color: {
			stroke_paint_.setAlpha(global_alpha_);
			SkColor color = 0;
			convert_color_with_alpha(stroke_style_.color_, color);
			stroke_paint_.setColor(color);
			stroke_paint_.setShader(nullptr);
		}
		break;
	case render_context_2d_shader::gradient: {
			stroke_paint_.setAlpha(global_alpha_);
			stroke_paint_.setShader(stroke_style_.gradient_);
		}
		break;
	case render_context_2d_shader::pattern: {
			stroke_paint_.setAlpha(global_alpha_);
			stroke_paint_.setShader(stroke_style_.pattern_);
		}
		break;
	}

	if (dash_path_effect_) {
		stroke_paint_.setPathEffect(dash_path_effect_);
	} else if (!line_dash_.empty()) {
		dash_path_effect_ = SkDashPathEffect::Make(
			line_dash_.data(), line_dash_.size(), dash_offset_);
		stroke_paint_.setPathEffect(dash_path_effect_);
	} else {
		stroke_paint_.setPathEffect(nullptr);
	}

	if (shadow_color_ != 0) {
		if (!shadow_masker_) {
			shadow_masker_ = SkMaskFilter::MakeBlur(
				kNormal_SkBlurStyle, shadow_blur_/2, true);
		}
		stroke_paint_.setMaskFilter(shadow_masker_);
	} else {
		stroke_paint_.setMaskFilter(nullptr);
	}
}

void render_context_2d_context::prepare_for_fill() {
	// guodong test
	fill_paint_.setColor(SK_ColorRED);
	switch(fill_style_.class_) {
	case render_context_2d_shader::color: {
			fill_paint_.setAlpha(global_alpha_);
			SkColor color = 0;
			convert_color_with_alpha(fill_style_.color_, color);
			fill_paint_.setColor(color);
			fill_paint_.setShader(nullptr);
		}
		break;
	case render_context_2d_shader::gradient: {
			fill_paint_.setAlpha(global_alpha_);
			fill_paint_.setShader(fill_style_.gradient_);
		}
		break;
	case render_context_2d_shader::pattern: {
			fill_paint_.setAlpha(global_alpha_);
			fill_paint_.setShader(fill_style_.pattern_);
		}
		break;
	}

	if (dash_path_effect_) {
		fill_paint_.setPathEffect(dash_path_effect_);
	} else if (!line_dash_.empty()) {
		dash_path_effect_ = SkDashPathEffect::Make(
			line_dash_.data(), line_dash_.size(), dash_offset_);
		fill_paint_.setPathEffect(dash_path_effect_);
	} else {
		fill_paint_.setPathEffect(nullptr);
	}

	if (shadow_color_ != 0) {
		if (!shadow_masker_) {
			shadow_masker_ = SkMaskFilter::MakeBlur(
				kNormal_SkBlurStyle, shadow_blur_/2, true);
		}
		fill_paint_.setMaskFilter(shadow_masker_);
	} else {
		fill_paint_.setMaskFilter(nullptr);
	}
}

void render_context_2d_context::prepare_for_text() {
	if (!text_baseline_v_useable_) {
		text_baseline_v_useable_ = true;
		text_baseline_v_ = 0;
		SkFont font(typeface_, typeface_size_);
		SkFontMetrics fm; font.getMetrics(&fm);
		switch (text_baseline_) {
		case render_text_baseline::top:
			text_baseline_v_ = -fm.fAscent;
			break;
		case render_text_baseline::hanging:
			text_baseline_v_ = -fm.fAscent;
			break;
		case render_text_baseline::middle:
			text_baseline_v_ = -(fm.fAscent + fm.fDescent) / 2;
			break;
		case render_text_baseline::alphabetic:
			text_baseline_v_ = 0;
			break;
		case render_text_baseline::ideographic:
			text_baseline_v_ = 0;
			break;
		case render_text_baseline::bottom:
			text_baseline_v_ = -fm.fDescent;
			break;
		default:
			break;
		}
	}
}

void render_context_2d_context::convert_color_with_alpha(
	SkColor in, SkColor& out) {
	if (255 == global_alpha_) {
		out = in;
		return;
	}
	auto alpha = (uint8_t)(
		SkColorGetA(in) * global_alpha_ >> 8);
	out = SkColorSetA(in, alpha);
}

bool render_context_2d_context::is_have_shadow() {
	return 0 != shadow_blur_;
}

static const SkScalar kBLUR_SIGMA_SCALE = 0.57735f;
inline SkScalar __convert_radius_to_sigma(SkScalar radius) {
    return radius > 0 ? kBLUR_SIGMA_SCALE * radius + 0.5f : 0.0f;
}

sk_sp<SkDrawLooper> render_context_2d_context::get_shadow_looper() {
	if (shadow_looper_ || SkColorGetA(shadow_color_) == 0) {
		return shadow_looper_;
	}
	SkLayerDrawLooper::Builder builder;
    SkLayerDrawLooper::LayerInfo info;
    info.fColorMode = SkBlendMode::kSrc;
    info.fPaintBits |= SkLayerDrawLooper::kMaskFilter_Bit;
    info.fPaintBits |= SkLayerDrawLooper::kColorFilter_Bit;
    info.fOffset.set(shadow_offset_x_, shadow_offset_y_);
    auto paint = builder.addLayerOnTop(info);
	paint->setColor(shadow_color_);
    paint->setMaskFilter(SkMaskFilter::MakeBlur(
		kNormal_SkBlurStyle,
		__convert_radius_to_sigma(shadow_blur_)));
	SkLayerDrawLooper::LayerInfo info_0;
    builder.addLayerOnTop(info_0);
    shadow_looper_ = builder.detach();
	return shadow_looper_;
}