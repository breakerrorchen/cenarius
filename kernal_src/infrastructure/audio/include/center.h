
#pragma once
#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <string.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include <thread>

#include "fmod.h"
#include "fmod.hpp"

namespace cenarius { namespace infrastructure { namespace audio {
class context;
class center: public std::enable_shared_from_this<center> {
	friend class context;
public:
	center();
	virtual ~center();

public:
	void update();

public:
	std::shared_ptr<context> create();

private:
	FMOD::System* system_ = nullptr;
	std::vector<std::shared_ptr<context>> sound_contexts_;
};


}}}