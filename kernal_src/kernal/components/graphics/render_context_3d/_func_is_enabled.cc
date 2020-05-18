
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      GLboolean gl.isEnabled(cap);
 * 
 * cap
 *      A GLenum specifying which WebGL capability to test. Possible values:
 *          gl.BLEND
 *          gl.CULL_FACE
 *          gl.DEPTH_TEST
 *          gl.DITHER
 *          gl.POLYGON_OFFSET_FILL
 *          gl.SAMPLE_ALPHA_TO_COVERAGE
 *          gl.SAMPLE_COVERAGE
 *          gl.SCISSOR_TEST
 *          gl.STENCIL_TEST
 *      When using a WebGL 2 context,
 *      the following values are available additionally:
 *          gl.RASTERIZER_DISCARD
 *
 * Return value
 *      A GLboolean indicating 
 *      if the capability cap is enabled (true), or not (false).
 */
void render_context_3d::is_enabled(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto cap = (uint32_t)v.to_int32(); bool value = false;
    if (DWL_BLEND == value) {
        value = context_cache_.enable_blend_;
    } else if (DWL_CULL_FACE == value) {
        value = context_cache_.enable_cull_face_;
    } else if (DWL_DEPTH_TEST == value) {
        value = context_cache_.enable_depth_test_;
    } else if (DWL_DITHER == value) {
        value = context_cache_.enable_dither_;
    } else if (DWL_POLYGON_OFFSET_FILL == value) {
        value = context_cache_.enable_polygon_offset_fill_;
    } else if (DWL_SAMPLE_ALPHA_TO_COVERAGE == value) {
        value = context_cache_.enable_sample_alpha_to_coverage_;
    } else if (DWL_SAMPLE_COVERAGE == value) {
        value = context_cache_.enable_coverage_;
    } else if (DWL_SCISSOR_TEST == value) {
        value = context_cache_.enable_scissor_test_;
    } else if (DWL_STENCIL_TEST == value) {
        value = context_cache_.enable_stencil_test_;
    } else {
        return;
    }
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(js_context, value));
}