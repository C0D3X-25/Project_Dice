#pragma once

#include "CapacityActionData.hpp"
#include "ECapacityData.hpp"

#include <vector>
#include <string>

namespace capacity_action {

	using capacity::CapacityActionData;
	using capacity::ECapacityTargetData;

	/// <summary>
	/// Base class for Capacity Action.
	/// Capacity Action hold one DTO. This is a simple action who gonna serve in Capacities
	/// </summary>
	class BaseCapacityActionSystem {
	public:
		BaseCapacityActionSystem(const std::vector<ECapacityTargetData>& targets) 
			: m_targets(targets) {}
		virtual ~BaseCapacityActionSystem(void) = default;

		virtual CapacityActionData doAction(void) {
			m_capacity_dto.m_targets = m_targets;
			return m_capacity_dto;
		}

		virtual std::vector<ECapacityTargetData> getTargets(void) const { return m_targets; }

	protected:

		CapacityActionData m_capacity_dto;

	private:

		std::vector<ECapacityTargetData> m_targets;
	};
}