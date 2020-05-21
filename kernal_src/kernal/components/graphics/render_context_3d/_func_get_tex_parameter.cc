
#include "../render_context_3d_texture/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getTexParameter(target, pname);
 * 
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.TEXTURE_2D: A two-dimensional texture.
 *          gl.TEXTURE_CUBE_MAP: A cube-mapped texture.
 *      When using a WebGL 2 context, 
 *      the following values are available additionally:
 *          gl.TEXTURE_3D: A three-dimensional texture.
 *          gl.TEXTURE_2D_ARRAY: A two-dimensional array texture.
 * pname
 *      Available in a WebGL 1 context:
 *      gl.TEXTURE_MAG_FILTER               gl.LINEAR (default value), 
 *                                          gl.NEAREST.
 * 
 *      gl.TEXTURE_MIN_FILTER               gl.LINEAR, 
 *                                          gl.NEAREST, 
 *                                          gl.NEAREST_MIPMAP_NEAREST, 
 *                                          gl.LINEAR_MIPMAP_NEAREST, 
 *                                          gl.NEAREST_MIPMAP_LINEAR (default value), 
 *                                          gl.LINEAR_MIPMAP_LINEAR.
 * 
 *      gl.TEXTURE_WRAP_S	                gl.REPEAT (default value),
 *                                          gl.CLAMP_TO_EDGE,
 *                                          gl.MIRRORED_REPEAT.
 * 
 *      gl.TEXTURE_WRAP_T                   gl.REPEAT (default value),
 *                                          gl.CLAMP_TO_EDGE,
 *                                          gl.MIRRORED_REPEAT.
 * 
 *      Additionally available when using the EXT_texture_filter_anisotropic extension
 *      ext.TEXTURE_MAX_ANISOTROPY_EXT	    Any float values.
 * 
 *      Additionally available when using a WebGL 2 context
 *      gl.TEXTURE_BASE_LEVEL               Any int values.
 *      
 *      gl.TEXTURE_COMPARE_FUNC	            gl.LEQUAL (default value), 
 *                                          gl.GEQUAL, 
 *                                          gl.LESS, 
 *                                          gl.GREATER, 
 *                                          gl.EQUAL, 
 *                                          gl.NOTEQUAL, 
 *                                          gl.ALWAYS, 
 *                                          gl.NEVER.
 *  
 *      gl.TEXTURE_COMPARE_MODE             gl.NONE (default value), 
 *                                          gl.COMPARE_REF_TO_TEXTURE.
 * 
 *      gl.TEXTURE_IMMUTABLE_FORMAT         true or false
 * 
 *      gl.TEXTURE_IMMUTABLE_LEVELS	        Any uint values.
 * 
 *      gl.TEXTURE_MAX_LEVEL                Any int values.
 * 
 *      gl.TEXTURE_MAX_LOD	                Any float values.
 * 
 *      gl.TEXTURE_MIN_LOD                  Any float values.
 * 
 *      gl.TEXTURE_WRAP_R                   gl.REPEAT (default value), 
 *                                          gl.CLAMP_TO_EDGE, 
 *                                          gl.MIRRORED_REPEAT.
 * Return value
 *      Returns the requested texture information (as specified with pname). 
 *      If an error occurs, null is returned.
 */
void render_context_3d::get_tex_parameter(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    render_context_3d_texture* raw_texture = nullptr;
    if (DWL_TEXTURE_2D == target) {
        raw_texture = context_cache_.raw_texture_2d_bind_;
    } else if (DWL_TEXTURE_CUBE_MAP == target) {
        raw_texture = context_cache_.raw_texture_cube_bind_;
    } else {
        return;
    }
    if (nullptr == raw_texture) return;

    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;
    auto pname = (uint32_t)_1.to_int32();
    if (DWL_TEXTURE_MAG_FILTER == pname) {
        auto js_context = _parameter.get_context();
        _parameter.set_return(js_value::create(
            js_context, (int32_t)raw_texture->mag_filter_));
    }
    else if (DWL_TEXTURE_MIN_FILTER == pname) {
        auto js_context = _parameter.get_context();
        _parameter.set_return(js_value::create(
            js_context, (int32_t)raw_texture->min_filter_));
    }
    else if (DWL_TEXTURE_WRAP_S == pname) {
        auto js_context = _parameter.get_context();
        _parameter.set_return(js_value::create(
            js_context, (int32_t)raw_texture->wrap_s_));
    }
    else if (DWL_TEXTURE_WRAP_T == pname) {
        auto js_context = _parameter.get_context();
        _parameter.set_return(js_value::create(
            js_context, (int32_t)raw_texture->wrap_t_));
    } 
    else {
        ;
    }
}