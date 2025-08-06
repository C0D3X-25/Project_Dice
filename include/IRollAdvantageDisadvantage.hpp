#pragma once

#include <cstdint>

namespace dice {

    /// <summary>
    /// Interface for performing rolls with advantage or disadvantage, returning the higher or lower of two rolls respectively.
    /// </summary>
    /// <typeparam name="T">The type representing the result of a roll.</typeparam>
    template <typename T>
    class IRollAdvantageDisadvantage {
    public:

        virtual const T rollAdvantage(void) = 0;
        virtual const T rollDisadvantage(void) = 0;
    };
}