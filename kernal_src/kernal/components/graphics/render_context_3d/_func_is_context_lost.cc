
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      gl.isContextLost();
 * 
 * Return value
 *      A Boolean which is true if the context is lost, or false if not.
 */
void render_context_3d::is_context_lost(js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(js_context, false));
}