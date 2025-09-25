#pragma once

#include "CharacterGeneratorSystem.hpp"
#include "ListCapacityData.hpp"

namespace character {

	using capacity::ListCapacityData;

	class CharacterManager {
		public:
		CharacterSystem createNewPlayerCharacter() {

			CharacterSystem character =	m_character_generator.generateNewPlayercharacter();
			return character;
		}

		void printCharacter(const CharacterSystem& character) {
			character.printcharacter();
			DiceCapacitySystem dice_capacity = character.getDiceCapacity();

			std::cout << "\n---------- Dice Capacity ----------\n";
			for (uint8_t side = 1; side <= dice_capacity.m_SIDES_COUNT; ++side) {
				std::cout << "Side " << static_cast<int>(side) << ":\n";
				m_list_capacity.printCapacityData(dice_capacity.getCapacity(side));
				std::cout << "----------\n";
			}
		}
		
	private:
		CharacterGeneratorSystem m_character_generator;
		ListCapacityData m_list_capacity;
	};
}