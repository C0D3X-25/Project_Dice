#pragma once

#include "ICapacityResolution.hpp"

#include <iostream>
#include <vector>
#include <memory>

namespace capacity_resolution {

	// How a capacity is resolved when received
    class CapacityResolution : public ICapacityResolution {
    public:

        // TODO: Change by a linked list and add weight to each resolution for having an order of resolution
        void addResolution(std::shared_ptr<ICapacityResolution> sp_resolution) {
			if (!sp_resolution) {
				std::cerr << "Error: Attempted to add a null resolution.\n";
				return;
			}
			std::cout << "Adding resolution: " << typeid(*sp_resolution).name() << "\n";
            m_sp_resolutions.push_back(sp_resolution);
        }


        std::shared_ptr<ICapacityResolution> getResolution(int index) {
            return m_sp_resolutions.at(index);
        }


		bool isEmpty(void) const {
			return m_sp_resolutions.empty();
		}


		void clearResolutions(void) {
			m_sp_resolutions.clear();
		}


        void resolveCapacity(CapacityDTO& capacity_comp, BaseEntity& target) override {
			for (auto& resolution : m_sp_resolutions) {
				resolution->resolveCapacity(capacity_comp, target);
			}
        }

    private:
		std::vector<std::shared_ptr<ICapacityResolution>> m_sp_resolutions;
    };
}
