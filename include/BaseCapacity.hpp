#pragma once

#include "CapacityDTO.hpp"
#include "ECapacity.hpp"
#include "BaseCapacityAction.hpp"
#include "EAttribute.hpp"

#include <queue>
#include <string>
#include <string_view>
#include <vector>
#include <iostream>

namespace capacity {

	using namespace attribute;

	class BaseCapacity {
	public:
		virtual ~BaseCapacity(void) = default;


		std::queue<CapacityDTO> getAllCapacityModifiers(void) {
			return m_capacity_modifiers;
		}


		void queueCapacityModifier(const CapacityDTO& capacity_modifier) {
			addCapacityTarget(capacity_modifier);
			m_capacity_modifiers.push(capacity_modifier);
		}


		CapacityDTO getNextCapacityModifier(void) {
			if (!m_capacity_modifiers.empty()) {
				m_current_modifier = m_capacity_modifiers.front();
				m_capacity_modifiers.pop();
				return m_current_modifier;
			}
			return CapacityDTO{};
		}


		bool isNextCapacityModifier(void) {
			return m_capacity_modifiers.size() > 1;
		}


		void printCapacity(void) const {
			std::cout << " - " << getCapacityName()
				<< " - \n" << getCapacityDescription() << '\n';
			std::cout << "Capacity purposes: [ ";
			for (const auto& purpose : m_capacity_purpose) {
				std::cout << toString(purpose) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity targets:  [ ";
			for (const auto& target : m_capacity_target) {
				std::cout << toString(target) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity triggers: [ ";
			for (const auto& trigger : m_capacity_trigger) {
				std::cout << toString(trigger) << " ";
			}
			std::cout << "]\n";
		}

		bool isEmpty(void) const { return m_capacity_modifiers.empty(); }

		void setCapacityName(const std::string& name)							{ m_name = name; }
		void setCapacityDescription(const std::string& description)				{ m_description = description; }
		void setCapacityPurposes(const std::vector<ECapacityPurpose>& purpose)	{ m_capacity_purpose = purpose; }
		void setCapacityTriggers(const std::vector<ECapacityTrigger>& trigger)	{ m_capacity_trigger = trigger; }
		void setCapacityAttribute(const std::vector<EAttribute>& attribute)		{ m_capacity_attribute = attribute; }
		
		std::string_view getCapacityName(void) const					{ return m_name; }
		std::string_view getCapacityDescription(void) const				{ return m_description; }
		std::vector<ECapacityPurpose> getCapacityPurposes(void) const	{ return m_capacity_purpose; }
		std::vector<ECapacityTarget> getCapacityTargets(void) const		{ return m_capacity_target; }
		std::vector<ECapacityTrigger> getCapacityTriggers(void) const	{ return m_capacity_trigger; }
		std::vector<EAttribute> getCapacityAttributes(void) const		{ return m_capacity_attribute; }

	private:
		void addCapacityTarget(const CapacityDTO& capacity_modifier) {
			for (const auto& target : capacity_modifier.m_targets) {
				if (std::find(m_capacity_target.begin(), m_capacity_target.end(), target) == m_capacity_target.end()) {
					m_capacity_target.push_back(target);
				}
			}
		}

	private:
		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
		std::queue<CapacityDTO> m_capacity_modifiers;
		CapacityDTO m_current_modifier; // Useless maybe
		std::vector<ECapacityPurpose> m_capacity_purpose;
		std::vector<ECapacityTarget> m_capacity_target;
		std::vector<ECapacityTrigger> m_capacity_trigger;
		std::vector<EAttribute> m_capacity_attribute;
	};
}
