
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::stencil_op(
    uint32_t fail, uint32_t zfail, uint32_t zpass) {
    ::glStencilOp((GLenum)fail, (GLenum)zfail, (GLenum)zpass);
}