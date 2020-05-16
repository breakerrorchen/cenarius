
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::anti_alias(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(js_context, context.aa_));
}

void render_context_2d::set_anti_alias(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto aa = _parameter[0].to_bool();
    auto& context = related_->lt_context_stack_.top();
    context.aa_ = aa;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        bool aa_ = false;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.fill_paint_  .setAntiAlias(aa_);
            context.stroke_paint_.setAntiAlias(aa_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
	if (task) { 
        task->aa_ = aa; task->related_ = related_.get();
    }
}