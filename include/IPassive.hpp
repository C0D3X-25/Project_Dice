#pragma once 

#include <string>

namespace passive {
	/// <summary>
	/// Interface for passive.
	/// </summary>
	class IPassive {
	public:
		virtual ~IPassive() = default;
		virtual void executePassive() = 0;
		virtual void printPassive() const = 0;
		virtual std::string getPassiveName() const = 0;
	};
}