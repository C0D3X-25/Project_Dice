#include "../include/CapacityActionRemoveArmorSystem.hpp"

using namespace capacity_action;

capacity_action::CapacityActionRemoveArmorSystem::CapacityActionRemoveArmorSystem(const uint8_t armor, const std::vector<ECapacityTargetData>& targets)
	: m_armor(armor), BaseCapacityActionSystem(targets) {
}


capacity_action::CapacityActionData CapacityActionRemoveArmorSystem::doAction(void) {
	m_capacity_dto.m_remove_armor = m_armor;
	return m_capacity_dto;
}
