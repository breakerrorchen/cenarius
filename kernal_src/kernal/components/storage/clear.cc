
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void local_storage::clear(js_parameter& parameter) {
	if (store_) {
		store_->clear();
	}
}