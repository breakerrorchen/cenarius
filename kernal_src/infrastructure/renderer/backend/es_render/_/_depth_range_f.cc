
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::depth_range_f(float near, float far) {
    ::glDepthRangef((GLclampf)near, (GLclampf)far);
}