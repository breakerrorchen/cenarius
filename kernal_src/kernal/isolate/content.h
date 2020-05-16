
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/command_buffer/transmitter.h"
#include "kernal/basis_service/event_observer.h"
#include "kernal/components/extension_embeder.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "content_context.h"
#include "related_thread.h"

namespace cenarius { namespace kernal { namespace isolate {
using namespace asynchronous;
using namespace scheduler;
using namespace interpreter;
using namespace components;
class content final
    : public std::enable_shared_from_this<content> {
public:
    content(std::shared_ptr<content_context>);

public:
    void on_create ();                  // 创建后调用
    void on_pause  ();                  // 休眠
    void on_vsync  ();                  // 收到vsync
    void on_resum  ();                  // 唤醒
    void on_destory();                  // 销毁
    void on_resize (uint32_t, uint32_t);// 修改大小

public:
    /**
     * 外部提交JavaScript代码并执行
     * */
    void eval(const char*);

private:
    std::shared_ptr<related_thread> related_thread_;
    std::shared_ptr<extension_embeder> extension_;
    js_vm vm_; 
    js_actuator actuator_;
    std::shared_ptr<content_context> content_context_;
};


}}}