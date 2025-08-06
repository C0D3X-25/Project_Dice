#pragma once

#include "BaseCapacityAction.hpp"
#include "CapacityDTO.hpp"

#include <cstdint>

namespace capacity_action {

	using capacity::CapacityDTO;

	class CapacityActionAddArmor : public BaseCapacityAction {
	public:

		CapacityActionAddArmor(const uint8_t armor, const std::vector<ECapacityTarget>& targets);

		CapacityDTO doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
	};
}