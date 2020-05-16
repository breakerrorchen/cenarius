
#pragma once
#include "common/base_header_inct.h"
#include "kernal/cc/coordinator.h"
#include "env.h"
#include "care.h"

namespace cenarius { namespace platform {
using namespace kernal;
using namespace cc;
class runtime_isolate final {
public:
    runtime_isolate() = default;
public:
    void on_create();
    void on_receive_vsync();
    void on_surface_created(ANativeWindow*);
    void on_surface_changed(ANativeWindow*, float);
    void on_surface_destroy();
    void on_finalization();

public:
    // 引擎侧的协调器，用来控制逻辑和渲染的相关性
    std::shared_ptr<coordiator> coordiator_;

    // 和上层交互的对象
    std::shared_ptr<care_i> care_;

    // 已经创建的窗口的大小
    // 当窗口大小变动的时候需要比较大小来通知协调器是不是大小变动了
    // 这些变量只能在启动线程中调用
    int32_t window_w_ = 0, window_h_ = 0;

    // 用来判断是不是新的surface需要重建windows
    bool is_new_created_surface_ = false;
};


}}
