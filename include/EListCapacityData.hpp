#pragma once

#include <string_view>

namespace capacity {

	/// <summary>
	/// Key for the Capacity std::map
	/// </summary>
	enum EListCapacityData {
		NOTHING,
		SINGLE_ATTACK,
	};

	constexpr std::string_view toString(EListCapacityData capacity) {
		switch (capacity) {
		case NOTHING:			return "NOTHING";
		case SINGLE_ATTACK:		return "SINGLE_ATTACK";
		default:				return "N/A";
		}
	}
}