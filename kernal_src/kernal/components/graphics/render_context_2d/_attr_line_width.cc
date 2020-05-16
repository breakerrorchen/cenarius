
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::line_width(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, context.line_width_));
}

void render_context_2d::set_line_width(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto line_width = _parameter[0].to_float();
    auto& context = related_->lt_context_stack_.top();
    context.line_width_ = line_width;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        float line_width_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.fill_paint_  .setStrokeWidth(line_width_);
            context.stroke_paint_.setStrokeWidth(line_width_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->line_width_ = line_width;
        task->related_ = related_.get();
    }
}