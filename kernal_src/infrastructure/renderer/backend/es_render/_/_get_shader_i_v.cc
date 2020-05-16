
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_shader_i_v(
    uint32_t shader, uint32_t pname, int32_t* v) {
    if (nullptr != v) {
        GLint params = 0;
        ::glGetShaderiv((GLuint)shader, (GLenum)pname, &params);
        *v = (int32_t)params;
    }
}