
#include "render_context_local.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
using namespace components;

render_context_2d_context_local::render_context_2d_context_local(
    const render_context_2d_context_local& that) {
    operator=(that);
}

render_context_2d_context_local& 
render_context_2d_context_local::operator=(
    const render_context_2d_context_local& that) {
    if (&that != this) {
        aa_ = that.aa_;
        current_matrix_ = that.current_matrix_;
        typeface_size_ = that.typeface_size_;
        typeface_ = that.typeface_;
    }
    return *this;
}