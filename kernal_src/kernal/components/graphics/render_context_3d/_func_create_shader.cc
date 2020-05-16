
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_3d::create_shader(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto t = (uint32_t)v.to_int32();
    if (DWL_VERTEX_SHADER != t && DWL_FRAGMENT_SHADER != t) {
        return;
    }
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    auto _context = _parameter.get_context();
    auto _obj = thread_related->cls_render_3d_shader_
        .create_new_instance(_context);
    if (!_obj.is_useable()) return;

    render_context_3d_shader* _instance = nullptr;
    _obj.hold_native_data(i_runtime_container<
        render_context_3d_shader>::create(&_instance));
    assert(_instance && _instance->related_value_);
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* v_ = nullptr; uint32_t t_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_ && v_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->create_shader(t_, v_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->v_ = _instance->related_value_;
    task->t_ = t;
    task->context_ = raw_context_.get();

    if (DWL_VERTEX_SHADER == t) {
        _instance->class_ = render_context_3d_shader_class::_vs_;
    } else if (DWL_FRAGMENT_SHADER == t) {
        _instance->class_ = render_context_3d_shader_class::_fs_;
    }
    _parameter.set_return((js_value)_obj);
}