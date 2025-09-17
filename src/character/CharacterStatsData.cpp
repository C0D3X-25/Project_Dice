#include "CharacterStatsData.hpp"
#include "CharacterStatsData.hpp"
#include "CharacterStatsData.hpp"
#include "CharacterStatsData.hpp"
#include "../../include/CharacterStatsData.hpp"

void character::CharacterStatsData::printCharacterStats() const {
	std::cout
		<< m_name
		<< " || " << m_life << "/" << m_max_life << " Life "
		<< " | " << m_armor << "/" << m_max_armor << " Armor "
		<< '\n';
}

void character::CharacterStatsData::setCharacterStats(const ECharacterStatsData stats, const int16_t value) {
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

void character::CharacterStatsData::setCharacterStatsInString(const ECharacterStatsData stats, const std::string& value) {
	switch (stats) {
	case character::NAME:
		m_name = value;
		break;
	default:
		break;
	}
}

int16_t character::CharacterStatsData::getCharacterStats(const ECharacterStatsData stats) const {
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

std::string character::CharacterStatsData::getCharacterStatsInString(const ECharacterStatsData stats) const {
	switch (stats) {
	case character::NAME:
		return m_name;
		break;
	default:
		break;
	}
}
