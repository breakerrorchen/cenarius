
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::sample_parameter_f(
    uint32_t sampler, uint32_t pname, float param) {
    ::glSamplerParameterf(
        (GLuint)sampler, (GLenum)pname, (GLfloat)param);
}