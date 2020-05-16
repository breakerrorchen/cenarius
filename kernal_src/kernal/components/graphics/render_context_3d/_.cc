
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace infrastructure;
using namespace interpreter;
using namespace service;
using namespace renderer;
using namespace asynchronous;
using namespace bestead;
using namespace isolate;

render_context_3d::render_context_3d(__sptr<command_transmitter> 
	_transmitter, puppet<renderer::canvas>& _canvas,
    std::shared_ptr<render_attitude> _attitude,
	std::shared_ptr<alived_token<canvas>> related_canvas)
	: transmitter_(_transmitter)
    , related_canvas_(related_canvas)
    , render_attitude_(_attitude)
    , alived_watcher_(this) {
	assert(_transmitter && related_canvas && _attitude);
    struct __task__ {
		puppet_container<canvas_render_3d>* raw_context_;
        puppet_container<renderer::canvas>* raw_canvas_;
        void run(barrel_buffer*) {
			assert(raw_context_ && raw_canvas_);
            raw_context_->data_ 
                = raw_canvas_->data_->render_3d();
        }
    };
    auto task = _transmitter->alloc<__task__>();
    assert(nullptr != task);
	if (task) {
        task->raw_canvas_  = _canvas.get();
        task->raw_context_ = raw_context_.get();
    }
    _transmitter->force_commit(false, true);

    // init
    assert(related_canvas->is_useable());
    int canvas_w = 0, canvas_h = 0;
    related_canvas->get()->get_size(&canvas_w, &canvas_h);
    context_cache_.scissor_ [2] = canvas_w;
    context_cache_.scissor_ [3] = canvas_h;
    context_cache_.viewport_[2] = canvas_w;
    context_cache_.viewport_[3] = canvas_h;
}

render_context_3d::~render_context_3d() {
    assert(transmitter_);
    struct __task__ {
		puppet_container<canvas_render_3d>* raw_context_;
		void run(barrel_buffer*) {
			if (raw_context_) {
			    delete raw_context_;
            }
		}
	};
    auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	if (task) {
		task->raw_context_ = raw_context_.get();
	}
}