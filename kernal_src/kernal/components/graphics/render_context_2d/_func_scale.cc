
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::scale(js_parameter& parameter) {
    assert(transmitter_ && related_);
    if (parameter.get_argument_count() != 2) return;
    auto x = parameter.get_argument_at(0).to_float();
    auto y = parameter.get_argument_at(1).to_float();
    if ((0 == x || 0 == y) || (1 == x && 1 == y)) {
        return;
    }
    related_->get_lt_context().current_matrix_.preScale(x, y);
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        float x_ = 0, y_ = 0;
        void run(barrel_buffer*) {
            assert(related_);
            auto& render_context = related_->get_rt_context();
            render_context.current_matrix_.preScale(x_, y_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->x_ = x; 
        task->y_ = y; 
        task->related_ = related_.get();
    }
}