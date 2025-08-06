#pragma once

#include "IResolutionCapacity.hpp"

namespace resolution_capacity {

	/// <summary>
	/// Default resolution when an entity life is modified.
	/// </summary>
	class ResolutionLifeDefault : public IResolutionCapacity {
	public:

		void resolveCapacity(CapacityDTO& capacity_dto, BaseEntity& target) override {

		}
	};
}
