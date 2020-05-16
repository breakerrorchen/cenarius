
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::blend_color(float r, float g, float b, float a) {
    ::glBlendColor((GLfloat)r, (GLfloat)g, (GLfloat)b, (GLfloat)a);
}