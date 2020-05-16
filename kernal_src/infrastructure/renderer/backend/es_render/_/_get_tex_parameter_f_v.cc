
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_tex_parameter_f_v(uint32_t target, uint32_t pname, float* v) {
    GLfloat value = 0;
    ::glGetTexParameterfv((GLenum)target, (GLenum)pname, &value);
    if (v) { *v = (float)value; }
}