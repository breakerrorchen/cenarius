
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/command_buffer/command_consumer.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/syncer/syncer_condition.h"
#include "care.h"
#include "care_render_connector.h"

namespace cenarius { namespace kernal { namespace cc {
using namespace asynchronous;
/**
 * 用来消费渲染队列的线程，
 * 必须在控制器线程启动前启动，控制器线程销毁完成后销毁
 * */
class command_renderer final
    : public std::enable_shared_from_this<command_renderer> {
public:
    command_renderer(
        std::shared_ptr<barrel_buffer_center>, 
        std::shared_ptr<care>, 
        std::shared_ptr<care_render_connector>);
public:
    /**
     * start render thread
     * */
    void start();

    /**
     * stop or wait sync render thread exit
     * */
    void stop(bool sync = false);

private:
    /* 渲染命令的消费 */
    void render_command_consume(syncer_condition&);

private:
    std::atomic_bool should_exit_ = ATOMIC_VAR_INIT(false);
    std::thread render_thread_;
    std::shared_ptr<care> care_;
    std::shared_ptr<barrel_buffer_center> buffer_center_;
    std::shared_ptr<care_render_connector> render_connector_;
};


}}}