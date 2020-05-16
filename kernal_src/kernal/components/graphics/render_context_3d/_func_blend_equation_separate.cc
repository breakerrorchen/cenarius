
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.blendEquationSeparate(modeRGB, modeAlpha);
 *
 * modeRGB
 *      A GLenum specifying how the red, green and blue components of 
 *      source and destination colors are combined. Must be either:
 *          gl.FUNC_ADD:                source + destination (default value),
 *          gl.FUNC_SUBTRACT:           source - destination,
 *          gl.FUNC_REVERSE_SUBTRACT:   destination - source,
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
 * modeAlpha
 *      A GLenum specifying how the alpha component (transparency) 
 *      of source and destination colors are combined. Must be either:
 *          gl.FUNC_ADD:                source + destination (default value),
 *          gl.FUNC_SUBTRACT:           source - destination,
 *          gl.FUNC_REVERSE_SUBTRACT:   destination - source,
 * 
 *      When using the EXT_blend_minmax extension:
 *          ext.MIN_EXT:                Minimum of source and destination,
 *          ext.MAX_EXT:                Maximum of source and destination.
 * 
 *      When using a WebGL 2 context, 
 *      the following values are available additionally:
 *          gl.MIN:                     Minimum of source and destination,
 *          gl.MAX:                     Maximum of source and destination
 *          
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      If mode is not one of the three possible values, 
 *      a gl.INVALID_ENUM error is thrown.
 */
void render_context_3d::blend_equation_separate(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) return;
    auto rgb = _0.to_int32();
    if (DWL_FUNC_ADD != rgb && DWL_FUNC_SUBTRACT != rgb
            && DWL_FUNC_REVERSE_SUBTRACT != rgb) {
        return;
    }
    auto alpha = _1.to_int32();
    if (DWL_FUNC_ADD != alpha && DWL_FUNC_SUBTRACT != alpha
            && DWL_FUNC_REVERSE_SUBTRACT != alpha) {
        return;
    }
    context_cache_.blend_equation_rgb_mode_   = rgb;
    context_cache_.blend_equation_alpha_mode_ = alpha;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t rgb_, alpha_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->blend_equation_separate(rgb_, alpha_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->alpha_   = (uint32_t)alpha;
    task->rgb_     = (uint32_t)rgb;
    task->context_ = raw_context_.get();
}