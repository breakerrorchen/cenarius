
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.compileShader(shader);
 *
 * shader
 *      A fragment or vertex WebGLShader.
 * 
 * Return value
 *      None.
 */
void render_context_3d::compile_shader(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    auto shader = js_class_extract::extract<
        render_context_3d_shader>(_0);
    if (!shader || !shader->is_useable()) return;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        bool* success_ = nullptr; std::string* log_  = nullptr;
        uint32_t* shader_ = nullptr;
        void run(barrel_buffer*) {
            assert(success_ && log_ && shader_);
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->compile_shader(*shader_);
            int32_t result = DWL_FALSE;
            raw_context->get_shader_i_v(
                *shader_, DWL_COMPILE_STATUS, &result);
            if (DWL_TRUE == result) {
                *success_ = true;
            } else {
                int32_t info_len = 0;
                raw_context->get_shader_i_v(
                    *shader_, DWL_INFO_LOG_LENGTH, &info_len);
                log_->resize(info_len + 1);
                if (info_len <= 0) return;
                raw_context->get_shader_info_log(
                    *shader_, info_len, nullptr, log_->data());
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    bool success = true; std::string log;
    task->shader_  = shader->related_value_;
    task->success_ = &success;
    task->log_     = &log; 
    task->context_ = raw_context_.get();
    // ！！！同步
    transmitter_->force_commit(true, false);

    shader->compile_log_ = std::move(log);
    if (success) {
        shader->state_ = 
            render_context_3d_shader_state::_compile_success_;
    } else {
        shader->state_ = 
            render_context_3d_shader_state::_compile_fail_;
    }
}