
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_shader(uint32_t index, bool* ret) {
    if (ret) {
        *ret = ::glIsShader((GLuint)index);
    }
}