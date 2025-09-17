#pragma once

#include "SFindSystem.hpp"
#include "EAttributeData.hpp"

#include <cstdint>
#include <iostream>

namespace attribute {

	inline constexpr int8_t ATTRIBUTE_MIN_VALUE{ -10 };
	inline constexpr int8_t ATTRIBUTE_MAX_VALUE{ 30 };

	/// <summary>
	/// Struct to hold the attributes of a character.
	/// Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma.
	/// Minimum value is -10.
	/// Maximum value is 30
	/// </summary>
	struct AttributeData {

		void printAllAttributesData(void) const;

		void setAttributeData(const EAttributeData attribute_type, int8_t value);
		int8_t getAttributeData(const EAttributeData attribute_type) const;

	private:
		int8_t m_strength{ 0 };
		int8_t m_dexterity{ 0 };
		int8_t m_constitution{ 0 };
		int8_t m_intelligence{ 0 };
		int8_t m_wisdom{ 0 };
		int8_t m_charisma{ 0 };
	};
}
