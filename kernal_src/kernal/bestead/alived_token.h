
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace bestead {
/**
 * 主要的场景就是有一些c++的对象并不是通过引用计数来维护生命周期的
 * 通过alived_watcher，可以用来监控对象的生命周期
 * ！！！！
 * alived_watcher是线程不安全的
 * */
template<typename cls> class alived_watcher;
template<typename cls> class alived_token {
    friend class alived_watcher<cls>;
public:
    inline cls* get() { return raw_instance_; }
    inline bool is_useable() const {
        return !!raw_instance_;
    }
private:
    cls* raw_instance_ = nullptr;
};

template<typename cls> class alived_watcher final {
    void* operator new(size_t) = delete;
public:
    alived_watcher(cls* _instance)
        : raw_instance_(_instance) {
        ;
    }

    ~alived_watcher() {
        if (ptr_) {
            ptr_->raw_instance_ = nullptr;
        }
    }

public:
    inline std::shared_ptr<alived_token<cls>> get() {
        if (!ptr_) {
            ptr_ = std::make_shared<alived_token<cls>>();
            ptr_->raw_instance_ = raw_instance_;
        }
        return ptr_;
    }

private:
    cls* raw_instance_ = nullptr;
    std::shared_ptr<alived_token<cls>> ptr_;
};


}}}