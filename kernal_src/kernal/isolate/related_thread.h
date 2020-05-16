
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/kv-store/include/kv.h"
#include "infrastructure/archiver/include/ora_center.h"
#include "infrastructure/net/include/io_center.h"
#include "infrastructure/net/include/io_committer.h"
#include "infrastructure/net/include/io_sendback.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/runnable/committer.h"
#include "kernal/cc/care_info.h"
#include "kernal/cc/care_render_connector.h"
#include "kernal/bestead/remote_container.h"
#include "kernal/scheduler/reactor_timer.h"
#include "kernal/scheduler/batch_container.h"

namespace cenarius { namespace kernal { namespace isolate {
using namespace cc;
using namespace asynchronous;
using namespace scheduler;
using namespace interpreter;
using namespace bestead;
using namespace infrastructure;
using namespace net;
using namespace renderer;
using namespace persistence;
using namespace archiver;
class related_thread final {
public:
    related_thread() = default;
    
public:
    /**
     * 获取和当前线程捆绑的对象
     * */
    static std::shared_ptr<related_thread> obtain();

    // 销毁当前线程中的数据
    static void dispose();

public:
    void construct();

public:
    // js监听生命周期
    js_value_holder on_show_  ;
    js_value_holder on_hide_  ;
    js_value_holder on_resume_;
    js_value_holder on_pause_ ;
    js_value_holder on_exit_  ;
    js_value_holder on_size_changed_;

public:
    // 用于管理和回收远程对象的容器
    remote_container remote_container_;
    
public:
    // javascript proto
    js_value_holder render_context_3d_proto_;

    // javascript class
    js_class cls_canvas_;
    js_class cls_render_context_2d_;
    js_class cls_render_context_3d_;
    js_class cls_image_;
    js_class cls_image_data_;
    js_class cls_render_2d_gradient_;
    js_class cls_render_2d_pattern_;
    js_class cls_render_3d_active_info_;
    js_class cls_render_3d_buffer_;
    js_class cls_render_3d_framebuffer_;
    js_class cls_render_3d_program_;
    js_class cls_render_3d_renderbuffer_;
    js_class cls_render_3d_shader_;
    js_class cls_render_3d_shader_precison_;
    js_class cls_render_3d_texture_;
    js_class cls_render_3d_uniform_location_;

public:
    __sptr<ora_center> ora_center_;                 // 只读文件系统和包资源管理器
    __sptr<kv_store> kv_store_;                     // 用于kv存储的的对象
    __sptr<runnable_committer> committer_;          // 消息队列
    __sptr<reactor_timer> reactor_timer_;           // 定时器
    __sptr<batch_timer_container> anima_timer_;     // 动画定时器
    __sptr<care_info> care_info_;                   // info
    __sptr<care_render_connector> render_connector_;// render connector
    __sptr<render_attitude> render_attitude_;       // 显卡写死的参数
    __sptr<barrel_buffer_center> buffer_center_;    // 通讯的高速command buffer

    // 网络服务
    __sptr<net::io_center>    net_io_center_;
    __sptr<net::io_committer> net_io_committer_;
    __sptr<net::io_sendback>  net_io_sendback_;
};


}}}