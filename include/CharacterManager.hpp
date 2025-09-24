#pragma once

#include "CharacterGeneratorSystem.hpp"
#include "ListCapacityData.hpp"

namespace character {
	class CharacterManager {
		public:
		CharacterManager() = default;
		~CharacterManager() = default;
		CharacterSystem createNewPlayerCharacter() {

			CharacterSystem character =	m_character_generator.generateNewPlayercharacter();
			printCharacter(character);
			return character;
		}

		void printCharacter(const CharacterSystem& character) {
			character.printcharacter();
			character.getDiceCapacity().printDiceSides();
		}
		
	private:
		CharacterGeneratorSystem m_character_generator;
		ListCapacityData m_list_capacity;
	};
}