
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.flush();
 */
void render_context_3d::flush(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->finish();
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->context_ = raw_context_.get();

    // 异步推送
    transmitter_->force_commit(false, false);
}