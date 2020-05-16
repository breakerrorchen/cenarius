
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.stencilMask(mask);
 *
 * mask
 *      A GLuint specifying a bit mask to enable or disable writing of 
 *      individual bits in the stencil planes. 
 *      By default, the mask is all 1.
 */
void render_context_3d::stencil_mask(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    uint32_t mask = (uint32_t)_0.to_int32();
    if (context_cache_.stencil_write_mask_      == mask &&
        context_cache_.stencil_back_write_mask_ == mask) {
        return;
    }
    
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mask_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->stencil_mask(mask_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mask_ = mask; task->context_ = raw_context_.get();
}