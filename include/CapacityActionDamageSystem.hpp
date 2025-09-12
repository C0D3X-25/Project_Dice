#pragma once

#include "BaseCapacityActionSystem.hpp"
#include "CapacityActionData.hpp"

#include <cstdint>
#include <vector>

namespace capacity_action {

	class CapacityActionDamageSystem : public BaseCapacityActionSystem {
	public:
		CapacityActionDamageSystem(const uint8_t damage, const std::vector<ECapacityTargetData>& targets);

		CapacityActionData doAction(void) override;

	private:
		uint8_t m_damage{ 0 };
	};
}
