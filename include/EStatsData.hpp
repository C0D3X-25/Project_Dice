#pragma once
#include <string_view>

namespace character {

	enum EStatsData {
		NAME,
		LIFE,
		MAX_LIFE,
		ARMOR,
		MAX_ARMOR,
		LEVEL,
		XP,
		NEXT_LEVEL_XP,
	};

	constexpr std::string_view toString(EStatsData stats) {
		switch (stats) {
		case LIFE:			return "LIFE";
		case MAX_LIFE:		return "MAX_LIFE";
		case ARMOR:			return "ARMOR";
		case MAX_ARMOR:		return "MAX_ARMOR";
		case LEVEL:			return "LEVEL";
		case XP:			return "XP";
		case NEXT_LEVEL_XP:	return "NEXT_LEVEL_XP";
		default:			return "N/A";
		}
	}
}