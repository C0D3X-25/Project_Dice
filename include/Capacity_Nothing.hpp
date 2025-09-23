#pragma once 

#include "ACapacitySystem.hpp"

#include <vector>

namespace capacity {

	using character::CharacterSystem;

	class Capacity_Nothing : public ACapacitySystem {
	public:

		void executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override {
			setCapacityName("Nothing");
			setCapacityDescription("Just skip your turn");
			setCapacityPurposes({ });
			setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
			setCapacityAttribute({ });
		}

		~Capacity_Nothing(void) override = default;
	};
}
