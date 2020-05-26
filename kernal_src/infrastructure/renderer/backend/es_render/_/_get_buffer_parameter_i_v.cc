
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_buffer_parameter_i_v(
    uint32_t target, uint32_t value, int32_t* data) {
    if (nullptr == data) return;
    GLint ret_value = 0;
    ::glGetBufferParameteriv((GLenum)target,
        (GLenum)value, &ret_value);
    *data = (int32_t)ret_value;
}