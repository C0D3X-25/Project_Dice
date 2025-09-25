#pragma once

#include "ACapacitySystem.hpp"
#include "Capacity_NotImplementedSystem.hpp"
#include "Capacity_NothingSystem.hpp"
#include "Capacity_AttackSingleSystem.hpp"
#include "Capacity_AttackRandomSystem.hpp"
#include "Capacity_DefendSelfSystem.hpp"
#include "Capacity_HealFastSystem.hpp"
#include "Capacity_AttackTeamSystem.hpp"


#include <map>

namespace capacity {

	using character::CharacterSystem;

	/// <summary>
	/// This class is a library for all the capacities.
	/// </summary>
	class ListCapacityData {
	public:

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

		void printCapacityData(const EListCapacityData capacity) {
			auto it = m_all_capacities.find(capacity);
			if (it != m_all_capacities.end()) {
				it->second.printCapacityData();
			}
		}


		CapacityData getCapacityData(const EListCapacityData capacity) {
			auto it = m_all_capacities.find(capacity);
			if (it != m_all_capacities.end()) {
				return it->second;
			}
		}
		
	private:

		Capacity_NotImplementedSystem m_capacity_not_implemented;
		Capacity_NothingSystem m_capacity_nothing;
		Capacity_AttackSingleSystem m_capacity_single_attack;
		Capacity_AttackRandomSystem m_capacity_random_attack;
		Capacity_DefendSelfSystem m_capacity_defend_self;
		Capacity_HealFastSystem m_capacity_heal_fast;
		Capacity_AttackTeamSystem m_capacity_attack_team;


		const std::map<EListCapacityData, CapacityData> m_all_capacities{
			{NOT_IMPLEMENTED, m_capacity_not_implemented.getCapacity()},
			{NOTHING, m_capacity_nothing.getCapacity()},
			{ATTACK_SINGLE, m_capacity_single_attack.getCapacity()},
			{ATTACK_RANDOM, m_capacity_random_attack.getCapacity()},
			{DEFEND_SELF, m_capacity_defend_self.getCapacity()},
			{HEAL_FAST, m_capacity_heal_fast.getCapacity()},
			{ATTACK_TEAM, m_capacity_attack_team.getCapacity()},
		};
	};
}