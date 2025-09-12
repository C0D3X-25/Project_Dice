#include "../include/CapacityActionDamageSystem.hpp"

using namespace capacity_action;

capacity_action::CapacityActionDamageSystem::CapacityActionDamageSystem(const uint8_t damage, const std::vector<ECapacityTargetData>& targets)
	: m_damage(damage), BaseCapacityActionSystem(targets) {
}


CapacityActionData capacity_action::CapacityActionDamageSystem::doAction(void) {
	m_capacity_dto = BaseCapacityActionSystem::doAction();
	m_capacity_dto.m_damage = m_damage;
	return m_capacity_dto;
}