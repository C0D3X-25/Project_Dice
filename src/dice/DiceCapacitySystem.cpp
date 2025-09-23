#include "DiceCapacitySystem.hpp"


using namespace dice;

dice::DiceCapacitySystem::DiceCapacitySystem() {
	//CapacityFactory capacity_factory;

 //   // Initialize sides 1 through m_SIDES_COUNT (inclusive)
 //   for (uint8_t i{ 1 }; i <= m_SIDES_COUNT; i++) {
 //       m_sides.emplace(i, capacity_factory.nothing());
 //   }
}


void dice::DiceCapacitySystem::setCapacity(const EListCapacityData capacity, const uint8_t side) {
    if (side > m_SIDES_COUNT || side < 1) {
        std::cerr << "Out of range-> capacity {" << toString(capacity) << "} for side " << static_cast<int>(side) << '\n';
        throw std::runtime_error("Invalid side for capacity assignment.");
    }
    m_sides.at(side) = capacity;
}


const EListCapacityData DiceCapacitySystem::getCapacity(const uint8_t side) const {
    auto it = m_sides.find(side);
    if (it != m_sides.end()) {
        return it->second;  // Return the weak_ptr of the found capacity
    }
    return EListCapacityData();
}


void dice::DiceCapacitySystem::printDiceSides() const {
    for (const auto& [side, capacity] : m_sides) {
        std::cout << "Side " << static_cast<int>(side) << ":\n";
        //if (auto capacityPtr = capacity.lock()) {
        //    capacityPtr->printCapacity();
        //}
        std::cout << "---------------\n";
    }
}

#pragma warning(push)
#pragma warning(disable: 4244) // Disable warning about possible data loss
const EListCapacityData DiceCapacitySystem::roll() {

    auto it = m_sides.find(getRandomValue(m_SIDES_COUNT));

    if (it != m_sides.end()) {
        return it->second;
    }
    return EListCapacityData();
}
#pragma warning(pop)  // Restore warning settings


//const dice::ACapacitySystem& DiceCapacitySystem::rollAdvantage() {
//    // TODO: Return the capacity with the highest rarity
//    return ;
//}
//
//
//const dice::ACapacitySystem& DiceCapacitySystem::rollDisadvantage() {
//	// TODO: Return the capacity with the highest rarity
//    return ;
//}

