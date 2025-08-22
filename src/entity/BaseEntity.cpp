#include "../include/BaseEntity.hpp"

using namespace entity;

entity::BaseEntity::BaseEntity(const std::string& name)
	: m_name(name)
{
	initializeEntity();
}



entity::BaseEntity::BaseEntity(const std::string& name, const int16_t max_life, const int16_t max_armor)
	: m_name(name), m_max_life(max_life), m_max_armor(max_armor)
{
	initializeEntity();
}


void entity::BaseEntity::initializeEntity() {
	m_passive.initializePassiveHandler(*this);
}

void entity::BaseEntity::printEntity() const {
	std::cout << "Entity name:     - " << getEntityName() << " -\n";
	std::cout << "Entity life:     - " << getMaxLife() << " -\n";
	std::cout << "Entity armor:    - " << getMaxArmor() << " -\n";
	m_attributes.printAllAttributes();
}


void entity::BaseEntity::updateAttributes(const Attribute& update_attribute) {

	m_attributes.setAttribute(attribute::STRENGTH, update_attribute.getAttribute(attribute::STRENGTH));
	m_attributes.setAttribute(attribute::DEXTERITY, update_attribute.getAttribute(attribute::DEXTERITY));
	m_attributes.setAttribute(attribute::CONSTITUTION, update_attribute.getAttribute(attribute::CONSTITUTION));
	m_attributes.setAttribute(attribute::INTELLIGENCE, update_attribute.getAttribute(attribute::INTELLIGENCE));
	m_attributes.setAttribute(attribute::WISDOM, update_attribute.getAttribute(attribute::WISDOM));
	m_attributes.setAttribute(attribute::CHARISMA, update_attribute.getAttribute(attribute::CHARISMA));

	updateEntity();
}


void entity::BaseEntity::updateEntity() {
	// TODO
}


