#include "ACapacitySystem.hpp"


void capacity::ACapacitySystem::queueCapacityActionData(const CapacityActionData& capacity_dto) {
	addCapacityTarget(capacity_dto);
	m_capacity_data.m_capacity_dto_queue.push(capacity_dto);
}

capacity::CapacityActionData capacity::ACapacitySystem::getNextCapacityActionData() {
	if (!m_capacity_data.m_capacity_dto_queue.empty()) {
		CapacityActionData m_current_dto = m_capacity_data.m_capacity_dto_queue.front();
		m_capacity_data.m_capacity_dto_queue.pop();
		return m_current_dto;
	}
	return CapacityActionData{};
}

void capacity::ACapacitySystem::printCapacity() const {
	std::cout << " - " << getCapacityName()
		<< " - \n" << getCapacityDescription() << '\n';
	std::cout << "Capacity purposes: [ ";
	for (const auto& purpose : m_capacity_data.m_capacity_purpose) {
		std::cout << toString(purpose) << " ";
	}
	std::cout << "]\n";
	std::cout << "Capacity targets:  [ ";
	for (const auto& target : m_capacity_data.m_capacity_target) {
		std::cout << toString(target) << " ";
	}
	std::cout << "]\n";
	std::cout << "Capacity triggers: [ ";
	for (const auto& trigger : m_capacity_data.m_capacity_trigger) {
		std::cout << toString(trigger) << " ";
	}
	std::cout << "]\n";
}

void capacity::ACapacitySystem::addCapacityTarget(const CapacityActionData& capacity_dto) {
	for (const auto& target : capacity_dto.m_targets) {
		if (std::find(m_capacity_data.m_capacity_target.begin(), m_capacity_data.m_capacity_target.end(), target) == m_capacity_data.m_capacity_target.end()) {
			m_capacity_data.m_capacity_target.push_back(target);
		}
	}
}