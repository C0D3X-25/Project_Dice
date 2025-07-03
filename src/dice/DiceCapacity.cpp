#include "../include/DiceCapacity.hpp"


using namespace dice;

DiceCapacity::DiceCapacity(void) {
	CapacityFactory capacity_factory;

    // Initialize sides 1 through m_SIDES_COUNT (inclusive)
    for (uint8_t i{ 1 }; i <= m_SIDES_COUNT; i++) {
        m_sides.emplace(i, capacity_factory.nothing());
    }
}


void DiceCapacity::setCapacity(const BaseCapacity& capacity, const uint8_t side) {
    if (side > m_SIDES_COUNT || side < 1) {
        std::cerr << "Out of range-> capacity {" << capacity.getCapacityName() << "} for side " << static_cast<int>(side) << '\n';
        throw std::runtime_error("Invalid side for capacity assignment.");
    }
    m_sides.at(side) = capacity;
}


const BaseCapacity* DiceCapacity::getCapacity(const uint8_t side) const {
    auto it = m_sides.find(side);
    if (it != m_sides.end()) {
        return &(it->second);  // Return address of the found capacity
    }
    return nullptr;
}


void DiceCapacity::printDiceSides(void) const {
    for (const auto& [side, capacity] : m_sides) {
        std::cout << "Side " << static_cast<int>(side) << ":\n";
        capacity.printCapacity();
        std::cout << "---------------\n";
    }
}

#pragma warning(push)
#pragma warning(disable: 4244) // Disable warning about possible data loss
const BaseCapacity DiceCapacity::roll(void) {

    auto it = m_sides.find(getRandomValue(m_SIDES_COUNT));

    if (it != m_sides.end()) {
        return it->second;
    }
    return BaseCapacity();
}
#pragma warning(pop)  // Restore warning settings


//const BaseCapacity& DiceCapacity::rollAdvantage(void) {
//    // TODO: Return the capacity with the highest rarity
//    return ;
//}
//
//
//const BaseCapacity& DiceCapacity::rollDisadvantage(void) {
//	// TODO: Return the capacity with the highest rarity
//    return ;
//}

