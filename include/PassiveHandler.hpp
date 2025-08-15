#pragma once 

#include "IPassive.hpp"

#include <string>

namespace passive {

	/// <summary>
	/// Facade Design for handling passive abilities.
	/// </summary>
	class PassiveHandler {
	public:
		// add passive to the handler
	private:
		std::vector<IPassive> m_passives_starting_turn;
	};
}