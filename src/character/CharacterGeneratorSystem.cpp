#include "CharacterGeneratorSystem.hpp"

using namespace character;

CharacterSystem character::CharacterGeneratorSystem::generateNewPlayercharacter() {

	auto new_character = CharacterSystem("Generated character");

	generateAttributes(new_character);


	new_character.resetToDefaultValues();

	return new_character;
}

// Roll for each attributes is between 6 (4 + 1 + 1) and 12 (4 + 4 + 4)
// Final value of an attribute without other modifiers is between -4 and 2
void character::CharacterGeneratorSystem::generateAttributes(CharacterSystem& character) {

	constexpr int8_t BASE_VALUE{ attribute::ATTRIBUTE_MIN_VALUE + 4 };
	constexpr uint8_t DICE_SIDES{ 4 };
	constexpr uint8_t DICE_NBR_ROLLS{ 2 };

	AttributeData generated_attributes;

	generated_attributes.setAttributeData(attribute::STRENGTH, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
	generated_attributes.setAttributeData(attribute::DEXTERITY, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
	generated_attributes.setAttributeData(attribute::CONSTITUTION, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
	generated_attributes.setAttributeData(attribute::INTELLIGENCE, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
	generated_attributes.setAttributeData(attribute::WISDOM, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));
	generated_attributes.setAttributeData(attribute::CHARISMA, getRandomValue(DICE_SIDES, DICE_NBR_ROLLS, BASE_VALUE));

	character.updateAttributes(generated_attributes);
}

int8_t character::CharacterGeneratorSystem::getRandomValue(uint8_t max_value, uint8_t nbr_roll, int8_t base_value) {

	int8_t total{ base_value };

	for (uint8_t roll{ 0 }; roll < nbr_roll; roll++) {
		total += helper::random::generateRandomValue(max_value, 1);
	}

	return total;
}
