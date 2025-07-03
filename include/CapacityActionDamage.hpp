#pragma once

#include "BaseCapacityAction.hpp"
#include "CapacityComponent.hpp"

#include <cstdint>
#include <vector>

namespace capacity_action {

	class CapacityActionDamage : public BaseCapacityAction {
	public:
		CapacityActionDamage(const uint8_t damage, const std::vector<ECapacityTarget>& targets);

		CapacityComponent doAction(void) override;

	private:
		uint8_t m_damage{ 0 };
	};
}
