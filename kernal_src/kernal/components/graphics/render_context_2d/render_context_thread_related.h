
#pragma once
#include "common/base_header_inct.h"
#include "render_context.h"
#include "render_context_local.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
class render_context_thread_related {
public:
    // 只能在逻辑线程中使用
    SkPath lt_current_path_;
    std::stack<render_context_2d_context_local> lt_context_stack_;
    render_context_2d_context_local& get_lt_context();

public:
    // 只能在渲染线程中使用
    SkPaint rt_provisional_paint_;
	SkPath rt_current_path_;
	std::stack<render_context_2d_context> rt_context_stack_;
    render_context_2d_context& get_rt_context();
};


}}}