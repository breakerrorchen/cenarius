
#include <iostream>
#include "ora_branch.h"
#include "ora_center.h"
using namespace std;
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

int main() {
    return 0;
    //_b.get_node("/1/2231231/../../ wqwdad");
    
    auto center = std::make_shared<ora_center>();
    auto ret = center->load("/Users/bytedance/Desktop/Cenarius/ora_maker/build/macosx/x86_64/release/out.bin");
    if (ret) {
        printf("load success \n");
    } else {
        printf("load fail \n");
    }

    auto node = center->get_node("/1.txt");
    printf("%x \n", node);
    std::string data((char*)node->get_buffer(), node->get_size());
    printf("%s %d\n", data.c_str(), node->get_size());
    return 0;
}