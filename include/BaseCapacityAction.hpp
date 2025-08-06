#pragma once

#include "CapacityDTO.hpp"
#include "ECapacity.hpp"

#include <vector>
#include <string>

namespace capacity_action {

	using capacity::CapacityDTO;
	using capacity::ECapacityTarget;

	/// <summary>
	/// Base class for Capacity Action.
	/// Capacity Action hold one DTO. This is a simple action who gonna serve in Capacities
	/// </summary>
	class BaseCapacityAction {
	public:
		BaseCapacityAction(const std::vector<ECapacityTarget>& targets) 
			: m_targets(targets) {}
		virtual ~BaseCapacityAction(void) = default;

		virtual CapacityDTO doAction(void) {
			m_capacity_dto.m_targets = m_targets;
			return m_capacity_dto;
		}

		virtual std::vector<ECapacityTarget> getTargets(void) const { return m_targets; }

	protected:

		CapacityDTO m_capacity_dto;

	private:

		std::vector<ECapacityTarget> m_targets;
	};
}