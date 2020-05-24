
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.enableVertexAttribArray(index);
 *
 * index
 *      A GLuint specifying the index number 
 *      that uniquely identifies the vertex attribute to enable.
 */
void render_context_3d::enable_vertex_attrib_arr(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto index = (uint32_t)_0.to_int32();
    if (index >= render_attitude_->max_vertex_attribs_ || index >= 64) {
        return;
    }
    context_cache_.vertex_attrib_[index].enable_ = true;
    
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t index_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->enable_vertex_attr_arr(index_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->index_ = index; task->context_ = raw_context_.get();
}