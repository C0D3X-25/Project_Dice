#pragma once

#include "IResolutionCapacity.hpp"
#include "SFind.hpp"

namespace resolution_capacity {

	/// <summary>
	/// Default resolution when the character armor is modified.
	/// When taking damage, the armor will absorb the damage taken first.
	/// Min armor is 0.
	/// </summary>
	class ResolutionArmorDefault : public IResolutionCapacity {
	public:

		void resolveCapacity(CapacityDTO& capacity_dto, Character& target) override {

			std::cout << "Resolving component remove armor: " << capacity_dto.m_remove_armor << "\n";
			std::cout << "character armor before: " << target.getCurrentArmor() << "\n";

			// 1st - Remove armor
			if (capacity_dto.m_remove_armor != 0 && target.getCurrentArmor() > 0) {
				if (capacity_dto.m_remove_armor > target.getCurrentArmor()) {
					target.setCurrentArmor(0);
				}
				else {
					target.setCurrentArmor(target.getCurrentArmor() - capacity_dto.m_remove_armor);
				}
			}

			std::cout << "character armor after remove: " << target.getCurrentArmor() << "\n";
			std::cout << "-----------------\n";
			std::cout << "Resolving component damage: " << capacity_dto.m_damage << "\n";

			// 2nd - Damage to armor
			if (capacity_dto.m_damage != 0 && target.getCurrentArmor() > 0) {
				if (capacity_dto.m_damage >= target.getCurrentArmor()) {
					// If the damage is greater than the current armor, set armor to 0
					target.setCurrentArmor(0);
					// And apply the remaining damage to life
					capacity_dto.m_damage = capacity_dto.m_damage - target.getCurrentArmor();
				}
				else {
					target.setCurrentArmor(target.getCurrentArmor() - capacity_dto.m_damage);
				}
			}

			std::cout << "character armor after damage: " << target.getCurrentArmor() << "\n";
			std::cout << "-----------------\n";
			std::cout << "Resolving component add armor: " << capacity_dto.m_add_armor << "\n";

			// 3rd - Add armor
			if (capacity_dto.m_add_armor != 0) {
				int16_t new_armor = target.getCurrentArmor() + capacity_dto.m_add_armor;
				if (new_armor > target.getMaxArmor()) {
					target.setCurrentArmor(target.getMaxArmor());
				}
				else {
					target.setCurrentArmor(new_armor);
				}
			}

			std::cout << "character armor after add: " << target.getCurrentArmor() << "\n";
			

			target.printcharacter();
		}
	};
}
