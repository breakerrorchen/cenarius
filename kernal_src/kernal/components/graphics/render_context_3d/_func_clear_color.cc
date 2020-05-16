
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.clearColor(red, green, blue, alpha);
 *
 * red
 *      A GLclampf specifying the red color value used when 
 *      the color buffers are cleared. Default value: 0.
 * 
 * green
 *      A GLclampf specifying the green color value used when 
 *      the color buffers are cleared. Default value: 0.
 * 
 * blue
 *      A GLclampf specifying the blue color value used when 
 *      the color buffers are cleared. Default value: 0.
 * 
 * alpha
 *      A GLclampf specifying the alpha (transparency) value 
 *      used when the color buffers are cleared. Default value: 0.
 * 
 * Return value
 *      None.
 */
void render_context_3d::clear_color(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    float r = _parameter[0].to_float(); r = std::clamp(r, 0.f, 1.f);
    float g = _parameter[1].to_float(); g = std::clamp(g, 0.f, 1.f);
    float b = _parameter[2].to_float(); b = std::clamp(b, 0.f, 1.f);
    float a = _parameter[3].to_float(); a = std::clamp(a, 0.f, 1.f);
    context_cache_.clear_color_[0] = r;
    context_cache_.clear_color_[1] = g;
    context_cache_.clear_color_[2] = b;
    context_cache_.clear_color_[3] = a;
    
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        float r_ = 0, g_ = 0, b_ = 0, a_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->clear_color(r_, g_, b_, a_);
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