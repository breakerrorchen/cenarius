
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.clearStencil(s);
 * s
 *      A GLint specifying the index used when 
 *      the stencil buffer is cleared. Default value: 0.
 * 
 * Return value
 *      None.
 */
void render_context_3d::clear_stencil(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto value = v.to_float();
    context_cache_.clear_stencil_value_ = value;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float value_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->clear_stencil((int32_t)value_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->value_ = value; task->context_ = raw_context_.get();
}