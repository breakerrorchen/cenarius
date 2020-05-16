
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/renderer/backend/android/render_basement.h"
#include "infrastructure/renderer/backend/android/renderer.h"
#include "infrastructure/renderer/backend/android/render_interface_canvas_center.h"
#include "kernal/cc/care_render.h"
#include "kernal/asynchronous/syncer/spinlocker.h"
#include "kernal/asynchronous/syncer/spinlocker_watcher.h"
#include "render_window.h"

namespace cenarius { namespace platform {
using namespace kernal;
using namespace asynchronous;
using namespace infrastructure;
using namespace renderer;
using namespace cc;
class care_render_i final : public care_render {
public:
    care_render_i();

public:
    /**
     * 渲染服务启动的时候调用
     * */
    void on_start() override;

    /**
     * 上屏前
     * */
    void pre_commit_drawable() override;
    
    /**
     * 上屏
     * */
    void commit_drawable() override;

    /**
     * 上屏后
     * */
    void after_commit_drawable() override;

    /**
     * 获取系统窗口管理器
     * */
    std::shared_ptr<canvas_center> get_canvas_center() override;

    /**
     * 渲染服务退出的时候调用
     * */
    void on_finish() override;

public:
    /**
     * 多线程，线程安全接口，外部线程设置新的native window
     * */
    void reset_window(std::shared_ptr<render_window>);

public:
    // 只能在渲染线程中使用的renderer
    std::shared_ptr<renderer_combined> renderer_;
    // 只能在渲染线程中使用的canvas center
    std::shared_ptr<render_interface_canvas_center> canvas_center_;

    // 渲染线程使用的window,和new_window交换的时候需要加锁
    std::shared_ptr<render_window> current_window_;
    // 当外部线程设置需要重置成新的window，需要通过加锁设置
    // 渲染线程需要在上屏之前判断是不是需要重置native window
    spinlocker locker_;
    std::shared_ptr<render_window> new_window_;
};


}}