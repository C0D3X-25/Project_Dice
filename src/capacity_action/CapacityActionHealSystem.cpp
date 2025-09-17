#include "../include/CapacityActionHealSystem.hpp"

using namespace capacity_action;

capacity_action::CapacityActionHealSystem::CapacityActionHealSystem(const uint8_t heal, const std::vector<ECapacityTargetData>& targets)
	: m_heal(heal), BaseCapacityActionSystem(targets) {
}

CapacityActionData capacity_action::CapacityActionHealSystem::doAction(void) {
	m_capacity_action_data.m_heal = m_heal;
	return m_capacity_action_data;
}