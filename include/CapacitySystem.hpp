#pragma once

#include "EAttributeData.hpp"
#include "ECapacityTargetData.hpp"
#include "ECapacityPurposeData.hpp"
#include "ECapacityTriggerData.hpp"
#include "CapacityActionData.hpp"
//#include "BaseCapacityActionSystem.hpp"

#include <queue>
#include <string>
#include <string_view>
#include <vector>
#include <iostream>

namespace capacity {

	using namespace attribute;

	/// <summary>
	/// Base class for all capacities.
	/// Capacities are abilities or skills that can be used by entities in the game, she can deal damage, heal, add armor, buff, debuff other entities.
	/// It's composed of a name, description, purposes, targets, triggers, attributes and capacity DTO.
	/// When an character uses a capacity, there is only the capacity DTO who is send tho the target manager.
	/// </summary>
	class CapacitySystem {
	public:
		virtual ~CapacitySystem() = default;

		std::queue<CapacityActionData> getAllCapacityActionData() {	return m_capacity_dto_queue; }

		void queueCapacityActionData(const CapacityActionData& capacity_dto);

		CapacityActionData getNextCapacityActionData();

		bool isNextCapacityDTO() { return m_capacity_dto_queue.size() > 1; }
		bool isEmpty() const { return m_capacity_dto_queue.empty(); }

		void printCapacity() const;


		void setCapacityName(const std::string& name)								{ m_name = name; }
		void setCapacityDescription(const std::string& description)					{ m_description = description; }
		void setCapacityPurposes(const std::vector<ECapacityPurposeData>& purpose)	{ m_capacity_purpose = purpose; }
		void setCapacityTriggers(const std::vector<ECapacityTriggerData>& trigger)	{ m_capacity_trigger = trigger; }
		void setCapacityAttribute(const std::vector<EAttributeData>& attribute)		{ m_capacity_attribute = attribute; }
		
		std::string_view getCapacityName()								const { return m_name; }
		std::string_view getCapacityDescription()						const { return m_description; }
		std::vector<ECapacityPurposeData> getCapacityPurposes()			const { return m_capacity_purpose; }
		std::vector<ECapacityTargetData> getCapacityTargets()			const { return m_capacity_target; }
		std::vector<ECapacityTriggerData> getCapacityTriggers()			const { return m_capacity_trigger; }
		std::vector<EAttributeData> getCapacityAttributes()				const { return m_capacity_attribute; }

	private:
		void addCapacityTarget(const CapacityActionData& capacity_dto);

	private:
		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
		std::queue<CapacityActionData> m_capacity_dto_queue;
		std::vector<ECapacityPurposeData> m_capacity_purpose;
		std::vector<ECapacityTargetData> m_capacity_target;
		std::vector<ECapacityTriggerData> m_capacity_trigger;
		std::vector<EAttributeData> m_capacity_attribute;
	};
}
