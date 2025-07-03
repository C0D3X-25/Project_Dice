#include "../include/BaseEntity.hpp"

using namespace entity;

entity::BaseEntity::BaseEntity(const std::string& name)
	: m_name(name) {}


entity::BaseEntity::BaseEntity(const std::string& name, const int16_t max_life, const int16_t max_armor)
	: m_name(name), m_max_life(max_life), m_max_armor(max_armor) {}


void entity::BaseEntity::printEntity(void) const {
	std::cout << "Entity name:     - " << getEntityName() << " -\n";
	std::cout << "Entity life:     - " << getMaxLife() << " -\n";
	std::cout << "Entity armor:    - " << getMaxArmor() << " -\n";
	m_attributes.printAllAttributes();
}


void entity::BaseEntity::setAttributes(const Attribute& new_attribute) {

	m_attributes.setStrength(new_attribute.getStrength());
	m_attributes.setDexterity(new_attribute.getDexterity());
	m_attributes.setConstitution(new_attribute.getConstitution());
	m_attributes.setIntelligence(new_attribute.getIntelligence());
	m_attributes.setWisdom(new_attribute.getWisdom());
	m_attributes.setCharisma(new_attribute.getCharisma());

	updateEntity();
}


void entity::BaseEntity::updateAttributes(const Attribute& update_attribute) {

	m_attributes.setStrength(update_attribute.getStrength());
	m_attributes.setDexterity(update_attribute.getDexterity());
	m_attributes.setConstitution(update_attribute.getConstitution());
	m_attributes.setIntelligence(update_attribute.getIntelligence());
	m_attributes.setWisdom(update_attribute.getWisdom());
	m_attributes.setCharisma(update_attribute.getCharisma());

	updateEntity();
}


void entity::BaseEntity::updateEntity(void) {
	// TODO
}


