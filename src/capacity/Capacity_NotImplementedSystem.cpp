#include "Capacity_NotImplementedSystem.hpp"

using namespace capacity;

capacity::Capacity_NotImplementedSystem::Capacity_NotImplementedSystem() {
	setCapacityName("Not implemented");
	setCapacityDescription("WIP");
	setCapacityPurposes({});
	setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
	setCapacityAttribute({});
}

CapacityData capacity::Capacity_NotImplementedSystem::executeCapacity(CharacterSystem& source_character, CharacterSystem& target_character) {
	return m_capacity_data;
}

CapacityData capacity::Capacity_NotImplementedSystem::getCapacity() {
	return m_capacity_data;
}
