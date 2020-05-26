
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::end_query(uint32_t target) {
    ::glEndQuery((GLenum)target);
}