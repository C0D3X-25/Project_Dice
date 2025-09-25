#include "Capacity_AttackTeamSystem.hpp"

using namespace capacity;

capacity::Capacity_AttackTeamSystem::Capacity_AttackTeamSystem() {
	setCapacityName("Strike the ennemy team once");
	setCapacityDescription("Attack all ennemy with best INT, WIS or CHA");
	setCapacityPurposes({ ATTACK });
	setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
	setCapacityAttribute({ INTELLIGENCE, WISDOM, CHARISMA });
}

CapacityData capacity::Capacity_AttackTeamSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {

	// Take the best between dexterity and strength
	{
		std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_TEAM, TARGET_ENEMY };
		constexpr int8_t min_damage{ 1 };
		constexpr int8_t base_damage{ 2 };
		int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(CHARISMA), source_character.getAttribute(WISDOM), source_character.getAttribute(INTELLIGENCE), min_damage);
		CapacityActionDamageSystem attack(total_damage, targets);
		queueCapacityActionData(attack.doAction());
	}
	return m_capacity_data;
}

CapacityData capacity::Capacity_AttackTeamSystem::getCapacity() {
	return m_capacity_data;
}
