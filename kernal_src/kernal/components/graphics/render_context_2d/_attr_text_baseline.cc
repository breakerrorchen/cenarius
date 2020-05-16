
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::text_baseline(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    _parameter.set_return((js_value)context.text_baseline_);
}

void render_context_2d::set_text_baseline(js_parameter& _parameter) {
    const static char* text_baseline_top         = "top";
    const static char* text_baseline_hanging     = "hanging";
    const static char* text_baseline_middle      = "middle";
    const static char* text_baseline_alphabetic  = "alphabetic";
    const static char* text_baseline_ideographic = "ideographic";
    const static char* text_baseline_bottom      = "bottom";
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto v = _parameter[0]; if (!v.is_str()) return;
    auto str = v.to_string();
    render_text_baseline baseline;
    if (str == text_baseline_top) {
        baseline = render_text_baseline::top;
    } else if (str == text_baseline_hanging) {
        baseline = render_text_baseline::hanging;
    } else if (str == text_baseline_middle) {
        baseline = render_text_baseline::middle;
    } else if (str == text_baseline_alphabetic) {
        baseline = render_text_baseline::alphabetic;
    } else if (str == text_baseline_ideographic) {
        baseline = render_text_baseline::ideographic;
    } else if (str == text_baseline_bottom) {
        baseline = render_text_baseline::bottom;
    } else {
        return;
    }
    auto& context = related_->lt_context_stack_.top();
    context.text_baseline_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        render_text_baseline baseline_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            if (context.text_baseline_ != baseline_) {
                context.text_baseline_ = baseline_;
                context.text_baseline_v_useable_ = false;
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) { 
        task->baseline_ = baseline;
        task->related_ = related_.get();
    }
}