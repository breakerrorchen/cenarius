
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_vertex_attrib_pointer_v(
    uint32_t index, uint32_t pname, void** pointer) {
    if (nullptr != pointer) {
        ::glGetVertexAttribPointerv((GLuint)index, (GLenum)pname, pointer);
    }
}