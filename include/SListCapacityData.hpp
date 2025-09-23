#pragma once

#include "ACapacitySystem.hpp"
#include "CapacityPlayerSingleAttack"

#include <map>

namespace capacity {


	enum EListCapacityData {
		NOTHING = 0,
		ATTACK_SINGLE,
		ATTACK_RANDOM,
		PROTECT_SELF,
		FAST_HEAL,
		// More capacities can be added here
	};

	/// <summary>
	/// This class is a library for all the capacities.
	/// 1 method = 1 Capacity
	/// A method must return a ACapacitySystem object.
	/// </summary>
	static class SListCapacityData {
	public:

		const std::map<EListCapacityData, ACapacitySystem> getAllCapacities() const { return m_all_capacities; }
		

	private:
		static const std::map<EListCapacityData, ACapacitySystem> m_all_capacities{
			{NOTHING, CapacityFactory::nothing()},
			{ATTACK_SINGLE, CapacityFactory::attackSingle()},
			{ATTACK_RANDOM, CapacityFactory::attackRandom()},
			{PROTECT_SELF, CapacityFactory::protectSelf()},
			{FAST_HEAL, CapacityFactory::fastHeal()},
		}
	};
}