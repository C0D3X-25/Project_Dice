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

		//CapacityData executeCapacity(const EListCapacityData capacity, CharacterSystem& source_character, CharacterSystem& target_character) {
		//	auto it = m_all_capacities.find(capacity);
		//	if (it != m_all_capacities.end()) {
		//		return it->second->executeCapacity(source_character, target_character);
		//	}
		//	else {
		//		std::cerr << "Error: Capacity not found in the list.\n";
		//		return CapacityData{};
		//	}
		//}

		void printCapacity(const EListCapacityData capacity) {
			auto it = m_all_capacities.find(capacity);
			if (it != m_all_capacities.end()) {
				it->second->printCapacity();  // Use -> with shared_ptr
			}
			else {
				std::cerr << "Error: Capacity not found in the list.\n";
			}
		}
		

	private:
		const std::map<EListCapacityData, std::shared_ptr<ACapacitySystem>> m_all_capacities{
			{NOT_IMPLEMENTED, std::make_shared<Capacity_NotImplemented>()},
			{NOTHING, std::make_shared<Capacity_Nothing>()},
			{ATTACK_SINGLE, std::make_shared<Capacity_SingleAttack>()}
			//{ATTACK_RANDOM, std::make_shared<Capacity_RandomAttack>()},
			//{DEFEND_SELF, std::make_shared<Capacity_DefendSelf>()},
			//{HEAL_FAST, std::make_shared<Capacity_HealFast>()}
		};
	};
}