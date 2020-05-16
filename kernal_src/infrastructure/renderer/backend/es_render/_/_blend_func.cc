
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::blend_func(uint32_t s, uint32_t d) {
    ::glBlendFunc((GLenum)s, (GLenum)d);
}