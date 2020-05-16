
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::shadow_offset_x(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, context.shadow_offset_x_));
}

void render_context_2d::set_shadow_offset_x(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto shadow_offset = _parameter[0].to_float();
    auto& context = related_->lt_context_stack_.top();
    context.shadow_offset_x_ = shadow_offset;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        float shadow_offset_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.shadow_offset_x_ = shadow_offset_;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->shadow_offset_ = shadow_offset;
        task->related_ = related_.get();
    }
}