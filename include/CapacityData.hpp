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
		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
		std::queue<CapacityActionData> m_capacity_dto_queue;
		std::vector<ECapacityPurposeData> m_capacity_purpose;
		std::vector<ECapacityTargetData> m_capacity_target;
		std::vector<ECapacityTriggerData> m_capacity_trigger;
		std::vector<EAttributeData> m_capacity_attribute;
	};
}