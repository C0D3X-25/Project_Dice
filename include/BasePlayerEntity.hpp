#pragma once

#include "BaseEntity.hpp"
#include "BaseCapacity.hpp"
#include "DiceCapacity.hpp"
#include "ICapacityResolution.hpp"
#include "CapacityResolution.hpp"
#include "SFind.hpp"
#include "BaseArmorResolution.hpp"
#include "BaseDeathResolution.hpp"
#include "BaseLifeResolution.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <cstdint>



namespace entity {

	using namespace dice;
	using namespace capacity;
	using namespace capacity_resolution;

	inline constexpr uint8_t BASE_MAX_LIFE{ 20 };
	inline constexpr uint8_t BASE_MIN_LIFE{ 1 };
	inline constexpr uint8_t BASE_MAX_ARMOR{ 2 };
	inline constexpr uint8_t BASE_MIN_ARMOR{ 0 };

	class BasePlayerEntity : public BaseEntity, 
		public ICapacityResolution {
	
	public:
		BasePlayerEntity(const std::string& name);
		virtual ~BasePlayerEntity(void) = default;
		//BasePlayerEntity(const BasePlayerEntity& other);
		//BasePlayerEntity& operator=(const BasePlayerEntity& other);

		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param sp_capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const BaseCapacity& sp_capacity, const uint8_t side);

		const BaseCapacity rollDiceCapacity(void);
		
		//void useCapacity(const BaseCapacity& capacity, BaseEntity& target) override;


		void printEntity(void) const override;

		void resetToDefaultValues(void) {
			updateEntity();
			m_current_life = m_max_life;
			m_current_armor = m_max_armor;
		}

	//protected:

		void updateEntity(void) override {
			calculateMaxLife();
			calculateMaxArmor();
			setResolution();
		}

		void resolveCapacity(CapacityDTO& capacity_comp, BaseEntity& target) override {
			m_capacity_resolution.resolveCapacity(capacity_comp, target);
		}

	private:

		void calculateMaxLife(void) {

			int16_t max_life{ BASE_MAX_LIFE };
			// TODO: max_life += bonus_life;
			max_life += int16_t(m_attributes.getConstitution() * 1.5);

			setMaxLife(max_life);
		}


		// Calculate the maximum armor value based on the attributes
		// best physic = max(strength, dexterity)
		// best psychic = max(wisdom, intelligence, charisma)
		// max_armor = base_max_armor + best_physic + best_psychic
		void calculateMaxArmor(void) {

			// TODO: max_armor += bonus_armor;
			int16_t best_physic{ helper::find::getHighestValue<int16_t>( m_attributes.getStrength(), m_attributes.getDexterity(), 0) };
			int16_t best_psychic{ helper::find::getHighestValue<int16_t>(m_attributes.getWisdom(), m_attributes.getIntelligence(), m_attributes.getCharisma(), 0) };
			int16_t max_armor{ BASE_MAX_ARMOR + best_physic + best_psychic };

			setMaxArmor(max_armor);
		}


		// TODO: Move this method in another class (need to work with the passives)
		void setResolution(void) {

			// Clear if there is something, like that it's the last update who is taken into account
			// Can be probably removed later.
			if (!m_capacity_resolution.isEmpty()) {
				m_capacity_resolution.clearResolutions();
			}

			std::shared_ptr<CapacityResolution> sp_armor_resolutions = std::make_shared<CapacityResolution>();
			std::shared_ptr<CapacityResolution> sp_life_resolutions = std::make_shared<CapacityResolution>();
			std::shared_ptr<CapacityResolution> sp_death_resolutions = std::make_shared<CapacityResolution>();

			sp_armor_resolutions->addResolution(std::make_shared<BaseArmorResolution>());
			sp_life_resolutions->addResolution(std::make_shared<BaseLifeResolution>());
			sp_death_resolutions->addResolution(std::make_shared<BaseDeathResolution>());

			m_capacity_resolution.addResolution(sp_armor_resolutions);
			m_capacity_resolution.addResolution(sp_life_resolutions);
			m_capacity_resolution.addResolution(sp_death_resolutions);
		}

	private:

		CapacityResolution m_capacity_resolution;
		DiceCapacity m_dice_capacity;
		// TODO: Equipment m_inventory;
		// TODO: Feat m_feat;

	};
} // namespace entity
