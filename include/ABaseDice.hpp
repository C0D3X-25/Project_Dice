#pragma once
#include "SRandom.hpp"

#include <iostream>

namespace dice {

    /// @brief Abstract base class template for dice implementations
    /// @tparam T The return type for dice roll results
    template <typename T>
    class ABaseDice {
    public:
        virtual ~ABaseDice(void) = default;

        /// @brief Pure virtual method to roll the dice
        /// @return Result of the dice roll as type T
        virtual const T roll(void) = 0;

        /// @brief Pure virtual method to display dice information
        virtual void printDiceSides(void) const = 0;

    protected:

        uint16_t getRandomValue(const uint16_t max_value, const uint16_t min_value = 1) {
			return helper::random::generateRandomValue(max_value, min_value);
        }
    };
}