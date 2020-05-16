
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void local_storage::remove_item(js_parameter& parameter) {
	if (store_) return;
	if (parameter.get_argument_count() == 0) {
		return;
	}
	auto val = parameter.get_argument_at(0);
	if (!val.is_str()) {
		return;
	}
	store_->remove(val.to_string().c_str());
}