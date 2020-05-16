
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::clear_color(float r, float g, float b, float a) {
    ::glClearColor((GLfloat)r, (GLfloat)g, (GLfloat)b, (GLfloat)a);
}