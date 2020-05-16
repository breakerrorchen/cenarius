
#pragma once
#include "center.h"

namespace cenarius { namespace infrastructure { namespace audio {
class context : public std::enable_shared_from_this<context> {
	enum status {
		__init__ 	= 0,
	};
	friend class center;
public:
	context(std::shared_ptr<center> _center);
	virtual ~context();

public:
	bool open_uri   (const char*);
	bool open_buffer(const uint8_t*, uint32_t);

public:
	bool play();
	bool pause();
	bool stop();
	bool seek(float);
	bool loop(bool);
	bool autoplay(bool);
	bool get_autoplay(bool&) const;
	bool get_loop(bool&) const;
	bool volume(float);
	bool get_volume(float&) const;
	bool get_duration(float&);
	bool get_current_time(float&);
	bool get_pause(bool&) const;

public:
	void update();

private:
	FMOD::Sound*   sound_   = nullptr ;
    FMOD::Channel* channel_ = nullptr ;
    status current_status_  = __init__;

private:
	std::weak_ptr<center> ws_center_;
};


}}}