#pragma once

#include "ICapacityResolution.hpp"

namespace capacity_resolution {


	class BaseLifeResolution : public ICapacityResolution {
	public:

		void resolveCapacity(CapacityComponent& capacity_comp, BaseEntity& target) override {

		}
	};
}
