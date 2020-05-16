
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::stencil_mask_separate(
    uint32_t face, uint32_t mask) {
    ::glStencilMaskSeparate((GLenum)face, (GLuint)mask);
}