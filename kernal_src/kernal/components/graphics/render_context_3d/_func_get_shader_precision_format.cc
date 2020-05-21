
#include "../render_context_3d_shader_precison/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      WebGLShaderPrecisionFormat gl.getShaderPrecisionFormat(shaderType, precisionType);
 * 
 * shaderType
 *      Either a gl.FRAGMENT_SHADER or a gl.VERTEX_SHADER.
 *
 * precisionType
 *      A precision type value. Either gl.LOW_FLOAT, 
 *      gl.MEDIUM_FLOAT, gl.HIGH_FLOAT, gl.LOW_INT, 
 *      gl.MEDIUM_INT, or gl.HIGH_INT.
 * 
 * Return value
 *      A WebGLShaderPrecisionFormat object or null, if an error occurs.
 * 
 * Exceptions
 *      gl.INVALID_ENUM if the shader or precision types aren't recognized.
 *      gl.INVALID_OPERATION if the shader compiler isn't supported.
 */
void render_context_3d::get_shader_precision_format(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto type = (uint32_t)_0.to_int32();
    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;
    auto precision = (uint32_t)_1.to_int32();

    float min_ = 0, max_ = 0, precision_ = 0;
    if (DWL_FRAGMENT_SHADER == type) {
        if (DWL_LOW_FLOAT == precision) {
            min_       = render_attitude_->fs_l_f_.range_min_;
            max_       = render_attitude_->fs_l_f_.range_max_;
            precision_ = render_attitude_->fs_l_f_.precision_;
        } else if (DWL_MEDIUM_FLOAT == precision) {
            min_       = render_attitude_->fs_m_f_.range_min_;
            max_       = render_attitude_->fs_m_f_.range_max_;
            precision_ = render_attitude_->fs_m_f_.precision_;
        } else if (DWL_HIGH_FLOAT == precision) {
            min_       = render_attitude_->fs_h_f_.range_min_;
            max_       = render_attitude_->fs_h_f_.range_max_;
            precision_ = render_attitude_->fs_h_f_.precision_;
        } else if (DWL_LOW_INT == precision) {
            min_       = render_attitude_->fs_l_i_.range_min_;
            max_       = render_attitude_->fs_l_i_.range_max_;
            precision_ = render_attitude_->fs_l_i_.precision_;
        } else if (DWL_MEDIUM_INT == precision) {
            min_       = render_attitude_->fs_m_i_.range_min_;
            max_       = render_attitude_->fs_m_i_.range_max_;
            precision_ = render_attitude_->fs_m_i_.precision_;
        } else if (DWL_HIGH_INT == precision) {
            min_       = render_attitude_->fs_h_i_.range_min_;
            max_       = render_attitude_->fs_h_i_.range_max_;
            precision_ = render_attitude_->fs_h_i_.precision_;
        } else {
            return;
        }
    } else if (DWL_VERTEX_SHADER == type) {
        if (DWL_LOW_FLOAT == precision) {
            min_       = render_attitude_->vs_l_f_.range_min_;
            max_       = render_attitude_->vs_l_f_.range_max_;
            precision_ = render_attitude_->vs_l_f_.precision_;
        } else if (DWL_MEDIUM_FLOAT == precision) {
            min_       = render_attitude_->vs_m_f_.range_min_;
            max_       = render_attitude_->vs_m_f_.range_max_;
            precision_ = render_attitude_->vs_m_f_.precision_;
        } else if (DWL_HIGH_FLOAT == precision) {
            min_       = render_attitude_->vs_h_f_.range_min_;
            max_       = render_attitude_->vs_h_f_.range_max_;
            precision_ = render_attitude_->vs_h_f_.precision_;
        } else if (DWL_LOW_INT == precision) {
            min_       = render_attitude_->vs_l_i_.range_min_;
            max_       = render_attitude_->vs_l_i_.range_max_;
            precision_ = render_attitude_->vs_l_i_.precision_;
        } else if (DWL_MEDIUM_INT == precision) {
            min_       = render_attitude_->vs_m_i_.range_min_;
            max_       = render_attitude_->vs_m_i_.range_max_;
            precision_ = render_attitude_->vs_m_i_.precision_;
        } else if (DWL_HIGH_INT == precision) {
            min_       = render_attitude_->vs_h_i_.range_min_;
            max_       = render_attitude_->vs_h_i_.range_max_;
            precision_ = render_attitude_->vs_h_i_.precision_;
        } else {
            return;
        }
    } else {
        return;
    }
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    auto js_context = _parameter.get_context();
    auto _obj = thread_related->cls_render_3d_shader_precison_
        .create_new_instance(js_context);
    render_context_3d_shader_precison* _instance = nullptr;
    _obj.hold_native_data(i_runtime_container<
        render_context_3d_shader_precison>::create(&_instance));
    assert(nullptr != _instance);
    _instance->min_       = min_;
    _instance->max_       = max_;
    _instance->precision_ = precision_;
    _parameter.set_return((js_value)_obj);
}