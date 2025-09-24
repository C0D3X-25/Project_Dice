#pragma once 

#include "ACapacitySystem.hpp"

#include <vector>

namespace capacity {

	using character::CharacterSystem;

	class Capacity_NotImplemented : public ACapacitySystem {
	public:

		CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override {
			setCapacityName("Not implemented");
			setCapacityDescription("WIP");
			setCapacityPurposes({ });
			setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
			setCapacityAttribute({ });

			return m_capacity_data;
		}

		~Capacity_NotImplemented(void) override = default;
	};
}
