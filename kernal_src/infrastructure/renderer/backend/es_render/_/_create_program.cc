
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::create_program(uint32_t* ret) {
    if (nullptr != ret) {
        *ret = (uint32_t)::glCreateProgram();
    }
}