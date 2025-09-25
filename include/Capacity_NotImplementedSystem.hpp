#pragma once 

#include "ACapacitySystem.hpp"

#include <vector>

namespace capacity {

	using character::CharacterSystem;

	class Capacity_NotImplementedSystem : public ACapacitySystem {
	public:

		Capacity_NotImplementedSystem();
		CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override;
		CapacityData getCapacity() override;
		~Capacity_NotImplementedSystem(void) override = default;
	};
}
