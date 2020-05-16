
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::stencil_func(
    uint32_t func, int32_t ref, uint32_t mask) {
    ::glStencilFunc((GLenum)func, (GLint)ref, (GLuint)mask);
}