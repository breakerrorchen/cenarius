
#include "../render_context_3d_program/_.h"
#include "../render_context_3d_uniform_location/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

#define render_context_3d_uniform_intend_code(_parameter)           \
    auto current_program = context_cache_.raw_current_program_;     \
    if (!current_program) return;                                   \
    if (_parameter.get_argument_count() == 0) return;               \
    auto location = _parameter.get_argument_at(0);                  \
    auto raw_location = js_class_extract::extract<                  \
        render_context_3d_uniform_location>(location);              \
    if (nullptr == raw_location) return;                            \
    auto& shader_env = current_program->reflection_;                \
    auto local_uniform = shader_env                                 \
        .find_uniform(raw_location->location_);                     \
    if (nullptr == local_uniform) return;                           \
    int32_t location_index = raw_location->location_;