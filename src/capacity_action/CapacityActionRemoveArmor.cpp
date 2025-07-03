#include "../include/CapacityActionRemoveArmor.hpp"

using namespace capacity_action;

capacity_action::CapacityActionRemoveArmor::CapacityActionRemoveArmor(const uint8_t armor, const std::vector<ECapacityTarget>& targets)
	: m_armor(armor), BaseCapacityAction(targets) {}


capacity_action::CapacityComponent CapacityActionRemoveArmor::doAction(void) {
	m_component.m_remove_armor = m_armor;
	return m_component;
}
