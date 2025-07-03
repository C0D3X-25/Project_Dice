#pragma once

#include "BaseCapacity.hpp"
#include "BaseEntity.hpp"

namespace capacity {

	using namespace entity;

	/**
	* @brief Interface for classes that can use and resolve capacities
	*/
	class IUseAndResolveCapacity {
	public:
		/**
		* @brief Use a capacity on a target entity
		* @param capacity The capacity to use
		* @param target The target Entity
		*/
		virtual void useCapacity(const BaseCapacity& capacity, BaseEntity& target) = 0;


		/**
		* @brief Resolve a capacity on the source entity
		* @param capacity The capacity to resolve
		* @param source The Entity that is the source of the capacity
		*/
		virtual void resolveCapacity(const CapacityComponent& capacity, const BaseEntity& source) = 0;
	};
}
