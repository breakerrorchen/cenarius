
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::global_alpha(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, context.global_alpha_));
}

void render_context_2d::set_global_alpha(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto alpha = _parameter[0].to_int32();
    if (alpha < 0  ) alpha = 0;
    if (alpha > 255) alpha = 255;
    auto& context = related_->lt_context_stack_.top();
    context.global_alpha_ = alpha;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        int alpha_ = 255;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.global_alpha_ = (U8CPU)alpha_;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) { 
        task->alpha_ = alpha; task->related_ = related_.get();
    }
}