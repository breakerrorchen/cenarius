
#pragma once
#include "ora_branch.h"
#include "ora_bundle.h"
#include "ora_bundle.h"

namespace cenarius { namespace infrastructure { namespace archiver {
class ora_center final {
public:
    ora_center() = default;
    ora_center(const ora_center&) = delete;
    ora_center(ora_center&&) = delete;
    ora_center& operator=(const ora_center&) = delete;
    ora_center* operator=(ora_center&&) = delete;

public:
    /**
     * load并不检查文件之前是不是已经装载，外部需要保证文件是只装载一次
     * load函数是同步加载，
     * 异步可以在另一个线程创建一个bundle在回到线程装载
     * */
    bool load(const char*);
    bool load(std::shared_ptr<ora_bundle>);

public:
    ora_node* get_node(const char*); 

private:
    std::shared_ptr<ora_branch> branch_;
    std::vector<std::shared_ptr<ora_bundle>> bundles_;
};


}}}