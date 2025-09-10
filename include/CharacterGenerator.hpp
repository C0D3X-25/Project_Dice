#pragma once

#include "Character.hpp"
#include "AttributeData.hpp"
#include "SRandom.hpp"

#include <iostream>
#include <memory>
#include <cstdint>


namespace character {

	class CharacterGenerator {
	public:
		CharacterGenerator(void) = default;
		~CharacterGenerator(void) = default;

		Character generateNewPlayercharacter(void) {

			auto new_character = Character("Generated character");

			generateAttributes(new_character);


			new_character.resetToDefaultValues();

			return new_character;
		}

	private:

		// Roll for each attributes is between 6 (4 + 1 + 1) and 12 (4 + 4 + 4)
		// Final value of an attribute without other modifiers is between -4 and 2
		void generateAttributes(Character& character) {

			constexpr int8_t BASE_VALUE{ attribute::ATTRIBUTE_MIN_VALUE + 4 };
			constexpr uint8_t DICE_SIDES{ 4 };
			constexpr uint8_t DICE_NBR_ROLLS{ 2 };

			AttributeData generated_attributes;

			generated_attributes.setAttribute(attribute::STRENGTH, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
			generated_attributes.setAttribute(attribute::DEXTERITY, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
			generated_attributes.setAttribute(attribute::CONSTITUTION, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
			generated_attributes.setAttribute(attribute::INTELLIGENCE, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
			generated_attributes.setAttribute(attribute::WISDOM, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
			generated_attributes.setAttribute(attribute::CHARISMA, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));

			character.updateAttributes(generated_attributes);
		}


		int8_t getRandomValue(uint8_t max_value, uint8_t nbr_roll = 1, int8_t base_value = 0) {

			int8_t total{ base_value };

			for (uint8_t roll{ 0 }; roll < nbr_roll; roll++) {
				total += helper::random::generateRandomValue(max_value, 1);
			}

			return total;
		}
	};
}
