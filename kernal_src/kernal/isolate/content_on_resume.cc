
#include "common/logger.h"
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

void content::on_resum() {
	__log_error("%s %d %x", __FILE__, __LINE__, this);
    assert(related_thread_);
    auto& on_resume = related_thread_->on_resume_;
    if (!on_resume.is_useable()) {
    	return;
    }
    js_release_scope release_scope(on_resume);
    auto callback = (js_value)on_resume;
    callback.function_invoke(
    	nullptr, nullptr, 0, nullptr);
}