#pragma once

#include <string_view>

namespace capacity {

	// When the capacity is used
	enum ECapacityTriggerData {
		TRIGGERED_WHEN_TURN_END,
		TRIGGERED_WHEN_TURN_START,
		TRIGGERED_WHEN_ASSIGNED
	};

	constexpr std::string_view toString(ECapacityTriggerData trigger) {
		switch (trigger) {
			case TRIGGERED_WHEN_TURN_END:	return "TRIGGERED_WHEN_TURN_END";
			case TRIGGERED_WHEN_TURN_START:	return "TRIGGERED_WHEN_TURN_START";
			case TRIGGERED_WHEN_ASSIGNED:   return "TRIGGERED_WHEN_ASSIGNED";
			default:						return "N/A";
		}
	}
}
