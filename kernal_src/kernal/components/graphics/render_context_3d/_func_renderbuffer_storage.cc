
#include "../render_context_3d_renderbuffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.renderbufferStorage(target, internalFormat, width, height);
 *
 * target
 *      A Glenum specifying the target renderbuffer object. 
 *      Possible values:
 *          gl.RENDERBUFFER: Buffer data storage for single 
 *              images in a renderable internal format.
 *
 * internalFormat
 *      A Glenum specifying the internal format of the renderbuffer. 
 *      Possible values: 
 *          gl.RGBA4: 4 red bits, 4 green bits, 4 blue bits 4 alpha bits.
 *          gl.RGB565: 5 red bits, 6 green bits, 5 blue bits.
 *          gl.RGB5_A1: 5 red bits, 5 green bits, 5 blue bits, 1 alpha bit.
 *          gl.DEPTH_COMPONENT16: 16 depth bits.
 *          gl.STENCIL_INDEX8: 8 stencil bits.
 *          gl.DEPTH_STENCIL
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.R8
 *          gl.R8UI
 *          gl.R8I
 *          gl.R16UI
 *          gl.R16I
 *          gl.R32UI
 *          gl.R32I
 *          gl.RG8
 *          gl.RG8UI
 *          gl.RG8I
 *          gl.RG16UI
 *          gl.RG16I
 *          gl.RG32UI
 *          gl.RG32I
 *          gl.RGB8
 *          gl.RGBA8
 *          gl.SRGB8_ALPHA8 (also available as an extension for WebGL 1, see below)
 *          gl.RGB10_A2
 *          gl.RGBA8UI
 *          gl.RGBA8I
 *          gl.RGB10_A2UI
 *          gl.RGBA16UI
 *          gl.RGBA16I
 *          gl.RGBA32I
 *          gl.RGBA32UI
 *          gl.DEPTH_COMPONENT24
 *          gl.DEPTH_COMPONENT32F
 *          gl.DEPTH24_STENCIL8
 *          gl.DEPTH32F_STENCIL8
 *      When using the WEBGL_color_buffer_float extension:
 *          ext.RGBA32F_EXT: RGBA 32-bit floating-point type.
 *          ext.RGB32F_EXT: RGB 32-bit floating-point type.
 *      When using the EXT_sRGB extension:
 *          ext.SRGB8_ALPHA8_EXT: 8-bit sRGB and alpha.
 *      When using a WebGL 2 context and the EXT_color_buffer_float extension:
 *          gl.R16F
 *          gl.RG16F
 *          gl.RGBA16F
 *          gl.R32F
 *          gl.RG32F
 *          gl.RGBA32F
 *          gl.R11F_G11F_B10F
 * width
 *      A GLsizei specifying the width of the renderbuffer in pixels.
 *
 * height
 *      A GLsizei specifying the height of the renderbuffer in pixels.      
 */
void render_context_3d::renderbuffer_storage(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    auto target          = (uint32_t)_parameter[0].to_int32();
    auto internal_format = (uint32_t)_parameter[1].to_int32();
    int  width           = _parameter[2].to_int32();
    int  height          = _parameter[3].to_int32();
    if (DWL_RENDERBUFFER != target) {
        return;
    }

    if (width  <= 0 || width  > render_attitude_->max_renderbuffer_size_ ||
        height <= 0 || height > render_attitude_->max_renderbuffer_size_) {
        return;
    }
    
    if (DWL_RGBA4             != internal_format &&
        DWL_RGB565            != internal_format &&
        DWL_RGB5_A1           != internal_format &&
        DWL_DEPTH_COMPONENT16 != internal_format &&
        DWL_STENCIL_INDEX8    != internal_format &&
        DWL_DEPTH_STENCIL     != internal_format) {
        return;
    }

    if (DWL_DEPTH_STENCIL == internal_format) {
        internal_format = DWL_DEPTH24_STENCIL8;
    }

    auto renderbuffer = context_cache_.raw_renderbuffer_bind_;
    if (nullptr == renderbuffer) return;
    renderbuffer->w_ = (uint32_t)width ;
    renderbuffer->h_ = (uint32_t)height;
    renderbuffer->internal_format_ = internal_format;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t internal_format_; int w_, h_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->render_buffer_storage(
                DWL_RENDERBUFFER, internal_format_, w_, h_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->internal_format_ = internal_format;
    task->w_ = width;
    task->h_ = height;
    task->context_ = raw_context_.get();
}