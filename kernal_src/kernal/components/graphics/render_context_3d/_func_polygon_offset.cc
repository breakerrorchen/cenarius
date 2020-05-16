
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.polygonOffset(factor, units);
 * 
 * factor
 *      A GLfloat which sets the scale factor for the 
 *      variable depth offset for each polygon. The default value is 0. 
 *
 * units
 *      A GLfloat which sets the multiplier by which an implementation-specific 
 *      value is multiplied with to create a constant depth offset. 
 *      The default value is 0.
 */
void render_context_3d::polygon_offset(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) return;
    auto factor = _0.to_float();
    auto units  = _1.to_float();
    if (context_cache_.polygon_offset_factor_ == factor &&
        context_cache_.polygon_offset_units_  == units) {
        return;
    }
    context_cache_.polygon_offset_factor_ = factor;
    context_cache_.polygon_offset_units_  = units;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float factor_ = 0, units_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->polygon_offset(factor_, units_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->factor_  = factor;
    task->units_   = units;
    task->context_ = raw_context_.get();
}