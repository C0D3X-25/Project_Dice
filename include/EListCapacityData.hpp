#pragma once

#include <string_view>

namespace capacity {

	/// <summary>
	/// Key for the Capacity std::map
	/// </summary>
	enum EListCapacityData {
		NOT_IMPLEMENTED = -1,
		NOTHING,
		ATTACK_SINGLE,
		ATTACK_RANDOM,
		DEFEND_SELF,
		HEAL_FAST,
		ATTACK_TEAM,
		// More capacities can be added here
	};

	constexpr std::string_view toString(EListCapacityData capacity) {
		switch (capacity) {
		case NOT_IMPLEMENTED:	return "NOT_IMPLEMENTED";
		case NOTHING:			return "NOTHING";
		case ATTACK_SINGLE:		return "ATTACK_SINGLE";
		case ATTACK_RANDOM:		return "ATTACK_RANDOM";
		case DEFEND_SELF:		return "DEFEND_SELF";
		case HEAL_FAST:			return "HEAL_FAST";
		case ATTACK_TEAM:		return "ATTACK_TEAM";
		default:				return "N/A";
		}
	}
}