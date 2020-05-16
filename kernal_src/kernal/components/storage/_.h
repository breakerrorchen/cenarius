
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/kv-store/include/kv.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace persistence;
class local_storage {
public:
    void set_item   (js_parameter&);
    void get_item   (js_parameter&);
    void remove_item(js_parameter&);
    void clear   	(js_parameter&);

private:
	std::shared_ptr<kv_store> store_;

public:
    static void outlet(js_context&, js_object&);
};


}}}