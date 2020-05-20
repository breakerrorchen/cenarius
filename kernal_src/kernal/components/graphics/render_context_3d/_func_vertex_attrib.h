
#include "_.h"
#include "_buffer_extract.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

#define render_context_3d_vertex_attrib_intend_code(_parameter)     \
    if (_parameter.get_argument_count() == 0) return;               \
    auto _parameter_0 = _parameter.get_argument_at(0);              \
    if (!_parameter_0.is_number()) return;                          \
    auto index =  (uint32_t)_parameter_0.to_int32();                \
    if (index >= 64 ||                                              \ 
        render_attitude_->max_vertex_attribs_ <= index) {           \
        return;                                                     \
    }                                                               \
    float* attrib_data = context_cache_.attrib_pointer_[index].data_;
    
