
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::line_cap(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    _parameter.set_return((js_value)context.line_cap_);
}

void render_context_2d::set_line_cap(js_parameter& _parameter) {
    const static char* line_cap_butt   = "butt"  ;
    const static char* line_cap_round  = "round" ;
    const static char* line_cap_square = "square";
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto v = _parameter[0]; if (!v.is_str()) return;
    auto str = v.to_string();
    SkPaint::Cap cap = SkPaint::kButt_Cap;
    if (str == line_cap_butt) {
        cap = SkPaint::kButt_Cap;
    } else if (str == line_cap_round) {
        cap = SkPaint::kRound_Cap;
    } else if (str == line_cap_square) {
        cap = SkPaint::kSquare_Cap;
    } else {
        return;
    }
    auto& context = related_->lt_context_stack_.top();
    context.line_cap_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkPaint::Cap cap_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.fill_paint_  .setStrokeCap(cap_);
            context.stroke_paint_.setStrokeCap(cap_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
	if (task) { 
        task->cap_ = cap; task->related_ = related_.get();
    }
}