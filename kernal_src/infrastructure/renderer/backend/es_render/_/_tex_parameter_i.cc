
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::tex_parameter_i(
    uint32_t target, uint32_t pname, int32_t param) {
    ::glTexParameteri((GLenum)target, (GLenum)pname, (GLint)param);
}