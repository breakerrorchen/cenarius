
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_queries(int32_t n, const uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> queries; queries.resize(n);
            for (int32_t i = 0; i < n; ++i) {
                queries[i] = arr[i];
            }
            ::glDeleteQueries((GLsizei)n, &(queries[0]));
        } else {
            GLuint queries[32];
            for (int32_t i = 0; i < n; ++i) {
                queries[i] = arr[i];
            }
            ::glDeleteQueries((GLsizei)n, &(queries[0]));
        }
    }
}