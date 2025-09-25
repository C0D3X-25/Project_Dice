#pragma once 

#include "ACapacitySystem.hpp"
#include "CapacityActionDamageSystem.hpp"

#include <vector>

namespace capacity {

	using namespace character;
	using namespace attribute;
	using namespace capacity_action;

	class Capacity_DefendSelfSystem : public ACapacitySystem {
	public:

		Capacity_DefendSelfSystem();
		CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override;
		CapacityData getCapacity() override;
		~Capacity_DefendSelfSystem() override = default;
	};
}
