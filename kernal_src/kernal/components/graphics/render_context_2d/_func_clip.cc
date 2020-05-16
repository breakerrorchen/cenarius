
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::clip(js_parameter& parameter) {
    const static char* _evenodd = "evenodd";
	assert(transmitter_ && related_);
    auto fill_type = SkPathFillType::kWinding;
    if (parameter.get_argument_count() > 0) {
        auto str = parameter.get_argument_at(0).to_string();
        if (str == _evenodd) {
            fill_type = SkPathFillType::kEvenOdd;
        }
    }
    struct __task__ {
        puppet_container<canvas_render_2d>* context_ = nullptr;
		render_context_thread_related* related_ = nullptr;
        SkPathFillType fill_type_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
			auto canvas = context_->data_->get();
			assert(canvas && related_);
            auto& path = related_->rt_current_path_;
            auto old_fill = path.getFillType();
            path.setFillType(fill_type_);
            canvas->clipPath(path, true);
            path.setFillType(old_fill);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->context_   = raw_context_.get();
        task->fill_type_ = fill_type;
        task->related_   = related_.get();
    }
    transmitter_->force_commit();
}