#include "../include/CapacityActionAddArmorSystem.hpp"


capacity_action::CapacityActionAddArmorSystem::CapacityActionAddArmorSystem(const uint8_t armor, const std::vector<ECapacityTargetData>& targets)
	: m_armor(armor), BaseCapacityActionSystem(targets) {}


capacity_action::CapacityActionData capacity_action::CapacityActionAddArmorSystem::doAction(void) {
	m_capacity_dto.m_add_armor = m_armor;
	return m_capacity_dto;
}



