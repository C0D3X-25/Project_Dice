#pragma once

#include ".\BaseCapacityAction.hpp"
#include "CapacityComponent.hpp"

#include <cstdint>

namespace capacity_action {

	using capacity::CapacityComponent;

	class CapacityActionHeal : public BaseCapacityAction {
	public:
		CapacityActionHeal(const uint8_t heal, const std::vector<ECapacityTarget>& targets);

		CapacityComponent doAction(void) override;

	private:
		CapacityComponent m_component;
		uint8_t m_heal{ 0 };
	};
}