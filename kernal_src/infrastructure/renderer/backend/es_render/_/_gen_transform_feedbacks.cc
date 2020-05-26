
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::gen_transform_feedbacks(int32_t n, uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> feedbacks; feedbacks.resize(n);
            ::glGenTransformFeedbacks((GLsizei)n, &(feedbacks[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = feedbacks[i];
            }
        } else {
            GLuint feedbacks[32] = { 0 };
            ::glGenTransformFeedbacks((GLsizei)n, &(feedbacks[0]));
            for (int32_t i = 0; i < n; ++i) {
                arr[i] = feedbacks[i];
            }
        }
    }
}