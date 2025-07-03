#include "../include/CapacityActionAddArmor.hpp"


capacity_action::CapacityActionAddArmor::CapacityActionAddArmor(const uint8_t armor, const std::vector<ECapacityTarget>& targets)
	: m_armor(armor), BaseCapacityAction(targets) {}


capacity_action::CapacityComponent capacity_action::CapacityActionAddArmor::doAction(void) {
	m_component.m_add_armor = m_armor;
	return m_component;
}



