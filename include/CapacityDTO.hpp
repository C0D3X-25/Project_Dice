#pragma once
#include "ECapacity.hpp"
//#include "BaseEntity.hpp"

#include <cstdint>
#include <vector>
#include <memory>



namespace capacity {

	//using entity::BaseEntity;

	/// <summary>
	/// Represent the data who need to be transfered when a entity use a capacity, from source to target.
	/// </summary>
	struct CapacityDTO {

		std::vector<ECapacityTarget> m_targets;

		//std::shared_ptr<BaseEntity> m_p_user;

		uint16_t m_damage{ 0 };
		uint16_t m_heal{ 0 };

		uint16_t m_add_armor{ 0 };
		uint16_t m_remove_armor{ 0 };

		
		// TODO: Status
	};
} // namespace capacity
