#pragma once

#include <string_view>

namespace item {

	/// <summary>
	/// Represents the different tags of items in the game.
	/// An item can be more than 1 tag, but it must have at least one tag.
	/// </summary>
	enum EItemTagData {
		ARMOR,
		WEAPON,
		SHIELD,
		ACCESSORIES
	};

	constexpr std::string_view toString(EItemTagData item_tag) {
		switch (item_tag) {
		case ARMOR:			return "ARMOR";
		case WEAPON:		return "WEAPON";
		case SHIELD:		return "SHIELD";
		case ACCESSORIES:	return "ACCESSORIES";
		default:			return "N/A";
		}
	}
}