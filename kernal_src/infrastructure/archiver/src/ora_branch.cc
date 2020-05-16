
#include "ora_branch.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

ora_node* ora_branch::get_node(const char* uri) {
    if (nullptr == uri) return nullptr;
    char* current = (char*)uri;
    if (current[0] == '/' || current[0] == '\\') {
        current += 1;
    }
    std::stack<ora_branch*> branch_stack;
    branch_stack.push(this);

    while (true) {
        char* ptr = strchr(current, '/');
        if (nullptr == ptr) {
            ptr = strchr(current, '\\');
        }

        if (nullptr == ptr) {
            std::string name(current);
            if (".." != name && "." != name && !name.empty()) {
                auto iter = nodes_.find(name);
                if (nodes_.end() == iter) {
                    return nullptr;
                }
                return &iter->second;
            } else {
                return nullptr;
            }
        } else {
            std::string name(current, ptr - current);
            if ("." == name || name.empty()) {
                ;
            } else if (".." == name) {
                branch_stack.pop();
                if (branch_stack.empty()) {
                    return nullptr;
                }
            } else {
                auto iter = children_.find(name);
                if (children_.end() == iter) {
                    return nullptr;
                }
                branch_stack.push(iter->second.get());
            }
            current = ptr + 1;
        }
    }
    return nullptr;
}

bool ora_branch::merge(std::shared_ptr<ora_branch> branch) {
    if (nullptr == branch) return false;
    for (auto& kv: branch->nodes_) {
        nodes_[kv.first] = kv.second;
    }
    for (auto& kv: branch->children_) {
        auto iter = children_.find(kv.first);
        if (children_.end() == iter) {
            children_[kv.first] = kv.second;
        } else {
            iter->second->merge(kv.second);
        }
    }
    return true;
}