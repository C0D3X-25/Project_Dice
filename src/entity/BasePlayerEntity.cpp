#include "../include/BasePlayerEntity.hpp"

using namespace entity;

entity::BasePlayerEntity::BasePlayerEntity(const std::string& name)
	: BaseEntity(name) {}


void entity::BasePlayerEntity::setCapacity(const BaseCapacity& capacity, const uint8_t side) {
    m_dice_capacity.setCapacity(capacity, side);
}


const BaseCapacity entity::BasePlayerEntity::rollDiceCapacity(void) {
    return m_dice_capacity.roll();
}


void entity::BasePlayerEntity::printEntity(void) const {
    std::cout
        << m_name
        << " || " << m_current_life << "/" << m_max_life << " Life "
		<< " | " << m_current_armor << "/" << m_max_armor << " Armor "
		<< '\n';

    std::cout << "\n---------- Attributes ----------\n";
	m_attributes.printAllAttributes();

    std::cout << "\n---------- Dice Capacity ----------\n";
    m_dice_capacity.printDiceSides();
}


//void entity::BasePlayerEntity::useCapacity(const BaseCapacity& capacity, BaseEntity& target) {
//	std::cout
//		<< m_name
//		<< " use capacity " << capacity.getCapacityName()
//		<< " on " << target.getEntityName()
//		<< '\n';
//
//	//target.resolveCapacity(capacity.getStats(), *this);
//}


//void entity::BasePlayerEntity::resolveCapacity(const CapacityComponent& capacity, const BaseEntity& source) {
    //// Initialize modifiers
    //int16_t dmg_life = capacity.m_max_life < 0 ? -capacity.m_max_life : 0;
    //int16_t heal_life = capacity.m_max_life > 0 ? capacity.m_max_life : 0;
    //int16_t remove_armor = capacity.m_max_armor < 0 ? -capacity.m_max_armor : 0;
    //int16_t add_armor = capacity.m_max_armor > 0 ? capacity.m_max_armor : 0;

    //if (dmg_life > 0) {
    //    std::cout << m_name << " took (" << dmg_life << ") damage from "
    //        << source.getEntityName() << '\n';
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
    //    std::cout << m_name << " has been killed by " << source.getEntityName() << '\n';
    //}

    //printEntity();
    //std::cout << '\n';
//}
