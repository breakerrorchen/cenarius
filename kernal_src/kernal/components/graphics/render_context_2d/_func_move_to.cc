
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::move_to(js_parameter& parameter) {
    assert(transmitter_ && related_);
	if (parameter.get_argument_count() != 2) return;
    auto x = parameter[0].to_float();
    auto y = parameter[1].to_float();
    auto& martix = related_->get_lt_context().current_matrix_;
    SkPoint pt; martix.mapXY(x, y, &pt);
    related_->lt_current_path_.moveTo(pt.x(), pt.y());
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkPoint pt_;
        void run(barrel_buffer*) {
            assert(related_);
            related_->rt_current_path_.moveTo(pt_.x(), pt_.y());
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->pt_ = pt; task->related_ = related_.get();
    }
}