
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.frontFace(mode);
 *
 * mode
 *      A GLenum type winding orientation. The default value is gl.CCW. 
 *      Possible values:
 *          gl.CW: Clock-wise winding.
 *          gl.CCW: Counter-clock-wise winding.
 * 
 * Return value
 *      None.
 */
void render_context_3d::front_face(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto mode = (uint32_t)v.to_int32();
    if (DWL_CW != mode && DWL_CCW != mode) {
        return;
    }
    context_cache_.front_face_ = mode;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mode_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->front_face(mode_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mode_ = mode; task->context_ = raw_context_.get();
}