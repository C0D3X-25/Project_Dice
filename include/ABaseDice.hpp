#pragma once
#include "SRandom.hpp"

#include <iostream>

namespace dice {
    
    /// <summary>
    /// Abstract base class template for dice implementations
    /// </summary>
    /// <typeparam name="T">The return type for dice roll results</typeparam>
    template <typename T>
    class ABaseDice {
    public:
        virtual ~ABaseDice(void) = default;

        /// <summary>
        /// Pure virtual method to roll the dice
        /// </summary>
        /// <param name=""></param>
        /// <returns>Result of the dice roll as type T</returns>
        virtual const T roll(void) = 0;


        /// <summary>
        /// Pure virtual method to display dice informations in console
        /// </summary>
        /// <param name=""></param>
        virtual void printDiceSides(void) const = 0;

    protected:

        uint16_t getRandomValue(const uint16_t max_value, const uint16_t min_value = 1) {
			return helper::random::generateRandomValue(max_value, min_value);
        }
    };
}