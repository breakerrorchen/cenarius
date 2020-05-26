
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_vertx_array(uint32_t array) {
    ::glBindVertexArray((GLuint)array);
}