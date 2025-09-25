#include "Capacity_NothingSystem.hpp"

using namespace capacity;

capacity::Capacity_NothingSystem::Capacity_NothingSystem() {
	setCapacityName("Nothing");
	setCapacityDescription("Just skip your turn");
	setCapacityPurposes({});
	setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
	setCapacityAttribute({});
}

CapacityData capacity::Capacity_NothingSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {
	return m_capacity_data;
}

CapacityData capacity::Capacity_NothingSystem::getCapacity() {
	return m_capacity_data;
}
