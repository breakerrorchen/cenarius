
#include "../render_context_3d_texture/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      GLboolean gl.isTexture(texture);
 * 
 * texture
 *      A WebGLTexture to check.
 *
 * Return value
 *      A GLboolean indicating whether or not the texture is valid.
 */
void render_context_3d::is_texture(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    auto _i = js_class_extract::extract<render_context_3d_texture>(v);
    bool useable = _i && _i->is_useable();
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(js_context, useable));
}