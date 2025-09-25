#pragma once

#include "EAttributeData.hpp"
#include "ECapacityTargetData.hpp"
#include "ECapacityPurposeData.hpp"
#include "ECapacityTriggerData.hpp"
#include "CapacityActionData.hpp"

#include <string>
#include <vector>
#include <queue>

namespace capacity {

	using attribute::EAttributeData;

	/// <summary>
	/// Represents a data structure for capacity-related information.
	/// </summary>
	struct CapacityData {

		//void printCapacityData() const 
		//	{
		//	std::cout << "Capacity Name: " << m_name << "\n";
		//	std::cout << "Description: " << m_description << "\n";
		//	std::cout << "Purposes: ";
		//	for (const auto& purpose : m_capacity_purpose) {
		//		std::cout << static_cast<int>(purpose) << " "; // Assuming ECapacityPurposeData can be cast to int for display
		//	}
		//	std::cout << "\n";
		//	std::cout << "Triggers: ";
		//	for (const auto& trigger : m_capacity_trigger) {
		//		std::cout << static_cast<int>(trigger) << " "; // Assuming ECapacityTriggerData can be cast to int for display
		//	}
		//	std::cout << "\n";
		//	std::cout << "Used Attributes: ";
		//	for (const auto& attribute : m_capacity_attribute) {
		//		std::cout << static_cast<int>(attribute) << " "; // Assuming EAttributeData can be cast to int for display
		//	}
		//	std::cout << "\n";
		//	std::cout << "Capacity Actions in Queue: " << m_capacity_dto_queue.size() << "\n";
		//}

		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
		std::queue<CapacityActionData> m_capacity_dto_queue;
		std::vector<ECapacityPurposeData> m_capacity_purpose;
		std::vector<ECapacityTargetData> m_capacity_target;
		std::vector<ECapacityTriggerData> m_capacity_trigger;
		std::vector<EAttributeData> m_capacity_attribute;
	};
}