
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_query(uint32_t _id, bool* ret) {
    if (ret) {
        *ret = ::glIsQuery((GLuint)_id);
    }
}