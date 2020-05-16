
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.copyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
 *
 * target
 *      A GLenum specifying 
 *      the binding point (target) of the active texture. Possible values:
 *          gl.TEXTURE_2D: A two-dimensional texture.
 *          gl.TEXTURE_CUBE_MAP_POSITIVE_X: Positive X face for a cube-mapped texture.
 *          gl.TEXTURE_CUBE_MAP_NEGATIVE_X: Negative X face for a cube-mapped texture.
 *          gl.TEXTURE_CUBE_MAP_POSITIVE_Y: Positive Y face for a cube-mapped texture.
 *          gl.TEXTURE_CUBE_MAP_NEGATIVE_Y: Negative Y face for a cube-mapped texture.
 *          gl.TEXTURE_CUBE_MAP_POSITIVE_Z: Positive Z face for a cube-mapped texture.
 *          gl.TEXTURE_CUBE_MAP_NEGATIVE_Z: Negative Z face for a cube-mapped texture.
 * 
 * level
 *      A GLint specifying the level of detail. 
 *      Level 0 is the base image level and level n is the nth mipmap reduction level.
 * 
 * xoffset
 *      A GLint specifying the horizontal offset within the texture image.
 * 
 * yoffset
 *      A GLint specifying the vertical offset within the texture image.
 * 
 * x
 *      A GLint specifying the x coordinate of the lower left corner where to start copying.
 * 
 * y
 *      A GLint specifying the y coordinate of the lower left corner where to start copying.
 * 
 * width
 *      A GLsizei specifying the width of the texture.
 * 
 * height
 *      A GLsizei specifying the height of the texture.    
 * 
 * Return value
 *      None.
 */
void render_context_3d::copy_texsubimage_2d(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 8) return;
    uint32_t target   = (uint32_t)_parameter[0].to_int32();
    int      level    = (int)     _parameter[1].to_int32();
    int      x_offset = (int)     _parameter[2].to_int32();
    int      y_offset = (int)     _parameter[3].to_int32();
    int      x        = (int)     _parameter[4].to_int32();
    int      y        = (int)     _parameter[5].to_int32();
    int      width    = (int)     _parameter[6].to_int32();
    int      height   = (int)     _parameter[7].to_int32();

    if (DWL_TEXTURE_2D                  != target &&
        DWL_TEXTURE_CUBE_MAP_POSITIVE_X != target &&
        DWL_TEXTURE_CUBE_MAP_NEGATIVE_X != target &&
        DWL_TEXTURE_CUBE_MAP_POSITIVE_Y != target &&
        DWL_TEXTURE_CUBE_MAP_NEGATIVE_Y != target &&
        DWL_TEXTURE_CUBE_MAP_POSITIVE_Z != target &&
        DWL_TEXTURE_CUBE_MAP_NEGATIVE_Z != target) {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t target_;
        int      level_;
        int      x_offset_, y_offset_, x_, y_, width_, height_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->copy_tex_sub_image2d(target_, level_, 
                x_offset_, y_offset_, x_, y_, width_, height_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->target_    = target;
    task->level_     = level;
    task->x_offset_  = x_offset;
    task->y_offset_  = y_offset;
    task->x_         = x;
    task->y_         = y;
    task->width_     = width;
    task->height_    = height;
    task->context_   = raw_context_.get();
}