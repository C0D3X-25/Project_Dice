#pragma once

#include <cstdint>

namespace dice {
    /**
     * @brief Interface for implementing advantage/disadvantage dice rolling mechanics
     * 
     * This interface defines methods for rolling with advantage or disadvantage.
     * 
     * @tparam T The type used for the roll results (e.g., int, BaseCapacity)
     */
    template <typename T>
    class IRollAdvantageDisadvantage {
    public:
        /**
         * @brief Performs a roll with advantage
         * 
         * @return The higher value of two rolls
         */
        virtual const T rollAdvantage(void) = 0;

        /**
         * @brief Performs a roll with disadvantage
         * 
         * @return The lower value of two rolls
         */
        virtual const T rollDisadvantage(void) = 0;
    };
}