#include "Capacity_HealFastSystem.hpp"

using namespace capacity;

capacity::Capacity_HealFastSystem::Capacity_HealFastSystem() {
	setCapacityName("Fast heal");
	setCapacityDescription("Heal directly a single ally with best INT, WIS or CHA");
	setCapacityPurposes({ HEAL });
	setCapacityTriggers({ TRIGGERED_WHEN_ASSIGNED });
	setCapacityAttribute({ INTELLIGENCE, WISDOM, CHARISMA });
}

CapacityData capacity::Capacity_HealFastSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {

	// Take the best between INT, WIS or CHA
	{
		std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ALLY };
		constexpr int8_t min_heal{ 0 };
		constexpr int8_t base_heal{ 1 };
		int8_t total_heal = base_heal + helper::find::getHighestValue(source_character.getAttribute(CHARISMA), source_character.getAttribute(WISDOM), source_character.getAttribute(INTELLIGENCE), min_heal);
		CapacityActionDamageSystem heal(total_heal, targets);
		queueCapacityActionData(heal.doAction());
	}
	return m_capacity_data;
}

CapacityData capacity::Capacity_HealFastSystem::getCapacity() {
	return m_capacity_data;
}
