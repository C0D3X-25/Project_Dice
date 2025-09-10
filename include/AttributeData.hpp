#pragma once

#include "SFind.hpp"
#include "EAttribute.hpp"

#include <cstdint>
#include <iostream>

namespace attribute {

	inline constexpr int8_t ATTRIBUTE_MIN_VALUE{ -10 };
	inline constexpr int8_t ATTRIBUTE_MAX_VALUE{ 30 };

	/// <summary>
	/// Struct to hold the attributes of an character.
	/// Minimum value is -10.
	/// Maximum value is 30
	/// </summary>
	struct AttributeData {

		void printAllAttributes(void) const {
			std::cout
				<< "STR: " << static_cast<int>(m_strength) << '\n'
				<< "DEX: " << static_cast<int>(m_dexterity) << '\n'
				<< "CON: " << static_cast<int>(m_constitution) << '\n'
				<< "INT: " << static_cast<int>(m_intelligence) << '\n'
				<< "WIS: " << static_cast<int>(m_wisdom) << '\n'
				<< "CHA: " << static_cast<int>(m_charisma) << '\n';
		}

		void setAttribute(const EAttribute attribute_type, int8_t value) {

			int8_t safe_value = helper::find::getValueInRange(value, ATTRIBUTE_MIN_VALUE, ATTRIBUTE_MAX_VALUE);

			switch (attribute_type) {
			case attribute::STRENGTH:
				m_strength = safe_value;
				break;
			case attribute::DEXTERITY:
				m_dexterity = safe_value;
				break;
			case attribute::CONSTITUTION:
				m_constitution = safe_value;
				break;
			case attribute::INTELLIGENCE:
				m_intelligence = safe_value;
				break;
			case attribute::WISDOM:
				m_wisdom = safe_value;
				break;
			case attribute::CHARISMA:
				m_charisma = safe_value;
				break;
			default:
				break;
			}
		}


		int8_t getAttribute(const EAttribute attribute_type) const {
			switch (attribute_type) {
			case attribute::STRENGTH:
				return m_strength;
				break;
			case attribute::DEXTERITY:
				return m_dexterity;
				break;
			case attribute::CONSTITUTION:
				return m_constitution;
				break;
			case attribute::INTELLIGENCE:
				return m_intelligence;
				break;
			case attribute::WISDOM:
				return m_wisdom;
				break;
			case attribute::CHARISMA:
				return m_charisma;
				break;
			default:
				break;
			}
		}

	private:
		int8_t m_strength{ 0 };
		int8_t m_dexterity{ 0 };
		int8_t m_constitution{ 0 };
		int8_t m_intelligence{ 0 };
		int8_t m_wisdom{ 0 };
		int8_t m_charisma{ 0 };
	};
}
