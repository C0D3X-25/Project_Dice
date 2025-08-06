#include "../include/CapacityActionDamage.hpp"

using namespace capacity_action;

capacity_action::CapacityActionDamage::CapacityActionDamage(const uint8_t damage, const std::vector<ECapacityTarget>& targets)
	: m_damage(damage), BaseCapacityAction(targets) {}


CapacityDTO capacity_action::CapacityActionDamage::doAction(void) {
	m_capacity_dto = BaseCapacityAction::doAction();
	m_capacity_dto.m_damage = m_damage;
	return m_capacity_dto;
}