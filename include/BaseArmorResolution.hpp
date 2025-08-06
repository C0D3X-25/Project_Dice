#pragma once

#include "ICapacityResolution.hpp"
#include "SFind.hpp"

namespace capacity_resolution {

	// When taking damage, the armor will absorb the damage taken first
	// Min armor = 0
	// Max armor = 
	class BaseArmorResolution : public ICapacityResolution {
	public:

		void resolveCapacity(CapacityDTO& capacity_comp, BaseEntity& target) override {

			std::cout << "Resolving component remove armor: " << capacity_comp.m_remove_armor << "\n";
			std::cout << "Entity armor before: " << target.getCurrentArmor() << "\n";

			// 1st - Remove armor
			if (capacity_comp.m_remove_armor != 0 && target.getCurrentArmor() > 0) {
				if (capacity_comp.m_remove_armor > target.getCurrentArmor()) {
					target.setCurrentArmor(0);
				}
				else {
					target.setCurrentArmor(target.getCurrentArmor() - capacity_comp.m_remove_armor);
				}
			}

			std::cout << "Entity armor after remove: " << target.getCurrentArmor() << "\n";
			std::cout << "-----------------\n";
			std::cout << "Resolving component damage: " << capacity_comp.m_damage << "\n";

			// 2nd - Damage to armor
			if (capacity_comp.m_damage != 0 && target.getCurrentArmor() > 0) {
				if (capacity_comp.m_damage >= target.getCurrentArmor()) {
					// If the damage is greater than the current armor, set armor to 0
					target.setCurrentArmor(0);
					// And apply the remaining damage to life
					capacity_comp.m_damage = capacity_comp.m_damage - target.getCurrentArmor();
				}
				else {
					target.setCurrentArmor(target.getCurrentArmor() - capacity_comp.m_damage);
				}
			}

			std::cout << "Entity armor after damage: " << target.getCurrentArmor() << "\n";
			std::cout << "-----------------\n";
			std::cout << "Resolving component add armor: " << capacity_comp.m_add_armor << "\n";

			// 3rd - Add armor
			if (capacity_comp.m_add_armor != 0) {
				int16_t new_armor = target.getCurrentArmor() + capacity_comp.m_add_armor;
				if (new_armor > target.getMaxArmor()) {
					target.setCurrentArmor(target.getMaxArmor());
				}
				else {
					target.setCurrentArmor(new_armor);
				}
			}

			std::cout << "Entity armor after add: " << target.getCurrentArmor() << "\n";
			

			target.printEntity();
		}
	};
}
