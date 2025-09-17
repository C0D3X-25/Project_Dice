#pragma once
#include "ECapacityTargetData.hpp"

#include <cstdint>
#include <vector>
#include <memory>

namespace capacity {

	/// <summary>
	/// Represent the data who need to be transfered when a character use a capacity, from source to target.
	/// </summary>
	struct CapacityActionData {

		/// <summary>
		/// Vector holding elements of type ECapacityTargetData, 
		/// because a capacity can have multiple actions who have different targets.
		/// </summary>
		std::vector<ECapacityTargetData> m_targets;

		uint16_t m_damage{ 0 };
		uint16_t m_heal{ 0 };

		uint16_t m_add_armor{ 0 };
		uint16_t m_remove_armor{ 0 };

		
		// TODO: Status
	};
}
