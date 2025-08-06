#include "../include/CapacityActionAddArmor.hpp"


capacity_action::CapacityActionAddArmor::CapacityActionAddArmor(const uint8_t armor, const std::vector<ECapacityTarget>& targets)
	: m_armor(armor), BaseCapacityAction(targets) {}


capacity_action::CapacityDTO capacity_action::CapacityActionAddArmor::doAction(void) {
	m_capacity_dto.m_add_armor = m_armor;
	return m_capacity_dto;
}



