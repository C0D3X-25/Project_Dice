#pragma once

#include "BaseCapacityAction.hpp"
#include "CapacityComponent.hpp"

#include <cstdint>

namespace capacity_action {

	using capacity::CapacityComponent;

	class CapacityActionRemoveArmor : public BaseCapacityAction {
	public:
		CapacityActionRemoveArmor(const uint8_t armor, const std::vector<ECapacityTarget>& targets);

		CapacityComponent doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
	};
}
