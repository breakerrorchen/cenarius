
#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <fstream>  
#include <streambuf> 
#include <list>
#include <map>
#include <vector>
#include <string.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include <thread>
#include <ghc/filesystem.hpp>
#include <snappy.h>
using namespace std;
namespace fs = ghc::filesystem;

static unsigned int crc32_tab[] = {
   0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
   0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
   0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
   0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
   0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
   0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
   0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
   0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
   0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
   0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
   0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
   0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
   0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
   0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
   0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
   0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
   0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
   0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
   0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
   0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
   0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
   0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
   0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
   0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
   0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
   0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
   0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
   0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
   0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
   0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
   0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
   0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
   0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
   0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
   0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
   0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
   0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
   0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
   0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
   0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
   0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
   0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
   0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

inline uint32_t __crc32__(const void* buffer, int size, uint32_t crc = 0) {
    const uint8_t* ptr = (uint8_t*)buffer;
    crc = crc ^ ~0U;
    while (size--) {
        crc = crc32_tab[(crc ^ *ptr++) &0xFF] ^(crc >>8);
    }
    return crc ^ ~0U;
}

const char* _show_logo_str = 
"\n\
================================                \n\
Ora Maker Tools, Ver: 1.0                       \n\
Created By Chenguodong                          \n\
================================                \n\
 ______     __    __     ______                 \n\
/\\  __ \\   /\\ \"-./  \\   /\\__  _\\         \n\ 
\\ \\ \\/\\ \\  \\ \\ \\-./\\ \\  \\/_/\\ \\/   \n\ 
 \\ \\_____\\  \\ \\_\\ \\ \\_\\    \\ \\_\\    \n\ 
  \\/_____/   \\/_/  \\/_/     \\/_/            \n\
--------------------------------                \n\
\n\n";

class node {
public:
    // ora文件开头会有3个info数据
    // "ora" + version(6位) + crc32(4位)
    // 这里的offset指的不是相对文件头，而是文件头偏移 3 + 6 + 4后的
    uint32_t file_size_ = 0, offset_ = 0;

public:
    // offset是out已经写入了多少数据
    void write(ofstream& out, int& offset) {
        if (!out.good()) {
            std::abort();
        }

        // 这2个offset相对基地址是不一样的，需要做个转化
        if (offset != offset_ + 3 + 6 + 4) {
            printf("ORA SAY: \"%s\" %d %d file offset is not match!\n\n", 
                file_path_.c_str(), offset, offset_);
            std::abort();
        }

        std::ifstream in(file_path_.c_str());
        std::string str((std::istreambuf_iterator<char>(in)),  
            std::istreambuf_iterator<char>());
        //printf("==>%s \n", str.c_str());
        if (str.size() != file_size_) {
            printf("ORA SAY: \"%s\" file size is not match!\n\n", file_path_.c_str());
            std::abort();
        }

        if (!str.empty()) {
            out.write(str.data(), str.size());
        }
        offset += str.size();
    }

public:
    std::string file_path_;
};

class branch {
public:
    std::map<std::string, std::shared_ptr<node>>   nodes_;
    std::map<std::string, std::shared_ptr<branch>> childrens_;

public:
    void write(ofstream& out, int& offset) {
        if (!out.good()) {
            std::abort();
        }

        uint32_t nodes_num = nodes_.size();
        out.write((char*)&nodes_num, sizeof(uint32_t));
        offset += sizeof(uint32_t);
        for (auto& kv : nodes_) {
            // 写入名字的长度和真实的数据
            uint16_t name_len = kv.first.length();
            out.write((char*)&name_len, sizeof(uint16_t));
            offset += sizeof(uint16_t);
            out.write(kv.first.data(), kv.first.length());
            offset += kv.first.size();

            // 写入文件长度和内存的偏移值
            out.write((char*)&(kv.second->file_size_), sizeof(uint32_t));
            offset += sizeof(uint32_t);
            out.write((char*)&(kv.second->offset_), sizeof(uint32_t));
            offset += sizeof(uint32_t);
        }

        uint32_t branch_num = childrens_.size();
        out.write((char*)&branch_num, sizeof(uint32_t));
        offset += sizeof(uint32_t);
        for (auto& kv : childrens_) {
            // 写入名字的长度和真实的数据
            uint16_t name_len = kv.first.length();
            out.write((char*)&name_len, sizeof(uint16_t));
            offset += sizeof(uint16_t);
            out.write(kv.first.data(), kv.first.length());
            offset += kv.first.length();


            kv.second->write(out, offset);
        }
    }

public:
    inline uint32_t calc() {
        uint32_t size = 0;
        size += sizeof(uint32_t);
        for (auto& kv : nodes_) {
            size += sizeof(uint16_t);
            size += kv.first.length();
            size += sizeof(uint32_t) + sizeof(uint32_t);
        }

        size += sizeof(uint32_t);
        for (auto& kv : childrens_) {
            size += sizeof(uint16_t);
            size += kv.first.length();
            size += kv.second->calc();
        }
        return size;
    }
};

void __traversal_dirs(std::string _path, 
    std::shared_ptr<branch> _branch, std::vector<std::shared_ptr<node>>& _nodes) {
    if (!fs::is_directory(fs::path(_path.c_str()))) {
        printf("ORA SAY: inner error!\n");
        std::abort();
        return;
    }
    for (auto& i : fs::directory_iterator(_path.c_str())) {
        auto _path = fs::path(i);
        if (fs::is_directory(_path)) {
            auto _sub_branch = std::make_shared<branch>();
            __traversal_dirs(i.path(), _sub_branch, _nodes);
            // printf("dirs: %s \n", i.path().c_str());
            _branch->childrens_[i.path().filename().c_str()] = _sub_branch;
        } else {
            // printf("file: %s \n", i.path().c_str());
            auto _node = std::make_shared<node>();
            _node->file_path_ = i.path().c_str();
            try {
                _node->file_size_ = fs::file_size(i.path().c_str());
                _branch->nodes_[i.path().filename().c_str()] = _node;
                _nodes.push_back(_node);
            } catch (fs::filesystem_error& e) {
                ;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    printf(_show_logo_str);
    if (argc < 3) {
        printf("ORA SAY: need input file dirs and version number!\n");
        printf("ORA SAY: exit!\n");
        return 0;
    }
    std::string target_path(argv[1]);
    printf("ORA SAY: try build ora file use dirs => \"%s\" .\n", target_path.c_str());
    fs::path path(target_path.c_str());
    if (!fs::is_directory(path)) {
        printf("ORA SAY: ~e => \"%s\" is not a real dirs path!\n", target_path.c_str());
        printf("ORA SAY: exit!\n");
        return 0;
    }

    // version
    int version_0 = 0, version_1 = 0, version_2 = 0;
    sscanf(argv[2], "%d.%d.%d", &version_0, &version_1, &version_2);
    printf("ORA SAY: version info %d.%d.%d\n", version_0, version_1, version_2);

    // 遍历文件夹
    printf("\nORA SAY: scan files\n");
    auto _branch = std::make_shared<branch>();
    std::vector<std::shared_ptr<node>> nodes;
    __traversal_dirs(target_path, _branch, nodes);
    printf("\n");

    // 打印info
    printf("ORA SAY: have %d files\n", nodes.size());

    // 统计meta数据需要占据的内存大小
    // 最开始3位 ora 文件标识符 
    // meta信息前面6位是版本信息，后面四位是crc32校验
    // printf("====%d \n", _branch->calc());
    auto meta_size = _branch->calc();// + 3 + 6 + 4;
    printf("ORA SAY: meta size %f KB\n", meta_size/1024.f);

    // 计算每个文件的偏移地址
    uint32_t current_offset = meta_size;
    for (auto& i : nodes) {
        i->offset_ = current_offset;
        current_offset += i->file_size_;
    }
    printf("ORA SAY: bundle size %f KB\n\n", current_offset/1024.f);

    // 构建文件
    ofstream ora_file("out.bin", std::ofstream::out|std::ofstream::trunc);
    if (!ora_file.good()) {
        printf("ORA SAY: build ora file faile\n");
        return 0;
    }
    // 写入文件头标识符
    ora_file.write("ora", 3);

    // 写入版本号
    uint16_t v_0 = version_0, v_1 = version_1, v_2 = version_2;
    ora_file.write((char*)&v_0, sizeof(uint16_t));
    ora_file.write((char*)&v_1, sizeof(uint16_t));
    ora_file.write((char*)&v_2, sizeof(uint16_t));

    // 写入crc32校验
    uint32_t crc_data = 0;
    ora_file.write((char*)&crc_data, sizeof(uint32_t));

    // 写入brach的文件meta数据
    int write_offset = 3 + 6 + 4; // ora + 1.0.1 + crc32
    _branch->write(ora_file, write_offset);

    //printf("====%d \n", write_offset - 13);

    // 写入文件的数据
    for (auto& i : nodes) {
        i->write(ora_file, write_offset);
    }

    // 写入文件关闭
    ora_file.close();

    // snappy 压缩
    // 先读取整个文件
    std::ifstream ora_in("out.bin");
    std::string ora_in_str((
        std::istreambuf_iterator<char>(ora_in)),  
        std::istreambuf_iterator<char>());

    // 计算crc32的值
    uint32_t _crc = __crc32__(ora_in_str.data(), ora_in_str.size());
    printf("ORA SAY: crc %d \n", _crc);

    // 写入 crc32
    memcpy((void*)(ora_in_str.data() + 9), &_crc, sizeof(_crc));

    // 压缩
    std::string compress_data;
    snappy::Compress(ora_in_str.data(), ora_in_str.size(), &compress_data);

    // 写入新的文件
    printf("ORA SAY: compress bundle size %f KB\n", compress_data.size()/1024.f);
    ofstream ora_out_file("out.ora", std::ofstream::out|std::ofstream::trunc);
    if (!ora_out_file.good()) {
        printf("ORA SAY: build ora file faile\n");
        return 0;
    }
    ora_out_file.write(compress_data.data(), compress_data.size());
    ora_out_file.close();

    printf("ORA SAY: success!!!!!!!!\n");
    return 0;
}
