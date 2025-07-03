#pragma once

#include <cstdint>
#include <iostream>
#include "SCalculate.hpp"

namespace attribute {

	inline constexpr int8_t ATTRIBUTE_MIN_VALUE{ -10 };

	/// <summary>
	/// Struct to hold the stats of an entity.
	/// Minimum value is -10.
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

		void setStrength(int8_t value) { m_strength = helper::calculate::getBestValue(value, ATTRIBUTE_MIN_VALUE); }
		void setDexterity(int8_t value) { m_dexterity = helper::calculate::getBestValue(value, ATTRIBUTE_MIN_VALUE); }
		void setConstitution(int8_t value) { m_constitution = helper::calculate::getBestValue(value, ATTRIBUTE_MIN_VALUE); }
		void setIntelligence(int8_t value) { m_intelligence = helper::calculate::getBestValue(value, ATTRIBUTE_MIN_VALUE); }
		void setWisdom(int8_t value) { m_wisdom = helper::calculate::getBestValue(value, ATTRIBUTE_MIN_VALUE); }
		void setCharisma(int8_t value) { m_charisma = helper::calculate::getBestValue(value, ATTRIBUTE_MIN_VALUE); }

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
