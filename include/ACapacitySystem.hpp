#pragma once

#include "CapacityData.hpp"
#include "CharacterSystem.hpp"

#include <string>
#include <string_view>
#include <iostream>

namespace capacity {

	using character::CharacterSystem;

	/// <summary>
	/// Base class for all capacities.
	/// Capacities are abilities or skills that can be used by entities in the game, she can deal damage, heal, add armor, buff, debuff other entities.
	/// It's composed of a name, description, purposes, targets, triggers, attributes and capacity DTO.
	/// When an character uses a capacity, there is only the capacity DTO who is send tho the target manager.
	/// </summary>
	class ACapacitySystem {
	public:
		virtual ~ACapacitySystem() = default;

		std::queue<CapacityActionData> getAllCapacityActionData() {	return m_capacity_data.m_capacity_dto_queue; }
		void queueCapacityActionData(const CapacityActionData& capacity_dto);
		CapacityActionData getNextCapacityActionData();

		bool isNextCapacityDTO()	{ return m_capacity_data.m_capacity_dto_queue.size() > 1; }
		bool isEmpty()				const { return m_capacity_data.m_capacity_dto_queue.empty(); }
		virtual void printCapacity() const;


		virtual CapacityData executeCapacity(CharacterSystem& source_character, CharacterSystem& dest_character) = 0;
		virtual CapacityData getCapacity() = 0;

		void setCapacityName(const std::string& name)								{ m_capacity_data.m_name = name; }
		void setCapacityDescription(const std::string& description)					{ m_capacity_data.m_description = description; }
		void setCapacityPurposes(const std::vector<ECapacityPurposeData>& purpose)	{ m_capacity_data.m_capacity_purpose = purpose; }
		void setCapacityTriggers(const std::vector<ECapacityTriggerData>& trigger)	{ m_capacity_data.m_capacity_trigger = trigger; }
		void setCapacityAttribute(const std::vector<EAttributeData>& attribute)		{ m_capacity_data.m_capacity_attribute = attribute; }
		
		std::string_view getCapacityName()								const { return m_capacity_data.m_name; }
		std::string_view getCapacityDescription()						const { return m_capacity_data.m_description; }
		std::vector<ECapacityPurposeData> getCapacityPurposes()			const { return m_capacity_data.m_capacity_purpose; }
		std::vector<ECapacityTargetData> getCapacityTargets()			const { return m_capacity_data.m_capacity_target; }
		std::vector<ECapacityTriggerData> getCapacityTriggers()			const { return m_capacity_data.m_capacity_trigger; }
		std::vector<EAttributeData> getCapacityAttributes()				const { return m_capacity_data.m_capacity_attribute; }

	protected:
		CapacityData m_capacity_data;

	private:
		void addCapacityTarget(const CapacityActionData& capacity_dto);
	};
}
