
#include "context.h"
using namespace cenarius;
using namespace infrastructure;
using namespace audio;

context::context(std::shared_ptr<center> _center) {
	assert(_center);
	ws_center_ = _center;
}

context::~context() {
	auto _center = ws_center_.lock();
	if (_center) {
		auto& pool = _center->sound_contexts_;
		auto iter = pool.begin();
		for (; iter != pool.end(); ++iter) {
			if (iter->get() == this) {
				pool.erase(iter);
				break;
			}
		}
	}
}

bool context::open_uri(const char* uri) {
	if (nullptr != sound_) {
		sound_->release();
		sound_ = nullptr; channel_ = nullptr;
	}
	auto _center = ws_center_.lock();
	if (!_center || !_center->system_ || !uri) {
		return false;
	}

	FMOD_CREATESOUNDEXINFO exinfo;
    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
    exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.filebuffersize = 1024 * 16;
    auto mode = FMOD_CREATESTREAM|FMOD_NONBLOCKING;
    auto ret = _center->system_->createSound(
    	uri, mode, &exinfo, &sound_);
   	return sound_ && FMOD_OK == ret;
}

bool context::open_buffer(
	const uint8_t* buffer, uint32_t size) {
	if (nullptr != sound_) {
		sound_->release();
		sound_ = nullptr; channel_ = nullptr;
	}

	return true;
}

void context::update() {

}