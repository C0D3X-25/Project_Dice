#pragma once 

//#include "IPassive.hpp"
//#include "IResolutionCapacity.hpp"
#include "SFind.hpp"
#include "EAttribute.hpp"
#include "EStatsData.hpp"
#include "BaseCapacity.hpp"
//#include "DiceCapacity.hpp"
#include "CapacityDTO.hpp"
#include "AttributeData.hpp"
#include "StatsData.hpp"
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
    using attribute::AttributeData;
    using attribute::EAttribute;
	//using dice::DiceCapacity;

    /// <summary>
    /// Base Class for any character.
    /// </summary>
    class CharacterSystem /*: public IResolutionCapacity*/ {
    public:
        CharacterSystem(const std::string& name);
        CharacterSystem(const std::string& name, const int16_t max_life, const int16_t max_armor);
        ~CharacterSystem() = default;

        void updateAttributes(const AttributeData& update_attributes);
        //void addPassive(passive::IPassive& sp_passive) { m_passive.addPassive(sp_passive); }



		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param sp_capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const BaseCapacity& capacity, const uint8_t side);

		const BaseCapacity rollDiceCapacity();

		//void useCapacity(const BaseCapacity& capacity, CharacterSystem& target) override;


		void printcharacter() const;

		void resetToDefaultValues() {
			updatecharacter();
			setStats(EStatsData::LIFE, getStats(EStatsData::MAX_LIFE));
			setStats(EStatsData::ARMOR, getStats(EStatsData::MAX_ARMOR));
		}


		void updatecharacter() {
			calculateMaxLife();
			calculateMaxArmor();
			//setResolution();
		}

		//void resolveCapacity(CapacityDTO& capacity_comp, CharacterSystem& target) {
		//	m_capacity_resolution.resolveCapacity(capacity_comp, target);
		//}

        std::string getcharacterName()								const { return m_stats.getStatsInString(EStatsData::NAME); }
		int8_t getAttribute(const EAttribute attribute_type)		const { return m_attributes.getAttribute(attribute_type); }
		int8_t getBonusAttribute(const EAttribute attribute_type)	const { return m_bonus_attributes.getAttribute(attribute_type); }
		int8_t getStats(const EStatsData stats)						const { return m_stats.getStats(stats); }

        void setcharacterName(const std::string& name)							{ m_stats.setStatsInString(EStatsData::NAME, name); }
		void setAttribute(const EAttribute attribute_type, int8_t value)		{ m_attributes.setAttribute(attribute_type, value); }
		void setBonusAttribute(const EAttribute attribute_type, int8_t value)	{ m_bonus_attributes.setAttribute(attribute_type, value); }
		void setStats(const EStatsData stats, int16_t value)					{ m_stats.setStats(stats, value); }

	private:

		void calculateMaxLife() {

			int16_t max_life{ BASE_MAX_LIFE };
			// TODO: max_life += bonus_life;
			max_life += int16_t(m_attributes.getAttribute(attribute::CONSTITUTION) * 1.5);

			setStats(EStatsData::MAX_LIFE, max_life);
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

			setStats(EStatsData::MAX_ARMOR, max_armor);
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
			// TODO: m_passives[];
			// TODO: m_status;
			// TODO: m_feat;
			AttributeData m_attributes;
			AttributeData m_bonus_attributes;
			StatsData m_stats;
			//ResolutionCapacity m_capacity_resolution;
			//DiceCapacity m_dice_capacity;
			// TODO: Equipment m_equipment;

	};
} // namespace character
