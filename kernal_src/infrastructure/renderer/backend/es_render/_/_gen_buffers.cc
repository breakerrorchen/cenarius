
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::gen_buffers(int32_t n, uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> buffers; buffers.resize(n);
            ::glGenBuffers((GLsizei)n, &(buffers[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = buffers[i];
            }
        } else {
            GLuint raw_buffer[32] = { 0 };
            ::glGenBuffers((GLsizei)n, &(raw_buffer[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = raw_buffer[i];
            }
        }
    }
}