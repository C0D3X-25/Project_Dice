#pragma once 

#include <string_view>

namespace rarity {

	enum ERarity {
		COMMON,
		UNCOMMON,
		RARE,
		NAMED,
		LEGENDARY,
		RELIC
	};

	constexpr std::string_view toString(ERarity rarity) {
		switch (rarity) {
		case COMMON:		return "COMMON";
		case UNCOMMON:		return "UNCOMMON";
		case RARE:			return "RARE";
		case NAMED:			return "NAMED";
		case LEGENDARY:		return "LEGENDARY";
		case RELIC:			return "RELIC";
		default:				return "N/A";
		}
	}
}