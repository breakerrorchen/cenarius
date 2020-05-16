
#include "common/logger.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace interpreter;
using namespace asynchronous;
using namespace bestead;
using namespace isolate;
using namespace components;

components::canvas::~canvas() {
	if (!transmitter_) return;
	struct __task__ {
		puppet_container<renderer::canvas>* raw_canvas_;
		void run(barrel_buffer*) {
			assert(raw_canvas_);
			delete raw_canvas_;
		}
	};
	auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	task->raw_canvas_ = raw_canvas_.get();
}

components::canvas::canvas(__sptr<related_thread> _related)
	: alived_watcher_(this) {
	assert(_related);
	transmitter_ = std::make_shared<
		command_transmitter>(_related->buffer_center_);
	canvas_center_   = _related->render_connector_->canvas_center_;
	care_render_     = _related->render_connector_->render_;
	render_attitude_ = _related->render_attitude_;
	assert(canvas_center_ && care_render_ && render_attitude_);

	w_ = _related->care_info_->window_w_;
	h_ = _related->care_info_->window_h_;
	struct __task__ {
		__sptr<canvas_center> center_;
		puppet_container<renderer::canvas>* raw_canvas_;
		void run(barrel_buffer*) {
			assert(raw_canvas_ && center_);
			raw_canvas_->data_ = center_->related_window();
		}
	};
	auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	task->center_ = canvas_center_;
	task->raw_canvas_ = raw_canvas_.get();

	// 监听全局的vsync信号
	vsync_listener_ = event_observer::listen(
		(uint32_t)event_observer_id::_vsync_, 
		[this](uint32_t, std::shared_ptr<runtime_base>) {
		this->on_vsync();
	});
}

components::canvas::canvas(
	__sptr<related_thread> _related, int w, int h)
	: alived_watcher_(this) {
	assert(_related && _related->buffer_center_);
	assert(_related->render_connector_);
	transmitter_ = std::make_shared<
		command_transmitter>(_related->buffer_center_);
	canvas_center_ = _related->render_connector_->canvas_center_;
	care_render_   = _related->render_connector_->render_;
	assert(canvas_center_ && care_render_);

	w_ = w; h_ = h;

	struct __task__ {
		__sptr<canvas_center> center_;
		uint32_t w_, h_;
		puppet_container<renderer::canvas>* raw_canvas_;
		void run(barrel_buffer*) {
			assert(raw_canvas_ && center_);
			raw_canvas_->data_ = center_->create(w_, h_);
		}
	};
	auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	task->center_ = canvas_center_;
	task->w_ = (uint32_t)w;
	task->h_ = (uint32_t)h;
	task->raw_canvas_ = raw_canvas_.get();
}

void components::canvas::get_size(int* w, int* h) {
	if (w) { *w = w_; }
	if (h) { *h = h_; }
}