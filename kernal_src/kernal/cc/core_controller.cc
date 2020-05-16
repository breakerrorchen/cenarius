
#include "common/logger.h"
#include "kernal/asynchronous/syncer/syncer_condition.h"
#include "core_controller.h"
using namespace cenarius;
using namespace kernal;
using namespace isolate;
using namespace asynchronous;
using namespace cc;

core_controller::core_controller(
    std::shared_ptr<barrel_buffer_center> buffer_center,
    std::shared_ptr<care> _care,
    std::shared_ptr<care_render_connector> connector) {
    assert(buffer_center && _care && connector);
    if (!buffer_center || !_care || !connector) {
        throw std::invalid_argument("~");
    }
    render_connector_ = connector;
    buffer_center_ = buffer_center;
    care_ = _care; care_info_ = _care->arguments();
    assert(care_ && care_info_ && buffer_center_);
}

// 启动整个控制器线程的函数
void core_controller::start() {
    auto _protected_this = shared_from_this();
    syncer_condition syncer;
    auto thread = std::thread([_protected_this, this, &syncer]() {
        auto _care_controller = care_->controller();
        assert(_care_controller);
        if (!_care_controller) { 
            std::abort(); 
        }
        care_controller_ = _care_controller;
        task_committer_ = std::dynamic_pointer_cast<
            runnable_committer>(care_controller_);
        _care_controller->on_start(); //通知底层控制器线程开始
        
        // 定时器
        reactor_timer_ = std::make_shared<reactor_timer>();
        //创建 content context 和 content
        auto _context = std::make_shared<content_context>();
        _context->committer_        = task_committer_;
        _context->reactor_timer_    = reactor_timer_;
        _context->care_info_        = care_info_;
        _context->render_connector_ = render_connector_;
        _context->buffer_center_    = buffer_center_;
        content_ = std::make_shared<content>(_context);

        // 通知外部线程已经准备好了
        syncer.completed_notify();    
        
        // 启动内部逻辑
        content_->on_create();

        // vsync的回调函数
        _care_controller->listen_vsync([&]() { 
            content_->on_vsync(); 
        });

        /**
         * 事件循环逻辑：
         * 1. 需要适时的退出
         * 2. 调用跨平台的接口并维护定时器
         * */
        while (true) {
            if (should_exit_.load()) { break; }
            bool is_timeout = false;
            _care_controller->poll_once(reactor_timer_
                ->get_lastest_timeout_time(), &is_timeout);
            if (is_timeout) {
                reactor_timer_->poll();
            }
        }

        /**
         * 退出释放逻辑：
         * 1. 退出对vsync的监听
         * 2. 释放content
         * 3. 强制释放定时器
         * 4. 通知底层控制器线程要退出了
         * */
        _care_controller->listen_vsync(nullptr);
        content_->on_destory(); content_ = nullptr; 
        reactor_timer_ = nullptr;
        _care_controller->on_finish();
    });

    // 同步通知外部等待线程初始化完成
    syncer.wait(); controller_thread_.swap(thread);
}

void core_controller::stop(bool sync) {
    /**
     * 外部通知退出的逻辑：
     * 1. 标记退出标志
     * 2. 推送一个空的runnable用来唤醒队列
     * 3. 如果当前线程出于pause状态，需要先唤醒 
     * 4. 等待线程的退出
     * */
    should_exit_.store(true);
    if (care_controller_) {
        care_controller_->commit([]() { ; });
    }

    // 有可能当前线程出于被外部pause的情况下
    // 所以需要通知内部线程唤醒执行
    if (syncer_condition_) {
        syncer_condition_->completed_notify();
        syncer_condition_ = nullptr;
    }

    // 根据外部情况来判断是不是需要同步等待线程的退出
    // 特殊场景下需要通过强制同步退出时机来保证安全
    if (sync) {
        controller_thread_.join();
    } else {
        controller_thread_.detach();
    }
}

bool core_controller::post(std::function<void()> task) {
    if (!task && !care_controller_) {
        care_controller_->commit(task);
    }
    return true;
}

void core_controller::pause() {
    // 如果有多次需求暂停需要折叠成一次
    // 目前暂停完全跟随系统的事件，不提供主动暂停和唤醒的接口
    if (syncer_condition_) return;
    if (content_ && task_committer_) {
        std::weak_ptr<content> ws_content = content_;
        auto _syncer = std::make_shared<syncer_condition>();
        task_committer_->commit([ws_content, _syncer] () {
            auto _content = ws_content.lock();
            if (!_content) {
                return;
            }

            // 通过信号量来实现暂停和恢复的逻辑
            _content->on_pause();
            _syncer->wait();
            _content->on_resum();
        });
        syncer_condition_ = _syncer;
    }
}

void core_controller::resume() {
    /**
     * 唤醒线程，在退出的时候也需要唤醒
     * */
    if (syncer_condition_) {
        syncer_condition_->completed_notify();
        syncer_condition_ = nullptr;
    }
}

void core_controller::resize(uint32_t w, uint32_t h) {
    if (content_) {
        std::weak_ptr<content> ws_content = content_;
        post([ws_content, w, h]() {
            auto _content = ws_content.lock();
            if (_content) {
                _content->on_resize(w, h);
            }
        });
    }
}