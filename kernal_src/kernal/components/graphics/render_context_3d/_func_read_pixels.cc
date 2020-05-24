
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      // WebGL1: 
 *      void gl.readPixels(x, y, width, height, format, type, pixels); 
 *      
 *      // WebGL2: 
 *      void gl.readPixels(x, y, width, height, format, type, GLintptr offset); 
 *      void gl.readPixels(x, y, width, height, 
 *          format, type, ArrayBufferView pixels, GLuint dstOffset);
 *
 * x
 *      A GLint specifying the first horizontal pixel that is read from the 
 *      lower left corner of a rectangular block of pixels.
 *
 * y
 *      A GLint specifying the first vertical pixel that is read from the 
 *      lower left corner of a rectangular block of pixels.
 *
 * width
 *      A GLsizei specifying the width of the rectangle.
 *
 * height
 *      A GLsizei specifying the height of the rectangle. 
 *
 * format
 *      A GLenum specifying the format of the pixel data. 
 *      Possible values:
 *          gl.ALPHA: Discards the red, green and 
 *              blue components and reads the alpha component.
 *          gl.RGB: Discards the alpha components 
 *              and reads the red, green and blue components.
 *          gl.RGBA: Red, green, blue and alpha 
 *              components are read from the color buffer.
 * type
 *      A GLenum specifying the data type of the pixel data. 
 *      Possible values:
 *          gl.UNSIGNED_BYTE
 *          gl.UNSIGNED_SHORT_5_6_5
 *          gl.UNSIGNED_SHORT_4_4_4_4
 *          gl.UNSIGNED_SHORT_5_5_5_1
 *          gl.FLOAT
 *
 *      WebGL2 adds
 *          gl.BYTE
 *          gl.UNSIGNED_INT_2_10_10_10_REV
 *          gl.HALF_FLOAT
 *          gl.SHORT
 *          gl.UNSIGNED_SHORT
 *          gl.INT
 *          gl.UNSIGNED_INT
 *          gl.UNSIGNED_INT_10F_11F_11F_REV
 *          gl.UNSIGNED_INT_5_9_9_9_REV
 *
 * pixels
 *      An ArrayBufferView object to read data into. 
 *      The array type must match the type of the type parameter.
 *          Uint8Array for gl.UNSIGNED_BYTE.
 *          Uint16Array for gl.UNSIGNED_SHORT_5_6_5, 
 *              gl.UNSIGNED_SHORT_4_4_4_4, or gl.UNSIGNED_SHORT_5_5_5_1.
 *          Float32Array for gl.FLOAT.
 *
 * dstOffset
 *      Offset. Defaults to 0.
 *
 * Exceptions
 *      A gl.INVALID_ENUM error is thrown if format or type is not an accepted value.
 *      A gl.INVALID_OPERATION error is thrown if
 *          type is gl.UNSIGNED_SHORT_5_6_5 and format is not gl.RGB.
 *          type is gl.UNSIGNED_SHORT_4_4_4_4 and format is not gl.RGBA.
 *          type does not match the typed array type of pixels.
 *      A gl.INVALID_FRAMEBUFFER_OPERATION error is thrown if the currently 
 *          bound framebuffer is not framebuffer complete.
 *
 */
void render_context_3d::read_pixels(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 7) return;
    auto x      = _parameter[0].to_int32();
    auto y      = _parameter[1].to_int32();
    auto w      = _parameter[2].to_int32();
    auto h      = _parameter[3].to_int32();
    auto format = _parameter[4].to_int32();
    auto type   = _parameter[5].to_int32();
    auto pixels = _parameter[6];

    if (w <= 0 || h <= 0) return;
    if (DWL_ALPHA   != format &&
        DWL_RGB     != format &&
        DWL_RGBA    != format) {
        return;
    }

    if (DWL_UNSIGNED_BYTE           != type &&
        DWL_UNSIGNED_SHORT_5_6_5    != type &&
        DWL_UNSIGNED_SHORT_4_4_4_4  != type &&
        DWL_UNSIGNED_SHORT_5_5_5_1  != type &&
        DWL_FLOAT                   != type) {
        return;
    }

    // DWL_INVALID_OPERATION
    if (DWL_UNSIGNED_SHORT_5_6_5  == type && 
        DWL_RGB != format) {
        return;
    }

    // DWL_INVALID_OPERATION
    if ((DWL_UNSIGNED_SHORT_4_4_4_4 == type ||
        DWL_UNSIGNED_SHORT_5_5_5_1  == type) &&
        DWL_RGBA != format) {
        return;
    }

    // DWL_INVALID_OPERATION
    if (DWL_UNSIGNED_BYTE == type && 
            !pixels.is_typed_arr_uint8()) {
        return;
    }

    // DWL_INVALID_OPERATION
    if ((DWL_UNSIGNED_SHORT_5_6_5   == type ||
         DWL_UNSIGNED_SHORT_4_4_4_4 == type ||
         DWL_UNSIGNED_SHORT_5_5_5_1 == type) &&
            !pixels.is_typed_arr_uint16()) {
        return;
    }

    // DWL_INVALID_OPERATION
    if (DWL_FLOAT == type && 
            !pixels.is_typed_arr_float32()) {
        return;
    }

    auto typed_buffer = pixels.typedarr_buffer();
    if (!typed_buffer.addr_ || 0 == typed_buffer.size_) {
        return;
    }

    // check size
    if (DWL_UNSIGNED_BYTE == type) {
        if (DWL_ALPHA == format) {
            if (w * h > typed_buffer.size_) {
                return; 
            }
        } else if (DWL_RGB == format) {
            if (w * h * 3 > typed_buffer.size_) {
                return; 
            }
        } else if (DWL_RGBA == format) {
            if (w * h * 4 > typed_buffer.size_) {
                return; 
            }
        }
    } else if (DWL_UNSIGNED_SHORT_5_6_5 == type) {
        if (w * h * 2 > typed_buffer.size_) {
            return; 
        }
    } else if (DWL_UNSIGNED_SHORT_4_4_4_4 == type ||
            DWL_UNSIGNED_SHORT_5_5_5_1 == type) {
        if (w * h * 2 > typed_buffer.size_) {
            return; 
        }
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        void* buffer_ = nullptr; uint32_t format_, type_;
        int x_ = 0, y_ = 0, w_ = 0, h_ = 0; 
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->read_pixels(
                x_, y_, w_, h_, format_, type_, buffer_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->buffer_  = typed_buffer.addr_;
    task->format_  = format;
    task->type_    = type;
    task->x_       = x;
    task->y_       = y;
    task->w_       = w;
    task->h_       = h;
    task->context_ = raw_context_.get();

    // 同步 !!!
    transmitter_->force_commit(true);
}