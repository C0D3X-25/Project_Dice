#pragma once

#include "BaseCapacityActionSystem.hpp"

#include <cstdint>

namespace capacity_action {

	using capacity::CapacityActionData;

	class CapacityActionHealSystem : public BaseCapacityActionSystem {
	public:
		CapacityActionHealSystem(const uint8_t heal, const std::vector<ECapacityTargetData>& targets);

		CapacityActionData doAction() override;

	private:
		uint8_t m_heal{ 0 };
	};
}