
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.blendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
 *
 * srcRGB
 *      A GLenum specifying a multiplier for the red, green and blue 
 *      (RGB) source blending factors. The default value is gl.ONE. 
 *      For possible values, see below. 
 * 
 * dstRGB
 *      A GLenum specifying a multiplier for the red, green and blue
 *      (RGB) destination blending factors. 
 *      The default value is gl.ZERO. For possible values, see below.
 * 
 * srcAlpha
 *      A GLenum specifying a multiplier for the alpha source 
 *      blending factor. 
 *      The default value is gl.ONE. For possible values, see below.
 * 
 * dstAlpha
 *      A GLenum specifying a multiplier for the alpha destination 
 *      blending factor. The default value is gl.ZERO. 
 *      For possible values, see below.
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      If srcRGB, dstRGB, srcAlpha, or dstAlpha is not one of the listed 
 *      possible values, a gl.INVALID_ENUM error is thrown.
 * 
 *      If a constant color and a constant alpha value are used together 
 *      as source (srcRGB) and destination (dstRGB) factors, 
 *      a gl.INVALID_ENUM error is thrown.
 */
void render_context_3d::blend_func_separate(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    auto _2 = _parameter.get_argument_at(2);
    auto _3 = _parameter.get_argument_at(3);
    if (!_0.is_number() || !_1.is_number()) return;
    if (!_2.is_number() || !_3.is_number()) return;
    uint32_t value[4] = {
        (uint32_t)_0.to_int32(), (uint32_t)_1.to_int32(),
        (uint32_t)_2.to_int32(), (uint32_t)_3.to_int32()
    };
    for (int i = 0; i < 4; ++i) {
        auto& _v = value[i];
        if (DWL_ZERO                     != _v &&
            DWL_ONE                      != _v &&
            DWL_SRC_COLOR                != _v &&
            DWL_ONE_MINUS_SRC_COLOR      != _v &&
            DWL_DST_COLOR                != _v &&
            DWL_ONE_MINUS_DST_COLOR      != _v &&
            DWL_SRC_ALPHA                != _v &&
            DWL_ONE_MINUS_SRC_ALPHA      != _v &&
            DWL_DST_ALPHA                != _v &&
            DWL_ONE_MINUS_DST_ALPHA      != _v &&
            DWL_CONSTANT_COLOR           != _v &&
            DWL_ONE_MINUS_CONSTANT_COLOR != _v &&
            DWL_CONSTANT_ALPHA           != _v &&
            DWL_ONE_MINUS_CONSTANT_ALPHA != _v &&
            DWL_SRC_ALPHA_SATURATE       != _v) {
            return;
        }
    }
    context_cache_.blend_func_src_rgb_   = value[0];
    context_cache_.blend_func_src_alpha_ = value[1];
    context_cache_.blend_func_dst_rgb_   = value[2];
    context_cache_.blend_func_dst_alpha_ = value[3];
    
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t value_[4] = {0, 0, 0, 0};
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->blend_func_separate(
                value_[0], value_[1], value_[2], value_[3]);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->value_[0] = value[0];
    task->value_[1] = value[1];
    task->value_[2] = value[2];
    task->value_[3] = value[3];
    task->context_  = raw_context_.get();
}