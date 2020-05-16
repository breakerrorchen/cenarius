
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::miter_limit(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, context.miter_limit_));
}

void render_context_2d::set_miter_limit(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto miter_limit = _parameter[0].to_float();
    auto& context = related_->lt_context_stack_.top();
    context.miter_limit_ = miter_limit;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        float miter_limit_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top() ;
            context.fill_paint_  .setStrokeMiter(miter_limit_);
            context.stroke_paint_.setStrokeMiter(miter_limit_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->miter_limit_ = miter_limit;
        task->related_ = related_.get();
    }
}