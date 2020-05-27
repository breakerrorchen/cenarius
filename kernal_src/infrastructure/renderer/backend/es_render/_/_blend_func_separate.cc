
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::blend_func_separate(
    uint32_t s_rgb, uint32_t d_rgb, uint32_t s_a, uint32_t d_a) {
    ::glBlendFuncSeparate(
        (GLenum)s_rgb, (GLenum)d_rgb, (GLenum)s_a, (GLenum)d_a);
}