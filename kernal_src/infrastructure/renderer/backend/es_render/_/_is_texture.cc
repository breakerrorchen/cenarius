
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_texture(uint32_t index, bool* ret) {
    if (ret) {
        *ret = ::glIsTexture((GLuint)index);
    }
}