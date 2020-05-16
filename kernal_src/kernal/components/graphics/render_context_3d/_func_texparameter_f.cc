
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.texParameteri(GLenum target, GLenum pname, GLint param);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.TEXTURE_2D: A two-dimensional texture.
 *          gl.TEXTURE_CUBE_MAP: A cube-mapped texture.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.TEXTURE_3D: A three-dimensional texture.
 *          gl.TEXTURE_2D_ARRAY: A two-dimensional array texture.
 */
void render_context_3d::texparameter_f(js_parameter& _parameter) {
    render_context_3d::texparameter_i(_parameter);
}