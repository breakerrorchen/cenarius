
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.pixelStorei(pname, param);
 * 
 * pname
 *      A Glenum specifying which parameter to set. See below for possible values. 
 *
 * param
 *      A GLint specifying a value to set the pname parameter to. 
 *      See below for possible values.
 */
void render_context_3d::pixel_store_i(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_number()) return;
    auto pname = (uint32_t)v.to_int32();
    if (DWL_PACK_ALIGNMENT == pname || DWL_UNPACK_ALIGNMENT == pname) {
        v = _parameter.get_argument_at(1);
        if (!v.is_number()) return;
        auto param = (uint32_t)v.to_int32();
        if (1 != param && 2 != param && 4 != param && 8 != param) {
            return;
        }

        if (DWL_PACK_ALIGNMENT == pname) {
            if (param == context_cache_.pack_alignment_) {
                return;
            }
            context_cache_.pack_alignment_ = param;
        } else {
            if (param == context_cache_.unpack_alignment_) {
                return;
            }
            context_cache_.unpack_alignment_ = param;
        }

        struct __task__ {
            puppet_container<canvas_render_3d>* context_ = nullptr;
            uint32_t pname_, param_;
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
                auto raw_context = context_->data_;
                assert(raw_context);
                raw_context->pixel_store_i(pname_, param_);
            }
        };
        auto task = transmitter_->alloc<__task__>();
        assert(nullptr != task);
        task->pname_   = pname;
        task->param_   = param;
        task->context_ = raw_context_.get();
    } else if (DWL_UNPACK_FLIP_Y_WEBGL == pname) {
        auto v = _parameter.get_argument_at(1);
        if (!v.is_boolean()) return;
        context_cache_.unpack_filp_y_webgl_ = v.to_bool();
    } else if (DWL_UNPACK_PREMULTIPLY_ALPHA_WEBGL == pname) {
        auto v = _parameter.get_argument_at(1);
        if (!v.is_boolean()) return;
        context_cache_.unpack_premu_alpha_webgl_ = v.to_bool();
    }
}