#pragma once

#include "ACapacitySystem.hpp"
#include "CapacityActionDamageSystem.hpp"

namespace capacity {

	using namespace character;
	using namespace attribute;
	using namespace capacity_action;

	class Capacity_AttackRandomSystem : public ACapacitySystem {
	public:
		Capacity_AttackRandomSystem();
		~Capacity_AttackRandomSystem() override = default;
		CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override;
		CapacityData getCapacity() override;
	};
}