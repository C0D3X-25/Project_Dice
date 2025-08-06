#pragma once

#include "ICapacityResolution.hpp"

namespace capacity_resolution {


	class BaseDeathResolution : public ICapacityResolution {
	public:

		void resolveCapacity(CapacityDTO& capacity_comp, BaseEntity& target) override {

		}
	};
}
