#include "../include/CharacterSystem.hpp"


character::CharacterSystem::CharacterSystem(const std::string& name) {
    m_stats.setCharacterStatsInString(character::NAME, name);
}


character::CharacterSystem::CharacterSystem(const std::string& name, const int16_t max_life, const int16_t max_armor) {

    m_stats.setCharacterStatsInString(character::NAME, name);
    m_stats.setCharacterStats(character::MAX_LIFE, max_life);
    m_stats.setCharacterStats(character::MAX_ARMOR, max_armor);

    resetToDefaultValues();
}


void character::CharacterSystem::updateAttributes(const AttributeData& update_attribute) {

    m_attributes.setAttributeData(attribute::STRENGTH, update_attribute.getAttributeData(attribute::STRENGTH));
    m_attributes.setAttributeData(attribute::DEXTERITY, update_attribute.getAttributeData(attribute::DEXTERITY));
    m_attributes.setAttributeData(attribute::CONSTITUTION, update_attribute.getAttributeData(attribute::CONSTITUTION));
    m_attributes.setAttributeData(attribute::INTELLIGENCE, update_attribute.getAttributeData(attribute::INTELLIGENCE));
    m_attributes.setAttributeData(attribute::WISDOM, update_attribute.getAttributeData(attribute::WISDOM));
    m_attributes.setAttributeData(attribute::CHARISMA, update_attribute.getAttributeData(attribute::CHARISMA));

    updatecharacter();
}


//void character::CharacterSystem::setCapacity(const CapacitySystem& capacity, const uint8_t side) {
//    m_dice_capacity.setCapacity(capacity, side);
//}


//const CapacitySystem character::CharacterSystem::rollDiceCapacity(void) {
//    return m_dice_capacity.roll();
//}


void character::CharacterSystem::printcharacter(void) const {

	m_stats.printCharacterStats();

    std::cout << "\n---------- Attributes ----------\n";
    m_attributes.printAllAttributesData();

    std::cout << "\n---------- Temp Attributes ----------\n";
    m_temp_attributes.printAllAttributesData();

    std::cout << "\n---------- Dice Capacity ----------\n";
    m_dice_capacity.printDiceSides();

    std::cout << "\n---------- Passives ----------\n";
    //m_passive.printListPassives();

}


void character::CharacterSystem::calculateMaxLife() {

    int16_t max_life{ BASE_MAX_LIFE };
    // TODO: max_life += bonus_life;
    max_life += int16_t(m_attributes.getAttributeData(attribute::CONSTITUTION) * 1.5);

    setStats(ECharacterStatsData::MAX_LIFE, max_life);
}


// Calculate the maximum armor value based on the attributes
// best physic = max(strength, dexterity)
// best psychic = max(wisdom, intelligence, charisma)
// max_armor = base_max_armor + best_physic + best_psychic
void character::CharacterSystem::calculateMaxArmor() {

    // TODO: max_armor += bonus_armor;
    int16_t best_physic{ helper::find::getHighestValue<int16_t>(m_attributes.getAttributeData(attribute::STRENGTH), m_attributes.getAttributeData(attribute::DEXTERITY), 0) };
    int16_t best_psychic{ helper::find::getHighestValue<int16_t>(m_attributes.getAttributeData(attribute::WISDOM), m_attributes.getAttributeData(attribute::INTELLIGENCE), m_attributes.getAttributeData(attribute::CHARISMA), 0) };
    int16_t max_armor{ BASE_MAX_ARMOR + best_physic + best_psychic };

    setStats(ECharacterStatsData::MAX_ARMOR, max_armor);
}


//void character::CharacterSystem::useCapacity(const CapacitySystem& capacity, CharacterSystem& target) {
//	std::cout
//		<< m_name
//		<< " use capacity " << capacity.getCapacityName()
//		<< " on " << target.getcharacterName()
//		<< '\n';
//
//	//target.resolveCapacity(capacity.getStats(), *this);
//}


//void character::CharacterSystem::resolveCapacity(const CapacityDTO& capacity, const CharacterSystem& source) {
    //// Initialize modifiers
    //int16_t dmg_life = capacity.m_max_life < 0 ? -capacity.m_max_life : 0;
    //int16_t heal_life = capacity.m_max_life > 0 ? capacity.m_max_life : 0;
    //int16_t remove_armor = capacity.m_max_armor < 0 ? -capacity.m_max_armor : 0;
    //int16_t add_armor = capacity.m_max_armor > 0 ? capacity.m_max_armor : 0;

    //if (dmg_life > 0) {
    //    std::cout << m_name << " took (" << dmg_life << ") damage from "
    //        << source.getcharacterName() << '\n';
    //}

    //// First apply armor modifications
    //if (remove_armor > 0) {
    //    m_max_armor = std::max(0, m_max_armor - remove_armor);
    //}
    //if (add_armor > 0) {
    //    m_max_armor += add_armor;
    //}

    //// Then handle damage
    //if (dmg_life > 0) {
    //    // Damage is first absorbed by armor
    //    if (m_max_armor > 0) {
    //        if (m_max_armor >= dmg_life) {
    //            m_max_armor -= dmg_life;
    //            dmg_life = 0;
    //        }
    //        else {
    //            dmg_life -= m_max_armor;
    //            m_max_armor = 0;
    //        }
    //    }

    //    // Remaining damage goes to life
    //    if (dmg_life > 0) {
    //        m_max_life -= dmg_life;
    //    }
    //}

    //// Apply healing
    //if (heal_life > 0) {
    //    m_max_life += heal_life;
    //}

    //// Check for death
    //if (m_max_life <= 0) {
    //    std::cout << m_name << " has been killed by " << source.getcharacterName() << '\n';
    //}

    //printcharacter();
    //std::cout << '\n';
//}

