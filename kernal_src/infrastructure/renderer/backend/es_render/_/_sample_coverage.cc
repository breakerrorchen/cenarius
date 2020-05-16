
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::sample_coverage(float value, bool invert) {
    ::glSampleCoverage((GLclampf)value, (GLboolean)invert);
}