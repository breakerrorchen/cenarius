
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_sampler_parameter_f_v(
    uint32_t sampler, uint32_t pname, float* params) {
    if (nullptr == params) return;
    GLfloat ret_params = 0;
    ::glGetSamplerParameterfv(
        (GLuint)sampler, (GLenum)pname, &ret_params);
    *params = (float)ret_params;
}