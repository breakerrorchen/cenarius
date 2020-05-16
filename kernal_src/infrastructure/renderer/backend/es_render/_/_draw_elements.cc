
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::draw_elements(
    uint32_t mode, int32_t count, uint32_t t, const void* indices) {
    ::glDrawElements((GLenum)mode, (GLsizei)count, (GLenum)t, indices);
}