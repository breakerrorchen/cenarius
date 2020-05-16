
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/runnable/committer.h"
#include "kernal/cc/care_info.h"
#include "kernal/cc/care_render_connector.h"
#include "kernal/scheduler/reactor_timer.h"

namespace cenarius { namespace kernal { namespace isolate {
using namespace cc;
using namespace asynchronous;
using namespace scheduler;
class content_context final {
public:
	// 用来完成线程通讯的消息队列
    std::shared_ptr<runnable_committer> committer_;
    // 定时器
    std::shared_ptr<reactor_timer> reactor_timer_;
    // info
    std::shared_ptr<care_info> care_info_;
    // render connector
    std::shared_ptr<care_render_connector> render_connector_;
    // 和渲染线程通讯的高速command buffer
    std::shared_ptr<barrel_buffer_center> buffer_center_;
};


}}}
