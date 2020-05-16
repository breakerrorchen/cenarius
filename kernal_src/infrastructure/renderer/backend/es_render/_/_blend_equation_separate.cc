
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::blend_equation_separate(uint32_t rgb, uint32_t a) {
    ::glBlendEquationSeparate((GLenum)rgb, (GLenum)a);
}