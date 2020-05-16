
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::close_path(js_parameter& parameter) {
    assert(transmitter_ && related_);
    if (!related_->lt_current_path_.isEmpty()) {
        related_->lt_current_path_.close();
    }
    struct __task__ {
		render_context_thread_related* related_ = nullptr;
        void run(barrel_buffer*) {
            assert(related_);
			auto& path = related_->rt_current_path_;
            if (!path.isEmpty()) {
                path.close();
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) { 
        task->related_ = related_.get(); 
    }
}