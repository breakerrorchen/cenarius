
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

/**
 * 启动后初始化解释器和设置global对象
 * JSCode中全局变量会挂接到global对象上面
 * */
void content::on_create() {
	// 安装全局的通知服务
	event_observer::setup_and_set_current();
	// 启动js虚拟机
    js_release_scope __release_scope__(vm_);
    auto context = actuator_.get_context();
    context.on_exception_ = 
        [](std::string& info, int line, int column) {
        __log_error("JSE: %s %d %d", info.c_str(), line, column);
    };
    auto global_object = context.get_global_object();
    global_object["global"] = global_object;
    extension_ = extension_embeder::create(actuator_);
    extension_->build(global_object);
}