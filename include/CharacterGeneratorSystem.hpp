#pragma once

#include "CharacterSystem.hpp"
//#include "AttributeData.hpp"
#include "SRandomSystem.hpp"

#include <iostream>
#include <memory>
#include <cstdint>


namespace character {

	class CharacterGeneratorSystem {
	public:

		CharacterSystem generateNewPlayercharacter();

	private:

		void generateAttributes(CharacterSystem& character);

		int8_t getRandomValue(uint8_t max_value, uint8_t nbr_roll = 1, int8_t base_value = 0);
	};
}
