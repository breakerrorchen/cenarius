
#include "common/logger.h"
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

void content::on_destory() {
__log_error("%s %d %x", __FILE__, __LINE__, this);
	assert(related_thread_);
    auto& on_exit = related_thread_->on_exit_;
    if (!on_exit.is_useable()) {
    	return;
    }
    js_release_scope release_scope(on_exit);
    auto callback = (js_value)on_exit;
    callback.function_invoke(
    	nullptr, nullptr, 0, nullptr);

    // 卸载全局的通知服务
	event_observer::dispose();
}