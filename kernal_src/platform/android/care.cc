
#include "care.h"
using namespace cenarius;
using namespace kernal;
using namespace cc;
using namespace platform;

std::shared_ptr<care_communicate> care_i::communicate() {
    return nullptr;
}

std::shared_ptr<care_info> care_i::arguments() {
    return info_;
}

std::shared_ptr<care_render> care_i::render() {
    return std::dynamic_pointer_cast<care_render>(render_);
}

std::shared_ptr<care_controller> care_i::controller() {
    return std::dynamic_pointer_cast<
        care_controller>(controller_);
}