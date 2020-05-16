
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::stencil_mask(uint32_t mask) {
    ::glStencilMask((GLuint)mask);
}