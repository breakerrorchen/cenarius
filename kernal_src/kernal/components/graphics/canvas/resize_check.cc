
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void components::canvas::resize_check() {
	if (!need_resize_) return;
	need_resize_ = false;
	assert(transmitter_);
	struct __task__ {
		puppet_container<renderer::canvas>* raw_canvas_;
		uint32_t w_ = 0, h_ = 0;
		void run(barrel_buffer*) {
			assert(raw_canvas_ && raw_canvas_->data_);
			raw_canvas_->data_->resize(w_, h_);
		}
	};
	auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	task->raw_canvas_ = raw_canvas_.get();
	task->w_ = (uint32_t)w_; task->h_ = (uint32_t)h_;
}