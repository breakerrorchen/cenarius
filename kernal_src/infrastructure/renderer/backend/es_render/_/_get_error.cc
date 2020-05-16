
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_error(uint32_t* ret) {
    if (ret) {
        *ret = (uint32_t)::glGetError();
    }
}