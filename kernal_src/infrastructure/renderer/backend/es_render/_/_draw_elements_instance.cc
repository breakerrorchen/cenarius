
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::draw_elements_instance(
    uint32_t mode, int32_t count, uint32_t type, 
    const void* indices, int32_t primcount) {
    ::glDrawElementsInstanced((GLenum)mode,
        (GLsizei)count, (GLenum)type, indices,
        (GLsizei)primcount);
}