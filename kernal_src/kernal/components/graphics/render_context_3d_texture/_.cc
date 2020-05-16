
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace interpreter;

render_context_3d_texture::render_context_3d_texture() {
    related_value_ = new uint32_t();
}

render_context_3d_texture::~render_context_3d_texture() {
    render_context_3d_texture::dispose();
}

bool render_context_3d_texture::is_useable() {
    return _builded_ == status_ 
        && related_ && related_->is_useable();
}

bool render_context_3d_texture::dispose() {
    if (_builded_ != status_) return false;
    status_ = _deleted_;
    assert(transmitter_ && related_ && related_value_);
    puppet_container<canvas_render_3d>* context = nullptr;
    auto raw_context = related_->get();
    if (nullptr != raw_context) {
        context = raw_context->raw_context_.get();
    }
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* v_ = nullptr;
        void run(barrel_buffer*) {
            assert(v_);
            if (context_) {
                assert(context_->data_);
                context_->data_->delete_textures(1, v_);
            }
            delete v_;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->v_ = related_value_; 
        task->context_ = context;
    }
    related_value_ = nullptr;
    return true;
}