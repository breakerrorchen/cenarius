
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.depthRange(zNear, zFar);
 * 
 * zNear
 *      A GLclampf specifying the mapping of the near clipping 
 *      plane to window or viewport coordinates. Clamped to the 
 *      range 0 to 1 and must be less than or equal to zFar. 
 *      The default value is 0.
 * 
 * zFar
 *      A GLclampf specifying the mapping of the far clipping 
 *      plane to window or viewport coordinates. 
 *      Clamped to the range 0 to 1. The default value is 1.
 */
void render_context_3d::depth_range(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    float n = _parameter[0].to_float(); n = std::clamp(n, 0.f, 1.f);
    float f = _parameter[1].to_float(); f = std::clamp(f, 0.f, 1.f);
    context_cache_.depth_range_[0] = n;
    context_cache_.depth_range_[1] = f;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float n_ = 0, f_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->depth_range_f(n_, f_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->n_ = n;
    task->f_ = f;
    task->context_ = raw_context_.get();
}