#pragma once

#include "../include/Attribute.hpp"

#include <string>
#include <cstdint>

namespace item {

	using namespace attribute;

	struct Item {
		int32_t id{ 0 };

		Attribute attribute;
		std::string name{ "N/A" };
	};

}