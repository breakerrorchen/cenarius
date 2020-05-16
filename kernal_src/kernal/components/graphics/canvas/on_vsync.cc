
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void components::canvas::on_vsync() {

    // 上屏操作
    assert(care_render_ && transmitter_ && canvas_center_);
    struct __task__ {
    	__sptr<canvas_center> canvas_center_;
    	__sptr<care_render> care_render_;
    	void run(barrel_buffer*) {
    		assert(care_render_ && canvas_center_);
    		care_render_->pre_commit_drawable();
    		canvas_center_->commit_drawable();
    		care_render_->commit_drawable();
    		care_render_->after_commit_drawable();
    	}
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->care_render_   = care_render_;
    task->canvas_center_ = canvas_center_;

    // 同步等待vsync动作操作完成
    transmitter_->force_commit(true, false);
}