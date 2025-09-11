#pragma once

#include "SFind.hpp"
#include "EStatsData.hpp"

#include <cstdint>
#include <iostream>
#include <string>

namespace character {

	/// <summary>
	/// Struct to hold the stats of a character.
	/// </summary>
	struct StatsData {

		void printAllStats() const {
			std::cout
				<< m_name
				<< " || " << m_life << "/" << m_max_life << " Life "
				<< " | " << m_armor << "/" << m_max_armor << " Armor "
				<< '\n';
		}
		
		void setStats(const EStatsData stats, const int16_t value) {
			switch (stats) {
			case character::MAX_LIFE:
				m_max_life = value;
				break;
			case character::LIFE:
				m_life = value;
				break;
			case character::MAX_ARMOR:
				m_max_armor = value;
				break;
			case character::ARMOR:
				m_armor = value;
				break;
			default:
				break;
			}
		}

		void setStatsInString(const EStatsData stats, const std::string& value) {
			switch (stats) {
			case character::NAME:
				m_name = value;
				break;
			default:
				break;
			}
		}

		int16_t getStats(const EStatsData stats) const {
			switch (stats) {
			case character::MAX_LIFE:
				return m_max_life;
				break;
			case character::LIFE:
				return m_life;
				break;
			case character::MAX_ARMOR:
				return m_max_armor;
				break;
			case character::ARMOR:
				return m_armor;
				break;
			default:
				break;
			}
		}

		std::string getStatsInString(const EStatsData stats) const {
			switch (stats) {
			case character::NAME:
				return m_name;
				break;
			default:
				break;
			}
		}

	private:
		std::string m_name{ "N/A" };
		int16_t m_max_life{ 0 };
		int16_t m_life{ 0 };
		int16_t m_max_armor{ 0 };
		int16_t m_armor{ 0 };
	};
}
