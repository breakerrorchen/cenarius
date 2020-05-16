
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace bestead {
template<typename cls> class puppet_container {
public:
	std::shared_ptr<cls> data_;
};

template<typename cls> class puppet final {
public:
	puppet() {
		container_ = new puppet_container<cls>();
	}
	
public:
	inline puppet_container<cls>* get() const {
		return container_;
	}

	inline operator bool() const {
		return !!container_;
	}

private:
	puppet_container<cls>* container_ = nullptr;
};

}}}