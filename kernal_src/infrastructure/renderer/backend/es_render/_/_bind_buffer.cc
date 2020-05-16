
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_buffer(uint32_t target, uint32_t buffer) {
    ::glBindBuffer((GLenum)(target), (GLuint)buffer);
}