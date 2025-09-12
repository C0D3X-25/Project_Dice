#pragma once 

#include <string_view>

namespace rarity {

	enum ERarityData {
		COMMON,
		UNCOMMON,
		RARE,
		MYTHIC,
		LEGENDARY,
		RELIC
	};

	constexpr std::string_view toString(ERarityData rarity) {
		switch (rarity) {
		case COMMON:		return "COMMON";
		case UNCOMMON:		return "UNCOMMON";
		case RARE:			return "RARE";
		case MYTHIC:		return "MYTHIC";
		case LEGENDARY:		return "LEGENDARY";
		case RELIC:			return "RELIC";
		default:				return "N/A";
		}
	}
}