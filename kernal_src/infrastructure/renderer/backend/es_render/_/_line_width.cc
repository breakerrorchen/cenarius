
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::line_width(float width) {
    ::glLineWidth((GLfloat)width);
}