#pragma once

#include "IResolutionCapacity.hpp"

namespace resolution_capacity {

	/// <summary>
	/// Default resolution when an character die.
	/// </summary>
	class ResolutionDeathDefault : public IResolutionCapacity {
	public:

		void resolveCapacity(CapacityDTO& capacity_dto, Character& target) override {

		}
	};
}
