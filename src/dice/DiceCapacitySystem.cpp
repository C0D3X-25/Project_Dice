#include "DiceCapacitySystem.hpp"


using namespace dice;

dice::DiceCapacitySystem::DiceCapacitySystem() {
	//CapacityFactory capacity_factory;

 //   // Initialize sides 1 through m_SIDES_COUNT (inclusive)
 //   for (uint8_t i{ 1 }; i <= m_SIDES_COUNT; i++) {
 //       m_sides.emplace(i, capacity_factory.nothing());
 //   }
}


void dice::DiceCapacitySystem::setCapacity(const CapacitySystem& capacity, const uint8_t side) {
    if (side > m_SIDES_COUNT || side < 1) {
        std::cerr << "Out of range-> capacity {" << capacity.getCapacityName() << "} for side " << static_cast<int>(side) << '\n';
        throw std::runtime_error("Invalid side for capacity assignment.");
    }
    //m_sides.at(side) = std::make_shared<CapacitySystem>(capacity);
}

void dice::DiceCapacitySystem::setCapacity(const std::weak_ptr<CapacitySystem> wp_capacity, const uint8_t side) {
    if (side > m_SIDES_COUNT || side < 1) {
        std::cerr << "Out of range-> capacity {" << wp_capacity.lock()->getCapacityName() << "} for side " << static_cast<int>(side) << '\n';
        throw std::runtime_error("Invalid side for capacity assignment.");
    }
}


const std::weak_ptr<CapacitySystem> DiceCapacitySystem::getCapacity(const uint8_t side) const {
    auto it = m_sides.find(side);
    if (it != m_sides.end()) {
        return it->second;  // Return the weak_ptr of the found capacity
    }
    return std::weak_ptr<CapacitySystem>();
}


void dice::DiceCapacitySystem::printDiceSides() const {
    for (const auto& [side, capacity] : m_sides) {
        std::cout << "Side " << static_cast<int>(side) << ":\n";
        if (auto capacityPtr = capacity.lock()) {
            capacityPtr->printCapacity();
        } else {
            std::cout << "Capacity no longer exists.\n";
        }
        std::cout << "---------------\n";
    }
}

#pragma warning(push)
#pragma warning(disable: 4244) // Disable warning about possible data loss
const std::weak_ptr<CapacitySystem> DiceCapacitySystem::roll() {

    auto it = m_sides.find(getRandomValue(m_SIDES_COUNT));

    if (it != m_sides.end()) {
        return it->second;
    }
    return std::weak_ptr<CapacitySystem>();
}
#pragma warning(pop)  // Restore warning settings


//const dice::CapacitySystem& DiceCapacitySystem::rollAdvantage() {
//    // TODO: Return the capacity with the highest rarity
//    return ;
//}
//
//
//const dice::CapacitySystem& DiceCapacitySystem::rollDisadvantage() {
//	// TODO: Return the capacity with the highest rarity
//    return ;
//}

