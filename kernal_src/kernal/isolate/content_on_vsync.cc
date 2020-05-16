
#include "common/logger.h"
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

/**
 * 接收到系统的vsync信号，通知全局收到信号
 * */
void content::on_vsync() {
    assert(related_thread_);
    assert(related_thread_->anima_timer_);
    related_thread_->anima_timer_->call();

    // 全局广播vsync
    event_observer::dispatch(
    	(uint32_t)event_observer_id::_vsync_, nullptr);
}