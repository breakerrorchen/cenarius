// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "committer.h"

namespace cenarius { namespace kernal { namespace asynchronous {

class runnable_committer_current final {
public:
    /**
     * binds the entry for the current thread
     * */
    static void attach(std::shared_ptr<runnable_committer>);

    /**
     * gets the entry for the current thread
     * */
    static std::shared_ptr<runnable_committer> obtain();

    /**
     * committer
     * */
    static bool commit(std::function<void()>);

private:
    template<class cls> static void attach(std::shared_ptr<cls> var) {
        if (var) {
            attach(std::dynamic_pointer_cast<runnable_committer>(var));
        } else {
            attach(nullptr);
        }
    }
};


}}} // end => cenarius.kernal.asynchronous