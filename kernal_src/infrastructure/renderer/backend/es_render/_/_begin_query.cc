
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::begin_query(uint32_t target, uint32_t _id) {
    ::glBeginQuery((GLenum)target, (GLuint)_id);
}