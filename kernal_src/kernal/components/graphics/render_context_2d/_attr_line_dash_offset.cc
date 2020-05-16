
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::line_dash_offset(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, context.line_dash_offset_));
}

void render_context_2d::set_line_dash_offset(js_parameter& _parameter) {
    assert(transmitter_ && related_);
	if (_parameter.get_argument_count() == 0) return;
    auto offset = _parameter[0].to_float();
    auto& context = related_->lt_context_stack_.top();
    context.line_dash_offset_ = offset;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        float offset_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            if (context.dash_offset_ != offset_) {
                context.dash_offset_ = offset_;
                context.dash_path_effect_ = nullptr;
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->offset_  = offset;
        task->related_ = related_.get();
    }
}