
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.colorMask(red, green, blue, alpha);
 *
 * red
 *      A GLboolean specifying whether or not the red color 
 *      component can be written into the frame buffer. Default value: true.
 * 
 * green
 *      A GLboolean specifying whether or not the green color 
 *      component can be written into the frame buffer. Default value: true.
 * 
 * blue
 *      A GLboolean specifying whether or not the blue color component 
 *      can be written into the frame buffer. Default value: true.
 * 
 * alpha
 *      A GLboolean specifying whether or not the alpha (transparency) component 
 *      can be written into the frame buffer. Default value: true.
 * 
 * Return value
 *      None.
 */
void render_context_3d::color_mask(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    auto r = _parameter[0].to_bool();
    auto g = _parameter[1].to_bool();
    auto b = _parameter[2].to_bool();
    auto a = _parameter[3].to_bool();
    context_cache_.color_write_mask_[0] = r;
    context_cache_.color_write_mask_[1] = g;
    context_cache_.color_write_mask_[2] = b;
    context_cache_.color_write_mask_[3] = a;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        bool r_, g_, b_, a_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->color_mask(r_, g_, b_, a_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->r_ = r;
    task->g_ = g;
    task->b_ = b;
    task->a_ = a;
    task->context_ = raw_context_.get();
}