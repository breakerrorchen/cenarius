
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::text_align(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    _parameter.set_return((js_value)context.text_align_);
}

void render_context_2d::set_text_align(js_parameter& _parameter) {
    const static char* text_align_left   = "left";
    const static char* text_align_right  = "right";
    const static char* text_align_center = "center";
    const static char* text_align_start  = "start";
    const static char* text_align_end    = "end";
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto v = _parameter[0]; if (!v.is_str()) return;
    auto str = v.to_string();
    SkTextUtils::Align text_align = SkTextUtils::kLeft_Align;
    if (str == text_align_left) {
        text_align = SkTextUtils::kLeft_Align;
    } else if (str == text_align_right) {
        text_align = SkTextUtils::kRight_Align;
    } else if (str == text_align_center) {
        text_align = SkTextUtils::kCenter_Align;
    } else if (str == text_align_start) {
        text_align = SkTextUtils::kLeft_Align;
    } else if (str == text_align_end) {
        text_align = SkTextUtils::kRight_Align;
    } else {
        return;
    }
    auto& context = related_->lt_context_stack_.top();
    context.text_align_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkTextUtils::Align text_align_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.sk_text_align_ = text_align_;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
	if (task) { 
        task->text_align_ = text_align;
        task->related_ = related_.get();
    }
}