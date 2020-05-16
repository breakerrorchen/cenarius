
#include "kv.h"
using namespace cenarius;
using namespace infrastructure;
using namespace persistence;

int main() {
    printf("test \n");
    auto s = std::make_shared<kv_store>(
        "/Users/bytedance/Code/Cenarius/kernal_src/benchmark");
    auto v = std::string("haha");
    for (int i = 0; i < 1000000; ++i) {
        s->set("guodong", v);
        v.clear();
        s->get("guodong", v);
        // printf("%s \n", v.c_str());
    }

    return 0;
}