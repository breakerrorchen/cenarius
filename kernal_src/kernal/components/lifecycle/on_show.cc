
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace isolate;
using namespace components;

void lifecycle::on_show(js_parameter& parameter) {
	auto thread_related = related_thread::obtain();
	assert(thread_related);
    if (parameter.get_argument_count() == 0) {
    	thread_related->on_show_.reset();
	} else {
		auto func = parameter.get_argument_at(0);
	    if (func.is_function()) {
	    	thread_related->on_show_ = func;
	    } else {
	    	thread_related->on_show_.reset();
	    }
	}
}