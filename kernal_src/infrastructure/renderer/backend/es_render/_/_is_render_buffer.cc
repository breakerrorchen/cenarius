
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_render_buffer(uint32_t index, bool* ret) {
    if (ret) {
        *ret = ::glIsRenderbuffer((GLuint)index);
    }
}