
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.generateMipmap(target);
 * 
 * target
 *      A GLenum specifying the binding point (target) of the active 
 *      texture whose mipmaps will be generated. 
 *      Possible values:
 *          gl.TEXTURE_2D: A two-dimensional texture.
 *          gl.TEXTURE_CUBE_MAP: A cube-mapped texture.
 *      When using a WebGL 2 context, 
 *      the following values are available additionally:
 *          gl.TEXTURE_3D: A three-dimensional texture.
 *          gl.TEXTURE_2D_ARRAY: A two-dimensional array texture.
 * 
 * Return value
 *      None.
 */
void render_context_3d::generate_mipmap(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto target = (uint32_t)v.to_int32();
    if (DWL_TEXTURE_2D       != target &&
        DWL_TEXTURE_CUBE_MAP != target) {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t target_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->generate_mipmap(target_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->target_ = target; task->context_ = raw_context_.get();
}