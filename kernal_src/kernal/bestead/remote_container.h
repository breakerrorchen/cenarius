
#pragma once
#include "common/base_header_inct.h"
#include "thread_usefor.h"
#include "remote_base.h"
#include "remote_ptr.h"

namespace cenarius { namespace kernal { namespace bestead {
/**
 * remote_ptr需要和remote_container配合使用
 * 1. 设计目的，相当于线程对象容器
 * 2. 场景，有些场景下解释器释放后但是还有解释器变量被外部持有
 * 3. 通过container统一收回, 确保安全
 * */
class remote_container final: 
    public std::enable_shared_from_this<remote_container> {
public:
    ~remote_container();

public:
    /**
     * 清空和回收所有外部被引用的数据
     * */
    void clear();

public:
    /**
     * eg:
     * auto ptr = remote_container.create<type>(...);
     * ptr.dispose();
     * */
    template<typename cls, typename ...args_t>
    remote_ptr<cls> create(args_t&&... arguments) {
        remote_ptr<cls> ptr;
        ptr.ptr_ = new remote_class<cls>(
            std::forward<args_t>(arguments)...);
        ptr.thread_index_ = thread_userfor::thread_id();
        auto base = dynamic_cast<remote_base*>(ptr.ptr_);
        base->next_ = remote_base_.next_; 
        base->last_ = &remote_base_;
        remote_base_.next_ = base;
        return ptr;
    }

private:
    remote_base remote_base_;    
};


}}}