#pragma once 

//#include "IPassive.hpp"
//#include "IResolutionCapacity.hpp"
#include "SFind.hpp"
#include "EAttribute.hpp"
#include "BaseCapacity.hpp"
//#include "DiceCapacity.hpp"
#include "CapacityDTO.hpp"
#include "Attribute.hpp"
//#include "PassiveHandler.hpp"
//#include "ResolutionCapacity.hpp"
//#include "ResolutionArmorDefault.hpp"
//#include "ResolutionDeathDefault.hpp"
//#include "ResolutionLifeDefault.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <string_view>
#include <cstdint>

namespace character {

	inline constexpr uint8_t BASE_MAX_LIFE{ 20 };
	inline constexpr uint8_t BASE_MIN_LIFE{ 1 };
	inline constexpr uint8_t BASE_MAX_ARMOR{ 2 };
	inline constexpr uint8_t BASE_MIN_ARMOR{ 0 };

    using capacity::BaseCapacity;
    using capacity::CapacityDTO;
    using attribute::Attribute;
    using attribute::EAttribute;
	//using dice::DiceCapacity;

    /// <summary>
    /// Base Class for any character.
    /// </summary>
    class Character /*: public IResolutionCapacity*/ {
    public:
        Character(const std::string& name);
        Character(const std::string& name, const int16_t max_life, const int16_t max_armor);
        virtual ~Character(void) = default;

        void updateAttributes(const Attribute& update_attributes);
        //void addPassive(passive::IPassive& sp_passive) { m_passive.addPassive(sp_passive); }

        std::string_view getcharacterName(void) const { return m_name; }
        int16_t getMaxLife(void) const { return m_max_life; }
        int16_t getCurrentLife(void) const { return m_current_life; }
        int16_t getMaxArmor(void) const { return m_max_armor; }
        int16_t getCurrentArmor(void) const { return m_current_armor; }
        int8_t getAttribute(const EAttribute attribute_type) const { return m_attributes.getAttribute(attribute_type); }

        void setcharacterName(const std::string& name) { m_name = name; }
        void setMaxLife(int16_t life) { m_max_life = life; }
        void setCurrentLife(int16_t life) { m_current_life = life; }
        void setMaxArmor(int16_t armor) { m_max_armor = armor; }
        void setCurrentArmor(int16_t armor) { m_current_armor = armor; }


		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param sp_capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const BaseCapacity& sp_capacity, const uint8_t side);

		const BaseCapacity rollDiceCapacity(void);

		//void useCapacity(const BaseCapacity& capacity, Character& target) override;


		void printcharacter(void) const;

		void resetToDefaultValues(void) {
			updatecharacter();
			m_current_life = m_max_life;
			m_current_armor = m_max_armor;
		}


		void updatecharacter(void) {
			calculateMaxLife();
			calculateMaxArmor();
			//setResolution();
		}

		//void resolveCapacity(CapacityDTO& capacity_comp, Character& target) {
		//	m_capacity_resolution.resolveCapacity(capacity_comp, target);
		//}


	private:

		void calculateMaxLife(void) {

			int16_t max_life{ BASE_MAX_LIFE };
			// TODO: max_life += bonus_life;
			max_life += int16_t(m_attributes.getAttribute(attribute::CONSTITUTION) * 1.5);

			setMaxLife(max_life);
		}


		// Calculate the maximum armor value based on the attributes
		// best physic = max(strength, dexterity)
		// best psychic = max(wisdom, intelligence, charisma)
		// max_armor = base_max_armor + best_physic + best_psychic
		void calculateMaxArmor(void) {

			// TODO: max_armor += bonus_armor;
			int16_t best_physic{ helper::find::getHighestValue<int16_t>(m_attributes.getAttribute(attribute::STRENGTH), m_attributes.getAttribute(attribute::DEXTERITY), 0) };
			int16_t best_psychic{ helper::find::getHighestValue<int16_t>(m_attributes.getAttribute(attribute::WISDOM), m_attributes.getAttribute(attribute::INTELLIGENCE), m_attributes.getAttribute(attribute::CHARISMA), 0) };
			int16_t max_armor{ BASE_MAX_ARMOR + best_physic + best_psychic };

			setMaxArmor(max_armor);
		}


		// TODO: Move this method in another class (need to work with the passives)
		//void setResolution(void) {

		//	// Clear if there is something, like that it's the last update who is taken into account
		//	// Can be probably removed later.
		//	if (!m_capacity_resolution.isEmpty()) {
		//		m_capacity_resolution.clearResolutions();
		//	}

		//	std::shared_ptr<ResolutionCapacity> sp_armor_resolutions = std::make_shared<ResolutionCapacity>();
		//	std::shared_ptr<ResolutionCapacity> sp_life_resolutions = std::make_shared<ResolutionCapacity>();
		//	std::shared_ptr<ResolutionCapacity> sp_death_resolutions = std::make_shared<ResolutionCapacity>();

		//	sp_armor_resolutions->addResolution(std::make_shared<ResolutionArmorDefault>());
		//	sp_life_resolutions->addResolution(std::make_shared<ResolutionLifeDefault>());
		//	sp_death_resolutions->addResolution(std::make_shared<ResolutionDeathDefault>());

		//	m_capacity_resolution.addResolution(sp_armor_resolutions);
		//	m_capacity_resolution.addResolution(sp_life_resolutions);
		//	m_capacity_resolution.addResolution(sp_death_resolutions);
		//}

		private:
			// TODO: m_passive[];
			// TODO: m_status[];
			// TODO: m_feat[];
			Attribute m_attributes;
			Attribute m_bonus_attributes;
			std::string m_name{ "N/A" };
			int16_t m_max_life{ 0 };
			int16_t m_current_life{ 0 };
			int16_t m_max_armor{ 0 };
			int16_t m_current_armor{ 0 };
			//ResolutionCapacity m_capacity_resolution;
			//DiceCapacity m_dice_capacity;
			// TODO: Equipment m_inventory;
			// TODO: Feat m_feat;

	};
} // namespace character
