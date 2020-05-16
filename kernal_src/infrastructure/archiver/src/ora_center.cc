
#include "ora_center.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

bool ora_center::load(const char* file) {
    if (nullptr == file) return false;
    auto bundle = std::make_shared<ora_bundle>();
    if (!bundle->load(file)) {
        return false;
    }
    return load(bundle);
}

bool ora_center::load(std::shared_ptr<ora_bundle> bundle) {
    if (!bundle) return false;
    if (!bundle->memmap_ || !bundle->branch_) return false;
    bundles_.push_back(bundle);
    if (!branch_) {
        branch_ = bundle->branch_;
    } else {
        branch_->merge(bundle->branch_);
    }
    return true;
}

ora_node* ora_center::get_node(const char* filename) {
    if (!filename || !branch_) return nullptr;
    return branch_->get_node(filename);
}