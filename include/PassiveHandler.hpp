#pragma once 

#include "IPassive.hpp"

#include <string>
#include <vector>
#include <memory>

namespace passive {

	/// <summary>
	/// Facade Design for handling passive abilities.
	/// </summary>
	class PassiveHandler {
	public:
		/// <summary>
		/// Adds a passive object to the list of passives that start at the beginning of a turn.
		/// </summary>
		/// <param name="sp_passive">A shared pointer to the passive object to add.</param>
		void addPassive(std::shared_ptr<IPassive> sp_passive) {
			m_passives_starting_turn.push_back(sp_passive);
		}


	private:
		std::vector<std::shared_ptr<IPassive>> m_passives_starting_turn;
		std::map<int, std::shared_ptr<IPassive>> m_active_passives; // <weight, passive>
	};
}