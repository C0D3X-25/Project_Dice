#pragma once

#include "CharacterGeneratorSystem.hpp"
#include "ListCapacityData.hpp"

namespace character {
	class CharacterManager {
		public:
		CharacterManager() = default;
		~CharacterManager() = default;
		CharacterSystem createNewPlayerCharacter() {
			return m_character_generator.generateNewPlayercharacter();
		}

		
	private:
		CharacterGeneratorSystem m_character_generator;
		ListCapacityData m_list_capacity;
	};
}