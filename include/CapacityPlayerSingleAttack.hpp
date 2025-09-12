//#pragma once 
//
//#include "BasECapacityData.hpp"
//#include "CapacityActionDamageSystem.hpp"
//#include "AttributeData.hpp"
//#include "CharacterSystem.hpp" 
//#include "SFindSystem.hpp"
//
//#include <vector>
//
//namespace capacity {
//
//	using namespace character;
//	using namespace attribute;
//
//	class CapacityPlayerSingleAttack : public CapacitySystem {
//	public:
//
//		CapacityPlayerSingleAttack(const CharacterSystem& user) {
//
//			setcharacterName("1 Attack and 1 Random Attack");
//			setCapacityDescription("Attack a single ennemy with STR or DEX, then attack a random ennemy with STR or DEX");
//			setCapacityPurposes({ ATTACK_PHYSICAL });
//			setCapacityTriggers({ USED_WHEN_TURN_END });
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
//
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 3 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(user.getAttribute(attribute::STRENGTH), user.getAttribute(attribute::DEXTERITY), min_damage);
//
//				CapacityActionDamageSystem attack(total_damage, targets);
//				queueCapacityDTO(attack.doAction());
//			}
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENNEMY };
//
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 5 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(user.getAttribute(attribute::STRENGTH), user.getAttribute(attribute::DEXTERITY), min_damage);
//
//				CapacityActionDamageSystem attack(total_damage, targets);
//				queueCapacityDTO(attack.doAction());
//			}
//		}
//		~CapacityPlayerSingleAttack(void) = default;
//	};
//} // namespace capacity
