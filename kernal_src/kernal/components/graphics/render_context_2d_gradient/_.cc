
#include "infrastructure/css_pattern/include/css_parser_color.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace interpreter;
using namespace infrastructure;
using namespace renderer;
using namespace css_pattern;
using namespace components;

bool render_context_2d_gradient::build_linear(
    float _0, float _1, float _2, float _3) {
    init_arguments_[0] = _0;
    init_arguments_[1] = _1;
    init_arguments_[2] = _2;
    init_arguments_[3] = _3;
    shader_ = nullptr; class_ = __linear__;
    return true;
}

bool render_context_2d_gradient::build_radial(
    float _0, float _1, float _2, float _3, float _4, float _5) {
    init_arguments_[0] = _0;
    init_arguments_[1] = _1;
    init_arguments_[2] = _2;
    init_arguments_[3] = _3;
    init_arguments_[4] = _4;
    init_arguments_[5] = _5;
    shader_ = nullptr; class_ = __radial__;
    return true;
}

bool render_context_2d_gradient::add_color_stop(
    uint32_t color, float offset) {
    stop_colors_.emplace_back(color);
    stop_colors_offsets_.emplace_back(offset);
    shader_ = nullptr;
    return true;
}

void render_context_2d_gradient::add_color_stop(
    js_parameter& parameter) {
    if (parameter.get_argument_count() != 2) return;
    auto offset = parameter[0].to_float();
    uint32_t color = 0;
    auto clr_str = parameter[1].to_string();
    if (!css_parser_color::parse(clr_str, color)) {
        return;
    }
    add_color_stop(color, offset);
}

sk_sp<SkShader> render_context_2d_gradient::get_shader() {
    if (nullptr != shader_) return shader_;
    SkPoint pt[2];
    pt[0] = SkPoint::Make(init_arguments_[0], init_arguments_[1]);
    pt[1] = SkPoint::Make(init_arguments_[2], init_arguments_[3]);
    if (class_ == __linear__) {    
        if (stop_colors_.size() > 0 && stop_colors_offsets_.size() > 0) {
            int count = stop_colors_offsets_.size();
            shader_ = SkGradientShader::MakeLinear(
                pt, &(stop_colors_[0]), &(stop_colors_offsets_[0]),
                count, SkTileMode::kClamp);
        } else {
            shader_ = SkGradientShader::MakeLinear(
                pt, nullptr, nullptr, 0, SkTileMode::kClamp);
        }
    } else if (class_ == __radial__) {
        float start = init_arguments_[2], end = init_arguments_[5];
        if (stop_colors_.size() > 0 && stop_colors_offsets_.size() > 0) {
            int count = stop_colors_offsets_.size();
            shader_ = SkGradientShader::MakeTwoPointConical(
                pt[0], start, pt[1], end, &stop_colors_[0],
                &stop_colors_offsets_[0], count, SkTileMode::kClamp);
        } else {
            shader_ = SkGradientShader::MakeTwoPointConical(
                pt[0], start, pt[1], 
                end, nullptr, nullptr, 0, SkTileMode::kClamp);
        }
    }
    return shader_;
}