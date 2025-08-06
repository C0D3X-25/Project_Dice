#pragma once

#include <cstdint>
#include <iostream>
#include "SFind.hpp"

namespace attribute {

	inline constexpr int8_t ATTRIBUTE_MIN_VALUE{ -10 };
	inline constexpr int8_t ATTRIBUTE_MAX_VALUE{ 30 };

	/// <summary>
	/// Struct to hold the attributes of an entity.
	/// Minimum value is -10.
	/// Maximum value is 30
	/// </summary>
	struct Attribute {

		void printAllAttributes(void) const {
			std::cout
				<< "STR: " << static_cast<int>(m_strength) << '\n'
				<< "DEX: " << static_cast<int>(m_dexterity) << '\n'
				<< "CON: " << static_cast<int>(m_constitution) << '\n'
				<< "INT: " << static_cast<int>(m_intelligence) << '\n'
				<< "WIS: " << static_cast<int>(m_wisdom) << '\n'
				<< "CHA: " << static_cast<int>(m_charisma) << '\n';
		}

		void setStrength(int8_t value) { m_strength = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE); }
		void setDexterity(int8_t value) { m_dexterity = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE); }
		void setConstitution(int8_t value) { m_constitution = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE); }
		void setIntelligence(int8_t value) { m_intelligence = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE); }
		void setWisdom(int8_t value) { m_wisdom = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE); }
		void setCharisma(int8_t value) { m_charisma = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE); }

		int8_t getStrength(void) const { return m_strength; }
		int8_t getDexterity(void) const { return m_dexterity; }
		int8_t getConstitution(void) const { return m_constitution; }
		int8_t getIntelligence(void) const { return m_intelligence; }
		int8_t getWisdom(void) const { return m_wisdom; }
		int8_t getCharisma(void) const { return m_charisma; }

	private:
		int8_t m_strength{ 0 };
		int8_t m_dexterity{ 0 };
		int8_t m_constitution{ 0 };
		int8_t m_intelligence{ 0 };
		int8_t m_wisdom{ 0 };
		int8_t m_charisma{ 0 };
	};
}
