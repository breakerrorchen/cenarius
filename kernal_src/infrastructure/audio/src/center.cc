
#include "context.h"
using namespace cenarius;
using namespace infrastructure;
using namespace audio;

center::center() {
	FMOD::System_Create(&system_);
	if (system_) {
		system_->init(32, FMOD_INIT_NORMAL, nullptr);
		system_->setStreamBufferSize(
			64*1024, FMOD_TIMEUNIT_RAWBYTES);
	}
}

center::~center() {
	if (system_) {
		system_->close();
		system_->release();
	}
}

void center::update() {
	if (system_) {
		system_->update();
	}
	
	for (auto& item: sound_contexts_) {
		item->update();
	}
}

std::shared_ptr<context> center::create() {
	auto _this = shared_from_this();
	auto _context = std::make_shared<context>(_this);
	sound_contexts_.push_back(_context);
	return _context;
}