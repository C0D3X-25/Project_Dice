#include "../include/CapacityActionRemoveArmor.hpp"

using namespace capacity_action;

capacity_action::CapacityActionRemoveArmor::CapacityActionRemoveArmor(const uint8_t armor, const std::vector<ECapacityTarget>& targets)
	: m_armor(armor), BaseCapacityAction(targets) {}


capacity_action::CapacityDTO CapacityActionRemoveArmor::doAction(void) {
	m_capacity_dto.m_remove_armor = m_armor;
	return m_capacity_dto;
}
