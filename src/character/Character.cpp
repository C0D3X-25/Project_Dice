#include "../include/Character.hpp"

using namespace character;

character::Character::Character(const std::string& name)
	: m_name(name)
{

}


character::Character::Character(const std::string& name, const int16_t max_life, const int16_t max_armor)
	: m_name(name), m_max_life(max_life), m_max_armor(max_armor)
{

}


void character::Character::updateAttributes(const Attribute& update_attribute) {

	m_attributes.setAttribute(attribute::STRENGTH, update_attribute.getAttribute(attribute::STRENGTH));
	m_attributes.setAttribute(attribute::DEXTERITY, update_attribute.getAttribute(attribute::DEXTERITY));
	m_attributes.setAttribute(attribute::CONSTITUTION, update_attribute.getAttribute(attribute::CONSTITUTION));
	m_attributes.setAttribute(attribute::INTELLIGENCE, update_attribute.getAttribute(attribute::INTELLIGENCE));
	m_attributes.setAttribute(attribute::WISDOM, update_attribute.getAttribute(attribute::WISDOM));
	m_attributes.setAttribute(attribute::CHARISMA, update_attribute.getAttribute(attribute::CHARISMA));

	updatecharacter();
}


//void character::Character::setCapacity(const BaseCapacity& capacity, const uint8_t side) {
//    m_dice_capacity.setCapacity(capacity, side);
//}


//const BaseCapacity character::Character::rollDiceCapacity(void) {
//    return m_dice_capacity.roll();
//}


void character::Character::printcharacter(void) const {
    std::cout
        << m_name
        << " || " << m_current_life << "/" << m_max_life << " Life "
        << " | " << m_current_armor << "/" << m_max_armor << " Armor "
        << '\n';

    std::cout << "\n---------- Attributes ----------\n";
    m_attributes.printAllAttributes();

    std::cout << "\n---------- Bonus Attributes ----------\n";
    m_bonus_attributes.printAllAttributes();

    std::cout << "\n---------- Dice Capacity ----------\n";
    //m_dice_capacity.printDiceSides();

    std::cout << "\n---------- Passives ----------\n";
    //m_passive.printListPassives();

}


//void character::Character::useCapacity(const BaseCapacity& capacity, Character& target) {
//	std::cout
//		<< m_name
//		<< " use capacity " << capacity.getCapacityName()
//		<< " on " << target.getcharacterName()
//		<< '\n';
//
//	//target.resolveCapacity(capacity.getStats(), *this);
//}


//void character::Character::resolveCapacity(const CapacityDTO& capacity, const Character& source) {
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

