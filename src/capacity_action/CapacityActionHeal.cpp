#include "../include/CapacityActionHeal.hpp"

using namespace capacity_action;

capacity_action::CapacityActionHeal::CapacityActionHeal(const uint8_t heal, const std::vector<ECapacityTarget>& targets)
	: m_heal(heal), BaseCapacityAction(targets) {}

CapacityComponent capacity_action::CapacityActionHeal::doAction(void) {
	m_component.m_heal = m_heal;
	return m_component;
}