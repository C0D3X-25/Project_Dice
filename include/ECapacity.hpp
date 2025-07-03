#pragma once

#include <string_view>

namespace capacity {

	// Goal of the capacity
	enum ECapacityPurpose {
		ATTACK_PHYSICAL,
		ATTACK_MAGIC,
		DEFENSE,
		SUPPORT,
		MAGIC,
		HEALING,
		BUFF,
		DEBUFF,
		SPECIAL
	};

	constexpr std::string_view toString(ECapacityPurpose purpose) {
		switch (purpose) {
			case ATTACK_PHYSICAL:	return "ATTACK_PHYSICAL";
			case ATTACK_MAGIC:		return "ATTACK_MAGIC";
			case DEFENSE:			return "DEFENSE";
			case SUPPORT:			return "SUPPORT";
			case MAGIC:				return "MAGIC";
			case HEALING:			return "HEALING";
			case BUFF:				return "BUFF";
			case DEBUFF:			return "DEBUFF";
			case SPECIAL:			return "SPECIAL";
			default:				return "N/A";
		}
	}


	// Target of the capacity
	enum ECapacityTarget {
		TARGET_SELF,
		TARGET_SINGLE,
		TARGET_RANDOM,
		TARGET_AREA,
		TARGET_TEAM,
		TARGET_EVERYONE,
		TARGET_ALLY,
		TARGET_ENNEMY,
		TARGET_ALIVE,
		TARGET_DEAD,
	};

	constexpr std::string_view toString(ECapacityTarget target) {
		switch (target) {
			case TARGET_SELF:      return "TARGET_SELF";
			case TARGET_SINGLE:    return "TARGET_SINGLE";
			case TARGET_RANDOM:    return "TARGET_RANDOM";
			case TARGET_AREA:      return "TARGET_AREA";
			case TARGET_TEAM:      return "TARGET_TEAM";
			case TARGET_EVERYONE:  return "TARGET_EVERYONE";
			case TARGET_ALLY:      return "TARGET_ALLY";
			case TARGET_ENNEMY:    return "TARGET_ENNEMY";
			case TARGET_ALIVE:     return "TARGET_ALIVE";
			case TARGET_DEAD:      return "TARGET_DEAD";
			default:               return "N/A";
		}
	}


	// When the capacity is used
	enum ECapacityTrigger {
		USED_WHEN_TURN_END,
		USED_WHEN_TURN_START,
		USED_WHEN_ASSIGNED
	};

	constexpr std::string_view toString(ECapacityTrigger trigger) {
		switch (trigger) {
			case USED_WHEN_TURN_END:	return "USED_WHEN_TURN_END";
			case USED_WHEN_TURN_START:	return "USED_WHEN_TURN_START";
			case USED_WHEN_ASSIGNED:    return "USED_WHEN_ASSIGNED";
			default:                    return "N/A";
		}
	}
}
