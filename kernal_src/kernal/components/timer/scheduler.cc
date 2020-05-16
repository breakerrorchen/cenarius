
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void __internal_set__(js_parameter& parameter, bool loop) {
	auto parameter_len = parameter.get_argument_count();
	if (parameter_len < 2) { return; }
	
	auto func = parameter.get_argument_at(0);
	auto time = parameter.get_argument_at(1);
	if (!func.is_function() || !time.is_number()) {
		return;
	}
	auto thread_related = related_thread::obtain();
	assert(thread_related && thread_related->reactor_timer_);
	auto _context = parameter.get_context();
	js_value_holder callback = func;
	auto timeout = time.to_int32();
	std::vector<js_value_holder> parameters;
	for (int i = 2; i < parameter_len; ++i) {
		parameters.emplace_back(
			parameter.get_argument_at(i));
	}
	auto index = thread_related->reactor_timer_->add(
		timeout, [func{std::move(callback)}, 
			parameters{std::move(parameters)}]() {
			js_release_scope _release_scope(func);
			auto _context = func.get_context();
			auto callback = (js_value)func;
			assert(callback.is_useable());
			auto parameters_len = parameters.size();
			if (parameters_len > 0) {
				if (parameters_len <= 16) {
					js_value vs[16];
					for (size_t i = 0; i < parameters_len; ++i) {
						vs[i] = (js_value)parameters[i];
					}
					callback.function_invoke(nullptr, 
						&(vs[0]), parameters_len, nullptr);
				} else {
					std::vector<js_value> vs;
					vs.reserve(parameters.size());
					for (size_t i = 0; i < parameters_len; ++i) {
						vs.emplace_back((js_value)parameters[i]);
					}
					callback.function_invoke(nullptr, 
						&(vs[0]), parameters_len, nullptr);
				}
			} else {
				callback.function_invoke(
					nullptr, nullptr, 1, nullptr);
			}
		}, loop);
	parameter.set_return(
        js_value::create(_context, (int32_t)index));
}

void __internal_clear__(js_parameter& parameter) {
	auto parameter_len = parameter.get_argument_count();
	if (parameter_len < 1) {
		return;
	}
	auto v = parameter.get_argument_at(0);
	if (!v.is_number()) {
		return;
	}
	auto idx = (uint32_t)v.to_int32();
	auto thread_related = related_thread::obtain();
	assert(thread_related && thread_related->reactor_timer_);
	thread_related->reactor_timer_->remove(idx);
}

void timer::set_interval(js_parameter& parameter) {
    __internal_set__(parameter, true);
}

void timer::clear_interval(js_parameter& parameter) {
	__internal_clear__(parameter);
}

void timer::set_timeout(js_parameter& parameter) {
   	__internal_set__(parameter, false);
}

void timer::clear_timeout(js_parameter& parameter) {
	__internal_clear__(parameter);
}