#pragma once 

#include "ACapacitySystem.hpp"

#include <vector>

namespace capacity {

	using character::CharacterSystem;

	class Capacity_NothingSystem : public ACapacitySystem {
	public:

		Capacity_NothingSystem();
		CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override;
		CapacityData getCapacity() override;
		~Capacity_NothingSystem(void) override = default;
	};
}
