#pragma once

#include "PassiveModifierDTO.hpp"

#include <string>

namespace passive {
	/// <summary>
	/// Interface for passive.
	/// </summary>
	class IPassive {
	public:
		virtual ~IPassive() = default;
		virtual PassiveModifierDTO executePassive(PassiveModifierDTO& passive_mod) = 0;
		virtual void printPassive() const = 0;
		virtual std::string getPassiveName() const = 0;
	};
}