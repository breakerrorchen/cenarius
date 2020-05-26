
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::gen_vertex_arrays(int32_t n, uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> arrays; arrays.resize(n);
            ::glGenVertexArrays((GLsizei)n, &(arrays[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = arrays[i];
            }
        } else {
            GLuint arrays[32] = { 0 };
            ::glGenVertexArrays((GLsizei)n, &(arrays[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = arrays[i];
            }
        }
    }
}