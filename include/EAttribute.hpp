#pragma once
#include <string_view>

namespace attribute {

	enum EAttribute {
		STRENGTH,
		DEXTERITY,
		CONSTITUTION,
		INTELLIGENCE,
		WISDOM,
		CHARISMA
	};

	constexpr std::string_view toString(EAttribute attribute) {
		switch (attribute) {
		case STRENGTH:		return "STRENGTH";
		case DEXTERITY:		return "DEXTERITY";
		case CONSTITUTION:	return "CONSTITUTION";
		case INTELLIGENCE:	return "INTELLIGENCE";
		case WISDOM:		return "WISDOM";
		case CHARISMA:		return "CHARISMA";
		default:			return "N/A";
		}
	}
}