#pragma once

#include "CapacityActionData.hpp"

#include <vector>
#include <string>

namespace capacity_action {

	using capacity::CapacityActionData;
	using capacity::ECapacityTargetData;

	/// <summary>
	/// Base class for Capacity Action.
	/// Capacity Action is one simple action who is part of a Capacity
	/// </summary>
	class BaseCapacityActionSystem {
	public:
		BaseCapacityActionSystem(const std::vector<ECapacityTargetData>& targets) 
			: m_targets(targets) {}
		virtual ~BaseCapacityActionSystem() = default;

		virtual CapacityActionData doAction() {
			m_capacity_action_data.m_targets = m_targets;
			return m_capacity_action_data;
		}

		virtual std::vector<ECapacityTargetData> getTargets() const { return m_targets; }

	protected:

		CapacityActionData m_capacity_action_data;

	private:

		std::vector<ECapacityTargetData> m_targets;
	};
}