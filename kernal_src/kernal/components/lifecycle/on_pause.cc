
#include "common/logger.h"
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace isolate;
using namespace components;

void lifecycle::on_pause(js_parameter& parameter) {
__log_error("%s %d", __FILE__, __LINE__);
	auto thread_related = related_thread::obtain();
	assert(thread_related);
	if (parameter.get_argument_count() == 0) {
    	thread_related->on_pause_.reset();
	} else {
		auto value = parameter.get_argument_at(0);
	    if (value.is_function()) {
	    	thread_related->on_pause_ = value;
	    } else {
	    	thread_related->on_pause_.reset();
	    }
	}
}