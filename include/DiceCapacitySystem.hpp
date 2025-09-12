#pragma once
#include "ABaseDiceSystem.hpp"
//#include "IRollAdvantageDisadvantage.hpp"
#include "CapacitySystem.hpp"
//#include "CapacityFactory.hpp"

#include <array>
#include <map>
#include <memory>

//namespace capacity {
//    class CapacitySystem;
//    //class CapacityFactory;
//}

namespace dice {

    using capacity::CapacitySystem;
    //using capacity::CapacityFactory;

    /// <summary>
    /// Represents a dice system where each side is associated with a specific capacity, providing methods to set, retrieve, roll, and print dice sides.
    /// </summary>
    class DiceCapacitySystem: public ABaseDiceSystem<CapacitySystem>/*,
        IRollAdvantageDisadvantage<std::shared_ptr<CapacitySystem>>*/ {

    public:
        DiceCapacitySystem();
        ~DiceCapacitySystem() = default;

        /// <summary>
        /// Sets the capacity for a specified side in the given CapacitySystem.
        /// </summary>
        /// <param name="capacity">Reference to the CapacitySystem object to modify.</param>
        /// <param name="side">The side (as an unsigned 8-bit integer) for which to set the capacity.</param>
        void setCapacity(const CapacitySystem& capacity, const uint8_t side);
        
        
        /// <summary>
        /// Retrieves the capacity system associated with the specified side.
        /// </summary>
        /// <param name="side">The side identifier for which to get the capacity system.</param>
        /// <returns>A pointer to the CapacitySystem associated with the given side.</returns>
        const CapacitySystem* getCapacity(const uint8_t side) const;

        /**
         * @brief Performs an advantage roll (rolls twice and takes the better result)
         * @return The capacity from the higher roll
         */
        //const std::shared_ptr<CapacitySystem> rollAdvantage(void) override;

        /**
         * @brief Performs a disadvantage roll (rolls twice and takes the worse result)
         * @return The capacity from the lower roll
         */
        //const std::shared_ptr<CapacitySystem> rollDisadvantage(void) override;

        /// <summary>
        /// Performs a single roll of the dice
        /// </summary>
        /// <returns>The capacity from the rolled side</returns>
        const CapacitySystem roll() override;

        /// <summary>
        /// Prints the sides of a dice to the standard output.
        /// </summary>
        void printDiceSides() const override;

        static constexpr uint8_t m_SIDES_COUNT = 10;

    private:
        /** @brief Map storing the capacity for each side of the dice */
        std::map<uint8_t, CapacitySystem> m_sides{};
    };
}