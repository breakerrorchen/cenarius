
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_vertex_attrib_i_u_i_v(
    uint32_t index, uint32_t pname, uint32_t* v) {
    if (nullptr == v) return;

    GLenum i = (GLenum)pname;
    if (i == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING  ||
        i == GL_VERTEX_ATTRIB_ARRAY_ENABLED         ||
        i == GL_VERTEX_ATTRIB_ARRAY_NORMALIZED      ||
        i == GL_VERTEX_ATTRIB_ARRAY_SIZE            ||
        i == GL_VERTEX_ATTRIB_ARRAY_STRIDE          ||
        i == GL_VERTEX_ATTRIB_ARRAY_TYPE            ||
        i == GL_VERTEX_ATTRIB_ARRAY_INTEGER         ||
        i == GL_VERTEX_ATTRIB_ARRAY_DIVISOR) {
        GLint ret = 0;
        ::glGetVertexAttribiv((GLuint)index, i, &ret);
        if (v) { *v = (uint32_t)ret; }
    } else if (i == GL_CURRENT_VERTEX_ATTRIB) {
        GLfloat param[4] = {0, 0, 0, 0};
        ::glGetVertexAttribfv((GLuint)index, i, param);
        for (int ii = 0; ii < 4; ++ii) {
            v[ii] = (uint32_t)param[ii];
        }
    }
}