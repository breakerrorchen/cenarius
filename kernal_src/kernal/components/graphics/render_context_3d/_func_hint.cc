
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.hint(target, mode);
 *
 * target
 *      Sets which behavior to be controlled. 
 *      Possible values:
 *          gl.GENERATE_MIPMAP_HINT: Quality of filtering 
 *              when generating mipmap images with 
 *              WebGLRenderingContext.generateMipmap().
 *      When using the OES_standard_derivatives extension:
 *          ext.FRAGMENT_SHADER_DERIVATIVE_HINT_OES: 
 *              Accuracy of the derivative calculation for 
 *              the GLSL built-in functions: dFdx, dFdy, and fwidth.
 *      When using a WebGL 2 context, 
 *      the following values are available additionally:
 *          gl.FRAGMENT_SHADER_DERIVATIVE_HINT: 
 *              Same as ext.FRAGMENT_SHADER_DERIVATIVE_HINT_OES
 * mode
 *      Sets the behavior. The default value is gl.DONT_CARE. 
 *      The possible values are:
 *          gl.FASTEST: The most efficient behavior should be used.
 *          gl.NICEST: The most correct 
 *              or the highest quality option should be used.
 *          gl.DONT_CARE: There is no preference for this behavior.
 *
 * Return value
 *      None.
 */
void render_context_3d::hint(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_GENERATE_MIPMAP_HINT != target) {
        return;
    }
    auto mode = (uint32_t)_1.to_int32();
    if (DWL_FASTEST != mode && DWL_NICEST != mode) {
        return;
    }
    context_cache_.generate_mipmap_hint_ = mode;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t target_ = 0, mode_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->hint(target_, mode_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->target_  = target;
    task->mode_    = mode;
    task->context_ = raw_context_.get();
}