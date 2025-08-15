#pragma once 

#include "BaseCapacity.hpp"
#include "CapacityDTO.hpp"
#include "Attribute.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <string_view>
#include <PassiveHandler.hpp>

namespace entity {

	using capacity::BaseCapacity;
	using capacity::CapacityDTO;
	using attribute::Attribute;
	using passive::PassiveHandler;

	/// <summary>
	/// Base Class for any entity.
	/// </summary>
	class BaseEntity {
	public:
		BaseEntity(const std::string& name);
		BaseEntity(const std::string& name, const int16_t max_life, const int16_t max_armor);
		virtual ~BaseEntity(void) = default;

		virtual void printEntity(void) const;

		virtual void setAttributes(const Attribute& new_attributes);
		virtual void updateAttributes(const Attribute& update_attributes);

		virtual void setEntityName(const std::string& name)		{ m_name = name; }
		virtual void setMaxLife(int16_t life)					{ m_max_life = life; }
		virtual void setCurrentLife(int16_t life)				{ m_current_life = life; }
		virtual void setMaxArmor(int16_t armor)					{ m_max_armor = armor; }
		virtual void setCurrentArmor(int16_t armor)				{ m_current_armor = armor; }

		virtual std::string_view getEntityName(void) const		{ return m_name; }
		virtual int16_t getMaxLife(void) const					{ return m_max_life; }
		virtual int16_t getCurrentLife(void) const				{ return m_current_life; }
		virtual int16_t getMaxArmor(void) const					{ return m_max_armor; }
		virtual int16_t getCurrentArmor(void) const				{ return m_current_armor; }
		virtual int8_t getStrength(void) const					{ return m_attributes.getStrength(); }
		virtual int8_t getDexterity(void) const					{ return m_attributes.getDexterity(); }
		virtual int8_t getConstitution(void) const				{ return m_attributes.getConstitution(); }
		virtual int8_t getIntelligence(void) const				{ return m_attributes.getIntelligence(); }
		virtual int8_t getWisdom(void) const					{ return m_attributes.getWisdom(); }
		virtual int8_t getCharisma(void) const					{ return m_attributes.getCharisma(); }

	protected:

		virtual void updateEntity(void);

	protected:

		std::string m_name		{ "N/A" };
		Attribute m_attributes;
		PassiveHandler m_passive;
		// TODO: StatusHandler m_status;
		// TODO: FeatHandler m_feat;
		int16_t m_max_life		{ 0 };
		int16_t m_current_life	{ 0 };
		int16_t m_max_armor		{ 0 };
		int16_t m_current_armor	{ 0 };
	};
}
