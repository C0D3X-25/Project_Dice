#pragma once

#include "SFindSystem.hpp"
#include "ECharacterStatsData.hpp"

#include <cstdint>
#include <iostream>
#include <string>

namespace character {

	/// <summary>
	/// Struct to hold the stats of a character.
	/// </summary>
	struct CharacterStatsData {

		void printCharacterStats() const;
		
		void setCharacterStats(const ECharacterStatsData stats, const int16_t value);
		void setCharacterStatsInString(const ECharacterStatsData stats, const std::string& value);

		int16_t getCharacterStats(const ECharacterStatsData stats) const;
		std::string getCharacterStatsInString(const ECharacterStatsData stats) const;

	private:
		std::string m_name{ "N/A" };
		int16_t m_max_life{ 0 };
		int16_t m_life{ 0 };
		int16_t m_max_armor{ 0 };
		int16_t m_armor{ 0 };
	};
}
