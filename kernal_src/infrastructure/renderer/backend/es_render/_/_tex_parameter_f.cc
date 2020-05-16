
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::tex_parameter_f(
    uint32_t target, uint32_t pname, float param) {
    ::glTexParameterf((GLenum)target, (GLenum)pname, param);
}