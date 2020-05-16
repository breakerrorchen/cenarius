
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_active_attrib(
    uint32_t program, uint32_t index, int32_t buf_size,
    int32_t* length, int32_t* size, uint32_t* t, char* name) {
    GLsizei rt_length = 0; GLint rt_size = 0; GLenum rt_t;
    ::glGetActiveAttrib((GLuint)program, (GLuint)index,
        (GLsizei)buf_size, &rt_length, &rt_size, &rt_t, name);
    if (size)   { *size   = (int32_t) rt_size;   }
    if (t)      { *t      = (uint32_t)rt_t;      }
    if (length) { *length = (uint32_t)rt_length; }
}