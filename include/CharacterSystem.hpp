#pragma once 

//#include "IPassive.hpp"
//#include "IResolutionCapacity.hpp"
#include "SFindSystem.hpp"
#include "EAttributeData.hpp"
#include "ECharacterStatsData.hpp"
//#include "CapacitySystem.hpp"
#include "DiceCapacitySystem.hpp" // TODO: Should be moved ?
//#include "CapacityActionData.hpp"
#include "AttributeData.hpp"
#include "CharacterStatsData.hpp"
//#include "ResolutionCapacity.hpp"
//#include "ResolutionArmorDefault.hpp"
//#include "ResolutionDeathDefault.hpp"
//#include "ResolutionLifeDefault.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <string_view>
#include <cstdint>

namespace dice {
	class DiceCapacitySystem;
}

namespace attribute {
	enum EAttributeData;
	struct AttributeData;
}

namespace character {

	inline constexpr uint8_t BASE_MAX_LIFE{ 20 };
	inline constexpr uint8_t BASE_MIN_LIFE{ 1 };
	inline constexpr uint8_t BASE_MAX_ARMOR{ 2 };
	inline constexpr uint8_t BASE_MIN_ARMOR{ 0 };

    //using capacity::CapacitySystem;
    //using capacity::CapacityActionData;
    using attribute::AttributeData;
    using attribute::EAttributeData;
	using dice::DiceCapacitySystem;

    /// <summary>
    /// Base Class for any character.
    /// </summary>
    class CharacterSystem /*: public IResolutionCapacity*/ {
    public:
        CharacterSystem(const std::string& name);
        CharacterSystem(const std::string& name, const int16_t max_life, const int16_t max_armor);

        void updateAttributes(const AttributeData& update_attributes);

		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param sp_capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		//void setCapacity(const CapacitySystem& capacity, const uint8_t side);

		//const CapacitySystem rollDiceCapacity();

		//void useCapacity(const CapacitySystem& capacity, CharacterSystem& target) override;


		void printcharacter() const;

		void resetToDefaultValues() {
			updatecharacter();
			setStats(ECharacterStatsData::LIFE, getStats(ECharacterStatsData::MAX_LIFE));
			setStats(ECharacterStatsData::ARMOR, getStats(ECharacterStatsData::MAX_ARMOR));
		}


		void updatecharacter() {
			calculateMaxLife();
			calculateMaxArmor();
			//setResolution();
		}

		//void resolveCapacity(CapacityActionData& capacity_comp, CharacterSystem& target) {
		//	m_capacity_resolution.resolveCapacity(capacity_comp, target);
		//}

        std::string getcharacterName()									const { return m_stats.getCharacterStatsInString(ECharacterStatsData::NAME); }
		int8_t getAttribute(const EAttributeData attribute_type)		const { return m_attributes.getAttributeData(attribute_type); }
		int8_t getBonusAttribute(const EAttributeData attribute_type)	const { return m_temp_attributes.getAttributeData(attribute_type); }
		int8_t getStats(const ECharacterStatsData stats)							const { return m_stats.getCharacterStats(stats); }

        void setcharacterName(const std::string& name)								{ m_stats.setCharacterStatsInString(ECharacterStatsData::NAME, name); }
		void setAttribute(const EAttributeData attribute_type, int8_t value)		{ m_attributes.setAttributeData(attribute_type, value); }
		void setBonusAttribute(const EAttributeData attribute_type, int8_t value)	{ m_temp_attributes.setAttributeData(attribute_type, value); }
		void setStats(const ECharacterStatsData stats, int16_t value)						{ m_stats.setCharacterStats(stats, value); }

	private:

		/// <summary>
		/// Calculates the maximum life value.
		/// </summary>
		void calculateMaxLife();


		/// <summary>
		/// Calculates the maximum armor value.
		/// </summary>
		void calculateMaxArmor();


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
			CharacterStatsData m_stats;
			DiceCapacitySystem m_dice_capacity;
			AttributeData m_attributes;
			AttributeData m_temp_attributes;
			//ResolutionCapacity m_capacity_resolution;
			// TODO: Equipment m_equipment;

	};
} // namespace character
