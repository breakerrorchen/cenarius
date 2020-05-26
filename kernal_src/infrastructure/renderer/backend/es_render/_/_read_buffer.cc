
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::read_buffer(uint32_t src) {
    ::glReadBuffer((GLenum)src);
}