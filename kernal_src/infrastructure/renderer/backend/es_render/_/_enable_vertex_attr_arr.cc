
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::enable_vertex_attr_arr(uint32_t index) {
    ::glEnableVertexAttribArray((GLuint)index);
}