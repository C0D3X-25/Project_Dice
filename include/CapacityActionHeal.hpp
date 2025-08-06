#pragma once

#include ".\BaseCapacityAction.hpp"
#include "CapacityDTO.hpp"

#include <cstdint>

namespace capacity_action {

	using capacity::CapacityDTO;

	class CapacityActionHeal : public BaseCapacityAction {
	public:
		CapacityActionHeal(const uint8_t heal, const std::vector<ECapacityTarget>& targets);

		CapacityDTO doAction(void) override;

	private:
		CapacityDTO m_capacity_dto;
		uint8_t m_heal{ 0 };
	};
}