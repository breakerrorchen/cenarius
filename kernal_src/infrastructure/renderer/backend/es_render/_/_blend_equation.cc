
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::blend_equation(uint32_t mode) {
    ::glBlendEquation((GLenum)mode);
}