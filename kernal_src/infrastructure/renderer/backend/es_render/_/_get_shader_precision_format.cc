
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_shader_precision_format(
    uint32_t shader_type, uint32_t precision_type,
    int32_t* range, int32_t* precision) {
    GLint _range[2] = {0, 0}; GLint value = 0;
    ::glGetShaderPrecisionFormat((GLenum)shader_type,
        (GLenum)precision_type, _range, &value);
    range[0] = _range[0]; range[1] = range[1];
    if (precision) { *precision = (int32_t)value; }
}