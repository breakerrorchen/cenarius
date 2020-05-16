
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas_render_2d.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
using namespace infrastructure;
using namespace renderer;
class render_context_2d_gradient {
public:
    virtual ~render_context_2d_gradient() = default;
public:
    bool build_linear(float, float, float, float);
    bool build_radial(
        float, float, float, float, float, float);
    bool add_color_stop(uint32_t, float);
    void add_color_stop(js_parameter&);
    
public:
    sk_sp<SkShader> get_shader();
private:
    sk_sp<SkShader> shader_;
    enum __class__ {
        __nil__, __linear__, __radial__,
    };
    __class__ class_ = __nil__;
    float init_arguments_[6] = {0};
    std::vector<uint32_t> stop_colors_;
    std::vector<float>    stop_colors_offsets_;

public:
    static void outlet(js_context&, js_object&);
};


}}}