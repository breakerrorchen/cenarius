
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.drawElements(mode, count, type, offset);
 *
 * mode
 *      A GLenum specifying the type primitive to render. Possible values are:
 *          gl.POINTS: Draws a single dot.
 *          gl.LINE_STRIP: Draws a straight line to the next vertex.
 *          gl.LINE_LOOP: Draws a straight line to the next vertex, 
 *              and connects the last vertex back to the first.
 *          gl.LINES: Draws a line between a pair of vertices.
 *          gl.TRIANGLE_STRIP
 *          gl.TRIANGLE_FAN
 *          gl.TRIANGLES: Draws a triangle for a group of three vertices.
 * 
 * count
 *      A GLsizei specifying the number of elements to be rendered.
 * 
 * type
 *      A GLenum specifying the type of the values in the element array buffer. 
 *      Possible values are:
 *          gl.UNSIGNED_BYTE
 *          gl.UNSIGNED_SHORT
 *      When using the OES_element_index_uint extension:
 *          gl.UNSIGNED_INT
 * 
 * offset
 *      A GLintptr specifying a byte offset in the element array buffer. 
 *      Must be a valid multiple of the size of the given type.
 * 
 * Return value
 *      None.
 *
 * Exceptions
 *      If mode is not one of the accepted values, a gl.INVALID_ENUM error is thrown.
 *      If offset is not a valid multiple of the size of the given type, 
 *      a gl.INVALID_OPERATION error is thrown.
 *      If count is negative, a gl.INVALID_VALUE error is thrown.
 */
void render_context_3d::draw_elements(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    uint32_t mode   = (uint32_t)_parameter[0].to_int32();
    int      count  = (int)     _parameter[1].to_int32();
    uint32_t type   = (uint32_t)_parameter[2].to_int32();
    int      offset = (int)     _parameter[3].to_int32();

    if (DWL_POINTS          != mode &&
        DWL_LINE_STRIP      != mode &&
        DWL_LINE_LOOP       != mode &&
        DWL_LINES           != mode &&
        DWL_TRIANGLE_STRIP  != mode &&
        DWL_TRIANGLE_FAN    != mode &&
        DWL_TRIANGLES       != mode) {
        return;
    }

    if (DWL_UNSIGNED_BYTE  != type &&
        DWL_UNSIGNED_SHORT != type) { 
        return;
    }

    if (offset < 0) {
        return;
    }

    if (DWL_UNSIGNED_SHORT == type && offset % 2 != 0) {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mode_, type_; int count_, offset_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            auto ptr = (void*)((char*)(nullptr) + offset_);
            raw_context->draw_elements(mode_, count_, type_, ptr);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mode_    = mode ;
    task->count_   = count;
    task->type_    = type ;
    task->offset_  = offset;
    task->context_ = raw_context_.get();
    transmitter_->force_commit();
}