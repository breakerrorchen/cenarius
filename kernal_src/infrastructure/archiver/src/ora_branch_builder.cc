
#include "ora_branch_builder.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

std::shared_ptr<ora_branch> ora_branch_builder::__build(
    uint8_t* base, uint8_t* buffer, uint32_t size, uint32_t* offset) {
    if (nullptr == buffer || nullptr == base || 0 == size) return nullptr;
    auto branch = std::make_shared<ora_branch>();
    branch->base_buffer_ = base;
    uint32_t current_offset = 0, left = size;

    // 读取有多少个文件节点
    if (left < sizeof(uint32_t)) return nullptr;
    uint32_t node_size = 0;
    memcpy((void*)&node_size, buffer, sizeof(uint32_t));
    current_offset += sizeof(uint32_t); 
    buffer += sizeof(uint32_t); left -= sizeof(uint32_t);

    // 遍历处理文件节点
    for (int i = 0; i < node_size; ++i) {
        // 读取文件名的长度
        if (left < sizeof(uint16_t)) return nullptr;
        uint16_t len = 0;
        memcpy((void*)&len, buffer, sizeof(uint16_t));
        current_offset += sizeof(uint16_t); 
        buffer += sizeof(uint16_t); left -= sizeof(uint16_t);

        // 读取文件名
        if (left < len) return nullptr;
        std::string name((char*)buffer, len);
        current_offset += len;  buffer += len; size -= len;

        // 读取文件的大小和偏移
        if (left < sizeof(uint32_t) * 2) return nullptr;
        uint32_t offset = 0, buffer_size = 0;
        memcpy((void*)&buffer_size, buffer, sizeof(uint32_t));
        memcpy((void*)&offset, 
            buffer + sizeof(uint32_t), sizeof(uint32_t));
        current_offset += sizeof(uint64_t); 
        buffer += sizeof(uint64_t); left -= sizeof(uint64_t);

        // add
        // 检查内存是不是越界
        // size代表的是从buffer到结束的长度
        // 但是buffer_size和offset是对整个内存区域的
        // 所以需要计算上base到buffer之间的内存区域
        if (buffer_size + offset > size + (buffer - base)) {
            return nullptr;
        }
        ora_node sub_node; 
        sub_node.buffer_ = base + offset; 
        sub_node.size_ = buffer_size;
        branch->nodes_[name] = sub_node;
    }

    // 处理文件子树的
    if (left < sizeof(uint32_t)) return nullptr;
    uint32_t branch_size = 0;
    memcpy((void*)&branch_size, buffer, sizeof(uint32_t));
    current_offset += sizeof(uint32_t); 
    buffer += sizeof(uint32_t); left -= sizeof(uint32_t);

    // 遍历处理子树节点
    for (int i = 0; i < branch_size; ++i) {
        // 读取文件夹名的长度
        if (left < sizeof(uint16_t)) return nullptr;
        uint16_t len = 0;
        memcpy((void*)&len, buffer, sizeof(uint16_t));
        current_offset += sizeof(uint16_t); 
        buffer += sizeof(uint16_t); left -= sizeof(uint16_t);

        // 读取文件名
        if (left < len) return nullptr;
        std::string name((char*)buffer, len);
        current_offset += len;  buffer += len; left -= len;

        // 加载文件夹的数据
        uint32_t sub_branch_size = 0;
        auto sub_branch = __build(
            base, buffer, left, &sub_branch_size);
        if (!sub_branch) return nullptr;

        // add
        branch->children_[name] = sub_branch;

        // offset
        current_offset += sub_branch_size;  
        buffer += sub_branch_size; left -= sub_branch_size;
    }

    // ret offset
    if (offset) { *offset = current_offset; }

    return branch;
}

std::shared_ptr<ora_branch> 
    ora_branch_builder::build(void* buffer, uint32_t size) {
    return __build((uint8_t*)buffer, (uint8_t*)buffer, size, nullptr);
}