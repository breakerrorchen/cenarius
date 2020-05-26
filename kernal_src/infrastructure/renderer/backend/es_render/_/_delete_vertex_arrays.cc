
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_vertex_arrays(int32_t n, const uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> arrays; arrays.resize(n);
            for (int32_t i = 0; i < n; ++i) {
                arrays[i] = arr[i];
            }
            ::glDeleteVertexArrays((GLsizei)n, &(arrays[0]));
        } else {
            GLuint arrays[32];
            for (int32_t i = 0; i < n; ++i) {
                arrays[i] = arr[i];
            }
            ::glDeleteVertexArrays((GLsizei)n, &(arrays[0]));
        }
    }
}