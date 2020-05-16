
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.activeTexture(texture);
 *
 * Parameters
 *      texture
 *      The texture unit to make active. The value is a gl.TEXTUREI where I 
 *      is within the range from 0 to gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1.
 * 
 * Return value
 *      None.
 *
 * Exceptions
 *      If texture is not one of gl.TEXTUREI, where I is within the range from 0 
 *      to gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1, a gl.INVALID_ENUM error is thrown
 */
void render_context_3d::active_texture(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto index = v.to_int32();
    if (index < 0 || index >= 
        render_attitude_->max_combined_texture_image_units_) {
        return;
    }
    context_cache_.ative_texture_ = DWL_TEXTURE0 + index;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t index_ = DWL_TEXTURE0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->active_texture(index_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->context_ = raw_context_.get();
    task->index_ = context_cache_.ative_texture_;
}