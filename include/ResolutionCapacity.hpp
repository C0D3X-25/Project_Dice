#pragma once

#include "IResolutionCapacity.hpp"

#include <iostream>
#include <vector>
#include <memory>

namespace resolution_capacity {

    /// <summary>
    /// Manages a collection of capacity resolution strategies and applies them to resolve capacity for a target entity.
    /// </summary>
    class ResolutionCapacity : public IResolutionCapacity {
    public:

        // TODO: Change by a linked list and add weight to each resolution for having an order of resolution
        void addResolution(std::shared_ptr<IResolutionCapacity> sp_resolution) {
			if (!sp_resolution) {
				std::cerr << "Error: Attempted to add a null resolution.\n";
				return;
			}
			std::cout << "Adding resolution: " << typeid(*sp_resolution).name() << "\n";
            m_sp_resolutions.push_back(sp_resolution);
        }


        std::shared_ptr<IResolutionCapacity> getResolution(int index) {
            return m_sp_resolutions.at(index);
        }


		bool isEmpty(void) const {
			return m_sp_resolutions.empty();
		}


		void clearResolutions(void) {
			m_sp_resolutions.clear();
		}


        void resolveCapacity(CapacityDTO& capacity_dto, BaseEntity& target) override {
			for (auto& resolution : m_sp_resolutions) {
				resolution->resolveCapacity(capacity_dto, target);
			}
        }

    private:
		std::vector<std::shared_ptr<IResolutionCapacity>> m_sp_resolutions;
    };
}
