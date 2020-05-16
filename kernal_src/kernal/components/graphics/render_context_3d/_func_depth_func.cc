
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.depthFunc(func);
 * 
 * func
 *      A GLenum specifying the depth comparison function, 
 *      which sets the conditions under which the pixel will be drawn. 
 *      The default value is gl.LESS. Possible values are:
 *          gl.NEVER    (never pass)
 *          gl.LESS     (pass if the incoming value is less than the depth buffer value)
 *          gl.EQUAL    (pass if the incoming value equals the the depth buffer value)
 *          gl.LEQUAL   (pass if the 
 *              incoming value is less than or equal to the depth buffer value)
 *          gl.GREATER  (pass if the incoming value is greater than the depth buffer value)
 *          gl.NOTEQUAL (pass if the incoming value is not equal to the depth buffer value)
 *          gl.GEQUAL   (pass if the 
 *              incoming value is greater than or equal to the depth buffer value)
 *          gl.ALWAYS   (always pass)
 */
void render_context_3d::depth_func(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto func = (uint32_t)v.to_int32();
    if (DWL_NEVER       != func &&
        DWL_LESS        != func &&
        DWL_EQUAL       != func &&
        DWL_LEQUAL      != func &&  
        DWL_GREATER     != func &&
        DWL_NOTEQUAL    != func &&
        DWL_GEQUAL      != func &&
        DWL_ALWAYS      != func) {
        return;
    }
    context_cache_.depth_func_ = func;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t func_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->depth_func(func_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->func_ = func; task->context_ = raw_context_.get();
}