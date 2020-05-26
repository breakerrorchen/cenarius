
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_buffer_pointer_v(
    uint32_t target, uint32_t pname, void** params) {
    ::glGetBufferPointerv(
        (GLenum)target, (GLenum)pname, params);
}