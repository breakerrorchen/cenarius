
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::front_face(uint32_t mode) {
    ::glFrontFace((GLenum)mode);
}