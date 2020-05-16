
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::depth_func(uint32_t func) {
    ::glDepthFunc((GLenum)func);
}