
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/renderer/include/canvas_center.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
class render_context_2d_context_local {
public:
    render_context_2d_context_local() = default;
    render_context_2d_context_local(
        const render_context_2d_context_local&);
    render_context_2d_context_local& operator=(
        const render_context_2d_context_local&);
public:
    SkMatrix            current_matrix_ = SkMatrix::I();
    js_value_holder     composite_oper_;
    js_value_holder     line_cap_;
    js_value_holder     line_join_;
    js_value_holder     shadow_color_;
    js_value_holder     text_align_;
    js_value_holder     text_baseline_;
    js_value_holder     line_dash_;
    bool                aa_             = false;
    SkScalar            typeface_size_  = 0;
    int                 global_alpha_   = 255;
    float               line_width_     = 1;
    float               miter_limit_    = 3.402823466e+38f;
    float               shadow_blur_    = 0;
    float               shadow_offset_x_    ;
    float               shadow_offset_y_    ;
    float               line_dash_offset_   ;
    sk_sp<SkTypeface>   typeface_       = nullptr;
};

}}}