
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::disable(uint32_t cap) {
    ::glDisable((GLenum)cap);
}