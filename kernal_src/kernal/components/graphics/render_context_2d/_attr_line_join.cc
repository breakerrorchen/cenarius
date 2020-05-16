
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::line_join(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    _parameter.set_return((js_value)context.line_join_);
}

void render_context_2d::set_line_join(js_parameter& _parameter) {
    const static char* line_join_bevel = "bevel";
    const static char* line_join_round = "round";
    const static char* line_join_miter = "miter";
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto v = _parameter[0]; if (!v.is_str()) return;
    auto str = v.to_string();
    SkPaint::Join join = SkPaint::kBevel_Join;
    if (str == line_join_bevel) {
        join = SkPaint::kBevel_Join;
    } else if (str == line_join_round) {
        join = SkPaint::kRound_Join;
    } else if (str == line_join_miter) {
        join = SkPaint::kMiter_Join;
    } else {
        return;
    }
    auto& context = related_->lt_context_stack_.top();
    context.line_join_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkPaint::Join join_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.fill_paint_  .setStrokeJoin(join_);
            context.stroke_paint_.setStrokeJoin(join_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
	if (task) { 
        task->join_ = join; task->related_ = related_.get();
    }
}