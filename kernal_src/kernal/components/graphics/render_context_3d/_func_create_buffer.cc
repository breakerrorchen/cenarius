
#include "../render_context_3d_buffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_3d::create_buffer(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    auto _context = _parameter.get_context();
    auto _obj = thread_related->cls_render_3d_buffer_
        .create_new_instance(_context);
    if (!_obj.is_useable()) return;

    render_context_3d_buffer* _instance = nullptr;
    _obj.hold_native_data(i_runtime_container<
        render_context_3d_buffer>::create(&_instance));
    assert(_instance && _instance->related_value_);
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* v_ = nullptr;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_ && v_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->gen_buffers(1, v_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->v_ = _instance->related_value_;
    task->context_ = raw_context_.get();
    _parameter.set_return((js_value)_obj);
}