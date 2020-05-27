
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::draw_arrays(
    uint32_t mode, int32_t first, int32_t count) {
    ::glDrawArrays((GLenum)mode, (GLint)first, (GLsizei)count);
}