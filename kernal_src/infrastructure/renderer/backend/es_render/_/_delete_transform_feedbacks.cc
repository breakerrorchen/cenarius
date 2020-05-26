
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_transform_feedbacks(int32_t n, const uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> feedbacks; feedbacks.resize(n);
            for (int32_t i = 0; i < n; ++i) {
                feedbacks[i] = arr[i];
            }
            ::glDeleteTransformFeedbacks((GLsizei)n, &(feedbacks[0]));
        } else {
            GLuint feedbacks[32];
            for (int32_t i = 0; i < n; ++i) {
                feedbacks[i] = arr[i];
            }
            ::glDeleteTransformFeedbacks((GLsizei)n, &(feedbacks[0]));
        }
    }
}