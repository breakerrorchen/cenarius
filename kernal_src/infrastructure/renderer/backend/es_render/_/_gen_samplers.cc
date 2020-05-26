
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::gen_samplers(int32_t n, uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> samplers; samplers.resize(n);
            ::glGenSamplers((GLsizei)n, &(samplers[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = samplers[i];
            }
        } else {
            GLuint samplers[32] = { 0 };
            ::glGenSamplers((GLsizei)n, &(samplers[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = samplers[i];
            }
        }
    }
}