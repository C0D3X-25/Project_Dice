#pragma once

#include <random>
#include <cstdint>

namespace helper {
    namespace random {
        
        /// <summary>
        /// Helper method to generate random numbers within a range
        /// </summary>
        /// <param name="max_value">max_value Maximum value (inclusive) for random number generation</param>
        /// <param name="min_value">min_value Minimum value (inclusive) for random number generation, defaults to 1</param>
        /// <returns>Random number between min_value and max_value</returns>
        static inline uint16_t generateRandomValue(const uint16_t max_value, const uint16_t min_value) {
            std::random_device random_device;
            std::mt19937 generate(random_device());
            std::uniform_int_distribution<> distribution(min_value, max_value);

            return distribution(generate);
        }
    }
}
