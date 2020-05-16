
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_vertex_attrib_i_v(
    uint32_t index, uint32_t pname, int32_t* v) {
    if (nullptr == v) return;

    GLenum i = (GLenum)pname;
    if (i == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING  ||
        i == GL_VERTEX_ATTRIB_ARRAY_ENABLED         ||
        i == GL_VERTEX_ATTRIB_ARRAY_NORMALIZED      ||
        i == GL_VERTEX_ATTRIB_ARRAY_SIZE            ||
        i == GL_VERTEX_ATTRIB_ARRAY_STRIDE          ||
        i == GL_VERTEX_ATTRIB_ARRAY_TYPE) {
        GLint ret = 0;
        ::glGetVertexAttribiv((GLuint)index, i, &ret);
        if (v) { *v = (int32_t)ret; }
    } else if (i == GL_CURRENT_VERTEX_ATTRIB) {
        GLfloat param[4] = {0, 0, 0, 0};
        ::glGetVertexAttribfv((GLuint)index, i, param);
        for (int ii = 0; ii < 4; ++ii) {
            v[ii] = (int32_t)param[ii];
        }
    }
}