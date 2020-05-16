
#include "ora_node.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

ora_node::ora_node(const ora_node& from) {
    operator=(from);
}

ora_node::ora_node(ora_node&& from) {
    operator=(from);
}

ora_node& ora_node::operator=(const ora_node& from) {
    if (this != &from) {
        buffer_ = from.buffer_;
        size_   = from.size_;
    }
    return *this;
}

ora_node& ora_node::operator=(ora_node&& from) {
    if (this != &from) {
        buffer_ = from.buffer_; from.buffer_ = nullptr;
        size_   = from.size_;   from.size_   = 0;
    }
    return *this;
}