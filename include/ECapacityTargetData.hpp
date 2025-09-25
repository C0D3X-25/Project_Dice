#pragma once

#include <string_view>

namespace capacity {

	// Target of the capacity
	enum ECapacityTargetData {
		TARGET_SELF,
		TARGET_SINGLE,
		TARGET_RANDOM,
		TARGET_AREA,
		TARGET_TEAM,
		TARGET_EVERYONE,
		TARGET_ALLY,
		TARGET_ENEMY,
		TARGET_ALIVE,
		TARGET_DEAD,
	};

	constexpr std::string_view toString(ECapacityTargetData target) {
		switch (target) {
		case TARGET_SELF:      return "TARGET_SELF";
		case TARGET_SINGLE:    return "TARGET_SINGLE";
		case TARGET_RANDOM:    return "TARGET_RANDOM";
		case TARGET_AREA:      return "TARGET_AREA";
		case TARGET_TEAM:      return "TARGET_TEAM";
		case TARGET_EVERYONE:  return "TARGET_EVERYONE";
		case TARGET_ALLY:      return "TARGET_ALLY";
		case TARGET_ENEMY:    return "TARGET_ENEMY";
		case TARGET_ALIVE:     return "TARGET_ALIVE";
		case TARGET_DEAD:      return "TARGET_DEAD";
		default:               return "N/A";
		}
	}
}
