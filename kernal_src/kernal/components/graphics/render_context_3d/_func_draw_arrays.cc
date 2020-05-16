
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.drawArrays(mode, first, count);
 *
 * mode
 *      A GLenum specifying the type primitive to render. Possible values are:
 *          gl.POINTS: Draws a single dot.
 *          gl.LINE_STRIP: Draws a straight line to the next vertex.
 *          gl.LINE_LOOP: Draws a straight line to the next 
 *              vertex, and connects the last vertex back to the first.
 *          gl.LINES: Draws a line between a pair of vertices.
 *          gl.TRIANGLE_STRIP
 *          gl.TRIANGLE_FAN
 *          gl.TRIANGLES: Draws a triangle for a group of three vertices.
 * 
 * first
 *      A GLint specifying the starting index in the array of vector points.
 * 
 * count
 *      A GLsizei specifying the number of indices to be rendered.
 * 
 * Return value
 *      None.
 *
 * Exceptions
 *      If mode is not one of the accepted values, a gl.INVALID_ENUM error is thrown.
 *      If first or count are negative, a gl.INVALID_VALUE error is thrown.
 *      if gl.CURRENT_PROGRAM is null, a gl.INVALID_OPERATION error is thrown.
 */
void render_context_3d::draw_arrays(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 3) return;
    uint32_t mode  = (uint32_t)_parameter[0].to_int32();
    int      first = (int)     _parameter[1].to_int32();
    int      count = (int)     _parameter[2].to_int32();

    if (DWL_POINTS         != mode &&
        DWL_LINE_STRIP     != mode &&
        DWL_LINE_LOOP      != mode &&
        DWL_LINES          != mode &&
        DWL_TRIANGLE_STRIP != mode &&
        DWL_TRIANGLE_FAN   != mode &&
        DWL_TRIANGLES      != mode) {
        return;
    }

    if (first < 0 || count < 0) { return; }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mode_; int first_, count_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->draw_arrays(mode_, first_, count_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mode_  = mode ;
    task->first_ = first;
    task->count_ = count;
    task->context_ = raw_context_.get();
    transmitter_->force_commit();
}