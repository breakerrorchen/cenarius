
#include "_.h"
#include "infrastructure/css_pattern/include/css_parser_color.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace css_pattern;
using namespace renderer;
using namespace components;

void render_context_2d::shadow_color(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto& context = related_->lt_context_stack_.top();
    _parameter.set_return((js_value)context.shadow_color_);
}

void render_context_2d::set_shadow_color(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    if (_parameter.get_argument_count() <= 0) return;
    auto v = _parameter[0]; if (!v.is_str()) return;
    auto str = v.to_string();
    uint32_t rgba = 0;
    if (!css_parser_color::parse(str, rgba)) {
        return;
    }
    auto& context = related_->lt_context_stack_.top();
    context.shadow_color_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        uint32_t color_;
        void run(barrel_buffer*) {
            uint8_t r = 0, g = 0, b = 0, a = 0;
            r = (uint8_t)((color_ & 0xff000000) >> 24);
            g = (uint8_t)((color_ & 0x00ff0000) >> 16);
            b = (uint8_t)((color_ & 0x0000ff00) >> 8);
            a = (uint8_t)((color_ & 0x000000ff));
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.shadow_color_ = SkColorSetARGB(a, r, g, b);
            context.shadow_masker_ = nullptr;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->color_ = rgba; task->related_ = related_.get();
    }
}