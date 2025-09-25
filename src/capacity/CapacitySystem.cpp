#include "ACapacitySystem.hpp"

using namespace capacity;

void capacity::ACapacitySystem::queueCapacityActionData(const CapacityActionData& capacity_dto) {
	addCapacityTarget(capacity_dto);
	m_capacity_data.m_capacity_dto_queue.push(capacity_dto);
}

CapacityActionData capacity::ACapacitySystem::getNextCapacityActionData() {
	if (!m_capacity_data.m_capacity_dto_queue.empty()) {
		CapacityActionData m_current_dto = m_capacity_data.m_capacity_dto_queue.front();
		m_capacity_data.m_capacity_dto_queue.pop();
		return m_current_dto;
	}
	return CapacityActionData{};
}

void capacity::ACapacitySystem::addCapacityTarget(const CapacityActionData& capacity_dto) {
	for (const auto& target : capacity_dto.m_targets) {
		if (std::find(m_capacity_data.m_capacity_target.begin(), m_capacity_data.m_capacity_target.end(), target) == m_capacity_data.m_capacity_target.end()) {
			m_capacity_data.m_capacity_target.push_back(target);
		}
	}
}