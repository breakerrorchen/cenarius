
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::stencil_func_separate(
    uint32_t face, uint32_t func, int32_t ref, uint32_t mask) {
    ::glStencilFuncSeparate(
        (GLenum)face, (GLenum)func, (GLint)ref, (GLuint)mask);
}