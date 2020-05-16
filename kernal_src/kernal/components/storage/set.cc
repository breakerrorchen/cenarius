
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void local_storage::set_item(js_parameter& parameter) {
	if (store_) return;
	if (parameter.get_argument_count() < 2) {
		return;
	}

	auto k = parameter.get_argument_at(0);
	auto v = parameter.get_argument_at(1);
	if (!k.is_str() || !v.is_str()) {
		return;
	}
	auto k_str = k.to_string();
	auto v_str = v.to_string();
	store_->set(k_str.c_str(), v_str);
}