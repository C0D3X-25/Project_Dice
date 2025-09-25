#include "Capacity_AttackRandomSystem.hpp"

using namespace capacity;

capacity::Capacity_AttackRandomSystem::Capacity_AttackRandomSystem() {
	setCapacityName("Random Attack");
	setCapacityDescription("Attack a single enemy with worst STR or DEX, then attack another random enemy with best STR or DEX");
	setCapacityPurposes({ ATTACK });
	setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
	setCapacityAttribute({ STRENGTH, DEXTERITY });
}

CapacityData capacity::Capacity_AttackRandomSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {
	// Take the best between dexterity and strength 
	{
		std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENEMY };

		constexpr int8_t min_damage{ 1 };
		constexpr int8_t base_damage{ 3 };
		int8_t total_damage = base_damage + helper::find::getLowestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);

		CapacityActionDamageSystem attack(total_damage, targets);
		queueCapacityActionData(attack.doAction());
	}

	// Take the best between dexterity and strength
	{
		std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENEMY };

		constexpr int8_t min_damage{ 1 };
		constexpr int8_t base_damage{ 5 };
		int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);

		CapacityActionDamageSystem attack(total_damage, targets);
		queueCapacityActionData(attack.doAction());
	}
	return m_capacity_data;
}

CapacityData capacity::Capacity_AttackRandomSystem::getCapacity() {
	return m_capacity_data;
}
