#include "../include/CapacityActionDamage.hpp"

using namespace capacity_action;

capacity_action::CapacityActionDamage::CapacityActionDamage(const uint8_t damage, const std::vector<ECapacityTarget>& targets)
	: m_damage(damage), BaseCapacityAction(targets) {}


CapacityComponent capacity_action::CapacityActionDamage::doAction(void) {
	m_component = BaseCapacityAction::doAction();
	m_component.m_damage = m_damage;
	return m_component;
}