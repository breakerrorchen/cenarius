
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/syncer/syncer_condition.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/runnable/committer.h"
#include "kernal/asynchronous/syncer/syncer_condition.h"
#include "kernal/scheduler/reactor_timer.h"
#include "kernal/isolate/content_context.h"
#include "kernal/isolate/content.h"
#include "care.h"
#include "care_info.h"
#include "care_render_connector.h"

namespace cenarius { namespace kernal { namespace cc {
using namespace asynchronous;
using namespace isolate;
using namespace scheduler;
class core_controller final 
    : public std::enable_shared_from_this<core_controller> {
public:
    core_controller(const core_controller&) = delete;
    core_controller& operator=(const core_controller&) = delete;
    core_controller(
        std::shared_ptr<barrel_buffer_center>, 
        std::shared_ptr<care>,
        std::shared_ptr<care_render_connector>);

public:
    /**
     * start controller thread
     * */
    void start();

    /**
     * stop or wait sync controller thread exit
     * */
    void stop(bool sync = false);

    /**
     * post task
     * */
    bool post(std::function<void()>);

    /**
     * pause
     * */
    void pause();

    /**
     * resume
     * */
    void resume();

    /**
     * resize
     * */
    void resize(uint32_t, uint32_t);

public:
    std::atomic_bool should_exit_ = ATOMIC_VAR_INIT(false);
    std::shared_ptr<barrel_buffer_center> buffer_center_;
    std::thread controller_thread_;
    std::shared_ptr<care> care_;
    std::shared_ptr<runnable_committer> task_committer_;

    // startover + 用来实现暂停和恢复的
    std::shared_ptr<content> content_;
    std::shared_ptr<syncer_condition> syncer_condition_; 

    // 定时器, 只能在控制器线程中使用
    std::shared_ptr<reactor_timer> reactor_timer_;
    // care info
    std::shared_ptr<care_info> care_info_;
    // care_controller 只能在控制器线程中使用，通过它的传递异步命令
    std::shared_ptr<care_controller> care_controller_;
    // 用来和渲染线程中通讯，只能在渲染线程中执行
    std::shared_ptr<care_render_connector> render_connector_;
};


}}}