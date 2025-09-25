#pragma once

#include "ACapacitySystem.hpp"
#include "Capacity_NotImplemented.hpp"
#include "Capacity_Nothing.hpp"
#include "Capacity_SingleAttack.hpp"

#include <map>

namespace capacity {

	using character::CharacterSystem;


	/// <summary>
	/// This class is a library for all the capacities.
	/// 1 method = 1 Capacity
	/// A method must return a ACapacitySystem object.
	/// </summary>
	class ListCapacityData {
	public:

		//ListCapacityData() {
		//	m_all_capacities.emplace(NOT_IMPLEMENTED, m_capacity_not_implemented.getCapacity());
		//	m_all_capacities.emplace(NOTHING, m_capacity_nothing.getCapacity());
		//	m_all_capacities.emplace(ATTACK_SINGLE, m_capacity_single_attack.getCapacity());

		//		//{ATTACK_RANDOM, std::make_shared<Capacity_RandomAttack>()},
		//		//{DEFEND_SELF, std::make_shared<Capacity_DefendSelf>()},
		//		//{HEAL_FAST, std::make_shared<Capacity_HealFast>()}
		//}

		//CapacityData executeCapacity(const EListCapacityData capacity, CharacterSystem& source_character, CharacterSystem& target_character) {
		//	auto it = m_all_capacities_ptr.find(capacity);
		//	if (it != m_all_capacities_ptr.end()) {
		//		return it->second->executeCapacity(source_character, target_character);
		//	}
		//	else {
		//		std::cerr << "Error: Capacity not found in the list.\n";
		//		return CapacityData{};
		//	}
		//}

		//void printCapacity(const EListCapacityData capacity) {
		//	auto it = m_all_capacities_ptr.find(capacity);
		//	if (it != m_all_capacities_ptr.end()) {
		//		it->second->printCapacity();
		//	}
		//}
		CapacityData printCapacity(const EListCapacityData capacity) { // TODO : CapacityData or ACapacitySystem
			auto it = m_all_capacities.find(capacity);
			if (it != m_all_capacities.end()) {
				return it->second;
			}
			else {
				std::cerr << "Error: Capacity not found in the list.\n";
				return CapacityData{};
			}
		}
		
	private:
		//const std::map<EListCapacityData, std::shared_ptr<ACapacitySystem>> m_all_capacities_ptr{
		//	{NOT_IMPLEMENTED, std::make_shared<Capacity_NotImplemented>()},
		//	{NOTHING, std::make_shared<Capacity_Nothing>()},
		//	{ATTACK_SINGLE, std::make_shared<Capacity_SingleAttack>()}
		//	//{ATTACK_RANDOM, std::make_shared<Capacity_RandomAttack>()},
		//	//{DEFEND_SELF, std::make_shared<Capacity_DefendSelf>()},
		//	//{HEAL_FAST, std::make_shared<Capacity_HealFast>()}
		//};

		Capacity_NotImplemented m_capacity_not_implemented;
		Capacity_Nothing m_capacity_nothing;
		Capacity_SingleAttack m_capacity_single_attack;

		const std::map<EListCapacityData, CapacityData> m_all_capacities{
			{NOT_IMPLEMENTED, m_capacity_not_implemented.getCapacity()},
			{NOTHING, m_capacity_nothing.getCapacity()},
			{ATTACK_SINGLE, m_capacity_single_attack.getCapacity()}
			//{ATTACK_RANDOM, std::make_shared<Capacity_RandomAttack>()},
			//{DEFEND_SELF, std::make_shared<Capacity_DefendSelf>()},
			//{HEAL_FAST, std::make_shared<Capacity_HealFast>()}
		};

		//std::map<EListCapacityData, CapacityData> m_all_capacities;
	};
}