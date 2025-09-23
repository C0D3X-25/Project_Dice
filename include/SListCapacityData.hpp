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
	static class SListCapacityData {
	public:

		static CapacityActionData executeCapacity(const EListCapacityData capacity, CharacterSystem& source_character, CharacterSystem& target_character) {
			auto it = m_all_capacities.find(capacity);
			if (it != m_all_capacities.end()) {
				it->second.executeCapacity(source_character, target_character);
				return it->second.getNextCapacityActionData();
			}
			else {
				std::cerr << "Error: Capacity not found in the list.\n";
				return CapacityActionData{};
			}
		}

		static void printCapacity(const EListCapacityData capacity) {
			auto it = m_all_capacities.find(capacity);
			if (it != m_all_capacities.end()) {
				it->second.printCapacity();
			}
			else {
				std::cerr << "Error: Capacity not found in the list.\n";
			}
		}
		

	private:
		static const std::map<EListCapacityData, CapacityData> m_all_capacities{
			{NOT_IMPLEMENTED, m_capacity_not_implemented},
			{NOTHING, m_capacity_nothing},
			{ATTACK_SINGLE, m_capacity_single_attack},
			//{ATTACK_RANDOM, Capacity_RandomAttack},
			//{DEFEND_SELF, Capacity_DefendSelf},
			//{HEAL_FAST, Capacity_HealFas)}
		};

		static Capacity_NotImplemented m_capacity_not_implemented;
		static Capacity_Nothing m_capacity_nothing;
		static Capacity_SingleAttack m_capacity_single_attack;
	};

	// Define static member variables
	Capacity_NotImplemented SListCapacityData::m_capacity_not_implemented;
	Capacity_Nothing SListCapacityData::m_capacity_nothing;
	Capacity_SingleAttack SListCapacityData::m_capacity_single_attack;
}