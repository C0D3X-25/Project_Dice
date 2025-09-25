#include "Capacity_AttackSingleSystem.hpp"

using namespace capacity;

capacity::Capacity_AttackSingleSystem::Capacity_AttackSingleSystem() {
	setCapacityName("Single Attack");
	setCapacityDescription("Attack a single enemy with the best between STR or DEX");
	setCapacityPurposes({ ATTACK });
	setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
	setCapacityAttribute({ STRENGTH, DEXTERITY });
}

CapacityData capacity::Capacity_AttackSingleSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {

	// Take the best between dexterity and strength
	{
		std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENEMY };
		constexpr int8_t min_damage{ 1 };
		constexpr int8_t base_damage{ 3 };
		int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);
		CapacityActionDamageSystem attack(total_damage, targets);
		queueCapacityActionData(attack.doAction());
	}
	return m_capacity_data;
}

CapacityData capacity::Capacity_AttackSingleSystem::getCapacity() {
	return m_capacity_data;
}
