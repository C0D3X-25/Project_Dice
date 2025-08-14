#pragma once

#include <string_view>

namespace item {

	/// <summary>
	/// Represents the different types of items in the game.
	/// An item can be more than 1 type, but it must have at least one type.
	/// </summary>
	enum EItemType {
		ARMOR,
		WEAPON,
		SHIELD,
		MAGICAL_ITEM
	};

	constexpr std::string_view toString(EItemType item_type) {
		switch (item_type) {
		case ARMOR:			return "ARMOR";
		case WEAPON:		return "WEAPON";
		case SHIELD:		return "SHIELD";
		case MAGICAL_ITEM:	return "MAGICAL_ITEM";
		default:			return "N/A";
		}
	}
}