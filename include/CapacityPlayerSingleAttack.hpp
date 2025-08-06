//#pragma once 
//
//#include "BaseCapacity.hpp"
//#include "CapacityActionDamage.hpp"
//#include "Attribute.hpp"
//#include "BaseEntity.hpp" 
//#include "SFind.hpp"
//
//#include <vector>
//
//namespace capacity {
//
//	using namespace entity;
//	using namespace attribute;
//
//	class CapacityPlayerSingleAttack : public BaseCapacity {
//	public:
//
//		CapacityPlayerSingleAttack(const BaseEntity& user) {
//
//			setCapacityName("1 Attack and 1 Random Attack");
//			setCapacityDescription("Attack a single ennemy with STR or DEX, then attack a random ennemy with STR or DEX");
//			setCapacityPurposes({ ATTACK_PHYSICAL });
//			setCapacityTriggers({ USED_WHEN_TURN_END });
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
//
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 3 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(user.getStrength(), user.getDexterity(), min_damage);
//
//				CapacityActionDamage attack(total_damage, targets);
//				queueCapacityModifier(attack.doAction());
//			}
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENNEMY };
//
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 5 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(user.getStrength(), user.getDexterity(), min_damage);
//
//				CapacityActionDamage attack(total_damage, targets);
//				queueCapacityModifier(attack.doAction());
//			}
//		}
//		~CapacityPlayerSingleAttack(void) = default;
//	};
//} // namespace capacity
