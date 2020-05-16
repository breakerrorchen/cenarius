
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.depthMask(flag);
 * 
 * flag
 *      A GLboolean specifying whether or not writing into 
 *      the depth buffer is enabled. Default value: true, 
 *      meaning that writing is enabled.
 */
void render_context_3d::depth_mask(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    context_cache_.depth_mask_ = v.to_bool();
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        bool flag_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->depth_mask(flag_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->context_ = raw_context_.get();
    task->flag_ = context_cache_.depth_mask_;
}