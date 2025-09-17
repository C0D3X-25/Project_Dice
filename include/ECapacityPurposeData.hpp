#pragma once

#include <string_view>

namespace capacity {

	// Goal of the capacity
	enum ECapacityPurposeData {
		ATTACK,
		DEFENSE,
		SUPPORT,
		HEAL,
		BUFF,
		DEBUFF,
		SPECIAL
	};

	constexpr std::string_view toString(ECapacityPurposeData purpose) {
		switch (purpose) {
		case ATTACK:	return "ATTACK";
		case DEFENSE:	return "DEFENSE";
		case SUPPORT:	return "SUPPORT";
		case HEAL:		return "HEAL";
		case BUFF:		return "BUFF";
		case DEBUFF:	return "DEBUFF";
		case SPECIAL:	return "SPECIAL";
		default:		return "N/A";
		}
	}
}
