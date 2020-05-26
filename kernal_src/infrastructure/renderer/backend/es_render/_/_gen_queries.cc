
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::gen_queries(int32_t n, uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> queries; queries.resize(n);
            ::glGenQueries((GLsizei)n, &(queries[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = queries[i];
            }
        } else {
            GLuint queries[32] = { 0 };
            ::glGenQueries((GLsizei)n, &(queries[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = queries[i];
            }
        }
    }
}