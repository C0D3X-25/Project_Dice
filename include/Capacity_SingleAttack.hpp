#pragma once 

#include "ACapacitySystem.hpp"
#include "CapacityActionDamageSystem.hpp"

#include <vector>

namespace capacity {

	using namespace character;
	using namespace attribute;
	using namespace capacity_action;

	class Capacity_SingleAttack : public ACapacitySystem {
	public:

		void executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) override {
			setCapacityName("1 Attack");
			setCapacityDescription("Attack a single ennemy with STR or DEX");
			setCapacityPurposes({ ATTACK });
			setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
			setCapacityAttribute({ STRENGTH, DEXTERITY });

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 3 };
				int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);
				CapacityActionDamageSystem attack(total_damage, targets);
				queueCapacityActionData(attack.doAction());
			}
		}

		~Capacity_SingleAttack(void) override = default;
	};
}
