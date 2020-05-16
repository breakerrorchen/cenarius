
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::polygon_offset(float factor, float units) {
    ::glPolygonOffset((GLfloat)factor, (GLfloat)units);
}