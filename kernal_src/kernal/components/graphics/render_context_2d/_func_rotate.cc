
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::rotate(js_parameter& parameter) {
	assert(transmitter_ && related_);
    if (parameter.get_argument_count() != 1) return;
    auto r = parameter.get_argument_at(0).to_float();
    if (::fabs(r) < 0.00001) {
        return;
    }
    r = SkRadiansToDegrees(r);
    related_->get_lt_context().current_matrix_.preRotate(r);
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        float r_ = 0;
        void run(barrel_buffer*) {
            assert(related_);
            auto& render_context = related_->get_rt_context();
            render_context.current_matrix_.preRotate(r_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->r_ = r; task->related_ = related_.get();
    }
}