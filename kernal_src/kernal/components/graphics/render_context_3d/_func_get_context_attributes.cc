
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      gl.getContextAttributes();
 * 
 * Return value
 *      A WebGLContextAttributes object that contains the actual 
 *      context parameters, or null if the context is lost.
 */
void render_context_3d::get_context_attributes(js_parameter& _parameter) {
    const char* context_attributes = 
        "   {                                   "
        "       alpha:                  true,   " 
        "       antialias:              true,   "
        "       depth:                  true,   "
        "       stencil:                true,   "
        "       preserveDrawingBuffer:  true    "
        "   }                                   ";
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, context_attributes, true));
}