
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_tex_parameter_i_v(
    uint32_t target, uint32_t pname, int32_t* v) {
    GLint value = 0;
    ::glGetTexParameteriv((GLenum)target, (GLenum)pname, &value);
    if (v) { *v = (int32_t)value; }
}