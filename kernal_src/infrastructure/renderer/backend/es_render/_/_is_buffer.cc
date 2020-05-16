
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_buffer(uint32_t buffer, bool* ret) {
    if (ret) {
        *ret = ::glIsBuffer((GLuint)buffer);
    }
}