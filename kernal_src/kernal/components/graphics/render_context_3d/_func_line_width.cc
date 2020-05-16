
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.lineWidth(width);
 * 
 * width
 *      A GLfloat specifying the width of rasterized lines. 
 *      Default value: 1.
 */
void render_context_3d::line_width(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto value = v.to_float();
    if (value == context_cache_.line_width_) return;
    context_cache_.line_width_ = value;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float value_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->line_width(value_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->value_ = value; task->context_ = raw_context_.get();
}