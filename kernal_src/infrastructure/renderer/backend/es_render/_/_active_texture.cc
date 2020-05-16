
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::active_texture(uint32_t v) {
    ::glActiveTexture((GLenum)v);
}