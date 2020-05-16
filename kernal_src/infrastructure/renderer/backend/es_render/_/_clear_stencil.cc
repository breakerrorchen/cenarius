
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::clear_stencil(int32_t v) {
    ::glClearStencil((GLint)v);
}