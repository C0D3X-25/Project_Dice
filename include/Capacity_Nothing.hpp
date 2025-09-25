#pragma once 

#include "ACapacitySystem.hpp"

#include <vector>

namespace capacity {

	using character::CharacterSystem;

	class Capacity_Nothing : public ACapacitySystem {
	public:

		Capacity_Nothing() {
			setCapacityName("Nothing");
			setCapacityDescription("Just skip your turn");
			setCapacityPurposes({ });
			setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
			setCapacityAttribute({ });
		}

		CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override {
			return m_capacity_data;
		}

		CapacityData getCapacity() override {
			return m_capacity_data;
		}

		~Capacity_Nothing(void) override = default;
	};
}
