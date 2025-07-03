#pragma once

#include "BaseEntity.hpp"
#include "BaseGroup.hpp"

#include <string>

namespace group {

	using entity::BaseEntity;

	inline constexpr uint8_t TEAM_MAX_SIZE{ 5 };

	class Team : public BaseGroup {
	public:
		Team(std::string team_name)
		: BaseGroup(TEAM_MAX_SIZE, team_name) {

		}


	private:

	};
}