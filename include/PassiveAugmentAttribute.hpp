#pragma once 

#include "IPassive.hpp"
#include "EAttributeData.hpp"
#include "CharacterSystem.hpp"
#include "PassiveModifierDTO.hpp"

#include <memory>

namespace passive {

	using character::CharacterSystem;
	using attribute::EAttributeData;

	class PassiveAugmentAttribute : public IPassive {
	public:
		PassiveAugmentAttribute(const EAttributeData attribute_type, const int8_t augment_value)
			: m_attribute_type{ attribute_type }, m_augment_value{ augment_value } {
		}
		~PassiveAugmentAttribute() = default;

		PassiveModifierDTO executePassive(PassiveModifierDTO& passive_mod) {

			switch (m_attribute_type) {
			case attribute::STRENGTH:
				passive_mod.m_temp_attributes.setAttribute(attribute::STRENGTH, m_augment_value);
				break;
			case attribute::DEXTERITY:
				passive_mod.m_temp_attributes.setAttribute(attribute::DEXTERITY, m_augment_value);
				break;
			case attribute::CONSTITUTION:
				passive_mod.m_temp_attributes.setAttribute(attribute::CONSTITUTION, m_augment_value);
				break;
			case attribute::INTELLIGENCE:
				passive_mod.m_temp_attributes.setAttribute(attribute::INTELLIGENCE, m_augment_value);
				break;
			case attribute::WISDOM:
				passive_mod.m_temp_attributes.setAttribute(attribute::WISDOM, m_augment_value);
				break;
			case attribute::CHARISMA:
				passive_mod.m_temp_attributes.setAttribute(attribute::CHARISMA, m_augment_value);
				break;
			default:
				break;
			}

			return passive_mod;
		}

		void printPassive() const {
			std::cout
				<< "Passive Name: " << m_name << '\n'
				<< "Description: " << m_description << '\n'
				<< "--------------\n"
				<< '\n';
		}

		std::string getPassiveName() const { return m_name; }
		std::string getPassiveDescription() const { return m_description; }

	private:
		EAttributeData m_attribute_type;
		int8_t m_augment_value{ 0 };
		std::string m_name{ "Augment " + std::string(toString(m_attribute_type)) };
		std::string m_description{ "Augment " + std::string(toString(m_attribute_type)) + " by " + std::to_string(m_augment_value) + ". It can't goes over " + std::to_string(attribute::ATTRIBUTE_MAX_VALUE) + "." };
	};
}