
#include "ora_bundle.h"
#include "ora_branch_builder.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

/**
 * 
 *                                                file node offset base address
 * +------------+-------+-------+--------+--------------------------+        +
 * |    ora     |   v0  |   v1  |   v2   |          crc32           |        |
 * +------------+-------+-------+--------+---------------------------<-------+
 * |                                                                |
 * |                                                                |
 * |                         file buffer                            |
 * |                                                                |
 * |                                                                |
 * +----------------------------------------------------------------+
 **/
const char* __ora__ = "ora";
bool ora_bundle::load(const char* file) {
    memmap_ = nullptr; branch_ = nullptr;
    if (nullptr == file) return false;
    memmap_ = mem_map::build();
    if (!memmap_->open(file))     { return false; }
    if (!memmap_->is_available()) { return false; }
    uint32_t size = 0; uint8_t* buffer = nullptr;
    memmap_->get_addr(&buffer); memmap_->get_size(&size);
    if (nullptr == buffer || 0 == size) {
        return false;
    }

    // ora文件开头必须是"ora"字符串
    auto token_size = sizeof(uint8_t) * 3;
    if (size < token_size) return false;
    char token[4] = { 0 };
    memcpy(token, buffer, token_size); 
    buffer += token_size; size -= token_size;
    if (0 != memcmp(__ora__, token, 3)) return false;

    // version 版本信息
    auto version_size = sizeof(uint16_t) * 3;
    if (size < version_size) return false;
    memcpy(version_, buffer, version_size);
    buffer += version_size; size -= version_size;

    // crc32校验
    auto crc32_size = sizeof(uint32_t);
    if (size < crc32_size) return false;
    uint32_t crc32 = 0;
    memcpy(&crc32, buffer, crc32_size);
    buffer += crc32_size; size -= crc32_size;

    // 构建ora文件树
    branch_ = ora_branch_builder::build(buffer, size);

    return !!branch_;
}