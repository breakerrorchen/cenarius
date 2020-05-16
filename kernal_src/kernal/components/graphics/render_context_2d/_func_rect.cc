
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::rect(js_parameter& parameter) {
    assert(transmitter_ && related_);
    if (parameter.get_argument_count() != 4) return;
    auto x = parameter.get_argument_at(0).to_float();
    auto y = parameter.get_argument_at(1).to_float();
    auto w = parameter.get_argument_at(2).to_float();
    auto h = parameter.get_argument_at(3).to_float();
    if (w == 0 || h == 0) return;
    if (w < 0) { x += w; w = -w; }
    if (h < 0) { y += h; h = -h; }
    auto rect = SkRect::MakeXYWH(x, y, w, h);
    auto& martix = related_->get_lt_context().current_matrix_;
    SkPath path;
    path.addRect(rect); path.transform(martix);
    related_->lt_current_path_.addPath(path);
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkPath path_;
        void run(barrel_buffer*) {
            assert(related_);
            related_->rt_current_path_.addPath(path_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->related_ = related_.get() ; 
        task->path_    = std::move(path);
    }
}