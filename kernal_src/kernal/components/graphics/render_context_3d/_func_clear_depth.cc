
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.clearDepth(depth);
 * depth
 *      A GLclampf specifying the depth value used when 
 *      the depth buffer is cleared. Default value: 1.
 * 
 * Return value
 *      None.
 */
void render_context_3d::clear_depth(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto value = v.to_float();
    context_cache_.clear_depth_value_ = value;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float value_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->clear_depth_f(value_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->value_ = value; task->context_ = raw_context_.get();
}