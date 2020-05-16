
#include "common/logger.h"
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

void content::on_pause() {
	__log_error("%s %d %x", __FILE__, __LINE__, this);
	assert(related_thread_);
	auto& on_pause = related_thread_->on_pause_;
	if (!on_pause.is_useable()) {
		return;
	}
	js_release_scope release_scope(on_pause);
	auto callback = (js_value)on_pause;
	callback.function_invoke(
    	nullptr, nullptr, 0, nullptr);
}