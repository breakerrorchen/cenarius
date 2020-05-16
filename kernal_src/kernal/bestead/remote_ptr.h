
#pragma once
#include "common/base_header_inct.h"
#include "thread_usefor.h"
#include "remote_base.h"

namespace cenarius { namespace kernal { namespace bestead {
class remote_container;
template<typename cls> class remote_ptr {
    friend class remote_container;
public:
    // remote_ptr只支持move语义, 而且不允许变量的覆盖操作
    // 由于覆盖操作必然需要释放前一个被覆盖的对象
    // 这就涉及到需要释放内存，但是由于内存必须在特定的线程
    // 中释放，所以此类行为是不安全行为
    //
    // remote_ptr的线程安全策略是任何时候只有一个线程持有
    // remote_ptr内部的数据和指针
    remote_ptr() = default;
    remote_ptr(remote_ptr&& that) {
        assert(nullptr == ptr_);
        thread_index_ = that.thread_index_;
        that.thread_index_ = 0;
        ptr_ = that.ptr_; that.ptr_ = nullptr;
    }
    
    remote_ptr(const remote_ptr& that) {
        assert(nullptr == ptr_);
        auto v = const_cast<remote_ptr*>(&that);
        thread_index_ = v->thread_index_;
        v->thread_index_ = 0;
        ptr_ = v->ptr_; v->ptr_ = nullptr;
    }

    remote_ptr& operator=(const remote_ptr&& that) {
        if (this == &that) return *this;
        assert(nullptr == ptr_);
        thread_index_ = that.thread_index_;
        that.thread_index_ = 0;
        ptr_ = that.ptr_; that.ptr_ = nullptr;
        return *this;
    }
    
    remote_ptr& operator=(const remote_ptr& that) {
        if (this == &that) return *this;
        assert(nullptr == ptr_);
        auto v = const_cast<remote_ptr*>(&that);
        thread_index_ = v->thread_index_;
        v->thread_index_ = 0;
        ptr_ = v->ptr_; v->ptr_ = nullptr;
        return *this;
    }

    /**
     * 析构函数比较容易误解，远程指针可以任意地方析构
     * 但是如果内部force_release必须在构建的线程
     * ！！！
     * 如果出现在非构建线程中析构，
     * 而且is_force_release_为true,说明使用方式有问题
     * 
     * 
     * 由于内部只有一个类型结构，所有force_relase已经
     * 调用过了这个对象的析构函数。
     * 为了防止重复调用2次内部对象的析构函数，free释放
     * */
    ~remote_ptr() {
        if (ptr_) {
            if (!ptr_->is_force_release_.s_) {
                auto idx = thread_userfor::thread_id();
                assert(thread_index_ == idx);
                // !!! 必须在合适的线程
                ptr_->force_release();
            }
            // 调用mark的析构函数
            ptr_->release_mark(); 

            // 真正的释放内存
            ::free(ptr_); ptr_ = nullptr;
        }
    }

private:
    // 用来包裹真实数据的容器
    remote_class<cls>* ptr_ = nullptr;

    // 用来构建的数据结构的线程index
    // 相关操作只能在一样的线程才安全
    uint32_t thread_index_ = 0;

public:
    /**
     * 由于数据可能会被container统一回收
     * 所以必须在和container一个线程中操作，强制线程安全
     * */
    inline cls& get_data() {
        auto idx = thread_userfor::thread_id();
        assert(thread_index_ == idx && ptr_);
        return ptr_->raw_data_;
    }

    /**
     * 判断数据是不是可用, 优先检查线程，再检查数据完整
     * 这个接口不强制在必要的线程中执行
     * */
    inline bool is_useable() const {
        auto idx = thread_userfor::thread_id();
        if (thread_index_ != idx) {
            return false;
        }
        return ptr_ && !(ptr_->is_force_release_.s_);
    }

public:
    /**
     * 销毁内部数据
     * 由于container并不保证线程安全，所以要做线程检查
     * 
     * 由于内部只有一个类型结构，所有force_relase已经
     * 调用过了这个对象的析构函数。
     * 为了防止重复调用2次内部对象的析构函数，free释放
     * */
    inline void dispose() {
        auto idx = thread_userfor::thread_id();
        assert(thread_index_ == idx);
        if (ptr_) {
            if (!(ptr_->is_force_release_.s_)) {
                ptr_->force_release();
            }
            // 调用mark的析构函数
            ptr_->release_mark();

            // 真正的释放内存
            ::free(ptr_); ptr_ = nullptr;
        }
    }
};


}}}