
#include "../render_context_3d_renderbuffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getRenderbufferParameter(target, pname);
 * 
 * target
 *      A Glenum specifying the target renderbuffer object. Possible values:
 *          gl.RENDERBUFFER: Buffer data storage for single images 
 *              in a renderable internal format.
 * 
 * pname
 *     A Glenum specifying the information to query. Possible values:
 *          gl.RENDERBUFFER_WIDTH: Returns a GLint indicating the width 
 *              of the image of the currently bound renderbuffer.
 *          gl.RENDERBUFFER_HEIGHT: Returns a GLint indicating the height 
 *              of the image of the currently bound renderbuffer.
 *          gl.RENDERBUFFER_INTERNAL_FORMAT: Returns a GLenum indicating 
 *              the internal format of the currently bound renderbuffer. 
 *              The default is gl.RGBA4. Possible return values:
 *              gl.RGBA4: 4 red bits, 4 green bits, 4 blue bits 4 alpha bits.
 *              gl.RGB565: 5 red bits, 6 green bits, 5 blue bits. 
 *              gl.RGB5_A1: 5 red bits, 5 green bits, 5 blue bits, 1 alpha bit.
 *              gl.DEPTH_COMPONENT16: 16 depth bits.
 *              gl.STENCIL_INDEX8: 8 stencil bits.
 *          gl.RENDERBUFFER_GREEN_SIZE: Returns a GLint that is the 
 *              resolution size (in bits) for the green color.
 *          gl.RENDERBUFFER_BLUE_SIZE: Returns a GLint that is the resolution 
 *              size (in bits) for the blue color.
 *          gl.RENDERBUFFER_RED_SIZE: Returns a GLint that is the resolution 
 *              size (in bits) for the red color.
 *          gl.RENDERBUFFER_ALPHA_SIZE: Returns a GLint that is the resolution 
 *              size (in bits) for the alpha component.
 *          gl.RENDERBUFFER_DEPTH_SIZE: Returns a GLint that is the resolution 
 *              size (in bits) for the depth component.
 *          gl.RENDERBUFFER_STENCIL_SIZE: Returns a GLint that is the resolution 
 *              size (in bits) for the stencil component.
 * 
 * When using a WebGL 2 context, the following value is available additionally:
 *          gl.RENDERBUFFER_SAMPLES: Returns a GLint indicating the number of 
 *              samples of the image of the currently bound renderbuffer.
 * 
 * Return value
 *      Depends on the requested information (as specified with pname). 
 *      Either a GLint or a GLenum.
 */
void render_context_3d::get_renderbuffer_parameter(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_RENDERBUFFER != target) return;
    auto renderbuffer = context_cache_.raw_renderbuffer_bind_;
    if (nullptr == renderbuffer) return;
    auto pname = (uint32_t)_parameter[1].to_int32();

    auto js_context = _parameter.get_context();
    if (DWL_RENDERBUFFER_WIDTH == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)renderbuffer->w_));
    } else if (DWL_RENDERBUFFER_HEIGHT == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)renderbuffer->h_));
    } else if (DWL_RENDERBUFFER_INTERNAL_FORMAT == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)renderbuffer->internal_format_));
    } else if (DWL_RENDERBUFFER_GREEN_SIZE == pname) {
        auto format = renderbuffer->internal_format_;
        int32_t size = 0;
        if (DWL_RGBA4 == format) {
            size = 4;
        } else if (DWL_RGB565 == format) {
            size = 6;
        } else if (DWL_RGB5_A1 == format) {
            size = 5;
        } else if (DWL_DEPTH_COMPONENT16 == format) {
            size = 0;
        } else if (DWL_STENCIL_INDEX8 == format) {
            size = 0;
        }
        _parameter.set_return(js_value::create(js_context, size));
    } else if (DWL_RENDERBUFFER_BLUE_SIZE == pname) {
        auto format = renderbuffer->internal_format_;
        int32_t size = 0;
        if (DWL_RGBA4 == format) {
            size = 4;
        } else if (DWL_RGB565 == format) {
            size = 5;
        } else if (DWL_RGB5_A1 == format) {
            size = 5;
        } else if (DWL_DEPTH_COMPONENT16 == format) {
            size = 0;
        } else if (DWL_STENCIL_INDEX8 == format) {
            size = 0;
        }
        _parameter.set_return(js_value::create(js_context, size));
    } else if (DWL_RENDERBUFFER_RED_SIZE == pname) {
        auto format = renderbuffer->internal_format_;
        int32_t size = 0;
        if (DWL_RGBA4 == format) {
            size = 4;
        } else if (DWL_RGB565 == format) {
            size = 5;
        } else if (DWL_RGB5_A1 == format) {
            size = 5;
        } else if (DWL_DEPTH_COMPONENT16 == format) {
            size = 0;
        } else if (DWL_STENCIL_INDEX8 == format) {
            size = 0;
        }
        _parameter.set_return(js_value::create(js_context, size));
    } else if (DWL_RENDERBUFFER_ALPHA_SIZE == pname) {
        auto format = renderbuffer->internal_format_;
        int32_t size = 0;
        if (DWL_RGBA4 == format) {
            size = 4;
        } else if (DWL_RGB565 == format) {
            size = 0;
        } else if (DWL_RGB5_A1 == format) {
            size = 1;
        } else if (DWL_DEPTH_COMPONENT16 == format) {
            size = 0;
        } else if (DWL_STENCIL_INDEX8 == format) {
            size = 0;
        }
        _parameter.set_return(js_value::create(js_context, size));
    } else if (DWL_RENDERBUFFER_DEPTH_SIZE == pname) {
        auto format = renderbuffer->internal_format_;
        int32_t size = 0;
        if (DWL_RGBA4 == format) {
            size = 0;
        } else if (DWL_RGB565 == format) {
            size = 0;
        } else if (DWL_RGB5_A1 == format) {
            size = 0;
        } else if (DWL_DEPTH_COMPONENT16 == format) {
            size = 16;
        } else if (DWL_STENCIL_INDEX8 == format) {
            size = 0;
        }
        _parameter.set_return(js_value::create(js_context, size));
    } else if (DWL_RENDERBUFFER_STENCIL_SIZE == pname) {
        auto format = renderbuffer->internal_format_;
        int32_t size = 0;
        if (DWL_RGBA4 == format) {
            size = 0;
        } else if (DWL_RGB565 == format) {
            size = 0;
        } else if (DWL_RGB5_A1 == format) {
            size = 0;
        } else if (DWL_DEPTH_COMPONENT16 == format) {
            size = 0;
        } else if (DWL_STENCIL_INDEX8 == format) {
            size = 8;
        }
        _parameter.set_return(js_value::create(js_context, size));
    } else {
        ;
    }
}