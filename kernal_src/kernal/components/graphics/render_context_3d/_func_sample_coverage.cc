
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.sampleCoverage(value, invert);
 *
 * value
 *      A GLclampf which sets a single floating-point coverage 
 *      value clamped to the range [0,1]. The default value is 1.0.
 *
 * invert
 *      A GLboolean which sets whether or not the coverage masks 
 *      should be inverted. 
 *      The default value is false. 
 */
void render_context_3d::sample_coverage(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto value = _parameter[0].to_float(); 
    value = std::clamp(value, 0.f, 1.f);
    auto invert= _parameter[1].to_bool();
    context_cache_.sample_coverage_value_  = value;
    context_cache_.sample_coverage_invert_ = invert;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float value_; bool invert_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->sample_coverage(value_, invert_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->value_   = value ;
    task->invert_  = invert;
    task->context_ = raw_context_.get();
}