
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.blendFunc(sfactor, dfactor);
 * sfactor
 *      A GLenum specifying a multiplier for the source blending factors. 
 *      The default value is gl.ONE. For possible values, see below.
 * 
 * dfactor
 *      A GLenum specifying a multiplier for the destination blending factors. 
 *      The default value is gl.ZERO. For possible values, see below.
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      If sfactor or dfactor is not one of the listed possible values, 
 *      a gl.INVALID_ENUM error is thrown.
 * 
 *      If a constant color and a constant alpha value are used together 
 *      as source and destination factors, a gl.INVALID_ENUM error is thrown.
 */
void render_context_3d::blend_func(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) return;
    uint32_t value[2] = {
        (uint32_t)_0.to_int32(), (uint32_t)_1.to_int32()
    };
    for (int i = 0; i < 2; ++i) {
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
    context_cache_.blend_func_src_alpha_ = value[0];
    context_cache_.blend_func_dst_rgb_   = value[1];
    context_cache_.blend_func_dst_alpha_ = value[1];

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t src_ = 0, dst_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->blend_func(src_, dst_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->src_ = value[0];
    task->dst_ = value[1];
    task->context_  = raw_context_.get();
}