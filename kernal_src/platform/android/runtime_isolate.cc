
#include "common/logger.h"
#include "runtime_isolate.h"
#include "render_window.h"
#include "kernal/test/test_start.h"
using namespace cenarius;
using namespace platform;
using namespace kernal;
using namespace cc;

void runtime_isolate::startup_script(std::string& script, bool move_) {
    if (!move_) {
        startup_script_ = script;
    } else {
        startup_script_ = std::move(script);
    }
}

void runtime_isolate::on_create() {
    //::cenarius::kernal::test::_start_test();
}

// vsync的分发, 这里是在android的UI线程中触发的
// 需要通过linux的eventfd切换到控制器线程，
// 然后通过command-buffer操作到渲染线程做上屏操作
void runtime_isolate::on_receive_vsync() {
    if (care_ && care_->controller_) {
        care_->controller_->vsync_dispatch();   
    }
}

/**
 * android系统的特性：
 * 1. surface创建后会调用这个函数，然后调用changed通知大小变化
 * 2. 不管是重建还是只是简单的大小变化都会调用的changed
 * 3. 所以全部逻辑都都放在changed里面处理
 * 4. created里面标记了surface是不是新建的
 * */
void runtime_isolate::on_surface_created(ANativeWindow* win) {
    is_new_created_surface_ = true;
    if (nullptr != win) {
        ::ANativeWindow_release(win);
    }
__log_error("runtime_isolate::on_surface_created");
}

/**
 * android系统的特性：
 * 1. 系统Surface在重建的时候会调用creat然后调用changed
 * 2. 当界面发生大小变化的时候，只会通知changed的
 * */
void runtime_isolate::on_surface_changed(ANativeWindow* win, float scale) {
__log_error("runtime_isolate::on_surface_changed %x", win);
    assert(win);
    auto w = ::ANativeWindow_getWidth (win);
    auto h = ::ANativeWindow_getHeight(win);
    if (coordiator_) {
        if (is_new_created_surface_) {
            // 通知底层渲染的native window需要被替换
            if (care_ && care_->render_) {
                care_->render_->reset_window(
                    std::make_shared<render_window>(win, scale));
            }
        }
        // 检查大小是不是发生了变动
        // 如果窗口大小发生了变动，需要通知上层业务
        if (w != window_w_ || h != window_w_) {
            // 通知协调器窗口发生了大小变化,并记录窗口大小
            window_w_ = w; window_h_ = h;
            coordiator_->size_changed(w, h);
        }
        coordiator_->resume();
    } else {
        auto renderable = std::make_shared<render_window>(win, scale);
        auto info = std::make_shared<care_info>();
        info->window_w_ = w; info->window_h_ = h;
        care_ = std::make_shared<care_i>();
        care_->controller_ = std::make_shared<care_controller_i>();
        care_->render_ = std::make_shared<care_render_i>();
        care_->render_->reset_window(renderable);
        care_->communicate_ = std::shared_ptr<care_communicate_i>();
        care_->info_ = info;
        
        coordiator_ = std::make_shared<coordiator>(
            std::dynamic_pointer_cast<care>(care_));
        coordiator_->start();
        coordiator_->eval_script(startup_script_, true);
    }

    // 标记
    is_new_created_surface_ = false;

    // 减少native windows的引用计数
    ::ANativeWindow_release(win);
}

/**
 * android系统的特性：
 * 1. 当界面暂停比如activity被盖住，会调用surface的destory
 * 2. 当界面回到渲染的引擎的界面，会调用surface的create
 * 3. 然后在调用changed
 * */
void runtime_isolate::on_surface_destroy() {
__log_error("runtime_isolate::on_surface_destroy");
    if (coordiator_) {
        coordiator_->pause();
    }
}

/**
 * android系统的特性：
 * 1. 需要在activity退出的时候通知渲染引擎退出
 * */
void runtime_isolate::on_finalization() {
    if (coordiator_) {
        // 当前有可能存储于pause的状态，所以需要先唤醒再处理
        coordiator_->resume();
        coordiator_->finalization();
    }
}