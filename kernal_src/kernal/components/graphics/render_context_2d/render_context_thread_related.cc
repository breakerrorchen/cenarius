
#include "render_context_thread_related.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;

render_context_2d_context_local& 
render_context_thread_related::get_lt_context() {
    assert(!lt_context_stack_.empty());
    return lt_context_stack_.top();
}

render_context_2d_context&
render_context_thread_related::get_rt_context() {
    assert(!rt_context_stack_.empty());
    return rt_context_stack_.top();
}