//#pragma once 
//
//#include "CapacitySystem.hpp"
//#include "CapacityActionDamageSystem.hpp"
//#include "AttributeData.hpp"
//#include "CharacterSystem.hpp"
//#include "SFindSystem.hpp"
//
//#include <vector>
//
//namespace character {
//	class CharacterSystem;
//}
//
//namespace capacity {
//
//	using character::CharacterSystem;
//	using namespace attribute;
//	using namespace capacity_action;
//
//	/// <summary>
//	/// This class is a library for all the capacities.
//	/// 1 method = 1 Capacity
//	/// A method must return a CapacitySystem object.
//	/// </summary>
//	class CapacityFactory {
//	public:
//
//		CapacityFactory(void) {}
//		~CapacityFactory(void) = default;
//
//
//		CapacitySystem nothing(void) {
//			CapacitySystem capacity;
//			capacity.setCapacityName("Nothing");
//			capacity.setCapacityDescription("Just skip your turn");
//			return capacity;
//		}
//
//
//		CapacitySystem attackSingle(const CharacterSystem& source_character) {
//			CapacitySystem capacity;
//			capacity.setCapacityName("1 Attack");
//			capacity.setCapacityDescription("Attack a single ennemy with STR or DEX");
//			capacity.setCapacityPurposes({ ATTACK });
//			capacity.setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
//			capacity.setCapacityAttribute({ STRENGTH, DEXTERITY });
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 3 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);
//				CapacityActionDamageSystem attack(total_damage, targets);
//				capacity.queueCapacityActionData(attack.doAction());
//			}
//			return capacity;
//		}
//
//
//		CapacitySystem attackRandom(const CharacterSystem& source_character) {
//			CapacitySystem capacity;
//			capacity.setCapacityName("1 Attack and 1 Random Attack");
//			capacity.setCapacityDescription("Attack a single ennemy with worst STR or DEX, then attack another random ennemy with best STR or DEX");
//			capacity.setCapacityPurposes({ ATTACK });
//			capacity.setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
//			capacity.setCapacityAttribute({ STRENGTH, DEXTERITY });
//
//			// Take the best between dexterity and strength 
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
//
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 3 };
//				int8_t total_damage = base_damage + helper::find::getLowestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);
//
//				CapacityActionDamageSystem attack(total_damage, targets);
//				capacity.queueCapacityActionData(attack.doAction());
//			}
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENNEMY };
//
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 5 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(DEXTERITY), min_damage);
//
//				CapacityActionDamageSystem attack(total_damage, targets);
//				capacity.queueCapacityActionData(attack.doAction());
//			}
//			return capacity;
//		}
//
//		CapacitySystem attackEnnemyTeam(const CharacterSystem& source_character) {
//			CapacitySystem capacity;
//			capacity.setCapacityName("Strike the ennemy team once");
//			capacity.setCapacityDescription("Attack all ennemy with best INT, WIS or CHA");
//			capacity.setCapacityPurposes({ ATTACK });
//			capacity.setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
//			capacity.setCapacityAttribute({ INTELLIGENCE, WISDOM, CHARISMA });
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_TEAM, TARGET_ENNEMY };
//				constexpr int8_t min_damage{ 1 };
//				constexpr int8_t base_damage{ 2 };
//				int8_t total_damage = base_damage + helper::find::getHighestValue(source_character.getAttribute(CHARISMA), source_character.getAttribute(WISDOM), source_character.getAttribute(INTELLIGENCE), min_damage);
//				CapacityActionDamageSystem attack(total_damage, targets);
//				capacity.queueCapacityActionData(attack.doAction());
//			}
//			return capacity;
//		}
//
//
//		CapacitySystem protectSelf(const CharacterSystem& source_character) {
//			CapacitySystem capacity;
//			capacity.setCapacityName("Protect self");
//			capacity.setCapacityDescription("Protect yourself with your armor");
//			capacity.setCapacityPurposes({ DEFENSE });
//			capacity.setCapacityTriggers({ TRIGGERED_WHEN_TURN_END });
//			capacity.setCapacityAttribute({ STRENGTH, DEXTERITY });
//
//			// Take the best between dexterity and strength
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_SELF };
//				constexpr int8_t min_armor{ 1 };
//				constexpr int8_t base_armor{ 3 };
//				int8_t total_armor = base_armor + helper::find::getHighestValue(source_character.getAttribute(STRENGTH), source_character.getAttribute(WISDOM), min_armor);
//				CapacityActionDamageSystem protect(total_armor, targets);
//				capacity.queueCapacityActionData(protect.doAction());
//			}
//			return capacity;
//		}
//
//
//		CapacitySystem fastHeal(const CharacterSystem& source_character) {
//			CapacitySystem capacity;
//			capacity.setCapacityName("Fast heal");
//			capacity.setCapacityDescription("Heal directly a single ally with best INT, WIS or CHA");
//			capacity.setCapacityPurposes({ HEAL });
//			capacity.setCapacityTriggers({ TRIGGERED_WHEN_ASSIGNED });
//			capacity.setCapacityAttribute({ INTELLIGENCE, WISDOM, CHARISMA });
//
//			// Take the best between INT, WIS or CHA
//			{
//				std::vector<ECapacityTargetData> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ALLY };
//				constexpr int8_t min_heal{ 0 };
//				constexpr int8_t base_heal{ 1 };
//				int8_t total_heal = base_heal + helper::find::getHighestValue(source_character.getAttribute(CHARISMA), source_character.getAttribute(WISDOM), source_character.getAttribute(INTELLIGENCE), min_heal);
//				CapacityActionDamageSystem heal(total_heal, targets);
//				capacity.queueCapacityActionData(heal.doAction());
//			}
//			return capacity;
//		}
//	};
//} // namespace capacity
