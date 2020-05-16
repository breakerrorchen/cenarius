
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.clear(mask);
 *
 * mask
 *      A GLbitfield bitwise OR mask that indicates 
 *      the buffers to be cleared. Possible values are:
 *          gl.COLOR_BUFFER_BIT
 *          gl.DEPTH_BUFFER_BIT
 *          gl.STENCIL_BUFFER_BIT
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      If mask is not one of the listed possible values, 
 *      a gl.INVALID_ENUM error is thrown.
 */
void render_context_3d::clear(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto mask = v.to_int32();
    if (mask != DWL_COLOR_BUFFER_BIT &&
        mask != DWL_DEPTH_BUFFER_BIT &&
        mask != DWL_STENCIL_BUFFER_BIT) {
        return;
    }
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mask_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->clear(mask_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mask_ = mask; task->context_ = raw_context_.get();
}