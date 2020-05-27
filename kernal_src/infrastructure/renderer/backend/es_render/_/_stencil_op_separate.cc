
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::stencil_op_separate(
    uint32_t face, uint32_t fail, uint32_t zfail, uint32_t zpass) {
    ::glStencilOpSeparate((GLenum)face, 
        (GLenum)fail, (GLenum)zfail, (GLenum)zpass);
}