
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::pixel_store_i(uint32_t pname, int32_t param) {
    ::glPixelStorei((GLenum)pname, (GLint)param);
}