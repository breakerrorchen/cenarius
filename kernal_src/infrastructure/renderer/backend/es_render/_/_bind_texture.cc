
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_texture(uint32_t target, uint32_t texture) {
    ::glBindTexture((GLenum)target, (GLuint)texture);
}