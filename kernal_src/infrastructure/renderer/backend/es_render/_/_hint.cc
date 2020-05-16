
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::hint(uint32_t target, uint32_t mode) {
    ::glHint((GLenum)target, (GLenum)mode);
}