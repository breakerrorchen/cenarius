
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace bestead {
class remote_container;
class remote_base {
    friend class remote_container;
public:
    virtual ~remote_base() = default;

public:
    // 完成双向队列的数据结构
    remote_base* last_ = nullptr;
    remote_base* next_ = nullptr;

public:
    /**
     * 必须由子类重写，没有重写主动调用会crash
     * */
    virtual void force_release() {
        assert(false);
    }
};

/**
 * 用来标记被内部清理的标记
 * */
class remote_release_mark final {
public:
    std::atomic<bool> s_ = false;
};

/**
 * 用来存储用户定义数据的的容器
 * */
template<typename cls> class remote_class: protected remote_base {
    friend class remote_container;
public:
    template<typename ...args_t>
    remote_class(args_t&&... arguments) : raw_data_(
        std::forward<args_t>(arguments)...) {
        ;
    }

public:
    // 标记内部数据结构是不是已经被释放了
    // 由于析构的时候会判定是不是内部release了
    // 不允许在非构建线程做force_release
    // 但是该标准要求CPU内存一致性
    remote_release_mark is_force_release_;

    /**
     * 强制调用标志位析构函数
     * */
    void release_mark() {
        is_force_release_.~remote_release_mark();
    }

    /**
     * 强制释放当前对象
     * 从双向队列中摘除自己后删除自己，必须是堆
     * */
    void force_release() {
        if (!(is_force_release_.s_)) {
            if (next_) { 
                next_->last_ = last_; 
            }

            if (last_) { 
                last_->next_ = next_; 
            }

            // 暂时只析构内部数据
            // 由于真实的内存和container混在一起，
            // 所以并不是立刻释放内存
            raw_data_.~cls();

            // 标记析构标志
            is_force_release_.s_ = true;
        }
    }

public:
    cls raw_data_;
};


}}}