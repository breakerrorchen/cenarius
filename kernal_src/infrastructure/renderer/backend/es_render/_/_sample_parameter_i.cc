
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::sample_parameter_i(
    uint32_t sampler, uint32_t pname, int32_t param) {
    ::glSamplerParameteri(
        (GLuint)sampler, (GLenum)pname, (GLint)param);
}