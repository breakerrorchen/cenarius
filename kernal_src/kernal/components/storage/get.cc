
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void local_storage::get_item(js_parameter& parameter) {
	if (store_) return;
	if (parameter.get_argument_count() == 0) {
		return;
	}

	auto val = parameter.get_argument_at(0);
	if (!val.is_str()) {
		return;
	}
	auto k = val.to_string(); std::string v;
	if (store_->get(k.c_str(), v)) {
		auto _context = parameter.get_context();
		parameter.set_return(js_value::create(
			_context, v.c_str(), false));
	}
}