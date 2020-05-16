
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.blendEquation(mode);
 *
 * mode
 *      A GLenum specifying how source and destination colors are combined. Must be either:
 *          gl.FUNC_ADD:                source + destination,
 *          gl.FUNC_SUBTRACT:           source - destination,
 *          gl.FUNC_REVERSE_SUBTRACT:   destination - source
 * 
 *      When using the EXT_blend_minmax extension:
 *          ext.MIN_EXT:                Minimum of source and destination,
 *          ext.MAX_EXT:                Maximum of source and destination.
 *      
 *      When using a WebGL 2 context, 
 *      the following values are available additionally:
 *          gl.MIN:                     Minimum of source and destination,
 *          gl.MAX:                     Maximum of source and destination.     
 * 
 * default value
 *      gl.FUNC_ADD
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      If mode is not one of the three possible values, 
 *      a gl.INVALID_ENUM error is thrown.
 */
void render_context_3d::blend_equation(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto mode = v.to_int32();
    if (DWL_FUNC_ADD != mode && DWL_FUNC_SUBTRACT != mode
            && DWL_FUNC_REVERSE_SUBTRACT != mode) {
        return;
    }
    context_cache_.blend_equation_rgb_mode_   = mode;
    context_cache_.blend_equation_alpha_mode_ = mode;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mode_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->blend_equation(mode_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mode_ = (uint32_t)mode;
    task->context_ = raw_context_.get();
}