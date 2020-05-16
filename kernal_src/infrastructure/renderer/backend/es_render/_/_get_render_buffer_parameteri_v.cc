
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_render_buffer_parameteri_v(
    uint32_t target, uint32_t pname, int32_t* params) {
    GLint value = 0;
    ::glGetRenderbufferParameteriv((GLenum)target, (GLenum)pname, &value);
    if (params) { *params = (int32_t)value; }
}