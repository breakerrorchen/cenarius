
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::generate_mipmap(uint32_t target) {
    ::glGenerateMipmap((GLenum)target);
}