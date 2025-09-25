#include "Capacity_DefendSelfSystem.hpp"

using namespace capacity;

capacity::Capacity_DefendSelfSystem::Capacity_DefendSelfSystem() {
	setCapacityName("Protect self");
	setCapacityDescription("Protect yourself with your armor");
	setCapacityPurposes({ DEFENSE });
	setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
	setCapacityAttribute({ STRENGTH, DEXTERITY });
}

CapacityData capacity::Capacity_DefendSelfSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {

	// Take the best between dexterity and strength
	{
		std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_SELF };
		constexpr int8_t min_armor{ 1 };
		constexpr int8_t base_armor{ 3 };
		int8_t total_armor = base_armor + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(WISDOM), min_armor);
		CapacityActionDamageSystem protect(total_armor, targets);
		queueCapacityActionData(protect.doAction());
	}
	return m_capacity_data;
}

CapacityData capacity::Capacity_DefendSelfSystem::getCapacity() {
	return m_capacity_data;
}
