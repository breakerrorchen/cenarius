
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::set_line_dash(js_parameter& _parameter) {
	assert(transmitter_ && related_);
	if (_parameter.get_argument_count() == 0) return;
    auto v = _parameter[0]; if (!v.is_array()) return;
    auto& context = related_->lt_context_stack_.top();
    context.line_dash_ = v;
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        std::vector<float> offset_;
        void run(barrel_buffer*) {
            assert(related_);
            assert(!related_->rt_context_stack_.empty());
            auto& context = related_->rt_context_stack_.top();
            context.line_dash_.clear();
            context.line_dash_.reserve(offset_.size());
            for (auto& v: offset_) {
                context.line_dash_.emplace_back(v);
            }
            context.dash_path_effect_ = nullptr;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        auto size = v.value_arr_size();
        task->offset_.reserve(size);
        for (int i = 0; i < size; ++i) {
            auto item = v.value_arr_at(i);
            task->offset_.emplace_back(item.to_float());
        }
        task->related_ = related_.get();
    }
}