
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::save(js_parameter& parameter) {
    assert(transmitter_ && related_);
    auto& _stack = related_->lt_context_stack_;
    _stack.emplace(_stack.top());
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        void run(barrel_buffer*) {
            assert(related_);
            auto& _stack = related_->rt_context_stack_;
            _stack.emplace(_stack.top());
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->related_ = related_.get();
    }
}