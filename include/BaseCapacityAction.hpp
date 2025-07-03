#pragma once

#include "CapacityComponent.hpp"
#include "ECapacity.hpp"

#include <vector>
#include <string>

namespace capacity_action {

	using capacity::CapacityComponent;
	using capacity::ECapacityTarget;

	class BaseCapacityAction {
	public:
		BaseCapacityAction(const std::vector<ECapacityTarget>& targets) 
			: m_targets(targets) {}
		virtual ~BaseCapacityAction(void) = default;

		virtual CapacityComponent doAction(void) {
			m_component.m_targets = m_targets;
			return m_component;
		}

		virtual std::vector<ECapacityTarget> getTargets(void) const { return m_targets; }

	protected:

		CapacityComponent m_component;

	private:

		std::vector<ECapacityTarget> m_targets;
	};
}