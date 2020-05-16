
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_enabled(uint32_t cap, bool* ret) {
    if (ret) {
        *ret = ::glIsEnabled((GLenum)cap);
    }
}