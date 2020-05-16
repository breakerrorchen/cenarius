
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::global_composite(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    _parameter.set_return((js_value)context.composite_oper_);
}

void render_context_2d::set_global_composite(js_parameter& _parameter) {
    const static char* blend_mode_source_over      = "source-over";
    const static char* blend_mode_source_atop      = "source-atop";
    const static char* blend_mode_source_in        = "source-in";
    const static char* blend_mode_source_out       = "source-out";
    const static char* blend_mode_destination_over = "destination-over";
    const static char* blend_mode_destination_atop = "destination-atop";
    const static char* blend_mode_destination_in   = "destination-in";
    const static char* blend_mode_destination_out  = "destination-out";
    const static char* blend_mode_lighter          = "lighter";
    const static char* blend_mode_copy             = "copy";
    const static char* blend_mode_xor              = "xor";
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto v = _parameter[0]; if (!v.is_str()) return;
    auto str = v.to_string();
    auto blend_mode = SkBlendMode::kClear;
    if (str == blend_mode_source_over) {
        blend_mode = SkBlendMode::kSrcOver;
    } else if (str == blend_mode_source_atop) {
        blend_mode = SkBlendMode::kSrcATop;
    } else if (str == blend_mode_source_in) {
        blend_mode = SkBlendMode::kSrcIn;
    } else if (str == blend_mode_source_out) {
        blend_mode = SkBlendMode::kSrcOut;
    } else if (str == blend_mode_destination_over) {
        blend_mode = SkBlendMode::kDstOver;
    } else if (str == blend_mode_destination_atop) {
        blend_mode = SkBlendMode::kDstATop;
    } else if (str == blend_mode_destination_in) {
        blend_mode = SkBlendMode::kDstIn;
    } else if (str == blend_mode_destination_out) {
        blend_mode = SkBlendMode::kDstOut;
    } else if (str == blend_mode_lighter) {
        blend_mode = SkBlendMode::kPlus;
    } else if (str == blend_mode_copy) {
        blend_mode = SkBlendMode::kSrc;
    } else if (str == blend_mode_xor) {
        blend_mode = SkBlendMode::kXor;
    } else {
        return;
    }
    auto& context = related_->lt_context_stack_.top();
    context.composite_oper_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkBlendMode mode_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.fill_paint_  .setBlendMode(mode_);
            context.stroke_paint_.setBlendMode(mode_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
	if (task) { 
        task->mode_ = blend_mode; task->related_ = related_.get();
    }
}