
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class extension_embeder final {
public:
    extension_embeder(js_actuator& actuator);

public:
    /**
     * 构建扩展
     * */
    void build(js_object& global_object);

private:
    js_actuator actuator_;

public:
    static std::shared_ptr<extension_embeder> 
        create(js_actuator& actuator) {
        return std::make_shared<extension_embeder>(actuator);
    }
};


}}}
