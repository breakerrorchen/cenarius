
#include <iostream>
#include "kernal/bestead/remote_ptr.h"
#include "kernal/bestead/remote_container.h"
using namespace std;
using namespace cenarius;
using namespace kernal;
using namespace bestead;

class guodong {
public:
    guodong() {
        //printf("%s %d\n", __FILE__, __LINE__);
    }

    ~guodong() {
        printf("%s %d\n", __FILE__, __LINE__);
    }
};

int main() {
    
    remote_container container;
    {
    std::vector<remote_ptr<guodong>> pool;

    
    for (int i = 0; i < 10; ++i) {
        auto ptr = container.create<guodong>();
        pool.push_back(ptr);
    }
    //container.clear();
    }

    printf("b clear \n");
    container.clear();

    return 0;
}
