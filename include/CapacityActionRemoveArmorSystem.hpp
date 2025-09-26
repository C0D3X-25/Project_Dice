#pragma once

#include "BaseCapacityActionSystem.hpp"

namespace capacity_action {

	using capacity::CapacityActionData;

	class CapacityActionRemoveArmorSystem : public BaseCapacityActionSystem {
	public:
		CapacityActionRemoveArmorSystem(const uint8_t armor, const std::vector<ECapacityTargetData>& targets);

		CapacityActionData doAction() override;

	private:
		uint8_t m_armor{ 0 };
	};
}
