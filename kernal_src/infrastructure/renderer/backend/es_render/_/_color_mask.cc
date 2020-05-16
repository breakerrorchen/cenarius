
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::color_mask(bool r, bool g, bool b, bool a) {
    ::glColorMask((GLboolean)r, 
        (GLboolean)g, (GLboolean)b, (GLboolean)a);
}