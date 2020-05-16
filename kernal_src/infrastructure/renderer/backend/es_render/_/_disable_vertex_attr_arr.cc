
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::disable_vertex_attr_arr(uint32_t index) {
    ::glDisableVertexAttribArray((GLuint)index);
}