
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.enable(cap);
 * 
 * cap
 *      A GLenum specifying which WebGL capability to enable. Possible values:
 *          gl.BLEND	                Deactivates blending of the computed fragment color values
 *          gl.CULL_FACE	            Deactivates culling of polygons
 *          gl.DEPTH_TEST	            Deactivates depth comparisons and updates to the depth buffer.
 *          gl.DITHER	                Deactivates dithering of 
 *                                      color components before they get written to the color buffer.
 *          gl.POLYGON_OFFSET_FILL	    Deactivates adding an offset to depth values of polygon's fragments
 *          gl.SAMPLE_ALPHA_TO_COVERAGE	Deactivates the computation 
 *                                      of a temporary coverage value determined by the alpha value
 *          gl.SAMPLE_COVERAGE	        Deactivates ANDing the fragment's 
 *                                      coverage with the temporary coverage value.
 *          gl.SCISSOR_TEST	            Deactivates the scissor test that discards 
 *                                      fragments that are outside of the scissor rectangle
 *          gl.STENCIL_TEST	            Deactivates stencil testing and updates to the stencil buffer
 * 
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.RASTERIZER_DISCARD	    Deactivates that primitives are discarded immediately 
 *                                      before the rasterization stage, but after the optional transform 
 *                                      feedback stage. gl.clear() commands are ignored.
 */
void render_context_3d::enable(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto value = (uint32_t)v.to_int32();
    if (DWL_BLEND == value) {
        context_cache_.enable_blend_                      = true;
    } else if (DWL_CULL_FACE == value) {
        context_cache_.enable_cull_face_                  = true;
    } else if (DWL_DEPTH_TEST == value) {
        context_cache_.enable_depth_test_                 = true;
    } else if (DWL_DITHER == value) {
        context_cache_.enable_dither_                     = true;
    } else if (DWL_POLYGON_OFFSET_FILL == value) {
        context_cache_.enable_polygon_offset_fill_        = true;
    } else if (DWL_SAMPLE_ALPHA_TO_COVERAGE == value) {
        context_cache_.enable_sample_alpha_to_coverage_   = true;
    } else if (DWL_SAMPLE_COVERAGE == value) {
        context_cache_.enable_coverage_                   = true;
    } else if (DWL_SCISSOR_TEST == value) {
        context_cache_.enable_scissor_test_               = true;
    } else if (DWL_STENCIL_TEST == value) {
        context_cache_.enable_stencil_test_               = true;
    } else {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t value_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->enable(value_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->value_ = value; task->context_ = raw_context_.get();
}