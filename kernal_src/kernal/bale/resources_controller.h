// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/fs/include/filesystem.h"

namespace cenarius { namespace kernal { namespace assets {
using namespace infrastructure;
using namespace filesystem;

class resources_controller final {
public:
    resources_controller(const char*, const char*);
    resources_controller(const resources_controller&) = delete;
    resources_controller(resources_controller&&);
    resources_controller& operator=(const resources_controller&) = delete;
    resources_controller& operator=(resources_controller&&);

public:
    /**
     * executed when the engine starts, to ensure that the folders exist
     * */
    bool available_check();

private:
    filesystem::path root_path_, system_cache_path_;
};


}}}