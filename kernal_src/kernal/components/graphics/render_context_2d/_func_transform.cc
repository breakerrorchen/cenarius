
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::transform(js_parameter& parameter) {
    assert(transmitter_ && related_);
    if (parameter.get_argument_count() != 6) return;
    auto a = parameter.get_argument_at(0).to_float();
    auto b = parameter.get_argument_at(1).to_float();
    auto c = parameter.get_argument_at(2).to_float();
    auto d = parameter.get_argument_at(3).to_float();
    auto e = parameter.get_argument_at(4).to_float();
    auto f = parameter.get_argument_at(5).to_float();
    auto m = SkMatrix::MakeAll(a, c, e, b, d, f, 0, 0, 1);
    related_->get_lt_context().current_matrix_.preConcat(m);
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkMatrix matrix_;
        void run(barrel_buffer*) {
            assert(related_);
            auto& render_context = related_->get_rt_context();
            render_context.current_matrix_.preConcat(matrix_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->matrix_ = m; task->related_ = related_.get();
    }
}