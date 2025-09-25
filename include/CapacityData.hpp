#pragma once

#include "EAttributeData.hpp"
#include "CapacityActionData.hpp"

#include <string>
#include <vector>
#include <queue>
#include <iostream>

namespace capacity {

	using attribute::EAttributeData;

	/// <summary>
	/// Represents a data structure for capacity-related information.
	/// </summary>
	struct CapacityData {

		void printCapacityData() const {
			std::cout << " - " << m_name
				<< " - \n" << m_description << '\n';
			std::cout << "Capacity purposes: [ ";
			for (const auto& purpose : m_capacity_purpose) {
				std::cout << toString(purpose) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity targets:  [ ";
			for (const auto& target : m_capacity_target) {
				std::cout << toString(target) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity triggers: [ ";
			for (const auto& trigger : m_capacity_trigger) {
				std::cout << toString(trigger) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity Actions in Queue: " << m_capacity_dto_queue.size() << "\n";
		}

		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
		std::queue<CapacityActionData> m_capacity_dto_queue;
		std::vector<ECapacityPurposeData> m_capacity_purpose;
		std::vector<ECapacityTargetData> m_capacity_target;
		std::vector<ECapacityTriggerData> m_capacity_trigger;
		std::vector<EAttributeData> m_capacity_attribute;
	};
}