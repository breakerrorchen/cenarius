
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void timer::anima_request(js_parameter& parameter) {
    if (parameter.get_argument_count() == 0) return;
    auto value = parameter.get_argument_at(0);
    if (!value.is_function()) return;
    auto _context = parameter.get_context();
    js_value_holder value_holder(value);
    auto thread_related = related_thread::obtain();
    assert(thread_related && thread_related->anima_timer_);
    auto index = thread_related->anima_timer_->add(
        [v {std::move(value_holder)}](uint32_t t) {
        js_release_scope _release_scope(v);
        auto _context = v.get_context();
        auto func = (js_value)v; assert(func.is_useable());
        auto argument = js_value::create(_context, (int32_t)t);
        func.function_invoke(nullptr, &argument, 1, nullptr);
    });
    parameter.set_return(
        js_value::create(_context, (int32_t)index));
}

void timer::anima_cancel(js_parameter& parameter) {
    if (parameter.get_argument_count() == 0) return;
    auto value = parameter.get_argument_at(0);
    if (!value.is_number()) return;
    auto thread_related = related_thread::obtain();
    assert(thread_related->anima_timer_);
    thread_related->anima_timer_->cancel(value.to_int32());
}